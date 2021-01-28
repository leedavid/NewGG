#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che1pao
#define END_my_m_MT_R_1che1pao2pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao2pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){


	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_ChePao_ByPawnByShi[your_shi_num]);

	if((my_shi_num + my_xiang_num) >= 1){
	  MY_EV_ADD(ADD_ChePaoPawn_ChePao_ByShiXiang);
	}

	int mcan = EV_MY_CAN;

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
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

	// fen 4kab2/4a4/4b4/5R3/2c1r2PP/9/9/5C3/5K3/9 w - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if (have_bit(lp, MyLowBB[MY_RANK1])){
		MY_EV_ADD(64);
		// fen 4kab2/4a4/4b4/5R3/2c1r2PP/9/9/5C3/5K3/9 w - - 0 1
		if ((my_shi_num + my_xiang_num) <= 1){
			if (isStringByChe(POSITION, mk, mpao, mche)){
				MY_EV_ADD(64);
			}
		}
	}



	// fen 2bcka3/4a4/8b/rC3R3/2p6/9/9/4B4/4A1p2/2BA1K3 b - - 120 120
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			if(isStringByChe(POSITION,mche,ypao,yche)){
				if(StoX(mche) == 0x0 && StoX(ypao) == 0x1){
					RETRUN_MUL(8);
				}
				if(StoX(mche) == 0x8 && StoX(ypao) == 0x7){
					RETRUN_MUL(8);
				}
			}
		}
	}

    //兵方的车给压在边上
	// fen 3ak1b2/4a4/3cb4/5RP2/4r4/4C4/4P4/B8/9/5K3 w - - 0 122
	if(your_shi_num == 2 && your_xiang_num == 2 && yk == MY_SQ04){
		Bitboard p = m_and(bb_my_pawn, MyLowBB[MY_RANK2]);
		if(count_1s(p) == 2){
			MY_EV_SUB(96);
		}
	}
	// fen 2bak4/4a4/4b4/9/9/4P4/P7R/5C3/6r2/3AK2c1 w - - 0 1
	if(StoY(ypao) == MY_RANK2 && abs(StoX(ypao) - 0x4) <= 1){
	}
	else{
		MY_EV_ADD(EV_MY_CAN * 16);
		if(have_bit(bb_my_pawn,m_and(LeftBB[0x5],RightBB[0x3]))){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
	// fen 5ab2/4k4/4ba3/9/3R4C/P8/4r3P/9/3K5/7c1 b - - 0 1
	if(StoY(yk) != MY_RANK0){
		MY_EV_ADD(EV_MY_CAN * 32);

		if(EV_MY_CAN == 2){
			MY_EV_ADD(32);
		}
	}
	if(StoX(mche) == StoX(mk) && StoY(mche) MY_SMALL_EQL StoY(mk)){
		MY_EV_ADD(EV_MY_CAN * 16);
	}




}

//void m_MT_B_1che1pao2pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_ChePaoPawn_ChePao_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	if((board->B_shi + board->B_xiang) != 0){
//		board->mulScore -= ADD_ChePaoPawn_ChePao_ByShiXiang;
//	}
//
//	int rche = PieceListStart(board,RCHE);
//	int rpao = PieceListStart(board,RPAO);
//	int bche = PieceListStart(board,BCHE);
//
//	int bcan = BpawnCanOverLiver(board);
//
//
//	// fen 2bcka3/4a4/8b/rC3R3/2p6/9/9/4B4/4A1p2/2BA1K3 b - - 120 120
//    //兵方的车给压在边上
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			if(IsStringByChe(board,rche,rpao,bche)){
//				if(bcan <= 1){
//					if(StoX(bche) == 0x3 && StoX(rpao) == 0x4){
//						return 8;
//					}
//					if(StoX(bche) == 0xb && StoX(rpao) == 0xa){
//						return 8;
//					}
//				}
//			}
//		}
//	}
//
//
//
//	*/
//}
