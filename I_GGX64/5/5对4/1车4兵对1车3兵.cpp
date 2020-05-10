#ifndef END_my_m_MT_R_1che4pawn_B_1che3pawn
#define END_my_m_MT_R_1che4pawn_B_1che3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对1车3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che4pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_1Che1Pao1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheXPawn_To_1Che1Pao1Pawn_ByPawn[my_shi_num]);

	//1, 红方只有一个兵可过河． 2,且只过河了一个兵 3,黑方只有一个兵可过河，就是和棋
	// fen 2bak4/4a4/2P1b4/p6rp/4p4/2R5P/P5P2/4B4/9/3AKAB2 w - - 3 3
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		int mcan = EV_MY_CAN;
		if(mcan <= 1){
			RETRUN_MUL(8);
		}
	}

/*
int rcan = RpawnCanOverLiver(board);
int bcan = BpawnCanOverLiver(board);

	Square rk   = PieceListStart(board,RKING);
	Square bk   = PieceListStart(board,BKING);

	//1, 红方只有一个兵可过河． 2,且只过河了一个兵 3,黑方只有一个兵可过河，就是和棋
	// fen 2bak4/4a4/2P1b4/p6rp/4p4/2R5P/P5P2/4B4/9/3AKAB2 w - - 3 3
	if(rcan <= 1 && RpawnAlreadyRiver(board) <= 1){
		if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
			board->bsafe = TRUE;
		}
	}

	if(BpawnAlreadyRiver(board) <= 1){
		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
			board->rsafe = TRUE;
		}
	}

	*/
}

//void m_MT_B_1che4pawn_R_1che3pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	Square rk   = PieceListStart(board,RKING);
//	Square bk   = PieceListStart(board,BKING);
//
//	//1, 红方只有一个兵可过河． 2,且只过河了一个兵 3,黑方只有一个兵可过河，就是和棋
//	// fen 2bak4/4a4/2P1b4/p6rp/4p4/2R5P/P5P2/4B4/9/3AKAB2 w - - 3 3
//	if(bcan <= 1 && BpawnAlreadyRiver(board) <= 1){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			board->rsafe = TRUE;
//		}
//	}
//
//	if(RpawnAlreadyRiver(board) <= 1){
//		if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//			board->bsafe = TRUE;
//		}
//	}
//
//
//
//	*/
//}