#ifndef END_my_m_MT_R_2ma2pawn_B_2pao
#define END_my_m_MT_R_2ma2pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2Âí2±ø¶Ô2ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2ma2pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pok = (int)count_1s(bmp);
	MY_EV_ADD(pok * ADD_2MaXPawn_2Pao_ByPawnShi[your_shi_num]);

	// fen 2b1kab2/4a4/9/2P4c1/4N3c/2P3B2/9/4B1N2/4A4/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			MY_EV_SUB(64);
		}
	}

	// fen 3a5/2P3P2/3k1a3/5cN2/2bNc4/9/9/8B/9/5K3 b - - 123 123
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(pok == 0){
			RETRUN_MUL(4);
		}
	}	
}
