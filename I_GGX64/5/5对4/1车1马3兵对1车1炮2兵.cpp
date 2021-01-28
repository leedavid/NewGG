#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che1ma3pawn_B_1che1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1马3兵对1车1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1ma3pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1che2ma1pawn_1che1pao1ma_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1che2ma1pawn_1che1pao1ma_ByShi[my_shi_num]);

	// fen 3ak1b2/2c1a4/4b4/9/R2Np3P/2P6/1r2P4/4B4/3pA4/3AK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN <= 1){
			if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 16);
				//// 如果我方的将能动
				//print_bb(MY_SAFE_BIT); 
				//print_bb(ei.attacked_by(my_king));
				//if(have_bit(MY_SAFE_BIT,ei.attacked_by(my_king))){ 
				//   MY_EV_ADD(32);
				//}
			}
		}
	}

	//  fen 3ak1b2/2P1ac3/4b4/2R2N3/p3P3p/9/8P/4B4/4K4/3r5 b - - 0 1
	if (EV_YOUR_CAN <= 1) {
		if (!have_bit(bb_your_pawn, MyLowBB[MY_RANK4])) {
			MY_EV_ADD(32);
			if (count_1s(bb_your_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8])) == 2) {
				MY_EV_ADD(32);
				if (count_1s(bb_my_pawn, MyUpBB[MY_RANK4]) >= 2) {
					MY_EV_ADD(32);
				}
			}
		}
	}



	//m_and(ei.SafeBit[Us],ei.attacked_by(RKING + delt)));	
	// fen 2ba1k3/4a4/4b4/4p4/1P4n1p/1r2P4/2N1R3P/B8/9/3AKA3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
		}

		if(EV_YOUR_CAN <= 1){
			if(!have_bit(bb_your_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
			if(StoY(yche) MY_SMALL_EQL MY_RANK4 && StoY(mma) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
		}
	}

	// fen 2bak4/4a4/4bcr2/9/2p5R/6N2/P1P5P/4B1p1B/4A4/3AK4 w - - 0 1
	if (EV_MY_CAN >= 2 && EV_YOUR_CAN <= 1){
		if ((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * 8);
			if (StoY(mma) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(32);
			}
		}
	}
}