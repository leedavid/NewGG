#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_2che
#define END_my_m_MT_R_1che1pao1ma1pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1Che1Pao1MaXPawn_2CheOnly[3]         = {96, 64, 32};   //1 
//const int  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe       =  96;

void my_m_MT_R_1che1pao1ma1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Che1Pao1MaXPawn_2CheOnly[your_shi_num]);

	Square mk = my_king_pos;
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);

	// fen 4k1b2/4a4/4ba3/1r7/2n6/p8/5R3/4BA3/9/1cRA1K3 w - - 0 1r_
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) >= 4){
			MY_EV_SUB(64);
		}
		if (StoY(mma) MY_LARGE_EQL MY_RANK6){
			MY_EV_SUB(32);
		}
	}

	// fen 4k1c2/4a4/3rbn3/4R4/6p2/R8/9/4B4/4A4/2BAK4 b - - 0 1
	if (my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if (StoY(mpao) == MY_RANK9 && abs(StoX(mpao) - 0x4) <= 2){
			MY_EV_ADD(32);
			if (MY_SQ42 == mma || MY_SQ44 == mma){
				MY_EV_ADD(32);
				if (StoY(mche) == MY_RANK7){
					MY_EV_ADD(32);
				}
			}
		}
	}

	// fen 4ka3/4a4/4b4/1Pr6/9/9/9/N3R4/1r2A4/1C1AK4 b - - 0 1
	if (my_shi_num == 2 && MY_SQ55 == mk){
		MY_EV_ADD(32);
		if (StoY(mpao) MY_LARGE_EQL MY_RANK7){
			MY_EV_ADD(32);
		}
	}

	// fen 3a2b2/5k3/5a3/7P1/6R2/P8/5r3/4CN3/4AK3/2BA4r w - - 0 1
	if(StoY(mk) != MY_RANK9 && !have_bit(bb_your_che,MyUpBB[MY_RANK4])){
		if(StoX(mk) == 0x5 && !have_bit(bb_your_che,LeftBB[0x4])){
			MY_EV_SUB(96);
		}
		if(StoX(mk) == 0x3 && !have_bit(bb_your_che,RightBB[0x4])){
			MY_EV_SUB(96);
		}
		if(StoY(mma) MY_LARGE_EQL MY_RANK7){
			MY_EV_SUB(32);
		}
	}

    if(my_shi_num == 2){
		if(MY_SQ55 == my_king && PB90(MY_SQ4C) == my_shi){
			Square sq = SQ_END90 ;
			if(PB90(MY_SQ54) == my_shi){
				sq = Square(MY_SQ56);
			}
			if(PB90(MY_SQ56) == my_shi){
				sq = Square(MY_SQ54);
			}
			if(sq != SQ_END90 ){
				Bitboard rook = POSITION.Rook_attacks_bb(sq);
				if(PB90(sq) != EMPTY){
					EV_MY_SAFE = TRUE;
				}
				if(m_have_bit(m_and(rook,
					m_or(bb_my_pao,
					bb_my_che)))){
					EV_MY_SAFE = TRUE;
				}				
			}
		}
	}



	if(EV_MY_SAFE){
		MY_EV_ADD(ADD_1Che1Pao1MaXPawn_2CheOnly_Safe);
	}

	// fen 3ak4/4a4/4b4/7r1/6bCP/6N2/8r/4B2R1/4A4/3AK1B2 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(96);
			if(EV_MY_SAFE){
				RETRUN_MUL(8);
			}
		}
		// fen N2a1kb2/4a2PR/4b4/6r2/9/6r2/9/B8/4A2C1/2B1KA3 w - - 0 91
		if(abs(StoX(mpawn) - 0x4) >= 3){
			if(EV_MY_SAFE){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/3Ra4/2n1kc3/4p2R1/4r4/9/9/9/4A4/4KA3 w - - 0 1
	if(my_shi_num >= 1 && PB90(MY_SQ3A) == my_pawn){
		if(MY_SQ43 == mk && StoY(mpao) == MY_RANK7){
			if(mma == MY_SQ45 || mma == MY_SQ41){
				if(!IsOnSameSide(mpao,mma) && (your_xiang_num + your_shi_num) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}
	// fen 4k1c2/4a4/3rbn3/4R4/6p2/R8/9/4B4/4A4/2BAK4 b - - 0 1
	if (my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if (StoY(mpao) == MY_RANK9){
			if (MY_SQ42 == mma || MY_SQ44 == mma){
				if (StoY(mche) == MY_RANK7){
					RETRUN_MUL(8);
				}
			}
		}
	}
	// fen 4kab2/4a4/4b4/9/9/r8/2P6/4N4/4A4/2C1KRBr1 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (my_shi_num >= 1 && my_xiang_num >= 1 && MY_SQ55 == mk){
			if (StoY(mpao) == MY_RANK9 && MY_SQ43 == mma){
				if (StoY(mche) MY_LARGE_EQL MY_RANK5){
					if (StoX(mpao) <= 0x3 && PB90(MY_SQ54) != my_shi){
						RETRUN_MUL(8);
					}
					if (StoX(mpao) >= 0x5 && PB90(MY_SQ56) != my_shi){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

}

//void m_MT_B_1che1pao1ma1pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
//
// /*
//	Square bk    = PieceListStart(board,BKING);
//	Square rk    = PieceListStart(board,RKING);
//
//	int bche  = PieceListStart(board,BCHE);
//	int bpao  = PieceListStart(board,BPAO);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1Che1Pao1MaXPawn_2CheOnly[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(StoY(bk) == 0x3){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if(board->B_shi == 2){
//		if(board->b256[0x37] == BKING && board->b256[0x47] == BSHI){
//			if(FALSE){
//			}
//		    else if(board->b256[0x36] == BSHI){
//				//车安全
//				if(IsCheCanToOrAt(board,bche,0x38)){
//					board->bsafe = TRUE;
//				}
//
//				//炮安全
//				if(IsCheCanToOrAt(board,bpao,0x38)){
//					board->bsafe = TRUE;
//				}
//			}
//			else if(board->b256[0x38] == BSHI){
//				//车安全
//				if(IsCheCanToOrAt(board,bche,0x36)){
//					board->bsafe = TRUE;
//				}
//
//				//炮安全
//				if(IsCheCanToOrAt(board,bpao,0x36)){
//					board->bsafe = TRUE;
//				}
//			}
//		}
//	}
//
//	if(board->bsafe){
//		board->mulScore -=  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe;
//	}
//
//		// fen 3ak1b2/4a4/4b4/7r1/4r4/2C3P2/P1R5P/2N1B4/4A4/2B1KA3 b - - 0 0
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < 0x8){
//				board->mulScore += ADD_1Che1Pao1MaXPawn_PawnNotOverRiver;
//			}
//		}
//	}
//
//
//	*/
//
//}

