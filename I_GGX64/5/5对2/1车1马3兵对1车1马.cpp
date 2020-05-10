#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che1ma
#define END_my_m_MT_R_1che1ma3pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马3兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//const int PawnAdd = 32;

//我方1车1马2兵，对方1车1马
void my_m_MT_R_1che1ma3pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_CheMa_ByPawnByShi[your_shi_num]);

	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 3){
			MY_EV_SUB(128);
		}
	}

	// fen 4kab2/4a4/4b4/9/9/P2R4P/4Pr3/4B4/2nN5/4KA3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 2b1ka1n1/4a4/4b4/1N6R/9/6P2/P3P3P/9/4K4/3r5 w - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK2){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoY(mma) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 14);
		}
	}
}

//void m_MT_B_1che1ma3pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_CheMaPawn_CheMa_ByPawnByShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}
