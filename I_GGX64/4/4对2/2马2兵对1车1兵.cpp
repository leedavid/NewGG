#ifndef END_my_m_MT_R_2ma2pawn_B_1che1pawn
#define END_my_m_MT_R_2ma2pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马2兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_2ma2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_MAT_B_2ma1pawn_R_1che1pawn_ByShi[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * Add_MAT_B_1che1pawn_R_2ma1pawn_ByShi[my_shi_num]);

	int ycan = EV_YOUR_CAN;

	//if(ycan == 0){
	//	MY_EV_ADD(My_pawn_can_over_river(POSITION) * Add_2ma1pawn_1che1pawn_MaPawnCan);
	//}

	if(ycan == 0){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}


	Square yche = S90_from_piecelist(POSITION,your_che,0);
	// fen 3k5/4aP3/3ab4/9/2b2n3/6B2/5Rn2/4B4/2p1A1p2/4KA3 b - - 84 84
	if(ycan > 0){
		MY_EV_SUB(64);
		if(your_shi_num == 2 && your_xiang_num >= 1){			
			Bitboard p1 = POSITION.Rook_attacks_bb(yche);
			p1 = m_and(p1,bb_my_ma);
			if(count_1s(p1) == 2){
				MY_EV_SUB(80);
			}
		}
	}

	// fen 4ka3/5P3/3a5/5P3/6b2/5N3/5r1N1/8B/1p2A4/3AK1B2 w - - 0 
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 4ka3/4a4/8b/7rp/4P1b2/2B3N1P/9/6N2/4A4/4KAB2 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3 && EV_MY_CAN <= 1){
			RETRUN_MUL(8);
		}
	}

	//if(bcan > 0){
	//	if(board->B_shi == 2 && board->B_xiang >= 1){
	//		if(OneCheControlTwoMa(bche,rma1,rma2) || (StoY(rma1) >= 0x8 && StoY(rma2) >= 0x8)){
	//			board->mulScore -= 256;
	//		}
	//	}
	//}

	
}

// 黑方马炮兵,红方车兵
//void m_MT_B_2ma2pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	int bma1 = PieceListStart(board,BMA);
//	int bma2 = NextPiece(board,bma1);
//	int rche = PieceListStart(board,RCHE);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  Add_MAT_B_2ma1pawn_R_1che1pawn_ByShi[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_2ma1pawn_ByShi[board->B_shi];
//		}
//	}
//
//
//	//如果黑方的兵不能过河,要减分
//	//if((board->B_shi + board->B_xiang) >= 3){
//	//	if(rcan == 0){
//	//		board->mulScore -= Add_2ma1pawn_1che1pawn_chePawnCan0;
//	//	}
//	//}
//	// fen 3k1ab2/9/4ba3/9/4p4/5N3/P3P1r1P/3AB1N2/9/2B1K4 w - - 1 1
//	if(rcan == 0){
//		board->mulScore -= bcan * Add_2ma1pawn_1che1pawn_MaPawnCan;
//	}
//
//	// fen 3k5/4aP3/3ab4/9/2b2n3/6B2/5Rn2/4B4/2p1A1p2/4KA3 b - - 84 84
//	if(rcan > 0){
//		if(board->R_shi == 2 && board->R_xiang >= 1){
//			if(OneCheControlTwoMa(rche,bma1,bma2) || (StoY(bma1) <= 0x7 && StoY(bma2) <= 0x7)){
//				board->mulScore += 256;
//			}
//		}
//	}
//
//	*/
//}

