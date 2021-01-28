#ifndef END_my_m_MT_R_1che1ma2pawn_B_2che
#define END_my_m_MT_R_1che1ma2pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int MAT_R_2che1pawn_B_1che1ma1pawn_MaSafe = 256;


void my_m_MT_R_1che1ma2pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	////////////////////
	Square mk = my_king_pos;

	your_m_MT_R_2CHE_B_1CHE1MA(POSITION,ei);

	if(ei.mul <= 2){
		EV_MY_SAFE = TRUE;
	}
	// fen 4kab2/4aR3/4R4/4n1r2/9/9/9/4B4/9/2BAKA3 w - - 0 0
	if(my_xiang_num >= 1 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(PB90(MY_SQ3A) == my_ma && PB90(MY_SQ43) == your_che){
			if(PB90(MY_SQ53) == my_xiang && PB90(MY_SQ4B) == your_che){
				EV_MY_SAFE = TRUE;
			}
			if(PB90(MY_SQ57) == my_xiang && PB90(MY_SQ4D) == your_che){
				EV_MY_SAFE = TRUE;
			}
		}
	}

	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	if(EV_MY_SAFE){
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_2Che_MaSafe_ByPawn[your_shi_num] * 3/2);
	}
	else{
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_2Che_MaSafe_ByPawn[your_shi_num]);
	}
}
//
//void m_MT_B_1che1ma2pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	int rcan = RpawnCanOverLiver(board);
//
//    Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int bche = PieceListStart(board,BCHE);
//
//
//	if(m_MT_R_2CHE_B_1CHE1MA(board) == 1){
//		board->bsafe = TRUE;
//	}
//
//
//	// fen 4kab2/4aR3/4R4/4n1r2/9/9/9/4B4/9/2BAKA3 w - - 0 0
//	//红方二个车一个也不能动了,也是和棋, 红方的兵不能过河
//	if(rcan == 0){
//		if(board->B_xiang >= 1 && board->B_shi == 2){
//			if(StoY(bk) == 0x3){
//				if(board->b256[0x67] == BMA && board->b256[0x57] == RCHE){
//					if(IsCheCanToOrAt(board,bche,0x67)){
//						if(FALSE){
//						}
//						else if(board->b256[0x39] == BXIANG && board->b256[0x48] == RCHE){
//
//							board->bsafe = TRUE;
//						}
//						else if(board->b256[0x35] == BXIANG && board->b256[0x46] == RCHE){
//							board->bsafe = TRUE;
//						}
//					}
//				}
//			}
//		}
//	}
//
//
//
//
//
//	//board->mulScore -= MAT_R_2che1pawn_B_1che1ma1pawn_MaSafe; //ADD_CheMaPawn_2Che_MaSafe_ByPawn
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			//board->mulScore -= ADD_CheMaPawn_2Che_MaSafe_ByPawn[board->R_shi];
//			int add = ADD_CheMaPawn_2Che_MaSafe_ByPawn[board->R_shi];
//			if(board->bsafe) {
//				add *= 2;
//			}
//			board->mulScore -= add;
//		}
//	}
//
//
//	
// 
//
//	*/
//}




