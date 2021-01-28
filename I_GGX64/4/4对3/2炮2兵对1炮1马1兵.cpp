#ifndef END_my_m_MT_R_2pao2pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_2pao2pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮2兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao2pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[my_shi_num]);

	Square ypawn  = S90_from_piecelist(POSITION,your_pawn,0);
	//炮方要减一些分
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
	}
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);

	// fen 4kab2/4a4/4b4/7P1/P3c4/4Cn3/9/B8/1C1pA4/2BAK4 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if (StoX(ypawn) < 0x4 && StoX(mk) >= 0x4){
			if (!have_bit(bb_my_shi, RightBB[0x4])){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
		if (StoX(ypawn) > 0x4 && StoX(mk) <= 0x4){
			if (!have_bit(bb_my_shi, LeftBB[0x4])){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}

		// fen 4kab2/9/4ba3/3C5/9/1nP1p4/P3c4/1C7/9/2BAKAB2 b - - 0 1
		if (EV_MY_CAN >= 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(32);
		}
	}

	// fen 4kab2/4a4/4b4/2P6/4p4/6B1C/4P4/n2AB4/9/4KAC1c w - - 0 1
	if (EV_MY_CAN <= 1) {
		if ((your_shi_num + your_xiang_num) == 4) {
			MY_EV_SUB(16);
			if (StoY(yma) MY_LARGE_EQL MY_RANK4) {
				MY_EV_SUB(16);
			}
		}
	}
	

	// fen 4kab2/9/4ba3/3C5/9/1nP1p4/P3c4/1C7/9/2BAKAB2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		MY_EV_ADD(16);
	}

	// fen 2bak4/4a4/4b1P2/1C7/3C5/P8/1n7/4p4/4A4/3K1AB1c w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1 && MY_SQ43 == ypawn){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoX(ypao) != StoX(mk)){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 4kab2/4a4/4b4/p8/4CnC2/8P/Pc7/4B4/4A4/3AK4 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 4ka3/4a4/b8/4P4/P5b2/9/nC3p3/B2A1A3/1c1C5/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
		}
		if (my_xiang_num <= 1){
			MY_EV_SUB(32);
		}
	}

	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	// fen 4k4/4a2C1/b2a5/4pN1c1/p5c2/9/P8/4B4/4A4/4KAB2 b - - 14 14
	if(ycan == 0 && mcan >= 1){
		if((my_shi_num + my_xiang_num) >= 2){
			MY_EV_ADD(32);
		}
	}

	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2b1ka3/4a4/6c2/9/p3P1b2/8p/6c2/C3B4/4A4/4KABN1 w - - 7 7
	if(your_shi_num == 2 && your_xiang_num == 2){
		Bitboard b1 = m_and(bb_my_pawn,MyLowBB[MY_RANK3]);
		if(count_1s(b1) == 2){
			if(ycan >= 1 ){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 4kab2/4a4/4b4/4c4/P7P/3n5/5p3/3C3CB/4A4/3K1A3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(EV_MY_CAN >= 2){
			if(count_1s(bb_my_pao,MyLowBB[MY_RANK4]) == 2){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 4kab2/4a4/2P1b4/6C2/5P3/9/5C3/5K2n/2p1A3c/5A3 w - - 0 1
    if(my_shi_num == 2 && StoY(ypawn) MY_LARGE StoY(mk)){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 2bCk2P1/3P5/4b4/9/7c1/4n4/9/2CA5/5p3/3K5 b - - 0 1
	if(your_xiang_num == 2){
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){ // 有一个底兵
			if(PB90(MY_SQ04) == your_king){
				if(PB90(MY_SQ03) == my_pao && PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ02) == your_xiang){
					MY_EV_SUB(96);
				}
				if(PB90(MY_SQ05) == my_pao && PB90(MY_SQ0E) == my_pawn && PB90(MY_SQ06) == your_xiang){
					MY_EV_SUB(96);
				}
			}
		}
	}

	// fen 2bak4/4a2C1/4b1P2/8c/5P3/1n6C/9/3A5/3pA4/4K1B2 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK8){
			if(StoX(ypawn) < 0x4 && PB90(MY_SQ42) == my_shi){
				MY_EV_ADD(EV_MY_CAN * 32);
			}
			if(StoX(ypawn) > 0x4 && PB90(MY_SQ44) == my_shi){
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}

	// fen 4kab2/4c4/4b4/9/4n1p2/2P6/2C3P2/4BC2B/4A4/3AK4 b - - 0 1
    if(EV_MY_CAN == 0){
		if(your_xiang_num == 2 && your_shi_num >= 1){
			MY_EV_SUB(64);
		}
		if(my_shi_num == 2 && my_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}

	// fen C3k4/4a4/4b1c2/p7C/9/8P/P3n4/4B4/9/2BAKA3 b - - 0 1
    if(your_shi_num >= 1 && your_xiang_num >= 1 &&!have_bit(MyUpBB[MY_RANK4],bb_my_pawn)){
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(64);
			MY_EV_SUB((sint16)count_1s(MyLowBB[MY_RANK4],bb_my_pawn) * 32);

			if(EV_YOUR_CAN == 0 && (my_xiang_num == 2 && my_shi_num >= 1)){
				RETRUN_MUL(8);
			}
		}		
	}

	// fen 2bak4/4a4/c1P5n/4p3C/6b2/C3P4/9/4B4/4A4/2BAK4 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1){
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k1a3/4a4/b3b4/7CP/9/3Cn1P2/2pc5/4B4/4A4/4KAB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && EV_MY_CAN <= 1 ){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			RETRUN_MUL(12);
		}
	}

	// fen C3k4/4aP3/5a2b/9/p1b1c4/9/P3n4/3A5/2C1A4/3K5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && EV_MY_CAN <= 1 ){
		if(my_shi_num == 2 || my_xiang_num == 2){
			if(EV_YOUR_CAN == 0){
				RETRUN_MUL(12);
			}
		}
	}

}

//void m_MT_B_2pao2pawn_R_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	int boff = 0;
//	int rgh  = 0;
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2PaoXPawn_1Pao1Ma_ByPawn[board->B_shi];
//			if(StoY(from) == 0x6 || StoY(from) == 0x7) rgh ++;
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Pao1Ma_ByPawn[board->R_shi];
//		}
//		if(abs(StoX(from) - 0x7) >= 3) boff++;
//	}
//
//	//炮方要减一些分
//	// fen C1baka3/9/4b4/2P5C/2n6/2B5P/3p2c2/9/4A4/4KAB2 w - - 6 6
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		board->mulScore += 64;
//	}
//
//	// fen 4k4/4a2C1/b2a5/4pN1c1/p5c2/9/P8/4B4/4A4/4KAB2 b - - 14 14
//	if(rcan == 0 && bcan != 0){
//		if((board->B_shi + board->B_xiang) >= 2){
//			board->mulScore -= 96;
//		}
//	}
//
//	// fen 2b1ka3/4a4/6c2/9/p3P1b2/8p/6c2/C3B4/4A4/4KABN1 w - - 7 7
//	if(rgh == 1 && boff == 2){
//		board->mulScore += 80;
//	}
//
//
//
//	*/
//}