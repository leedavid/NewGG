#ifndef END_my_m_MT_R_2ma2pawn_B_2ma1pawn
#define END_my_m_MT_R_2ma2pawn_B_2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马2兵对2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma2pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2Ma1Pawn_2MaXPawn_ByPawn[my_shi_num]);
	
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 1){
			EV_MY_SAFE = TRUE;
		}
	}
	if((my_shi_num + my_xiang_num) >= 3 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
		EV_MY_SAFE = TRUE;
	}

	if(my_shi_num == 2){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK7 && !IsOnSameSide(ypawn,mk) 
			&& abs(StoX(ypawn) - StoX(mk)) >= 2){
			EV_MY_SAFE = TRUE;
		}
	}


	if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		MY_EV_ADD(96);
	}

	MY_EV_ADD(EV_MY_CAN * 16);

	// fen 5k3/4a1P2/b2ab1nN1/5N3/9/2B6/3n5/4BA3/2ppA4/4K4 w - - 120 120
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			Bitboard bb = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(count_1s(bb) == 2){
				Bitboard b2 = m_and(bb,LeftBB[0x4]);
				if(count_1s(b2) == 2){
					RETRUN_MUL(4);
				}
				b2 = m_and(bb,RightBB[0x4]);
				if(count_1s(b2) == 2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2bk1a3/4a1P2/9/9/pNn1n4/9/P8/B3B4/3NA4/3A1K3 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(EV_YOUR_CAN == 0){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2bk1a3/4a1P2/9/9/pNn1n4/9/P8/B3B4/3NA4/3A1K3 w - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1){
			if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
					Bitboard gp = m_and(bb_my_pawn,MyUpBB[MY_RANK4]);
					if(m_have_bit(gp)){
						Square p = pop_1st_bit_sq(gp);
						if(abs(StoX(p) - StoX(yk)) >= 2){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}


	// fen 2b2k3/2P1a4/4ba3/9/9/6P2/9/2n1Nn2B/2N1p4/3K5 w - - 0 1
	if(my_xiang_num >= 1 && my_shi_num == 0 && (your_shi_num + your_xiang_num) >= 3){
		if(StoY(mk) == MY_RANK9 && PB90(MY_SQ4C) == your_pawn && PB90(MY_SQ43) == my_ma){
			if(MY_SQ54 == mk && PB90(MY_SQ4A) == my_ma){
				RETRUN_MUL(6);
			}
			if(MY_SQ56 == mk && PB90(MY_SQ4E) == my_ma){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 6b2/3ka4/4ba3/9/6nNp/2B6/4P1N1P/3ABA1n1/9/5K3 w - - 120 120'
	//
	if((my_shi_num + my_xiang_num) >= 2 && (your_shi_num + your_xiang_num) >= 2){
		if(PB90(MY_SQ3A) == my_pawn){
			if(PB90(MY_SQ3C) == my_ma && PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2C) == your_pawn){
				if(PB90(MY_SQ2B) == my_ma && PB90(MY_SQ2A) == your_ma && PB90(MY_SQ46) == your_ma){
					RETRUN_MUL(8);
				}
			}
			if(PB90(MY_SQ38) == my_ma && PB90(MY_SQ36) == my_pawn && PB90(MY_SQ24) == your_pawn){
				if(PB90(MY_SQ25) == my_ma && PB90(MY_SQ26) == your_ma && PB90(MY_SQ40) == your_ma){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2b2k3/2P1a4/4ba3/9/9/6P2/9/2n1Nn2B/2N1p4/3K5 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1){
		if(!have_bit(bb_my_ma,MyUpBB[MY_RANK5])){
			RETRUN_MUL(8);
		}
	}

	// fen 3a1kb2/3Pa4/6n2/9/N5n1p/9/6N1P/4B4/4A4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && EV_MY_CAN <= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(64);
		Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if((have_bit(ghp,LeftBB[0x4]) && PB90(MY_SQ05) != your_shi)
			|| (have_bit(ghp,RightBB[0x4]) && PB90(MY_SQ03) != your_shi)){
				if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2A) == your_ma && PB90(MY_SQ2C) == your_pawn){
					RETRUN_MUL(8);
				}
				if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ26) == your_ma && PB90(MY_SQ24) == your_pawn){
					RETRUN_MUL(8);
				}
		}
	}

	// fen 2b1ka3/4a4/4b4/8N/pn7/4P4/3n4P/4N4/9/2BAKAB2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				if(EV_MY_CAN <= 1){
					RETRUN_MUL(8);
				}
				RETRUN_MUL(12);
			}
		}
	}

	// fen 4k4/2P1aP3/3a5/9/2n1Nnb2/9/5N3/4B4/3KAp3/5A3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			// 对方的将能走动
			if(PB90(MY_SQ0D) != my_pawn){
				if(m_have_bit(_mm_andnot_si128(MY_ATTACK,ei.attacked_by(your_king)))){
					RETRUN_MUL(12);
				}
			}
		}
	}

	// fen 9/1P2k4/2Naba2b/2n5p/9/8P/4P1nN1/3ABA3/9/2B1K4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 
			&& EV_MY_CAN <= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				int malr = My_pawn_already_over_river(POSITION);
				if(malr <= 1){
					MY_EV_SUB(32);
					if(count_1s(m_or(bb_my_pawn,bb_my_ma),MyUpBB[MY_RANK4]) <= 2){
						RETRUN_MUL(12);
					}
				}
		}
	}

}

//void m_MT_B_2ma2pawn_R_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Ma1Pawn_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	//Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_2Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	// fen 5k3/4a1P2/b2ab1nN1/5N3/9/2B6/3n5/4BA3/2ppA4/4K4 w - - 120 120
//	if(StoY(bk) == 0x3 && board->B_shi == 2 && board->B_xiang == 2){
//		board->bsafe = TRUE;
//	}
//
//	//
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(StoY(bpawn1) >= 0xb && StoY(bpawn2) >= 0xb 
//			&& IsOnSameSide(bpawn1,bpawn2)){
//				if(board->bsafe == TRUE){
//					return 8;
//				}
//		}
//	}
//
//	// fen 6b2/3ka4/4ba3/9/6nNp/2B6/4P1N1P/3ABA1n1/9/5K3 w - - 120 120
//	if((board->R_shi + board->R_xiang) >= 2 && (board->B_shi + board->B_xiang) >= 2){
//		if(board->b256[0x67] == BPAWN){
//			if(board->b256[0x69] == BMA && board->b256[0x6b] == BPAWN && board->b256[0x8b] == RPAWN){
//				if(board->b256[0x8a] == BMA && board->b256[0x89] == RMA && board->b256[0x5a] == RMA){
//					return 8;
//				}				
//			}
//			if(board->b256[0x65] == BMA && board->b256[0x63] == BPAWN && board->b256[0x83] == RPAWN){
//				if(board->b256[0x84] == BMA && board->b256[0x85] == RMA && board->b256[0x54] == RMA){
//					return 8;
//				}				
//			}
//		}
//	}
//
//	//// fen 6b2/3ka4/4ba3/9/6nNp/2B6/4P1N1P/3ABA1n1/9/5K3 w - - 120 120
//	//if((board->R_shi + board->R_xiang) >= 2 && (board->B_shi + board->B_xiang) >= 2){
//	//	if(board->b256[0x97] == RPAWN){
//	//		if(board->b256[0x99] == RMA && board->b256[0x9b] == RPAWN && board->b256[0x7b] == BPAWN){
//	//			if(board->b256[0x7a] == RMA && board->b256[0x79] == BMA && board->b256[0xaa] == BMA){
//	//				return 8;
//	//			}				
//	//		}
//	//		if(board->b256[0x95] == RMA && board->b256[0x93] == RPAWN && board->b256[0x73] == BPAWN){
//	//			if(board->b256[0x74] == RMA && board->b256[0x75] == BMA && board->b256[0xa4] == BMA){
//	//				return 8;
//	//			}				
//	//		}
//	//	}
//	//}
//
//	*/
//
//}
