#ifndef END_my_m_MT_R_1che1pawn_B_2pawn
#define END_my_m_MT_R_1che1pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square ypawn1 = S90_from_piecelist(POSITION,your_pawn,0);
	Square ypawn2 = S90_from_piecelist(POSITION,your_pawn,1);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	//RETRUN_MUL(2); // fen 3a5/4k4/3ab4/3PP4/9/5r3/9/4B4/3pA4/3AK1B2 b - - 0 0</
	//兵方要仕相全, 且兵连成线了 
	// fen 3ak4/3Pa4/4b3b/9/9/3pp4/7R1/4B4/4A4/3A1K3 b - - 121 121
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0) {

		Bitboard ypp = m_and(bb_your_pawn,RankBB_A[MY_RANK6]);
		if(count_1s(ypp) == 2){
			if(!have_bit(ypp,LeftBB[0x3]) && !have_bit(ypp,RightBB[0x5])){
				// fen 2b1ka3/4a2P1/b8/3R5/9/9/4pp3/9/3KA4/5A3 w - - 0 1
				if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
					if(StoX(mpawn) > 0x4 && !have_bit(bb_your_xiang,RightBB[0x4])){
						RETRUN_MUL(2);
					}
					if(StoX(mpawn) < 0x4 && !have_bit(bb_your_xiang,LeftBB[0x4])){
						RETRUN_MUL(2);
					}
				}
			}
		}

		if(StoY(mpawn) == MY_RANK0 && abs(StoX(mpawn) - 0x4) >= 2){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if(bit_is_set(lp,MY_SQ31) || bit_is_set(lp,MY_SQ3A)){
				RETRUN_MUL(2);
			}
		}

		if(PB90(MY_SQ16) == your_xiang ){
			if((StoX(mpawn) <= 0x4 && PB90(MY_SQ03) == your_shi) ||
				(StoX(mpawn) >= 0x4 && PB90(MY_SQ05) == your_shi)){
					//再看一下 黑方有没有连兵 在5线 
					if(StoY(ypawn1) == StoY(ypawn2) && StoY(ypawn1) MY_SMALL MY_RANK7){
						if(abs(StoX(ypawn1) - StoX(ypawn2)) == 1){
							// fen 3ak1b2/P8/4ba3/9/9/7R1/5pp2/4B4/9/3AKAB2 b - - 0 1
							if(abs(StoX(ypawn1) - 0x4) <= 1 || abs(StoX(ypawn2) - 0x4) <= 1){
								RETRUN_MUL(2);
							}
							RETRUN_MUL(4);
						}
					} 
			}
		}


	} // 吃,然后被吃?

	// fen 3ak4/2P1a4/8b/9/6b1R/3p1p3/9/3A5/9/3K1A3 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk) {
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK1){
			if(!have_bit(LeftBB[0x3],bb_your_pawn) && !have_bit(RightBB[0x5],bb_your_pawn)){
				if((count_1s(bb_your_pawn,RankBB_A[MY_RANK5]) == 2)
					|| (count_1s(bb_your_pawn,RankBB_A[MY_RANK6]) == 2)){
                   if(StoX(mpawn) <= 0x3 && PB90(MY_SQ03) == your_shi){
					   if(PB90(MY_SQ02) != your_xiang){
						   RETRUN_MUL(4);
					   }
				   }
				   if(StoX(mpawn) >= 0x5 && PB90(MY_SQ05) == your_shi){
					   if(PB90(MY_SQ06) != your_xiang){
						   RETRUN_MUL(4);
					   }
				   }
				}
			}
		}
	}

	MY_EV_ADD(ADD_CheXPawn_To_2Pawn);

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_CheXPawn_To_2PawnByShi[your_shi_num]);
	}

	// fen 2b1k4/4aR3/3ab4/3P5/9/9/3pp4/4B4/4A4/2BAK4 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk) {
		Bitboard lp = Your_get_connect_Pawn(POSITION);
		if(bit_is_set(lp,Square(MY_SQ31)) || bit_is_set(lp,Square(MY_SQ3A))){
			RETRUN_MUL(8);
		}
	}
}
