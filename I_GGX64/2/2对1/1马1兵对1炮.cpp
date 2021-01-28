#ifndef END_my_m_MT_R_1MA1PAWN_B_1PAO
#define END_my_m_MT_R_1MA1PAWN_B_1PAO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




//我方一马一兵，对方一炮
void my_m_MT_R_1MA1PAWN_B_1PAO(typePOS &POSITION, EvalInfo &ei){
	
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square yk = your_king_pos;
	Square mk = my_king_pos;

	// fen 5c3/N8/4k1P1b/9/9/9/9/5K3/9/9 b - - 0 1
	if (your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK2 && StoY(yk) != MY_RANK0) {
		MY_EV_SUB(32);
		if (StoX(yk) == 0x4) {
			MY_EV_SUB(32);
			if (StoY(ypao) MY_SMALL_EQL MY_RANK2) {
				MY_EV_SUB(32);
			}
		}
	}

	//对方没有仕，就不可能杀我
	if(your_shi_num == 0){
		if(StoY(yk) MY_LARGE StoY(mpawn)){
			RETRUN_MUL(2);
		}

		//马单兵对炮双象则为例和棋。 
		if(your_xiang_num == 2){
			RETRUN_MUL(2);
		}
		else{ // 马高兵例胜炮象
			if(StoY(mpawn) MY_LARGE StoY(yk)){
				MY_EV_ADD(ADD_1马兵对1炮_by_Pawn_By_Shi[your_shi_num]);
			}
		}
	}

	if(StoY(yk) MY_LARGE StoY(mpawn)){
		if((my_shi_num + my_xiang_num) >= 1){
			RETRUN_MUL(2);
		}
	}

	if(your_shi_num == 2){
		RETRUN_MUL(2);
	}

	//马高兵例和炮仕相 
	//例典 page84 fen 2c6/4ak3/9/5P3/2b6/5N3/9/9/9/4K4 w
	//象,仕守护中宫, 红兵难以入侵,终成和局
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		RETRUN_MUL(2);
	}

	// fen 3P1k3/9/5c1N1/9/9/2B6/9/3A5/4A4/5KB2 w - - 0 1
	if(StoY(mpawn) == MY_RANK0){
		if(StoY(yk) != MY_RANK0){
			RETRUN_MUL(2);
		}
		if(PB90(MY_SQ15) == my_ma && MY_SQ05 == yk){
		}
		else if(PB90(MY_SQ17) == my_ma && MY_SQ03 == yk){
		}
		else{
			RETRUN_MUL(2);
		}
	}

	// fen 9/3P1P3/3ak4/5cN2/9/9/9/B2A4B/5K3/3A5 b - - 40 40
	// fen 9/3P5/3ak4/5cN2/9/9/9/B2A4B/5K3/3A5 b
	if(StoY(mpawn) MY_SMALL StoY(yk)){
		if(your_shi_num >= 1){
			if(PB90(MY_SQ17) == your_shi && StoX(ypao) == 0x3){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ15) == your_shi && StoX(ypao) == 0x5){
				RETRUN_MUL(4);
			}
		}
	}

	

	if(StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(4);
	}

	// fen 3k5/5P3/1N2b4/9/9/2B6/4c4/9/5K3/9 b - - 0 1
	if(your_xiang_num >= 1 && StoX(ypao) == 0x4 && StoY(ypao) MY_LARGE_EQL MY_RANK3){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
			if(StoX(mpawn) != 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	//fen 9/6P2/4ka3/3N5/9/9/9/5c3/9/5K3 w - - 0 1
	if (your_shi_num >= 1 && StoY(mpawn) MY_SMALL StoY(yk)){
		if (StoY(ypao) MY_LARGE MY_RANK2 && StoY(ypao) MY_SMALL StoY(mk)){
			RETRUN_MUL(4);
		}

		RETRUN_MUL(8);
	}

	// fen 5a3/3ka4/9/9/2b3b2/9/9/9/2nC1p3/3K1A3 w - - 0 1
	if(your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi && StoX(mma) < 0x4){
			RETRUN_MUL(8);
		}
		if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi && StoX(mma) > 0x4){
			RETRUN_MUL(8);
		}
	}

	// fen 5c3/N8/4k1P1b/9/9/9/9/5K3/9/9 b - - 0 1
	if (your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK2 && StoY(yk) != MY_RANK0) {
		if (StoX(yk) == 0x4) {
			if (StoY(ypao) MY_SMALL_EQL MY_RANK2) {
				if (my_shi_num == 0 && my_xiang_num == 0) {
					if (StoX(mk) == 0x5 && StoX(mpawn) >= 0x6 && StoX(ypao) == 0x5) {
						RETRUN_MUL(8);
					}
					if (StoX(mk) == 0x3 && StoX(mpawn) <= 0x2 && StoX(ypao) == 0x3) {
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2b6/4k4/3P1cN2/9/9/2B6/9/9/5K3/6B2 w - - 0 1
	if (your_xiang_num >= 1){
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			RETRUN_MUL(12);
		}
	}



	// fen 9/3P5/3aNk3/9/9/2B3B2/9/3A5/4Kc3/3A5 w - - 0 0
}

