#ifndef END_my_m_MT_R_2pao_1pawn_B_1che
#define END_my_m_MT_R_2pao_1pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao_1pawn_B_1che(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_To_1Che_PawnByShi[your_shi_num]);

	Square mk = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(my_shi_num == 2){
			EV_MY_SAFE = TRUE;
		}
		if(my_xiang_num == 2){
			EV_MY_SAFE = TRUE;
		}
	}

	if(PB90(MY_SQ55) == my_king){
		if(my_shi_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}

	//黑方车方有三个以上的东东
	if((your_shi_num + your_xiang_num) >= 3){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 2bk5/9/9/7P1/3C1rb2/9/9/3A5/9/3KC4 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){
		MY_EV_SUB(64);
	}
	// fen 2b2ab2/2P1a4/5k3/3r5/9/3C5/9/9/3K5/3C5 b - - 0 1
	//if(EV_YOUR_SAFE){
		if(StoY(mk) != MY_RANK9){
			if(PB90(XYtoS(StoX(mk),MY_RANK9)) == my_pao){
				MY_EV_SUB(64);
				Bitboard mp = m_and(POSITION.Rook_attacks_bb(mk),
					m_and(FileBB_A[StoX(mk)],bb_my_pao));
				if(count_1s(mp) == 2){
					RETRUN_MUL(2);
				}
			}
		}
	//}

	// fen 5a3/3P5/b2abk3/9/9/3r5/3C5/3K5/9/3C5 w - - 0 1
	if(PB90(XYtoS(StoX(mk),MY_RANK9)) == my_pao && PB90(XYtoS(StoX(mk),MY_RANK7)) != my_pao
		&& count_1s(bb_my_pao,FileBB_A[StoX(mk)]) == 2){
        RETRUN_MUL(4);
	}

	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0 && PB90(MY_SQ0D) != my_pawn){
			RETRUN_MUL(4);
		}
		if(StoY(mpawn) == MY_RANK0 && StoY(yk) != MY_RANK0){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4a4/1P3a3/9/9/8C/6r2/9/4A4/3CKA3 r
	if(EV_MY_SAFE){
		if(my_xiang_num <= 1){
			if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}
}


//void m_MT_B_2pao_1pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_To_1Che_PawnByShi[board->R_shi];
//		}
//	}
//
//	if(StoY(bk) == 0x3){
//		if(board->B_shi == 2){
//			board->bsafe = TRUE;
//		}
//		if(board->B_xiang == 2){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if(board->b256[0x37] == BKING){
//		if(board->B_shi != 0){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if((board->R_shi+board->R_xiang) >= 3){
//		board->rsafe = TRUE;
//	}
//
//
//	*/
//}
