#ifndef END_my_m_MT_R_1pao3pawn_B_1pao1pawn
#define END_my_m_MT_R_1pao3pawn_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮3兵对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int  ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[3]      = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分
//const int  ADD_1PaoXPawn_1Ma1Pawn_ByMaPanw[3]       = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分



void my_m_MT_R_1pao3pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[my_shi_num]);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	

	int mcan = EV_MY_CAN;
	if(mcan == 0){
		RETRUN_MUL(4);
	}

	// fen 3a1kb2/9/3ab2P1/4cC3/9/P5P2/4p4/9/9/3A1K3 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 32);


	// fen 2b1ka3/c3a4/4b1P2/9/p8/6B2/P3P2C1/9/4A4/5K3 w - - 0 1
	if(EV_MY_CAN <= 2){ 
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpao) == MY_RANK6){
				if(PB90(MY_SQ36) == my_pawn){
					if(bit_is_set(ei.attacked_by(your_pao),Square(MY_SQ36)) && bit_is_set(ei.attacked_by(my_pao),Square(MY_SQ36))){
						RETRUN_MUL(4);
					}
				}
				if(PB90(MY_SQ3E) == my_pawn){
					if(bit_is_set(ei.attacked_by(your_pao),Square(MY_SQ3E)) && bit_is_set(ei.attacked_by(my_pao),Square(MY_SQ3E))){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	
	if(EV_MY_CAN <= 2){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			// fen C1bak4/4a4/4b4/9/8p/4P4/P6cP/4B4/4A4/2BA1K3 w - - 0 1
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(8);
			}
			
		}
	}
}
//
//void m_MT_B_1pao3pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[board->B_shi];
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//
//
//	if(bcan == 0){
//		board->rsafe = TRUE;
//	}
//
//	if(rcan == 0){
//		board->bsafe = TRUE;
//	}
//
// 
//
//	*/
//}