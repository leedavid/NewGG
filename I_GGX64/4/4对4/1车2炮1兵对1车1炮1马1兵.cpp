#ifndef END_m_MT_R_1che2pao1pawn_B_1che1pao1ma1pawn
#define END_m_MT_R_1che2pao1pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车2炮1兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che2pao1pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	//int mcan = EV_MY_CAN;
	//if(mcan == 0){
	//	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
	//		int ycan = EV_YOUR_CAN;
	//		MY_EV_SUB(ycan * ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan);
	//	}
	//}

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	MY_EV_SUB(EV_YOUR_CAN * 32);

	// fen 4k4/4a4/4b4/5R3/7r1/P5C2/1n2p4/4B4/4A4/1cCA1KB2 w - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		MY_EV_SUB(16);
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(16);
			if(abs(StoX(mpawn) - 0x4) == 4){
				MY_EV_SUB(16);
			}
		}
	}
}