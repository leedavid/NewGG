#ifndef END_my_m_MT_R_2ma3pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_2ma3pawn_B_1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马3兵对1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma3pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Pao1Ma1Pawn_ByPawn[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao1Ma1Pawn_2MaXPawn_ByPawn[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 2b1ka3/4a4/4b4/4nc3/P8/1NP1p4/8P/2N1B4/9/3AKA3 w - - 2 2
	//如果马方仕相不全,也要扣分

	MY_EV_SUB((4 - (my_shi_num + my_xiang_num)) * 32); 

	// fen 4k4/3P5/4N4/4n2n1/9/9/3p3p1/3A5/4A1p2/2BK1C3 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 16);

	if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		if(abs(StoX(ypawn) - StoX(mk)) >= 2){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
	// fen 5kb2/4a4/3ab4/3PP4/1c7/6P2/2n1N4/2N6/3K2p2/9 w - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if(have_bit(lp,MyLowBB[MY_RANK2])){
		MY_EV_ADD(16);
	}

}

//void m_MT_B_2ma3pawn_R_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao1Ma1Pawn_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_1Pao1Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 2b1ka3/4a4/4b4/4nc3/P8/1NP1p4/8P/2N1B4/9/3AKA3 w - - 2 2
//	//如果马方仕相不全,也要扣分
//	int nsx = board->B_shi + board->B_xiang; 
//	board->mulScore += (4 - nsx) * 32;
//
//	*/
//
//}
