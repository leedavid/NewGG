#ifndef END_my_m_MT_R_1CHE2PAWN_B_1CHE1PAO
#define END_my_m_MT_R_1CHE2PAWN_B_1CHE1PAO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int const_Pawn_Shi_Add[3] = {128,96,32};

// 我方 一车二兵 对方 车炮
void my_m_MT_R_1CHE2PAWN_B_1CHE1PAO(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePawn_To_ChePao_Pawn_Shi_Add[your_shi_num]);

	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square ypao   = S90_from_piecelist(POSITION,your_pao,0);

	int mcan = EV_MY_CAN;

	// fen 4ka3/4a4/4P3c/P1R6/9/8r/9/4B4/4A4/2B1KA3 w - - 0 1
	if(your_shi_num == 2 && MY_SQ04 == yk){
		MY_EV_SUB(64);
		//if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
		//	MY_EV_SUB(32);
		//}
	}
	// fen 4ka3/4a4/c1r6/4P4/4R2P1/9/9/9/4K4/9 b - - 0 1
	if(your_xiang_num == 2){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 2b1kar2/3P1R3/b3c4/9/8P/6B2/9/9/9/5K3 b - - 0 1
	if (your_shi_num <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
		Bitboard pup = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
		if (have_bit(pup, m_and(LeftBB[0x6], RightBB[0x2]))){
			MY_EV_ADD(EV_MY_CAN * 16);
			if ((my_shi_num + my_xiang_num) >= 1){
				MY_EV_ADD(EV_MY_CAN * 16);
				if (StoY(yche) == MY_RANK0){
					MY_EV_ADD(32);
				}
				if (EV_MY_CAN == 2){
					MY_EV_ADD(32);
				}
			}
		}
	}

	// fen 4k3c/4a1r2/5P3/2P6/9/3R5/9/9/4K4/9 b - - 0 1
	if (your_xiang_num == 0 && your_shi_num <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
		if (have_bit(MyUpBB[MY_RANK3], bmp)){
			MY_EV_ADD(32);
		}
	}

	// fen 3R5/5k3/4c4/9/2b5P/P8/9/9/6r2/2B1K4 b - - 0 1
	if(your_xiang_num >= 1 && my_shi_num == 0 && my_xiang_num <= 1){
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK4 && StoY(mpawn2) MY_LARGE_EQL MY_RANK4){
			if(abs(StoX(mpawn1) - 0x4) >= 3 && abs(StoX(mpawn2) - 0x4) >= 3){
				MY_EV_SUB(64);
				if(StoX(yk) == 0x4){
					MY_EV_SUB(32);
				}
			}
		}
	}

	int isString = isStringByChe(POSITION,mche,ypao,yche);

	if(isString){
		MY_EV_ADD(128); //如果车炮被牵制了, 则炮方要减分
	}	

	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0E) == my_pawn){
		}
		else{
			EV_YOUR_SAFE = TRUE;
		}
	}
	
	
	Bitboard lp = My_get_connect_Pawn(POSITION);

	// fen 3ak1b2/4a4/2c6/5PP2/4r4/3R2B2/9/4B4/3K5/9 b - - 41 41
	//如果红方有二个连兵,且过河了,也是安全的
	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		Bitboard b1 = m_and(lp,MyLowBB[MY_RANK2]);
		if(m_have_bit(b1)){
			EV_MY_SAFE = TRUE;
		}
	}

	if(your_shi_num >= 1){
		//红车不能动,也是黑方安全的
		if(PB90(MY_SQ55) == my_king && PB90(MY_SQ4C) == my_shi){
			if(PB90(MY_SQ54) == my_che && PB90(MY_SQ52) == your_che && PB90(MY_SQ51) == your_pao){
				EV_YOUR_SAFE = TRUE;
			}
			if(PB90(MY_SQ56) == my_che && PB90(MY_SQ58) == your_che && PB90(MY_SQ59) == your_pao){
				EV_YOUR_SAFE = TRUE;
			}
		}
	} 

	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

    
	//特殊的和形
	// fen 2b6/4P4/5k2b/9/5c1r1/8P/5R3/B7B/9/3AKA3 b - - 121 121
	if((my_shi_num + my_xiang_num) >= 1 && StoY(yche) == MY_RANK4){
		if(StoY(mpawn1) MY_SMALL StoY(yk) || StoY(mpawn2) MY_SMALL StoY(yk)){
			if(StoY(ypao) == StoY(yche) && StoY(mche) MY_LARGE StoY(yche)){ //挡住一个车
				if(PB90(MY_SQ35) == my_pawn || PB90(MY_SQ3E) == my_pawn){
					if(PB90(MY_SQ2B) == your_che && StoX(ypao) < StoX(yche)){
						RETRUN_MUL(2);
					}
				}
				if(PB90(MY_SQ2D) == my_pawn || PB90(MY_SQ36) == my_pawn){
					if(PB90(MY_SQ25) == your_che && StoX(ypao) > StoX(yche)){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
	// fen 4kab2/3Ra4/9/9/9/3pp4/5r3/3AB4/3CA4/4K1B2 w - - 11 11
	if(EV_YOUR_SAFE || (your_shi_num == 2 && StoY(yk)  MY_SMALL_EQL MY_RANK1)){
		if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
			Bitboard b1 = m_and(lp,MyLowBB[MY_RANK2]);
			if(m_have_bit(b1)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3akab2/1R7/4b4/3P1P3/c8/9/9/B8/3K5/2B1r4 b - - 0 1
	if (EV_YOUR_SAFE){
		if (my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if (StoY(mpawn1) == MY_RANK3 && StoY(mpawn2) == MY_RANK3){
				if (abs(StoX(mpawn1) - StoX(mpawn2)) <= 2){
					if ((abs(StoX(mpawn1) - 0x4) + abs(StoX(mpawn2) - 0x4)) <= 2){
						if (!(StoX(ypao) == StoX(mk) && StoY(ypao) MY_SMALL MY_RANK3)){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}

	// fen 3ak1b2/4a4/3c4b/8P/9/2BR2P2/7r1/3AB4/3KA4/9 b
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(EV_MY_CAN == 2){
				RETRUN_MUL(4);
			}
			else if(EV_MY_CAN == 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4ka3/4a4/c1r6/4P4/4R2P1/9/9/9/4K4/9 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}

	// fen 2b2P3/3k5/3rc4/2P6/9/9/9/4B3B/4A4/2R1KA3 b - - 128 128
	//1,一兵到底，另一个兵不能下去，
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 1 && StoY(mche) == MY_RANK9){
			if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
				MY_EV_SUB(128);
				// 看一下有没有铁门栓
				if(MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi && PB90(MY_SQ43) == my_xiang){
					if(PB90(MY_SQ16) == your_pao){
						if(PB90(MY_SQ56) == my_shi && PB90(MY_SQ15) == your_che){
							RETRUN_MUL(8);
						}
						if(PB90(MY_SQ54) == my_shi && PB90(MY_SQ17) == your_che){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}

	// fen 4ka3/4a4/c1r6/4P4/4R2P1/9/9/9/4K4/9 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK4]) && EV_MY_CAN == 2){
			RETRUN_MUL(8);
		}
	}
	
    // fen 1R4b2/3r1k1P1/8b/9/9/6P2/9/3AB1c2/4A4/2B1K4 w - - 129 129
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(mcan <= 1){
			MY_EV_SUB(168);
		}
		if(your_shi_num == 0 && (my_shi_num + my_xiang_num) >= 3){
			RETRUN_MUL(8);
		}
	}

	// fen 2b1ka1RC/4a4/8r/9/6p2/4p4/9/4B4/4A4/2BAK4 b - - 0 1
    if(my_shi_num == 2 && PB90(MY_SQ55) == my_king){
		if(StoY(yche) == StoY(ypao) && StoY(yche) == MY_RANK9){
			if(bit_is_set(MY_ATTACK,ypao) && bit_is_set(YOUR_ATTACK,ypao)){
				if(abs(StoX(ypao) - 0x4) > abs(StoX(yche) - 0x4)){
					MY_EV_ADD(64);
					MY_EV_ADD(EV_MY_CAN * 64);
				}
			}
		}
	}

	// fen 2b1ka3/2R1aPP2/5c3/9/4r4/9/9/9/9/5K3 b - - 0 1
    if(your_shi_num == 2 && your_xiang_num <= 1 && StoY(mche) == MY_RANK1){
		if(PB90(MY_SQ0E) == my_pawn && PB90(MY_SQ0F) == my_pawn){
			if(StoX(mche) < 0x4 && StoX(mk) >= 0x4){
				RETRUN_MUL(8);
			}
		}
		if(PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0B) == my_pawn){
			if(StoX(mche) > 0x4 && StoX(mk) <= 0x4){
				RETRUN_MUL(8);
			}
		}
	}

}

