#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"



//5±ø¶Ô1±ø
void m_MT_BR_1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){


	Square rk = RKpos();
	Square bk = BKpos();

	Bitboard bmp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (int)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[RShi_num()];

	Bitboard rmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (int)count_1s(rmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[BShi_num()];

	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
	ei.evscore += (White_pawn_already_over_river(POSITION) - Black_pawn_already_over_river(POSITION)) * 16;

	// fen 3aknb1C/4a3N/1cn5b/p3p4/7N1/P3P1B2/9/3A5/4A4/4K1B2 w - - 0 1
	if(ei.rcan == 0){
		if(BShi_num() == 2 && BXiang_num() == 2 && 0x4 == bk){
			if(PB90(0x11) == RMA && PB90(0x1A) == BXIANG && PB90(0x06) == BXIANG){
				ei.evscore -= 64;
			}
			if(PB90(0x09) == RMA && PB90(0x12) == BXIANG && PB90(0x02) == BXIANG){
				ei.evscore -= 64;
			}
		}
	}
	// fen 3aknb1C/4a3N/1cn5b/p3p4/7N1/P3P1B2/9/3A5/4A4/4K1B2 w - - 0 1
	if(ei.bcan == 0){
		if(RShi_num() == 2 && RXiang_num() == 2 && 0x55 == rk){
			if(PB90(0x50) == BMA && PB90(0x47) == RXIANG && PB90(0x57) == RXIANG){
				ei.evscore += 64;
			}
			if(PB90(0x48) == BMA && PB90(0x3F) == RXIANG && PB90(0x53) == RXIANG){
				ei.evscore += 64;
			}
		}
	}
}

//void m_MT_B_1pao2ma2pawn_R_1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//   int rcan = RpawnCanOverLiver(board);
//   int bcan = BpawnCanOverLiver(board);
//
//   if(rcan == 0){
//	   board->mulScore -= bcan * ADD_1Pao2Ma_To_1Pao2Ma_By_PawnCan;
//   }
//
//   if(bcan == 0){
//	   board->mulScore += rcan * ADD_1Pao2Ma_To_1Pao2Ma_By_PawnCan;
//   }
//
//	*/
//}

//const int ADD_2Pao1Ma_To_2Pao1Ma_By_PawnCan         = 64;
//const int ADD_2Pao1Ma_To_1Pao2Ma_By_PawnCan         = 64;
//const int ADD_1Pao2Ma_To_1Pao2Ma_By_PawnCan         = 64;
