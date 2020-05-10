#ifndef END_my_m_MT_R_2pao1ma1pawn_B_1che1ma
#define END_my_m_MT_R_2pao1ma1pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao1ma1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2Pao1MaXPawn_1Che1Ma_To_ByPawn[your_shi_num]);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 4k4/C3aP3/3ab4/9/2b1Nr3/9/7n1/4BA3/4A4/3CK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
		
	// fen 4k4/4a4/3a5/9/2b6/1C4P2/1r5n1/N3BA3/4AC3/2B1K4 r

	// fen 4k4/4a4/3a5/9/2b6/1C4P2/1r5n1/N3BA3/4AC3/2B1K4 r
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
				RETRUN_MUL(12);
			}
		}
	}
}
