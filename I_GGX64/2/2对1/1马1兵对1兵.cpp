#ifndef END_my_m_MT_R_1MA1PAWN_B_1PAWN
#define END_my_m_MT_R_1MA1PAWN_B_1PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h" 
#include "..\\..\\endgame\mat.h"
#include "1马1兵对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//const int MaPawnAdd = 96;
//const int KingMid   = 24;

//我方一马一兵，对方一兵
void my_m_MT_R_1MA1PAWN_B_1PAWN(typePOS &POSITION, EvalInfo &ei){

    Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;
	

	int mcan = EV_MY_CAN;

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		// fen 2b1k4/4aP3/3a5/9/2bN5/9/3p5/B8/9/3AKA3 b - - 0 1
		MY_EV_SUB(64);
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(168);
		}
	}

	//MY_EV_ADD(96);

	if(StoX(mk) == 0x4){
		MY_EV_ADD(64);
	}
	// fen 3k5/4a4/5aP2/9/4N1b2/9/9/3AB4/3p5/3A1K3 w - - 0 1
	if(StoY(ypawn) != MY_RANK9){
		MY_EV_SUB(128);
	}

	if(StoY(ypawn) == MY_RANK9 && my_xiang_num >= 1){
		if(abs(StoX(ypawn) - 0x4) <= 1){
			MY_EV_ADD(96);
		}
	}
	// fen 2b1k1b2/4a4/3a5/3P1N3/6p2/9/9/B3B4/3KA4/5A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(168);
		}
	}

	// 我方的兵到底了
	if(StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(1);
	}

	if(StoY(mk) MY_SMALL_EQL StoY(ypawn)){
		MY_EV_ADD(96);
	}

	if(abs(StoX(ypawn) - 0x4) >= 3){
		MY_EV_SUB(196);
	}

	// fen 3k5/3N3P1/4ba3/9/9/6B2/9/9/3K5/4p4 b - - 0 1
	if(StoY(mma) MY_SMALL_EQL MY_RANK2 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(your_shi_num >= 1 && your_xiang_num >= 1){
			if(!IsOnSameSide(mma,mpawn)){
				if(XYtoS(StoX(yk),StoY(yk) MY_ADD 0x1) == mma){
					RETRUN_MUL(2);
				}	
			}
		}
	}

	//如果黑兵过河了，用黑方有二个仕，
	// fen 4k4/4a4/4NaP2/9/9/9/9/3A5/4A1p2/5K3 w - - 47 47
	if(your_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK5 && StoY(ypawn) != MY_RANK9){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi && StoX(yk) <= 0x4){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi && StoX(yk) >= 0x4){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4k4/3Pa4/5a3/9/2b1N4/9/4p4/4B4/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 1){
			RETRUN_MUL(2);
		}
	}

	// fen 5k3/3P1N3/3a5/9/2b3b2/9/9/4B4/3pAK3/3A2B2 w - - 0 1
	if(your_shi_num >= 1 && (your_xiang_num == 2 || EV_YOUR_CAN >= 1)){
		//if(StoY(mma) MY_SMALL_EQL MY_RANK1 && PB90(yk MY_ADD 0x9) == my_ma){
		//	if(StoX)
		//}
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi 
				&& yk == MY_SQ05 && mma == MY_SQ0E){
					RETRUN_MUL(2);
			}
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi 
				&& yk == MY_SQ03 && mma == MY_SQ0C){
					RETRUN_MUL(2);
			}
		}
	}

	// fen 3k2b2/9/3a4b/2N6/9/2B3P2/9/3AB4/3p5/4KA3 b - - 0 1
	if (your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK5 && EV_MY_CAN == 0){
			RETRUN_MUL(2);
		}
	}


	// fen: 3a5/3k1P3/9/6N2/9/9/3p5/9/9/4K4 w - - 0 0 
	//卒士弈和馬低兵，須弈成本局士在將底，即“太公坐椅”形式互相保護，士藏將底，紅無法可勝，最後用卒走閑。倘若兵位於三線以上，即屬必勝。

	if(your_shi_num >= 0){
		if(StoY(mpawn) MY_SMALL MY_RANK2){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ03) == your_shi && StoX(yk) == 0x3){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ05) == your_shi && StoX(yk) == 0x5){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5k3/4a4/2Pa5/6N2/6b2/9/9/3AK4/4A4/7p1 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (EV_YOUR_CAN >= 1 || (
			StoY(ypawn) == MY_RANK9 && abs(StoX(ypawn) - 0x4) >= 2)){
			if (StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if (StoX(yk) == 0x5 && StoX(mpawn) <= 0x3 
					&& !have_bit(bb_your_shi, RightBB[0x4])){
					RETRUN_MUL(2);
				}
				if (StoX(yk) == 0x3 && StoX(mpawn) >= 0x5
					&& !have_bit(bb_your_shi, LeftBB[0x4])){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// 马高兵对卒双仕的一个和型
	// fen 4k4/4aP3/3a5/9/9/9/9/2n1p4/3KA4/5A3 w - - 127 127
	if(your_shi_num == 2){
		// 红兵给二个仕控制住了
		if(MY_SQ16 == mpawn && PB90(MY_SQ0D) == your_shi){
			//还要看一下没有被红帅牵制住
			// fen 9/1N1ka4/3aP4/9/9/2B6/9/9/3KA1p2/3A5 b - - 30 30
			//这个红方能胜
			if(FALSE){
			}
			else if(StoX(mk) == 0x3 && PB90(MY_SQ15) == your_shi){
			}
			else if(StoX(mk) == 0x5 && PB90(MY_SQ17) == your_shi){
			}
			else{
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/3k1P3/3N1a3/9/9/9/9/B4A2B/1p7/3K1A3 w - - 1 1
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(MY_SQ0C == yk && MY_SQ15 == mma){
			if(StoX(mpawn) > 0x4){
				RETRUN_MUL(2);
			}
		}
		if(MY_SQ0E == yk && MY_SQ17 == mma){
			if(StoX(mpawn) < 0x4){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2ba1k3/4a4/2P5b/3N5/9/2B3B2/9/5A3/4K4/3A2p2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if (StoX(mpawn) < 0x4 && StoX(yk) > 0x4 
				&& !have_bit(RightBB[0x4], bb_your_shi)){
					RETRUN_MUL(2);
			}
			if (StoX(mpawn) > 0x4 && StoX(yk) < 0x4
				&& !have_bit(LeftBB[0x4], bb_your_shi)){
					RETRUN_MUL(2);
			}
		}
	}

	

	
    if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ16) == your_xiang){
			
			// fen 5a3/5P3/3kb4/2N6/2b6/2B6/9/3AK4/5p3/6B2 b - - 0 1
			if(StoX(mpawn) >= 0x5 && (PB90(MY_SQ05) == your_shi || PB90(MY_SQ0D) == your_shi)){
				//if(StoX(mma) < 0x4 || StoY(mma) MY_LARGE_EQL MY_RANK4){
				//	RETRUN_MUL(2);
				//}
				if(!bit_is_set(ei.attacked_by(my_ma),Square(MY_SQ0D))){
					RETRUN_MUL(2);
				}
			}
			if(StoX(mpawn) <= 0x3 && (PB90(MY_SQ03) == your_shi || PB90(MY_SQ0D) == your_shi)){
				//if(StoX(mma) > 0x4 || StoY(mma) MY_LARGE_EQL MY_RANK4){
				//	RETRUN_MUL(2);
				//}
				if(!bit_is_set(ei.attacked_by(my_ma),Square(MY_SQ0D))){
					RETRUN_MUL(2);
				}
			}

			// fen 9/3kaP3/4b4/6N2/2b6/2B6/9/3AK3B/7p1/9 w - - 0 1
			//if(!bit_is_set(ei.attacked_by(my_ma),MY_SQ0D)){
			//	if(StoX(mpawn) >= 0x5 && StoX(yk) == 0x3 && 
			//}
		}
	}

	
	// fen 9/4a4/3k1aP2/4N4/9/9/9/3A5/4A2p1/4K4 w - - 0 0
	// fen 9/4a4/4kaP2/9/6N2/9/9/3A5/4A2p1/4K4 w - - 0 0

	
	if((your_shi_num + your_xiang_num) == 4){

		// fen 2b2a3/3ka4/b8/9/9/1NP3B2/9/8B/5p3/3AK4 b - - 120 120
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK5 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(mcan == 0){
				RETRUN_MUL(2);
			}
		}

		// fen 4k4/4a4/5a3/2P6/9/9/5n3/2pAB4/4A4/3K2B2 b - - 67 67
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 3a1k3/4a4/9/6p2/2b3b2/2B3P2/9/2nK5/9/6B2 w - - 128 128
	if(your_xiang_num == 2){
		if(MY_SQ26 == ypawn && MY_SQ38 == mpawn){
			RETRUN_MUL(2);
		}
		if(MY_SQ2A == ypawn && MY_SQ3C == mpawn){
			RETRUN_MUL(2);
		}
	}

	// fen 4k1P2/9/4ba3/9/9/9/9/2p6/4A4/3A1K1n1 w - - 0 1
    if(your_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK4 && StoY(ypawn) != MY_RANK9){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3a1k1P1/9/3a4b/9/9/9/3n5/4pA3/3KA4/9 w - - 0 1
    if(your_shi_num == 2 && PB90(MY_SQ16) == my_pawn && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(StoY(ypawn) == MY_RANK9 && abs(StoX(ypawn) - 0x4) <= 1){
		}
		else{
			if(StoX(yk) == 0x3 && PB90(MY_SQ03) != your_shi && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ05) != your_shi && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k5/5P3/9/9/9/9/9/3A5/5p3/n3KA3 w - - 0 0
	if(your_shi_num == 2 && StoY(ypawn) MY_LARGE MY_RANK5 && StoY(ypawn) != MY_RANK9){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ17) == your_shi && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ15) == your_shi && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(2);
			}
		}
		// fen 3k5/5P3/9/9/9/9/9/3A5/5p3/n3KA3 w - - 0 0
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(yk) < 0x4 && StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(yk) > 0x4 && StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(2);
			}
		}
	}

	if((StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi)
		||(StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi)){
			if(StoY(mpawn) != MY_RANK0){
				MY_EV_ADD(96);
			}
	}

	// fen 9/4k1P2/5a3/9/9/9/9/3K2p2/4A4/1n3AB2 b - - 0 1
	if(your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK2 && EV_YOUR_CAN >= 1){
		if(IsOnSameSide(yk,mpawn) == FALSE && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/3k1P3/3a5/9/2b1N1b2/9/3p5/5A3/9/3K1AB2 w - - 0 1
    if(StoY(ypawn) == MY_RANK6 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoX(yk) == 0x3 && StoX(ypawn) == 0x3 && StoX(mpawn) >= 0x5){
				RETRUN_MUL(2);
			}
			if(StoX(yk) == 0x5 && StoX(ypawn) == 0x5 && StoX(mpawn) <= 0x3){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k1a3/5P3/N2a4b/9/2p3b2/6B2/9/B4A3/3K5/5A3 b - - 0 1
	if(your_xiang_num == 2 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(2);
			}
		}
	}
	
	if(your_xiang_num == 2 && your_shi_num >= 1 && EV_YOUR_CAN >= 1 && StoY(ypawn) == MY_RANK6){

		// fen 2b1ka3/8P/9/6n2/9/9/4p4/4B4/4A4/2B2K3 w - - 32 32
		//如果兵过河了,且兵方是单缺仕
		//if(StoY(yk) MY_SMALL_EQL MY_RANK1){		
		//	//if(StoY(ypawn) MY_LARGE MY_RANK4){
		//	//	if(StoY(mpawn) MY_SMALL MY_RANK2){
		//	//		RETRUN_MUL(2);
		//	//	}	
		//	//	RETRUN_MUL(4);
		//	//}
		//}
		// fen 5ab2/5k3/2P1b4/9/9/9/2N6/9/p8/3AK1B2 b
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && !IsOnSameSide(mpawn,yk)){
			if(StoX(yk) == 0x3 && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(2);
			}
		}
		// fen 4k4/4a4/5a2b/3P5/9/3n5/4p4/4B4/4A4/4K1B2 w - - 120 120
		if(StoY(mpawn) MY_LARGE MY_RANK2){
            RETRUN_MUL(4);
		}		
	}

	// fen 4k4/4aP3/3aN4/9/9/9/9/B2K1A3/1p7/3A2B2 w - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK6){
		if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ15) == your_shi){
				if(PB90(MY_SQ03) != your_shi && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(4);
				}
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ17) == your_shi){
				if(PB90(MY_SQ05) != your_shi && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2b1k4/4a4/4ba3/6N1p/9/6B1P/9/5A3/4A4/2B1K4 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(4);
			}
		}	
	}

	// fen 2b2k3/4a4/5a3/9/P3N4/8p/9/9/4A4/3AK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){		
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(4);
			}
		}		
	}

	// fen 2b2k3/4a4/5a3/5P3/9/2B5N/9/4K1p2/4A4/6B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && EV_YOUR_CAN){
		MY_EV_SUB(96);
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/3Pa2N1/4ba3/9/9/9/9/9/2p1K4/2B3B2 b - - 0 1
	if(EV_YOUR_CAN){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ16) == your_xiang){
				if(StoX(mpawn) < 0x4 && MY_SQ10 == mma 
					&& PB90(MY_SQ17) == your_shi){
						RETRUN_MUL(4);
				}
				if(StoX(mpawn) > 0x4 && MY_SQ0A == mma 
					&& PB90(MY_SQ15) == your_shi){
						RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5k3/4a1P2/5a3/9/2bN5/9/9/9/3KA4/6p2 b - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				if(have_bit(bb_your_shi,MyLowBB[MY_RANK1])){
					RETRUN_MUL(4);
				}
			}
		}
	}

	//如果黑兵过河了,且有二个仕
	// fen 9/3ka4/5a3/N4P3/9/6B2/9/5A3/2p1A4/4K1B2 b - - 122 122
	if(your_shi_num == 2 && StoY(ypawn) != MY_RANK9 && EV_YOUR_CAN >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){	

		MY_EV_SUB(80);
		if (StoY(ypawn) MY_LARGE MY_RANK5) {			

			if (PB90(MY_SQ15) == your_shi && StoX(yk) == 0x5) {
				RETRUN_MUL(4);
			}
			if (PB90(MY_SQ17) == your_shi && StoX(yk) == 0x3) {
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}

	//if(your_shi_num == 2 )

	//my_m_MT_R_1MA1PAWN_B_NO(POSITION,ei);
	// fen 4k4/4a4/5a2b/3P5/9/3n5/4p4/4B4/4A4/4K1B2 w - - 120 120

	// fen 3k1a3/4a4/4N4/4P4/9/2B6/2p6/5A3/4AK3/9 b
	if(your_shi_num == 2 && StoY(ypawn) == MY_RANK6){
		if(abs(StoX(ypawn) - 0x4) <= 2){
			RETRUN_MUL(8);
		}
	}

	// fen 5k3/4a1P2/5a3/9/2bN5/9/9/9/3KA4/6p2 b - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(8);
		}
	}
}
