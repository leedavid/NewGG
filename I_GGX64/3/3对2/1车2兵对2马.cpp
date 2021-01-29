#ifndef END_my_m_MT_R_1che2pawn_B_2ma
#define END_my_m_MT_R_1che2pawn_B_2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2兵对2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//#define ADD_ChePawn_To_MaPao_By_Panw   128              //车兵对马炮,车兵方兵要加分,因为马炮太难杀对方了
//#define ADD_ChePawn_To_MaPao_By_Che    128              //车兵对马炮,车兵方车要加分,因为马炮太难杀对方了

//我方1车2兵,对方是马炮
void my_m_MT_R_1che2pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePawn_To_2Ma_By_PawnByShi[your_shi_num]);
}

//void m_MT_B_1che2pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	board->mulScore -= ADD_ChePawn_To_MaPao_By_Che;
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_ChePawn_To_2Ma_By_PawnByShi[board->R_shi];
//		}
//	}
//	*/
//}
