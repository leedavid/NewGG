#include "eval_total.h"
#pragma warning(disable : 4530)  

const Score Che2_String_Pao[10] = {	   //我方有二车时，炮被对方牵制扣分
	Score(((116) << 16) + (196)),     //0,  车炮 -- 车的自由度
	Score(((108) << 16) + (186)),     //1,
	Score(((100) << 16) + (178)),     //2,
	Score((( 92) << 16) + (170)),     //3,
	Score((( 84) << 16) + (162)),     //4, 
	Score((( 72) << 16) + (154)),     //5,
	Score((( 64) << 16) + (146)),     //6, 
	Score((( 56) << 16) + (138)),     //7,
	Score((( 48) << 16) + (130)),     //8,
	Score((( 40) << 16) + (124)),     //9,	
};

const Score Che1_String_Pao[10] = {   //我方仅一车时，炮被对方牵制扣分
	Score(((168) << 16) + (196)),     //0,  车炮 -- 车的自由度
	Score(((160) << 16) + (186)),     //1,
	Score(((152) << 16) + (178)),     //2,
	Score(((144) << 16) + (170)),     //3,
	Score(((136) << 16) + (162)),     //4, 
	Score(((128) << 16) + (154)),     //5,
	Score(((120) << 16) + (146)),     //6, 
	Score(((112) << 16) + (138)),     //7,
	Score(((104) << 16) + (130)),     //8,
	Score((( 96) << 16) + (124)),     //9,	
};

// fen 4kab2/4ac3/4b4/pR2p2P1/cn7/C8/2p1P4/4B1N1B/1r1N5/3AKA3 w - - 0 1
const Score Che2_String_Ma[10] = {		
	Score(((118) << 16) + (196)),     //0,  车马 -- 车的自由度
	Score(((110) << 16) + (186)),     //1,
	Score(((102) << 16) + (178)),     //2,
	Score((( 94) << 16) + (170)),     //3,
	Score((( 86) << 16) + (162)),     //4, 
	Score((( 78) << 16) + (154)),     //5,
	Score((( 70) << 16) + (146)),     //6, 
	Score((( 62) << 16) + (138)),     //7,
	Score((( 54) << 16) + (130)),     //8,
	Score((( 46) << 16) + (124)),     //9,	
};

const Score Che1_String_Ma[10] = {
	Score(((168) << 16) + (196)),     //0,  车马 -- 车的自由度
	Score(((160) << 16) + (186)),     //1,
	Score(((152) << 16) + (178)),     //2,
	Score(((144) << 16) + (170)),     //3,
	Score(((136) << 16) + (162)),     //4, 
	Score(((128) << 16) + (154)),     //5,
	Score(((120) << 16) + (146)),     //6, 
	Score(((112) << 16) + (138)),     //7,
	Score(((108) << 16) + (130)),     //8,
	Score(((100) << 16) + (124)),     //9,	
};



//////////////////////////////////////////////////////////////////////////
/// 评估双方的弱子

template<Color Us>
Score eval_weak_piece(Position& pos, EvalInfo& ei){
	//const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Score bonus = SCORE_ZERO;

	Bitboard myMaPao = m_or(pos.pieces(RMA + delt), pos.pieces(RPAO + delt));

	if (!have_bit(ei.attacked_by(RCHE + delt), myMaPao)){
		return SCORE_ZERO;
	}

	// 先看一下我方的马,炮是不是给对方炮攻击, 车 马(炮) 车， 
	Bitboard str = m_and(ei.attacked_by(RCHE + delt), myMaPao);

	Bitboard yourChePao = m_or(ei.attacked_by(BCHE - delt), ei.attacked_by(BPAO - delt));
	if (!have_bit(str, yourChePao)){
		return SCORE_ZERO;
	}

	// 如果 str 给对方的（车，炮），只有车炮才能牵制棋子攻击了
	str = m_and(str, yourChePao);

	// 如果给自己的相，仕，兵保护也，也不算受攻击的弱子	((( 还要加上自己的炮，马保护哇）))
	str = _mm_andnot_si128(ei.pi->pawnshiXiang_attacks(Us), str);     //print_bb(str);
	////////////////////////////////////////////////////////////////////////
	// 2炮同时给对方2车牵制了。
	if (pos.piece_count(RCHE + delt) == 2 
		&& count_1s(str, pos.pieces(RPAO + delt)) == 2
		&& !have_bit(pos.pieces(RCHE + delt), ei.attacked_by(Us))){  // 我方的车没有保护
		Bitboard str2pao2che = m_and(str, ei.attacked_by(BCHE - delt));
		if (count_1s(str2pao2che) == 2 ){
			if (have_bit(str2pao2che, ei.attacked_by(RPAO + delt))){  // 2炮相互在保护着，
				// 再看一下有没有其它的棋子在保护。
				Bitboard bsxp_ma = m_or(ei.pi->pawnshiXiang_attacks(Us),
					ei.attacked_by(RMA + delt));
				if (!have_bit(bsxp_ma, str2pao2che)){
					bonus -= Score(((48) << 16) + (138));     //9,	
				}
			}
		}
	}
	////////////////////////////////////////////////////////////////////////		
	// 去了中间受保护的棋子
	str = _mm_andnot_si128(m_or(ei.attacked_by(RMA + delt), ei.attacked_by(RPAO + delt)), str);    
	Square sqStr;
	while (pop_1st_bit_sq(str, sqStr)) {

		Piece  strPiece = pos.piece_on(sqStr);

		// fen 2ba2RN1/4a2r1/2C1k4/c2n5/5n2P/3p2p2/2P6/4B4/1C2A4/4KAB2 w - - 0 1 
		// 压死马了。
		if (strPiece == (RMA + delt)){
			if (have_bit(CheYaMa[sqStr], pos.pieces(BCHE - delt))){
				bonus -= Score(((48) << 16) + (118));     //9,	
			}
		}

		// 先找出保护自己的车，再找出攻击自己的车，或炮
		Bitboard cheAtt = pos.Rook_attacks_bb(sqStr);
		Bitboard mc = m_and(pos.pieces(RCHE + delt), cheAtt);
		Square sqMche;
		while (pop_1st_bit_sq(mc, sqMche)) {
			// 找到对方的车
			Bitboard mask = StoX(sqMche) == StoX(sqStr) ?
				FileBB_A[StoX(sqStr)] : RankBB_A[StoY(sqStr)];

			// 如果车有保护，也要去了。
			if (bit_is_set(ei.attacked_by(Us), sqMche)){
			}
			else if (have_bit(cheAtt, m_and(mask, pos.pieces(BCHE - delt)))){
				// 这个是我方的马，或炮给对方的车牵制了
				// nbet 很重要，主要是算一下我方车的自由度，也就是被牵制方的车的自由度
				int nbet = (int)count_1s(mask, pos.Rook_attacks_bb(sqMche));
				// fen 1r1ak4/cC2anC2/1Rn1b4/p8/2p1p1b2/5N3/P1c1P4/2N1B4/9/3AKAB2 b - - 0 1	
				if (pos.piece_count(RCHE + delt) == 2){
					if (strPiece == (RMA + delt)){
						bonus -= Che2_String_Ma[nbet];
					}
					else{
						bonus -= Che2_String_Pao[nbet];
					}
				} // fen 2bakab2/9/2n5n/p1p1p1p1p/6c2/2P6/Prc1R3P/C1N1BC2N/4A4/2BAK4 b - - 0 1
				else{
					if (strPiece == (RMA + delt)){
						bonus -= Che1_String_Ma[nbet];
					}
					else{
						bonus -= Che1_String_Pao[nbet];
					}
				}
			}
			//////////////////////////////////////////////////////////////////////////
			// 还要判断一下是不是给对方的炮牵制了， mChe sqStr X 炮
			if (strPiece == (RMA + delt) && bit_is_set(ei.attacked_by(BPAO - delt), sqStr)){
				Bitboard paoAtt = m_and(pos.Pao_Eat_bb(sqStr), pos.pieces(BPAO - delt));
				// 要去了 炮 车 X
				paoAtt = _mm_andnot_si128(pos.Rook_attacks_bb(sqMche), paoAtt); // pos.board_display("");
				if (have_bit(paoAtt, mask)){
					bonus -= make_score(64, 168);
					// fen 3ak1b2/9/3ab4/p4np1p/9/PN4P1P/2C1Pnrc1/4B1NR1/4A4/2BAK4 w - - 0 1
				}
			}
		}
	}
	return bonus;
}