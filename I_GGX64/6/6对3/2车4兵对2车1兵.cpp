#ifndef END_my_m_MT_R_2che4pawn_B_2che1pawn
#define END_my_m_MT_R_2che4pawn_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2³µ4±ø¶Ô2³µ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2che4pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2CheXPawn_2Che1Pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2CheXPawn_2Che1Pawn_ByShi[my_shi_num]);

	// fen 3a1kb2/4a4/4b4/5r2p/P8/R5R2/5rP1P/4B4/4A4/4K1B2 w - - 11 11
	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;
	if(ycan == 0){
		if((my_shi_num + my_xiang_num) >= 3 && PB90(MY_SQ55) == my_king){
			Square mche1 = S90_from_piecelist(POSITION,my_che,0);
			Square mche2 = S90_from_piecelist(POSITION,my_che,1);
			Bitboard rook = POSITION.Rook_attacks_bb(mche1);
			if(bit_is_set(rook,mche2)){
				MY_EV_ADD(96);
				MY_EV_ADD(mcan * 64);
			}
		}
	}

}

//void m_MT_B_2che4pawn_R_2che1pawn(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2CheXPawn_2Che1Pawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2CheXPawn_2Che1Pawn_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}