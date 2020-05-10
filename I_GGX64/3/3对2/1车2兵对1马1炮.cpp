#ifndef END_my_m_MT_R_1che2pawn_B_1pao1ma
#define END_my_m_MT_R_1che2pawn_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2兵对1马1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//#define ADD_ChePawn_To_MaPao_By_Panw   128              //车兵对马炮,车兵方兵要加分,因为马炮太难杀对方了
//#define ADD_ChePawn_To_MaPao_By_Che    128              //车兵对马炮,车兵方车要加分,因为马炮太难杀对方了

//我方1车1兵,对方是马炮
void my_m_MT_R_1che2pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePawn_To_MaPao_By_PawnByShi[your_shi_num]);

	MY_EV_ADD(ADD_ChePawn_To_MaPao_By_Che);
	Square mche = S90_from_piecelist(POSITION,my_che,0);

	// fen 3ak1b2/4a4/4b4/8P/3c1n3/9/P3p2R1/9/4A4/2B1KA3 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 32);

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	// fen 4ka3/9/5a3/9/2b3b2/1p3r3/9/4BAp2/1N2A4/1C2K1B2 b - - 83 83
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mche) == MY_RANK4 && !IsOnSameSide(mpawn1,mpawn2)){
			if(PB90(MY_SQ2B) == my_pawn && PB90(MY_SQ10) == your_ma
				&& PB90(MY_SQ07) == your_pao){
					RETRUN_MUL(4);
			} 
			if(PB90(MY_SQ25) == my_pawn && PB90(MY_SQ0A) == your_ma
				&& PB90(MY_SQ01) == your_pao){
					RETRUN_MUL(4);
			} 
		}
	}

}

