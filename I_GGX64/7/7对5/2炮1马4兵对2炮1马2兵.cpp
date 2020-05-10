#ifndef END_my_m_MT_R_2pao1ma4pawn_B_2pao1ma2pawn 
#define END_my_m_MT_R_2pao1ma4pawn_B_2pao1ma2pawn 
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí4±ø¶Ô2ÅÚ1Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

#pragma warning(disable : 4100) 

void my_m_MT_R_2pao1ma4pawn_B_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2bk1ab2/4a4/9/9/2p3P1p/C4N3/P1P1n3P/N3Bc3/1n2K4/2BA5 b - - 0 1	
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

}