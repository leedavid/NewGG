#ifndef END_my_m_MT_R_1ma2pawn_B_1che
#define END_my_m_MT_R_1ma2pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马2兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



// void m_MT_B_1CHE_R_1MA(board_t *board);
// void my_m_MT_R_1CHE_B_1MA(board_t *board);
//我方一马一兵, 对方一车
void my_m_MT_R_1ma2pawn_B_1che(typePOS &POSITION, EvalInfo &ei){


	Square mk  = my_king_pos;
	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	MY_EV_SUB(128);  // 车方要加分

	//有一种和形
	// fen 4k4/9/4b4/4p4/2n4R1/9/9/9/9/4K4 w  例典: 一车例和马卒象 page
	// fen 4k4/9/9/4P4/9/1r4N2/4P4/4B4/9/4K4 w
	if(my_xiang_num >= 1){
		if(PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ43) == my_xiang && StoX(mk) == 0x4){
			if(PB90(MY_SQ2F) == my_ma || PB90(MY_SQ33) == my_ma){
				RETRUN_MUL(2);
			}			
			Bitboard matt = POSITION.ma_to_king_attacks_bb(mma);
			if(bit_is_set(matt,Square(MY_SQ2F)) || bit_is_set(matt,Square(MY_SQ33))){
				RETRUN_MUL(2);
			}
		}
	}

	if(your_shi_num == 2){
		EV_YOUR_SAFE = TRUE;
	}

    your_m_MT_R_1CHE_B_1MA(POSITION,ei);
	if(ei.mul <= 2){
		EV_MY_SAFE = TRUE;
	}
	//马方有二相,或二仕, 则马方如果在中线有连兵就是和了.
	// fen 1R1nk4/9/5a3/9/9/9/3pp4/9/4A4/3K1A3 w
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
		if(m_have_bit(m_and(lp,FileBB_A[0x4]))){
			if((my_shi_num == 2 || my_xiang_num == 2)){
				RETRUN_MUL(2);
			}
			if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
				RETRUN_MUL(2);
			}
		}
	}
	
	
	// fen 9/4a4/3kb4/6NP1/4P1b2/3r5/9/9/4K4/9 w - - 0 1
    if(PB90(MY_SQ28) == my_pawn){
		if(PB90(MY_SQ21) == my_ma){
			if(PB90(MY_SQ22) == my_pawn || PB90(MY_SQ23) == my_pawn){
				RETRUN_MUL(2);
			} 
		}
		if(PB90(MY_SQ1D) == my_ma){
			if(PB90(MY_SQ1B) == my_pawn || PB90(MY_SQ1C) == my_pawn){
				RETRUN_MUL(2);
			} 
		}
	}

	//fen 2b1k4/9/3a1a2b/2PPN4/2r6/9/9/9/4A4/4KA3 w - - 0 1
	if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if (have_bit(lp, RankBB_A[MY_RANK3])){
			if (MY_SQ1F == mma){
				RETRUN_MUL(2);
			}
		}
	}
    
	// fen 3ak4/9/3a2n1b/4p3p/1R7/9/9/B8/4A4/4KA3 w - - 0 0
	if(my_shi_num == 2 && my_xiang_num >= 1 && MY_SQ55 == mk){
		if(PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ36) == my_pawn && MY_SQ41 == mma){
			RETRUN_MUL(4);
		}
		if(PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ3E) == my_pawn && MY_SQ45 == mma){
			RETRUN_MUL(4);
		}
	}

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square yk = your_king_pos;

	// fen 5a3/5PP2/3k5/9/2b1r4/9/2N6/4B4/4A4/3AK1B2 w - - 194 194
	if(StoY(mpawn1) MY_SMALL StoY(yk) && StoY(mpawn2) MY_SMALL StoY(yk)){
		MY_EV_SUB(256);
	}
	// fen 5kb2/4a4/5a2b/3PPN3/9/9/6r2/9/9/4KA3 w - - 0 1
	if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if(bit_is_set(lp,Square(MY_SQ1F)) || bit_is_set(lp,Square(MY_SQ28))){
			RETRUN_MUL(4);
		}
	}

	//fen 2b1k4/9/3a1a2b/2PPN4/2r6/9/9/9/4A4/4KA3 w - - 0 1
	if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if (have_bit(lp, RankBB_A[MY_RANK3]) || have_bit(lp, RankBB_A[MY_RANK4])){
			RETRUN_MUL(8);
		}
	}
}

