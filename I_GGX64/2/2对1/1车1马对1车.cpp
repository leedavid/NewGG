#ifndef END_my_m_MT_R_1CHE1MA_B_1CHE
#define END_my_m_MT_R_1CHE1MA_B_1CHE
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int CheMaAdd  = 96;

//我方一车一马, 对方一车
void my_m_MT_R_1CHE1MA_B_1CHE(typePOS &POSITION, EvalInfo &ei){

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square yk   = your_king_pos;
	Square mk   = my_king_pos;

	//MY_EV_ADD(96);

	//
	if(StoX(yche) == StoX(yk)){
		MY_EV_SUB(96);
	}

	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(128);

		if(MY_SQ04 == yk && StoY(yk) == MY_RANK2){
			MY_EV_SUB(64);
		}
	}



	// fen 5kb2/4a4/4ba3/9/1R7/3N5/9/9/4r4/3K5 b - - 0 1
	MY_EV_ADD(96);

	bool isStr = isStringByChe(POSITION,mche,mma,yche);

	// fen 4k1b2/4a4/9/4r4/4N4/4R4/9/3A5/4K4/2B2AB2 r
	if(isStr){
		MY_EV_SUB(96);
	}
	// fen 3k1a3/4a4/b8/2R2N3/9/9/3r5/B8/4A4/3AK1B2 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(yche) MY_SMALL_EQL MY_RANK3){
			MY_EV_SUB(96);
		}
	}
	//// fen 3k1a3/4a4/b8/2R2N3/9/9/3r5/B8/4A4/3AK1B2 w - - 0 1
	//Bitboard te;
	////te.m128i_u64[1] =  0x188abc82af880000;
	////te.m128i_u64[0] =  0x00001f1d549255f1;

	////m_Rsf(te,32);    //0x00001f1d549255f1;
	////te.m128i_u64[0] &= 0xffff000000000000;
	////te.m128i_u64[0] |= 0x00001f1d549255f1;
	////print_bb(te);
	//te.m128i_u64[0]   =  0x00001f1d549255f1;
	//m_Lsf(te,45);
	//uint64 d =           0x188abc82af880000;
	//d = d >> 19;
	//te.m128i_u64[0]  |=  d;
 //	print_bb(te);
	// fen 9/5k3/4rN1R1/9/2b6/9/9/B3B4/4A4/5K3 b
	// fen 3k5/4a4/4b3b/9/9/6B2/9/3nR4/1r1K5/9 w - - 0 0
	if(StoY(mma) == MY_RANK2){		
		if(isStringByChe(POSITION,mk,mma,yk)){
			if(StoY(yche) == StoY(mma)){
				RETRUN_MUL(2);
			}
		}
	}

	// 如果车马被牵制了, 也是和棋, 
	// fen 3a1k3/4a4/4br3/5N3/9/5R3/9/4B4/9/5K3 w - - 78 78 
	if((your_shi_num+your_xiang_num) >= 2){
		if(isStr){
			RETRUN_MUL(2);
		}
	}

	// 如果对方有二个仕,且马被对方压制了
	// fen 4ka3/9/9/7r1/9/9/1R7/3A5/3nA4/5K3 w
	if(your_shi_num == 2 && PB90(MY_SQ0D) == your_shi){
		if(StoY(mma) MY_SMALL_EQL MY_RANK2 && !IsOnSameSide(mma,yk)){
			if(PB90(MY_SQ15) == your_shi){
				if(StoX(mma) < 0x4 && StoX(yche) == 0x1){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ17) == your_shi){
				if(StoX(mma) > 0x4 && StoX(yche) == 0x7){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k5/2RNa4/3a5/1r7/9/9/9/3AK4/4A4/9 w - - 39 39
	if(your_shi_num == 2 && StoY(mche) == MY_RANK1){
		if(FALSE){
		}
		else if(MY_SQ03 == yk && MY_SQ0C == mma && PB90(MY_SQ15) == your_shi){
		  if(StoX(yche) == 0x1){
			  RETRUN_MUL(2);
		  }
		}
		else if(MY_SQ05 == yk && MY_SQ0E == mma && PB90(MY_SQ17) == your_shi){
			if(StoX(yche) == 0x7){
				RETRUN_MUL(2);
			}
		}
  	}

	//如果是车马对车仕相全,也基本是和棋
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(yk) MY_SMALL MY_RANK2){
			RETRUN_MUL(2);
		}
	}

	// fen 9/5k3/9/4R4/2b6/9/9/4n4/4r4/3K5 b - - 0 0
	if(PB90(MY_SQ0D) == my_che && PB90(MY_SQ16) == my_ma && StoY(yk) == MY_RANK0){
		if(StoX(yche) == 0x4){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/9/b2ab4/9/9/2B6/9/9/R2KA4/nr1A5 b - - 50 50
	//马给车压住了
	if(your_shi_num == 2 && StoY(yk) MY_SMALL MY_RANK2){
		if(MY_SQ00 == mma && MY_SQ09 == yche){
			RETRUN_MUL(2);
		}
		if(MY_SQ08 == mma && MY_SQ11 == yche){
			RETRUN_MUL(2);
		}
	}

	// fen 9/5R3/3k5/9/9/9/4r4/4B4/4A1n2/2B2K3 w - - 116 116
	if(my_shi_num == 0 && my_xiang_num == 0){
		if((your_xiang_num + your_shi_num) >= 3){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(2);
			}
		}
	}

	// 
	if(your_xiang_num == 2 && PB90(MY_SQ16) == your_xiang){
		MY_EV_SUB(196);
	}

	// 如果是车马对车单缺相,也基本是和棋
	if(your_xiang_num == 2 && your_shi_num >= 1){
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	// fen 4kaNR1/4a1r2/9/9/9/9/9/4BA2B/4A4/4K4 w - - 0 1
    if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) == MY_RANK0 && StoY(mche) == MY_RANK0){
		if(StoY(mma) == MY_RANK0 && XYtoS(StoX(mma),MY_RANK1) == yche){
			if(abs(StoX(mma) - 0x4) >= 2 && abs(StoX(mche) - 0x4) > abs(StoX(mma) - 0x4)){
				if((StoX(mma) < 0x4 && PB90(MY_SQ03) == your_shi) 
					|| (StoX(mma) > 0x4 && PB90(MY_SQ05) == your_shi)){
					RETRUN_MUL(2);
				}
			} 
		}
	}

	// fen 3k1a2R/4a2rN/9/9/9/9/9/4BA2B/4A4/4K4 r
	if(your_shi_num == 2 && abs(StoX(mma) - 0x4) == 4 && StoX(mche) == StoX(mma)){
		if(StoY(mma) == MY_RANK1 && StoY(mche) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	if(your_xiang_num >= 1 && your_shi_num == 2){
		if(StoY(yk) == MY_RANK0){
			// fen 4ka3/4a4/b5r2/3R1N3/9/9/9/3KBA3/9/5AB2 b - - 0 1
			if(StoY(yche) == MY_RANK2){
				RETRUN_MUL(3);
			}
			RETRUN_MUL(4);
		}
	}

	// fen 9/4a1R2/b3ka3/5rN2/9/6B2/9/9/4A4/2BK1A3 b - - 122 122
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mma) MY_LARGE_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
			 // fen 4k4/4a4/4ba2b/9/6r2/9/9/3ABR3/2n1A4/5K3 w - - 0 1
			if(!IsOnSameSide(mma,yk)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k1b2/4a4/9/6R2/9/9/9/4r4/4N4/3AKA3 b - - 0 1
	if(my_xiang_num == 0){
		if(MY_SQ4C == mma && PB90(MY_SQ54) == my_shi
			&& PB90(MY_SQ56) == my_shi && MY_SQ55 == mk){
				if(StoX(yche) == 0x4){
					RETRUN_MUL(4);
				}
		}
	}

 //   // fen 4k4/4a4/4ba2b/9/6r2/9/9/3ABR3/2n1A4/5K3 w - - 0 1
	//if(your_shi_num == 2 && your_xiang_num >= 1){
	//}

	// fen 9/4a4/4k3b/9/9/9/9/6Rn1/4AK3/3A3r1 b - - 148 148
	if(your_shi_num == 2 && StoY(mche) MY_SMALL StoY(mma) 
		&& StoX(mche) == StoX(mma)){
			if(MY_SQ19 == mma && MY_SQ18 == yche){
				RETRUN_MUL(4);
			}
			if(MY_SQ13 == mma && MY_SQ14 == yche){
				RETRUN_MUL(4);
			}
	}

	// fen 9/4a1R2/b3ka3/5rN2/9/6B2/9/9/4A4/2BK1A3 b - - 122 122
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoX(mche) == StoX(mma) && StoY(yche) == StoY(mma)){
		    RETRUN_MUL(4);
		}
	}

	// fen 9/4k4/9/4r4/9/9/5R3/9/4A3n/3AK4 w - - 0 114
	if((my_shi_num + my_xiang_num) == 0){
		if(your_shi_num == 2){
			if(StoY(yk) == MY_RANK0){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a4/4ba2b/9/9/9/9/3AB2R1/2n1AK3/6r2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(IsOnSameSide(mma,yk) == FALSE){
			RETRUN_MUL(4);
		}
	}


	// fen 3a1k3/4a4/b8/9/2b6/2R6/9/5A3/4K4/1r2nA3 w - - 0 1
	// fen 3aN2R1/4k4/3a5/9/6r2/6B2/9/8B/4A4/3K1A3 b - - 0 1
	if(your_shi_num >= 1 && MY_SQ04 == mma && MY_SQ0D == yk 
		&& StoY(yk) MY_SMALL_EQL MY_RANK4 && StoY(mche) == MY_RANK0){
		if(PB90(MY_SQ03) == your_shi && StoX(yche) == 0x6){
			RETRUN_MUL(4);
		}
		if(PB90(MY_SQ05) == your_shi && StoX(yche) == 0x2){
			RETRUN_MUL(4);
		}
	}
	
	// fen 1R3a3/3ka4/b4r3/1N7/9/2B6/9/4BA3/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(yche) == MY_RANK2 && StoY(mma) MY_LARGE_EQL MY_RANK3){
			if(StoX(mma) < 0x4 && have_bit(bb_your_xiang,LeftBB[0x4]))
				RETRUN_MUL(6);
			if(StoX(mma) > 0x4 && have_bit(bb_your_xiang,RightBB[0x4]))
				RETRUN_MUL(6);
		}
	}

	

	// 车马难杀马双相。
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}
	// fen 2Rak4/9/5a3/9/6b2/6B2/1r7/3A5/3KA1n2/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(yche) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
		}
		RETRUN_MUL(10);
	}

	// fen 3k5/2R6/3a1a3/7r1/2N6/9/9/9/4AK3/9 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if((my_shi_num + my_xiang_num) <= 1){
			RETRUN_MUL(10);
		}
	}
	
}
