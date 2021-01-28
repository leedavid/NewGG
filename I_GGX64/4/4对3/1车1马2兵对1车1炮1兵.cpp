#ifndef END_my_m_MT_R_1che1ma2pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1che1ma2pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1ma2pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);
	

	//如果炮方的兵不能过河,也要减分'
	// fen 6b2/4k4/9/p6C1/8r/5R3/P8/4B4/2n1A1p2/3A1KB2 w - - 7 7
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);

	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = true;
		}
	}

	// fen 3a1kb2/4a4/8b/5P3/P8/2R6/5N3/2p2A3/c4K3/2r6 b - - 0 1
	if (my_shi_num >= 1){
		if (isStringByChe(POSITION, mche, ypawn, yche) && StoY(yche) MY_LARGE StoY(mche)){
			if (StoY(ypawn) MY_LARGE_EQL MY_RANK6 && abs(StoX(ypawn) - StoX(mk)) >= 3){
				MY_EV_ADD(64);
				MY_EV_ADD(EV_MY_CAN * 64);
			}
		}
	}

	//  fen 3ak1b2/4a4/4b4/4R4/5r3/2P5P/4P4/4B1N2/2p1A1c2/3AK4 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9) {
		if (abs(StoX(ypawn) - 0x4) >= 2) {
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 2bk1a3/4a4/3rb4/P4P3/9/2R6/3p5/4B4/4A4/1cNAK1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(32);
			if(EV_YOUR_CAN){
				MY_EV_SUB(32);
			}
		}
		if(bit_is_set(EV_YOUR_XBIT,mma)){
			MY_EV_SUB(32);
		}		
	}

	// fen 2cakab2/9/4b4/9/9/r5P2/4R3P/B3B1N2/2p1A4/3AK4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoX(ypawn) < 0x4 && PB90(MY_SQ54) == my_shi){
			MY_EV_ADD(EV_MY_CAN * 8);
		}
		if(StoX(ypawn) > 0x4 && PB90(MY_SQ56) == my_shi){
			MY_EV_ADD(EV_MY_CAN * 8);
		}
	}
	if(ycan == 0){
	   MY_EV_ADD(32);
	}
	// fen R8/2cka4/b1r1b4/3P5/p3N4/9/P8/3AB4/4A4/4K4 w - - 0 0
	if(mcan <= 1 && (your_xiang_num == 2 && your_shi_num >= 1)){
		MY_EV_SUB(32);
	}

	// fen 3aka3/9/4b4/N5R2/2b6/P3c4/1r6P/4B4/2p1A4/3AK1B2 r
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 32);
		if(StoX(ypawn) < 0x4 && PB90(MY_SQ54) == my_shi){
			MY_EV_ADD(32);
		}
		if(StoX(ypawn) > 0x4 && PB90(MY_SQ56) == my_shi){
			MY_EV_ADD(32);
		}
	}

	// fen 2b1k1b2/4a3c/9/3PP4/5r2p/4R4/9/4N4/9/4K4 w - - 0 1
	if (abs(StoX(ypawn) - 0x4) >= 4){
		MY_EV_ADD(32);
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if (m_have_bit(lp)){
			MY_EV_ADD(32);
		}
	}

	// fen 3a1kb2/2N1a4/5c2b/P4R2p/8r/9/8P/4B4/9/3AKAB2 w - - 0 1
	if ((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0) {
		if (EV_MY_CAN <= 1) {
			MY_EV_SUB(64);
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])) {
				MY_EV_SUB(64);
			}
			MY_EV_SUB(count_1s(bb_my_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8])) * 64);
		}
	}

	// fen 2bak4/4a4/4b4/8R/2cNp4/6P2/4Pr3/4B4/4A4/2BAK4 w - - 4 4
    //如果多兵方的兵不能一上也能过河,也是和棋
	if(mcan == 0 && ycan == 0){
		if((my_shi_num + my_xiang_num) == 4 && (your_shi_num + your_xiang_num) == 4){
			RETRUN_MUL(4);
		}
	}

	// fen 2b1ka3/4a4/4b4/9/R2P2pc1/8P/3r5/4B3N/9/3AKAB2 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mma) MY_LARGE_EQL MY_RANK5){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
				MY_EV_SUB(32);
				//
				Bitboard x = m_and(ei.attacked_by(my_che),m_and(ei.attacked_by(your_che),ei.attacked_by(your_pao)));
				if(have_bit(x,bb_my_pawn)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	//fen 3ak1b2/4a4/4b4/9/1r4p2/2P1R3P/2N2c3/9/4A4/3AK1B2 w - - 0 1
	if ((my_shi_num + my_xiang_num) >= 3 && (your_shi_num + your_xiang_num) == 4){
		if (!have_bit(bb_your_pawn, MyLowBB[MY_RANK4])){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/R8/P5c1p/6N2/r7P/4B4/4A4/2BAK4 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if(EV_MY_CAN <= 1 && StoY(mma) MY_SMALL_EQL MY_RANK5){
				RETRUN_MUL(12);
			}
		}
	}
}

//void m_MT_B_1che1ma2pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	int rpao = PieceListStart(board,RPAO);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	//如果炮方的兵不能过河,也要减分'
//	// fen 6b2/4k4/9/p6C1/8r/5R3/P8/4B4/2n1A1p2/3A1KB2 w - - 7 7
//	Square rpawn = PieceListStart(board,RPAWN);
//	if(board->b256[rpawn - 0x20] == BPAWN || board->b256[rpawn - 0x30] == BPAWN){
//		board->mulScore -= 96;
//	}
//
//	//红方的炮在底线, 而且兵也在同一线,就不太好进攻
//
//	// fen 2bak4/4a4/4b4/8R/2cNp4/6P2/4Pr3/4B4/4A4/2BAK4 w - - 4 4
//    //如果多兵方的兵不能一上也能过河,也是和棋
//	if(rcan == 0 && bcan == 0){
//		if(board->B_shi == 2 && board->B_xiang == 2){
//			if(board->R_shi == 2 && board->R_xiang == 2){
//				return 4;
//			}
//		}
//	}
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//	
//
//	//// fen 1r2ka3/4n4/4ba2b/p3C4/3R5/P8/9/3K1A3/5p3/3A5 w - - 244 244
//	//if(board->B_shi == 2 && board->B_xiang == 2 && board->b256[0x47] == BMA){
//	//	if(IsStringByPao(board,rpao,0x47,bk)){
// //          if(board->b256[rpawn - 0x20] == BPAWN || board->b256[rpawn - 0x30] == BPAWN){
//	//		   if(StoY(bpawn1) >= 0x8 || StoY(bpawn2) >= 0x8){
//	//		   }
//	//	   }
//	//	}
//	//}
// //  
//
//
//	*/
//}