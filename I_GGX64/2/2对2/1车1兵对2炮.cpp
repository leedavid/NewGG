#ifndef END_my_m_MT_R_1che1pawn_B_2pao
#define END_my_m_MT_R_1che1pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1兵对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//#define ADD_ChePawn_To_MaPao_By_Panw   128              //车兵对马炮,车兵方兵要加分,因为马炮太难杀对方了
//#define ADD_ChePawn_To_MaPao_By_Che    128              //车兵对马炮,车兵方车要加分,因为马炮太难杀对方了

//我方1车1兵,对方是2炮
void my_m_MT_R_1che1pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	MY_EV_ADD(ADD_ChePawn_To_MaPao_By_Che);

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_ChePawn_To_2Pao_By_PawnByShi[your_shi_num]);
	}

	// 
	if((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk){
		RETRUN_MUL(2);
	}

	// fen 9/2P1kc3/3ab4/1c7/2b6/9/4R4/4B4/4A4/2BAK4 w - - 0 0
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		Bitboard peat = POSITION.Pao_Eat_bb(mpawn);
		if(m_have_bit(
			m_and(peat,bb_your_pao))){
				RETRUN_MUL(2);
		}
	}

	// fen 2bckc2R/4a4/4b4/3P5/9/9/9/4B4/4A4/4KAB2 b - - 0 1
	if(your_xiang_num == 2 && your_shi_num >= 1 && MY_SQ04 == yk){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 || abs(StoX(mpawn) - 0x4) >= 2){
			if(have_bit(bb_your_pao,RankBB_A[MY_RANK0])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4kc3/3Pa3R/4b4/9/2b6/9/4c4/B3B4/4A4/3AK4 w - - 121 121
	//炮方是单缺仕,且兵到了下二线, 炮方在一线守, 中间是相, 就是和棋
	if(your_xiang_num == 2 && your_shi_num >= 1 && MY_SQ04 == yk){
		if(PB90(MY_SQ16) == your_xiang){
			//如果兵没有过河,也是和哇
			if(StoY(mpawn) MY_LARGE MY_RANK4){
				RETRUN_MUL(2);
			}

			//炮将在一线, 且炮保着自己的中仕
			if(m_have_bit(
				m_and(RankBB_A[MY_RANK0],bb_your_pao))){
					Bitboard peat = POSITION.Pao_Eat_bb(Square(MY_SQ0D));
					if(m_have_bit(
						m_and(peat,bb_your_pao))){
							RETRUN_MUL(2);
					}
			}
		}

		if(StoY(mpawn) != MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	

	// fen 4k1b2/4a4/3cb4/4P4/1c7/6B2/5R3/4B4/4A4/5K3 w - - 5 5
	

}

