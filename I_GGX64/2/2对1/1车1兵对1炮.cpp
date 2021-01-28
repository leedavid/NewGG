#ifndef END_my_m_MT_R_1che1pawn_B_1pao
#define END_my_m_MT_R_1che1pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//车兵对1炮
void my_m_MT_R_1che1pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(your_shi_num == 2 && your_xiang_num == 2 ){

		if(StoY(yk) == MY_RANK0){
			MY_EV_SUB(128);
		}

		if(PB90(MY_SQ16) == your_xiang){
			MY_EV_SUB(96);
		}

		// fen 3ckab2/4a4/5P2b/9/R8/2B6/9/3A5/9/2BAK4 b - - 36 36
		// 这个不和
		//if(StoY(mpawn) == MY_RANK2 && PB90(MY_SQ4C) != my_shi && PB90(MY_SQ43) != my_xiang){
		//	if(StoX(mpawn) > 0x4){
		//		if(count_1s(RightBB[0x4],bb_your_xiang)) == 2){
		//			RETRUN_MUL(16);
		//		}
		//	}
		//	if(StoX(mpawn) < 0x4){
		//		if(count_1s(LeftBB[0x4],bb_your_xiang)) == 2){
		//			RETRUN_MUL(16);
		//		}
		//	}
		//}
		// fen 2b1k4/4a4/9/9/9/9/3p5/B2A5/4A4/2B1KC1r1 w - - 0 0
		if(your_king_pos == MY_SQ04 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		   if(PB90(MY_SQ17) == your_shi && PB90(MY_SQ03) == your_pao){
			   RETRUN_MUL(2);
		   }
		   if(PB90(MY_SQ15) == your_shi && PB90(MY_SQ05) == your_pao){
			   RETRUN_MUL(2);
		   }
		}  

		if(PB90(MY_SQ16) == your_xiang){
			if(StoY(yk) == MY_RANK0){
				if(StoY(ypao) == MY_RANK0){
					RETRUN_MUL(2);
				}
				// fen 5a3/3P5/b2ak4/9/6b2/5r3/9/4C3B/3pA4/3AK1B2 w - - 14 14
				if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(2);
				}
			}

			// 如果对方的兵不能过河,也是和棋
			// fen 5k3/9/9/9/2b1C1p2/2B6/1r7/3AB4/3KA4/9 r
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(mpawn == MY_SQ2F || mpawn == MY_SQ33 || mpawn == MY_SQ38 || mpawn == MY_SQ3C){
					RETRUN_MUL(2);
				}
			}
			// fen 2b1ka3/4a4/b8/1R2P4/9/2B6/9/2cAB4/9/3A1K3 b - - 156 
			// 将在原位
			if(your_king_pos == MY_SQ04 && StoY(mpawn) MY_LARGE MY_RANK2){
				RETRUN_MUL(2);
			}
		}
	}// if(your_shi_num == 2 && your_xiang_num == 2 ){

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_CheXPawn_To1Pao_ByPawnShi[your_shi_num]);
	}

	MY_EV_ADD(ADD_CheXPawn_To1Pao);

	
	if(your_xiang_num == 2 && your_shi_num >= 1){
		if(StoY(yk) == MY_RANK0 ){
			// fen 3k1P3/4a4/3cb4/9/3R2b2/6B2/9/8B/9/3AKA3 b - - 0 0
			if(PB90(MY_SQ0D) == your_shi){
				if(MY_SQ05 == mpawn && MY_SQ15 == ypao){
					RETRUN_MUL(2);
				}
				if(MY_SQ03 == mpawn && MY_SQ17 == ypao){
					RETRUN_MUL(2);
				}
			}
			// fen 1P2kc3/9/3ab4/9/2b6/9/1R7/4B4/4A4/2B1K4 b 
			if(StoY(mpawn) == MY_RANK0 && StoY(ypao) == MY_RANK0){
				if(StoX(mpawn) <= 0x1 && StoX(ypao) >= 0x5){
					RETRUN_MUL(2);
				}
				if(StoX(mpawn) >= 0x7 && StoX(ypao) <= 0x3){
					RETRUN_MUL(2);
				}
				RETRUN_MUL(4);
			}
		}
	}

	// fen 1R1ak4/4a4/4b4/p1p5p/9/2Pn5/P3c3P/3K5/4A4/5A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && yk == MY_SQ04){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi){ 
				if(!have_bit(bb_your_xiang,RightBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi){
				if(!have_bit(bb_your_xiang,LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}
	

	// fen 2b1k1b2/4a4/3a1c3/3P5/4R4/9/9/3A1A3/3K5/2B3B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(ypao) MY_SMALL_EQL MY_RANK2 && StoX(ypao) != 0x4){
			RETRUN_MUL(4);
		}
	}

	// fen 3a1a3/9/5k3/5r3/9/4C1B2/9/4BA3/3pAK3/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 ){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(abs(StoX(ypao) - 0x4) <= 1 && StoY(ypao) MY_LARGE MY_RANK3){
					if(StoX(mpawn) < 0x4 && StoX(yk) > 0x4){
						RETRUN_MUL(4);
					}
					if(StoX(mpawn) > 0x4 && StoX(yk) < 0x4){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 1R5P1/3ka4/5a2b/9/c8/9/9/5A3/9/4K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mpawn) == MY_RANK0){
			if(StoX(mpawn) >= 0x7 && PB90(MY_SQ1A) == your_xiang 
				&& PB90(MY_SQ17) == your_shi && StoX(ypao) <= 0x3){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) <= 0x1 && PB90(MY_SQ12) == your_xiang 
				&& PB90(MY_SQ15) == your_shi && StoX(ypao) >= 0x5){
					RETRUN_MUL(4);
			}
		}
	}

	// fen 4ka3/4a4/2P1bc3/8R/2b6/9/9/3K5/4A4/2B6 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
			if(!IsOnSameSide(mpawn,ypao) && abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(4);
			}
		}
	}
	

	// fen 4ka3/4a4/2P1bc3/8R/2b6/9/9/3K5/4A4/2B6 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		RETRUN_MUL(8);
	}
}

