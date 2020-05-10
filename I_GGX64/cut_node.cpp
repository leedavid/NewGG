#ifndef BUILD_nodo_tagliatoee
#define BUILD_nodo_tagliatoee
#include "chess.h"
#include "history.h"
#include "null_move.h" 
#include "cut_node.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

#define RETURN(x) return(x)

// my_node_cut

int MyCut (typePOS* POSITION, int VALUE, int depth)
{
	int height, i, SINGULAR;
	uint32 move;
	int k;
	TRANS_DECLARE();
	int trans_depth, move_depth = 0, Value, cnt;
	uint32 trans_move = 0;
	int v, EXTEND, new_depth, move_is_check;
	typeNEXT NextMove[1];
	typeDYNAMIC* POS0 = POSITION->DYN;
	uint64 zob = POSITION->DYN->HASH;
	int to, fr;
	boolean SPLIT;
	YUSUF_DECLARE ();
	TRACE (TRACE_CUT,
		printf ("C%c V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	CheckRepetition;

	k = zob & HashMask;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (zob >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_CUT, HASH_READZ (trans, zob));
			trans_depth = trans->DepthLower;
			move = trans->move;
			if (move && trans_depth > move_depth)
			{
				move_depth = trans_depth;
				(POS0 + 1)->move = trans_move = move;
			}
			trans_depth = MAX (trans->DepthLower, trans->DepthUpper);
			if (trans->DepthLower >= depth)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
				{
					if (!((trans->flags & FLAG_ALL) == FLAG_ALL))
						if (MyNull || move)
						{
							UPDATE_AGE ();
							RETURN (Value);
						}
				}
			}
			if (trans->DepthUpper >= depth)
			{
				Value = HashUpperBound (trans);
				if (Value < VALUE)
				{
					UPDATE_AGE ();
					RETURN (Value);
				}
			}
		}
	}
	NextMove->trans_move = trans_move;

	if (POS0->valu >= VALUE && MyNull)
	{
		if (SMOOTH_SCALING)
			new_depth = null_new_depth(depth, POS0->valu - VALUE);
		else
		{
			new_depth = depth - NULL_REDUCTION;
			new_depth -= ((uint32) (MIN (POS0->valu - VALUE, 96))) / 32;
		}
		v = VALUE;
		if (v >= VALUE)
		{
			MakeNull (POSITION);
			if (QSEARCH_CONDITION)
				v = -OppQsearch (POSITION, 1 - VALUE, 0);
			else if (LOW_DEPTH_CONDITION)
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppAll (POSITION, 1 - VALUE, new_depth);
			UndoNull (POSITION);
			CHECK_HALT ();
		}
		if (VERIFY_NULL && v >= VALUE)
		{
			int FLAGS = POSITION->DYN->flags;
			POSITION->DYN->flags &= ~3;
			new_depth -= VERIFY_REDUCTION;
			if (QSEARCH_CONDITION)
				v = MyQsearch (POSITION, VALUE, 0);
			else if (LOW_DEPTH_CONDITION)
				v = MyLowDepth (POSITION, VALUE, new_depth);
			else
				v = MyCut (POSITION, VALUE, new_depth);
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

	if (trans_move == 0 && depth >= 6)
	{
		new_depth = depth - 4;
		if (LOW_DEPTH_CONDITION)
			v = MyLowDepth (POSITION, VALUE, new_depth);
		else
			v = MyCut (POSITION, VALUE, new_depth);
		CHECK_HALT ();
		if (v >= VALUE)
			trans_move = (POS0 + 1)->move;
	}
	SINGULAR = 0;
	if (depth >= 16 && trans_move && MyOK (POSITION, trans_move))
	{
		v = MyExclude (POSITION, VALUE - depth, depth - MIN (12, depth / 2),
			trans_move & 0x7fff);
		CHECK_HALT ();
		if (v < VALUE - depth)
		{
			SINGULAR++;
			height = HEIGHT (POSITION);
			if (height * 4 <= depth)
				SINGULAR++;
			v = MyExclude (POSITION, VALUE - 2 * depth,
				depth - MIN (12, depth / 2), trans_move & 0x7fff);
			CHECK_HALT ();
			if (v < VALUE - 2 * depth)
			{
				SINGULAR++;
				if (height * 8 <= depth)
					SINGULAR++;
			}
		}
	}

	cnt = 0;
	NextMove->trans_move = trans_move;
	NextMove->phase = TRANS;
	NextMove->TARGET = OppOccupied;
	if (depth < 20 && VALUE - POS0->valu >= 48 * (depth - 5))
	{
		NextMove->phase = TRANS2;
		cnt = 1;
		if (VALUE - POS0->valu >= 48 * (depth - 2)){
			//NextMove->TARGET ^=  bitboard_your_pawn;//BitboardOppP;
			NextMove->TARGET = m_xor(NextMove->TARGET,bitboard_your_pawn);
		}
	}
	NextMove->move = 0;
	NextMove->bc = 0;
	v = VALUE;

	SPLIT = FALSE;

	while (TRUE)
	{
#if 1 && defined (YUSUF_MULTICORE)
		if (TITANIC_MODE && SMP_FREE != 0 && SPLIT_AT_CUT &&
			depth >= CUT_SPLIT_DEPTH && !SPLIT && NextMove->phase != TRANS &&
			cnt >= 1  && NextMove->phase <= ORDINARY_MOVES)
		{
			int r;
			boolean b;
			SPLIT = TRUE;
			b = IVAN_SPLIT
				(POSITION, NextMove, depth, VALUE, VALUE, NODE_TYPE_CUT, &r);
			if (b)
				return r;
		}
#endif
		move = MyNext (POSITION, NextMove);
		if (!move)
			break;
		to = TO (move);
		fr = FROM (move);

		if (cnt > 5 
			&& NextMove->phase == ORDINARY_MOVES
			&& (move & RE0XE000) == 0 			
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr])) 
			&& depth < 20)
		{
			if ((1 << (depth - 6)) + MAX_POSITIONAL (move) +
				(POS0->valu) < VALUE + 35 + 2 * cnt)
			{
				cnt++;
				continue;
			}
		}
		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue2, move);

		if (ILLEGAL_MOVE)
		{
			UNDO (POSITION, move);
			continue;
		}
		if (MOVE_IS_CHECK){
			move_is_check = 1;
		}
		else{
			move_is_check = 0;
		}

		if (move != NextMove->trans_move)
			SINGULAR = 0;
		EXTEND = 0;
		if (move == NextMove->trans_move)
		{
			if (PassedPawnPush (to, FOURTH_RANK (to)))
				EXTEND = 1;
		}
		else
		{
			if (PassedPawnPush (to, SIXTH_RANK (to)))
				EXTEND = 1;
		}
		if (NextMove->trans_move == move
			&& TO ((POS1 - 1)->move) == TO (POS1->move)  // ЁтвсясиЛ
			&& (POS1 - 1)->catturaa != 0)
			EXTEND++;
		EXTEND = MAX (EXTEND, SINGULAR);
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (move_is_check)	{
#else
		if (move_is_check)	{
#endif
			new_depth = depth - 2 + MAX (1, EXTEND);
			v = -OppAllCheck (POSITION, 1 - VALUE, new_depth);
		}
		else
		{
			if (cnt > 2 
				&& depth < 20 
				&& POS1->catturaa == 0
				&& (2 << (depth - 6)) - POS1->valu < VALUE + cnt - 15)
			{
				UNDO (POSITION, move);
				cnt++;
				continue;
			}
			if (NextMove->phase == ORDINARY_MOVES && !EXTEND)
			{
				new_depth = depth - 2 + EXTEND - (4 + BSR (4 + cnt));
				if (QSEARCH_CONDITION)
					v = -OppQsearch (POSITION, 1 - VALUE, 0);
				else if (LOW_DEPTH_CONDITION)
					v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
				else
					v = -OppAll (POSITION, 1 - VALUE, new_depth);
				if (v < VALUE)
					goto DONE;
			}
			new_depth = depth - 2 + EXTEND;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppAll (POSITION, 1 - VALUE, new_depth);
		}
DONE:
		UNDO (POSITION, move);
		CHECK_HALT ();

		if(v > HEIGHT (POSITION) - VALUE_MATE){
			cnt++;
		}

		if (v >= VALUE)
		{
			if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
				HISTORY_GOOD (move, depth);
			HashLower (POSITION->DYN->HASH, move, depth, v);
			RETURN (v);
		}
		if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
			HISTORY_BAD (move, depth);
	}

	if (!cnt && NextMove->phase <= TRANS2){
		RETURN (HEIGHT (POSITION) - VALUE_MATE);
	}
	v = VALUE - 1;
	HashUpperCUT (POSITION, depth, v);
	RETURN (v);
}

int MyCutCheck (typePOS* POSITION, int VALUE, int depth)
{
	uint32 move;
	int height, k, cnt, REDUCTION, EXTEND;
	uint32 trans_move = 0;
	int trans_depth, move_depth = 0, Value, new_depth, v, i;
	TRANS_DECLARE();
	typeMoveList LIST[128], *list, *p, *q;
	uint64 zob = POSITION->DYN->HASH;
	int best_value, SINGULAR;
	typeDYNAMIC *POS0 = POSITION->DYN;
	boolean GEN;
	YUSUF_DECLARE ();
	TRACE (TRACE_CUT,
		printf ("C%cC V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	CheckRepetition;

	k = zob & HashMask;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (zob >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_LOW_DEPTH, HASH_READZ (trans, zob));
			trans_depth = trans->DepthLower;
			move = trans->move;
			if (move && trans_depth > move_depth)
			{
				move_depth = trans_depth;
				(POS0 + 1)->move = trans_move = move;
			}
			trans_depth = MAX (trans->DepthLower, trans->DepthUpper);
			if (trans->DepthLower >= depth)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
				{
					if (!((trans->flags & FLAG_ALL) == FLAG_ALL))
					{
						UPDATE_AGE ();
						RETURN (Value);
					}
				}
			}
			if (trans->DepthUpper >= depth)
			{
				Value = HashUpperBound (trans);
				if (Value < VALUE)
				{
					UPDATE_AGE ();
					RETURN (Value);
				}
			}
		}
	}
	if (trans_move && !MyOK (POSITION, trans_move))
		trans_move = 0;

	best_value = HEIGHT (POSITION) - VALUE_MATE;
	SINGULAR = 0;
	if (depth >= 16 && trans_move)
	{
		v = MyExcludeCheck (POSITION, VALUE - depth,
			depth - MIN (12, depth / 2), trans_move & 0x7fff);
		CHECK_HALT ();
		if (v < VALUE - depth)
		{
			SINGULAR++;
			height = HEIGHT (POSITION);
			if (height * 4 <= depth)
				SINGULAR++;
			v = MyExcludeCheck (POSITION, VALUE - 2 * depth,
				depth - MIN (12, depth / 2), trans_move & 0x7fff);
			CHECK_HALT ();
			if (v < VALUE - 2 * depth)
			{
				SINGULAR++;
				if (height * 8 <= depth)
					SINGULAR++;
			}
		}
	}

	p = LIST;
	LIST[0].move = trans_move;
	cnt = 0;
	GEN = FALSE;
	LIST[1].move = 0;
	while (p->move || !GEN)
	{
		if (!p->move)
		{
			list = MyEvasion (POSITION, LIST + 1, _mm_set1_epi32(0xFFFFFFFF));
			GEN = TRUE;
			for (p = list - 1; p >= LIST + 1; p--)
			{
				if ((p->move & 0x7fff) == trans_move)
					p->move = 0;
				else if (p->move <= (0x80 << 24))
				{
					if ((p->move & 0x7fff) == POS0->killer1)
						p->move |= 0x7fff8000;
					else if ((p->move & 0x7fff) == POS0->killer2)
						p->move |= 0x7fff0000;
					else
						p->move |=
						(p->move & 0x7fff) |
						(HISTORY_VALUE (POSITION, p->move) << 15);
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
		move = p->move & 0x7fff;
		p++;
		if (move != trans_move)
			SINGULAR = 0;

		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue2, move);
		if (ILLEGAL_MOVE)
		{
			UNDO (POSITION, move);
			continue;
		}
#ifdef USE_HASH_EAXCT_VALUE 		
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (MOVE_IS_CHECK)
#else
		if (MOVE_IS_CHECK)
#endif
		{
			new_depth = depth - 2;
			if (SINGULAR)
				new_depth += SINGULAR;
			else
				new_depth++;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepthCheck (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppAllCheck (POSITION, 1 - VALUE, new_depth);
		}
		else
		{
			if (cnt >= 1)
			{
				if (depth > 8)
					REDUCTION = BSR (depth - 7);
				else
					REDUCTION = 0;
				REDUCTION += 1 + MIN (cnt, 2);
				if (EARLY_GAME)
					EXTEND = 1;
				else
					EXTEND = 0;
				new_depth = depth + EXTEND - REDUCTION - 2;
				if (QSEARCH_CONDITION)
					v = -OppQsearchEvasion (POSITION, 1 - VALUE, 0);
				else if (LOW_DEPTH_CONDITION)
					v = -OppLowDepthEvasion (POSITION, 1 - VALUE, new_depth);
				else
					v = -OppAllEvasion (POSITION, 1 - VALUE, new_depth);
				if (v < VALUE)
					goto LOOP;
			}
			if (!SINGULAR && EARLY_GAME)
				EXTEND = 1;
			else
				EXTEND = 0;
			new_depth = depth - 2 + EXTEND + SINGULAR;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepthEvasion (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppAllEvasion (POSITION, 1 - VALUE, new_depth);
		}
LOOP:
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v > best_value)
			best_value = v;
		if (v < VALUE)
		{
			cnt++;
			continue;
		}

		HashLower (POSITION->DYN->HASH, move, MAX (1, depth), v);
		RETURN (v);
	}

	HashUpperCUT (POSITION, MAX (1, depth), best_value);
	RETURN (best_value);
}

int MyCutEvasion (typePOS* POSITION, int VALUE, int depth)
{
	int height, i, SINGULAR;
	uint32 move;
	int k;
	TRANS_DECLARE();
	int trans_depth, move_depth = 0, Value, cnt;
	uint32 trans_move = 0;
	int v, EXTEND, new_depth, move_is_check;
	typeNEXT NextMove[1];
	typeDYNAMIC* POS0 = POSITION->DYN;
	uint64 zob = POSITION->DYN->HASH;
	int to, fr;
	boolean SPLIT;
	YUSUF_DECLARE ();
	TRACE (TRACE_CUT,
		printf ("C%c V:%d dp:%d ev:%d\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	CheckRepetition;

	k = zob & HashMask;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (zob >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_CUT, HASH_READZ (trans, zob));
			trans_depth = trans->DepthLower;
			move = trans->move;
			if (move && trans_depth > move_depth)
			{
				move_depth = trans_depth;
				(POS0 + 1)->move = trans_move = move;
			}
			trans_depth = MAX (trans->DepthLower, trans->DepthUpper);
			if (trans->DepthLower >= depth)
			{
				Value = HashLowerBound (trans);
				if (Value >= VALUE)
				{
					if (!((trans->flags & FLAG_ALL) == FLAG_ALL))
						if (MyNull || move)
						{
							UPDATE_AGE ();
							RETURN (Value);
						}
				}
			}
			if (trans->DepthUpper >= depth)
			{
				Value = HashUpperBound (trans);
				if (Value < VALUE)
				{
					UPDATE_AGE ();
					RETURN (Value);
				}
			}
		}
	}
	NextMove->trans_move = trans_move;

	if (POS0->valu >= VALUE && MyNull)
	{
		new_depth = depth - NULL_REDUCTION;
		new_depth -= ((uint32) (MIN (POS0->valu - VALUE, 96))) / 32;
		v = VALUE;
		if (v >= VALUE)
		{
			MakeNull (POSITION);
			if (QSEARCH_CONDITION)
				v = -OppQsearch (POSITION, 1 - VALUE, 0);
			else if (LOW_DEPTH_CONDITION)
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppAll (POSITION, 1 - VALUE, new_depth);
			UndoNull (POSITION);
			CHECK_HALT ();
		}
		if (VERIFY_NULL && v >= VALUE)
		{
			int FLAGS = POSITION->DYN->flags;
			POSITION->DYN->flags &= ~3;
			new_depth -= VERIFY_REDUCTION;
			if (QSEARCH_CONDITION)
				v = MyQsearch (POSITION, VALUE, 0);
			else if (LOW_DEPTH_CONDITION)
				v = MyLowDepth (POSITION, VALUE, new_depth);
			else
				v = MyCut (POSITION, VALUE, new_depth);
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

	if (trans_move == 0 && depth >= 6)
	{
		new_depth = depth - 4;
		if (LOW_DEPTH_CONDITION)
			v = MyLowDepth (POSITION, VALUE, new_depth);
		else
			v = MyCut (POSITION, VALUE, new_depth);
		CHECK_HALT ();
		if (v >= VALUE)
			trans_move = (POS0 + 1)->move;
	}
	SINGULAR = 0;
	if (depth >= 16 && trans_move && MyOK (POSITION, trans_move))
	{
		v = MyExclude (POSITION, VALUE - depth, depth - MIN (12, depth / 2),
			trans_move & 0x7fff);
		CHECK_HALT ();
		if (v < VALUE - depth)
		{
			SINGULAR++;
			height = HEIGHT (POSITION);
			if (height * 4 <= depth)
				SINGULAR++;
			v = MyExclude (POSITION, VALUE - 2 * depth,
				depth - MIN (12, depth / 2), trans_move & 0x7fff);
			CHECK_HALT ();
			if (v < VALUE - 2 * depth)
			{
				SINGULAR++;
				if (height * 8 <= depth)
					SINGULAR++;
			}
		}
	}

	cnt = 0;
	NextMove->trans_move = trans_move;
	NextMove->phase = TRANS;
	NextMove->TARGET = OppOccupied;
	if (depth < 20 && VALUE - POS0->valu >= 48 * (depth - 5))
	{
		NextMove->phase = TRANS2;
		cnt = 1;
		if (VALUE - POS0->valu >= 48 * (depth - 2)){
			//NextMove->TARGET ^=  bitboard_your_pawn;//BitboardOppP;
			NextMove->TARGET = m_xor(NextMove->TARGET,bitboard_your_pawn);
		}
	}
	NextMove->move = 0;
	NextMove->bc = 0;
	v = VALUE;

	SPLIT = FALSE;

	while (TRUE)
	{
#if 1 && defined (YUSUF_MULTICORE)
		if (TITANIC_MODE && SMP_FREE != 0 && SPLIT_AT_CUT &&
			depth >= CUT_SPLIT_DEPTH && !SPLIT && NextMove->phase != TRANS &&
			cnt >= 1  && NextMove->phase <= ORDINARY_MOVES)
		{
			int r;
			boolean b;
			SPLIT = TRUE;
			b = IVAN_SPLIT
				(POSITION, NextMove, depth, VALUE, VALUE, NODE_TYPE_CUT, &r);
			if (b)
				return r;
		}
#endif
		move = MyNext (POSITION, NextMove);
		if (!move)
			break;
		to = TO (move);
		fr = FROM (move);

		if (cnt > 5 
			&& NextMove->phase == ORDINARY_MOVES
			&& (move & RE0XE000) == 0 			
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr])) 
			&& depth < 20)
		{
			if ((1 << (depth - 6)) + MAX_POSITIONAL (move) +
				(POS0->valu) < VALUE + 35 + 2 * cnt)
			{
				cnt++;
				continue;
			}
		}
		move &= 0x7fff;
		MAKE (POSITION, move);
		EvalLazy (VALUE, VALUE, LazyValue2, move);

		if (ILLEGAL_MOVE)
		{
			UNDO (POSITION, move);
			continue;
		}
		if (MOVE_IS_CHECK){
			move_is_check = 1;
		}
		else{
			move_is_check = 0;
		}

		if (move != NextMove->trans_move)
			SINGULAR = 0;
		EXTEND = 0;
		if (move == NextMove->trans_move)
		{
			if (PassedPawnPush (to, FOURTH_RANK (to)))
				EXTEND = 1;
		}
		else
		{
			if (PassedPawnPush (to, SIXTH_RANK (to)))
				EXTEND = 1;
		}
		if (NextMove->trans_move == move
			&& TO ((POS1 - 1)->move) == TO (POS1->move)  // ЁтвсясиЛ
			&& (POS1 - 1)->catturaa != 0)
			EXTEND++;
		EXTEND = MAX (EXTEND, SINGULAR);

#ifdef USE_HASH_EAXCT_VALUE 	
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (move_is_check)	{
#else
		if (move_is_check)	{
#endif
			new_depth = depth - 2 + MAX (1, EXTEND);
			v = -OppAllCheck (POSITION, 1 - VALUE, new_depth);
		}
		else
		{
			if (cnt > 2 
				&& depth < 20 
				&& POS1->catturaa == 0
				&& (2 << (depth - 6)) - POS1->valu < VALUE + cnt - 15)
			{
				UNDO (POSITION, move);
				cnt++;
				continue;
			}
			if (NextMove->phase == ORDINARY_MOVES && !EXTEND)
			{
				new_depth = depth - 2 + EXTEND - (4 + BSR (4 + cnt));
				if (QSEARCH_CONDITION)
					v = -OppQsearch (POSITION, 1 - VALUE, 0);
				else if (LOW_DEPTH_CONDITION)
					v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
				else
					v = -OppAll (POSITION, 1 - VALUE, new_depth);
				if (v < VALUE)
					goto DONE;
			}
			new_depth = depth - 2 + EXTEND;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppAll (POSITION, 1 - VALUE, new_depth);
		}
DONE:
		UNDO (POSITION, move);
		CHECK_HALT ();

		//if(v > HEIGHT (POSITION) - VALUE_MATE){
		cnt++;
		//}

		if (v >= VALUE)
		{
			if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
				HISTORY_GOOD (move, depth);
			HashLower (POSITION->DYN->HASH, move, depth, v);
			RETURN (v);
		}
		if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
			HISTORY_BAD (move, depth);
	}

	if (!cnt && NextMove->phase <= TRANS2){
		RETURN (HEIGHT (POSITION) - VALUE_MATE);
	}
	v = VALUE - 1;
	HashUpperCUT (POSITION, depth, v);
	RETURN (v);
}

#endif