#ifndef END_my_m_MT_R_2ma2pawn_B_1ma1pao
#define END_my_m_MT_R_2ma2pawn_B_1ma1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马2兵对1马1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2ma2pawn_B_1ma1pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_1Pao1Ma_ByPawn[your_shi_num]);

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	
	//Square mk = my_king_pos;
	int mcan = EV_MY_CAN;
	// fen 3k2b2/2P1a4/4ba3/9/3N5/2P6/c5N2/3AB4/8n/2BAK4 w - - 32 32
	// fen 3ak4/4a4/4b3b/9/2p3p2/9/6nn1/3AB2N1/4A4/2BC1K3 w - - 120 120
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){  //兵一个也不能过河,就是和棋
			RETRUN_MUL(4);
		}
	}

	// fen 3a5/3Pa4/2P1bkN2/4c4/3Nn1b2/2B6/9/3AB4/4A4/4K4 b - - 124 124
	if((your_shi_num + your_xiang_num) == 4){
		Bitboard p1 = m_and(bb_my_pawn,MyUpBB[StoY(yk)]);
		if(count_1s(p1) >= 1){
			if(StoX(yk) == 0x3){
				Bitboard p2 = m_and(bb_my_pawn,RightBB[0x4]);
				if(count_1s(p2) == 2){
					RETRUN_MUL(4);
				}
			}
			if(StoX(yk) == 0x5){
				Bitboard p2 = m_and(bb_my_pawn,LeftBB[0x4]);
				if(count_1s(p2) == 2){
					RETRUN_MUL(4);
				}
			}
		}
	}



	// fen 2ba5/4ak3/6N1b/3N5/P3P4/2B6/9/9/2nKA4/7c1 b - - 11 11
	//如果黑方是仕相全,要加一些分
	if((your_shi_num + your_xiang_num) == 4){
		RETRUN_MUL(8);
	}

	// fen 4k4/2PPac3/3a2N2/9/5Nb2/9/2n6/9/4K4/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
		Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(!have_bit(RightBB[0x3],ghp) && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(8);
			}
			if(!have_bit(LeftBB[0x5],ghp) && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}

}

//void m_MT_B_2ma2pawn_R_1ma1pao(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square rk = PieceListStart(board,RKING);
//	int bcan = BpawnCanOverLiver(board);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_1Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 3ak4/4a4/4b3b/9/2p3p2/9/6nn1/3AB2N1/4A4/2BC1K3 w - - 120 120
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			if(bcan <= 1){             //兵一个也不能过河,就是和棋
//				return 1; 
//			}
//		}
//	}
//
//	
//	// fen 3a5/3Pa4/2P1bkN2/4c4/3Nn1b2/2B6/9/3AB4/4A4/4K4 b - - 124 124
//    Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	if(StoY(bpawn1) >= StoY(rk) && StoY(bpawn2) >= StoY(rk)){
//		if(board->R_shi == 2 && board->R_xiang == 2){
//			return 4;
//		}
//	}
//
//	// fen 2ba5/4ak3/6N1b/3N5/P3P4/2B6/9/9/2nKA4/7c1 b - - 11 11
//	//如果黑方是仕相全,要加一些分
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		board->mulScore += 96;
//		return 8;
//	}
//
//
//	*/
//}