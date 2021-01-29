#ifndef END_my_m_MT_R_1che1ma2pawn_B_1che2pawn
#define END_my_m_MT_R_1che1ma2pawn_B_1che2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马2兵对1车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1ma2pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[my_shi_num]); 

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	int mcan = EV_MY_CAN;

	// fen 4ka3/4aP3/6r2/1PN1p4/9/9/9/9/4Ap3/4K2R1 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(my_xiang_num == 0 && my_shi_num <= 1){
			if(StoY(mk) == MY_RANK9){
				//if(have_bit(bb_your_pawn,))
				Bitboard yb = m_and(bb_your_pawn,RankBB_A[MY_RANK8]);
				if(have_bit(LeftBB[0x6],yb) && have_bit(RightBB[0x2],yb)){
					MY_EV_SUB(64);
					if(StoY(mma) MY_SMALL_EQL MY_RANK5){
						MY_EV_SUB(64);
					}
					if(StoY(mche) == MY_RANK9){
						MY_EV_SUB(64);
					}
				}
			}
		}
	}

	// fen 3ak4/4a4/4b4/6p2/p8/6P2/P5R2/B4AN2/4K4/3A2r2 b - - 6 6
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(mcan == 0 && isStringByChe(POSITION,mche,mma,yche)){
			RETRUN_MUL(4);
		}
	}

	// fen 4ka3/4a4/9/p7p/4r1n2/P5R1P/9/3AB4/4A4/4K1B2 b - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mma) MY_LARGE_EQL MY_RANK5 && my_xiang_num == 0){
			if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ2C) == your_pawn){
				if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ3E) == my_pawn){
					if(StoY(yche) == MY_RANK4){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
	// fen 3ak4/9/4b4/4r4/P3p4/2P2n3/5R3/4B1p2/4A4/2B1KA3 b - - 0 63
	MY_EV_ADD(EV_MY_CAN * 32);

	// fen 9/9/4k4/p1r1p4/9/8R/Pn6P/4B4/4A4/3AK1B2 w - - 0 1
	// 黑方二个兵都在家里,要扣分
	ymp = m_and(bb_your_pawn, MyUpBB[MY_RANK4]);
	MY_EV_ADD(64 * count_1s(ymp));
}

