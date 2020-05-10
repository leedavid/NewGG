#ifndef END_my_m_MT_R_1che2pao1ma3pawn_B_2che1ma2pawns
#define END_my_m_MT_R_1che2pao1ma3pawn_B_2che1ma2pawns
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮1马3兵对2车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao1ma3pawn_B_2che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 2r1kab2/4a4/4b4/7R1/3P2n1P/2P6/p3rp3/3CB3N/4A4/2BCKA3 b - - 0 1
	if(MY_SQ04 == yk && your_xiang_num == 2 && your_shi_num == 2){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
			if(!have_bit(MyUpBB[MY_RANK5],m_or(bb_my_pao,bb_my_ma))){
				MY_EV_SUB(16);
				if(count_1s(bb_your_pawn,MyLowBB[MY_RANK5]) >= 2){
					MY_EV_SUB(32);
				}
			}
		}
	}
}