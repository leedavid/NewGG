#ifndef END_my_m_MT_R_2pao2ma2pawn_B_1che2pao1pawn
#define END_my_m_MT_R_2pao2ma2pawn_B_1che2pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马2兵对1车2炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_2pao2ma2pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// fen 4kab2/4a4/6rc1/4p4/PNb6/6C1P/4P1c2/4B1N2/4A4/2BAKC3 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
		Bitboard mp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(mp) >= 2){ // 有二个以上的兵没有过河
			MY_EV_SUB(16);
			if(have_bit(mp,LeftBB[0x1])){
				MY_EV_SUB(16);
			}
			if(have_bit(mp,RightBB[0x7])){
				MY_EV_SUB(16);
			}
		}
	}
}