#ifndef END_my_m_MT_R_1che3pawn_B_1che1ma
#define END_my_m_MT_R_1che3pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车3兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//const int PanwAdd = 32;

void my_m_MT_R_1che3pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePawn_To_CheMa_By_PawnByShi[your_shi_num]); 
	
	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	//如果兵方一个子也没有了
	if((my_shi_num + my_xiang_num) <= 1){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(ADD_ChePawn_To_CheMa_Pawn_SX_LessOne);
		}
	}

	// fen 2b1k4/9/4b4/9/P1P1R3P/9/2r6/3An4/4A4/3K5 b - - 3 3
	if (my_xiang_num == 0 && StoY(yma) MY_LARGE_EQL MY_RANK5) {
		Bitboard p = m_and(bb_my_pawn, MyLowBB[MY_RANK3]);
		if (count_1s(p) == 3) {
			MY_EV_SUB(128);
		}
	}



	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(128);

		// fen 3ak1b2/4a4/4b4/9/9/P8/4P1nrP/2R6/4A4/2BK1A3 b - - 0 1
		MY_EV_ADD(EV_MY_CAN * 32);

		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}



}

//void m_MT_B_1che3pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_ChePawn_To_CheMa_By_PawnByShi[board->R_shi];
//		}
//	}
//
//	//如果兵方一个子也没有了
//	if((board->B_shi + board->B_xiang)<= 1){
//		board->mulScore += ADD_ChePawn_To_CheMa_Pawn_SX_LessOne ;
//	}
//
//	Square rk = PieceListStart(board,RKING);
//    Square bk = PieceListStart(board,BKING);
//
//	int rma = PieceListStart(board,RMA);
//
//	if((board->B_shi + board->B_xiang) >= 3 && StoY(bk) != 0x5){   //兵方安全了
//		board->mulScore -= 128;
//
//		// fen 4kab2/4a4/4b4/1R7/P1P3r2/8P/9/3nB4/9/2BK1A3 b - - 0 0
//		if((board->R_shi + board->R_xiang) == 4 && StoY(rk) == 0xc){
//			return 8;
//		}
//	}
//
//	// fen 2b1k4/9/4b4/9/P1P1R3P/9/2r6/3An4/4A4/3K5 b - - 3 3
//	if(board->B_xiang == 0 && StoY(rma) <= 0x7){
//		//如果所有兵在兵线上	
//		bool pok = FALSE;
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) >= 0xa && StoY(from) <= 0xb){
//				pok = TRUE;
//				break;
//			}
//		}
//
//		if(pok == FALSE){
//			board->mulScore += 196;
//		}
//	}
//
//
//
//	*/
//}