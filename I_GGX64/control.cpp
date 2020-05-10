#include "chess.h"
#include "control.h"

#ifdef USE_STOCK_FISH_FILE
#else

static sint64 LAST_MESSAGE;
static sint64 ABSOLUTE_TIME;
static sint64 DESIRED_TIME;
static sint64 INCREMENT;
static int DEPTH;
static boolean NEW_PONDERHIT;

void ponderhit() /* ABSOLUTE_TIME se cambia ? */
{
	if (!DO_PONDER)
		return;
	PONDER_HIT = TRUE;
	DO_PONDER = FALSE;
	NEW_PONDERHIT = TRUE;
#if 1 /* ? */
	ABSOLUTE_TIME += GetClock() - START_CLOCK;

#if 0
	EASY_TIME += EASY_TIME / 4;
	BATTLE_TIME += BATTLE_TIME / 4;
	ORDINARY_TIME += ORDINARY_TIME / 4;
#endif

#endif
}

void HaltSearch (int tr)
{
	STOP = TRUE;
	DO_PONDER = FALSE;
	DO_INFINITE = FALSE;
	SUPPRESS_INPUT = TRUE;
	if (JUMP_IS_SET)
		longjmp (J, 1);
}

void Info (sint64 x)
{
	uint64 t, nps, NODES = 0;
	int cpu, rp;
	clock_t u;
	uint64 TBHITS = 0;

	if (x < sint64(1000ULL * OUTPUT_DELAY))
		return;
	DO_OUTPUT = TRUE;
	if (TITANIC_MODE)
		for (cpu = 0; cpu < CPUS_SIZE; cpu++)
			for (rp = 0; rp < RP_PER_CPU ; rp++)
				NODES += ROOT_POSITION[cpu][rp].nodes;
	else
		NODES = ROOT_POSIZIONE0->nodes;
	if (TITANIC_MODE)
		for (cpu = 0; cpu < CPUS_SIZE; cpu++)
			for (rp = 0; rp < RP_PER_CPU ; rp++)
				TBHITS += ROOT_POSITION[cpu][rp].tbhits;
	else
		TBHITS = ROOT_POSIZIONE0->tbhits;
	u = clock ();
	LAST_MESSAGE = x;
	t = x / 1000;
	if (t == 0)
		nps = 0;
	else
		nps = NODES / t;
	u = clock () - INIT_CLOCK;

#ifdef SERCH_SEND_INFO_TIME
	SEND ("info time " TYPE_64_BIT " nodes " TYPE_64_BIT " nps " TYPE_64_BIT,
		t, NODES, nps * 1000);
	if (TBHITS)
		SEND (" tbhits " TYPE_64_BIT, TBHITS);
	SEND (" cpuload %d\n", (int) ((double) u / (double) x * 1000.0));
#endif
//	uint64 t, nps, NODES = 0;
//	int cpu, rp;
//	clock_t u;
//	uint64 TBHITS = 0;
//	if (TITANIC_MODE)
//		for (cpu = 0; cpu < CPUS_SIZE; cpu++)
//			for (rp = 0; rp < RP_PER_CPU ; rp++)
//				NODES += ROOT_POSITION[cpu][rp].nodes;
//	else
//		NODES = ROOT_POSIZIONE0->nodes;
//	if (TITANIC_MODE)
//		for (cpu = 0; cpu < CPUS_SIZE; cpu++)
//			for (rp = 0; rp < RP_PER_CPU ; rp++)
//				TBHITS += ROOT_POSITION[cpu][rp].tbhits;
//	else
//		TBHITS = ROOT_POSIZIONE0->tbhits;
//	u = clock ();
//	LAST_MESSAGE = x;
//	t = x / 1000;
//	if (t == 0)
//		nps = 0;
//	else
//		nps = NODES / t;
//	u = clock () - INIT_CLOCK;
//#ifdef SERCH_SEND_INFO_TIME
//	SEND ("info time " TYPE_64_BIT " nodes " TYPE_64_BIT " nps " TYPE_64_BIT,
//		t, NODES, nps * 1000);
//	if (TBHITS)
//		SEND (" tbhits " TYPE_64_BIT, TBHITS);
//	SEND (" cpuload %d\n", (int) ((double) u / (double) x * 1000.0));
//#endif
	
}

/********************************/ /********************************/
static sint64 BATTLE_TIME, EASY_TIME, ORDINARY_TIME;

static int moves_in_control;
static sint64 total_white_time, total_black_time;
static int old_mtg;
static boolean INCREASED_DEPTH;
static float time_factor;

void CheckDoneAlternative (typePOS* POSITION, int d)
{
	sint64 x;
	x = GetClock () - START_CLOCK;
#ifdef UTILITIES
	if (DEBUG_TIME_MANAGEMENT)
	{
		SEND ("DebugTimeA: time: " TYPE_64_BIT " depth %d ", x, d);
		SEND ("DO_PONDER %d ABSOLUTE TIME " TYPE_64_BIT "\n",
			DO_PONDER, ABSOLUTE_TIME);
	}
#endif
	if (d == DEPTH)
		HaltSearch (1);
	if (x - LAST_MESSAGE > 1000000)
		Info (x);
	if (DO_PONDER)
		goto END; /* Decembrist */
	if (DO_INFINITE)
		goto END; /* Decembrist */
	if (d >= 1 && d < 8) /* porque? */
		goto END;
	if (x > ABSOLUTE_TIME)
		HaltSearch (1);
	if (d == 0 && !NEW_PONDERHIT)
		goto END;
#if defined (UTILITIES)
	if (DEBUG_TIME_MANAGEMENT)
	{
		SEND ("DebugTimeA: NEW_PONDERHIT %d INCREASED_DEPTH %d time_factor %f ",
			NEW_PONDERHIT, INCREASED_DEPTH, time_factor);
		SEND ("MOVES: EASY %d BATTLE %d BAD %d ",
			EASY_MOVE, BATTLE_MOVE, BAD_MOVE);
		SEND (" TIMES: EASY " TYPE_64_BIT " BATTLE " TYPE_64_BIT
			" ORDINARY " TYPE_64_BIT " CLOCK " TYPE_64_BIT "\n",
			EASY_TIME, BATTLE_TIME, ORDINARY_TIME, x);
	}
#endif
	NEW_PONDERHIT = FALSE;
	/* Alternative TimeUsage */
#define INCREASE_DEPTH() { INCREASED_DEPTH = TRUE; goto END; }
#define CHECK_INCREASE_DEPTH() \
	{ if (!INCREASED_DEPTH && time_factor > 1.05) INCREASE_DEPTH (); \
	HaltSearch (2); }
	if (!BAD_MOVE && x >= BATTLE_TIME)
		CHECK_INCREASE_DEPTH();
	if (EASY_MOVE && x >= EASY_TIME)
		CHECK_INCREASE_DEPTH();
	if (!BATTLE_MOVE && x >= ORDINARY_TIME && !BAD_MOVE)
		CHECK_INCREASE_DEPTH();
END:
	while (TryInput ())
		Input (POSITION);
}

void CheckDone (typePOS* POSITION, int d)
{
	sint64 x;
	if (SUPPRESS_INPUT)
		return;
	if (!JUMP_IS_SET)
		return;
	if (USE_ALTERNATIVE_TIME)
	{
		CheckDoneAlternative (POSITION, d);
		return;
	}
	x = GetClock () - START_CLOCK;
#if defined(UTILITIES)
	if (DEBUG_TIME_MANAGEMENT)
	{
		SEND ("DebugTime: time: " TYPE_64_BIT " depth %d ", x, d);
		SEND ("DO_PONDER %d ABSOLUTE TIME " TYPE_64_BIT "\n",
			DO_PONDER, ABSOLUTE_TIME);
	}
#endif
	if (d == DEPTH)
		HaltSearch (1);
	if (x - LAST_MESSAGE > 1000000)
		Info (x);
	if (DO_PONDER)
		goto END; /* Decembrist */
	if (DO_INFINITE)
		goto END; /* Decembrist */
	if (d >= 1 && d < 8)
		goto END;
	if (x > ABSOLUTE_TIME)
		HaltSearch (1);
	if (d == 0 && !NEW_PONDERHIT)
		goto END;
#if defined (UTILITIES)
	if (DEBUG_TIME_MANAGEMENT)
	{
		SEND ("DebugTime: NEW_PONDERHIT %d INCREASED_DEPTH %d time_factor %f ",
			NEW_PONDERHIT, INCREASED_DEPTH, time_factor);
		SEND ("MOVES: EASY %d BATTLE %d BAD %d ",
			EASY_MOVE, BATTLE_MOVE, BAD_MOVE);
		SEND (" TIMES: EASY " TYPE_64_BIT " BATTLE " TYPE_64_BIT
			" ORDINARY " TYPE_64_BIT " CLOCK " TYPE_64_BIT "\n",
			EASY_TIME, BATTLE_TIME, ORDINARY_TIME, x);
	}
#endif
	NEW_PONDERHIT = FALSE;
	/* Default TimeUsage */
	if (!BAD_MOVE && x >= BATTLE_TIME)
		HaltSearch (2);
	if (EASY_MOVE && x >= EASY_TIME)
		HaltSearch (3);
	if (!BATTLE_MOVE && x >= ORDINARY_TIME && !BAD_MOVE)
		HaltSearch (4);
END:
	while (TryInput ())
		Input (POSITION);
}

/********************************/ /********************************/

#define INFINITY 0x7ffffffffffffff /* sint64 */
#define STRTOK(p) p = strtok_s (NULL, " " ,&next_token)

static uint32 FullMove (typePOS* POSITION, uint32 x)
{
	//int pi, to = TO (x), fr = FROM (x);
	//if (!x)
	//	return x;
	//pi = POSITION->sq[fr];
	//if (pi == wEnumK || pi == bEnumK)
	//{
	//	if (to - fr == 2 || fr - to == 2)
	//		x |= FlagOO;
	//}
	//if (TO (x) != 0 && TO (x) == POSITION->DYN->ep
	//	&& (pi == wEnumP || pi == bEnumP))
	//	x |= FlagEP;
	return x;
}

static uint32 numeric_move (typePOS* POSITION, char* str)
{
	int x;
	x = FullMove (POSITION, (str[2] - 'a') + ((str[3] - '1') << 4) +
		((str[0] - 'a') << 8) + ((str[1] - '1') << 12));
	//if (str[4] == 'b')
	//	x |= FlagPromB;
	//if (str[4] == 'n')
	//	x |= FlagPromN;
	//if (str[4] == 'r')
	//	x |= FlagPromR;
	//if (str[4] == 'q')
	//	x |= FlagPromQ;
	return x;
}

/********************************/ /********************************/

void TimeManagerAlternative //¿ÉÑ¡ÔñµÄ 
	(sint64 TOTAL_TIME, sint64 TIME, sint64 INCREMENT, int mtg)
{
	TIME = MAX (TIME - 500000, (9 * TIME) / 10);
	if (mtg)
	{
		old_mtg = mtg;
		time_factor = (float) (TIME * moves_in_control) / (float) (TOTAL_TIME * mtg);
		if (time_factor < 1.0)
			DESIRED_TIME = TIME / mtg + INCREMENT;
		else
			DESIRED_TIME =
			MIN (TIME * time_factor * time_factor / mtg + INCREMENT, TIME);
		if (time_factor < 1.2 && mtg > 2)
			ABSOLUTE_TIME =
			MIN ((TIME * time_factor * (mtg + 2)) / (mtg + 3),
			6 * DESIRED_TIME);
		else
			ABSOLUTE_TIME = (TIME * (mtg + 1)) / (mtg + 2);
		ABSOLUTE_TIME = MAX (10000, ABSOLUTE_TIME);
	}
#define NUMBER (UCI_PONDER ? 6 : 0)
	else /* no mtg */
	{
		sint64 temp = TIME / 20;
		float sf;
		if (temp > INCREMENT)
		{
			//sint64 ttt = temp * TIME;
			DESIRED_TIME =
				INCREMENT + (temp * TIME) / ((50 - NUMBER) * temp - 20 * INCREMENT);
			ABSOLUTE_TIME = (temp * TIME) / (5 * temp - 3 * INCREMENT);
		}
		else
		{
			ABSOLUTE_TIME = TIME >> 1;
			DESIRED_TIME = INCREMENT + TIME / (30 - NUMBER);
		}
		sf = (float) (TIME + 20 * INCREMENT) / (float) (TOTAL_TIME);
		if (6.0 * sf < 1.0)
			ABSOLUTE_TIME /= 2;
		else if (3.0 * sf < 1.0)
			ABSOLUTE_TIME *= (3.0 * sf);
		if (TIME < 500000)
		{
			ABSOLUTE_TIME = 10000;
			DESIRED_TIME = 5000;
		}
		if (TIME >= 500000 && TIME < 1000000 && INCREMENT < 500000)
		{
			ABSOLUTE_TIME = (TIME * 5) / 100;
			DESIRED_TIME = (TIME * 5) / 400;
		}
		if (TIME >= 1000000 && TIME < 2000000 && INCREMENT < 500000)
		{
			ABSOLUTE_TIME = TIME / 10;
		}
	}
	DESIRED_TIME = MAX (5000, DESIRED_TIME);
	EASY_TIME = DESIRED_TIME >> 2;
	ORDINARY_TIME = 3 * EASY_TIME;
	BATTLE_TIME = DESIRED_TIME;
}

void TimeManager (sint64 TIME, sint64 INCREMENT, int mtg)
{  
	if (mtg)
	{
		if (mtg > 25)
			mtg = 25;
		DESIRED_TIME = TIME / mtg + INCREMENT;
		ABSOLUTE_TIME =
			(TIME * mtg) / (4 * mtg - 3) - MIN (1000000, TIME / 10);
		if (mtg == 1)
			ABSOLUTE_TIME -= MIN (1000000, ABSOLUTE_TIME / 10);
		if (ABSOLUTE_TIME < 1000) /* porque? */
			ABSOLUTE_TIME = 1000;
	}
	else
	{
		ABSOLUTE_TIME = TIME / 4 - 10000;
		if (ABSOLUTE_TIME < 1000)
			ABSOLUTE_TIME = 1000;
		//DESIRED_TIME = ABSOLUTE_TIME / 11 + INCREMENT; old was 11
		DESIRED_TIME = ABSOLUTE_TIME / 20 + INCREMENT;
	}
	if (DESIRED_TIME > ABSOLUTE_TIME)
		DESIRED_TIME = ABSOLUTE_TIME;
	if (DESIRED_TIME < 1000)
		DESIRED_TIME = 1000;
	EASY_TIME = DESIRED_TIME / 4;
#if 1
	if (UCI_PONDER)
		EASY_TIME = DESIRED_TIME / 3;
#endif
	BATTLE_TIME = DESIRED_TIME;
	ORDINARY_TIME = (3 * DESIRED_TIME) / 4;
}

void InitSearch (typePOS* POSITION, char* str)
{
	char *p;
	char *next_token;
	sint64 wtime = INFINITY, btime = INFINITY, winc = 0, binc = 0, TIME, mtg = 0;
	int sm = 0;

	DEPTH = 255;
	ABSOLUTE_TIME = DESIRED_TIME = INFINITY;
	STOP = FALSE;
	DO_INFINITE = FALSE;
	DO_PONDER = FALSE;
	NEW_PONDERHIT = FALSE;
	DO_SEARCH_MOVES = FALSE;
	LAST_MESSAGE = 0;
	p = strtok_s (str, " ", &next_token);
	for (STRTOK (p); p != NULL; STRTOK (p))
	{
		if (!strcmp (p, "depth"))
		{
			STRTOK (p);
			DEPTH = MAX (1, atoi (p));
		}
		else if (!strcmp (p, "movetime"))
		{
			STRTOK (p);
			ABSOLUTE_TIME = MAX (1, atoll (p)) * 1000; /* - 10000 ? */			
		}
		else if (!strcmp (p, "steptime"))
		{
			STRTOK (p);
			ABSOLUTE_TIME = MAX (1, atoll (p)) * 1000; /* - 10000 ? */
		}
		else if (!strcmp (p, "byotime")){
			STRTOK (p);
		}
		else if (!strcmp (p, "limittime")){
			STRTOK (p);
		}


		else if (!strcmp (p, "wtime"))
		{
			STRTOK (p);
			wtime = atoll (p) * 1000;
		}
		else if (!strcmp (p, "winc"))
		{
			STRTOK (p);
			winc = atoll (p) * 1000;
		}
		else if (!strcmp (p, "btime"))
		{
			STRTOK (p);
			btime = atoll (p) * 1000;
		}
		else if (!strcmp (p, "binc"))
		{
			STRTOK (p);
			binc = atoll (p) * 1000;
		}
		else if (!strcmp (p, "movestogo"))
		{
			STRTOK (p);
			mtg = atoi (p);
		}
		else if (!strcmp (p, "infinite"))
			DO_INFINITE =  TRUE;
		else if (!strcmp (p, "ponder"))
			DO_PONDER = TRUE;
		else if (!strcmp (p, "searchmoves"))
			DO_SEARCH_MOVES = TRUE;
		else if (DO_SEARCH_MOVES)
			SEARCH_MOVES[sm++] = numeric_move (POSITION, p);		
		else{
			//ABSOLUTE_TIME = 1000;
			ERROR_END ("go string: %s", p);
		}
	}
	BATTLE_TIME = INFINITY;
	ORDINARY_TIME = INFINITY;
	EASY_TIME = INFINITY;

	/* TimeManagerAlternative */
	time_factor = 1.0;
	INCREASED_DEPTH = FALSE;
	if (NEW_GAME || mtg > old_mtg) /* reset */
	{
		moves_in_control = mtg;
		total_white_time = MAX (wtime - 500000, (95 * wtime) / 100);
		total_black_time = MAX (wtime - 500000, (95 * btime) / 100);
	}

	TIME = POS_SIDE ? wtime : btime;
	TIME = TIME - BUFFER_TIME * 1000ULL;
	if (TIME < 0)
		TIME = 0;  
	if (TIME == INFINITY)
		goto END;
	INCREMENT = POS_SIDE ? winc : binc;
	if (USE_ALTERNATIVE_TIME)
		TimeManagerAlternative (POS_SIDE ? total_white_time : total_black_time,
		TIME, INCREMENT, mtg); /* alternativo */
	else
		TimeManager (TIME, INCREMENT, mtg);
END:
	if (TIME == INFINITY)
		ANALYSING = TRUE;
	else
		ANALYSING = FALSE;
	if (DO_SEARCH_MOVES)
		SEARCH_MOVES[sm] = MOVE_NONE;
}

#endif