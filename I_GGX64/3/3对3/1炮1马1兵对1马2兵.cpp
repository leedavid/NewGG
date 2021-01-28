#ifndef END_my_m_MT_R_1pao1ma1pawn_B_1ma2pawn
#define END_my_m_MT_R_1pao1ma1pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马1兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma1pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_1ma2pawn);

	Square mpawn  = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn1 = S90_from_piecelist(POSITION,your_pawn,0);
	Square ypawn2 = S90_from_piecelist(POSITION,your_pawn,1);
	Square yma    = S90_from_piecelist(POSITION,your_ma,0);

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	// fen 2bk5/4a4/2n1ba3/2CNp4/9/4P1B2/3p5/9/4A4/4KAB2 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan == 0){
		   MY_EV_SUB(ycan * 80);
		}
	}

	// fen 4k4/1N2aP3/4ba3/9/4Cn3/6B2/3pp4/9/4A4/3K5 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if ((StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,LeftBB[0x4]))
				|| (StoX(mpawn) < 0x4 && !have_bit(bb_your_shi, RightBB[0x4]))){
				MY_EV_SUB(32);
				if (count_1s(bb_your_pawn, RankBB_A[MY_RANK6]) == 2){
					MY_EV_SUB(64);
					if (abs(StoY(yma) - MY_RANK4) <= 2){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}

	// fen 4k4/5C3/4b1P2/9/2bN5/9/3n5/4pp3/9/3A1K3 b - - 0 1
    //对方二个兵在进攻，我方的马炮在外面，且我方的兵还没有进入攻击状态
	if(my_shi_num <= 1 && EV_YOUR_CAN == 2 && StoY(mk) == MY_RANK9){
		if(abs(StoX(mpawn) - 0x4) >= 2){
			if(abs(StoX(ypawn1) - StoX(mk)) <= 1 && abs(StoX(ypawn2) - StoX(mk)) <= 1){
				if(StoY(ypawn1) MY_LARGE_EQL MY_RANK7 && StoY(ypawn2) MY_LARGE_EQL MY_RANK7){
					if(StoY(yma) MY_LARGE_EQL MY_RANK5){
						MY_EV_SUB(96);
					}
				}
			}
		}
	}

	// fen 5k3/4a2P1/bN1a4n/5C3/6b2/9/4pp3/9/4A4/3A1K3 b
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		Bitboard lp = Your_get_connect_Pawn(POSITION);
		if(bit_is_set(lp,MY_SQ3A)){
			MY_EV_SUB(96);
			if(abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(12);
			}
		}
	}
}

//void m_MT_B_1pao1ma1pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1pao1maXpawn_To_1ma2pawn_ByPs[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1pao1maXpawn_To_1ma2pawn_ByPs[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_1pao1maXpawn_To_1ma2pawn;
//
//
//	int rcan = RpawnCanOverLiver(board);
//    int bcan = BpawnCanOverLiver(board);
//
//	// fen 2bk5/4a4/2n1ba3/2CNp4/9/4P1B2/3p5/9/4A4/4KAB2 w - - 0 0
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(bcan == 0){
//			board->mulScore += rcan * 64;
//			return 8;
//		}
//	}
//
//	*/
//}