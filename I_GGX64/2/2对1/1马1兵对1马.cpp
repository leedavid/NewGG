#ifndef END_my_m_MT_R_1MA1PAWN_B_1MA
#define END_my_m_MT_R_1MA1PAWN_B_1MA
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马1兵对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
//const int ADD_1马兵对1马兵_by_Pawn  = 20;

//我方一马一兵，对方一马
void my_m_MT_R_1MA1PAWN_B_1MA(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	int mcan  = EV_MY_CAN;
	Square yk    = your_king_pos;
	Square mk    = my_king_pos;

	if(StoY(mk) == MY_RANK7){
		MY_EV_ADD(96);
	}

	// fen 4k4/4a4/4P4/5n3/9/5N3/9/8B/9/2B1K4 b - - 0 1
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_SUB(80);
		}
	}
	
	//红兵到底了
	if(StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(1);
	}
	// fen 2ba1k3/4a4/4b4/9/5N3/9/3n5/3AB1p2/4A4/4K4 w
	//RETRUN_MUL(1);

	//马高兵例和马象 //象棋殘局例典 22局, 85页
	if(your_xiang_num >= 1 && StoY(yma) MY_SMALL_EQL MY_RANK4){
		RETRUN_MUL(2);
	}
	//对方有2仕
	if(your_shi_num == 2){
		RETRUN_MUL(2);
	}
	// 马低兵例和马仕 //象棋殘局例典 22局, 67页
	// fen 3a1k3/2P6/9/2N1n4/9/9/9/9/9/4K4 w 
	if(your_shi_num != 0 && StoY(mpawn) MY_SMALL MY_RANK2 && StoY(yma) MY_SMALL_EQL MY_RANK4){
		RETRUN_MUL(2);
	}

	// fen 5k3/3P5/3ab3b/9/9/9/8N/5A3/4K4/6Bn1 w - - 46 46
	if(your_shi_num != 0 && your_xiang_num == 2){
		if(abs(StoY(yma) - StoY(mma)) <= 3){
			RETRUN_MUL(2);
		}
	}
	// fen 9/3P5/4k3b/9/2N6/9/9/1n2BA3/9/3K5 b - - 15 15
	// 
	if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL StoY(yk)){
		RETRUN_MUL(2);
	}

	if(your_xiang_num == 2 && mcan == 0){
		RETRUN_MUL(2);
	}

	// fen 6b2/1N2a4/3a1k3/9/6b2/1nB6/9/7p1/3KA4/9 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK0 && MY_SQ0D == mpawn){
		}
		else{
			RETRUN_MUL(2);
		}
	}

	// fen 3a5/5k3/4P4/1N7/1n7/2B6/9/5A3/4A4/4K1B2 w - - 0 102
	if(your_shi_num >= 1 && StoY(yma) MY_SMALL_EQL MY_RANK5){

		if(StoY(yk) == MY_RANK1){
			if(PB90(MY_SQ03) == your_shi || PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(2);
			}			
		}
	}

	// fen 5k3/9/b3b4/5NP2/9/2n6/9/8B/4A4/4K4 w - - 0 1
	if(your_xiang_num == 2){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(yma) MY_SMALL_EQL MY_RANK5){
			RETRUN_MUL(4);
		}
	}

	// fen 3a5/5k3/4P4/1N7/1n7/2B6/9/5A3/4A4/4K1B2 w - - 0 102
	if(your_shi_num >= 1 && StoY(yma) MY_SMALL_EQL MY_RANK5){

		if(StoY(yk) == MY_RANK1){
			RETRUN_MUL(4);
		}

		// fen 3a1k3/9/4P4/4n1N2/9/2B3B2/9/3K1A3/9/5A3 b - - 0 1
		if(MY_SQ16 == mpawn && MY_SQ1F == yma){
			RETRUN_MUL(6);
		}

		// fen 3a1k3/9/4P4/4n4/3N5/9/9/3A1A3/9/3K5 b - - 0 112
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(6);
			}
		}
		
		RETRUN_MUL(8);
	}
}

