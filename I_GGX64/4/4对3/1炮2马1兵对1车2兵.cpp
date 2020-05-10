#ifndef END_my_m_MT_R_1pao2ma1pawn_B_1che2pawn
#define END_my_m_MT_R_1pao2ma1pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮2马1兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2ma1pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

  
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 6P2/5k3/3ab1N2/p8/5N3/3C1r3/9/9/3KA4/5p3 w - - 0 1
	if(my_shi_num >= 1){
		if(have_bit(bb_your_pawn,RankBB_A[MY_RANK9])){  // 一个兵到了底线
			// 得到另一个兵
			Bitboard op = m_and(bb_your_pawn,MyUpBB[MY_RANK5]);
			if(m_have_bit(op)){
				MY_EV_ADD(32);
				Square np = pop_1st_bit_sq(op);
				if(abs(StoX(np) - 0x4) >= 2){
					MY_EV_ADD(32);
				}
				if(your_shi_num <= 1 && your_xiang_num <= 1){
					MY_EV_ADD(EV_MY_CAN * 32);
				}
			}
		}
	}

	// fen 3k1abC1/4a4/4b1P2/p2N5/3r1N3/9/9/9/4Ap3/3AK4 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(have_bit(bb_your_pawn,MyUpBB[MY_RANK5])){
			MY_EV_ADD(32);
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 9/4ak3/2Pa5/9/2bNr4/9/2N6/3K1C3/5p3/5p3 w - - 0 1
    //if(!have_bit(bb_your_pawn,MyLowBB[StoY(mk)]))
	if(count_1s(bb_your_pawn,MyLowBB[StoY(mk)]) == 2){
		MY_EV_ADD(96);
		if(StoY(mpao) == StoY(mk) 
			&& count_1s(ei.attacked_by(my_ma),bb_my_ma) == 2){
				MY_EV_ADD(64);

			if(have_bit(bb_your_pawn,MyUpBB[MY_RANK9]) && my_shi_num == 0 && my_xiang_num == 0){
				if(!IsOnSameSide(yk,mpawn)){
					RETRUN_MUL(8);
				}
			}
		}
	}

}

//void m_MT_B_1pao2ma1pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}


