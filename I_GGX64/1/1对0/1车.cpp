#ifndef Emy_m_MT_R_1CHE
#define Emy_m_MT_R_1CHE
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif  

//红方一车
void my_m_MT_R_1CHE(typePOS &POSITION, EvalInfo &ei){
    Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yk   = your_king_pos;
	Square mk   = my_king_pos;
	Bitboard T;
	// 我的将不在底线，也更好杀对方。
	if(StoY(mk) != MY_RANK9){
		MY_EV_ADD(32);
	}
	// 双方的将在同一线
	if(StoX(mk) == StoX(yk)){
		MY_EV_ADD(24);
	}
	T = m_and(POSITION.Rook_attacks_bb(mk),BitboardOCC);
	if(m_have_bit(T) == FALSE){
		MY_EV_ADD(24);  // 将上面没有棋子
	}
	else {
		Square sq;
		while(pop_1st_bit_sq(T,sq)){			
			if(PB90(sq) == your_shi){
				MY_EV_ADD(40);
			}
			else if(PB90(sq) == your_xiang){
				MY_EV_ADD(24);
			}
		}
	}

	MY_EV_ADD(ADD_CheXPawn_To_1Pawn); // 有车方的加分

	if (StoY(yk) == MY_RANK2){
		RETRUN_MUL(16);
	}
	
	//fen 4kab2/9/3ab1R2/9/9/9/9/4KA3/9/2BA2B2 w - - 0 1
	if (have_bit(bb_your_shi, RankBB_A[MY_RANK2])){
		MY_EV_ADD(32);
	}
	
	// 对方仕相全
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){

		MY_EV_SUB(256);

		Square x1 = S90_from_piecelist(POSITION, your_xiang, 0);
		Square x2 = S90_from_piecelist(POSITION, your_xiang, 1);

		if (PB90(MY_SQ16) == your_xiang){
			// fen 4k4/4a4/3ab3b/R8/9/2B6/9/3AB4/5K3/9 b - - 76 76 
			if (yk == MY_SQ04){
				RETRUN_MUL(1);
			}
			if (yk == MY_SQ03 && PB90(MY_SQ02) == your_xiang){
				RETRUN_MUL(1);
			}
			if (yk == MY_SQ05 && PB90(MY_SQ06) == your_xiang){
				RETRUN_MUL(1);
			}
			// fen 5k3/4a4/4ba3/5R3/6b2/9/9/3AK4/9/2B2AB2 w - - 9 9</P> 也是和棋
			if (StoY(yk) == MY_RANK0){  // 对方的将在底线。
				T = POSITION.Rook_attacks_bb(mche);
				if (m_have_bit(m_and(T, RankBB_A[MY_RANK0])) == FALSE){
					RETRUN_MUL(1);  // fen 5k3/4a4/4ba3/7R1/6b2/9/9/3AK4/9/2B2AB2 b
				}
			}
		}

		if (StoY(yk) == MY_RANK0){
			// fen 9/4a4/3k1a3/9/9/9/9/B8/3rA4/2B1KA3 b - - 12 12</P>
			// fen 3a1a3/9/4k4/9/9/9/9/B8/4A4/r1B1KA3 b - - 120 120
			if (PB90(MY_SQ02) == your_xiang && PB90(MY_SQ12) == your_xiang
				&& PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(1);
			}
			if (PB90(MY_SQ06) == your_xiang && PB90(MY_SQ1A) == your_xiang
				&& PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(1);
			}
			// fen 4k4/4a4/5a2b/9/4R1b2/9/9/3AK4/9/2B2AB2 b - - 0 0 
			// 二个相的位置在一边,随时可连线
			if ((abs(StoX(mche) - 0x4) <= 1) &&
				(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi)){
				// 二个相是连在一起的。
				Square xi = S90_from_piecelist(POSITION, your_xiang, 0);
				if (m_have_bit(m_and(POSITION.xiang_attacks_bb(xi),
					bb_your_xiang))){
					RETRUN_MUL(1);
				}
			}
		}


		//这是红车在底线时的特殊的形
		if (StoY(mche) == MY_RANK0
			&& PB90(MY_SQ0D) == your_shi && PB90(MY_SQ16) == your_xiang){
			// fen 2baR4/4ak3/4b4/9/9/9/9/9/4K4/9 b - - 105 105
			// L
			if (PB90(MY_SQ0E) == your_king && PB90(MY_SQ03) == your_shi
				&& StoX(mche) >= 0x04){
				// 左边还有象。就是和棋
				if (m_have_bit(m_and(LeftBB[0x4],
					bb_your_xiang))){ //	print_bb(LeftBB[0x4]);
					RETRUN_MUL(1);
				}
			}
			// R
			if (PB90(MY_SQ0C) == your_king && PB90(MY_SQ05) == your_shi
				&& StoX(mche) <= 0x04){
				// 左边还有象。就是和棋
				if (m_have_bit(m_and(RightBB[0x4],
					bb_your_xiang))){ //	print_bb(LeftBB[0x4]);
					RETRUN_MUL(1);
				}
			}
		}

		if (PB90(MY_SQ0D) == your_shi && PB90(MY_SQ16) == your_xiang){
			if (StoY(yk) == MY_RANK0){
				// fen 3a1k3/4a4/4b4/3R5/2b6/9/9/9/4K4/9 b - - 0 0
				// 将车不在一边，也是和棋，将在底线。
				if ((StoX(yk) >= 0x4) && StoX(mche) <= 0x4){
					RETRUN_MUL(1);
				}
				if ((StoX(yk) <= 0x4) && StoX(mche) >= 0x4){
					RETRUN_MUL(1);
				}
			}
		}

		// fen 2b1kab2/3Ra4/9/9/9/9/9/5A2B/3KA4/6B2 b - - 0 1
		if (PB90(MY_SQ0D) == your_shi && StoY(yk) == MY_RANK0){
			if (abs(StoX(x1) - StoX(x2)) <= 4){
				RETRUN_MUL(1);
			}
		}

		// fen 4Rab2/5k3/5a2b/9/9/9/9/4B4/4AK3/3A5 w - - 120 120
		if (StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (StoX(mche) == 0x4){
				// R
				if (StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi
					&& count_1s(bb_your_xiang, RightBB[0x4]) == 2){
					RETRUN_MUL(1);
				}
				// L
				if (StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi
					&& count_1s(bb_your_xiang, LeftBB[0x4]) == 2){
					RETRUN_MUL(1)
				}
			}
			// fen 3a5/4a4/4k4/9/6b2/9/9/1r3A2B/4A4/3K2B2 r
			if (StoY(yk) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ0D) == your_shi){
				if ((StoX(yk) == 0x3 && count_1s(RightBB[0x3], m_or(bb_your_xiang, bb_your_shi)) == 4)
					|| (StoX(yk) == 0x5 && count_1s(LeftBB[0x5], m_or(bb_your_xiang, bb_your_shi)) == 4)){
					RETRUN_MUL(1);
				}
			}

			// fen 5k3/9/3a1a3/9/9/2B3B2/7r1/3A5/4A4/5K3 b - - 0 1
			if (StoY(yk) MY_SMALL_EQL MY_RANK1){
				if (StoX(yk) == 0x3 && !have_bit(LeftBB[0x4], bb_your_shi)){
					RETRUN_MUL(1);
				}
				if (StoX(yk) == 0x5 && !have_bit(RightBB[0x4], bb_your_shi)){
					RETRUN_MUL(1);
				}
			}


			// fen 9/3k5/3a1a3/9/9/2B6/9/4B4/1r2A4/3K1A3 b - - 0 1
			if (StoY(yk) MY_SMALL_EQL MY_RANK1){
				if (PB90(MY_SQ0D) == your_shi){
					if ((StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi)
						|| (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi)){
						if (StoY(mche) == MY_RANK0){
							RETRUN_MUL(1);
						}
						if (StoY(mche) != MY_RANK0 && StoY(yk) == MY_RANK0){
							RETRUN_MUL(1);
						}
					}
				}
			}

			//fen 4k4/4a4/5a3/9/2b3b2/9/7R1/3A1K3/9/5A3 b - - 0 1
			if (MY_SQ04 == yk && PB90(MY_SQ0D) == your_shi){
				Bitboard mix = m_and(m_and(LeftBB[0x7], RightBB[0x1]), bb_your_xiang);
				if (count_1s(mix) == 2){
					RETRUN_MUL(1);
				}
			}

			// fen 2b1k4/4a4/b2a5/9/6R2/9/9/B8/3KA4/2B2A3 b - - 0 1
			if (MY_SQ04 == yk && StoX(mk) != 0x4){
				if (!have_bit(LeftBB[0x4], bb_your_xiang) || !have_bit(RightBB[0x4], bb_your_xiang)){
					RETRUN_MUL(1);
				}
			}

			// fen 3a5/4k4/b8/9/6b2/9/9/8B/4A4/4KAB1r w - - 0 1
			if (StoY(mche) MY_SMALL_EQL MY_RANK1 && StoY(yk) == MY_RANK0){
				if (StoX(mche) <= 1){
					if (PB90(MY_SQ02) == your_xiang && PB90(MY_SQ12) == your_xiang){
						RETRUN_MUL(1);
					}
				}
				if (StoX(mche) >= 7){
					if (PB90(MY_SQ06) == your_xiang && PB90(MY_SQ1A) == your_xiang){
						RETRUN_MUL(1);
					}
				}
			}

			//  fen 2b3R2/3ka4/3a5/9/2b6/9/9/9/3KA4/6B2 b - - 0 1
			if (StoX(mche) >= 0x3 && StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi) {
				if (!have_bit(bb_your_xiang, RightBB[0x3])) {
					RETRUN_MUL(2);
				}
			}
			if (StoX(mche) <= 0x5 && StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi) {
				if (!have_bit(bb_your_xiang, LeftBB[0x5])) {
					RETRUN_MUL(2);
				}
			}


			// fen 2b6/3ka3R/b2a5/9/9/9/9/5A3/3KA4/9 w - - 0 1			
			if (StoX(mche) > 0x4 && StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi){
				if (!have_bit(bb_your_xiang, RightBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			if (StoX(mche) < 0x4 && StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){
				if (!have_bit(bb_your_xiang, LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			

			// fen 5a3/3ka4/4b4/R8/2b6/6B2/9/3A5/3K5/5A3 b - - 0 1
			if (StoY(yk) MY_SMALL_EQL MY_RANK1 && StoX(yk) != 0x4 && POSITION.side_to_move() == YOUR_COLOR){
				if (!have_bit(FileBB_A[StoX(yk)], bb_your_shi)){
					RETRUN_MUL(4);
				}
			}

			// fen 2bk5/9/b2a1a3/1R7/9/9/9/5A3/3K5/3A5 w - - 0 1
			if (!have_bit(bb_your_xiang, MyLowBB[MY_RANK2])){
				if (StoX(yk) == 0x3 && !have_bit(bb_your_xiang, RightBB[0x4])){
					RETRUN_MUL(4);
				}
				if (StoX(yk) == 0x5 && !have_bit(bb_your_xiang, LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
			

			if (MY_SQ04 == yk){
				RETRUN_MUL(8);
			}

			if (StoY(yk) MY_SMALL_EQL MY_RANK1){
				if (!have_bit(FileBB_A[StoX(yk)], bb_your_shi)){
					RETRUN_MUL(8);
				}
			}

			//POSITION.board_display("mm16");

			//RETRUN_MUL(16);

			// fen 4kab2/9/4ba3/9/9/P8/9/4BA3/4AK3/2B4r1 b - - 0 48
			//if(StoY(yk) MY_SMALL_EQL MY_RANK1){

			//	Bitboard bkp = pao_eat_attacks_bb(yk,BitboardOCC);
			//	if(bit_is_set(bkp,mk)){
			//	}
			//	else{
			//	   RETRUN_MUL(4);
			//	}
			//}

		} // 对方仕相全
	}
}
