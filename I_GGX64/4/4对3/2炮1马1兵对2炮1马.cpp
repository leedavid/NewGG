#ifndef END_my_m_MT_R_2pao1ma1pawn_B_2pao1ma
#define END_my_m_MT_R_2pao1ma1pawn_B_2pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对2炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1ma1pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2Pao1MaXpawn_To_2Pao1Ma_ByPawn[your_shi_num]);
	Square mk = my_king_pos;

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	
	// fen 4k4/2c1a4/3ab4/N7C/2b6/8P/1n3C3/4B4/4AK3/1cBA5 b
	// fen 4k4/2c1a4/3ab4/N7N/2b6/8P/1n3C3/4B4/4AK3/1cBA5 b - - 4 4
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(32);
	}

	// fen 2ba1k3/4a4/4b1c2/1P6c/9/2C3nC1/9/5A2N/4A4/4K4 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 32);
			if(StoY(mpawn) == MY_RANK3){
				MY_EV_ADD(32);
			}
		}
	}
	// fen 4kab2/4a4/4b4/9/7CP/cN7/C4n3/4B4/1c2A4/4KAB2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (StoY(yma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(32);
		}
		if (abs(StoX(mpawn) - 0x4) >= 3){
			RETRUN_MUL(12);
		}
	}

}
//
//void m_MT_B_2pao1ma1pawn_R_2pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma_To_2Pao1MaXpawn_ByPawn[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	if(board->B_xiang == 2 && board->B_shi == 2 && StoY(bk) <= 0x4){
//		board->mulScore -= 64;
//	}
//
//
//
//	*/
//}