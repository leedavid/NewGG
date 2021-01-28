#ifndef END_my_m_MT_R_1ma3pawn_B_1ma2pawn
#define END_my_m_MT_R_1ma3pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1马3兵对1炮2兵 //ADD_1PaoXPawn_1MaXPawn_ByShi

void my_m_MT_R_1ma3pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1MaXPawn_1MaXPawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1MaXPawn_1MaXPawn_ByShi[my_shi_num]);

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	//一个和型

	//int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;


	// fen 3akab2/9/4b4/p8/8p/2B1n4/P7P/2N1BA3/4Ap3/3K5 w - - 0 0
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(mcan <= 1){
			EV_YOUR_SAFE = TRUE;
		}
	}

	if(my_shi_num == 2 && my_xiang_num >= 1){
		EV_MY_SAFE = TRUE;
	}



	// fen 3a1kb2/4a4/4b1n2/8p/4P1p2/2B5P/6P2/4B4/4AN3/3K1A3 w - - 9 
	// fen 3ak4/4a4/4b4/p8/8p/P5B2/4P1n1P/6N2/4A4/2BAK4 w - - 3 3
    //如果黑兵上面有二个红兵,红马给黑马压制住了,也是和棋
	if(mcan <= 1 && PB90(MY_SQ3A) == my_pawn){
		if(PB90(MY_SQ45) == my_ma && PB90(MY_SQ3C) == your_ma){
			if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2C) == your_pawn){
				RETRUN_MUL(2);
			}
		}
		if(PB90(MY_SQ41) == my_ma && PB90(MY_SQ38) == your_ma){
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ24) == your_pawn){
				RETRUN_MUL(2);
			}
		}
	}


	// fen 2b2k3/4a4/3a5/P7p/3npN3/2B5P/4P4/4BA3/5K3/5A3 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ28) == your_pawn){
			if(PB90(MY_SQ1B) == my_pawn && PB90(MY_SQ27) == your_ma 
				&& PB90(MY_SQ29) == my_ma){
					if(PB90(MY_SQ23) == your_pawn && PB90(MY_SQ35) == my_pawn){
						RETRUN_MUL(4);
					}
			}
			if(PB90(MY_SQ23) == my_pawn && PB90(MY_SQ29) == your_ma
				&& PB90(MY_SQ27) == my_ma){
					if(PB90(MY_SQ1B) == your_pawn && PB90(MY_SQ2D) == my_pawn){
						RETRUN_MUL(4);
					}
			}
		}
	}

	// fen 4ka3/4a4/9/p3Nn2p/9/9/P3P3P/4B4/4A4/2BA1K3 w - - 0 1
	if (EV_MY_SAFE){
		if (EV_MY_CAN <= 1 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (count_1s(bb_my_pawn, MyLowBB[MY_RANK4]) >= 3){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 2b1ka3/4a4/9/P8/3np3p/9/4P3P/B3B4/5N3/3AKA3 w - - 0 1
	if (EV_MY_SAFE){
		if (EV_MY_CAN <= 1 && your_shi_num == 2 
			&& StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (StoY(mma) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(6);
			}
		}
	}

	

	// fen 2b1k4/4aP3/9/6N2/p1b5p/6B2/P6nP/4BA3/4A4/3K5 w - - 120
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			Bitboard b1 = m_and(bb_your_pawn,RankBB_A[MY_RANK4]);
			if(count_1s(b1) == 2){
				Bitboard b2 = m_and(bb_my_pawn,RankBB_A[MY_RANK6]);
				if(count_1s(b2) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}
		
	
	// fen 4kab2/9/4ba3/p3n3p/9/2B1P4/P7P/6N2/4A4/3K1AB2 w - - 0 0
    //多兵方只能过一个兵,也可能是和棋艺
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 3P5/3P1k3/4Pa2b/5Nn2/6b2/6B2/9/4BK3/2p1A1p2/3A5 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num == 2 
		&& abs(StoY(yma) - MY_RANK3) <= 1){
			if(have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){
				if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
					Bitboard p2 = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
					if(count_1s(p2) >= 2){
						if(StoX(yk) > 0x4 && !have_bit(bb_my_pawn,m_and(RightBB[0x4],MyLowBB[MY_RANK0]))){
							RETRUN_MUL(8);
						}
						if(StoX(yk) < 0x4 && !have_bit(bb_my_pawn,m_and(LeftBB[0x4],MyLowBB[MY_RANK0]))){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}

}

