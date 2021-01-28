#ifndef END_my_m_MT_R_1che2pawn_B_1che1pawn
#define END_my_m_MT_R_1che2pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int const_Pawn_Add = 32;

//红方1车2兵，黑方1车1兵
void my_m_MT_R_1che2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePawn_To_ChePawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_ChePawn_To_ChePawnByShi[my_shi_num]);

	Square mpawn1 = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mpawn2 = S90_from_piecelist(POSITION, my_pawn, 1);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);

	int malr = My_pawn_already_over_river(POSITION);
	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);

	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	if((your_shi_num + your_xiang_num) <= 3){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 4ka3/4aR3/b8/3PP4/9/9/9/4B3B/3r1p3/3AK4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if (my_shi_num <= 1 && abs(StoY(mk) - StoY(ypawn)) <= 1){
			MY_EV_SUB(64);
		}
	}

    // fen 2P2a3/1R3P3/b4k2b/3r5/9/9/9/9/4K4/1p7 b - - 0 1
	if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
		if(count_1s(bb_my_pawn,MyUpBB[StoY(mk)]) == 2){
			if(your_shi_num >= 1){
				MY_EV_SUB(64);
				if((my_shi_num + my_xiang_num) == 0){
					MY_EV_SUB(64);
				}
			}
		}
	}

	//还有一种情况,就是有多仕相一方只有一兵,且那个兵被对方的兵挡住了,就是和棋
	

	// fen 9/3ka4/3aR4/9/8p/P5P2/8r/4B4/9/4KA3 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num <= 1 && my_xiang_num <= 1){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				MY_EV_SUB(64);
			}
			if(my_shi_num == 0 && EV_YOUR_CAN >= 1){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 9/4k4/4b4/9/1P1R5/2B3B1P/9/3K5/4rp3/9 w - - 0 1
	if(my_shi_num == 0 && StoY(ypawn) MY_SMALL_EQL MY_RANK8 && abs(StoX(ypawn) - StoX(mk)) <= 2){
		MY_EV_SUB(32);
		Bitboard mp = m_and(bb_my_pawn,MyLowBB[MY_RANK3]);
		mp = m_or(m_and(mp,LeftBB[0x2]), m_and(mp,RightBB[0x6]));
		MY_EV_SUB(64 * (sint16)count_1s(mp));
	}


	// fen 9/3ka4/b2a3P1/3P5/p1b6/3R5/6r2/9/4K4/9 b - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 && abs(StoX(ypawn) - 0x4) == 4){
		MY_EV_ADD(32);
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK4]) && !have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){
			MY_EV_ADD(64);
		}
	}

	//红方2兵,黑方1兵
	// fen 3R5/5k3/5a3/p1r6/8p/9/P8/4B4/9/3AKAB2 b
	// fen 2baka3/9/4b4/8p/9/P8/6R1P/3A5/3K5/5r3 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			if(StoY(mche) MY_LARGE_EQL MY_RANK5){
				if(StoY(mche) == StoY(mpawn1) || StoY(mche) == StoY(mpawn2)){
					EV_YOUR_SAFE = TRUE;
				}
			}
		}
	}

	// fen 4ka3/4a4/4b2P1/3R5/P8/9/9/3Ap4/3K5/5r3 w - - 0 1
	if(my_shi_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK7){
		if(StoX(ypawn) >= 0x4 && StoX(mk) == 0x3 && StoX(mche) == 0x3 
			&& PB90(MY_SQ42) == my_shi){
				EV_MY_SAFE = TRUE;
		}
		if(StoX(ypawn) <= 0x4 && StoX(mk) == 0x5 && StoX(mche) == 0x5 
			&& PB90(MY_SQ44) == my_shi){
				EV_MY_SAFE = TRUE;
		}
	} 

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ15) != your_shi || PB90(MY_SQ17) != your_shi){
			// fen 5kb2/2P1a1P1R/3rba3/9/9/9/9/4B4/3pA4/3AK1B2 b - - 0 1
		}
		else{
		    EV_YOUR_SAFE = TRUE;
		}
	}		

	// fen 3aka3/9/2P6/4r3p/9/8P/8R/4B4/4A4/2B1KA3 b - - 14 14
	//如果红方只有过一个兵,则也是和棋
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		// fen 2P1ka3/4aP3/5r3/9/3R5/9/9/B4A3/9/2BK1p3 b - - 0 1 not he
		if(mcan <= 1 && have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 4k1b2/4a4/4b4/9/8r/1p4P2/5R2P/4B4/9/2BAKA3 b - - 0 0
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			if(PB90(XYtoS(StoX(yche),StoY(mche))) == my_pawn){
				if(StoY(mche) MY_LARGE_EQL MY_RANK4){
					if(StoX(yche) == 0x0 || StoX(yche) == 0x8){
						EV_YOUR_SAFE = TRUE;
					}
				}
			}
		}
	}

	if(my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}
	if(ycan == 0){
		EV_MY_SAFE = TRUE;
	}

	if(EV_MY_CAN == 0){
		if(your_shi_num >= 1 && your_xiang_num == 2){
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 2bak4/4a4/9/9/2r3b2/P2RP1B2/9/3K5/5p3/3A2B2 b - - 0 1
	if(my_shi_num >= 1 && StoY(mk) MY_SMALL_EQL StoY(ypawn) 
		&& StoY(ypawn) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	// fen 6b2/3ka4/3ab4/9/5P3/2r2p3/4R3P/9/3KA4/9 w - - 0 1
	if(my_shi_num >= 1 && StoX(mche) == 0x4 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK5){
			EV_MY_SAFE = TRUE;
		}
	}


	// fen 4k4/4a4/4b4/9/4r3p/2P3B2/7RP/4B4/4A4/4KA3 w - - 120 120
    //红方二个兵都不能过河.
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
			if(mcan == 0){
				if(StoY(yche) == StoY(ypawn) && StoY(yche) MY_SMALL_EQL MY_RANK4){
					EV_YOUR_SAFE = TRUE;
				}
			}
		}
	}


	// fen 4k4/4a4/9/4p3p/2b6/P4R3/8r/4B4/4A4/3AK1B2 w - - 0 0
	if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK9){
			EV_MY_SAFE = TRUE;
		}
		if(abs(StoX(ypawn) - 0x4) >= 3){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2bak4/4a4/4b4/8p/p8/4P1B1r/4R4/8B/5K3/5A3 w - - 0 0
	if (your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
		if (StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && StoY(mpawn2) MY_LARGE_EQL MY_RANK5) {
			if (abs(StoX(mpawn1) - 0x4) >= 4 && abs(StoX(mpawn2) - 0x4) >= 4) {
				MY_EV_SUB(196);
			}
		}
	}

	// fen 5a3/3k5/b2a5/9/r8/4P1P2/8P/2p1B4/9/3RKAB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
		Bitboard mp = m_and(bb_my_pawn, MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(mp) * 32);
	}

	// fen 2b6/3k5/5R3/p7p/9/6B1P/9/9/4K4/3r1AB2 b - - 0 1
	if (EV_YOUR_CAN == 0 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8) {
		MY_EV_ADD(80);
		if (your_shi_num <= 1) {
			MY_EV_ADD(EV_MY_CAN * 64);
		}
	}
	// fen 2b6/PP3k3/5a3/9/6b2/9/5R3/9/2r6/3K1p3 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
		if (my_shi_num == 0 && my_xiang_num == 0 && StoY(ypawn) == MY_RANK9) {  // my_safe
			if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])) {
				if (StoX(ypawn) > 0x4 && StoX(yche) == 0x2) {
					if (!have_bit(bb_my_pawn, RightBB[0x1])) {
						MY_EV_SUB(96);
					}
				}
				if (StoX(ypawn) < 0x4 && StoX(yche) == 0x6) {
					if (!have_bit(bb_my_pawn, LeftBB[0x7])) {
						MY_EV_SUB(96);
					}
				}
			}
		}
	}

	if(EV_MY_SAFE){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3a1kb2/4a4/8b/1r1P2P2/9/9/9/2R2A3/3K1p3/9 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2bak4/4a4/4b4/9/P3p3P/2R6/r8/4B4/4A4/2B1KA3 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(64);
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3ak4/4a4/9/4R4/1r2P4/2P6/9/B2AB4/4Ap3/4K4 b - - 0 1
	if (EV_MY_SAFE && your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if (EV_YOUR_CAN >= 1 || your_xiang_num >= 1){
			if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
				if (StoY(yche) == MY_RANK4 && PB90(MY_SQ28) == my_pawn){
					if (StoX(mche) == 0x4 && StoY(mche) MY_SMALL_EQL MY_RANK3){
						RETRUN_MUL(4);
					}
				}
				// fen 3ak4/4a4/4R4/4P4/4r4/2P6/9/B2AB4/4Ap3/4K4 b
				if (StoY(yche) == MY_RANK4 && StoX(mche) == StoX(yche)
					&& StoY(mche) MY_SMALL StoY(yche)){
					Bitboard bb = m_and(BetweenBB[mche][yche], POSITION.occupied_squares());
					if (m_have_bit(bb)){
						Square p = pop_1st_bit_sq(bb);
						if (PB90(p) == my_pawn){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}

	

	// fen 4ka3/r1P1aP3/9/2R6/6b2/9/5p3/B2A4B/4A4/4K4 b - - 0
	if(EV_MY_SAFE && StoY(ypawn) == MY_RANK6){
		if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				Square x = XYtoS(StoX(mche),StoY(yche));
				if(PB90(x) == my_pawn){
					if(abs(StoX(x) - 0x4) >= 2 && !IsOnSameSide(mpawn1,mpawn2)){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k4/4a4/4b4/9/4r4/P1P1p1R2/9/4B3B/4A4/3AK4 b - - 0 
	if (EV_MY_SAFE && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])) {
		if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0) {
			if (EV_MY_CAN <= 1 && StoY(yche) == MY_RANK4) {
				if (PB90(MY_SQ31) == your_pawn || PB90(MY_SQ30) == your_pawn) {
					if (PB90(MY_SQ2F) == my_pawn && have_bit(bb_my_pawn, LeftBB[0x1])) {
						RETRUN_MUL(4);
					}
				}
				if (PB90(MY_SQ31) == your_pawn || PB90(MY_SQ32) == your_pawn) {
					if (PB90(MY_SQ33) == my_pawn && have_bit(bb_my_pawn, RightBB[0x7])) {
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3ak4/2r3P2/4b4/6R2/p8/2B6/P8/8B/9/3AKA3 w - - 0 1
    if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1 && your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
			if(count_1s(ghp) == 1){
				Square p = pop_1st_bit_sq(ghp);
				if(abs(StoX(p) - 0x4) >= 2){
					if(StoY(yche) == StoY(p) && StoX(mche) == StoX(p)){
						RETRUN_MUL(4);
					}
				}
			}
		}
		// fen 4k1PR1/4a4/4b4/9/p8/2B6/P2r5/8B/9/3AKA3 w - - 0 1
		if(EV_MY_CAN == 0 && your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/4a4/b3b4/3P1r3/9/2PR2B2/9/4B4/2p6/3AKA3 w - - 0 1
	if (EV_MY_SAFE){
		if (EV_MY_CAN <= 1 ){
			if (your_shi_num >= 1 && your_xiang_num == 2){
				if (StoY(yche) == MY_RANK3){
					if (PB90(MY_SQ1E) == my_pawn && StoX(mche) == 0x3){
						RETRUN_MUL(4);
					}
					if (PB90(MY_SQ20) == my_pawn && StoX(mche) == 0x5){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 6b2/3ka4/3ab4/9/5P3/2r2p3/4R3P/9/3KA4/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(((my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8)) || EV_YOUR_CAN == 0){ // fen 4kab2/4a4/4b4/4p4/9/4r4/P2R4P/3K5/9/5A3 b - - 0 1
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				RETRUN_MUL(4);
			}
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/5P3/4k4/5R3/2r3b2/9/4pp3/9/4A4/3AK1B2 w - - 65 65
	if(my_shi_num == 0 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mk) == MY_RANK7 && StoY(ypawn) == MY_RANK8){
		   if(StoY(mpawn1) == StoY(mpawn2) && abs(StoX(mpawn1) - StoX(mpawn2)) == 1){
			   if(StoY(mpawn1) MY_LARGE_EQL MY_RANK2){
				   RETRUN_MUL(4);
			   }
		   }
		}
	}

   // fen 2ba1k3/4a4/9/4P4/p1b2r3/4R3P/9/4B4/4K4/9 w - - 152 152
	if(my_xiang_num >= 1 || my_shi_num >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 && StoY(mche) == MY_RANK5 && StoX(mche) == 0x4){
			MY_EV_ADD(64);
		}
	}

   // fen 2b1k4/4aP1r1/4b4/5R3/6p2/9/3p5/4B3B/3KA4/5A3 w - - 134 134
	if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) == StoY(mche) && StoX(ypawn) == StoX(yche)){
			MY_EV_ADD(64);
		}
	}

   // fen 4ka3/4a1P2/4b4/r8/9/P2R5/4p4/4B4/4A4/2BAK4 b - - 37 37
   //求得二车的交叉点
   int xc = XYtoS(StoX(yche),StoY(mche));
   if(PB90(xc) == my_pawn){
	   if(xc != MY_SQ2F || xc != MY_SQ33){
		   if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			   if(StoY(xc) MY_LARGE_EQL MY_RANK5){
				   EV_YOUR_SAFE = TRUE;
			   }
		   }
	   }
   }

   // fen 2b1k4/4a4/9/p4P2p/9/1p7/r8/4B4/3R5/3AKAB2 w - - 0 0
   if(my_shi_num >= 1 && my_xiang_num >= 1 && MY_SQ55 == mk){
	   if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
		   MY_EV_ADD(mcan * 32);
	   }
   }


   // fen 5k3/4a4/4ba3/9/4PPb2/6R2/4r4/5A1p1/5K3/6B2 w - - 120 120
   if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	   Bitboard lp = My_get_connect_Pawn(POSITION);
	   if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
		   EV_MY_SAFE = TRUE;
	   }
   }

   // fen 4k4/4a4/4b3b/9/1r2PR3/2B3P2/4p4/4B4/4A4/3AK4 w - - 0 0
   if (EV_MY_SAFE){
	   if (mcan <= 1 && malr <= 1){
		   if ((your_shi_num + your_xiang_num) >= 3 && PB90(MY_SQ04) == your_king){
			   if (StoY(ypawn) MY_LARGE_EQL MY_RANK5){
				   if (StoY(mche) == StoY(yche)){
					   if (StoY(mche) == MY_RANK4){
						   Square mid;
						   if (getBetweenSq(POSITION, mche, yche, mid)){
							   if (abs(StoX(mid) - 0x4) <= 2){
								   RETRUN_MUL(4);
							   }
						   }
					   }
				   }
			   }
		   }
	   }
   }
   // fen 2bak4/4a4/9/9/2r3b2/P2RP1B2/9/3K5/5p3/3A2B2 b - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		   if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			   RETRUN_MUL(4);
		   }
	   }
   }

   // fen 2P1ka3/4aP3/5r3/9/3R5/9/9/B4A3/9/2BK1p3 b - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && MY_SQ04 == yk){
		   if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			   RETRUN_MUL(4);
		   }
	   }
   }

   // fen 3a1k3/4a4/9/3P5/9/7r1/3R5/4B4/1pp1A4/4KA3 w - - 120 120
   //二兵在底线中间
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		   Bitboard mb = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		   if(count_1s(mb) == 2){
			   Bitboard lr;
			   lr = m_and(mb,LeftBB[0x3]);
			   if(count_1s(lr) == 2 && StoX(yche) == 0x3){
				   RETRUN_MUL(4);
			   }
			   lr = m_and(mb,RightBB[0x5]);
			   if(count_1s(lr) == 2 && StoX(yche) == 0x5){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }

  
   // fen 2b6/4k4/4b4/9/P1r5p/2B6/R7P/4BA3/4A4/4K4 w - - 120 120
   if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	   if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
		   int x = XYtoS(StoX(mche),StoY(yche));
		   if(PB90(x) == my_pawn && StoY(x)  MY_LARGE_EQL MY_RANK3 && StoY(x) MY_SMALL_EQL MY_RANK4){
			   if(StoX(x) == 0x0 && PB90(MY_SQ02) == your_xiang){
				   RETRUN_MUL(4);
			   }
			   if(StoX(x) == 0x8 && PB90(MY_SQ06) == your_xiang){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }
   // fen 6b2/4a4/4ka3/p8/2b5P/P4R3/9/4r4/5K3/9 w - - 0 1 
   // 红方要加分
   if(EV_YOUR_CAN == 0){
	   MY_EV_ADD(EV_MY_CAN * 96);
	   if(EV_MY_CAN <= 1){
		   if(your_shi_num == 2 && your_xiang_num == 2){
			   RETRUN_MUL(4);
		   }
	   }
	   if(EV_MY_CAN == 2){
		   if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			   RETRUN_MUL(4);
		   }
	   }
   }

   // fen 4k1b2/9/4b4/9/5r3/6P1P/p8/4B4/1R7/2BAKA3 b - - 0 1
   if(EV_MY_SAFE){
	   if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
	       if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			   if(abs(StoX(mpawn1) - 0x4) == 4){
				   if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
				       RETRUN_MUL(4);
				   }
				   if(StoY(mpawn1) MY_LARGE_EQL MY_RANK3){
					   if(StoY(yche) == StoY(mpawn1) && StoX(mche) == StoX(mpawn1)){
						   RETRUN_MUL(4);
					   }
				   }
			   }
			   if(abs(StoX(mpawn2) - 0x4) == 4){
				   if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
					   RETRUN_MUL(4);
				   }
				   if(StoY(mpawn2) MY_LARGE_EQL MY_RANK3){
					   if(StoY(yche) == StoY(mpawn2) && StoX(mche) == StoX(mpawn2)){
						   RETRUN_MUL(4);
					   }
				   }
			   }
		   }
	   }
   }

   // fen 2bakab2/9/9/9/P8/3p4P/4r4/B8/1R2A4/4K4 b - - 0 1
   if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
	   if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
		   MY_EV_ADD(64);
		   MY_EV_ADD(EV_MY_CAN * 32);
	   }
   }

   // fen 9/3P1k3/b3ba2R/9/3r4p/9/8P/8B/4A4/3AK4 b - - 0 1
   if(EV_MY_SAFE && EV_MY_CAN <= 1 && your_shi_num >= 1 && your_xiang_num == 2){
	   Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
	   if(count_1s(ghp) == 1){
		   Square p = pop_1st_bit_sq(ghp);
		   if(StoY(yche) == MY_RANK4){
			   if((PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn) 
				   || (PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn)){
					   if(StoX(p) <= 0x3 && PB90(MY_SQ17) == your_shi && StoX(mche) != 0x5){
						   RETRUN_MUL(4);
					   }
					   if(StoX(p) >= 0x5 && PB90(MY_SQ15) == your_shi && StoX(mche) != 0x3){
						   RETRUN_MUL(4);
					   }
			   }

		   }
	   }
   }

   // fen 4k1b2/4a4/4b4/4R3p/4P4/4r1B1P/9/9/4A4/2B1KA3 w - - 0 1
   if(EV_MY_SAFE){
	   if(EV_MY_CAN <= 1 && your_xiang_num == 2 && your_shi >= 1 && StoY(yk) == MY_RANK0){
		   if(StoX(mche) == StoX(yche) && StoY(mche) MY_SMALL_EQL StoY(yche)){
			   if(have_bit(bb_my_pawn,m_and(ei.attacked_by(your_che),ei.attacked_by(my_che)))){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }

   // fen 1R1aka3/9/4b4/9/1Pp6/8P/8r/5A3/9/2BK1AB2 b - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		   Bitboard mlp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		   mlp = m_and(mlp,m_or(LeftBB[0x1],RightBB[0x7]));
		   if(have_bit(mlp,ei.attacked_by(your_che))){
			   RETRUN_MUL(4);
		   }
	   }
   }


   // fen 5kb2/2P1a1P1R/3rba3/9/9/9/9/4B4/3pA4/3AK1B2 b - - 0 1
   if(EV_MY_SAFE){
	   if(your_xiang_num == 2 && your_shi_num == 2 && StoY(yk) == MY_RANK0){
		   RETRUN_MUL(8);
	   }
   }

   // fen 3ak1b2/4a4/b8/9/r3P1p1p/4R4/9/4B4/9/3AK4 w - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num >= 1 && your_xiang_num >= 1){
		   if(MY_SQ04 == yk && MY_SQ28 == yche){
			   if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

   //fen 4ka3/4aP3/9/3P4R/9/4r4/4p4/5A3/9/3AK4 w - - 0 1
   if (EV_MY_SAFE){
	   if (your_shi_num == 2 && MY_SQ04 == yk){
		   if (!have_bit(bb_your_shi, RankBB_A[MY_RANK2])){
			   if (StoY(ypawn) == MY_RANK5){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }


   // fen 4k4/9/4b4/6P2/p1b1p4/5R3/9/4B4/9/2BAKA1r1 w - - 0 0
   if(EV_YOUR_SAFE){
	   if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		   RETRUN_MUL(8);
	   }
   }


   // fen 3ak1b2/9/5R2b/P1r5p/9/9/8P/4B4/9/3AKAB2 w - - 0 1
   if (EV_MY_SAFE) {
	   if (EV_MY_CAN <= 1) {
		   if ((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0) {
			   MY_EV_SUB(64);
			   if (count_1s(bb_my_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8])) == 2) {
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }


   // fen 5k3/3P5/3a1r3/6R2/9/9/9/2pAB4/4A2p1/3K2B2 b - - 0 1
   if(EV_YOUR_SAFE){
	   if(StoY(ypawn) MY_LARGE_EQL MY_RANK8 && my_shi_num >= 1){
	       if(StoX(ypawn) > 0x4 && StoX(mche) == 0x3 && PB90(MY_SQ44) == my_shi){
			   EV_MY_SAFE = true;
		   }
		   if(StoX(ypawn) < 0x4 && StoX(mche) == 0x5 && PB90(MY_SQ42) == my_shi){
			   EV_MY_SAFE = true;
		   }
	   }
   }
   

   // fen 4ka3/4a4/4b2P1/3R5/P8/9/9/3Ap4/3K5/5r3 w - - 0 1
   if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
	   if(have_bit(bb_my_pawn,LeftBB[0x3]) || have_bit(bb_my_pawn,RightBB[0x5])){
		   RETRUN_MUL(8);
	   }
   }

   // fen 2P5R/4ak3/5a3/7rp/9/8P/9/3A4B/9/4KA3 b - - 0 1
   if (EV_MY_CAN == 0){
	   if (your_shi_num == 2 && StoY(yche) == MY_RANK3){
		   if (StoY(ypawn) == MY_RANK3 && PB90(ypawn MY_ADD 18) == my_pawn){
			   Bitboard mdp = m_and(bb_my_pawn, RankBB_A[MY_RANK0]);
			   if (m_have_bit(mdp)){
				   if (StoX(yk) == 0x5 && have_bit(LeftBB[0x4], mdp)){
					   RETRUN_MUL(8);
				   }
				   if (StoX(yk) == 0x3 && have_bit(RightBB[0x4], mdp)){
					   RETRUN_MUL(8);
				   }
			   }
		   }
	   }
   }

   // fen 4k1b2/4a4/4b4/5P3/R7p/9/P7r/B3B4/4A4/4KA3 w - - 0 1
   if (EV_MY_SAFE) {
	   if (your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk && EV_YOUR_CAN >= 1) {
		   MY_EV_SUB(64);

		   // 有一个边兵被牵制了
		   if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])) {
			   if (abs(StoX(mpawn1) - 0x4) == 4) {
				   if (bit_is_set(ei.attackedBy[your_che], mpawn1)
					   && bit_is_set(ei.attackedBy[my_che], mpawn1))
				   {
					   RETRUN_MUL(8);
				   }
			   }
			   if (abs(StoX(mpawn2) - 0x4) == 4) {
				   if (bit_is_set(ei.attackedBy[your_che], mpawn2)
					   && bit_is_set(ei.attackedBy[my_che], mpawn2))
				   {
					   RETRUN_MUL(8);
				   }
			   }
		   }
	   }
   }


   // fen 4ka3/4aR3/b8/3PP4/9/9/9/4B3B/3r1p3/3AK4 w - - 0 1
   if (EV_MY_SAFE) {
	   if (your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk) {
		   if (my_shi_num <= 1 && abs(StoY(mk) - StoY(ypawn)) <= 1) {
			   Bitboard lop = m_and(bb_my_pawn, MyLowBB[MY_RANK2]);
			   if (count_1s(lop) == 2) {
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

}

