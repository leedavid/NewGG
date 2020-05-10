#ifndef END_my_m_MT_R_2PAWN_B_1CHE
#define END_my_m_MT_R_2PAWN_B_1CHE
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int CheAdd   = 50;
//const int PawnAdd  = 10;

//我方二个兵，对方一个车
void my_m_MT_R_2PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){
	
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// 兵在保持在卒线 //在这儿看一下有多少兵在二线，有几个加分
	Bitboard mpbb = m_and(bb_my_pawn, RankBB_A[MY_RANK3]);
	MY_EV_ADD((sint16)count_1s(mpbb) * 64);

	if(my_shi_num == 2 && my_xiang_num == 2){
		if(mk == MY_SQ55){
			RETRUN_MUL(2);
		}
	}

	MY_EV_SUB(64);

	// fen 3ak3P/9/3ab3b/9/9/2P6/9/4BA3/3KA4/1r4B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2){
		if   ( (StoX(mk) == 0x3 && !have_bit(bb_my_shi,LeftBB[0x4]))
			|| (StoX(mk) == 0x5 && !have_bit(bb_my_shi,RightBB[0x4]))){
				if(StoY(yche) == MY_RANK9 && StoY(mk) MY_LARGE_EQL MY_RANK8){
					RETRUN_MUL(2);
				}
				if(StoY(mk) == MY_RANK9){
					RETRUN_MUL(2);
				}
		}
	}

	
	if(your_shi_num == 0 && StoY(yk) == MY_RANK0 
		&& PB90(MY_SQ0D) == my_pawn && StoY(mk) != MY_RANK7){
			//例典 page184 第2局 一车例和双低卒仕, 
			//双低卒侵入九宫, 能控制主帅, 如有士护将, 可以弈和
			// fen 9/3ka4/9/9/9/8R/9/9/3pp4/5K3 w
			if(my_shi_num >= 1){
				if((PB90(MY_SQ0C) == my_pawn && StoX(mk) == 0x3)
					||(PB90(MY_SQ0E) == my_pawn && StoX(mk) == 0x5)){
						RETRUN_MUL(2);
				}
			}
			//////////////////////////////////////////////////
			// 例典 page184 第4局 一车例和双低卒象,
			// fen 9/5k3/1R6b/9/9/9/9/9/4pp3/3K5 w
			// 如果有相与将在同一边,
			if(your_xiang_num >= 1){
				if(PB90(MY_SQ0C) == my_pawn || PB90(MY_SQ0E) == my_pawn){
					for(int i = 0; i < my_xiang_num; i++){
						int x = S90_from_piecelist(POSITION,my_xiang,i);
						if((StoX(yk) < 0x4 && StoX(x) > 0x4) || (StoX(yk) > 0x4 && StoX(x) < 0x4)){
							RETRUN_MUL(2);
						}
					}
				}
			}
	}

	///////////////////////////////////////////////////////////////////////////////////
	// 第6局 一车例和双高卒双象
	// 双高卒,双象连环互保, 又在中线挡帅护将, 无懈可击
	// fen 4k4/9/1R2b4/9/2b6/9/4pp3/9/9/4K4 w
	if(my_xiang_num == 2 && StoY(mk) != MY_RANK7){  // 不在上面
		if(PB90(MY_SQ43) == my_xiang){
			if(StoY(mpawn1) MY_LARGE StoY(yk)){
				if(PB90(mpawn1 + 1) == my_pawn || PB90(mpawn2 + 1) == my_pawn){
					// fen 4k4/9/1R2b4/9/2b6/9/4pp3/9/9/4K4 w
					if(StoX(mpawn1) == 0x4 || StoX(mpawn2) == 0x4){
						RETRUN_MUL(2);
					}
					// fen 2b1k4/9/4b4/9/9/1R7/2pp5/9/9/4K4 b
					if((abs(StoX(mpawn1) - 0x4) <= 1) || (abs(StoX(mpawn2) - 0x4) <= 1)){
						if(PB90(MY_SQ53) == my_xiang || PB90(MY_SQ57) == my_xiang){
							RETRUN_MUL(2);
						}
					}
				}
			}
		}
	}

	// 第11局, page 187 一车例和双高卒,双士
	// 双卒在中线,双士中有一个是高仕,可以成和
	// fen 3ak4/9/3a5/9/5R3/9/3pp4/9/9/4K4 w
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(PB90(MY_SQ42) == my_shi || PB90(MY_SQ44) == my_shi){
			if(StoY(mpawn1) MY_LARGE StoY(yk)){
				if(PB90(mpawn1 + 1) == my_pawn || PB90(mpawn2 + 1) == my_pawn){
					if((abs(StoX(mpawn1) - 0x4) <= 1) || (abs(StoX(mpawn2) - 0x4) <= 1)){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	//一车巧胜3ak4/4a4/9/1R7/9/9/3pp4/9/9/4K4 w
	// fen 3ak4/4a4/9/1R7/9/9/3pp4/9/9/4K4 w
	MY_EV_ADD(ADD_CheXPawn_To_1Pawn); // 有车方的加分

	// fen R8/3ka4/3a5/9/9/9/3pp4/4B4/4A4/2BAK4 w - - 125 125
	if(my_shi_num == 2 && StoY(mk) MY_LARGE MY_RANK7){
		if(StoX(mk) == 0x3 && PB90(MY_SQ42) == my_shi){
			if( (PB90(MY_SQ27) == my_pawn && PB90(MY_SQ28) == my_pawn)
				||(PB90(MY_SQ1E) == my_pawn && PB90(MY_SQ1F) == my_pawn)){
					RETRUN_MUL(2);
			}			
		}
		if(StoX(mk) == 0x5 && PB90(MY_SQ44) == my_shi){
			if( (PB90(MY_SQ29) == my_pawn && PB90(MY_SQ28) == my_pawn)
				||(PB90(MY_SQ20) == my_pawn && PB90(MY_SQ1F) == my_pawn)){
					RETRUN_MUL(2);
			}			
		}
	}

	//如果我方有二个兵，且将在连兵的一边，就有可能是和棋
	// fen 3ak4/9/3a5/9/5PP2/9/9/5A3/4AK3/6r2 w - - 62 62
	if(my_shi_num == 2  && StoY(mk) != MY_RANK7){
		if(StoY(mpawn1) == StoY(mpawn2) && abs(StoX(mpawn1) - StoX(mpawn2)) == 1){
			if(StoX(mk) == 0x3 && PB90(MY_SQ42) == my_shi){
				if(PB90(MY_SQ27) == my_pawn || PB90(MY_SQ1E) == my_pawn){
					RETRUN_MUL(2);
				}
			}
			if(StoX(mk) == 0x5 && PB90(MY_SQ44) == my_shi){
				if(PB90(MY_SQ29) == my_pawn || PB90(MY_SQ20) == my_pawn){
					RETRUN_MUL(2);
				}
			}
		}		
	}

	// fen 3k5/4a4/4ba3/9/3PP3r/6B2/9/9/9/3AK1B2 b - - 0 1
    if(my_xiang_num == 2 && my_shi_num >= 1 && MY_SQ55 == mk){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(bit_is_set(lp,Square(MY_SQ28)) || bit_is_set(lp,Square(MY_SQ1F))){
			if(PB90(MY_SQ54) == my_shi && PB90(MY_SQ57) == my_xiang){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ56) == my_shi && PB90(MY_SQ53) == my_xiang){
				RETRUN_MUL(2);
			}
		}
	}


	// fen 4R4/5k3/4b4/9/6b2/9/2p1p4/4BA3/4A4/5KB2 w - - 0 1
	// fen 5a3/4k4/5a3/3PP4/9/r8/9/9/4A4/3K1A3 b - - 0 1
	if(my_xiang_num == 2 || (my_shi_num == 2 && MY_SQ4C != mk)){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			// 6线有二兵
			if((StoY(mpawn1) == MY_RANK3 && StoY(mpawn2) == MY_RANK3)
				|| (StoY(mpawn1) == MY_RANK4 && StoY(mpawn2) == MY_RANK4)){
				// fen 2bk5/4a4/3ab4/4P1P2/9/2B6/9/4B4/3K5/4r4 b - - 0 1
				if(PB90(MY_SQ43) == my_xiang && count_1s(bb_my_xiang,MY_ATTACK) == 2){
					if(PB90(MY_SQ55) == your_che || PB90(MY_SQ4C) == your_che){
						if(abs(StoX(mpawn1) - 0x4) <= 2 && abs(StoX(mpawn2) - 0x4) <= 2){
							RETRUN_MUL(2);
						}
					}
				}
				// fen 3k5/9/4b3b/2R6/9/9/2pp5/3A4B/9/4KAB2 w - - 0 200
				if(abs(StoX(mpawn1) - 0x4) <= 2 && abs(StoX(mpawn2) - 0x4) <= 2){
					if(abs(StoX(mpawn1) - StoX(mpawn2)) <= 1){
						RETRUN_MUL(4);
					}				
				}
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak4/9/5a3/9/3PP4/2B6/r8/B4A3/9/5K3 b - - 0 1
	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
			RETRUN_MUL(8);
		}
	}
}


