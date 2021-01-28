#ifndef END_my_m_MT_R_2CHE_B_1CHE1MA
#define END_my_m_MT_R_2CHE_B_1CHE1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//双车方加分

//const int 双车vs车马_车方加分 = 64;

//我方2车，对方一车一马
void my_m_MT_R_2CHE_B_1CHE1MA(typePOS &POSITION, EvalInfo &ei){



	MY_EV_ADD(80);

	Square yk = your_king_pos;
	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	

	// 如果黑方是仕相全,且将在原位,则是和棋
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == your_xiang){
			RETRUN_MUL(2);
		}
	}

	// 例典: page 440 fen 3ak4/4a4/4b1n2/1R7/4r4/3R5/9/9/9/3K5 w
	// 双车例和车马单缺象 其方法是全力坚守
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(PB90(MY_SQ0D) == your_shi && PB90(MY_SQ16) == your_xiang){
			if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ05) == your_ma){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ03) == your_ma){
				RETRUN_MUL(2);
			}
		}

		//车马也能和单缺象哇
		// fen 3a1k3/4a4/9/9/8R/9/9/2rN5/4Ar3/2B1KA3 b - - 4 4
		if(MY_SQ04 == yk && PB90(MY_SQ0D) == your_shi){
			if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ05) == your_shi && PB90(MY_SQ02) == your_xiang){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ03) == your_shi && PB90(MY_SQ06) == your_xiang){
				RETRUN_MUL(2);
			}
		}

		// fen 4kab2/4aR3/4R4/4n1r2/9/9/9/4B4/9/2BAKA3 w - - 0 0
		// 红方二个车一个也不能动了,也是和棋
		if(StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ1F) == your_ma && PB90(MY_SQ16) == my_che){
				//Square yche = S90_from_piecelist(POSITION,your_che,0);
				Bitboard cheeat = POSITION.Rook_attacks_bb(Square(MY_SQ1F));
				if(bit_is_set(cheeat,yche)){
					if(PB90(MY_SQ0C) == my_che && PB90(MY_SQ05) != your_shi && PB90(MY_SQ02) == your_xiang){
						RETRUN_MUL(2);
					}
					if(PB90(MY_SQ0E) == my_che && PB90(MY_SQ03) != your_shi && PB90(MY_SQ06) == your_xiang){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
	
	// 例典: page 440
	// 双车例和车马单缺仕 黑士在底线可和,中线则负
	// fen 
	if(your_xiang_num == 2 && your_shi_num >= 1){
		if(StoY(yk) == MY_RANK0 && PB90(MY_SQ16) == your_ma){
			if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ06) == your_xiang && PB90(MY_SQ1A) == your_xiang){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ02) == your_xiang && PB90(MY_SQ12) == your_xiang){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5kb2/4a4/4br3/1N7/6r2/9/9/BR6B/4A4/4KA3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk) {
		if (StoY(yche) == MY_RANK2) {
			RETRUN_MUL(4);
		}
	}


	// fen 5kb2/4a4/4br3/1N7/6r2/9/9/BR6B/4A4/4KA3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk) {
		if (StoY(yche) MY_SMALL_EQL MY_RANK4) {
			RETRUN_MUL(8);
		}
	}

	// fen 3aknr2/4aR3/9/4R4/9/9/9/3A4B/9/3A1KB2 w - - 0 1
    if(your_shi_num == 2 && MY_SQ04 == yk){
		if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ05) == your_ma){
			RETRUN_MUL(8);
		}
		if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ03) == your_ma){
			RETRUN_MUL(8);
		}
	}



}

