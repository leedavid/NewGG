#ifndef END_my_m_MT_R_1ma2pawn_B_1pao
#define END_my_m_MT_R_1ma2pawn_B_1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马2兵对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int Pawn_Add = 64;

void my_m_MT_R_1ma2pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1马兵对1炮_by_Pawn_By_Shi[your_shi_num]);

	//Square yk   = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	int mcan = EV_MY_CAN;

	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(ypao) MY_SMALL_EQL MY_RANK4){
		MY_EV_SUB(64);
	}

	// fen 2b1k4/3P1P3/3aba3/3c1N3/9/6B2/9/4BA3/3K5/5A3 w - - 0 1
   if((your_shi_num + your_xiang_num) == 4){
	   if(StoY(yk) == MY_RANK0){
		   if(PB90(MY_SQ0D) == my_pawn || (PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0E) == my_pawn)){
			   if (!(PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi)){
				   return;
			   }
		   }		   
	   }
	   RETRUN_MUL(2);
   }
   // fen 4k4/9/b2a5/9/9/2B6/3nC4/2p1BA3/3K2p2/9 w - - 126 126

   Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
   Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

   Square mma    = S90_from_piecelist(POSITION,my_ma,0);

   // fen 4k4/1P3c3/3aba3/2N6/1P7/9/9/B4A3/9/3A1K3 w - - 0 1
   if (your_shi_num == 2 && StoY(yk) == MY_RANK0 && your_xiang_num >= 1){
	   MY_EV_SUB(64);
	   if (StoY(ypao) MY_SMALL_EQL MY_RANK2){
		   MY_EV_SUB(64);
	   }
   }

   // fen 3P5/4P4/3k5/2N6/2b6/4c4/9/9/4K4/9 w - - 44 44
   if(StoY(mpawn1) MY_SMALL StoY(yk) && StoY(mpawn2) MY_SMALL StoY(yk)){
	   if(your_xiang_num >= 1 && StoX(ypao) == 0x4 && StoY(ypao) MY_LARGE MY_RANK2){
		   RETRUN_MUL(2);
	   }
	   // fen 9/2P2P3/4k4/7N1/4c4/9/9/3K5/9/9 b - - 134 134
	   if(StoX(ypao) == 0x4 && StoY(ypao) MY_LARGE MY_RANK2){
		   RETRUN_MUL(2);
	   }
   }

	//如果有窝心马在,就可能是和棋
	// fen 3aka3/4n4/b3b4/9/9/4C1B2/9/5p3/2p1K4/3p5 w - - 14 14
   // fen 9/4k1P2/b8/9/4c4/2P6/9/4B3B/4N4/3AKA3 w
   if(PB90(MY_SQ4C) == my_ma && PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi
	   && PB90(MY_SQ43) == my_xiang){
		   if(isStringByPao(POSITION,ypao,Square(MY_SQ4C),my_king_pos)){
			   if(mcan <= 1){
				   RETRUN_MUL(2);
			   }
		   }
   }

   // fen 4k4/5P3/5a3/9/4PNbc1/2B6/9/5A3/3K5/3A2B2 b - - 0 1
   if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	   if(PB90(MY_SQ28) == my_pawn){
		   if(PB90(MY_SQ29) == my_ma 
			   && PB90(MY_SQ17) == your_shi && PB90(MY_SQ2A) == your_xiang){
				   if(StoY(ypao) == MY_RANK4 && StoX(ypao) > 0x4){
					   if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
						   RETRUN_MUL(2);
					   }
					   if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
						   RETRUN_MUL(2);
					   }
				   }
		   }
		   if(PB90(MY_SQ27) == my_ma 
			   && PB90(MY_SQ15) == your_shi && PB90(MY_SQ26) == your_xiang){
				   if(StoY(ypao) == MY_RANK4 && StoX(ypao) < 0x4){
					   if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
						   RETRUN_MUL(2);
					   }
					   if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
						   RETRUN_MUL(2);
					   }
				   }
		   }
	   }
   }
    
   // fen 2P1k1P2/3ca4/3a5/7N1/9/9/9/9/4A4/5KB2 b - - 0 0 
   if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK0){
	   RETRUN_MUL(2);
   }

   // fen 5P3/2P1cN3/3kb4/9/9/9/9/5A3/9/5K3 w - - 0 1
   if(your_xiang_num >= 1){
	   if(   (MY_SQ15 == yk && PB90(MY_SQ0D) == your_pao && PB90(MY_SQ0E) == my_ma)
		   || (MY_SQ17 == yk && PB90(MY_SQ0D) == your_pao && PB90(MY_SQ0C) == my_ma)){
			   if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				   RETRUN_MUL(2);
			   }
			   if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
				   RETRUN_MUL(2);
			   }
	   }
   }

   // fen 3P5/3P5/4k4/9/5cN2/2B6/9/4BA3/3K5/3A5 b - - 0 1
   if(StoY(yk) == MY_RANK2){
	   if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
		   RETRUN_MUL(4);
	   }
	   if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
		   RETRUN_MUL(4);
	   }
   }

   // fen 3a1k3/2c1a4/6PP1/5N3/2b6/9/9/5A3/4K4/5A3 w - - 0 1
   if (your_shi_num == 2 && your_xiang_num >= 1){
	   if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
		   if (StoY(ypao) MY_SMALL_EQL MY_RANK2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			   if (!have_bit(bb_your_shi, RightBB[0x4])){
				   if (!have_bit(bb_my_pawn, LeftBB[0x6]) && StoX(ypao) < 0x4){
					   RETRUN_MUL(4);
				   }
			   }
			   if (!have_bit(bb_your_shi, LeftBB[0x4])){
				   if (!have_bit(bb_my_pawn, RightBB[0x2]) && StoX(ypao) > 0x4){
					   RETRUN_MUL(4);
				   }
			   }
		   }
	   }
   }

   // fen 4k4/1P3c3/3aba3/2N6/1P7/9/9/B4A3/9/3A1K3 w - - 0 1

   // fen 9/3ca1P2/2Pak4/9/2b6/6N2/9/5A3/4A4/4K4 w - - 0 1
   if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(ypao) MY_SMALL_EQL MY_RANK4){
	   if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2]) && StoY(yk) == MY_RANK2){
		   if (PB90(MY_SQ17) != your_shi && have_bit(bb_my_pawn, LeftBB[0x4])){ 
			   // 左边有一个废兵
			   Bitboard op = m_and(bb_my_pawn, RightBB[0x5]);
			   if (have_bit(op, MyUpBB[MY_RANK2])){
				   RETRUN_MUL(4);
			   }
		   }
		   if (PB90(MY_SQ15) != your_shi && have_bit(bb_my_pawn, RightBB[0x4])){
			   // 左边有一个废兵
			   Bitboard op = m_and(bb_my_pawn, LeftBB[0x3]);
			   if (have_bit(op, MyUpBB[MY_RANK2])){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }

   // fen 9/3ka1PP1/4ba3/2cN5/9/9/9/9/9/4K4 b - - 0 1
   if(your_shi_num == 2 && your_xiang_num >= 1){
	   if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		   if(!have_bit(bb_your_shi,FileBB_A[StoX(yk)])){
			   MY_EV_SUB(32);
			   if(StoX(yk) == 0x3 && !have_bit(bb_my_pawn,LeftBB[0x5])){
				   RETRUN_MUL(4);
			   }
			   if(StoX(yk) == 0x5 && !have_bit(bb_my_pawn,RightBB[0x3])){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }

   // fen 3a5/4k1P2/2ca2P2/9/2b4N1/9/9/9/3KA4/9 w - - 0 1
   if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	   if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) 
		   && have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
		   if(!have_bit(LeftBB[0x6],bb_my_pawn) || !have_bit(RightBB[0x2],bb_my_pawn)){
			   RETRUN_MUL(4);
		   }
	   }
   }

	// fen 4k4/3P3P1/3a1a3/3Nc4/2b6/9/9/9/4AK3/9 b - - 122 122
   if((your_shi_num + your_xiang_num) >= 3){
	   if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){	
		   if(IsOnSameSide(mpawn1,mpawn2)){
			   if(PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }
   // fen 1P2k4/2c1a1P2/3aN4/9/9/9/9/9/5K3/5AB2 w - - 156 156
   if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
	   if(your_shi_num == 2){
	      if(StoY(mpawn2) == MY_RANK1){			  
			  Bitboard peat = POSITION.Pao_Eat_bb(ypao);
			  if(bit_is_set(peat,mpawn2)){
				  RETRUN_MUL(4);
			  }
		  }
		  if(StoY(mpawn1) == MY_RANK1){			  
			  Bitboard peat = POSITION.Pao_Eat_bb(ypao);
			  if(bit_is_set(peat,mpawn1)){
				  RETRUN_MUL(4);
			  }
		  }
	   }
   }

   // fen 9/2PP1k3/3ac4/7N1/2b6/9/9/9/9/3K5 b - - 0 1
   if (your_shi_num >= 1 && your_xiang_num >= 1){
	   if (StoY(ypao) MY_SMALL_EQL MY_RANK2 && StoY(yk) MY_LARGE_EQL MY_RANK1){
		   Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
		   if (count_1s(mp) == 2){
			   if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
				   if (!have_bit(mp, RightBB[0x3])){
					   RETRUN_MUL(4);
				   }
			   }
			   if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
				   if (!have_bit(mp, LeftBB[0x5])){
					   RETRUN_MUL(4);
				   }
			   }
		   }
	   }
   }

   // fen 4P4/2P1ak3/4c4/9/4N1b2/9/9/9/3K5/9 w - - 0 1
   if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_LARGE_EQL MY_RANK1){
	   if (StoY(mpawn1) == MY_RANK0 || StoY(mpawn1) == MY_RANK1){
		   Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
		   if (count_1s(mp) == 2){
			   if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
				   RETRUN_MUL(4);
			   }
			   if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
				   RETRUN_MUL(4);
			   }
		   }
	   }
   }

 

	// fen 4k4/3Pa2P1/4b4/9/4N1b2/9/6c2/9/5K3/9 b - - 120 120
	//一个红兵在外面，给炮控制了
    if(my_xiang_num == 0){
		if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
					if(abs(StoX(mpawn1) - 0x4) >= 3 || abs(StoX(mpawn2) - 0x4) >= 3){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}	

	// fen 9/3P1P3/3ak4/5cN2/9/9/9/B2A4B/5K3/3A5 b - - 40 40
	if(StoY(mpawn1) MY_SMALL StoY(yk) && StoY(mpawn2) MY_SMALL StoY(yk)){
		if(your_shi_num >= 1){
			RETRUN_MUL(4);
		}
	}

	// fen 9/1P1Nc1P2/4bk2b/9/9/9/9/3K5/4A4/2BA5 b - - 0 1
	if(your_xiang_num == 2 && count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
		   RETRUN_MUL(4);
		}
	}

	//fen 9/4ak3/2Pa2P2/4cN3/2b6/2B6/9/3A1A2B/9/4K4 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(ypao) MY_SMALL_EQL MY_RANK4){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
			if (StoX(yk) == 0x5 && have_bit(LeftBB[0x4], bb_my_pawn)){
				if (!have_bit(bb_your_shi, RightBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			if (StoX(yk) == 0x3 && have_bit(RightBB[0x4], bb_my_pawn)){
				if (!have_bit(bb_your_shi, LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/1P3c3/3aba3/2N6/1P7/9/9/B4A3/9/3A1K3 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0 && your_xiang_num >= 1){
		if (StoY(ypao) == MY_RANK1){
			Bitboard mp = m_and(bb_my_pawn, RankBB_A[MY_RANK1]);
			if (StoX(ypao) >= 0x5 && have_bit(mp, LeftBB[0x3])){
				RETRUN_MUL(4);
			}
			if (StoX(ypao) <= 0x3 && have_bit(mp, RightBB[0x5])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/3PaN1P1/3abc3/9/9/9/9/9/4A4/4K4 w - - 0 0
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){

		if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
			if(PB90(MY_SQ05) == your_king && PB90(MY_SQ0E) == my_ma && PB90(MY_SQ0F) == my_pawn
				&& PB90(MY_SQ17) == your_pao){
					RETRUN_MUL(4);
			}	
			if(PB90(MY_SQ03) == your_king && PB90(MY_SQ0E) == my_ma && PB90(MY_SQ0F) == my_pawn
				&& PB90(MY_SQ17) == your_pao){
					RETRUN_MUL(4);
			}
		}
		// fen 3a5/3Pak3/4b1P2/3Nc4/9/9/9/8B/4K4/9 b - - 0 1
		if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) && StoY(ypao) MY_SMALL_EQL MY_RANK4){
				if(!IsOnSameSide(yk,mma)){
					if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
						RETRUN_MUL(6);
					}
					if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
						RETRUN_MUL(6);
					}
				}
			}
		}

		RETRUN_MUL(8);
	}



 	// fen 5P3/2P1cN3/3kb4/9/9/9/9/5A3/9/5K3 w - - 0 1
	if(your_xiang_num >= 1 && StoY(ypao) MY_SMALL_EQL MY_RANK3){
		if(StoY(yk) == MY_RANK2){
			if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
			if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1k4/5PP2/3ab4/4cN3/9/9/9/B4A3/9/3K1A3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 
		&& !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
        if(IsOnSameSide(mpawn1,mpawn2) && StoY(yk) == MY_RANK0){
			if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b2P3/1N1k1P3/3a5/3c5/6b2/9/9/4B4/4A4/3K1A3 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 
		&& !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
					RETRUN_MUL(8);
			}
	}

	// fen 9/1P1kaP3/8b/9/2b1N4/6B2/2c6/3A5/5K3/2BA5 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(!have_bit(bb_my_pawn,MyLowBB[StoY(yk)])){
			if(have_bit(bb_my_pawn,LeftBB[0x2]) ||
				have_bit(bb_my_pawn,RightBB[0x6])){
					RETRUN_MUL(8);
			}
		}
	}

	// fen 5k3/1P2a1P2/9/9/2b1N1b2/6B2/9/3A4B/4A4/2c1K4 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(have_bit(bb_my_pawn,LeftBB[0x2])){
					RETRUN_MUL(8);
			}
			if(have_bit(bb_my_pawn,RightBB[0x6])){
					RETRUN_MUL(8);
			}
		}
	}
	// fen 2b1k4/3P1P3/3aba3/3c1N3/9/6B2/9/4BA3/3K5/5A3 w - - 0 1
	//if (your_shi_num == 2 && your_xiang_num == 2){
	//	if (StoY(yk) == MY_RANK0){
	//		if (!have_bit(MyLowBB[MY_RANK1], bb_my_pawn)){
	//			if (PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
	//				RETRUN_MUL(8);
	//			}
	//		}
	//	}
	//}

	// fen 7P1/4a4/b4kc2/2N6/9/2P3B2/9/9/9/2B1K4 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		if (have_bit(bb_my_pawn, MyUpBB[MY_RANK1])){
			if (EV_MY_CAN <= 1){
				RETRUN_MUL(8);
			}
		}
	}
}

