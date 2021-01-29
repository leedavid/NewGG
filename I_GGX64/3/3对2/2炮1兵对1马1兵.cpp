#ifndef END_my_m_MT_R_2pao1pawn_B_1ma1pawn
#define END_my_m_MT_R_2pao1pawn_B_1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮1兵对1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 





void my_m_MT_R_2pao1pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
    Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Pao_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2PaoXPawn_2Pao_ByPawnShi[my_shi_num]);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 2bak4/4a1P2/4b4/9/5Cn2/4C4/5p3/3A4B/4A4/5K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(128);

		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			MY_EV_SUB(80);
		}

		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(80);
			if((StoX(mpawn) > 0x4 && StoX(ypawn) > 0x4) || (StoX(mpawn) < 0x4 && StoX(ypawn) < 0x4)){
				MY_EV_SUB(64);
				if(abs(StoX(mpawn) - 0x4) >= 2){
					MY_EV_SUB(64);
					RETRUN_MUL(6);
				}
				RETRUN_MUL(8);
			}
		}		
	}
}

//void m_MT_B_2pao1pawn_R_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += 96;
//		}
//
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= 96;
//		}
//
//	}
//
//	*/
//}