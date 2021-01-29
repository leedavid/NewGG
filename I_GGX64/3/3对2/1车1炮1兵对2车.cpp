#ifndef END_my_m_MT_R_1che1pao1pawn_B_2che
#define END_my_m_MT_R_1che1pao1pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮1兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//#define ADD_车炮兵对二车_by_Pawn_Safe   32             //车炮兵对二车,炮方安全时兵的加分



//红方车炮1兵 对 黑方2车
void my_m_MT_R_1che1pao1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	your_m_MT_R_2CHE_B_1CHE1PAO(POSITION,ei);

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);
	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_车炮兵对二车_by_Pawn__Safe_Shi[your_shi_num]);

	if(ei.mul == 1){
		return;
	}

	// fen 2bakc3/5R3/4b4/9/3r5/4p4/R8/4B4/4A4/2BAK4 w - - 0 0</P>
    //也是和棋

	// fen 2bak4/4a4/4b4/4r4/4CP3/8R/4r4/9/4A4/3AK4 w - - 2 2
	//这个也是和棋
	if(my_shi_num == 2 && PB90(MY_SQ55) == my_king){
		if (StoY(mpao) MY_LARGE_EQL MY_RANK7){
			MY_EV_ADD(32);
			if (StoX(mpao) > 0x4 && PB90(MY_SQ56) != my_shi){
				MY_EV_ADD(32);
			}
			if (StoX(mpao) < 0x4 && PB90(MY_SQ54) != my_shi){
				MY_EV_ADD(32);
			}
			MY_EV_ADD(EV_MY_CAN * 32);
		}
		if(PB90(MY_SQ28) == my_pao && PB90(MY_SQ1F) == your_che){
			if(PB90(MY_SQ29) == my_pawn || PB90(MY_SQ27) == my_pawn){
				RETRUN_MUL(2);
			}
		} 
	}



	// fen 2c1ka3/4a4/9/9/3RR4/8r/8p/4B4/4A4/2BK1A3 w - - 0 0
	if(your_shi_num >= 1){
		EV_YOUR_SAFE = TRUE;
	}
	


	// fen 4ckb2/9/3a1a3/7R1/r5b2/9/7R1/B3B4/4K3p/9 w - - 116 116
	// fen 4ckb2/9/3a1a3/7R1/r5b2/9/7R1/B3B4/4K3p/9 w - - 116 116
	if(your_xiang_num == 2){
		if((StoX(mpawn) - 0x4) >= 3){
			EV_YOUR_SAFE = TRUE;
		}
		MY_EV_SUB(96);
	}

	// fen 3ak4/4a4/9/4R4/8R/5r3/4cp3/B2A5/9/3AK1B2 w - - 145 145
    // fen 3ak4/4a4/9/4R4/8R/5r3/4cp3/B2A5/9/3AK1B2 w - - 145 145
	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		EV_YOUR_SAFE = TRUE;
	}
	// fen 3k2b2/4a4/9/9/2b6/4P4/9/4BC2R/3r5/3AKA1r1 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && PB90(MY_SQ55) == my_king){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				if(StoX(mpao) > 0x4 && PB90(MY_SQ54) == my_shi){
					RETRUN_MUL(2);
				}
				if(StoX(mpao) < 0x4 && PB90(MY_SQ56) == my_shi){
					RETRUN_MUL(2);
				}
			}
		}	
	}

	// fen 3ak4/1c2ar3/2R1R4/9/9/7p1/9/3A5/9/2BAK1B2 w - - 35 35
	if(my_shi_num == 2 && PB90(MY_SQ55) == my_king && PB90(MY_SQ4C) == my_shi){
		Square sq = SQ_END90;
		if(PB90(MY_SQ56) == my_shi){
			sq = MY_SQ54;
		}
		if(PB90(MY_SQ54) == my_shi){
			sq = MY_SQ56;
		}
		if(sq != SQ_END90){
			if(PB90(sq) == my_che){
				RETRUN_MUL(4);
			}
			Bitboard rook = POSITION.Rook_attacks_bb(mche);
			if(bit_is_set(rook,sq)){
				RETRUN_MUL(4);
			}
		}
		RETRUN_MUL(8);
	}

	// fen 1R7/3k5/9/9/4r1r2/2P6/9/B2C5/4A4/2BK1A3 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_1che1pao1pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	int bpao    = PieceListStart(board,BPAO);
//	Square bpawn   = PieceListStart(board,BPAWN);
//
//	Square bk   = PieceListStart(board,BKING);
//	Square rk   = PieceListStart(board,RKING);
//	int bche = PieceListStart(board,BCHE);
//
//	int  mul  = m_MT_R_2CHE_B_1CHE1PAO(board);
//
//	for(int pawn = PieceListStart(board,BPAWN); pawn > 0x32; pawn = NextPiece(board,pawn)){
//		if(StoY(pawn) != 0xc){
//			board->mulScore -= ADD_车炮兵对二车_by_Pawn__Safe_Shi[board->R_shi];
//		}
//	}
//
//	if(mul <= 2){
//		return mul;
//	}
//
//	// fen 2bak4/4a4/4b4/4r4/4CP3/8R/4r4/9/4A4/3AK4 w - - 2 2
//	//这个也是和棋
//	if(board->B_shi == 2 && board->b256[0x37] == BKING){
//		if(board->b256[0x87] == BPAO && board->b256[0x97] == RCHE){
//			if(board->b256[0x86] == BPAWN || board->b256[0x88] == BPAWN){
//				return 1;
//			}
//		}
//	}
//
//	// fen 2c1ka3/4a4/9/9/3RR4/8r/8p/4B4/4A4/2BK1A3 w - - 0 0
//	if(board->R_shi != 0){
//		board->rsafe = TRUE;
//	}
//
//	if(board->B_shi == 2 && board->b256[0x37] == BKING){
//		if(board->b256[0x38] == BSHI && IsCheCanToOrAt(board,bpao,0x36)){
//			board->bsafe = TRUE;
//		}
//		if(board->b256[0x36] == BSHI && IsCheCanToOrAt(board,bpao,0x38)){
//			board->bsafe = TRUE;
//		}
//	}
//
//
//	// fen 4ckb2/9/3a1a3/7R1/r5b2/9/7R1/B3B4/4K3p/9 w - - 116 116
//	if(board->R_xiang == 2){
//		if(StoX(bpawn) == 0x3 || StoX(bpawn) == 0xb){
//			board->rsafe = TRUE;
//		}
//		board->mulScore += 128;
//	}
//
//	// fen 3ak4/4a4/9/4R4/8R/5r3/4cp3/B2A5/9/3AK1B2 w - - 145 145
//	if(board->R_shi >= 1 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//		board->rsafe = TRUE;
//	}
//
//	if(board->B_shi == 2 && board->b256[0x37] == BKING){
//		if(StoY(bpawn) == 0x8 || StoY(bpawn) == 0x9){
//			if(abs(StoX(bpawn) - 0x7) <= 1 && StoX(bche) == StoX(bpawn) 
//				&& StoY(bche) < StoY(bpawn)){
//					if(StoX(bpao) == 0x7 && StoY(bpao) == StoY(bpawn)){
//						board->bsafe = TRUE;
//					}
//			}
//		}
//	}
//
//	// fen 3ak4/1c2ar3/2R1R4/9/9/7p1/9/3A5/9/2BAK1B2 w - - 35 35
//	if(board->B_shi == 2 && board->rsafe == TRUE 
//		&& board->b256[0x37] == BKING && board->b256[0x47] == BSHI){
//			if(board->b256[0x38] == BSHI && LeftFirstSq256(board,0x47) == bche){
//				return 4;
//			}
//			if(board->b256[0x36] == BSHI && RightFirstSq256(board,0x47) == bche){
//				return 4;
//			}
//	}
//
//
//	// fen 4k1b2/9/b4a3/7P1/9/5C3/2r6/r8/4A4/1R2KA3 b - - 161 161
//	if(board->B_shi == 2 &&  board->b256[0x37] == BKING && board->b256[0x47] == BSHI){
//		if(StoY(bpawn) >= 0x8 && abs(StoX(bpao) - 0x7) <= 1 && StoY(bpao) <= 0x7){
//			return 4;
//		}
//	}
//
//
//  
//
//    */
//}