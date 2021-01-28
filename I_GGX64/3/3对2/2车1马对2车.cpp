#ifndef END_my_m_MT_R_2che1ma_B_2che
#define END_my_m_MT_R_2che1ma_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "2车1马对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int const_Shi_add[3] = {128,48,0};
//const int const_Pawn_add   =  48;

//2车1兵对2车
void my_m_MT_R_2che1ma_B_2che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	//fen 2rk1ab2/4a1N2/4b4/7R1/9/9/1R7/B3B1p2/3rA4/4KA3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(64);
		if (have_bit(bb_your_che, FileBB_A[StoX(yk)])){
			MY_EV_SUB(64);
		}
	}

}