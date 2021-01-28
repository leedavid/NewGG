#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che1ma
#define END_my_m_MT_R_1che1pao2pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int PanwAdd = 32;

void my_m_MT_R_1che1pao2pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_CheMa_ByPawnByShi[your_shi_num]);

	// fen 4kab2/4a4/4b4/3n5/4r4/6C2/P2R4P/4B4/4A4/2B1KA3 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = true;
	}
	// fen 4kab2/4a4/4b4/3n5/4r4/6C2/P2R4P/4B4/4A4/2B1KA3 b - - 0 1
	if((my_shi_num == 2 || my_xiang_num == 2)){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = true;
		}
	}
		

	// fen 4kab2/4a4/4b4/5PP2/2n6/9/9/5A3/3R5/3AKCr2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 2){
			if(StoY(yma) MY_LARGE_EQL MY_RANK4){
				MY_EV_SUB(32);
				if(StoY(mpao) MY_LARGE_EQL MY_RANK6){
					MY_EV_SUB(32);
				}
				if(!have_bit(bb_my_pao,MyUpBB[MY_RANK3])){
					MY_EV_SUB(32);
				}
			}
		}
	}

	// fen 4kab2/4a4/4b4/3n5/4r4/6C2/P2R4P/4B4/4A4/2B1KA3 b - - 0 1
	// 有二个边兵
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			if(have_bit(bb_my_pawn,LeftBB[0x1])){
				MY_EV_SUB(32);
			}
			if(have_bit(bb_my_pawn,RightBB[0x7])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3ak4/9/3ab3b/9/5P3/9/PR7/n3r4/4AC3/4K4 b - - 0 1
	if(my_shi_num >= 1 && MY_SQ55 == mk){
		if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
			MY_EV_ADD(64);
			if(!m_have_bit(_mm_andnot_si128(MY_ATTACK,ei.attacked_by(your_ma)))){
				MY_EV_ADD(EV_MY_CAN * 16);
				if(abs(StoX(yma) - 0x4) == 4){
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
	}

	// fen 3k1ab2/4a4/4b4/C3R4/1r7/P8/8P/3A5/3KA1n2/9 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(!IsOnSameSide(yma,mk)){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	if((my_shi_num + my_xiang_num) == 0 && StoY(yma) MY_LARGE_EQL MY_RANK5){
		MY_EV_SUB(80);
	}

	if((my_shi_num + my_xiang_num) <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK4){
		MY_EV_SUB(64);
		if(mk != MY_SQ55){
			MY_EV_SUB(32);
		}
	}
	// fen 5k3/4a4/2Pab4/3P5/4C1b2/5r3/1n1R5/9/4A4/4K4 b
	if(mk == MY_SQ55){
	   MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 3ak4/9/3ab3b/9/5P3/9/PR7/n3r4/4AC3/4K4 b - - 0 1
	if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 16);
	}


	// fen 5k3/4a4/5a3/3PP4/6n2/9/C3R4/9/4K4/2r6 b - - 0 1
    if(StoY(yma) MY_SMALL_EQL MY_RANK5 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(16);
		MY_EV_ADD(EV_MY_CAN * 16);
		if((your_shi_num + your_xiang_num) <= 2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3k1ab2/4a4/4b4/4C4/3r5/2B6/4PR2P/2n6/4AK3/9 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
        if(!IsOnSameSide(yma,mk)){
			MY_EV_ADD(16);			
		}
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 4kab2/4a4/4b4/3n5/3r5/P1P2R3/9/4B4/9/2B1KC3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 2){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5]) && StoY(yma) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(8);
			}
		}
		if(EV_MY_SAFE){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kab2/4a4/4b4/5PP2/2n6/9/9/5A3/3R5/3AKCr2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 2){
			if(StoY(yma) MY_LARGE_EQL MY_RANK4){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
					if(StoY(mpao) MY_LARGE_EQL MY_RANK8){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3akab2/PP7/4b4/R8/9/9/2r4n1/B6C1/4A4/2B1KA3 r
	if(your_xiang_num == 2 && your_shi_num == 2 && MY_SQ04 == yk){
		if(!have_bit(MyLowBB[MY_RANK1],bb_my_pawn)){
			if(StoX(yche) == 0x2 && !have_bit(bb_my_pawn,RightBB[0x1])){
				MY_EV_SUB(96);
				if(StoY(mpao) MY_LARGE_EQL MY_RANK4){
					MY_EV_SUB(64);
					RETRUN_MUL(12);
				}
			}
			if(StoX(yche) == 0x6 && !have_bit(bb_my_pawn,LeftBB[0x7])){
				MY_EV_SUB(96);
				if(StoY(mpao) MY_LARGE_EQL MY_RANK4){
					MY_EV_SUB(64);
					RETRUN_MUL(12);
				}
			}
		}
	}


}
//
//void m_MT_B_1che1pao2pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  ADD_ChePaoPawn_CheMa_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
