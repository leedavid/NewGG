#ifndef END_my_m_MT_R_1pao2pawn_B_1che
#define END_my_m_MT_R_1pao2pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

// void m_MT_B_1CHE_R_1PAO(board_t *board);
// void my_m_MT_R_1CHE_B_1PAO(board_t *board);

//1炮2兵对1车  //马x兵对1车_addByPawnSafe

void my_m_MT_R_1pao2pawn_B_1che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mk = my_king_pos;
	//炮方有二相二仕, 则马方安全了
	if(my_xiang_num == 2 && my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}

	if(my_shi_num == 2 || my_xiang_num == 2 || (my_shi_num >= 1 && PB90(MY_SQ55) == my_king)){

		// 看一下是不是有连兵
		Bitboard lp = My_get_connect_Pawn(POSITION);

		if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
			EV_MY_SAFE = TRUE;
		}
	}

	if ((my_shi_num + my_xiang_num) <= 3){
		MY_EV_SUB(32);
	}


	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	// fen 4ka3/4a4/9/3P1P3/6b2/9/9/C3r4/4A4/3AK4 w - - 127 127 
	//OrgFen: 3k1a3/4P4/9/5r3/6b2/9/9/3C5/4A4/3AK4 w - - 8 1
	//BcRFen: 4ka3/4a4/5c3/9/9/2B6/3R5/9/4p4/3A1K3 b - - 0 0

	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoxPawn对1Che_addByPawnSafeByShi[your_shi_num]);
	

	// fen 5P3/3k5/b2a5/4CP3/6b2/9/9/4B4/1r2K4/6B2 w - - 130 130 

	my_m_MT_R_1PAO1PAWN_B_1CHE(POSITION,ei);

	if((your_shi_num + your_xiang_num) >= 2){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 4k1b2/9/3a1a3/4CPP2/2b6/9/9/4r4/9/5K3 b - - 0 1
	

	// fen 3k5/4a4/3ab4/1CP1P4/6b2/9/r8/9/5K3/9 b
	Bitboard mp = m_and(bb_my_pawn,RankBB_A[MY_RANK3]);
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if (count_1s(mp) == 2 && m_have_bit(lp)){
		if (StoX(mpao) <= 0x4 && !have_bit(bb_my_pawn, LeftBB[0x4])){
			RETRUN_MUL(2);
		}
		if (StoX(mpao) >= 0x4 && !have_bit(bb_my_pawn, RightBB[0x4])){
			RETRUN_MUL(2);
		}
	}

	if(count_1s(mp) == 2 && PB90(MY_SQ1F) == my_pawn){
		MY_EV_ADD(80);
		if(StoY(mpao) == MY_RANK3){
			if(!have_bit(bb_my_pawn,LeftBB[0x2]) && !have_bit(bb_my_pawn,RightBB[0x6])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k2b2/4a4/4b4/3P1P3/9/4r4/9/4C4/4K4/9 b - - 0 1
	if(StoY(mpao) MY_LARGE_EQL MY_RANK7 && StoX(mpao) == StoX(mk)){
		Bitboard bp = m_and(bb_my_pawn,RankBB_A[MY_RANK3]);
		if(count_1s(bp) == 2){
			if(!have_bit(bp,LeftBB[0x2]) && !have_bit(bp,RightBB[0x6])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2bk5/4a4/3a5/4PP3/2b6/9/9/9/4KC1r1/2B6 w - - 0 1
	
	if(bit_is_set(lp,MY_SQ1F) || bit_is_set(lp,MY_SQ28)){

		if(StoY(mk) MY_LARGE_EQL MY_RANK8){

			if(my_shi_num >= 1 || my_xiang_num >= 1){
				if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
					RETRUN_MUL(4);
				}
			}

			RETRUN_MUL(8);
		}
	}

	// fen 4k4/4a4/3ab4/3PP4/9/9/9/3K5/4r2C1/9 w - - 0 1
	//Bitboard lp = My_get_connect_Pawn(POSITION);
	if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
		if(StoY(mpao) MY_LARGE_EQL StoY(mk)){
			RETRUN_MUL(8);
		}
	}
}


//void m_MT_B_1pao2pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//
//
//	//bool paoSideSafe = FALSE;
//
//	int  rk = PieceListStart(board,RKING);
//
//
//	if(board->B_xiang == 2 && board->B_shi == 2){   //炮方有二相二仕, 则马方安全了
//		//paoSideSafe = TRUE;
//		board->bsafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2 || (board->B_shi >= 1 && board->b256[0x37] == BKING)){  //马方有二相,或二仕, 则马方如果在中线有连兵就是和了.
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) < StoY(rk) && StoX(from) == 0x7){
//
//				if(board->b256[from+1] == BPAWN || board->b256[from-1] == BPAWN){
//
//					board->bsafe = TRUE;
//
//					break;
//				}
//			}
//		}
//	}
//
//	//if(TRUE == paoSideSafe){
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//		if(StoY(from) <= StoY(rk)){
//
//			board->mulScore -= ADD_PaoxPawn对1Che_addByPawnSafeByShi[board->R_shi];
//		}
//	}
//
//	//       return 1;
//	//}
//
//	//return m_MT_B_1PAO1PAWN_R_1CHE(board);;
//
//	if(m_MT_R_1CHE_B_1PAO(board) <= 2){
//		board->bsafe = TRUE;
//	}
//
//	if((board->R_shi + board->R_xiang) >= 2){
//		board->rsafe = TRUE;
//	}
//
//
//	*/
//}