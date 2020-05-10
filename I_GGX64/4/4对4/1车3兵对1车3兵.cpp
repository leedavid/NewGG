#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"

void m_MT_BR_1che3pawn(typePOS &POSITION, EvalInfo &ei){


	// fen 4k1b2/5R3/4b4/6p2/2p2P2p/9/2P2r2P/4B4/4A4/4KA3 b - - 1 1
	//特征是什么?
	Square rk = RKpos();
	Square bk = BKpos();

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	if(RShi_num() == 2 && RXiang_num() >= 1 && StoY(rk) >= 0x8){
		if(bcan <= 1){
			ei.rsafe = TRUE;
		}
	}
	if(BShi_num() == 2 && BXiang_num() >= 1 && StoY(bk) <= 0x1){
		if(rcan <= 1){
			ei.bsafe = TRUE;
		}
	}


	//if(board->rsafe){
	//	if(board->B_xiang == 2 && board->b256[0x37] == BKING){
	//		if(abs(StoX(rche) - 0x7) == 1){
	//			//算一下顶兵的数量
	//			int d = 0;
	//			int p = 0;
	//			for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
	//				if(board->b256[from - 0x20] == BPAWN || board->b256[from - 0x30] == BPAWN){
	//					d++;
	//				}
	//				else{
	//					p = from;
	//				}
	//			}
	//			if(d == 2 && StoX(p) == StoX(rche) && StoY(rche) < StoY(p) && StoX(p) == StoX(bche)){
	//				if(StoY(bche) > StoY(p)){
	//					// fen 4k1b2/5R3/4b4/6p2/2p2P2p/9/2P2r2P/4B4/4A4/4KA3 b - - 1 1
	//					board->mulScore -= 96;
	//					return 8;
	//				}
	//			}
	//		}
	//	}
	//}

	//if(board->bsafe){
	//	if(board->R_xiang == 2 && board->b256[0xc7] == RKING){
	//		if(abs(StoX(bche) - 0x7) == 1){
	//			//算一下顶兵的数量
	//			int d = 0;
	//			int p = 0;
	//			for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
	//				if(board->b256[from + 0x20] == RPAWN || board->b256[from + 0x30] == RPAWN){
	//					d++;
	//				}
	//				else{
	//					p = from;
	//				}
	//			}
	//			if(d == 2 && StoX(p) == StoX(rche) && StoY(bche) > StoY(p) && StoX(p) == StoX(bche)){
	//				if(StoY(rche) < StoY(p)){
	//					// fen 4k1b2/5R3/4b4/6p2/2p2P2p/9/2P2r2P/4B4/4A4/4KA3 b - - 1 1
	//					board->mulScore += 96;
	//					return 8;
	//				}
	//			}
	//		}
	//	}
	//}

	//*/
}