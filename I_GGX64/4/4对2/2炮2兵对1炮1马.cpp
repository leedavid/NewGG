#ifndef END_my_m_MT_R_2pao2pawn_B_1ma1pao
#define END_my_m_MT_R_2pao2pawn_B_1ma1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮2兵对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao2pawn_B_1ma1pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square mk = my_king_pos;
	Square yk = your_king_pos;
    Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[your_shi_num]);

	// fen 3a1k3/9/bPP1b2c1/9/9/9/5C3/6C2/5K3/6n2 w - - 0 114
	if(my_shi_num == 0 && my_xiang_num == 0){
		MY_EV_SUB(64);
	}

	// fen 4kab2/2P1a4/4b4/3P5/cC7/2B6/Cn7/4BA3/4A4/3K5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		MY_EV_SUB(64);
		if(StoY(yk) == MY_RANK0){
			MY_EV_SUB(32);
		}
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			MY_EV_SUB(64);
		}
	}

	// 2b1k4/4a4/9/6N2/6p1C/9/p5cc1/4B4/4A4/2BAK4 w - - 0 1
	if (my_xiang_num >= 1 || my_shi_num >= 1){
		if (StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4k4/1P1Pa4/3abn3/9/6b2/2B6/3Cc4/B2A1C3/4A4/3K5 b
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(!have_bit(LeftBB[0x5],bb_my_pawn) && PB90(MY_SQ03) != your_shi){
				RETRUN_MUL(8);
			}
			if(!have_bit(RightBB[0x3],bb_my_pawn) && PB90(MY_SQ05) != your_shi){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 1C1a5/C4k3/4Pa2b/3n5/9/6P2/5c3/5A2B/9/2B1K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && PB90(MY_SQ16) == my_pawn){
			RETRUN_MUL(8);
		}
	}
	// fen 3a1k3/9/bPP1b2c1/9/9/9/5C3/6C2/5K3/6n2 r
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			Bitboard bp = m_and(bb_my_pawn,RankBB_A[MY_RANK2]);
			if(count_1s(bp) == 2){
				if(!have_bit(bp,RightBB[0x2]) && have_bit(bp,ei.attacked_by(your_pao))){
					if(StoX(ypao) > 0x4){
					    RETRUN_MUL(8);
					}
				}
				if(!have_bit(bp,LeftBB[0x6]) && have_bit(bp,ei.attacked_by(your_pao))){
					if(StoX(ypao) < 0x4){
					   RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3k5/9/4b4/3N5/2c1c1b2/C8/4pp3/4B4/4A4/2BAK4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){

		if(EV_MY_CAN <= 1){
			RETRUN_MUL(8);
		}

		if(!have_bit(MyUpBB[MY_RANK3],bb_my_pawn)){
			RETRUN_MUL(12);
		}
	}

	
}

//void m_MT_B_2pao2pawn_R_1ma1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_2PaoXPawn_1Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}