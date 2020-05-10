#include "eval_total.h"

// fen 3ak4/3Pa4/1N2b1N2/8p/1P4b2/5p3/3r1n2n/R7B/4AK3/3A2B2 b - - 0 1
const int attControlbyMa[5]   = {0, 4,  8, 12,  16};


const Score Point_ma_Att_Score[] = {           // 棋子保护自己棋子的得分．
	Score(0),
	//  将	     仕	      相        马         车         炮	        兵   
	SMG(0,0),SMG(4,8),SMG(4,16),SMG(8,12),SMG(16,8), SMG(16,16),SMG(4,8),
	Score(0),
	//  将	     仕	      相        马         车         炮	        兵   
	SMG(0,0),SMG(4,8),SMG(4,16),SMG(8,12),SMG(16,8), SMG(16,16),SMG(4,8),
};

const Score Point_Pao_Att_Score[] = {          // 棋子保护自己棋子的得分．
	Score(0),
	//  将	     仕	      相        马         车         炮	        兵   
	SMG(0,0),SMG(8,8),SMG(8,4),SMG(16,16),SMG(16,12), SMG(8,12),SMG(4,16),
	Score(0),
	//  将	     仕	      相        马         车         炮	        兵   
	SMG(0,0),SMG(8,8),SMG(8,4),SMG(16,16),SMG(16,12), SMG(8,12),SMG(4,16),
};






//////////////////////////////////////////////////////////////////////////
/// 第一将评估一下不包括将的其它的棋子.
template<Color Us>
Score evaluate_pieces_no_include_king_first(Position& pos, EvalInfo& ei){

	const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Bitboard occ = pos.occupied_squares();
	Square yk = pos.king_square(Them);
	//Square mk = pos.king_square(Us);
	Score bonus = SCORE_ZERO;

	//////////////////////////////////////////////////////////////////////////	
	// Do not include in mobility squares protected by enemy pawns or occupied by our pieces
	// const Bitboard mobilityArea = ~(ei.attackedBy[Them][PAWN] | pos.pieces(Us));
	const Bitboard nmobilityArea = m_or(ei.pi->pawnshiXiang_attacks(Them),
		 pos.pieces_of_color(Us));  // 我方不可走动的棋格，受对方的兵，仕，相攻击的棋格。

	//////////////////////////////////////////////////////////////////////////
	// 先评价一下马	
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0; i < pos.piece_count(RMA + delt); i++){
		Square s =  pos.piece_list(RMA + delt,i);

		Bitboard A = pos.ma_to_king_attacks_bb(s);
		//int mob = 0;
		//Bitboard bmob = _mm_andnot_si128(nmobilityArea,m_and(A,Ma_good_mask[Us]));
		//mob += (int)count_1s(bmob);

		ei.attackedBy[RMA + delt] = m_or(ei.attackedBy[RMA + delt],A);

		//////////////////////////////////////////////////////////////////////////		
		if(bit_is_set(Ma_Pseudo_Att[yk],s)){		// 马有牵制对方的棋子	
			if(bit_is_set(A,yk)){ // 如果这个马在将军
			}
			else{
				Square leg = maleg(s,yk);
				set_bit(ei.xray_bit[Us],leg);
				bonus += eval_zhou_and_moveless<Us>(pos,ei,leg,MA,s);				
				set_bit(ei.attackKingBoard[Us],s);
			}
		}
		//////////////////////////////////////////////////////////////////////////		
		// 再看一下马能不能将军
		if(Us == WHITE ? StoY(s) <= 0x4 : StoY(s) >= 0x5){
			// fen 4ka3/4a4/5cN2/1R6p/3R2b2/9/nNP5r/4c3B/1r2A4/2BK1A3 b - - 0 1	// 去了自己的棋子
			Bitboard ckatt = m_and(A,pos.king_to_ma_attacks_bb(yk));
			if(m_have_bit(ckatt)){
				set_bit(ei.attackKingBoard[Us],s);
				ckatt = _mm_andnot_si128(pos.pieces_of_color(Us),ckatt);

				if(m_have_bit(ckatt)){
					ei.attPoint[Us] +=  3;   // MaCanCHeckPoint;
					if(StoX(s) == 0x4){
						// fen 1c2kabC1/4a4/4Nr3/2P6/4R3p/9/4P3P/9/2c1K4/9 w - - 0 1
						ei.attPoint[Us] += 3; // 马在中间要加一些哇
					}
				}
			}
			// fen 3k1ab2/2N6/3ab4/p7p/9/P1p6/3r5/3C5/3CAK3/1c1A5 b 又能将，又能控制对方的将
			// 3. 马攻击到对方将的走步, 在KingSafe已有表达了. 
			if(m_have_bit(m_and(A,MaKingAttackZone[yk]))){
				set_bit(ei.attackKingBoard[Us],s);//sb_attboard_num(ei.attackKingBoard[Us],s,ei.att_ma_num[Us]);  
				Bitboard bb = m_and(A,
					(Us == WHITE ? one_bpawn_bk_attacks(yk) : one_rpawn_rk_attacks(yk)) );	
				if(m_have_bit(bb)){
					ei.attPoint[Us] += attControlbyMa[count_1s(bb)];
					//if(mob == 0) mob ++;
					// fen 2bk1ab2/R1N1a2r1/6n2/p3p1p2/9/6P1p/P8/4B4/4A4/1N2KAB1c w - - 0 1
					// 对方的将不能进去。
					if(StoX(yk) != 0x4 && bit_is_set(A,XYtoS(0x4,StoY(yk)))){
						bonus += make_score(64,16);
					}
				}
			}
			// 4. 马在攻击将的位置，也要算能进攻哇
			else if(bit_is_set(MaPosAttackKing[yk],s)){
				set_bit(ei.attackKingBoard[Us],s);		
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////	
	// 车	
	//////////////////////////////////////////////////////////////////////////	
	for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
		Square s =  pos.piece_list(RCHE + delt,i);

		// Bitboard tb = _mm_andnot_si128(pos.pieces(RCHE + delt),occ);  // 车可连接
		Bitboard A // 1. 车的攻击,要传递一下,因为二车可连线攻击.
			=  pos.Rook_attacks_bb(s);  // 车就不要转递了。

		//////////////////////////////////////////////////////////////////////////
		// moblity
		Bitboard bmob = _mm_andnot_si128(nmobilityArea,A);
		int mobr = (int)count_1s(RankBB_A[StoY(s)],bmob);
		int mobf = (int)count_1s(FileBB_A[StoX(s)],bmob);
		bonus += (f_CheMove[mobf] + r_CheMove[mobr]);
		//bonus += FR_CheMob[count_1s(bmob)];

		//////////////////////////////////////////////////////////////////////////
		// 
		ei.attackedBy[RCHE + delt] = m_or(ei.attackedBy[RCHE + delt],A);

		// 车将在一线
		if(bit_is_set(ChePseudoMask_FR[yk],s)){ //const Square yk  = pos.king_square(Them)
			Bitboard bet = m_and(BetweenBB[s][yk],occ);
			switch(count_1s(bet)){
			case 0:   // 这个车正在将军
				set_bit(ei.attackKingBoard[Us],s);
				break;
			case 1: { //  这个车在牵制了
				//////////////////////////////////////////////////////////////////////////
				// 保存一下XBIT
				Square x = pop_1st_bit_sq(bet);
				bonus += eval_zhou_and_moveless<Us>(pos,ei,x,CHE,s);
				set_bit(ei.xray_bit[Us],x);
				set_bit(ei.attackKingBoard[Us],s);
				//set_bit(ei.keypont[Us],x);
					}
					break;
			default:
				break;
			}
		}

		// 看一下车是不是开放了
		//Bitboard OpenBB = (Us == WHITE ? 
		//	UpBB[StoY(pos.king_square(Them)) + CHE_OPEN_SUB_LINE] 
		//: LowBB[StoY(pos.king_square(Them)) - CHE_OPEN_SUB_LINE]);
		//print_bb(OpenBB);
		Bitboard OpenBB = Us == WHITE ? UpBB[0x6] : LowBB[0x3];
		if(have_bit(A,OpenBB)){
			ei.attPoint[Us] += CheOpenAtt; // 车开放要加攻击点哇
			//sb_attboard_num(ei.attackKingBoard[Us],s,ei.att_che_num[Us]);
			set_bit(ei.attackKingBoard[Us],s);   
			bonus += make_score(16,32);          // 有车开放要加分 // fen 1r2kab2/4a1n2/4b2C1/p3p3p/2pn2c2/4P2N1/PcP5P/2N1C4/9/1RBAKAB2 w - - 0 1
		}

		// 车能自由将
		if(have_bit(A,ChePseudoMask_FR[yk])){
			// fen 8C/6N2/3k5/4p4/2b6/p8/2c2r3/2RAB3B/7n1/3K5 w - - 0 1
			// 得去了我方的棋子
			Bitboard ckatt = _mm_andnot_si128(pos.pieces_of_color(Us),A);
			ckatt = m_and(ckatt,pos.Rook_attacks_bb(yk));
			if(m_have_bit(ckatt)){
				ei.attPoint[Us] += 3;   // 红车能直接将
				//if(m_have_bit(_mm_andnot_si128(ei.attacked_by(Them),ckatt))){
				//	ei.attPoint[Us] += 3;   // 看一下是不是安全的将
				//}
				// 看一下是不是将军一线了,
				//ei.keypont[Us] = m_or(ei.keypont[Us],ckatt);
				// fen 4ka3/4aR3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
				if(bit_is_set(A,pos.king_square(Us)) && StoX(s) == StoX(pos.king_square(Us))){ 
					ei.attPoint[Us] += 3;
				}
				//如果将不在原位，或没有二个仕 
				// fen 5kb2/4a4/3ab4/9/5R3/2r6/5r3/9/4A4/2B1KA3 b - - 0 0</
				//这个因为是在将军，	
				if((Us == WHITE ? 0x04 : 0x55) != yk || pos.piece_count((Us == WHITE ? BSHI : RSHI)) == 0){   // 将不在原位，或没有仕了．
					//while(m_have_bit(ckatt)){   
					//	Square ckq = pop_1st_bit(ckatt);						
					//	//if(pos.see(s,ckq) > 0){ // fen 2bakab2/9/n8/p3C4/2P5p/5N3/P3P1n1P/2N2A3/3K4R/3A3rc b - - 0 1
					//	if(!bit_is_set(ei.attacked_by(Them),ckq)){
					//		ei.attPoint[Us] += 6;
					//	}
					//	else{
					//		ei.attPoint[Us] += 3;
					//	}
					//}
					 bonus += make_score(32, 32);
					ei.attPoint[Us] += 3;
				} // 二车错杀的情况	
			}
		}

		// 如果对方的仕为0，则要
		// fen 2b1ka3/4a4/4b4/p1n2R2p/1P4pR1/P7P/5NP2/r3B4/3NK4/2r6 w - - 0 1
		if(pos.piece_count(BSHI - delt) == 0 && i == 1){
			if(count_1s(ei.attackKingBoard[Us],pos.pieces(RCHE + delt)) == 2){
			   bonus += make_score(96, 168);
			   ei.attPoint[Us] += 4;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////
	// 先评价一下炮, 因为要算 PaoNull,所以得放在车，马后面。	
	//////////////////////////////////////////////////////////////////////////	

	for(int i = 0; i < pos.piece_count(RPAO + delt); i++){
		Square s =  pos.piece_list(RPAO + delt,i);

		Bitboard A = pos.Pao_Eat_bb(s);	
		ei.attackedBy[RPAO + delt] = m_or(ei.attackedBy[RPAO + delt],A);		

		// 炮将在一线
		if(bit_is_set(ChePseudoMask_FR[yk],s)){ //const Square yk  = pos.king_square(Them);
			Bitboard bet = m_and(BetweenBB[s][yk],occ);
			switch(count_1s(bet)){
			case 0:        // 空炮
				//            专门评价一下空炮
				//Score eval_null_pao(Position& pos, EvalInfo& ei, Square mpao, Square yk, Bitboard& A){
				//set_bit(ei.keypont[Us],s);	
				set_bit(ei.attackKingBoard[Us],s);
				set_bit(ei.KongPao[Us],s);
				break;
			case 1:        // 这个炮正在将军
				//set_bit(ei.keypont[Us],s);	
				set_bit(ei.attackKingBoard[Us],s);
				break;
			case 2:{        // 这个是中炮，或底炮
				//////////////////////////////////////////////////////////////////////////
				// 保存一下XBIT
				ei.xray_bit[Us] = m_or(ei.xray_bit[Us],bet);
				Bitboard b = m_and(bet,A);
				Square p2 = pop_1st_bit_sq(b);   ASSERT(p2 > 0 && p2 < 90);
				clear_bit(bet,p2);
				Square p1 = pop_1st_bit_sq(bet);

				// 如果p1 == ma 或 che, 还要减分。
				// fen 2r1kar2/4a4/1c2bc3/4p3p/3R2pR1/1N7/4P1P1P/2C1BA3/2n2N3/2BA1K3 w - - 0 1			
				if(pos.piece_on(p2) == BMA - delt){
					bonus += make_score(32,64);
				}
				else if(pos.piece_on(p2) == BCHE - delt){
					bonus += make_score(64,96);
				}

				// 这儿再加上一个中炮的评价。
				//set_bit(ei.keypont[Us],s);	  // 防守的关键点	
				//set_bit(ei.keypont[Us],p2);
	
				bonus += eval_zhou_and_moveless<Us>(pos,ei,p1,PAO,s);
				bonus += eval_zhou_and_moveless<Us>(pos,ei,p2,PAO,s);
				set_bit(ei.attackKingBoard[Us],s);

				ei.attPoint[Us] += 8;   // 中炮，底炮总要加一些
				   }
				break;     
			case 3:        // 这个炮能吃子将   
				set_bit(ei.attackKingBoard[Us],s);
				ei.attPoint[Us] += 4;
				break;
			default: 
				break;
			}
			// fen 3k1ab2/2N6/3ab4/p7p/9/P1p6/3r5/3C5/3CA4/1c1A1K3 w - - 0 1 马炮联合
			//if(StoX(s) == StoX(yk) && StoX(yk) != 0x4){
			//	if(bit_is_set(ei.attacked_by(RMA + delt),XYtoS(0x4,StoY(yk)))){
			//		ei.attPoint[Us] += 4;
			//	}
			//}
		}
		//////////////////////////////////////////////////////////////////////////		
		// 4. 有炮加入了进攻.要不在宫内哇
		else if(bit_is_set(PaoCanAttKing[yk],s)){ // fen 2b2anC1/3kaP3/2P1b4/p7p/8c/3rC4/P3R4/4B4/4AK3/2BA3c1 r	
			if(Us == WHITE ? (StoY(s) <= 0x2) : (StoY(s) >= 0x7)){ // 炮在对方的上三线内. 
				set_bit(ei.attackKingBoard[Us],s);
				//set_bit(ei.keypont[Us],s);		// 如果能攻击到炮，也算
				// fen 1C3ab2/2N1k4/3ab3n/p1R6/9/5p3/P3P1P2/B4A3/3K4c/1r7 w - - 0 1
			}
			else{ // 炮在中三线。且与对方的将相差一条线。
				// fen 2bak4/2n1c4/4ba3/C3p1N2/1P3N3/4P4/8p/2C1B4/4A1n2/2BA1K2c w - - 0 1
				// 这个黑炮没有加入进攻哇，如果炮打着自己的棋子，且棋了在家里，就不算进攻
				Bitboard K = Us == WHITE ? UpBB[0x3] : LowBB[0x6];
				if (have_bit(A, K)){
					set_bit(ei.attackKingBoard[Us], s);
				}
			}			
		}
		// fen 2Rak1b2/9/2n2C3/p3p3p/9/1N7/PcrNP3P/1C7/c2KA4/5A3 w - - 0 1 这个不算进攻
		// 如果炮能吃到对方的子，且在对方的将线上。
		//if(have_bit(A,RankBB_A[StoY(yk)])){
		//	// fen 2bak4/2n1c4/4ba3/C3p1N2/1P3N3/4P4/8p/2C1B4/4A1n2/2BA1K2c w - - 0 1
		//	set_bit(ei.attackKingBoard[Us],s);
		//}

		// 还有闷宫的牵制  e->_PawnInfo |= PEV_Rshi_L_MenGong;
		if(Us == WHITE){
			if(ei.pi->getExtraPawnInfo() & PEV_Bshi_MenGong ){
				if (StoX(s) <= 0x2 && pos.piece_on(Square(0x03)) == BSHI){
					bonus += make_score(32,16); //set_bit(ei.attackKingBoard[Us],s);
				}
				else if (StoX(s) >= 0x6 && pos.piece_on(Square(0x05)) == BSHI){
					bonus += make_score(32,16); // set_bit(ei.attackKingBoard[Us],s); // fen 1C2ka3/4a4/b3b4/2R6/9/5pC2/1p3r3/4BA3/2NnAK2c/2B6 w - - 0 1
				}
			}
		}
		else{
			if(ei.pi->getExtraPawnInfo() & PEV_Rshi_MenGong){
				if (StoX(s) <= 0x2 && pos.piece_on(Square(0x54)) == RSHI){
					//set_bit(ei.attackKingBoard[Us],s);
					bonus += make_score(32,16);
				}
				else if (StoX(s) >= 0x6 && pos.piece_on(Square(0x56)) == RSHI){
					bonus += make_score(32,16); //set_bit(ei.attackKingBoard[Us],s);
				}
			}
		}
	}

	
	return bonus;
}

template<Color Us>
Score evaluate_ma_mob(Position& pos, EvalInfo& ie){

	const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Score bonus = SCORE_ZERO;	

	for(int i = 0; i < pos.piece_count(RMA + delt); i++){
		Square s =  pos.piece_list(RMA + delt,i);
		// Bitboard E = pos.ma_to_king_attacks_bb(s);
		Bitboard A = m_and(pos.ma_to_king_attacks_bb(s), BitMaGooDMove[Us]);

		// fen 4kab2/4a4/4b4/6PP1/p4c3/4n1P2/2p6/4B4/N3A1C2/2BAK4 w - - 0 1
		if (Us == WHITE ? StoY(s) >= 8 : StoY(s) <= 1){
			// fen 4k4/4a4/4ba3/4cN1P1/2b6/2N3Bn1/7C1/2n2A3/9/3AK4 w - - 0 1
			if (have_bit(A, ie.pi->pawnshiXiang_attacks(Them))){ // 马的走步受到对方兵仕相的攻击
				Bitboard B = _mm_andnot_si128(pos.pieces_of_color(Us), A);
				B = _mm_andnot_si128(ie.pi->pawnshiXiang_attacks(Them), B); // fen 1rbnkab2/4a4/3cc4/pCP3R2/8p/4C4/P3P1P1n/2N1B4/4A4/3K1AB2 b - - 0 1
				if (!m_have_bit(B)){
					bonus -= make_score(32, 108);
				}
			}
		}

		A = _mm_andnot_si128(ie.attacked_by(Them), A);  // 去了对方的攻击棋格。

		int mob = (int)count_1s(A);		

		if(bit_is_set(ie.pi->pawnshiXiang_attacks(Us),s)){   // 被自己的仕相兵保护了
			bonus += Point_MaMob[mob]/2;
		}
		else{
			bonus += Point_MaMob[mob];
			if(bit_is_set(ie.attacked_by(Them),s)){ // 马还在受攻击
				bonus -= make_score(16,48);
			}
		}
	}

	return bonus;
}
