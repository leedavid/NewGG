#ifndef END_my_m_MT_R_1MA1PAWN_B_NO
#define END_my_m_MT_R_1MA1PAWN_B_NO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1兵对无.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//我方一马一兵，对方 0 attacker
void my_m_MT_R_1MA1PAWN_B_NO(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	int mycan  = EV_MY_CAN;
	Square yk     = your_king_pos;

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		MY_EV_SUB(32);
	}

	// fen 3a5/5k1N1/5a3/4P4/2b3b2/9/9/3AB4/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(64);
	}


	//RETRUN_MUL(16);

	// fen 4P4/3k5/3N4b/9/2b6/2B6/9/9/4A4/3K5 w - - 0 0
	if(mycan == 0){
		if((your_shi_num + your_xiang_num) > 1){
			if(StoY(yk) == MY_RANK1){
				if(PB90(yk MY_ADD 9) == my_ma){ // 马给对方的将牵制住了. 
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 9/4k4/4ba3/7N1/6b2/2B3P2/9/3AB4/4A4/5K3 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2){
		if (StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK5 && EV_MY_CAN == 0){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3a1k3/3P1N3/9/9/6b2/9/9/B4K3/4A4/9 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(mma) MY_SMALL_EQL MY_RANK2 && PB90(yk MY_ADD 0x9) == my_ma){
			if(!IsOnSameSide(mpawn,yk) && abs(StoX(mpawn) - StoX(yk)) >= 2){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 3P1k3/5N3/9/9/2b6/9/9/3A5/9/2B2K3 w - - 0 1
	if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK0){
		if(StoY(mma) MY_SMALL_EQL MY_RANK2 && PB90(yk MY_ADD 0x9) == my_ma){
			if(!IsOnSameSide(mpawn,yk) && abs(StoX(mpawn) - StoX(yk)) >= 2){
				if(StoX(yk) == 0x5 && have_bit(bb_your_xiang,RightBB[0x3])){
					RETRUN_MUL(2);
				}
				if(StoX(yk) == 0x3 && have_bit(bb_your_xiang,LeftBB[0x5])){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 4k2P1/1N2a4/3ab4/9/9/6B2/9/3A5/9/4KA3 w - - 0 1
	if ((your_shi_num + your_xiang_num) >= 3){
		if (StoY(mpawn) == MY_RANK0){
			if (abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5a3/3kaP3/2N5b/9/9/9/9/5K3/4A4/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,LeftBB[0x4]) && StoX(yk) == 0x3){
			RETRUN_MUL(2);
		}
		if(StoX(mpawn) < 0x4 && !have_bit(bb_your_shi,RightBB[0x4]) && StoX(yk) == 0x5){
			RETRUN_MUL(2);
		}
	}

	// fen 9/4k4/4ba3/7N1/6b2/2B3P2/9/3AB4/4A4/5K3 w - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1){
		if (EV_MY_CAN == 0 && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(2);
		}
	}

	// fen 3a2P2/4a4/3k5/6N2/6b2/2B6/9/3A5/9/3AK1B2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (StoY(mpawn) == MY_RANK0){
			if (StoX(mpawn) >= 0x6 && StoX(yk) == 0x3){
				RETRUN_MUL(2);
			}
			if (StoX(mpawn) <= 0x2 && StoX(yk) == 0x5){
				RETRUN_MUL(2);
			}
		}
	}

	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(2);
		}
		//if(StoY(mpawn) MY_SMALL MY_RANK2){
		//	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		//		RETRUN_MUL(2);
		//	}
		//}
		MY_EV_SUB(128); // 减一些分哇.

		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && !IsOnSameSide(mpawn,yk)){
			if(StoX(yk) == 0x3 && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(3);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(3);
			}
		}		
	}

	// fen 4k4/4a4/5a3/9/9/6B2/5n3/2pAB4/3KA4/9 w - - 0 0
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(mpawn) MY_SMALL MY_RANK2){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(3);
			}
		}
		MY_EV_SUB(128); // 减一些分哇.
	}

	// fen 5k3/3P1N3/3a5/9/2b3b2/9/9/4B4/4AK3/6B2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		//if(StoY(mma) MY_SMALL_EQL MY_RANK1 && PB90(yk MY_ADD 0x9) == my_ma){
		//	if(StoX)
		//}
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi 
				&& yk == MY_SQ05 && mma == MY_SQ0E){
					RETRUN_MUL(3);
			}
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi 
				&& yk == MY_SQ03 && mma == MY_SQ0C){
					RETRUN_MUL(3);
			}
		}
	}

	// fen 3a1k3/9/3ab4/9/2b6/6B2/2n6/3K5/4Ap3/3A5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL MY_RANK2){
			if(StoY(yk) MY_LARGE_EQL StoY(mpawn) ){
                  if(StoX(yk) < 0x4 && StoX(mpawn) > 0x4 && PB90(MY_SQ15) != your_shi){
					  RETRUN_MUL(3);
				  }
				  if(StoX(yk) > 0x4 && StoX(mpawn) < 0x4 && PB90(MY_SQ17) != your_shi){
					  RETRUN_MUL(3);
				  }
			}
		}
	}


	// fen 3a5/9/3a1k2b/9/9/9/9/4p2nB/4A4/3K1A3 w - - 120 120
	// 特殊和形
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoX(yk) != 0x7 && mpawn == MY_SQ16 
			&& PB90(MY_SQ0D) == your_shi){
				// 对方将上面的第一个棋子不是仕。
				if(PB90(yk MY_ADD 9) != your_shi
					&& PB90(yk MY_ADD 18) != your_shi){
						RETRUN_MUL(3);
				}
		}
	}
	// fen 4k1b2/9/3a1a3/9/6b2/6B2/9/1n1K1A3/4A1p2/6B2 w - - 20 20
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(IsOnSameSide(yk,mpawn) == FALSE){
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(3);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(3);
			}
		}
	}

	if(your_shi_num == 2 && your_xiang_num == 2){
		if(mycan == 0){
			RETRUN_MUL(3);
		} // fen k8/4a4/5a3/9/9/6B2/5n3/2pAB4/3KA4/9 w
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi
				|| StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){					
			}
			else{
				RETRUN_MUL(3);
			}
		}
	}

	// fen 3a5/5k1N1/5a3/4P4/2b3b2/9/9/3AB4/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		 if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			 RETRUN_MUL(3);
		 }
	}

	

	// fen 3P1k3/9/b3b2N1/9/9/6B2/9/4BA3/9/4KA3 b - - 0 1
	if(your_xiang_num == 2){
		if(StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(3);
		}
	}

	// fen 6b2/3ka1P2/4b4/9/7N1/6B2/9/B8/9/5K3 b - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1){
		if (StoX(mpawn) > 0x4 && StoX(yk) == 0x3 
			&& PB90(MY_SQ15) != your_shi){
			if (have_bit(bb_your_shi, LeftBB[0x5])){
				RETRUN_MUL(3);
			}
		}
		if (StoX(mpawn) < 0x4 && StoX(yk) == 0x5
			&& PB90(MY_SQ17) != your_shi){
			if (have_bit(bb_your_shi, RightBB[0x3])){
				RETRUN_MUL(3);
			}
		}
	}

	// fen 5k3/4a4/2Pa5/9/2b6/9/9/9/N2K5/6B2 b - - 122 122
	if(your_shi_num == 2 && your_xiang_num >= 1 
		&& StoY(yk) MY_SMALL_EQL MY_RANK1 ){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if(StoX(mpawn) > 0x4 && StoX(yk) == 0x3
					&& PB90(MY_SQ15) != your_shi){
						RETRUN_MUL(4);
				}
				if(StoX(mpawn) < 0x4 && StoX(yk) == 0x5
					&& PB90(MY_SQ17) != your_shi){
						RETRUN_MUL(4);
				}
			}
	}
	// fen 3P1k3/9/b3b2N1/9/9/6B2/9/4BA3/9/4KA3 b - - 0 190
	if(StoY(mpawn) == MY_RANK0 && your_xiang_num == 2){
		RETRUN_MUL(4);
	}

	// fen 3k2b2/6N2/3a4b/9/9/6P2/9/3K5/9/2BA5 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(EV_MY_CAN == 0 && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(4);
		}
	}

	/*RETRUN_MUL(16);*/

	// fen 4k1b2/4a4/3ab4/9/9/6B2/5p3/4BA3/4AK1n1/9 w - - 0 0 
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK2){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			RETRUN_MUL(4);
		}
	}

	// fen 4P4/4a4/b2a1k3/6N2/9/2B6/9/3A5/9/3K5 w - - 0 111
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == mpawn){
		if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
			RETRUN_MUL(2);
		}
		if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
			RETRUN_MUL(2);
		}
	}

	//RETRUN_MUL(16);

	// fen 9/4ak3/3Pb4/8N/6b2/9/9/B8/9/4K4 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 
		&& StoY(mpawn) MY_SMALL_EQL MY_RANK2 
		&& StoY(yk) != MY_RANK0 && PB90(MY_SQ0D) == your_shi){
		if(StoX(mpawn) <= 0x3 && StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
			RETRUN_MUL(8);
		}
		if(StoX(mpawn) >= 0x5 && StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
			RETRUN_MUL(8);
		}
	}

	


	// fen 1P1k5/4a4/4b4/9/9/4N4/9/4B4/4A4/4K1B2 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(8);
	}

	// fen 3k2b2/6N2/3a4b/9/9/6P2/9/3K5/9/2BA5 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(8);
		}
	}

	// fen 2b6/3k5/9/9/6b2/4n4/9/3AB4/5p3/2BK1A3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (!IsOnSameSide(yk, mpawn)){
			RETRUN_MUL(8);
		}
	}
}


// fen 5k3/9/3Pb4/9/9/9/9/9/9/4K1B2 b - - 0 0

