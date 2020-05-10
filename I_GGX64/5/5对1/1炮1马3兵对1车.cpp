#ifndef END_my_m_MT_R_1pao1ma_3pawn_B_1che
#define END_my_m_MT_R_1pao1ma_3pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马3兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1pao1ma_3pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_1Che_PawnByShi[your_shi_num]);

	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	//如果对方是仕相全，且我方的兵没有过河，要减分
	// fen 3ak1b2/4a4/4b4/5r3/9/5CP1P/P3N4/4B4/4A4/2B1KA3 w - - 6 6
	// SUB
	if ((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(count_1s(bb_my_pawn, MyLowBB[MY_RANK4])
			* ADD_1Pao1MaXPawn_To_1Che_PawnNotRiver);

		// fen 3k1ab2/1PP6/4ba3/9/1r7/4P4/9/3A5/4A4/4KCN2 w - - 0 1
		if ((my_shi_num + my_xiang_num) <= 2){
			MY_EV_SUB(32);
		}
		if (StoY(mma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(32);
		}

		Bitboard mup = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
		if (StoX(yk) == 0x3 && count_1s(mup, LeftBB[0x3]) >= 2){
			MY_EV_SUB(32);
		}
		if (StoX(yk) == 0x5 && count_1s(mup, RightBB[0x5]) >= 2){
			MY_EV_SUB(32);
		}

		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			MY_EV_SUB(64);
		}
	}

	if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 64);
	}

	


	//int a = count_1s(bb_my_pawn, MyLowBB[MY_RANK4]);

	//print_bb(bb_my_pawn);
	//print_bb(MyLowBB[MY_RANK4]);

	// fen 4k4/4a4/b4a3/5NP2/5r3/P1P3B2/3C5/3A5/4A4/2B1K4 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		Bitboard mp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(mp) == 2){
			MY_EV_SUB(64);
			if(PB90(MY_SQ20) == my_ma && PB90(MY_SQ21) == my_pawn && PB90(MY_SQ17) == your_shi){
				if(PB90(MY_SQ29) == your_che){
					RETRUN_MUL(8);
				}
			}
			if(PB90(MY_SQ1E) == my_ma && PB90(MY_SQ1D) == my_pawn && PB90(MY_SQ15) == your_shi){
				if(PB90(MY_SQ27) == your_che){
					RETRUN_MUL(8);
				}
			}
		}
	}
}
//
//
//void m_MT_B_1pao1ma_3pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_To_1Che_PawnByShi[board->R_shi];
//		}
//	}
//
//	//如果对方是仕相全，且我方的兵没有过河，要减分
//	// fen 3ak1b2/4a4/4b4/5r3/9/5CP1P/P3N4/4B4/4A4/2B1KA3 w - - 6 6
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < 0x8){
//				board->mulScore += ADD_1Pao1MaXPawn_To_1Che_PawnNotRiver; //ADD_2PaoXPawn_To_1Che_PawnByShi
//			}
//		}
//	}
//
//
//	*/
//}
//
