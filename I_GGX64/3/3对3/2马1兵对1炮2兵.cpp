#ifndef END_my_m_MT_R_2ma1pawn_B_1pao2pawn
#define END_my_m_MT_R_2ma1pawn_B_1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2马1兵对1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_2ma1pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yk    = your_king_pos;

	// fen 3k5/4aP3/5a2b/3N1N3/4c1b2/6B2/4pp3/9/9/3A1KB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(yk,mpawn) && PB90(yk MY_ADD 18) != your_shi){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if(have_bit(lp,RankBB_A[MY_RANK6])){
				RETRUN_MUL(6);
			}
		}
	}
	
}