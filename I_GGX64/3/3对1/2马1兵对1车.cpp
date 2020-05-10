#ifndef END_my_m_MT_R_2ma_1pawn_B_1che
#define END_my_m_MT_R_2ma_1pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2ma_1pawn_B_1che(typePOS &POSITION, EvalInfo &ei){	

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	int mcan  = EV_MY_CAN;
	Square yk    = your_king_pos;
	Square mk    = my_king_pos;
	// fen 3a5/4a3P/3kb3b/3N5/5N3/6B2/9/4BA3/4AK3/7r1 b - - 125 125
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(mpawn) MY_SMALL StoY(yk)){
			EV_YOUR_SAFE = TRUE;
		}
	}
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}

   // fen 9/3k5/9/3n5/4R4/2B1n4/9/5A3/3p5/3A1K3 b - - 12 12
   if((my_shi_num + my_xiang_num) <= 1){
	   if(your_shi_num >= 1){
		   EV_YOUR_SAFE = TRUE;
	   }
   }   
   //如果二马成连环了,也可能是和棋
   if(StoY(mpawn) MY_SMALL_EQL MY_RANK5 && StoY(mpawn) MY_LARGE MY_RANK0){
	   if(PB90(MY_SQ28) == my_ma){
		   if(PB90(MY_SQ39) == my_ma || PB90(MY_SQ3B) == my_ma){
			  EV_MY_SAFE = TRUE;
		   }
		   if(PB90(MY_SQ1D) == my_ma && my_shi_num >= 1){
			   EV_MY_SAFE = TRUE;
		   }
		   if(PB90(MY_SQ21) == my_ma && my_shi_num >= 1){
			   EV_MY_SAFE = TRUE;
		   }
	   }
   }  

	// fen 3k5/9/3a5/9/9/4n4/2n1R4/B8/1p2A4/4KA3 b
	// fen 2bak4/4a4/4b1n2/3R5/4n1p2/9/9/4BA3/9/3AK1B2 w - - 23 23
   if(your_shi_num == 2 && your_xiang_num == 2){
	   EV_YOUR_SAFE = TRUE;
   }
	// fen 3a1kb2/4a4/4b4/2P4N1/4N4/2Br5/9/4BA3/9/4KA3 w - - 8 4

  
	// fen 9/3k5/3aba3/9/6b1P/6N2/2r6/7N1/9/3AKA3 b - - 0 0


	// fen 2bak4/4a4/9/9/2p3b2/4n4/2n1R4/B8/5K3/9 b - - 108 108
    if(your_xiang_num != 0){
		if(mcan == 0){
			Square yche = S90_from_piecelist(POSITION,your_che,0);
			Bitboard ceat = POSITION.Rook_attacks_bb(yche);
			if(count_1s(ceat,bb_my_ma) == 2){
				MY_EV_SUB(128);
				EV_YOUR_SAFE = TRUE;
			}
		}
	}

	// fen 3a2b2/4k4/9/6NP1/4N1b2/7r1/9/9/9/4K4 w - - 0 1
	if(EV_YOUR_SAFE){
		if(PB90(MY_SQ28) == my_ma && StoY(mpawn) == MY_RANK3){
			if(PB90(MY_SQ21) == my_ma && StoX(mpawn) >= 0x7){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ1D) == my_ma && StoX(mpawn) <= 0x1){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a4/4Pa3/2rN5/3N5/9/9/4B4/9/2B1K4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ16) == my_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k5/4a2P1/9/6r2/6b2/4N1N2/9/3AB4/9/3AK1B2 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}



	// fen 1Nb1ka3/1r7/2Na5/9/1P7/6B2/9/3AB4/9/3AK4 w - - 0 1
	if(EV_MY_SAFE){
		// 压死一个马?
		if(your_shi_num == 2 && your_xiang_num >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 2b6/9/b4k3/9/9/4n4/2n5R/9/1p2A4/2BK5 w - - 0 1    
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		MY_EV_SUB(32);
		if(abs(StoX(mpawn) - StoX(yk)) >= 2 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(32);
		}
	}	

	// fen 4k1b2/4a4/4ba3/2PN5/9/9/4N4/9/1r7/3K5 b - - 0 1
	if(EV_YOUR_SAFE){
		if(StoY(mpawn) == MY_RANK3){
			MY_EV_ADD(96);
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK3]) 
				&& !have_bit(bb_my_ma,MyLowBB[MY_RANK6])){
					RETRUN_MUL(8);
			}
		}
	}

	
}

//void m_MT_B_2ma_1pawn_R_1che(typePOS &POSITION, EvalInfo &ei){	
///*
// 
//
//	Square bpawn = PieceListStart(board,BPAWN);	
//	Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	int bma1  = PieceListStart(board,BMA);
//	int bma2  = NextPiece(board,bma1);
//
//	int rche  = PieceListStart(board,RCHE);
//
//	int bcan  = BpawnCanOverLiver(board);
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(bpawn) > StoY(rk)){
//			board->rsafe = TRUE;
//		}
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){
//		if(StoY(bk) <= 0x4){
//			board->bsafe = TRUE;
//		}
//	}
//
//	// fen 9/3k5/9/3n5/4R4/2B1n4/9/5A3/3p5/3A1K3 b - - 12 12
//    //
//	if((board->B_shi + board->B_xiang) <= 1){
//		if(board->R_shi >= 1){
//			board->rsafe = TRUE;
//		}
//	}
//
//	//如果二马成连环了,也可能是和棋
//	if(StoY(bpawn) > 0x7 && StoY(bpawn) < 0xc){
//		if(board->b256[0x87] == BMA){
//			//if(StoX(bk) <= 0x7 && StoX(bpawn) <= 0x7){
//				if(board->b256[0x66] == BMA){
//					board->bsafe = TRUE;
//				}
//				if(board->b256[0x95] == BMA){
//					if(board->B_shi != 0){
//						board->bsafe = TRUE;
//					}
//				}
//			//}
//			//if(StoX(bk) >= 0x7 && StoX(bpawn) >= 0x7){
//				if(board->b256[0x68] == BMA){
//					board->bsafe = TRUE;
//				}
//				if(board->b256[0x99] == BMA){
//					if(board->B_shi != 0){
//						board->bsafe = TRUE;
//					}
//				}
//			//}
//		}
//	}
//
//	// fen 3k5/9/3a5/9/9/4n4/2n1R4/B8/1p2A4/4KA3 b
//	//if(StoY(bpawn) > 0x7 && StoY(bpawn) < 0xc){
//	//	if(board->b256[0x
//	//}
//
//
//	// fen 2bak4/4a4/4b1n2/3R5/4n1p2/9/9/4BA3/9/3AK1B2 w - - 23 23
//	if(board->B_shi == 2 || board->B_xiang == 2 && StoY(bk) == 0x3){
//		board->bsafe = TRUE;
//	}
//	if(board->R_shi == 2 && board->R_xiang == 2){		
//		board->rsafe = TRUE;
//	}	
//
//	// fen 3a1kb2/4a4/4b4/2P4N1/4N4/2Br5/9/4BA3/9/4KA3 w - - 8 4
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		return 4;
//	}
//
//	// fen 9/3k5/3aba3/9/6b1P/6N2/2r6/7N1/9/3AKA3 b - - 0 0
//	if(board->B_shi == 2 && StoY(bk) <= 0x4){
//		if(board->rsafe == TRUE){
//			return 4;
//		}
//	}
//
//	// fen 2bak4/4a4/9/9/2p3b2/4n4/2n1R4/B8/5K3/9 b - - 108 108
//	if(board->R_xiang != 0){
//		if(OneCheControlTwoMa(rche,bma1,bma2)){
//			if(board->b256[0x75] == BPAWN){
//				if(board->b256[0xa3] == RXIANG || board->b256[0xa7] == RXIANG){
//					return 4;
//				}
//			}
//			if(board->b256[0x79] == BPAWN){
//				if(board->b256[0xab] == RXIANG || board->b256[0xa7] == RXIANG){
//					return 4;
//				}
//			}
//		}
//	}
//
//
//
//
//
//	*/
//}

