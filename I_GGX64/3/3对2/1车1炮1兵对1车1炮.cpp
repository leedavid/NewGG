#ifndef END_my_m_MT_R_1che1pao1pawn_B_1che1pao
#define END_my_m_MT_R_1che1pao1pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_ChePao_ByPawnByShi[your_shi_num]);

	if((my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD(ADD_ChePaoPawn_ChePao_ByShiXiang);
	}

	//Square yk    = your_king_pos;
	int mcan = EV_MY_CAN;
	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	//Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);

	// fen 9/3kaPC2/b4a3/3c2r2/9/5R3/9/4BA3/4K4/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2 && StoY(ypao) MY_SMALL_EQL MY_RANK4){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 4kab2/4a4/9/9/4r1p2/4c3R/9/3CB3B/4A4/3K1A3 b - - 0 1
	if ((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
	}

	if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
		MY_EV_SUB(64);
	}


	if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		if(your_shi_num == 2 && your_xiang_num >= 1 && !IsOnSameSide(mpawn,yk)){
			MY_EV_SUB(32);
			if(StoY(ypao) MY_SMALL_EQL MY_RANK3){
				MY_EV_SUB(32);
			}
		}
	}

	if((my_shi_num + my_xiang_num) == 0){
		if((your_shi_num + your_xiang_num) >= 3){
			if(isStringByChe(POSITION,mche,mpao,yche)){
				MY_EV_SUB(168);
			}
		}
		// fen 4k4/9/3R5/6C2/8p/1r2c4/1p7/4B4/9/3AKAB2 w - - 0 0
		if((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk){
			MY_EV_SUB(80);
		}
	}
	// fen 1Ccak1b2/1P1ra4/4b4/9/1R7/9/9/4BA3/9/3AK1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
		MY_EV_SUB(64);
	}

	//  fen 9/5k3/3c1a2b/4R4/5rb2/P8/9/9/6C2/4K4 b - - 0 1
	if (EV_MY_CAN >= 1 && your_shi_num <= 1) {
		MY_EV_ADD(32);
		if (StoY(mpao) MY_LARGE StoY(mche)) {
			MY_EV_ADD(32);
			if (StoY(mche) MY_LARGE_EQL MY_RANK3 && StoY(mche) MY_SMALL_EQL MY_RANK6) {
				MY_EV_ADD(32);
			}
		}
	}


	// fen 3rkab2/4a4/4b4/R8/4C1p2/9/9/4B4/1c2A4/4KA3 b - - 0 0
    //1,铁门栓, 2, 兵不能过河, 3, 
	if((your_shi_num + your_xiang_num) >= 3 && mcan == 0){
		if(isStringByPao(POSITION,ypao,Square(MY_SQ4C),Square(MY_SQ55))){
			if(StoY(mche) == MY_RANK9){
				RETRUN_MUL(4);
			}
		}
	}
	
	// fen 9/4a4/4k4/4r4/9/2R1p1B1c/9/9/4A3C/3AK1B2 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}

	// fen 3ak4/4a4/1c2b4/4r4/9/4C4/4P4/3ABR2B/4A4/5K3 w - - 128 128
	if((your_shi_num + your_xiang_num) >= 3){
		if(PB90(MY_SQ31) == my_pao && PB90(MY_SQ3A) == my_pawn){
			if(MY_SQ1F == yche || MY_SQ28 == yche){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a4/b7b/4R4/4c2r1/9/7C1/4p4/4A4/3AK4 b - - 151 151
	if(your_shi_num == 2 && MY_SQ04 == yk){
		if(MY_SQ16 == mpawn && StoX(mpao) == 0x4){
			if(isStringByChe(POSITION,yche,mpao,mpawn)){
				if(StoX(ypao) == StoX(mche) && StoY(ypao) MY_SMALL StoY(mche)){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4ka3/4aP3/4b4/R3C4/6b1c/9/3r5/3AB4/4A4/2B2K3 b - - 0 113
	if((your_shi_num + your_xiang_num) == 4 && yk == MY_SQ04){
		MY_EV_SUB(64);

		// 1r1aka3/9/9/9/9/9/9/4B4/1p1RA4/1cCAK1B2 b - - 0 112
		if(bit_is_set(ei.attacked_by(your_che),mpawn) && bit_is_set(ei.attacked_by(my_che),mpawn)){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3ak4/2c1a1PR1/4b4/9/5r3/2B6/9/4C4/9/3AKAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		// fen 3ak4/2c1a1PR1/4b4/9/5r3/2B6/9/4C4/9/3AKAB2 w - - 0 1
		if(StoY(ypao) == StoY(mche) && !IsOnSameSide(ypao,mpawn)){
			if(isStringByPao(POSITION,ypao,mpawn,mche)){
				if(StoY(mpao) != MY_RANK0){
					if(StoX(mpawn) >= 0x6 && StoX(yche) == 0x5){
						RETRUN_MUL(4);
					}
					if(StoX(mpawn) <= 0x2 && StoX(yche) == 0x3){
						RETRUN_MUL(4);
					}
				}
			}
		}
		// fen 3ak4/2c1a1PR1/4b4/9/5r3/2B6/9/4C4/9/3AKAB2 w - - 0 1
		if(StoY(mpawn) == MY_RANK1 && StoY(mche) == MY_RANK0 && StoX(mche) == StoX(mpawn)){
		    if(abs(StoX(mpawn) - 0x4) >= 2){
				if(bit_is_set(ei.attacked_by(your_pao),mpawn)){
					if(StoY(mpao) == MY_RANK0 && IsOnSameSide(mche,mpao)){
					}
					else{
						RETRUN_MUL(4);
					}

				}
			}
		}
	}//
	

	
   

	// fen fen 4k4/1CP1a4/3a5/1r6c/9/2B5R/9/9/4K4/9 b - - 0 1
	//if(your_shi_num == 2 && StoY(yk) == MY_RANK0 && abs(StoX(mpawn) - StoX(yk)) >= 2){
	//	if(StoY(mche) MY_LARGE_EQL MY_RANK5){
	//		if(StoY(mpawn) == MY_RANK1 && StoY(mpao) == StoY(mpawn)){
	//			if(bit_is_set(ei.pi->pawnshi_attacks(MY_COLOR),mpao)){
	//				if(StoX(yche) == StoX(mpao) && StoY(yche) != MY_RANK0){
	//					RETRUN_MUL(8);
	//				}
	//			}
	//		}
	//	}
	//}

	// fen 4k4/9/9/3R5/4r1c2/P8/9/5C3/9/3K5 w - - 0 1
	if(StoX(yche) == 0x4 && (my_shi_num + my_xiang_num) == 0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(StoY(yche) == MY_RANK4 && StoY(ypao) == MY_RANK4){
				if(StoX(mpawn) < 0x4 && StoX(ypao) > 0x4){
					RETRUN_MUL(8);
				}
				if(StoX(mpawn) > 0x4 && StoX(ypao) < 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3ak4/2c1a1PR1/4b4/9/5r3/2B6/9/4C4/9/3AKAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(StoY(mpawn) == MY_RANK1 && abs(StoX(mpawn) - 0x4) >= 1){
			if(bit_is_set(ei.attacked_by(your_pao),mpawn) && StoY(mpao) == MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}


	// fen 4k4/4a3P/3ab4/8R/9/4rC3/7c1/3AB4/9/2BAK4 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if((your_shi_num + your_xiang_num) >= 3 && MY_SQ04 == yk){
			if(!bit_is_set(EV_MY_XBIT,yche)){
				if(abs(StoX(mpawn) - 0x4) == 4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 1Ccak1b2/1P1ra4/4b4/9/1R7/9/9/4BA3/9/3AK1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) >= 3 && StoX(mpawn) == StoX(mche)){
			if(bit_is_set(ei.attacked_by(my_che),mpawn) && bit_is_set(ei.attacked_by(your_che),mpawn)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/3cak3/8b/9/6b2/4Cr3/4P2R1/9/9/4K4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 2){
		if(PB90(MY_SQ3A) == my_pawn && MY_SQ31 == mpao){
			if((my_shi_num + my_xiang_num) <= 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/3kaPC2/b4a3/3c2r2/9/5R3/9/4BA3/4K4/9 w - - 0 1
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(yk,mpawn)){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(abs(StoX(yk) - StoX(mpawn)) >= 2){
				if(StoY(ypao) MY_SMALL_EQL MY_RANK3 && StoY(yche) MY_SMALL_EQL MY_RANK3){
					if(StoX(ypao) == StoX(yk)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 5a3/4a2C1/b2k5/4PR3/2br5/6B2/3c5/9/9/5KB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		RETRUN_MUL(8);
	}

	// fen 9/3P1k1c1/4ba3/9/2b6/5r3/3R5/4BC3/4A4/3K1AB2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK3){
				if(bit_is_set(ei.attacked_by(your_pao),mpawn) 
					&& bit_is_set(ei.attacked_by(my_che),mpawn)){
						RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4ka3/2P1aR3/4b4/6c2/3r5/2B6/4C4/9/4A4/2BAK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK4 && StoY(yche) MY_SMALL_EQL MY_RANK4){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(12);
			}
			if(StoY(mpao) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(12);
			}
		}
	}
}

//void m_MT_B_1che1pao1pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int bcan = BpawnCanOverLiver(board);
//
//	int rche = PieceListStart(board,RCHE);
//	int bche = PieceListStart(board,BCHE);
//
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	int rpao = PieceListStart(board,RPAO);
//	int bpao = PieceListStart(board,BPAO);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoPawn_ChePao_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	if((board->B_shi + board->B_xiang) != 0){
//		board->mulScore -= ADD_ChePaoPawn_ChePao_ByShiXiang;
//	}
//
//	// fen 3rkab2/4a4/4b4/R8/4C1p2/9/9/4B4/1c2A4/4KA3 b - - 0 0
//    //1,铁门栓, 2, 兵不能过河, 3, 
//	if((board->R_shi+board->R_xiang) >= 3 && bcan == 0){
//		if(Is_RhaveTianMenShuanCanControl_Bking(board) && StoY(bche) == 0x3){
//			if(board->b256[0x36] != BSHI && StoX(bche) < 0x7 && StoX(rche) < 0x7){
//				return 4;
//			}
//			if(board->b256[0x38] != BSHI && StoX(bche) > 0x7 && StoX(rche) > 0x7){
//				return 4;
//			}
//		}
//	}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		board->mulScore /= 2;
//		return 4;
//	}
//
//	// fen 3ak4/4a4/1c2b4/4r4/9/4C4/4P4/3ABR2B/4A4/5K3 w - - 128 128
//	if((board->R_shi+board->R_xiang) >= 3 && (board->R_shi+board->R_xiang) >= 3){
//		if(StoY(rk) >= 0xb && StoY(bk) <= 0x4){
//			if(board->b256[0x67] == BPAWN && board->b256[0x77] == BPAO){
//				if(board->b256[0x87] == RCHE || board->b256[0x97] == RCHE){
//					return 4;
//				}
//			}
//		}
//	}
//
//	// fen 4k4/4a4/b7b/4R4/4c2r1/9/7C1/4p4/4A4/3AK4 b - - 151 151
//	if(board->R_shi == 2 && rk == 0xc7){
//		if(board->b256[0xa7] == BPAWN && StoX(bpao) == 0x7){
//			if(IsStringByChe(board,rche,bpao,bpawn)){
//				if(StoY(bche) == StoY(bpao)){
//					if(StoX(rpao) == StoX(bche) && StoY(rpao) > StoY(bche)){
//						return 4;
//					}
//				}
//			}
//		}
//	}
//
//	*/
//}
