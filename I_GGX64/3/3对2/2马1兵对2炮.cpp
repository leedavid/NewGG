#ifndef END_my_m_MT_R_2ma1pawn_B_2pao
#define END_my_m_MT_R_2ma1pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2ma1pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_2Pao_ByPawnShi[your_shi_num]);

	int mcan = EV_MY_CAN;

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 4k1b2/4a1c2/9/4P1N2/5Np2/4c2p1/9/p3B4/4A4/4KAB2 w - - 0 0
	if(your_shi_num <= 1 && mcan >= 1){
		MY_EV_ADD(mcan * (4- (your_shi_num + your_xiang_num)) * 80);
	}

	// fen 4k4/4ac3/2P2aNc1/9/2b3b2/9/4N4/9/9/3K5 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if((your_shi_num + your_xiang_num) == 4){
			MY_EV_SUB(80);
		}
	}

	// fen 4k4/4c4/3a1a2b/2N2N3/1P7/9/9/5A3/3K5/c5B2 b - - 0 1
	if (count_1s(bb_your_pao, MyUpBB[MY_RANK4]) == 2){
		MY_EV_SUB(32);   // 残局炮回家
	}

	// fen 3a1k3/4a4/bc2bc3/4P4/9/4N1N2/9/4B4/4A4/2BAK4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(80);
		}
	}

	// fen 3a1kb2/2Nca4/9/4P4/6bc1/2B6/4N4/4B4/4A4/4K4 w - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
		if(!have_bit(bb_your_pao,MyLowBB[MY_RANK5])){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ03) != your_shi){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ05) != your_shi){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k1ab2/4a4/2P5b/9/c2N5/1N7/9/4BA3/9/1c2KAB2 b - - 0 1
	if ((your_shi_num + your_xiang_num) == 4 && abs(StoX(mpawn) - 0x4) >= 2){
		if (StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	//Square yk = your_king_pos;
	//如果炮方是仕相全,则是和棋
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}

	// fen 4k1b1N/3ca3c/4b4/4P4/9/6B2/4N4/3AB4/4A4/4K4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){

		MY_EV_SUB(32);

		// 控制了我方的一个马
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			//for(int i = 0; i < POSITION.piece_count(my_ma); i++){
			//	Square s =  POSITION.piece_list(my_ma,i);
			//	if(StoY(s) == MY_RANK0 && abs(StoX(s) - 0x4) >= 3){
			//		// 马的所有步子都给控制了

			//	}
			//}

			MY_EV_SUB(64);
            RETRUN_MUL(8);			
		}
	}

	// fen 4k4/4c4/3a1a2b/2N2N3/1P7/9/9/5A3/3K5/c5B2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1
		&& StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			RETRUN_MUL(8);
		}
	}
}

