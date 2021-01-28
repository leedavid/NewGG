#ifndef END_my_m_MT_R_1che1pao2pawn_B_2che1pawn
#define END_my_m_MT_R_1che1pao2pawn_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对2车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int ADD_2CheXPawn_1Che1Pao1Pawn_ByShi[3]      = {96, 64, 32};            //2车x兵对1车1炮1兵, 兵方的加分
//const int ADD_1Che1PaoXPawn__2Che1Pawn_ByShi[3]     = {96, 64, 32}; 


void my_m_MT_R_1che1pao2pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Che1PaoXPawn__2Che1Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2CheXPawn_1Che1Pao1Pawn_ByShi[my_shi_num]);
	
	// fen 2b1ka3/4a4/4b4/3R5/p1rc5/4pp3/P6R1/4B4/4A4/2BAK4 b - - 25 25
	// fen 2b1ka3/4a4/4b4/3R5/p1rc5/4pp3/P6R1/4B4/4A4/2BAK4 b - - 25 25
	int ycan = EV_YOUR_CAN;
	if(ycan == 0){
		if((my_shi_num + my_xiang_num) == 4 && mk == MY_SQ55 && PB90(MY_SQ4C) == my_shi){
			MY_EV_ADD(96);
		}
	}

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 4kab2/4a4/4b4/4R4/1r1PP4/7p1/r8/4BC3/4A4/3AK1B2 w - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
        if(bit_is_set(lp,MY_SQ1F) || bit_is_set(lp,MY_SQ28)){
			MY_EV_ADD(96);
		}
	}

	// fen 9/3ka4/9/9/4p4/6BrC/2r1P1R1P/4BA3/9/3AK4 w - - 0 51
	int malr = My_pawn_already_over_river(POSITION);
	if(malr == 0){
		MY_EV_SUB(60);
	}

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	//炮不在家
	if(StoY(mpao) MY_SMALL MY_RANK7){
		MY_EV_SUB(64);
	}

	// fen 2baka3/9/4b4/2p4r1/9/2P5C/P4R3/4B4/3rA4/4KAB2 b - - 0 1
	if((my_shi_num + my_xiang_num) == 4 && mk == MY_SQ55){
		if(StoY(mche) == MY_RANK6){
			if(PB90(MY_SQ2F) == my_pawn && MY_SQ1D == ypawn){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ33) == my_pawn && MY_SQ21 == ypawn){
				RETRUN_MUL(4);
			}
		}
	}

	if((my_shi_num + my_xiang_num) == 4 && mk == MY_SQ55){
		if(malr == 0){
			RETRUN_MUL(8);
		}
	}
	// fen 4kab2/4a4/4b4/4R4/1r1PP4/7p1/r8/4BC3/4A4/3AK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(bit_is_set(lp,MY_SQ1F) || bit_is_set(lp,MY_SQ28)){
			MY_EV_ADD(64);
			if(StoY(mpao) MY_LARGE_EQL StoY(ypawn)){
				RETRUN_MUL(8);
			}
		}
	}

}

//void m_MT_B_1che1pao2pawn_R_2che1pawn(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2CheXPawn_1Che1Pao1Pawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Che1PaoXPawn__2Che1Pawn_ByShi[board->R_shi];
//		}
//	}
//
//		// fen 2b1ka3/4a4/4b4/3R5/p1rc5/4pp3/P6R1/4B4/4A4/2BAK4 b - - 25 25
//	if(rcan == 0){
//		if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//			board->mulScore -= ADD_1che1paoXpawn_To_2che1pawn_ByPsafe;	
//		}
//	}
//
//
//
//
//	*/
//}