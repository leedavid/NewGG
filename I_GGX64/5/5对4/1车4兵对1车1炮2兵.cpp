#ifndef END_my_m_MT_R_1che4pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che4pawn_B_1che1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对1车1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[3]    = {96, 64, 16};            //车炮X兵对车2兵_兵的加分
//const int  ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[3]    = {96, 64, 32};            //车2兵_兵对车炮X兵的加分


//m_MT_R_1che4pawn_B_1che1pao2pawn
void my_m_MT_R_1che4pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[my_shi_num]);

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	Square mk = my_king_pos;

	// fen 2baka3/R2C1r3/4b4/2p5p/p8/2P3B1P/p8/3A5/9/4KAB2 b
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		//Square mche = S90_from_piecelist(POSITION,my_che,0);
		//Square yche = S90_from_piecelist(POSITION,your_che,0);
		//Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	    int ycan = EV_YOUR_CAN;

		if(ycan == 0){
			//int mcan = EV_MY_CAN;

			Bitboard ybmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
			MY_EV_ADD((sint16)count_1s(ybmp) * ADD_ChePaoString_OtPawn);

		}
	}

	// fen 2b1k4/4a4/b2a5/p8/3R4p/P1PcP4/8P/3r5/4K4/2B3B2 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if(isStringByChe(POSITION,mche,ypao,yche) && StoY(mk) MY_LARGE_EQL MY_RANK8){

			MY_EV_ADD(64);

			if(StoX(ypao) == StoX(yche) && StoY(yche) MY_LARGE_EQL StoY(ypao)){
				if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
					MY_EV_ADD(128);
					MY_EV_ADD(EV_MY_CAN * 32);
				}
			}
		}
	}


}

//void m_MT_B_1che4pawn_R_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[board->R_shi];
//		}
//	}
//
//	int rche = PieceListStart(board,RCHE);
//	int bche = PieceListStart(board,BCHE);
//	int rpao = PieceListStart(board,RPAO);
//
//	// fen 2baka3/R2C1r3/4b4/2p5p/p8/2P3B1P/p8/3A5/9/4KAB2 b
//	if(board->B_shi == 2 && board->B_xiang == 2 && board->b256[0x37] == BKING){
//		if(IsStringByChe(board,rche,rpao,bche)){
//			if(rcan == 0){
//				if(bcan >= 1){
//					for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//						if(StoY(from) < StoY(rk)){
//							board->mulScore -= ADD_ChePaoString_OtPawn;
//						}
//					}
//				}
//			}
//		}
//	}
//
//
//
//	*/
//}



