#ifndef END_my_m_MT_R_1pao3pawn_B_1che
#define END_my_m_MT_R_1pao3pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1炮3兵对1车  //马x兵对1车_addByPawnSafe

void my_m_MT_R_1pao3pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	if(my_xiang_num == 2 || my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}

	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk)  MY_SMALL_EQL MY_RANK1){
		EV_YOUR_SAFE = TRUE;
	}

	if(EV_MY_SAFE){
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoxPawn对1Che_addByPawnSafeByShi[your_shi_num]);
		// fen 6b2/4k4/4b4/p7p/9/6p2/6c2/B3K4/5R3/3A1A3 w - - 0 1
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 2b1ka3/4a4/4b4/9/3PPP3/9/4r4/5C3/5K3/9 b - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
		MY_EV_ADD(64);
		Bitboard p = m_and(bb_my_pawn,
			m_or(RankBB_A[MY_RANK3],RankBB_A[MY_RANK4]));
		if(count_1s(p) == 3){
			MY_EV_ADD(96);
			RETRUN_MUL(2);
		}
		RETRUN_MUL(4);
	}

	// fen 6b2/4k4/4b4/p7p/9/6p2/6c2/B3K4/5R3/3A1A3 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_1pao3pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//
//	//bool adfaf; = FALSE;
//
//	int  rk   = PieceListStart(board,RKING);
//	int  bpao = PieceListStart(board,BPAO);
//
//
//	if(board->B_xiang == 2 && board->B_shi == 2){   //马方有二相二仕, 则马方安全了
//		board->bsafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){  //马方有二相,或二仕, 则马方如果在中线有连兵就是和了.
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) < StoY(rk) && StoX(from) == 0x7){
//
//				if(board->b256[from+1] == BPAWN || board->b256[from-1] == BPAWN){
//
//					board->bsafe = TRUE;
//
//					break;
//				}
//			}
//		}
//	}
//
//	//if(TRUE == adfaf;){
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//		if(StoY(from) <= StoY(rk)){
//
//			board->mulScore -= ADD_PaoxPawn对1Che_addByPawnSafeByShi[board->R_shi];
//		}
//	}
//
//	if(board->R_shi == 2){
//		board->rsafe = TRUE;
//	}
//
//	// fen 6c2/4a1R2/4ka3/p8/4p4/6B1p/9/4B4/4A4/3A1K3 b - - 16 16
//	if(board->B_shi == 2){
//		if(board->b256[0x47] == BSHI){
//			if(StoY(bpao) == 0x3){
//				if(board->b256[0x56] == BSHI || board->b256[0x58] == BSHI){
//					board->bsafe = TRUE;
//				}
//			}
//		}
//		if(board->b256[0x37] == BKING && board->b256[0x36] == BSHI && board->b256[0x38] == BSHI){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if((board->R_shi + board->R_xiang) >= 2){
//		board->rsafe = TRUE;
//	}
//
//	
//
//
//
//	*/
//}