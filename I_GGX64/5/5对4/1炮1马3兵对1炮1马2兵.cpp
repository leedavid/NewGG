#ifndef END_my_m_MT_B_1pao1ma3pawn_R_1pao1ma2pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí3±ø¶Ô1ÅÚ1Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma3pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);
	// fen 2bk1C3/9/5P3/7N1/1c6p/4n4/2p5P/4BA3/3p5/4K1B2 w - - 0 71
	if(EV_YOUR_CAN <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2bak4/4a4/4bc3/p2Np4/9/2P3n2/P7P/7C1/4A4/2B1KAB2 w - - 0 1
	if ((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		Bitboard mp = m_and(bb_my_pawn, MyLowBB[MY_RANK4]);
		if (count_1s(mp) == 3){
			MY_EV_SUB(32);
			if (EV_YOUR_CAN){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 4kab2/4a4/4b4/C7p/4p4/P1n6/4P3P/6N2/4A4/2c2K3 b - - 0 1
	if(EV_YOUR_CAN == 0 && my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2bk1ab2/4aP3/9/p3C4/3P4p/P8/9/B2A1nc2/4KN3/9 w - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK7){
			if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
			if(!have_bit(bb_your_pawn,m_and(LeftBB[0x6],RightBB[0x2]))){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
		}
	}

	// fen 2C2a3/4a4/5k3/N3P3p/9/2P6/4c3P/4p4/n2K5/5A3 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if((my_shi_num ) >= 1){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2b2ab2/3ka4/4c4/p8/3P3P1/9/P3Cn1N1/8B/2p1A4/4KA3 w - - 0 1
	if(EV_YOUR_CAN <= 1){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(EV_MY_CAN >= 2){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 3k1ab2/4a4/4b4/p6N1/8p/2P3Bn1/P6CP/3A5/9/3AK2c1 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN == 0){
		if(EV_YOUR_CAN == 0){
			if((my_shi_num + my_xiang_num) >= 3){
				RETRUN_MUL(8);
			}
		}
	}
}

//void my_m_MT_R_1pao1ma3pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){
//
//	//
//	//Square rk = PieceListStart(board,RKING);
//	//Square bk = PieceListStart(board,BKING);
//
//	//return 16;
//}