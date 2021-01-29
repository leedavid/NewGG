#ifndef Emy_m_MT_R_1PAO_B_1PAWN
#define Emy_m_MT_R_1PAO_B_1PAWN
#include "../../chess.h"
#include "../../preGen.h"
 
#include "1炮对1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif  
// 能不能和，怎样胜

// 我方一个炮, 对方一个兵
void my_m_MT_R_1PAO_B_1PAWN(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yk = your_king_pos;
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);

	// fen 9/3k5/3a5/9/6b2/2B6/5p3/3A5/4A4/2BCK4 r
	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(128);
	}

	if(StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(64);
		if(abs(StoX(ypawn) - 0x4) <= 2){
			MY_EV_SUB(64);
			if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 9/4k4/4b4/9/9/9/5p3/3K1A2B/4A4/4C1B2 b - - 0 1
	if (StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(64);
	}

	// 炮方 0 仕
	if(my_shi_num == 0){
		RETRUN_MUL(1);
	}
	// 炮仕相全和2相
	if(your_xiang_num ==  2){
		RETRUN_MUL(1);
	}
	///////////////////////////////////////////////////////////////////////////////////
	// 43局，炮仕相全和单仕相
	if(your_xiang_num == 1){
		if(your_shi_num == 2) {
			RETRUN_MUL(1);
		}
		if(your_shi_num == 1){ //对方有一个以上的仕, 这儿得判断一下是不是中炮控制了	
			if(m_have_bit(
				m_and(POSITION.Pao_Super_bb(your_king_pos),
				bb_my_pao))){
					// fen 4k4/4a4/9/9/2p6/6b2/9/3A5/4K4/4C4 w
					// board_display(POSITION,"zhong pao!!");
			}
			else{
				RETRUN_MUL(1);
			}
		}
	}
	if(FALSE){
	}
	else if(my_shi_num == 1){
		// *********************************************************************
		// 第7局, 低兵巧和炮仕相 <<象棋殘局例典>>
		// fen 3ak4/9/4bP3/9/c8/9/9/9/9/4K4 w
		// fen 4k4/9/9/9/9/8C/9/3pB4/9/4KA3 b
       if(my_xiang_num == 0 && PB90(MY_SQ43) == your_pawn){
		   RETRUN_MUL(1);
	   }
	   int ms = S90_from_piecelist(POSITION,my_shi,0);
	   // 兵在底线，不能上来
	   // fen 4k4/9/9/9/9/8C/9/4B4/3p5/4KA3 b
	   if(StoY(my_king_pos) == MY_RANK9 && StoY(ms) == MY_RANK9){
		   if(ypawn == MY_SQ4B || ypawn == MY_SQ4D){
			   RETRUN_MUL(1);
		   }
	   }
	}
	else if(my_shi_num == 2){
	}
	// 炮仕例和卒仕
	// 黑方将,仕互保, 卒走闲着, 例成和局
	// 例典 page 98 
	// fen 9/3k5/3a5/9/9/2B6/6p2/3A1K2B/3C5/9 b - - 122 122
	if(your_shi_num != 0 && my_shi_num <= 1){
		if(StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/9/9/9/2b6/9/4p2C1/9/4A4/4K1B2 w - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1 && my_shi_num <= 1){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(abs(StoX(ypawn) - 0x4) <= 1){
				RETRUN_MUL(2);
			}
		}
	}

	if(your_shi_num == 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				RETRUN_MUL(2);
			}
			// fen 2bak4/4a4/9/9/6b1c/4P4/9/3A5/4A4/4K4 w - - 121 121
			// fen 4k4/4a4/5a3/9/4p4/C1B6/9/9/4A4/4KAB2 b
			if(StoY(ypawn) == MY_RANK4 && StoX(mpao) != StoX(ypawn)){
			  if(ypawn == MY_SQ24 || ypawn == MY_SQ28 || ypawn == MY_SQ2C){
				  RETRUN_MUL(4);
			  }
			}			
		}
		// fen 2bak4/8c/5a3/9/6b2/4P4/9/3A1A3/9/5K3 w - - 0 0
		// fen 2bak4/5c3/5a3/9/6b2/4P4/9/5A3/4A4/5K3 w - - 0 0
		// fen 3k1a3/4a4/9/9/4p4/2B6/9/3AB4/4C4/4KA3 b - - 0 0
	}

	// fen 4c4/5k3/3a1a3/5P3/9/9/9/3A1A3/9/4K4 b - - 0 0
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(4);
		}
	}

	// fen 1c2k1b2/4a4/9/3P5/9/9/9/9/9/4K4 b - - 0 1
	// fen 4k4/9/9/9/9/9/5p3/9/4A4/2B1K2C1 w - - 0 1
	if(my_shi_num <= 1 && my_xiang_num <= 1){
		if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 1){
			if(!bit_is_set(EV_MY_XBIT,ypawn)){ // fen 4k4/9/9/9/9/9/4p4/9/4A4/2BKC4 b
				RETRUN_MUL(4);
			}
			//RETRUN_MUL(8);
		}
	}

	// fen 9/4k4/4b4/9/9/9/5p3/4B4/4C4/2BAKA3 w - - 0 1
	if(your_xiang_num >= 1 && StoY(ypawn) == MY_RANK6
		// fen 9/4k4/4b4/9/9/9/5p3/3K1A2B/4A4/4C1B2 b - - 0 1//
		&& !have_bit(bb_my_shi,RankBB_A[MY_RANK7])){
		RETRUN_MUL(4);
	}

	// fen 9/4k4/3a5/9/9/6B2/6p2/3A1A3/1C7/5K3 b - - 0 1
	if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && have_bit(bb_your_shi,MyLowBB[StoY(yk)])){
		   RETRUN_MUL(4);
		}
	}

	// fen 9/4ak3/9/9/9/9/1p7/3A1A2B/5C3/2B2K3 b - - 0 1
	if (your_shi_num >= 1 && StoY(ypawn) == MY_RANK6) {
		RETRUN_MUL(4);
	}

	// fen 9/1P3k3/3ac4/9/9/9/9/5A3/9/3K1A3 w - - 0 1
	//if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	//	RETRUN_MUL(4);
	//}

	// fen 3ak4/9/9/9/9/2B6/3p5/5A3/3K5/6C2 b - - 0 1
    if(StoY(ypawn) == MY_RANK6){
		if(my_shi_num <= 1 && my_xiang_num <= 1 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(8);
		}
	}
	// fen 9/5k3/9/9/9/5C3/6p2/9/4AK3/9 b - - 0 1
	if(my_xiang_num == 0 && my_shi_num <= 1){
		if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 2){
			RETRUN_MUL(8);
		}
	}

	// fen 4k4/4a4/9/9/9/9/3C2p2/5A3/4AK3/9 w - - 0 1
	// fen 9/3k5/3a5/9/9/2B3B2/6p2/3A5/3CA4/5K3 r
    if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(8);
		}
	}
}

