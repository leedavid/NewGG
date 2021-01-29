
#ifndef BUILD_mossa_gen_ST
#define BUILD_mossa_gen_ST

#include "chess.h"
////
//// Includes
////

#include <cassert>


#include "movegen.h"

#define SERIALIZE_MOVES(from,to)  (*mlist++).move = make_move(from, to);


// Explicit template instantiations
template<> 
ExtMove* generate<CAPTURES>(Position& pos, ExtMove* mlist){
	
	//ASSERT(pos.pos_is_ok());
	ASSERT(!pos.in_check());

	if(pos.side_to_move() == WHITE){
		return WhiteCaptures(pos,mlist);
	}
	return BlackCaptures(pos,mlist);    
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////
template<> 
ExtMove* generate<QUIETS>(Position& pos, ExtMove* mlist){
	
		//ASSERT(pos.pos_is_ok());
		ASSERT(!pos.in_check());
	
		if(pos.side_to_move() == WHITE){
			return WhiteOrdinary(pos,mlist);
		}
		return BlackOrdinary(pos,mlist);  
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////
template<> 
ExtMove* generate<NON_EVASIONS>(Position& pos, ExtMove* mlist){

	mlist = generate<CAPTURES>(pos,mlist);
	mlist = generate<QUIETS>(pos,mlist);

	return mlist;
}

//////////////////////////////////////////////////////////////////////////
/// 不吃子的将军步
/// generate<MV_NON_CAPTURE_CHECK> generates all pseudo-legal non-captures and knight
/// underpromotions that give check. Returns a pointer to the end of the move list.
template<>
ExtMove* generate<QUIET_CHECKS>(Position& pos, ExtMove* mlist) {

	//ASSERT(pos.pos_is_ok());
	ASSERT(!pos.in_check());

	if(pos.side_to_move() == WHITE){
		return QuietChecksWhite(pos,mlist);
	}
	return QuietChecksBlack(pos,mlist);  
}

/// generate<MV_EVASION> generates all pseudo-legal check evasions when the side
/// to move is in check. Returns a pointer to the end of the move list.
template<>
ExtMove* generate<EVASIONS>(Position& pos, ExtMove* mlist) {

	//ASSERT(pos.pos_is_ok());
	ASSERT(pos.in_check());

	if(pos.side_to_move() == WHITE){
		return WhiteEvasions(pos,mlist);
	}
	return BlackEvasions(pos,mlist); 
}

//////////////////////////////////////////////////////////////////////////
/// generate<MV_LEGAL> generates all legal moves in the current position
//////////////////////////////////////////////////////////////////////////

template<>
ExtMove* generate<LEGAL>(Position& pos, ExtMove* mlist) {	

	ExtMove *last, *cur = mlist;
	//Bitboard pinned = pos.pinned_pieces(pos.side_to_move());
	
	last = pos.in_check() ? generate<EVASIONS>(pos, mlist)
		: generate<NON_EVASIONS>(pos, mlist);

	// Remove illegal moves from the list
	while (cur != last){
		if (!pos.legal(cur->move)) 
			cur->move = (--last)->move;
		else
			cur++;
	}

	return last;
}

#include "movegen.cpp"
#include "s_white.h"
#else
#include "s_black.h"
#endif

//////////////////////////////////////////////////////////////////////////
// 我方的走步是不是合法走步。
bool myIsLegalEvasionMove(typePOS &POSITION,Square from, Square to){
//#undef NOT_VERIFEY_EVAMOVE
//#ifdef NOT_VERIFEY_EVAMOVE
//	return true;
//#else	
	Bitboard ncc = BitboardOCC;
	Square mk = my_king_pos;

	clear_bit(ncc,from);
	set_bit(ncc,to);
	// fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w
	if(from == mk){  //如果走的是将，就要另外算一下。 
		mk = to;
	}	
	Bitboard KFR = ChePseudoMask_FR[mk];

	// 2.1.1. 是不是给对方的 车,将 将军, ** 但不包括吃了对方的棋.同时去了对方的棋子
	if(have_bit(KFR,m_or(POSITION.pieces(your_king),POSITION.pieces(your_che)))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
			m_or(POSITION.pieces(your_king),POSITION.pieces(your_che))),
			POSITION.Rook_attacks_bb(mk,ncc)))) {  		
				return false; 
		}
	}

	// 2.1.2. 是不是还给对方的炮将军
	if(have_bit(KFR,POSITION.pieces(your_pao))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION.pieces(your_pao)),
			POSITION.Pao_Eat_bb(mk,ncc)))) {   // pao_eat_attacks_bb(myk,occ)))){
				return false;
		}
	}

	// 2.1.3. 是不是还给对方的马将军
	if(have_bit(Ma_Pseudo_Att[mk],POSITION.pieces(your_ma))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION.pieces(your_ma)),
			POSITION.king_to_ma_attacks_bb(mk,ncc)))){
				return false;
		}
	}

	// 2.1.4 是不是还给对方的兵将军
	if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION.pieces(your_pawn)),
		your_attack_by_pawn(mk)))){
			return false;
	}
	return true;
//#endif
}


//////////////////////////////////////////////////////////////////////////
// 吃子步
ExtMove* MyCapture(typePOS &POSITION, ExtMove* mlist) {

	// 对方的棋格.
	Bitboard cel = OppOccupied;

	//***********************************************************
	//产生所有兵的不吃子走步 5个兵一起产生走步
	//***********************************************************
	Bitboard bbMyPawn = POSITION.pieces(my_pawn);
	//
	Bitboard btmp = bbMyPawn;
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);	
	my_m_Rsf(btmp,9); //所有兵向前一步
	btmp = m_and(btmp,cel);          //与目标棋格AND
	Square to;
	while (pop_1st_bit_sq(btmp, to)) {
		SERIALIZE_MOVES(my_pawn_add_9(to),to);
	}	
	Bitboard ghp = my_guo_he_pawn(bbMyPawn); // 得到过河兵
	if(m_have_bit(ghp)){	   
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);  //去了最左面的兵	
		m_Rsf(btmp,1);                                         //所有红兵向左一步			
		btmp = m_and(btmp,cel);                                 //与目标棋格AND
		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to+1,to);
		}
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);  //去了最右面的兵
		m_Lsf(btmp,1);           //所有红兵向右一步	
		btmp = m_and(btmp,cel);          //与目标棋格AND
		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to-1,to);
		}
	}
	//***********************************************************
	// 产生所有相的吃子走步
	//***********************************************************
	for(int i = 0; i < my_xiang_num; i++){
		Square from = S90_from_piecelist(POSITION,my_xiang,i);
		Bitboard att = m_and(cel,POSITION.xiang_attacks_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有红仕的吃子走步
	//***********************************************************
	for(int i = 0; i < my_shi_num; i++){
		Square from = S90_from_piecelist(POSITION,my_shi,i);
		Bitboard att = m_and(cel,shi_attacks(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有炮的吃子走步
	//***********************************************************
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);
		Bitboard att = m_and(cel,POSITION.Pao_Eat_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有马的吃子走步
	//***********************************************************
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = m_and(cel,POSITION.ma_to_king_attacks_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 产生所有车的吃子走步
	//***********************************************************
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att = m_and(cel,POSITION.Rook_attacks_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 所有的王的吃子步
	//***********************************************************
	Square from = my_king_pos; // 
	Bitboard att = m_and(cel,my_pawn_k_attacks(from)); // fen rnbakCbnr/4a4/1c5c1/p1p3p1p/3RN4/9/P1P1P1P1P/3C5/5K3/R1BA1ABN1 b - - 	
	while (pop_1st_bit_sq(att, to)) {
		SERIALIZE_MOVES(from,to);
	}

	return mlist;
}

//////////////////////////////////////////////////////////////////////////
//  解将步,这个不是全解将步
ExtMove* MyEvasion  (typePOS &POSITION, ExtMove* mlist)
{
	Bitboard occ = BitboardOCC;
	Bitboard paoJia_BB        = _mm_setzero_si128 ();        // 炮架上的棋子, 能走到其它的地方去解将. 
	Bitboard PaoJia_CannotEva = _mm_setzero_si128 ();        // 在炮架上的，不能走到炮架上去解将。
	Bitboard can_eva_BB       = _mm_set1_epi32(0xFFFFFFFF);      // 可能解将的棋格
	Bitboard checker          = POSITION.checkers(); // my_king_check;           // 得到将军的棋格.	
	Bitboard ghp;
	Bitboard mpawnBB;
	Bitboard btmp;
	Square myk = my_king_pos;

	// 去了自己的棋子。不能走到自己的棋格上来解将哇
	//Bitboard c2 = _mm_andnot_si128(MyOccupied,_mm_set1_epi32(0xFFFFFFFF));  //

	ASSERT(m_have_bit(checker));

	// fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w
	//board_display(POSITION,"move_check!");
	Square check_sq;
	while (pop_1st_bit_sq(checker, check_sq)) { // 这个不用判断,肯定是有棋在将军
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
	if(m_have_bit(m_or(can_eva_BB,paoJia_BB)) == 0){
		goto ONLY_MOVE_KING_EVASION;
	}

	// ===================================================================================
	// 看能不能解将步. 我方的所有棋子能不能走到那儿.
	// 我方的炮的解将步
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);

		Bitboard att = m_or(m_and(POSITION.Pao_Eat_bb(from),OppOccupied),  // 吃子步,
			_mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from)));         // 不吃子步.

		 if(bit_is_set(paoJia_BB,from)){                                 // 这个棋子是炮架, 要检查所有的棋格				
			 att = _mm_andnot_si128(PaoJia_CannotEva,att);	             // 车，炮不可能走到另一个炮的线上去。		
		 }
		 else{
			 att = m_and(att,can_eva_BB);
		 }	
		 Square to;
		 while (pop_1st_bit_sq(att, to)) {
			 if(myIsLegalEvasionMove(POSITION,from,to)){
				 SERIALIZE_MOVES(from,to);
			 }
		 }
	}
	// 我方的车的解将步
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,POSITION.Rook_attacks_bb(from));
		if(bit_is_set(paoJia_BB,from)){                          // 这个棋子是炮架, 要检查所有的棋格
			att = _mm_andnot_si128(PaoJia_CannotEva,att);	     // 车，炮不可能走到另一个炮的线上去。			
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			   SERIALIZE_MOVES(from,to);
			}
		}
	}
	// 我方的马的解将步
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,POSITION.ma_to_king_attacks_bb(from));
		if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
		}
		else{
			att = m_and(att,can_eva_BB);
		}
		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    SERIALIZE_MOVES(from,to);
			}
		}
	}
	// 我方的相的解将步
	for(int i = 0; i < my_xiang_num; i++){
		Square from = S90_from_piecelist(POSITION,my_xiang,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,POSITION.xiang_attacks_bb(from));
		if(bit_is_set(paoJia_BB,from)){                         // 这个棋子是炮架, 要检查所有的棋格
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    SERIALIZE_MOVES(from,to);
			}
		}
	}
	// 我方的仕的解将步
	for(int i = 0; i < my_shi_num; i++){
		Square from = S90_from_piecelist(POSITION,my_shi,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,shi_attacks(from));
		if(bit_is_set(paoJia_BB,from)){                // 这个棋子是炮架, 要检查所有的棋格
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    SERIALIZE_MOVES(from,to);
			}
		}
	}

	// ===================================================================================
	// 所有的兵解将步, 这个兵的解将比较复杂
	// 可以一起算. 
	//***********************************************************
	//产生所有兵的不吃子走步 5个兵一起产生走步
	//***********************************************************
	mpawnBB = POSITION.pieces(my_pawn); // POSITION.byChessBB[my_pawn];
	btmp    = mpawnBB;
	//所有兵向前的不吃子步
	//BB_and_BB2(tmp,rpawnBB,NotRank0BB); //去掉最后一排的兵
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	//所有兵向前一步
	my_m_Rsf(btmp,9);
	btmp = _mm_andnot_si128(MyOccupied,btmp);
	Square to;
	while (pop_1st_bit_sq(btmp, to)) {
		Square from = my_pawn_add_9(to);
		if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
			if(!bit_is_set(PaoJia_CannotEva,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   SERIALIZE_MOVES(from,to); 
				}
			}			
		}
		else{
			if(bit_is_set(can_eva_BB,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   SERIALIZE_MOVES(from,to);
				}
			}
		}
	}
	
	//得到过河兵 //所有兵左右的步
	ghp = my_guo_he_pawn(mpawnBB);
	if(m_have_bit(ghp)){			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);	    // 去了最左面的兵		
		m_Rsf(btmp,1);                    // 所有兵向左一步	
		btmp = _mm_andnot_si128(MyOccupied,btmp);
		while (pop_1st_bit_sq(btmp, to)) {
			Square from = to + 1;
			if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
				if(myIsLegalEvasionMove(POSITION,from,to)){
				    SERIALIZE_MOVES(from,to);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					      SERIALIZE_MOVES(from,to);
					}
				}
			}
		}			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);	      // 去了最左面的兵
		m_Lsf(btmp,1);                   // 所有兵向右一步
		btmp = _mm_andnot_si128(MyOccupied,btmp);
		while (pop_1st_bit_sq(btmp, to)) {
			Square from = to - 1;
			if(bit_is_set(paoJia_BB,from)){           // 这个棋子是炮架, 要检查所有的棋格
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   SERIALIZE_MOVES(from,to);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					   SERIALIZE_MOVES(from,to);
					}
				}
			}
		}
	} 

ONLY_MOVE_KING_EVASION:
	// ===================================================================================
	// 最后动将来解将哇 
	// ===================================================================================
	Bitboard att = _mm_andnot_si128(MyOccupied,my_pawn_k_attacks(myk));
	while (pop_1st_bit_sq(att, to)) {
		if(myIsLegalEvasionMove(POSITION,myk,to)){
		   SERIALIZE_MOVES(myk,to);
		}
	}	
	return mlist;
}

//////////////////////////////////////////////////////////////////////////
// 不吃子步.
ExtMove* MyOrdinary (typePOS &POSITION, ExtMove* mlist)
{	

	Bitboard occ = BitboardOCC;
	
	//***********************************************************
	// 产生所有兵的不吃子走步 5个兵一起产生走步 btmp = _mm_andnot_si128(occ,btmp);          // 与目标棋格xorAND
	//***********************************************************
	Bitboard bbMyPawn = POSITION.pieces(my_pawn);
	Bitboard btmp     = bbMyPawn;
	//所有兵向前一步
	//得先把第一线的兵去了。 //MyLastRankPawnBB
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	my_m_Rsf(btmp,9);
	// fen 4k4/9/9/8p/4P4/9/9/6C2/9/4K4 b   
	btmp = _mm_andnot_si128(occ,btmp);          // 与目标棋格xorAND
	Square to;
	while (pop_1st_bit_sq(btmp, to)) {
		SERIALIZE_MOVES(my_pawn_add_9(to),to);
	}

	// 得到过河兵
	// Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	Bitboard ghp = my_guo_he_pawn(bbMyPawn);
	// BB_and_BB2(ghp,rpawnBB,RpawnOverBB);
	if(m_have_bit(ghp)){			
		// BB_and_BB2(tmp,ghp,NotFile0BB);           // 去了最左面的兵	
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);
		m_Rsf(btmp,1);                     // 所有红兵向左一步			
		btmp = _mm_andnot_si128(occ,btmp);           // 与目标棋格xorAND

		//print_bb(btmp); // fen 2bak4/4a4/4b4/p1P6/2n6/2R4R1/3r2r2/3N4B/4A4/2B1KA3 w

		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to+1,to);
		}			
		// BB_and_BB2(tmp,ghp,NotFile8BB);         // 去了最右面的兵
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);
		m_Lsf(btmp,1);                    // 所有红兵向右一步	
		btmp = _mm_andnot_si128(occ,btmp);         // 与目标棋格xorAND
		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to-1,to);
		}
	}

	//***********************************************************
	// 产生所有相的不吃子走步
	//***********************************************************
	for(int i = 0; i < my_xiang_num; i++){
		Square from = S90_from_piecelist(POSITION,my_xiang,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.xiang_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 产生所有红仕的不吃子走步
	//***********************************************************
	for(int i = 0; i < my_shi_num; i++){
		Square from = S90_from_piecelist(POSITION,my_shi,i);
		Bitboard att = _mm_andnot_si128(occ,shi_attacks(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	
	//***********************************************************
	// 产生所有炮的不吃子走步
	//***********************************************************
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	
	//***********************************************************
	// 产生所有马的不吃子走步
	//***********************************************************
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.ma_to_king_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 产生所有车的不吃子走步
	//***********************************************************
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 所有的王的不吃子步
	//***********************************************************

	Square from = my_king_pos;
	Bitboard att = _mm_andnot_si128(occ,my_pawn_k_attacks(from));
	//att = _mm_andnot_si128(OppAttacked,att);  // 我方的将不能走到对方攻击的棋格上面。
	//Square to;
	while (pop_1st_bit_sq(att, to)) {
		SERIALIZE_MOVES(from,to);
	}

	return mlist;
}
//////////////////////////////////////////////////////////////////////////
// 不吃子的将军步
ExtMove* MyQuietChecks (typePOS &POSITION, ExtMove* mlist)
{	

	Bitboard chouJiangChessBB2    = _mm_setzero_si128 ();  // 可以抽将的棋子．
	Bitboard dianJiangBB          = _mm_setzero_si128 ();  // 可以叠将的棋格．

	Bitboard occ = BitboardOCC;
	Square yk_pos = your_king_pos;          // 得到对的将的位置

	Bitboard king_pao   = POSITION.Pao_Eat_bb(yk_pos);	
	Bitboard king_che   = POSITION.Rook_attacks_bb(yk_pos);
	
	// A. 找到抽将的棋子.有三种可能，１，是炮ＸＸ将，２，是车Ｘ将, 3, 马X将.
	
	// 1, 要先算炮XX将,
	if(have_bit(bb_my_pao,ChePseudoMask_FR[yk_pos])){
		for(int i = 0; i < my_pao_num; i++){
			Square s = S90_from_piecelist(POSITION,my_pao,i);
			Bitboard bet = m_and(BetweenBB[s][yk_pos],occ);
			switch(count_1s(bet)){
			case 0: // 空炮
				dianJiangBB = m_or(BetweenBB[s][yk_pos], dianJiangBB); 
				break;
			case 2: // 中炮，底炮
				chouJiangChessBB2 = m_or(BetweenBB[s][yk_pos], chouJiangChessBB2); 
				break;
			default:
				break;
			}
		}
	}

	// 2, 车X将
	Bitboard pao_eat_att = m_and(POSITION.pieces(my_che),	king_pao);
	Square sq;
	while (pop_1st_bit_sq(pao_eat_att, sq)) {
		chouJiangChessBB2 = m_or(BetweenBB[sq][yk_pos], chouJiangChessBB2);  // 保存抽将的区域.		  
	}

	// 3, 马X将,
	Bitboard ma_att = m_and(POSITION.pieces(my_ma), Ma_Pseudo_Att[yk_pos]);
	Square ma;
	while (pop_1st_bit_sq(ma_att, ma)) {
		Square leg = maleg(ma,yk_pos);
		set_bit(chouJiangChessBB2,leg);    // 保存抽将的区域.
	}


	//***********************************************************
	// 产生所有车的不吃子将军走步
	//***********************************************************
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att =  _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from)); 
		if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			att = _mm_andnot_si128(chouJiangChessBB2,att);				
		}
		else {  // 这个棋子不可抽将, 则可产生叠将步, 或直接将军步.
			att = m_and(att,m_or(king_che,dianJiangBB));			
		}
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有炮的不吃子将军走步
	//***********************************************************
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from));      // 炮的不吃子 only use rook_attack
		if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// fen 4k1b2/5C3/2nrbN2n/p1p6/4P3p/2P3P2/P7P/4C3B/4A4/2B1KA1rc w - - 0 0				
		}
		else{                                    // 这个棋子不可抽将, 则可产生叠将步, 或直接将军步.
			// fen rnbakabnr/9/7c1/p1p1p1p1p/9/9/P1P1c1P1P/1C4NC1/9/R1BAKABNR b - - 0 0
			// 如果这个炮已在将的车ATT上,则不可能再有其它的将.
			if(bit_is_set(king_che,from)){
				continue;
			}
			att = m_and(att,m_or(king_pao,dianJiangBB));	
		}	
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// 产生所有马的不吃子将军走步
	//***********************************************************
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.ma_to_king_attacks_bb(from));
		if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子	
		}
		else{                                     // 这个棋子不可抽将, 则可产生叠将步, 或直接将军步.
			if(have_bit(att,Ma_Pseudo_Att[yk_pos])){
				att = m_and(att,m_or(POSITION.king_to_ma_attacks_bb(yk_pos),dianJiangBB));
			}
			else{
				att = m_and(att,dianJiangBB);
			}
		}
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// 产生所有兵的不吃子将军走步
	//***********************************************************
    // 1, 只有过了河的兵才能产生不吃子的将军步
	Bitboard p = my_guo_he_pawn(bb_my_pawn);
	if(m_have_bit(p)){  // 当前有了过河兵
		// 得到可抽将的兵 ----------------------------------------------------------------------
		p = m_and(chouJiangChessBB2,p);
		if(m_have_bit(p)){
			// 所有兵向前一步		
			Bitboard att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //得先把第一线的兵去了。 //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = _mm_andnot_si128(occ,att);                // 与目标棋格xorAND
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// 去了在一线上的棋步
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(my_pawn_add_9(to),to);
			}
			// 所有兵向左一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // 所有红兵向左一步
			att = _mm_andnot_si128(occ,att);          // 与目标棋格xorAND
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// 去了在一线上的棋步
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to+1,to);				
			}
			// 所有兵向右一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // 所有红兵向左一步
			att = _mm_andnot_si128(occ,att);          // 与目标棋格xorAND
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// 去了在一线上的棋步
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to-1,to);	
			}
		}
		// 其它不可抽将的兵 ----------------------------------------------------------------------
		p = _mm_andnot_si128(chouJiangChessBB2,my_guo_he_pawn(bb_my_pawn));	
		if(m_have_bit(p)){
			// Attack_By_Rpawn_Rking my_attack_by_pawn
			Bitboard check_target = m_or(my_attack_by_pawn(your_king_pos),dianJiangBB);  // 加上叠将的棋格
			check_target = _mm_andnot_si128(occ,check_target);          // 与目标棋格xorAND
			// 所有兵向前一步		
			Bitboard att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //得先把第一线的兵去了。 //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = m_and(att,check_target); // 目标棋格			
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(my_pawn_add_9(to),to);
			}
			// 所有兵向左一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // 所有红兵向左一步
			att = m_and(att,check_target); // 目标棋格
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to+1,to);
			}
			// 所有兵向右一步
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // 所有红兵向左一步
			att = m_and(att,check_target); // 目标棋格
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to-1,to);
			}
		}
	}

	// 仕, 相, 将, 不能直接将. 
	if(m_have_bit(chouJiangChessBB2) || m_have_bit(dianJiangBB)){
		//***********************************************************
		// 产生所有红相的不吃子将军走步
		//***********************************************************
		for(int i = 0; i < my_xiang_num; i++){
			Square from = S90_from_piecelist(POSITION,my_xiang,i);
			Bitboard att =  _mm_andnot_si128(occ,POSITION.xiang_attacks_bb(from));  // 得到相所在位置的所有可走步
			if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子  
			}
			else{                                    // 这个棋子不可抽将, 则可产生叠将步, 
				att = m_and(att,dianJiangBB);
			}
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(from,to);
			}
		}

		//***********************************************************
		// 产生所有红仕的不吃子将军走步
		//***********************************************************
		for(int i = 0; i < my_shi_num; i++){
			Square from = S90_from_piecelist(POSITION,my_shi,i);
			Bitboard att = _mm_andnot_si128(occ,shi_attacks(from));  // 得到仕所在位置的所有可走步
			if(bit_is_set(chouJiangChessBB2,from)){   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			}
			else{                                    // 这个棋子不可抽将, 则可产生叠将步, 
				att = m_and(att,dianJiangBB);
			}
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(from,to);
			}
		}
		// 这个非常少见，没有必要加了
		////***********************************************************
		//// 产生所有红将的不吃子将军走步
		////***********************************************************
		Square mk_pos = my_king_pos;
		if(bit_is_set(chouJiangChessBB2,mk_pos)){                   // 这个棋子可抽将,则可产生所有的走步.但不包括走到抽将的步子
			Bitboard att = my_pawn_k_attacks(mk_pos);               // 得到将所在位置的所有可走步  
			att = _mm_andnot_si128(chouJiangChessBB2,att);	
			att= _mm_andnot_si128(occ,att);                          // 与目标棋格xorAND
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(mk_pos,to);
			}
		}
	}

	return mlist;
}
