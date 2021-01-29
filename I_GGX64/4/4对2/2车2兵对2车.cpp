#ifndef END_my_m_MT_R_2che2pawn_B_2che
#define END_my_m_MT_R_2che2pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车2兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int const_Shi_add[3] = { 128, 48, 0};
//const int const_Pawn_add   = 64;

void my_m_MT_R_2che2pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2车x兵对2车_byPawn[your_shi_num]);

	// fen 2b1ka3/4a4/4b4/3r5/PR3P3/1R7/5r3/9/4A4/4KA3 w - - 0 1
	if(my_shi_num == 2 && mk == MY_SQ55){
		MY_EV_ADD(EV_MY_CAN * 24);
	}
}
//
//void m_MT_B_2che2pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	//uint16 Info16 = board->pMat->sixiangInfo8;
//
//	//if(Info16 & CK_R_2s){
//	//	board->mulScore += 128;
//	//}
//	//else if(Info16 & CK_R_1s){
//	//	board->mulScore += 48;
//	//}
//
//
//	//if(Info16 & CK_B_2s){
//	//	board->mulScore -= 128;
//	//}
//	//else if(Info16 & CK_B_1s){
//	//	board->mulScore -= 48;
//	//}
//
//	board->mulScore += const_Shi_add[board->B_shi];
//	board->mulScore -= const_Shi_add[board->R_shi];
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= const_Pawn_add;
//		}
//	}
//
//
//	*/
//}
