#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che2pao1pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1³µ1ÅÚ3±ø¶Ô1³µ2ÅÚ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	if((your_shi_num + your_xiang_num) <= 1 && EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 4k1b2/4a4/4b2r1/4C2c1/9/P3P2R1/6P2/3AB3p/8c/3AK4 w - - 0 1
	if((my_xiang_num + my_shi_num) >= 3 && StoY(mk) == MY_RANK9){
		if(StoY(yche) MY_SMALL_EQL MY_RANK3){
			if(abs(StoX(ypawn) - 0x4) == 4){
				Bitboard x = m_and(ei.attacked_by(my_che),ei.attacked_by(your_che));
				if(have_bit(m_and(MyUpBB[MY_RANK5],bb_your_pao),x)){
					MY_EV_ADD(32);
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
	}
}

//void m_MT_B_1che1pao3pawn_R_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){
//	//return 16;
//}
//

