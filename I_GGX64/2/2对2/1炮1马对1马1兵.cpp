#ifndef END_my_m_MT_R_1pao1ma_B_1ma1pawn
#define END_my_m_MT_R_1pao1ma_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	//MY_EV_ADD(96);

	//Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square yk = your_king_pos;
	Square mk = my_king_pos;

	if(my_shi_num >= 1){
		MY_EV_ADD(64);
	}

	// fen 4k1b2/9/3a1a3/9/6b2/9/1n7/1C1pB1N2/9/5K3 w - - 0 1
	if(abs(StoY(ypawn) - StoY(mk)) >= 2 || abs(StoX(ypawn) - StoX(mk)) >= 2){
		MY_EV_ADD(128);
		if(my_xiang_num >= 1){
			MY_EV_ADD(64);
		}
	}

	// fen 3k5/4a4/3ab4/2p1C2N1/2b6/2B6/5n3/B8/4A4/3A1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(64);
	}
	

	if((your_shi_num + your_xiang_num) <= 3){
		if(my_shi_num >= 1){
			MY_EV_ADD(64);
		}
	}

	if((your_shi_num + your_xiang_num) >= 3){
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
		}
		MY_EV_SUB(64);
	}
	//如果红方
	// fen 3k5/9/9/5NC2/9/9/9/2n6/4p4/5K3 w - - 0 0 
	if((my_shi_num + my_xiang_num) == 0){
		if(PB90(MY_SQ4C) == your_pawn && StoY(mk) == MY_RANK9){
			MY_EV_SUB(128);
			RETRUN_MUL(4);
		}
	}

	// fen 4k1b2/4a4/4ba3/3N5/9/2B6/3C5/3KB4/n8/5p3 w - - 0 1
	if(my_shi_num == 0){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!bit_is_set(EV_MY_XBIT,yma)){
			    RETRUN_MUL(6);
			}			
		}
	}

	// fen 2bk5/4a4/4ba3/3N5/9/6B2/1C6n/3AB4/2p2K3/3A5 w - - 120 120
	//如果兵方已过河,则减一些分
	if((your_shi_num + your_xiang_num) == 4){

		MY_EV_SUB(EV_YOUR_CAN * 128);

		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(ypawn) == MY_RANK6){
				if(abs(StoX(ypawn) - 0x4) <= 1){
					RETRUN_MUL(6);
				}
				RETRUN_MUL(8);
			}
		}

		if(my_shi_num == 0){
			RETRUN_MUL(8);
		}
	}

	// fen 6b2/4k4/9/4C4/6b2/2B6/3p1N3/1n7/4A4/3K5 b - - 54 54
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num <= 1 && my_xiang_num <= 1){
			if(StoY(ypawn) == MY_RANK6){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 4k4/4a4/4ba3/9/2p3b2/9/4N4/3A1K1n1/9/7C1 w - - 126 126
	if(my_xiang_num == 0 && my_shi_num <= 1){
		if((your_shi_num + your_xiang_num) == 4){
			if(StoY(yk) == MY_RANK1){
				MY_EV_SUB(96);
				if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3k5/4a4/3ab4/2p1C2N1/2b6/2B6/5n3/B8/4A4/3A1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(abs(StoY(yma) - MY_RANK4) <= 2){
			RETRUN_MUL(8);
		}
	}

	// fen 2ba5/5k1N1/4b4/9/4p4/1C7/8n/9/4K4/5A3 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && EV_YOUR_CAN >= 1 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			if(your_xiang_num == 2 && your_shi_num >= 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bN5/4k4/4b4/9/4p4/1C7/9/6n2/9/4K4 r
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num == 0 && my_xiang_num == 0){
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
				RETRUN_MUL(8);
			}
		}
	}


	// fen 9/3k5/4b4/3NC4/2b6/9/3p5/4n4/4A4/3A1K3 r
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	     if(StoY(ypawn) == MY_RANK6){
			 MY_EV_SUB(96);
			 if(my_xiang_num == 0){
				 RETRUN_MUL(8);
			 }
			 RETRUN_MUL(12);
		 }
		 if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			 if((my_shi_num + my_xiang_num) <= 1){
				 RETRUN_MUL(12);
			 }
		 }
	}



}

