#ifndef END_my_m_MT_R_1CHE_5PAWN_B_1CHE
#define END_my_m_MT_R_1CHE_5PAWN_B_1CHE
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车5兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//我方一车5兵，对方一车
void my_m_MT_R_1CHE_5PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_Che_ByShi[your_shi_num]);

	// fen 2bak1b2/4a4/9/7R1/P1P6/6r1P/9/3A1A3/5K3/9 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 16);

	if((my_shi_num + my_xiang_num) >= 2){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2b1ka3/4a4/4b4/p8/9/4r4/2R1p3p/4B4/4A4/3AK1B2 w - - 0 1
	//if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
	//	MY_EV_SUB(64);
	//}

	// fen 3akab2/9/4b4/5R3/7PP/9/P3r4/9/9/3K5 w - - 0 1
	if(EV_MY_CAN >= 2){
		MY_EV_ADD(EV_MY_CAN * 64);
	}
}

//我方一车5兵，对方一车
//void m_MT_B_1CHE_5PAWN_R_1CHE(typePOS &POSITION, EvalInfo &ei){
//	/*	
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16 = pMat->sixiangInfo8;
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_CheXPawn_To_Che_ByShi[board->R_shi];
//		}
//	}
//
//
//	//if((Info16 & CK_R_2s) && (Info16 & CK_R_2x)){		//对方仕相全
//	//	//if((Info16 & CK_R_2s) && (Info16 & CK_R_2x)){		//对方仕相全
//	//	//	if((rk > 0xc0) && (bk < 0x40)){
//	//	//		return 4;
//	//	//	}
//	//	//}
//	//	if(rk == 0xc7){
//	//		board->mulScore /= 2;
//	//		return 4;
//	//	}
//	//}
//
//	*/
//}