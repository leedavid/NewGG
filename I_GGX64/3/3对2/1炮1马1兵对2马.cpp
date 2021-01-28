#ifndef END_my_m_MT_R_1ma1pao1pawn_B_2ma
#define END_my_m_MT_R_1ma1pao1pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马1兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//马炮兵对二马, 二马方不可能胜

//const int reg_2Ma_2Shi_2Xiang = 96;

void my_m_MT_R_1ma1pao1pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_2Ma_ByPawnShi[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	MY_EV_ADD(64);

	// fen 3k5/2P6/3aba3/7NC/4n1b1n/9/9/B2AB4/4AK3/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_your_ma,MyLowBB[MY_RANK6])){
			if(PB90(MY_SQ28) == your_ma){
				MY_EV_SUB(16);
			}
			if(abs(StoX(mpawn) - 0x4) >= 2){
				MY_EV_SUB(16);
			} 
		}
	}

	//fen 4k3C/4a4/3aP3b/9/1N7/9/3n5/B1n6/3K5/2B6 b - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0 && your_xiang_num >= 1){
		if (MY_SQ16 == mpawn){
			MY_EV_SUB(64);
		}
	}

	// fen 2P6/5kN2/9/9/9/6B2/n2n5/4B4/3K5/8C w - - 21 e21
	if(my_shi_num == 0 && StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(2);
	}

	// fen 2ba5/3Pak3/b3Cn3/9/5N3/9/3n5/B4A3/4A4/2BK5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(PB90(MY_SQ16) == my_pao){
			if(MY_SQ0C == mpawn && PB90(MY_SQ17) == your_ma){
				RETRUN_MUL(4);
			}
			if(MY_SQ0E == mpawn && PB90(MY_SQ15) == your_ma){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a1P2/1n2ba3/1N4n2/9/2B6/9/3AB4/4C4/3K5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && abs(StoX(mpawn) - 0x4) >= 2){
			if(!have_bit(bb_your_ma,MyLowBB[MY_RANK6])){
			    RETRUN_MUL(4);
			}
		}
	}

	// fen 2b2k3/5c3/3a5/7N1/6b1p/2B6/5nN2/3A5/4A4/4K1B2 w - - 144 144
    //对方是仕相全, 且兵没有过河, 也是基本和棋
	if((your_shi_num + your_xiang_num) == 4){
		// fen 2b2k3/2N1a1P2/4ba3/9/9/5n3/3n5/B2AB4/4A4/4KC3 b - - 0 1
		if(StoY(yk) == MY_RANK0){
			MY_EV_SUB(16);
		}
		if(abs(StoX(mpawn) - 0x4) >= 2){
			MY_EV_SUB(16);
			// fen 5kb2/2P1a4/5a2b/4n2N1/9/5n3/9/9/4A4/3AKC3 w - - 0 1
			if(!IsOnSameSide(mpawn,yk)){
				MY_EV_SUB(16);
			}
		}

		if(StoY(yk) == MY_RANK0 && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(4);
		}
		// fen 2b1k4/4anN2/4ba3/3P5/9/3n1CB2/9/4B4/4A4/3A1K3 b - - 0 1
		if(StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(16);
			}
		}
	}

	if(StoY(mpawn) MY_LARGE_EQL MY_RANK1){
		if(my_shi_num >= 1){
		    MY_EV_ADD(16);
		}
		MY_EV_ADD(16);
	}

	// fen 4k4/4anN2/b4a3/3P1C3/6b2/2Bn2B2/9/3A5/4A4/5K3 w - - 0 1
	// 如果我方的兵的所有步子都给对方攻击了。


	// fen 3k1a3/2P1a4/2N1b4/9/4n4/9/2nC5/3A5/4A4/2B1K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoX(yk) != 0x4 && abs(StoX(mpawn) - 0x4) >= 2){
			RETRUN_MUL(4);
		}
	}

	if((your_shi_num + your_xiang_num) == 4){

		MY_EV_SUB(16);

		// fen 3k5/4a1N2/3ab1P2/9/2b6/2Bn5/7n1/4B4/3CA4/4K4 w - - 0 1
		if(abs(StoX(mpawn) - StoX(yk)) >= 2){
			MY_EV_SUB(16);
		}

		// fen 5k3/3Pa4/4ba1N1/9/2b6/6B2/9/5A3/3KA3n/7nC b - - 0 161
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				if(abs(StoX(mpao) - 0x4) >= 3){
					RETRUN_MUL(4);
				}
			}
		}

		// fen 4k1c2/4a4/3a4n/5N3/4N4/6B2/9/5A3/2p1A4/2BK5 b - - 0 1
		if((my_shi_num + my_xiang_num) <= 2 && my_shi_num  >= 1){
			MY_EV_ADD(64);
		}

		if(my_shi_num == 0){
			MY_EV_SUB(64);
		}

		// fen 4k1b2/2P1a4/5a3/4n4/2n1N1b2/6B2/4C4/4BA3/4A4/4K4 w - - 0 1
        if(yk == MY_SQ04){
			if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
				Bitboard bym = m_and(bb_your_ma,MyUpBB[MY_RANK6]);
				bym = _mm_andnot_si128(EV_MY_XBIT,bym);  // 去了牵制对方的马。
				if(count_1s(bym) == 2){
					RETRUN_MUL(4);
				}
			}
		}

		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
		// fen 3k1c3/9/3ab4/5N3/2b6/2N3B2/4p4/5An1B/4AK3/9 b - - 0 1
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){			
			RETRUN_MUL(8);
		}
	}
	if(StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		MY_EV_SUB(64);
	}
	// fen 9/1N1kaP3/b2ab4/9/9/3n2B2/5n3/3A1A3/3C5/5KB2 w - - 0 100
	if((your_shi_num + your_xiang_num) == 4){
		if(abs(StoX(mpawn) - StoX(yk)) >= 2){
			if(StoY(mpawn) MY_SMALL_EQL StoY(yk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/4a1P2/3a4b/2nN2n2/9/2B6/9/4BA3/4AC3/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) >= 2){
			RETRUN_MUL(8);
		}
	}

	// fen 3k5/5P3/3a1a3/9/9/5N3/2n6/3n5/2C6/5K3 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(8);
		}
	}

	// fen 4P4/2N2k3/3a5/9/2b1n4/9/9/1n1ABA3/1C7/2B2K3 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 2){
		if(StoY(mpawn) == MY_RANK0 && StoY(yk) != MY_RANK0){
			MY_EV_SUB(64);
			RETRUN_MUL(8);
		}
	}

	// fen 4k4/3ca4/3a4b/9/6b2/2B6/6N2/3N1A3/4A1n1p/3K5 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(abs(StoX(mpawn) - 0x4) >= 3){
			RETRUN_MUL(8);
		}
		RETRUN_MUL(12);
	}
}

//void m_MT_B_1ma1pao1pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bpawn = PieceListStart(board,BPAWN);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_2Ma_ByPawnShi[board->R_shi];
//		}
//	}
//
//	// fen 2P6/5kN2/9/9/9/6B2/n2n5/4B4/3K5/8C w - - 21 21
//	if(board->B_shi == 0 && StoY(bpawn) == 0xc){
//		return 2;
//	}
//
//	// fen 2b2k3/5c3/3a5/7N1/6b1p/2B6/5nN2/3A5/4A4/4K1B2 w - - 144 144
//    //对方是仕相全, 且兵没有过河, 也是基本和棋
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			if(StoY(bpawn) <= 0x7){
//				return 4;
//			}
//		}
//	}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			return 8;
//		}
//	}
//
//	*/
//}