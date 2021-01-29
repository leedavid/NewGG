#ifndef END_my_m_MT_R_2ma1pawn_B_1che1ma
#define END_my_m_MT_R_2ma1pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2马1兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车马
void my_m_MT_R_2ma1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei) {

	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mk = my_king_pos;

	//  fen 3k5/4a4/5a2b/5P3/9/5N3/5r1N1/5A3/2n1A4/2B2KB2 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		MY_EV_ADD(32);
		if (StoY(mpawn) == MY_RANK3) {
			MY_EV_ADD(32);
			if (count_1s(bb_my_ma, ei.attacked_by(my_ma)) == 2) {
				if (count_1s(bb_my_ma, MyLowBB[MY_RANK4]) == 2) {
					RETRUN_MUL(4);
				}				
			}
			RETRUN_MUL(8);
		}
	}
}