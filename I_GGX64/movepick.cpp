#include "chess.h"

















#include <cassert>

#include "movepick.h"

namespace {

	enum Stages {
		MAIN_TT, CAPTURE_INIT, GOOD_CAPTURE, REFUTATION, QUIET_INIT, QUIET, BAD_CAPTURE,
		EVASION_TT, EVASION_INIT, EVASION,
		PROBCUT_TT, PROBCUT_INIT, PROBCUT,
		QSEARCH_TT, QCAPTURE_INIT, QCAPTURE, QCHECK_INIT, QCHECK
	};

	// partial_insertion_sort() sorts moves in descending order up to and including
	// a given limit. The order of moves smaller than the limit is left unspecified.
	void partial_insertion_sort(ExtMove* begin, ExtMove* end, int limit) {

		for (ExtMove* sortedEnd = begin, *p = begin + 1; p < end; ++p)
			if (p->value >= limit)
			{
				ExtMove tmp = *p, * q;
				*p = *++sortedEnd;
				for (q = sortedEnd; q != begin && *(q - 1) < tmp; --q)
					*q = *(q - 1);
				*q = tmp;
			}
	}

} // namespace


/// Constructors of the MovePicker class. As arguments we pass information
/// to help it to return the (presumably) good moves first, to decide which
/// moves to return (in the quiescence search, for instance, we only want to
/// search captures, promotions, and some checks) and how important good move
/// ordering is at the current node.

/// MovePicker constructor for the main search
MovePicker::MovePicker(const Position& p, Move ttm, Depth d, const ButterflyHistory* mh, const LowPlyHistory* lp,
	const CapturePieceToHistory* cph, const PieceToHistory** ch, Move cm, const Move* killers, int pl)
	: pos(p), mainHistory(mh), lowPlyHistory(lp), captureHistory(cph), continuationHistory(ch),
	ttMove(ttm), refutations{ {killers[0], 0}, {killers[1], 0}, {cm, 0} }, depth(d), ply(pl) {

	assert(d > 0);

	stage = (m_have_bit(pos.checkers()) ? EVASION_TT : MAIN_TT) +
		!(ttm && pos.pseudo_legal(ttm));
}

/// MovePicker constructor for quiescence search
MovePicker::MovePicker(const Position& p, Move ttm, Depth d, const ButterflyHistory* mh,
	const CapturePieceToHistory* cph, const PieceToHistory** ch, Square rs)
	: pos(p), mainHistory(mh), captureHistory(cph), continuationHistory(ch), ttMove(ttm), recaptureSquare(rs), depth(d) {

	assert(d <= 0);

	stage = (m_have_bit(pos.checkers()) ? EVASION_TT : QSEARCH_TT) +
		!(ttm
			&& (pos.checkers() || depth > DEPTH_QS_RECAPTURES || to_sq(ttm) == recaptureSquare)
			&& pos.pseudo_legal(ttm));
}

/// MovePicker constructor for ProbCut: we generate captures with SEE greater
/// than or equal to the given threshold.
MovePicker::MovePicker(const Position& p, Move ttm, Value th, const CapturePieceToHistory* cph)
	: pos(p), captureHistory(cph), ttMove(ttm), threshold(th) {

	assert(!pos.checkers());

	stage = PROBCUT_TT + !(ttm && pos.capture(ttm)
		&& pos.pseudo_legal(ttm)
		&& pos.see_ge(ttm, threshold));
}

/// MovePicker::score() assigns a numerical value to each move in a list, used
/// for sorting. Captures are ordered by Most Valuable Victim (MVV), preferring
/// captures with a good history. Quiets moves are ordered using the histories.
template<GenType Type>
void MovePicker::score() {

	static_assert(Type == CAPTURES || Type == QUIETS || Type == EVASIONS, "Wrong type");

	for (auto& m : *this)
		if (Type == CAPTURES)
			m.value = int(PieceValue[MG][pos.piece_on(to_sq(m))]) * 6
			+ (*captureHistory)[pos.moved_piece(m)][to_sq(m)][type_of(pos.piece_on(to_sq(m)))];

		else if (Type == QUIETS)
			m.value = (*mainHistory)[pos.side_to_move()][from_to(m)]
			+ 2 * (*continuationHistory[0])[pos.moved_piece(m)][to_sq(m)]
			+ 2 * (*continuationHistory[1])[pos.moved_piece(m)][to_sq(m)]
			+ 2 * (*continuationHistory[3])[pos.moved_piece(m)][to_sq(m)]
			+ (*continuationHistory[5])[pos.moved_piece(m)][to_sq(m)]
			+ (ply < MAX_LPH ? std::min(4, depth / 3) * (*lowPlyHistory)[ply][from_to(m)] : 0);

		else // Type == EVASIONS
		{
			if (pos.capture(m))
				m.value = PieceValue[MG][pos.piece_on(to_sq(m))]
				- Value(type_of(pos.moved_piece(m)));
			else
				m.value = (*mainHistory)[pos.side_to_move()][from_to(m)]
				+ (*continuationHistory[0])[pos.moved_piece(m)][to_sq(m)]
				- (1 << 28);
		}
}

/// MovePicker::select() returns the next move satisfying a predicate function.
/// It never returns the TT move.
template<MovePicker::PickType T, typename Pred>
Move MovePicker::select(Pred filter) {

	while (cur < endMoves)
	{
		if (T == Best)
			std::swap(*cur, *std::max_element(cur, endMoves));

		if (*cur != ttMove && filter())
			return *cur++;

		cur++;
	}
	return MOVE_NONE;
}


/// MovePicker::next_move() is the most important method of the MovePicker class. It
/// returns a new pseudo-legal move every time it is called until there are no more
/// moves left, picking the move with the highest score from a list of generated moves.
Move MovePicker::next_move(bool skipQuiets) {

top:
	switch (stage) {

	case MAIN_TT:
	case EVASION_TT:
	case QSEARCH_TT:
	case PROBCUT_TT:
		++stage;
		return ttMove;

	case CAPTURE_INIT:
	case PROBCUT_INIT:
	case QCAPTURE_INIT:
		cur = endBadCaptures = moves;
		endMoves = generate<CAPTURES>(pos, cur);

		score<CAPTURES>();
		++stage;
		goto top;

	case GOOD_CAPTURE:
		if (select<Best>([&]() {
			return pos.see_ge(*cur, Value(-69 * cur->value / 1024)) ?
				// Move losing capture to endBadCaptures to be tried later
				true : (*endBadCaptures++ = *cur, false); }))
			return *(cur - 1);

			// Prepare the pointers to loop over the refutations array
			cur = std::begin(refutations);
			endMoves = std::end(refutations);

			// If the countermove is the same as a killer, skip it
			if (refutations[0].move == refutations[2].move
				|| refutations[1].move == refutations[2].move)
				--endMoves;

			++stage;
			[[fallthrough]];

	case REFUTATION:
		if (select<Next>([&]() { return    *cur != MOVE_NONE
			&& !pos.capture(*cur)
			&& pos.pseudo_legal(*cur); }))
			return *(cur - 1);
		++stage;
		[[fallthrough]];

	case QUIET_INIT:
		if (!skipQuiets)
		{
			cur = endBadCaptures;
			endMoves = generate<QUIETS>(pos, cur);

			score<QUIETS>();
			partial_insertion_sort(cur, endMoves, -3000 * depth);
		}

		++stage;
		[[fallthrough]];

	case QUIET:
		if (!skipQuiets
			&& select<Next>([&]() {return   *cur != refutations[0].move
				&& *cur != refutations[1].move
				&& *cur != refutations[2].move; }))
			return *(cur - 1);

		// Prepare the pointers to loop over the bad captures
		cur = moves;
		endMoves = endBadCaptures;

		++stage;
		[[fallthrough]];

	case BAD_CAPTURE:
		return select<Next>([]() { return true; });

	case EVASION_INIT:
		cur = moves;
		endMoves = generate<EVASIONS>(pos, cur);

		score<EVASIONS>();
		++stage;
		[[fallthrough]];

	case EVASION:
		return select<Best>([]() { return true; });

	case PROBCUT:
		return select<Best>([&]() { return pos.see_ge(*cur, threshold); });

	case QCAPTURE:
		if (select<Best>([&]() { return   depth > DEPTH_QS_RECAPTURES
			|| to_sq(*cur) == recaptureSquare; }))
			return *(cur - 1);

		// If we did not find any move and we do not try checks, we have finished
		if (depth != DEPTH_QS_CHECKS)
			return MOVE_NONE;

		++stage;
		[[fallthrough]];

	case QCHECK_INIT:
		cur = moves;
		endMoves = generate<QUIET_CHECKS>(pos, cur);

		++stage;
		[[fallthrough]];

	case QCHECK:
		return select<Next>([]() { return true; });
	}

	assert(false);
	return MOVE_NONE; // Silence warning
}


/*

/// score() assigns a numerical value to each move in a move list. The moves with
/// highest values will be picked first.
template<>
void MovePicker::score<CAPTURES>() {
	// Winning and equal captures in the main search are ordered by MVV, preferring
	// captures near our home rank. Surprisingly, this appears to perform slightly
	// better than SEE-based move ordering: exchanging big pieces before capturing
	// a hanging piece probably helps to reduce the subtree size.
	// In the main search we want to push captures with negative SEE values to the
	// badCaptures[] array, but instead of doing it now we delay until the move
	// has been picked up, saving some SEE calls in case we get a cutoff.
	for (auto& m : *this)
		m.value = PieceValueMidgame[pos.piece_on(to_sq(m))]
		- Value(200 * relative_rank(pos.side_to_move(), to_sq(m)));
}

template<>
void MovePicker::score<QUIETS>() {

	const ButterflyHistory& history = pos.this_thread()->history;

	const PieceToHistory& cmh = *(ss - 1)->history;
	const PieceToHistory& fmh = *(ss - 2)->history;
	const PieceToHistory& fm2 = *(ss - 4)->history;

	Color c = pos.side_to_move();

	for (auto& m : *this)
		m.value = cmh[pos.moved_piece(m)][to_sq(m)]
		+ fmh[pos.moved_piece(m)][to_sq(m)]
		+ fm2[pos.moved_piece(m)][to_sq(m)]
		+ history[c][from_to(m)];
}

template<>
void MovePicker::score<EVASIONS>() {
	// Try captures ordered by MVV/LVA, then non-captures ordered by stats heuristics
	const ButterflyHistory& history = pos.this_thread()->history;
	Color c = pos.side_to_move();

	for (auto& m : *this)
		if (pos.capture(m))
			m.value = PieceValueMidgame[pos.piece_on(to_sq(m))]
			- Value(type_of(pos.moved_piece(m))) + (1 << 28);
		else
			m.value = history[c][from_to(m)];
}


/// next_move() is the most important method of the MovePicker class. It returns
/// a new pseudo legal move every time it is called, until there are no more moves
/// left. It picks the move with the biggest value from a list of generated moves
/// taking care not to return the ttMove if it has already been searched.

Move MovePicker::next_move(bool skipQuiets) {

	Move move;

	switch (stage) {

	case MAIN_SEARCH: case EVASION: case QSEARCH_WITH_CHECKS:
	case QSEARCH_NO_CHECKS: case PROBCUT:
		++stage;
		return ttMove;

	case CAPTURES_INIT:
		endBadCaptures = cur = moves;
		endMoves = generate<CAPTURES>(pos, cur);
		score<CAPTURES>();
		++stage;	

	case GOOD_CAPTURES:
		while (cur < endMoves)
		{
			move = pick_best(cur++, endMoves);
			if (move != ttMove)
			{
				if (pos.see_ge(move))
					return move;

				// Losing capture, move it to the beginning of the array
				*endBadCaptures++ = move;
			}
		}

		++stage;
		move = killers[0];  // First killer move
		if (move != MOVE_NONE
			&&  move != ttMove
			&&  pos.pseudo_legal(move)
			&& !pos.capture(move))
			return move;
		

	case KILLERS:
		++stage;
		move = killers[1]; // Second killer move
		if (move != MOVE_NONE
			&&  move != ttMove
			&&  pos.pseudo_legal(move)
			&& !pos.capture(move))
			return move;
	

	case COUNTERMOVE:
		++stage;
		move = countermove;
		if (move != MOVE_NONE
			&&  move != ttMove
			&&  move != killers[0]
			&& move != killers[1]
			&& pos.pseudo_legal(move)
			&& !pos.capture(move))
			return move;
		

	case QUIET_INIT:
		cur = endBadCaptures;
		endMoves = generate<QUIETS>(pos, cur);
		score<QUIETS>();		
		partial_insertion_sort(cur, endMoves, -4000 * depth / ONE_PLY);
		++stage;
		

	case QUIET:
		while (cur < endMoves
			&& (!skipQuiets || cur->value >= VALUE_ZERO))
		{
			move = *cur++;

			if (move != ttMove
				&& move != killers[0]
				&& move != killers[1]
				&& move != countermove)
				return move;
		}
		++stage;
		cur = moves; // Point to beginning of bad captures
				

	case BAD_CAPTURES:
		if (cur < endBadCaptures)
			return *cur++;
		break;

	case EVASIONS_INIT:
		cur = moves;
		endMoves = generate<EVASIONS>(pos, cur);
		score<EVASIONS>();
		++stage;
		

	case ALL_EVASIONS:
		while (cur < endMoves)
		{
			move = pick_best(cur++, endMoves);
			if (move != ttMove)
				return move;
		}
		break;

	case PROBCUT_INIT:
		cur = moves;
		endMoves = generate<CAPTURES>(pos, cur);
		score<CAPTURES>();
		++stage;
		

	case PROBCUT_CAPTURES:
		while (cur < endMoves)
		{
			move = pick_best(cur++, endMoves);
			if (move != ttMove
				&& pos.see_ge(move, threshold))
				return move;
		}
		break;

	case QCAPTURES_1_INIT: case QCAPTURES_2_INIT:
		cur = moves;
		endMoves = generate<CAPTURES>(pos, cur);
		score<CAPTURES>();
		++stage;
		

	case QCAPTURES_1: case QCAPTURES_2:
		while (cur < endMoves)
		{
			move = pick_best(cur++, endMoves);
			if (move != ttMove)
				return move;
		}
		if (stage == QCAPTURES_2)
			break;
		cur = moves;
		endMoves = generate<QUIET_CHECKS>(pos, cur);
		++stage;
		

	case QCHECKS:
		while (cur < endMoves)
		{
			move = cur++->move;
			if (move != ttMove)
				return move;
		}
		break;

	case QSEARCH_RECAPTURES:
		cur = moves;
		endMoves = generate<CAPTURES>(pos, cur);
		score<CAPTURES>();
		++stage;
		

	case QRECAPTURES:
		while (cur < endMoves)
		{
			move = pick_best(cur++, endMoves);
			if (to_sq(move) == recaptureSquare)
				return move;
		}
		break;

	default:
		assert(false);
	}

	return MOVE_NONE;
}

*/


