#ifndef END_my_m_MT_R_2che1pao_B_2che1pawn
#define END_my_m_MT_R_2che1pao_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车1炮对2车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2che1pao_B_2che1pawn(typePOS &POSITION, EvalInfo &ei) {

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);

	if (my_shi_num == 2 && StoY(mk) == MY_RANK9) {
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK7) {
			EV_MY_SAFE = true;
		}
	}

	// fen 4kab2/4a4/4b4/9/2c1R4/2R6/P8/4B3r/3rA4/2B1KA3 w - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
			RETRUN_MUL(8);
		}
	}


}