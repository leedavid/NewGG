#ifndef END_my_m_MT_R_1pao2pawn_B_1ma2pawn
#define END_my_m_MT_R_1pao2pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// fen 4kab2/2n6/3ab4/P1p5p/3P3C1/9/9/4B4/4A4/4KAB2 w - - 0 0 这个要调整一下分数

void my_m_MT_R_1pao2pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){	

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_1MaXPawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_1MaXPawn_ByShi[my_shi_num]);

	// fen 3a1k3/9/4P4/1N7/9/5cB2/9/3A5/2p1A1p2/5K3 w - - 59 59
	if(my_shi_num <= 1 && my_xiang_num == 0){
		if(PB90(MY_SQ43) == your_pawn){
			MY_EV_SUB(64);
		}
	}

	// fen 2ba1k3/4a4/1N4P2/3P5/p3p1b1c/9/9/5A3/4A4/2B1K4 b - - 0 1
	if ((your_shi_num + your_xiang_num) <= 3){
		if ((my_shi_num + my_xiang_num) == 4){
			if (EV_MY_CAN == 2){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 4kab2/4aP3/9/6n2/8p/1p7/8P/9/4A4/3A1K2C w - - 0 1
	if(EV_MY_CAN <= 1 && EV_YOUR_CAN >= 1){
		if((my_shi_num + my_xiang_num) <= 2){
			MY_EV_SUB(32);
		}		
	}

	// fen 5Cb2/4k1PP1/8b/6n2/9/6B2/2p6/4B4/3pA4/4KA3 w - - 0 1
	if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(StoY(yk) MY_LARGE_EQL MY_RANK1){
			MY_EV_SUB(EV_YOUR_CAN * 32);
		}
	}

	// fen 6P2/4a1P2/5k3/9/8n/C5B2/9/3ABA3/3p2p2/5K3 w - - 0 1
	if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		MY_EV_SUB(32);
		MY_EV_SUB(EV_YOUR_CAN * 16);
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			MY_EV_SUB(EV_YOUR_CAN * 16);
		}
	}

	if(EV_YOUR_CAN <= 1 && my_shi_num == 2 && my_xiang_num >= 1){
		EV_MY_SAFE = true;
	}

	if(EV_YOUR_CAN == 0 && my_shi_num == 2){
		EV_MY_SAFE = true;
	}

	if(have_bit(bb_my_pawn,LeftBB[0x4]) && have_bit(bb_my_pawn,RightBB[0x4])){
		MY_EV_ADD(32);
	}

	// fen 4ka3/4aP3/7Pb/9/3C2b2/4p4/2pn5/9/4A4/3AK1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			if(!have_bit(bb_my_pawn,LeftBB[0x4]) || !have_bit(bb_my_pawn,RightBB[0x4])){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 2bak4/4a4/9/2P2N3/5P2p/9/8p/9/3KA4/5A1c1 w - - 0 1
	//if(my_shi_num == 2 && EV_MY_CAN >= 2){
	//	if(your_xiang_num == 0){
	//		MY_EV_ADD(64);
	//	}
	//}

	//MY_EV_SUB(16);
	// fen 3ak1b2/4a4/4b4/2P1P4/3N5/p7p/c8/4B4/4A4/4KAB2 w - - 0 1
	//if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
	//	MY_EV_ADD(EV_MY_CAN * 32);
	//}

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	Square ypawn1 = S90_from_piecelist(POSITION,your_pawn,0);
	Square ypawn2 = S90_from_piecelist(POSITION,your_pawn,1);

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	int ycan = EV_YOUR_CAN;
	// fen 2b2k3/4a4/8b/2P3C2/7P1/6p1n/6p2/9/4A4/3AK4 w - - 2 2
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(my_xiang_num == 0){
			if(ycan == 2){
				if(StoY(mpawn1) MY_LARGE_EQL MY_RANK4 || StoY(mpawn2) MY_LARGE_EQL MY_RANK4){
					MY_EV_SUB(96);
				}
			}
		}
	}

	// fen 6b2/5P3/b2k4c/7Np/9/8P/5p3/B3K4/4A4/5A3 b - - 122 122
	if(EV_MY_CAN <= 1 && (your_shi_num + your_xiang_num) >= 3 && my_shi_num <= 1){
		EV_YOUR_SAFE = true;
	}

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	// fen 2bak4/9/3ab4/C3P4/p5p2/9/4n3P/9/4A4/3A1K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK7])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a1k3/1cN1a1P2/4P4/9/9/2B3B2/4pp3/3A5/4A4/5K3 b - - 140 140
    //如果红方二个兵都走死了，要减分
	if(my_shi_num == 2 ){

		if(PB90(MY_SQ43) == your_pawn && StoX(mk) != 0x4){
			Square op = ypawn1;
			if(op == MY_SQ43){
				op = ypawn2;
			}
			if(StoY(op) MY_LARGE_EQL MY_RANK8){
				if(isStringByPao(POSITION,mpao,Square(MY_SQ4C),op)){
					MY_EV_ADD(196);
				}
			}
		}
		if(your_shi_num == 2 && your_xiang_num >= 1 && my_xiang_num >= 1){			
			RETRUN_MUL(8);
		}
	}

	

	// fen 3a5/4a4/4k3b/3P5/p8/9/Pn7/C4K2B/3p5/2B6 w - - 0 1
	if(EV_YOUR_SAFE){
		if(StoY(ypawn1) MY_LARGE_EQL StoY(mk) || StoY(ypawn2) MY_LARGE_EQL StoY(mk)){
			if(EV_YOUR_CAN <= 1 && my_xiang_num >= 1){
				if(StoY(mpawn1) == MY_RANK3 || StoY(mpawn2) == MY_RANK3){
			     	RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2b1c4/3k5/3ab4/5NP2/2p6/4P4/9/B2AB4/2p6/3A1K3 b - - 0 1
	if(my_shi_num >= 1 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(EV_MY_CAN <= 1 && (your_shi_num + your_xiang_num) >= 2){
			if(PB90(MY_SQ28) == your_pawn && bit_is_set(ei.attacked_by(my_pao),MY_SQ28)){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ1F) == your_pawn && bit_is_set(ei.attacked_by(my_pao),MY_SQ1F)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k5/9/3ab4/p2N5/8p/P8/8P/4K4/4A4/c1B2A3 w - - 0 1
    if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(your_shi_num >= 1 && your_xiang_num >= 1){
			if(EV_MY_CAN == 0 && EV_YOUR_CAN == 0){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4P4/1P7/3kba3/9/6b2/5CB2/9/3ABK1n1/2p6/1p7 w - - 0 1
	if(EV_YOUR_SAFE){
		if((my_shi_num + my_xiang_num) >= 3){
			if(!have_bit(MyUpBB[StoY(mk)],bb_your_pawn)){
				if(have_bit(bb_your_pawn,RankBB_A[MY_RANK9])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 5k3/4a1PP1/3a5/9/9/3n2B2/4p4/6p2/2C1A4/4KA3 b - - 0 1
	if(your_shi_num == 2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(!have_bit(bb_my_pawn,LeftBB[0x6]) || !have_bit(bb_my_pawn,RightBB[0x2])){
			if(my_shi_num == 2 && have_bit(bb_your_pawn,RankBB_A[MY_RANK6]) && my_xiang_num >= 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/5k3/9/p3p4/3n5/9/P7P/4C3B/3KA4/5A3 w - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1 && EV_YOUR_CAN >= 1){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				if(!bit_is_set(EV_MY_XBIT,yma)){
				    RETRUN_MUL(8);
				}
			}
		}
	}

}

//void m_MT_B_1pao2pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){	
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square rpawn1 = PieceListStart(board,RPAWN);
//	Square rpawn2 = NextPiece(board,rpawn1);
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	int bpao   = PieceListStart(board,BPAO);
//	int rma    = PieceListStart(board,RMA);
//
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1PaoXPawn_1MaXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1PaoXPawn_1MaXPawn_ByShi[board->R_shi];
//		}
//	}
//
//	// fen 3a1k3/9/4P4/1N7/9/5cB2/9/3A5/2p1A1p2/5K3 w - - 59 59
//	if(board->B_shi <= 1 && board->B_xiang == 0){
//		if(board->b256[0x57] == RPAWN){
//			board->mulScore += 128;
//		}
//	}
//
//	// fen 2b2k3/4a4/8b/2P3C2/7P1/6p1n/6p2/9/4A4/3AK4 w - - 2 2
//	if(board->R_shi >= 1 && board->R_xiang == 2){
//		if(board->B_xiang == 0){
//			if(StoY(rpawn1) > StoY(bk) && StoY(rpawn2) > StoY(bk)){
//				if(StoY(bpawn1) <= 0x8 || StoY(bpawn2) <= 0x8){
//			       board->mulScore += 80;
//				}
//			}
//		}
//	}
//
//	// fen 3a1k3/1cN1a1P2/4P4/9/9/2B3B2/4pp3/3A5/4A4/5K3 b - - 140 140
//    //如果红方二个兵都走死了，要减分
//	if(board->B_shi == 2){
//		if(board->b256[0x57] == RPAWN && StoX(bk) != 0x7){
//			int op = rpawn1;
//			if(op == 0x57) op = rpawn2;
//			if(StoY(op) <= 0x4 && StoY(bpao) == 0x4){
//				if(FALSE){
//				}
//				else if(StoX(op) >= 0x9 && StoX(bpao) < StoX(rma)){
//					if(rma == 0x45){
//						board->mulScore -= Ma2PawnIsString;
//					}
//				}
//				else if(StoX(op) <= 0x5 && StoX(bpao) > StoX(rma)){
//					if(rma == 0x49){
//						board->mulScore -= Ma2PawnIsString;
//					}
//				}
//			}
//		}
//
//		if(board->R_shi == 2 && board->R_xiang >= 1){
//			return 8;
//		}
//	}
//
//
//
//	*/
//}