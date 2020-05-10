#ifndef END_my_m_MT_R_2che1pao2pawn_B_2che1pao1pawn
#define END_my_m_MT_R_2che1pao2pawn_B_2che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车1炮2兵对2车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//const int ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[3]    = {96, 64, 32};            //2车x兵对1车1炮1马1兵, 兵方的加分
//const int ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[3]    = {96, 64, 32};            //1车1炮1马1兵对2车x兵, 兵方的加分

void my_m_MT_R_2che1pao2pawn_B_2che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 4kab2/4a4/4b4/1r1C5/7r1/4P1P2/1p1R5/2R6/4A4/1cBAK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if(have_bit(MyUpBB[MY_RANK5],bb_your_che)){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

}
