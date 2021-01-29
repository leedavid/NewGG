#ifndef END_my_m_MT_R_1CHE1PAWN_B_1CHE
#define END_my_m_MT_R_1CHE1PAWN_B_1CHE
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//红方一车一兵, 黑方一车
void my_m_MT_R_1CHE1PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	int mcan = EV_MY_CAN;

	Bitboard yCheATT = POSITION.Rook_attacks_bb(yche);
	bool isstr = isStringByChe(POSITION,mche,mpawn,yche);

	// fen 4k1b2/4a4/9/5P1R1/2r6/9/9/4B4/4A4/4KAB2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		MY_EV_SUB(64);
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
		}
		// fen 3a5/4k4/3r4b/4P4/9/7R1/9/4B4/4K4/2B6 b - - 0 1
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(64);
		}
		if (StoY(yche) == MY_RANK2){
			MY_EV_SUB(64);
		}
	}

	// fen 3aka3/9/9/9/5r3/2B6/1p6R/4B4/4A4/3AK4 b - - 0 82 
	MY_EV_ADD(your_shi_num * 64 + your_xiang_num * 64);
	
	// <<象棋残局例典>> page295 车高兵仕例和车2仕
	if(your_shi_num == 2){
		if(StoY(yk) == MY_RANK0 
			|| StoY(mpawn) MY_SMALL StoY(yk)){
				if(StoX(mpawn) < 0x4){
					if(PB90(MY_SQ03) == your_shi){
						MY_EV_SUB(64);
					}
				}
				if(StoX(mpawn) > 0x4){
					if(PB90(MY_SQ05) == your_shi){
						MY_EV_SUB(64);
					}
				}
				RETRUN_MUL(1);
		}
	}

	MY_EV_ADD(96);  // 有兵方的加分.

	// fen 2b6/4k4/4b4/1r2P4/9/2B1R4/9/9/9/2BAKA3 w - - 0 1
	if(your_xiang_num == 2 && StoX(yk) == 0x4){
	   Square x = XYtoS(StoX(mche),StoY(yche));
	   if(PB90(x) == my_pawn && StoX(x) == 0x4 && StoY(x) MY_LARGE MY_RANK2){
		   RETRUN_MUL(1);
	   }
	}

	
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		
		// fen 3ak1b2/9/9/9/5r3/2P4R1/9/4B3B/4A4/4KA3 r 
		// 对方的兵没有过河
		if(StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE MY_RANK4){
				RETRUN_MUL(1);
			}
		}

		// fen 4ka3/1P1r5/4b4/9/9/1R7/9/3A5/9/3K5 w - - 26 26
		//车兵对车仕象
		if(your_king_pos == MY_SQ04){
			if(StoY(mche) MY_LARGE StoY(yche)){
				if((StoX(mpawn) <= 0x02 && PB90(MY_SQ05) == your_shi)
					|| (StoX(mpawn) >= 0x06 && PB90(MY_SQ03) == your_shi)){
						if(XYtoS(StoX(mche),StoY(yche)) == mpawn){
						     RETRUN_MUL(1)
						}
				}
			}
		}

		// fen 3ak4/9/4b4/5P3/9/9/1R7/9/4K4/5r3 w - - 196 196
		if(your_king_pos == MY_SQ04){
			if(my_shi_num == 0 && my_xiang_num == 0){
				if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
					RETRUN_MUL(1);
				}
			}
		}
	} // if(your_shi_num >= 1 && your_xiang_num >= 1){

	// fen 3k5/9/9/4R4/9/2B6/9/3A5/1r1K1p3/9 w - - 211 211
	// 单车领高仕
	if(your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1 && my_shi_num == 0){
		if(StoY(yche) MY_LARGE MY_RANK2){
			// R
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ15) == your_shi){
				if(StoX(mche) != 0x3){
					if(m_have_bit(
						m_and(yCheATT,_mm_load_si128 ((__m128i*)File3BB)))){
							RETRUN_MUL(1);
					}
				}
			}
			// L
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ17) == your_shi){
				if(StoX(mche) != 0x5){
					if(m_have_bit(
						m_and(yCheATT,_mm_load_si128 ((__m128i*)File5BB)))){
							RETRUN_MUL(1);
					}
				}
			}
		}
	}

	// 车兵难胜单缺仕	
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		// fen 2b1k4/9/4b4/9/9/6R2/5r3/4B4/4A2p1/4K1B2 w - - 41 41  
		if(abs(StoX(mpawn) - 0x4) > 2 || StoY(mpawn) != MY_RANK1){
			RETRUN_MUL(1);
		}
		// fen 4k1b2/4a4/4b4/9/5R3/9/9/4B4/6p2/2B1KA2r w - - 121 121
		if(StoX(mpawn) >= 0x5 && StoX(mche) >= 0x6){
			if(PB90(MY_SQ05) == your_shi && StoX(yche) == 0x5){
				RETRUN_MUL(1);
			}
		}
		if(StoX(mpawn) <= 0x3 && StoX(mche) <= 0x2){
			if(PB90(MY_SQ03) == your_shi && StoX(yche) == 0x3){
				RETRUN_MUL(1);
			}
		}
		// fen 3k5/4a4/9/9/2b2r3/9/9/B3B4/4Ap1R1/4K4 w - - 124 124
		if(StoY(mpawn)  MY_SMALL_EQL MY_RANK4 && StoY(mpawn) == StoY(yche) && StoX(mche) == StoX(mpawn)){
			if(PB90(MY_SQ0D) == your_shi && PB90(MY_SQ16) == your_xiang){
				if(StoX(mpawn) > 0x4){
					if(StoX(yche) > StoX(mpawn) && (PB90(MY_SQ12) == your_xiang || PB90(MY_SQ02) == your_xiang)){
						RETRUN_MUL(1);
					}
				}
				if(StoX(mpawn) < 0x4){
					if(StoX(yche) < StoX(mpawn) && (PB90(MY_SQ1A) == your_xiang || PB90(MY_SQ06) == your_xiang)){
						RETRUN_MUL(1);
					}
				}
			}
		}

		// fen 9/4k4/9/9/5R3/9/9/4B4/3p3r1/4KAB2 b - - 186 186
		if(StoY(mpawn) == MY_RANK1){
			if(StoX(mpawn) < 0x4){
				if(StoX(mche) > 0x4 && StoX(yche) == 0x5 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(1);
				}
			}
			if(StoX(mpawn) > 0x4){
				if(StoX(mche) < 0x4 && StoX(yche) == 0x3 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(1);
				}
			}
		}


	}// 车兵难胜单缺仕	

	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		// fen 5a3/4ak3/9/9/9/7r1/9/3R1A2B/3p1K3/2B6 w - - 0 0
		if(StoY(mpawn) == MY_RANK1){
			if(StoX(mpawn) < 0x4){
				if(PB90(MY_SQ17) == your_shi){
					if(StoX(mche) == 0x5 && PB90(MY_SQ15) == your_che && PB90(MY_SQ0E) == your_king){
						RETRUN_MUL(1);
					}
					if(StoX(mche) != 0x5 && StoX(yk) == 0x5){
						if(bit_is_set(yCheATT,XYtoS(0x5,StoY(yche)))){
							RETRUN_MUL(1);
						}
					}
				}
			}
			if(StoX(mpawn) > 0x4){
				if(PB90(MY_SQ15) == your_shi){
					if(StoX(mche) == 0x3 && PB90(MY_SQ17) == your_che && PB90(MY_SQ0C) == your_king){
						RETRUN_MUL(1);
					}
					if(StoX(mche) != 0x3 && StoX(yk) == 0x3){
						if(bit_is_set(yCheATT,XYtoS(0x3,StoY(yche)))){
							RETRUN_MUL(1);
						}
					}
				}
			}
		}
	}

	//车兵对1仕1相
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		// fen 5a3/4k4/5a3/9/9/9/9/5A3/2p3R2/5KBr1 w - - 120 
		if(StoY(yk) == MY_RANK0){
           if(StoY(mpawn) == MY_RANK1 && StoY(yche) == MY_RANK1){
			   //二个车在一边,车与兵不在一边
			   if(IsOnSameSide(mche,yche) && !IsOnSameSide(yche,mpawn)){
				   if(PB90(MY_SQ06) == your_xiang && StoX(yche) == 0x6){
					   RETRUN_MUL(1);
				   }
				   if(PB90(MY_SQ02) == your_xiang && StoX(yche) == 0x2){
					   RETRUN_MUL(1);
				   }
			   }
		   }
		}
		if(StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(1);
		}
	} //车兵对>1仕>1相

	// 红车兵对车,兵给倒牵制了也是和棋
	// fen 3ak4/9/5a3/9/2b3b2/2R6/9/2p6/2r1AK3/9 w - - 130 130 
	if(your_shi_num >= 1){
		if(isstr){
			if(StoY(yche) MY_LARGE StoY(mche)){
				if(abs(StoX(mpawn) - StoX(yk)) >= 2){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 4k4/2R6/2P1b4/2r6/9/9/9/4B3B/4A4/3AK4 w - - 0 0
	//对方有相, 且被反牵制了
	if(your_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && abs(StoX(mpawn) - 0x4) >= 2){
			if(PB90(mpawn MY_SUB 9) == my_che && (StoX(mche) == 0x2 || StoX(mche) == 0x6)){
				if(StoX(yche) == StoX(mpawn)){
					RETRUN_MUL(1);
				}
			}
		}
	}

	//
	if(StoY(mpawn) == MY_RANK0){
       // fen 4k1b2/9/3r5/9/5R3/9/9/5A3/3p5/5K3 b - - 115 115 高仕, 车保仕
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoX(yk) <= 0x4){
				if(PB90(MY_SQ15) == your_shi && StoX(mpawn) > 0x4){
					if(StoX(yche) == 0x3){
						RETRUN_MUL(1);
					}
				}
			}
			if(StoX(yk) >= 0x4){
				if(PB90(MY_SQ17) == your_shi && StoX(mpawn) < 0x4){
					if(StoX(yche) == 0x5){
						RETRUN_MUL(1);
					}
				}
			}
		}
		/////////////////////////////////////////////////////////////////////////////////
		// <<象棋残局例典>> page237 车底兵例和一车 
		// fen 4k1P2/9/4r4/3R5/9/9/9/9/9/3K5 w
		if(StoX(yche) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK2){
			RETRUN_MUL(1);
		}

		if(StoX(yche) == 0x4 || StoX(yk) == 0x4){
			if(StoY(yche) MY_LARGE StoY(yk)){
				if(your_shi_num != 0 || your_xiang_num != 0){
					RETRUN_MUL(1);
				}
			}
		}
		// fen 9/4k4/4b4/4r4/6b2/1R7/9/3A5/3K5/4p4 w - - 142 142
		if(StoY(yk) == MY_RANK1 && PB90(yk MY_ADD 9) == your_shi && StoY(yche) MY_LARGE MY_RANK2){
			RETRUN_MUL(1);
		}

		// fen 9/3k1P3/3r1a3/9/9/4R4/9/9/4A4/4K4 w  //高仕,左兵右将 
		// fen 5k3/3P5/3a5/3R5/5r3/2B6/9/5A2B/4A4/4K4 b - - 134 134 
		if(your_shi_num >= 1){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(StoX(yk) <= 0x4){
					if(PB90(MY_SQ17) == your_shi && StoX(mpawn) >= 0x4){
						RETRUN_MUL(1);
					}
					if(PB90(MY_SQ15) == your_shi && StoX(mpawn) <= 0x4){
						RETRUN_MUL(1);
					}
				}
			}
		}
		//l <<象棋残局例典>> 车低仕例和车仕 
		//车,仕例和车低兵, 术语称为:单车保剑或单车领仕
		//1, 形A , fen 3a5/3k1P3/9/9/4R4/3r5/9/9/4A4/4K4 w
		if(((MY_SQ0C == yk || (yk == MY_SQ15 && StoY(yche) != MY_RANK0)) && PB90(MY_SQ03) == your_shi 
			&& StoX(mpawn) > 0x4)
			|| ((MY_SQ0E == yk || (yk == MY_SQ17 && StoY(yche) != MY_RANK0)) && PB90(MY_SQ05) == your_shi 
			&& StoX(mpawn) < 0x4)){
				if(StoX(yche) == StoX(yk)){
					RETRUN_MUL(1);
				}
		}
	} // if(StoY(mpawn) == MY_RANK0){

	if(StoY(mpawn) == MY_RANK1){

		if(your_shi_num >= 1){
			//l <<象棋残局例典>> 车低仕例和车仕 
			//车,仕例和车低兵, 术语称为:单车保剑或单车领仕
			//1, 形A , fen 3a5/3k1P3/9/9/4R4/3r5/9/9/4A4/4K4 w
			if(((MY_SQ0C == yk || (yk == MY_SQ15 && StoY(yche) != MY_RANK0)) && PB90(MY_SQ03) == your_shi 
				&& StoX(mpawn) > 0x4)
				|| ((MY_SQ0E == yk || (yk == MY_SQ17 && StoY(yche) != MY_RANK0)) && PB90(MY_SQ05) == your_shi 
				&& StoX(mpawn) < 0x4)){
					if(StoX(yche) == StoX(yk)){
						RETRUN_MUL(1);
					}
			}
			// fen 9/3k1P3/3r1a3/9/9/4R4/9/9/4A4/4K4 w  //高仕,左兵右将
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(StoX(yk) <= 0x4){
					if(PB90(MY_SQ17) == your_shi && StoX(mpawn) > 0x4){
						if(PB90(MY_SQ15) == your_che){
							RETRUN_MUL(1);
						}
						if(bit_is_set(yCheATT,Square(MY_SQ15))){
							RETRUN_MUL(1);
						}
					}
				}
				if(StoX(yk) >= 0x4){
					if(PB90(MY_SQ15) == your_shi && StoX(mpawn) < 0x4){
						if(PB90(MY_SQ17) == your_che){
							RETRUN_MUL(1);
						}
						if(bit_is_set(yCheATT,Square(MY_SQ17))){
							RETRUN_MUL(1);
						}
					}
				}
			}
			// fen 4k1b2/9/3r5/9/5R3/9/9/5A3/3p5/5K3 b - - 115 115 高仕, 车保仕
			if(StoY(yk) MY_SMALL_EQL MY_RANK1 && my_shi_num == 0){
				if(StoX(yk) <= 0x4){
					if(PB90(MY_SQ15) == your_shi && StoX(mpawn) > 0x4){
						if(StoX(yche) == 0x3){
							RETRUN_MUL(1);
						}
					}
				}
				if(StoX(yk) >= 0x4){
					if(PB90(MY_SQ17) == your_shi && StoX(mpawn) < 0x4){
						if(StoX(yche) == 0x5){
							RETRUN_MUL(1);
						}
					}
				}
			}
			// fen 9/3kaRP2/9/9/3r5/9/9/9/4A4/4K4 w - - 6 6  //这个也是和形, 对方车将, 我方不得不上将
			if(PB90(MY_SQ0D) == your_shi && StoY(mche) == MY_RANK1){
				if(StoY(yche) MY_LARGE StoY(yk) && StoX(yche) == StoX(yk)){
					if(isStringByPao(POSITION,yk,mche,mpawn)){
						RETRUN_MUL(1);
					}
				}
			}
		} //if(your_shi_num >= 1){
	} // if(StoY(mpawn) == MY_RANK1){

	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			//<<象棋残局例典>> page249 车低兵例和车象
			if(StoY(yk) == MY_RANK2 ){
				if(StoX(yche) == 0x4 && StoY(yche) MY_LARGE MY_RANK2){
					if(abs(StoX(mpawn) - StoX(yk)) != 1){
						RETRUN_MUL(1);
					}

					// fen 6b2/5P3/4k4/9/3R5/4r4/9/9/9/5K3 w - - 8 8 
					//对方的车将不同线,且车与黑将相差一格,此时车也没有办法将
					if(abs(StoX(mche) - StoX(yk)) == 1){
						if(StoX(mche) != StoX(mk)){
							RETRUN_MUL(1);
						}
					}
				}
			}

			// fen 9/5P3/3kr3b/9/9/9/5R3/9/9/5K3 b - - 0 1
            if(StoX(yche) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK2){
				if(StoX(mk) == 0x5){
					if(PB90(MY_SQ06) == your_xiang || PB90(MY_SQ1A) == your_xiang){
						RETRUN_MUL(1);
					}
				}
				if(StoX(mk) == 0x3){
					if(PB90(MY_SQ02) == your_xiang || PB90(MY_SQ12) == your_xiang){
						RETRUN_MUL(1);
					}
				}
			}

			//3 
			// <<象棋残局例典>> page250 车低兵例和车象3
			// 象不高飞,与将同一侧 fen 4k1b2/6P2/9/5R3/9/9/4r4/9/9/5K3 w
			if(StoX(yche) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK2 && abs(StoY(yche) - StoY(mk)) >= 2){
				if(StoX(mche) > 0x4){
					if(PB90(MY_SQ06) == your_xiang){
						if(StoX(mpawn) > 0x4){
							RETRUN_MUL(1);
						}
					}
					if(PB90(MY_SQ1A) == your_xiang){
						if(StoX(yk) == 0x7){
							if(abs(StoX(mpawn) - StoX(yk)) > 1){
								RETRUN_MUL(1);
							}
						}
					}
				}
				else{
					if(PB90(MY_SQ1A) == your_xiang){
						if(StoX(mpawn) < 0x4){
							RETRUN_MUL(1);
						}
					}
				}

				if(StoX(mche) < 0x4){
					if(PB90(MY_SQ02) == your_xiang){
						if(StoX(mpawn) < 0x4){
							RETRUN_MUL(1);
						}
					}
					if(PB90(MY_SQ12) == your_xiang){
						if(StoX(yk) == 0x7){
							if(abs(StoX(mpawn) - StoX(yk)) > 1){
								RETRUN_MUL(1);
							}
						}
					}
				}
				else{
					if(PB90(MY_SQ12) == your_xiang){
						if(StoX(mpawn) > 0x4){
							RETRUN_MUL(1);
						}
					}
				}
			}
		}
		// fen 6b2/5P3/4k4/9/3R5/4r4/9/9/9/5K3 w - - 8 81:
	} //if(your_xiang_num >= 1){

	// fen 3R5/4k4/4b4/9/4r4/6P2/9/4B4/4A4/4KAB2 w - - 1 1 
	//如果是三七路兵, 且对方有
	if(your_xiang_num >= 1 && PB90(MY_SQ16) == your_xiang && my_xiang_num == 0){
		if(StoX(yche) == 0x4 && mcan == 0){
			RETRUN_MUL(1);
		}
	}

	// fen 3akab2/9/9/9/9/9/5R3/B4A3/3p4r/2B2K3 b - - 143 143 
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoY(yche) MY_SMALL_EQL MY_RANK3){
				if(StoX(yche) == StoX(yk) && !IsOnSameSide(yk,mpawn)){
					if(PB90(yk MY_ADD 9) == your_shi || PB90(yk MY_ADD 18) == your_shi){
						RETRUN_MUL(1);
					}
				}
			}
		}
	}

	//黑车黑兵被牵制了,不能动了,也是和棋
	// fen 4kab2/4a4/4b4/9/4R4/9/9/4p4/4r4/5K3 b - - 123 123 
	if(StoY(yk) == MY_RANK0 && PB90(MY_SQ0D) == my_che && MY_SQ16 == mpawn){
		if(StoX(yche) == 0x4){
			RETRUN_MUL(1);
		}
	}

	// fen 4ka1R1/9/1r7/9/6b2/9/9/4B4/1p7/4KA3 w - - 153 153
	// 兵被对方左右牵制住了,也是和棋
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoX(mpawn) == 0x8 && StoX(yche) == 0x8 && StoY(yche) == StoY(mpawn)){
			RETRUN_MUL(1);
		}
		if(StoX(mpawn) == 0x0 && StoX(yche) == 0x0 && StoY(yche) == StoY(mpawn)){
			RETRUN_MUL(1);
		}
	}
	// fen 4k4/4a4/3a5/5R3/7r1/6B2/9/4B4/4A1p2/4K4 w - - 0 0
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(MY_SQ04 == yk){
			if(PB90(MY_SQ0D) == your_shi){
				if(StoX(mpawn) > 0x5 && StoX(yche) == 0x5){
					RETRUN_MUL(1);
				}
				if(StoX(mpawn) < 0x3 && StoX(yche) == 0x3){
					RETRUN_MUL(1);
				}
			}
		}
	}

	//========================================================================
	// fen 2b1k4/4a4/9/4R4/4P4/2B1r1B2/9/9/5K3/9 w - - 201 201
	//车兵给对方在中线牵制住了,反面牵制住了
	if(PB90(MY_SQ04) == your_king){
		if(PB90(MY_SQ0D) == your_shi){
			if(StoX(yche) == 0x4 && StoX(mche) == 0x4){
				if(StoY(yche) MY_LARGE StoY(mche) && isstr){
					RETRUN_MUL(1);
				}
			}
		}
	}

	if(StoY(mpawn) == MY_RANK0){
		if(your_shi_num >= 1){
			RETRUN_MUL(1);
		}
	}

	// fen 9/4k4/b1R6/9/9/2P1r4/9/3A5/4A4/3K5 w - - 0 0
	if(mcan == 0 && your_xiang_num != 0){
		if(my_xiang_num == 0 && StoY(yche) == StoY(mpawn) && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(1);
		}
	}

	// fen 2b1k4/4a4/9/P1r6/9/9/R8/3AB4/4A4/3K5 w - - 6 6
	if(your_xiang_num >= 1 && your_shi_num >= 1){
		if(StoY(yk) == MY_RANK0 && StoY(mpawn) MY_SMALL_EQL MY_RANK4){
			if(StoX(mpawn) == 0x0 || StoX(mpawn) == 0x8){
				if(StoY(mpawn) == StoY(yche) && StoX(mche) == StoX(mpawn)){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 3a5/3k5/5a3/9/9/9/9/1rp4R1/4AK3/9 w - - 123 123
	//对方的车兵被牵制住了,且我方的将在一边, 对方无法解套.
	if(StoY(mche) == StoY(mpawn) && StoY(mche) == MY_RANK2 && isstr){
		if(PB90(MY_SQ0D) == your_shi){
			if(StoX(mche) < 0x4 && StoX(mpawn) < 0x3 && StoX(yche) > 0x3 && PB90(MY_SQ0E) == your_king){
				RETRUN_MUL(1);
			}
			if(StoX(mche) > 0x4 && StoX(mpawn) > 0x5 && StoX(yche) < 0x5 && PB90(MY_SQ0C) == your_king){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 5k3/6R2/5a3/9/8r/9/9/4B2p1/4A4/4K4 w - - 23 23
	if(your_xiang_num >= 1 && your_shi_num >= 1){
		if(PB90(MY_SQ04) == your_king){
			if(abs(StoX(mpawn) - 0x4) >= 3){
				if((my_shi_num + my_xiang_num) <= 1){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 9/4k4/9/9/9/5r1p1/6R2/4B4/9/2B1K4 w - - 79 79
	//这个兵方没有仕相, 胜红方有二个相以上
	if(your_xiang_num == 2 && my_shi_num == 0 && my_xiang_num == 0){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
				if(abs(StoX(mpawn) - 0x4) >= 3){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 9/5k3/9/p8/4R4/5r3/9/9/4K4/9 b - - 8 8
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(StoX(mpawn) != 0x4 && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(StoX(yche) == 0x4 && StoX(yk) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK4){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 3ak4/9/4ba3/9/6b2/9/9/3RB3r/2p6/4KA3 w - - 122 122
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK0){
			if(StoX(mpawn) < 0x3 && StoX(yche) == 0x3 && PB90(MY_SQ05) == your_shi){
				if(StoX(mche) > 0x5){
					RETRUN_MUL(1);
				}
			}
			if(StoX(mpawn) > 0x5 && StoX(yche) == 0x5 && PB90(MY_SQ03) == your_shi){
				if(StoX(mche) < 0x3){
					RETRUN_MUL(1);
				}
			}
		}
	}
	// fen 2b1k4/3R1P3/3ab4/5r3/9/9/9/9/4K4/2B3B2 w - - 140 140
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(mpawn) == MY_RANK1 && StoY(mpawn) == StoY(mche) && StoX(yche) == StoX(mpawn)){
			if(StoX(mche) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(1);
			}
			if(StoX(mche) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 5k3/4a4/b3b4/9/9/9/2R3p2/4B1r2/3KA4/9 w - - 120 120
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK4 && StoY(yk) MY_SMALL_EQL MY_RANK1 
			&& StoY(mche) MY_SMALL_EQL StoY(mpawn)){
				if(PB90(MY_SQ0D) == your_shi){
					if(!IsOnSameSide(mche,yk)){
						if(StoX(mche) == StoX(mpawn) && StoY(yche) == StoY(mpawn)){
							RETRUN_MUL(1);
						}
					}
				}
		}
	}

	// fen 2b6/1P1ka1R2/9/2r6/9/2B6/9/4B4/4A4/3AK4 w - - 33 33
	if(your_shi_num >= 1 && your_xiang_num >= 1 && !IsOnSameSide(mche,yk)){
		if(PB90(MY_SQ0D) == your_shi && StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) <= 0x1 && StoX(yche) == 0x2 && StoX(yk) == 0x3){
				RETRUN_MUL(1);
			}
			if(StoX(mpawn) >= 0x7 && StoX(yche) == 0x6 && StoX(yk) == 0x5){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 3P5/2P1k4/9/9/9/9/8r/9/4A4/3AKR3 w - - 0 0
	// fen 4k4/3P5/9/9/9/8r/9/9/4A4/3AK2R1 b - - 1 1

	if(your_shi_num >= 1 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK4 && StoX(mpawn) == StoX(mche)){
			if(StoX(mpawn) < 0x4){
				if(StoY(yche) == StoY(mpawn) && StoX(yche) == 0x3){
					RETRUN_MUL(1);
				}
			}
			if(StoX(mpawn) > 0x4){
				if(StoY(yche) == StoY(mpawn) && StoX(yche) == 0x5){
					RETRUN_MUL(1);
				}
			}
			if(StoX(mpawn) == 0x4){
				if(StoY(yche) == StoY(mpawn)){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 5k3/3Ra4/9/3P2r2/9/6B2/9/4KA3/9/5A3 b - - 120 120
	if(PB90(MY_SQ0D) == your_shi && StoY(mpawn) MY_SMALL_EQL MY_RANK4){
		if(StoY(yche) == StoY(mpawn) && StoX(mpawn) == StoX(mche) && !IsOnSameSide(mche,yk)){
			if(PB90(MY_SQ0C) == my_che){
				RETRUN_MUL(1);
			}
			if(PB90(MY_SQ0E) == my_che){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 3k5/4a4/4P1R2/9/4r4/2B6/9/4B4/4A4/4K4 b - - 0 1
	if (your_shi_num >= 1 && MY_SQ16 == mpawn){
		if (StoX(yche) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK3){
			if (StoX(yk) == 0x3 && StoX(mche) > 0x5){
				RETRUN_MUL(1);
			}
			if (StoX(yk) == 0x5 && StoX(mche) < 0x3){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 5k3/4P4/3a1r3/9/9/2B1R4/9/3A5/9/3AK1B2 b - - 0 0
	// fen 5k3/3P5/3a1r3/9/9/2B1R4/9/3A5/9/3AK1B2 w - - 0 0
	//if(StoX(yche) == StoX(yk) && StoY(yche) MY_LARGE_EQL StoY(yk)){
	//	if(PB90(MY_SQ0D) == my_pawn){
	//		if(POS_SIDE != PIECE_SIDE(my_pawn)){
	//			RETRUN_MUL(2);
	//		}
	//	}
	//}


	// fen 3a1k3/1R1P2r2/9/9/2b6/9/9/3A5/3KA4/9 b - - 128 128
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK0 && StoY(mpawn) == MY_RANK1){
		if(StoY(mche) == StoY(mpawn) && StoY(mche) == StoY(yche)){
			if(StoX(mpawn) <= 0x3 && StoX(mche) < StoX(mpawn)){
				if(StoX(yche) > 0x5 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(2);
				}
			}
			if(StoX(mpawn) >= 0x5 && StoX(mche) > StoX(mpawn)){
				if(StoX(yche) < 0x3 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 2b1k1b2/2r1a4/5a3/9/9/9/9/2p1R4/4A4/5K3 w - - 122 122
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) >= 2 && XYtoS(StoX(mche),StoY(yche)) == mpawn){
			if(IsOnSameSide(mpawn,yk) == FALSE){
				if(StoY(mpawn) MY_SMALL_EQL MY_RANK4){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3ak4/9/9/9/9/3RP4/4r4/3A5/4A4/2BK2B2 b - - 0 1
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ31) == my_pawn && PB90(MY_SQ3A) == your_che){
			if(StoY(mche) == MY_RANK5){
				RETRUN_MUL(2);
			}
		}
	}


	// fen 2b1k4/4a4/3ab4/6r2/9/9/9/3R2p2/4A4/3K5 w - - 0 0
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(IsOnSameSide(yk,mpawn) == FALSE && StoX(yche) == StoX(yk)){
			if(abs(StoX(mpawn) - 0x4) >= 2 && StoY(yche) MY_LARGE_EQL MY_RANK1){
				RETRUN_MUL(2);		
			}
		}
	}
	// fen 9/3k1P3/5R2b/9/4r4/9/9/9/5K3/9 b - - 0 1
	if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(yk) MY_LARGE_EQL MY_RANK1){
			if(StoX(yche) == 0x4 && (my_shi_num + my_xiang_num) == 0){
				if(abs(StoY(mche) - StoY(yk)) <= 1){
					if(StoX(yk) < 0x4 && have_bit(RightBB[0x4],bb_your_xiang)){
						RETRUN_MUL(2);
					}
					if(StoX(yk) > 0x4 && have_bit(LeftBB[0x4],bb_your_xiang)){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 3aka3/9/b8/9/p5b2/5R3/4r4/4B4/9/2BK5 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && StoY(yche) == MY_RANK4){
			if(StoX(mpawn) == 0x0 && PB90(MY_SQ02) == your_xiang){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) == 0x8 && PB90(MY_SQ06) == your_xiang){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4k4/4a2P1/4b4/2R6/6r2/9/9/3A5/9/2B1KA3 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) >= 0x7 && StoX(yche) == 0x6){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) <= 0x1 && StoX(yche) == 0x2){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4k1b2/9/9/9/4r3P/9/8R/3A1A3/5K3/9 w - - 0 1
	if (your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if (StoX(mche) == StoX(mpawn) && StoY(mche) MY_LARGE StoY(mpawn)
			&& StoY(mpawn) MY_LARGE MY_RANK2){
			if (StoX(mpawn) == 0x8 && PB90(MY_SQ06) == your_xiang){
				RETRUN_MUL(2);
			}
			if (StoX(mpawn) == 0x0 && PB90(MY_SQ02) == your_xiang){
				RETRUN_MUL(2);
			}
		}
	}



	// fen 9/4k4/4b3b/9/9/5RP2/9/3r1A3/9/4K1B2 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN == 0){
			RETRUN_MUL(2);
		}
		// fen 3akab2/9/4b4/3r4p/9/8R/9/9/9/2B1K1B2 w - - 0 1
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(XYtoS(StoX(yche),StoY(mche)) == mpawn){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/3k5/4b4/9/4r4/5RP2/9/3AB4/9/3A1K3 w - - 0 1
    if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ28) == your_che){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				if(abs(StoX(mpawn) - 0x4) == 2){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 2b4R1/4k4/4b4/r8/9/P8/9/9/9/2BAK1B2 w - - 0 1
	if (your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
		if (abs(StoX(mpawn) - 0x4) == 4 && StoY(mpawn) MY_LARGE_EQL MY_RANK5) {
			if (StoX(yche) == StoX(mpawn) && StoY(yche) MY_SMALL_EQL StoY(mpawn)) {
				RETRUN_MUL(2);
			}
		}
	}

	
	// fen 4k4/3R5/4b4/9/2r6/9/9/3Ap4/3K5/9 w - - 0 1
	if(my_shi_num == 0 && your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK2 && my_xiang_num == 0){
		if(StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi 
			&& StoX(yche) == 0x5 && StoX(mpawn) <= 4){
				RETRUN_MUL(2);
		}

		if(StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi 
			&& StoX(yche) == 0x3 && StoX(mpawn) >= 4){
				RETRUN_MUL(2);
		}
	}

	// fen 3a2b2/4a4/4k2P1/9/4R4/9/1r7/4B4/4A4/2B1K4 b - - 0 1
	if (your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK2 
		&& StoY(yche) MY_LARGE MY_RANK2){
		if (StoX(mpawn) > 0x5 && StoX(yk) <= 0x4){
			if (PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(2);
			}
		}
		if (StoX(mpawn) < 0x3 && StoX(yk) >= 0x4){
			if (PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k5/4a4/4r4/9/4PR3/9/9/4B4/4A4/3AK1B2 w - - 0 1
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			
			if(StoX(yche) == StoX(mpawn) && StoY(mche) == StoY(mpawn)){
				RETRUN_MUL(2);
			}
			if(StoX(yche) == 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k1b2/9/4b4/8R/8P/6B2/8r/3A4B/9/3K5 w - - 0 1
	if(your_xiang_num == 2 && abs(StoX(mpawn) - 0x4) == 4 && StoY(mche) MY_SMALL StoY(yche)){
		if(isStringByChe(POSITION,mche,mpawn,yche)){
			RETRUN_MUL(4);
		}
	}


	// fen 9/4ak3/5a3/8R/6P2/2r6/9/8B/4A4/3AK4 b - - 0 1
	if (your_shi_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK2) {
		if (StoY(yk) MY_SMALL_EQL MY_RANK1) {
			RETRUN_MUL(4);
		}
	}



	// fen 5k3/9/4b4/9/7R1/2P6/9/4B4/5r3/4K1B2 b - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 2){
			if(StoX(yk) != 0x4){
			   RETRUN_MUL(4);
			}
		}
	}

	// fen 5kb2/9/4b4/4R4/3r5/2B5P/9/8B/9/3AKA3 b - - 0 1
	if(your_xiang_num == 2 && abs(StoX(mpawn) - 0x4) == 4){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoX(mche) == StoX(mpawn) && StoY(yche) == StoY(mpawn)){
				if(StoX(mpawn) == 0x8 && PB90(MY_SQ06) == your_xiang){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn) == 0x0 && PB90(MY_SQ02) == your_xiang){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3R5/4k4/9/9/2b3b2/6B2/9/3K4B/4r4/5p3 w - - 0 1
	if(your_xiang_num == 2 && StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(4);
	}

	// fen 4k1b2/4a4/9/5P1R1/2r6/9/9/4B4/4A4/4KAB2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4a4/9/9/9/P2R5/r8/3A5/9/3AK4 r
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ2D) == my_pawn || PB90(MY_SQ35) == my_pawn){
			if(StoY(yche) MY_LARGE StoY(mpawn)){
				if(bit_is_set(ei.attacked_by(your_che),mpawn)){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2bk5/5P3/3a5/7R1/3r5/2B6/9/4B4/4A4/4K4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!IsOnSameSide(yk,mpawn) && StoX(yche) == StoX(yk)){
			if(PB90(XYtoS(StoX(yk), MY_RANK2)) == your_shi){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/1P7/3r1a3/9/9/9/5R3/9/5K3/9 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		if (your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if (StoX(mpawn) <= 0x3 && StoX(yche) <= 0x3 && StoX(yk)== 0x5){
				if (PB90(MY_SQ17) == your_shi && StoX(mche) == 0x5){
					RETRUN_MUL(4);
				}
			}
			if (StoX(mpawn) >= 0x5 && StoX(yche) >= 0x5 && StoX(yk) == 0x3){
				if (PB90(MY_SQ15) == your_shi && StoX(mche) == 0x3){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/4k4/4b4/9/8R/6P2/4r4/3A4B/5K3/3A5 b - - 0 1
	if (your_xiang_num >= 1 && StoX(yche) == 0x4){
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			if (StoX(mpawn) == 0x6 || StoX(mpawn) == 0x2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/9/3a1a3/9/pr7/2B6/9/9/4K4/R8 b - - 0 124
	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(bit_is_set(ei.attacked_by(your_che),mpawn)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a1kb2/4a4/9/4r3p/2b6/9/8R/9/4A4/4K4 w - - 4 4
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoX(mpawn) == 0x0 || StoX(mpawn) == 0x8){
			if(StoX(yche) == StoX(mpawn) && StoY(yche) MY_SMALL StoY(mpawn)
				&& StoY(mpawn) MY_LARGE_EQL MY_RANK5){
					if(StoY(mche) == StoY(mpawn)){
						RETRUN_MUL(4);
					}
			}
		}
	}
	// fen 4k4/3RaP3/4r3b/9/9/9/9/9/4A4/4KAB2 w - - 131 131
	if(your_shi_num >= 1 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mche,mpawn)){
			if(PB90(MY_SQ16) == your_che && PB90(MY_SQ0D) == your_shi){
				Bitboard x = _mm_setzero_si128();
				if(StoX(mche) < 0x4){
					x = m_and(bb_your_xiang,RightBB[0x4]);
				}
				if(StoX(mche) > 0x4){
					x = m_and(bb_your_xiang,LeftBB[0x4]);
				}
				if(count_1s(x) >= 1){
					RETRUN_MUL(4);
				}
			}
		}
	}
	// fen 9/9/3a1k3/1r7/9/2B6/3p5/2RA5/3K5/9 w - - 59 59
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(yche) == MY_RANK5){
			RETRUN_MUL(4);
		}
	}

	// fen 5ab2/5P3/5k3/R8/2b1r4/2B6/9/9/4A4/2B1KA3 w - - 0 1
    if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_LARGE_EQL StoY(mpawn)){
		if(StoY(yche) MY_LARGE MY_RANK2){
			if(StoX(mpawn) >= 0x4 && have_bit(bb_your_shi,RightBB[0x3])){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) <= 0x4 && have_bit(bb_your_shi,LeftBB[0x5])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b1k4/5P3/9/9/6b2/9/5R3/4r4/9/5K3 w - - 0 1
	if(your_xiang_num == 2){
		if(my_shi_num == 0 && my_xiang_num == 0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoX(yche) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK2){
				if(StoX(mche) >= 0x5 && StoX(mpawn) >= 0x5){
					RETRUN_MUL(4);
				}
				if(StoX(mche) <= 0x3 && StoX(mpawn) <= 0x3){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/4a4/3a5/1R7/9/r8/9/1p2B4/4A4/4K4 b - - 7 7
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && abs(StoX(mpawn) - 0x4) >= 2){
			RETRUN_MUL(4);
		}
	}

	// fen 5k3/9/9/9/9/4R4/3p3r1/9/4A4/3K5 w - - 166 166
	if(my_shi_num == 0 && my_xiang_num == 0 && your_shi_num >= 1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}
	
	// fen 4k4/4a4/3a5/1R7/9/r8/9/1p2B4/4A4/4K4 b - - 7 7
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoX(mpawn) == StoX(mche) && StoY(mche) MY_SMALL_EQL StoY(mpawn)) {
			if(StoY(yche) == StoY(mpawn)){
				if(StoX(mche) <= 2 && StoX(yche) >= 3){
					RETRUN_MUL(4);
				}
				if(StoX(mche) >= 6 && StoX(yche) <= 5){
					RETRUN_MUL(4);
				}
			}
		}
		// fen 5a3/4k2R1/5a3/3r5/9/9/3p5/4B4/4A4/4K4 b - - 120 120
		if(StoX(mche) == StoX(mpawn) && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}

	// fen R8/1P1k5/3a1a3/2r6/9/2B6/9/3AB4/9/3AK4 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoX(mpawn) - 0x4) >= 3){
			RETRUN_MUL(4);
		}
	}

	// fen 3a2b2/2P2R3/4k3b/9/3r5/6B2/9/4B4/4A4/5K3 w - - 0 1
    if(your_xiang_num == 2 && your_shi_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && StoY(yk) MY_LARGE_EQL MY_RANK1){
			if(StoX(mpawn) <= 0x3 && PB90(MY_SQ03) == your_shi && StoX(yche) == 0x3){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) >= 0x5 && PB90(MY_SQ05) == your_shi && StoX(yche) == 0x5){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a2R2/4ak3/6P2/9/9/2B6/9/5A3/4A2r1/5K3 b - - 0 1
    if(your_shi_num == 2 && StoY(mche) MY_SMALL StoY(mpawn) && StoX(mche) == StoX(mpawn)){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) >= 0x6 && StoX(yche) >= 0x7){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) <= 0x2 && StoX(yche) <= 0x1){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5a3/3Ra4/4k4/6P2/5r3/9/9/4B4/4A4/2BK5 b - - 0 1
	if (your_shi_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		if (StoY(yche) MY_LARGE_EQL MY_RANK3 && abs(StoX(yche) - 0x4) <= 1){
			RETRUN_MUL(4);
		}
	}

	// fen 3a4R/4ak1r1/6P2/9/9/2B6/9/5A3/4A4/5K3 r
	if(your_shi_num == 2 && StoY(yche) == StoY(yk) && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(yk) == 0x5 && StoX(yche) > 0x5){
				RETRUN_MUL(4);
			}
			if(StoX(yk) == 0x3 && StoX(yche) < 0x3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a2R2/4ak3/9/9/6P1r/9/9/4B4/4A4/4K1B2 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(mpawn) MY_LARGE StoY(mche) && StoX(mche) == StoX(mpawn)){
			if (StoY(mpawn) == StoY(yche)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5a3/4a4/5k3/3PR4/8r/9/9/B2A5/3KA4/9 w - - 0 1
	if (your_shi_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		if (StoY(yche) MY_LARGE StoY(yk)){
			if (StoX(yche) == StoX(yk)){
				RETRUN_MUL(4);
			}
		}
	}



	// fen 3a1k3/9/3r5/9/9/2B6/P3R4/3A1A2B/9/4K4 w - - 0 1
	//if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
	//	if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && StoY(mche) == StoY(mpawn)){
	//		RETRUN_MUL(4);
	//	}
	//}
	
	// fen 3ak4/9/b2ab4/9/9/9/6r2/9/2R3p2/3AK4 b - - 125 125
	if(your_shi_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(mpawn) == MY_RANK1 && StoY(yche) == StoY(mpawn) && StoX(mche) == StoX(mpawn)){
			if(StoX(mpawn) > 0x5 && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) < 0x3 && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bk5/1r3P3/9/9/2b2R3/9/9/3A5/5K3/9 w - - 0 1
	if (your_xiang_num == 2 && StoY(yk) == MY_RANK0 && StoY(mpawn) == MY_RANK1){
		if (abs(StoX(mpawn) - StoX(yk)) >= 2){
			if (StoX(mpawn) == StoX(mche) && StoY(mche) MY_LARGE StoY(mpawn)){
				if (StoY(yche) == StoY(mpawn)){
					if (StoX(mpawn) > 0x4 && StoX(yche) < 0x4){
						if (!have_bit(RightBB[0x4], bb_your_xiang)){
							RETRUN_MUL(8);
						}
					}
					if (StoX(mpawn) < 0x4 && StoX(yche) > 0x4){
						if (!have_bit(LeftBB[0x4], bb_your_xiang)){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}

	// fen 4k4/4a4/3a5/1R7/9/r8/9/1p2B4/4A4/4K4 b - - 7 7
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}

	// fen 3P5/4R4/5k3/9/9/8r/9/3A5/9/3AK4 b - - 0 0
	if(your_shi_num == 0 && your_shi_num == 0 && StoX(mche) == 0x4){
		MY_EV_ADD(128);
		// fen 5k3/9/9/9/4R4/5r2P/9/4B4/9/3AKAB2 b - - 0 1 
		if(StoY(mpawn) MY_LARGE StoY(yk)){
			MY_EV_ADD(512);
		}
	}

	// fen 3k5/9/4b4/4r4/7P1/7R1/9/3A5/3K5/9 w - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(64);
		}
	}
	// fen 3P1k3/9/4br3/4R4/6b2/9/9/9/3K5/9 b - - 0 194
	if(your_xiang_num == 2 && StoY(mpawn) == MY_RANK0){
		if(my_shi_num == 0 && my_xiang_num == 0){
			RETRUN_MUL(8);
		}
	}

	// fen 3P1k3/9/4br3/4R4/6b2/9/9/9/3K5/9 b - - 0 194
	if(your_xiang_num == 2 && my_shi_num == 0 && my_xiang_num == 0){
		if(StoX(yche) == 0x4 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(8);
		}
	}
	// fen 9/4k4/5R3/9/9/9/9/3r1p3/4A4/4K4 w - - 0 1
	if((my_shi_num + my_xiang_num) == 0){
		if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if(StoY(mche) == StoY(mpawn) && StoX(yche) == StoX(mpawn)){
					if(StoY(yche) MY_LARGE StoY(mpawn)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/9/9/4r4/4p4/5R2B/5K3/2B6 b - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if(StoY(yche) == MY_RANK2){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 4P4/5k3/9/4R4/6b2/9/9/9/4K4/5rB2 b
	if(StoY(mpawn) == MY_RANK0 && my_shi_num == 0 && my_xiang_num <= 1){
		if(your_xiang_num >= 1 && StoY(yche) MY_LARGE_EQL MY_RANK2){
			RETRUN_MUL(8);
		}
	}

	// fen 6R2/3ka4/9/9/4P4/9/9/4B4/4K4/5rB2 w - - 0 1
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			if(!IsOnSameSide(yk,mche)){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 3a1k3/9/3r5/9/9/2B6/P3R4/3A1A2B/9/4K4 w - - 0 1
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(8);
		}
	}

	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 2){
			RETRUN_MUL(8);
		}

		// // fen 9/3k5/3a5/9/2r5p/4R4/9/9/9/2B1K4 w - - 0 1
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 4){
			if (StoX(yche) == 0x4 && StoY(yche) == MY_RANK4){
				RETRUN_MUL(8);
			}
		}
	}

	
	

	// fen 3a2R2/4ak3/9/9/6P1r/9/9/4B4/4A4/4K1B2 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			RETRUN_MUL(8);
		}
	}

	


} // end 






