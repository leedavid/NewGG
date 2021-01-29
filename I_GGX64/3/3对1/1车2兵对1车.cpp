#ifndef END_my_m_MT_R_1CHE_2PAWN_B_1CHE
#define END_my_m_MT_R_1CHE_2PAWN_B_1CHE
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int PawnAdd = 64;

//我方一车二兵，对方一车
void my_m_MT_R_1CHE_2PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	sint16 pmok = (sint16)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheXPawn_To_Che_ByShi[your_shi_num]);
	
	
	int mcan = EV_MY_CAN;
	
	// fen 2b1ka3/4a4/4b4/p8/9/4r4/2R1p3p/4B4/4A4/3AK1B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		MY_EV_SUB(96);
	}

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	//int malr = My_pawn_already_over_river(POSITION);

 	// fen 3ak1b2/9/4br1P1/9/9/2P4R1/9/4B3B/4A4/4KA3 w - - 134 134
	//只有一个兵可过河，且另个兵不能过河
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(yk) == MY_RANK0){
			if(mcan <= 1){
				if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
					if(StoY(yche) == StoY(mpawn2) && StoX(mche) == StoX(mpawn2)){
						if(StoX(mpawn2) > 0x4 && StoX(yche) >= 0x4){
							RETRUN_MUL(2);
						}
						if(StoX(mpawn2) < 0x4 && StoX(yche) <= 0x4){
							RETRUN_MUL(2);
						}
					}
				}
				if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
					if(StoY(yche) == StoY(mpawn1) && StoX(mche) == StoX(mpawn1)){
						if(StoX(mpawn1) > 0x4 && StoX(yche) >= 0x4){
							RETRUN_MUL(2);
						}
						if(StoX(mpawn1) < 0x4 && StoX(yche) <= 0x4){
							RETRUN_MUL(2);
						}
					}
				}
				//3ak1bP1/9/4b4/9/5r3/2P4R1/9/4B3B/4A4/4KA3 r
				//一个兵到底了，且
				if(mcan == 0){
					if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
						RETRUN_MUL(2);
					}
				}
			} // if(mcan <= 1){
		}
	} 

	// fen 2b1ka3/4a4/4b4/5r3/2p3p2/4R4/9/4B4/9/4K1B2 b - - 0 1
	if (your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(yche) == MY_RANK4){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
				if (!have_bit(bb_my_pawn, LeftBB[0x2])
					&& !have_bit(bb_my_pawn, RightBB[0x7])){
					RETRUN_MUL(2);
				}
			}
		}
	}
 

	// fen 3ak4/4a4/4b4/9/3R5/2P3P2/4r4/3AB4/9/2B1KA3 w - - 121 121
	//
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(mcan == 0){
			RETRUN_MUL(2);
		}
		//如果二个兵都没有过河,也是和棋
		if(mcan == 1){
			if(My_pawn_already_over_river(POSITION) == 0){
				RETRUN_MUL(2);
			}
		}
	}	

	// fen 2b1ka3/9/4b4/8r/9/2P6/5R2P/3AB4/9/4KAB2 b - - 2 2
	//只有一人兵可过河,且另一个兵给顶住了
	if(mcan <= 1){
		if((your_shi_num + your_xiang_num) >= 3){
			if(StoY(yk) == MY_RANK0){
				int x = XYtoS(StoX(yche),StoY(mche));
				if(PB90(x) == my_pawn){
					if(StoY(x) MY_LARGE_EQL MY_RANK5){
						if(StoX(x) == 0x0 || StoX(x) == 0x8){
							RETRUN_MUL(2);
						}
					}
				}
			}
		}
	}	
	// fen 4k4/4a4/4b4/4r4/2b6/P2R2P2/9/9/4A4/2B1K1B2 b - - 124 124


	//--------------------------------------------------------------------
	// fen 3k5/4a4/R3Pa3/9/P3r4/9/9/4B4/4A4/2B1KA3 w - - 9 9
	//对方有二个仕, 且一个兵在中间,另一个车兵车成直角
	if(your_shi_num == 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ16) == my_pawn){
			if(StoX(yche) == 0x4){
				int x = XYtoS(StoX(mche),StoY(yche));
				if(PB90(x) == my_pawn){
					if(StoY(x) MY_SMALL_EQL MY_RANK4){
						if(abs(StoX(x) - 0x4) >= 2){
							RETRUN_MUL(2);
						}
					}
				}
			}
		}
	}	

    // fen 4kab1R/9/4b4/9/9/6P1P/8r/4B4/4A4/3AK1B2 w - - 6 6
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(mcan <= 1 && StoX(mche) == StoX(yche)){
			if(StoX(mche) == 0x0 || StoX(mche) == 0x8){
				if(StoY(mche) MY_SMALL StoY(yche)){
					if(StoX(mpawn1) == StoX(mche)){
						if(isStringByChe(POSITION,mche,mpawn1,yche)){
							RETRUN_MUL(2);
						}
					}
					if(StoX(mpawn2) == StoX(mche)){
						if(isStringByChe(POSITION,mche,mpawn2,yche)){
							RETRUN_MUL(2);
						}
					}
				}
			}
		}
	}
	// fen 2baka3/9/4b4/7r1/2p6/9/4R4/p3B4/4A4/3AK4 w - - 12 12
	if(mcan <= 1){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 || StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3a1k3/4a4/r3P4/9/9/2B6/P3R4/3A4B/4A4/4K4 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == my_pawn){
			Square mp = XYtoS(StoX(yche),StoY(mche));
			if(PB90(mp) == my_pawn && abs(StoX(mp) - 0x4) == 4 && StoY(mp) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 6b2/4k4/8b/9/6p1p/2R6/r8/4B4/4A4/4K1B2 b - - 173 173
	//兵方二个兵都在家
	if(your_xiang_num == 2 && your_shi_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(yche) == MY_RANK4 && PB90(MY_SQ16) == your_xiang){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				if(StoX(mpawn1) == 0x2 || StoX(mpawn1) == 0x6){
					if(StoX(mpawn2) == 0x0 || StoX(mpawn2) == 0x8){
						RETRUN_MUL(2);
					}
				}
				if(StoX(mpawn2) == 0x2 || StoX(mpawn2) == 0x6){
					if(StoX(mpawn1) == 0x0 || StoX(mpawn1) == 0x8){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 2b1k4/4a3P/5a3/P6r1/9/9/R8/3A5/3K5/9 w - - 74 74
	//一个兵在边上，一个兵十字
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		int x = XYtoS(StoX(mche),StoY(yche));
		if(PB90(x) == my_pawn && StoY(x) MY_LARGE MY_RANK2){
			if(StoX(x) == 0x0 && PB90(MY_SQ02) == your_xiang){
				if(mpawn1 != x && StoX(mpawn1) >= 0x7){
					RETRUN_MUL(2);
				}
				if(mpawn2 != x && StoX(mpawn2) >= 0x7){
					RETRUN_MUL(2);
				}
			}
			if(StoX(x) == 0x8 && PB90(MY_SQ06) == your_xiang){
				if(mpawn1 != x && StoX(mpawn1) <= 0x1){
					RETRUN_MUL(2);
				}
				if(mpawn2 != x && StoX(mpawn2) <= 0x1){
					RETRUN_MUL(2);
				}
			}
		}
	}
	// fen 5a3/3k5/9/R8/9/9/3r5/4B4/3pAp3/4KAB2 w - - 40 40
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0E) == my_pawn){
		}
		else{
			RETRUN_MUL(2);
		}
	}

	// fen 3ak4/1P2a4/8r/9/2b6/2R5P/9/4B4/4A4/2B1KA3 w - - 33 33
	if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn1) == StoY(mche) 
			&& StoX(yche) == StoX(mpawn1)){
				if(StoX(mpawn1) == 0x0 || StoX(mpawn1) == 0x8){
					RETRUN_MUL(2);
				}
		} 
		if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) == StoY(mche) 
			&& StoX(yche) == StoX(mpawn2)){
				if(StoX(mpawn2) == 0x0 || StoX(mpawn2) == 0x8){
					RETRUN_MUL(2);
				}
		}
	}	
	// fen 3ak4/9/3ab4/r8/6b2/9/9/4B1R2/4A2pp/3AK4 w - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn1) <= 1 && StoX(mpawn2) <= 1){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn1) >= 7 && StoX(mpawn2) >= 7){
				RETRUN_MUL(2);
			}
		}
	}
	
	// fen 3akab2/9/9/9/r8/8P/P2R5/3AB4/4A4/2B1K4 b - - 32 32
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
			int x = XYtoS(StoX(yche),StoY(mche));
			if(PB90(x) == my_pawn){
				if(StoX(x) == 0x0 || StoX(x) == 0x8){
					if(StoX(yche) == MY_RANK4){
						RETRUN_MUL(2);
					}
				}
			}
			// fen 3ak1b2/4a4/9/9/6r2/P3R3P/9/B8/9/3AKA3 b - - 120 120 
			if(StoY(mche) == StoY(mpawn1) && StoY(mche) == StoY(mpawn2)
				&& StoY(yche) == MY_RANK4){
					RETRUN_MUL(2);
			}
		}
	}

	// fen 3ak4/4a4/4b4/p2r4p/5R3/9/9/9/4A4/3AK4 w - - 12 12
	if(your_shi_num == 2 && PB90(MY_SQ04) == your_king){
		if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ3E) == my_pawn){
			if(StoY(yche) == MY_RANK5 && StoY(mche) == MY_RANK6){
				RETRUN_MUL(2);
			}
		}
	}	

	// fen 4k1b2/9/3aba3/9/9/p1R6/r3p4/9/4A4/2BA1K3 w - - 121 121
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(!IsOnSameSide(yk,mche) && abs(StoX(mche) - 0x4) >= 4 
			&& StoY(yche) MY_LARGE StoY(mche)){
			if(PB90(XYtoS(StoX(mche),StoY(yche))) == my_pawn){
				if(StoY(mpawn1) != StoY(mpawn2)){
					RETRUN_MUL(2);
				}
			}
		}
	}		

	// fen 4k4/9/3rb4/9/2b6/5R3/9/4B4/4A1pp1/2B1K4 b - - 120 120
	if(your_shi_num >= 1 && your_xiang_num == 2 && PB90(MY_SQ04) == your_king){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn1) >= 0x6 && StoX(mpawn2) >= 0x6){
				if(StoX(yche) == 0x5){
					RETRUN_MUL(2);
				}
			}
			if(StoX(mpawn1) <= 0x2 && StoX(mpawn2) <= 0x2){
				if(StoX(yche) == 0x3){
					RETRUN_MUL(2);
				}
			}
		}
	}
	
	// fen 4ka3/4a4/4b4/9/p4r2p/4R4/9/9/4A4/3AK4 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn1) == MY_RANK5 && StoY(mpawn2) == MY_RANK5){
			if(StoY(yche) == MY_RANK4){
				if(my_xiang_num == 0){
					RETRUN_MUL(2);
				}
				if(PB90(MY_SQ2F) != my_pawn || PB90(MY_SQ33) != my_pawn){
					RETRUN_MUL(2);
				}
			}
		}
	}


	// fen 4k4/4aPP2/5a3/3R5/2b6/9/4r4/5A3/4A4/5K3 w - - 218 218
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoX(yche) == 0x4){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(PB90(MY_SQ03) != your_shi && StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ05) != your_shi && StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 6b2/R2k5/3ab4/9/P8/2P6/r8/4BA3/4A4/2B2K3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
             Bitboard bp = m_and(ei.attacked_by(your_che),
				 m_and(ei.attacked_by(my_che),bb_my_pawn));
			 if(m_have_bit(bp)){
				 if(StoX(yche) == StoX(mche) && StoY(yche) MY_LARGE_EQL StoY(mche)){
					 Square p = pop_1st_bit_sq(bp);
					 if(abs(StoX(p) - 0x4) == 4){
						 RETRUN_MUL(4);
					 }
				 }
			 }
		}
	}

	// fen 5k3/4a4/5a3/9/9/2r6/9/2p2R2B/2p1A4/3A1K3 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(IsOnSameSide(mpawn1,mpawn2) && !IsOnSameSide(mpawn1,yk)){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
				if(StoY(mpawn1) != StoY(mpawn2)){
					if(PB90(XYtoS(StoX(mche),StoY(yche))) == my_pawn){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}



	// fen 2b1k4/4a4/4b4/4R4/4P3r/6P2/9/9/4A4/4KAB2 b - - 0 1
	if(your_xiang_num == 2 && your_shi_num >= 1 && EV_MY_CAN <= 1){
		if(PB90(MY_SQ28) == my_pawn && PB90(MY_SQ1F) == my_che){
			if(StoY(yche) == MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k1b2/4a3P/4b4/6r1P/9/6B1R/9/4B4/9/4K4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(StoY(yche) == MY_RANK3 
			&& have_bit(bb_my_pawn,RankBB_A[MY_RANK3])
			&& have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				if(!have_bit(bb_my_pawn,LeftBB[0x7])){
					if(PB90(MY_SQ23) == my_pawn && PB90(MY_SQ21) == your_che){
						RETRUN_MUL(4);
					}
				}
				if(!have_bit(bb_my_pawn,RightBB[0x1])){
					if(PB90(MY_SQ1B) == my_pawn && PB90(MY_SQ1D) == your_che){
						RETRUN_MUL(4);
					}
				}
		}
	}



	// fen 4k1b2/4a4/9/r7P/6b2/9/P7R/5A3/4A4/4K1B2 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
	    if(StoY(mche) MY_LARGE_EQL MY_RANK5){
			Square bp = XYtoS(StoX(mche),StoY(yche));
			if(PB90(XYtoS(StoX(yche),StoY(mche))) == my_pawn
				&& PB90(bp) == my_pawn){
				if(abs(StoX(bp) - 0x4) == 4 && StoY(bp) MY_LARGE_EQL MY_RANK2){
					if(bit_is_set(YOUR_ATTACK, XYtoS(StoX(bp), MY_RANK2))){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	

	// fen 2bk1a3/4aP3/9/3r1P3/9/5R3/9/3A4B/4A4/4K1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		// 有一个兵在2线以上，且兵边有仕
		Square x = XYtoS(StoX(mche),StoY(yche));
		if(PB90(x) == my_pawn && StoY(x) MY_LARGE_EQL MY_RANK3){
			if(StoX(x) == 0x5 && PB90(MY_SQ05) == your_shi){
				if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoX(mpawn1) >= 0x5){
					RETRUN_MUL(4);
				}
				if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && StoX(mpawn2) >= 0x5){
					RETRUN_MUL(4);
				}
			}
			if(StoX(x) == 0x3 && PB90(MY_SQ03) == your_shi){
				if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoX(mpawn1) <= 0x3){
					RETRUN_MUL(4);
				}
				if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && StoX(mpawn2) <= 0x3){
					RETRUN_MUL(4);
				}
			}
		}
	}
	
	// fen 4ka3/4a4/1PP1b4/7R1/1r7/2B6/9/4B4/9/3AKA3 w - - 122 122
	if(your_shi_num == 2 && PB90(MY_SQ04) == your_king && your_xiang_num >= 1){

		if((my_shi_num + my_xiang_num) <= 2){
			MY_EV_SUB(64);
		}

		if(IsOnSameSide(mpawn1,mpawn2)){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
				if(StoX(mpawn1) < 0x3 && StoX(mpawn2) < 0x3){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn1) > 0x5 && StoX(mpawn2) > 0x5){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4P4/R2P1k3/4ba3/9/3r5/9/9/3A5/9/3AK4 r
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK1){
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){
			// 看另一个兵
			Bitboard p2l = m_and(bb_my_pawn,RankBB_A[MY_RANK1]);
			if(m_have_bit(p2l)){
				Square sp2 = pop_1st_bit_sq(p2l);
				if(StoY(mche) == MY_RANK1 && PB90(MY_SQ16) == your_xiang 
					/*&& StoX(yche) == StoX(sp2)*/){
					if(StoX(sp2) < 0x4 && StoX(mche) < StoX(sp2) 
						&& StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){
							RETRUN_MUL(4);
					}
					if(StoX(sp2) > 0x4 && StoX(mche) > StoX(sp2) 
						&& StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi){
							RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 5kb2/4a4/4b4/r3P4/9/P3R4/9/9/9/3AK4 w - - 0 1
	if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4]) && my_xiang_num == 0){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				if(count_1s(ei.attacked_by(my_che),bb_my_pawn) == 2){
					if(count_1s(ei.attacked_by(your_che),bb_my_pawn) == 2){
						if(StoY(mche) MY_LARGE StoY(yche)){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}		
	}

	
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		// fen 5a3/3ka4/9/9/8r/2B3P2/3R4P/4B4/4K4/5A3 b - - 3 3
		if(StoY(mche) == MY_RANK6 && StoY(yche) == MY_RANK4){
			if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ33) == my_pawn){
				if(StoX(yche) == 0x8){
					RETRUN_MUL(4);
				}				
			}
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ2F) == my_pawn){
				if(StoX(yche) == 0x0){
					RETRUN_MUL(4);
				}				
			}
		}
		// fen 5a3/3ka4/9/9/6P1r/2B6/6R1P/4B4/4K4/5A3 b - - 0 0
		if(StoX(yk) < 0x4 && PB90(MY_SQ15) == your_shi){
			if(StoX(mche) == 0x6 && StoX(yche) == 0x8){
				if(   (PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ3C) == my_che)
					||(PB90(MY_SQ35) == my_pawn && PB90(MY_SQ33) == my_che)){
						int x = XYtoS(StoX(mche),StoY(yche));
						if(PB90(x) == my_pawn){
							RETRUN_MUL(4);
						}
				}
			}
		}
		// fen 5a3/3k5/3a5/9/6P1r/2B6/6R1P/4B4/4K4/5A3 w
		if(StoX(yk) > 0x4 && PB90(MY_SQ17) == your_shi){
			if(StoX(mche) == 0x2 && StoX(yche) == 0x0){
				if(   (PB90(MY_SQ36) == my_pawn && PB90(MY_SQ38) == my_che)
					||(PB90(MY_SQ2D) == my_pawn && PB90(MY_SQ2F) == my_che)){
						int x = XYtoS(StoX(mche),StoY(yche));
						if(PB90(x) == my_pawn){
							RETRUN_MUL(4);
						}
				}
			}
		}
	}

	// fen 4k1b2/4a4/4ba3/4r4/9/6B2/4p1R2/3A5/4A2p1/3K5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		Square x = XYtoS(StoX(mche),StoY(yche));
		if(x == MY_SQ1F && PB90(x) == my_pawn){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && abs(StoX(mpawn1) - 0x4) >= 3){
				RETRUN_MUL(4);
			}
			if(StoY(mpawn2) MY_SMALL_EQL MY_RANK2 && abs(StoX(mpawn2) - 0x4) >= 3){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 3ak4/4a4/4b3b/9/9/1R6p/9/5K3/4A3r/p1BA2B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		bool bad = false;
		Square p = SQ_START;
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2){
			if(IsOnSameSide(yk,mpawn1) == false){
               bad = true; p = mpawn2;
			}
		}
		if(StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
			if(IsOnSameSide(yk,mpawn2) == false){
				bad = true; p = mpawn1;
			}
		}
		if(bad){
			if(StoY(mche) MY_SMALL StoY(p) && StoX(mche) == StoX(p)){
				if(bit_is_set(ei.attacked_by(my_che),p) && bit_is_set(ei.attacked_by(your_che),p)){
					if(StoX(p) == 0x0 || StoX(p) == 0x8){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3aka3/6P2/9/r7P/6b1R/9/9/4B4/4A4/2BAK4 b - - 0 1
    if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		//有一个兵在3线下
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			Bitboard op = m_and(bb_my_pawn,MyLowBB[MY_RANK2]);
			if(m_have_bit(op)){
				Square pawn1 = pop_1st_bit_sq(op);
				if(StoY(yche) == StoY(pawn1)){
					if (StoX(pawn1) == 0x8 && bit_is_set(YOUR_ATTACK, MY_SQ1A)){
						RETRUN_MUL(4);
					}
					if (StoX(pawn1) == 0x0 && bit_is_set(YOUR_ATTACK, MY_SQ12)){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3ak1b2/4a4/5PP2/4R4/9/2B6/5r3/9/4A4/2BK1A3 b - - 0 1
	if(your_shi_num == 2 && MY_SQ04 == yk && your_xiang_num >= 1){
		if(StoY(yche) MY_LARGE_EQL MY_RANK3){
		   if(StoX(yche) == 0x5 && PB90(MY_SQ17) == my_pawn && PB90(MY_SQ18) == my_pawn){
			   RETRUN_MUL(4);
		   }
		   if(StoX(yche) == 0x3 && PB90(MY_SQ15) == my_pawn && PB90(MY_SQ14) == my_pawn){
			   RETRUN_MUL(4);
		   }
		}
	}


	// fen 4ka3/4a4/9/8P/3r5/9/PR7/8B/9/3K5 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if (my_shi_num == 0 && my_xiang_num <= 1){
			if (StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn1) - 0x4) == 4){
				RETRUN_MUL(6);
			}
			if (StoY(mpawn2) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn2) - 0x4) == 4){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 9/5k3/9/9/4R4/9/1r5p1/1p2B4/4A4/4KA3 w - - 185 185
	//没有仕相要降一些分
	if(my_shi_num == 0 && my_xiang_num == 0){
		// fen 9/5k3/9/9/4R4/9/1r5p1/1p2B4/4A4/4KA3 w - - 185 185
		if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
			if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2){
				RETRUN_MUL(8);
			}
		}
		// fen 4k1b2/4a4/4b2P1/9/9/4PR3/9/9/7r1/4K4 w - - 44 44
		if(your_shi_num >= 1 && your_xiang_num == 2 && PB90(MY_SQ04) == your_king){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 || StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}
	
	if((your_shi_num + your_xiang_num) <= 1){
		MY_EV_ADD(64);
	}

	// fen 9/2PPak2R/5a3/4r4/9/9/9/9/9/3K5 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				MY_EV_SUB(32);
				if(!have_bit(bb_my_pawn,RightBB[0x3]) && StoX(yk) == 0x5){					
						RETRUN_MUL(8);				
				}
				if(!have_bit(bb_my_pawn,LeftBB[0x5]) && StoX(yk) == 0x3){					
						RETRUN_MUL(8);					
				}
			}
		}
	}


	// fen 4ka3/4aP3/9/8R/9/4r3P/9/3A5/3KA4/9 w - - 0 1
	if(your_shi_num == 2 && MY_SQ04 == yk && abs(StoX(mche) - 0x4) == 4){
		if(!have_bit(bb_my_pawn,LeftBB[0x4]) && PB90(MY_SQ05) == your_shi){
			if(abs(StoX(mpawn1) - 0x4) == 4 && StoX(mpawn1) == StoX(mche) && StoY(mche) MY_SMALL StoY(mpawn1)){
				if(StoY(yche) == StoY(mpawn1) && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
			if(abs(StoX(mpawn2) - 0x4) == 4 && StoX(mpawn2) == StoX(mche) && StoY(mche) MY_SMALL StoY(mpawn2)){
				if(StoY(yche) == StoY(mpawn2) && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
		}
		if(!have_bit(bb_my_pawn,RightBB[0x4]) && PB90(MY_SQ03) == your_shi){
			if(abs(StoX(mpawn1) - 0x4) == 4 && StoX(mpawn1) == StoX(mche) && StoY(mche) MY_SMALL StoY(mpawn1)){
				if(StoY(yche) == StoY(mpawn1) && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
			if(abs(StoX(mpawn2) - 0x4) == 4 && StoX(mpawn2) == StoX(mche) && StoY(mche) MY_SMALL StoY(mpawn2)){
				if(StoY(yche) == StoY(mpawn2) && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
		}
	}

	
	if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		// fen 2raka3/1P7/8b/3P3R1/9/2B6/9/3AB4/9/3A1K3 b - - 0 0
		if(abs(StoX(mpawn1) - 0x4) >= 3 || abs(StoX(mpawn2) - 0x4) >= 3){
			RETRUN_MUL(8);
		}

		// fen 4kab2/4a4/6PP1/9/3R5/9/6r2/5A3/5K3/3A5 w - - 0 0
		//if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
  //          if(IsOnSameSide(mpawn1,mpawn2)){
		//		if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2 ){
		//			RETRUN_MUL(8);
		//		}
		//	}
	 //   }
	}

	// fen 9/4k4/9/8p/9/p8/9/9/3KAR3/4rA3 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(your_shi_num == 2){
			if(abs(StoX(mpawn1) - 0x4) >= 3 && abs(StoX(mpawn2) - 0x4) >= 3){
				RETRUN_MUL(8);
			}
		}
		// fen 3a1k3/4a4/9/9/4R4/P8/4P4/9/4K4/5r3 b - - 0 1
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			RETRUN_MUL(8);
		}
		//如果一个兵在家里，一个兵在二线。
		// fen 2bak4/9/9/9/3r5/P1R6/4P4/9/4K4/9 w - - 0 1
		if(your_shi_num >= 1 && your_xiang_num >= 1 && yk == MY_SQ04){
			MY_EV_SUB(64);
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(8);
			} 	
		}
	}

	// fen 3a1k3/4a4/9/9/4R4/P8/4P4/9/4K4/5r3 b - - 0 1
	// fen 4k4/4a4/4b4/9/4r4/P1BR4P/9/9/4A4/3AK4 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			RETRUN_MUL(8);
		} 
	}

	// fen 4k1b2/4a1P2/4b4/1R7/5r3/6P2/9/9/4K4/2B3B2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN <= 1){
			if(StoX(yche) == 0x5){
				if(StoX(mpawn1) >= 0x6 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
				if(StoX(mpawn2) >= 0x6 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
			if(StoX(yche) == 0x3){
				if(StoX(mpawn1) <= 0x2 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
				if(StoX(mpawn2) <= 0x2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2b1ka3/4aP3/4b4/4R4/4P3r/6P2/9/4B4/3KA4/5A3 b - - 0 1
	if(your_shi_num >= 1 && EV_MY_CAN <= 1 && your_xiang_num == 2){
		if(MY_SQ04 == yk){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				RETRUN_MUL(8);
			}
		}
	}


	// fen 4ka3/4a4/9/4R4/9/9/4pp3/8B/9/3AKA1r1 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			bmp = m_and(MyLowBB[MY_RANK2], bmp);
			int p = (int)count_1s(bmp);
			if(p == 2){
				MY_EV_SUB(168);
			}
			// fen 3a1kbR1/3Pa4/6r2/5P3/9/2B6/9/8B/4A4/3AK4 w - - 116 116
			if(p == 1){
				MY_EV_SUB(128);
			}
		}
		// fen 2b1k4/4a4/4ba3/9/3r5/2R6/4pp3/9/4A4/2B1KA3 b - - 0 1

		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			RETRUN_MUL(8);
		}

		RETRUN_MUL(10);
	}

	//
}

