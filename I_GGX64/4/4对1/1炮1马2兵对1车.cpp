#ifndef END_my_m_MT_R_1pao_1ma2pawn_B_1che
#define END_my_m_MT_R_1pao_1ma2pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao_1ma2pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_1Che_PawnByShi[your_shi_num]);

	// fen 4k1b2/9/2n1bR3/p5c2/4p4/9/9/4B4/4A4/2BA1K3 w - - 0 0    
	Square mk = my_king_pos;
	//Square yk = your_king_pos;

	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}

	if((my_shi_num + my_xiang_num) == 4){
		EV_MY_SAFE = TRUE;
	}

	// fen 2b2k3/4a4/4b4/9/9/P1P6/5C2r/B2N1A3/4A4/4K4 b - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		MY_EV_SUB(64);
	}


	int mcan = EV_MY_CAN;
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// fen 3c2bn1/3ka2R1/4ba3/9/6p2/9/9/3AB4/4A4/2B1K3p b - - 121 121
	if(StoY(mma) == MY_RANK9 && abs(StoX(mma) - 0x4) >= 3 && mcan <= 1 ){
		if(PB90(mma MY_SUB 0x9) == your_che){
			MY_EV_SUB(128);
		}
	}

	// fen 2b1ka3/4a4/4b4/9/3C1P3/8P/P8/4r4/4N4/3AKA3 b - - 0 1
	if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 64);
	}
	 
	// fen 2ba5/1PP1a1N2/b2k5/9/9/6B2/5r3/B8/4K4/6C2 b - - 0 1
	if (my_shi_num == 0){
		if ((your_shi_num + your_xiang_num) >= 3){
			MY_EV_SUB(32);
		}
		MY_EV_SUB(32);
		if (count_1s(bb_my_pawn, MyUpBB[StoY(yk)]) == 2){
			MY_EV_SUB(64);
			if (StoY(mma) MY_SMALL_EQL MY_RANK3){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 4ka3/6P2/b2a5/9/8r/2P6/9/4BN3/4A4/2BAKC3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(EV_MY_CAN <= 1){
				MY_EV_SUB(96);
				if(StoY(mma) MY_LARGE_EQL MY_RANK5){
					RETRUN_MUL(4);
				}
			}
		}
	}

	
	
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){		

			// fen 4kab2/4a4/4b1N2/3r5/C8/2P1P4/9/4B4/9/2BAKA3 b - - 0 1
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				MY_EV_SUB(64);
			}


			// fen 4k4/4a1PP1/3ab4/9/2b2r3/6B2/9/4BA3/1N1CA4/4K4 b - - 125 125
			if(StoY(mma) MY_LARGE_EQL MY_RANK5 && StoY(mpao) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(4);
			}

			// fen 4k1b2/3Pa4/b2a5/9/9/2P3B2/3r5/3NBA3/1C2A4/4K4 b - - 121 121
			if(StoY(mma) MY_LARGE_EQL MY_RANK7 && mcan <= 1){
				RETRUN_MUL(4);
			}

			// fen 2ba5/C4k3/b2a3P1/8r/8N/2P6/9/4BA3/4A4/2B1K4 r
			if(StoY(yk) MY_SMALL_EQL MY_RANK1 && EV_MY_CAN <= 1){
				RETRUN_MUL(4);
			}

			// fen 5kb2/r3a4/4ba3/3N5/PP7/2B6/9/B2C5/4A4/3AK4 w - - 128 128
			if(count_1s(bb_my_pawn,MyLowBB[MY_RANK3]) == 2){
			    RETRUN_MUL(8);
			}
		}
	}
   
	// fen 2b2k3/4a4/5a3/5NP2/r8/2P3B2/6C2/3AB4/4A4/4K4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(StoY(yche) == MY_RANK4){
				Bitboard notp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
				if(m_have_bit(notp)){
					RETRUN_MUL(8);
				}
			}
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3]) 
				|| have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
					RETRUN_MUL(8);
			}
		}
	}

	// fen 2b2k3/4a4/4b4/9/9/P1P6/5C2r/B2N1A3/4A4/4K4 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1){
			if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
					RETRUN_MUL(4);
				}
				RETRUN_MUL(8);
			}
		}
	}
}
