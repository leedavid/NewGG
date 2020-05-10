#ifndef END_my_m_MT_R_1ma3pawn_B_1che
#define END_my_m_MT_R_1ma3pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// void m_MT_B_1CHE_R_1MA(board_t *board);
// void my_m_MT_R_1CHE_B_1MA(board_t *board);
//我方一马一兵, 对方一车
void my_m_MT_R_1ma3pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	MY_EV_SUB(128);  // 车方要加分

	your_m_MT_R_1CHE_B_1MA(POSITION,ei);

	//Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	//有一种和形
	// fen 4k4/9/9/7PP/9/1r4N2/4P4/4B4/9/4K4 b w  例典: 一车例和马卒象 page
	if(my_xiang_num >= 1 && PB90(MY_SQ3A) == my_pawn && StoX(mk) == 0x4){
		if(PB90(MY_SQ2F) == my_ma || PB90(MY_SQ33) == my_ma){
			ei.mul = 2;
		}
		else {			
			Bitboard matt = POSITION.ma_to_king_attacks_bb(mma);
		   if(bit_is_set(matt,Square(MY_SQ2F)) || bit_is_set(matt,Square(MY_SQ33))){
			   ei.mul = 2;
		   }
		}
	}

	//马方有二相,或二仕, 则马方如果在中线有连兵就是和了
	if((my_shi_num == 2 || my_xiang_num == 2) && StoX(mk) == 0x4){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
			ei.mul = 2;
		}
	}


	if(ei.mul <= 2){
		Square yk = your_king_pos;
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		int pmok = (int)count_1s(bmp);
		MY_EV_ADD(pmok * ADD_MaXPawn_To_CheByShi_WmaSafe[your_shi_num]);
	}

}

//void m_MT_B_1ma3pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16 = pMat->sixiangInfo8;
//
//	Square rk     = PieceListStart(board,RKING);
//	Square bk     = PieceListStart(board,BKING);
//	int bma    = PieceListStart(board,BMA);
//	Square bpawn  = PieceListStart(board,BPAWN);
//
//	bool isSafe = FALSE;
//
//	//有一种和形
//	// fen 4k4/9/4b4/4p4/2n4R1/9/9/9/9/4K4 w  例典: 一车例和马卒象 page
//	if(board->B_xiang != 0){
//		if(board->b256[0x67] == BPAWN && board->b256[0x57] == BXIANG && StoX(bk) == 0x7){
//			//1, 马在相眼上
//			//if(board->b256[0x75] == BMA || board->b256[0x79] == BMA){
//			//	return 1;
//			//}
//			//2, 马可走到相眼上
//			if(IsMaCanToOrAt(board,bma,0x75) || IsMaCanToOrAt(board,bma,0x79)){
//				isSafe = TRUE;
//			}
//		}
//	}
//
//	if(m_MT_R_1CHE_B_1MA(board) == 1){
//		isSafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){  //马方有二相,或二仕, 则马方如果在中线有连兵就是和了.
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) < StoY(rk) && StoX(from) == 0x7){
//
//				if(board->b256[from+1] == BPAWN || board->b256[from-1] == BPAWN){
//
//					isSafe = TRUE;
//
//					break;
//				}
//			}
//		}
//	}
//
//	if(isSafe){    //马兵方安全了
//
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < StoY(rk)){
//				board->mulScore -= ADD_MaXPawn_To_CheByShi_WmaSafe[board->R_shi];
//			}
//		}
//
//		return 1;
//	}
//
//
//	*/
//}


