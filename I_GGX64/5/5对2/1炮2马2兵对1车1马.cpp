#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1che1ma
#define END_my_m_MT_R_1pao2ma2pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马2兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2ma2pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXPawn_1Che1Ma_To_ByPawn[your_shi_num]);

	// fen 3a1k3/4a4/8b/5N2C/9/3r2P2/P4n3/3NB4/4A4/2B1KA3 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(32);
		}
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(64);
		}
	}

	// fen 4k4/4a1P2/3ab2rb/9/2n6/6P2/6N2/3AB3N/4A1C2/2B1K4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if(EV_MY_CAN <= 1){
				MY_EV_SUB(32);
				if(!have_bit(bb_my_ma,MyUpBB[MY_RANK5])){
					RETRUN_MUL(8);
				}
			}
		}
	}
}

//void m_MT_B_1pao2ma2pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao2MaXPawn_1Che1Ma_To_ByPawn[board->R_shi];
//		}
//	}
//
//	
//	*/
//}




//m_MT_R_2pao1ma1pawn_B_1che1pao(