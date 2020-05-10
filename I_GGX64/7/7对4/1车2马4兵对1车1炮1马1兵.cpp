#ifndef END_my_m_MT_R_1che2ma4pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_1che2ma4pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马4兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2ma4pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk  = my_king_pos;
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 2b1ka3/2n2r3/3ab4/2R4N1/P7p/2P6/2N1P3P/4B4/3K2c2/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(yma) MY_SMALL_EQL MY_RANK2){
				MY_EV_ADD(32);
				if(StoY(ypao) MY_LARGE_EQL MY_RANK7){
					MY_EV_ADD(32);					
				}
				MY_EV_ADD(EV_MY_CAN * 16);
			}			
		}
	}

}