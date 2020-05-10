#ifndef END_my_m_MT_R_1ma3pawn_B_1ma
#define END_my_m_MT_R_1ma3pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//ADD_1马兵对1马兵_by_Pawn

//1马3兵对1马
void my_m_MT_R_1ma3pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);

	int pok = (int)count_1s(bmp);

	MY_EV_ADD(pok * ADD_1马兵对1马_by_Pawn_By_Shi[your_shi_num]);


	// fen 3a2b2/2PPak3/9/3n1P3/3N2b2/6B2/9/5A3/4K4/9 w - - 120 120
	//有二个兵低于将，且对方是仕相全，要减半


	int mcan = EV_MY_CAN;

	// fen 2bk1a3/9/4ba3/5N3/2p3p2/9/5n3/3AB4/4AK2p/2B6 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoX(yk) != 0x4 && mcan <= 2 && My_pawn_already_over_river(POSITION) <= 1){
			RETRUN_MUL(8);
		}
	}


	if(pok <= 1 && your_shi_num == 2 && your_xiang_num == 2){
		RETRUN_MUL(8);
	}

}

//void m_MT_B_1ma3pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1马兵对1马_by_Pawn_By_Shi[board->R_shi];
//		}
//	}
//
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16  = pMat->sixiangInfo8;
//	//int    rk      = PieceListStart(board,BKING);
//
//	//if(board->R_shi == 2 && board->R_xiang == 2){
//	//	return 12;
//	//}
//
//	// fen 3a2b2/2PPak3/9/3n1P3/3N2b2/6B2/9/5A3/4K4/9 w - - 120 120
//	//有二个兵低于将，且对方是仕相全，要减半
//	int blow = 0;
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) >= StoY(rk) && StoY(from) >= 0xb){
//			blow ++;
//		}
//	}
//
//	// fen 2bk1a3/9/4ba3/5N3/2p3p2/9/5n3/3AB4/4AK2p/2B6 b - - 120 120
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) >= 0xb && StoX(rk) != 0x7){
//		if(bcan <= 2 && BpawnAlreadyRiver(board)  <= 1){
//            return 8;
//		}
//	}
//
//	if(blow >= 2 && board->R_shi == 2 && board->R_xiang == 2){
//		return 8;
//	}
//
//	*/
//}