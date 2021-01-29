#ifndef END_my_m_MT_R_2ma4pawn_B_2pao1pawn
#define END_my_m_MT_R_2ma4pawn_B_2pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马4兵对2炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma4pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_2Pao1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Pawn_2MaXPawn_ByPawn[my_shi_num]);

    // fen 3aka3/4n4/9/6p1p/4n4/p8/2p5P/4C4/4A4/2C1KAB2 b - - 1 1
    //如果1炮控制了二马,就是很大的优势. 

	Square mk = my_king_pos;
	Bitboard bsuper = POSITION.Pao_Super_bb(mk);

	Bitboard bp = m_and(bsuper,bb_your_pao);

	while(m_have_bit(bp)){
		Square ypao = pop_1st_bit_sq(bp);
		if(count_1s(BetweenBB[ypao][mk],bb_my_ma) == 2){
			MY_EV_SUB(256);
		}
	}
	

    //int bma1 = PieceListStart(board,BMA);
	//int bma2 = NextPiece(board,bma1);
	//if(board->b256[0x37] == BKING && board->b256[0x36] == BSHI 
	//	&& board->b256[0x38] == BSHI && board->b256[0x47] == BMA){
	//		//if(LowFirstSq256(board,0x47) == BMA 
	//		int ma = LowFirstSq256(board,0x47);
	//		if(ma != 0x47 && board->b256[ma] == BMA){
	//			int pao = LowFirstSq256(board,ma);
	//			if(board->b256[pao] == RPAO){
	//				board->mulScore -= 
	//			}
	//		}			
	//}


	//*/

}

//void m_MT_B_2ma4pawn_R_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Pawn_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_2Pao1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//
//}
