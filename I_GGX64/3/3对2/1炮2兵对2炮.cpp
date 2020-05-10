#ifndef END_my_m_MT_R_1pao2pawn_B_2pao
#define END_my_m_MT_R_1pao2pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_2Pao_ByPawnShi[your_shi_num]);

	if(your_shi_num == 0){
		EV_MY_SAFE = TRUE;
	}

	Bitboard mlp = My_get_connect_Pawn(POSITION);
	if (have_bit(mlp, MyLowBB[MY_RANK2])){
		MY_EV_ADD(64);
	}

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	// fen 9/3k5/5P3/9/5c1c1/P8/9/9/9/2C1K4 w - - 93 93
	//红方有一个兵不能过河
	if(my_shi_num == 0 && my_xiang_num == 0){
		Square p = SQ_END90 ;
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){		
			p = mpawn1;
		}
		if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5 && StoY(mpawn1) MY_SMALL_EQL MY_RANK2){		
			p = mpawn2;
		}
		if(p != SQ_END90 ){
			p = p MY_SUB 9;
			Bitboard peat = POSITION.Pao_Eat_bb(p);
			if(m_have_bit(m_and(peat,bb_your_pao))){
				RETRUN_MUL(4);
			}
		}
	}
	// fen 5k3/6P2/4b1P2/5c3/4Cc3/2B6/9/9/9/3K2B2 w - - 0 0<
	if(my_shi_num == 0 && (your_shi_num + your_xiang_num) >= 1){
		if(StoY(mpawn1)  MY_SMALL_EQL MY_RANK2 && StoY(mpawn2)  MY_SMALL_EQL MY_RANK2){
			Square ypao1 = S90_from_piecelist(POSITION,your_pao,0);
			Square ypao2 = S90_from_piecelist(POSITION,your_pao,1);
			if(StoX(ypao1) == StoX(ypao2) && StoX(ypao1) == StoX(yk)){
				if(StoX(yk) == 0x5 && StoX(mpawn1) > 0x5 && StoX(mpawn2) > 0x5){
					RETRUN_MUL(4);
				}
				if(StoX(yk) == 0x3 && StoX(mpawn1) < 0x3 && StoX(mpawn2) < 0x3){
					RETRUN_MUL(4);
				}
			}
		}
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			RETRUN_MUL(4);
		}
	}
	// fen 3akab2/5c3/4b4/8P/9/9/8P/4B4/2C1A4/c3KAB2 b - - 0 0
	if((your_shi_num + your_xiang_num) >= 3){
		if((my_shi_num + my_xiang_num) == 4){
		     RETRUN_MUL(4);
		}
	}
	if ((your_shi_num + your_xiang_num) >= 3){
		if (my_shi_num == 2 || my_xiang_num == 2){
			if (have_bit(mlp, MyLowBB[MY_RANK2]) && StoY(mk) MY_LARGE_EQL MY_RANK8){
				RETRUN_MUL(8);
			}
			// fen 5k3/4a4/3aC4/4c4/9/5C3/3p1p3/4B4/4A4/4KAB2 w - - 0 1
			if (count_1s(bb_my_pawn, RankBB_A[MY_RANK6]) == 2){
				if (abs(StoX(mpawn1) - StoX(mpawn2)) <= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}


	/*
	// fen 5k3/6P2/4b1P2/5c3/4Cc3/2B6/9/9/9/3K2B2 w - - 0 0<
	if(board->R_shi == 0 && (board->B_xiang + board->B_shi) >= 1){
		if(StoY(rpawn1) <= 05 && StoY(rpawn2) <= 0x5 ){
			if(StoX(bpao1) == StoX(bpao2) && StoX(bpao1) == StoX(bk)){
				if(StoX(bk) == 0x8 && StoX(rpawn1) >= 0x9 && StoX(rpawn2) >= 0x9){
					return 2;
				}
				if(StoX(bk) == 0x6 && StoX(rpawn1) <= 0x5 && StoX(rpawn2) <= 0x5){
					return 2;
				}
			}
		}
	}

 
	*/
}

//void m_MT_B_1pao2pawn_R_2pao(typePOS &POSITION, EvalInfo &ei){
//
//	/*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	int rpao1 = PieceListStart(board,RPAO);
//	int rpao2 = NextPiece(board,rpao1);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1PaoXPawn_2Pao_ByPawnShi[board->R_shi];
//		}
//	}
//
//	//return 16;
//
//
//
//	if(board->R_shi == 0){
//		board->bsafe = TRUE;
//	}
//
//	if(board->B_shi == 0){
//		//黑方有一个兵不能过河
//		// fen 9/3k5/5P3/9/5c1c1/P8/9/9/9/2C1K4 w - - 93 93
//		if(board->B_xiang == 0){			
//			if(StoY(bpawn1) <= 0x7 && StoX(bpawn1) != 0x7){
//				//如果有兵没有过河
//				if(StoY(rpao1) == 0x8 && StoY(rpao2) == 0x8){
//					if(StoX(rpao1) > StoX(bpawn1) && StoX(rpao2) > StoX(bpawn1)){
//						board->rsafe = TRUE;
//					}
//					if(StoX(rpao1) < StoX(bpawn1) && StoX(rpao2) < StoX(bpawn1)){
//						board->rsafe = TRUE;
//					}
//				}
//
//			}
//			if(StoY(bpawn2) <= 0x7 && StoX(bpawn2) != 0x7){
//				if(StoY(rpao1) == 0x8 && StoY(rpao2) == 0x8){
//					if(StoX(rpao1) > StoX(bpawn2) && StoX(rpao2) > StoX(bpawn2)){
//						board->rsafe = TRUE;
//					}
//					if(StoX(rpao1) < StoX(bpawn2) && StoX(rpao2) < StoX(bpawn2)){
//						board->rsafe = TRUE;
//					}
//				}
//			}
//		}
//		//-------
//	}
//
//	// fen 5k3/6P2/4b1P2/5c3/4Cc3/2B6/9/9/9/3K2B2 w - - 0 0<
//	if(board->B_shi == 0 && (board->R_xiang + board->R_shi) >= 1){
//		if(StoY(bpawn1) >= 0xa && StoY(bpawn2) >= 0xa ){
//			if(StoX(rpao1) == StoX(rpao2) && StoX(rpao1) == StoX(rk)){
//				if(StoX(rk) == 0x8 && StoX(bpawn1) >= 0x9 && StoX(bpawn2) >= 0x9){
//					return 2;
//				}
//				if(StoX(rk) == 0x6 && StoX(bpawn1) <= 0x5 && StoX(bpawn2) <= 0x5){
//					return 2;
//				}
//			}
//		}
//	}
// 
//	*/
//}