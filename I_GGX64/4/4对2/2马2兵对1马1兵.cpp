#ifndef END_my_m_MT_R_2ma2pawn_B_1ma1pawn
#define END_my_m_MT_R_2ma2pawn_B_1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马2兵对1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int  ADD_2MaXPawn_1Ma2Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1马2兵, 多兵的加分
//const int  ADD_1Ma2Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma2pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Ma2Pawn_2MaXPawn_ByPawn[my_shi_num]);

	Square mma1 = S90_from_piecelist(POSITION,my_ma,0);
	Square mma2 = S90_from_piecelist(POSITION,my_ma,1);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);

	// fen 5a3/3kaP3/9/7P1/2bN1Nb2/5n3/9/B3BA3/2p1A4/3K5 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num == 2){		
		Bitboard ymatt = POSITION.ma_to_king_attacks_bb(yma);
		if((isStringByChe(POSITION,yk,mma1,mk) && bit_is_set(ymatt,mma1))
	     || (isStringByChe(POSITION,yk,mma2,mk) && bit_is_set(ymatt,mma2))){
			 RETRUN_MUL(8);
		}
	}
}

