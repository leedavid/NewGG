#ifndef END_my_m_MT_R_1che1ma2pawn_B_1che1ma
#define END_my_m_MT_R_1che1ma2pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//我方1车1马2兵，对方1车1马
void my_m_MT_R_1che1ma2pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;

	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_CheMa_ByPawnByShi[your_shi_num]);

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);

	if(my_shi_num == 2 || my_xiang_num == 2){
		EV_MY_SAFE = true;
	}

	// fen 2ba1k3/4a4/4b4/9/9/2N5P/P1n2r3/3A2R2/4K4/3A5 w - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 32);
			if(StoY(mche) MY_LARGE_EQL MY_RANK5){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
		// fen 3ak1b2/9/4ba3/9/9/2P6/PN6R/9/4A1r1n/3A1K3 w - - 0 1
		if(IsOnSameSide(mche,yma)){
			MY_EV_ADD(32);
		}
	}
	else {
		if(my_shi_num >= 1 && MY_SQ04 == mk){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(StoY(mche) MY_LARGE_EQL MY_RANK5){
				MY_EV_ADD(EV_MY_CAN *16);
			}
		}
	}

	// fen 3ak4/4a4/4b4/3R5/6b2/8P/P4r3/4nN3/4A4/3AK4 b - - 0 1
	if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 16);
		if (MY_SQ44 == mma && PB90(MY_SQ56) != my_shi){
			MY_EV_ADD(32);
		}
		if (MY_SQ42 == mma && PB90(MY_SQ54) != my_shi){
			MY_EV_ADD(32);
		}
	}

	// fen 4ka3/4a4/4b4/R8/2r3bP1/P5N2/2n6/4B4/4A4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(64);
			if(StoY(mma) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(32);
			}
			if(StoY(yma) MY_LARGE_EQL MY_RANK4){
				MY_EV_SUB(32);
			}
			if(have_bit(bb_my_pawn,LeftBB[0x1])){
				MY_EV_SUB(32);
			}
			if(have_bit(bb_my_pawn,RightBB[0x7])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 2bak1b2/4a4/9/9/P8/9/3N4P/4B2r1/9/n2AKR3 w - - 0 1
	if(my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(!IsOnSameSide(yma,mk)){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(abs(StoX(yma) - 0x4) >= 3){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen 4ka3/4a4/6N2/8P/6b2/P8/3nr4/8R/4A4/3AK4 w - - 0 1
	if(!have_bit(bb_my_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
		if((your_shi_num + your_xiang_num) >= 3){
			if(StoY(yma) MY_LARGE_EQL MY_RANK5){
				if(my_xiang_num == 0){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4bn3/9/3r5/4P1B2/P8/9/7R1/3NKA3 b - - 0 1
	if((my_shi_num == 2 || my_xiang_num == 2) && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(32);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2bk5/4a4/3ab4/9/2rNP4/P5n2/9/4R4/4A4/4K4 b
	//
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
			if(my_xiang_num <= 1){
				MY_EV_SUB(32);
			}
		}
		if((my_shi_num + my_xiang_num) == 0 && StoY(yma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(32);
		}
	}

	// fen 4k4/3PaP3/4ba3/9/6b2/9/4n1N2/4R4/5K3/4r4 w - - 64 64

	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(32);
		}
		// 如果二个兵都在3线上面,也要减分
		// fen 4k1b2/R3a4/4ba3/PPN6/2n6/8r/9/5A3/4A4/2B1K1B2 b - - 0 126
		if(count_1s(MyLowBB[MY_RANK2],bmp) == 2){
			MY_EV_SUB(32);
		}
	}
	// fen 4kab2/4a4/4b4/4PP3/6n2/9/1r7/1N1R5/4A4/4KA3 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4kab2/4a4/4b4/9/9/P2R4P/4Pr3/4B4/2nN5/4KA3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3akab2/9/8b/3PP4/4r4/9/2n6/4N3R/4K4/5A3 b - - 0 137

	// fen r3ka3/4a4/4n4/9/2N6/3p5/9/B5R2/4A2p1/2B1KA3 b - - 0 68
	// b must good

	// fen 4k1b2/R3a4/4ba3/PPN6/2n6/8r/9/5A3/4A4/2B1K1B2 b - - 0 126

	// fen 2b1ka1n1/4a4/4b4/1N6R/9/6P2/P3P3P/9/4K4/3r5 w - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK2){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoY(mma) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 14);
		}
	}

	// fen 4kab2/9/4ba3/9/2r6/P8/2NR4P/3A5/3KA4/7n1 w - - 0 1
	if (EV_MY_SAFE) {
		MY_EV_ADD(64);
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	/// fen 2bak4/4a4/2n1b4/9/r8/4P4/2N3R1P/4B4/4A4/2BAK4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
				if(StoY(mma) MY_LARGE_EQL MY_RANK5){
					RETRUN_MUL(8);
				}
			}
			// fen 4kab2/4a4/4b2P1/9/4r4/2P1n1B2/1R7/2N1B4/4A4/4KA3 w - - 0 1
			if (EV_MY_CAN <= 1 && StoY(mma) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kab2/4a4/4b2P1/9/4r4/2P1n1B2/1R7/2N1B4/4A4/4KA3 w - - 0 1


}
//
//void m_MT_B_1che1ma2pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_CheMaPawn_CheMa_ByPawnByShi[board->R_shi];
//		}
//
//	}
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//		//
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(StoY(bpawn1) <= 0x7 && StoY(bpawn2) <= 0x7) {
//			if(board->B_xiang <= 1) board->mulScore += 64;
//		}
//	}
//
//
//	*/
//}

//这个要换车

// fen 9/3k5/3r1a3/3R5/4nN3/9/5p3/3AB2p1/4A4/4K1B2 w - - 57 57

