#ifndef END_my_m_MT_R_1pao_2ma1pawn_B_1che
#define END_my_m_MT_R_1pao_2ma1pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马1兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2炮1马对1车, 炮马方要加分

void my_m_MT_R_1pao_2ma1pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_1炮2马对1车_byPawn_Shi[your_shi_num]);

	MY_EV_ADD(Add_2炮1马对1车);
}


//void m_MT_B_1pao_2ma1pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  Add_1炮2马对1车_byPawn_Shi[board->R_shi];
//		}
//	}
//
//	board->mulScore -= Add_2炮1马对1车;
//
//	*/
//}