#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1ma
#define END_my_m_MT_R_1che1pao3pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮3兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//const int pawnAdd = 32;

void my_m_MT_R_1che1pao3pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_CheMa_ByPawnByShi[your_shi_num]);

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	if((my_shi_num + my_xiang_num) <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK4){
		MY_EV_SUB(128);
	}

	// fen 3k1ab2/4a4/4b4/C3R4/1r7/P8/8P/3A5/3KA1n2/9 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(!IsOnSameSide(yma,mk)){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// 如果我方有连兵，也要加分, 主要是可以以车换马
	// fen 2b1ka3/4a4/4b4/9/3PPP3/3r5/1R3n3/5C3/4K4/9 b - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
		MY_EV_ADD(64);
		Bitboard p = m_and(bb_my_pawn,
			m_or(RankBB_A[MY_RANK3],RankBB_A[MY_RANK4]));
		if(count_1s(p) == 3){
			MY_EV_ADD(96);
		}
	}
}

//void m_MT_B_1che1pao3pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
//	
//	/*for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  ADD_ChePaoPawn_CheMa_ByPawnByShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}
