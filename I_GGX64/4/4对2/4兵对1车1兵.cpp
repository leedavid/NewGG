#ifndef END_my_m_MT_R_4pawn_B_1che1pawn
#define END_my_m_MT_R_4pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_4pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheXPawn_To_PawnByShi[my_shi_num]);

	MY_EV_SUB(ADD_CheXPawn_To_3Pawn);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;


	Bitboard lp = My_get_connect_Pawn(POSITION);
	if (have_bit(lp, RankBB_A[MY_RANK3])){
		MY_EV_ADD(EV_MY_CAN * 64);
	}

	// fen 3ak1b2/4a4/2P1b4/9/9/3R5/2p1pp2p/4BA2B/9/3K1A3 r
	if (my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		if (have_bit(lp, RankBB_A[MY_RANK3])){
			RETRUN_MUL(2);
		}
	}

	// fen 3akab2/1r7/4b4/4PPP2/9/9/9/5A3/3pAK3/9 w - - 0 1
	if(my_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK8){

		bool isok = false;
		if(!IsOnSameSide(ypawn,mk) && !have_bit(bb_my_shi,MyLowBB[MY_RANK8])){
			if(StoX(ypawn) < 0x4 && PB90(MY_SQ44) == my_shi){
				isok = true;
			}
			if(StoX(ypawn) > 0x4 && PB90(MY_SQ42) == my_shi){
				isok = true;
			}
		}
		if(isok){
			if(bit_is_set(lp,Square(MY_SQ1F)) || bit_is_set(lp,Square(MY_SQ20)) || bit_is_set(lp,Square(MY_SQ1E))){
				if(count_1s(lp) == 3){
					RETRUN_MUL(2);
				}				
				if(count_1s(lp) >= 2 && count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 3){
					RETRUN_MUL(2);
				}				
			}
		}
	}
}
//
//void m_MT_B_4pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheXPawn_To_PawnByShi[board->B_shi];
//		}
//	}
//
//	board->mulScore += ADD_CheXPawn_To_3Pawn;
//	*/
//}


//const int ADD_CheXPawn_To_3Pawn                     =  168;             //车兵对3兵,车方的加分
//const int ADD_CheXPawn_To_2Pawn                     =  196;             //车兵对2兵,车方的加分
//const int ADD_CheXPawn_To_1Pawn                     =  256;             //车兵对1兵,车方的加分
//const int ADD_CheXPawn_To_PawnByShi[3]              =  {196,128, 96};   //车兵对兵, 车方兵的加分