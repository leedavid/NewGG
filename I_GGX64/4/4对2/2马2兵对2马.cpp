#ifndef END_my_m_MT_R_2ma2pawn_B_2ma
#define END_my_m_MT_R_2ma2pawn_B_2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马2兵对2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2ma2pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pok = (int)count_1s(bmp);
	MY_EV_ADD(pok * ADD_2MaXPawn_2Ma_ByPawnShi[your_shi_num]);

	// fen 4kab2/3Pa4/b8/6N2/3nN1n2/2P3B2/9/5A3/4A4/2BK5 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (EV_MY_CAN <= 1){
			MY_EV_SUB(96);
		}
	}

	// fen 2bN4P/4P4/b2k1N3/6n2/9/9/9/2n1K4/9/9 w - - 0 0
	if(pok == 0){
		MY_EV_SUB(128);
		if((my_shi_num + my_xiang_num) == 0){
			if(your_xiang_num == 2){
				RETRUN_MUL(4);
			}
		}
	}

	Bitboard bym = m_and(bb_your_ma,MyUpBB[MY_RANK6]);
	if(count_1s(bym) == 2){
		MY_EV_SUB(96);  // 对方的二马要回守
	}

	if(StoY(yk) == MY_RANK0){
		if((your_shi_num + your_xiang_num) == 4){
			RETRUN_MUL(8);
		}
	}

	// fen 3a5/3P1P3/3k1a2b/2N1nN3/2n6/2B6/9/3A5/9/4K4 b - - 0 170
	if(your_shi_num == 2 && your_xiang_num >= 1){
		bmp = m_and(bb_my_pawn,MyUpBB[StoY(yk)]);
		if(count_1s(bmp) == 2){
			RETRUN_MUL(8);
		}
	}

	// fen 2P6/3k1P3/2n2a2b/2N1nN3/9/9/9/B8/4A4/4K4 w - - 0 1
    if(your_shi_num >= 1 && your_xiang_num >= 1 && have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){
		if(StoY(yk) != MY_RANK0){
			Bitboard mbp = m_and(bb_my_pawn,MyLowBB[MY_RANK0]);
			if(PB90(MY_SQ17) == your_shi && !have_bit(mbp,LeftBB[0x4])){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ15) == your_shi && !have_bit(mbp,RightBB[0x4])){
				RETRUN_MUL(8);
			}
		}
	}

}
//
//void m_MT_B_2ma2pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_2Ma_ByPawnShi[board->R_shi];
//		}
//	}
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	// fen 2bN4P/4P4/b2k1N3/6n2/9/9/9/2n1K4/9/9 w - - 0 0
//	if(board->B_shi == 0 && board->B_xiang == 0){
//		if(StoY(bpawn1) > StoY(rk) && StoY(bpawn2) > StoY(rk)){
//			if(board->R_xiang == 2){
//				return 4;
//			}
//		}
//	}
//
//	// fen 3k5/4a4/2Pab4/3P5/2bNn4/3nN4/9/5A3/4A4/2BK5 w - - 121 121
//	if(StoY(rk) == 0xc){
//		if(board->R_shi == 2 && board->R_xiang == 2){
//			return 8;
//		}
//	}
//
//	*/
//}