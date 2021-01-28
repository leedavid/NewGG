#include "eval_total.h"
#pragma warning(disable : 4530)    
//////////////////////////////////////////////////////////////////////////
/// 
template<Color Us>
Score eval_zhou_and_moveless(Position& pos, EvalInfo& ei, 
	Square mid, PieceType XPiece, Square xPos){
		           // 牵制对方的棋子 牵制对方的棋子的棋子位置

	const Color Them = (Us == WHITE ? BLACK : WHITE);	

	Piece midP = pos.piece_on(mid);
	PieceType ptype = type_of(midP);	
	Score bonus = SCORE_ZERO;
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	//////////////////////////////////////////////////////////////////////////
	/// 我方可抽将的棋子 
	if(color_of(midP) == Us){ 
		//print_bb(pos.sq_attack_by_color(xPos,Them));  // 这儿还没有attack_info哇
		//if(bit_is_set(ei.attacked_by(Them),xPos)){ 
		//bool isAttXpos = m_have_bit(pos.sq_attack_by_color(xPos,Them));	

		//if(ptype == PAWN){
		//	if(Us == WHITE ? StoY(mid) <= 0x4 : StoY(mid) >= 0X5){	
		//		set_bit(ei.CanCheckPiece,mid);  // 能将军
		//	}
		//}
		//else{
		//	set_bit(ei.CanCheckPiece,mid);  // 能将军
		//}

		switch(ptype){		
		case PAWN:
			if(Us == WHITE ? StoY(mid) <= 0x4 : StoY(mid) >= 0X5){				
				//////////////////////////////////////////////////////////////////////////
				/// 再看一下是给那个在后面抽将了.
				switch(XPiece){
				case CHE:
					ei.attPoint[Us] += 6;
					//if(isAttXpos) ei.attPoint[Us] -= 3;
					bonus += make_score(16,96);
					break;
				case PAO:
					ei.attPoint[Us] += 6;
					//if(isAttXpos) ei.attPoint[Us] -= 3;
					bonus +=  make_score(64,32);
					break;
				case MA:
					ei.attPoint[Us] += 8;
					//if(isAttXpos) ei.attPoint[Us] -= 3;
					bonus +=  make_score(64,32);
					break;
				}
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 我方可抽将的马
		case MA:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个在后面抽将了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Us] += 20;
				//if(isAttXpos) ei.attPoint[Us] -= 6;
				bonus +=  make_score(64,96);
				break;
			case PAO: // fen 2b1kab2/4a4/3c5/C6P1/p4P3/2BC5/P2nN4/9/1n1K5/5A3 b - - 0 1
				ei.attPoint[Us] += 10; // fen 2b1kabr1/4a1c2/2N4c1/7Rp/4N4/9/p1P1C3P/8B/4Ap3/2nAK4 w - - 0 1
				//if(isAttXpos) ei.attPoint[Us] -= 4;
				bonus +=  make_score(64,32);
				break;
			case MA:
				ei.attPoint[Us] += 8;
				//if(isAttXpos) ei.attPoint[Us] -= 4;
				bonus +=  make_score(32,64);
				break;
			case KING:{ // fen 3a5/4k4/4N4/9/2b6/9/3r5/2N6/9/4K4 w
				bonus -=  make_score(0,64);
				ei.attPoint[Us] -= 4;
				// 如果给对方的王攻击了  one_rpawn_rk_attacks(rk);
				if (bit_is_set((Us == WHITE ? 
					one_bpawn_bk_attacks(pos.king_square(BLACK)) : one_rpawn_rk_attacks(pos.king_square(WHITE))), mid)){
					bonus -= make_score(16,128);
					ei.attPoint[Us] -= 2;
				}
					  }
					  break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 我方可抽将的炮
		case PAO:		
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个在后面抽将了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Us] += 12;
				//if(isAttXpos) ei.attPoint[Us] -= 4;
				bonus += make_score(80,32);
				break;
			case PAO:
				ei.attPoint[Us] += 8;
				//if(isAttXpos) ei.attPoint[Us] -= 3;
				bonus += make_score(64,16);
				break;
			case MA:
				ei.attPoint[Us] += 6;
				//if(isAttXpos) ei.attPoint[Us] -= 2;
				bonus += make_score(64,80);
				break;
			}
			break;		
			//////////////////////////////////////////////////////////////////////////	
			/// 我方可抽将的车
		case CHE:			
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个在后面抽将了.
			switch(XPiece){
			case CHE:
				//ei.attPoint[Us] += 0;
				break;
			case PAO:
				ei.attPoint[Us] += 12;               // 如果这个是对方的炮，就能防一些？？
				//if(isAttXpos){                       // 抽将的棋子被攻击。
				//	ei.attPoint[Us] -= 4;
					bonus += make_score(64,16);
	/*			}
				else{
					bonus += make_score(80,16);
				}*/
				// fen 1CR1ck3/9/7r1/4Cn2p/2P6/2N5r/c8/B3B4/4A4/4KA3 b - - 0 1
                //对方是炮在将一边，就要减一些哇
				//{
				//	Square yk = pos.king_square(Them);
				//	Bitboard ykatt = (Them == WHITE ? one_rpawn_rk_attacks(yk) : one_bpawn_bk_attacks(yk));
				//	Bitboard bit = m_and(BetweenBB[mid][yk],ykatt);
				//	if(m_have_bit(bit)){
				//		Square yp = pop_1st_bit(bit);
				//		if(pos.piece_on(yp) == (BPAO - COLOR_BY_SIDE_ADD[Us])){
				//			ei.attPoint[Us] -= 6;   
				//		}
				//	}
				//}
				break;
			case MA:
				ei.attPoint[Us] += 16;
				//if(isAttXpos){
				//	ei.attPoint[Us] -= 8;
				//	bonus += make_score(48,196);
				//}
				//else{
					bonus += make_score(96,168);
				//}				
				break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 我方可抽将的仕
		case SHI:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个在后面抽将了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Us] += 6;
				bonus += make_score(64,64);
				break;
			case PAO:
				ei.attPoint[Us] += 4;
				bonus += make_score(32,32);
				break;
			case MA:
				ei.attPoint[Us] += 0;
				bonus += make_score(32,32);
				break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 我方可抽将的相
		case XIANG:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个在后面抽将了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Us] += 6;
				break;
			case PAO:
				ei.attPoint[Us] += 4;	
				break;
			case MA:
				ei.attPoint[Us] += 0;
				break;
			}
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	/// 对方不能动的棋子.
	else{
		switch(ptype){
			//////////////////////////////////////////////////////////////////////////		
			/// 对方不能走的兵
		case PAWN:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个牵制了.
			//switch(type_of(pos.piece_on(s))){
			//case CHE:
			//	break;
			//case PAO:
			//	break;
			//case MA:
			//	bonus  += make_score(8,16);
			//	break;
			//}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 对方不能走的马
		case MA:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个牵制了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Them] -= 2;
				ei.attPoint[Us]   += 5;
				bonus += make_score(16,32);
				break;
			case PAO: // fen 2bk5/4a4/3ab3r/p2npNP1p/7R1/P1p6/4P4/2NC5/4A4/2c1KAB1c b - - 0 1
				ei.attPoint[Them] -= 2;
				ei.attPoint[Us]   += 8;  // fen 2b1ka3/4a4/4n3b/p2R4p/4C2n1/2P3N2/P7P/2N2A2B/1r7/c3KACc1 b - - 0 1
				if(StoY(mid) == StoY(xPos)){
					bonus += make_score(16,32);
				}
				bonus += make_score(32,64);
				// fen 2bak4/9/3ab4/p3p4/9/2p1P1pp1/P8/3AKNN1c/6C2/3A5 w - - 0 35
				break;
			case MA:
				ei.attPoint[Them] -= 2;
				ei.attPoint[Us]   += 8;
				bonus += make_score(64, 32);
				break;
			case KING: {// fen 3a5/4k4/4N4/9/2b6/9/3r5/2N6/9/4K4 w
				// 如果这个马给对方的将攻击了,就要减分哇, 1, 对方没有棋子在保护这个马,2,对方的将可以吃这个马
				Bitboard ka	= (Us == WHITE ? one_rpawn_rk_attacks(pos.king_square(Us))
					: one_bpawn_bk_attacks(pos.king_square(Us)));
				if(bit_is_set(ka,mid)){
					//if(!bit_is_set(ei.attacked_by(Them),mid)){
					bonus += make_score(16, 96);   // eval -577
					//}
				}
				else{
					bonus += make_score(8, 48);
				}
					   }
				break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 对方不能走的炮
		case PAO:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个牵制了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Them] -= 2;		
				ei.attPoint[Us]   += 2;
				bonus += make_score(16,32);
				break;
			case PAO:
				ei.attPoint[Them] -= 3;	
				ei.attPoint[Us]   += 6;
				if(StoY(xPos) == StoY(mid)){ // fen C1cak1b2/4a4/4b4/1NR3P2/9/P3p4/3n1r2p/4B4/4A4/3AK1B2 w - - 0 1
					bonus += make_score(16,64);
				}
				bonus += make_score(16,32);
				break;
			case MA: // fen 4kab2/1r2a4/2c1b2cn/p1p1N1p2/8p/2P3P2/P3P3P/4B1N2/1rnCA4/2RCKABR1 b - - 0 17
				ei.attPoint[Them] -= 2;
				ei.attPoint[Us]   += 5;
				bonus += make_score(32,64);
				break;
			}
			break;						
			//////////////////////////////////////////////////////////////////////////	
			/// 对方不能走的车
		case CHE:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个牵制了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Them] -= 3;
				ei.attPoint[Us]   += 2;
				bonus += make_score(32,32);
				break;
			case PAO: // fen 1Cra1k3/4ac3/2P1b4/1R3N3/2n5p/P8/8P/9/2p1A4/3K1AB2 b - - 0 1
				ei.attPoint[Them] -= 6;
				ei.attPoint[Us]   += 3;
				// fen 4ka3/4aP3/4b4/2p1p4/5n3/p1P2C3/7r1/B3B4/2N1A4/4KARc1 b - - 0 1
				if(pos.piece_count(BCHE - delt) == 2){
					bonus += make_score(48,128);
				}
				else{
                    bonus += make_score(64,168);
				}
				// 而且如果对方有兵在进攻，则要加分。
				// fen 1Crakab2/9/4b4/8p/9/P3pp3/1R6P/3CnA3/9/4KA3 b - - 0 1
				break;
			case MA:				
				ei.attPoint[Them] -= 3;
				ei.attPoint[Us]   += 4;
				bonus += make_score(32,64);				
				break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 对方不能走的仕
		case SHI:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个牵制了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Us] += 3;
				//bonus  += make_score(16,8);
				break;
			case PAO:
				ei.attPoint[Us] += 1;
				//bonus  += make_score(16,16);
				break;
			case MA:
				ei.attPoint[Us] += 2;
				//bonus  += make_score(16,64);
				break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////	
			/// 对方不能走的相
		case XIANG:
			//////////////////////////////////////////////////////////////////////////
			/// 再看一下是给那个牵制了.
			switch(XPiece){
			case CHE:
				ei.attPoint[Us] += 2;
				break;
			case PAO:
				ei.attPoint[Us] += 1;
				break;
			case MA:
				ei.attPoint[Us] += 2;
				break;
			}
			break;
		}
	}

	return bonus;
}






