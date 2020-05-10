
#ifndef END_my_m_MT_R_2pao1pawn_B_1pao2pawn
#define END_my_m_MT_R_2pao1pawn_B_1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int _OnlyOnePawnCanOverRiver = 96; 

 void my_m_MT_R_2pao1pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
	 // ADD_MY
	 Square yk = your_king_pos;
	 Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	 int pmok = (int)count_1s(bmp);
	 MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao2Pawn_ByPawn[your_shi_num]);
	 // SUB
	 Square mk = my_king_pos;
	 Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	 int pyok = (int)count_1s(ymp);
	 MY_EV_SUB(pyok * ADD_1Pao2Pawn_2PaoXPawn_ByPawn[my_shi_num]);
	
	 
	 int ycan = EV_YOUR_CAN;
	 Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	 Square ypawn1 = S90_from_piecelist(POSITION, your_pawn, 0);
	 Square ypawn2 = S90_from_piecelist(POSITION, your_pawn, 1);

	 Bitboard lp = Your_get_connect_Pawn(POSITION);
	 if (have_bit(lp, MyUpBB[MY_RANK7])){
		 MY_EV_SUB(64);
	 }

	 //board->mulScore 
	 //如果黑方只有一个兵可过河,则要扣分
	 if(ycan <= 1){
		 MY_EV_ADD(32);
	 }	

	 // fen 4k4/5P3/3aCa3/4c4/9/5C3/4pp3/4B4/4A4/3K1AB2 b - - 0 1
	 if ((my_shi_num + my_xiang_num) >= 2){
		 if (your_shi_num == 2 && StoY(yk)  MY_SMALL_EQL MY_RANK1){
			 if (StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				 if (PB90(MY_SQ16) == my_pao && !have_bit(bb_your_shi, MyUpBB[MY_RANK2])){
					 if (PB90(MY_SQ1F) == your_pao){
						 if (count_1s(bb_your_pawn, RankBB_A[MY_RANK6]) == 2){
							 if (abs(StoX(ypawn1) - StoX(ypawn2)) <= 2)
								 RETRUN_MUL(2);
						 }
					 }
				 }
			 }
		 }
	 }

	 // fen 3k1ab2/4a4/8b/4P2C1/4C4/4c4/3pp4/9/4A4/4K1B2 w - - 0 1
	 if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
	    
		if(bit_is_set(lp,MY_SQ3A) || bit_is_set(lp,MY_SQ31)){
			MY_EV_SUB(64);

			// fen 4kab2/3Pac3/4b4/3C5/9/3C5/3pp4/9/4A4/4K1B2 b - - 0 1
			if(bit_is_set(ei.attacked_by(your_pao),mpawn) 
				&& (bit_is_set(ei.attacked_by(my_pao),mpawn))
				&& abs(StoX(mpawn) - 0x4) >= 1){
					RETRUN_MUL(6);
			}

			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2 || abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(8);
			}

		}
	 }

 }

//  void m_MT_B_2pao1pawn_R_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao2Pawn_2PaoXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Pao2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//
//	 int rcan = RpawnCanOverLiver(board);
//	 //如果红方只有一个兵可过河,则要扣分
//	 // fen 3k1ab2/4a4/4b4/8C/2p1c4/P8/6p2/4B4/5K3/6C2 b - - 1 1
//	 if(rcan <= 1){
//		 board->mulScore -= _OnlyOnePawnCanOverRiver;
//	 }
//
//	 */
// }