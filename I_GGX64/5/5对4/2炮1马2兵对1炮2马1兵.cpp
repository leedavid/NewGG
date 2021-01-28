#ifndef END_my_m_MT_R_2pao1ma2pawn_B_1pao2ma1pawn
#define END_my_m_MT_R_2pao1ma2pawn_B_1pao2ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮1马2兵对1炮2马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_2pao1ma2pawn_B_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[my_shi_num]);

	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
	int malr = My_pawn_already_over_river(POSITION);
	int yalr = Your_pawn_already_over_river(POSITION);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 2bak4/4a2c1/1Cn1b4/3N5/1P2P3n/5C3/9/8p/4A4/3AK4 w - - 0 1
	if(abs(StoX(ypawn) - 0x4) >= 3){
		if(my_shi_num == 2 || my_xiang_num == 2){
			MY_EV_ADD(EV_MY_CAN * 8);
		}
		if(have_bit(bb_your_ma,MyUpBB[MY_RANK4])){
			MY_EV_ADD(EV_MY_CAN * 8);
		}
	}

	MY_EV_ADD((malr - yalr) * 16);

	// fen 4k4/4n1C2/3a1a3/9/1Nb3n2/1C4B2/P3P2c1/9/4Ap3/4KAB2 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(count_1s(bb_your_ma,MyUpBB[MY_RANK5]) == 2){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(StoX(ypawn) > 0x4 && !have_bit(bb_my_shi,LeftBB[0x4])){
				MY_EV_ADD(16);
			}
			if(StoX(ypawn) < 0x4 && !have_bit(bb_my_shi,RightBB[0x4])){
				MY_EV_ADD(16);
			}
		}
	}

}
//
//void m_MT_B_2pao1ma2pawn_R_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
//
//	/*Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square rpawn = PieceListStart(board,RPAWN);
//	int bcan = BpawnCanOverLiver(board);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
//	if(StoY(rpawn) >= 0x8 && bcan >= 0 && BpawnAlreadyRiver(board) >= 1){
//		board->mulScore -= bcan * 16;
//	}
//
//
//	*/
//}