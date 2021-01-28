#ifndef END_my_m_MT_R_2pao1ma1pawn_B_1pao2ma
#define END_my_m_MT_R_2pao1ma1pawn_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对1炮2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2pao1ma1pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2Pao1MaXpawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	Square mk = my_king_pos;
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(32);
	}

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 3ck4/4a4/b3ba3/9/2n6/2B2N1nC/P8/3AB4/1C2A4/4K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(32);
		}
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


}
//
//void m_MT_B_2pao1ma1pawn_R_1pao2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao2Ma_To_2Pao1MaXpawn_ByPawn[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_1Pao2Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	if(board->B_xiang == 2 && board->B_shi == 2 && StoY(bk) <= 0x4){
//		board->mulScore -= 64;
//	}
//
//
//
//
//	*/
//}