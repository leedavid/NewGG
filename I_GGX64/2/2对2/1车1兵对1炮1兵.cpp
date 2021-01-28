#ifndef END_my_m_MT_R_1che1pawn_B_1pao1pawn
#define END_my_m_MT_R_1che1pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// fen 9/3P5/4k4/9/2b3b2/6B2/9/3AB4/r3Ap3/C3K4 w - - 44 44

//const int ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[3]  =  { 80, 48, 16};  //炮兵对车兵,炮方安全后,有兵的加分 

//车兵对炮兵
void my_m_MT_R_1che1pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	my_m_MT_R_1che1pawn_B_1pao(POSITION,ei);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(ei.mul <= 2) return;

	Square yk   = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);

	// fen 2b1ka3/4a4/4b4/p2P5/2c6/9/6R2/B8/4A4/3AK4 w - - 2 2
	if((your_shi_num + your_xiang_num) == 4){
		if(MY_SQ04 == yk && PB90(MY_SQ16) == your_xiang){
			RETRUN_MUL(2);
		}
	}

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_CheXPawn_To_PaoPawn_PawnByShi[your_shi_num]);
	}

	MY_EV_ADD(ADD_CheXPawn_To_PaoPawn);

	// fen 4k4/4a4/3ab4/c8/p8/6B2/P3R4/9/4A4/2BAK4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 4){
			if(StoY(mche) == StoY(mpawn) && StoY(ypao) MY_SMALL_EQL MY_RANK4){
				if(bit_is_set(ei.attacked_by(your_pao),mpawn)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k1a3/9/4ba3/7rp/2b6/6B1P/9/4B3C/4A4/4K4 b - - 123 123
	// 对方的兵不能过河
    if(your_xiang_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ16) == your_xiang){
			if(StoX(mpawn) == 0 || StoX(mpawn) == 8){
				Bitboard peat = POSITION.Pao_Eat_bb(ypao);
				if(bit_is_set(peat,mpawn)){
					RETRUN_MUL(2);
				}
			}
		}
	}
	// fen 4ka3/9/5a2b/pr7/6b2/P1B6/C8/4B4/4A4/5K3 w - - 120 120
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ16) == your_xiang){
		if(MY_SQ26 == ypawn && MY_SQ38 == mpawn){
			RETRUN_MUL(4);
		}
		if(MY_SQ2A == ypawn && MY_SQ3C == mpawn){
			RETRUN_MUL(4);
		}
	}

	// fen 1R4b1c/3ka4/3a5/9/8p/9/8P/9/4K4/6B2 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 4){
			if(bit_is_set(ei.attacked_by(your_pao),mpawn)){
				if(!IsOnSameSide(mche,ypao) && StoY(ypao) MY_SMALL_EQL MY_RANK3){
					RETRUN_MUL(4);
				}
			}
		}
	}

}

