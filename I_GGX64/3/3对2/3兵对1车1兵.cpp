#ifndef END_my_m_MT_R_3pawn_B_1che1pawn
#define END_my_m_MT_R_3pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "3兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_3pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheXPawn_To_PawnByShi[my_shi_num]);

	MY_EV_SUB(ADD_CheXPawn_To_3Pawn);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	//Square yche  = S90_from_piecelist(POSITION,your_che,0);

	Square mk = my_king_pos;

	// fen 2baka3/9/4b4/2PP5/3P5/9/6r2/3AB4/8p/2B1KA3 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(have_bit(lp,RankBB_A[MY_RANK3]) || have_bit(lp,RankBB_A[MY_RANK4])){
			//如果是连相，就是和棋
			if(StoX(ypawn) <= 0x4 && PB90(MY_SQ54) == my_shi){
				RETRUN_MUL(2);
			}
			if(StoX(ypawn) >= 0x4 && PB90(MY_SQ56) == my_shi){
				RETRUN_MUL(2);
			}
		} 
	}

	//if(StoY(ypawn) MY_SMALL_EQL MY_RANK8)

	// fen 3akab2/1r7/4b4/4PPP2/9/9/9/5A3/3pAK3/9 w - - 0 1
	if(my_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK8){

		Bitboard lp = My_get_connect_Pawn(POSITION);
		bool isok = false;
		if(!IsOnSameSide(ypawn,mk) && !have_bit(bb_my_shi,MyLowBB[MY_RANK8])){
			if(StoX(ypawn) < 0x4 && PB90(MY_SQ44) == my_shi){
				isok = true;
			}
			if(StoX(ypawn) > 0x4 && PB90(MY_SQ42) == my_shi){
				isok = true;
			}
		}
		if(isok){
			if(bit_is_set(lp,Square(MY_SQ1F)) || bit_is_set(lp,Square(MY_SQ20)) || bit_is_set(lp,Square(MY_SQ1E))){
				if(count_1s(lp) == 3){
					RETRUN_MUL(2);
				}				
				if(count_1s(lp) >= 2 && count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 3){
					RETRUN_MUL(2);
				}				
			}
		}
	}

}
