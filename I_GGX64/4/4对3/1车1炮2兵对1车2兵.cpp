#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che2pawn
#define END_my_m_MT_R_1che1pao2pawn_B_1che2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮2兵对1车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1pao2pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[my_shi_num]);

	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);

	//
	int ycan = EV_YOUR_CAN;
	if(ycan <= 1){
		if(my_shi_num == 2){
			EV_MY_SAFE = TRUE;
		}
		if(my_shi_num >= 1 && my_xiang_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}
	int mcan = EV_MY_CAN;

	// fen 2bak4/4a4/9/3C4p/9/2B1R1P2/P8/3p5/7r1/4K4 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num <= 1){
		if (EV_YOUR_CAN >= 2 && (your_shi_num+your_xiang_num) >= 2){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK4])){
				if (have_bit(ymp, MyLowBB[MY_RANK6])){
					MY_EV_SUB(32);
					if (StoY(yche) MY_LARGE_EQL MY_RANK5){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}

	// fen 1C3R3/4k4/b3b4/9/1r7/2B1p1P2/8P/3p5/5K3/6B2 w - - 0 1
	if (my_shi_num == 0) {
		Bitboard yghp = m_and(bb_your_pawn, MyLowBB[MY_RANK4]);
		MY_EV_SUB(count_1s(yghp) * 64);

		Bitboard mghp = m_and(bb_my_pawn, MyUpBB[MY_RANK5]);
		if (count_1s(mghp) <= 0) {
			MY_EV_SUB(32);
			if (StoY(mpao) MY_SMALL_EQL MY_RANK4) {
				MY_EV_SUB(32);
			}
		}
	}
	


	// fen 3ak1b2/4a4/9/7rp/3P2bC1/7RP/9/4BA3/4Ap3/2B1K4 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (EV_MY_CAN <= 1){
			MY_EV_SUB(64);
		}
		if (isStringByChe(POSITION, mche, mpao, yche)){
			MY_EV_SUB(64);
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK4])){
				MY_EV_SUB(32);
			}
		}
	}


	// fen 3a1kb2/4a4/4b4/4R4/p3Cr3/4p1P2/P8/B8/3KA4/5AB2 w - - 123 123
	if(mcan == 0 && My_pawn_already_over_river(POSITION) == 0){
		if((your_xiang_num + your_shi_num) == 4 && StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ31) == your_pawn && PB90(MY_SQ28) == my_pao && PB90(MY_SQ1F) == my_che){
				if(PB90(MY_SQ27) == your_che || PB90(MY_SQ29) == your_che){
					RETRUN_MUL(4);
				}
			}
		}
	} 

	// fen 3k1ab2/4a4/4b4/p8/9/P7p/4P4/8B/4K2C1/3r2BR1 b - - 1 1
	MY_EV_ADD(32); 

	// fen 3akab2/9/C8/7Rp/p8/2P6/8P/9/3K5/4r4 b - - 0 1
    // 如果对方的兵都没有过河，要减分
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
		MY_EV_ADD(64);
		MY_EV_ADD(EV_MY_CAN * 32);
	}
}

//void m_MT_B_1che1pao2pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
//
///*
//
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square rpawn1 = PieceListStart(board,RPAWN);
//	Square rpawn2 = NextPiece(board,rpawn1);
//
//    int rche = PieceListStart(board,RCHE);
//	int bpao = PieceListStart(board,BPAO);
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	if(rcan <= 1){
//		if(board->B_shi >= 1 && board->B_xiang >= 1){
//			board->bsafe = TRUE;
//		}
//	}
//
//	// fen 3a1kb2/4a4/4b4/4R4/p3Cr3/4p1P2/P8/B8/3KA4/5AB2 w - - 123 123
//    if(bcan == 0 && BpawnAlreadyRiver(board) == 0){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc && StoY(rche) == StoY(bpao)){
//			if(board->b256[0x97] == BCHE && board->b256[0x87] == BPAO && board->b256[0x77] == RPAWN){
//				if(rpawn1 != 0x77){
//					if(board->b256[rpawn1-0x20] == BPAWN || board->b256[rpawn1-0x30] == BPAWN){
//						return 1;
//					}
//				}
//				if(rpawn2 != 0x77){
//					if(board->b256[rpawn2-0x20] == BPAWN || board->b256[rpawn2-0x30] == BPAWN){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//	board->mulScore -= 64;
//
//
//	*/
//}