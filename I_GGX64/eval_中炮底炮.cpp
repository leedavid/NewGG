#include "eval_total.h"
/*
//////////////////////////////////////////////////////////////////////////
/// 中炮底炮的评价
template<Color Us>
Score eval_zhong_di_pao(Position& pos, EvalInfo& ei){

	Score bonus = SCORE_ZERO;
	Bitboard bzp = ei.ZhongDiPaoBB[Us];
	while(m_have_bit(bzp)){
		const Color Them = (Us == WHITE ? BLACK : WHITE);
		//const Square mk  = pos.king_square(Us);
		const Square yk  = pos.king_square(Them);
		const Piece delt = COLOR_BY_SIDE_ADD[Us];	
		//Bitboard occ = pos.occupied_squares();
		Square pao_sq = pop_1st_bit(bzp);

		// fen 2bak4/3ra4/4n2r1/pR1CCP2p/6b2/9/Pp6P/3R5/2nNA4/2c1KAB2 b - - 0 1
		// 如果炮给自己的兵保护了，要加分
		if(bit_is_set(ei.attacked_by(RPAWN + delt),pao_sq)){
			bonus += make_score(16,32);
		}

		//////////////////////////////////////////////////////////////////////////
		/// 这个可能是中炮
		if(StoX(pao_sq) == StoX(yk)){
			bonus  += make_score(8,32);
			ei.attPoint[Us] += 6;			//////////////////////////////////////////////////////////////////////////


			// 还要判断一下是不是受到对方的攻击
			if(bit_is_set(ei.attacked_by(Them),pao_sq)){
				if(bit_is_set(ei.attacked_by(Us),pao_sq)){
				}
				else{
					ei.attPoint[Us] -= 3;
				}
			}
		} 
		//////////////////////////////////////////////////////////////////////////
		/// 这个肯定是底炮
		else{ 
			ei.attPoint[Us] += 8;   // 底炮加攻击点	
			bonus  += make_score(32, -8);
			// 还要判断一下是不是受到对方的攻击
			if(bit_is_set(ei.attacked_by(Them),pao_sq)){
				if(bit_is_set(ei.attacked_by(Us),pao_sq)){
				}
				else{
					ei.attPoint[Us] -= 3;
				}
			}
		}


		// 对边上的一子的攻击分要加大. 
		Bitboard bet = BetweenBB[pao_sq][yk];
		// 如果有车在里面, 就要判断是不是还有子在攻击side.
		// fen 1CRaka3/9/n8/p2Rp3p/2b3p2/3nr1Pr1/P7P/B8/4A4/3AK4 r
		if(have_bit(bet,pos.pieces(RCHE + delt))){
			Bitboard kingside = m_and(bet,ei.attacked_by(BKING - delt));
			// 车
			for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
				Square s =  pos.piece_list(RCHE+ delt,i);
				Bitboard A = ei.CheAtt[Us][i];                                // 得到炮的攻击位棋盘
				if(have_bit(A,kingside)){
					if(!bit_is_set(bet,s)){
						ei.haveKillDanger[Us] = true; 
						continue;
					}
				}
			}		
			// 马
			for(int i = 0; i < pos.piece_count(RMA + delt); i++){
				//Square s =  pos.piece_list(RMA + delt,i);
				Bitboard A = ei.MaAtt[Us][i];                                // 得到炮的攻击位棋盘
				if(have_bit(A,kingside)){
					ei.haveKillDanger[Us] = true; 
					continue;
				}
			}			
			// 兵
			if(have_bit(ei.attacked_by(RPAWN + delt),kingside)){
				ei.haveKillDanger[Us] = true; 
				continue;
			}
			
		}
	}

	return bonus;
}

*/