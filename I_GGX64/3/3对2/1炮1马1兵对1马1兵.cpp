#ifndef END_my_m_MT_R_1ma1pao1pawn_B_1ma1pawn
#define END_my_m_MT_R_1ma1pao1pawn_B_1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马1兵对1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1ma1pao1pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[my_shi_num]);

	MY_EV_ADD(MaPaoXPawn_MaPawn);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	// fen 4k4/4a2N1/b4a3/2cn4p/7P1/9/9/4B4/4A4/2BA1K3 w - - 120 120
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){

		
		Bitboard ymatt   = POSITION.ma_to_king_attacks_bb(yma);

		if(bit_is_set(ymatt,mpawn)){
			if(PB90(MY_SQ36)  == my_pawn && PB90(MY_SQ2E) == your_pawn){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ3E)  == my_pawn && PB90(MY_SQ34) == your_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2c1k4/4a4/4b4/6P2/9/9/2N6/B1nAB4/3pAK3/9 b - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
			if(StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5){
				if((StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi) 
					|| (StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi)){
				}
				else{
					if(StoY(mma) MY_SMALL_EQL MY_RANK2 && !IsOnSameSide(mma,yk)){
						RETRUN_MUL(6);
					}
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3c1kb2/9/3aba3/2P6/6p2/9/9/3NBA3/4A1n2/3K2B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN == 0 && StoY(ypawn) == MY_RANK6){
			//if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			   RETRUN_MUL(8);
			////}
			//RETRUN_MUL(12);
		}
	}
}

//void m_MT_B_1ma1pao1pawn_R_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bpawn = PieceListStart(board,BPAWN);
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	int bpao = PieceListStart(board,BPAO);
//	int bma  = PieceListStart(board,BMA);
//	Square rk   = PieceListStart(board,RKING);
//	int rma  = PieceListStart(board,RMA);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore +=  96;
//		}
//
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= 96;
//		}
//	}
//
//	//马炮方另外加分
//	board->mulScore -= MaPaoXPawn_MaPawn ;
//
//	// fen 4k4/4a2N1/b4a3/2cn4p/7P1/9/9/4B4/4A4/2BA1K3 w - - 120 120
//	if(StoY(bpao) == 0x6 && StoY(bma) == 0x6){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			if(board->b256[0x6b] == BPAWN && board->b256[0x7a] == RPAWN){
//				if(IsMaCanToOrAt(board,rma,0x6b)){
//					return 4;
//				}
//			}
//			if(board->b256[0x63] == BPAWN && board->b256[0x74] == RPAWN){
//				if(IsMaCanToOrAt(board,rma,0x63)){
//					return 4;
//				}
//			}
//		}
//	}
//
//	*/
//}