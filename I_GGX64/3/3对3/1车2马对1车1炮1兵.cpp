#ifndef END_my_m_MT_R_1che2ma_B_1che1pao1pawn
#define END_my_m_MT_R_1che2ma_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int  AD_Che_CanNotMove = 256;

void my_m_MT_R_1che2ma_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 3k1a3/4a4/7c1/9/9/4p4/7r1/R6N1/4AN3/5K3 b - - 0 1
	if((your_shi_num == 2 || your_xiang_num == 2) && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if((my_shi_num + my_xiang_num) <= 1){
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK6])){
				MY_EV_SUB(64);
				if(StoY(ypawn) MY_LARGE_EQL MY_RANK5 && StoY(ypawn) MY_SMALL_EQL StoY(mk)){
					MY_EV_SUB(32);
				}
			}
		}
	}

	// fen 4k1b2/4a4/3ab4/9/9/6B2/3r4p/3N2R2/4A4/2B1KAN1c b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK6])){
				if(StoY(ypawn) MY_LARGE_EQL MY_RANK6 && !IsOnSameSide(ypawn,mk) 
					&& have_bit(bb_my_ma,EV_YOUR_XBIT)){
					MY_EV_SUB(64);
					RETRUN_MUL(8);
				}
			}
		}
	}
}