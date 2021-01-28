#ifndef END_my_m_MT_R_1PAO1PAWN_B_1PAWN
#define END_my_m_MT_R_1PAO1PAWN_B_1PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h" 
#include "..\\..\\endgame\mat.h"
#include "1炮1兵对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//const int absPPscore[10] =  {104,96,80,72,64,56,48,32,24,8};
//const int PaoXsamePawn   =   32;
                     //0,1,2,3,4,5,6,7,8,9

//我方是炮兵，对方一个兵
void my_m_MT_R_1PAO1PAWN_B_1PAWN(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	int mcan = EV_MY_CAN;

	// 炮兵方的别外加分
	MY_EV_ADD(ADD_1PaoXPawn_1Pawn);

	// fen 3k5/4aP3/4ba3/9/2b6/2B3C2/9/3A1A3/4p4/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(128);
	}

	// fen 1C4b2/5k3/3a5/9/9/8P/1p7/4B4/4K4/2B6 r
	if (my_shi_num == 0 && your_shi_num >= 1 && your_xiang_num >= 1){
		if (StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(128);
		}
	}


	// fen 4k4/9/9/8p/4P4/9/9/6C2/9/4K4 w - - 0 0
    if(my_shi_num == 0 && my_xiang_num == 0){
		if(StoY(ypawn) MY_SMALL MY_RANK7){
			//if(StoY(mpawn) MY_SMALL (StoY(ypawn) MY_SUB 1)){
			//	RETRUN_MUL(1); // fen 4k4/9/9/4P3p/9/9/9/6C2/9/4K4 w
			//}
			if(StoY(ypawn) MY_LARGE MY_RANK4){
				RETRUN_MUL(1);  // fen 4k4/9/9/9/4P3p/9/9/6C2/9/4K4 w
			}
		}
	}
	// 炮兵方的兵不能过河
	// fen 3k1a3/9/5a2b/4c1p2/2b6/6P2/9/B3B4/4A4/4K4 b - - 0 0
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ2A) == your_pawn && PB90(MY_SQ3C) == my_pawn){
				RETRUN_MUL(1);
			}
			if(PB90(MY_SQ26) == your_pawn && PB90(MY_SQ38) == my_pawn){
				RETRUN_MUL(1);
			}
		}
	}

	//如果对方是仕相全,高兵,就和了
	// fen 1C2ka3/4a4/4b4/9/p1b6/6B2/P8/9/9/2BAKA3 w - - 3 3
	//not he
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(1);
		}
	}



	//
	if(FALSE){
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//炮方没有仕
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if(my_shi_num == 0){
		//*************************************************************************
		//1, 如果我方的兵到底了就和了
		if(StoY(mpawn) MY_SMALL MY_RANK1){
			RETRUN_MUL(1);
		}
		//*************************************************************************
		//2,如果对方是有双仕,高兵,则难胜
		if(your_shi_num == 2){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				RETRUN_MUL(1);
			}
		}
		//<<象棋残局例典>> 炮高兵例和双象 121
		if(your_xiang_num == 2){
			if(my_xiang_num == 0){
				RETRUN_MUL(1);
			}
		}
		// fen 2C6/3P5/b4k3/9/9/9/9/9/4K4/4p4 w - - 104 104
		//炮兵的兵到了对方将的下面
		if(StoY(yk) MY_LARGE StoY(mpawn)){
			if(your_xiang_num != 0){
				RETRUN_MUL(1);
			}
		}
		// 
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(abs(StoY(mpawn) - StoY(yk)) <= 1){
				if(your_xiang_num != 0 && my_xiang_num == 0){
					RETRUN_MUL(1);
				}
			}
		}

		// fen 3k5/4P4/3a5/9/9/2B6/2p6/9/3K5/1C7 w - - 0 1
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if (abs(StoY(mpawn) - StoY(yk)) <= 1){
				if (StoY(ypawn) == MY_RANK6 && StoX(ypawn) != StoX(mk)){
					RETRUN_MUL(1);
				}
			}
		}

		// fen 9/6P2/4k4/9/9/9/5p3/9/C8/2B2KB2 b - - 0 1
		if(StoY(mpawn) MY_SMALL StoY(yk) && StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(2);
		}

		
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//炮方有1仕
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if(my_shi_num == 1){
		// fen 5kC2/4P4/9/9/2b6/9/9/9/5p3/3AK4 w - - 0 0
		// 如果炮兵方只有一个仕,且被兵方的兵控制住了, 而且兵方有其它的棋子可走!! 红方炮兵,黑方兵
		if(your_xiang_num != 0){
			if(MY_SQ4B == ypawn || MY_SQ4D == ypawn){
				if(StoY(my_king_pos) == MY_RANK9){
					if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
						if(PB90(MY_SQ54) == my_shi || PB90(MY_SQ56) == my_shi){
							RETRUN_MUL(1);
						}
					}
				}
			}
		}
	}
	// fen 5kC2/4P4/9/9/2b6/9/9/9/4K4/9 b

	// fen 3ak4/5c3/3ab4/6P2/2b6/2B6/9/4B4/5K3/3p5 w - - 120 120
	// fen 5P3/3k5/4b4/9/6b2/6B2/2p6/4BA3/3C5/4KA3 b
	// 一个和形 红方兵到底了
	 if(StoY(mpawn) == MY_RANK0){
		 if(your_xiang_num == 2){
			 if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				 RETRUN_MUL(1);
			 }
		 }
	 }

	 // fen 3k5/4aP3/4ba3/9/2b6/2B3C2/9/3A1A3/4p4/5K3 b - - 0 1
	 if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		 if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ0D) == your_shi){
			 if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				 RETRUN_MUL(2);
			 }
			 if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				 RETRUN_MUL(2);
			 }
		 }
	 }

	 // fen 4k4/9/3a4b/9/2b6/6P2/2p6/4BA3/9/3K1C3 w - - 0 0
	 if(your_shi_num >= 1 && your_xiang_num == 2){
		 if(mcan == 0){
			if(StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5){
				RETRUN_MUL(2);
			}
		 }
	 }

	 // fen 5k3/4P4/4b4/9/6b2/2B6/9/3K1C3/4p4/9 b - - 0 1
	 if (StoY(mpawn) MY_SMALL_EQL MY_RANK1 && abs(StoY(mpawn) - StoY(yk)) <= 1){
		 if (your_xiang_num == 2 && my_shi_num == 0){
			 RETRUN_MUL(2);
		 }
	 }

	 // fen 3ak4/5P3/4b4/9/6b2/6B2/p8/3A5/4AK3/4C4 r
     if(StoY(ypawn) == MY_RANK6 && PB90(MY_SQ0D) != your_shi){
		 if(your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk){
			 if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				 if(bit_is_set(YOUR_ATTACK,Square(MY_SQ16))){
					 if(PB90(MY_SQ16) == your_xiang && bit_is_set(YOUR_ATTACK,MY_SQ16)){
						 RETRUN_MUL(2);
					 }					 
					 if(count_1s(POSITION.xiang_attacks_bb(MY_SQ16),
						 bb_your_xiang) == 2){
							 RETRUN_MUL(2);
					 }
				 }
			 }
		 }
	 }

	 // fen 2b2k3/9/9/5P3/2b6/2B6/3p5/8B/5K3/4C4 b - - 0 1
	 if(my_shi_num == 0 && your_xiang_num == 2){
		 if(StoY(ypawn) == MY_RANK6 && StoX(ypawn) != StoX(yk)){
			 RETRUN_MUL(2);
		 }
	 }

	 // fen 5a3/3k1P3/3a5/9/9/9/6p2/3ABA3/3C5/4K1B2 b - - 0 1
	 if(your_shi_num >= 1 && StoY(ypawn) == MY_RANK6){
		 if(StoX(ypawn) != StoX(yk)){
			 if(StoY(mpawn) == MY_RANK0){
				 //if(StoX(yk) == 0x3 && StoX(mpawn) >= 0x5){
					// if(StoY(mpawn) == MY_RANK0) RETRUN_MUL(4);
				 //}
				 //if(StoX(yk) == 0x5 && StoX(mpawn) <= 0x3){
					// if(StoY(mpawn) == MY_RANK0) RETRUN_MUL(4);
				 //}
				 if(MY_SQ04 != yk){
					 RETRUN_MUL(4);
				 }
			 }
		 }
	 }

	 // fen 5a3/4a1P2/5k3/9/9/9/4p4/3AB4/4A4/2C1K1B2 b - - 0 1
	 if(your_shi_num == 2 && StoY(ypawn) == MY_RANK6){
		 if(StoX(ypawn) != StoX(yk)){
			 if(StoY(mpawn) MY_SMALL StoY(yk)){
				 RETRUN_MUL(4);
			 }
		 }
	 }



	 // fen 7P1/3k5/9/9/9/9/5p3/9/4AK3/4C4 r
	 if(StoY(mpawn) == MY_RANK0 && StoY(yk) != MY_RANK0){
		 if(my_shi_num <= 1 && StoY(ypawn) == MY_RANK6){
			 MY_EV_SUB(128);
			 if(abs(StoX(ypawn) - 0x4) <= 1){
				RETRUN_MUL(4);
			 }
		 }
	 }

	 // fen 5a3/3k1P3/3a5/9/9/9/6p2/3ABA3/3C5/4K1B2 b - - 0 1
     if(your_shi_num == 2 && StoY(ypawn) == MY_RANK6){
		 if(StoX(ypawn) != StoX(yk)){
			 if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(yk) == 0x3 && StoX(mpawn) >= 0x5){
					if(StoY(mpawn) == MY_RANK0) RETRUN_MUL(2);
					RETRUN_MUL(4);
				}
				if(StoX(yk) == 0x5 && StoX(mpawn) <= 0x3){
					if(StoY(mpawn) == MY_RANK0) RETRUN_MUL(2);
					RETRUN_MUL(4);
				}
			 }
		 }
	 }

	 // fen 2b1k1b2/4a4/9/4P4/9/4C4/4p4/3A1A3/3K5/2B6 b - - 0 1
	 if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		 if(StoY(ypawn) == MY_RANK6 && StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			 RETRUN_MUL(4);
		 }
	 }

	 // fen 4kab2/4a4/9/9/2b4P1/2c6/4p4/9/4A4/3K1AB2 b - - 0 1
	 if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		 if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			 if(!bit_is_set(EV_MY_XBIT,MY_SQ0D)){
				 RETRUN_MUL(4);
			 }
		 }
	 }

	//Square yk = your_king_pos;
	 // fen 5k3/3Pa4/3a5/9/2b6/9/6p2/3K5/4A4/3A2C2 w - - 0 1
	 if(your_shi_num == 2 && your_xiang_num >= 1 && !IsOnSameSide(yk,mpawn)){
		 if(StoY(yk) == MY_RANK0 && StoY(ypawn) == MY_RANK6){
			 if(my_xiang_num == 0 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				 RETRUN_MUL(4);
			 }
		 }
	 }

	 // fen 3ac4/9/4k3b/2P6/9/2B6/9/4B4/5p3/4K4 w - - 0 123
	 if(your_xiang_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK2){
		 if(StoY(ypawn) == MY_RANK6){
			 if(abs(StoY(mpawn) - StoY(yk)) == 1){
				 if(StoX(yk) == 0x4){
					 MY_EV_SUB(96);
					 RETRUN_MUL(4);
				 }
			 }
		 }
	 }

	 // fen 4P4/3k5/3ab4/9/6b2/9/9/3A1A3/3CK4/3p5 w - - 0 1
	 if(StoY(mpawn) == MY_RANK0){
		 if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) != MY_RANK0){
			 RETRUN_MUL(4);
		 }
	 }


	 // fen 3a1k3/9/3a5/5P3/6b2/9/1C2p4/9/4A4/4KA3 b - - 0 1
	 if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		 if(my_xiang_num == 0 && StoY(ypawn) == MY_RANK6){
			 RETRUN_MUL(4);
		 }
	 }
	 
	 // fen 2bk2b2/9/9/4P4/9/4C4/4p4/4B4/9/2B1K4 r
     if(my_shi_num == 0 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		 if(StoY(ypawn) == MY_RANK6 && yk != MY_SQ04){
			 RETRUN_MUL(4);
		 }
	 }

	 // fen 3a5/3Pa4/5k3/9/9/9/9/7C1/4p4/3K5 w - - 0 1
    if(my_shi_num == 0 && my_xiang_num == 0){
		if(StoY(ypawn) MY_SMALL_EQL StoY(mk) && abs(StoX(ypawn) - StoX(mk)) == 1){
			if(your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn) < 0x4 && StoX(yk) > 0x4){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn) > 0x4 && StoX(yk) < 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/4aP3/b3ba3/9/9/9/9/4CA3/3K5/2p2AB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(4);
			}
		}
	}

	//如果对方是仕相全,高兵,就和了
	// fen 1C2ka3/4a4/4b4/9/p1b6/6B2/P8/9/9/2BAKA3 w - - 3 3
	//not he
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(4);
		}
		RETRUN_MUL(6);
	}	

	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(8);
		}
	}
	// fen 5a3/2P1a4/3k4b/9/9/9/2p6/4BA3/5C3/2BAK4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(StoY(ypawn) == MY_RANK6 && StoY(yk) MY_LARGE StoY(mpawn)){
			RETRUN_MUL(8);
		}
	}

	// fen 1C4b2/5k3/3a5/9/9/8P/1p7/4B4/4K4/2B6 r
	if (my_shi_num == 0 && your_shi_num >= 1 && your_xiang_num >= 1){
		if (StoY(ypawn) == MY_RANK6){
			// if (StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			// 对方的相没有给看住
			if (!have_bit(EV_MY_XBIT, bb_your_xiang)){
				if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
					RETRUN_MUL(8);
				}
				if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
					RETRUN_MUL(8);
				}
			}
			// }
		}
	}
}
// fen 
// fen 4k4/4a4/9/9/4P3p/9/9/6C2/9/4K4 w
// fen 4k4/9/9/4P4/9/8p/9/6C2/9/4K4 w