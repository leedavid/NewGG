#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);

	// fen 2b1ka3/4a4/4b4/8C/5P1P1/1p7/2Pn4r/3R5/4A4/3AK4 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(16);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoY(yma) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2bak4/4a4/4b4/4PP3/PC4r2/7p1/7n1/7R1/9/4KA3 b - - 0 1
	if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && StoY(yma) MY_SMALL_EQL MY_RANK6){
			if(StoY(mche) MY_LARGE_EQL StoY(yma)){
				MY_EV_ADD(EV_MY_CAN * 16);
				if(count_1s(MyUpBB[MY_RANK5],bb_my_pawn) >= 3){
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
	}

	// fen 2bak4/4a1P2/4b4/3C5/4PP3/9/2pn5/3R4B/3KA4/7r1 b - - 0 1
	//if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	//	if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && StoY(yma) MY_SMALL_EQL MY_RANK6){
	//		MY_EV_ADD(EV_MY_CAN * 16);
	//	}
	//}
}
//
//void m_MT_B_1che1pao3pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}