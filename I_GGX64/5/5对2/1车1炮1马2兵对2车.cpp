#ifndef END_my_m_MT_R_1che1pao1ma2pawn_B_2che
#define END_my_m_MT_R_1che1pao1ma2pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮1马2兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int  ADD_1Che1Pao1MaXPawn_2CheOnly[3]         = {96, 64, 32};   //1 
//const int  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe       =  96;

void my_m_MT_R_1che1pao1ma2pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	//return;

	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Che1Pao1MaXPawn_2CheOnly[your_shi_num]);

	int mcan = EV_MY_CAN;

	Square mk = my_king_pos;

	if(my_shi_num == 2 && my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			EV_MY_SAFE = TRUE;
		}
	}

	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);

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

	// fen 2baka3/9/8P/4C4/9/9/4P2RP/6r2/4A4/1r1NK4 b - - 0 1
	if(my_shi_num <= 1 && my_xiang_num == 0){
		if(StoY(mma) MY_LARGE_EQL MY_RANK7){
			MY_EV_SUB(32);
			if((your_shi_num + your_xiang_num) >= 3){
				//if(!have_bit(bb_my_pawn,MyUpBB(m)))
				if(count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) >= 1){
					MY_EV_SUB(16);
				}
			}
		}
		
	}


	if(my_shi_num == 2){
		if(MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){

			Square sq = SQ_END90 ;
			if(PB90(MY_SQ54) == my_shi){
				sq = Square(MY_SQ56);
			}
			if(PB90(MY_SQ56) == my_shi){
				sq = Square(MY_SQ54);
			}
			if(sq != SQ_END90 ){
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

	// fen 3aka3/9/4b3b/9/4PP3/4r4/7r1/5R3/4N4/3AK1C2 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(MY_SQ55 == mk){
			Bitboard mlp = My_get_connect_Pawn(POSITION);
			if(have_bit(mlp,RankBB_A[MY_RANK4]) || have_bit(mlp,RankBB_A[MY_RANK3])){
				if(StoY(mpao) == MY_RANK9 && MY_SQ4C == mma){
					if(PB90(MY_SQ54) == my_shi && StoX(mpao) > 0x4 && StoX(mche) == 0x5){
						RETRUN_MUL(4);
					}
					if(PB90(MY_SQ56) == my_shi && StoX(mpao) < 0x4 && StoX(mche) == 0x3){
						RETRUN_MUL(4);
					}
				}

			}
		}
	}

}

//void m_MT_B_1che1pao1ma2pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
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
//	*/
//
//}

