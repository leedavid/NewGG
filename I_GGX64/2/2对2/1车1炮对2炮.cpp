#ifndef END_my_m_MT_R_1che1pao_B_2pao
#define END_my_m_MT_R_1che1pao_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h" //
#endif 

//车炮对2炮

void my_m_MT_R_1che1pao_B_2pao(typePOS &POSITION, EvalInfo &ei){

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square ypao1 = S90_from_piecelist(POSITION,your_pao,0);
	Square ypao2 = S90_from_piecelist(POSITION,your_pao,1);
	Square yk = your_king_pos;


	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		// fen 2bak4/4a4/1c2b2c1/7R1/C8/9/9/4B4/9/2BAKA3 w
		//"担子炮" 与士,象互相掩护, 足可应战. 如果炮在下二路,则中象难保.
		if(PB90(MY_SQ16) == your_xiang && (PB90(MY_SQ02) == your_xiang || PB90(MY_SQ06) == your_xiang)){			

			if (MY_SQ04 == yk){
				if (StoY(ypao1) == MY_RANK2 && StoY(ypao2) == MY_RANK2){
					if (IsOnSameSide(ypao1, ypao2) == FALSE){
						RETRUN_MUL(2);
					}
				}

				//这个也是和
				// fen C1bak1c1R/4a4/2c1b4/9/9/9/9/9/9/2BAKAB2 w - - 14 14
				if (IsOnSameSide(mche, mpao) == FALSE){
					if (IsOnSameSide(ypao1, ypao2) == FALSE && (StoY(ypao1) == MY_RANK2 || StoY(ypao2) == MY_RANK2)){
						if (StoX(mche) > 0x4 && PB90(MY_SQ06) == your_pao){
							RETRUN_MUL(2);
						}
						if (StoX(mche) < 0x4 && PB90(MY_SQ02) == your_pao){
							RETRUN_MUL(2);
						}
					}
				}
				// fen C1bak4/9/2cabc3/4R4/9/9/9/9/9/2BAKAB2 w - - 8 8
				//------------------------------------------

				if (IsOnSameSide(ypao1, ypao2) == FALSE){
					if (StoY(ypao1) MY_SMALL_EQL MY_RANK2 && StoY(ypao2) MY_SMALL_EQL MY_RANK2){
						RETRUN_MUL(4);
					}
				}
			}

			// fen 2bk1a3/2R1a4/3cb1c2/9/9/9/9/4CA3/4A4/2BK5 w - - 0 1//
			if (StoY(ypao1) == MY_RANK2 && StoY(ypao2) == MY_RANK2){
				if (StoX(mche) < 0x3 && StoX(yk) == 0x3 && PB90(MY_SQ02) == your_xiang){
					if (StoX(mpao) >= 0x4){
						RETRUN_MUL(4);
					}
				}
				if (StoX(mche) > 0x5 && StoX(yk) == 0x5 && PB90(MY_SQ06) == your_xiang){
					if (StoX(mpao) <= 0x4){
						RETRUN_MUL(4);
					}
				}
			}

			
		}
	}

	// fen 4k4/4a4/3ab4/9/6b2/2P4r1/9/4B3C/4A4/c1CAK1B2 b - - 95 95

}

//void m_MT_B_1che1pao_R_2pao(typePOS &POSITION, EvalInfo &ei){
///*
//	int bche = PieceListStart(board,BCHE);
//	int rpao1 = PieceListStart(board,RPAO);
//	int rpao2 = NextPiece(board,rpao1);
//	int bpao  = PieceListStart(board,BPAO);
//
//	// fen 2bak4/4a4/1c2b2c1/7R1/C8/9/9/4B4/9/2BAKA3 w
//	//"担子炮" 与士,象互相掩护, 足可应战. 如果炮在下二路,则中象难保.
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(board->b256[0xa7] == RXIANG 
//			&& board->b256[0xb7] == RSHI 
//			&& board->b256[0xc7] == RKING){
//			
//			//------------------------------------------
//			
//
//			if(StoY(rpao1) == 0xa && StoY(rpao2) == 0xa){
//				if(   (StoX(rpao1) < 0x7 && StoX(rpao2) > 0x7)
//					||(StoX(rpao2) < 0x7 && StoX(rpao1) > 0x7)){
//						return 1;
//				}
//			}
//
//			//这个也是和
//			// fen C1bak1c1R/4a4/2c1b4/9/9/9/9/9/9/2BAKAB2 w - - 14 14
//			if(StoY(bche) == 0xc){
//				if(FALSE){
//				}
//				else if(StoX(bche) > 0x7){
//					if(   (StoY(rpao1) == 0xa && StoX(rpao1) < 0x7)
//						||(StoY(rpao2) == 0xa && StoX(rpao2) < 0x7)){
//							if(board->b256[0xc9] == RPAO){
//								return 1;
//							}
//					}
//				}
//				else if(StoX(bche) < 0x7){
//					if(   (StoY(rpao1) == 0xa && StoX(rpao1) > 0x7)
//						||(StoY(rpao2) == 0xa && StoX(rpao2) > 0x7)){
//							if(board->b256[0xc5] == RPAO){
//								return 1;
//							}
//					}
//				}
//			}
//			//------------------------------------------
//		}
//	}
//
//	// fen 4k4/4a4/3ab4/9/6b2/2P4r1/9/4B3C/4A4/c1CAK1B2 b - - 95 95
//	if(board->R_shi == 2 && board->R_xiang == 2 
//		&& board->b256[0xc7] == RKING 
//		&& board->b256[0xa6] != RSHI && board->b256[0xa8] != RSHI){
//		if(StoY(rpao1) == 0xa && StoY(rpao2) >= 0xa){
//			if(IsOnSameSide(bpao,rpao2)){
//				if(abs(StoX(rpao2) - 0x7) < abs(StoX(bpao) - 0x7)){
//				  return 4;
//				}
//			}
//		}
//		if(StoY(rpao2) == 0xa && StoY(rpao1) >= 0xa){
//			if(IsOnSameSide(bpao,rpao1)){
//				if(abs(StoX(rpao1) - 0x7) < abs(StoX(bpao) - 0x7)){
//				  return 4;
//				}
//			}
//		}
//	}
//
//
//	*/
//}