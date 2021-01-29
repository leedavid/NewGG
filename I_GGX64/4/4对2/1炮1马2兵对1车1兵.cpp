#ifndef END_my_m_MT_R_1ma1pao2pawn_B_1che1pawn
#define END_my_m_MT_R_1ma1pao2pawn_B_1che1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马2兵对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_1ma1pao2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){


	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;


	if(StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[my_shi_num]);
	}

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[your_shi_num]);

	Bitboard lp = My_get_connect_Pawn(POSITION);
    //如果红方有联兵，也要加分
	if(m_have_bit(m_and(lp,MyLowBB[StoY(yk)]))){
		MY_EV_ADD(Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByConPawn);
	}

	// fen 2bak4/4a4/4b4/9/P8/2NrC4/4Pp3/4B4/4A4/2BAK4 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3k5/4a4/4b4/p2r1NP2/9/P1B6/9/4B4/9/4K2C1 w - - 0 1
	if(EV_MY_CAN <= 1 && your_shi_num >= 1 && my_shi_num == 0){
		MY_EV_SUB(32);
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3]) && StoY(yk) == MY_RANK0){
			MY_EV_SUB(32);
		}
	}

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	// fen 6b2/4k4/2n1b4/p3p4/9/9/4P4/4BR3/4A1c2/2BA1K3 w - - 15 15
	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8 && PB90(MY_SQ3A) == my_pawn){
		if(PB90(MY_SQ1F) == your_pawn || PB90(MY_SQ28) == your_pawn){
			if(PB90(MY_SQ3E) == my_pawn && (PB90(MY_SQ45) == my_ma || PB90(MY_SQ33) == my_ma)){
				if(StoX(mpao) < 0x4){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ36) == my_pawn && (PB90(MY_SQ41) == my_ma || PB90(MY_SQ2F) == my_ma)){
				if(StoX(mpao) > 0x4){
					RETRUN_MUL(2);
				}
			}
		}
	}
	

	// fen 2bak4/9/b4a3/3PP4/3N5/6B2/5r3/3AB4/2C1Ap3/4K4 w - - 122 122]]
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mk) == MY_RANK9){
			if(PB90(MY_SQ4B) == your_pawn || PB90(MY_SQ4D) == your_pawn){
				MY_EV_SUB(164);
			}
		}
	}

	// fen 3k2b2/4a4/4ba3/2r1CP3/9/4P4/9/3N2p2/4A4/4K4 w - - 0 1
    if((your_shi_num + your_xiang_num) >= 3){
		if(my_shi_num >= 1 && MY_SQ55 == mk && StoY(ypawn) MY_LARGE_EQL MY_RANK7){
			if(PB90(MY_SQ1F) == my_pao && PB90(MY_SQ31) == my_pawn){
				if(StoX(ypawn) >= 0x5 && PB90(MY_SQ42) == my_ma && PB90(MY_SQ20) == my_pawn){
					RETRUN_MUL(4);
				}
				if(StoX(ypawn) <= 0x3 && PB90(MY_SQ44) == my_ma && PB90(MY_SQ1E) == my_pawn){
					RETRUN_MUL(4);
				}
			}
		}
	}
}

// 黑方马炮兵,红方车兵
//void m_MT_B_1ma1pao2pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	int bpao  = PieceListStart(board,BPAO);
//
//		//Square rk = PieceListStart(board,RKING);
//	
//    for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[board->B_shi];
//		}
//	}
//
//	// fen 3nkab2/4a1P2/4b4/7R1/8c/1p7/9/4B4/4A4/4KAB2 w - - 4 4
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			//board->mulScore -=  Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//			int bonus = Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//			//if(board->bsafe){
//			//	bonus *= 2;
//			//}
//			board->mulScore -=  bonus;
//		}
//	}
//
//	//如果红方有联兵，也要加分
//	if(B_PawnConnect_0x7(board) && board->B_shi == 2){
//		board->mulScore -= Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByConPawn;
//	}
//
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		if(StoY(rk) >= 0xb){
//			board->rsafe = TRUE;
//		}
//	}
//
//	// fen 6b2/4k4/2n1b4/p3p4/9/9/4P4/4BR3/4A1c2/2BA1K3 w - - 15 15
//	//黑方能守住
//	if(board->b256[rpawn - 0x20] == BPAWN || board->b256[rpawn - 0x30] == BPAWN){
//		if(StoY(bk) <= 0x4){
//			if(board->B_xiang == 2){
//				//1
//				if(board->b256[0x55] == BMA && board->b256[0x63] == BPAWN && board->b256[0x67] == BPAWN){
//					if(IsCheCanToOrAt(board,bpao,XYtoS(StoX(bpao),0x5))){
//						if(StoX(bpao) > 0x7){
//							return 1;
//						}
//					}
//				}
//				//2
//				if(board->b256[0x75] == BMA && board->b256[0x6b] == BPAWN && board->b256[0x67] == BPAWN){
//					return 1;
//				}
//				//1
//				if(board->b256[0x59] == BMA && board->b256[0x6b] == BPAWN && board->b256[0x67] == BPAWN){
//					if(IsCheCanToOrAt(board,bpao,XYtoS(StoX(bpao),0x5))){
//						if(StoX(bpao) < 0x7){
//							return 1;
//						}
//					}
//				}
//				//2
//				if(board->b256[0x79] == BMA && board->b256[0x6b] == BPAWN && board->b256[0x67] == BPAWN){
//					return 1;
//				}
//			}
//		}
//	}
//
//
//	// fen 2bak4/9/b4a3/3PP4/3N5/6B2/5r3/3AB4/2C1Ap3/4K4 w - - 122 122
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(board->B_shi == 2){
//			if((board->b256[0x46] == RPAWN || board->b256[0x48] == RPAWN) && StoY(bk) == 0x3){
//				board->mulScore += 164;
//			}
//		}
//	}
//
//	*/
//}

