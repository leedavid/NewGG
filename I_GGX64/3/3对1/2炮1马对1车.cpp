#ifndef END_my_m_MT_R_2pao_1ma_B_1che
#define END_my_m_MT_R_2pao_1ma_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2炮1马对1车, 炮马方要加分

void my_m_MT_R_2pao_1ma_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	if((my_shi_num + my_xiang_num) >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(Add_2炮1马对1车);
	}


	// fen 3k1ab2/4a4/9/9/8C/9/6r2/9/4C4/3NKA3 b - - 0 1
	if(my_shi_num <= 1 && my_xiang_num == 0){
		MY_EV_SUB(64);
	}

	// fen 5k3/4a4/8b/5N3/2bN1r3/5C3/9/B3B4/9/4K4 w - - 0 1
	if(count_1s(ei.attacked_by(your_che),bb_my_ma) == 2){
		MY_EV_SUB(64);
	}
	if((my_shi_num + my_xiang_num) <= 2){
		MY_EV_SUB(64);
	}
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(64);
	}

	// fen 2ba2N1C/5k3/2Ca5/1r7/9/9/9/9/9/4K4 b - - 0 1
	if((my_shi_num + my_xiang_num) == 0){
		if(!have_bit(bb_my_pao,MyLowBB[MY_RANK6])){
			MY_EV_SUB(96);
		}
	}

	if((your_shi_num + your_xiang_num) == 4){
		MY_EV_SUB(128);
		RETRUN_MUL(8);
	}
	//如果车方是仕相全,也是和棋


}


//void m_MT_B_2pao_1ma_R_1che(typePOS &POSITION, EvalInfo &ei){
//
//	/*board->mulScore -= Add_2炮1马对1车;
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		board->mulScore /= 8;
//		return 8;
//	}
//
//	*/
//}
