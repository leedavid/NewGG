#ifndef END_my_m_MT_R_1che1ma2pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1che1ma2pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对1车2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int ADD_ChePaoXPawn_To_1Pao1Ma1Pawn_ByPawn[3]    =  { 96, 64, 32};  //车炮X兵,对2炮1兵
//const int ADD_1Pao1Ma1Pawn_To_ChePaoXPawn_ByPawn[3]    =  { 96, 64, 32};  //车炮X兵,对2炮1兵


void my_m_MT_R_1che1ma2pawn_B_1che2pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_CheMaPao_ByPawnByShi[your_shi_num]);

	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

}