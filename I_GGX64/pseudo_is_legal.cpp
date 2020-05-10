#include "chess.h" 
#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"

bool pseudo_is_legal(int move, typePOS *POSITION){

	int from  = FROM(move);
	int   to  = TO(move);
	int piece = PB90(from);
	int k;
	//Bitboard iskxy;

	 Bitboard occ = m_and(POSITION->byWhiteBlack,ClearMaskBB[from]);   //
     occ          = m_or(occ,SetMaskBB[to]);

	//PIECE_SIDE
	// if(POS_SIDE){

	if(PIECE_SIDE(piece) == WHITE_TO_MOVE){
		
		if(piece == RKING){  // 1,走的棋子是将,
			
			// 1. 是不是给对方的 车,将 将军
			if(m128_is_have_bit(m_and(m_or(POSITION->byChessBB[BKING],POSITION->byChessBB[BCHE]),
				rook_attacks_bb(to,occ)))) return FALSE;            

			// 2. 是不是给对方的 炮 将军
			if(m128_is_have_bit(m_and(POSITION->byChessBB[BPAO],
				pao_eat_attacks_bb(to,occ)))) return FALSE;

            // 3. 是不是给对方的 马 将军
			if(m128_is_have_bit(m_and(POSITION->byChessBB[BMA],
				king_to_ma_attacks_bb(to,occ)))) return FALSE;

			// 4, 是不是给对方的 兵 将军
			if(m128_is_have_bit(m_and(Attack_By_Bpawn_Bking[to],POSITION->byChessBB[BPAWN]))) 
			     return FALSE;
		}
		else{  // 2,走的棋子不是将

			k = RKpos();
			
			// 2.1 判断是不是走动的自己将线上的棋,走了后,给对方的车,炮,将 将军
			//iskxy = m_and(ChePseudoMask_FR[k],m_or(ChePseudoMask_FR[from],ChePseudoMask_FR[to]));  
			//if(m128_is_have_bit(iskxy)){
			if(bit_is_set(ChePseudoMask_FR[k],from) || bit_is_set(ChePseudoMask_FR[k],to)){
				
				// 2.1.1. 是不是给对方的 车,将 将军, ** 但不包括吃了对方的棋.同时去了对方的棋子
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
					m_or(POSITION->byChessBB[BKING],POSITION->byChessBB[BCHE])),
					rook_attacks_bb(k,occ)))) {
						return FALSE; 
				}
				
				// 2.1.2. 是不是给对方的 炮 将军
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[BPAO]),
					pao_eat_attacks_bb(k,occ)))){  //board_display(board,"""");
					return FALSE;
				}

			}

			// 2.2 判断是不是走动的可能将军的马腿上的棋 ** 但不包括吃了对方的棋.
			if( ABS(from - k) == 8 || ABS(from - k) == 10){
				// 再重算一下 马 的将军
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[BMA]), //这儿已去了对方的马.
					king_to_ma_attacks_bb(k,occ))))
					return FALSE;
			}
		}
	}
	else{
		if(piece == BKING){  // 1,走的棋子是将,
			
			// 1. 是不是给对方的 车,将 将军
			if(m128_is_have_bit(m_and(m_or(POSITION->byChessBB[RKING],POSITION->byChessBB[RCHE]),
				rook_attacks_bb(to,occ)))) return FALSE;            

			// 2. 是不是给对方的 炮 将军
			if(m128_is_have_bit(m_and(POSITION->byChessBB[RPAO],
				pao_eat_attacks_bb(to,occ)))) return FALSE;

            // 3. 是不是给对方的 马 将军
			if(m128_is_have_bit(m_and(POSITION->byChessBB[RMA],
				king_to_ma_attacks_bb(to,occ)))) return FALSE;

			// 4, 是不是给对方的 兵 将军
			if(m128_is_have_bit(m_and(Attack_By_Bpawn_Bking[to],POSITION->byChessBB[RPAWN]))) 
			     return FALSE;
		}
		else{  // 2,走的棋子不是将

			k = BKpos();
			
			// 2.1 判断是不是走动的自己将线上的棋,走了后,给对方的车,炮,将 将军
			//iskxy = m_and(ChePseudoMask_FR[k],m_or(ChePseudoMask_FR[from],ChePseudoMask_FR[to]));  
			//if(m128_is_have_bit(iskxy)){
			if(bit_is_set(ChePseudoMask_FR[k],from) || bit_is_set(ChePseudoMask_FR[k],to)){
				
				// 2.1.1. 是不是给对方的 车,将 将军, ** 但不包括吃了对方的棋.同时去了对方的棋子
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
					m_or(POSITION->byChessBB[RKING],POSITION->byChessBB[RCHE])),
					rook_attacks_bb(k,occ)))) {
						return FALSE; 
				}
				
				// 2.1.2. 是不是给对方的 炮 将军
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[RPAO]),
					pao_eat_attacks_bb(k,occ)))){
					return FALSE;
				}

			}

			// 2.2 判断是不是走动的可能将军的马腿上的棋 ** 但不包括吃了对方的棋.
			if( ABS(from - k) == 8 || ABS(from - k) == 10){
				// 再重算一下 马 的将军
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[RMA]),
					king_to_ma_attacks_bb(k,occ))))
					return FALSE;
			}
		}
	}  

    return TRUE;
}

#endif