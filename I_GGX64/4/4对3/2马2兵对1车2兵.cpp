#ifndef END_my_m_MT_R_2ma2pawn_B_1che2pawn
#define END_my_m_MT_R_2ma2pawn_B_1che2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马2兵对1车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_Che2Pawn_To_2MaXPawn_ByPawn[3]        =  { 96, 64, 32};  //车2兵,对2马x兵
//const int ADD_2MaXPawn_To_Che2Pawn_ByPawn[3]        =  { 96, 64, 32};  //车2兵,对2马x兵

void my_m_MT_R_2ma2pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_To_Che2Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_Che2Pawn_To_2MaXPawn_ByPawn[my_shi_num]);

	int ycan = EV_YOUR_CAN;

	// fen 2ba5/4ak3/9/2P5p/p8/9/P3N3P/3AB1N2/6r2/2BAK4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(32);
			MY_EV_SUB(32 * count_1s(bb_my_ma,MyLowBB[MY_RANK4]));
		}
	}

	// fen 3ak4/4aP3/6n2/4nR2p/2b6/5p2P/9/4BA3/9/4KA3 b - - 121 121
	if(my_shi_num == 2 && my_xiang_num >= 1 && PB90(MY_SQ55) == my_king 
		&& ycan <= 1 && PB90(MY_SQ3A) == my_ma){
		Bitboard bb =  m_and(bb_your_pawn,MyLowBB[MY_RANK7]);
		if(count_1s(bb) == 1){
			if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn 
				&& PB90(MY_SQ41) == my_ma){
					RETRUN_MUL(4);
			}
			if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn
				&& PB90(MY_SQ45) == my_ma){
					RETRUN_MUL(4);
			}
		}
	}


}

//void m_MT_B_2ma2pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	Square rpawn1 = PieceListStart(board,RPAWN);
//	Square rpawn2 = NextPiece(board,rpawn1);
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_To_Che2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_Che2Pawn_To_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	// fen 3ak4/4aP3/6n2/4nR2p/2b6/5p2P/9/4BA3/9/4KA3 b - - 121 121
//	if(board->B_shi == 2 && StoY(bk) == 0x3 && board->B_xiang >= 1){
//		if(StoY(rpawn1) <= 0x4 || StoY(rpawn2) <= 0x4){
//			if(StoY(bpawn1) == 0x8 || StoY(bpawn2) == 0x8){
//				if(board->b256[0x67] == BMA && board->b256[0x59] == BMA && board->b256[0x6b] == BPAWN){
//					if(board->b256[0x8b] == RPAWN || board->b256[0x9b] == RPAWN){
//						return 4;
//					}
//				}
//				if(board->b256[0x67] == BMA && board->b256[0x55] == BMA && board->b256[0x63] == BPAWN){
//					if(board->b256[0x83] == RPAWN || board->b256[0x93] == RPAWN){
//						return 4;
//					}
//				}
//			}
//		}
//	}
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn