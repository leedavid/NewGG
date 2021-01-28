#ifndef END_my_m_MT_R_1che4pawn_B_1che1pao
#define END_my_m_MT_R_1che4pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


////const int const_Pawn_Shi_Add[3] = {180, 120, 32};

//车3兵对车炮
void my_m_MT_R_1che4pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	//看一下对方是不是有仕

	// fen 2bak4/9/4b4/4R4/P3c4/4r1P2/8P/4B4/9/2B1KA3 b - - 0 0 //这个FEN 应是红优

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	if((my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]);
	}
	else{
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Ma2Pawn_ByPawn[your_shi_num]/2);
	}

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	if(isStringByChe(POSITION,mche,ypao,yche)){
		MY_EV_ADD(ADD_ChePawn_To_ChePao_By_StringPao);
	}

	// fen 2b1k1b2/4a4/9/2P1P4/4P2P1/5r3/3R5/9/4K4/3A4c w - - 0 1
	Bitboard mop = m_and(bmp, MyUpBB[MY_RANK5]);
	if (count_1s(mop) >= 2){
		MY_EV_ADD(count_1s(mop) * 16);
		if (your_shi_num <= 1){
			MY_EV_ADD(32);
		}
		if (StoY(ypao) MY_LARGE_EQL MY_RANK5){
			MY_EV_ADD(32);
		}
	}
	//fen 3ak4/4a4/9/4R4/6P2/2P6/4Pr2P/9/5c3/4K1B2 w - - 0 1
	if (your_xiang_num == 0 ){
		if (EV_MY_CAN >= 3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}

//void m_MT_B_1che4pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16 = pMat->sixiangInfo8;
//
//	Square rk    = PieceListStart(board,RKING);
//	//Square rk    = PieceListStart(board,RKING);
//
//	//Square rpawn1 = PieceListStart(board,RPAWN);
//	//Square rpawn2 = NextPiece(board,rpawn1);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//
//			if(board->B_shi != 0 || board->B_xiang != 0){
//			    board->mulScore -= ADD_ChePawn_To_ChePao_Pawn_Shi_Add[board->R_shi];
//			}
//			else{
//				board->mulScore -= ADD_ChePawn_To_ChePao_Pawn_Shi_Add[board->R_shi]/2;
//			}
//		}
//	}
//
//	int rche = PieceListStart(board,RCHE);
//	int bche = PieceListStart(board,BCHE);
//	int rpao = PieceListStart(board,RPAO);
//
//	//如果车炮被牵制了, 则炮方要减分
//	if(IsStringByChe(board,rche,rpao,bche)){
//		board->mulScore -= ADD_ChePawn_To_ChePao_By_StringPao;
//	}
//
//	*/
//}