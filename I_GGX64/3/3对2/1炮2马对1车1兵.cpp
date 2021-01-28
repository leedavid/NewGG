#ifndef END_my_m_MT_R_1pao_2ma_B_1che1pawn
#define END_my_m_MT_R_1pao_2ma_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//1炮2马对1车, 炮马方要加分

void my_m_MT_R_1pao_2ma_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	//如果没有过河,或者马炮方有仕
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	//if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 || my_shi_num >= 1){
	//	MY_EV_ADD(Add_1炮2马对1车1兵);
	//}
	if(EV_YOUR_CAN == 0 || my_shi_num == 2){
		MY_EV_ADD(Add_1炮2马对1车1兵);
	}

	MY_EV_SUB(32);

	if(my_shi_num <= 1 && my_xiang_num <= 1){
		MY_EV_SUB(EV_YOUR_CAN * 64);
	}

	// fen 2bak4/4a4/4b4/8N/9/p7r/9/2N1BC3/9/2B2K3 w - - 0 1
	if(my_xiang_num == 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK5){
		MY_EV_ADD(80);
	}
	// fen 4k4/4a4/1N3a3/1N7/3C5/2B6/4p4/9/4K4/3r5 b - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && (my_shi_num >= 1 || my_xiang_num >= 1)){
		if((your_shi_num + your_xiang_num) <= 2){
			MY_EV_ADD(96);
			if(your_xiang_num == 0){
				MY_EV_ADD(32);
			}
		}
	}
	

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_CheMaXPawn_To_1Pao2Pawn_ByPawn[my_shi_num]);

}


//void m_MT_B_1pao_2ma_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn > 0x80 || board->B_shi > 0){
//		board->mulScore -= Add_1炮2马对1车1兵;
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  Add_1炮2马对1车1兵_byPawn_Shi[board->B_shi];
//		}
//	}
//
//
//	*/
//}



//void my_m_MT_R_2pao_1ma_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){
//
//
//	//如果没有过河,或者马炮方有仕
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	if(bpawn < 0x80 || board->R_shi > 0){
//		board->mulScore += Add_2炮1马对1车1兵;
//	}
//
//	return 16;
//}
//
//
//void m_MT_B_2pao_1ma_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
//
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn > 0x80 || board->B_shi > 0){
//		board->mulScore -= Add_2炮1马对1车1兵;
//	}
//
//	return 16;
//}

