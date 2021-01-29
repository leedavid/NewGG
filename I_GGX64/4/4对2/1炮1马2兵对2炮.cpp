#ifndef END_my_m_MAT_R_1ma1pao2pawn_B_2paao
#define END_my_m_MAT_R_1ma1pao2pawn_B_2paao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马2兵对2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1ma1pao2pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Pao1MaXPawn_2Pao_ByPawnShi[your_shi_num]);

}

//void m_MAT_B_1ma1pao2pawn_R_2pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(pos,RKING);
//	
//	for(int from = PieceListStart(pos,BPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) < StoY(rk)){
//			pos.mulScore -= ADD_1Pao1MaXPawn_2Pao_ByPawnShi[pos.R_shi];
//		}
//
//	}
//
//	*/
//}