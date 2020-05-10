#ifndef END_my_m_MT_R_1che1ma_B_1che1pawn
#define END_my_m_MT_R_1che1ma_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//const PanwAdd = 32;

void my_m_MT_R_1che1ma_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){


	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePawn_To_CheMa_By_PawnByShi[my_shi_num]);

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);

	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(64);
		if (StoY(yche) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(32);
			EV_YOUR_SAFE = true;
		}
		// fen 3ak1b2/4a4/3r5/3N1R3/9/p8/9/4B4/9/4K1B2 w - - 0 1
		if (my_shi_num == 0 && EV_YOUR_CAN >= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 4k4/9/5R3/9/9/2P6/r8/2n1B4/9/3AKAB2 w - - 0 1
	if (EV_YOUR_SAFE){
		if (my_shi_num == 0 && EV_YOUR_CAN >= 1 ){
			MY_EV_SUB(32);
			if (my_xiang_num <= 1){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3ak1b2/4a4/3r5/3N1R3/9/p8/9/4B4/9/4K1B2 w - - 0 1



	// fen 1R7/2rka4/5a3/9/2bN5/9/9/B7B/4A4/3AK2p1 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		//MY_EV_SUB(64);
		if(StoX(yk) < 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
			if(IsOnSameSide(yk,yche)){
				MY_EV_SUB(64);
			}
		}
		if(StoX(yk) > 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
			if(IsOnSameSide(yk,yche)){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3k1a3/2P1a4/b3b4/3r5/9/9/5R3/B3B4/7n1/4K4 b - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK6){
			MY_EV_SUB(64);
		}
		if(StoY(yche) MY_SMALL_EQL MY_RANK3){
			MY_EV_SUB(64);
		}
	}

	if(my_shi_num >= 1){
		EV_MY_SAFE = TRUE;
	}
	// fen 3P5/4k4/b2a1a3/9/1r2n4/9/9/B3R4/4A4/4KA3 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		EV_YOUR_SAFE = TRUE;
	}

	if(StoY(ypawn) MY_LARGE StoY(mk)){
		EV_MY_SAFE = TRUE;
	}
	//如果兵方一个子也没有了
	if((your_shi_num + your_xiang_num) <= 1){
		MY_EV_ADD(ADD_ChePawn_To_CheMa_Pawn_SX_LessOne);
	}


	//   fen 5k3/9/5r3/5N3/9/2B6/4p4/3A1R3/9/2B1KA3 b - - 0 1
	if (StoX(yche) == StoX(mche) && isStringByChe(POSITION, mche, mma, yche)) {
		MY_EV_SUB(64);
		if (StoX(yche) == StoX(yk) && StoY(yche) MY_LARGE StoY(yk)) {
			MY_EV_SUB(64);
			if (have_bit(bb_your_pawn, RankBB_A[MY_RANK6])
				|| have_bit(bb_your_pawn,RankBB_A[MY_RANK8])
				|| have_bit(bb_your_pawn, RankBB_A[MY_RANK7])) {
				MY_EV_SUB(32);

				if (EV_MY_SAFE) {
					RETRUN_MUL(2);
				}
			}
		}
	}


	
	if(EV_MY_SAFE){

		// fen 2bk1a3/4a4/4b4/2n2r3/9/6R2/8P/4B4/4A4/3AK4 r 
		if ((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}

		if(isStringByChe(POSITION,mche,mma,yche)){

			// fen R8/5k3/N8/9/r8/9/9/6p2/4A4/2BAK1B2 w - - 0 1
			if(StoY(mche) MY_SMALL_EQL MY_RANK1 && StoX(mche) == StoX(mma)){
				if(abs(StoX(mma) - 0x4) == 4 && abs(StoX(mma) - StoX(yk)) >= 5){
					RETRUN_MUL(2);
				}
			}
			// fen 9/4ak3/9/1r7/9/1N7/9/4B1p2/9/1RBAKA3 w - - 0 0
			if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(StoY(mche) MY_LARGE StoY(mma) && StoY(mma) MY_SMALL_EQL MY_RANK5){
					int ycan = EV_YOUR_CAN;
					if(ycan >= 1){
						RETRUN_MUL(2);
					}					
				}
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a5/3P1k3/4ba3/9/6b2/2B6/4R4/B8/3KAr3/6n2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	// fen 7R1/4ak3/4ba3/9/6r2/7N1/9/8B/3pA4/3AK1B2 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(yche) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a5/4a4/b3k4/3r5/2b6/N2p5/1R7/4B4/4A4/3AK1B2 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4){
			if(EV_YOUR_CAN && StoY(mma) MY_LARGE_EQL MY_RANK5 && StoY(yche) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}

	//  fen 5k3/9/5r3/5N3/9/2B6/4p4/3A1R3/9/2B1KA3 b - - 0 1

	if (StoX(yche) == StoX(mche) && isStringByChe(POSITION, mche, mma, yche)) {
		
		if (StoX(yche) == StoX(yk) && StoY(yche) MY_LARGE StoY(yk)) {
		
			if (have_bit(bb_your_pawn, RankBB_A[MY_RANK6]) || have_bit(bb_your_pawn, RankBB_A[MY_RANK8])
				|| have_bit(bb_your_pawn, RankBB_A[MY_RANK7])) {
				if (my_shi_num >= 1) {
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/9/5R3/9/9/2P6/r8/2n1B4/9/3AKAB2 w - - 0 1
	if (EV_YOUR_SAFE){
		if (StoY(ypawn)  MY_SMALL_EQL MY_RANK5){
			RETRUN_MUL(6);
		}
	}

	// fen 5k3/2N4R1/4b4/4r4/2b6/6B2/9/9/4A4/2B1KA2p b - - 0 1
	if(EV_MY_SAFE){
		if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(yche) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(6);
			}
		}
	}


	// fen 9/3k5/7P1/2r6/2n6/4R4/9/3AB4/4A4/4K1B2 w - - 0 1
	if(EV_YOUR_SAFE){
		if(abs(StoX(ypawn) - StoX(yk)) >= 3){
			RETRUN_MUL(6);
		}
	}

	// fen 3a5/4a4/b3k4/3r5/2b6/N2p5/1R7/4B4/4A4/3AK1B2 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4){
			if(EV_YOUR_CAN && StoY(yche) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1k4/4a4/4b4/9/9/3R5/2N6/4B4/2p1r4/3K5 b - - 0 1
    if(EV_YOUR_SAFE){
		if(my_shi_num == 0 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(ypawn) MY_LARGE_EQL MY_RANK8){
				if(PB90(MY_SQ43) == my_xiang){
					if(StoX(ypawn) <= 0x2 && PB90(MY_SQ38) == my_ma){
						RETRUN_MUL(8);
					}
					if(StoX(ypawn) >= 0x6 && PB90(MY_SQ3C) == my_ma){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 4k4/9/9/9/9/5R2P/4n3r/5A3/4A4/5KB2 w - - 0 0
	if(EV_YOUR_SAFE){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && my_xiang_num >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 5k3/3R5/4b4/2rN2p2/6b2/9/9/B4A3/4A4/2B1K4 r
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_SAFE){
			RETRUN_MUL(8);
		}
	}
	// fen 4R4/3ka4/3ab4/9/9/2N6/9/B2AK4/1r7/5p3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >=1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mk) == MY_RANK7 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			if(my_shi_num <= 1 && my_xiang_num <= 1){
				MY_EV_SUB(32);
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k5/4aP3/3ab4/3P5/9/3n1N3/9/3A1K3/2p1A4/9 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_YOUR_CAN && your_shi_num == 2){
			if(StoY(yk) == MY_RANK0){
				if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(8);
				}
			}
		}
	}

}

//void m_MT_B_1che1ma_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += ADD_ChePawn_To_CheMa_By_PawnByShi[board->B_shi];
//		}
//	}
//
//	
//    Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	Square rpawn = PieceListStart(board,RPAWN);
//	int bma   = PieceListStart(board,BMA);
//	int rche  = PieceListStart(board,RCHE);
//	int bche  = PieceListStart(board,BCHE);
//
//	//if(board->R_xiang == 2 && StoY(rk) != 0xa){
//	//	if(board->B_shi != 0){
//	//		board->mulScore = 0;
//	//	}
//
//	//	return 1;
//	//}
//
//	if(board->B_shi != 0 ){
//		board->bsafe = TRUE;
//	}
//	if((board->R_xiang + board->R_shi) >=  3 && StoY(rk) != 0xa){
//		board->rsafe = TRUE;
//	}
//
//	if(StoY(rpawn) < StoY(bk)){
//		board->bsafe = TRUE;
//	}
//
//	if((board->R_shi + board->R_xiang) >= 3){
//		if(StoY(rk) == 0xc){
//			board->rsafe = TRUE;
//		}
//	}
//
//	
//
//	// fen 3P5/4k4/b2a1a3/9/1r2n4/9/9/B3R4/4A4/4KA3 w - - 0 0
//	//if((board->R_shi + board->R_xiang) >= 3){
//	//	if(StoY(rk) == 0xc){
//	//		if(StoY(rpawn) < StoY(bk)){
//	//			board->mulScore = 0;
//	//			return 1;
//	//		}
//	//		if(board->B_shi != 0){
//	//			board->mulScore = 0;
//	//			return 1;
//	//		}
//	//	}
//	//}
//
//	//如果兵方一个子也没有了
//	if((board->R_shi + board->R_xiang)<= 1){
//		board->mulScore -= ADD_ChePawn_To_CheMa_Pawn_SX_LessOne ;
//	}
//
//	// fen 9/4ak3/9/1r7/9/1N7/9/4B1p2/9/1RBAKA3 w - - 0 0
//	if(board->bsafe == TRUE){
//		if(board->R_shi >= 1 && StoY(rk) >= 0xb){
//			if(StoY(bche) < StoY(bma) && StoY(bma) <= 0x7){
//				if(IsStringByChe(board,rche,bma,bche) && StoY(rpawn) <= 0x7 && StoY(rpawn) >= 0x4){
//					return 2;
//				}
//			}
//		}
//	}
//
//
//
//	*/
//}