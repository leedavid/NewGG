#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮3兵对1车1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2baka3/9/2n1b4/2C2PP2/P1P5p/9/8P/1r2B2R1/4A4/3AK3c b - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2 && EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	//fen C3ka3/4a2P1/P1c1b4/4p4/P8/4n4/7R1/4B4/1r2A4/3AK1B2 b - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0){
		Bitboard bp = m_and(bb_my_pawn, m_or(LeftBB[0x1], RightBB[0x7]));
		if (count_1s(bp) >= 2){
			MY_EV_SUB(32);
		}
		if (StoY(yma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(16);
		}
		if (your_xiang_num >= 1){
			MY_EV_SUB(16);
		}
	}
}

//void m_MT_B_1che1pao5pawn_R_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}


