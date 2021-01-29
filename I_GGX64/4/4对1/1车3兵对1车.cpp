#ifndef END_my_m_MT_R_1CHE_3PAWN_B_1CHE
#define END_my_m_MT_R_1CHE_3PAWN_B_1CHE
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车3兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//我方一车3兵，对方一车
void my_m_MT_R_1CHE_3PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){
	

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_Che_ByShi[your_shi_num]);

	//Square yk = your_king_pos;
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// fen 2bak1b2/4a4/9/P1P1R4/9/9/4P4/9/3K5/2r6 w - - 0 1
	if(EV_MY_CAN >= 3){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2b1ka3/4a2P1/9/4PP3/8R/9/6r2/4B4/4A4/2B1KA3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		MY_EV_SUB(64);
		//
		Bitboard patt = m_and(MyUpBB[MY_RANK3],m_and(LeftBB[0x6],RightBB[0x2]));
		patt = m_and(bb_my_pawn,patt); //fen 2b1ka3/4a4/4b4/6P2/9/2P1P3R/9/4B1r2/4K4/9 b - - 0 1
		MY_EV_SUB((3 - count_1s(patt)) * 32);
	}

	// fen 2bak1b2/4a4/9/7R1/P1P6/6r1P/9/3A1A3/5K3/9 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 16);

	if((my_shi_num + my_xiang_num) >= 2){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	int mcan = EV_MY_CAN;
    
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		// fen 2b1ka3/4a4/4b4/p8/9/4r4/2R1p3p/4B4/4A4/3AK1B2 w - - 0 1
		if(MY_SQ04 == yk){
			MY_EV_SUB(128);

			int p2l = (int)count_1s(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(p2l <= 1){
				MY_EV_SUB((3-p2l) * 48);
			}
		}

		// fen 3ak1b2/4a4/4b4/9/1r7/P3P2RP/9/4B4/4A4/3AK4 b - - 0 0
		//三个兵与车在一线,则也是和棋,
		if(StoY(mche) == MY_RANK5 && StoY(yche) == MY_RANK4){
			if(PB90(MY_SQ2D) == my_pawn && PB90(MY_SQ31) == my_pawn && PB90(MY_SQ35) == my_pawn){
				RETRUN_MUL(2);
			}
		}
		if(StoY(mche) == MY_RANK6 && StoY(yche) == MY_RANK5){
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ3E) == my_pawn){
				RETRUN_MUL(2);
			}
		}

		// fen 3ak4/4a4/b3b4/p7r/6p2/9/R7p/4B4/9/3AKAB2 b - - 122 122
		//没有那一个兵能走动的 车二兵组成了一个长方形
		if(mcan <= 2){
			if(PB90(MY_SQ1B) == my_pawn && PB90(MY_SQ3E) == my_pawn){
				if(PB90(MY_SQ36) == my_che && PB90(MY_SQ23) == your_che){
					if(PB90(MY_SQ02) == your_xiang){
						RETRUN_MUL(2);
					}
				}
			}
			if(PB90(MY_SQ23) == my_pawn && PB90(MY_SQ36) == my_pawn){
				if(PB90(MY_SQ3E) == my_che && PB90(MY_SQ1B) == your_che){
					if(PB90(MY_SQ06) == your_xiang){
						RETRUN_MUL(2);
					}
				}
			}
		}
		// fen 4kab2/4a4/4b4/9/2p3p1R/8p/9/4B4/4A4/2B1KA2r b - - 45 45
		// fen R2ak1b2/4a4/4b4/9/P8/r1P3P2/9/4B4/4A4/2BAK4 w - - 0 0
		if(mcan <= 1){
			if(StoX(mche) == StoX(yche) && StoY(mche) MY_SMALL StoY(yche)){
				Square psq;
				if(getBetweenSq(POSITION,mche,yche,psq)){
					if(PB90(psq) == my_pawn && StoY(psq) MY_SMALL MY_RANK5){

					}
				}
			}
		}
		// fen 3a1k3/4a4/4br3/9/2p3b2/3R5/9/4B3B/1pp1A4/3AK4 w - - 120 120
		if(mcan <= 2 && StoY(yche) == MY_RANK4){
			Bitboard b1 = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(count_1s(b1) == 2){
				Bitboard b2 = m_and(b1,RightBB[0x4]);
				if(count_1s(b2) == 2 && StoX(yche) == 0x5){
					RETRUN_MUL(2);
				}
				b2 = m_and(b1,LeftBB[0x4]);
				if(count_1s(b2) == 2 && StoX(yche) == 0x3){
					RETRUN_MUL(2);
				}
			}
		}

		// fen 3ak1b2/4a4/4b4/R8/P8/r1P3P2/9/4B4/4A4/3AK1B2 b - - 0 1
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(mcan <= 1){
				Bitboard bmp1 = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
				if(count_1s(bmp1) == 1){
					Square p1 = pop_1st_bit_sq(bmp1);
					if(StoX(mche) == StoX(p1) && abs(StoX(p1) - 0x4) >= 3 && bit_is_set(ei.attacked_by(your_che),p1)){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 2b1ka3/4aP3/4b4/4R4/4P3r/6P2/9/4B4/3KA4/5A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN <= 2){
			if(PB90(MY_SQ28) == my_pawn && PB90(MY_SQ1F) == my_che){
				if(StoY(yche) == MY_RANK4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3k5/6P2/3a1a2b/9/9/P1R3P2/r8/3A5/9/3AK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN <= 2){
			Bitboard bmp2 = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
			if(count_1s(bmp2) >= 2 && StoY(mche) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(6);
			}
		}
	}

    if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		// fen 3a1k3/4a4/4br3/9/2p3b2/3R5/9/4B3B/1pp1A4/3AK4 w - - 120 120
		if(mcan <= 2){
			//如果只有一个以下的兵过河,要减分
			if(My_pawn_already_over_river(POSITION) <= 1){
				MY_EV_SUB(96);
			}
			RETRUN_MUL(8);
		}
	} // if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
	// fen 3akab2/9/4b4/5R3/7PP/9/P3r4/9/9/3K5 w - - 0 1
	if(mcan >= 2){
		MY_EV_ADD(mcan * 64);
	}
}

