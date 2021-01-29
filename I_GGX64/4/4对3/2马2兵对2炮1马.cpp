#ifndef END_my_m_MT_R_2ma2pawn_B_2pao1ma
#define END_my_m_MT_R_2ma2pawn_B_2pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马2兵对2炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_2ma2pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2pao1ma_2maXpawn_ByShi[your_shi_num]);	

	Square mk = my_king_pos;

	if((my_shi_num + my_xiang_num) <= 2){
		MY_EV_SUB(168);
	}

	// fen 2bak4/4a4/4b4/3PP4/4c4/5nN2/5N3/3A5/4K2c1/6B2 b - - 0 1
	if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(have_bit(lp,RankBB_A[MY_RANK3])){
			Bitboard pma = m_and(bb_my_ma,m_and(MyUpBB[MY_RANK8],MyLowBB[MY_RANK2]));
			if(count_1s(pma) == 2){
				RETRUN_MUL(8);
			}
		}
	}

}

//void m_MT_B_2ma2pawn_R_2pao1ma(typePOS &POSITION, EvalInfo &ei){
//
//	/*Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	//int rcan = RpawnAlreadyRiver(board);
//	//int bcan = BpawnAlreadyRiver(board);
//	//
//	//for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//	//	if(StoY(from) > StoY(bk)){
//	//		board->mulScore += ADD_2pao1ma_2pao1pawn_ByShi[board->B_shi];
//	//	}
//	//}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2pao1ma_2maXpawn_ByShi[board->R_shi];
//		}
//	}
//
//
//	//board->mulScore += rcan * 64;
//	//board->mulScore -= bcan * 64;
//
//	*/
//}