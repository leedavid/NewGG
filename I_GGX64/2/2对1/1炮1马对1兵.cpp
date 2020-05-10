#ifndef END_my_m_MT_R_1pao1ma_B_1pawn
#define END_my_m_MT_R_1pao1ma_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao1ma_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	//困死一个炮// fen 3a1Cb2/5k1N1/4b4/9/9/6B2/2p6/4BA3/9/3AK4 w - - 17 17
	if (your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(yk) == MY_RANK1 && StoY(mpao) == MY_RANK0){
			if(StoY(ypawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpao)-0x4) <= 1){
				Bitboard bbp = POSITION.Rook_attacks_bb(mpao);
				bbp = _mm_andnot_si128(BitboardOCC,bbp);
				if(count_1s(bbp) <= 1){
     			   	RETRUN_MUL(2);
				}
			}
		}
		//if(StoY(ypawn) MY_LARGE_EQL MY_RANK5 && PB90(MY_SQ16) == your_xiang){
		//	if(StoY(yk) == MY_RANK1 && StoX(your_king_pos) == StoX(mpao)){

		//	}
		//}
	}

	// fen 5k3/4P4/9/2c6/9/9/9/3A4B/5n3/5K3 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		if (my_shi_num == 0 && my_xiang_num == 0){
			if (StoY(mma) MY_SMALL MY_RANK3 
				&& abs(StoY(mma) - StoY(yk)) == 1
				&& isStringByChe(POSITION, yk, mma, mk)){
				RETRUN_MUL(2);
			}
		}
	}

   // fen 3k5/3N5/9/9/2b6/2B6/5p3/4B4/3K5/3C5 w - - 0 1
   if(my_shi_num == 0){
	   if(StoY(ypawn) == MY_RANK6){
		   if(StoX(yk) != 0x4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			   if((yk MY_ADD 0x9) == mma){
				   RETRUN_MUL(2);
			   }
		   }
	   }
   }

}

