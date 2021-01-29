#ifndef END_my_m_MT_R_1CHE1PAO_B_1CHE
#define END_my_m_MT_R_1CHE1PAO_B_1CHE
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//我方一车一炮, 对方一车
void my_m_MT_R_1CHE1PAO_B_1CHE(typePOS &POSITION, EvalInfo &ei){

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yk   = your_king_pos;
	Square mk   = my_king_pos;

	//*****************************************************************************************
	//1, 如果对方是仕相全,则是和棋
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
		else if(StoY(yk) == MY_RANK1){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/9/4b3b/5R3/9/9/4r4/3KCA3/9/2BA5 b - - 0 1
	if(your_xiang_num == 2){
		MY_EV_SUB(128);
	}

	//对方没有双相,要另外加分
	if(your_xiang_num == 0){
		MY_EV_ADD(128);
	}

	//*****************************************************************************************
	//2,如果对方没有仕相,则可海底搂月来胜
	if(your_shi_num == 0 && your_xiang_num == 0){
		//炮方的车守了中线, 在这儿作海底搂月的判断
		if(StoX(mche) == 0x4){
			MY_EV_ADD(64);

			if((StoX(yk) == 0x3 && StoX(mpao) <= 0x3) 
				|| (StoX(yk) == 0x5 && StoX(mpao) >= 0x5)){
					MY_EV_ADD(64);
			}

			if(StoY(mpao) MY_SMALL StoY(yk)){
				MY_EV_ADD(96);
			}

			if(StoX(mpao) == StoX(yk)){
				MY_EV_ADD(64);
			}
		}
	}
	//*****************************************************************************************
	//炮方一个仕相也没有了, 133局，车炮和车士，车炮和车相
	if(my_shi_num == 0 && my_xiang_num == 0){
		if((your_shi_num + your_xiang_num) >= 1){
			RETRUN_MUL(2);
		}
		if(StoX(yche) == 0x4 && StoY(yk) != MY_RANK2){
			RETRUN_MUL(2);
		}
	}

	// fen 5kb2/4a4/9/9/9/2B6/9/9/4KC1R1/5r3 w - - 35 35 
	//如果红方没有仕了,黑方有仕相,也是和棋
	if(my_shi_num == 0){
		if(your_shi_num >= 1 && your_xiang_num >= 1){
			RETRUN_MUL(2);
		}
	}

	// 另一种妙和
	// fen 4kaRC1/4a4/9/7r1/9/6B2/9/8B/9/4K4 b
	if(your_shi_num == 2){
		if(StoY(mpao) == StoY(mche) && StoY(mche) == MY_RANK0){
			if(StoX(yche) == StoX(mpao)){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 4kaR1C/4a4/9/8r/9/6B2/9/9/9/4K1B2 w - - 0 0 moves i9h9 i6h6 h9i9 h6i6


	//*****************************************************************************************
	// 如果车炮被牵制了,也是和棋
	// fen 4k4/9/3ab4/9/2b6/9/1R1C4r/4B4/4A4/2B1K4 w
	if (isStringByChe(POSITION, mche, mpao, yche)){
		// fen 4k1b2/4a4/3a5/9/9/2B6/2r6/2C1BA3/4AK3/2R6 w - - 0 1 
		// not he
		if (StoY(mpao) == MY_RANK7){
		}
		else{
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/6C2/4b4/9/2b6/9/9/3R4B/1r2K4/9 w - - 7 7 
	// 车炮对车,车炮方没有仕了, 车方有二个象
	if(my_shi_num == 0){
		if(your_xiang_num == 2 && StoY(yk) != MY_RANK2){
			RETRUN_MUL(2);
		}
	}

	// fen 5ab2/4a4/4k4/9/9/4R4/r3c4/4B4/4A4/3AK4 b - - 57 57
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpao) MY_SMALL_EQL MY_RANK4){
			if(StoY(mche) == StoY(mpao) && StoX(yche) == StoX(mpao)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3ak4/9/R1Ca5/2r6/9/2B6/9/B4A3/4A4/5K3 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0 && StoY(mpao) == MY_RANK2){
		if(StoY(mche) == StoY(mpao) && abs(StoX(mche) - 0x4) >  abs(StoX(mpao) - 0x4)){
			if(StoY(yche) MY_LARGE StoY(mpao) && bit_is_set(ei.attacked_by(your_che),mpao)){
				if(StoX(mpao) <= 0x02 && PB90(MY_SQ15) == your_shi && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(mpao) >= 0x06 && PB90(MY_SQ17) == your_shi && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}


	if(my_shi_num == 0){
		if(your_shi_num == 2 && StoY(yk) != MY_RANK2){
			RETRUN_MUL(4);
		}
	} 

	// fen 9/4ak3/1r1a4b/C8/9/9/9/5AR2/5K3/9 b - - 0 1
	if (my_xiang_num == 0 && my_shi_num <= 1){
		if ((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (StoY(mpao) MY_SMALL MY_RANK7){
				RETRUN_MUL(4);
			}
		}		
	}

	// fen 3ak4/9/R3Ca3/4r4/9/2B6/9/4BA3/4A4/5K3 w - - 37 37
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mche) == StoY(mpao) && StoX(yche) == StoX(mpao)){
			if(StoX(mpao) <= 0x4 && StoX(mche) < 0x4){
				if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(4);
				}
			}
			if(StoX(mpao) >= 0x4 && StoX(mche) > 0x4){
				if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/9/5a3/4r4/2b2C3/9/5R3/9/5K3/3A5 b - - 0 1
	if(my_xiang_num == 0 && my_shi_num <= 1 && your_shi_num >= 1){
		if(StoX(mche) == StoX(mpao) && StoX(mche) == StoX(mk)){
			if(StoY(mche) MY_SMALL_EQL StoY(mk) && StoY(mpao) MY_SMALL_EQL StoY(mche)){
				if(StoY(mpao) MY_LARGE_EQL MY_RANK2){
					if(PB90(MY_SQ17) == your_shi && StoX(mpao) == 0x5){
						if(StoX(yche) == 0x4){
							RETRUN_MUL(4);
						}
					}
					if(PB90(MY_SQ15) == your_shi && StoX(mpao) == 0x3){
						if(StoX(yche) == 0x4){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}

	// fen 4k4/5R3/9/9/9/9/9/3KB4/3C5/3r2B2 b - - 0 1
	if(my_shi_num == 0 && StoY(mk) == MY_RANK7 && StoY(yche) == MY_RANK9){
		if(StoY(mpao) == MY_RANK8){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4a4/b2a5/4R4/9/2r6/9/9/4A4/3CK4 b - - 0 1
	if(my_shi_num <= 1 && my_xiang_num == 0){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			if(StoY(yche) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 1Rb1ka3/9/3a5/9/9/9/9/9/4A4/1CrAK4 b - - 0 1
    if(StoY(yk) == MY_RANK0 && (your_shi_num + your_xiang_num) >= 3){
		if(my_xiang_num == 0){
			if(bit_is_set(ei.attacked_by(my_che),mpao) 
				&& bit_is_set(ei.attacked_by(your_che),mpao)){
					RETRUN_MUL(8);
			}
		}
	}

	// fen 1Rb1k1b2/4a4/9/9/9/9/9/2r1BA3/C8/4K4 b - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if (my_xiang_num <= 1 && my_shi_num <= 1){
			RETRUN_MUL(8);
		}
	}


	// fen 3ck4/4a4/9/9/6R2/4r4/9/3A5/4A4/5K3 w - - 26 26
	if(my_xiang_num == 0 &&  my_shi_num <= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(your_shi_num == 2){
			if(StoX(mpao) != StoX(yk)){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 4k4/4a4/3a5/9/5R3/6B2/4r4/9/9/4KCB2 w - - 170 170
	if(my_shi_num == 0 && your_shi_num == 2){
		if(StoY(yk) == MY_RANK0 && StoY(yche) MY_LARGE_EQL MY_RANK3){			
			RETRUN_MUL(8);			
		}
	}

	// fen r3ka3/3Ra4/4b4/9/9/9/9/5A3/3KC4/9 w - - 0 1
	if(my_shi_num <= 1 && my_xiang_num == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
			RETRUN_MUL(8);
		}
	}

	// fen 9/5k3/4br3/9/4R4/9/9/B8/9/2C1K4 b - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num == 0 && my_xiang_num <= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 6b2/3k5/b8/9/4R4/6r2/3C5/3K5/9/3A5 b - - 0 1
	if((my_xiang_num + my_shi_num) <= 1){
		if(your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}


	// fen 9/4k4/3ab4/9/2b6/5R3/9/9/4A1r2/3C1KB2 r
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		// fen 3k2b2/4a4/4b4/4r4/9/9/9/3A2R2/4C4/4K4 w - - 0 1
		if(my_shi_num <= 1 && my_xiang_num == 0){
			RETRUN_MUL(8);
		}

		if(my_xiang_num == 0){
			RETRUN_MUL(12);
		}

		if(my_shi_num <= 1 && my_xiang_num <= 1){
			RETRUN_MUL(12);
		}
	}
}

