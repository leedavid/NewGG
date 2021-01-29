#ifndef END_my_m_MT_R_1che5pawn_B_1che1pao
#define END_my_m_MT_R_1che5pawn_B_1che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车5兵对1车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

////const int const_Pawn_Shi_Add[3] = {180, 120, 32};

//车3兵对车炮
void my_m_MT_R_1che5pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	//看一下对方是不是有仕

	// fen 2bak4/9/4b4/4R4/P3c4/4r1P2/8P/4B4/9/2B1KA3 b - - 0 0 //这个FEN 应是红优

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	if((my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]);
	}
	else{
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]/2);
	}

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	
	if(isStringByChe(POSITION,mche,ypao,yche)){
		MY_EV_ADD(ADD_ChePawn_To_ChePao_By_StringPao);
	}
}

