#ifndef END_my_m_MT_R_1che1pao5pawn_B_2pao2ma2pawn
#define END_my_m_MT_R_1che1pao5pawn_B_2pao2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1³µ1ÅÚ5±ø¶Ô2ÅÚ2Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao5pawn_B_2pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	// fen 4kab2/3na2R1/6c1b/N1p5p/P2P5/2P6/6n1P/4B4/4A4/2BA1K2c w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 8);
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}
