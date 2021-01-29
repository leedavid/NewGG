#ifndef END_my_m_MT_R_2ma2pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_2ma2pawn_B_1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马2兵对1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma2pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_1Pao1Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Pao1Ma1Pawn_2MaXPawn_ByPawn[my_shi_num]);
	

	// fen 3akab2/5n3/3cb4/7P1/p8/2P2N3/9/4BAN2/9/2BAK4 w - - 0 0
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;	


	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);

	// fen 3k1ab2/4a4/4b4/5P1N1/9/p5P2/5N3/3n5/3K5/c8 b - - 0 1
	if(abs(StoX(ypawn) - StoX(yma)) >= 2){
		if(isStringByChe(POSITION,mk,yma,yk) && bit_is_set(ei.attacked_by(my_king),yma)){
			MY_EV_ADD(96);
		}
	}

	// fen 3k5/4aP3/4ba1N1/9/2b6/c2Nn1P2/9/3A5/3pA4/5K3 w - - 0 1
	if(my_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK7){
		if((StoX(ypawn) < 0x4 && PB90(MY_SQ42) == my_shi)
			||(StoX(ypawn) > 0x4 && PB90(MY_SQ44) == my_shi)){
				MY_EV_ADD(32);
				MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3ak4/9/4ba3/4P3p/6b2/7NP/9/3An4/4AN2c/5K3 w - - 0 1
	if (EV_YOUR_CAN == 0) {
		MY_EV_ADD(32);
		if (abs(StoX(ypawn) - 0x4) == 4) {
			MY_EV_ADD(EV_MY_CAN * 32);
		}		
		if (my_shi_num == 2) {
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
	

	// fen 4kab2/9/2n2a3/4p4/2b2N3/1N4B1P/4P4/9/3c5/2BAKA3 w - - 1 1
	//if(your_shi_num == 2){
	//	MY_EV_SUB(16);
	//	if(your_shi_num == 2 && mcan <= 1){
	//		MY_EV_SUB(32);
	//	}
	//}

	int mysx = my_xiang_num + my_shi_num;
	MY_EV_SUB((4 - mysx) * 16);


	// fen 2b1ka3/4a4/4b1P2/p3c4/3nN4/2B6/P8/4N4/4A4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2  && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(32);
		if(have_bit(bb_my_ma,MyLowBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
	}

	// fen 5ab2/4k4/4ba3/9/p3N4/6P2/2n6/1C2B1np1/4A4/4KAB2 b - - 9 9
	//if(ycan == 0){
	//	MY_EV_ADD(mcan * 32);
	//}

	// fen 4kab2/9/2n2a3/4p4/2b2N3/1N4B1P/4P4/9/3c5/2BAKA3 w - - 1 1

	if(mcan <= 1){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(ycan * 32);
			MY_EV_SUB(32);

			if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak1b2/4a4/4bc3/2P2N1N1/2n4P1/5p3/9/3AB4/4A4/4K1B2 b - - 0 1
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/2PPa4/4ba3/9/2bNc4/3n5/9/3N1A3/6p2/3K1A3 b - - 0 1
	if(your_shi_num == 2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(!have_bit(bb_my_pawn,RightBB[0x3]) && PB90(MY_SQ05) != your_shi){
			MY_EV_SUB(64);
		}
		if(!have_bit(bb_my_pawn,LeftBB[0x5]) && PB90(MY_SQ03) != your_shi){
			MY_EV_SUB(64);
		}
	}

    // fen 3k5/6P2/3a1a1nb/9/5N3/2B3BC1/3n5/3A1A3/2pp1K3/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		bmp = m_and(bb_my_pawn,MyUpBB[StoY(yk) MY_ADD 1]);
		if(count_1s(bmp) == 2){
			MY_EV_SUB(32);
			MY_EV_SUB(EV_YOUR_CAN * 64);
		}
	}

	// fen 2bak4/3PaP3/9/9/5N3/9/9/5p3/n1N6/1c2KAB2 b - - 0 1
	//二车拍门，要加分。

	// fen 3k1a3/4a2P1/b4c3/4NN3/2p6/2B6/2P6/4BA3/2n1A4/5K3 b - - 0 1
	if(EV_MY_CAN <= 1){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
			if((my_shi_num + my_xiang_num) >= 3 && EV_YOUR_CAN == 0){
				Bitboard bmp3 = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
				if(count_1s(bmp3) == 1){
					Square p = pop_1st_bit_sq(bmp3);
					if(StoX(p) > 0x4 && StoX(yk) < 0x4){
						RETRUN_MUL(8);
					}
					if(StoX(p) < 0x4 && StoX(yk) > 0x4){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2b1k4/4a4/4ba3/2p2N3/6P2/2P6/5N1n1/4B4/7c1/4K1B2 b - - 0 1
	if(EV_YOUR_CAN == 0 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 32);
	}




}
