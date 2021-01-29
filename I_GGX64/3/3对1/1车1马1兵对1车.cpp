#ifndef END_my_m_MT_R_1che_1ma_1pawn_B_1che
#define END_my_m_MT_R_1che_1ma_1pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马1兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che_1ma_1pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	//兵不能过河,马被牵制了,对方是仕相全,也是和棋
    // fen 2b1kab2/9/3a5/9/6p2/2B4R1/7n1/4B4/3KA2r1/5A3 w - - 120 120
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square yk = your_king_pos;

	bool isString = isStringByChe(POSITION,mche,mma,yche); //车马牵制了
	int mcan = EV_MY_CAN;
	
	if(isString){
		MY_EV_SUB(128);
	}
	// fen 3ak4/9/4b4/4R4/4n1b2/2B1r3p/9/4B4/4A4/4KA3 b - - 0 59 not he
	if((your_xiang_num + your_shi_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(128);

		if(MY_SQ04 == yk){
			MY_EV_SUB(64);
		}

		if(isString){	
			Bitboard bn = BetweenBB[mche][mma];
			if(count_1s(bn) != 1 || count_1s(bn) != 3){
				if(mcan == 0){
					RETRUN_MUL(2);
				}
				// fen 4k1b2/4a4/4baP2/9/9/3rN1R2/9/9/4AK3/9 w - - 40 40
				// fen 3a5/5k3/9/9/3r5/9/3n5/2p1BA2B/4A4/3R1K3 w - - 36 36
				if(StoY(mpawn) MY_SMALL StoY(mma)){
					RETRUN_MUL(4);
				}
			}
			RETRUN_MUL(8);
		}

		// fen 4k1b2/4a4/3ab4/4Nr3/9/6P2/4R4/9/9/3AKA3 b - - 0 1
		if (StoY(yk) == MY_RANK0){
			if (my_xiang_num == 0 && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				if (abs(StoX(mpawn) - 0x4) <= 2){
					RETRUN_MUL(6);
				}
			}
		}

		// fen 3ak1b2/2P1a4/3rb4/3N1R3/9/2B6/9/9/4AK3/2BA5 b - - 120 120
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(8);
			}
		}

		// fen 4k4/4a4/4b4/9/6b2/2B6/1r3n3/6R2/4A1p2/2B1KA3 b - - 0 99
		if(StoX(mpawn) <= 0x4 && PB90(MY_SQ03) == your_shi){
			MY_EV_SUB(80);
		}
		if(StoX(mpawn) >= 0x4 && PB90(MY_SQ05) == your_shi){
			MY_EV_SUB(80);
		}

		// fen 3aka3/6R2/b4r2b/4PN3/9/6B2/9/4BA3/4A4/4K4 w - - 121 121
		//如果对方是仕相全，且我方的兵在三线上面，就返回９
		// 3a1k3/3Pa4/b3r3b/3R1N3/9/9/9/3A1A3/9/5KB2 b - - 120 120
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			RETRUN_MUL(8);
		}

		// fen 3k5/4aP3/b2rba3/3N3R1/9/9/9/3AB4/4A4/4K1B2 b - - 0 1
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(!IsOnSameSide(yk,mpawn)){
				if(StoX(yk) <= 0x4 && StoX(yche) < 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
					RETRUN_MUL(8);
				}
				if(StoX(yk) >= 0x4 && StoX(yche) > 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
					RETRUN_MUL(8);
				}
			}
		}

		// fen 1N1ak4/4a4/2P1b4/2r6/1Rb6/2B6/9/4B4/4A4/3AK4 b - - 0 1
		if(MY_SQ04 == yk && StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) <= 0x3 && PB90(MY_SQ03) == your_shi){
				if(StoX(yche) < 0x4 && MY_SQ01 == mma){
					RETRUN_MUL(8);
				}
			}
			if(StoX(mpawn) >= 0x5 && PB90(MY_SQ05) == your_shi){
				if(StoX(yche) > 0x4 && MY_SQ07 == mma){
					RETRUN_MUL(8);
				}
			}
		}

	}

	
}

