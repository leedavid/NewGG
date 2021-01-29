#ifndef END_my_m_MT_R_1che1ma1pawn_B_2pao1ma
#define END_my_m_MT_R_1che1ma1pawn_B_2pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马1兵对2炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_1che1ma1pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[your_shi_num]);


}
