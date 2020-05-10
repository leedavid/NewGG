#include "..\\chess.h"
#include <cassert>
#include <cstring>
#include "preGen.h"
#include "s_bitcount.h"
#include "s_evaluate.h"
#include "s_material.h"
#include "s_pawns.h"
#include "s_scale.h"
#include "s_thread.h"
#include "s_ucioption.h"
#include "s_eval_const.h"

//////////////////////////////////////////////////////////////////////////
/// 中炮底炮的评价
template<Color Us>
void eval_zhong_di_pao(const Position& pos, EvalInfo& ei){

	Bitboard bzp = ei.ZhongDiPaoBB[Us];
	while(m_have_bit(bzp)){

		const Color Them = (Us == WHITE ? BLACK : WHITE);
		const Square mk  = pos.king_square(Us);
		const Square yk  = pos.king_square(Them);
		const Piece delt = COLOR_BY_SIDE_ADD[Us];	
		Bitboard occ = pos.occupied_squares();

		Square pao_sq = pop_1st_bit(&bzp);
		//////////////////////////////////////////////////////////////////////////
		/// 这个可能是中炮
		if(StoX(pao_sq) == StoX(yk)){
			ei.valu += Sign[Us] * make_score(16,64);
			ei.attPoint[Us] += MidPao_att_point;			//////////////////////////////////////////////////////////////////////////

			// 还要判断一下是不是受到对方的攻击
			if(bit_is_set(ei.attacked_by(Them),pao_sq)){
				if(bit_is_set(ei.attacked_by(Us),pao_sq)){
				}
				else{
					ei.attPoint[Us] -= 4;
				}
			}
			//////////////////////////////////////////////////////////////////////////
			/// 再判断一下是不是铁门栓.
			bool ist = false;
			Bitboard BLR = _mm_setzero_si128();
			if(Us == WHITE){
				if(yk == Square(0x04)){
					Piece sm = pos.piece_on(Square(0x0d));
					if(sm == BSHI){ // && pos.piece_on(Square(0x16)) != EMPTY
						if(pos.piece_on(Square(0x03)) == BSHI){
							ist = true;
							BLR = RightBB[0x4];
						}
						if(pos.piece_on(Square(0x05)) == BSHI){
							ist = true;
							BLR = LeftBB[0x4];
						}
					}
					if(sm == BMA || sm == BCHE){
						if(pos.piece_on(Square(0x03)) == BSHI){
							if(pos.piece_on(Square(0x05)) != BSHI && pos.piece_on(Square(0x17)) != BSHI){
								ist = true;
								BLR = RightBB[0x4];
							}
						}
						if(pos.piece_on(Square(0x05)) == BSHI){
							if(pos.piece_on(Square(0x03)) != BSHI && pos.piece_on(Square(0x15)) != BSHI){
								ist = true;
								BLR = LeftBB[0x4];
							}
						}
					}
				}
			}
			else{
				if(yk == Square(0x55)){ 
					Piece sm = pos.piece_on(Square(0x4c));
					if(sm == RSHI){
						if(pos.piece_on(Square(0x54)) == RSHI){
							ist = true;
							BLR = RightBB[0x4];
						}
						if(pos.piece_on(Square(0x56)) == RSHI){
							ist = true;
							BLR = LeftBB[0x4];
						}
					}
					if(sm == RMA || sm == RCHE){
						if(pos.piece_on(Square(0x54)) == RSHI){
							if(pos.piece_on(Square(0x56)) != RSHI && pos.piece_on(Square(0x44)) != RSHI){
								ist = true;
								BLR = RightBB[0x4];
							}
						}
						if(pos.piece_on(Square(0x56)) == RSHI){
							if(pos.piece_on(Square(0x54)) != RSHI && pos.piece_on(Square(0x42)) != RSHI){
								ist = true;
								BLR = LeftBB[0x4];
							}
						}
					}
				}
			}
			if(ist){
				//////////////////////////////////////////////////////////////////////////					  
				// 1. 车能不能攻击到对方将的右边,底线.
				for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
					Square s =  pos.piece_list(RCHE + delt,i);						  
					if(bit_is_set(BLR,s)){
						Bitboard att = ei.CheAtt[Us][i];
						Us == WHITE ?
							att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank0BB),
							m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])))
							: att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank9BB),
							m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));
						if(m_have_bit(att)){
							ei.valu += Sign[Us] * TiMen_Che_att_Score;
							ei.attPoint[Us] += TiMen_Che_att_point;
						}
					}									
				}
				//////////////////////////////////////////////////////////////////////////
				// 2 看一下兵
				Bitboard tbp = m_and(pos.pieces(RPAWN + delt),
					m_and(BLR,_mm_load_si128((__m128i*)TiMenBit_Pawn)));
				if(m_have_bit(tbp)){
					ei.valu += Sign[Us] * TiMen_Pawn_att_Score;
					ei.attPoint[Us] += TiMen_Pawn_att_point;
				}
				//////////////////////////////////////////////////////////////////////////
				/// 3. 将
				if(bit_is_set(BLR,mk)){
					Bitboard tkb = rook_attacks_bb(mk,_mm_andnot_si128(
						m_or(pos.pieces(RCHE + delt), tbp),occ));
					if(have_bit(tkb,_mm_load_si128((__m128i*)TiMenBit_Pawn))){
						ei.valu += Sign[Us] * TiMen_King_att_Score;
						ei.attPoint[Us] += TiMen_King_att_point;
					}
				}
				//////////////////////////////////////////////////////////////////////////
				/// 4. 马
				for(int i = 0; i < pos.piece_count(RMA + delt); i++){
					Square s =  pos.piece_list(RMA + delt,i);	
					if(bit_is_set(BLR,s)){
						Bitboard att = ma_to_king_attacks_bb(s,occ);
						if(have_bit(att,ei.attackKingMaCan[Them])){
							ei.valu += Sign[Us] * TiMen_Ma_att_Score;
							ei.attPoint[Us] += TiMen_Ma_att_point;
						}
					}
				}
				//////////////////////////////////////////////////////////////////////////
				/// 5. 对方有炮在防守,也要扣分
				BLR = m_and(BLR, _mm_load_si128((__m128i*)(Us == WHITE ? Rank0BB : Rank9BB)));	// 去了底线兵
				//BLR = m_and(BLR,US == WHITE ? pos.pieces(BPAO) : pos.pieces(RPAO));
				if(have_bit(BLR,Us == WHITE ? pos.pieces(BPAO) : pos.pieces(RPAO))){
					ei.attPoint[Us] -= 6; // fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
				}
			}	
		} 
		//////////////////////////////////////////////////////////////////////////
		/// 这个肯定是底炮
		else{ 
			ei.attPoint[Us] += Di_Pao_att_point;   // 底炮加攻击点	
			ei.valu += Sign[Us] * make_score(12, 48);
			// 还要判断一下是不是受到对方的攻击
			if(bit_is_set(ei.attacked_by(Them),pao_sq)){
				if(bit_is_set(ei.attacked_by(Us),pao_sq)){
				}
				else{
					ei.attPoint[Us] -= 6;
				}
			}
		}
	}
}