#ifndef END_my_m_MT_R_1pao2pawn_B_1che1pawn
#define END_my_m_MT_R_1pao2pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1炮2兵对1车1兵, 炮马方要加分

void my_m_MT_R_1pao2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[my_shi_num]);

	bool issafe = false;

	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king_pos){
		if(PB90(MY_SQ43) == my_xiang){
			issafe = true;
		}
	}

	if(issafe){

		// ADD
		Square yk = your_king_pos;
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		int pmok = (int)count_1s(bmp);
		MY_EV_ADD(pmok * ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[your_shi_num]);

		RETRUN_MUL(2);
	}

	// fen 2b1kab2/3Ra4/9/4P4/9/2B6/2ppc4/4B4/4K4/3A1A3 w - - 120 120
	// fen 2b1kab2/3Ra4/9/4P4/9/2B6/2ppc4/4B4/4K4/3A1A3 w - - 120 120
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
			RETRUN_MUL(2);
		}
	}

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	// fen 2b1kab2/4a4/9/p7r/4P4/2B6/P8/C8/4A4/3AK4 w - - 2 2
    //黑方的兵给红方的炮牵制住了．
	if(my_shi_num == 2 && my_xiang_num >= 1 && PB90(MY_SQ55) == my_king){
		if(StoX(ypawn) == 0x0 || StoX(ypawn) == 0x8){
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 && StoY(mpao) MY_LARGE MY_RANK5){
				Bitboard peat = POSITION.Pao_Eat_bb(mpao);
				if(bit_is_set(peat,ypawn)){
					RETRUN_MUL(2);
				}
			}
		}
	}
	// fen 3akab2/9/4b4/p7p/4P2c1/9/5R3/4B4/4A4/2BK1A3 w - - 0 0
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		//Bitboard lp = My_get_connect_Pawn(POSITION);
		//if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
		//	RETRUN_MUL(2);
		//}

		MY_EV_ADD(EV_MY_CAN * 32);
		RETRUN_MUL(2);
	}

	// fen 5kb2/4a4/4ba3/3P1P3/9/2B6/5p3/B2C1A3/4AK3/7r1 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 2){
			if(StoY(mpao) MY_SMALL_EQL MY_RANK7){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a4/3ab4/3PPC3/9/9/9/3Ap4/3KA4/1r7 b - - 0 1
	if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(PB90(MY_SQ43) == your_pawn){
			Bitboard lp = My_get_connect_Pawn(POSITION);
			if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
				RETRUN_MUL(4);
			}
		}
	}

}


//void m_MT_B_1pao2pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//如果没有过河,或者马炮方有仕
//    bool isSafe = FALSE;
//
//	int  bpao  = PieceListStart(board,BPAO);
//	int  rpawn = PieceListStart(board,RPAWN);
//	int  rk    = PieceListStart(board,RKING);
//
//	//Square bpawn1 = PieceListStart(board,BPAWN);
//	//Square bpawn2 = 
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(board->b256[0x57] == BXIANG){
//			isSafe = TRUE;
//		}
//	}
//
//
//	if(isSafe){
//
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < StoY(rk)){
//				board->mulScore -= ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[board->R_shi];
//			}
//		}
//
//		return 1;
//	}
//
//	// fen 2b1kab2/3Ra4/9/4P4/9/2B6/2ppc4/4B4/4K4/3A1A3 w - - 120 120
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(board->b256[0x37] == BKING){
//			int lp = B_PawnConnect_0x7(board);
//			if(abs(StoX(lp) - 0x7) <= 1 && StoY(lp) < 0xa){
//				return 1;
//			}
//		}
//	}
//
//	// fen 2b1kab2/4a4/9/p7r/4P4/2B6/P8/C8/4A4/3AK4 w - - 2 2
//    //黑方的兵给红方的炮牵制住了．
//	if(board->B_shi == 2 && board->b256[0x37] == BKING && board->B_xiang >= 1){
//		if(board->b256[rpawn - 0x20] == BPAWN || board->b256[rpawn - 0x30] == BPAWN){
//			if(StoX(rpawn) == 0x3 || StoX(rpawn) == 0xb){
//				if(StoX(bpao) == StoX(rpawn) && StoY(bpao) <= 0x5){
//					return 1;
//				}
//			}
//		}
//	}
//
//	*/
//}


