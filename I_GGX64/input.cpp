#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else

#include <string.h>
#include "control.h"

#include "chess.h"
#include <string.h>
#include "control.h"

#if defined(UTILITIES)
#define SWAP_TWO(x, y) { (x) ^= (y); (y) ^= (x); (x) ^= (y); }
#define SHUFFLE_TWO(x) { (x) = ((((x) & 0x3) << 2) | (((x) & 0xc) >> 2)); }
static void InvertBoard (typePOS* POSITION)
{
	int f, r, sq;
	for (f = FA; f <= FH; f++)
		for (r = R1; r <= R4; r++)
			SWAP_TWO (POSITION->sq[8 * r + f], POSITION->sq[8 * (7 - r) + f]);
	for (sq = A1; sq <= H8; sq++)
	{
		if (POSITION->sq[sq])
			POSITION->sq[sq] ^= 8;
		if ((POSITION->sq[sq] & 0x6) == 0x4)
			POSITION->sq[sq] ^= 1; /* HACK */
	}
	POS_SIDE ^= 1;
	if (POSITION->DYN->ep)
		POSITION->DYN->ep ^= 6 << 3; /* HACK */
	SHUFFLE_TWO (POSITION->DYN->oo);
	InitBitboards (POSITION,FALSE);
}

static void EvalTest (typePOS* POSITION)
{
	int v;
	EvalExplanation (POSITION, -32767, 32767, 0);
	v = POSITION->DYN->Value;
	Eval (POSITION, -32767, 32767, 0);
	if (v != POSITION->DYN->Value)
	{
		printf ("ERROR with EvalExplanation compared to EvalEvaluation %d %d\n",
			v, POSITION->DYN->Value);
	}
	InvertBoard (POSITION);
	Eval (POSITION, -32767, 32767, 0);
	if (v != POSITION->DYN->Value)
	{
		printf ("ERROR in InvertBoard Eval compared to Invert %d %d\n",
			v, POSITION->DYN->Value);
		printf ("FEN is: %s\n", EmitFen (POSITION, STRING1));
	}
	InvertBoard (POSITION);
}
#endif

static void SetOption (typePOS* POSITION, char* string)
{
	char *v;
	int Value;
	//if (!memcmp (string, "Hash", 4) || !memcmp (string, "TranspositionalTabularSizing", 28))
	//{
	if (!memcmp (string, "Hash", 4))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			Value = InitHash (Value);
			/*SEND ("Optional TranspositionalTabularSizing %d\n", Value);*/
			SEND ("info NewHash Size set to: %d\n", Value);
			SEND ("readyok\n");
		}
	}

	/*if (!memcmp (string, "TitanicCPUsSizings", 18))*/
	if (!memcmp (string, "Threads", 7))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			if (Value <= 0)
				Value = 1;
			if (Value > 64)
				Value = 64;
			if (Value > MAX_CPUS)
				Value = MAX_CPUS;
			CPUS_SIZE = Value;
			/*SEND ("Optional TitanicCPUsSizings (Capitalist!) %d\n", Value);*/
			SEND ("info New Cpu Size Set: %d\n", Value);
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "TitanicMode", 11))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				TITANIC_MODE = FALSE;
			if (!strcmp (v + 6, "true"))
				TITANIC_MODE = TRUE;
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "BufferTime", 10))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			if (Value < 0)
				Value = 0;
			if (Value > 10000)
				Value = 10000;
			BUFFER_TIME = Value;
			SEND ("Optional BufferTime %d\n", BUFFER_TIME);
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "AlternativeTimeUsage", 20))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				USE_ALTERNATIVE_TIME = FALSE;
			if (!strcmp (v + 6, "true"))
				USE_ALTERNATIVE_TIME = TRUE;
			SEND ("Optional AlternativeTimeUsage %s\n",
				USE_ALTERNATIVE_TIME ? "true" : "false");
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "AllowInstantMoveFromHash", 24))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				ALLOW_INSTANT_MOVE = FALSE;
			if (!strcmp (v + 6, "true"))
				ALLOW_INSTANT_MOVE = TRUE;
			SEND ("Optional AllowInstantMoveFromHash %s\n",
				ALLOW_INSTANT_MOVE ? "true" : "false");
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "Ponder", 6))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				UCI_PONDER = FALSE;
			if (!strcmp (v + 6, "true"))
				UCI_PONDER = TRUE;
			SEND ("Optional Ponder %s\n", UCI_PONDER ? "true" : "false");
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "VerifyNullMove", 14))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				VERIFY_NULL = FALSE;
			if (!strcmp (v + 6, "true"))
				VERIFY_NULL = TRUE;
			SEND ("Optional VerifyNullMove %s\n", VERIFY_NULL ? "true" : "false");
			SEND ("readyok\n");
		}
	}


#ifndef MINIMAL
	if (!memcmp (string, "AlwaysAnalyze", 13))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				ALWAYS_ANALYZE = FALSE;
			if (!strcmp (v + 6, "true"))
				ALWAYS_ANALYZE = TRUE;
			SEND ("Optional AlwaysAnalyze %s\n",
				ALWAYS_ANALYZE ? "true" : "false");
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "SendCurrmove", 12))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				SEND_CURR_MOVE = FALSE;
			if (!strcmp (v + 6, "true"))
				SEND_CURR_MOVE = TRUE;
			SEND ("Optional SendCurrmove %s\n",
				SEND_CURR_MOVE ? "true" : "false");
			SEND ("readyok\n");
		}
	}
#ifdef UTILITIES
	if (!memcmp (string, "DebugTimeManagement", 19))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				DEBUG_TIME_MANAGEMENT = FALSE;
			if (!strcmp (v + 6, "true"))
				DEBUG_TIME_MANAGEMENT = TRUE;
			SEND ("Optional DebugTimeManagement %s\n",
				DEBUG_TIME_MANAGEMENT ? "true" : "false");
			SEND ("readyok\n");
		}
	}
#endif
	//if (!memcmp (string, "GetFEN", 6))
	//{
	//	EmitFen (POSITION, STRING1);
	//	SEND ("info string %s\n", STRING1);
	//	SEND ("readyok\n");
	//}
	if (!memcmp (string, "RandomCount", 11))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			RANDOM_COUNT = Value;
			if (RANDOM_COUNT < 0)
				RANDOM_COUNT = 0;
			if (RANDOM_COUNT >= 8)
				RANDOM_COUNT = 8;
			SEND ("Optional RandomCount %d\n", RANDOM_COUNT);
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "RandomBits", 10))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			RANDOM_BITS = Value;
			if (RANDOM_BITS < 1)
				RANDOM_BITS = 1;
			if (RANDOM_BITS >= 3)
				RANDOM_BITS = 3;
			SEND ("Optional RandomBits %d\n", RANDOM_BITS);
			SEND ("readyok\n");
		}
	}

#ifdef USER_SPLIT
	if (!memcmp (string, "SplitAtCUT", 10))
	{
		v = strstr (string, "value");
		if (v)
		{
			if (!strcmp (v + 6, "false"))
				SPLIT_AT_CUT = FALSE;
			if (!strcmp (v + 6, "true"))
				SPLIT_AT_CUT = TRUE;
			SEND ("Optional SplitAtCUT %s\n", SPLIT_AT_CUT ? "true" : "false");
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "SplitDepthCUT", 13))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			CUT_SPLIT_DEPTH = Value;
			if (CUT_SPLIT_DEPTH <= 16)
				CUT_SPLIT_DEPTH = 16;
			if (CUT_SPLIT_DEPTH >= 20)
				CUT_SPLIT_DEPTH = 20;
			SEND ("Optional SplitDepthCUT %d\n", CUT_SPLIT_DEPTH);
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "SplitDepthALL", 13))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			ALL_SPLIT_DEPTH = Value;
			if (ALL_SPLIT_DEPTH <= 12)
				ALL_SPLIT_DEPTH = 12;
			if (ALL_SPLIT_DEPTH >= 20)
				ALL_SPLIT_DEPTH = 20;
			SEND ("Optional SplitDepthALL %d\n", ALL_SPLIT_DEPTH);
			SEND ("readyok\n");
		}
	}
	if (!memcmp (string, "SplitDepthPV", 12))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			PV_SPLIT_DEPTH = Value;
			if (PV_SPLIT_DEPTH <= 10)
				PV_SPLIT_DEPTH = 10;
			if (PV_SPLIT_DEPTH >= 20)
				PV_SPLIT_DEPTH = 20;
			SEND ("Optional SplitDepthPV %d\n", PV_SPLIT_DEPTH);
			SEND ("readyok\n");
		}
	}
#endif
	if (!memcmp (string, "MultiPV", 7))
	{
		v = strstr (string, "value");
		if (v)
		{
			Value = atoi (v + 6);
			MULTI_PV = Value;
			if (MULTI_PV <= 1)
				MULTI_PV = 1;
			if (MULTI_PV >= 250)
				MULTI_PV = 250;
			SEND ("Optional MultiPV %d\n", MULTI_PV);
			SEND ("readyok\n");
		}
	}
	//if (!memcmp (string, "MultiCentiPawnPV", 16))
	//{
	//	v = strstr (string, "value");
	//	if (v)
	//	{
	//		Value = atoi (v + 6);
	//		MULTI_CENTI_PAWN_PV = Value;
	//		if (MULTI_CENTI_PAWN_PV <= 1)
	//			MULTI_CENTI_PAWN_PV = 1;
	//		if (MULTI_CENTI_PAWN_PV >= 65535)
	//			MULTI_CENTI_PAWN_PV = 65535;
	//		SEND ("Optional MultiCentiPawnPV %d\n", MULTI_CENTI_PAWN_PV);
	//		SEND ("readyok\n");
	//	}
	//}
#endif
}

static void uci ()
{
	SEND ("id name %s version %s\n", EPONYM, VERSION);
	//SEND ("Igor Igorovich Igoronov, Roberto Pescatore, ");
	//SEND ("Yusuf Ralf Weisskopf, ");
	//SEND ("Ivan Skavinsky Skavar plus Decembrists (all)\n");
	SEND ("id copyright 2010-2012\n");
	//SEND ("id dedication To Vladimir Ilyich\n");
	SEND ("option name Hash type spin min 1 max 2048 default 32\n");

#ifndef USE_CYCLONE_UCI  //==================================
	//SEND ("option name PawnsHash type spin min 1 max 1024 default 2\n");
	/*SEND ("option name TitanicMode (Capitalist!) type check default false\n");
#ifndef USE_CYCLONE_UCI  //==================================
	SEND ("option name TitanicCPUsSizings (Capitalist!) type spin min 1 max %d default 1\n", MAX_CPUS);*/
	SEND ("option name TitanicMode (Capitalist!) type check default true\n");
	SEND ("option name TitanicCPUsSizings (Capitalist!) type spin min 1 max %d default 4\n", MAX_CPUS);
	SEND ("option name Ponder type check default false\n");
	SEND ("option name VerifyNullMove type check default true\n");
	SEND ("option name AlternativeTimeUsage (beta) type check default true\n");
	SEND ("option name AllowInstantMoveFromHash (ponder off only) type check default true\n");
	SEND ("option name BufferTime (milliseconds) type spin min 0 max 10000 default 0\n");
#ifdef CON_ROBBO_BUILD
	SEND ("option name RobboTripleBaseDirectory type string default NULL\n");
	SEND ("option name LoadRobboTripleBases type button\n");
	SEND ("option name RobboTotalBaseDirectory type string default NULL\n");
	SEND ("option name RegisterRobboTotalBases type button\n");
	SEND ("option name RobboTotalBaseCacheSize type spin min 1 max 1024 default 1\n");
#endif
#ifdef UTILITIES
	SEND ("option name DebugTimeManagement type check default false\n");
#endif
#ifndef MINIMAL
	SEND ("option name MultiPV type spin min 1 max 250 default 1\n");
	SEND ("option name MultiCentiPawnPV type spin min 1 max 65535 default 65535\n");
	SEND ("option name RandomCount type spin min 0 max 8 default 0\n");
	SEND ("option name RandomBits type spin min 1 max 3 default 1\n");
#ifdef USER_SPLIT
	SEND ("option name SplitAtCUT (half ply) type check default true\n");
	SEND ("option name SplitDepthCUT (half ply) type spin min 16 max 20 default 16\n");
	SEND ("option name SplitDepthALL (half ply) type spin min 12 max 20 default 14\n");
	SEND ("option name SplitDepthPV (half ply) type spin min 10 max 20 default 14\n");
#endif
	//SEND ("option name UCI_BishopPairScale (centipawns) type spin min 0 max 150 default 45\n");
	//SEND ("option name UCI_PawnScale (centipawns) type spin min 50 max 200 default 100\n");
	//SEND ("option name UCI_KnightScale (centipawns) type spin min 150 max 500 default 300\n");
	//SEND ("option name UCI_BishopScale (centipawns) type spin min 150 max 500 default 310\n");
	//SEND ("option name UCI_RookScale (centipawns) type spin min 300 max 700 default 500\n");
	//SEND ("option name UCI_QueenScale (centipawns) type spin min 500 max 1500 default 950\n");
	SEND ("option name AlwaysAnalyze type check default false\n");
	SEND ("option name SendCurrmove type check default false\n");
	//SEND ("option name GetFEN type button\n");
#endif
#endif  //==================================

	SEND ("uciok\n");
	SEND ("info initend\n");
}

static void readyok ()
{
	SEND ("readyok\n");
}

static void quit ()
{
	exit (0);
}

static void ParseInput (typePOS* POSITION, char* I)
{
	if (!strcmp (I, "quit"))
		quit ();
	if (!strcmp (I, "stop"))
		HaltSearch (0);
	if (!strcmp (I, "isready"))
		readyok ();
	if (!strcmp (I, "ponderhit"))
		ponderhit ();
	if (!strcmp (I, "ucinewgame"))
	{
		HaltSearch (0);
		NewGame (POSITION, TRUE);
	}
	if (JUMP_IS_SET)
		return;
#if defined (BENCHMARK) || defined(UTILITIES)
	if (!strcmp (I, "benchmark"))
		BenchMark (POSITION, "go movetime 1000");
	else if (!memcmp (I, "benchmark", 9)) /* run benchmark */
		BenchMark (POSITION, I + 10);
#endif
#if defined (UTILITIES)
	if (!memcmp (I, "perft-check", 11))
		Perfd (POSITION, atoi (I + 12), atoi (I + 14)); /* HACK */
	if (!memcmp (I, "drawboard", 9))
		DrawBoard (POSITION);
	if (!strcmp (I, "eval"))
		EvalTest (POSITION);
	if (!memcmp (I, "perft ", 6))
		PERFD (POSITION, atoi (I + 6));
	if (!memcmp (I, "verify-triple", 13))
	{
		int p[4];
		char A[64], B[64], C[64], D[64];
		sscanf (I + 14, "%s %s %s %s", A, B, C, D);
		p[0] = atoi(A);
		p[1] = atoi(B);
		p[2] = atoi(C);
		p[3] = atoi(D);
		VerifyTripleBase (POSITION, p);
	}
#endif
	if (!memcmp (I, "go", 2))
	{
		InitSearch (POSITION, I);
		if (BOARD_IS_OK)
			Search (POSITION);
	}
	if (!memcmp (I, "fen", 3))
		InitPosition (POSITION, I + 0);
	if (!memcmp (I, "position", 8))
		InitPosition (POSITION, I + 9);
	if (!memcmp (I, "setoptionuci", 12))
		SetOption (POSITION, I + 13);
	if (!strcmp (I, "uci"))
		uci ();
	if (!memcmp (I, "cmd", 3)){
		uci_cmd(I+4);
	}
	SUPPRESS_INPUT = FALSE;
}

#include <io.h>
#include <conio.h>
void Input (typePOS* POSITION)
{
	//int i;
	int r = 0;
	if (SUPPRESS_INPUT)
		return;
	if (_kbhit()) /* does this work? */
	{
		INPUT_BUFFER[r] = (char) _getche();
		while (INPUT_BUFFER[r++] != '\r') /* what is \r ?? */
			INPUT_BUFFER[r] = (char) _getche ();
	}
	else
	{
		_read (_fileno (stdin), INPUT_BUFFER, 1);
		while (INPUT_BUFFER[r++] != '\n') /* but now \n is correct? */
			_read (_fileno (stdin), INPUT_BUFFER + r, 1);
	}
	INPUT_BUFFER[r - 1] = 0; /* gobble \n, or maybe \r who knows? */
	INPUT_BUFFER[r] = 0; /* safety */
	ParseInput (POSITION, INPUT_BUFFER);
}

#ifdef USE_CYCLONE_UCI

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <shellapi.h>
#include <sys/stat.h>

void read_uci_set_file(){
	//打开设定文件
	char filename[1024];  
	sprintf_s(filename,1024,"%s\\%s",installDir,"ggX64set.txt");

	//strcat_s(filename,1024, REG_FILE);

	//fprintf_s(log_file,	"\nfilename filename %s\n", filename);

	//fflush(log_file);

	int pFile;
	char rbuf[4096];

	errno_t err = _sopen_s(&pFile,filename,_O_RDONLY, _SH_DENYNO,
		_S_IREAD);


	if(err == 0){
		int byteRead = _read(pFile,rbuf,4096);
		rbuf[byteRead] = 0;
		_close(pFile);


		//在这儿读出设定数据
		//setoption name xx value xx
		char *p = rbuf;

		char name[512];
		char value[512];

		char opcmd[1024];

		//while(byteRead-- != 0){  //当有字节存在时
		while(*p != 0){
			//strncpy_s(name,p,128);
			//p = strstr(name,"=");
			//if(p = NULL){
			// break;
			//}

			//name
			if(*p == 10) p++;
			for(int i=0; i<128;i++){
				name[i] = *p;
				p++;
				if(*p == 0) return;
				if(*p == '='){
					name[i+1] = 0;
					break;
				}				
			}

			p++;
			for(int i=0; i<128; i++){
				value[i] = *p;
				p++;
				if(*p == 0) return;
				if(*p == 10){
					value[i+1] = 0;
					break;
				}	
			}

			if(strlen(name) > 0 && strlen(value) > 0){
				sprintf_s(opcmd,1024,"%s value %s",name,value);
				//ParseInput(ROOT_POSIZIONE0,opcmd);
				//uci_setoption(opcmd);
				//ROOT_POSIZIONE0)
				SetOption(ROOT_POSIZIONE0,opcmd);
			}
		}      

	}
	else{
		printf("\ncannot open set file!!\n");
	}
}
#endif

#endif
