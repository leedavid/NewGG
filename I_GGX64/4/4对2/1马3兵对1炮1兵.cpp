#ifndef END_my_m_MT_R_1ma3pawn_B_1pao1pawn
#define END_my_m_MT_R_1ma3pawn_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马3兵对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//1马3兵对炮兵
void my_m_MT_R_1ma3pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

    // ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_PaoPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_MaPawn_To_PaoPawnByShi[my_shi_num]); 

	int mcan = EV_MY_CAN;

	// fen 4kab2/4a4/8b/3P5/8p/2B3PN1/6c1P/3AB4/4A4/4K4 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 4k1b2/9/3aba3/p5C2/9/PnB6/4p4/3AB4/4A1p2/5K3 w - - 120 120
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan <= 2){
			if(PB90(MY_SQ04) == your_king && PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0E) == my_pawn){

			}
			else{
				if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn && PB90(MY_SQ26) == your_xiang){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2A) == your_xiang){
					RETRUN_MUL(4);
				}
			}
		}
	}

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 9/2P1a1P2/3a1k3/4PN3/2b3b2/9/4c4/B3B4/4Ap3/3AK4 w - - 121 121
    //２兵到底，马不能动了，也是和棋
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK2){
		Bitboard low = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		bool ok = false;
		if(count_1s(low) == 3){		
			ok = true;
		}
		else if(count_1s(low) == 2){	
			//找到另外一个兵，在卒线，且不在将一边
			low = m_and(bb_my_pawn,RankBB_A[MY_RANK3]);
			if(count_1s(low) == 1){
				int p = pop_1st_bit_sq(low);
				if(!IsOnSameSide(p,yk)){
					ok = true;
				}
			}
		}
		if(ok == true){
			if(PB90(MY_SQ55) == my_king && PB90(MY_SQ43) == my_xiang){
				if(isStringByPao(POSITION,ypao,Square(MY_SQ4C),Square(MY_SQ55))){
					if(PB90(MY_SQ54) == my_shi && PB90(MY_SQ4D) == your_pawn 
						&& PB90(MY_SQ20) == my_ma && PB90(MY_SQ17) == your_king){
							RETRUN_MUL(2);
					}
					if(PB90(MY_SQ56) == my_shi && PB90(MY_SQ4B) == your_pawn 
						&& PB90(MY_SQ1E) == my_ma && PB90(MY_SQ15) == your_king){
							RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 4k4/4a4/b3ba3/8p/6n2/1p4B1P/9/4BA2C/4Ap3/4K4 b - - 120 120
    //顶死一个兵,炮还在打那个兵,有可能是难胜
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		Square sq = SQ_END90;
		if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn){
			sq = Square(MY_SQ36);
		}
		if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn){
			sq = Square(MY_SQ3E);
		}
		//Bitboard peat = pao_eat_attacks_bb(sq,BitboardOCC);
		Bitboard peat = ei.attacked_by(your_pao);
		if(sq != SQ_END90 && bit_is_set(peat,sq)){
			RETRUN_MUL(4);
		}
	}

	// fen 9/9/3P1k3/4C4/2b3b2/9/3n5/B4A3/4Appp1/2B1K4 b - - 121 121
	if(your_shi_num == 2 && your_xiang_num == 2){
		Bitboard p = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(p) == 3){
			Bitboard p1 = m_and(p,LeftBB[0x4]);
			if(StoX(yk) >= 4 && count_1s(p1) == 3){
				RETRUN_MUL(4);
			}
			p1 = m_and(p,RightBB[0x4]);
			if(StoX(yk) <= 4 && count_1s(p1) == 3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a1k3/9/8C/9/6p1p/9/2p5P/6n1B/3KA4/6B2 w - - 3 3
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(mcan <= 1){
			RETRUN_MUL(8);
		}
	}

	
}

//1马3兵对炮兵
//void m_MT_B_1ma3pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	int bcan = BpawnCanOverLiver(board);
//	int rpao = PieceListStart(board,RPAO);
//	Square rpawn = PieceListStart(board,RPAWN);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_MaPawn_To_PaoPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_PaoPawnByShi[board->R_shi];
//		}
//	}
//
//	// fen 4k1b2/9/3aba3/p5C2/9/PnB6/4p4/3AB4/4A1p2/5K3 w - - 120 120
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			if(bcan <= 2){
//				if(board->b256[0xc7] == RKING && board->b256[0xb6] == BPAWN && board->b256[0xb8] == BPAWN){
//				}
//				else{
//					//另外二个兵给顶住了
//					if(FALSE){
//					}
//					else if(board->b256[0x83] == RPAWN && board->b256[0x63] == BPAWN){
//						return 1;
//					}
//					else if(board->b256[0x8b] == RPAWN && board->b256[0x6b] == BPAWN){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xa){
//		int blow = 0;
//		int up   = 0;
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) > StoY(rk)){
//				blow ++;
//			}
//			else{
//				up = from;
//			}
//		}
//
//		if(blow >= 2){
//			//看一上是不是红马不能走了．
//			if(board->b256[0x37] == BKING && board->b256[0x47] == BSHI && board->b256[0x57] == BXIANG){
//				if(StoX(rpao) == 0x7 && StoY(rpao) > 0x5 && StoY(rpao) <= 0x8){
//					if(board->b256[0x36] == BSHI && board->b256[0x48] == RPAWN){
//						if(board->b256[0xa8] == RKING && board->b256[0x98] == BMA){
//							if(blow == 3) return 1;
//							if(blow == 2){
//								if(StoY(up) == 0x9 && StoX(up) <= 0x7){
//									return 1;
//								}
//							}
//						}
//					}
//					if(board->b256[0x38] == BSHI && board->b256[0x46] == RPAWN){
//						if(board->b256[0xa6] == RKING && board->b256[0x96] == BMA){
//							if(blow == 3) return 1;
//							if(blow == 2){
//								if(StoY(up) == 0x9 && StoX(up) >= 0x7){
//									return 1;
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	// fen 4k4/4a4/b3ba3/8p/6n2/1p4B1P/9/4BA2C/4Ap3/4K4 b - - 120 120
//    //顶死一个兵,炮还在打那个兵,有可能是难胜
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//		if(StoY(rpao) > 0x8){
//			if(board->b256[0x79] == BMA && board->b256[0x6b] == BPAWN 
//				&& board->b256[0x8b] == RPAWN){
//					if(StoX(rpao) == 0xb){
//						return 4;
//					}
//
//			}
//			if(board->b256[0x75] == BMA && board->b256[0x63] == BPAWN
//				&& board->b256[0x83] == RPAWN){
//					if(StoX(rpao) == 0x3){
//						return 4;
//					}
//			}
//		}
//	}
//
//	// fen 3a1k3/9/8C/9/6p1p/9/2p5P/6n1B/3KA4/6B2 w - - 3 3
//	if(board->R_shi >= 1 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//		if(bcan <= 1) return 8;
//	}
//
//
//
//	// fen 9/9/3P1k3/4C4/2b3b2/9/3n5/B4A3/4Appp1/2B1K4 b - - 121 121
//	if(board->R_xiang == 2 && board->R_shi == 2){
//		//for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		//	if(IsOnSameSide
//		//}
//		Square bpawn1 = PieceListStart(board,BPAWN);
//		Square bpawn2 = NextPiece(board,bpawn1);
//		Square bpawn3 = NextPiece(board,bpawn2);
//		if(StoY(bpawn1) >= 0xb && StoY(bpawn2) >= 0xb && StoY(bpawn3) >= 0xb){
//			if(StoX(bpawn1) < 0x7 && StoX(bpawn2) < 0x7 && StoX(bpawn3) < 0x7){
//				return 8;
//			}
//			if(StoX(bpawn1) > 0x7 && StoX(bpawn2) > 0x7 && StoX(bpawn3) > 0x7){
//				return 8;
//			}
//		}
//	}
//
//	*/
//}