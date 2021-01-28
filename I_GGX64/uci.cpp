
#include "chess.h"


////
//// Includes
////

#include <iostream>
#include <sstream>
#include <string>

#include "platform.h"
#include "evaluate.h"
#include "misc.h"
#include "move.h"
#include "movegen.h"
#include "position.h"
#include "notation.h"
#include "search.h"
#include "uci.h"
#include "thread.h"
#include "timeman.h"
#include "tt.h"


#pragma warning(disable : 4239)  

using namespace std;

extern void benchmark(const Position& pos, istream& is);


namespace {

	// FEN string for the initial position
	const char* StartFEN = "rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w - - 0 1";

	// A list to keep track of the position states along the setup moves (from the
	// start position to the position just before the search starts). Needed by
	// 'draw by repetition' detection.
	StateListPtr States(new std::deque<StateInfo>(1));

	void position(Position& pos, istringstream& is) {

		Move m;
		string token, fen;

		is >> token; // operator>>() skips any whitespace

		if (token == "startpos")
		{
			fen = StartFEN;
			is >> token; // Consume "moves" token if any
		}
		else if (token == "fen"){
			while (is >> token && token != "moves")
				fen += token + " ";
		}
		else 
			return;

		States = StateListPtr(new std::deque<StateInfo>(1));
		pos.set(fen, &States->back(), Threads.main());

	    // Parse move list (if any)
		// fen 2b1k1b2/4a1P2/3a5/R8/8C/9/9/9/1r2K1p2/2B6 w - - 0 155
		// fen rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w - - 0 1 moves 
		// Parse move list (if any)
		while (is >> token && (m = UCI::to_move(pos, token)) != MOVE_NONE)
		{
			States->push_back(StateInfo());
			CheckInfo ci(pos);
			pos.do_move(m, States->back(), pos.gives_check(m, ci), ci);
		}
		// 如果没有合法走了？
	}




	// set_option() is called when engine receives the "setoption" UCI command. The
	// function updates the UCI option ("name") to the given value ("value").

	void set_option(istringstream& is) {

		string token, name, value;

		is >> token; // Consume "name" token

		// Read option name (can contain spaces)
		while (is >> token && token != "value")
			name += string(" ", name.empty() ? 0 : 1) + token;

		// Read option value (can contain spaces)
		while (is >> token)
			value += string(" ", value.empty() ? 0 : 1) + token;

		if (Options.count(name))
			Options[name] = value;
		else
			sync_cout << "No such option: " << name << sync_endl;
	}



	// go() is called when engine receives the "go" UCI command. The function sets
	// the thinking time and other parameters from the input string, and then starts
	// the search.

	void go(Position& pos, istringstream& is) {

		Search::LimitsType limits;
		string token;

		limits.startTime = now(); // As early as possible!

		while (is >> token)
		{
			if (token == "searchmoves")
				while (is >> token)
					limits.searchmoves.push_back(UCI::to_move(pos, token));

			else if (token == "wtime")     is >> limits.time[WHITE];
			else if (token == "btime")     is >> limits.time[BLACK];
			else if (token == "winc")      is >> limits.inc[WHITE];
			else if (token == "binc")      is >> limits.inc[BLACK];
			else if (token == "movestogo") is >> limits.movestogo;
			else if (token == "depth")     is >> limits.depth;
			else if (token == "nodes")     is >> limits.nodes;
			else if (token == "movetime")  is >> limits.movetime;
			else if (token == "mate")      is >> limits.mate;
			else if (token == "infinite")  limits.infinite = 1;
			else if (token == "ponder")    limits.ponder = 1;
		}

		Threads.start_thinking(pos, States, limits);
	}

	  // On ucinewgame following steps are needed to reset the state
	void newgame() {

		TT.resize(Options["Hash"]);
		Search::clear();
		//Tablebases::init(Options["SyzygyPath"]);
		Time.availableNodes = 0;

	}

}

extern bool ccmd(Position& pos, istringstream& uip);

/// Wait for a command from the user, parse this text string as an UCI command,
/// and call the appropriate functions. Also intercepts EOF from stdin to ensure
/// that we exit gracefully if the GUI dies unexpectedly. In addition to the UCI
/// commands, the function also supports a few debug commands.

void UCI::loop(int argc, char* argv[]) {

	Position pos;
	string token, cmd;

	newgame(); // Implied ucinewgame before the first position command

	pos.set(StartFEN, &States->back(), Threads.main());

	for (int i = 1; i < argc; ++i)
		cmd += std::string(argv[i]) + " ";

	do	{
		if (argc == 1 && !getline(cin, cmd)) // Block here waiting for input
			cmd = "quit";

		istringstream is(cmd);

		token.clear(); // getline() could return empty or blank line

#ifdef USE_LOG_FILE
		fprintf_s(llog_file, "%s\n\n", cmd.c_str());
		fflush(llog_file);
#endif

		is >> skipws >> token;

		// The GUI sends 'ponderhit' to tell us to ponder on the same move the
		// opponent has played. In case Signals.stopOnPonderhit is set we are
		// waiting for 'ponderhit' to stop the search (for instance because we
		// already ran out of time), otherwise we should continue searching but
		// switching from pondering to normal search.
		if (token == "quit"
			|| token == "stop"
			|| (token == "ponderhit" && Search::Signals.stopOnPonderhit))
		{
			Search::Signals.stop = true;
			Threads.main()->start_searching(true); // Could be sleeping
		}
		else if (token == "ponderhit")
			Search::Limits.ponder = 0; // Switch to normal search

		else if (token == "uci")
		{
			sync_cout << "id name " << engine_info(true)
				<< "\n" << Options
				<< "\nuciok" << sync_endl;
		}
		else if (token == "ucinewgame")
		{
			newgame();
		}
		else if (token == "isready")	    sync_cout << "readyok" << sync_endl;
		else if (token == "go")             go(pos, is);
		else if (token == "position")		position(pos, is);
		else if (token == "fen")            { istringstream ifen(cmd); position(pos, ifen); }
		else if (token == "setoption")		set_option(is);
		else if (token == "flip")    		{ /*pos.flip();*/ }
		else if (token == "bench")          benchmark(pos, is);
		
		else if (token == "cmd")		    ccmd(pos, is);

		else if (token == "perft")
		{
			int depth;
			stringstream ss;

			is >> depth;
			ss << Options["Hash"] << " "
				<< Options["Threads"] << " " << depth << " current " << token;

			benchmark(pos, ss);
		}

		//else
		//	sync_cout << "Unknown command: " << cmd << sync_endl;

	} while (token != "quit" && argc == 1); // Passed args have one-shot behaviour

	Threads.main()->wait_for_search_finished();
}

/// UCI::value() converts a Value to a string suitable for use with the UCI
/// protocol specification:
///
/// cp <x>    The score from the engine's point of view in centipawns.
/// mate <y>  Mate in y moves, not plies. If the engine is getting mated
///           use negative values for y.

string UCI::value(Value v) {

	assert(-VALUE_INFINITE < v && v < VALUE_INFINITE);

	stringstream ss;

	if (abs(v) < VALUE_MATE - MAX_PLY)
		ss << " score " << v * 100 / 100;
	else
		ss << " mate " << (v > 0 ? VALUE_MATE - v + 1 : -VALUE_MATE - v) / 2;

	return ss.str();
}


/// UCI::square() converts a Square to a string in algebraic notation (g1, a7, etc.)

std::string UCI::square(Square s) {
	return std::string{ char('a' + StoX(s)), char('9' - StoY(s)) };
}


/// UCI::move() converts a Move to a string in coordinate notation (g1f3, a7a8q).
/// The only special case is castling, where we print in the e1g1 notation in
/// normal chess mode, and in e1h1 notation in chess960 mode. Internally all
/// castling moves are always encoded as 'king captures rook'.

string UCI::move(Move m) {

	Square from = from_sq(m);
	Square to = to_sq(m);

	if (m == MOVE_NONE)
		return "0000";
	else if (m == MOVE_NULL)
		return "0000";
	
	string move = UCI::square(from) + UCI::square(to);
	
	return move;
}









/// UCI::to_move() converts a string representing a move in coordinate notation
/// (g1f3, a7a8q) to the corresponding legal Move, if any.

Move UCI::to_move(Position& pos, string& str) {

	if (str.length() == 5) // Junior could send promotion piece in uppercase
		str[4] = char(tolower(str[4]));

	for (const auto& m : MoveList<LEGAL>(pos))
		if (str == UCI::move(m))
			return m;

	return MOVE_NONE;
}


bool ccmd(Position& pos, istringstream& uip){
	string token;
	while(uip >> token){
		if(token == "eval"){	

#ifdef CAN_OUT_EVAL_INFO
			//Value margin;
			// 
			Eval::init();		
			// 全局变量,可输出评估信息了. 
			MustOuPutEvalInf = true;
			Eval::evaluate(pos);
			//print_eval_info(RootPosition,eiInfo,val);		
#endif
		}
		else if(token == "bookmove"){
			while (uip >> token){
				int move_delay_time = 0;
				if(token == "delay"){
					uip >> move_delay_time;
					uip >> token;
				}

				sleep_ms(DELEY_BEST_MOVE_TIME);
				std::cout << "bestmove " << token << std::endl;
				return true;
			}
		}
		else if(token == "see"){
			//int m;
			if(uip >> token){

				pos.board_display("see!");

				Move m = move_from_string(pos, token);
				int see = pos.see_ge(Move(m), VALUE_ZERO);
				// pos.board_display("see!");

				std::cout << "see value: " << see << std::endl;
			}
		}
		else if(token == "cf"){
			// fen 4kab2/4a4/4b4/4nr2p/3R5/9/4P3P/4B1N2/4A4/4K4 b - - 0 53 moves f6f3 d5d6 e6g5 d6d4 g5h3 e0d0 f3f5 d4d2 f5b5 e2c0 b5b0 d2c2 b0b4 g2f0 b4d4 c2d2 d4c4 c0a2 c4c3 f0g2 c3b3 a2c0 b3b4 d2c2 e8d9 g2f0 f9e8 d0e0 h3g1 e0d0 g1f3 c2f2 f3g5 d0e0 e8f7 e0d0 b4g4 f2g2 g4h4 g2e2 f7e8 c0a2 i6i5 f0g2 h4d4 d0e0 g5h3 g2h0 d4f4 e2g2 h3g5 h0i2 g5e6 i2g3 f4g4 a2c0

			// istringstream ifen("fen 4kab2/4a4/4b4/4nr2p/3R5/9/4P3P/4B1N2/4A4/4K4 b - - 0 53 moves f6f3 d5d6 e6g5 d6d4 g5h3 e0d0 f3f5 d4d2 f5b5 e2c0 b5b0 d2c2 b0b4 g2f0 b4d4 c2d2 d4c4 c0a2 c4c3 f0g2 c3b3 a2c0 b3b4 d2c2 e8d9 g2f0 f9e8 d0e0 h3g1 e0d0 g1f3 c2f2 f3g5 d0e0 e8f7 e0d0 b4g4 f2g2 g4h4 g2e2 f7e8 c0a2 i6i5 f0g2 h4d4 d0e0 g5h3 g2h0 d4f4 e2g2 h3g5 h0i2 g5e6 i2g3 f4g4 a2c0");
			
			istringstream ifen("fen 2bak3C/1R2a4/3c5/4p4/2p3R2/2P6/2r1c3n/C3r3N/4Ap3/3NKAB2 w - - 0 2 moves g5g9 e8f9 g9g8 f9e8 g8g9");
			position(pos, ifen);
		}

		else if(token == "repeat"){

			// fen 1nbaka3/5r3/3Pb4/p1p1p3p/3c5/P1PN5/R5p2/2N1CAn2/9/2B1KAB2 b - - 0 moves d5e5 e0d0 e5d5 d0e0 d5e5 e0d0 e5d5 d0e0
			// fen 1nbaka3/5r3/3Pb4/p1p1p3p/3c5/P1PN5/R5p2/2N1C1n2/4A4/2B1KAB2 b - - 0 moves d5e5 e0d0 e5d5 d0e0 d5e5 e0d0 e5d5 d0e0
			// fen 3k5/1R7/3ara3/9/6n2/6B2/9/4C4/4AK3/c5B2 w - - 0 1 moves b8b9 d9d8 b9a9 a0b0 a9a8 d8d9 a8b8 b0a0 b8b9


#define REPEAT_DEBUG
#ifdef REPEAT_DEBUG
			pos.board_display("repeat test!");

			switch(pos.is_repeat()){
			case REPEAT_TRUE:
				std::cout << "REPEAT_TRUE!" << std::endl;
				break;
			case REPEAT_BAN_ME_CHECK:
				std::cout << "REPEAT_BAN_ME_CHECK!" << std::endl;
				break;
			case REPEAT_BAN_OTHER_CHECK:
				std::cout << "REPEAT_BAN_OTHER_CHECK!" << std::endl;
				break;
			case REPEAT_BAN_ME_CAP:
				std::cout << "REPEAT_BAN_ME_CAP!" << std::endl;
				break;
			case REPEAT_BAN_OTHER_CAP:
				std::cout << "REPEAT_BAN_OTHER_CAP!" << std::endl;
				break;
			case REPEAT_NO:
				std::cout << "REPEAT_NO!" << std::endl;
				break;
			}
#else
			pos.board_display("repeat test!");

			switch (pos.is_repeat()){
			case REPEAT_TRUE:
				std::cout << "REPEAT_TRUE!" << std::endl;
				break;
			case REPEAT_BAN_ME:
				std::cout << "REPEAT_BAN_ME_CHECK!" << std::endl;
				break;
			case REPEAT_BAN_OTHER:
				std::cout << "REPEAT_BAN_OTHER_CHECK!" << std::endl;
				break;
			case REPEAT_NO:
				std::cout << "REPEAT_NO!" << std::endl;
				break;
			}
#endif


			//if(!isre){
			//	RootPosition.board_display("repeat Now!");
			//}
			//else{
			//	std::cout << "not repeat!" << std::endl;
			//}
		}
	}
	return true;
}

#ifdef _MSC_VER

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include  <windows.h>  
#include <shellapi.h>
#include <sys/stat.h>

void read_uci_set_file(){
	//打开设定文件
	TCHAR filename[1024];  
	swprintf_s(filename,1024,L"%s\\%s",installDir,L"ggX64set2017.ini");

	int pFile;
	char rbuf[4096];

	errno_t err = _wsopen_s(&pFile,filename,_O_RDONLY, _SH_DENYNO,_S_IREAD);

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

        // 当有字节存在时
		while(*p != 0){

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

			if(strlen(name) > 2 && strlen(value) > 0){
				sprintf_s(opcmd,1024,"name %s value %s",name,value);
				istringstream uip(opcmd);
				set_option(uip);
			}
			else{
				return;
			}
		}      

	}
	else{
		printf("\ncannot open set file!!\n");
	}
}

#else

void read_uci_set_file() {
	
}

#endif

