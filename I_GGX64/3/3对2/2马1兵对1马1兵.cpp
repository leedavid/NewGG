#ifndef END_my_m_MT_R_2ma1pawn_B_1ma1pawn
#define END_my_m_MT_R_2ma1pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




//const int  ADD_2MaXPawn_1Ma1Pawn_ByPawn[3]         = {96, 80, 64};            //2马x兵对1马2兵, 多兵的加分
//const int  ADD_1Ma1Pawn_2MaXPawn_ByPawn[3]         = {96, 32, 16};            //2马x兵对1马2兵, 多兵的加分

void my_m_MT_R_2ma1pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_1Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Ma1Pawn_2MaXPawn_ByPawn[my_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 1P3k3/4aN3/3a2n2/6N2/6b2/6B2/9/3A5/3p1K3/2BA5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(mpawn) == MY_RANK0){
		if(!IsOnSameSide(mpawn,yk)){
			Square ykl = yk MY_ADD 0x9;
			if(PB90(ykl) == my_ma && StoY(ykl) MY_SMALL_EQL MY_RANK2){
				if(StoY(yma) MY_SMALL_EQL MY_RANK4){
				  RETRUN_MUL(4);
				}
				RETRUN_MUL(8);
			}
		}
	}


	// fen 2b2k3/2N1a1P2/2Nnba3/9/9/9/5p3/4B4/4A4/4KAB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
			if(StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,FileBB_A[0x3])){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) < 0x4 && !have_bit(bb_your_shi,FileBB_A[0x5])){
				RETRUN_MUL(8);
			}
		}
	}

}

