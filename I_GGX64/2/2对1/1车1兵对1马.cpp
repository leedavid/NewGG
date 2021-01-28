#ifndef END_my_m_MT_R_1che1pawn_B_1ma
#define END_my_m_MT_R_1che1pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//1车1兵对1马
void my_m_MT_R_1che1pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_CheXPawn_To1Ma_ByPawnShi[your_shi_num]);
	}

	MY_EV_ADD(ADD_CheXPawn_To1Ma);

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){

		// fen 3aka3/3P5/4n3b/9/6b2/7R1/9/B8/4K4/6B2 w - - 0 1
       if(MY_SQ04 == yk && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(MY_SQ16 == yma){
				// 二个相在一边
				if(!have_bit(bb_your_xiang,LeftBB[0x4]) && StoX(mpawn) < 0x4 
					&& PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(2); 
				}
				if(!have_bit(bb_your_xiang,RightBB[0x4]) && StoX(mpawn) > 0x4
					&& PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}

		if(StoY(yma) MY_LARGE_EQL MY_RANK2){
			// fen 5k3/4a4/3ab4/3N5/9/6B2/9/3AB4/4Ar3/4K2p1 w - - 0 1
			if(StoY(mpawn) == MY_RANK0){
				if(abs(StoX(mpawn) - 0x4) >= 3){
					RETRUN_MUL(2);
				}
			}
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){

				// fen 1R1aka3/5P3/b3n4/9/2b6/9/9/3AK3B/9/3A5 w - - 0 113
				if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 || abs(StoX(mpawn) - 0x4) >= 2){
					// fen 3ak4/4a4/2P1n3b/4R4/6b2/6B2/9/4BA3/9/4KA3 b - - 0 1
					if(PB90(MY_SQ16) == your_ma){
						if(count_1s(bb_your_xiang,LeftBB[0x4]) == 2){
							RETRUN_MUL(4);
						}
						if(count_1s(bb_your_xiang,RightBB[0x4]) == 2){
							RETRUN_MUL(4);
						}
					}
				}


				RETRUN_MUL(8);
			}
		}
	}

	// fen 1R1aka3/5P3/b3n4/9/2b6/9/9/3AK3B/9/3A5 w - - 0 113

	
}

