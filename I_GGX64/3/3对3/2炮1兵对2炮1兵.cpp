
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"


void m_MT_2pao1pawn_2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_BR
	Square bk = BKpos();
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (count_1s(bmp) * ADD_2PaoXPawn_2Pao_ByPawnShi[BShi_num()]);
	// SUB
	Square rk = RKpos();
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (count_1s(ymp) * ADD_2PaoXPawn_2Pao_ByPawnShi[RShi_num()]);
	

	// fen 2b1k1b2/4a4/2P6/C2C5/9/5p3/c4c3/4B4/4A4/2BAK4 b - - 0 0
	if(RShi_num() == 2 && RXiang_num() == 2){
		if(PB90(0x4B) != BPAWN && PB90(0x4D) != BPAWN){
			ei.rsafe = TRUE;
		}
	}

	if(BShi_num() == 2 && BXiang_num() == 2){
		if(PB90(0x0C) != RPAWN && PB90(0x0E) != RPAWN){
			ei.bsafe = TRUE;
		}
	}



	if(ei.rsafe == TRUE){
		if((BShi_num() + BXiang_num()) >= 3){
			if(PB90(0x0C) != RPAWN && PB90(0x0E) != RPAWN){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe == TRUE){
		if((RShi_num() + RXiang_num()) >= 3){
			if(PB90(0x4B) != BPAWN && PB90(0x4D) != BPAWN){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4kac2/3Pa4/4c4/9/9/9/9/4C4/3pA4/4KAC2 w 
	//if(RShi_num() == 2 && RXiang_num() == 0 && BShi_num() == 2 && BXiang_num() == 0){
	//	if(PB90(0x04) == BKING && PB90(0x55) == RKING && PB90(0x0d) == BSHI && PB90(0x4c) == RSHI){
	//		if(PB90(0x0c) == RPAWN && PB90(0x05) == BSHI && PB90(0x4b) == BPAWN && PB90(0x56) == RSHI){

	//		}
	//		if(PB90(0x0e) == RPAWN && PB90(0x03) == BSHI && PB90(0x4d) == BPAWN && PB90(0x54) == RSHI){
	//		}				
	//	}
	//}

}