#ifndef Emy_m_MT_R_1MA
#define Emy_m_MT_R_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h" 
#include "1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif  

//红方一个马
void my_m_MT_R_1MA(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);

	// MY_EV_ADD(32);

	// 对方有双相 或双仕
	if(your_shi_num == 2 || your_xiang_num == 2){
		RETRUN_MUL(1);
	}
	// fen 3k5/3Na4/9/9/9/6B2/9/5A3/9/2BK1A3 w - - 41 41
	// 红马给黑将牵制住了, 也是和棋
	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(your_king_pos MY_ADD 9) == my_ma){
			if (your_xiang_num >= 1 || your_shi_num >= 1){
				RETRUN_MUL(1);
			}
		}
	}
	// 对方有相
	if(your_xiang_num == 1){

		Square yx = S90_from_piecelist(POSITION, your_xiang, 0);
		if(your_shi_num >= 1){
			RETRUN_MUL(2);
		}

	    //fen 2ba1kb2/9/3a5/9/9/9/3n5/8B/3K5/9 w - - 0 1
		if (StoX(yk) < 0x4){
			if (StoX(yx) >= 4){
				RETRUN_MUL(2);
			}
		}
		if (StoX(yk) > 0x4){
			if (StoX(yx) <= 4){
				RETRUN_MUL(2);
			}
		}

		// fen 9/9/5k3/9/5Nb2/9/9/B8/9/4KAB2 b - - 0 1
		//if(have_bit(bb_your_xiang,RankBB_A[MY_RANK4])){
		//	if(!IsOnSameSide(yx,yk)){
		//	   RETRUN_MUL(4);
		//	}
		//}

		//// fen 3k5/9/4b4/6N2/9/9/9/9/9/4K4 w
		//if (StoX(yk) == 0x3 && StoX(yx) >= 0x4){
		//	RETRUN_MUL(4);
		//}
		//if (StoX(yk) == 0x5 && StoX(yx) <= 0x4){
		//	RETRUN_MUL(4);
		//}

		// fen 4k4/9/b3N4/9/9/9/9/5A3/9/5K3 b - - 0 1
		if (StoX(yk) >= 0x4 && StoX(yx) < 0x4){
			RETRUN_MUL(4);
		}
		if (StoX(yk) <= 0x4 && StoX(yx) > 0x4){
			RETRUN_MUL(4);
		}

	}

	// fen 5k3/9/5N3/9/6b2/9/9/B2AB4/4A4/5K3 w - - 0 1
	if (your_xiang_num >= 1){
		if (isStringByChe(POSITION, mk, mma, yk)){
			RETRUN_MUL(4);
		}
	}

	//if (your_shi_num >= 1 && your_xiang_num >= 1){
	//	RETRUN_MUL(8);
	//}
}

