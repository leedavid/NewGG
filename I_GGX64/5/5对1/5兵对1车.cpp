#ifndef END_my_m_MT_R_5pawn_B_1che
#define END_my_m_MT_R_5pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "5兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int Pawn_add = 10;

//红方三兵，黑方一车
void my_m_MT_R_5pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	MY_EV_SUB(ADD_CheXPawn_To_1Pawn);

	if(my_shi_num == 2 && my_xiang_num == 2 && PB90(MY_SQ55) == my_king){
		RETRUN_MUL(2);
	}

	// fen 4k4/4a4/9/4P4/3PP4/9/r8/9/9/4K4 w - - 142 142 
	// 我方有三个兵连线了,就也要加分了
	// fen 4k4/4a4/9/4P4/3PP4/9/r8/9/4A4/4KA3 w
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
		if(m_have_bit(m_and(lp,FileBB_A[0x4]))){
			if(my_shi_num == 2 || my_xiang_num == 2){
               if(StoY(mk) MY_LARGE_EQL MY_RANK8){
				     RETRUN_MUL(2); 
			   }
			}
			// fen 4k4/4a4/9/4P4/3PP4/9/r8/9/9/4K4 w - - 142 142 
			// 如果连前面还有连兵
			Bitboard lpf = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),lp);
			//所有兵向前一步
			my_m_Rsf(lpf,9);
			if(m_have_bit(m_and(lpf,bb_my_pawn))){
				RETRUN_MUL(2);
			}
		}		
	} 

	if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) >= 4 && PB90(MY_SQ1F) == my_pawn){
		//if(PB90(MY_SQ1E) == my_pawn && PB90(MY_SQ1F) == my_pawn && PB90(MY_SQ20) == my_pawn){
		//	RETRUN_MUL(2);
		//}
		//Bitboard lp = My_get_connect_Pawn(POSITION);
		if(count_1s(lp) >= 3){
			RETRUN_MUL(2);
		}
	}
}

//黑方三兵，红方一车
//void m_MT_B_5pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	int PawnLian = 0;      //有多少个连兵
//
//    //在这儿看一下有多少兵在二线，有几个加分
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) == 0x9){
//			board->mulScore -= Pawn_add;
//		}
//
//		if(StoX(from) == 0x7){
//			if(board->b256[from+1] == BPAWN){
//				PawnLian ++;
//				//if(board->b256[from+1-16] == RPAWN)
//			}
//			if(board->b256[from-1] == BPAWN){
//				PawnLian ++;
//			}
//			if(PawnLian){
//				if(board->b256[from+16] == BPAWN){
//					board->mulScore /= 4;
//					return 1;
//				}
//			}
//		}
//	}
//
//	//premat_t* pMat = board->pMat;
//	//uint16 cInfo16 = pMat->sixiangInfo8;
//
//	Square bk = PieceListStart(board,BKING);
//	//Square rk = PieceListStart(board,RKING);
//
//	//if((cInfo16 & CK_B_2s) && (cInfo16 & CK_B_2x)){		//对方仕相全
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(bk == 0x37){
//			return 1;
//		}
//	}
//
//	board->mulScore += ADD_CheXPawn_To_1Pawn;    //有车方的加分
//
//	*/
//}