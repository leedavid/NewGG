#ifndef BUILD_qsearch_pv
#define BUILD_qsearch_pv
#include "chess.h"
#include "qsearch_pv.cpp"

//#include "MY_TEST_H.h"

#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

#ifdef TRACE_COMPILE
#define RETURN(x) \
  { TRACE (TRACE_PVQSEARCH, \
  printf ("PVQ%cR %d dp:%d V:[%d,%d]\n", \
  POS_SIDE ? 'w' : 'b', (x), depth, ALPHA, BETA)); \
  return (x); }
#else
#define RETURN(x) return(x)
#endif
//                                                                    
int MyPVQsearch (typePOS* POSITION, int ALPHA, int BETA, int depth)
{
	Bitboard TARGET;
	int i;
	uint32 good_move = 0, trans_move = 0, move, BAD_CAPS[64];
	uint32 trans_depth, move_depth = 0;
	int best_value, Value;	
	typeMoveList LIST[128], *list, *p, *q;
	int TEMP, v;
	typeDYNAMIC* POS0 = POSITION->DYN;
	int k = POSITION->DYN->HASH & HashMask;
	int bc = 0;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();

	TRACE (TRACE_PVQSEARCH,
		printf ("PVQ%c V:[%d,%d] dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		ALPHA, BETA, depth, POSITION->DYN->Value));
	CheckRepetition;

	if (BETA < -VALUE_MATE)
		RETURN (-VALUE_MATE);
	if (ALPHA > VALUE_MATE)
		RETURN (VALUE_MATE);
	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_PVQSEARCH, HASH_READ (trans));
			if (IsExact (trans))
			{
				Value = HashUpperBound (trans);
				RETURN (Value);
			}
			if (trans->DepthLower)
			{
				Value = HashLowerBound (trans);
				if (Value >= BETA)
					RETURN (Value);
			}
			if (trans->DepthUpper)
			{
				Value = HashUpperBound (trans);
				if (Value <= ALPHA)
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
	TARGET = OppOccupied;

	if (best_value >= BETA)	{
		RETURN (best_value);
	}
	else if (best_value > ALPHA){
		//还要上次不是将军，才算。
		//if(POSITION->STACKst[POSITION->StackHeight-1].check == FALSE){
		ALPHA = best_value;
		//}
	}
	else
	{
		if (best_value < ALPHA - PrunePawn)
		{
			//TARGET ^= BitboardOppP;
			TARGET = m_xor(TARGET,bitboard_your_pawn);
			if (best_value < ALPHA - PruneMinor)
			{
				//TARGET ^= (BitboardOppN | BitboardOppB);
				TARGET = m_xor(TARGET,	m_or(bitboard_your_shi,bitboard_your_xiang));
				if (best_value < ALPHA - PruneRook){
					//TARGET ^= BitboardOppR;
					TARGET = m_xor(TARGET,	m_or(bitboard_your_ma,bitboard_your_shi));
				}
			}
			best_value += PrunePawn;
		}
	}

	

	
	list = MyCapture (POSITION, LIST, TARGET); //先产生吃子步？
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
		if (EasySEE (move) || (move & 0x7fff) == trans_move
			|| MySEE (POSITION, move))
		{
			move &= 0x7fff;
			MAKE (POSITION, move);
			EVAL (move);
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
				v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
			}
			else{
				v = -OppPVQsearch (POSITION, -BETA, -ALPHA, depth - 1);
			}
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v <= ALPHA)
				continue;
			ALPHA = v;
			good_move = move;
			if (v >= BETA)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
		else
			BAD_CAPS[bc++] = move;
	}
	if (depth > 0) {                       // 如果还有深度，就搜索坏的吃子步
		for (i = 0; i < bc; i++)
		{
			move = BAD_CAPS[i] & 0x7fff;
			MAKE (POSITION, move);
			EVAL (move);
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
				v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
			}
			else{
				v = -OppPVQsearch (POSITION, -BETA, -ALPHA, depth - 1);
			}
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v <= ALPHA)
				continue;
			ALPHA = v;
			good_move = move;
			if (v >= BETA)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
	}

	if (depth >= -2 && POS0->valu >= ALPHA - (100 + (12 << (depth + 5))))
	{
		list = MyQuietChecks (POSITION, LIST, TARGET);  // 产生不吃子的将军步
		for (i = 0; i < list - LIST; i++)
		{
			move = LIST[i].move & 0x7fff;
		   
			MAKE (POSITION, move);

			EVAL (move);
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
				v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
			}
#else
			v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
#endif
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v <= ALPHA)
				continue;
			ALPHA = v;
			good_move = move;
			if (v >= BETA)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
		if (depth >= 0 && ALPHA <= POS0->valu + 150)
		{
			list = MyPositionalGain (POSITION, LIST, ALPHA - POS0->valu);
			for (i = 0; i < list - LIST; i++)
			{
				move = LIST[i].move & 0x7fff;
				MAKE (POSITION, move);
				EVAL (move);
				if (-POS1->valu < ALPHA)
				{
					UNDO (POSITION, move);
					continue;
				}
				if (ILLEGAL_MOVE || MOVE_IS_CHECK)
				{
					UNDO (POSITION, move);
					continue;
				}
#ifdef USE_HASH_EAXCT_VALUE 
				if (IS_EXACT (POSITION->DYN->exact)){
					v = -POSITION->DYN->valu;
				}
				else{
					v = -OppPVQsearch (POSITION, -BETA, -ALPHA, 0);
				}
#else
				v = -OppPVQsearch (POSITION, -BETA, -ALPHA, 0);
#endif
				UNDO (POSITION, move);
				CHECK_HALT ();
				if (v <= best_value)
					continue;
				best_value = v;
				if (v <= ALPHA)
					continue;
				ALPHA = v;
				good_move = move;
				HashLower (POSITION->DYN->HASH, move, 1, v);
				if (v >= BETA)
					RETURN (v);
			}
		}
	}
	
	
	if (good_move)
	{
		HashExact (POSITION, good_move, 1, best_value, FLAG_EXACT);
		RETURN (best_value);
	}
	HashUpper (POSITION->DYN->HASH, 1, best_value);
	RETURN (best_value);
}
// PV_对方将军，我方的搜索
int MyPVQsearchCheck (typePOS* POSITION, int ALPHA, int BETA, int depth)
{
	
	Bitboard TARGET;
	int i;
	uint32 trans_move = 0, good_move = 0, move, TEMP;
	int best_value, Value;	
	typeMoveList LIST[128], *list, *p, *q;
	int k = POSITION->DYN->HASH & HashMask;
	int v, trans_depth, move_depth = 0;
	typeDYNAMIC* POS0 = POSITION->DYN;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();

	TRACE (TRACE_PVQSEARCH,
		printf ("PVQ%c V:[%d,%d] dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		ALPHA, BETA, depth, POSITION->DYN->Value));
	CheckRepetition;
	if (BETA < -VALUE_MATE)
		RETURN (-VALUE_MATE);
	if (ALPHA > VALUE_MATE)
		RETURN (VALUE_MATE);
	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_PVQSEARCH, HASH_READ (trans));
			if (IsExact (trans))
			{
				Value = HashUpperBound (trans);
				RETURN (Value);
			}
			if (trans->DepthLower)
			{
				Value = HashLowerBound (trans);
				if (Value >= BETA)
					RETURN (Value);
			}
			if (trans->DepthUpper)
			{
				Value = HashUpperBound (trans);
				if (Value <= ALPHA)
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
	TARGET = _mm_set1_epi32(0xFFFFFFFF);
	if (POS0->valu + PruneCheck < ALPHA)
	{
		best_value = POS0->valu + PruneCheck;
		v = ALPHA - 200;
		TARGET = OppOccupied;
		if (v > best_value)
		{
			//TARGET ^= BitboardOppP; bitboard_your_pawn
			TARGET = m_xor(TARGET,bitboard_your_pawn);
			v = ALPHA - 500;
			best_value += 200;
			if (v > best_value){
				//TARGET ^= (BitboardOppN | BitboardOppB);
				TARGET = m_xor(TARGET,	m_or(bitboard_your_shi,bitboard_your_xiang));
			}
		}
	}
	list = MyEvasion (POSITION, LIST, TARGET);
	if ((list - LIST) != 1)
		depth--;
	p = LIST;
	while (p->move)
	{
		if ((p->move & 0x7fff) == trans_move)
			p->move |= 0xfff00000;
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
		move &= 0x7fff;
		MAKE (POSITION, move);
		EVAL (move);
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
			v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth);
		}
		else{
			v = -OppPVQsearchEvasion (POSITION, -BETA, -ALPHA, depth);  // 每次将军要减分
		}
		UNDO (POSITION, move);
		CHECK_HALT ();

		if (v <= best_value)
			continue;
		best_value = v;
		if (v <= ALPHA)
			continue;
		ALPHA = v;
		good_move = move;
		HashLower (POSITION->DYN->HASH, move, 1, v);
		if (v >= BETA)
			RETURN (v);
	}
	if (good_move)
	{
		HashExact (POSITION, good_move, 1, best_value, FLAG_EXACT);
		RETURN (best_value);
	}
	HashUpper (POSITION->DYN->HASH, 1, best_value);
	RETURN (best_value);
}
//                                                                    
int MyPVQsearchEvasion (typePOS* POSITION, int ALPHA, int BETA, int depth)
{
	Bitboard TARGET;
	int i;
	uint32 good_move = 0, trans_move = 0, move, BAD_CAPS[64];
	uint32 trans_depth, move_depth = 0;
	int best_value;
	int Value;	
	typeMoveList LIST[128], *list, *p, *q;
	int TEMP, v;
	typeDYNAMIC* POS0 = POSITION->DYN;
	int k = POSITION->DYN->HASH & HashMask;
	int bc = 0;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();

	TRACE (TRACE_PVQSEARCH,
		printf ("PVQ%c V:[%d,%d] dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		ALPHA, BETA, depth, POSITION->DYN->Value));
	CheckRepetition;

	if (BETA < -VALUE_MATE)
		RETURN (-VALUE_MATE);
	if (ALPHA > VALUE_MATE)
		RETURN (VALUE_MATE);
	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_PVQSEARCH, HASH_READ (trans));
			if (IsExact (trans))
			{
				Value = HashUpperBound (trans);
				RETURN (Value);
			}
			if (trans->DepthLower)
			{
				Value = HashLowerBound (trans);
				if (Value >= BETA)
					RETURN (Value);
			}
			if (trans->DepthUpper)
			{
				Value = HashUpperBound (trans);
				if (Value <= ALPHA)
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
	TARGET = OppOccupied;

	if (best_value >= BETA)	{
		RETURN (best_value);
	}
	else if (best_value > ALPHA){
		ALPHA = best_value;
	}
	else
	{
		if (best_value < ALPHA - PrunePawn)
		{
			//TARGET ^= BitboardOppP;
			TARGET = m_xor(TARGET,bitboard_your_pawn);
			if (best_value < ALPHA - PruneMinor)
			{
				//TARGET ^= (BitboardOppN | BitboardOppB);
				TARGET = m_xor(TARGET,	m_or(bitboard_your_shi,bitboard_your_xiang));
				if (best_value < ALPHA - PruneRook){
					//TARGET ^= BitboardOppR;
					TARGET = m_xor(TARGET,	m_or(bitboard_your_ma,bitboard_your_shi));
				}
			}
			best_value += PrunePawn;
		}
	}

	list = MyCapture (POSITION, LIST, TARGET); //先产生吃子步？
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
		if (EasySEE (move) || (move & 0x7fff) == trans_move
			|| MySEE (POSITION, move))
		{
			move &= 0x7fff;
			MAKE (POSITION, move);
			EVAL (move);
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
				v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
			}
			else{
				v = -OppPVQsearch (POSITION, -BETA, -ALPHA, depth - 1);
			}
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v <= ALPHA)
				continue;
			ALPHA = v;
			good_move = move;
			if (v >= BETA)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
		else
			BAD_CAPS[bc++] = move;
	}
	if (depth > 0) {                       // 如果还有深度，就搜索坏的吃子步
		for (i = 0; i < bc; i++)
		{
			move = BAD_CAPS[i] & 0x7fff;
			MAKE (POSITION, move);
			EVAL (move);
			if (ILLEGAL_MOVE)
			{
				UNDO (POSITION, move);
				continue;
			}
#ifdef USE_HASH_EAXCT_VALUE 
			if (IS_EXACT (POSITION->DYN->exact))
				v = -POSITION->DYN->valu;
			else if (MOVE_IS_CHECK){
#else
			if (MOVE_IS_CHECK){
#endif
				v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
			}
			else{
				v = -OppPVQsearch (POSITION, -BETA, -ALPHA, depth - 1);
			}
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v <= ALPHA)
				continue;
			ALPHA = v;
			good_move = move;
			if (v >= BETA)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
	}

	if (depth >= -2 && POS0->valu >= ALPHA - (100 + (12 << (depth + 5))))
	{
		list = MyQuietChecks (POSITION, LIST, TARGET);  // 产生不吃子的将军步
		for (i = 0; i < list - LIST; i++)
		{
			move = LIST[i].move & 0x7fff;

			MAKE (POSITION, move);

			EVAL (move);
			if (ILLEGAL_MOVE)
			{
				UNDO (POSITION, move);
				continue;
			}
#ifdef USE_HASH_EAXCT_VALUE 
			if (IS_EXACT (POSITION->DYN->exact))
				v = -POSITION->DYN->valu;
			else{
				v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
			}
#else
			v = -OppPVQsearchCheck (POSITION, -BETA, -ALPHA, depth - 1);
#endif
			UNDO (POSITION, move);
			CHECK_HALT ();
			if (v <= best_value)
				continue;
			best_value = v;
			if (v <= ALPHA)
				continue;
			ALPHA = v;
			good_move = move;
			if (v >= BETA)
			{
				HashLower (POSITION->DYN->HASH, move, 1, v);
				RETURN (v);
			}
		}
		if (depth >= 0 && ALPHA <= POS0->valu + 150)
		{
			list = MyPositionalGain (POSITION, LIST, ALPHA - POS0->valu);
			for (i = 0; i < list - LIST; i++)
			{
				move = LIST[i].move & 0x7fff;
				MAKE (POSITION, move);
				EVAL (move);
				if (-POS1->valu < ALPHA)
				{
					UNDO (POSITION, move);
					continue;
				}
				if (ILLEGAL_MOVE || MOVE_IS_CHECK)
				{
					UNDO (POSITION, move);
					continue;
				}

#ifdef USE_HASH_EAXCT_VALUE
				if (IS_EXACT (POSITION->DYN->exact))
					v = -POSITION->DYN->valu;
				else{
					v = -OppPVQsearch (POSITION, -BETA, -ALPHA, 0);
				}
#else
				v = -OppPVQsearch (POSITION, -BETA, -ALPHA, 0);
#endif
				UNDO (POSITION, move);
				CHECK_HALT ();
				if (v <= best_value)
					continue;
				best_value = v;
				if (v <= ALPHA)
					continue;
				ALPHA = v;
				good_move = move;
				HashLower (POSITION->DYN->HASH, move, 1, v);
				if (v >= BETA)
					RETURN (v);
			}
		}
	}


	if (good_move)
	{
		HashExact (POSITION, good_move, 1, best_value, FLAG_EXACT);
		RETURN (best_value);
	}
	HashUpper (POSITION->DYN->HASH, 1, best_value);
	RETURN (best_value);
}

#endif