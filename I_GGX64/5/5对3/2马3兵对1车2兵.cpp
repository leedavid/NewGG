#ifndef END_my_m_MT_R_2ma3pawn_B_1che2pawn
#define END_my_m_MT_R_2ma3pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马3兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_Che2Pawn_To_2MaXPawn_ByPawn[3]        =  { 96, 64, 32};  //车2兵,对2马x兵
//const int ADD_2MaXPawn_To_Che2Pawn_ByPawn[3]        =  { 96, 64, 32};  //车2兵,对2马x兵

void my_m_MT_R_2ma3pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_To_Che2Pawn_ByPawn[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_Che2Pawn_To_2MaXPawn_ByPawn[my_shi_num]);


	// fen 2ba5/4ak3/9/2P5p/p8/9/P3N3P/3AB1N2/6r2/2BAK4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(32);
			MY_EV_SUB(32 * (sint16)count_1s(bb_my_ma, MyLowBB[MY_RANK4]));
		}
	}

}

//void m_MT_B_2ma3pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_To_Che2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_Che2Pawn_To_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}
//



//m_MT_R_1che3pawn_B_3pawn