#ifndef END_my_m_MT_R_2pao2pawn_B_2pao1pawn
#define END_my_m_MT_R_2pao2pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2±ø¶Ô2ÅÚ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi


void my_m_MT_R_2pao2pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if((my_shi_num + my_xiang_num) >= 3){
		EV_MY_SAFE = TRUE;
	}

	// fen 3ak4/3Pa1P2/b3b4/9/7C1/6B2/9/3p5/5C3/4KcBc1 b - - 0 1
	if(EV_MY_CAN == 2 && MY_SQ55 == mk && my_xiang_num == 2){

		MY_EV_ADD(16);

		if(PB90(MY_SQ56) == your_pao && StoX(ypawn) <= 0x4){
			if(PB90(MY_SQ4D) == my_pao && PB90(MY_SQ57) == my_xiang){
				MY_EV_ADD(64);
			}	
		}
		if(PB90(MY_SQ54) == your_pao && StoX(ypawn) >= 0x4){
			if(PB90(MY_SQ4B) == my_pao && PB90(MY_SQ53) == my_xiang){
				MY_EV_ADD(64);
			}	
		}
	}
	
	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;
	// fen 3k5/4a4/4ba3/2p2C2c/2b1C1p2/2P5c/9/3A4B/4A4/3K2B2 b - - 120 120
	if(mcan <= 1 && ycan <= 1){
		if((your_shi_num + your_xiang_num) == 4){
			if((my_xiang_num + my_shi_num) >= 3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k1ab2/4a4/9/9/3P4p/1C4C2/P3c4/9/4c4/5KB2 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3k1ab2/4a4/9/9/3P4p/1C4C2/P3c4/9/4c4/5KB2 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		MY_EV_ADD(EV_MY_CAN * 8);
	}

	MY_EV_ADD(EV_MY_CAN * 8);

	// fen 2bak4/4a4/8b/7P1/2pcc4/3C5/P8/4BC3/4A4/2BA1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
			if(have_bit(bb_my_pawn,LeftBB[0x1]) || have_bit(bb_my_pawn,RightBB[0x7])){
				RETRUN_MUL(6);
			}
			RETRUN_MUL(8);
		}
	}

	// fen 2baka3/9/1c2b4/1c1C4P/4p4/P8/3C5/3KB4/4A4/5AB2 r
	if(EV_MY_SAFE){
		if(EV_YOUR_CAN && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
					if(!have_bit(bb_my_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
						RETRUN_MUL(10);
					}
				}
			}
		}
	}

}
//
//void m_MT_B_2pao2pawn_R_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[board->B_shi];
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//	// fen 3k5/4a4/4ba3/2p2C2c/2b1C1p2/2P5c/9/3A4B/4A4/3K2B2 b - - 120 120
//	if(bcan <= 1 && rcan <= 1){
//		if(board->B_shi == 2 && board->B_xiang == 2){
//			if(board->R_shi == 2 && board->R_xiang == 2){
//				return 4;
//			}
//		}
//	}
//
//	*/
//}