#ifndef BUILD_low_depth
#define BUILD_low_depth
#include "chess.h"

#include "history.h"
#include "null_move.h"
#include "low_depth.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

#ifdef TRACE_COMPILE
#define RETURN(x) \
  { TRACE (TRACE_LOW_DEPTH, \
  printf ("L%cR %d dp:%d V:%d\n", \
  POS_SIDE ? 'w' : 'b', (x), depth, VALUE)); \
  return (x); }
#else
#define RETURN(x) return(x)
#endif

int MyLowDepth (typePOS* POSITION, int VALUE, int depth)
{	
	int cnt, Value, best_value, v, k, i;
	uint32 move, trans_move = 0;
	int move_depth = 0, trans_depth, to, fr;
	typeNEXT NextMove[1];
	typeDYNAMIC* POS0 = POSITION->DYN;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();
	TRACE (TRACE_LOW_DEPTH,
		printf ("L%c V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	/* */
	v = POS0->valu + 1125;
	if (v < VALUE){
		RETURN (VALUE -1);
	}
	/* */

	CheckRepetition;

	k = POSITION->DYN->HASH & HashMask;
	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_LOW_DEPTH, HASH_READ (trans));
			if (trans->DepthLower >= depth)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
				{
					(POS0 + 1)->move = trans->move;
					RETURN (Value);
				}
			}
			if (trans->DepthUpper >= depth){	
				Value = HashUpperBound (trans);
				if (Value < VALUE) // 如果是解将步，则不能返回，回为可能有 BY_LGL
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
	v = POS0->valu - (70 + 10 * depth);
	if (v >= VALUE){
	  RETURN (POS0->valu);
	}
	best_value = MIN (POS0->valu, VALUE - 1);
	if (POS0->valu >= VALUE && MyNull)
	{
		v = VALUE;
		if (v >= VALUE)
		{
			MakeNull (POSITION);
			v = -OppQsearch (POSITION, 1 - VALUE, 0);
			UndoNull (POSITION);
			CHECK_HALT ();
		}
		if (VERIFY_NULL && v >= VALUE)
		{
			int FLAGS = POSITION->DYN->flags;
			POSITION->DYN->flags &= ~3;
			v = MyQsearch (POSITION, VALUE, 0);
			POSITION->DYN->flags = FLAGS;
			CHECK_HALT ();
		}
		if (v >= VALUE)
		{
			if (trans_move == 0)
				HashLower (POSITION->DYN->HASH, 0, depth, v);
			RETURN (v);
		}
	}
	NextMove->phase = TRANS;
	NextMove->TARGET = OppOccupied;
	if (POS0->valu + 50 + 8 * depth < VALUE)
	{
		NextMove->phase = TRANS2;
		if (VALUE >= POS0->valu + 75 + 32 * depth)
		{
			//NextMove->TARGET ^= BitboardOppP;
			NextMove->TARGET = m_xor(NextMove->TARGET,bitboard_your_pawn);  // 去了兵
			//if (BitboardOppP & MyAttacked)
			//	best_value += 125;
			if(m128_is_have_bit(m_and(bitboard_your_pawn,MyAttacked))){
				best_value += 125;
			}
			if (depth <= 3 && VALUE >= POS0->valu + 400 + 32 * depth)
			{
				//NextMove->TARGET ^= (BitboardOppN | BitboardOppB);
				NextMove->TARGET = m_xor(NextMove->TARGET,
					m_or(bitboard_your_shi,bitboard_your_xiang));
				best_value += 300;
				if (VALUE >= POS0->valu + 600 + 32 * depth)
				{
					//NextMove->TARGET ^= BitboardOppR;
					NextMove->TARGET= m_xor(NextMove->TARGET,
						m_or(bitboard_your_ma,bitboard_your_pao));
					best_value += 200;
				}
			}
		}
	}
	else if (depth <= 3 && POS0->valu + 4 * depth < VALUE)
	{
		NextMove->phase = TRANS3;
		NextMove->mask = (VALUE - POS0->valu) + 4 * depth + 5;
	}
	NextMove->bc = 0;
	NextMove->move = 0;
	NextMove->trans_move = trans_move;
	cnt = 0;
	while ((move = MyNext (POSITION, NextMove)))
	{
		to = TO (move);
		fr = FROM (move);

		if (cnt >= depth 
			&& NextMove->phase == ORDINARY_MOVES
			&& (move & RE0XE000) == 0
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr])) 
			//&& MyOccupied ^ (BitboardMyP | BitboardMyK) // 除了兵，将还有其它的子。
			&& m128_is_have_bit(_mm_xor_si128(MyOccupied,m_or(bitboard_my_pawn,bitboard_my_king))))
		{
			if ((2 * depth) + MAX_POSITIONAL (move) + POS0->valu <	VALUE + 40 + 2 * cnt)
			{
				cnt++;
				continue;
			}
		}
		if (cnt > 1 
			&& (PB90(to) == 0 || (depth <= 5 && !EasySEE (move)))  //不是吃子步
			//&& SqSet[fr] & ~MyXRAY 
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr]))  //不是抽将,
			//&& POSITION->sq[fr] != EnumMyK  // 走的不是将。
			&& PB90(fr) != my_king
			//&& !MoveIsEP (move)  // 这儿要加上一个不是将军步，如果是将军步，也不能近回0
			&& move != trans_move 
			&& !MySEE (POSITION, move))  //送吃子？？　// 送子的将军步不走？？ 带着车将,不算送子哇.			
		{
			cnt++;
			continue;
		}

		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue, move);
		if (ILLEGAL_MOVE || (NextMove->phase == POSITIONAL_GAIN_PHASE && MOVE_IS_CHECK))
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
			v = -OppLowDepthCheck (POSITION, 1 - VALUE, depth - 1); //
		}
		else
		{
			int new_depth = depth - 2;
			if (cnt >= depth && (2 * depth) - POS1->valu < VALUE + cnt)
			{
				UNDO (POSITION, move);
				cnt++;
				continue;
			}
			if (QSEARCH_CONDITION){  // QSEARCH_CONDITION        (new_depth <= 1)
				v = -OppQsearch (POSITION, 1 - VALUE, 0);       //这个有问题,对方不走将军步了?
			}
			else{
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			}
		}
		
		if(v > (MAXIMUM_PLY - VALUE_MATE)){
			cnt++;
		}
		

		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v >= VALUE)
		{
			if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
				HISTORY_GOOD (move, depth);
			HashLower (POSITION->DYN->HASH, move, depth, v);
			RETURN (v);
		}
		if (v >= best_value)
			best_value = v;
		if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
			HISTORY_BAD (move, depth);
	}

	if (!cnt && NextMove->phase <= TRANS2){  //没有合法走步就是死了
		RETURN (HEIGHT (POSITION) - VALUE_MATE);
	}
	HashUpper (POSITION->DYN->HASH, depth, best_value);
	RETURN (best_value);
}



int MyLowDepthCheck (typePOS* POSITION, int VALUE, int depth)
{
	int ignored, k, trans_depth, move_depth = 0;
	int  Value;
	uint32 move, trans_move = 0;
	int i, best_value, v, new_depth;
	boolean GEN;
	TRANS_DECLARE ();
	typeMoveList LIST[128], *list, *p, *q;
	typeDYNAMIC* POS0 = POSITION->DYN;
	YUSUF_DECLARE ();
	TRACE (TRACE_LOW_DEPTH,
		printf ("L%cC V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);

	CheckRepetition;

	k = POSITION->DYN->HASH & HashMask;
	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_LOW_DEPTH, HASH_READ (trans));
			if (trans->DepthLower && trans->DepthLower >= depth)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
					RETURN (Value);
			}
			if (trans->DepthUpper && trans->DepthUpper >= depth)
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
	if (trans_move && !MyOK (POSITION, trans_move))
		trans_move = 0;

	best_value = HEIGHT (POSITION) - VALUE_MATE;
	p = LIST;
	LIST[0].move = trans_move;
	GEN = FALSE;
	LIST[1].move = 0;
	ignored = 0;
	while (p->move || !GEN)
	{
		if (!p->move)
		{
			list = MyEvasion (POSITION, LIST + 1, _mm_set1_epi32(0xFFFFFFFF));
			GEN = TRUE;
			for (p = list - 1; p >= LIST + 1; p--)
			{
				if ((p->move & 0x7fff) == trans_move){
					p->move = 0; // BY_LGL
				}
				else if (p->move <= (0x80 << 24))
				{
					if ((p->move & 0x7fff) == POS0->killer1)
						p->move |= 0x7fff8000;
					else if ((p->move & 0x7fff) == POS0->killer2)
						p->move |= 0x7fff0000;
					else
						p->move |= (p->move & 0xffff) |
						((HISTORY_VALUE (POSITION, p->move) >> 1) << 16);
				}
				move = p->move;
				for (q = p + 1; q < list; q++)
				{
					if (move < q->move)
						(q - 1)->move = q->move;
					else
						break;
				}
				q--;
				q->move = move;
			}
			p = LIST + 1;
			continue;
		}
		move = p->move;
		p++;

		if (IsInterpose (move)   // 是杀手步？？
			&& VALUE > -25000 // 搜索
			&& (move & 0x7fff) != trans_move 
			&& !MySEE (POSITION, move))
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
		//int cnt = 0;
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (MOVE_IS_CHECK){
#else
		if (MOVE_IS_CHECK){
#endif
			v = -OppLowDepthCheck (POSITION, 1 - VALUE, depth - 1 + (EARLY_GAME));
		}
		else
		{
			new_depth = depth - 2 + EARLY_GAME;
			if (QSEARCH_CONDITION){
				v = -OppQsearchEvasion (POSITION, 1 - VALUE, 0);
			}
			else{
				v = -OppLowDepthEvasion (POSITION, 1 - VALUE, new_depth);
			}
		}
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v <= best_value)
			continue;
		best_value = v;
		if (v >= VALUE)
		{
			HashLower (POSITION->DYN->HASH, move, MAX (1, depth), v);
			RETURN (v);
		}
	}
	if (ignored && best_value < -25000){
		best_value = VALUE - 1;
	}
	HashUpper (POSITION->DYN->HASH, MAX (1, depth), best_value);
	RETURN (best_value);
}


// 我方是解将步
int MyLowDepthEvasion (typePOS* POSITION, int VALUE, int depth)
{	
	int cnt, Value, best_value, v, k, i, trans_move = 0;
	int move, move_depth = 0, trans_depth, to, fr;
	typeNEXT NextMove[1];
	typeDYNAMIC* POS0 = POSITION->DYN;
	TRANS_DECLARE ();
	YUSUF_DECLARE ();
	TRACE (TRACE_LOW_DEPTH,
		printf ("L%c V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	/* */
	v = POS0->valu + 1125;
	if (v < VALUE){
		RETURN (VALUE -1);
	}
	/* */

	CheckRepetition;

	k = POSITION->DYN->HASH & HashMask;
	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (POSITION->DYN->HASH >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_LOW_DEPTH, HASH_READ (trans));
			if (trans->DepthLower >= depth)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
				{
					(POS0 + 1)->move = trans->move;
					RETURN (Value);
				}
			}
			if (trans->DepthUpper >= depth){
				//if(POSITION->STACKst[POSITION->StackHeight-1].checkk == FALSE){
				Value = HashUpperBound (trans);
				if (Value < VALUE) // 如果是解将步，则不能返回，回为可能有 BY_LGL
					RETURN (Value);
				//}
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
	v = POS0->valu - (70 + 10 * depth);
	if (v >= VALUE){
		//if(POSITION->STACKst[POSITION->StackHeight-1].checkk == FALSE){
		//	RETURN (POS0->valu);
		//}
	}
	best_value = MIN (POS0->valu, VALUE - 1);
	if (POS0->valu >= VALUE && MyNull)
	{
		v = VALUE;
		if (v >= VALUE)
		{
			MakeNull (POSITION);
			v = -OppQsearch (POSITION, 1 - VALUE, 0);
			UndoNull (POSITION);
			CHECK_HALT ();
		}
		if (VERIFY_NULL && v >= VALUE)
		{
			int FLAGS = POSITION->DYN->flags;
			POSITION->DYN->flags &= ~3;
			v = MyQsearch (POSITION, VALUE, 0);
			POSITION->DYN->flags = FLAGS;
			CHECK_HALT ();
		}
		if (v >= VALUE)
		{
			if (trans_move == 0)
				HashLower (POSITION->DYN->HASH, 0, depth, v);
			RETURN (v);
		}
	}
	NextMove->phase = TRANS;
	NextMove->TARGET = OppOccupied;
	if (POS0->valu + 50 + 8 * depth < VALUE)
	{
		NextMove->phase = TRANS2;
		if (VALUE >= POS0->valu + 75 + 32 * depth)
		{
			//NextMove->TARGET ^= BitboardOppP;
			NextMove->TARGET = m_xor(NextMove->TARGET,bitboard_your_pawn);  // 去了兵
			//if (BitboardOppP & MyAttacked)
			//	best_value += 125;
			if(m128_is_have_bit(m_and(bitboard_your_pawn,MyAttacked))){
				best_value += 125;
			}
			if (depth <= 3 && VALUE >= POS0->valu + 400 + 32 * depth)
			{
				//NextMove->TARGET ^= (BitboardOppN | BitboardOppB);
				NextMove->TARGET = m_xor(NextMove->TARGET,
					m_or(bitboard_your_shi,bitboard_your_xiang));
				best_value += 300;
				if (VALUE >= POS0->valu + 600 + 32 * depth)
				{
					//NextMove->TARGET ^= BitboardOppR;
					NextMove->TARGET= m_xor(NextMove->TARGET,
						m_or(bitboard_your_ma,bitboard_your_pao));
					best_value += 200;
				}
			}
		}
	}
	else if (depth <= 3 && POS0->valu + 4 * depth < VALUE)
	{
		NextMove->phase = TRANS3;
		NextMove->mask = (VALUE - POS0->valu) + 4 * depth + 5;
	}
	NextMove->bc = 0;
	NextMove->move = 0;
	NextMove->trans_move = trans_move;
	cnt = 0;
	while ((move = MyNext (POSITION, NextMove)))
	{
		to = TO (move);
		fr = FROM (move);

		if (cnt >= depth 
			&& NextMove->phase == ORDINARY_MOVES
			&& (move & RE0XE000) == 0
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr])) 
			//&& MyOccupied ^ (BitboardMyP | BitboardMyK) // 除了兵，将还有其它的子。
			&& m128_is_have_bit(_mm_xor_si128(MyOccupied,m_or(bitboard_my_pawn,bitboard_my_king))))
		{
			if ((2 * depth) + MAX_POSITIONAL (move) + POS0->valu <	VALUE + 40 + 2 * cnt)
			{
				cnt++;
				continue;
			}
		}
		if (cnt > 1 
			&& (PB90(to) == 0 || (depth <= 5 && !EasySEE (move)))  //不是吃子步
			//&& SqSet[fr] & ~MyXRAY 
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr]))  //不是抽将,
			//&& POSITION->sq[fr] != EnumMyK  // 走的不是将。
			&& PB90(fr) != my_king
			//&& !MoveIsEP (move)  // 这儿要加上一个不是将军步，如果是将军步，也不能近回0
			&& move != trans_move 
			&& !MySEE (POSITION, move))  //送吃子？？　// 送子的将军步不走？？ 带着车将,不算送子哇.			
		{
			cnt++;
			continue;
		}

		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue, move);
		if (ILLEGAL_MOVE || (NextMove->phase == POSITIONAL_GAIN_PHASE && MOVE_IS_CHECK))
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
			v = -OppLowDepthCheck (POSITION, 1 - VALUE, depth - 1); //
		}
		else
		{
			int new_depth = depth - 2;
			if (cnt >= depth && (2 * depth) - POS1->valu < VALUE + cnt)
			{
				UNDO (POSITION, move);
				cnt++;
				continue;
			}
			if (QSEARCH_CONDITION){  // QSEARCH_CONDITION        (new_depth <= 1)
				v = -OppQsearch (POSITION, 1 - VALUE, 0);       //这个有问题,对方不走将军步了?
			}
			else{
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			}
		}

		if(v > (MAXIMUM_PLY - VALUE_MATE)){
			cnt++;
		}

		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v >= VALUE)
		{
			if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
				HISTORY_GOOD (move, depth);
			HashLower (POSITION->DYN->HASH, move, depth, v);
			RETURN (v);
		}
		if (v >= best_value)
			best_value = v;
		if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
			HISTORY_BAD (move, depth);
	}

	if (!cnt && NextMove->phase <= TRANS2){  //没有合法走步就是死了。
		RETURN (HEIGHT (POSITION) - VALUE_MATE);
	}
	HashUpper (POSITION->DYN->HASH, depth, best_value);
	RETURN (best_value);
}

#endif