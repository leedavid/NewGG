#ifndef END_my_m_MT_R_1che1pawn_B_2ma
#define END_my_m_MT_R_1che1pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//#define ADD_ChePawn_To_MaPao_By_Panw   128              //车兵对马炮,车兵方兵要加分,因为马炮太难杀对方了
//#define ADD_ChePawn_To_MaPao_By_Che    128              //车兵对马炮,车兵方车要加分,因为马炮太难杀对方了

//我方1车1兵,对方是马炮
void my_m_MT_R_1che1pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk    = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	int mcan = EV_MY_CAN;

	MY_EV_ADD(ADD_ChePawn_To_MaPao_By_Che);

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_ChePawn_To_2Ma_By_PawnByShi[your_shi_num]);
	}

	if((your_shi_num + your_xiang_num) == 4){
		if(StoY(yk) == MY_RANK1){
			RETRUN_MUL(2);
		}
	}

	// fen 3k5/9/4b4/9/6b2/7p1/9/4BN3/2r1A4/2N1K1B2 w - - 121 121
	if(your_shi_num >= 1 && your_xiang_num == 2 && PB90(MY_SQ16) == your_xiang){
		// 二个马都在家里
		if(count_1s(bb_your_ma,MyUpBB[MY_RANK7]) == 2){
		    if(mcan == 0) {
				RETRUN_MUL(2);
			}
		}

		// 
		if(StoX(mpawn) >= 0x7 && PB90(MY_SQ17) == your_ma){
			if(PB90(MY_SQ02) == your_ma){
				RETRUN_MUL(4);
			}
		}
		if(StoX(mpawn) <= 0x1 && PB90(MY_SQ15) == your_ma){
			if(PB90(MY_SQ06) == your_ma){
				RETRUN_MUL(4);
			}
		}
	}
}

//void m_MT_B_1che1pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	board->mulScore -= ADD_ChePawn_To_MaPao_By_Che;
//
//	Square rk = PieceListStart(board,RKING);
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	//int rma1 = PieceListStart(board,RMA);
//	//int rma2 = NextPiece(board,rma1);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  ADD_ChePawn_To_2Ma_By_PawnByShi[board->R_shi];
//		}
//	}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			board->mulScore /= 4;
//			return 2;
//		}
//	}
//
//	// fen 3k5/9/4b4/9/6b2/7p1/9/4BN3/2r1A4/2N1K1B2 w - - 121 121
//	if(board->R_shi >= 1 && board->R_xiang == 2 && board->b256[0xa7] == RXIANG){
//		if(StoY(bpawn) < 0xa){
//			if(StoX(bpawn) >= 0xa){
//				if(board->b256[0xa8] == RMA && board->b256[0xc5] == RMA){
//					return 4;
//				}
//			}
//			if(StoX(bpawn) <= 0x4){
//				if(board->b256[0xa6] == RMA && board->b256[0xc9] == RMA){
//					return 4;
//				}
//			}
//		}
//	}
//
//	*/
//}