#ifndef END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮3兵对2炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void  my_m_MT_R_2pao3pawn_B_2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	// fen 2baka3/9/1c2b4/1c1C4p/4p4/P8/3CP3P/3KB4/4A4/5AB2 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if(EV_MY_CAN <= 1){
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
					RETRUN_MUL(10);
				}
			}
		}
	}
}