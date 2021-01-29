#ifndef END_my_m_MT_R_1CHE_B_1MA
#define END_my_m_MT_R_1CHE_B_1MA
#include "../../chess.h"
#include "../../preGen.h"
 
#include "1车对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int MaNotShi   = 128;          //马不在仕的一边
//const int MyKingOpen =  96;			 //我的将开放了

//红方一个车，黑方一个马
void my_m_MT_R_1CHE_B_1MA(typePOS &POSITION, EvalInfo &ei){

	MY_EV_ADD(32);

	Square yk  = your_king_pos;
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	//Bitboard matt = ma_to_king_attacks_bb(yma,BitboardOCC);

	// fen 4k4/4a4/b3b4/3R5/9/5nB2/9/3ABA3/9/4K4 w - - 0 1
	if (MY_SQ04 == yk){
		if (your_xiang_num == 2 && your_shi_num >= 1){
			MY_EV_SUB(128);
		}
	}

	// fen 3akab2/9/4b4/9/9/3N5/9/4BA3/4AK3/2B4r1 b - - 0 53
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(1);
		}
	}

	// 对方双相
	if(your_xiang_num == 2){
		if(your_shi_num == 2){
			if(yk == MY_SQ04){
				RETRUN_MUL(2);
			}
			if(StoY(yk) != MY_RANK2 && PB90(MY_SQ16) == your_xiang){
			    if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
					if(MY_SQ17 == yma || bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ17))){
						RETRUN_MUL(2);
					}
				}
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
					if(MY_SQ15 == yma || bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ15))){
						RETRUN_MUL(2);
					}
				}
			}
		}
		if(your_shi_num >= 1){
			if(yk == MY_SQ04){
				if(StoY(yma) MY_SMALL MY_RANK4){
					RETRUN_MUL(2);
				}
			}
		}
		//对方只有二个相了 //<<象棋残局例典>> 4 马双象 
		//第1局 一车例和马双象
		// fen 2bk5/9/4n4/9/2b6/4R4/9/9/9/4K4 w  //只有这种和形 中马,高象连环
		if(PB90(MY_SQ26) == your_xiang || PB90(MY_SQ2A) == your_xiang){
			int yx1 = S90_from_piecelist(POSITION,your_xiang,0);
			int yx2 = S90_from_piecelist(POSITION,your_xiang,1);

			 if(IsOnSameSide(yx1,yx2)){
				 //马能走到中间,或马在中间
				 if(MY_SQ16 == yma){
					 RETRUN_MUL(2);
				 }
				 //2,
				 if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ16)) && StoY(yk) == MY_RANK0){
					RETRUN_MUL(2);
				 }
			 }

		}
	}
	//对方双仕
	if(your_shi_num == 2){
		//<<象棋残局例典>> page 203 //一车例和马单缺象
		// fen 3ak1b2/4a4/5n3/1R7/9/9/9/9/9/4K4 w
		if(your_xiang_num >= 1){
			//1, 将在低线
			// fen 3k1a3/4a4/1R1nb4/9/9/9/9/B3K4/9/6B2 w - - 0 115
			if(StoY(yk) == MY_RANK0 && PB90(MY_SQ0D) == your_shi){
				if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ05) == your_shi){
					if(PB90(MY_SQ16) == your_xiang || PB90(MY_SQ02) == your_xiang){
						RETRUN_MUL(2);
					}
				}
				if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ03) == your_shi){
					if(PB90(MY_SQ16) == your_xiang || PB90(MY_SQ06) == your_xiang){
						RETRUN_MUL(2);
					}
				}
			}

			if(MY_SQ04 == yk){
				// fen 5kb2/9/3a1a3/9/2b6/9/9/4B4/3rA4/3NKA3 w - - 120 120 
				if(MY_SQ03 == yma || MY_SQ05 == yma){
					if(PB90(MY_SQ0D) == your_shi){
						RETRUN_MUL(2);
					}
				}
				//2, 仕结连环
				if(PB90(MY_SQ03) == your_shi){
					if(MY_SQ17 == yma && StoX(yk) >= 0x4){
						RETRUN_MUL(2);
					}
					if(PB90(MY_SQ06) == your_xiang && PB90(MY_SQ17) != your_shi){
						if(bit_is_set(ei.attacked_by(your_ma),MY_SQ17)){
							RETRUN_MUL(2);
						}
					}
				}
				if(PB90(MY_SQ05) == your_shi){
					if(MY_SQ15 == yma && StoX(yk) <= 0x4){
						RETRUN_MUL(2);
					}
					if(PB90(MY_SQ02) == your_xiang && PB90(MY_SQ15) != your_shi){
						if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ15))){
							RETRUN_MUL(2);
						}
					}
				}
			}
			// fen 3ak1b2/4a4/5n3/1R7/9/9/9/9/9/4K4 w
			// fen 3ak4/4a4/4bn3/9/8R/9/9/9/9/4K4 w - - 6 61:
		}
	}

	// fen 2b1k4/4a4/4b4/6R2/6n2/6B2/9/9/9/3A1K3 w - - 0 1
    if(your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(MY_SQ26 == yma || MY_SQ2A == yma){
			if(PB90(MY_SQ16) == your_xiang){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2bk1a3/4a4/7R1/9/2n6/9/9/9/4K4/2BA1AB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ02) == your_xiang && PB90(MY_SQ05) == your_shi){
			if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ15))){
				RETRUN_MUL(2);
			}
		}
		if(PB90(MY_SQ06) == your_xiang && PB90(MY_SQ03) == your_shi){
			if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ17))){
				RETRUN_MUL(2);
			}
		}
	}
	

	// fen 3a1k3/4a4/5n3/9/2R3b2/9/9/3A5/9/3AK1B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(have_bit(ei.attacked_by(your_ma),bb_your_xiang)){
			if(MY_SQ17 == yma && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(2);
			}
			if(MY_SQ15 == yma && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3nka3/9/3ab4/9/9/2B6/7R1/9/4A4/2BK1A3 w - - 0 1
    if(your_shi_num == 2 && MY_SQ04 == yk && your_xiang_num >= 1){
		if(MY_SQ03 == yma || MY_SQ05 == yma){
			RETRUN_MUL(2);
		}
	}

	

	//一车必胜马,双仕,关键是逼马到无仕的一边,并用帅助攻
	Bitboard mkatt = POSITION.Rook_attacks_bb(my_king_pos); // rook_attacks_bb(my_king_pos,BitboardOCC);
	if(m_have_bit(m_and(mkatt,MyUpBB[MY_RANK2]))){
		MY_EV_ADD(32);
	}

	if((StoX(yma) < 0x4 && PB90(MY_SQ03) != your_shi)
		|| (StoX(yma) > 0x4 && PB90(MY_SQ05) != your_shi)){
			MY_EV_ADD(64);
	}

	if(StoY(my_king_pos) == MY_RANK7){
		MY_EV_ADD(32);
	}

	// fen 2ba4R/4ak3/5n3/9/9/9/9/B4K3/4A4/3A2B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){

		MY_EV_SUB(96);

		if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ0D) == your_shi && PB90(MY_SQ03) == your_shi){
			if(have_bit(bb_your_xiang,LeftBB[0x5])){
				RETRUN_MUL(2);
			}
		}
		if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ0D) == your_shi && PB90(MY_SQ05) == your_shi){
			if(have_bit(bb_your_xiang,RightBB[0x3])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2bk1a3/R8/3n4b/9/9/2B6/9/4K4/4A4/5AB2 r
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(MY_SQ15 == yma && (PB90(MY_SQ02) == your_xiang || PB90(MY_SQ16) == your_xiang)){
			RETRUN_MUL(2);
		}
		if(MY_SQ17 == yma && (PB90(MY_SQ06) == your_xiang || PB90(MY_SQ16) == your_xiang)){
			RETRUN_MUL(2);
		}
	}

	// fen 3a5/4ak3/2R2n3/9/6b2/9/9/3A5/9/3A1KB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(MY_SQ17 == yma && PB90(MY_SQ2A) == your_xiang && StoX(mche) <= 0x4 && PB90(MY_SQ05) == EMPTY){
			RETRUN_MUL(2);
		}
		if(MY_SQ15 == yma && PB90(MY_SQ26) == your_xiang && StoX(mche) >= 0x4 && PB90(MY_SQ03) == EMPTY){
			RETRUN_MUL(2);
		}
	}

	

	// fen 6n2/4k4/4ba2b/R8/9/9/9/5K3/9/2BA5 w
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(MY_SQ06 == yma && PB90(MY_SQ17) == your_shi){
			RETRUN_MUL(4);
		}
		if(MY_SQ02 == yma && PB90(MY_SQ15) == your_shi){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4a4/b3b4/3R5/9/5nB2/9/3ABA3/9/4K4 w - - 0 1
	if (MY_SQ04 == yk){
		if (your_xiang_num == 2 && your_shi_num >= 1){
			if (PB90(MY_SQ16) == your_xiang){
				if (StoY(yma) MY_SMALL_EQL MY_RANK5){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2n4R1/5k3/3aba3/9/9/9/9/B2AB4/4AK3/9 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (PB90(MY_SQ16) == your_xiang){
			if (StoX(yk) == 0x5 && MY_SQ02 == yma){
				RETRUN_MUL(4);
			}
			if (StoX(yk) == 0x3 && MY_SQ06 == yma){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 1Rnk5/4a4/4ba3/9/9/9/9/B3K4/9/9 w - - 121 121
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == your_xiang){
			if(PB90(MY_SQ02) == your_ma && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ06) == your_ma && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ15) == your_ma){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ17) == your_ma){
				RETRUN_MUL(4);
			}
		}
		if(PB90(MY_SQ04)){
			if(PB90(MY_SQ26) == your_xiang){
				if(PB90(MY_SQ02) == your_ma || PB90(MY_SQ15) == your_ma){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ2A) == your_xiang){
				if(PB90(MY_SQ06) == your_ma || PB90(MY_SQ17) == your_ma){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4nkb2/9/4ba3/9/9/3R5/9/9/9/4K4 w - - 0 1
    if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(MY_SQ04 == yma){
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){
				MY_EV_SUB(32);
				if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ06) == your_xiang){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ1A) == your_xiang){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ06) == your_xiang){
					if(PB90(MY_SQ26) == your_xiang || PB90(MY_SQ2A) == your_xiang){
						RETRUN_MUL(4);
					}
				}
			}
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi){
				MY_EV_SUB(32);
				if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ02) == your_xiang){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ12) == your_xiang){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ02) == your_xiang){
					if(PB90(MY_SQ26) == your_xiang || PB90(MY_SQ2A) == your_xiang){
						RETRUN_MUL(4);
					}
				}
			}
		}
		// fen 5kb2/9/3nba3/9/4R4/9/9/9/9/4K4 b
		if(StoX(mche) == 0x4){
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){
				MY_EV_SUB(32);
				if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ06) == your_xiang){
					if(MY_SQ15 == yma || MY_SQ0B == yma){
						RETRUN_MUL(4);
					}
				}
			}
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi){
				MY_EV_SUB(32);
				if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ02) == your_xiang){
					if(MY_SQ17 == yma || MY_SQ0F == yma){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}
	// fen 4k1b2/3Ra4/4b4/9/4n4/9/9/9/9/3K5 w - - 0 1
	if(your_xiang_num == 2 && your_shi_num >= 1 && MY_SQ04 == yk && PB90(MY_SQ16) == your_xiang){
		if(PB90(MY_SQ0D) == your_shi){
			if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ15))){
				RETRUN_MUL(4);
			}
			if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ17))){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a1kb2/4a4/9/9/6n2/9/2R6/3A5/9/3AK1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){

		if(MY_SQ2A == yma && PB90(MY_SQ06) == your_xiang 
			&& PB90(MY_SQ03) == your_shi && PB90(MY_SQ17) == EMPTY){
				RETRUN_MUL(4);
		}
		if(MY_SQ26 == yma && PB90(MY_SQ02) == your_xiang 
			&& PB90(MY_SQ05) == your_shi && PB90(MY_SQ15) == EMPTY){
				RETRUN_MUL(4);
		}
	}

	// fen 2b1ka3/4a4/3n5/9/9/9/1R7/3K1A2B/9/2B2A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		//if(StoY(yma) MY_SMALL_EQL MY_RANK4){
		//	RETRUN_MUL(8);
		//}
		if(MY_SQ15 == yma || MY_SQ17 == yma){
			RETRUN_MUL(4);
		}
	}

	// fen 6n2/R3k4/4ba2b/9/9/9/9/5K3/9/2BA5 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}

	// fen 2b1ka3/4a4/3n5/9/9/9/1R7/3K1A2B/9/2B2A3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (MY_SQ02 == yma || MY_SQ06 == yma || MY_SQ15 == yma || MY_SQ17 == yma){
			RETRUN_MUL(8);
		}
	}
}
