#ifndef END_my_m_MT_R_2ma1pawn_B_1ma1pao
#define END_my_m_MT_R_2ma1pawn_B_1ma1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1马1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2ma1pawn_B_1ma1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_1Pao1Ma_ByPawn[your_shi_num]);

	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(32);
	}

	// fen 9/4ak3/5a2N/3P5/3n3N1/6B2/7c1/3AB4/4A4/4K4 b - - 0 1
	if(your_shi_num == 2){
		MY_EV_SUB(64);
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(64);
		}
	}

	// fen 3a1k3/4a4/4b4/c4P3/6b2/2N6/9/B2A5/1N7/1n2K4 b - - 0 1
	if (StoY(yma) == MY_RANK9) {
		if (PB90(yma MY_SUB 9) != EMPTY) {
			MY_EV_ADD(64);
		}
	}

	// fen 4k1b2/4a4/9/9/2b6/4pn3/9/nCN2A3/4A4/5K3 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(64);
		}
	}

	// fen 4ka3/4a4/4N4/1N7/5P3/6B2/5c3/9/4A1n2/5K3 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && your_xiang_num == 0){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
	}


	// fen 3ak4/4a4/4b3b/9/2p3p2/9/6nn1/3AB2N1/4A4/2BC1K3 w - - 120 120
	if((your_shi_num + your_xiang_num) == 4){
		if(my_shi_num == 2 || my_xiang_num == 2){
			RETRUN_MUL(2);
		}
	}

	// fen 4k1b2/4a2N1/9/N8/9/P8/9/4B4/2n1A4/3K1AB1c b - - 0 0
	if((your_xiang_num + your_shi_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn)  MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(96);
		}
	}

	// fen 3a5/4ak3/4b1N2/1N2P4/4c4/7n1/9/B2AB4/4A4/4K4 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2){
		if((your_shi_num + your_xiang_num) >= 3){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/4k4/9/9/3N5/2B6/1n3n3/3AB4/2p1AC3/4K4 w - - 132 132
	if(StoY(mpawn) MY_LARGE StoY(yk)){
		if((your_shi_num + your_xiang_num) >= 2){
			// fen 4k4/4a4/3a5/1Nn1N4/5P3/9/9/Bc1A5/4A4/4K1B2 b - - 0 1
			if(your_shi_num == 2 && StoY(yk) == MY_RANK0 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(64);
				RETRUN_MUL(6);
			}
			RETRUN_MUL(8);
		}
	}

	// fen 3a5/2P2k3/3c5/7N1/2bN2b2/2B6/5n3/3AB4/4A4/5K3 w - - 0 0
	if(StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		MY_EV_SUB(96);
		if(your_shi_num >= 1 && your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}
    
	// fen 3a1k3/9/3a5/9/4nN3/9/9/B2A1A3/6n2/3C1K2p b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		MY_EV_ADD(96);
		if(your_shi_num == 2 && StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_2ma1pawn_R_1ma1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bpawn = PieceListStart(board,BPAWN);
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
//			//if(bcan <= 0){             //兵一个也不能过河,就是和棋
//			//	return 1; 
//			//}
//			if(board->B_xiang == 2 || board->B_shi == 2){
//				return 1;
//			}
//		}
//	}
//
//	// fen 4k1b2/4a2N1/9/N8/9/P8/9/4B4/2n1A4/3K1AB1c b - - 0 0
//	if((board->R_shi + board->R_xiang) >= 2 && StoY(rk) >= 0xb){
//		if(StoY(bpawn) <= 0x9){
//			board->mulScore += 64;
//		}
//	}
//
//	// fen 3a5/2P2k3/3c5/7N1/2bN2b2/2B6/5n3/3AB4/4A4/5K3 w - - 0 0
//	if(StoY(bpawn) >= StoY(rk)){
//		if(board->R_shi >= 1 && board->R_xiang == 2){
//			return 8;
//		}
//	}
//
//	if(StoY(bpawn) < StoY(rk)){
//		if((board->R_shi + board->R_xiang) >= 2){
//			return 8;
//		}
//	}
//
//
//	*/
//}