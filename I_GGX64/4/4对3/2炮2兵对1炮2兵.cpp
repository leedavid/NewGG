#ifndef END_my_m_MT_R_2pao2pawn_B_1pao2pawn
#define END_my_m_MT_R_2pao2pawn_B_1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮2兵对1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


 void my_m_MT_R_2pao2pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
	 // ADD_MY
	 Square yk = your_king_pos;
	 Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	 int pmok = (int)count_1s(bmp);
	 MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao2Pawn_ByPawn[your_shi_num]);
	 // SUB
	 Square mk = my_king_pos;
	 Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	 int pyok = (int)count_1s(ymp);
	 MY_EV_SUB(pyok * ADD_1Pao2Pawn_2PaoXPawn_ByPawn[my_shi_num]);
	
 }

//  void m_MT_B_2pao2pawn_R_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao2Pawn_2PaoXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Pao2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	 */
// }