#ifndef END_my_m_MT_R_2pao3pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_2pao3pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮3兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao3pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_1Pao1Ma_ByPawn[your_shi_num]);

	Square mk = my_king_pos;
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2PaoXPawn_1Pao1Ma_ByPawn[my_shi_num]);

	// 
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0); 

	// fen 9/4k4/b2C1N3/9/2p5p/4P4/9/4Bc2B/4K4/cp3A3 b - - 1 1
    //如果炮方没有仕了, 有红方的兵可过河,要加分
	int ycan = EV_YOUR_CAN;
	if(my_shi_num == 0 && StoY(ypawn) MY_SMALL_EQL StoY(mk)){
		MY_EV_SUB(ycan * 64);
	}


	// fen 2bak3C/2n1a4/9/2P6/6b2/2p6/P7P/4K3C/9/c2A1A3 w - - 0 0
	if(ycan >= 1 && (my_shi_num + my_xiang_num) <= 2 && StoY(ypawn) MY_SMALL_EQL StoY(mk)){
		if((your_xiang_num + your_shi_num) == 4){
			MY_EV_SUB(32);
			bmp = m_and(bmp,MyLowBB[MY_RANK4]);
			if(count_1s(bmp) >= 2){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3a5/4k4/b2ab4/9/4c4/3C1p2P/P3P2n1/4B4/2C1A4/3AK1B2 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 
		&& StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(My_pawn_already_over_river(POSITION) == 0 
				&& Your_pawn_already_over_river(POSITION) >= 1){
					MY_EV_SUB(ycan * 64);
			}
	}

	//if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) <= 0x4){
	//	if(RpawnAlreadyRiver(board) == 0 && BpawnAlreadyRiver(board) >= 1){
	//		board->mulScore -= bcan * 64;
	//	}
	//}


	
}

//void m_MT_B_2pao3pawn_R_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan  = RpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2PaoXPawn_1Pao1Ma_ByPawn[board->B_shi];
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 9/4k4/b2C1N3/9/2p5p/4P4/9/4Bc2B/4K4/cp3A3 b - - 1 1
//    //如果炮方没有仕了, 有红方的兵可过河,要加分
//	if(board->B_shi == 0 && rcan >= 1){
//		board->mulScore += 64;
//	}
//
//	// fen 2bak3C/2n1a4/9/2P6/6b2/2p6/P7P/4K3C/9/c2A1A3 w - - 0 0
//	if(rcan >= 1 && (board->B_xiang + board->B_shi) <= 1){
//		if((board->R_shi + board->R_xiang) >= 3){
//			board->mulScore += 128;
//		}
//	}
//
//	// fen 3a5/4k4/b2ab4/9/4c4/3C1p2P/P3P2n1/4B4/2C1A4/3AK1B2 w - - 0 0
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//		if(BpawnAlreadyRiver(board) == 0 && RpawnAlreadyRiver(board) >= 1){
//			board->mulScore += rcan * 64;
//		}
//	}
//
//
//
//	*/
//}