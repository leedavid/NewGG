#ifndef END_m_MT_R_1che2pao2pawn_B_1che1pao1ma1pawn
#define END_m_MT_R_1che2pao2pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车2炮2兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che2pao2pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei) {

	Square yk = your_king_pos;

	//  fen 2bak4/4a4/4b4/4R4/1n4p2/1CP6/Pc7/4B4/2r1A4/1C2KAB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
		if (EV_MY_CAN <= 1) {
			MY_EV_SUB(32);
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])) {
				MY_EV_SUB(32);
				if (have_bit(bb_my_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8]))) {
					MY_EV_SUB(32);
				}
			}
		}
	}
}