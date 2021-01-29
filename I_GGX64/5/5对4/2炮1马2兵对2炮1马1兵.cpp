#ifndef END_my_m_MT_R_2pao1ma2pawn_B_2pao1ma1pawn
#define END_my_m_MT_R_2pao1ma2pawn_B_2pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮1马2兵对2炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_2pao1ma2pawn_B_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
	int malr  = My_pawn_already_over_river(POSITION);
	int yalr  = Your_pawn_already_over_river(POSITION);
	//MY_EV_ADD((malr - yalr) * 16);
	MY_EV_ADD((malr - yalr) * 16);
	
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	// fen 2ba1k3/4a4/2n1b3c/4C2N1/9/p1B1P1P2/2C6/B2A2c2/9/4K4 w - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && abs(StoX(ypawn) - 0x4) >= 4){
		if((my_shi_num + my_xiang_num) >= 3){
		     MY_EV_ADD(EV_MY_CAN * 16);
		}
		MY_EV_ADD(32);
	}

	// fen 5k1C1/7c1/b2a1a3/5c3/7C1/2PNn4/P8/4Bp3/4K4/2BA1A3 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			if(StoY(mk) != MY_RANK9 && have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 2bak1b2/4a4/3c3n1/9/3C1N2P/6B2/4P4/B2A5/2p1ACc2/4K4 b - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK8){
		if(my_shi_num == 2 && my_xiang_num >= 1){
			if(StoX(ypawn) < 0x4 && PB90(MY_SQ42) == my_shi){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
			if(StoX(ypawn) > 0x4 && PB90(MY_SQ44) == my_shi){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

}

//void m_MT_B_2pao1ma2pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square rpawn = PieceListStart(board,RPAWN);
//	int bcan = BpawnCanOverLiver(board);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma1pawn_To_2Pao1MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
//	if(StoY(rpawn) >= 0x8 && bcan >= 0 && BpawnAlreadyRiver(board) >= 1){
//		board->mulScore -= bcan * 16;
//	}
//
//	
//
//
//	*/
//
//	//printf_s(" m_MT_B_2pao1ma2pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei)");
//}