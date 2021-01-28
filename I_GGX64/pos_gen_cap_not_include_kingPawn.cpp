#include "chess.h"

////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>


#include "mersenne.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

using std::string;

#define SERIALIZE_MOVES(from,to)  (*mlist++).move = make_move(from, to);

/// 产生不包括兵和将移动的吃子步

ExtMove* Position::cattura_not_include_pawn_king(ExtMove* mlist, Color c) {
	
	Piece delt = COLOR_BY_SIDE_ADD[c];
	Bitboard cel = byChessBB[_X_X - delt]; // 对方的棋格 bitboard_occ_black

	Bitboard pawnKingAtt;  //  = _mm_setzero_si128();

	// 将，兵可吃的位棋盘
	if (c == WHITE){
		pawnKingAtt = OneRpawnOrRking_AttackBB[piece_list(RKING, 0)];

		Bitboard bbMyPawn = pieces(RPAWN);
		//
		Bitboard btmp = bbMyPawn;
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB), btmp);
		m_Rsf(btmp, 9); //所有兵向前一步
		pawnKingAtt = m_or(pawnKingAtt, btmp);
		Bitboard ghp = m_and(bbMyPawn, _mm_load_si128((__m128i*)RpawnOverBB));// 得到过河兵
		if (m_have_bit(ghp)){
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB), ghp);  //去了最左面的兵	
			m_Rsf(btmp, 1);                                         //所有红兵向左一步			
			pawnKingAtt = m_or(pawnKingAtt, btmp);
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB), ghp);  //去了最右面的兵
			m_Lsf(btmp, 1);                                               //所有红兵向右一步	
			pawnKingAtt = m_or(pawnKingAtt, btmp);
		}
	}
	else{
		pawnKingAtt = OneBpawnOrBking_AttackBB[piece_list(BKING, 0)];

		Bitboard bbMyPawn = pieces(BPAWN);
		//
		Bitboard btmp = bbMyPawn;
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB), btmp);
		m_Lsf(btmp, 9); //所有兵向前一步
		pawnKingAtt = m_or(pawnKingAtt, btmp);
		Bitboard ghp = m_and(bbMyPawn, _mm_load_si128((__m128i*)BpawnOverBB));// 得到过河兵
		if (m_have_bit(ghp)){
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB), ghp);  //去了最左面的兵	
			m_Rsf(btmp, 1);                                         //所有红兵向左一步			
			pawnKingAtt = m_or(pawnKingAtt, btmp);
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB), ghp);  //去了最右面的兵
			m_Lsf(btmp, 1);                                               //所有红兵向右一步	
			pawnKingAtt = m_or(pawnKingAtt, btmp);
		}
	}


	//***********************************************************
	// 产生所有相的吃子走步
	//***********************************************************
	for(int i = 0; i < piece_count(RXIANG + delt); i++){
		Square from = piece_list(RXIANG + delt,i);	
		Bitboard att = m_and(cel,xiang_attacks_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有红仕的吃子走步
	//***********************************************************
	for(int i = 0; i < piece_count(RSHI + delt); i++){
		Square from = piece_list(RSHI + delt,i);	
		Bitboard att = m_and(cel,shi_attacks(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有炮的吃子走步
	//***********************************************************
	for(int i = 0; i < piece_count(RPAO + delt); i++){
		Square from = piece_list(RPAO + delt,i);	
		Bitboard att = m_and(cel,Pao_Eat_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有马的吃子走步
	//***********************************************************
	for(int i = 0; i < piece_count(RMA + delt); i++){
		Square from = piece_list(RMA + delt,i);	
		Bitboard att = m_and(cel,ma_to_king_attacks_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 产生所有车的吃子走步
	//***********************************************************
	for(int i = 0; i < piece_count(RCHE + delt); i++){
		Square from = piece_list(RCHE + delt,i);	
		Bitboard att = m_and(cel,Rook_attacks_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	return mlist;
}

