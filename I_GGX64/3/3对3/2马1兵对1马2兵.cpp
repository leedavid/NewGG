#ifndef END_my_m_MT_R_2ma1pawn_B_1ma2pawn
#define END_my_m_MT_R_2ma1pawn_B_1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马1兵对1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_2ma1pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Ma2Pawn_2MaXPawn_ByPawn[my_shi_num]);

	int ycan = EV_YOUR_CAN;

	// fen 3k2b2/4a4/9/4P4/9/6n2/3N5/4K3N/2pp5/9 b - - 0 1
	if(count_1s(bb_your_pawn,MyLowBB[StoY(mk)]) == 2){
		MY_EV_ADD(64);
		MY_EV_ADD(EV_MY_CAN * 64);
	}

	// fen 4kab2/4a4/5n3/6N2/4p4/5NB2/2p1P4/9/4AK3/2BA5 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
         if(PB90(MY_SQ28) == your_pawn && PB90(MY_SQ3A) == my_pawn){
			 if(PB90(MY_SQ17) == your_ma || PB90(MY_SQ15) == your_ma){
				 if(ycan >= 1){
					 RETRUN_MUL(4);
				 }
			 }
		 }
	}

	//if(board->B_shi == 2 && board->B_xiang >= 1 && StoY(bk) <= 0x4){
	//	if(board->b256[0x77] == BPAWN && board->b256[0x97] == RPAWN){
	//		if(board->b256[0x95] == BPAWN || board->b256[0x99] == BPAWN){
	//			if(IsMaCanToOrAt(board,bma,0x77)){
	//				return 4;
	//			}
	//		}
	//	}
	//}



	//*/

}

//void m_MT_B_2ma1pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk  = PieceListStart(board,BKING);
//	int rma = PieceListStart(board,RMA);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Ma2Pawn_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_1Ma2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//		// fen 4kab2/4a4/5n3/6N2/4p4/5NB2/2p1P4/9/4AK3/2BA5 b - - 120 120
//	if(board->R_shi == 2 && board->R_xiang >= 1 && StoY(rk) >= 0xb){
//		if(board->b256[0x87] == RPAWN && board->b256[0x67] == BPAWN){
//			if(board->b256[0x65] == RPAWN || board->b256[0x69] == RPAWN){
//				if(IsMaCanToOrAt(board,rma,0x87)){
//					return 4;
//				}
//			}
//		}
//	}
//
//	*/
//
//}
