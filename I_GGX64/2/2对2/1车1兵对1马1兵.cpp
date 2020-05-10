#ifndef END_my_m_MT_R_1che1pawn_B_1ma1pawn
#define END_my_m_MT_R_1che1pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// fen 9/3P5/4k4/9/2b3b2/6B2/9/3AB4/r3Ap3/C3K4 w - - 44 44

//const int ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[3]  =  { 80, 48, 16};  //炮兵对车兵,炮方安全后,有兵的加分 
//
//车兵对马兵
void my_m_MT_R_1che1pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	//
    int mcan = EV_MY_CAN;
	Square yk   = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_CheXPawn_To_MaPawn_PawnByShi[your_shi_num]);
	}

	MY_EV_ADD(ADD_CheXPawn_To_MaPawn);
	// fen 3aka3/9/4b4/pR7/2n3b2/2B6/P8/8B/4A4/4KA3 w
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		// fen 3ak4/4a4/b8/8p/6b2/2B3N2/7rP/4B4/9/3AKA3 w - - 4 4
		//对方是仕相全,且一个兵不能过河
		if(StoY(mpawn) MY_LARGE MY_RANK4 && mcan == 0){
			if(StoY(yk) == MY_RANK0){
				RETRUN_MUL(2);
			}
		}		

		// fen 3ak1b2/1P2a4/4bn3/5R3/9/2B6/9/3A2p2/4A4/2B2K3 w - - 33 33
		//车低兵对马仕相全
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ16) == your_xiang){
			if(StoX(mpawn) < 0x4){
				if(MY_SQ17 == yma){
					RETRUN_MUL(2);
				}
			}
			if(StoX(mpawn) > 0x4){
				if(MY_SQ15 == yma){
					RETRUN_MUL(2);
				}
			}
		}		

		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(8);
		}

		// fen 1P3k3/4a4/4ba3/9/9/9/1pr6/4B4/4A4/N1BA1K3 w - - 0 1
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK4) {
			RETRUN_MUL(8);
		}

	}

	

}

