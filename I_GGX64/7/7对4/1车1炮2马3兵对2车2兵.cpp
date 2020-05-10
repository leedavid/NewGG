#ifndef END_my_m_MT_R_1che1pao2ma3pawn_B_2che2pawn
#define END_my_m_MT_R_1che1pao2ma3pawn_B_2che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮2马3兵对2车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao2ma3pawn_B_2che2pawn(typePOS &POSITION, EvalInfo &ei) {

	//Square yk = your_king_pos;
	//Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);

	//// fen 2bak4/4a4/4b4/1P7/8P/3p2P2/2r2n2N/R2CB4/4A1r2/2N1KAB2 w - - 0 1
	//if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
	//	if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])) {
	//		MY_EV_SUB(16);
	//	}
	//	if (StoY(ypawn) MY_LARGE_EQL MY_RANK5) {
	//		if (!have_bit(bb_my_ma, MyUpBB[MY_RANK4])) {
	//			MY_EV_SUB(16);
	//		}
	//	}
	//}

	//fen 2b1ka3/9/5a2b/p8/3Nr4/3p2P2/P7P/1r1C1R3/4A4/3AK1N2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2) {
		if (have_bit(bb_your_pawn, MyLowBB[MY_RANK4])) {
			MY_EV_SUB(32);
			if (my_xiang_num == 0) {
				MY_EV_SUB(32);
				if (!have_bit(bb_my_pawn, MyUpBB[0x5])) {
					MY_EV_SUB(32);
				}
			}
		}
	}

}



 //fen 2b1ka3/9/5a2b/p8/3Nr4/3p2P2/P7P/1r1C1R3/4A4/3AK1N2 w - - 0 1
 //r2b fen 2n1ka3/4a4/3r1c1R1/p7p/2p2P3/4Rn3/8P/B2A5/9/3AK1B2 b - - 0 1
 //mat: 400 ph: 102 mg: 87 eg: 88 rs: 82 bs: 0 mul: 16  eval: 160 <w>
 //rcan: 1 bcan: 1 rsafe: 0 bsafe: 0 
 //pawn: mv: -298 ev: -152 pcan w: 1 b: 1 patt w: -6 b: 8 pinfo 129 
 //AttW Che: 1 Ma: 1 Pao: 0 Pawn: 0 King: 0 attpw: 3 
 //AttB Che: 2 Ma: 0 Pao: 0 Pawn: 0 King: 1 attpb: 37