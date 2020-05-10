#ifndef END_my_m_MT_K2CHE_B_1CHE1PAO_S
#define END_my_m_MT_K2CHE_B_1CHE1PAO_S
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h" 
#include "..\\..\\endgame\mat.h"
#include "2车对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//my_m_MT_R_2CHE_B_1CHE1PAO 
//我方2车，对方一车一炮
void my_m_MT_R_2CHE_B_1CHE1PAO(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	if(MY_SQ04 == your_king_pos){
		if(your_shi_num == 2){
			//
			if(PB90(MY_SQ0D) == your_shi){
				if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ05) == your_pao){
					RETRUN_MUL(2);
				}
				if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ03) == your_pao){
					RETRUN_MUL(2);
				}
			}

			// 对方仕相全
			if(your_xiang_num == 2 && PB90(MY_SQ16) == your_xiang){
				RETRUN_MUL(2);
			}
		}
		
		if(your_shi_num >= 1 && your_xiang_num == 2){

			MY_EV_SUB(128);
			
			if(StoX(yche) == StoX(ypao)){
				// 双车例和车炮单缺仕 page 442 fen R2ckab2/9/4b4/9/3r5/5R3/9/9/9/2BAKAB2 w  
				if(PB90(MY_SQ16) == your_xiang){
					if(PB90(MY_SQ03) == your_pao && PB90(MY_SQ06) == your_xiang){
						if(PB90(MY_SQ0D) == your_shi || PB90(MY_SQ05) == your_shi){
							RETRUN_MUL(2);
						}
					}
					if(PB90(MY_SQ05) == your_pao && PB90(MY_SQ02) == your_xiang){
						if(PB90(MY_SQ0D) == your_shi || PB90(MY_SQ03) == your_shi){
							RETRUN_MUL(2);
						}
					}
				}
			}
			// fen 2b1k4/4a4/3ab4/4R4/9/9/2r6/B8/7r1/2BCKA3 w - - 0 0
			if(PB90(MY_SQ03) == your_pao){
				if(PB90(MY_SQ0D) == your_shi || PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ05) == your_pao){
				if(PB90(MY_SQ0D) == your_shi || PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(4);
				}
			}
			// fen 2b1kc2R/4aR3/4b4/9/4r4/2B6/9/9/4A4/3AK1B2 b - - 0 1			
		}
	}
	if(StoY(yk) == MY_RANK0 && StoY(ypao) == MY_RANK0 && abs(StoX(ypao) - 0x4) <= 1){
		if(your_shi_num == 2){
			RETRUN_MUL(4);
		}
	}

	//fen 9/4ak3/3a5/9/3r5/9/9/1r1C5/4A4/R2K1A3 b - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if (StoY(ypao) MY_SMALL_EQL MY_RANK6 && PB90(MY_SQ0D) == your_shi){
			if (PB90(MY_SQ03) == your_shi && StoX(ypao) == 0x5){
				if (StoX(yche) > 0x5){
					RETRUN_MUL(4);
				}
			}
			if (PB90(MY_SQ05) == your_shi && StoX(ypao) == 0x3){
				if (StoX(yche) < 0x3){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3a1kb2/4a4/4c3b/9/9/2R3R2/3r5/9/9/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}

	// fen 4ka3/4a4/3R5/4R4/9/1c7/9/9/9/2r1K4 w - - 0 1
	if (your_shi_num == 2 && MY_SQ04 == yk){
		if ((my_shi_num + my_xiang_num) == 0){
			RETRUN_MUL(8);
		}
	}


}

//我方2车，对方一车一炮
//void m_MT_B_2CHE_R_1CHE1PAO(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 cInfo16 = pMat->sixiangInfo8;
//
//	Square bk    = PieceListStart(board,BKING);
//	Square rk    = PieceListStart(board,RKING);
//	int rpao  = PieceListStart(board,RPAO);
//	int rche  = PieceListStart(board,RCHE);
//
//	//if((cInfo16 & CK_R_2s)){		//对方2仕
//	//if(board->R_shi == 2){
//	//	if(rk == 0xc7){
//	//		return 2;
//	//	}	
//	//}
//
//	if(rk == 0xc7){
//
//		
//		if(board->R_shi == 2){	//红方有二个仕
//			if(board->b256[0xb7] == RSHI){
//				if(   (board->b256[0xc6] == RSHI && board->b256[0xc8] == RPAO)
//					||(board->b256[0xc8] == RSHI && board->b256[0xc6] == RPAO)){
//						return 1;
//				}
//
//				//对方仕相全
//				if(board->R_xiang == 2 && board->b256[0xa7] == RXIANG){
//					return 1;
//				}
//			}
//	
//		}
//		
//
//
//		//双车例和车炮单缺仕 page 442 fen R2ckab2/9/4b4/9/3r5/5R3/9/9/9/2BAKAB2 w
//
//		//双车例和车炮单缺仕 page 442 fen R2ckab2/9/4b4/9/3r5/5R3/9/9/9/2BAKAB2 w        
//		if(board->R_shi == 1 && board->R_xiang == 2){
//			if(board->b256[0xa7] == RXIANG){
//				if((board->b256[0xc6] == RPAO && board->b256[0xc9] == RXIANG)
//					||(board->b256[0xc8] == RPAO && board->b256[0xc5] == RXIANG)){
//					 int rshi = PieceListStart(board,RSHI);
//					 if(StoY(rshi) >= 0xb){
//						//再看一下车是不是在保着炮
//						 SlideMoveStruct *ps = FileMove(StoY(rpao), board->wBitFiles[StoX(rpao)]);
//						 int sq1 = ps->RookCap[DUpLeft] + StoX(rpao);
//						 if(board->b256[sq1] == RCHE){
//							return 1;
//						 }
//					 }
//				}
//			}
//
//			// fen 2b1k4/4a4/3ab4/4R4/9/9/2r6/B8/7r1/2BCKA3 w - - 0 0
//			//if(StoX(rche) == 0x7){
//			//	if(board->b256[0xc6] == RPAO && (board->b256[0xc8] == RSHI || board->b256[0xc7] == RSHI)){
//			//		return 2;
//			//	}
//			//	if(board->b256[0xc8] == RPAO && (board->b256[0xc6] == RSHI || board->b256[0xc7] == RSHI)){
//			//		return 2;
//			//	}
//			//}
//
//			if(board->b256[0xc6] == RPAO){
//				if(board->b256[0xb7] == RSHI){
//					return 2;
//				}
//				if(board->b256[0xc8] == RSHI){
//					return 2;
//				}
//			}
//			if(board->b256[0xc8] == RPAO){
//				if(board->b256[0xb7] == RSHI){
//					return 2;
//				}
//				if(board->b256[0xc6] == RSHI){
//					return 2;
//				}
//			}
//
//
//
//		}// 双车例和车炮单缺仕
//
//
//
//	}
//
//	if(board->b256[0xc7] == RKING){
//		if(board->R_shi == 2){	//红方有二个仕
//			return 8;
//		}
//	}
//
//	*/
//}