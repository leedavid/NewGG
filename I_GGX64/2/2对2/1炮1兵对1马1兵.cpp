#ifndef END_my_m_MT_R_1pao1pawn_B_1ma1pawn
#define END_my_m_MT_R_1pao1pawn_B_1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1兵对1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//炮兵对马兵
//const int PaoPawn_MaPawn_PaoNoShi = 128;

void my_m_MT_R_1pao1pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	//int mcan  = EV_MY_CAN;
	sint16 ycan  = EV_YOUR_CAN;
	
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);

	// fen 4P3c/9/3k5/9/9/3N5/9/5p3/9/5K3 w - - 0 1
	if(StoY(ypawn) == MY_RANK9 || EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}

	if((your_shi_num + your_xiang_num) >= 3){
		EV_YOUR_SAFE = TRUE;
	}

	if(my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}

	// fen 5k3/4P4/9/9/9/9/3p5/3A5/3KA2n1/1C7 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	if((your_shi_num + your_xiang_num) >= 2 && (my_shi_num + my_xiang_num) >= 2){
		RETRUN_MUL(2);
	}

	if(my_shi_num == 0 && EV_YOUR_CAN){
		EV_YOUR_SAFE = TRUE;
	}

	if(my_shi_num == 0){
		MY_EV_SUB(ycan * 128);
		// fen 4k4/3P5/9/8p/4N4/9/8c/2p1B4/3KAp3/3A5 b - - 7 7
		if(my_xiang_num == 0 && StoY(ypawn) MY_SMALL StoY(mk)){
			MY_EV_SUB(128);
		}
	}
	// fen 2P6/3k5/6c2/9/9/9/5N3/4K4/7p1/9 b - - 72 72
	if(StoY(mpawn) MY_SMALL_EQL StoY(yk) && my_shi_num == 0){
		if(StoY(ypawn) == MY_RANK9){
			RETRUN_MUL(2);
		}
	}

    // fen 9/3k5/4P1cNb/9/9/2B6/4p4/8B/9/3A1K3 w - - 120 120
    // fen 3k1a3/9/b8/4P4/6b2/9/9/BnC1p4/5K3/9 b
	if(my_shi_num == 0 && my_xiang_num >= 1 
		&& StoY(mpawn) MY_SMALL_EQL MY_RANK4){
			if(your_shi_num >= 1 && your_xiang_num >= 1){
				if(MY_SQ43 == ypawn){
					if(MY_SQ4B == mk && MY_SQ45 == mpao && MY_SQ46 == yma){
							RETRUN_MUL(4);
					}
					if(MY_SQ4D == mk && MY_SQ41 == mpao && MY_SQ40 == yma){
							RETRUN_MUL(4);
					}
				}
			} 
	}

	// fen 2b1k4/4a4/5a3/9/9/P1n6/9/5Cp2/5K3/9 w - - 0 1
	// fen 8c/5k3/9/9/N8/8P/9/B2AB4/3pA4/4K4 w - - 0 1 not he
	if(EV_YOUR_SAFE){
		//if(EV_MY_CAN >= 1 && StoY(mk) != MY_RANK9){
		//	MY_EV_ADD(64);
		//	if(StoY(mpao) MY_LARGE_EQL MY_RANK6){
		//		RETRUN_MUL(4);
		//	}
		//}
	}

	// fen 4k4/9/6N2/9/9/5p2c/P8/9/3K5/3A1A3 w - - 202 202
	// fen 3a1a3/5k3/9/8p/C2P5/9/9/2n6/9/4K4 w
	// 对方的 兵不能过河
	if(StoY(ypawn) == MY_RANK3 && StoY(mpawn) == MY_RANK4){
		if(your_xiang_num == 0){
			Bitboard peat = POSITION.Pao_Eat_bb(mpao);
			if(bit_is_set(peat,ypawn MY_ADD 9)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4P4/4a4/3k5/6C2/2b3b2/9/7n1/B3B4/5p3/4K4 w - - 0 0
	if(my_xiang_num == 2 && my_shi_num == 0){
		if(StoY(mk) != MY_RANK9 || MY_SQ4C != ypawn){
			RETRUN_MUL(4);
		}
	}
	// fen 9/5k3/4P1cNb/9/9/2B6/9/5A3/2p1A4/4K1B2 w - - 0 1
	if(EV_MY_CAN > 0 && my_xiang_num >= 1){
		if(PB90(MY_SQ43) == your_pawn && StoY(mk) == MY_RANK8){
			if(PB90(MY_SQ41) == my_pao && PB90(MY_SQ40) == your_ma){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ45) == my_pao && PB90(MY_SQ46) == your_ma){
				RETRUN_MUL(4);
			}
		}
	}

	//9/4k1P2/9/9/3n5/9/9/4p4/C3A4/4KA3 b - - 0 166
	if(my_shi_num == 2 && my_xiang_num == 0 && PB90(MY_SQ43) == your_pawn){
		RETRUN_MUL(4);
	}

	// fen 9/4a4/3k5/p1N6/9/P8/9/9/4AK3/c1BA2B2 b - - 0 1
	if(EV_MY_CAN == 0 || (your_shi_num + your_xiang_num) >= 3){
         if(EV_YOUR_CAN == 0 && (my_shi_num + my_xiang_num) >= 1){
			 if(bit_is_set(ei.attacked_by(my_pao),mpawn)){
				 RETRUN_MUL(4);
			 }
		 }
	}

	// fen 5k3/4P4/b5c2/6N2/9/2B6/2p6/3ABA3/9/3K5 w - - 0 1
	if(EV_YOUR_SAFE && StoY(mpawn) == MY_RANK3){
		if((my_shi_num + my_xiang_num) >= 1){
			if(StoY(mpao) MY_LARGE_EQL StoY(yma)){
				RETRUN_MUL(4);
			}
		}
	}
    

	// fen 9/4k4/5a3/9/p8/2B6/P8/1CnAB4/4A4/4K4 b - - 0 1
	if(EV_MY_CAN == 0){
		if(your_shi_num >= 1 || your_xiang_num >= 1){
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ40) == my_pao && PB90(MY_SQ41) == your_ma){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ46) == my_pao && PB90(MY_SQ45) == your_ma){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a5/5k3/3a5/C8/9/P8/9/3K1n3/5p3/9 b - - 0 1
	if(your_shi_num == 2 && StoY(ypawn) MY_LARGE StoY(mk)){
		if(EV_MY_CAN && my_shi_num <= 1){
			RETRUN_MUL(4);
		}
	}

	// fen 5a3/3k4P/4ba3/9/2b6/8n/9/3p2C1B/4K4/9 w - - 0 1
	if(EV_YOUR_SAFE && EV_MY_CAN >= 1){
		if(StoY(mk) != MY_RANK9 && my_xiang_num >= 1){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/3P5/3a1a2b/9/2b6/9/3C2n2/5K3/2p1A4/9 b - - 39 39
	if(StoY(ypawn) MY_LARGE StoY(mk)){
		if(my_shi_num >= 1){
			MY_EV_ADD(128);
		}
		if((your_shi_num + your_xiang_num) >= 3){
			RETRUN_MUL(6);
		}
	}

	// fen 3a5/3k5/9/3P5/5n3/9/7C1/4B3B/4p4/5K3 r
	if(EV_YOUR_SAFE){
		if(my_xiang_num == 2){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK6){
				RETRUN_MUL(6);
			}
		}
	}


	// fen 5k2N/9/4P1c1b/9/9/2B3B2/9/3A1A3/p3K4/9 w - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) != MY_RANK0){
		if(EV_YOUR_CAN >= 1){
			RETRUN_MUL(8);
		}
	}
	
	// fen 3k5/9/3P5/9/5n3/9/9/5K3/9/C3p4 b - - 0 1
	if(EV_MY_SAFE){
		if(my_shi_num == 0 && my_xiang_num == 0){
			RETRUN_MUL(8);
		}
	}

	// fen 4k4/9/4ba3/9/1P4b2/n8/6p2/9/4A4/3CK4 b - - 0 1
	if(EV_YOUR_SAFE){		
		if(my_shi_num >= 1 && EV_MY_CAN >= 1){
			if(StoY(mpawn) == MY_RANK4 || StoY(mpawn) == MY_RANK3){
				if(StoY(mpao) MY_SMALL_EQL MY_RANK7){
					MY_EV_ADD(64);
				}
				if(abs(StoX(mpawn) - 0x4) <= 1){
					MY_EV_ADD(32);
				}
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5a3/4a4/5k3/2P6/9/3C5/9/3A1n3/6p2/3K5 b - - 0 1
	if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8 && !IsOnSameSide(mk,ypawn)){
		if(your_shi_num == 2 && StoY(mpawn) == MY_RANK3){
			RETRUN_MUL(8);
		}
	}

	// fen 5k3/4P4/9/9/9/9/3p5/3A5/3KA2n1/1C7 w - - 0 1
	if(EV_MY_SAFE){
		if(StoY(ypawn) == MY_RANK6 && !bit_is_set(EV_MY_XBIT,yma)){
			RETRUN_MUL(8);
		}
	}

	// fen 9/5k3/9/4p4/9/2n5P/9/C7B/4A4/3K1A3 w - - 0 1
	if(EV_MY_SAFE){
		if(EV_YOUR_CAN >= 1 && !bit_is_set(EV_MY_XBIT,yma)){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
			if(abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(8);
			}
			if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 2){
				RETRUN_MUL(8);
			}
		}
	}
}

