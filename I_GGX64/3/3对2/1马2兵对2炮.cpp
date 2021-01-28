#ifndef END_my_m_MT_R_1ma2pawn_B_2pao
#define END_my_m_MT_R_1ma2pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//


// 1马2兵对2炮
void my_m_MT_R_1ma2pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_2Pao_ByShi[your_shi_num]);


	if(my_shi_num == 2 || my_xiang_num == 2){
		EV_MY_SAFE = TRUE;
	}

	if(your_shi_num == 0){
		EV_MY_SAFE = TRUE;
	}	
	
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	//二个都是低兵了,也是和棋
	if(StoY(mpawn1) MY_SMALL_EQL StoY(yk) && StoY(mpawn2) MY_SMALL_EQL StoY(yk)){
		EV_YOUR_SAFE = TRUE;
	}
	

	// fen 4k1b2/9/3a1a3/9/8p/4C1B2/2C2n3/4K4/3p5/9 w - - 125 125
	//红兵不能过河,也是和棋
	if(your_xiang_num >= 1){
		Bitboard mp = m_and(bb_my_pawn,MyUpBB[StoY(yk)]);
		if(count_1s(mp) >= 1){
			Square sq = SQ_END90;
			if(PB90(MY_SQ2D) == my_pawn){
				sq = Square(MY_SQ24);
			}
			if(PB90(MY_SQ35) == my_pawn){
				sq = Square(MY_SQ2C);
			}
			if(sq != SQ_END90){
				Square ypao1 = S90_from_piecelist(POSITION,your_pao,0);
				Square ypao2 = S90_from_piecelist(POSITION,your_pao,1);
				Bitboard peat = POSITION.Pao_Eat_bb(ypao1);
				if(bit_is_set(peat,sq)){
					RETRUN_MUL(4);
				}
				peat = POSITION.Pao_Eat_bb(ypao2);
				if(bit_is_set(peat,sq)){
					RETRUN_MUL(4);
				}
			}
		}
	}

    // fen 2ba5/2C1a4/1C3k3/9/9/3n5/6p2/2p6/4A4/2BK1A3 w - - 0 1
	MY_EV_ADD(EV_MY_CAN * 64);

	if(your_shi_num == 2){
		RETRUN_MUL(8);
	}

}

//void m_MT_B_1ma2pawn_R_2pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_2Pao_ByShi[board->R_shi];
//		}
//	}
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//	int rpao1  = PieceListStart(board,RPAO);
//	int rpao2  = NextPiece(board,rpao1);
//
//	
//	if(board->B_shi == 2 || board->B_xiang == 2){
//		board->bsafe = TRUE;
//	}
//	if(board->R_shi == 0){
//		board->bsafe = TRUE;
//	}
//
//	//二个都是低兵了,也是和棋
//	if(StoY(bpawn1) > StoY(rk) && StoY(bpawn2) > StoY(rk)){
//		board->rsafe = TRUE;
//	}
//
//	// fen 4k1b2/9/3a1a3/9/8p/4C1B2/2C2n3/4K4/3p5/9 w - - 125 125
//	//黑兵不能过河,也是和棋
//	if(StoY(bpawn1) > StoY(rk)){
//		if(StoY(bpawn2) < 0x8){
//			if(StoX(bpawn2) == 0xb){
//				if(board->b256[0x89] == RXIANG){
//					if(StoY(rpao1) == 0x8 && StoX(rpao1) < 0x9){
//						board->rsafe = TRUE;
//					}
//					if(StoY(rpao2) == 0x8 && StoX(rpao2) < 0x9){
//						board->rsafe = TRUE;
//					}
//				}
//			}
//			if(StoX(bpawn2) == 0x3){
//				if(board->b256[0x85] == RXIANG){
//					if(StoY(rpao1) == 0x8 && StoX(rpao1) > 0x5){
//						board->rsafe = TRUE;
//					}
//					if(StoY(rpao2) == 0x8 && StoX(rpao2) > 0x5){
//						board->rsafe = TRUE;
//					}
//				}
//			}
//		}
//	}
//	if(StoY(bpawn2) > StoY(rk)){
//		if(StoY(bpawn1) < 0x8){
//			if(StoX(bpawn1) == 0xb){
//				if(board->b256[0x89] == RXIANG){
//					if(StoY(rpao1) == 0x8 && StoX(rpao1) < 0x9){
//						board->rsafe = TRUE;
//					}
//					if(StoY(rpao2) == 0x8 && StoX(rpao2) < 0x9){
//						board->rsafe = TRUE;
//					}
//				}
//			}
//			if(StoX(bpawn1) == 0x3){
//				if(board->b256[0x85] == RXIANG){
//					if(StoY(rpao1) == 0x8 && StoX(rpao1) > 0x5){
//						board->rsafe = TRUE;
//					}
//					if(StoY(rpao2) == 0x8 && StoX(rpao2) > 0x5){
//						board->rsafe = TRUE;
//					}
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