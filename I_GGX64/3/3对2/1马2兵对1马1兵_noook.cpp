#ifndef END_my_m_MT_R_1ma2pawn_B_1ma1pawn_s
#define END_my_m_MT_R_1ma2pawn_B_1ma1pawn_s
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对1马1兵_noook.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//
//const int PawnNotSameSide = 64;         //二兵方的兵不在一边,要加分

void my_m_MT_R_1ma2pawn_B_1ma1pawn(typePOS *POSITION, EvalInfo *ei){

	// ADD
	Bitboard bmp = m128_bb_and_bb(bitboard_my_pawn,MyLowBB[StoY(your_king_pos)]);
	int pmok = count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_MaPawnByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m128_bb_and_bb(bitboard_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = count_1s(ymp);
	MY_EV_SUB(pyok * ADD_MaPawn_To_MaPawnByShi[my_shi_num]);

	int mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	int mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	int ypawn  = S90_from_piecelist(POSITION,your_pawn,0);

	//兵在二边,得加分
	//fen 3k5/9/2P3P2/9/9/6n2/3N5/5p3/9/4K4 w
	if(!IsOnSameSide(mpawn1,mpawn2)){
		MY_EV_ADD(64);
	}
	int mma = S90_from_piecelist(POSITION,my_ma,0);
	int yma = S90_from_piecelist(POSITION,your_ma,0);
	int mcan = My_pawn_can_over_river(POSITION);
	int ycan = Your_pawn_can_over_river(POSITION);
	int yk = your_king_pos;

	//fen 2ba2bn1/2P2k1N1/5a3/2p3p2/9/9/9/9/4K4/2B3B2 w - - 0 0
    //底兵搜山，全吃光
	if(StoY(mma) == MY_RANK9 && PB90[mma MY_SUB 0x9] == your_ma){
		if(mcan == 0 && ycan >= 1){
			MY_EV_SUB(168);
		}
	}
	if(my_shi_num >= 1 || StoY(ypawn) MY_SMALL_EQL MY_RANK4){
		EV_MY_SAFE = TRUE;
	}
	// 黑马可守着两边下兵
	if(MY_SQ1F == yma && your_shi_num >= 1){
        MY_EV_SUB(80);
	}

	//fen 5kb2/4a1PP1/4b4/9/4N4/5nB2/9/3KB4/4Ap3/5A3 w - - 3 3
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){ //二个兵到了底线
		   if(IsOnSameSide(mpawn1,mpawn2)){
			   RETRUN_MUL(2);
		   }	
		}
	}

	/*

	//fen 4k1P2/4a2P1/3a5/9/5N3/5nB2/9/3KB4/4Ap3/5A3 b - - 0 0 如果有一个兵到了底线
	if(board->B_shi == 2){
		if(StoY(rpawn1) == 0x3 || StoY(rpawn2) == 0x3){
			if(FALSE){
			}
			else if(StoX(rpawn1) > 0x7 && StoX(rpawn2) > 0x7 ){
				return 1;
			}
			else if(StoX(rpawn1) < 0x7 && StoX(rpawn2) < 0x7){
				return 1;
			}
		}
	}




	//如果红方的可过河兵==0; 
	//int rcan = rcan;
	if(rcan == 0){
		//fen 4k4/9/5a3/3N5/p2n5/9/P8/5K3/4p4/2B6 w - - 0 0
		if((board->B_shi + board->B_xiang) >= 1){
			board->mulScore /= 4;
			return 1;
		}
	}

	//fen 2bak4/4a4/9/2P6/2p6/1N2n4/2P6/3AB4/4A4/2BK5 w - - 4 4
	if(board->B_shi == 2 && board->B_xiang >= 1 && StoY(bk) == 0x3){
		if(board->b256[bpawn + 0x20] == RPAWN || board->b256[bpawn + 0x30] == RPAWN){
			return 1;
		}
	}


	//***********************************
	//fen 5P3/5P3/5k3/6N2/9/9/9/B2n5/9/p3K4 w - - 88 88
	//双方都是低兵了
	if(StoY(bpawn) == 0xc){
		board->rsafe = TRUE;
	}
	if(StoY(bpawn) >= StoY(rk)){
		board->rsafe = TRUE;
	}

	if(StoY(rpawn1) < StoY(bk) && StoY(rpawn2) < StoY(bk)){
		if(StoY(rpawn1) == 0x3){
			board->bsafe = TRUE;
		}
		if(StoY(rpawn2) == 0x3){
			board->bsafe = TRUE;
		}
	}
    //fen 3k5/4a4/5aP2/p8/9/Pn7/1N7/3AB4/4K4/3A5 w - - 30 30
	if(board->B_shi == 2 && StoY(bk) <= 0x4){
		if(board->b256[bpawn + 0x20] == RPAWN || board->b256[bpawn + 0x30] == RPAWN){
			if(StoY(rpawn1) <= 0x5 || StoY(rpawn2) <= 0x5){ //另一个兵以了相线
				//if(StoY(bma) > 0x5 && IsMaCanToOrAt(board,bma,bpawn)){
				//if(StoY(bma) > 0x5 ){
				if(ABS(StoX(bma) - StoX(bpawn)) <= 2){
					return 4;
				}
			}
		}
	}



	//***********************************
	//fen 3ak4/9/5a3/p8/2b3n2/P4NB2/4P4/4B4/4A4/3AK4 w - - 0 
	if(board->B_shi == 2 && board->B_xiang >= 1 && StoY(bk) == 0x3){
		if(board->b256[bpawn + 0x20] == RPAWN || board->b256[bpawn + 0x30] == RPAWN){
			if(RpawnAlreadyRiver(board) == 0){
				return 4;
			}
		}
	}

	//fen 2bk5/9/3a1a3/4P4/2b6/9/4n4/B1p1N1p1B/4A4/5K3 w - - 120 120
	if((board->B_shi + board->B_xiang) >= 3 && StoY(bk) == 0x3){
		if(StoY(bpawn) >= 0x8 && StoY(bpawn) <= 0x9 && StoY(bma) <= 0x7 && StoY(bma) >= 0x5){
			if(ABS(StoX(rpawn1) - 0x7) >= 2 && ABS(StoX(rpawn2) - 0x7) >= 2){
				return 4;
			}
		}
	}	

	//fen 9/4k1P2/3P4b/9/2b6/2Bn5/N8/8B/4p4/3K5 w - - 67 67
	if(board->R_shi == 0 && board->b256[0xb7] == BPAWN && StoY(rk) == 0xc){
		if(StoY(bma) >= 0x8){
			if(StoY(bk) >= StoY(rpawn1) || StoY(bk) >= StoY(rpawn2)){
				if(!IsOnSameSide(rpawn1,rpawn2) && StoY(bk) != 0x3 && board->B_xiang >= 1){
					board->mulScore -= 256;
				}
			}
		}
	}

	//fen 4ka3/4a4/4b4/2P1N3p/9/9/P7n/4B4/4A4/4K1B2 w - - 0 0
	if(board->rsafe == TRUE){
		if(board->B_shi == 2 && board->B_xiang >= 1){
			if(bcan >= 1){
				if(StoY(rpawn1) >= 0x5 && StoY(rpawn2) >= 0x5 && StoY(bk) <= 0x4){
					//board->mulScore -= 80;
					return 4;
				}
			}
		}
	}

	//5ab2/3k5/2Na5/p8/2b6/PnB6/3p5/9/4A4/5K3 w - - 120 120
	if(board->B_shi >= 1 && board->B_xiang >= 1 && StoY(bk) <= 0x4 ){
		if(StoY(rpawn1) <= 0x6 || StoY(rpawn2) <= 0x6){
			if(board->b256[0x73] == BPAWN && board->b256[0x93] == RPAWN){
				if(IsMaCanToOrAt(board,rma,0x93) && IsMaCanToOrAt(board,bma,0x93)){
					return 4;
				}				
			}
			if(board->b256[0x7b] == BPAWN && board->b256[0x9b] == RPAWN){
				if(IsMaCanToOrAt(board,rma,0x9b) && IsMaCanToOrAt(board,bma,0x9b)){
					return 4;
				}				
			}
		}
	}

	
	//9/4k1P2/3P4b/9/2b6/2Bn5/N8/8B/4p4/3K5 w - - 67 67
	if(board->B_shi >= 1 && board->B_xiang == 2 && StoY(bpawn) >= 0x8){
		if(rcan <= 1){
			return 8;
		}
	}

	if(board->B_shi == 2){
		return 8;
	}


 
	return 16;/*/
}


