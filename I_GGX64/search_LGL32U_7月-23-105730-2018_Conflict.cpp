
#include "chess.h"
//#include "s_eval_hash.h"

////
//// Includes
////









#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include "chess.h"

#include "evaluate.h"
#include "movegen.h"
#include "movepick.h"
#include "notation.h"
#include "search.h"
#include "timeman.h"
#include "thread.h"
#include "tt.h"
#include "uci.h"
#include "rkiss.h"
#include "VMP.h"
#include "open_book.h"

#pragma warning(disable : 4239)    
namespace Search {

	LimitsType Limits;
}

//namespace Tablebases {
//
//	int Cardinality;
//	bool RootInTB;
//	bool UseRule50;
//	Depth ProbeDepth;
//}

//namespace TB = Tablebases;

using std::string;
using Eval::evaluate;
using namespace Search;

namespace {

	// Different node types, used as a template parameter
	enum NodeType { NonPV, PV };

	// Sizes and phases of the skip-blocks, used for distributing search depths across the threads
	constexpr int SkipSize[] = { 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 };
	constexpr int SkipPhase[] = { 0, 1, 0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 6, 7 };

	// Razoring and futility margin based on depth
	constexpr int RazorMargin[] = { 0, 590, 604 };
	Value futility_margin(Depth d, bool improving) {
		return Value((175 - 50 * improving) * d / ONE_PLY);
	}

	// Margin for pruning capturing moves: almost linear in depth
	constexpr int CapturePruneMargin[] = { 0,
		1 * 200 * 1055 / 1000,
		2 * 200 * 1042 / 1000,
		3 * 200 * 963 / 1000,
		4 * 200 * 1038 / 1000,
		5 * 200 * 950 / 1000,
		6 * 200 * 930 / 1000
	};

	// Futility and reductions lookup tables, initialized at startup
	int FutilityMoveCounts[2][16]; // [improving][depth]
	int Reductions[2][2][64][64];  // [pv][improving][depth][moveNumber]

	template <bool PvNode> Depth reduction(bool i, Depth d, int mn) {
		return Reductions[PvNode][i][std::min(d / ONE_PLY, 63)][std::min(mn, 63)] * ONE_PLY;
	}

	// History and stats update bonus, based on depth
	int stat_bonus(Depth depth) {
		int d = depth / ONE_PLY;
		return d > 17 ? 0 : 32 * d * d + 64 * d - 64;
	}

	// Skill structure is used to implement strength limit
	//struct Skill {
	//	Skill(int l) : level(l) {}
	//	bool enabled() const { return level < 20; }
	//	bool time_to_pick(Depth depth) const { return depth / ONE_PLY == 1 + level; }
	//	Move best_move(size_t multiPV) { return best ? best : pick_best(multiPV); }
	//	Move pick_best(size_t multiPV);

	//	int level;
	//	Move best = MOVE_NONE;
	//};
	template <NodeType NT>
	Value search(Position& pos, Stack* ss, Value alpha, Value beta, Depth depth, bool cutNode);

	template <NodeType NT>
	Value qsearch(Position& pos, Stack* ss, Value alpha, Value beta, Depth depth = DEPTH_ZERO);

	Value value_to_tt(Value v, int ply);
	Value value_from_tt(Value v, int ply);
	void update_pv(Move* pv, Move move, Move* childPv);
	void update_continuation_histories(Stack* ss, Piece pc, Square to, int bonus);
	void update_quiet_stats(const Position& pos, Stack* ss, Move move, Move* quiets, int quietsCnt, int bonus);
	void update_capture_stats(const Position& pos, Move move, Move* captures, int captureCnt, int bonus);

	//inline bool gives_check(const Position& pos, Move move) {
	//	Color us = pos.side_to_move();
	//	return  type_of(move) == NORMAL && !(pos.blockers_for_king(~us) & pos.pieces(us))
	//		? pos.check_squares(type_of(pos.moved_piece(move))) & to_sq(move)
	//		: pos.gives_check(move);
	//}
	// perft() is our utility to verify move generation. All the leaf nodes up
	// to the given depth are generated and counted, and the sum is returned.
	//template<bool Root>
	//uint64_t perft(Position& pos, Depth depth) {

	//	StateInfo st;
	//	uint64_t cnt, nodes = 0;
	//	const bool leaf = (depth == 2 * ONE_PLY);

	//	for (const auto& m : MoveList<LEGAL>(pos))
	//	{
	//		if (Root && depth <= ONE_PLY)
	//			cnt = 1, nodes++;
	//		else
	//		{
	//			pos.do_move(m, st);
	//			cnt = leaf ? MoveList<LEGAL>(pos).size() : perft<false>(pos, depth - ONE_PLY);
	//			nodes += cnt;
	//			pos.undo_move(m);
	//		}
	//		if (Root)
	//			sync_cout << UCI::move(m, pos.is_chess960()) << ": " << cnt << sync_endl;
	//	}
	//	return nodes;
	//}

} // namespace



/// init_search() is called during startup to initialize various lookup tables

void Search::init() {

	for (int imp = 0; imp <= 1; ++imp)
		for (int d = 1; d < 64; ++d)
			for (int mc = 1; mc < 64; ++mc)
			{
				double r = log(d) * log(mc) / 1.95;

				Reductions[NonPV][imp][d][mc] = int(std::round(r));
				Reductions[PV][imp][d][mc] = std::max(Reductions[NonPV][imp][d][mc] - 1, 0);

				// Increase reduction for non-PV nodes when eval is not improving
				if (!imp && r > 1.0)
					Reductions[NonPV][imp][d][mc]++;
			}

	for (int d = 0; d < 16; ++d)
	{
		FutilityMoveCounts[0][d] = int(2.4 + 0.74 * pow(d, 1.78));
		FutilityMoveCounts[1][d] = int(5.0 + 1.00 * pow(d, 2.00));
	}
}


/// Search::clear() resets search state to zero, to obtain reproducible results

void Search::clear() {

	Threads.main()->wait_for_search_finished();

	Time.availableNodes = 0;
	TT.clear();
	Threads.clear();
}


/// MainThread::search() is called by the main thread when the program receives
/// the UCI 'go' command. It searches from the root position and outputs the "bestmove".

void MainThread::search() {

	//if (Limits.perft)
	//{
	//	nodes = perft<true>(rootPos, Limits.perft * ONE_PLY);
	//	sync_cout << "\nNodes searched: " << nodes << "\n" << sync_endl;
	//	return;
	//}
	
	Color us = rootPos.side_to_move();
	Time.init(Limits, us, rootPos.game_ply());
	TT.new_search();

	if (rootMoves.empty())
	{
		rootMoves.push_back(RootMove(MOVE_NONE));
		sync_cout << "info depth 0 score "
			<< UCI::value(-VALUE_MATE)
			<< sync_endl;
	}
	else
	{
		for (Thread* th : Threads)
			if (th != this)
				th->start_searching();

		Thread::search(); // Let's start searching!
	}

	// When we reach the maximum depth, we can arrive here without a raise of
	// Threads.stop. However, if we are pondering or in an infinite search,
	// the UCI protocol states that we shouldn't print the best move before the
	// GUI sends a "stop" or "ponderhit" command. We therefore simply wait here
	// until the GUI sends one of those commands (which also raises Threads.stop).
	Threads.stopOnPonderhit = true;

	while (!Threads.stop && (Threads.ponder || Limits.infinite))
	{} // Busy wait for a stop or a ponder reset

	// Stop the threads if not already stopped (also raise the stop if
	// "ponderhit" just reset Threads.ponder).
	Threads.stop = true;

	// Wait until all threads have finished
	for (Thread* th : Threads)
		if (th != this)
			th->wait_for_search_finished();

	// When playing in 'nodes as time' mode, subtract the searched nodes from
	// the available ones before exiting.
	if (Limits.npmsec)
		Time.availableNodes += Limits.inc[us] - Threads.nodes_searched();

	// Check if there are threads with a better score than main thread
	Thread* bestThread = this;
	if ( Options["MultiPV"] == 1
		&& !Limits.depth
		//&& !Skill(Options["Skill Level"]).enabled()
		&&  rootMoves[0].pv[0] != MOVE_NONE)
	{
		for (Thread* th : Threads)
		{
			Depth depthDiff = th->completedDepth - bestThread->completedDepth;
			Value scoreDiff = th->rootMoves[0].score - bestThread->rootMoves[0].score;

			// Select the thread with the best score, always if it is a mate
			if (scoreDiff > 0
				&& (depthDiff >= 0 || th->rootMoves[0].score >= VALUE_MATE_IN_MAX_PLY))
				bestThread = th;
		}
	}

	previousScore = bestThread->rootMoves[0].score;

	// Send new PV when needed
	if (bestThread != this)
		sync_cout << UCI::pv(bestThread->rootPos, bestThread->completedDepth, -VALUE_INFINITE, VALUE_INFINITE) << sync_endl;

	sync_cout << "bestmove " << UCI::move(bestThread->rootMoves[0].pv[0]);

	if (bestThread->rootMoves[0].pv.size() > 1 || bestThread->rootMoves[0].extract_ponder_from_tt(rootPos))
		std::cout << " ponder " << UCI::move(bestThread->rootMoves[0].pv[1]);

	std::cout << sync_endl;
}


/// Thread::search() is the main iterative deepening loop. It calls search()
/// repeatedly with increasing depth until the allocated thinking time has been
/// consumed, the user stops the search, or the maximum search depth is reached.

void Thread::search() {

	Stack stack[MAX_PLY + 7], *ss = stack + 4; // To reference from (ss-4) to (ss+2)
	Value bestValue, alpha, beta, delta;
	Move  lastBestMove = MOVE_NONE;
	Depth lastBestMoveDepth = DEPTH_ZERO;
	MainThread* mainThread = (this == Threads.main() ? Threads.main() : nullptr);
	double timeReduction = 1.0;
	Color us = rootPos.side_to_move();

	std::memset(ss - 4, 0, 7 * sizeof(Stack));
	for (int i = 4; i > 0; i--)
		(ss - i)->contHistory = &this->contHistory[EMPTY][0]; // Use as sentinel

	bestValue = delta = alpha = -VALUE_INFINITE;
	beta = VALUE_INFINITE;

	if (mainThread)
		mainThread->bestMoveChanges = 0, mainThread->failedLow = false;

	size_t multiPV = Options["MultiPV"];
	//Skill skill(Options["Skill Level"]);

	// When playing with strength handicap enable MultiPV search that we will
	// use behind the scenes to retrieve a set of possible moves.
	//if (skill.enabled())
	//	multiPV = std::max(multiPV, (size_t)4);	

	multiPV = std::min(multiPV, rootMoves.size());

	int ct = int(Options["Contempt"]) * 200 / 100; // From centipawns

												   // In analysis mode, adjust contempt in accordance with user preference
	if (Limits.infinite || Options["UCI_AnalyseMode"])
		ct = Options["Analysis Contempt"] == "Off" ? 0
		: Options["Analysis Contempt"] == "Both" ? ct
		: Options["Analysis Contempt"] == "White" && us == BLACK ? -ct
		: Options["Analysis Contempt"] == "Black" && us == WHITE ? -ct
		: ct;
		
	// In evaluate.cpp the evaluation is from the white point of view
	contempt = (us == WHITE ? make_score(ct, ct / 2)
		: -make_score(ct, ct / 2));
	
	// Iterative deepening loop until requested to stop or the target depth is reached	
	while ((rootDepth += ONE_PLY) < DEPTH_MAX
		&& !Threads.stop
		&& !(Limits.depth && mainThread && rootDepth / ONE_PLY > Limits.depth))
	{
		// Distribute search depths across the helper threads
		if (idx > 0)
		{
			int i = (idx - 1) % 20;
			if (((rootDepth / ONE_PLY + rootPos.game_ply() + SkipPhase[i]) / SkipSize[i]) % 2)
				continue;  // Retry with an incremented rootDepth
		}

		// Age out PV variability metric
		if (mainThread)
			mainThread->bestMoveChanges *= 0.517, mainThread->failedLow = false;

		// Save the last iteration's scores before first PV line is searched and
		// all the move scores except the (new) PV are set to -VALUE_INFINITE.
		for (RootMove& rm : rootMoves)
			rm.previousScore = rm.score;

		size_t PVFirst = 0;
		PVLast = 0;

		// MultiPV loop. We perform a full root search for each PV line
		for (PVIdx = 0; PVIdx < multiPV && !Threads.stop; ++PVIdx)
		{
			if (PVIdx == PVLast)
			{
				PVFirst = PVLast;
				for (PVLast++; PVLast < rootMoves.size(); PVLast++)
					if (rootMoves[PVLast].TBRank != rootMoves[PVFirst].TBRank)
						break;
			}

			// Reset UCI info selDepth for each depth and each PV line
			selDepth = 0;

			// Reset aspiration window starting size
			if (rootDepth >= 5 * ONE_PLY)
			{
				Value previousScore = rootMoves[PVIdx].previousScore;
				delta = Value(18);
				alpha = std::max(previousScore - delta, -VALUE_INFINITE);
				beta = std::min(previousScore + delta, VALUE_INFINITE);

				// Adjust contempt based on root move's previousScore (dynamic contempt)
				int dct = ct + 88 * previousScore / (abs(previousScore) + 200);

				contempt = (us == WHITE ? make_score(dct, dct / 2)
					: -make_score(dct, dct / 2));
			}

			// Start with a small aspiration window and, in the case of a fail
			// high/low, re-search with a bigger window until we're not failing
			// high/low anymore.
			while (true)
			{
				bestValue = ::search<PV>(rootPos, ss, alpha, beta, rootDepth, false);

				// Bring the best move to the front. It is critical that sorting
				// is done with a stable algorithm because all the values but the
				// first and eventually the new best one are set to -VALUE_INFINITE
				// and we want to keep the same order for all the moves except the
				// new PV that goes to the front. Note that in case of MultiPV
				// search the already searched PV lines are preserved.
				std::stable_sort(rootMoves.begin() + PVIdx, rootMoves.begin() + PVLast);

				// If search has been stopped, we break immediately. Sorting and
				// writing PV back to TT is safe because RootMoves is still
				// valid, although it refers to the previous iteration.
				if (Threads.stop)
					break;

				// When failing high/low give some update (without cluttering
				// the UI) before a re-search.
				if (mainThread
					&& multiPV == 1
					&& (bestValue <= alpha || bestValue >= beta)
					&& Time.elapsed() > 3000)
					sync_cout << UCI::pv(rootPos, rootDepth, alpha, beta) << sync_endl;

				// In case of failing low/high increase aspiration window and
				// re-search, otherwise exit the loop.
				if (bestValue <= alpha)
				{
					beta = (alpha + beta) / 2;
					alpha = std::max(bestValue - delta, -VALUE_INFINITE);

					if (mainThread)
					{
						mainThread->failedLow = true;
						Threads.stopOnPonderhit = false;
					}
				}
				else if (bestValue >= beta)
					beta = std::min(bestValue + delta, VALUE_INFINITE);
				else
					break;

				delta += delta / 4 + 5;

				assert(alpha >= -VALUE_INFINITE && beta <= VALUE_INFINITE);
			}

			// Sort the PV lines searched so far and update the GUI
			std::stable_sort(rootMoves.begin() + PVFirst, rootMoves.begin() + PVIdx + 1);

			if (mainThread
				&& (Threads.stop || PVIdx + 1 == multiPV || Time.elapsed() > 3000))
				sync_cout << UCI::pv(rootPos, rootDepth, alpha, beta) << sync_endl;
		}

		if (!Threads.stop)
			completedDepth = rootDepth;

		if (rootMoves[0].pv[0] != lastBestMove) {
			lastBestMove = rootMoves[0].pv[0];
			lastBestMoveDepth = rootDepth;
		}

		// Have we found a "mate in x"?
		if (Limits.mate
			&& bestValue >= VALUE_MATE_IN_MAX_PLY
			&& VALUE_MATE - bestValue <= 2 * Limits.mate)
			Threads.stop = true;

		if (!mainThread)
			continue;
		
		// If skill level is enabled and time is up, pick a sub-optimal best move
		//if (skill.enabled() && skill.time_to_pick(rootDepth))
		//	skill.pick_best(multiPV);
		
		// Do we have time for the next iteration? Can we stop searching now?
		if (Limits.use_time_management()
			&& !Threads.stop
			&& !Threads.stopOnPonderhit)
		{
			const int F[] = { mainThread->failedLow,
				bestValue - mainThread->previousScore };

			int improvingFactor = std::max(246, std::min(832, 306 + 119 * F[0] - 6 * F[1]));

			// If the bestMove is stable over several iterations, reduce time accordingly
			timeReduction = 1.0;
			for (int i : {3, 4, 5})
				if (lastBestMoveDepth * i < completedDepth)
					timeReduction *= 1.25;

			// Use part of the gained time from a previous stable move for the current move
			double bestMoveInstability = 1.0 + mainThread->bestMoveChanges;
			bestMoveInstability *= std::pow(mainThread->previousTimeReduction, 0.528) / timeReduction;

			// Stop the search if we have only one legal move, or if available time elapsed
			if (rootMoves.size() == 1
				|| Time.elapsed() > Time.optimum() * bestMoveInstability * improvingFactor / 581)
			{
				// If we are allowed to ponder do not stop the search now but
				// keep pondering until the GUI sends "ponderhit" or "stop".
				if (Threads.ponder)
					Threads.stopOnPonderhit = true;
				else
					Threads.stop = true;
			}
		}
  }

	if (!mainThread)
		return;

	mainThread->previousTimeReduction = timeReduction;

	// If skill level is enabled, swap best PV line with the sub-optimal one
	//if (skill.enabled())
	   // std::swap(rootMoves[0], *std::find(rootMoves.begin(),
		  //  rootMoves.end(), skill.best_move(multiPV)));
}


namespace {

	// search<>() is the main search function for both PV and non-PV nodes

	template <NodeType NT>
	Value search(Position& pos, Stack* ss, Value alpha, Value beta, Depth depth, bool cutNode) {

		// Use quiescence search when needed
		if (depth < ONE_PLY)
			return qsearch<NT>(pos, ss, alpha, beta);

		constexpr bool PvNode = NT == PV;
		const bool rootNode = PvNode && ss->ply == 0;

		assert(-VALUE_INFINITE <= alpha && alpha < beta && beta <= VALUE_INFINITE);
		assert(PvNode || (alpha == beta - 1));
		assert(DEPTH_ZERO < depth && depth < DEPTH_MAX);
		assert(!(PvNode && cutNode));
		assert(depth / ONE_PLY * ONE_PLY == depth);

		Move pv[MAX_PLY + 1], capturesSearched[32], quietsSearched[64];
		StateInfo st;
		TTEntry* tte;
		Key posKey;
		Move ttMove, move, excludedMove, bestMove;
		Depth extension, newDepth;
		Value bestValue, value, ttValue, eval, maxValue;
		bool ttHit, inCheck, givesCheck, improving;
		bool captureOrPromotion, doFullDepthSearch, moveCountPruning, skipQuiets, ttCapture, pvExact;
		Piece movedPiece;
		int moveCount, captureCount, quietCount;

		// Step 1. Initialize node
		Thread* thisThread = pos.this_thread();
		inCheck = pos.in_check(); //pos.in_check
		moveCount = captureCount = quietCount = ss->moveCount = 0;
		bestValue = -VALUE_INFINITE;
		maxValue = VALUE_INFINITE;

		// Check for the available remaining time
		if (thisThread == Threads.main())
			static_cast<MainThread*>(thisThread)->check_time();

		// Used to send selDepth info to GUI (selDepth counts from 1, ply from 0)
		if (PvNode && thisThread->selDepth < ss->ply + 1)
			thisThread->selDepth = ss->ply + 1;

		if (!rootNode)
		{
			// Step 2. Check for aborted search and immediate draw
			CheckRepetition(ss->ply);
			if (Threads.stop.load(std::memory_order_relaxed) || ss->ply >= MAX_PLY)
				return evaluate(pos);
			// Step 3. Mate distance pruning. Even if we mate at the next move our score
			// would be at best mate_in(ss->ply+1), but if alpha is already bigger because
			// a shorter mate was found upward in the tree then there is no need to search
			// because we will never beat the current alpha. Same logic but with reversed
			// signs applies also in the opposite condition of being mated instead of giving
			// mate. In this case return a fail-high score.


			alpha = std::max(mated_in(ss->ply), alpha);
			beta = std::min(mate_in(ss->ply + 1), beta);
			if (alpha >= beta)
				return alpha;

			// Check if there exists a move which draws by repetition, or an alternative
			// earlier move to this position.
			//if (pos.rule50_count() >= 3
			//	&& alpha < VALUE_DRAW
			//	&& pos.has_game_cycle(ss->ply))
			//{
			//	alpha = VALUE_DRAW;
			//	if (alpha >= beta)
			//		return alpha;
			//}
		}

		assert(0 <= ss->ply && ss->ply < MAX_PLY);

		(ss + 1)->ply = ss->ply + 1;
		ss->currentMove = (ss + 1)->excludedMove = bestMove = MOVE_NONE;
		ss->contHistory = thisThread->contHistory[NO_PIECE][0].get();
		(ss + 2)->killers[0] = (ss + 2)->killers[1] = MOVE_NONE;
		Square prevSq = to_sq((ss - 1)->currentMove);

		// Initialize statScore to zero for the grandchildren of the current position.
		// So statScore is shared between all grandchildren and only the first grandchild
		// starts with statScore = 0. Later grandchildren start with the last calculated
		// statScore of the previous grandchild. This influences the reduction rules in
		// LMR which are based on the statScore of parent position.
		(ss + 2)->statScore = 0;

		// Step 4. Transposition table lookup. We don't want the score of a partial
		// search to overwrite a previous full search TT value, so we use a different
		// position key in case of an excluded move.
		excludedMove = ss->excludedMove;
		posKey = pos.key() ^ Key(excludedMove << 16); // isn't a very good hash
		tte = TT.probe(posKey, ttHit);
		ttValue = ttHit ? value_from_tt(tte->value(), ss->ply) : VALUE_NONE;
		ttMove = rootNode ? thisThread->rootMoves[thisThread->PVIdx].pv[0]
			: ttHit ? tte->move() : MOVE_NONE;

		// At non-PV nodes we check for an early TT cutoff
		if (!PvNode
			&& ttHit
			&& tte->depth() >= depth
			&& ttValue != VALUE_NONE // Possible in case of TT access race
			&& (ttValue >= beta ? (tte->bound() & BOUND_LOWER)
				: (tte->bound() & BOUND_UPPER)))
		{
			// If ttMove is quiet, update move sorting heuristics on TT hit
			if (ttMove)
			{
				if (ttValue >= beta)
				{
					if (!pos.capture_or_promotion(ttMove))
						update_quiet_stats(pos, ss, ttMove, nullptr, 0, stat_bonus(depth));

					// Extra penalty for a quiet TT move in previous ply when it gets refuted
					if ((ss - 1)->moveCount == 1 && !pos.captured_piece())
						update_continuation_histories(ss - 1, pos.piece_on(prevSq), prevSq, -stat_bonus(depth + ONE_PLY));
				}
				// Penalty for a quiet ttMove that fails low
				else if (!pos.capture_or_promotion(ttMove))
				{
					int penalty = -stat_bonus(depth);
					thisThread->mainHistory[pos.side_to_move()][from_to(ttMove)] << penalty;
					update_continuation_histories(ss, pos.moved_piece(ttMove), to_sq(ttMove), penalty);
				}
			}
			return ttValue;
		}

		//// Step 4a. Tablebase probe
		//if (!rootNode && TB::Cardinality)
		//{
		//	int piecesCount = pos.count<ALL_PIECES>();

		//	if (piecesCount <= TB::Cardinality
		//		&& (piecesCount <  TB::Cardinality || depth >= TB::ProbeDepth)
		//		&& pos.rule50_count() == 0
		//		&& !pos.can_castle(ANY_CASTLING))
		//	{
		//		TB::ProbeState err;
		//		TB::WDLScore v = Tablebases::probe_wdl(pos, &err);

		//		if (err != TB::ProbeState::FAIL)
		//		{
		//			thisThread->tbHits++;

		//			int drawScore = TB::UseRule50 ? 1 : 0;

		//			value = v < -drawScore ? -VALUE_MATE + MAX_PLY + ss->ply
		//				: v >  drawScore ? VALUE_MATE - MAX_PLY - ss->ply
		//				: VALUE_DRAW + 2 * v * drawScore;

		//			tte->save(posKey, value_to_tt(value, ss->ply), BOUND_EXACT,
		//				std::min(DEPTH_MAX - ONE_PLY, depth + 6 * ONE_PLY),
		//				MOVE_NONE, VALUE_NONE, TT.generation());

		//			return value;
		//		}
		//	}
		//}
















		// Step 6. Evaluate the position statically
		if (inCheck)
		{
			ss->staticEval = eval = VALUE_NONE;
			improving = false;
			goto moves_loop;  // Skip early pruning when in check
		}
		else if (ttHit)
		{
			// Never assume anything on values stored in TT
			if ((ss->staticEval = eval = tte->eval()) == VALUE_NONE)
				eval = ss->staticEval = evaluate(pos);

			// Can ttValue be used as a better position evaluation?
			if (ttValue != VALUE_NONE
				&& (tte->bound() & (ttValue > eval ? BOUND_LOWER : BOUND_UPPER)))
				eval = ttValue;
		}
		else
		{
			ss->staticEval = eval =
				(ss - 1)->currentMove != MOVE_NULL ? evaluate(pos)
				: -(ss - 1)->staticEval + 2 * Eval::Tempo;

			tte->save(posKey, VALUE_NONE, BOUND_NONE, DEPTH_NONE, MOVE_NONE,
				ss->staticEval, TT.generation());
		}

		// Step 7. Razoring (skipped when in check)
		if (!PvNode
			&& depth < 3 * ONE_PLY
			&& eval <= alpha - RazorMargin[depth / ONE_PLY])
		{
			Value ralpha = alpha - (depth >= 2 * ONE_PLY) * RazorMargin[depth / ONE_PLY];
			Value v = qsearch<NonPV>(pos, ss, ralpha, ralpha + 1);
			if (depth < 2 * ONE_PLY || v <= ralpha)
				return v;
		}

		improving = ss->staticEval >= (ss - 2)->staticEval
			|| (ss - 2)->staticEval == VALUE_NONE;

		// Step 7. Futility pruning: child node (skipped when in check)
		if (!rootNode
			&&  depth < 7 * ONE_PLY
			&&  eval - futility_margin(depth, improving) >= beta
			&& eval < VALUE_KNOWN_WIN) // Do not return unproven wins
			return eval;

		// Step 9. Null move search with verification search (~40 Elo)
		if (!PvNode
			&& (ss - 1)->currentMove != MOVE_NULL
			&& (ss - 1)->statScore < 22500
			&& eval >= beta
			&& ss->staticEval >= beta - 36 * depth / ONE_PLY + 225
			&& !excludedMove
			&&  pos.non_pawn_material(pos.side_to_move())
			&& (ss->ply >= thisThread->nmp_ply || ss->ply % 2 != thisThread->nmp_odd))
		{
			assert(eval - beta >= 0);

			// Null move dynamic reduction based on depth and value
			Depth R = ((823 + 67 * depth / ONE_PLY) / 256 + std::min((eval - beta) / PawnValueMg, 3)) * ONE_PLY;

			ss->currentMove = MOVE_NULL;
			ss->contHistory = thisThread->contHistory[NO_PIECE][0].get();

			pos.do_null_move(st);

			Value nullValue = -search<NonPV>(pos, ss + 1, -beta, -beta + 1, depth - R, !cutNode);

			pos.undo_null_move();

			if (nullValue >= beta)
			{
				// Do not return unproven mate scores
				if (nullValue >= VALUE_MATE_IN_MAX_PLY)
					nullValue = beta;

				if (abs(beta) < VALUE_KNOWN_WIN && (depth < 12 * ONE_PLY || thisThread->nmp_ply))
					return nullValue;

				// Do verification search at high depths. Disable null move pruning
				// for side to move for the first part of the remaining search tree.
				thisThread->nmp_ply = ss->ply + 3 * (depth - R) / 4;
				thisThread->nmp_odd = ss->ply % 2;

				Value v = search<NonPV>(pos, ss, beta - 1, beta, depth - R, false);

				thisThread->nmp_odd = thisThread->nmp_ply = 0;

				if (v >= beta)
					return nullValue;
			}
		}

		// Step 10. ProbCut (skipped when in check)
		// If we have a good enough capture and a reduced search returns a value
		// much above beta, we can (almost) safely prune the previous move.
		if (!PvNode
			&&  depth >= 5 * ONE_PLY
			&&  abs(beta) < VALUE_MATE_IN_MAX_PLY)
		{
			Value rbeta = std::min(beta + 216 - 48 * improving, VALUE_INFINITE);
			MovePicker mp(pos, ttMove, rbeta - ss->staticEval, &thisThread->captureHistory);
			int probCutCount = 0;

			while ((move = mp.next_move()) != MOVE_NONE
				&& probCutCount < 3)
				if (pos.legal(move))
				{
					probCutCount++;

					ss->currentMove = move;
					ss->contHistory = thisThread->contHistory[pos.moved_piece(move)][to_sq(move)].get();

					assert(depth >= 5 * ONE_PLY);

					pos.do_move(move, st);

					// Perform a preliminary qsearch to verify that the move holds
					value = -qsearch<NonPV>(pos, ss + 1, -rbeta, -rbeta + 1);

					// If the qsearch held perform the regular search
					if (value >= rbeta)
						value = -search<NonPV>(pos, ss + 1, -rbeta, -rbeta + 1, depth - 4 * ONE_PLY, !cutNode);

					pos.undo_move(move);

					if (value >= rbeta)
						return value;
				}
		}

		// Step 11. Internal iterative deepening (skipped when in check)
		if (depth >= 8 * ONE_PLY
			&& !ttMove)
		{
			Depth d = 3 * depth / 4 - 2 * ONE_PLY;
			search<NT>(pos, ss, alpha, beta, d, cutNode);

			tte = TT.probe(posKey, ttHit);
			ttValue = ttHit ? value_from_tt(tte->value(), ss->ply) : VALUE_NONE;
			ttMove = ttHit ? tte->move() : MOVE_NONE;
		}

	moves_loop: // When in check search starts from here

		const PieceToHistory* contHist[] = { (ss - 1)->contHistory, (ss - 2)->contHistory, nullptr, (ss - 4)->contHistory };
		Move countermove = thisThread->counterMoves[pos.piece_on(prevSq)][prevSq];

		MovePicker mp(pos, ttMove, depth, &thisThread->mainHistory,
			&thisThread->captureHistory,
			contHist,
			countermove,
			ss->killers);
		value = bestValue; // Workaround a bogus 'uninitialized' warning under gcc

		skipQuiets = false;
		ttCapture = false;
		pvExact = PvNode && ttHit && tte->bound() == BOUND_EXACT;
		CheckInfo ci(pos);
		// Step 12. Loop through moves
		// Loop through all pseudo-legal moves until no moves remain or a beta cutoff occurs
		while ((move = mp.next_move(skipQuiets)) != MOVE_NONE)
		{
			assert(is_ok(move));

			if (move == excludedMove)
				continue;

			// At root obey the "searchmoves" option and skip moves not listed in Root
			// Move List. As a consequence any illegal move is also skipped. In MultiPV
			// mode we also skip PV moves which have been already searched and those
			// of lower "TB rank" if we are in a TB root position.
			if (rootNode && !std::count(thisThread->rootMoves.begin() + thisThread->PVIdx,
				thisThread->rootMoves.begin() + thisThread->PVLast, move))
				continue;

			ss->moveCount = ++moveCount;

			if (rootNode && thisThread == Threads.main() && Time.elapsed() > 3000)
				sync_cout << "info depth " << depth / ONE_PLY
				<< " currmove " << UCI::move(move, pos.is_chess960())
				<< " currmovenumber " << moveCount + thisThread->PVIdx << sync_endl;
			if (PvNode)
				(ss + 1)->pv = nullptr;

			extension = DEPTH_ZERO;
			captureOrPromotion = pos.capture_or_promotion(move);
			movedPiece = pos.moved_piece(move);
			givesCheck = pos.gives_check(move, ci);
		
			moveCountPruning = depth < 16 * ONE_PLY
				&& moveCount >= FutilityMoveCounts[improving][depth / ONE_PLY];

			// Step 13. Singular and Gives Check Extensions

			// Singular extension search. If all moves but one fail low on a search of
			// (alpha-s, beta-s), and just one fails high on (alpha, beta), then that move
			// is singular and should be extended. To verify this we do a reduced search
			// on all the other moves but the ttMove and if the result is lower than
			// ttValue minus a margin then we will extend the ttMove.
			if (depth >= 8 * ONE_PLY
				&&  move == ttMove
				&& !rootNode
				&& !excludedMove // Recursive singular search is not allowed
				&&  ttValue != VALUE_NONE
				&& (tte->bound() & BOUND_LOWER)
				&& tte->depth() >= depth - 3 * ONE_PLY
				&&  pos.legal(move))
			{
				Value rBeta = std::max(ttValue - 2 * depth / ONE_PLY, -VALUE_MATE);
				ss->excludedMove = move;
				value = search<NonPV>(pos, ss, rBeta - 1, rBeta, depth / 2, cutNode);
				ss->excludedMove = MOVE_NONE;

				if (value < rBeta)
					extension = ONE_PLY;
			}
			else if (givesCheck
				/*&& !moveCountPruning
				&&  pos.see_ge(move)*/)
				extension = ONE_PLY;

			// Calculate new depth for this move
			newDepth = depth - ONE_PLY + extension;

			// Step 13. Pruning at shallow depth 浅层搜索就裁剪，这个很危险
			if (!rootNode
				&&  non_pawn_material(pos)
				&& bestValue > VALUE_MATED_IN_MAX_PLY)
			{
				if (!captureOrPromotion
					&& !givesCheck
					&& have_CK_5000_Material(pos)) //	&& (pos.non_pawn_material() >= 5000))
				{
					// Move count based pruning
					if (moveCountPruning)
					{
						skipQuiets = true;
						continue;
					}

					// Reduced depth of the next LMR search
					int lmrDepth = std::max(newDepth - reduction<PvNode>(improving, depth, moveCount), DEPTH_ZERO) / ONE_PLY;

					// Countermoves based pruning (~20 Elo)
					if (lmrDepth < 3
						&& (*contHist[0])[movedPiece][to_sq(move)] < CounterMovePruneThreshold
						&& (*contHist[1])[movedPiece][to_sq(move)] < CounterMovePruneThreshold)
						continue;

					// Futility pruning: parent node (~2 Elo)
					if (lmrDepth < 7
						&& !inCheck
						&& ss->staticEval + 256 + 200 * lmrDepth <= alpha)
						continue;

					// Prune moves with negative SEE (~10 Elo)
					if (lmrDepth < 8
						&& !pos.see_ge(move, Value(-35 * lmrDepth * lmrDepth)))
						continue;
				}
				else if (depth < 7 * ONE_PLY // (~20 Elo)
					&& !extension
					&& !pos.see_ge(move, -Value(CapturePruneMargin[depth / ONE_PLY])))
					continue;
			}

			// Speculative prefetch
			prefetch(TT.first_entry(pos.key_after(move)));

			// Check for legality just before making the move
			if (!rootNode && !pos.legal(move))
			{
				ss->moveCount = --moveCount;
				continue;
			}

			if (move == ttMove && captureOrPromotion)
				ttCapture = true;

			// Update the current move (this must be done after singular extension search)
			ss->currentMove = move;
			ss->contHistory = thisThread->contHistory[movedPiece][to_sq(move)].get();

			// Step 15. Make the move
			pos.do_move(move, st, givesCheck, ci);

			// Step 15. Reduced depth search (LMR). If the move fails high it will be
			// re-searched at full depth.
			if (depth >= 3 * ONE_PLY
				&&  moveCount > 1
				&& (!captureOrPromotion || moveCountPruning))
			{
				Depth r = reduction<PvNode>(improving, depth, moveCount);

				if (captureOrPromotion)
					r -= r ? ONE_PLY : DEPTH_ZERO;
				else
				{
					// Decrease reduction if opponent's move count is high
					if ((ss - 1)->moveCount > 15)
						r -= ONE_PLY;

					// Decrease reduction for exact PV nodes
					if (pvExact)
						r -= ONE_PLY;

					// Increase reduction if ttMove is a capture
					if (ttCapture)
						r += ONE_PLY;

					// Increase reduction for cut nodes
					if (cutNode)
						r += 2 * ONE_PLY;

					// Decrease reduction for moves that escape a capture. Filter out
					// castling moves, because they are coded as "king captures rook" and
					// hence break make_move().
					else if (type_of(move) == NORMAL
						&& !pos.see_ge(make_move(to_sq(move), from_sq(move))))
						r -= 2 * ONE_PLY;

					ss->statScore = thisThread->mainHistory[~pos.side_to_move()][from_to(move)]
						+ (*contHist[0])[movedPiece][to_sq(move)]
						+ (*contHist[1])[movedPiece][to_sq(move)]
						+ (*contHist[3])[movedPiece][to_sq(move)]
						- 4000;

					// Decrease/increase reduction by comparing opponent's stat score
					if (ss->statScore >= 0 && (ss - 1)->statScore < 0)
						r -= ONE_PLY;

					else if ((ss - 1)->statScore >= 0 && ss->statScore < 0)
						r += ONE_PLY;

					// Decrease/increase reduction for moves with a good/bad history
					r = std::max(DEPTH_ZERO, (r / ONE_PLY - ss->statScore / 20000) * ONE_PLY);
				}

				Depth d = std::max(newDepth - r, ONE_PLY);

				value = -search<NonPV>(pos, ss + 1, -(alpha + 1), -alpha, d, true);

				doFullDepthSearch = (value > alpha && d != newDepth);
			}
			else
				doFullDepthSearch = !PvNode || moveCount > 1;

			// Step 17. Full depth search when LMR is skipped or fails high
			if (doFullDepthSearch)
				value = -search<NonPV>(pos, ss + 1, -(alpha + 1), -alpha, newDepth, !cutNode);

			// For PV nodes only, do a full PV search on the first move or after a fail
			// high (in the latter case search only if value < beta), otherwise let the
			// parent node fail low with value <= alpha and try another move.
			if (PvNode && (moveCount == 1 || (value > alpha && (rootNode || value < beta))))
			{
				(ss + 1)->pv = pv;
				(ss + 1)->pv[0] = MOVE_NONE;

				value = -search<PV>(pos, ss + 1, -beta, -alpha, newDepth, false);
			}

			// Step 18. Undo move
			pos.undo_move(move);

			assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

			// Step 19. Check for a new best move
			// Finished searching the move. If a stop occurred, the return value of
			// the search cannot be trusted, and we return immediately without
			// updating best move, PV and TT.
			if (Threads.stop.load(std::memory_order_relaxed))
				return VALUE_ZERO;

			if (rootNode)
			{
				RootMove& rm = *std::find(thisThread->rootMoves.begin(),
					thisThread->rootMoves.end(), move);

				// PV move or new best move?
				if (moveCount == 1 || value > alpha)
				{
					rm.score = value;
					rm.selDepth = thisThread->selDepth;
					rm.pv.resize(1);

					assert((ss + 1)->pv);

					for (Move* m = (ss + 1)->pv; *m != MOVE_NONE; ++m)
						rm.pv.push_back(*m);

					// We record how often the best move has been changed in each
					// iteration. This information is used for time management: When
					// the best move changes frequently, we allocate some more time.
					if (moveCount > 1 && thisThread == Threads.main())
						++static_cast<MainThread*>(thisThread)->bestMoveChanges;
				}
				else
					// All other moves but the PV are set to the lowest value: this
					// is not a problem when sorting because the sort is stable and the
					// move position in the list is preserved - just the PV is pushed up.
					rm.score = -VALUE_INFINITE;
			}

			if (value > bestValue)
			{
				bestValue = value;

				if (value > alpha)
				{
					bestMove = move;

					if (PvNode && !rootNode) // Update pv even in fail-high case
						update_pv(ss->pv, move, (ss + 1)->pv);

					if (PvNode && value < beta) // Update alpha! Always alpha < beta
						alpha = value;
					else
					{
						assert(value >= beta); // Fail high
						ss->statScore = std::max(ss->statScore, 0);
						break;
					}
				}
			}

			if (move != bestMove)
			{
				if (captureOrPromotion && captureCount < 32)
					capturesSearched[captureCount++] = move;

				else if (!captureOrPromotion && quietCount < 64)
					quietsSearched[quietCount++] = move;
			}
		}

		// The following condition would detect a stop only after move loop has been
		// completed. But in this case bestValue is valid because we have fully
		// searched our subtree, and we can anyhow save the result in TT.
		/*
		if (Signals.stop)
		return VALUE_DRAW;
		*/

		// Step 20. Check for mate and stalemate
		// All legal moves have been searched and if there are no legal moves, it
		// must be a mate or a stalemate. If we are in a singular extension search then
		// return a fail low score.

		assert(moveCount || !inCheck || excludedMove || !MoveList<LEGAL>(pos).size());

		if (!moveCount)
			bestValue = excludedMove ? alpha : mated_in(ss->ply);
		//: inCheck ? mated_in(ss->ply) : DrawValue[pos.side_to_move()];
		else if (bestMove)
		{
			// Quiet best move: update move sorting heuristics
			if (!pos.capture_or_promotion(bestMove))
				update_quiet_stats(pos, ss, bestMove, quietsSearched, quietCount, stat_bonus(depth));
			else
				update_capture_stats(pos, bestMove, capturesSearched, captureCount, stat_bonus(depth));

			// Extra penalty for a quiet TT move in previous ply when it gets refuted
			if ((ss - 1)->moveCount == 1 && !pos.captured_piece())
				update_continuation_histories(ss - 1, pos.piece_on(prevSq), prevSq, -stat_bonus(depth + ONE_PLY));
		}
		// Bonus for prior countermove that caused the fail low
		else if ((depth >= 3 * ONE_PLY || PvNode)
			&& !pos.captured_piece()
			&& is_ok((ss - 1)->currentMove))
			update_continuation_histories(ss - 1, pos.piece_on(prevSq), prevSq, stat_bonus(depth));

		if (PvNode)
			bestValue = std::min(bestValue, maxValue);

		if (!excludedMove)
			tte->save(posKey, value_to_tt(bestValue, ss->ply),
				bestValue >= beta ? BOUND_LOWER :
				PvNode && bestMove ? BOUND_EXACT : BOUND_UPPER,
				depth, bestMove, ss->staticEval, TT.generation());

		assert(bestValue > -VALUE_INFINITE && bestValue < VALUE_INFINITE);

		return bestValue;
	}


	// qsearch() is the quiescence search function, which is called by the main
	// search function with depth zero, or recursively with depth less than ONE_PLY.
	template <NodeType NT>
	Value qsearch(Position& pos, Stack* ss, Value alpha, Value beta, Depth depth) {

		const bool PvNode = NT == PV;

		// assert(InCheck == !!pos.checkers());
		assert(alpha >= -VALUE_INFINITE && alpha < beta && beta <= VALUE_INFINITE);
		assert(PvNode || (alpha == beta - 1));
		assert(depth <= DEPTH_ZERO);
		assert(depth / ONE_PLY * ONE_PLY == depth);

		Move pv[MAX_PLY + 1];
		StateInfo st;
		TTEntry* tte;
		Key posKey;
		Move ttMove, move, bestMove;
		Depth ttDepth;
		Value bestValue, value, ttValue, futilityValue, futilityBase, oldAlpha;
		bool ttHit, inCheck, givesCheck; // , evasionPrunable;
		Depth ttDepth;
		//int moveCount;

		if (PvNode)
		{
			oldAlpha = alpha; // To flag BOUND_EXACT when eval above alpha and no available moves
			(ss + 1)->pv = pv;
			ss->pv[0] = MOVE_NONE;
		}

		(ss + 1)->ply = ss->ply + 1;
		ss->currentMove = bestMove = MOVE_NONE;
		inCheck = pos.in_check();
		//moveCount = 0;
		CheckRepetition(ss->ply);
		if (ss->ply >= MAX_PLY) { //if (pos.is_draw() || ply >= MAX_PLY - 1)
			return ss->ply >= MAX_PLY && !InCheck ? evaluate(pos)
				: Value(0);
		}	assert(0 <= ss->ply && ss->ply < MAX_PLY);

		// Decide whether or not to include checks: this fixes also the type of
		// TT entry depth that we are going to use. Note that in qsearch we use
		// only two types of depth in TT: DEPTH_QS_CHECKS or DEPTH_QS_NO_CHECKS.
		ttDepth = inCheck || depth >= DEPTH_QS_CHECKS ? DEPTH_QS_CHECKS
			: DEPTH_QS_NO_CHECKS;
		// Transposition table lookup
		posKey = pos.key();
		tte = TT.probe(posKey, ttHit);
		ttValue = ttHit ? value_from_tt(tte->value(), ss->ply) : VALUE_NONE;
		ttMove = ttHit ? tte->move() : MOVE_NONE;

		if (!PvNode
			&& ttHit
			&& tte->depth() >= ttDepth
			&& ttValue != VALUE_NONE // Only in case of TT access race
			&& (ttValue >= beta ? (tte->bound() &  BOUND_LOWER)
				: (tte->bound() &  BOUND_UPPER)))
			return ttValue;

		// Evaluate the position statically
		if (inCheck)
		{
			ss->staticEval = VALUE_NONE;
			bestValue = futilityBase = -VALUE_INFINITE;
		}
		else
		{
			if (ttHit)
			{
				// Never assume anything on values stored in TT
				if ((ss->staticEval = bestValue = tte->eval()) == VALUE_NONE)
					ss->staticEval = bestValue = evaluate(pos);

				// Can ttValue be used as a better position evaluation?
				if (ttValue != VALUE_NONE
					&& (tte->bound() & (ttValue > bestValue ? BOUND_LOWER : BOUND_UPPER)))
					bestValue = ttValue;
			}
			else
				ss->staticEval = bestValue =
				(ss - 1)->currentMove != MOVE_NULL ? evaluate(pos)
				: -(ss - 1)->staticEval + 2 * Eval::Tempo;

			// Stand pat. Return immediately if static value is at least beta
			if (bestValue >= beta)
			{
				if (!ttHit)
					tte->save(pos.key(), value_to_tt(bestValue, ss->ply), BOUND_LOWER,
						DEPTH_NONE, MOVE_NONE, ss->staticEval, TT.generation());

				return bestValue;
			}

			if (PvNode && bestValue > alpha)
				alpha = bestValue;

			futilityBase = bestValue + 128;
		}

		// Initialize a MovePicker object for the current position, and prepare
		// to search the moves. Because the depth is <= 0 here, only captures,
		// queen promotions and checks (only if depth >= DEPTH_QS_CHECKS) will
		// be generated.
		MovePicker mp(pos, ttMove, depth, &pos.this_thread()->mainHistory,
			&pos.this_thread()->captureHistory,
			to_sq((ss - 1)->currentMove));
		CheckInfo ci(pos);
		// Loop through the moves until no moves remain or a beta cutoff occurs
		while ((move = mp.next_move()) != MOVE_NONE)
		{
			assert(is_ok(move));

			givesCheck = pos.gives_check(move, ci);
			
			// moveCount++;

			// Futility pruning(pos.pMatinfo()->searchInfo8 & CK_CAN_USE_FRUIT_PUN)
			if (!inCheck  
				&& !givesCheck
				&&  futilityBase > -VALUE_KNOWN_WIN)        //&& !pos.passed_pawn_push(move))

			{
				//assert(type_of(move) != ENPASSANT); // Due to !pos.advanced_pawn_push

				futilityValue = futilityBase + PieceValueEndgame[pos.piece_on(to_sq(move))];

				if (futilityValue <= alpha)
				{
					bestValue = std::max(bestValue, futilityValue);
					continue;
				}

				if (futilityBase <= alpha && !pos.see_ge(move, VALUE_ZERO + 1))
				{
					bestValue = std::max(bestValue, futilityBase);
					continue;
				}
			}

			// Detect non-capture evasions that are candidate to be pruned
			//evasionPrunable = InCheck
			// && bestValue > VALUE_MATED_IN_MAX_PLY  // VALUE_MATED_IN_MAX_PLY 
			// && !pos.capture(move);
			// Don't search moves with negative SEE values
			if (   // !PvNode				&& (
				!inCheck // || evasionPrunable)
				&& !givesCheck                               // 有将军也要将。
				&& !pos.see_ge(move))
				continue;

			// Speculative prefetch as early as possible
			prefetch(TT.first_entry(pos.key_after(move)));

			// Check for legality only before to do the move		  
			if (!pos.legal(move)) // , ci.pinned))
			{
				//moveCount--;
				continue;
			}

			ss->currentMove = move;

			// Make and search the move
			pos.do_move(move, st, givesCheck, ci); // , givesCheck
			value = -qsearch<NT>(pos, ss + 1, -beta, -alpha, depth - ONE_PLY);
			pos.undo_move(move);

			assert(value > -VALUE_INFINITE && value < VALUE_INFINITE);

			// Check for a new best move
			if (value > bestValue)
			{
				bestValue = value;

				if (value > alpha)
				{
					if (PvNode) // Update pv even in fail-high case
						update_pv(ss->pv, move, (ss + 1)->pv);

					if (PvNode && value < beta) // Update alpha here!
					{
						alpha = value;
						bestMove = move;
					}
					else // Fail high
					{
						tte->save(posKey, value_to_tt(value, ss->ply), BOUND_LOWER,
							ttDepth, move, ss->staticEval, TT.generation());

						return value;
					}
				}
			}
		}

		// All legal moves have been searched. A special case: If we're in check
		// and no legal moves were found, it is checkmate.
		if (InCheck && bestValue == -VALUE_INFINITE) // pos.board_display("no move");
			return mated_in(ss->ply); // Plies to mate from the root

		tte->save(posKey, value_to_tt(bestValue, ss->ply),
			PvNode && bestValue > oldAlpha ? BOUND_EXACT : BOUND_UPPER,
			ttDepth, bestMove, ss->staticEval, TT.generation());

		assert(bestValue > -VALUE_INFINITE && bestValue < VALUE_INFINITE);

		return bestValue;
	}


	// value_to_tt() adjusts a mate score from "plies to mate from the root" to
	// "plies to mate from the current ply".  Non-mate scores are unchanged.
	// The function is called before storing a value to the transposition table.

	Value value_to_tt(Value v, int ply) {

		assert(v != VALUE_NONE);

		return  v >= VALUE_MATE_IN_MAX_PLY ? v + ply
			: v <= VALUE_MATED_IN_MAX_PLY ? v - ply : v;
	}


	// value_from_tt() is the inverse of value_to_tt(): It adjusts a mate score
	// from the transposition table (where refers to the plies to mate/be mated
	// from current position) to "plies to mate/be mated from the root".

	Value value_from_tt(Value v, int ply) {

		return  v == VALUE_NONE ? VALUE_NONE
			: v >= VALUE_MATE_IN_MAX_PLY ? v - ply
			: v <= VALUE_MATED_IN_MAX_PLY ? v + ply : v;
	}


	// update_pv() adds current move and appends child pv[]

	void update_pv(Move* pv, Move move, Move* childPv) {

		for (*pv++ = move; childPv && *childPv != MOVE_NONE; )
			*pv++ = *childPv++;
		*pv = MOVE_NONE;
	}


	// update_continuation_histories() updates histories of the move pairs formed
	// by moves at ply -1, -2, and -4 with current move.

	void update_continuation_histories(Stack* ss, Piece pc, Square to, int bonus) {

		for (int i : {1, 2, 4})
			if (is_ok((ss - i)->currentMove))
				(*(ss - i)->contHistory)[pc][to] << bonus;
	}


	// update_capture_stats() updates move sorting heuristics when a new capture best move is found

	void update_capture_stats(const Position& pos, Move move,
		Move* captures, int captureCnt, int bonus) {

		CapturePieceToHistory& captureHistory = pos.this_thread()->captureHistory;
		Piece moved_piece = pos.moved_piece(move);
		PieceType captured = type_of(pos.piece_on(to_sq(move)));
		captureHistory[moved_piece][to_sq(move)][captured] << bonus;

		// Decrease all the other played capture moves
		for (int i = 0; i < captureCnt; ++i)
		{
			moved_piece = pos.moved_piece(captures[i]);
			captured = type_of(pos.piece_on(to_sq(captures[i])));
			captureHistory[moved_piece][to_sq(captures[i])][captured] << -bonus;
		}
	}


	// update_stats() updates move sorting heuristics when a new quiet best move is found

	void update_quiet_stats(const Position& pos, Stack* ss, Move move,
		Move* quiets, int quietsCnt, int bonus) {

		if (ss->killers[0] != move)
		{
			ss->killers[1] = ss->killers[0];
			ss->killers[0] = move;
		}

		Color us = pos.side_to_move();
		Thread* thisThread = pos.this_thread();
		thisThread->mainHistory[us][from_to(move)] << bonus;
		update_continuation_histories(ss, pos.moved_piece(move), to_sq(move), bonus);

		if (is_ok((ss - 1)->currentMove))
		{
			Square prevSq = to_sq((ss - 1)->currentMove);
			thisThread->counterMoves[pos.piece_on(prevSq)][prevSq] = move;
		}

		// Decrease all the other played quiet moves
		for (int i = 0; i < quietsCnt; ++i)
		{
			thisThread->mainHistory[us][from_to(quiets[i])] << -bonus;
			update_continuation_histories(ss, pos.moved_piece(quiets[i]), to_sq(quiets[i]), -bonus);
		}
	}


	// Is the PV leading to a draw position? Assumes all pv moves are legal
	bool pv_is_draw(Position& pos) {

		StateInfo st[MAX_PLY];
		auto& pv = pos.this_thread()->rootMoves[0].pv;

		for (size_t i = 0; i < pv.size(); ++i) {
			CheckInfo ci(pos);
			pos.do_move(pv[i], st[i], pos.gives_check(pv[i],ci),ci);
		}

		bool isDraw = pos.is_draw((int)pv.size());

		for (size_t i = pv.size(); i > 0; --i)
			pos.undo_move(pv[i - 1]);

		return isDraw;
	}
	
	// When playing with strength handicap, choose best move among a set of RootMoves
	// using a statistical rule dependent on 'level'. Idea by Heinz van Saanen.

	//Move Skill::pick_best(size_t multiPV) {

	//	const RootMoves& rootMoves = Threads.main()->rootMoves;
	//	static PRNG rng(now()); // PRNG sequence should be non-deterministic

	//							// RootMoves are already sorted by score in descending order
	//	Value topScore = rootMoves[0].score;
	//	int delta = std::min(topScore - rootMoves[multiPV - 1].score, PawnValueMg);
	//	int weakness = 120 - 2 * level;
	//	int maxScore = -VALUE_INFINITE;

	//	// Choose best move. For each move score we add two terms, both dependent on
	//	// weakness. One is deterministic and bigger for weaker levels, and one is
	//	// random. Then we choose the move with the resulting highest score.
	//	for (size_t i = 0; i < multiPV; ++i)
	//	{
	//		// This is our magic formula
	//		int push = (weakness * int(topScore - rootMoves[i].score)
	//			+ delta * (rng.rand<unsigned>() % weakness)) / 128;

	//		if (rootMoves[i].score + push > maxScore)
	//		{
	//			maxScore = rootMoves[i].score + push;
	//			best = rootMoves[i].pv[0];
	//		}
	//	}
	//	return best;
	//}

} // namespace


  // check_time() is used to print debug info and, more importantly, to detect
  // when we are out of available time and thus stop the search.

void MainThread::check_time() {

	if (--callsCnt > 0)
		return;

	// When using nodes, ensure checking rate is not lower than 0.1% of nodes
	callsCnt = Limits.nodes ? std::min(1024, int(Limits.nodes / 1024)) : 1024;

	static TimePoint lastInfoTime = now();

	TimePoint elapsed = Time.elapsed();
	TimePoint tick = Limits.startTime + elapsed;

	if (tick - lastInfoTime >= 1000)
	{
		lastInfoTime = tick;
		dbg_print();
	}

	// We should not stop pondering until told so by the GUI
	if (Threads.ponder)
		return;

	if ((Limits.use_time_management() && elapsed > Time.maximum() - 10)
		|| (Limits.movetime && elapsed >= Limits.movetime)
		|| (Limits.nodes && Threads.nodes_searched() >= (uint64_t)Limits.nodes))
		Threads.stop = true;
}


/// UCI::pv() formats PV information according to the UCI protocol. UCI requires
/// that all (if any) unsearched PV lines are sent using a previous search score.

string UCI::pv(Position& pos, Depth depth, Value alpha, Value beta) {

	std::stringstream ss;
	TimePoint elapsed = Time.elapsed() + 1;
	const RootMoves& rootMoves = pos.this_thread()->rootMoves;
	size_t PVIdx = pos.this_thread()->PVIdx;
	size_t multiPV = std::min((size_t)Options["MultiPV"], rootMoves.size());
	uint64_t nodesSearched = Threads.nodes_searched();
	//uint64_t tbHits = Threads.tb_hits() + (TB::RootInTB ? rootMoves.size() : 0);

	for (size_t i = 0; i < multiPV; ++i)
	{
		bool updated = (i <= PVIdx && rootMoves[i].score != -VALUE_INFINITE);

		if (depth == ONE_PLY && !updated)
			continue;

		Depth d = updated ? depth : depth - ONE_PLY;
		Value v = updated ? rootMoves[i].score : rootMoves[i].previousScore;

		//bool tb = TB::RootInTB && abs(v) < VALUE_MATE - MAX_PLY;
		//v = tb ? TB::Score : v;

		if (ss.rdbuf()->in_avail()) // Not at first line
			ss << "\n";
		//#ifdef  USE_CYCLONE_UCI  // get_cyclone_sub_depth

		ss << "info"
			<< " depth " << d / ONE_PLY
			<< " seldepth " << rootMoves[i].selDepth
			<< " multipv " << i + 1
			<< " score " << UCI::value(v);

		if (i == PVIdx) //      if (!tb && i == PVIdx)
			ss << (v >= beta ? " lowerbound" : v <= alpha ? " upperbound" : "");

		ss << " nodes " << nodesSearched
			<< " nps " << nodesSearched * 1000 / elapsed;

		if (elapsed > 1000) // Earlier makes little sense
			ss << " hashfull " << TT.hashfull();

		ss 	<< " time " << elapsed
			<< " pv";

		for (Move m : rootMoves[i].pv)
			ss << " " << UCI::move(m);

#ifdef OUTPUT_END_PV_POSITION  // 可以输出PV的最后一个局面
		Position mpos;
		StateInfo state[MAX_PLY + 4], *sta = state;
		mpos.set(pos.fen(), state, 0);

		for (Move m : rootMoves[i].pv) {
			CheckInfo ci(mpos);
			mpos.do_move_sim(m, *sta++, pos.gives_check(m, ci), ci);
		}
		mpos.board_display("END pv:");
#endif
	}

	return ss.str();
}

/// RootMove::extract_ponder_from_tt() is called in case we have no ponder move
/// before exiting the search, for instance in case we stop the search during a
/// fail high at root. We try hard to have a ponder move to return to the GUI,
/// otherwise in case of 'ponder on' we have nothing to think on.

bool RootMove::extract_ponder_from_tt(Position& pos)
{
	StateInfo st;
	bool ttHit;

	assert(pv.size() == 1);

	if (!pv[0])
		return false;
	CheckInfo ci(pos);
	pos.do_move(pv[0], st, pos.gives_check(pv[0], ci), ci);
	TTEntry* tte = TT.probe(pos.key(), ttHit);

	if (ttHit)
	{
		Move m = tte->move(); // Local copy to be SMP safe
		if (MoveList<LEGAL>(pos).contains(m))
			pv.push_back(m);
	}

	pos.undo_move(pv[0]);
	return pv.size() > 1;
}

//==================================================================================
//引擎走棋库步
#ifdef USE_OPENBOOK
// bool FillBookByPos(Position& pos, DB* db);

bool Search::Is_Have_Book_Move(Position& pos, RootMoves& rootMoves) {

	// pos.book_num = 0;             // 棋库棋步数量
	int max_book_val = -1;

	DB* db = MST->book;

	if (MST->Book_Init_Ok == FALSE) {
		return false;
	}

	bool have_book_move = false;

	Move book_move[128];             // 棋库棋步
	int book_val[128];               // 棋库棋步的分值
	int book_num = 0;                // 棋步的数量

									 //int id = 0;
	bool have_next = false;
	book_face_t book_face[1];

	Color side = Color(pos.side_to_move() ^ 0x1);
	for (RootMove rm : rootMoves) {

		//int f = 0x40;
		//int t = 0x43;
		//Move mft = make_move(f, t);

		Move m = rm.pv[0];

		//if (m == mft) {

		GetMirrorOnlyB33(side, pos.posB90(), book_face->f33, m);

		bk_GetBookInfo(book_face, db);

		int res = book_face->info->result;

		if (res != BOOK_NOT_RESULT) {

			have_next = true;
			if (book_face->info->isuse == TRUE) {
				if ((side == WHITE && res != BOOK_VERY_GOOD && res != BOOK_LIT_GOOD)		//不
					|| (side == BLACK && res != BOOK_VERY_BAD && res != BOOK_LIT_BAD)) {

					int tval = GetValByBookFaceInfo(book_face->info, side);

					book_move[book_num] = m;
					book_val[book_num] = tval;

					if (tval > max_book_val) {
						book_num = 0;               // 重新开始填充棋库棋步
						max_book_val = tval;
					}

					if (tval == max_book_val) {
						book_move[book_num] = m;
						book_val[book_num] = tval;
						book_num++;
					}

					have_book_move = true;
				}
			}
		}
	}

	if (book_num > 0) {

		int ra = 0;
		srand((int)time(0));

		ra = rand() % book_num;

		Move bm = book_move[ra];

		Sleep(300);

		sync_cout << "info multipv " << 1

			<< " depth " << 50
			<< UCI::value(Value(book_val[ra]))
			<< " time " << 1
			<< " nodes " << 888
			<< " nps " << 800
			<< " pv" << " " << UCI::move(bm) << sync_endl;

		Sleep(400);

		sync_cout << "bestmove " << UCI::move(bm);

		std::cout << sync_endl;
	}

	//for (Move m : rootMoves[i].pv) {

	//while()

	return have_book_move;
}

#endif  // #ifdef USE_OPENBOOK

/*
void Tablebases::filter_root_moves(Position& pos, Search::RootMoves& rootMoves) {

//Hits = 0;
//RootInTB = false;
//UseRule50 = Options["Syzygy50MoveRule"];
//ProbeDepth = Options["SyzygyProbeDepth"] * ONE_PLY;
//Cardinality = Options["SyzygyProbeLimit"];

// Skip TB probing when no TB found: !TBLargest -> !TB::Cardinality
//if (Cardinality > MaxCardinality)
//{
//	Cardinality = MaxCardinality;
//	ProbeDepth = DEPTH_ZERO;
//}

//if (Cardinality < popcount(pos.pieces()) || pos.can_castle(ANY_CASTLING))
//	return;

// If the current root position is in the tablebases, then RootMoves
// contains only moves that preserve the draw or the win.
//RootInTB = root_probe(pos, rootMoves, TB::Score);

//if (RootInTB)
//	Cardinality = 0; // Do not probe tablebases during the search

//else // If DTZ tables are missing, use WDL tables as a fallback
//{
//	// Filter out moves that do not preserve the draw or the win.
//	RootInTB = root_probe_wdl(pos, rootMoves, TB::Score);

//	// Only probe during search if winning
//	if (TB::Score <= VALUE_DRAW)
//		Cardinality = 0;
//}

//if (RootInTB)
//{
//	Hits = rootMoves.size();

//	if (!UseRule50)
//		TB::Score = TB::Score > VALUE_DRAW ? VALUE_MATE - MAX_PLY - 1
//		: TB::Score < VALUE_DRAW ? -VALUE_MATE + MAX_PLY + 1
//		: VALUE_DRAW;
//}

return;
}
*/


//////////////////////////////////////////////////////////////////////////
//R_HAVE_enoughMaterial
bool non_pawn_material(const Position& pos) {
	return (pos.pMatinfo()->searchInfo8 & HAVE_NONE_PAWN_MATERAIL);
}
//////////////////////////////////////////////////////////////////////////

//bool ok_to_do_nullmove(const Position& pos) {
//	return (pos.pMatinfo()->searchInfo8 & HAVE_enoughMaterial);
//}

bool have_CK_5000_Material(const Position& pos) {
	return (pos.pMatinfo()->searchInfo8 & CK_5000_Material);
}










