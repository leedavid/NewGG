#include "eval_total.h"
#pragma warning(disable : 4100) 
//////////////////////////////////////////////////////////////////////////
/// 过河兵的数量
template<Color Us>
int PawnOverRiver(Position& pos, EvalInfo& ei){
	Bitboard pawn;

	if (Us == WHITE){
		pawn = m_and(pos.pieces(RPAWN), UpBB[0x5]);
	}
	else{
		pawn = m_and(pos.pieces(BPAWN), LowBB[0x4]);
	}

	return count_1s(pawn);
}

//////////////////////////////////////////////////////////////////////////
// 根据子力的特殊性的专用评估
template<Color Us>
Score eval_Only_1Che1PaoxPawn(Position& pos, EvalInfo& ei){

	// fen 2ba1k3/2N1a4/4b4/p1R6/6pNP/9/9/3A5/3K2c2/5r3 r


	if(have_bit(ei.attackKingBoard[Us],Us == WHITE ? pos.pieces(RPAWN) : pos.pieces(BPAWN))){
		return SCORE_ZERO;
	}

	Score bonus = SCORE_ZERO;
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	const Color Them = (Us == WHITE ? BLACK : WHITE);
	Square mpao =  pos.piece_list(RPAO + delt,0);
	int mcan = (Us == WHITE ? ei.rcan : ei.bcan);

	//if(mcan >= 1) return;

	int ycan = ((Us == WHITE ? ei.bcan : ei.rcan) + 1)/2;
	int yalr = (PawnOverRiver<Them>(pos,ei) + 1)/2;

	ei.attPoint[Us] /= 2;

	if( Us == WHITE? StoY(mpao) <= 0x4 : StoY(mpao) >= 0x5){
		bonus  -= (yalr * Only_1Che1PaoxPawn_Your_pawnAlr_Pao_Not_Home);
		if(mcan == 0){
			bonus  -= (ycan * Only_1Che1PaoxPawn_Your_pawnCan_Pao_Not_Home);
		}
	}
	else{
		bonus  -= (yalr * Only_1Che1PaoxPawn_Your_pawnAlr_Pao_at_Home);
		if(mcan == 0){
			bonus  -= (ycan * Only_1Che1PaoxPawn_Your_pawnCan_Pao_at_Home);
		}
	}

	// fen 7r1/4k4/5a2b/p7p/6p2/3N5/P6cP/B3B4/4A4/4KR3 b - - 0 0
	// fen 3k1ab2/4a4/4b4/C3R4/1r7/P8/8P/3A5/3KA1n2/9 b - - 0 1
	// 对方有马
	if(pos.piece_count(BMA - delt) >= 0){
		if(pos.piece_count(RXIANG + delt) <= 1 
			&& pos.piece_count(RSHI + delt) <= 1){
				Bitboard yma = (Us == WHITE ?
					m_and(pos.pieces(BMA),LowBB[0x3]) : m_and(pos.pieces(RMA),UpBB[0x6]));
				if(m_have_bit(yma)){
					bonus  -= 
						Only_1Che1PaoxPawn_Your_Ma_add[pos.piece_count(RXIANG + delt) + pos.piece_count(RSHI + delt)]; 
				}
		}
	}

	return bonus;
	
}


