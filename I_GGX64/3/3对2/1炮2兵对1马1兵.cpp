#ifndef END_my_m_MT_R_1pao2pawn_B_1ma1pawn
#define END_my_m_MT_R_1pao2pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int  ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[3]      = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分
//const int  ADD_1PaoXPawn_1Ma1Pawn_ByMaPanw[3]       = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分


void my_m_MT_R_1pao2pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_1Ma1Pawn_ByMaPawn[my_shi_num]);

	int mcan  = EV_MY_CAN;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	// 
	Square mk = my_king_pos;

	if(EV_YOUR_CAN == 0){
		if(my_shi_num >= 1){
			EV_MY_SAFE = TRUE;
		}
		if(my_xiang_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}
	// fen 3ak4/3P3c1/5a3/9/4N1b2/9/9/3A1K2B/2pp5/9 b - - 0 1
	Bitboard myupb = m_and(bb_my_pawn, MyUpBB[StoY(yk)]);
	if (count_1s(myupb) == 2){
		MY_EV_SUB(96);
	}

	if(my_shi_num == 0 && EV_MY_CAN == 0){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 9/9/3Pbk3/6N2/6b2/3c5/9/2p2A3/2p1A4/3K5 b - - 0 1
	if (my_shi_num == 0 && StoY(ypawn) MY_SMALL_EQL StoY(mk) && EV_YOUR_CAN >= 1){
		MY_EV_SUB(64);
	}

	// fen 5k3/4N4/b8/5P3/2b6/9/9/3AcA3/2pp5/4K4 b - - 0 1
	if (your_shi_num == 2 && !have_bit(bb_my_pawn, MyLowBB[MY_RANK1])){
		MY_EV_SUB(64);
		//if (my_shi_num == 0 && StoY(ypawn) MY_SMALL StoY(mk) && EV_YOUR_CAN >= 1){
		//	MY_EV_SUB(64);
		//}
		if (!have_bit(LeftBB[0x4], bb_my_pawn)){
			MY_EV_SUB(32);
		}
		if (!have_bit(RightBB[0x4], bb_my_pawn)){
			MY_EV_SUB(32);
		}
	}

	// fen 4k1b2/3PaP3/3a5/9/9/9/4n4/4B4/2C1p4/3K5 w - - 0 1
	if (StoY(mpao) MY_LARGE_EQL MY_RANK8) {
		if (IsOnSameSide(mpao, mk)) {
			MY_EV_ADD(64);
		}

		if (my_xiang_num >= 1) {
			MY_EV_ADD(32);
		}

		MY_EV_ADD(EV_MY_CAN * 32);
	}


	// fen 5k3/4N4/b8/5P3/2b6/9/9/3AcA3/2pp5/4K4 b - - 0 1
	if (my_shi_num == 0 && StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(32);
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK6){
			MY_EV_SUB(64);
		}
		if (your_shi_num == 2){
			Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
			if (count_1s(mp) == 2){
				if (PB90(MY_SQ03) != your_shi && !have_bit(mp, LeftBB[0x5])){
					MY_EV_SUB(64);
				}
				if (PB90(MY_SQ05) != your_shi && !have_bit(mp, RightBB[0x3])){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 4k4/5PP2/5a3/9/6b2/9/3C5/1p3K3/9/2n6 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(StoY(ypawn) MY_SMALL_EQL StoY(mk) && EV_YOUR_CAN >= 1){
			MY_EV_SUB(96);
		}
		if(your_shi_num >= 1){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				if(!have_bit(bb_my_pawn,LeftBB[0x4]) || !have_bit(bb_my_pawn,RightBB[0x4])){
					MY_EV_SUB(96);
				}
			}
		}
	}

	// fen 3k1a3/9/4ba3/9/4p1b1p/9/6NcP/3AB4/4A4/4K4 w - - 0 1
	if(EV_MY_CAN <= 1){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3a1k3/9/4P4/1N7/9/5cB2/9/3A5/2p1A1p2/5K3 w - - 59 59
	if(my_shi_num <= 1 && my_xiang_num == 0){
		if(PB90(MY_SQ43) == your_pawn){
			MY_EV_SUB(164);
		}
	}
	// fen 3c5/4k4/4b4/4P2N1/9/9/4pp3/4B4/4A4/4KAB2 b - - 0 1
	if(my_xiang_num >= 1 || my_xiang_num >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(96);
		}		
	}
	// fen 5k3/4a4/b2a5/3PP4/2n6/6B2/3p2C2/3AB4/4A4/4K4 w - - 0 1
	if(StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(64);
	}

   	// 1, 如果马方是仕相全,炮方有仕,则基本是和棋
	// fen 4k1b2/3Pa4/3a5/3P5/2b6/2C6/9/2n1p4/3K5/9 w - - 122 1
	if((your_shi_num + your_xiang_num) == 4){
		if(my_shi_num >= 1){
			RETRUN_MUL(2);
		}
	}

	if(my_shi_num == 2 || (my_shi_num >= 1 && my_xiang_num >= 1)){
		EV_MY_SAFE = TRUE;
	}
	
	if(StoY(mk) == MY_RANK9 && PB90(MY_SQ4C) == your_pawn){
	}
	else{
		if(mcan >= 2){//炮方要加分
			MY_EV_ADD(ADD_1PaoM2Pawn_1Ma1Pawn_ByM2Pawn);
		}
	}

	// fen 4k4/3P5/9/8p/4N4/9/8c/2p1B4/3KAp3/3A5 b - - 7 7
	if((my_shi_num + my_xiang_num) == 0 && StoY(ypawn) MY_SMALL StoY(mk) && EV_YOUR_CAN >= 1){
		MY_EV_SUB(MaPawn_PaoPawnPaoNoShiXiang);
	}

	// fen 5k3/3P5/b2a4b/9/9/9/4N4/3AcA3/3p1p3/4K4 b - - 0 1
	if(your_shi_num == 2 && EV_YOUR_CAN >= 1 && !have_bit(bb_your_shi,MyUpBB[MY_RANK2])){
		if(PB90(MY_SQ16) == my_pao && PB90(MY_SQ1F) == your_ma){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k5/4aP3/5a3/9/p8/2B6/P8/1CnAB4/4A4/5K3 b - - 0 1
	if(your_shi_num == 2 && EV_MY_CAN <= 1){
		Bitboard upp = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		if(m_have_bit(upp)){
			if((StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi && have_bit(upp,RightBB[0x3])) ||
				(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi && have_bit(upp,LeftBB[0x5]))){
					MY_EV_SUB(128);
					if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ40) == my_pao && PB90(MY_SQ41) == your_ma){
						RETRUN_MUL(4);
					}
					if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ46) == my_pao && PB90(MY_SQ45) == your_ma){
						RETRUN_MUL(4);
					}
			}
		}		
	}

	//  fen 3k5/4a4/1P1ab4/6C2/6p2/2B5n/6P2/9/4A4/3A1KB2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1) {
		if (EV_MY_CAN <= 1 && have_bit(bb_my_pawn, MyUpBB[MY_RANK3])) {
			Bitboard mnhp = m_and(bb_my_pawn, MyLowBB[MY_RANK5]);
			if (have_bit(mnhp, YOUR_ATTACK)) {
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k5/4aPP2/3a5/9/9/9/3n5/5A3/2p1A1C2/2B1K4 b - - 0 1
	if(EV_MY_SAFE && EV_YOUR_CAN >= 1){
		if(your_shi_num == 2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(StoX(yk) <= 0x4 && PB90(MY_SQ03) != your_shi && !have_bit(bb_my_pawn,LeftBB[0x4])){
				if(StoX(ypawn) < 0x4){
					RETRUN_MUL(4);
				}
			}
			if(StoX(yk) >= 0x4 && PB90(MY_SQ05) != your_shi && !have_bit(bb_my_pawn,RightBB[0x4])){
				if(StoX(ypawn) > 0x4){
					RETRUN_MUL(4);
				}
			}
		}
		// fen 5P3/5P3/4k4/9/9/9/3n5/4CA3/3pA4/2B1K4 w - - 0 1
		//if(!have_bit(bb_my_pawn,MyLowBB[StoY(yk)])){
		if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4a4/4ba3/pCn6/9/P1B1P4/9/3AB4/9/3A1K3 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 2){
		if(PB90(MY_SQ31) == my_pawn && StoY(mpao) MY_SMALL_EQL MY_RANK4){
			if(MY_SQ1D == yma && MY_SQ1B == ypawn && PB90(MY_SQ2D) == my_pawn){
				RETRUN_MUL(4);
			}
			if(MY_SQ21 == yma && MY_SQ23 == ypawn && PB90(MY_SQ35) == my_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a1k3/2P1a3P/4bn3/9/9/9/5p3/3A5/4C4/3A1KB2 w - - 0 1
	if(StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(have_bit(bb_my_pawn,FileBB_A[0x0]) || have_bit(bb_my_pawn,FileBB_A[0x08])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/4a4/b2a5/3PP4/2n6/6B2/3p2C2/3AB4/4A4/4K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
		if(StoY(yma) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}

	// fen 2bk2c2/4a4/5a3/3PN4/9/9/9/B3K4/5pp2/9 w - - 0 1	
    if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		MY_EV_SUB(96);
		if(StoY(ypawn) == MY_RANK6 && (your_shi_num + your_xiang_num) >= 1){
			if(EV_MY_SAFE){
				RETRUN_MUL(4);
			}
			if(my_shi_num >= 1){
			   RETRUN_MUL(6);
			}
		}
	}

	// fen 9/9/3Pbk3/6N2/6b2/3c5/9/2p2A3/2p1A4/3K5 b - - 0 1
	if (your_shi_num == 2 && my_shi_num == 0 && EV_YOUR_CAN >= 1){
		Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
		if (count_1s(mp) == 2){
			if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
				if (!have_bit(mp, LeftBB[0x6])){
					RETRUN_MUL(8);
				}
			}
			if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
				if (!have_bit(mp, RightBB[0x2])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/3Pa4/4b4/4P4/2b6/1C1n5/5p3/B2A5/4AK3/9 w - - 114 114
	if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(64);
		// fen 3ckab2/4a4/4b4/5P3/9/6B2/2N6/3A1A3/1p4p2/5K3 b - - 0 114
		if(my_shi_num >= 1 || my_xiang_num == 2){ // my_safe 
			if(your_shi_num == 2 && your_xiang_num >= 1){
				RETRUN_MUL(6);
			}
		}
	}	

	//// fen 6P2/4k1P2/3a5/7n1/2b6/9/4p4/5A3/4A4/2BKC4 w - - 0 1
 //   if(your_shi_num >= 1 && your_xiang_num >= 1){
	//	if(have_bit(bb_my_pawn,MyUpBB[MY_RANK1]) && StoY(yk) != MY_RANK0){
	//		MY_EV_SUB(64);
	//		if(StoY(ypawn) == MY_RANK6 && StoY(yma) MY_LARGE_EQL MY_RANK3){
	//			if(EV_MY_SAFE){
	//				RETRUN_MUL(4);
	//			}
	//		}
	//	}
	//}

	// fen 6P2/3k1P3/3a5/9/9/9/3n5/5A3/2p1A1C2/2B1K4 w - - 0 1
	if(EV_MY_SAFE && EV_YOUR_CAN >= 1){
		if(your_shi_num >= 1 
			&& !have_bit(bb_my_pawn,MyLowBB[MY_RANK1]) 
			&& have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){
			if(StoX(yk) <= 0x4 && PB90(MY_SQ03) != your_shi && !have_bit(bb_my_pawn,LeftBB[0x5])){
				if(StoX(ypawn) < 0x4){
					RETRUN_MUL(8);
				}
			}
			if(StoX(yk) >= 0x4 && PB90(MY_SQ05) != your_shi && !have_bit(bb_my_pawn,RightBB[0x3])){
				if(StoX(ypawn) > 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 5a3/3P5/b3k4/9/8p/4n4/7CP/4BA3/3KA4/9 w - - 0 1
    if(your_shi_num >= 1 && your_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(EV_YOUR_CAN == 0 && have_bit(bb_my_pawn,MyUpBB[StoY(yk)])){
			RETRUN_MUL(8);
		}
	}




	if((your_shi_num + your_xiang_num) >= 3){
		RETRUN_MUL(8);
	}
	// fen 3a5/3Pa4/4k1P2/4C4/9/2B1n4/9/4B4/4p4/3K5 w - - 0 1
	if(my_xiang_num >= 1 && PB90(MY_SQ4C) == your_pawn){
		if(StoY(mk) == MY_RANK9 && PB90(MY_SQ43) == my_xiang){
			if(StoX(yma) == 0x4 && StoX(mpao) == 0x4){
				if(StoY(yma) MY_SMALL MY_RANK7 && StoY(mpao) MY_SMALL StoY(yma)){
					if(ei.attackedBy[mpao],MY_SQ43){
						MY_EV_ADD(96);
					}
				}
			}
		}
	}

	// fen 9/4k2P1/4ba3/p8/9/P1B6/1Cn6/3AB4/4A4/4K4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(MY_SQ04 != yk){
			if(have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				RETRUN_MUL(4);
			}
			if(have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4P4/1P7/3k1a3/4C4/9/5n3/9/4p4/9/3AK4 w - - 0 1
	if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		if(my_shi_num >= 1 && EV_YOUR_CAN >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 3P5/9/b4k3/8C/8p/9/8P/5n3/4K4/9 b - - 0 1
	if(EV_YOUR_SAFE){
		if(EV_YOUR_CAN == 0){
			RETRUN_MUL(8);
		}
	}

	//if(your_shi_num == 2 && EV_MY_CAN <= 1){
	//	Bitboard upp = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
	//	if(m_have_bit(upp)){
	//		if((StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi && have_bit(upp,RightBB[0x3])) ||
	//			(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi && have_bit(upp,LeftBB[0x5]))){
	//				RETRUN_MUL(8);
	//		}
	//	}
	//}
}

