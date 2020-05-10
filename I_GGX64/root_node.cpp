#ifndef BUILD_root_node
#define BUILD_root_node
#include "chess.h"
#define RETURN(x) return(x)

#include "control.h"
#include "root_node.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

int MyRootNode (typePOS* POSITION, int ALPHA, int BETA, int depth)
{
	int CNT, origALPHA, best_value, cnt, move_is_check, new_depth, v, TEMPvalu;
	typeRootMoveList *p, *q;
	typeDYNAMIC* POS0 = POSITION->DYN;
	uint32 move;
	int EXTEND;
	int to;

	if (BETA > VALUE_MATE)
		BETA = VALUE_MATE;
	if (ALPHA < -VALUE_MATE)
		ALPHA = -VALUE_MATE;
	if (DO_OUTPUT){
		SEND ("info depth %d\n", depth / 2);
	}
	CNT = 0;
	for (p = ROOT_MOVE_LIST; p->move; p++)
	{
		CNT++;
		p->move &= 0x7fff;
	}
	origALPHA = ALPHA;
	p = ROOT_MOVE_LIST;
	v = best_value = -VALUE_INFINITY;
	cnt = 0; /* SMP ? */
	while ((move = p->move))
	{
		MAKE (POSITION, move);
		EVAL (move);
		move_is_check = (MOVE_IS_CHECK != 0);
		EXTEND = 0;
		to = TO (move);
		if (POS1->catturaa || move_is_check ||
			PassedPawnPush (to, FOURTH_RANK (to)))
			EXTEND = 1;
		new_depth = depth - 2 + EXTEND;
		if (DO_OUTPUT && SEND_CURR_MOVE && depth >= 22)
			SEND ("info currmove %s currmovenumber %d\n",
			Notate (move, STRING1), (p - ROOT_MOVE_LIST) + 1);
		if (best_value == -VALUE_INFINITY || depth <= 2)
			v = -OppPV (POSITION, -BETA, -ALPHA, new_depth, move_is_check);
		else
		{
			if (LOW_DEPTH_CONDITION_PV)
			{
				if (move_is_check)
					v = -OppLowDepthCheck (POSITION, -ALPHA, new_depth);
				else
					v = -OppLowDepth (POSITION, -ALPHA, new_depth);
			}
			else
			{
				if (move_is_check)
					v = -OppCutCheck (POSITION, -ALPHA, new_depth);
				else
					v = -OppCut (POSITION, -ALPHA, new_depth);
			}
			if (v > ALPHA)
			{
				BATTLE_MOVE = TRUE;
				EASY_MOVE = FALSE;
			}
			if (v > ALPHA)
				v = -OppPV (POSITION, -ALPHA - 1, -ALPHA, new_depth, move_is_check);
			if (v > ALPHA)
				v = -OppPV (POSITION, -BETA, -ALPHA, new_depth, move_is_check);
			if (v <= ALPHA)
				v = ALPHA;
		}
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v <= ALPHA)
			TEMPvalu = origALPHA;
		else
			TEMPvalu = v;
		p->move |= (TEMPvalu + 0x8000) << 16;
		if (v > best_value)
		{
			best_value = v;
			if (best_value == -VALUE_INFINITY || v > ALPHA)
			{
				HashLower (POSITION->DYN->HASH, move, depth, v);
				ROOT_BEST_MOVE = move;
				ROOT_SCORE = v;
				ROOT_DEPTH = depth;
				if (v > ALPHA && v < BETA)
					Information (POSITION, GetClock () - START_CLOCK, origALPHA, v, BETA);
				if (v >= ROOT_PREVIOUS - 25)
					BAD_MOVE = FALSE;
				else
				{
					BAD_MOVE = TRUE;
					EASY_MOVE = FALSE;
				}
			}
		}
		if (v <= ALPHA)
		{
			if (cnt == 0)
			{
				BAD_MOVE = TRUE;
				EASY_MOVE = FALSE;
			}
		}
		else
			ALPHA = v;
		cnt++;
		if (v < BETA)
		{
			p++;
			continue;
		}
		break;
	}
	for (p = ROOT_MOVE_LIST + (CNT - 1); p >= ROOT_MOVE_LIST; p--)
	{
		move = p->move;
		for (q = p + 1; q < ROOT_MOVE_LIST + CNT; q++)
		{
			if ((move & 0xffff0000) < (q->move & 0xffff0000))
				(q - 1)->move = q->move;
			else
				break;
		}
		q--;
		q->move = move;
	}
	ROOT_DEPTH = depth;
	if (best_value <= origALPHA)
		HashUpper (POSITION->DYN->HASH, depth, origALPHA);
	else if (best_value < BETA)
		HashExact (POSITION, ROOT_BEST_MOVE, depth, best_value, FLAG_EXACT);
	Information (POSITION, GetClock () - START_CLOCK,
		origALPHA, best_value, BETA);
	return best_value;
}

#endif