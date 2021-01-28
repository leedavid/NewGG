#ifndef END_my_m_MT_R_1che3pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che3pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车3兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che3pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheXPawn_To_1Che1Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che1Ma1Pawn_To_CheXPawn_ByPawn[my_shi_num]);

	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	// fen 2b2k3/2R6/2N1b4/p1r6/8p/P5B2/8p/9/4A4/4KAB2 w - - 0 0
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		if(EV_YOUR_CAN == 0 && StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	if (my_shi_num == 2 && my_xiang_num == 2 && MY_RANK9 == StoY(mk)){
		Bitboard mlp = My_get_connect_Pawn(POSITION);
		if (have_bit(mlp, MyLowBB[MY_RANK2])){
			MY_EV_ADD(64);
		}
		if (abs(StoX(ypawn) - 0x4) >= 2){
			MY_EV_ADD(32);
		}
	}



	// fen 4kab2/2PPa4/4b4/8p/9/r3nR3/8P/B8/4A4/5K3 b
	if(EV_YOUR_CAN == 0 && my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if(isStringByChe(POSITION,mche,yma,yche)){
			MY_EV_ADD(64);
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4ka3/4a4/b8/4PP3/p1n6/9/P3R4/3AB4/4Ar3/4K4 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
			if(StoY(mche) == MY_RANK6){
				MY_EV_ADD(32);
				Bitboard lp = My_get_connect_Pawn(POSITION);
				if(bit_is_set(lp,MY_SQ1F) || bit_is_set(lp,MY_SQ28)){
					MY_EV_ADD(32);
				}
				if(StoY(yma) MY_SMALL_EQL MY_RANK5){
					MY_EV_ADD(32);
				}
			}
		}
	}

	if(ycan == 0 && (my_shi_num == 2 || my_xiang_num == 2)){
		if(IsOnSameSide(mk,yche) == FALSE){
			if(PB90(MY_SQ4A) == your_che && PB90(MY_SQ41) == your_ma && StoX(mche) == 0x2){
				MY_EV_ADD(mcan * 64);
			}
			if(PB90(MY_SQ4E) == your_che && PB90(MY_SQ45) == your_ma && StoX(mche) == 0x6){
				MY_EV_ADD(mcan * 64);
			}
		}
	}
	int malr = My_pawn_already_over_river(POSITION);
	// fen 4ka3/2NRa4/b8/p3p3p/2r6/9/6P2/B8/9/4K4 w - - 0 0
	if(malr == 0){
		MY_EV_SUB((4 - my_shi_num - my_xiang_num) * 96);
	}

	// fen 3akab2/9/5n3/6P1p/3PP4/R8/9/4BA3/4K4/5rB2 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(count_1s(bb_my_pawn,MyUpBB[MY_RANK5]) >= 2){
			if(StoY(yma) MY_SMALL_EQL MY_RANK2){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
		}
	}
}

//void m_MT_B_1che3pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//	int rcan  = RpawnCanOverLiver(board);
//	int bcan  = BpawnCanOverLiver(board);
//	Square rpawn = PieceListStart(board,RPAWN);
//	int rma   = PieceListStart(board,RMA);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Che1Ma1Pawn_To_CheXPawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheXPawn_To_1Che1Ma1Pawn_ByPawn[board->B_shi];
//		}
//	}
//
//	//// fen 2b2k3/2R6/2N1b4/p1r6/8p/P5B2/8p/9/4A4/4KAB2 w - - 0 0
//	// fen 2b2k3/2R6/2N1b4/p1r6/8p/P5B2/8p/9/4A4/4KAB2 w - - 0 0
//	int bche = PieceListStart(board,BCHE);
//	if(rcan == 0){
//		if(board->B_xiang == 2){
//			if(board->b256[0x45] == RCHE && board->b256[0x55] == RMA){
//				if(StoX(bche) == 0x5){
//					board->mulScore -= bcan * 80;
//				}
//			}
//			if(board->b256[0x49] == RCHE && board->b256[0x59] == RMA){
//				if(StoX(bche) == 0x9){
//					board->mulScore -= bcan * 80;
//				}
//			}
//		}
//	}
//
//	// fen 3akab2/9/b5n2/7Rp/6r2/2P5P/P8/4B4/4A4/2B1K4 w - - 6 6
//	if((board->B_shi + board->B_xiang) >= 3 && StoY(bk) == 0x3){
//		//
//		if(StoY(bche) == 0x9 && board->R_shi >= 1){
//			if(rcan == 0){
//				if(StoY(rpawn) == 0x9 && StoY(rma) >= 0xa){
//					return 4;
//				}
//			}
//		}
//	}
//
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn