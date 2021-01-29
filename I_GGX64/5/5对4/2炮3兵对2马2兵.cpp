#ifndef END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮3兵对2马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void  my_m_MT_R_2pao3pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);
	
	// fen 2ba4C/4ak3/4b4/p8/3n5/2P2p3/P3P3n/4B4/4A1C2/2BAK4 b - - 0 1
	if(EV_MY_CAN == 0){
		MY_EV_SUB(EV_YOUR_CAN * 32);
	}

	// fen 5ab2/4aPP2/3k3Cb/9/9/P8/3p2pn1/2n5C/4A4/4KA3 w - - 0 1
	if(your_shi_num == 2){
		if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) >= 2){
			MY_EV_SUB(EV_YOUR_CAN * 32);
		}
	}
}