#ifndef END_my_m_MT_R_2pao2pawn_B_1ma2pawn
#define END_my_m_MT_R_2pao2pawn_B_1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮2兵对1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int _OnlyOnePawnCanOverRiver = 96; 
//const int  ADD_2PaoXPawn_1Ma2Pawn_ByPawn[3]         = {96, 64, 32};            //2炮兵对1马2兵, 多兵的加分
//const int  ADD_1Ma2Pawn_2PaoXPawn_ByPawn[3]         = {96, 64, 32};            //1马2兵对2炮兵, 多兵的加分

 void my_m_MT_R_2pao2pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
	
	 // ADD_MY
	 Square yk = your_king_pos;
	 Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	 int pmok = (int)count_1s(bmp);
	 MY_EV_ADD(pmok * ADD_2PaoXPawn_1Ma2Pawn_ByPawn[your_shi_num]);
	 // SUB
	 Square mk = my_king_pos;
	 Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	 int pyok = (int)count_1s(ymp);
	 MY_EV_SUB(pyok * ADD_1Ma2Pawn_2PaoXPawn_ByPawn[my_shi_num]);
	
 }
// void m_MT_B_2pao2pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Ma2Pawn_2PaoXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Ma2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	 */
// }