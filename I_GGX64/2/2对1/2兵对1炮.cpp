#ifndef END_my_m_MT_R_2pawn_B_1pao
#define END_my_m_MT_R_2pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int PawnShiAdd[3] = {128,48,0};


void my_m_MT_R_2pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square yk   = your_king_pos;
	Square mk   = my_king_pos;
	int mcan =  EV_MY_CAN;	
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	Bitboard bb = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);

	MY_EV_ADD((sint16)count_1s(bb) * ADD_XPawnToPao_ByPawnShi[your_shi_num]);

	// fen 3k2b2/9/9/9/9/9/3C5/3A5/2p2p3/4K1B2 b - - 0 0
	//	黑方二个兵不在一边,可能给吃了
	if(your_shi_num != 0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(!IsOnSameSide(mpawn1,mpawn2)){
				MY_EV_SUB(128);
			}
		}
	}
	// 红方有二个相,
	if(my_xiang_num == 2){
		EV_MY_SAFE = TRUE;
	}

	if(my_xiang_num >= 1 && my_shi_num != 0){
		EV_MY_SAFE = TRUE;
	}
	// 对方也没有仕,就和了
	if(your_shi_num == 0){
		EV_MY_SAFE = TRUE;
	}

	if(your_shi_num == 1){
		//<<象棋残局例典>>，第5局  低兵例和仕
		//双底兵例和炮仕 fen 3P1P3/8c/3a1k3/9/9/9/9/9/9/4K4 w
		if(PB90(MY_SQ04) == my_pawn && StoX(mk) == 0x4){
			if(PB90(MY_SQ03) == my_pawn || PB90(MY_SQ05) == my_pawn){
				EV_MY_SAFE = TRUE;
			}
		}
	}

	if(your_shi_num == 2){
		EV_YOUR_SAFE = TRUE;
	}

	if(your_shi_num >= 1 && your_xiang_num >= 1){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 9/3k5/9/7C1/9/2B3B2/9/4K4/2ppA4/3A5 w - - 97 97这个不和
	// 红方二个兵,黑方一个炮
	if(StoY(mpawn1) == StoY(mpawn2) && StoY(mpawn1) MY_LARGE_EQL MY_RANK3){
		if(abs(StoX(mpawn1) - StoX(mpawn2)) == 1){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 9/c3k4/3P1P3/9/2b3b2/6B2/9/3A5/5K3/2BA5 b - - 30 30
	if(your_xiang_num == 2 && StoY(yk) == MY_RANK1 && StoY(ypao) == MY_RANK1){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 9/4k4/3P1P2b/9/2bc5/9/9/8B/3K5/2B6 b - - 156 156
	if(StoY(yk) MY_LARGE_EQL MY_RANK1){
		if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
			EV_YOUR_SAFE = TRUE;
		}
	}

	if(my_shi_num >= 1 && StoY(mpawn1) == StoY(mpawn2)){
		if(StoY(mpawn1) == MY_RANK3 || StoY(mpawn1) == MY_RANK4){
			if(abs(StoX(mpawn1) - StoX(mpawn2)) <= 2){
				EV_MY_SAFE = TRUE;
			}
		}
	}


	if(mcan <= 1 && EV_MY_SAFE == TRUE){
		RETRUN_MUL(2);
	}

	// fen 2bk5/5P3/4b1c2/3P5/9/9/9/9/9/3K5 w - - 0 0
	if(EV_MY_SAFE){
		if(your_xiang_num == 2){
			Bitboard bp = m_and(bb_my_pawn,MyLowBB[MY_RANK2]);
			if(count_1s(bp) >= 1){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/4a4/3a5/9/2b6/4C4/9/4p4/5p3/3AK4 w - - 0 1
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoX(ypao) == StoX(mk)){
			RETRUN_MUL(4);
		}
	}
	// fen 2bk5/4P4/5P3/9/9/4c1B2/9/3A1A3/4K4/6B2 b - - 0 1
	if(your_xiang_num >= 1 && your_shi_num == 0){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			if(StoX(yk) == 0x3){
				if(!have_bit(bb_my_pawn,LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			if(StoX(yk) == 0x5){
				if(!have_bit(bb_my_pawn,RightBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4ka3/5P3/4P4/9/9/6B2/3c5/5A3/4K4/9 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && PB90(MY_SQ0D) != my_pawn){
			RETRUN_MUL(4);
		}
	}

	// fen 3k5/4P4/b8/5P3/4c4/9/9/B2ABK3/9/5A3 w - - 0 1
	if (your_xiang_num >= 1) {
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK2])
			&& have_bit(bb_my_pawn,MyUpBB[MY_RANK2])) {
			if (StoX(yk) == 0x3) {
				if (count_1s(bb_my_pawn, RightBB[0x3]) == 2) {
					RETRUN_MUL(4);
				}
			}
			if (StoX(yk) == 0x5) {
				if (count_1s(bb_my_pawn, LeftBB[0x5]) == 2) {
					RETRUN_MUL(4);
				}
			}
		}
		
	}

	// fen 5k3/1c4P2/3P5/9/2b6/2B6/9/5A3/4K4/2B6 b - - 0 1
	if(your_xiang_num >= 1){
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(StoX(yk) > 0x4){
				if(have_bit(bb_my_pawn,RightBB[0x5]) 
					&& have_bit(bb_my_pawn,LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			if(StoX(yk) < 0x4){
				if(have_bit(bb_my_pawn,LeftBB[0x3]) 
					&& have_bit(bb_my_pawn,RightBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}

}

