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
///
template<Color Us>
bool isKingCanLeftRight(const Position& pos, EvalInfo& ei){
	//////////////////////////////////////////////////////////////////////////
	Square ksq = pos.king_square(Us);
	/// 将的左右棋步.
	Bitboard kcan = m_and(RankBB_A[StoY(ksq)],
		(Us == WHITE ? one_rpawn_rk_attacks(ksq) : one_bpawn_bk_attacks(ksq)));
	if(have_bit(kcan,ei.SafeBit[Us])){
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
bool isKingCanUpDown(const Position& pos, EvalInfo& ei){
	//////////////////////////////////////////////////////////////////////////
	Square ksq = pos.king_square(Us);
	/// 将的左右棋步.
	Bitboard kcan = m_and(FileBB_A[StoX(ksq)],
		(Us == WHITE ? one_rpawn_rk_attacks(ksq) : one_bpawn_bk_attacks(ksq)));
	if(have_bit(kcan,ei.SafeBit[Us])){
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
/// 空炮的攻击点数
template<Color Us>
int get_kong_pao_attack_point(const Position& pos, EvalInfo& ei){

	const Piece delt = COLOR_BY_SIDE_ADD[Us];	
	//int attackCounter = count_1s(ei.attackKingBoard[Us]);

	//fen 1rbakabr1/5R3/1cn3c2/p7p/2p1C1p2/9/P1P1N1n1P/6N1C/9/R1BAKAB2 w - - 0 13
	int k = pos.piece_count(RCHE + delt) * 128;
	ei.valu += Sign[Us] * make_score(k,k/8);

	return  (count_1s(ei.attackKingBoard[Us]) - 2) * 5
		+ (pos.piece_count(RCHE + delt) - 1) * 8       // 大子数目, 没有车要减分
		+ (pos.piece_count(RPAO + delt) -1) * 3
		+ pos.piece_count(RMA + delt) * 3;

	// 看一下可以攻击的棋子的数量.
}

//////////////////////////////////////////////////////////////////////////
/// 空_中炮底炮的评价
template<Color Us>
void eval_kong_zhong_di_pao(const Position& pos, EvalInfo& ei){
	Bitboard bkp = ei.KongPaoBB[Us];
	while(m_have_bit(bkp)){
		const Square pao = pop_1st_bit(&bkp);
		const Color Them = (Us == WHITE ? BLACK : WHITE);
		//const Square mk  = pos.king_square(Us);
		const Square yk  = pos.king_square(Them);
		//const Piece delt = COLOR_BY_SIDE_ADD[Us];	
		//////////////////////////////////////////////////////////////////////////
		/// 空中炮
		if(StoX(pao) == StoX(yk)){
			if(Us == WHITE ? StoY(pao) <= 0x2 : StoY(pao) >= 0x7){
				continue; //fen 3C2b2/3k4C/2N2n3/3P5/8P/4cn3/9/2pAB4/4A4/4K1B2 w - - 0 0
			}
			if(ABS(StoY(pao) - StoY(yk)) >= 2){
				set_bit(ei.attackKingBoard[Us],pao);
				//////////////////////////////////////////////////////////////////////////
				ei.valu += Sign[Us] * make_score(128, 32);
				/// 要判断将能不能左右移动
				if(isKingCanLeftRight<Them>(pos,ei)){
					ei.attPoint[Us] += get_kong_pao_attack_point<Us>(pos,ei)/2;				
				}
				else{
					ei.attPoint[Us] += get_kong_pao_attack_point<Us>(pos,ei) ;
				}				 
			}
		}
		//////////////////////////////////////////////////////////////////////////
		/// 空底炮
		else{
			if(ABS(StoX(pao) - 0x4) <= 1){
				continue;
			}
			if(ABS(StoX(pao) - StoX(yk)) >= 2){		
				ei.valu += Sign[Us] * make_score(32, 0);
				if(isKingCanUpDown<Them>(pos,ei)){
					ei.attPoint[Us] +=  get_kong_pao_attack_point<Us>(pos,ei)/2 - 2; 
				}
				else{
					ei.attPoint[Us] +=  get_kong_pao_attack_point<Us>(pos,ei) - 4;   //
				}
			}
			//还要判断一下是不是受到对方的攻击
			if(bit_is_set(ei.attacked_by(Them),pao)){
				ei.attPoint[Us] -= Kong_Di_Pao_att_By_Other;
			}
		}
	}
}