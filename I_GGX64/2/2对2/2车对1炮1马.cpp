#ifndef END_my_m_MT_R_2che_B_1pao1ma
#define END_my_m_MT_R_2che_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2che_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){
	
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	
	if((your_shi_num + your_xiang_num) == 4 && PB90(MY_SQ04) == your_king){
		if(PB90(MY_SQ0D) == your_shi && PB90(MY_SQ16) == your_xiang 
			&& StoY(ypao) MY_SMALL_EQL MY_RANK2){
			
			// fen 4kab2/9/5a3/9/2b6/5r3/7rC/4B4/4A4/2BAKN3 w - - 66 66 //一个特殊的和型
			if(PB90(MY_SQ03) == your_ma && PB90(MY_SQ05) == your_shi){
				if(StoX(ypao) < 0x4 && PB90(MY_SQ06) == your_xiang){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ05) == your_ma && PB90(MY_SQ03) == your_shi){
				if(StoX(ypao) > 0x4 && PB90(MY_SQ02) == your_xiang){
					RETRUN_MUL(2);
				}
			}
			// fen 2bakc3/4a4/n3b4/1R7/5R3/6B2/9/3AB4/9/3AK4 w - - 37 37
			if(PB90(MY_SQ12) == your_ma && PB90(MY_SQ02) == your_xiang){
				if(StoX(ypao) > 0x4){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ1A) == your_ma && PB90(MY_SQ06) == your_xiang){
				if(StoX(ypao) < 0x4){
					RETRUN_MUL(2);
				}
			}
			// fen 4k4/4a4/3ab4/9/2b3r2/9/7r1/3CB4/4A4/4KAB1N w - - 64 64

			// fen RR1ckab2/4a4/4b4/9/9/n8/9/1n1AB4/4A4/2B2K3 w - - 0 1
			if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ03) == your_pao){
				if(bit_is_set(YOUR_ATTACK,yma) && StoX(yma) > 0x4){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ05) == your_pao){
				if(bit_is_set(YOUR_ATTACK,yma) && StoX(yma) < 0x4){
					RETRUN_MUL(4);
				}
			}
		}		 
	}
}

//void m_MT_B_2che_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	int rpao = PieceListStart(board,RPAO);
//	int rma  = PieceListStart(board,RMA);
//
//	
//	if(board->b256[0xc7] == RKING && board->b256[0xb7] == RSHI && board->b256[0xa7] == RXIANG){
//
//		// fen 4kab2/9/5a3/9/2b6/5r3/7rC/4B4/4A4/2BAKN3 w - - 66 66
//		if(FALSE){
//		}
//		else if(board->b256[0xc6] == RSHI && board->b256[0xc8] == RMA){
//			return 1;
//		}
//		else if(board->b256[0xc8] == RSHI && board->b256[0xc6] == RMA){
//			return 1;
//		}
//
//		// fen 2bakc3/4a4/n3b4/1R7/5R3/6B2/9/3AB4/9/3AK4 w - - 37 37
//		if(board->b256[0xa3] == RMA && board->b256[0xc5] == RXIANG && StoX(rpao) > 0x7){
//			return 1;
//		}
//
//		if(board->b256[0xab] == RMA && board->b256[0xc9] == RXIANG && StoX(rpao) < 0x7){
//			return 1;
//		}
//
//		// fen 4k4/4a4/3ab4/9/2b3r2/9/7r1/3CB4/4A4/4KAB1N w - - 64 64
//		if(StoY(rpao) == 0xa && StoX(rpao) < 0x7 
//			&& IsMaCanToOrAt(board,rma,0xaa) && board->b256[0xc9] == RXIANG){
//			return 1;
//		}
//		if(StoY(rpao) == 0xa && StoX(rpao) > 0x7 
//			&& IsMaCanToOrAt(board,rma,0xa4) && board->b256[0xc5] == RXIANG){
//			return 1;
//		}
//	}
//
//	*/
//}