#ifndef END_my_m_MT_R_1CHE1PAO_B_1CHE1PAWN
#define END_my_m_MT_R_1CHE1PAO_B_1CHE1PAWN
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//我方一车一炮, 对方一车一兵
void my_m_MT_R_1CHE1PAO_B_1CHE1PAWN(typePOS &POSITION, EvalInfo &ei){

	static const sint16 PawnShiAdd[3] = {96, 32, 0};

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yk    = your_king_pos;
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mk    = my_king_pos;

	if(StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(64);
	} 

	if(StoY(ypawn) == MY_RANK9){
		MY_EV_ADD(96);
	}

	if(StoY(ypawn) == MY_RANK9){
		EV_MY_SAFE = true;
	}

	// fen 2b1k4/5R1P1/5c3/9/5r3/9/9/5A3/5K3/9 b - - 0 1
	if (my_shi_num == 0 && StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(64);
		if (abs(StoY(ypawn) - StoY(mk)) <= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 2b1k4/5R1P1/5c3/9/5r3/9/9/5A3/5K3/9 b - - 0 1
	if (my_shi_num == 0 && EV_YOUR_CAN >= 1){
		if (abs(StoY(ypawn) - StoY(mk)) <= 1){
			MY_EV_SUB(32);
			if (isStringByChe(POSITION, mche, mpao, yche)){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3ak2r1/4aP3/6R2/4c4/9/9/9/9/4K4/9 b - - 0 1
	if (my_xiang_num == 0 && EV_YOUR_CAN >= 1 && abs(StoX(ypawn) - 0x4) <= 1){
		MY_EV_SUB(64);
		if (abs(StoX(ypawn) - StoX(mk)) <= 1){
			MY_EV_SUB(64);
		}
	}

	//fen R2c5/2P1ak3/9/9/9/9/9/9/9/1r1AKA3 b - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if (my_shi_num <= 1 && my_xiang_num == 0){
			if (StoY(ypawn) == MY_RANK8 && abs(StoX(ypawn) - 0x4) >= 2){
				MY_EV_SUB(64);
			}
		}
	}

	if (your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){

	}

	if(your_xiang_num == 2 && my_shi_num == 0 && my_xiang_num <= 1){
		EV_YOUR_SAFE = true;
	}

	// fen 3k2b2/9/3ab4/6R2/9/9/5r1p1/4C4/4A4/3AK4 b - - 0 1
	if(my_xiang_num == 0){
		if(your_xiang_num == 2 && your_shi_num >= 1){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				MY_EV_SUB(32);
				if(StoY(ypawn) == MY_RANK6){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 9/3k5/9/9/5R3/9/4r1p2/3A5/3K5/3C5 b - - 0 1
	if(my_shi_num <= 1 && StoY(ypawn) == MY_RANK6 && my_xiang_num == 0){
		MY_EV_SUB(64);
	}

	// fen 9/5k3/3a1a3/9/9/5r3/3p5/1R2B4/9/3KC4 b - - 0 1
	if(my_shi_num >= 1 || my_xiang_num >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(32);
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 8C/5k3/9/9/9/4R4/9/6p2/4K4/5r3 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		if (StoY(ypawn) MY_SMALL_EQL StoY(mk)){
			MY_EV_SUB(32);
			if (abs(StoY(ypawn) - StoY(mk)) <= 2){
				MY_EV_SUB(64);
				if (abs(StoX(ypawn) - StoX(mk)) <= 2){
					MY_EV_SUB(32);
				}
			}
		}
	}

	if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	if(my_xiang_num == 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
      EV_MY_SAFE = TRUE;
	}

	if(StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(PawnShiAdd[my_shi_num]);
	}

	if(FALSE){
	}
	else if(my_shi_num == 0){
		if(your_shi_num == 0 && your_xiang_num == 0){
			//炮方的车守了中线, 在这儿作海底搂月的判断
			if(StoX(mche) == 0x4){
				MY_EV_ADD(96);
				if(IsOnSameSide(yk,mpao)){
					MY_EV_ADD(64);
				}
				if(StoY(mpao) MY_SMALL StoY(yk)){
					MY_EV_ADD(64);
					if(StoX(mpao) == StoX(yk)){
						MY_EV_ADD(64);
					}
				}
			}
		}

		//************************************************************************************************
		//1, 如果对方有仕相，而炮方没有，则对方好
		//兵方的车守中了
		if(StoX(yche) == 0x4){
            if(StoY(ypawn) == MY_RANK9){
				RETRUN_MUL(2);
			}
			MY_EV_SUB(64);
		}

		//2, 还有一种情况, 车炮在一线,对方的兵就不能下来	
		if(StoY(ypawn) MY_SMALL StoY(mk)){
			if(StoY(mche) MY_LARGE StoY(ypawn)){
				if(StoY(mche) == StoY(mpao) && StoY(mche) MY_SMALL StoY(mk)){
					if(StoX(mche) < StoX(ypawn) && StoX(mpao) < StoX(mche)){
						RETRUN_MUL(2);
					}
					if(StoX(mche) > StoX(ypawn) && StoX(mpao) > StoX(mche)){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
	else if(my_shi_num == 1){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}
	else if(my_shi_num == 2){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	if(my_shi_num >= 1 || StoY(ypawn) MY_LARGE StoY(mk)){
		if(isStringByChe(POSITION,mche,mpao,yche)){
			RETRUN_MUL(2);
		}
	}

	// fen 9/2P6/3kb3b/rc7/9/9/1R7/9/9/3AK1B2 w - - 92 92
	if(my_shi_num >= 1 || my_xiang_num >= 1){
         if(StoY(ypawn) == MY_RANK8 && StoY(mk) == MY_RANK7){
			 if(StoY(mche) == MY_RANK5 || StoY(mche) == MY_RANK6){
				 if(StoY(mche) MY_LARGE StoY(yche) && StoY(mche) == StoY(mpao)){
					 if(StoX(mche) == 0x0 || StoX(mche) == 0x8){
						 if(StoX(mpao) == StoX(yche)){
							 RETRUN_MUL(2);
						 }
					 }
				 }
			 }
		 }
	}

	// fen 2b1P4/4kc1R1/5a3/9/6b2/2B6/9/4B4/4K4/3r5 b - - 158 158
	if(your_xiang_num == 2){
		if(StoY(ypawn) == MY_RANK9 && my_shi_num == 1 
			&& PB90(MY_SQ4C) == my_king && StoY(yche) == MY_RANK8){
			if(PB90(MY_SQ4D) == my_pao && PB90(MY_SQ44) == my_shi){
				if(StoX(yche) > 0x4){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ4B) == my_pao && PB90(MY_SQ42) == my_shi){
				if(StoX(yche) < 0x4){
					RETRUN_MUL(2);
				}
			}
		}
		if(StoY(ypawn) == MY_RANK9 && my_shi_num == 0){
			RETRUN_MUL(2);
		}
	}
	// fen 2b3b2/3P5/5k3/9/4rc3/9/5R3/B7B/4A4/3AK4 b - - 0 0
    if(my_shi_num == 0 && StoY(mk) MY_SMALL StoY(ypawn) 
		&& StoY(yche) != StoY(mk) && your_xiang_num == 2){
			RETRUN_MUL(2);
	}

	// fen 5a3/5k3/9/9/2b3b2/2B6/2C6/2R6/1p7/4Kr3 w - - 233 233
	if(my_shi_num == 0 && your_xiang_num == 2){
		MY_EV_SUB(32);
	}

	if(StoY(ypawn) MY_LARGE_EQL MY_RANK8 && (my_shi_num + my_xiang_num) != 0){
	   if(StoX(ypawn) <= 0x1 && StoX(mche) == 0x2){
		   EV_MY_SAFE = TRUE;
	   }
	   if(StoX(ypawn) >= 0x7 && StoX(mche) == 0x6){
		   EV_MY_SAFE = TRUE;
	   }
	}

	// fen 2bck4/3P5/9/9/9/5R3/9/9/5K3/4r4 b - - 81 81
	if(my_shi_num == 0){
		if(your_shi_num == 0 && your_xiang_num == 0){
			if(PB90(MY_SQ55) == my_king && StoX(mche) == 0x4){
				if(PB90(MY_SQ56) == my_pao && PB90(MY_SQ4D) == your_pawn){
					RETRUN_MUL(2);
				}
				if(PB90(MY_SQ54) == my_pao && PB90(MY_SQ4B) == your_pawn){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3a1k3/9/4ba3/9/2b6/9/1p7/2R1B4/4K4/2Cr5 w - - 120 120
	if(my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(abs(StoX(ypawn) - 0x4) >= 3 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 3k5/9/b8/9/6b2/9/3r5/2p6/5R3/4CK3 w - - 100 100
	if(my_shi_num == 0 && my_xiang_num == 0 && your_shi_num == 0){
		if(PB90(MY_SQ55) == my_pao && StoY(mk) == MY_RANK9 && StoX(mk) == StoX(mche)){
			if(abs(StoX(ypawn) - 0x4) >= 1){
				if(StoX(ypawn) < 0x4 && StoX(mk) == 0x5){
					RETRUN_MUL(4);
				}
				if(StoX(ypawn) > 0x4 && StoX(mk) == 0x3){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/9/9/9/4R4/1r7/3p5/4KC3 w - - 0 1
    if((my_shi_num + my_xiang_num) == 0 && (your_xiang_num + your_shi_num) >= 2){
		if(MY_SQ55 == mk && StoY(mpao) == MY_RANK9 && StoX(mche) == 0x4){
			if(StoX(ypawn) < 0x4 && StoX(mpao) > 0x4){
				RETRUN_MUL(4);
			}
			if(StoX(ypawn) > 0x4 && StoX(mpao) < 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/3k5/5a3/9/3C1R3/3r2B2/9/3A1p3/3K5/9 w - - 0 0
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num == 1 && my_xiang_num >= 1){
			if(StoX(yche) == StoX(yk) && StoY(yche) MY_LARGE StoY(mpao)){
				if(PB90(MY_SQ44) == your_pawn && StoX(yche) == 0x3
					&& PB90(MY_SQ42) == my_shi && PB90(MY_SQ4B) == my_king){
						RETRUN_MUL(4);
				}
				if(PB90(MY_SQ42) == your_pawn && StoX(yche) == 0x5
					&& PB90(MY_SQ44) == my_shi && PB90(MY_SQ4D) == my_king){
						RETRUN_MUL(4);
				}
			}
		}
	}

	//fen 4ka3/4a4/5P3/4R4/3rc4/9/9/9/4K4/9 b - - 0 1
	if (EV_MY_SAFE){
		if (my_xiang_num == 0 && StoY(ypawn) == MY_RANK7){
			if (StoX(yche) == 0x4 && StoX(yk) == 0x4){
				if (abs(StoX(ypawn) - 0x4) <= 1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3ak2r1/4aP3/6R2/4c4/9/9/9/9/4K4/9 b - - 0 1
	if (EV_MY_SAFE){
		if (my_xiang_num == 0 && StoY(ypawn) == MY_RANK8){
			if (StoX(ypawn) == 0x3 && PB90(MY_SQ54) != my_shi){
				if (StoX(mche) < 0x3){
					RETRUN_MUL(4);
				}
			}
			if (StoX(ypawn) == 0x5 && PB90(MY_SQ56) != my_shi){
				if (StoX(mche) > 0x5){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen CR1ak4/4a4/4b4/9/8p/r8/9/4B4/4A4/2BAK4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ0D) == your_shi){
		if(MY_SQ04 == yk && StoY(mpao) == MY_RANK0 && StoY(mche) == MY_RANK0){
			if(StoX(yche) == StoX(mpao)){

				MY_EV_SUB(EV_MY_CAN * 80);

				if(StoX(mpao) < StoX(mche) && StoX(mche) <= 0x2 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(mpao) > StoX(mche) && StoX(mche) >= 0x6 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5k3/1P2ac3/5a3/1R7/9/6B2/9/3AB4/8r/3K5 b - - 128 128
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_xiang_num == 0 && my_shi_num >= 1 && StoY(mpao) MY_LARGE_EQL MY_RANK8){
			if(isStringByChe(POSITION,mpao,Square(MY_SQ4C),ypawn) && StoX(yche) == StoX(ypawn)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3r1a3/4k4/9/9/9/R2C5/9/4B4/4p4/3K5 b - - 0 1
	if(my_shi_num == 0 && ypawn == MY_SQ4C && StoY(mk) == MY_RANK9){
		if(my_xiang_num >= 1 && StoY(yche) MY_SMALL_EQL MY_RANK4){
			if(StoY(mche) == MY_RANK5 || StoY(mche) == MY_RANK6){
				if(abs(StoX(mche) - 0x4) == 4 && StoY(mche) == StoY(mpao)){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5k3/9/4ba3/4C4/6b2/2BR5/4p4/3K5/5r3/9 b - - 0 1
    if(EV_YOUR_SAFE){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7 && my_xiang_num >= 1){
			if(StoX(mche) == StoX(mk) && StoY(mche) MY_SMALL_EQL MY_RANK7){
				if(StoX(mk) <= 0x4 && StoX(ypawn) >= 0x4){
					RETRUN_MUL(4);
				}
				if(StoX(mk) >= 0x4 && StoX(ypawn) <= 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/4a4/4b3b/9/9/9/1r7/B2R5/4p4/2CK5 b - - 0 1
    if(EV_YOUR_SAFE){
		if(my_xiang_num >= 1){
			if(StoX(mk) == 0x3 && StoX(ypawn) >= 4){
				if(StoX(mpao) == 0x2){
					if(MY_SQ42 == mche){
						if(PB90(MY_SQ3F) == my_xiang){
						   RETRUN_MUL(4);
						}
						if(PB90(MY_SQ2F) == my_xiang && MY_SQ53 == mpao){
							RETRUN_MUL(4);
						}
					}
				}
			}
			if(StoX(mk) == 0x5 && StoX(ypawn) <= 4){
				if(StoX(mpao) == 0x6){
					if(MY_SQ44 == mche){
						if(PB90(MY_SQ47) == my_xiang){
							RETRUN_MUL(4);
						}
						if(PB90(MY_SQ33) == my_xiang && MY_SQ57 == mpao){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}

	// fen 5k3/9/9/4R4/9/9/9/3K5/3C5/1p1r5 w - - 0 1
	if(EV_MY_SAFE){
		if(my_shi_num == 0 && my_xiang_num == 0 && StoY(ypawn) == MY_RANK9){
			if(abs(StoX(ypawn) - 0x4) <= 3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b6/4k4/4b4/9/9/9/9/4R4/2p1Cr3/2BK5 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_xiang_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK8 
			&& StoX(mpao) == 0x4 && StoY(mche) MY_SMALL_EQL StoY(mpao) && StoX(mche) == 0x4){
				if(StoX(ypawn) <= 0x2 && StoX(mk) == 0x3 && StoX(yche) > 0x4){
					RETRUN_MUL(6);
				}
				if(StoX(ypawn) >= 0x6 && StoX(mk) == 0x5 && StoX(yche) < 0x4){
					RETRUN_MUL(6);
				}
		}
	}


	// fen 9/4kc3/2P1bR3/9/9/9/3r5/4BA3/4A4/4K1B2 w - - 214 214
	if(my_xiang_num >= 1 && my_shi_num == 0 && StoY(ypawn) == MY_RANK7){
		if(StoY(mk) == MY_RANK8 && StoY(mpao) == MY_RANK8 && !IsOnSameSide(mpao,ypawn)){
			if(StoX(ypawn) <= 0x2 && StoX(mche) == 0x3){
				MY_EV_ADD(164);
			}
			if(StoX(ypawn) >= 0x6 && StoX(mche) == 0x5){
				MY_EV_ADD(164);
			}
			if((your_shi_num + your_xiang_num) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen R2c5/2P1ak3/9/9/9/9/9/9/9/1r1AKA3 b - - 0 1
	if (your_shi_num == 2 || your_xiang_num == 2){
		if (StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (my_shi_num == 1 && abs(StoY(ypawn) - StoY(mk)) <= 1){
				if (StoY(ypawn) MY_SMALL_EQL MY_RANK8 && abs(StoX(ypawn) - 0x4) <= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}

	if(EV_YOUR_SAFE){
		if(my_xiang_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK8){
			if(abs(StoX(ypawn) - StoX(mk)) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a1kb2/4a4/4c4/4RP3/2b6/9/9/3A1Ar2/5K3/9 b - - 0 0</
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) == MY_RANK6 && StoY(yche) == MY_RANK6){
			RETRUN_MUL(8);
		}
	}
	// fen 3c1k3/9/5r3/4P4/2R6/9/9/9/4K4/6B2 w - - 0 115
	if((my_shi_num + my_xiang_num) == 0){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			RETRUN_MUL(8);
		}
	}

	// fen 6R2/4ak3/3a5/9/9/4r2p1/9/5C3/4A4/4KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(my_xiang_num == 0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(your_shi_num == 2 && !bit_is_set(EV_MY_XBIT,yche)){
				if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
					RETRUN_MUL(8);
				}
			}
		}
	}

	if(StoY(mk) == MY_RANK9 && StoY(mpao) == MY_RANK9){
		if(MY_SQ4C == ypawn){
			MY_EV_ADD(80);
		}
	}

  // fen 9/5k3/3a1a3/9/9/5r3/3p5/1R2B4/9/3KC4 b - - 0 1
  if(my_shi_num == 0 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	  if(your_shi_num == 2 || your_xiang_num == 2){
		  if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			  RETRUN_MUL(8);
		  }
	  }
  }
  
  // fen 3k5/9/4b4/9/6b2/9/9/3rp4/2R6/4K2C1 w - - 0 1
  if(my_shi_num == 0 && my_xiang_num == 0){
	  if(StoY(mk) == MY_RANK9 && StoY(ypawn) MY_SMALL_EQL MY_RANK7){
		  if(StoY(mpao) MY_LARGE_EQL MY_RANK8){
			  RETRUN_MUL(8);
		  }
	  }
  }

  // fen 5k3/9/9/9/3C1r3/3R5/9/4B3B/2p6/4K4 b - - 0 1
  if(my_shi_num == 0 && StoY(ypawn) == MY_RANK8){
	  if(my_xiang_num == 2 && abs(StoX(ypawn) - 0x4) >= 2){
		  RETRUN_MUL(8);
	  }
  }

  // fen 9/3k5/9/9/5R3/9/4r1p2/3A5/3K5/3C5 b - - 0 1
  if(my_shi_num <= 1 && my_xiang_num == 0 && StoX(yche) == 0x4){
	  if(StoY(ypawn) == MY_RANK6){
		  RETRUN_MUL(8);
	  }
  }

  // fen 4k4/9/3ab4/7R1/2b6/9/3r3p1/3C5/4A4/3AK1B2 w - - 0 1
  if(EV_MY_SAFE){
	  if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		  if(StoY(ypawn) == MY_RANK6 && StoY(yche) MY_SMALL_EQL MY_RANK6){
			  RETRUN_MUL(8);
		  }
	  }
  }


	// fen 4k4/9/4b4/7C1/4R1b2/9/3r1p3/3A5/4A4/4K4 b - - 0 1
	if(EV_MY_SAFE && my_xiang_num == 0 && StoY(ypawn) == MY_RANK6){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && your_xiang_num == 2){
			RETRUN_MUL(10);
		}
	}
}


