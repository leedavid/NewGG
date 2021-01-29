#ifndef END_my_m_MT_R_1che2pao_B_1che1pao1pawn
#define END_my_m_MT_R_1che2pao_B_1che1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮对1车1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int  AD_Che_CanNotMove = 256;

void my_m_MT_R_1che2pao_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	//Square mche = S90_from_piecelist(POSITION,my_che,0);

	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[my_shi_num]);

	// fen 3k5/3ca4/4b3b/8C/3R5/9/9/3CB4/3r3p1/4K4 b - - 0 1
   if(my_shi_num == 0 && StoY(mk) == MY_RANK9 && StoY(ypawn) == MY_RANK8){
	   if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		   if(StoY(yche) == MY_RANK8){
			   Bitboard p = m_and(FileBB_A[StoX(yche)],m_and(ei.attacked_by(your_che),
				   ei.attacked_by(my_che)));
			   if(have_bit(p,bb_my_pao)){
				   MY_EV_SUB(64);
			   }
		   }
	   }
   }
}

