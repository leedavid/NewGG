#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che4pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che4pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对1车4兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[3]    = {96, 64, 16};            //车炮X兵对车2兵_兵的加分
//const int  ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[3]    = {96, 64, 32};            //车2兵_兵对车炮X兵的加分

void my_m_MT_R_1che1pao3pawn_B_1che4pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[my_shi_num]);

	// fen 2baka3/R2C1r3/4b4/2p5p/p8/2P3B1P/P3p4/3A5/9/4KAB2 b - - 12 12
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		Square mche = S90_from_piecelist(POSITION,my_che,0);
		Square mpao = S90_from_piecelist(POSITION,my_pao,0);
		Square yche = S90_from_piecelist(POSITION,your_che,0);

		if(isStringByChe(POSITION,mche,mpao,yche)){
			int mcan = EV_MY_CAN;
			if(mcan == 0){
				int ycan = EV_YOUR_CAN;
				if(ycan >= 1){
					MY_EV_SUB((sint16)count_1s(ymp) * 48);
				}
			}
		}
	}

	//if(board->B_shi == 2 && board->B_xiang == 2 && board->b256[0x37] == BKING){
	//	if(IsStringByChe(board,rche,rpao,bche)){
	//		if(rcan == 0){
	//			if(bcan >= 1){
	//				for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
	//					if(StoY(from) < StoY(rk)){
	//						board->mulScore -= ADD_ChePaoString_OtPawn;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}



	//*/
}

//void m_MT_B_1che1pao3pawn_R_1che4pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[board->R_shi];
//		}
//	}
//
//	int rche = PieceListStart(board,RCHE);
//	int bche = PieceListStart(board,BCHE);
//	int bpao = PieceListStart(board,BPAO);
//
//	// fen 2baka3/R2C1r3/4b4/2p5p/p8/2P3B1P/P3p4/3A5/9/4KAB2 b - - 12 12
//	if(board->R_shi == 2 && board->R_xiang == 2 && board->b256[0xc7] == RKING){
//		if(IsStringByChe(board,rche,bpao,bche)){
//			if(bcan == 0){
//				if(rcan >= 1){
//					for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//						if(StoY(from) > StoY(bk)){
//							board->mulScore += ADD_ChePaoString_OtPawn;
//						}
//					}
//				}
//			}
//		}
//	}
//
//	*/
//}
//

