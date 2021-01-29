#ifndef END_my_m_MT_R_1PAO1PAWN_B_1PAO
#define END_my_m_MT_R_1PAO1PAWN_B_1PAO
#include "../../chess.h"
#include "../../preGen.h" 
#include "../../endgame/mat.h"
#include "1炮1兵对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//const int Pawn_Add = 64;

//红方炮兵，黑方只有一炮
void my_m_MT_R_1PAO1PAWN_B_1PAO(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yk = your_king_pos;
	//炮高兵例和一炮  // 例典 page 134
	if(my_shi_num == 0 && my_xiang_num == 0){
		RETRUN_MUL(1);
	}

	if(my_shi_num == 0){
		MY_EV_SUB(96);
	}

	if(StoY(mpawn) MY_LARGE MY_RANK0){
		MY_EV_ADD(64);
	}

	if(StoY(mpawn) MY_SMALL StoY(yk)){
		MY_EV_SUB(164);
	}

	if(your_shi_num == 2 && your_xiang_num == 2){
		RETRUN_MUL(1);
	}

	// fen 2b6/4P4/3k5/9/3c5/9/9/3A4B/9/2C1K4 w - - 35 35  //炮兵方的兵在对方将的下面,也和了
	if(StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(1);
	}

	if(StoY(mpawn) MY_SMALL StoY(yk)){
		if(your_xiang_num != 0){
			RETRUN_MUL(1);
		}
		if(your_shi_num == 2){
			RETRUN_MUL(1);
		}
	}

	// fen 2b6/3k1P3/3a5/3c5/9/6B2/9/3K5/4A4/7C1 w - - 122 122 
	if(your_shi_num != 0 && your_xiang_num != 0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(1);
		}
	}

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 9/5k3/4P4/9/9/2B6/5c3/9/4K2C1/6B2 b - - 0 0
	if(my_shi_num == 0 && StoX(ypao) != StoX(your_king_pos)){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 
			&& abs(StoY(yk) - StoY(mpawn)) <= 1){	
				if(StoX(ypao) != StoX(yk)){
					RETRUN_MUL(1); // fen 2bk5/9/5c3/9/6b2/4C4/9/9/4p4/5K3 w - - 0 1
				}
				RETRUN_MUL(2);
		}
	}
	


	//如果黑炮>红炮, 也是和了
	if(your_xiang_num != 0){
		if(StoY(mpao) MY_SMALL_EQL MY_RANK3 && StoY(ypao) MY_SMALL_EQL MY_RANK4){
			if(StoY(ypao) MY_LARGE StoY(mpao)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/4k4/1c7/4P4/2b3b2/9/3C5/3A5/4A4/5K3 b - - 0 1
	if(your_xiang_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(2);
		}
	}

	// fen 4c4/9/b3k1P2/9/9/9/9/3A5/3C1K3/9 w - - 218 218
	if(my_xiang_num == 0 && my_shi_num <= 1 && your_xiang_num != 0){
		if(abs(StoY(mpawn) - StoY(yk)) <= 1 
			&& StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if(StoX(your_king_pos) == 0X4 && PB90(MY_SQ04) == your_pao){
					RETRUN_MUL(2);
				}
		}
	}

	// fen 9/6c2/b2aka3/9/6b2/9/3p5/3AC4/4A4/3K5 b - - 0 1
	if(your_shi_num == 2 && (PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi)){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/2c6/b8/2C6/2b6/2P6/9/3KB3B/4A4/5A3 w - - 0 105
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN == 0){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/9/2ca2P2/9/6b2/9/6C2/5A2B/4A4/4K1B2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoX(mpawn) - 0x4) >= 2){
			if(bit_is_set(ei.attacked_by(your_pao),mpawn)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5a3/3P1k3/c8/9/9/9/9/5A3/4K4/1C4B2 w - - 0 1
	if(your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1 && StoY(ypao) == MY_RANK2){
		if(StoX(mpawn) < 0x4 && StoX(yk) == 0x5 && PB90(MY_SQ05) == your_shi){
			RETRUN_MUL(2);
		}
		if(StoX(mpawn) > 0x4 && StoX(yk) == 0x3 && PB90(MY_SQ03) == your_shi){
			RETRUN_MUL(2);
		}
	}

	// fen 2bk5/4a4/4ba3/9/p8/2B1c3C/9/4B4/9/5K3 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(64);
		}
		RETRUN_MUL(3);
	}

	// fen 3c1kb2/9/3a5/5P3/9/9/2C6/5A3/4A4/4K1B2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(3);
		}
	}


	// fen 3k2c2/9/b2a1a3/9/6b2/9/4C4/4p3B/4A4/4K4 w -
	// fen 6c2/4a4/3k1a3/9/6b2/9/4C4/4p3B/4A4/4K4 b - - 124 124
	if(your_shi_num >= 1 && your_xiang_num >= 1 && PB90(MY_SQ16) == my_pawn){
		if(PB90(MY_SQ0D) == your_shi && StoX(mpao) != 0x4){ //PB90(MY_SQ16)
			RETRUN_MUL(4);
		}
	}

	

	// fen 4k4/4a1c2/4b4/9/4C1b2/9/4p4/8B/9/4KA3 w - - 136 136
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(my_shi_num == 0){
			RETRUN_MUL(4);
		}

		if(my_shi_num <= 1){
            Bitboard rsuper = POSITION.Pao_Super_bb(my_king_pos);
			if(m_have_bit(m_and(
				rsuper,bb_your_pao))){
					RETRUN_MUL(4);
			}
		}
	}

	// fen 6c2/4k4/3a1a3/9/2b3b2/9/9/2p2C2B/4A4/4K4 b - - 0 0
	// fen 4k4/4a4/b2c2P2/9/9/2B3B2/9/3A1A3/4K4/2C6 w
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ0D) == your_shi && StoY(mpawn) MY_SMALL_EQL MY_RANK2){
				if(abs(StoX(mpawn) - 0x4) >= 2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	if((your_shi_num + your_xiang_num) >= 2){		
		RETRUN_MUL(4);
	}

	// fen 3k1ab2/9/4ba3/8p/9/9/9/3cB4/7C1/5K3 r
	if(your_xiang_num >= 1){
		if(PB90(MY_SQ0D) == my_pawn && StoY(yk) == MY_RANK0){
		}
		RETRUN_MUL(4);
	}

	// fen 4k4/4a4/3aP4/4c4/9/2B6/9/4KA3/3C5/6B2 b - - 0 111
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == my_pawn){  // PB90(MY_SQ16)
			RETRUN_MUL(4);
		}
	}

	// fen 3a5/3k1P3/6c2/9/9/2B6/9/3AK4/9/6C2 w - - 0 1
	if(my_shi_num <= 1 && your_shi_num >= 1 && StoY(yk) == MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && StoY(ypao) == MY_RANK2){
			if(yk == MY_SQ0C && PB90(MY_SQ03) == your_shi && StoX(mpawn) >= 0x4){
				RETRUN_MUL(4);
			}
			if(yk == MY_SQ0E && PB90(MY_SQ05) == your_shi && StoX(mpawn) <= 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/4ak3/9/5P3/9/6B2/9/3K5/5c3/3C5 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num <= 1 && your_shi_num >= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}

	
	// fen 5k3/4a4/3a4c/9/9/2B3B2/5p3/9/4A4/1C1K5 b - - 
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE MY_RANK1){
			RETRUN_MUL(4);
		}
		RETRUN_MUL(8);
	}

	// fen 4k4/4a4/3aP4/4c4/9/2B6/9/4KA3/3C5/6B2 b - - 0 111
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}

	// fen 9/4P4/3k5/3c5/9/2B6/9/3AK4/9/6C2 w - - 0 0
	if(my_shi_num <= 1 && StoY(mpawn) MY_SMALL StoY(yk)){
		RETRUN_MUL(8);
	}

	//fen 3k5/c8/5a3/3P5/9/6B2/9/4K4/6C2/2B6 b - - 0 1
	if (my_shi_num == 0){
		if (your_shi_num >= 1){
			if (StoY(ypao) == MY_RANK1 && StoY(yk) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}
	}

	


}

