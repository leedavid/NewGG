#ifndef END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮3兵对1炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void  my_m_MT_R_2pao3pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	MY_EV_SUB(EV_YOUR_CAN * 16);

	Square yma = S90_from_piecelist(POSITION, your_ma, 0);

	// fen 3kc4/4a4/5a2b/4P1PCp/2b6/2N6/1pp5c/8B/9/2BAKA3 b - - 0 1
	if(EV_YOUR_CAN >= 2 && (your_shi_num + your_xiang_num) == 4){
		// 我方还有兵没有过河
		Bitboard b = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(b) * 48);
	}

	// fen 3k5/6C2/5a3/4p3C/6p2/2Bn5/c3P1P1P/9/4A4/4KAB2 w - - 0 1
	if (EV_MY_CAN <= 1){
		MY_EV_SUB(32);
		if (your_shi_num >= 1){
			MY_EV_SUB(32);
		}
	}
	if (count_1s(bb_my_pawn, MyLowBB[MY_RANK4]) >= 3){
		MY_EV_SUB(64);
		if (StoY(yma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(32);
		}
	}	

	// fen 2bak4/4a4/4b4/4p4/1C7/C1P1P3P/1c5p1/B1n6/4A4/2BAK4 w - - 0 1
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN <= 1){
			MY_EV_ADD(EV_MY_CAN * 16);
			// 对方的后没有到位
			//Bitboard yp = m_and(MyLowBB[MY_RANK4],m_and(bb_your_pawn
			//	,m_and(LeftBB[0x]);
			}
	}

	// fen 4ka3/4a4/b3b4/2p1c4/4p1p2/2P6/4P4/3AB1cN1/4C4/2BAK4 w - - 0 1
	if(EV_MY_CAN == 0 && your_shi_num == 2 && your_xiang_num == 2){
		MY_EV_SUB(64);
		if(EV_YOUR_CAN == 0 && my_shi_num == 2 && my_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}

}