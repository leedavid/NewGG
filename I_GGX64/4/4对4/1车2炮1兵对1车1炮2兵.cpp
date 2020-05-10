#ifndef END_m_MT_R_1che2pao1pawn_B_1che1pao2pawn
#define END_m_MT_R_1che2pao1pawn_B_1che1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车2炮1兵对1车1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che2pao1pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_ChePaoXPawn_ChePao1Pawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_ChePaoXPawn_ChePao1Pawn[RShi_num()]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 2b1k4/4a4/4b4/3PP4/p4c3/6B1C/6R2/3A5/3K2c2/4r4 b - - 0 1
	//如果对方有二个兵，是连兵，而我方的兵不能过河，要减分
	Bitboard ylp = Your_get_connect_Pawn(POSITION);

	if(bit_is_set(ylp,MY_SQ3A) || bit_is_set(ylp,MY_SQ31)){
		if(your_shi_num >= 1 && your_xiang_num >= 1){
			// 如果我方的兵不能过兵
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
				if(bit_is_set(YOUR_ATTACK,XYtoS(StoX(mpawn),MY_RANK4))){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 4k4/2Rca4/4ba3/p8/4r3p/P8/9/1C7/3K2C2/3A1A3 b - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK6])){
		MY_EV_ADD(32);
		if(have_bit(LeftBB[0x1],bb_your_pawn)){
			MY_EV_ADD(32);
		}
		if(have_bit(RightBB[0x7],bb_your_pawn)){
			MY_EV_ADD(32);
		}
	}



}