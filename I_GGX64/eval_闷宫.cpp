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
/// 闷宫威胁的评估
//void eval_men_gong_threat(const Position& pos, EvalInfo& ei){
//
//#define  PAO_CAN_MEN_GONG_W_XIANG 4
//#define  PAO_CAN_MEN_GONG_O_XIANG 3
//
//	if(pos.piece_count(RSHI) == 2 && pos.piece_count(BPAO) != 0){
//		if(pos.piece_on(Square(0x4c)) == RSHI && pos.piece_on(Square(0x55)) == RKING){
//			if(pos.piece_on(Square(0x54)) == RSHI){
//				// 有二种情况, 1. 如果有相在,则要判断三七路是不是有炮
//				if(pos.piece_on(Square(0x53)) == RXIANG){
//					Bitboard pao = _mm_andnot_si128(UpBB[0x3],m_and(FileBB_A[0x2],pos.pieces(BPAO)));
//					ei.attackKingBoard[BLACK] = m_or(ei.attackKingBoard[BLACK],pao);
//					ei.attPoint[BLACK] += PAO_CAN_MEN_GONG_W_XIANG * count_1s(pao);
//				}
//				// 2. 如果没有相在, 则要判断<>=三七路是不是有对方的炮
//				else{
//					Bitboard pao = m_and(LeftBB[0x03],pos.pieces(BPAO));
//					ei.attackKingBoard[BLACK] = m_or(ei.attackKingBoard[BLACK],pao);
//					int p = count_1s(pao);
//					ei.attPoint[BLACK] += PAO_CAN_MEN_GONG_O_XIANG * p;
//					ei.valu -= make_score(16,32);
//				}
//			}
//			else if(pos.piece_on(Square(0x56)) == RSHI){
//				// 有二种情况, 1. 如果有相在,则要判断三七路是不是有炮
//				if(pos.piece_on(Square(0x57)) == RXIANG){
//					Bitboard pao = _mm_andnot_si128(UpBB[0x3],m_and(FileBB_A[0x6],pos.pieces(BPAO)));
//					ei.attackKingBoard[BLACK] = m_or(ei.attackKingBoard[BLACK],pao);
//					ei.attPoint[BLACK] += PAO_CAN_MEN_GONG_W_XIANG * count_1s(pao);
//				}
//				// 2. 如果没有相在, 则要判断<>=三七路是不是有对方的炮
//				else{
//					Bitboard pao = m_and(RightBB[0x05],pos.pieces(BPAO));
//					ei.attackKingBoard[BLACK] = m_or(ei.attackKingBoard[BLACK],pao);
//					int p = count_1s(pao);
//					ei.attPoint[BLACK] += PAO_CAN_MEN_GONG_O_XIANG * p;
//					ei.valu -= make_score(16,32);
//				}
//			}
//		}
//	}
//	if(pos.piece_count(BSHI) == 2  && pos.piece_count(RPAO) != 0){
//		if(pos.piece_on(Square(0x0d)) == BSHI && pos.piece_on(Square(0x04)) == BKING){
//			if(pos.piece_on(Square(0x03)) == BSHI){
//				// 有二种情况, 1. 如果有相在,则要判断三七路是不是有炮
//				if(pos.piece_on(Square(0x02)) == BXIANG){
//					Bitboard pao = _mm_andnot_si128(LowBB[0x6],m_and(FileBB_A[0x2],pos.pieces(RPAO)));
//					ei.attackKingBoard[WHITE] = m_or(ei.attackKingBoard[WHITE],pao);
//					ei.attPoint[WHITE] += PAO_CAN_MEN_GONG_W_XIANG * count_1s(pao);
//				}
//				// 2. 如果没有相在, 则要判断<>=三七路是不是有对方的炮
//				else{
//					Bitboard pao = m_and(LeftBB[0x03],pos.pieces(RPAO));
//					ei.attackKingBoard[WHITE] = m_or(ei.attackKingBoard[WHITE],pao);
//					int p = count_1s(pao);
//					ei.attPoint[WHITE] += PAO_CAN_MEN_GONG_O_XIANG * p;
//					ei.valu += make_score(16,32);
//				}
//			}
//			else if(pos.piece_on(Square(0x05)) == BSHI){
//				// 有二种情况, 1. 如果有相在,则要判断三七路是不是有炮
//				if(pos.piece_on(Square(0x06)) == BXIANG){
//					Bitboard pao = _mm_andnot_si128(LowBB[0x6],m_and(FileBB_A[0x6],pos.pieces(RPAO)));
//					ei.attackKingBoard[WHITE] = m_or(ei.attackKingBoard[WHITE],pao);
//					ei.attPoint[WHITE] += PAO_CAN_MEN_GONG_W_XIANG * count_1s(pao);
//				}
//				// 2. 如果没有相在, 则要判断<>=三七路是不是有对方的炮
//				else{ //fen 3ak4/3na4/4br3/9/7Np/P3P2R1/3p4P/1C7/4A4/2BAK3c b - - 0 35
//					Bitboard pao = m_and(RightBB[0x05],pos.pieces(RPAO));
//					ei.attackKingBoard[WHITE] = m_or(ei.attackKingBoard[WHITE],pao);
//					int p = count_1s(pao);
//					ei.attPoint[WHITE] += PAO_CAN_MEN_GONG_O_XIANG * p;
//					ei.valu += make_score(16,32);
//				}
//			}
//		}
//	}
//}
