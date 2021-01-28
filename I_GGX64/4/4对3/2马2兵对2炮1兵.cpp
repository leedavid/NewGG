#ifndef END_my_m_MT_R_2ma2pawn_B_2pao1pawn
#define END_my_m_MT_R_2ma2pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马2兵对2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma2pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_2Pao1Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2Pao1Pawn_2MaXPawn_ByPawn[my_shi_num]);
	

	if(EV_MY_CAN == 2){
		MY_EV_ADD(EV_MY_CAN * 24);
	}

	// fen 2bak4/4a4/3cb4/4Nc2p/P8/2B6/2P6/4B4/4A4/2NAK4 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}

    // fen 5a3/3ka4/2N6/3P5/p1b1cNb2/5c3/P8/B8/3K5/3A5 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			RETRUN_MUL(12);
		}
	}

}

//void m_MT_B_2ma2pawn_R_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Pawn_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_2Pao1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 2bak4/4a4/3cb4/4Nc2p/P8/2B6/2P6/4B4/4A4/2NAK4 w - - 0 0
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		return 8;
//	}
//
//	*/
//
//}
