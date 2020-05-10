#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1³µ1ÅÚ3±ø¶Ô1³µ1ÅÚ2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	
	Square mk = my_king_pos;
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 3a1kb2/4a4/b3c4/2r5p/p5P2/3R4P/P8/4B4/4A4/3CKAB2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		EV_MY_SAFE = true;
	}

	// fen 2r1k1b2/4a4/3a5/6P2/C3PP3/pp7/9/9/3RA4/1c3K3 w - - 0 1
	if(!have_bit(bb_your_pawn,
		m_and(MyLowBB[MY_RANK6],m_and(LeftBB[0x7],RightBB[0x1])))){
			MY_EV_ADD(EV_MY_CAN * 16);
	}
	// fen 3P5/5c1C1/3k1a3/4R4/9/P2p1p3/8P/6r2/4AK3/3A5 w - - 0 1
	if (have_bit(bb_my_pawn, RankBB_A[MY_RANK0])){
		Bitboard mbp = m_and(bb_my_pawn, m_or(LeftBB[0x1],RightBB[0x7]));
		MY_EV_SUB(count_1s(mbp) * 32);
	}

	// fen 3a1kb2/4a4/b3c4/2r5p/p5P2/3R4P/P8/4B4/4A4/3CKAB2 b - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
			if (EV_MY_CAN <= 1) {
				MY_EV_SUB(32);
				if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK2])) {
					RETRUN_MUL(12);
				}
			}
		}
	}

}


//void m_MT_B_1che1pao3pawn_R_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){
//	//return 16;
//}
//

