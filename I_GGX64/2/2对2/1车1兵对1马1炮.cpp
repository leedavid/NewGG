#ifndef END_my_m_MT_R_1che1pawn_B_1pao1ma
#define END_my_m_MT_R_1che1pawn_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对1马1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//#define ADD_ChePawn_To_MaPao_By_Panw   128              //车兵对马炮,车兵方兵要加分,因为马炮太难杀对方了
//#define ADD_ChePawn_To_MaPao_By_Che    128              //车兵对马炮,车兵方车要加分,因为马炮太难杀对方了

//我方1车1兵,对方是马炮
void my_m_MT_R_1che1pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	MY_EV_ADD(ADD_ChePawn_To_MaPao_By_Che);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yk   = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_ChePawn_To_MaPao_By_PawnByShi[your_shi_num]);
	}

	//如果对方是仕相全,也可能是和棋
	if(your_shi_num == 2){

		if(your_xiang_num == 2){
			if(PB90(MY_SQ16) == your_xiang){
				if(StoY(yk) == MY_RANK0){
					RETRUN_MUL(2);
				}
			}
		}

		// fen 1R1nkab2/4a4/4c4/5P3/9/6B2/9/4BA3/4A4/4K4 b - - 120 120
		if(your_xiang_num == 1){
			Square x = S90_from_piecelist(POSITION,your_xiang,0);
			if(yk == MY_SQ04){				
				Bitboard xatt = POSITION.xiang_attacks_bb(x);
				if(bit_is_set(xatt,Square(MY_SQ16))){
					if(MY_SQ03 == yma && PB90(MY_SQ05) == your_shi){
						RETRUN_MUL(2);
					}
					if(MY_SQ05 == yma && PB90(MY_SQ03) == your_shi){
						RETRUN_MUL(2);
					}
				}
			}

			// fen 4kab2/4a4/4b4/9/6p2/9/1r7/4B4/4A1N2/3CKA3 w - - 130 130
			if(PB90(MY_SQ16) == your_xiang){
				if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
					if(MY_SQ2F == mpawn || MY_SQ38 == mpawn){
						if(MY_SQ0B == yma && StoX(ypao) > 0x4){
							RETRUN_MUL(2);
						}
					}
					if(MY_SQ33 == mpawn || MY_SQ3C == mpawn){
						if(MY_SQ0F == yma && StoX(ypao) < 0x4){
							RETRUN_MUL(2);
						}
					}
				}
			}
		}
	}

	// fen 3akn3/4a4/4b4/7P1/1c7/1R7/9/5A3/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(PB90(MY_SQ16) == your_xiang && StoY(mpawn) MY_LARGE_EQL MY_RANK3 
			&& StoY(ypao) MY_SMALL_EQL MY_RANK4){
			if(PB90(MY_SQ05) == your_ma || PB90(MY_SQ03) == your_ma){
				RETRUN_MUL(4);
			}
		}

	}

}

