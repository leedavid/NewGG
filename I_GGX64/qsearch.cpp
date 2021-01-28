#ifndef BUILD_qsearch
#define BUILD_qsearch
#include "chess.h"
#include "qsearch.cpp"
#include "white.h"

//#include "MY_TEST_H.h"

#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

#ifdef TRACE_COMPILE
#define RETURN(x) \
  { TRACE (TRACE_QSEARCH, \
  printf ("Q%cR %d dp:%d V:%d\n", \
  POS_SIDE ? 'w' : 'b', (x), depth, VALUE)); \
  return (x); }
#else
#define RETURN(x) return(x)
#endif

int MyQsearch (typePOS* POSITION, int VALUE, int depth)
{
	Bitboard TARGET;
	int Value, i, k = POSITION->DYN->HASH & HashMask, v, best_value;
	/* k prefers to be uint32 ? */
	uint32 TEMP, move, trans_move = 0, trans_depth, move_depth = 0;	
	typeMoveList LIST[128], *list, *p, *q;
	typeDYNAMIC* POS0 = POSITION->DYN;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();
	
	TRACE (TRACE_QSEARCH,
		printf ("Q%c V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));
	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	CheckRepetition;


	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_QSEARCH, HASH_READ (trans));
			if (trans->DepthLower)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
					RETURN (Value);
			}
			if (trans->DepthUpper)
			{
				Value = HashUpperBound (trans);
				if (Value < VALUE)
					RETURN (Value);
			}
			trans_depth = trans->DepthLower;
			move = trans->move;
			if (move && trans_depth > move_depth)
			{
				move_depth = trans_depth;
				trans_move = move;
			}
		}
	}

	best_value = POS0->valu + TempoValue2;
	if (best_value >= VALUE)
		RETURN (best_value);
	v = VALUE - PrunePawn;
	TARGET = OppOccupied;
	if (v > best_value)
	{
		v = VALUE - PruneMinor;		
		TARGET = m_xor(TARGET,bitboard_your_pawn);
		if (v > best_value)
		{
			//TARGET ^= (BitboardOppN | BitboardOppB);
			TARGET = m_xor(TARGET,	m_or(bitboard_your_shi,bitboard_your_xiang));
			v = VALUE - PruneRook;
			if (v > best_value){
				//TARGET ^= BitboardOppR;
				TARGET = m_xor(TARGET,	m_or(bitboard_your_ma,bitboard_your_pao));
			}
		}
		//if (BitboardOppP & MyAttacked)
		//	best_value += PrunePawn;
		if(m128_is_have_bit(m_and(bitboard_your_pawn,MyAttacked))){
			best_value += PrunePawn;
		}
	}	

	list = MyCapture (POSITION, LIST, TARGET);
	p = LIST;
	while (p->move)
	{
		if ((p->move & 0x7fff) == trans_move)
			p->move |= 0xffff0000;
		p++;
	}
	p = LIST;
	while (p->move)
	{
		move = p->move;
		q = ++p;
		while (q->move)
		{
			if (move < q->move)
			{
				TEMP = q->move;
				q->move = move;
				move = TEMP;
			}
			q++;
		}
		if (!EasySEE (move) 
			&& (move & 0x7fff) != trans_move 
			//&& SqSet[FROM (move)] & ~MyXRAY 
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[FROM (move)])) 
			&& !MySEE (POSITION, move))
			continue;
		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue, move);
		if (ILLEGAL_MOVE)
		{
			UNDO (POSITION, move);
			continue;
		}
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (MOVE_IS_CHECK){
#else
		if (MOVE_IS_CHECK){
#endif
			v = -OppQsearchCheck (POSITION, 1 - VALUE, depth - 1);
		}
		else{
			v = -OppQsearch (POSITION, 1 - VALUE, depth - 1);
		}
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v <= best_value)
			continue;
		best_value = v;
		if (v >= VALUE)
		{
			HashLower (POSITION->DYN->HASH, move, 1, v);
			RETURN (v);
		}
	}

	if (depth >= -1 && POS0->valu >= VALUE - (100 + (12 << (depth + 4))))
	{
		list = MyQuietChecks (POSITION, LIST, TARGET); //print_bb(TARGET); //
		for (i = 0; i < list - LIST; i++)
		{
			move = LIST[i].move;
			move &= 0x7fff;


			MAKE (POSITION, move);
			EvalLazy (VALUE, VALUE, LazyValue, move);
			if (ILLEGAL_MOVE)
			{
				UNDO (POSITION, move);
				continue;
			}
#ifdef USE_HASH_EAXCT_VALUE 
			if (IS_EXACT (POSITION->DYN->exact)){
				v = -POSITION->DYN->valu;
			}
			else{
				v = -OppQsearchCheck (POSITION, 1 - VALUE, depth - 1);
			}
#else
			v = -OppQsearchCheck (POSITION, 1 - VALUE, depth - 1);
#endif
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v >= VALUE)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
	}	
	
	HashUpper (POSITION->DYN->HASH, 1, best_value);
	RETURN (best_value);
}

int MyQsearchCheck (typePOS* POSITION, int VALUE, int depth)
{
	Bitboard TARGET;
	int ignored, Value, i, k = POSITION->DYN->HASH & HashMask;
	int v, best_value, trans_depth, move_depth = 0;
	TRANS_DECLARE ();	
	typeMoveList LIST[128], *list, *p, *q;
	typeDYNAMIC* POS0;
	uint32 move, TEMP, trans_move = 0;
	YUSUF_DECLARE ();

	TRACE (TRACE_QSEARCH,
		printf ("Q%cC V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));
	POS0 = POSITION->DYN;
	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);

	CheckRepetition;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_QSEARCH, HASH_READ (trans));
			if (trans->DepthLower)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
					RETURN (Value);
			}
			if (trans->DepthUpper)
			{
				Value = HashUpperBound (trans);
				if (Value < VALUE)
					RETURN (Value);
			}
			trans_depth = trans->DepthLower;
			move = trans->move;
			if (move && trans_depth > move_depth)
			{
				move_depth = trans_depth;
				trans_move = move;
			}
		}
	}
	best_value = HEIGHT (POSITION) - VALUE_MATE;
	TARGET = _mm_set1_epi32(0xFFFFFFFF);   // _mm_set1_epi32()
	if (POS0->valu + PruneCheck < VALUE)
	{
		best_value = POS0->valu + PruneCheck;
		v = VALUE - 200;
		TARGET = OppOccupied;
		if (v > best_value)
		{
			//TARGET ^= BitboardOppP; bitboard_your_pawn
			TARGET = m_xor(TARGET,bitboard_your_pawn);
			v = VALUE - 500;
			best_value += 200;
			if (v > best_value){
				//TARGET ^= (BitboardOppN | BitboardOppB);
				TARGET = m_xor(TARGET,	m_or(bitboard_your_shi,bitboard_your_xiang));
			}
		}
	}

	list = MyEvasion (POSITION, LIST, TARGET);
	if ((list - LIST) > 1)
		depth--;
	p = LIST;
	while (p->move)
	{
		if ((p->move & 0x7fff) == trans_move)
			p->move |= 0xfff00000;
		p++;
	}
	p = LIST;
	ignored = 0;
	while (p->move)
	{
		move = p->move;
		q = ++p;
		while (q->move)
		{
			if (move < q->move)
			{
				TEMP = q->move;
				q->move = move;
				move = TEMP;
			}
			q++;
		}

		if (IsInterpose (move) 
			&& VALUE > -25000
			&& (move & 0x7fff) != trans_move 
			&& !MySEE (POSITION, move))
		{
			ignored++;
			continue;
		}
		if (PB90(TO (move)) == 0 
			&& (move & RE0XE000) == 0
			&& (move & 0x7fff) != trans_move 
			&& MyNull
			&& MAX_POSITIONAL (move) + POS0->valu < VALUE + 25
			&& VALUE > -25000)
		{
			ignored++;
			continue;
		}
		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue, move);
		if (ILLEGAL_MOVE)
		{
			UNDO (POSITION, move);
			continue;
		}
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (MOVE_IS_CHECK){
#else
		if (MOVE_IS_CHECK){
#endif
			v = -OppQsearchCheck (POSITION, 1 - VALUE, depth);
		}
		else{
			v = -OppQsearchEvasion (POSITION, 1 - VALUE, depth);  //解将步一定要延伸
		}
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v <= best_value)
			continue;
		best_value = v;
		if (v >= VALUE)
		{
			HashLower (POSITION->DYN->HASH, move, 1, v);
			RETURN (v);
		}
	}
	if (ignored && best_value < -25000){
		best_value = VALUE - 1;
	}
	HashUpper (POSITION->DYN->HASH, 1, best_value);
	RETURN (best_value);
}
// 解将步??
int MyQsearchEvasion (typePOS* POSITION, int VALUE, int depth)
{
	Bitboard TARGET;
	int Value;
	int i, k = POSITION->DYN->HASH & HashMask, v, best_value;
	/* k prefers to be uint32 ? */
	uint32 TEMP, move, trans_move = 0, trans_depth, move_depth = 0;	
	typeMoveList LIST[128], *list, *p, *q;
	typeDYNAMIC* POS0 = POSITION->DYN;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();

	TRACE (TRACE_QSEARCH,
		printf ("Q%c V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));
	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	CheckRepetition;


	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_QSEARCH, HASH_READ (trans));
			if (trans->DepthLower)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
					RETURN (Value);
			}
			if (trans->DepthUpper)
			{
				Value = HashUpperBound (trans);
				if (Value < VALUE)
					RETURN (Value);
			}
			trans_depth = trans->DepthLower;
			move = trans->move;
			if (move && trans_depth > move_depth)
			{
				move_depth = trans_depth;
				trans_move = move;
			}
		}
	}

	best_value = POS0->valu + TempoValue2;
	if (best_value >= VALUE){
		RETURN (best_value);
	}
	v = VALUE - PrunePawn;
	TARGET = OppOccupied;
	if (v > best_value)
	{
		v = VALUE - PruneMinor;		
		TARGET = m_xor(TARGET,bitboard_your_pawn);
		if (v > best_value)
		{
			//TARGET ^= (BitboardOppN | BitboardOppB);
			TARGET = m_xor(TARGET,	m_or(bitboard_your_shi,bitboard_your_xiang));
			v = VALUE - PruneRook;
			if (v > best_value){
				//TARGET ^= BitboardOppR;
				TARGET = m_xor(TARGET,	m_or(bitboard_your_ma,bitboard_your_pao));
			}
		}
		//if (BitboardOppP & MyAttacked)
		//	best_value += PrunePawn;
		if(m128_is_have_bit(m_and(bitboard_your_pawn,MyAttacked))){
			best_value += PrunePawn;
		}
	}	

	list = MyCapture (POSITION, LIST, TARGET);
	p = LIST;
	while (p->move)
	{
		if ((p->move & 0x7fff) == trans_move)
			p->move |= 0xffff0000;
		p++;
	}
	p = LIST;
	while (p->move)
	{
		move = p->move;
		q = ++p;
		while (q->move)
		{
			if (move < q->move)
			{
				TEMP = q->move;
				q->move = move;
				move = TEMP;
			}
			q++;
		}
		if (!EasySEE (move) 
			&& (move & 0x7fff) != trans_move 
			//&& SqSet[FROM (move)] & ~MyXRAY 
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[FROM (move)])) 
			&& !MySEE (POSITION, move))
			continue;
		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue, move);
		if (ILLEGAL_MOVE)
		{
			UNDO (POSITION, move);
			continue;
		}
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (MOVE_IS_CHECK){
#else
		if (MOVE_IS_CHECK){
#endif
			v = -OppQsearchCheck (POSITION, 1 - VALUE, depth - 1);
		}
		else{
			v = -OppQsearch (POSITION, 1 - VALUE, depth - 1);
		}
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v <= best_value)
			continue;
		best_value = v;
		if (v >= VALUE)
		{
			HashLower (POSITION->DYN->HASH, move, 1, v);
			RETURN (v);
		}
	}

	if (depth >= -1 && POS0->valu >= VALUE - (100 + (12 << (depth + 4))))
	{
		list = MyQuietChecks (POSITION, LIST, TARGET); //print_bb(TARGET); //
		for (i = 0; i < list - LIST; i++)
		{
			move = LIST[i].move;
			move &= 0x7fff;


			MAKE (POSITION, move);
			EvalLazy (VALUE, VALUE, LazyValue, move);
			if (ILLEGAL_MOVE)
			{
				UNDO (POSITION, move);
				continue;
			}
#ifdef USE_HASH_EAXCT_VALUE 
			if (IS_EXACT (POSITION->DYN->exact)){
				v = -POSITION->DYN->valu;
			}
			else{
				v = -OppQsearchCheck (POSITION, 1 - VALUE, depth - 1);
			}
#else
			v = -OppQsearchCheck (POSITION, 1 - VALUE, depth - 1);
#endif
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v >= VALUE)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
	}	

	HashUpper (POSITION->DYN->HASH, 1, best_value);
	RETURN (best_value);
}

#endif