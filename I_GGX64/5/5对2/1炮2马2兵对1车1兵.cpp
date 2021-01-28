#ifndef END_my_m_MT_R_1pao_2ma2pawn_B_1che1pawn
#define END_my_m_MT_R_1pao_2ma2pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马2兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1炮2马2兵对1车, 炮马方要加分

void my_m_MT_R_1pao_2ma2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	if(StoY(ypawn) MY_SMALL MY_RANK5 || my_shi_num > 0){
		MY_EV_ADD(Add_1炮2马对1车1兵);
	}

	// fen 4k4/4a4/1N3a3/1N7/3C5/2B6/4p4/9/4K4/3r5 b - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && (my_shi_num >= 1 || my_xiang_num >= 1)){
		if((your_shi_num + your_xiang_num) <= 2){
			MY_EV_ADD(96);
			if(your_xiang_num == 0){
				MY_EV_ADD(32);
			}
		}
	}

	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_1炮2马对1车1兵_byPawn_Shi[your_shi_num]);


}

//
//void m_MT_B_1pao_2ma2pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn > 0x80 || board->B_shi > 0){
//		board->mulScore -= Add_1炮2马对1车1兵;
//	}
//
//	//兵还有另外的加分
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  Add_1炮2马对1车1兵_byPawn_Shi[board->R_shi];
//		}
//	}
//
//	*/
//}