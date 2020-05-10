#ifndef END_my_m_MT_R_1che1pao1ma3pawn_B_2che
#define END_my_m_MT_R_1che1pao1ma3pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马3兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1Che1Pao1MaXPawn_2CheOnly[3]         = {96, 64, 32};   //1 
//const int  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe       =  96;

void my_m_MT_R_1che1pao1ma3pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Che1Pao1MaXPawn_2CheOnly[your_shi_num]);

	int mcan = EV_MY_CAN;

	Square mk = my_king_pos;
	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	if(my_shi_num == 2 && my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2baka3/9/8P/4C4/9/9/4P2RP/6r2/4A4/1r1NK4 b - - 0 1
	if(my_shi_num <= 1 && my_xiang_num == 0){
		if(StoY(mma) MY_LARGE_EQL MY_RANK7){
			MY_EV_SUB(32);
			if((your_shi_num + your_xiang_num) >= 3){
				//if(!have_bit(bb_my_pawn,MyUpBB(m)))
				if(count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) >= 2){
					MY_EV_SUB(32);
				}
			}
		}
		
	}

	if(my_shi_num == 2){
		if(MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){

			Square sq = SQ_END90;
			if(PB90(MY_SQ54) == my_shi){
				sq = Square(MY_SQ56);
			}
			if(PB90(MY_SQ56) == my_shi){
				sq = Square(MY_SQ54);
			}
			if(sq != SQ_END90){
				if(PB90(sq) == my_che || PB90(sq) == my_pao){
					EV_MY_SAFE = TRUE;
				}				
				Bitboard bsq = POSITION.Rook_attacks_bb(sq);
				if(m_have_bit(
					m_and(bsq,m_or(bb_my_pao,
					bb_my_che)))){
						EV_MY_SAFE = TRUE;
				}
			}
		}
	}

	if(EV_MY_SAFE){
		MY_EV_ADD(mcan * ADD_1Che1Pao1MaXPawn_2CheOnly_Safe);
	}

}

//void m_MT_B_1che1pao1ma3pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
// 
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
//	// fen 3ak1b2/4a4/4b4/7r1/4r4/2C3P2/P1R5P/2N1B4/4A4/2B1KA3 b - - 0 0
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



	//if(board->R_shi == 2){
	//	if(board->b256[0xc7] == RKING && board->b256[0xb7] == RSHI){
	//		if(FALSE){
	//		}
	//	    else if(board->b256[0xc6] == RSHI){
	//			//车安全
	//			if(IsCheCanToOrAt(board,rche,0xc8)){
	//				board->rsafe = TRUE;
	//			}

	//			//炮安全
	//			if(IsCheCanToOrAt(board,rpao,0xc8)){
	//				board->rsafe = TRUE;
	//			}
	//		}
	//		else if(board->b256[0xc8] == RSHI){
	//			//车安全
	//			if(IsCheCanToOrAt(board,rche,0xc6)){
	//				board->rsafe = TRUE;
	//			}

	//			//炮安全
	//			if(IsCheCanToOrAt(board,rpao,0xc6)){
	//				board->rsafe = TRUE;
	//			}
	//		}
	//	}
	//}
