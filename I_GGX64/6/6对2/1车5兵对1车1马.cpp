#ifndef END_my_m_MT_R_1che5pawn_B_1che1ma
#define END_my_m_MT_R_1che5pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车5兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 





void my_m_MT_R_1che5pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]);

	if((my_shi_num + my_xiang_num) <= 1){
		MY_EV_SUB(ADD_ChePawn_To_CheMa_Pawn_SX_LessOne);
	}

	if((my_shi_num + my_xiang_num) >= 3 && StoY(my_king_pos) != MY_RANK7){
		MY_EV_ADD(128);
	}
}

//void m_MT_B_1che5pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_ChePawn_To_CheMa_By_PawnByShi[board->R_shi];
//		}
//	}
//
//	//如果兵方一个子也没有了
//	if((board->B_shi + board->B_xiang)<= 1){
//		board->mulScore += ADD_ChePawn_To_CheMa_Pawn_SX_LessOne ;
//	}
//
//	Square bk = PieceListStart(board,BKING);
//	if((board->B_shi + board->B_xiang) >= 3 && StoY(bk) != 0x5 ){   //兵方安全了
//		board->mulScore -= 128;
//	}
//
//
//	*/
//}