#ifndef END_my_m_MT_R_1che4pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che4pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che4pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;

	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_1Che1Ma1Pawn_ByPawn[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Che1Ma1Pawn_To_CheXPawn_ByPawn[my_shi_num]);

	// fen 2bak4/4aPP2/4b4/p8/9/3Rnr2P/P8/8B/4A4/3K5 b - - 0 1
	if(EV_YOUR_CAN == 0 && my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if(isStringByChe(POSITION,mche,yma,yche)){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
	// fen 2b1kab2/4a4/9/p2P5/9/P4nP2/2r5P/1R2B4/4A4/2BK1A3 b - - 0 1
	// fen 2bakn3/4a4/4b4/9/R1p6/4r1P2/P1P5P/4B4/9/2BAKA3 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
			if (StoY(yma) MY_SMALL_EQL MY_RANK3
				|| StoY(ypawn) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 16);

				if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
					if (count_1s(bb_my_pawn, MyLowBB[MY_RANK4]) >= 3){
						RETRUN_MUL(10);
					}
				}
			}
		}
	}
}

//void m_MT_B_1che4pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Che1Ma1Pawn_To_CheXPawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheXPawn_To_1Che1Ma1Pawn_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn