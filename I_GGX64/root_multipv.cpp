#ifndef MINIMAL
#ifndef BUILD_root_multipv
#define BUILD_root_multipv
#include "chess.h"
#define RETURN(x) return(x)

#ifdef USE_STOCK_FISH_FILE
#else

#include "control.h"

void APPLY_SORT (int AGE_DEPTH_MIX, typeMPV* mpv)
{
	typeMPV *p;
	int s, x;
	for (s = 0; s < AGE_DEPTH_MIX && mpv[s].move; s++)
	{
		if (s == 0)
			continue;
		p = &mpv[s];
		while (p != mpv && p->Value > (p-1)->Value)
		{
			x = p->Value;
			p->Value = (p - 1)->Value;
			(p - 1)->Value = x;
			x = p->move;
			p->move = (p - 1)->move;
			(p - 1)->move = x;
			p--;
		}	
	}
}

#endif

#include "root_multipv.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

int MyMultiPV (typePOS* POSITION, int depth)
{
	int CNT, cnt, best_value, move_is_check, new_depth, v;
	typeRootMoveList* p;
	typeDYNAMIC* POS0 = POSITION->DYN;
	uint32 move;
	int EXTEND;
	int to;
	int i, j, x;
	int BETA = VALUE_MATE;
	int ALPHA = -VALUE_MATE;
	int GOOD_MOVES = 0;

	for (i = 0; i < 128; i++)
		MPV[i].move = MPV[i].Value = 0;
	if (DO_OUTPUT){
	    SEND ("info depth %d\n", depth / 2);
	}
	CNT = 0;
	for (p = ROOT_MOVE_LIST; p->move; p++)
	{
		CNT++;
		p->move &= 0x7fff;
	}
	p = ROOT_MOVE_LIST;
	v = best_value = -VALUE_INFINITY;
	cnt = 0; /* SMP ? */
	while ((move = p->move))
	{
		MAKE (POSITION, move);
		EVAL (move);
		move_is_check = (MOVE_IS_CHECK != 0);

		EXTEND =0;
		to = TO (move);
		if (POS1->catturaa || move_is_check ||
			PassedPawnPush (to, FOURTH_RANK (to)))
			EXTEND = 1;
		new_depth = depth - 2 + EXTEND;
		if (DO_OUTPUT && ANALYSING && depth >= 24)
			SEND ("info currmove %s currmovenumber %d\n",
			Notate (move, STRING1), (p - ROOT_MOVE_LIST) + 1);
		if (GOOD_MOVES < MULTI_PV || depth <= 2){
			v = -OppPV (POSITION, -BETA, -ALPHA, new_depth, move_is_check);
		}
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
				if (new_depth >= 16 && ANALYSING) /* ANALYSING es TRUE */
				{
					int an = new_depth - 12;
					v = VALUE_INFINITY;
					while (an <= new_depth && v > ALPHA)
					{
						v = -OppPV (POSITION, -ALPHA - 1, -ALPHA, an, move_is_check);
						an += 4;
					}
					if (an > new_depth)
						goto DEC;
				}
				if (move_is_check)
					v = -OppCutCheck (POSITION, -ALPHA, new_depth);
				else
					v = -OppCut (POSITION, -ALPHA, new_depth);
			}
			if (v > ALPHA)
				v = -OppPV (POSITION, -ALPHA - 1, -ALPHA, new_depth, move_is_check);
DEC:
			if (v > ALPHA)
				v = -OppPV (POSITION, -BETA, -ALPHA, new_depth, move_is_check);
			if (v <= ALPHA)
				v = ALPHA;
		} /* NORMALE */
		UNDO (POSITION, move);
		CHECK_HALT ();
		if (v > ALPHA)
		{
			if (v > best_value)
				HashLower (POSITION->DYN->HASH, move, depth, v);
			MPV[GOOD_MOVES].move = move;
			MPV[GOOD_MOVES++].Value = v;
			APPLY_SORT (GOOD_MOVES, MPV);
			if (GOOD_MOVES >= MULTI_PV)
				ALPHA = MPV[MULTI_PV - 1].Value;
			else{
				//ALPHA = MAX (MPV[0].Value - MULTI_CENTI_PAWN_PV, -VALUE_MATE);
				ALPHA = MAX (MPV[0].Value - 65535, -VALUE_MATE);
			}
			ROOT_BEST_MOVE = MPV[0].move;
			best_value = ROOT_SCORE = MPV[0].Value;
			Information (POSITION, GetClock () - START_CLOCK,
				-VALUE_MATE, MPV[0].Value, VALUE_MATE);
		}
		p++;
	}
	for (i = 0; i < GOOD_MOVES; i++)
	{
		for (j = 0; j < CNT; j++)
		{
			if (ROOT_MOVE_LIST[j].move == MPV[i].move)
			{
				x = ROOT_MOVE_LIST[i].move;
				ROOT_MOVE_LIST[i].move = ROOT_MOVE_LIST[j].move;
				ROOT_MOVE_LIST[j].move = x;
				break;
			}
		}
	}
	ROOT_DEPTH = depth;
	if (!DO_SEARCH_MOVES)
	{
		HashExact (POSITION, MPV[0].move, depth, MPV[0].Value, FLAG_EXACT);
	}
	Information (POSITION, GetClock () - START_CLOCK,
		-VALUE_MATE, MPV[0].Value, VALUE_MATE);
	return MPV[0].Value;
}
#endif /* MINIMAL */

#endif
