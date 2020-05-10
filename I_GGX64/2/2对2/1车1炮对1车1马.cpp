#ifndef END_my_m_MT_R_1che1pao_B_1che1ma
#define END_my_m_MT_R_1che1pao_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ChePao_CheMa_Pao_Empty = 196;

//车炮对车马
void my_m_MT_R_1che1pao_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);


	//  fen 4kab2/4a4/4b4/1n7/9/4r4/2R6/9/4C4/3AKA3 b - - 0 1
	//  这个不和
	if (my_shi_num == 2 && my_xiang_num == 0) {
		if (PB90(MY_SQ4C) == my_pao && PB90(MY_SQ54) == my_shi
			&& PB90(MY_SQ56) == my_shi && MY_SQ55 == mk) {
			if (StoX(yche) == 0x4) {
				RETRUN_MUL(16);
			}
		}
	}

	//如果炮方是二个仕,或二个相,马方是仕相全,就是和棋
	if(StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(my_xiang_num == 2){
			EV_MY_SAFE = TRUE;
		}
		if(my_shi_num == 2){
			EV_MY_SAFE = TRUE;
		}
	}
	// fen 7R1/3ka4/3ab4/9/9/9/1n7/4BA3/6C2/2B1KA2r b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		EV_YOUR_SAFE = TRUE;
	}	

	// fen 5k3/4a4/3a1n3/5R3/3r5/9/9/4B4/4C4/3AKAB2 b - - 0 1
	if (EV_MY_SAFE){
		if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (StoX(yk) == StoX(yma)){
				if (MY_SQ17 == yma && PB90(MY_SQ15) == your_shi){
					MY_EV_SUB(64);
				}
				if (MY_SQ15 == yma && PB90(MY_SQ17) == your_shi){
					MY_EV_SUB(64);
				}
			}
		}
	}



	// fen 2b1ka3/4c4/4ba3/9/9/6B2/9/3rB1R2/2N6/4K4 w - - 27 27
    //这个不和

	if(my_shi_num == 0){
		// fen 9/2c1k4/4b4/4r4/4NRb2/9/9/4B4/4A4/5K3 b - - 150 150
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!isStringByChe(POSITION,mche,yma,yche)){
				EV_YOUR_SAFE = TRUE;
			}
		}
	}

	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		EV_YOUR_SAFE = TRUE;
	}

	if((my_shi_num + my_xiang_num) == 0){
		MY_EV_SUB(64);   // was 196
	}


	if(EV_YOUR_SAFE){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(my_shi_num >= 1){
				MY_EV_ADD(32);
			}
			if(StoY(mche) MY_LARGE_EQL MY_RANK7){
				MY_EV_ADD(32);
			}
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 6R2/4ak3/3a1n3/9/9/9/5r3/9/4A4/2BAKCB2 w
	//一炮拖二子了.
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(bit_is_set(ei.attacked_by(your_che),mpao) && StoX(yche) == StoX(yma)){
			if(StoX(yk) == 0x5 && MY_SQ17 == yma){
				if(my_shi_num == 2 || my_xiang_num == 2){
					RETRUN_MUL(4);
				}
			}
			if(StoX(yk) == 0x3 && MY_SQ15 == yma){
				if(my_shi_num == 2 || my_xiang_num == 2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2b1kab1C/4a4/5n3/9/9/1r4BR1/9/9/4A4/4K4 r
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 && my_xiang_num >= 1){
			if(StoY(mk) MY_LARGE_EQL MY_RANK8){
				if(StoY(yma) MY_SMALL_EQL MY_RANK4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2b2k3/4a4/3ab4/9/6n2/9/4R4/9/9/C3KA1r1 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
			if(StoY(mpao) == MY_RANK9){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/9/9/2r6/9/3RCA3/9/1n3K3 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(mche) MY_LARGE_EQL MY_RANK7 && StoY(mpao) MY_LARGE_EQL MY_RANK7){
				if(!isStringByChe(POSITION,mche,mpao,yche)){
					if(abs(StoX(yma) - StoX(mk)) >= 4){
						RETRUN_MUL(6);
					}
				}
			}
		}
	}

	// fen 9/5k3/9/3R5/9/9/9/3K5/5r1n1/4C4 b
	if(EV_YOUR_SAFE){
		if(your_shi_num == 0 && your_xiang_num == 0){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 5C3/4k4/4b3b/9/9/5R3/4r4/3AB2n1/4A4/2BK5 b - - 0 1
	if(EV_MY_SAFE){
		if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!bit_is_set(EV_MY_XBIT,yche) && !bit_is_set(EV_MY_XBIT,yma)){
				if(!isStringByChe(POSITION,mche,yma,yche)){
					RETRUN_MUL(6);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/9/3r5/5n3/9/B6R1/3C5/3K5 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 || my_xiang_num >= 1){
			if(StoY(mk) == MY_RANK9){
				if(StoY(mche) MY_LARGE_EQL MY_RANK6 && StoY(mpao) MY_LARGE_EQL MY_RANK8){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 9/5k3/4b4/9/9/5rB1n/2R6/4C4/4A4/2B1K4 w - - 0 1
	if(EV_MY_SAFE && my_shi_num <= 1){
		if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(abs(StoY(yche) - MY_RANK4) <= 1){
				if(abs(StoY(yma) - MY_RANK4) <= 1){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/7r1/9/9/9/9/3RA1n2/3KC4 w - - 0 1
	if(EV_YOUR_SAFE){
		if(StoY(mk) == MY_RANK9 && my_shi_num >= 1){
			if(StoY(mpao) == MY_RANK9){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/4a4/5a3/9/6b2/9/7r1/5R2N/4A3c/3A1K3 w - - 45 45
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(your_shi_num == 2 || your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}

	// fen 9/3k5/9/4R4/9/9/2n6/9/5K3/3rC4 b - - 0 1
    if((your_xiang_num + your_shi_num) == 0){
		if((my_xiang_num + my_shi_num) == 0){
			if(StoX(mpao) == 0x4 && StoX(mche) == 0x4 && StoY(mche) MY_SMALL_EQL StoY(mpao)){
				if(StoX(mk) == 0x5 && StoX(yma) <= 0x3){
					RETRUN_MUL(8);
				}
				if(StoX(mk) == 0x3 && StoX(yma) >= 0x5){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/4a4/9/4R4/9/9/6r2/4BC3/4A1n2/3A1KB2 b - - 0 1
	if((your_shi_num + your_xiang_num) <= 1){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(96);
		}
	}
	// fen 2b1kab1C/4a4/5n3/9/9/1r4BR1/9/9/4A4/4K4 r
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 || my_xiang_num >= 1){
			if(StoY(mk) MY_LARGE_EQL MY_RANK8){
				if(StoY(yma) MY_SMALL_EQL MY_RANK4){
					RETRUN_MUL(8);
				}
			}
		}
	}
	// fen 4k4/9/3cr4/3RN4/9/9/9/9/4K4/9 b - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){  // 我方不安全。
		if(bit_is_set(EV_MY_XBIT,yma)){
			RETRUN_MUL(8);
		}
	}

	// fen 9/3k5/9/4R4/9/9/2n6/9/5K3/3rC4 b - - 0 1
	if(your_shi_num == 0 && your_xiang_num == 0){
		if(StoX(mche) == 0x4){
			if(StoX(yk) == 0x3 && StoX(yma) <= 0x3){
				MY_EV_ADD(96);
				if(my_shi_num == 0){
					RETRUN_MUL(8);
				}
			}
			if(StoX(yk) == 0x5 && StoX(yma) >= 0x5){
				MY_EV_ADD(96);
				if(my_shi_num == 0){
					RETRUN_MUL(8);
				}
			}
		}
	}
	// fen 5k3/4a4/3a1n3/5r3/9/8R/9/3A5/9/2BAKCB2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 4k1b2/4a4/3a5/9/9/9/r8/3R1AC2/6n2/3K5 w - - 0 1
	if(EV_YOUR_SAFE){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(my_shi_num >= 1){
				if(StoY(mche) MY_LARGE_EQL MY_RANK7){
					if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 4ka3/9/4ba2b/9/9/9/2n1r4/4B1R2/4K3C/9 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_xiang_num >= 1 && StoY(mche) MY_LARGE_EQL MY_RANK5 && StoY(mpao) MY_LARGE_EQL MY_RANK6){
			if(StoY(mk) MY_LARGE_EQL MY_RANK8 && !IsOnSameSide(yma,mk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/4k4/5a3/9/1Rb6/8C/4r2n1/3AB4/4A4/2BK5 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(abs(StoY(yma) - MY_RANK6) <= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/4k4/b2ara3/9/2b6/9/9/3RnC3/4A4/3K5 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				RETRUN_MUL(8);
			}
		}
	}
}

