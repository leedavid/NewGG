#ifndef END_my_m_MT_R_1PAO1PAWN_B_1CHE
#define END_my_m_MT_R_1PAO1PAWN_B_1CHE
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// void m_MT_B_1CHE_R_1PAO(board_t *board);
// void my_m_MT_R_1CHE_B_1PAO(board_t *board);

//炮兵对车
void my_m_MT_R_1PAO1PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){
	// fen 4ka3/4a4/b2c5/4p4/9/2B3B2/7R1/3A1A3/4K4/9 w
	if(PB90(MY_SQ0D) != my_pawn){
		your_m_MT_R_1CHE_B_1PAO(POSITION,ei);
	}
}

