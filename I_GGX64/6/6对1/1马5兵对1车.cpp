#ifndef END_my_m_MT_R_1ma5pawn_B_1che
#define END_my_m_MT_R_1ma5pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马5兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
// void m_MT_B_1CHE_R_1MA(board_t *board);
// void my_m_MT_R_1CHE_B_1MA(board_t *board);
//我方一马一兵, 对方一车
void my_m_MT_R_1ma5pawn_B_1che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;

	MY_EV_SUB(128);  // 车方要加分

	your_m_MT_R_1CHE_B_1MA(POSITION,ei);

	if(ei.mul <= 2){		
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_MaXPawn_To_CheByShi_WmaSafe[your_shi_num]);
	}
}

//void m_MT_B_1ma5pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16 = pMat->sixiangInfo8;
//
//	Square rk     = PieceListStart(board,RKING);
//	Square bk     = PieceListStart(board,BKING);
//	int bma    = PieceListStart(board,BMA);
//	Square bpawn  = PieceListStart(board,BPAWN);
//
//	bool isSafe = FALSE;
//
//	//有一种和形
//	// fen 4k4/9/4b4/4p4/2n4R1/9/9/9/9/4K4 w  例典: 一车例和马卒象 page
//	if(board->B_xiang != 0){
//		if(board->b256[0x67] == BPAWN && board->b256[0x57] == BXIANG && StoX(bk) == 0x7){
//			//1, 马在相眼上
//			//if(board->b256[0x75] == BMA || board->b256[0x79] == BMA){
//			//	return 1;
//			//}
//			//2, 马可走到相眼上
//			if(IsMaCanToOrAt(board,bma,0x75) || IsMaCanToOrAt(board,bma,0x79)){
//				isSafe = TRUE;
//			}
//		}
//	}
//
//	if(m_MT_R_1CHE_B_1MA(board) == 1){
//		isSafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){  //马方有二相,或二仕, 则马方如果在中线有连兵就是和了.
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) < StoY(rk) && StoX(from) == 0x7){
//
//				if(board->b256[from+1] == BPAWN || board->b256[from-1] == BPAWN){
//
//					isSafe = TRUE;
//
//					break;
//				}
//			}
//		}
//	}
//
//	if(isSafe){    //马兵方安全了
//
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < StoY(rk)){
//				board->mulScore -= ADD_MaXPawn_To_CheByShi_WmaSafe[board->R_shi];
//			}
//		}
//
//		return 1;
//	}
//
//
//	*/
//}


