#ifndef END_my_m_MT_R_2che2pawn_B_2che1pawn
#define END_my_m_MT_R_2che2pawn_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车2兵对2车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2che2pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2CheXPawn_2Che1Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2CheXPawn_2Che1Pawn_ByShi[my_shi_num]);

	int mcan = EV_MY_CAN;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	// fen 3aka3/9/8R/3Rp4/9/P6p1/4r3r/4B4/4A4/4KAB2 w - - 4 4
	if(my_shi_num == 2 && mk == MY_SQ55){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(mcan * 16);
		}
	}

	// fen 3a1kb2/4a4/4b4/5r2p/P8/R5R2/5rP1P/4B4/4A4/4K1B2 w - - 11 11
	int ycan = EV_YOUR_CAN;
	//int mcan = My_pawn_can_over_river(POSITION);
	if(ycan == 0){
		if((my_shi_num + my_xiang_num) >= 3 && PB90(MY_SQ55) == my_king){
			Square mche1 = S90_from_piecelist(POSITION,my_che,0);
			Square mche2 = S90_from_piecelist(POSITION,my_che,1);			
			Bitboard rook = POSITION.Rook_attacks_bb(mche1);
			if(bit_is_set(rook,mche2)){
				MY_EV_ADD(96);
				MY_EV_ADD(mcan * 64);
			}
		}
	}

	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			EV_MY_SAFE = TRUE;
		}
	}

	if (my_shi_num == 2 && my_xiang_num >= 1 && MY_SQ55 == mk) {
		if (EV_YOUR_CAN == 0) {
			EV_MY_SAFE = TRUE;
		}
	}

    // fen 3ak1b2/4a4/4b4/R7p/4R4/9/P3P4/2r6/4A4/4KA2r b - - 0 1
	if (my_shi_num == 2 && MY_SQ55 == mk){
		if (abs(StoX(ypawn) - 0x4) == 0x4 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4ka3/9/b3ba3/4r4/4p4/2P3R2/9/4R4/4Arp2/2B1KA3 w - - 125 125
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && yk == MY_SQ04){
			if(PB90(MY_SQ31) == my_pawn && (PB90(MY_SQ3A) == my_che || PB90(MY_SQ43) == my_che)){
				Bitboard rook = POSITION.Rook_attacks_bb(Square(MY_SQ28));
				if(count_1s(rook,bb_your_che) == 2){ // 二个车封住了兵的前进之路
					// 找到过河兵.
					Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
					if(m_have_bit(ghp)){
						Square p = pop_1st_bit_sq(ghp);
						rook = POSITION.Rook_attacks_bb(p);
						if(count_1s(rook,
							m_or(bb_my_che,bb_your_che)) == 2){
								RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}

	// fen 2b1ka3/3Rar3/4b4/p6r1/8P/P8/9/4B4/4A4/2B1KA2R w - - 0 1

	// fen 4ka3/4a4/4b3r/6R1p/4R4/r5P1P/9/4B4/9/3AKA3 b - - 0 1 
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num >= 1 && yk == MY_SQ04) {
			if (EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK3])) {
				RETRUN_MUL(8);
			}
		}
	}
}

//void m_MT_B_2che2pawn_R_2che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int bche1 = PieceListStart(board,BCHE);
//	int bche2 = NextPiece(board,bche1);
//	int rche1 = PieceListStart(board,RCHE);
//	int rche2 = NextPiece(board,rche1);
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2CheXPawn_2Che1Pawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2CheXPawn_2Che1Pawn_ByShi[board->R_shi];
//		}
//	}
//
//
//    // fen 3aka3/9/8R/3Rp4/9/P6p1/4r3r/4B4/4A4/4KAB2 w - - 4 4
//	if(board->B_shi == 2 && bk == 0x37){
//		if(StoY(rpawn) >= 0x8){
//			board->mulScore -= bcan * 64;
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		if(StoY(rpawn) >= 0x8){
//			board->bsafe = TRUE;
//		}
//	}
//
//	// fen 4ka3/9/b3ba3/4r4/4p4/2P3R2/9/4R4/4Arp2/2B1KA3 w - - 125 125
//	if(board->bsafe == TRUE){
//		if(board->R_shi == 2 && board->R_xiang >= 1 && rk == 0xc7){
//			if(board->b256[0x77] == BPAWN){
//				if(StoX(bche1) == 0x7 || StoX(bche2) == 0x7){
//					if(StoX(rche1) == 0x7 || StoX(rche2) == 0x7){
//						if(StoY(rche1) == 0x8 || StoY(rche2) == 0x8){
//                            int p = bpawn1;
//							if(p == 0x77) p = bpawn2;
//							if(StoY(p) >= 0xb){
//								if((StoY(bche1) == StoY(p) && IsOnSameSide(bche1,p))
//									|| (StoY(bche2) == StoY(p) && IsOnSameSide(bche2,p))){
//										if(StoX(rche1) == StoX(p) || StoX(rche2) == StoX(p)){
//											return 4;
//										}
//								}									
//							
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	*/
//}