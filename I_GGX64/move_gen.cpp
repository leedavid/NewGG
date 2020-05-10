#ifndef BUILD_mossa_gen
#define BUILD_mossa_gen

#include "chess.h" 



#include "preGen.h"
#include "iniz_gen.h"  // 棋子的吃子分

#define flag_check 0x8000  // #define pietra_scacco 0x8000 将军的标志

#ifdef MULTIPLE_HISTORY
#define LIST_ADD_noncap(L,from,to,piece,sca) \
	{(L++)->move =  MOVE_FromTo(from,to)  \
	| (HISTORY[POSITION->cpu][piece][to] << 16)\
	| (bit_is_set(sca,to) ? flag_check : 0); }
// 将仕相不可能将军
#define LIST_ADD_noncap_no(L,from,to,piece) \
	{(L++)->move =  MOVE_FromTo(from,to)  \
	| (HISTORY[POSITION->cpu][piece][to] << 16);}
#else
	#define MoveAdd(L, x, pi, to, check) \
	  { (L++)->move = (x) | ( (SqSet[to] & (check) ) ? FLAG_CHECK : 0) \
	  | ( HISTORY[pi][to] << 16); }
#endif


#define LIST_ADD_cap(L,from,to,piece) \
	{ (L++)->move = MOVE_FromTo(from,to) | CAPTURE_VALU[piece][PB90(to)]; }


#ifdef MULTIPLE_POS_GAIN
//teest
#define GAIN_ADD(L,from,to,piece,ai) \
		{ mossa =  MOVE_FromTo(from,to); \
		v = ( (int) MAX_POSITIONAL_GAIN[POSITION->cpu][piece][(mossa) & GAIN_MASK]); \
		if (v >= av) (L++)->move = (mossa) | (v << 16); }

//#define GAIN_ADD(L,from,to,piece,ai) \
//		{ mossa =  MOVE_FromTo(from,to); \
//		v = ( (int) MAX_POSITIONAL_GAIN[POSITION->cpu][piece][(mossa) & GAIN_MASK]); \
//		(L++)->move = (mossa) | (v << 16); }
#else
	//#define guadagno_ALLEGA(L, x, pezzo, ai) \
	//{ int v = ( (int) massimo_posizionale_guadagno[pezzo][(x) & 07777]); \
	//	if (v >= av) (L++)->mossa = (x) | (v << 16); }
#endif

#define SORTA\
	for (p = LISTA - 1; p >= sm; p--)\
	{ mossa = p->move;\
	for (q = p + 1; q < LISTA; q++)\
	{ if ( mossa<(int)(q->move) ) (q - 1)->move = q->move;\
		  else break;\
	}\
	q--;\
	q->move = mossa; }


#define OK(x)	(((x & 0x7fff) != s1) && ((x & 0x7fff) != s2) && ((x & 0x7fff) != s3))


#ifdef USE_STOCK_FISH_FILE
#else

void SortOrdinary	(typeMoveList * m1, typeMoveList * m2, uint32 s1, uint32 s2, uint32 s3)
{	
	typeMoveList *p, *q;
	uint32 mossa;
	if (m1 == m2)
		return;
	for (p = m2 - 1; p >= m1; p--)
	{
		if (OK (p->move))
			break;
		p->move = 0;
	}
	while (p > m1)
	{
		p--;
		mossa = p->move;
		if (OK (mossa))
		{
			for (q = p + 1; q < m2; q++)
			{
				if (mossa < (q->move))
					(q - 1)->move = q->move;
				else
					break;
			}
			q--;
			q->move = mossa;
		}
		else
		{
			m2--;
			for (q = p; q < m2; q++)
				q->move = (q + 1)->move;
			m2->move = 0;
		}
	}
}

typeMoveList * EvasionMoves (const typePOS *POSITION, typeMoveList * lista, Bitboard cel)
{
	if(POS_SIDE)
		return WhiteEvasions (POSITION, lista, cel);
	return BlackEvasions (POSITION, lista, cel);
}

typeMoveList * OrdinaryMoves (const typePOS *POSITION, typeMoveList * lista)
{
	if (POS_SIDE)
		return WhiteOrdinary (POSITION, lista);
	return BlackOrdinary (POSITION, lista);
}

typeMoveList * CaptureMoves (const typePOS *POSITION, typeMoveList * lista, Bitboard cel)
{
	if(POS_SIDE){
		return WhiteCaptures (POSITION, lista, m_and(cel,bitboard_occ_black));  // capture_white
	}
	return BlackCaptures (POSITION, lista, m_and(cel,bitboard_occ_white));
}

#endif

#include "move_gen.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

// 我方的走步是不是合法走步。
bool myIsLegalEvasionMove(const typePOS *POSITION,int from, int to){
	Bitboard occ = POSITION->byWhiteBlack;
	int myk = my_king_pos;
	
	clear_bit(occ,from);
	set_bit(occ,to);
	// fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w
	if(PB90(from) == my_king){  //如果走的是将，就要另外算一下。 
		myk = to;
	}

	// 2.1.1. 是不是给对方的 车,将 将军, ** 但不包括吃了对方的棋.同时去了对方的棋子
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
		m_or(POSITION->byChessBB[your_king],POSITION->byChessBB[your_che])),
		rook_attacks_bb(myk,occ)))) {
			return FALSE; 
	}

	// 2.1.2. 是不是还给对方的炮将军
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[your_pao]),
		pao_eat_attacks_bb(myk,occ)))){
			return FALSE;
	}

	// 2.1.3. 是不是还给对方的马将军
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[your_ma]),
		king_to_ma_attacks_bb(myk,occ)))){
			return FALSE;
	}

	// 2.1.4 是不是还给对方的兵将军
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[your_pawn]),
		your_attack_by_pawn(myk)))){
			return FALSE;
	}
	
	return TRUE;
}

//  解将步
typeMoveList * MyEvasion  (const typePOS *POSITION, typeMoveList * LISTA, Bitboard c2)
{
	Bitboard occ              = POSITION->byWhiteBlack;
	Bitboard paoJia_BB        = _mm_setzero_si128 ();        // 炮架上的棋子, 能走到其它的地方去解将. 
	Bitboard PaoJia_CannotEva = _mm_setzero_si128 ();        // 在炮架上的，不能走到炮架上去解将。
	Bitboard can_eva_BB   = _mm_set1_epi32(0xFFFFFFFF);    // 可能解将的棋格
	Bitboard att;
	Bitboard mpawnBB;
	Bitboard btmp;
	Bitboard ghp;
	Bitboard checker      = my_king_check;           // 得到将军的棋格.	
	int myk = my_king_pos;
	int check_sq;
	int i;
	int from,to;
	//int check90[90];
	//int pao_check_num = 0;

	// 去了自己的棋子。
	c2 = _mm_andnot_si128(MyOccupied,c2);  //不能走到自己的棋格上来解将哇

	//ASSERT(m128_is_have_bit(checker));

#ifdef DEBUG_TMP
	if(m128_is_have_bit(checker) == 0){
		board_display(POSITION,"no_checker!");
		// Attack_By_Rpawn_Rking[sq]
		// OneRpawnOrRking_AttackBB
		//print_bb(Attack_By_Rpawn_Rking[12]);
		//print_bb(OneRpawnOrRking_AttackBB[12]);
		myk = myk;
	}
#endif
	//fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w

	//board_display(POSITION,"move_check!");

	while(m128_is_have_bit(checker)){  // 这个不用判断,肯定是有棋在将军
		check_sq = pop_1st_bit(&checker);
		switch(PB90(check_sq)){
			case your_pawn:
				can_eva_BB = m_and(can_eva_BB,SetMaskBB[check_sq]);
				break;
			case your_ma:
				can_eva_BB = m_and(can_eva_BB,
					m_or(SetMaskBB[check_sq],SetMaskBB[maleg(check_sq,myk)]));  // 吃马，挡马腿
				//print_bb(can_eva_BB);board_display(board,"eva ma");
				break;	
			case your_che:
				can_eva_BB = m_and(can_eva_BB,
					m_or(BetweenBB[check_sq][myk],SetMaskBB[check_sq]));        // 挡车,吃车步	
				break;
			case your_pao:
				can_eva_BB = m_and(can_eva_BB,
					m_or(BetweenBB[check_sq][myk],SetMaskBB[check_sq]));        // 挡炮,吃炮步
				paoJia_BB  = m_or(paoJia_BB,                                    // 炮架上的棋子有特殊性
					m_and(BetweenBB[check_sq][myk],occ));
				//pao_check_num++;
				PaoJia_CannotEva = m_or(PaoJia_CannotEva,BetweenBB[check_sq][myk]); //车，炮不可能走到另一个炮的线上去。
				break;					
			case your_king:
				ASSERT(0);
				break;
			default:
				ASSERT(0);
				break;
		}
	}

	// 看一下是不是只能动将解将
	if(m128_is_have_bit(m_or(can_eva_BB,paoJia_BB)) == 0){
		goto ONLY_MOVE_KING_EVASION;
	}

	// ===================================================================================
	// 看能不能解将步. 我方的所有棋子能不能走到那儿.
	// 我方的炮的解将步
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		 att = m_and(m_or(
			 m_and(pao_eat_attacks_bb(from,occ),OppOccupied),   // 吃子步,
			 _mm_andnot_si128(occ,rook_attacks_bb(from,occ))),c2);       // 不吃子步.
		 if(bit_is_set(paoJia_BB,from)){                                 // 这个棋子是炮架, 要检查所有的棋格				
			 att = _mm_andnot_si128(PaoJia_CannotEva,att);	             // 车，炮不可能走到另一个炮的线上去。		
		 }
		 else{
			 att = m_and(att,can_eva_BB);
		 }		
		 while(m128_is_have_bit(att)){  // no test leagel
			 to = pop_1st_bit(&att);
			 if(myIsLegalEvasionMove(POSITION,from,to)){
			     LIST_ADD_cap(LISTA,from,to,my_pao);
			 }
		 }
	}
	// 我方的车的解将步
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att =  m_and(rook_attacks_bb(from,occ),c2);     //
		if(bit_is_set(paoJia_BB,from)){                          // 这个棋子是炮架, 要检查所有的棋格
			att = _mm_andnot_si128(PaoJia_CannotEva,att);	     // 车，炮不可能走到另一个炮的线上去。			
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			   LIST_ADD_cap(LISTA,from,to,my_che);
			}
		}
	}
	// 我方的马的解将步
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att =  m_and(ma_to_king_attacks_bb(from,occ),c2);   //
		if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
		}
		else{
			att = m_and(att,can_eva_BB);
		}
		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    LIST_ADD_cap(LISTA,from,to,my_ma);
			}
		}
	}
	// 我方的相的解将步
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att =  m_and(xiang_attacks_bb(from,occ),c2);   // 得到相所在位置的所有可走步
		if(bit_is_set(paoJia_BB,from)){                         // 这个棋子是炮架, 要检查所有的棋格
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    LIST_ADD_cap(LISTA,from,to,my_xiang);
			}
		}
	}
	// 我方的仕的解将步
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att =  m_and(shi_attacks(from),c2);   // 得到仕所在位置的所有可走步
		if(bit_is_set(paoJia_BB,from)){                // 这个棋子是炮架, 要检查所有的棋格
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			     LIST_ADD_cap(LISTA,from,to,my_shi);
			}
		}
	}

	// ===================================================================================
	// 所有的兵解将步, 这个兵的解将比较复杂
	// 可以一起算. 
	//***********************************************************
	//产生所有兵的不吃子走步 5个兵一起产生走步
	//***********************************************************
	mpawnBB = POSITION->byChessBB[my_pawn];
	btmp    = mpawnBB;
	//所有兵向前的不吃子步
	//BB_and_BB2(tmp,rpawnBB,NotRank0BB); //去掉最后一排的兵
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	//所有兵向前一步
	my_m_Rsf(btmp,9);
	//与目标棋格AND
	//BB_and_BB(tmp,target);	
	btmp =  m_and(btmp,c2);   //
	while(m128_is_have_bit(btmp)){			
		to   = pop_1st_bit(&btmp);
		from = my_pawn_add_9(to);
		if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
			if(!bit_is_set(PaoJia_CannotEva,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   LIST_ADD_cap(LISTA,from,to,my_pawn);  
				}
			}			
		}
		else{
			if(bit_is_set(can_eva_BB,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   LIST_ADD_cap(LISTA,from,to,my_pawn);
				}
			}
		}
	}
	
	//得到过河兵 //所有兵左右的步
	ghp = my_guo_he_pawn(mpawnBB);
	if(m128_is_have_bit(ghp)){			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);	    // 去了最左面的兵		
		m_Rsf(btmp,1);                    // 所有兵向左一步	
		btmp =  m_and(btmp,c2);   //
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			from = to + 1;
			if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
				if(myIsLegalEvasionMove(POSITION,from,to)){
				    LIST_ADD_cap(LISTA,from,to,my_pawn);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					      LIST_ADD_cap(LISTA,from,to,my_pawn);
					}
				}
			}
		}			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);	      // 去了最左面的兵
		m_Lsf(btmp,1);                   // 所有兵向右一步
		btmp =  m_and(btmp,c2);   //
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			from = to - 1;
			if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   LIST_ADD_cap(LISTA,from,to,my_pawn);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					   LIST_ADD_cap(LISTA,from,to,my_pawn);
					}
				}
			}
		}
	} 

ONLY_MOVE_KING_EVASION:
	// ===================================================================================
	// 最后动将来解将哇 
	// ===================================================================================
	att =  m_and(my_pawn_k_attacks(myk),c2);   // 得到将所在位置的所有可走步
	//att = _mm_andnot_si128(OppAttacked,att);            // 我方的将不能走到对方攻击的棋格上面。
	//还是有例外哇，就是空炮的时候。
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		if(myIsLegalEvasionMove(POSITION,myk,to)){
		   LIST_ADD_cap(LISTA,myk,to,my_king);
		}
	}	
	LISTA->move = 0;
	return LISTA;
}
// my_gain
typeMoveList * MyPositionalGain	(const typePOS *POSITION, typeMoveList * LISTA, int av)
{    
	Bitboard occ = POSITION->byWhiteBlack;
	//int yk_pos = your_king_pos;  // 得到对的将的位置
	Bitboard bbMyPawn;
	Bitboard btmp;
	Bitboard ghp;
	Bitboard att;
	typeMoveList *sm, *p, *q;
	int mossa;	
	int from,to;
	int i;
	int v;
	sm = LISTA;	
		
	//***********************************************************
	// 所有的王的不吃子步
	//***********************************************************
	from = my_king_pos;
	att = _mm_andnot_si128(occ,my_pawn_k_attacks(from));
	//att = _mm_andnot_si128(OppAttacked,att);  // 我方的将不能走到对方攻击的棋格上面。
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		GAIN_ADD(LISTA,from,to,my_king,ai);
	}

	//***********************************************************
	// 产生所有兵的不吃子走步 5个兵一起产生走步
	//***********************************************************
	bbMyPawn = POSITION->byChessBB[my_pawn];
	btmp     = bbMyPawn;
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);	
	my_m_Rsf(btmp,9); // 所有兵向前一
	btmp = _mm_andnot_si128(occ,btmp);          //与目标棋格xorAND
	while(m128_is_have_bit(btmp)){
		to = pop_1st_bit(&btmp);	
		GAIN_ADD(LISTA,my_pawn_add_9(to),to,my_pawn,ai);
	}
	// 得到过河兵	
	ghp = my_guo_he_pawn(bbMyPawn);  // Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	if(m128_is_have_bit(ghp)){			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp); // BB_and_BB2(tmp,ghp,NotFile0BB);         //去了最左面的兵	
		m_Rsf(btmp,1);                     //所有红兵向左一步			
		btmp = _mm_andnot_si128(occ,btmp);           //与目标棋格xorAND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			GAIN_ADD(LISTA,to+1,to,my_pawn,ai);
		}	
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp); //BB_and_BB2(tmp,ghp,NotFile8BB);  //去了最右面的兵
		m_Lsf(btmp,1);           //所有红兵向右一步	
		btmp = _mm_andnot_si128(occ,btmp);         //与目标棋格xorAND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			GAIN_ADD(LISTA,to-1,to,my_pawn,ai);
		}
	}
	//***********************************************************
	//产生所有相的不吃子走步
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = _mm_andnot_si128(occ,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_xiang,ai);
		}
	}
	//***********************************************************
	//产生所有红仕的不吃子走步
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = _mm_andnot_si128(occ,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_shi,ai);
		}
	}
	//***********************************************************
	//产生所有炮的不吃子走步
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_pao,ai);
		}
	}
	//***********************************************************
	//产生所有马的不吃子走步
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = _mm_andnot_si128(occ,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_ma,ai);
		}
	}	
	//***********************************************************
	//产生所有车的不吃子走步
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_che,ai);
		}
	}
	

	//
	LISTA->move = 0;
	SORTA;
	return LISTA;
}
// my_capture 
typeMoveList * MyCapture (const typePOS *POSITION, typeMoveList * LISTA, Bitboard cel)
{	
	Bitboard att;
	Bitboard bbMyPawn;
    Bitboard btmp;
	Bitboard ghp;
	Bitboard occ = POSITION->byWhiteBlack;
	int i;
	int from,to;
	if(m128_is_have_bit(m_and(cel,MyAttacked)) == 0){
		goto TARGA_NON;  // 没有吃子步
	}
	//***********************************************************
	//产生所有兵的不吃子走步 5个兵一起产生走步
	//***********************************************************
	//board_display(POSITION,"capture_move\n");
	//print_bb(cel);
	bbMyPawn = POSITION->byChessBB[my_pawn];
	btmp     = bbMyPawn;
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);	
	my_m_Rsf(btmp,9); //所有兵向前一步
	btmp = m_and(btmp,cel);          //与目标棋格AND
	while(m128_is_have_bit(btmp)){
		to = pop_1st_bit(&btmp);
		LIST_ADD_cap(LISTA,my_pawn_add_9(to),to,my_pawn);
	}	
	ghp = my_guo_he_pawn(bbMyPawn); // 得到过河兵
	if(m128_is_have_bit(ghp)){	   
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);  //去了最左面的兵	
		m_Rsf(btmp,1);                                         //所有红兵向左一步			
		btmp = m_and(btmp,cel);                                 //与目标棋格AND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_cap(LISTA,to+1,to,my_pawn);
		}
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);  //去了最右面的兵
		m_Lsf(btmp,1);           //所有红兵向右一步	
		btmp = m_and(btmp,cel);          //与目标棋格AND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_cap(LISTA,to-1,to,my_pawn);
		}
	}
	//***********************************************************
	// 产生所有相的吃子走步
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = m_and(cel,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_xiang);
		}
	}
	//***********************************************************
	// 产生所有红仕的吃子走步
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = m_and(cel,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_shi);
		}
	}
	//***********************************************************
	// 产生所有炮的吃子走步
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = m_and(cel,pao_eat_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_pao);
		}
	}
	//***********************************************************
	// 产生所有马的吃子走步
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = m_and(cel,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_ma);
		}
	}
	//***********************************************************
	// 产生所有车的吃子走步
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = m_and(cel,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_che);
		}
	}
	//***********************************************************
	// 所有的王的吃子步
	//***********************************************************
	from = my_king_pos; // 
	att = m_and(cel,my_pawn_k_attacks(from)); // fen rnbakCbnr/4a4/1c5c1/p1p3p1p/3RN4/9/P1P1P1P1P/3C5/5K3/R1BA1ABN1 b - - 	
	// att = _mm_andnot_si128(OppAttacked,att); // 我方的将不能走到到方的将的攻击步去，去了对方的攻击步。// print_bb(att);	
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		LIST_ADD_cap(LISTA,from,to,my_king);
	}
TARGA_NON: // 升变也算吃子步
	LISTA->move = 0;
	return LISTA;
}

//  用在常捉判断的 my_capture_not_include_king_pawn
typeMoveList * mio_cattura_not_include_pawn_king (const typePOS *POSITION, typeMoveList * LISTA){	
	Bitboard att;
	//Bitboard bbMyPawn;
    //Bitboard btmp;
	//Bitboard ghp;
	Bitboard occ = POSITION->byWhiteBlack;

	//if(m128_is_have_bit(m_and(cel,my_attack)) == 0){
	//	goto TARGA_NON;  // 没有吃子步
	//}
	Bitboard cel = OppOccupied;
	int i;
	int from,to;

	////***********************************************************
	////产生所有兵的不吃子走步 5个兵一起产生走步
	////***********************************************************
	//bbMyPawn = POSITION->byChessBB[my_pawn];
	//btmp     = bbMyPawn;
	////所有兵向前一步
	//my_m_Rsf(btmp,9);

	//// BB_and_BB(tmp,target);        
	//btmp = m_and(btmp,cel);          //与目标棋格AND
	//while(m128_is_have_bit(btmp)){
	//	int to = pop_1st_bit(&btmp);
	//	// LIST_ADD(list,MOVE_FromTo(my_pawn_add_9,to));
	//	LIST_ADD_cap(LISTA,my_pawn_add_9(to),to,my_pawn);
	//}

	//// 得到过河兵
	//// Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	//ghp = my_guo_he_pawn(bbMyPawn);

	//// BB_and_BB2(ghp,rpawnBB,RpawnOverBB);
	//if(m128_is_have_bit(ghp)){			
	//	//BB_and_BB2(tmp,ghp,NotFile0BB);         //去了最左面的兵	
	//	btmp = _mm_andnot_si128(File0BB,ghp);
	//	m_Rsf(btmp,1);                     //所有红兵向左一步			
	//	btmp = m_and(btmp,cel);          //与目标棋格AND
	//	while(m128_is_have_bit(btmp)){
	//		int to = pop_1st_bit(&btmp);
	//		//LIST_ADD(list,MOVE_FromTo(to+1,to));
	//		LIST_ADD_cap(LISTA,to+1,to,my_pawn);
	//	}			
	//	//BB_and_BB2(tmp,ghp,NotFile8BB);  //去了最右面的兵
	//	btmp = _mm_andnot_si128(File8BB,ghp);
	//	m_Lsf(btmp,1);           //所有红兵向右一步	
	//	btmp = m_and(btmp,cel);          //与目标棋格AND
	//	while(m128_is_have_bit(btmp)){
	//		int to = pop_1st_bit(&btmp);
	//		LIST_ADD_cap(LISTA,to-1,to,my_pawn);
	//	}
	//}

	//***********************************************************
	// 产生所有相的吃子走步
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = m_and(cel,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_xiang);
		}
	}

	//***********************************************************
	// 产生所有红仕的吃子走步
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = m_and(cel,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_shi);
		}
	}

	//***********************************************************
	// 产生所有炮的吃子走步
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = m_and(cel,pao_eat_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_pao);
		}
	}
	//***********************************************************
	// 产生所有马的吃子走步
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = m_and(cel,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_ma);
		}
	}

	//***********************************************************
	// 产生所有车的吃子走步
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = m_and(cel,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_che);
		}
	}

	//***********************************************************
	// 所有的王的吃子步
	//***********************************************************

	//from = my_king_pos;
	//att = m_and(cel,my_pawn_k_attacks(from));
	//while(m128_is_have_bit(att)){
	//	to = pop_1st_bit(&att);
	//	LIST_ADD_cap(LISTA,from,to,my_king);
	//}

//TARGA_NON: // 升变也算吃子步
	LISTA->move = 0;
	return LISTA;
}

// 不吃子步.
typeMoveList * MyOrdinary (const typePOS *POSITION, typeMoveList * LISTA)
{	
	Bitboard att;
	Bitboard bbMyPawn;
    Bitboard btmp;
	Bitboard ghp;
	Bitboard occ = POSITION->byWhiteBlack;
	Bitboard RE;
	int i;
	int from,to;
	int yk_pos = your_king_pos;  // 得到对的将的位置

	//***********************************************************
	// 所有的王的不吃子步
	//***********************************************************

	from = my_king_pos;
	att = _mm_andnot_si128(occ,my_pawn_k_attacks(from));
	//att = _mm_andnot_si128(OppAttacked,att);  // 我方的将不能走到对方攻击的棋格上面。
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		LIST_ADD_noncap_no(LISTA,from,to,my_king);
	}
	
	RE = my_attack_by_pawn(yk_pos);   // Attack_By_Rpawn_Rking
	//***********************************************************
	// 产生所有兵的不吃子走步 5个兵一起产生走步
	//***********************************************************
	bbMyPawn = POSITION->byChessBB[my_pawn];
	btmp     = bbMyPawn;
	//所有兵向前一步
	//得先把第一线的兵去了。 //MyLastRankPawnBB
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	my_m_Rsf(btmp,9);
	// fen 4k4/9/9/8p/4P4/9/9/6C2/9/4K4 b
	//BB_and_BB(tmp,target);        
	btmp = _mm_andnot_si128(occ,btmp);          // 与目标棋格xorAND
	while(m128_is_have_bit(btmp)){
		to = pop_1st_bit(&btmp);
		LIST_ADD_noncap(LISTA,my_pawn_add_9(to),to,my_pawn,RE);
	}

	// 得到过河兵
	// Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	ghp = my_guo_he_pawn(bbMyPawn);
	// BB_and_BB2(ghp,rpawnBB,RpawnOverBB);
	if(m128_is_have_bit(ghp)){			
		// BB_and_BB2(tmp,ghp,NotFile0BB);           // 去了最左面的兵	
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);
		m_Rsf(btmp,1);                     // 所有红兵向左一步			
		btmp = _mm_andnot_si128(occ,btmp);           // 与目标棋格xorAND

		//print_bb(btmp); // fen 2bak4/4a4/4b4/p1P6/2n6/2R4R1/3r2r2/3N4B/4A4/2B1KA3 w

		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_noncap(LISTA,to+1,to,my_pawn,RE);
		}			
		// BB_and_BB2(tmp,ghp,NotFile8BB);         // 去了最右面的兵
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);
		m_Lsf(btmp,1);                    // 所有红兵向右一步	
		btmp = _mm_andnot_si128(occ,btmp);         // 与目标棋格xorAND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_noncap(LISTA,to-1,to,my_pawn,RE);
		}
	}

	//***********************************************************
	// 产生所有相的不吃子走步
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = _mm_andnot_si128(occ,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap_no(LISTA,from,to,my_xiang);
		}
	}

	//***********************************************************
	// 产生所有红仕的不吃子走步
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = _mm_andnot_si128(occ,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap_no(LISTA,from,to,my_shi);
		}
	}

	RE = pao_eat_attacks_bb(yk_pos,occ);
	//***********************************************************
	// 产生所有炮的不吃子走步
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap(LISTA,from,to,my_pao,RE);
		}
	}

	RE = king_to_ma_attacks_bb(yk_pos,occ); 
	//***********************************************************
	// 产生所有马的不吃子走步
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = _mm_andnot_si128(occ,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap(LISTA,from,to,my_ma,RE);
		}
	}

	RE = rook_attacks_bb(yk_pos,occ);
	//***********************************************************
	// 产生所有车的不吃子走步
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap(LISTA,from,to,my_che,RE);
		}
	}

	

	LISTA->move = 0;
	return LISTA;
}

// 不吃子的将军步
typeMoveList * MyQuietChecks (const typePOS *POSITION, typeMoveList * LISTA, Bitboard cel )
{
	
	Bitboard check_target;
	Bitboard king_super;
	Bitboard king_pao;
	Bitboard king_che;
	Bitboard king_ma;
	Bitboard pao_super_att;
	Bitboard pao_eat_att;
	Bitboard ma_att;
	Bitboard kong_pao_att;
	Bitboard chouJiangChessBB2    = _mm_setzero_si128 ();  // 可以抽将的棋子．
	Bitboard dianJiangBB          = _mm_setzero_si128 ();  // 可以叠将的棋格．
	Bitboard att;
	Bitboard p;
	//Bitboard T;
	Bitboard ktoma;
	int mossa;
	int i;
	int yk_pos;
	int mk_pos;
	int from,to;
	int sq;

	Bitboard occ = POSITION->byWhiteBlack;

	cel = m_not(cel);
	cel = _mm_andnot_si128(occ,cel); // cel = ( ~cel) &~MyOccupied;

	yk_pos = your_king_pos;          // 得到对的将的位置

	king_super = pao_super_attacks_bb(yk_pos,occ);
	king_pao   = pao_eat_attacks_bb  (yk_pos,occ);
	king_ma    = Ma_Pseudo_Att[yk_pos];
	king_che   = rook_attacks_bb(yk_pos,occ);
	
	// A. 找到抽将的棋子.有三种可能，１，是炮ＸＸ将，２，是车Ｘ将, 3, 马X将.
	
	// 1, 要先算炮XX将,
	pao_super_att = m_and(POSITION->byChessBB[my_pao], king_super);
	while(m128_is_have_bit(pao_super_att)){
		sq = pop_1st_bit(&pao_super_att); 
		chouJiangChessBB2 = m_or(BetweenBB[sq][yk_pos], chouJiangChessBB2); 
	}

	// 2, 车X将
	pao_eat_att = m_and(POSITION->byChessBB[my_che],	king_pao);
	while(m128_is_have_bit(pao_eat_att)){
		sq = pop_1st_bit(&pao_eat_att);
		chouJiangChessBB2 = m_or(BetweenBB[sq][yk_pos], chouJiangChessBB2);  // 保存抽将的区域.		  
	}

	// 3, 马X将,
	ma_att = m_and(POSITION->byChessBB[my_ma], king_ma);
	while(m128_is_have_bit(ma_att)){       // board_display(board, "");
		int ma  = pop_1st_bit(&ma_att);    //
		int leg = maleg(ma,yk_pos);
		set_bit(chouJiangChessBB2,leg);    // 保存抽将的区域.
	}

	// B. 找到叠将的棋格（空炮），看棋子能不能走到这些棋格．不要算上面已抽将的棋子．
	kong_pao_att = m_and(POSITION->byChessBB[my_pao], king_che);
	while(m128_is_have_bit(kong_pao_att)){
		sq = pop_1st_bit(&kong_pao_att);		  
		dianJiangBB = m_or(BetweenBB[sq][yk_pos], dianJiangBB);	
	}

	//***********************************************************
	// 产生所有车的不吃子将军走步
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att =  rook_attacks_bb(from,occ);  
		att = m_and(att,cel);
		if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
		    // 如果走的棋子与对方的将在一线
			if(bit_is_set(ChePseudoMask_FR[yk_pos],from)){
				att = _mm_andnot_si128(chouJiangChessBB2,att);	
			}
			//att = _mm_andnot_si128(occ,att);   // 去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE(POSITION, mossa)){ // 抽将不要判断
					(LISTA++)->move = mossa;
				//}
			}
		}
		else {  // 这个棋子不可抽将, 则可产生叠将步, 或直接将军步.
			check_target = m_or(m_and(king_che,att),  // 找到交叉点
					dianJiangBB);   // 加上叠将的棋格
			att = m_and(att,check_target);
			//att = _mm_andnot_si128(occ,att);   // 去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE(POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}
		}		
	}
	//***********************************************************
	// 产生所有炮的不吃子将军走步
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = rook_attacks_bb(from,occ);          // 炮的不吃子 only use rook_attack
		att = m_and(att,cel);
		if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			// 如果走的棋子与对方的将在一线
			if(bit_is_set(ChePseudoMask_FR[yk_pos],from)){
				att = _mm_andnot_si128(chouJiangChessBB2,att);	
			} //fen 4k1b2/5C3/2nrbN2n/p1p6/4P3p/2P3P2/P7P/4C3B/4A4/2B1KA1rc w - - 0 0	
			//att = _mm_andnot_si128(occ,att);   // 去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE (POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}
		}
		else{                                    // 这个棋子不可抽将, 则可产生叠将步, 或直接将军步.
			// fen rnbakabnr/9/7c1/p1p1p1p1p/9/9/P1P1c1P1P/1C4NC1/9/R1BAKABNR b - - 0 0
			// 如果这个炮已在将的车ATT上,则不可能再有其它的将.
			if(bit_is_set(king_che,from)){
				continue;
			}
			check_target = m_or(m_and(king_pao,att),  // 找到交叉点,炮与车不一样.
				dianJiangBB);  // 加上叠将的棋格
			att = m_and(att,check_target);
			//att = _mm_andnot_si128(occ,att);   // 去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE (POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}
		}		
	}
	//***********************************************************
	// 产生所有马的不吃子将军走步
	//***********************************************************
	ktoma = king_to_ma_attacks_bb(yk_pos,occ);
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = ma_to_king_attacks_bb(from,occ);
		att = m_and(att,cel);
		if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			//att = _mm_andnot_si128(chouJiangChessBB,att);	
			//att = _mm_andnot_si128(occ,att);   //去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE (POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}		
		}
		else{                                     // 这个棋子不可抽将, 则可产生叠将步, 或直接将军步.
			check_target = m_or(m_and(ktoma,att),  // 找到交叉点,
				dianJiangBB);  // 加上叠将的棋格
			att = m_and(att,check_target);
		}
		//att = _mm_andnot_si128(occ,att);   //去了吃子步.
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			mossa = MOVE_FromTo(from,to);
			//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = mossa;
			//}
		}
	}

	//***********************************************************
	// 产生所有兵的不吃子将军走步
	//***********************************************************
    // 1, 只有过了河的兵才能产生将军步
	p = my_guo_he_pawn(bitboard_my_pawn);
	if(m128_is_have_bit(p)){  // 当前有了过河兵
		// 得到可抽将的兵 ----------------------------------------------------------------------
		p = m_and(chouJiangChessBB2,p);
		if(m128_is_have_bit(p)){
			// 所有兵向前一步		
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //得先把第一线的兵去了。 //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = m_and(att,cel); // 目标棋格
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// 去了在一线上的棋步
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(my_pawn_add_9(to),to);
				//}
			}
			// 所有兵向左一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // 所有红兵向左一步
			att = m_and(att,cel); // 目标棋格
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// 去了在一线上的棋步
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to+1,to);
				//}
			}
			// 所有兵向右一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // 所有红兵向左一步
			att = m_and(att,cel); // 目标棋格
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// 去了在一线上的棋步
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to-1,to);
				//}
			}
		}
		// 其它不可抽将的兵 ----------------------------------------------------------------------
		p = _mm_andnot_si128(chouJiangChessBB2,my_guo_he_pawn(bitboard_my_pawn));	
		if(m128_is_have_bit(p)){
			// Attack_By_Rpawn_Rking my_attack_by_pawn
			check_target = m_or(my_attack_by_pawn(your_king_pos),dianJiangBB);  // 加上叠将的棋格
			check_target = m_and(check_target,cel); 
			// 所有兵向前一步		
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //得先把第一线的兵去了。 //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = m_and(att,check_target); // 目标棋格
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(my_pawn_add_9(to),to);
				//}
			}
			// 所有兵向左一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // 所有红兵向左一步
			att = m_and(att,check_target); // 目标棋格
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to+1,to);
				//}
			}
			// 所有兵向右一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // 所有红兵向左一步
			att = m_and(att,check_target); // 目标棋格
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to-1,to);
				//}
			}
		}
	}

	// 仕, 相, 将, 不能直接将. 
	if(m128_is_have_bit(chouJiangChessBB2) || m128_is_have_bit(dianJiangBB)){
		//***********************************************************
		// 产生所有红相的不吃子将军走步
		//***********************************************************
		for(i = 0; i < my_xiang_num; i++){
			from = S90_from_piecelist(POSITION,my_xiang,i);
			att =  xiang_attacks_bb(from,occ);  // 得到相所在位置的所有可走步
			att = m_and(att,cel);
			if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
				// att = _mm_andnot_si128(chouJiangChessBB,att);		  
			}
			else{                                    // 这个棋子不可抽将, 则可产生叠将步, 
				att = m_and(att,dianJiangBB);
			}
			//att = _mm_andnot_si128(occ,att);   // 去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				(LISTA++)->move = MOVE_FromTo(from,to);
			}
		}

		//***********************************************************
		// 产生所有红仕的不吃子将军走步
		//***********************************************************
		for(i = 0; i < my_shi_num; i++){
			from = S90_from_piecelist(POSITION,my_shi,i);
			att = shi_attacks(from);  // 得到仕所在位置的所有可走步
			att = m_and(att,cel);
			if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
				// att = _mm_andnot_si128(chouJiangChessBB,att);		  
			}
			else{                                    // 这个棋子不可抽将, 则可产生叠将步, 
				att = m_and(att,dianJiangBB);
			}
			//att = _mm_andnot_si128(occ,att);   // 去了吃子步.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				(LISTA++)->move = MOVE_FromTo(from,to);
			}
		}

		//***********************************************************
		// 产生所有红将的不吃子将军走步
		//***********************************************************
		mk_pos = my_king_pos;
		if(bit_is_set(chouJiangChessBB2,mk_pos)){          // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			att = my_pawn_k_attacks(mk_pos);               // 得到将所在位置的所有可走步  
			att = _mm_andnot_si128(chouJiangChessBB2,att);	
			//att = _mm_andnot_si128(occ,att);                  //去了吃子步.
			att = m_and(att,cel);
			//att = _mm_andnot_si128(OppAttacked,att);  // 我方的将不能走到对方攻击的棋格上面。
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				(LISTA++)->move = MOVE_FromTo(mk_pos,to);
			}
		}
	}


	LISTA->move = 0;
	return LISTA;
}


#endif
