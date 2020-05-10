#ifndef END_my_m_MT_R_1che3pawn_B_1che1pao
#define END_my_m_MT_R_1che3pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车3兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


////const int const_Pawn_Shi_Add[3] = {180, 120, 32};

//车3兵对车炮
void my_m_MT_R_1che3pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePawn_To_ChePao_Pawn_Shi_Add[your_shi_num]);

	Square mk = my_king_pos;
	// fen 2bak4/9/4b4/4R4/P3c4/4r1P2/8P/4B4/9/2B1KA3 b - - 0 0 //这个FEN 应是红优
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	
	//如果车炮被牵制了, 则炮方要减分
	if(isStringByChe(POSITION,mche,ypao,yche)){
		MY_EV_ADD(ADD_ChePawn_To_ChePao_By_StringPao);
	}

    if(my_shi_num == 2 && my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			MY_EV_ADD(64);
		}
	}

	// fen 2b1kar2/3P1R3/b3c4/9/8P/6B2/9/9/9/5K3 b - - 0 1
	if (your_shi_num <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
		Bitboard pup = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
		if (have_bit(pup, m_and(LeftBB[0x6], RightBB[0x2]))){
			MY_EV_ADD(EV_MY_CAN * 16);
			if ((my_shi_num + my_xiang_num) >= 1){
				MY_EV_ADD(EV_MY_CAN * 16);
				if (StoY(yche) == MY_RANK0){
					MY_EV_ADD(32);
				}
				if (EV_MY_CAN == 2){
					MY_EV_ADD(32);
				}
			}
		}
	}

	//fen 3ak4/4a4/9/4R4/6P2/2P6/4Pr2P/9/5c3/4K1B2 w - - 0 1
	if (your_xiang_num == 0 ){
		if (EV_MY_CAN >= 3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 9/5k3/3aRa3/9/1C7/1r7/3ppp3/8B/4A4/3AK1B2 w - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if (have_bit(lp, MyLowBB[MY_RANK2])){
		int c = count_1s(lp);
		if (c >= 2){
			MY_EV_ADD(c * 48);
			if (my_shi_num == 2 || my_xiang_num == 2){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 7R1/4k4/9/9/2b5P/4r1P2/P8/9/c8/3K5 w - - 0 1
	if((my_shi_num + my_xiang_num) == 0){
		if(StoX(yche) == 0x4){
			MY_EV_SUB(32);
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 2b1k1b2/4a4/9/2P1P4/4P2P1/5r3/3R5/9/4K4/3A4c w - - 0 1
	Bitboard mop = m_and(bmp, MyUpBB[MY_RANK5]);
	if (count_1s(mop) >= 2){
		MY_EV_ADD(32);
		if (your_shi_num <= 1){
			MY_EV_ADD(32);
		}
		if (StoY(ypao) MY_LARGE_EQL MY_RANK5){
			MY_EV_ADD(32);
		}
	}

	int mcan = EV_MY_CAN;
	//车炮十字被牵
	// fen 3k1a3/4a2CR/9/9/7r1/9/2p2p3/9/2p1A4/2B1KAB2 w - - 110 110
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		int x = XYtoS(StoX(mche),StoY(yche));
		if(PB90(x) == your_pao){
			if(IsOnSameSide(mk,yche) == FALSE){
				MY_EV_ADD(mcan * 80);
			}
		}
	}

	// fen 3ak4/3R5/4ba2b/p5C1p/2p6/r8/9/4B4/4A4/4KAB2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			RETRUN_MUL(8);
		}
	}

	// fen 4ka1c1/4a1P2/b3r3b/5PP2/9/6B2/1R7/3AB4/9/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		MY_EV_SUB(64);
		if(my_xiang_num == 2 || my_shi_num == 2){
			RETRUN_MUL(12);
		}
	}
}

//void m_MT_B_1che3pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16 = pMat->sixiangInfo8;
//
//	Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	int bcan = BpawnCanOverLiver(board);
//
//	//Square rpawn1 = PieceListStart(board,RPAWN);
//	//Square rpawn2 = NextPiece(board,rpawn1);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePawn_To_ChePao_Pawn_Shi_Add[board->R_shi];
//		}
//	}
//
//	int rche = PieceListStart(board,RCHE);
//	int bche = PieceListStart(board,BCHE);
//	int rpao = PieceListStart(board,RPAO);
//
//	//如果车炮被牵制了, 则炮方要减分
//	if(IsStringByChe(board,rche,rpao,bche)){
//		board->mulScore -= ADD_ChePawn_To_ChePao_By_StringPao;
//	}
//
//	// fen R2akab2/9/3c5/9/2b6/9/P1r3P1P/4B4/4A4/4KAB2 w - - 3 3
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(StoY(bk) == 0x3){
//			board->mulScore -= 96;
//		}
//	}
//
//	
//	//车炮十字被牵
//	// fen 3k1a3/4a2CR/9/9/7r1/9/2p2p3/9/2p1A4/2B1KAB2 w - - 110 110
//	if(board->B_shi == 2 && StoY(bk) == 0x3){
//		if(board->b256[XYtoS(StoX(bche),StoY(rche))] == RPAO){
//			if(IsOnSameSide(bk,rche) == FALSE){
//			   board->mulScore -= bcan * 64;
//			}
//		}
//	}
//
//
//	*/
//}