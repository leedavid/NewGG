#ifndef END_my_m_MT_R_1che1ma_B_2pao
#define END_my_m_MT_R_1che1ma_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//车炮对1马1炮

void my_m_MT_R_1che1ma_B_2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mche = S90_from_piecelist(POSITION,my_che,0);

	// fen 9/3Rak3/3cbacNb/9/9/9/9/3AB4/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(count_1s(bb_your_pao,MyUpBB[MY_RANK3]) == 2){
			if(StoX(mche) <= 0x4 && StoX(yk) >= 0x4){
				RETRUN_MUL(4);
			}
			if(StoX(mche) >= 0x4 && StoX(yk) <= 0x4){
				RETRUN_MUL(4);
			}
		}
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_1che1pao_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
//
//	//return 16;
//}