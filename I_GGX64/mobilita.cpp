#include "chess.h"
 
//#include "preGen.h"
//#include "valore.h"

#ifdef USE_STOCK_FISH_FILE
#else

void   // 移动性评估, 主要是加入将的攻击,包括对方的将在攻击我的将.
Mobility (const typePOS *POSITION)
{
	Bitboard A;
	Bitboard T;
	Bitboard p;
	Bitboard bit_rk;
	Bitboard bit_bk;
	Bitboard occ = POSITION->byWhiteBlack;
    int i;
	int s;
	int leg;
	int rk = RKpos();
	int bk = BKpos();
	bit_rk = SetMaskBB[rk];
	bit_bk = SetMaskBB[bk];	

	POSITION->DYN->white_xray = _mm_setzero_si128();
	POSITION->DYN->black_xray = _mm_setzero_si128();

	POSITION->DYN->black_pao_null = _mm_setzero_si128();
	POSITION->DYN->white_pao_null = _mm_setzero_si128();

	POSITION->DYN->attack_white = one_rpawn_rk_attacks(rk);   //
	POSITION->DYN->attack_black = one_bpawn_bk_attacks(bk);   // 

	POSITION->DYN->black_king_check = _mm_setzero_si128();
	POSITION->DYN->white_king_check = _mm_setzero_si128();
	//if(StoX(rk) == StoX(bk)){         // 有可能是对将,要去了.		
	//	T = m_and(BetweenBB[rk][bk],occ);
	//	if(m128_is_have_bit(T)){
	//		if(count_1s(T) == 1){     // 交叉点上的棋子不能走哇
	//			// *********************** 暂时不放了
	//		}
	//	}
	//	else{
	//		POSITION->DYN->black_king_check = bit_rk;  // 对将
	//		POSITION->DYN->white_king_check = bit_bk;
	//		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,
	//			bit_bk);
	//		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,
	//			bit_rk);
	//	}
	//}
	// 红将
	A = rook_attacks_bb(rk,occ);  // 红将的车攻击位棋盘	
	if(m128_is_have_bit(m_and(A,bit_bk))){ // 看一下是不是对将了
		POSITION->DYN->black_king_check = bit_rk;  // 对将
		POSITION->DYN->white_king_check = bit_bk;
	}
	POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,
		m_and(A,KingKingAttBB[bk]));	

	// 再看一下是不是有黑炮，因为可以叠将，叠将也能强大哇
	A = m_and(A,bitboard_black_pao);
	while(m128_is_have_bit(A)){
		int pao = pop_1st_bit(&A);
		POSITION->DYN->black_pao_null = m128_bb_or_bb(POSITION->DYN->black_pao_null,
			BetweenBB[pao][rk]);
	}

	// 黑将
	A = rook_attacks_bb(bk,occ);
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,
		m_and(A,KingKingAttBB[rk]));

	// 再看一下是不是有红炮，因为可以叠将，叠将也能强大哇
	A = m_and(A,bitboard_white_pao);
	while(m128_is_have_bit(A)){
		int pao = pop_1st_bit(&A);
		POSITION->DYN->white_pao_null = m128_bb_or_bb(POSITION->DYN->white_pao_null,
			BetweenBB[pao][bk]);
	}

	// 车
	for(i = 0; i < RChe_num(); i++){
		s = S90_from_piecelist(POSITION,RCHE,i);
        A = rook_attacks_bb(s,occ);
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A);
		if(have_bit(A,bit_bk)){
			set_bit(POSITION->DYN->black_king_check,s);        // 在将军
		}
		else if(have_bit(bit_bk,ChePseudoMask_FR[s])){    // 对方的王在一条线上.
		    T = m_and(rook_attacks_bb(bk,occ),A);
			POSITION->DYN->white_xray = m128_bb_or_bb(POSITION->DYN->white_xray,T);
			if(m128_is_have_bit(T)){
				xray_white_list[pop_1st_bit(&T)] = s;   // this is only use in see
			}
		}
	}
	// 炮
	for(i = 0; i < RPao_num(); i++){
		s = S90_from_piecelist(POSITION,RPAO,i);
		A = pao_eat_attacks_bb(s,occ);  
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 
		if(have_bit(A,bit_bk)){
			set_bit(POSITION->DYN->black_king_check,s);      // 在将军
		}
		else if(have_bit(bit_bk,ChePseudoMask_FR[s])){  // 对方的王在一条线上.
			T = m_and(BetweenBB[bk][s],occ);
		    if(count_1s(T) == 2){     // 交叉点上的棋子不能走哇
			    POSITION->DYN->white_xray = m128_bb_or_bb(POSITION->DYN->white_xray,T);
				while(m128_is_have_bit(T)){                 // 这儿有二个棋子
					xray_white_list[pop_1st_bit(&T)] = s;   // this is only use in see
				}
			}
		}
	}
	// 马
	for(i = 0; i < RMa_num(); i++){
		s = S90_from_piecelist(POSITION,RMA,i);
        A =  ma_to_king_attacks_bb(s,occ);
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 
		if(have_bit(A,bit_bk)){
			set_bit(POSITION->DYN->black_king_check,s);      // 在将军
		}
		else{ // 得到马腿上的棋子.
			if(have_bit(Ma_Pseudo_Att[s],bit_bk)){
			    leg = maleg(s,bk);
				set_bit(POSITION->DYN->white_xray,leg);
				xray_white_list[leg] = s;
			}
		}
	}
	// 兵
	p = bitboard_white_pawn;
	A = p;
	A = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),A);
	// 向前一步.
	m_Rsf(A,9);
	POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A);
	A = m_and(A,bit_bk);
	m_Lsf(A,9);
	POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,A);
    // 过河兵	
	if(have_bit(p,_mm_load_si128((__m128i*)RpawnOverBB))){
		p = m_and(p,_mm_load_si128((__m128i*)RpawnOverBB));
		//
		A = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
		m_Rsf(A,1);                   //所有红兵向左一步
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A);
	    A = m_and(A,bit_bk);
		m_Lsf(A,1);
	    POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,A);
		//
		A = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
		m_Lsf(A,1);                   //所有红兵向右一步
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A);
	    A = m_and(A,bit_bk);
		m_Rsf(A,1);
	    POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,A);
	}
	// 相
	for(i = 0; i < RXiang_num(); i++){
		s = S90_from_piecelist(POSITION,RXIANG,i);
		POSITION->DYN->attack_white 
			= m128_bb_or_bb(POSITION->DYN->attack_white,xiang_attacks_bb(s,occ)); 
	}
	// 仕
	for(i = 0; i < RShi_num(); i++){
		s = S90_from_piecelist(POSITION,RSHI,i);
		POSITION->DYN->attack_white 
			= m128_bb_or_bb(POSITION->DYN->attack_white,shi_attacks(s)); 
	}
	// black 车
	for(i = 0; i < BChe_num(); i++){
		s = S90_from_piecelist(POSITION,BCHE,i);
        A = rook_attacks_bb(s,occ);
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A);
		if(have_bit(A,bit_rk)){
			set_bit(POSITION->DYN->white_king_check,s);        // 在将军
		}
		else if(have_bit(bit_rk,ChePseudoMask_FR[s])){    // 对方的王在一条线上.
		    T = m_and(rook_attacks_bb(rk,occ),A);
			POSITION->DYN->black_xray = m128_bb_or_bb(POSITION->DYN->black_xray,T);
			if(m128_is_have_bit(T)){
				xray_black_list[pop_1st_bit(&T)] = s;   // this is only use in see
			}
		}
	}
	// 炮
	for(i = 0; i < BPao_num(); i++){
		s = S90_from_piecelist(POSITION,BPAO,i);
		A = pao_eat_attacks_bb(s,occ);  
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
		if(have_bit(A,bit_rk)){
			set_bit(POSITION->DYN->white_king_check,s);      // 在将军
		}
		else if(have_bit(bit_rk,ChePseudoMask_FR[s])){  // 对方的王在一条线上.
			T = m_and(BetweenBB[rk][s],occ);
		    if(count_1s(T) == 2){     // 交叉点上的棋子不能走哇
			    POSITION->DYN->black_xray = m128_bb_or_bb(POSITION->DYN->black_xray,T);
				while(m128_is_have_bit(T)){                 // 这儿有二个棋子
					xray_black_list[pop_1st_bit(&T)] = s;   // this is only use in see
				}
			}
		}
	}
	// 马
	for(i = 0; i < BMa_num(); i++){
		s = S90_from_piecelist(POSITION,BMA,i);
        A =  ma_to_king_attacks_bb(s,occ);
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
		if(have_bit(A,bit_rk)){
			set_bit(POSITION->DYN->white_king_check,s);      // 在将军
		}
		else{ // 得到马腿上的棋子.
			if(have_bit(Ma_Pseudo_Att[s],bit_rk)){
			    leg = maleg(s,rk);
				set_bit(POSITION->DYN->black_xray,leg);
				xray_black_list[leg] = s;
			}
		}
	}
	// black 兵
	p = bitboard_black_pawn;
	A = p;
	// 向前一步.
	A = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),A);
	m_Lsf(A,9);
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A);
	A = m_and(A,bit_rk);
	m_Rsf(A,9);
	POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,A);
    // 过河兵	
	if(have_bit(p,_mm_load_si128((__m128i*)BpawnOverBB))){
		p = m_and(p,_mm_load_si128((__m128i*)BpawnOverBB));
		//
		A = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
		m_Rsf(A,1);                   //所有红兵向左一步
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A);
	    A = m_and(A,bit_rk);
		m_Lsf(A,1);
	    POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,A);
		//
		A = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
		m_Lsf(A,1);                   //所有红兵向右一步
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A);
	    A = m_and(A,bit_rk);
		m_Rsf(A,1);
	    POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,A);
	}
	// black 相
	for(i = 0; i < BXiang_num(); i++){
		s = S90_from_piecelist(POSITION,BXIANG,i);
		POSITION->DYN->attack_black 
			= m128_bb_or_bb(POSITION->DYN->attack_black,xiang_attacks_bb(s,occ)); 
	}
	// black 仕
	for(i = 0; i < BShi_num(); i++){
		s = S90_from_piecelist(POSITION,BSHI,i);
		POSITION->DYN->attack_black 
			= m128_bb_or_bb(POSITION->DYN->attack_black,shi_attacks(s)); 
	}

#include "get_check_history.h"
}

#endif
