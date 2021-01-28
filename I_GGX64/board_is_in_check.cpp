#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"

bool board_is_incheck(const typePOS *POSITION, int white_to_move){

	Bitboard occ = POSITION->byWhiteBlack;
	int k;

	if(white_to_move){   //红将是不是给黑方将军了
		k = RKpos();


		//是不是给对方的车, 将, 将军, 给对方的将,将军不算.
		//if(m128_is_have_bit(m_and(m_or(board->byChessBB[BKING],board->byChessBB[BCHE]),
		if(m128_is_have_bit(m_and(POSITION->byChessBB[BCHE],
			rook_attacks_bb(k,occ)))) return TRUE;

		//3,走子方是不是给对方的炮将军
		if(m128_is_have_bit(m_and(POSITION->byChessBB[BPAO],
			pao_eat_attacks_bb(k,occ)))) return TRUE;


		//4,走子方是不是给对方的马将军	
		if(m128_is_have_bit(m_and(POSITION->byChessBB[BMA],
			king_to_ma_attacks_bb(k,occ)))) return TRUE;

		//1,走子方是不是给对方的兵将军
		if(m128_is_have_bit(m_and(Attack_By_Bpawn_Bking[k],POSITION->byChessBB[BPAWN]))) 
			return TRUE;
	}
	else{ // side == BLACK
		k = BKpos();

		//是不是给对方的车, 将, 将军 ,给对方的将,将军不算.
		if(m128_is_have_bit(m_and(POSITION->byChessBB[RCHE],
			rook_attacks_bb(k,occ)))) return TRUE;

		//3,走子方是不是给对方的炮将军
		if(m128_is_have_bit(m_and(POSITION->byChessBB[RPAO],
			pao_eat_attacks_bb(k,occ)))) return TRUE;

		//4,走子方是不是给对方的马将军	
		if(m128_is_have_bit(m_and(POSITION->byChessBB[RMA],
			king_to_ma_attacks_bb(k,occ)))) return TRUE;

		//1,走子方是不是给对方的兵将军
		if(m128_is_have_bit(m_and(Attack_By_Rpawn_Rking[k],POSITION->byChessBB[RPAWN]))) 
			return TRUE;
	} 

	return FALSE;
}

#endif