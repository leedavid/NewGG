#ifndef END_my_m_MT_R_1pao1ma_4pawn_B_1ma
#define END_my_m_MT_R_1pao1ma_4pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马4兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//还有就是马过河了

void my_m_MT_R_1pao1ma_4pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_1Ma[your_shi_num]);

	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	
	//1, 我方的马要过河
	if(StoY(mma) MY_SMALL MY_RANK5){
		MY_EV_ADD(MaPaoXPawn_Vs_Ma_PaoMao_Over_River);
	}

	MY_EV_ADD(MaPaoXPawn_Ma);
}

//void m_MT_B_1pao1ma_4pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_1Ma[board->R_shi];
//		}
//	}
//
//
//	int bma = PieceListStart(board,BMA);
//
//	//1, 我方的马要过河
//	if(bma > 0x80){
//		board->mulScore -= MaPaoXPawn_Vs_Ma_PaoMao_Over_River;
//	}
//
//	//马炮方另外加分
//	board->mulScore -= MaPaoXPawn_Ma  ;
//
//
//	*/
//}