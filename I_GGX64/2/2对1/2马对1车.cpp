#ifndef END_my_K_MT_R_2ma_B_1che
#define END_my_K_MT_R_2ma_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



// fen 5k3/4R4/4n4/9/3n5/9/9/9/9/4K4 w

void my_m_MT_R_2ma_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square mk   = my_king_pos;
	Square mma1 = S90_from_piecelist(POSITION,my_ma,0);
	Square mma2 = S90_from_piecelist(POSITION,my_ma,1);

	if(my_shi_num == 2 || my_xiang_num == 2){
		EV_MY_SAFE = TRUE;
	}
	if((your_shi_num + your_xiang_num) >= 1){
		EV_YOUR_SAFE = TRUE;
	}

	// 象棋残局例典 page 222  双马连环互保, 如立于中线,和"例和"一车
	if(StoY(mk) MY_LARGE MY_RANK7){//1,首先将要安全
		//2, 二个马在相中间以上
		if(StoY(mma1) MY_SMALL_EQL MY_RANK7 && StoY(mma1) MY_LARGE MY_RANK2){
			if(StoY(mma2) MY_SMALL_EQL MY_RANK7 && StoY(mma2) MY_LARGE MY_RANK2){
				//3, 马结连环了, 且是立于中线, 
				if(StoX(mma1) == 0x4 || StoX(mma2) == 0x4){
					if(abs(StoX(mma1) - StoX(mma2)) == 1){
						if(abs(StoY(mma1) - StoY(mma2)) == 2){
							RETRUN_MUL(2);
						}
					}
				}

				if((my_shi_num + my_xiang_num) >= 1){
					if(abs(StoX(mma1) - StoX(mma2)) == 2){
						if(abs(StoY(mma1) - StoY(mma2)) == 1){
							RETRUN_MUL(2);
						}
					}
				}
			}
		}
	}

	// fen 4k4/9/4bRn2/9/5n3/6B2/9/9/4K4/5A3 w - - 0 0
	if(PB90(MY_SQ43) == my_xiang && StoY(mk) MY_LARGE_EQL MY_RANK8){
		//if(bit_is_set(ei.attacked_by(my_ma],MY_SQ43)){
		//	//看一下马是不是连着的的.
		//}
		Bitboard ma_att = ei.attacked_by(my_ma);
		if(m_have_bit(m_and(ma_att,bb_my_ma))){
			if(bit_is_set(ma_att,Square(MY_SQ43))){
				RETRUN_MUL(4);
			}
			
			// fen 3a5/4k4/9/9/2b6/3N5/3r5/2N1B4/9/4K4 w, 这个是车挡住了. 
			if(have_bit(Ma_Pseudo_Att[MY_SQ43],bb_my_ma)){
				RETRUN_MUL(4); // fen 3a5/4k4/9/9/2b6/3N5/3r5/2N1B4/9/4K4 w
			}
		}
	}
        
	// fen 2b2k3/4a4/3a5/9/9/6N2/9/5N3/5K3/4r4 w - - 0 1
	if(StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(count_1s(ei.attacked_by(my_ma),bb_my_ma) == 2){			
			RETRUN_MUL(8);			
		}
	}
}


