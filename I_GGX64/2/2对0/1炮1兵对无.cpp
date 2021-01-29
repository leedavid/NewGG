#ifndef END_my_m_MT_R_1PAO1PAWN_B_NO
#define END_my_m_MT_R_1PAO1PAWN_B_NO
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1兵对无.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int _PaoPawn_To_No_Canwin = 128;  //胜棋分

//应该是我方一点一点好，对方一点一点差来判断

//我方一炮一兵，对方 0 attacker
void my_m_MT_R_1PAO1PAWN_B_NO(typePOS &POSITION, EvalInfo &ei){
    // 炮兵方的别外加分
	MY_EV_ADD(ADD_1PaoXPawn_1Pawn);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square yk = your_king_pos;
	Square mk = my_king_pos;

	// fen 5P3/4k4/4b4/9/2b6/9/9/3A1A2B/4K4/5C3 w - - 0 1
	if(your_xiang_num == 2 && StoY(mpawn) == MY_RANK0 && StoY(yk) == MY_RANK1){
		MY_EV_SUB(196);
	}

	// fen 9/3k5/5P3/9/2b3b2/9/9/4K4/9/4C4 b - - 0 1
	if(my_shi_num == 0){
		MY_EV_SUB(128);
		if(my_xiang_num == 0){
			MY_EV_SUB(128);
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if(abs(StoY(mpawn) - StoY(yk)) <= 1){
					MY_EV_SUB(128);
				}
			}
		}
	}

	if(StoY(mk) != MY_RANK9 && my_shi_num != 0){
		MY_EV_ADD(64);
	}

	// fen 9/3ka4/5a3/9/9/2B6/9/3AB4/2p1Ac3/3K5 b - - 0 0
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(128);
	}

	if(StoY(mpawn) == MY_RANK0 && StoY(yk) != MY_RANK0){
		MY_EV_SUB(96);
	}

	//如果对方只有二仕一相,且对方的将在原位
	if(your_shi_num == 2 && your_xiang_num == 1){
		if(PB90(MY_SQ04) == your_king && PB90(MY_SQ0D) == your_shi){
            if(PB90(MY_SQ03) == your_shi || PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(16);
			}
		}
	}

	// fen 3k5/4aP3/4ba3/9/2b6/2B6/9/9/4AKC2/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ0D) == your_shi){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(1);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 5k3/4P4/4b4/9/2b2C3/9/9/B3K4/9/2B6 b - - 0 1
	if (my_shi_num == 0){
		if (your_xiang_num == 2
			&& StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(1);
		}
	}

	// fen 6b2/4P4/5k3/9/2b6/2B3B2/1C7/4K4/9/9 w - - 0 1
	if (my_shi_num == 0 && your_xiang_num == 2){
		if (StoY(mpawn) MY_SMALL StoY(yk)){
			RETRUN_MUL(1);
		}
	}

	// fen 5k3/3P5/b8/5C3/9/9/9/9/4K4/9 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(1);
		}
	}

	// fen 9/4k4/4bP3/9/2b6/9/9/4B4/9/3K4C w - - 0 1
	if(my_shi_num == 0 && my_xiang_num <= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK2){
		if(abs(StoY(yk) - StoY(mpawn)) <= 1){
			if(your_xiang_num == 2){
				if(StoX(yk) != 0x4){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 3k1C3/2P6/9/9/2b6/6B2/9/9/9/2B1K4 w - - 0 1
	if (my_shi_num == 0 && your_xiang_num >= 1) {
		//if (have_bit(bb_your_xiang, m_and(LeftBB[0x7], RightBB[0x1]))) {
		//	RETRUN_MUL(1);
		//}
		MY_EV_SUB(128);
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
			if (StoX(yk) != 0x4) {
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/9/b3k4/2c6/2b6/9/9/3K1A3/2p6/5A3 b - - 0 160
	if(my_shi_num == 0 && your_shi_num == 2 && StoY(yk) MY_LARGE StoY(mpawn)){		
		RETRUN_MUL(2);
	}

	// fen 2c6/9/4bk3/9/6p2/9/9/8B/9/3K2B2 w - - 0 1
	if(my_shi_num == 0 && your_xiang_num == 2){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && EV_MY_CAN == 0){
			if(yk != MY_SQ04){
				RETRUN_MUL(2);
			}
			RETRUN_MUL(3);
		}
	}

	// fen 9/3k5/4ba3/9/4c4/6B2/9/4B4/4Ap3/4KA3 b - - 0 1if
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ0D) == your_shi && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpao) == 0x4){
				if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(3);
				}
				if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(3);
				}
			}
		}
	}
	
	// 可能的杀棋检测
    // fen 2bak4/4a4/4b4/5P3/9/9/4C4/4B4/9/4K1B2 w
	Bitboard yourKsuper = POSITION.Pao_Super_bb(your_king_pos);
	if(StoX(mpao) == StoX(your_king_pos) && PB90(MY_SQ04) == your_king
		&& PB90(MY_SQ0D) == your_shi && PB90(MY_SQ16) == your_xiang){	
			if(PB90(MY_SQ03) == your_shi || PB90(MY_SQ05) == your_shi){
				if(m_have_bit(m_and(yourKsuper,bb_my_pao))){
					RETRUN_MUL(16);
				}
			}
	}

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(32);
	}

	// fen 9/3ka4/5a3/9/9/2B6/9/3AB4/2p1Ac3/3K5 b - - 0 0
	// fen 3ak4/5P3/b4a2b/9/9/6B2/9/5A3/4C4/3AK1B2 b
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(2);
			}		
		}
	}
	// fen 2c6/9/4k4/9/9/9/9/9/9/3p1K3 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){

		//if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
		//	if(abs(StoY(mpawn) - StoY(yk)) == 1){
		//	}
		//}

		//我方什么没了，兵到底就和了, <<象棋残局例典>> P108 炮底兵例和单将
		if(StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(1);
		}

		if(your_xiang_num == 2){
			RETRUN_MUL(2);
		}
		// fen 9/1c7/4k4/9/9/9/9/B2p5/5K3/9 w - - 0 185
		if(your_xiang_num >= 1){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if(abs(StoY(mpawn) - StoY(yk)) == 1){
					// fen 9/9/4k4/9/3c5/9/9/9/4p4/3K2B2 b - - 0 1
					MY_EV_SUB(256);

					// 要没有铁门栓才行.
					RETRUN_MUL(2);
				}
			}
		}

		

		if(your_xiang_num == 1 && your_shi_num == 2){
			RETRUN_MUL(2);
		}

		if(your_xiang_num == 1 && your_shi_num == 1){
			if (my_shi_num >= 1 || my_xiang_num >= 1) {
				if (m_have_bit(m_and(
					yourKsuper, bb_my_pao))) {
					RETRUN_MUL(16);
				}
				if (StoY(mpawn) MY_SMALL MY_RANK4) {
					if (StoY(mpawn) == MY_RANK3) {
						RETRUN_MUL(3);
					}
					RETRUN_MUL(2);
				}
			}
		}

		if(your_xiang_num == 1 && your_shi_num == 0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(16);
			}
			if(StoY(mpawn) == MY_RANK1){
				if(StoY(yk) == MY_RANK3){
					RETRUN_MUL(8);
				}
			}
			RETRUN_MUL(2);
		}

		if(your_shi_num == 2){
			if(StoY(yk) MY_LARGE StoY(mpawn)){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 3P5/4k4/9/9/2b3b2/6B2/9/3K1A3/9/2B2C3 b - - 0 179
	if(your_xiang_num == 2 && StoY(yk) != MY_RANK0){
		if(StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	


	//如果我方的将在上面,则要加分
	if (StoY(my_king_pos) == MY_RANK7) {
		MY_EV_ADD(96);
	}

	// fen 4P4/3k5/3a5/9/2b3b2/2B6/9/3A1K3/4A4/4C1B2 w - - 61 61
	// fen 3P5/5k3/4ba3/9/2b6/9/9/3KBA3/9/3A1C3 w - - 15 15
	if (StoY(mpawn) == MY_RANK0) {
		if (your_shi_num >= 1 && your_xiang_num == 2) {
			if (StoY(yk) MY_SMALL_EQL MY_RANK1) {
				RETRUN_MUL(2);
			}
		}
	}

	// fen 6b2/9/3kb4/9/9/6B2/3c5/4Bp3/9/3K5 w - - 120 120
	if (your_xiang_num == 2 && my_shi_num == 0) {
		if (abs(StoY(mpawn) - StoY(yk)) <= 1) {
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/3Pa4/3a5/9/2b6/9/9/B2AB4/5K3/4C4 b - - 123 123
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0) {
		if (StoX(mpawn) <= 0x3 && PB90(MY_SQ15) == your_shi) {
			RETRUN_MUL(2);
		}
		if (StoX(mpawn) >= 0x5 && PB90(MY_SQ17) == your_shi) {
			RETRUN_MUL(2);
		}
	}

	// fen 9/4a3c/3k1a3/9/9/9/9/B7B/4K4/3p5 r
	if (my_xiang_num == 0 && your_xiang_num == 2) {
		if (StoY(mpawn) == MY_RANK0) {
			RETRUN_MUL(2);
		}
	}

	// fen 9/4a4/3kba3/9/2p3b1c/9/9/4B4/4AK3/2B6 w - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1 && EV_MY_CAN == 0) {
		if (MY_SQ04 != yk) {
			RETRUN_MUL(2);
		}
	}

	// fen 9/1c7/4k4/9/9/9/9/B2p5/5K3/9 w - - 0 185

	if(my_shi_num == 0 && my_xiang_num != 0){
		if(StoY(mpawn) == MY_RANK0){
			RETRUN_MUL(2);
		}
		if(FALSE){
		}
		else if(your_xiang_num == 2 && your_shi_num == 2){
			RETRUN_MUL(2);
		}
		else if(your_xiang_num == 2 && your_shi_num == 1){
			if(StoY(mpawn) MY_SMALL MY_RANK3){
				RETRUN_MUL(2); //56局，炮高兵相胜单缺仕
			}
		}
		else if(your_xiang_num == 2 && your_shi_num == 1){
			if(StoY(mpawn) MY_SMALL MY_RANK2){
				RETRUN_MUL(2); //51局，炮高兵相胜双象
			}
		}
		else if(your_xiang_num == 1 && your_shi_num == 2){
			if(StoY(mpawn) MY_SMALL MY_RANK3){
				RETRUN_MUL(2); //56局，炮高兵相胜单缺象
			}
		}
		else if(your_xiang_num == 1 && your_shi_num == 1){
			if(StoY(mpawn) MY_SMALL MY_RANK3){
				RETRUN_MUL(2); //56局，炮高兵相胜单缺象
			}
		}
		else if(your_xiang_num == 1 && your_shi_num == 0){
			//我方是炮象，对方是1相 
			//1,      <<象棋残局例典>> P108 炮底兵相例和单象
			//2，    兵在九宫之外，可和
			if(StoY(mpawn) MY_SMALL MY_RANK2){
				if(StoY(yk) MY_LARGE StoY(mpawn)){
					RETRUN_MUL(2);
				}
				if(StoX(mpawn) < 0x3 || StoX(mpawn) > 0x5){
					RETRUN_MUL(3);
				}
			}
		}			 
	}

	if(my_shi_num != 0){
		if(FALSE){
		}
		else if(your_xiang_num == 2 && your_shi_num == 2){
			if(StoY(mpawn) MY_SMALL MY_RANK2){
				RETRUN_MUL(2); // 61局，炮低兵仕全和仕象全
			}
			else if(StoY(mpawn) == MY_RANK2){
				if(IsOnSameSide(mpawn,yk) == false){
				   RETRUN_MUL(2); // fen 9/4k4/4ba3/6c2/9/6B2/9/4BAp2/3KA4/9 w - - 0 1
				}
				RETRUN_MUL(3);
			}
		}
		else if(your_xiang_num == 1 && your_shi_num == 2){
			if(StoY(mpawn) == MY_RANK0){
				RETRUN_MUL(2); // 57局，炮低兵单仕胜单缺相
			}
		}
		else if(your_xiang_num == 1 && your_shi_num == 1){
			// fen 7P1/3ka4/4b4/9/9/9/9/4B4/4A1C2/4K4 w
			Square x =  S90_from_piecelist(POSITION,your_xiang,0);
			if(abs(StoX(x) - 0x4) <= 2){
				if(StoY(mpawn) == MY_RANK0){
					RETRUN_MUL(4); // 炮低兵难胜仕相
				}
			}
		}
	}

	//  fen 4k4/4a4/b8/4P4/4C4/9/9/9/5K3/9 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1) {
		if (my_shi_num == 0 && my_xiang_num == 0) {			
				RETRUN_MUL(4);	
		}
	}


	//如果对方是仕相全,则要降一些分
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(4);
	}


	// 
	//if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
	//	RETRUN_MUL(4);
	//}

	//对方是单缺相, 要破士后,成炮仕例胜单象的局面.
	// fen 9/3c5/b2a1k3/9/9/2B6/9/3A1A3/3K2p2/9 w - - 154 154
	//对方是单缺相, 要破士后,成炮仕例胜单象的局面.
	// fen 9/3c5/b2a1k3/9/9/2B6/9/3A1A3/3K2p2/9 w - - 154 154
	if(your_shi_num == 2 && your_xiang_num >= 1){
		RETRUN_MUL(8);
	}

}

