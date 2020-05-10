#ifndef END_my_m_MT_R_2che1pawn_B_1che1pao
#define END_my_m_MT_R_2che1pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车1兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




//2车1兵对2车
void my_m_MT_R_2che1pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2车x兵对2车_byPawn[your_shi_num]);
	
    int mcan = EV_MY_CAN;

	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);

	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) == 0){
			// 我方有车不能动了。
			if(have_bit(EV_YOUR_XBIT,bb_my_che) && StoY(mpawn) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3cka3/r1P1a4/2R1b3b/9/5R3/9/9/4B4/4A4/3A1KB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){

		// fen 2bak4/4a4/4bc3/2P1R4/1r7/9/3R5/9/4A4/2B1K1B2 w - - 0 1
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(128);
		}

		if(StoY(mpawn) == MY_RANK1 && bit_is_set(ei.attacked_by(your_che),mpawn)){
			if(MY_SQ03 == ypao && StoX(mpawn) <= 0x2){
				RETRUN_MUL(4);
			}
			if(MY_SQ05 == ypao && StoX(mpawn)>= 0x6){
				RETRUN_MUL(4);
			}
		}
	}

	
	if((your_xiang_num + your_shi_num) == 4 && PB90(MY_SQ04) == your_king){

		MY_EV_SUB(96);

		// fen 2bak4/9/3ab4/9/9/9/9/B2AR4/2r1Ap1r1/2BCK4 b - - 144 144
		if(StoX(yche) == 0x4 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) < 4 && PB90(MY_SQ05) == your_pao){
				if(PB90(MY_SQ06) == your_xiang && PB90(MY_SQ1A) == your_xiang){
					RETRUN_MUL(4);
				}
			}
			if(StoX(mpawn) > 4 && PB90(MY_SQ03) == your_pao){
				if(PB90(MY_SQ02) == your_xiang && PB90(MY_SQ12) == your_xiang){
					RETRUN_MUL(4);
				}
			}
		}
		// fen 7C1/4k4/9/9/3r5/R8/5r1p1/4B4/4A4/3AK1B2 w - - 0 1
		if(my_shi_num == 0 && my_xiang_num == 0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(4);
			}
		}	

		// fen 2b1ka3/1P2a4/4bc1R1/5R3/2r6/9/9/4B4/4A4/3AK4 r
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) <= 0x1 && StoX(yche) == 0x2 && StoX(ypao) > 0x4){
				RETRUN_MUL(6);
			}
			if(StoX(mpawn) >= 0x7 && StoX(yche) == 0x6 && StoX(ypao) < 0x4){
				RETRUN_MUL(6);
			}
		}

		// fen 2bak4/4a4/4b4/5R3/4r1c2/2PR5/9/4B4/4A4/4KAB2 w - - 8 8
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(mcan == 0 || StoX(yche) == 0x4){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}

		// fen 3ak1b2/1c2a4/4b4/2P1R1R2/9/7r1/9/4B4/4A4/3AK1B2 w - - 0 1
        if(yk == MY_SQ04){
			if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
				if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
					RETRUN_MUL(8);
				}
			}
		}

		

		// fen 2b1k1cR1/4aP3/1R1ab4/9/4r4/9/9/8B/4A4/4K4 b - - 0 1
		if(StoY(ypao) == MY_RANK0 && IsOnSameSide(mpawn,ypao)){
			RETRUN_MUL(12);
		}
	}
}



