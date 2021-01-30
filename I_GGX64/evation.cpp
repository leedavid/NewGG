#include "chess.h"
#include "misc.h"
#include <cassert>
#include <cstring>
#include "preGen.h"

#include "evaluate.h"
#include "material.h"
#include "thread.h"
#include "uci.h"
#include "eval_const.h"
#include "uci.h"
#include "misc.h"
#include "pawns.h"


namespace {

	//const Score Tempo = make_score(32, 12);  // make_score(48, 22);

	const Score Chess_Protect_Us_Score[] = {          // 兵仕相保护自己棋子的得分      
		Score(0),
		//  将	     仕	       相          马           车           炮	          兵   
		SMG(0, 0), SMG(4, 8), SMG(8, 16), SMG(16, 16), SMG(16, 24), SMG(16, 24), SMG(8, 32),
		Score(0),
		//  将	     仕	      相          马         车         炮	        兵   
		SMG(0, 0), SMG(4, 8), SMG(8, 16), SMG(16, 16), SMG(16, 24), SMG(16, 24), SMG(8, 32),
	};


}

//////////////////////////////////////////////////////////////////////////
#include "eval_king_fisrt.cpp"
#include "抽将与牵制.cpp"
#include "eval_空炮.cpp"
#include "eval_中炮底炮.cpp"
#include "弱子评估.cpp"
#include "第1次_棋子.cpp"
#include "王的安全.cpp"
#include "eval_king_up_string.cpp"
#include "eval_by_material_phase.cpp"
#include "eval_Only_1chexPaoxPawnNoshi.cpp"



namespace Eval {

	/// evaluate() is the main evaluation function. It returns a static evaluation
	/// of the position always from the point of view of the side to move.

	Value evaluate(Position& pos) {
		return do_evaluate(pos);
	}

	/// evaluate() is the main evaluation function. It always computes two
	/// values, an endgame score and a middle game score, and interpolates
	/// between them based on the remaining material.
#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
	Value evaluate_debug(Position& pos) {
#else
	Value do_evaluate(Position& pos) {
#endif

		//////////////////////////////////////////////////////////////////////////	
		///
		EvalInfo ei;
		Thread* th = pos.this_thread();

		Score bonus = pos.psq_score(); // +(pos.side_to_move() == WHITE ? Tempo : -Tempo);       // 位置分?
		
		Square rk = pos.king_square(WHITE);
		Square bk = pos.king_square(BLACK);

		//////////////////////////////////////////////////////////////////////////	
		// Probe the material hash table
		bonus += make_score(pos.pMatinfo()->material, pos.pMatinfo()->material);  // 子力分	

		ei.pi = Pawns::probe(pos, th->pawnsTable);    // 兵的hash
		bonus += ei.pi->pawns_value();

		ei.rcan = ei.pi->getPawnCan(WHITE);
		ei.bcan = ei.pi->getPawnCan(BLACK);

		ei.rsafe = ei.bsafe = false;
		ei.evscore = 0;

		//------------------------------------------------------------------------
		// ei.attPoint[WHITE] = 红方攻击黑方的点数
		ei.attPoint[WHITE] = ei.pi->getAttpoint(WHITE);
		ei.attPoint[BLACK] = ei.pi->getAttpoint(BLACK);

		//////////////////////////////////////////////////////////////////////////
		// // 得到仕，兵的攻击情况
		Bitboard RpawnShiXiang = ei.pi->pawnshiXiang_attacks(WHITE);  //print_bb(RpawnShi);
		Bitboard BpawnShiXiang = ei.pi->pawnshiXiang_attacks(BLACK);  //print_bb(BpawnShi);

		//////////////////////////////////////////////////////////////////////////	
		// 清空可攻击的棋子。
		ei.attackedBy[RCHE] = ei.attackedBy[RMA]
			= ei.attackedBy[RPAO]  = _mm_setzero_si128();
		ei.attackedBy[BCHE] = ei.attackedBy[BMA]
			= ei.attackedBy[BPAO]  = _mm_setzero_si128();

		ei.KongPao[WHITE] = ei.KongPao[BLACK] = _mm_setzero_si128();   // 双方的空炮，要单独评价一下。

		//////////////////////////////////////////////////////////////////////////	
		// 处于攻击的棋格，兵共用一个棋格
		ei.attackKingBoard[WHITE] = m_and(ei.pi->attack_pawn(), UpBB[0x5]);    // 正在攻击状态的棋子
		ei.attackKingBoard[BLACK] = m_and(ei.pi->attack_pawn(), LowBB[0x4]);

		//////////////////////////////////////////////////////////////////////////	
		// 红帅
		ei.attackedBy[RKING] = one_rpawn_rk_attacks(rk);
		// 黑将
		ei.attackedBy[BKING] = one_bpawn_bk_attacks(bk);

		//////////////////////////////////////////////////////////////////////////	
		// 再评价一下将
		// fen C1bak4/4N4/9/9/2b6/9/9/3AK4/9/2B2A3 w - - 0 1
		// 我方的将不直接攻击对方的子，也要算一下Xbit哇

		if (ei.pi->_PawnInfo & R_KING_CANNOT_ATT) {
		}
		else {
			//////////////////////////////////////////////////////////////////////////	
			Bitboard bRnoChe = _mm_andnot_si128(pos.pieces(RCHE), pos.occupied_squares());
			Bitboard rkFatt = pos.Rook_attacks_bb_only_F(rk, bRnoChe);
			if (have_bit(rkFatt, ei.attackedBy[BKING])) {
				set_bit(ei.attackKingBoard[WHITE], rk);    // 红将也加入了进攻
				ei.attPoint[WHITE] += 3;
			} // fen 8c/5k3/9/9/N8/5r2P/9/B2AB4/3pA4/4K4 w - - 0 1
		}
		if (ei.pi->_PawnInfo & B_KING_CANNOT_ATT) {
		}
		else {
			Bitboard bBnoChe = _mm_andnot_si128(pos.pieces(BCHE), pos.occupied_squares());
			Bitboard bkFatt = pos.Rook_attacks_bb_only_F(bk, bBnoChe);
			if (have_bit(bkFatt, ei.attackedBy[RKING])) {   // 黑将也加入了进攻
				set_bit(ei.attackKingBoard[BLACK], bk);
				ei.attPoint[BLACK] += 3;
			}
		}

		//////////////////////////////////////////////////////////////////////////	
		// 将的牵制
		
		ei.xray_bit[WHITE] = ei.xray_bit[BLACK] = _mm_setzero_si128(); // 清空初牵制的棋子

		if (!(ei.pi->_PawnInfo & KING_CANNOT_STRING)) {
			Bitboard bet = m_and(BetweenBB[bk][rk], pos.occupied_squares());
			if (count_1s(bet) == 1) { // 二个将中间只有一个子
				if (have_bit(pos.pieces_of_color(WHITE), bet)) {
					ei.xray_bit[BLACK] = bet;  // 这个用来判断窝心马什么的。
					set_bit(ei.attackKingBoard[BLACK], bk);
				}
				else {
					ei.xray_bit[WHITE] = bet;
					set_bit(ei.attackKingBoard[WHITE], rk);
				}
			}
		}


		//////////////////////////////////////////////////////////////////////////	
		// 第一将评价每一个棋子的攻击情况.
		bonus += evaluate_pieces_no_include_king_first<WHITE>(pos, ei)
			- evaluate_pieces_no_include_king_first<BLACK>(pos, ei);

		// white
		ei.attackedBy[NO_PIECE] = m_or(RpawnShiXiang,
			m_or(ei.attacked_by(RCHE),
			m_or(ei.attacked_by(RMA),
			ei.attacked_by(RPAO))));

		// 棋子保护自己的棋子的得分，加强联系。
		Bitboard A = m_and(ei.attackedBy[NO_PIECE], pos.pieces_of_color(WHITE)); // 这个不能有炮，马，车，将
		Square t;
		while (pop_1st_bit_sq(A, t)) {
			bonus += Chess_Protect_Us_Score[pos.piece_on(t)];
		}

		// black
		ei.attackedBy[_X_X] = m_or(BpawnShiXiang,
			m_or(ei.attacked_by(BCHE),
			m_or(ei.attacked_by(BMA),
			ei.attacked_by(BPAO))));

		Bitboard B = m_and(ei.attackedBy[_X_X], pos.pieces_of_color(BLACK)); // 这个不能有炮，马，车，将
		while (pop_1st_bit_sq(B, t)) {
			bonus -= Chess_Protect_Us_Score[pos.piece_on(t)];
		}
		// 马的移动能力评估
		// 这个得放到最后
		bonus += evaluate_ma_mob<WHITE>(pos, ei)
			- evaluate_ma_mob<BLACK>(pos, ei);


		//////////////////////////////////////////////////////////////////////////	
		// 这个放牵制,或其它的攻击
		bonus += eval_weak_piece<WHITE>(pos, ei)      // 
			- eval_weak_piece<BLACK>(pos, ei);

		//////////////////////////////////////////////////////////////////////////	
		// 王的安全性评估
		bonus += eval_king_safe<WHITE>(pos, ei)  // fen 2bak4/1C1Ca4/1PP1b4/8p/4n4/9/8P/3AB4/4A1n2/2B2K1c1 b - - 0 
			- eval_king_safe<BLACK>(pos, ei);


		//////////////////////////////////////////////////////////////////////////	
		uint8 serchinfo = pos.pMatinfo()->searchInfo8;   //根据特殊的棋子子力要做的搜索	
		//////////////////////////////////////////////////////////////////////////
		// 只有一车<=1炮进攻时,对方的兵的加分
		if (serchinfo & (CK_Only_1Che1PaoxPawn + CK_BR_1CHE_4MAPAO)){

			if (serchinfo & CK_Only_1Che1PaoxPawn){
				if (pos.piece_count(RMA) == 0 && pos.piece_count(RPAO) == 1){
					bonus += eval_Only_1Che1PaoxPawn<WHITE>(pos, ei);
				}
				if (pos.piece_count(BMA) == 0 && pos.piece_count(BPAO) == 1){
					bonus -= eval_Only_1Che1PaoxPawn<BLACK>(pos, ei);
				}
			}

			// fen 4kab2/4a4/4b1c2/2n1Nn3/9/P7C/3cP1P1P/1R1CB1N2/4K4/2r2A3 b - - 0 1
			if (serchinfo & CK_BR_1CHE_4MAPAO){
				if ((pos.piece_count(RXIANG) + pos.piece_count(RSHI)) <= 2){
					if ((pos.piece_count(BXIANG) + pos.piece_count(BSHI)) == 4 && StoY(bk) == 0x0){
						int s = 32 * (4 - (pos.piece_count(RXIANG) + pos.piece_count(RSHI)));
						bonus -= spoint(s,s);
					}
				}
				if ((pos.piece_count(BXIANG) + pos.piece_count(BSHI)) <= 2){
					if ((pos.piece_count(RXIANG) + pos.piece_count(RSHI)) == 4 && StoY(rk) == 0x9){
						int s = 32 * (4 - (pos.piece_count(BXIANG) + pos.piece_count(BSHI)));
						bonus += spoint(s, s);
					}
				}
			}
		} // searchinfo8 


		// 残局的信息
		Value v = scale_by_game_phase(pos, ei, bonus);
		ASSERT(abs(v) < 15000);
		return (pos.side_to_move() == WHITE ? v : -v) + Eval::Tempo;
	}


#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
	Value do_evaluate(Position& pos) {

		ASSERT(!pos.in_check());

		Value val_old;
		Value val_r2b;
		Value val_mir;
//		Value dmargin;
		//EvalInfo mei;
		//Position mPOS(pos,0);
		
		val_old = evaluate_debug(pos);
		
		StateInfo tmp[2];
		Position mPOS;
		mPOS.set(pos.fen(), tmp, pos.this_thread());

		mPOS.board_mirror(pos);
		val_mir = evaluate_debug(mPOS);
		if(val_old != val_mir ){
			pos.board_display("previous fen");
			mPOS.board_display("mirror pos not same!!");
   		    MustOuPutEvalInf = true;
			val_old = evaluate_debug(pos);
			MustOuPutEvalInf = true;
			val_mir = evaluate_debug(mPOS);
			val_mir = val_mir;
		}

		mPOS.board_red2black(pos);
		val_r2b = evaluate_debug(mPOS);
		if(val_old != val_r2b){
			pos.board_display("previous fen");
			mPOS.board_display("r2b pos not same!!");
			MustOuPutEvalInf = true;
			val_old = evaluate_debug(pos);
			MustOuPutEvalInf = true;
			val_r2b = evaluate_debug(mPOS);
  			val_r2b = val_r2b;
		}
		return val_old;
	}
#endif

} // namespace Eval








