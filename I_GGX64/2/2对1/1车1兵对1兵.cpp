#ifndef END_my_m_MT_R_1che1pawn_B_1pawn
#define END_my_m_MT_R_1che1pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//车2兵对1兵
void my_m_MT_R_1che1pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(StoY(mpawn) MY_LARGE_EQL StoY(yk)){
		MY_EV_ADD(ADD_CheXPawn_To1Pawn_ByPawnShi[your_shi_num]);
	}

	MY_EV_ADD(ADD_CheXPawn_To1Pawn);

	// fen 3a1kb2/4a4/4b4/9/5Rp2/2B6/6P2/5A2B/4K4/3A5 b - - 18 18
	//如果兵不能过河，也可能是和棋'
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == your_xiang){
			if(PB90(MY_SQ2A) == your_pawn && PB90(MY_SQ3C) == my_pawn){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ26) == your_pawn && PB90(MY_SQ38) == my_pawn){
				RETRUN_MUL(2);
			}
		}
	}
}

