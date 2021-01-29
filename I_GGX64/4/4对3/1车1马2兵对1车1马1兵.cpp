#ifndef END_my_m_MT_R_1che1ma2pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che1ma2pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马2兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1ma2pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[my_shi_num]); 
	
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
			EV_MY_SAFE = true;
		}
	}

	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if (EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3a1k3/2N1a4/9/8p/2b1p1R2/8P/5r3/4B3n/4A4/2BAK4 w - - 0 1
	if (EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mma) MY_LARGE_EQL MY_RANK6){
			MY_EV_SUB(32);
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK5])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3ak4/4a4/4b4/8R/6b2/9/Pnp2r2P/4BN3/4A4/2BAK4 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK7 || abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
			if (MY_SQ44 == mma && PB90(MY_SQ56) != my_shi){
				MY_EV_ADD(32);
			}
			if (MY_SQ42 == mma && PB90(MY_SQ54) != my_shi){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 3ak4/4a4/b4n3/9/1Pb1p4/2N4r1/4P4/B3R4/9/4K4 w - - 0 1
	if (EV_YOUR_CAN == 0 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if (MY_SQ28 == ypawn && StoY(yma) MY_SMALL_EQL MY_RANK4){
			if (bit_is_set(ei.attacked_by(my_ma), MY_SQ28) && bit_is_set(MY_ATTACK, mma)){
				MY_EV_ADD(EV_MY_CAN * 32);
				if (StoX(mche) == 0x4){
					MY_EV_ADD(32);
				}
			}
		}
	}

	//  fen 4kab2/4a4/2n1b4/2prp2N1/9/9/P3R4/4B4/4A4/4K1B2 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
		MY_EV_SUB(32);
		if (EV_YOUR_CAN >= 1 && !have_bit(bb_my_pawn, MyUpBB[MY_RANK5])) {
			MY_EV_SUB(32);
			if (StoY(yma) MY_LARGE_EQL MY_RANK4 && StoY(mma) MY_LARGE_EQL MY_RANK7) {
				MY_EV_SUB(32);
				if (StoY(yche) MY_LARGE_EQL MY_RANK3 && StoY(mche) MY_LARGE_EQL MY_RANK6) {
					MY_EV_SUB(16);
				}
			}
		}
	}
	

	// fen 4ka3/4a4/3n5/5r3/p4N3/2B1P4/P4R3/B2A5/9/3AK4 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN <= 1){
			if(isStringByChe(POSITION,yche,mma,mche)){
				MY_EV_SUB(64);
				if(PB90(MY_SQ3A) == my_pawn){
					if(bit_is_set(ei.attacked_by(your_ma),MY_SQ31)){
						MY_EV_SUB(64);
					}
				}
				if(PB90(MY_SQ31) == my_pawn){
					if(bit_is_set(ei.attacked_by(your_ma),MY_SQ28)){
						MY_EV_SUB(64);
					}
				}
			}
		}
	}

	// fen 2b1ka3/9/3ab4/2n6/4PN1r1/p8/4R3P/9/9/3AKA3 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2bak4/4a4/4b4/P8/4R1n1p/9/2N5P/B2r5/9/3AKA3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3){
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(16);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if(abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 5kb2/4a4/4ba3/p4P3/2n2r3/P1R3N2/9/4B4/9/4K4 r
	if(my_xiang_num >=1 && EV_YOUR_CAN == 0 
		&& StoY(yma) MY_SMALL_EQL MY_RANK4 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 16);
		MY_EV_ADD(16);
	}

	// fen 3ak4/4aR3/9/2r4np/1PN6/2B6/8P/3A4B/9/4KA3 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if (EV_MY_CAN <= 1){
			MY_EV_SUB(64);
			if (StoY(mma) MY_LARGE_EQL MY_RANK4){
				if (PB90(mma MY_SUB 0x9) == your_che){
					MY_EV_ADD(64);
				}
				if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 2bk5/4a4/3ab4/4n4/8p/9/4P1r1P/5RN2/4A4/2B1K4 w - - 0 1
	if(my_shi_num >= 1 && my_xiang_num >= 1 && EV_YOUR_CAN == 0){
		if(MY_SQ55 == mk && StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
	// fen 2bak4/4a4/4bn3/8R/6p2/2N1r4/6P1P/4B4/9/2BAKA3 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(yma) == MY_RANK2){
				if(EV_MY_CAN <= 1){
					MY_EV_SUB(64);
					if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
						RETRUN_MUL(10);
					}		
				}
			}
		}
	}

	// fen 2b1ka3/4a4/2r1b4/4n2P1/R5p2/9/P8/N3B4/4A4/2BAK4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mma) MY_LARGE_EQL MY_RANK6 && have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(10);
			}
		}
	}

}

