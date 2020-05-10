#ifndef BUILD_exclude_node
#define BUILD_exclude_node
#include "chess.h"
#include "history.h"
#include "null_move.h"

#include "exclude_node.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

#ifdef TRACE_COMPILE
#define RETURN(x) \
  { TRACE (TRACE_EXCLUDE, \
  printf ("E%cR %d dp:%d V:%d\n", \
  POS_SIDE ? 'w' : 'b', (x), depth, VALUE)); \
  return (x); }
#else
#define RETURN(x) return(x)
#endif

int MyExclude (typePOS* POSITION, int VALUE, int depth, uint32 MOVE)
{
	int i;
	uint32 move;
	int k;
	TRANS_DECLARE ();
	int trans_depth, move_depth = 0, Value, cnt;
	uint32 trans_move = 0;
	int v, EXTEND, new_depth, move_is_check;
	typeNEXT NextMove[1];
	typeDYNAMIC* POS0 = POSITION->DYN;
	uint64 zob = POSITION->DYN->HASH;
	int to, fr;
	int REDUCTION;
	boolean SPLIT;
	int SPLIT_ABISSO;
	YUSUF_DECLARE ();
	TRACE (TRACE_EXCLUDE,
		printf ("E%c V:%d dp:%d ev:%d %s\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value, Notate (MOVE, STRING1)));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	CheckRepetition;

	// zob ^= ZOBRIST[EnumMyK][FROM (MOVE)] ^ ZOBRIST[EnumOppK][TO (MOVE)];
	zob ^= ZOBRIST[my_king][FROM (MOVE)] ^ ZOBRIST[your_king][TO (MOVE)];
	k = zob & HashMask;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (zob >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_EXCLUDE, HASH_READZ (trans, zob));
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
					if (1)
					{
						UPDATE_AGE ();
						RETURN (Value);
					}
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
				v = -OppCut (POSITION, 1 - VALUE, new_depth);
			UndoNull (POSITION);
			CHECK_HALT();
		}
		new_depth -= VERIFY_REDUCTION;
		if (VERIFY_NULL && v >= VALUE && new_depth > 7)
		{
			int FLAGS = POSITION->DYN->flags;
			POSITION->DYN->flags &= ~3;
			v = MyExclude (POSITION, VALUE, new_depth, MOVE);
			POSITION->DYN->flags = FLAGS;
			CHECK_HALT ();
		}
		if (v >= VALUE)
		{
			if (trans_move == 0)
				HashLower (zob, 0, depth, v);
			RETURN (v);
		}
	}

	cnt = 0;
	NextMove->trans_move = trans_move;
	NextMove->phase = TRANS;
	NextMove->TARGET = OppOccupied;
	if (depth < 20 && VALUE - POS0->valu >= 48 * (depth - 4))
	{
		NextMove->phase = TRANS2;
		cnt = 1;
		if (VALUE - POS0->valu >= 48 * (depth - 2)){
			//NextMove->TARGET ^= BitboardOppP;
			NextMove->TARGET = m_xor(NextMove->TARGET,bitboard_your_pawn);
		}
	}

	NextMove->move = 0;
	NextMove->bc = 0;
	NextMove->exclude = MOVE & 0x7fff;
	v = VALUE;
	SPLIT = FALSE;
	SPLIT_ABISSO = 14;

	while (TRUE)
	{
#if 0 && defined (YUSUF_MULTICORE) /* con MOVE ? -- hash ? */
		if (TITANIC_MODE && SMP_FREE != 0 && depth >= SPLIT_ABISSO &&
			!SPLIT && NextMove->phase != TRANS && cnt >= 1 &&
			NextMove->phase <= ORDINARY_MOVES)
		{
			int r;
			boolean b;
			SPLIT = TRUE;
			b = IVAN_SPLIT
				(POSITION, NextMove, depth, VALUE, VALUE, NODE_TYPE_ALL, &r);
			if (b)
				return r;
		}
#endif
		move = MyNext (POSITION, NextMove);
		if (!move)
			break;
		if ((move & 0x7fff) == (MOVE & 0x7fff))
			continue;
		to = TO (move);
		fr = FROM (move);

		if (cnt > 5 
			&& NextMove->phase == ORDINARY_MOVES			
			&& (move & RE0XE000) == 0 			
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr]))
			&& depth < 20)
		{
			if ((6 << (depth - 6)) + MAX_POSITIONAL (move) +
				(POS0->valu) < VALUE + 30 + 2 * cnt)
			{
				cnt++;
				continue;
			}
		}
		REDUCTION = 0;
		if (depth < 20 
			&& (2 << (depth - 6)) + (POS0->valu) < VALUE + 125
			&& NextMove->phase == ORDINARY_MOVES 
			&& my_king_pos != fr
			//&& SqSet[fr] & ~MyXRAY 
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr]))
			&& (move & 0x8000) == 0
			&& !MySEE (POSITION, move))	
		{
			cnt++;
			continue;
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
		EXTEND = 0;
		if (PassedPawnPush (to, SIXTH_RANK (to))){
			EXTEND = 1;
		}
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (move_is_check){
#else
		if (move_is_check){
#endif
			v = -OppCutCheck (POSITION, 1 - VALUE, depth - 1);
		}
		else
		{
			if (cnt > 5 
				&& depth < 20 
				&& POS1->catturaa == 0
				&& (2 << (depth - 6)) - POS1->valu < VALUE + cnt - 15)
			{
				UNDO (POSITION, move);
				cnt++;
				continue;
			}
			if (NextMove->phase == ORDINARY_MOVES && (cnt >= 3 || REDUCTION))
			{
				new_depth =
					depth - 2 + EXTEND - BSR (1 + cnt) - REDUCTION;
				if (QSEARCH_CONDITION)
					v = -OppQsearch (POSITION, 1 - VALUE, 0);
				else if (LOW_DEPTH_CONDITION)
					v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
				else
					v = -OppCut (POSITION, 1 - VALUE, new_depth);
				if (v < VALUE)
					goto DONE;
			}
			new_depth = depth - 2 + EXTEND;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppCut (POSITION, 1 - VALUE, new_depth);
		}
DONE:
		UNDO (POSITION, move);
		CHECK_HALT ();
		cnt++;
		if (v >= VALUE)
		{
			if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
				HISTORY_GOOD (move, depth);
			HashLower (zob, move, depth, v);
			RETURN (v);
		}
		if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
			HISTORY_BAD (move, depth);
	}
	v = VALUE - 1;
	HashUpper (zob, depth, v);
	RETURN (v);
}

int MyExcludeCheck (typePOS* POSITION, int VALUE, int depth, uint32 MOVE)
{
	uint32 move;
	int k, cnt, EXTEND;
	uint32 trans_move = 0;
	int trans_depth, move_depth = 0, Value, new_depth, v, i;
	TRANS_DECLARE ();
	typeMoveList LIST[128], *list, *p, *q;
	uint64 zob = POSITION->DYN->HASH;
	int best_value;
	typeDYNAMIC *POS0 = POSITION->DYN;
	boolean GEN;
	YUSUF_DECLARE ();
	TRACE (TRACE_EXCLUDE,
		printf ("E%cC V:%d dp:%d ev:%d %s\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value, Notate (MOVE, STRING1)));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	zob ^= ZOBRIST[my_king][FROM (MOVE)] ^ ZOBRIST[your_king][TO (MOVE)];
	(POS0 + 1)->move = 0;
	CheckRepetition;

	k = zob & HashMask;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (zob >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_EXCLUDE, HASH_READZ (trans, zob));
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
					if (1)
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
					if (1)
					{
						UPDATE_AGE ();
						RETURN (Value);
					}
				}
			}
		}
	}
	if (trans_move && !MyOK (POSITION, trans_move))
		trans_move = 0;

	best_value = HEIGHT (POSITION) - VALUE_MATE;
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
				if ((p->move & 0x7fff) == trans_move){
					p->move = 0;
				}
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
		if (move == MOVE)
			continue;

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
			new_depth = depth - 1;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepthCheck (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppCutCheck (POSITION, 1 - VALUE, new_depth);
		}
		else
		{
			if (cnt >= 1)
			{
				if (EARLY_GAME)
					EXTEND = 1;
				else
					EXTEND = 0;
				new_depth = depth - 2 - MIN (2, cnt) + EXTEND;
				if (QSEARCH_CONDITION)
					v = -OppQsearchEvasion (POSITION, 1 - VALUE, 0);
				else if (LOW_DEPTH_CONDITION)
					v = -OppLowDepthEvasion (POSITION, 1 - VALUE, new_depth);
				else
					v = -OppCut (POSITION, 1 - VALUE, new_depth);
				if (v < VALUE)
					goto LOOP;
			}
			if (EARLY_GAME)
				EXTEND = 1;
			else
				EXTEND = 0;
			new_depth = depth - 2 + EXTEND;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepthEvasion (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppCutEvasion (POSITION, 1 - VALUE, new_depth);
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

		HashLower (zob, move, MAX (1, depth), v);
		RETURN (v);
	}
	HashUpper (zob, MAX (1, depth), best_value);
	RETURN (best_value);
}

int MyExcludeEvasion (typePOS* POSITION, int VALUE, int depth, uint32 MOVE)
{
	int i;
	uint32 move;
	int k;
	TRANS_DECLARE ();
	int trans_depth, move_depth = 0, trans_move = 0, Value, cnt;
	int v, EXTEND, new_depth, move_is_check;
	typeNEXT NextMove[1];
	typeDYNAMIC* POS0 = POSITION->DYN;
	uint64 zob = POSITION->DYN->HASH;
	int to, fr;
	int REDUCTION;
	boolean SPLIT;
	int SPLIT_ABISSO;
	YUSUF_DECLARE ();
	TRACE (TRACE_EXCLUDE,
		printf ("E%c V:%d dp:%d ev:%d %s\n", POS_SIDE ? 'w' : 'b',
		VALUE, depth, POSITION->DYN->Value, Notate (MOVE, STRING1)));

	if (VALUE < -VALUE_MATE + 1)
		RETURN (-VALUE_MATE + 1);
	if (VALUE > VALUE_MATE - 1)
		RETURN (VALUE_MATE - 1);
	(POS0 + 1)->move = 0;
	CheckRepetition;

	// zob ^= ZOBRIST[EnumMyK][FROM (MOVE)] ^ ZOBRIST[EnumOppK][TO (MOVE)];
	zob ^= ZOBRIST[my_king][FROM (MOVE)] ^ ZOBRIST[your_king][TO (MOVE)];
	k = zob & HashMask;

	for (i = 0; i < 4; i++)
	{
		Trans = HashTable + (k + i);
		HYATT_HASH (Trans, trans);
		if ((trans->hash ^ (zob >> 32)) == 0)
		{
			TRACE (TRACE_HASH && TRACE_EXCLUDE, HASH_READZ (trans, zob));
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
					if (1)
					{
						UPDATE_AGE ();
						RETURN (Value);
					}
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
				v = -OppCut (POSITION, 1 - VALUE, new_depth);
			UndoNull (POSITION);
			CHECK_HALT();
		}
		new_depth -= VERIFY_REDUCTION;
		if (VERIFY_NULL && v >= VALUE && new_depth > 7)
		{
			int FLAGS = POSITION->DYN->flags;
			POSITION->DYN->flags &= ~3;
			v = MyExclude (POSITION, VALUE, new_depth, MOVE);
			POSITION->DYN->flags = FLAGS;
			CHECK_HALT ();
		}
		if (v >= VALUE)
		{
			if (trans_move == 0)
				HashLower (zob, 0, depth, v);
			RETURN (v);
		}
	}

	cnt = 0;
	NextMove->trans_move = trans_move;
	NextMove->phase = TRANS;
	NextMove->TARGET = OppOccupied;
	if (depth < 20 && VALUE - POS0->valu >= 48 * (depth - 4))
	{
		NextMove->phase = TRANS2;
		cnt = 1;
		if (VALUE - POS0->valu >= 48 * (depth - 2)){
			//NextMove->TARGET ^= BitboardOppP;
			NextMove->TARGET = m_xor(NextMove->TARGET,bitboard_your_pawn);
		}
	}

	NextMove->move = 0;
	NextMove->bc = 0;
	NextMove->exclude = MOVE & 0x7fff;
	v = VALUE;
	SPLIT = FALSE;
	SPLIT_ABISSO = 14;

	while (TRUE)
	{
#if 0 && defined (YUSUF_MULTICORE) /* con MOVE ? -- hash ? */
		if (TITANIC_MODE && SMP_FREE != 0 && depth >= SPLIT_ABISSO &&
			!SPLIT && NextMove->phase != TRANS && cnt >= 1 &&
			NextMove->phase <= ORDINARY_MOVES)
		{
			int r;
			boolean b;
			SPLIT = TRUE;
			b = IVAN_SPLIT
				(POSITION, NextMove, depth, VALUE, VALUE, NODE_TYPE_ALL, &r);
			if (b)
				return r;
		}
#endif
		move = MyNext (POSITION, NextMove);
		if (!move)
			break;
		if ((move & 0x7fff) == (MOVE & 0x7fff))
			continue;
		to = TO (move);
		fr = FROM (move);

		if (cnt > 5 
			&& NextMove->phase == ORDINARY_MOVES			
			&& (move & RE0XE000) == 0 			
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr]))
			&& depth < 20)
		{
			if ((6 << (depth - 6)) + MAX_POSITIONAL (move) +
				(POS0->valu) < VALUE + 30 + 2 * cnt)
			{
				cnt++;
				continue;
			}
		}
		REDUCTION = 0;
		if (depth < 20 
			&& (2 << (depth - 6)) + (POS0->valu) < VALUE + 125
			&& NextMove->phase == ORDINARY_MOVES 
			&& my_king_pos != fr
			//&& SqSet[fr] & ~MyXRAY 
			&& m128_is_have_bit(_mm_andnot_si128(MyXRAY,SetMaskBB[fr]))
			&& (move & 0x8000) == 0
			&& !MySEE (POSITION, move))	
		{
			cnt++;
			continue;
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
		EXTEND = 0;
		if (PassedPawnPush (to, SIXTH_RANK (to)))
			EXTEND = 1;
#ifdef USE_HASH_EAXCT_VALUE 
		if (IS_EXACT (POSITION->DYN->exact)){
			v = -POSITION->DYN->valu;
		}
		else if (move_is_check){
#else
		if (move_is_check){
#endif
			v = -OppCutCheck (POSITION, 1 - VALUE, depth - 1);
		}
		else
		{
			if (cnt > 5 
				&& depth < 20 
				&& POS1->catturaa == 0
				&& (2 << (depth - 6)) - POS1->valu < VALUE + cnt - 15)
			{
				UNDO (POSITION, move);
				cnt++;
				continue;
			}
			if (NextMove->phase == ORDINARY_MOVES && (cnt >= 3 || REDUCTION))
			{
				new_depth =
					depth - 2 + EXTEND - BSR (1 + cnt) - REDUCTION;
				if (QSEARCH_CONDITION)
					v = -OppQsearch (POSITION, 1 - VALUE, 0);
				else if (LOW_DEPTH_CONDITION)
					v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
				else
					v = -OppCut (POSITION, 1 - VALUE, new_depth);
				if (v < VALUE)
					goto DONE;
			}
			new_depth = depth - 2 + EXTEND;
			if (LOW_DEPTH_CONDITION)
				v = -OppLowDepth (POSITION, 1 - VALUE, new_depth);
			else
				v = -OppCut (POSITION, 1 - VALUE, new_depth);
		}
DONE:
		UNDO (POSITION, move);
		CHECK_HALT ();
		cnt++;
		if (v >= VALUE)
		{
			if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
				HISTORY_GOOD (move, depth);
			HashLower (zob, move, depth, v);
			RETURN (v);
		}
		if ((POS0 + 1)->catturaa == 0 && MoveHistory (move))
			HISTORY_BAD (move, depth);
	}
	v = VALUE - 1;
	HashUpper (zob, depth, v);
	RETURN (v);
}

#endif
