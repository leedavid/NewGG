/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2010 Marco Costalba, Joona Kiiski, Tord Romstad

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <fstream>
#include <iostream>
#include <istream>
#include <vector>

#include "chess.h"
#include "misc.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "uci.h"
#include "tt.h"


using namespace std;

//"1r1a1k3/3Ra4/n2cb1n2/p1p3p1p/4C4/2P1r4/P3N1P1P/4BC3/4A4/2BAK2R1 w", // moves d8d7 ",
//	"2bk1a3/4a4/4b3n/9/3P3r1/2R6/5R3/4CA2B/4K4/2BA3r1 w", // moves c4c9 ",
//	"1r2kab2/4a2r1/4b4/pCp1nN2p/4C4/2Pn2P2/P6cP/4B4/4A4/1RBAK2R1 w",// moves h0h3|b6e6",
//	"3akabr1/7C1/2N1b2R1/p1C1p4/2P2c3/6p2/P4nr2/5R2B/4A4/2BAK4 w",// moves h8a8 ",
//	"2bakab2/9/2n2R3/p1p1p3p/9/9/P1P1c1P1P/4C4/1r2A4/RNBCKA2r w",// moves a0a1 ",

const vector<string> Defaults = {
  "rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w - - 0 1", // 开局
  "1Cb2a3/3ka4/b3c4/P1P1R3p/6r2/2P3N2/3r4P/4B4/4Anp2/2BAK2R1 b - - 0 1",
  "1r1a1k3/3Ra4/n2cb1n2/p1p3p1p/4C4/2P1r4/P3N1P1P/4BC3/4A4/2BAK2R1 w",
  "1r2kab2/4a2r1/4b4/pCp1nN2p/4C4/2Pn2P2/P6cP/4B4/4A4/1RBAK2R1 w",
  "1rbak2r1/9/2na2n2/p1p5p/6p2/2P6/P5P1P/BCN1C1Nc1/7R1/3AKAB2 r",  // 马三进 五
  "1R1ak1b2/4a4/R3b4/p3p3p/9/2P1P4/P4rn1P/2N1BC3/3CA4/3AKN1rc b - - 0 1",
  "2b1kab2/4a1c2/rcn3n2/p1p1pR2p/3NP4/2P6/P5p1P/1C7/4C2r1/RNBAKAB2 w - - 0 1",
  "2ba3R1/5k3/4ba3/p7p/3rN4/4P2N1/2c5P/4B4/2p1A4/c3KAB2 b",  // 黑车平5
  "2bak4/2c1a3c/4b1n2/1nN1pR3/p5p1p/7r1/P2R2P1P/B3C1N2/1r2C4/3AKAB2 w - - 0 1",
  "2bak4/4a1R1C/2n1b2cn/p1p1pNp2/3NP3p/2P3P2/PR6P/4C3B/3rA4/2B1KA1rc r",
  "2baka3/1R7/3c5/4p3C/2p3R2/2P6/2r1c3n/C3B2rN/4Ap3/3NKAB2 b", // 车8平5
  "2baka3/9/cR2b4/p1p4Rp/4p1p2/2P2r3/P3P1n1r/2N1BC3/4A4/2B1KA3 w",
  "2bakab2/9/2n2R3/p1p1p3p/9/9/P1P1c1P1P/4C4/1r2A4/RNBCKA2r w",
  "2bakn3/c3a4/1rn1bc3/p2RCN2p/6P2/9/P1p1P1r1P/4C1N2/3R5/2BAKAB2 w - - 0 1",
  "2bk1a3/4a4/4b3n/9/3P3r1/2R6/5R3/4CA2B/4K4/2BA3r1 w",
  "2Rak1br1/1R2a4/4c1n2/p3p3p/1n4rc1/9/P3P3P/2NCC1N2/4A4/2B1KAB2 r",   //马七进六 
  "3akabr1/7C1/2N1b2R1/p1C1p4/2P2c3/6p2/P4nr2/5R2B/4A4/2BAK4 w",
  "C1bCk1b2/4aR3/1R1c5/p6rp/2p3p2/P1p6/2n1P1P1P/n3B1N2/4A4/c2K1AB2 w - - 0 1",
  "r1bak4/4a2N1/n3b4/4C1p2/pRp1p4/6P2/P1C5p/9/4Ar3/c3K3c r",  // 士五进四
  "3akab2/9/4b1n2/p1RPp3p/1R7/6P2/6r1P/4B4/4Ar3/2B1KAC2 r",
  "2baka3/r8/4b4/p1pR4p/5N1r1/2P3p2/c3P1n1P/3CB1Nc1/9/1R1AKAB2 r", //马四进五
  "4kab2/3Pn4/9/9/6b2/9/9/9/4K4/4CA3 r",                           //帅五进一
};




#define BENCH_perft
#ifdef  BENCH_perft

static char* benchcomd[] = {
	"bench",
	"command",
	"128",
	"1",        // thread
	"5",        // depth 4 = 69841361， 5 = 3129657775
	"default",
	"perft"      // depth 
};
#else
static char* benchcomd[] = {
 "bench",
 "command",
 "128",
 "20",
 "18",        // depth 
 "default",
 "depth"      // depth 
};
#endif

//using namespace std;
//using namespace Search;

#define PERFT_DEPTH 5

/// benchmark() runs a simple benchmark by letting Stockfish analyze a set
/// of positions for a given limit each. There are five parameters: the
/// transposition table size, the number of search threads that should
/// be used, the limit value spent for each position (optional, default is
/// depth 13), an optional file name where to look for positions in FEN
/// format (defaults are the positions defined above) and the type of the
/// limit value: depth (default), time in millisecs or number of nodes.

void benchmark(const Position& current, istream& is) {

	string token;
	vector<string> fens;
	Search::LimitsType limits;

	// Assign default values to missing arguments
	string ttSize = (is >> token) ? token : "256";
	string threads = (is >> token) ? token : "4";
	string limit = (is >> token) ? token : "20";
	string fenFile = (is >> token) ? token : "default";
	string limitType = (is >> token) ? token : "depth";

	Options["Hash"] = ttSize;
	Options["Threads"] = threads;
	Search::clear();

	if (limitType == "time")
		limits.movetime = stoi(limit); // movetime is in millisecs

	else if (limitType == "nodes")
		limits.nodes = stoi(limit);

	else if (limitType == "mate")
		limits.mate = stoi(limit);

	else
		limits.depth = stoi(limit);

	if (fenFile == "default")
		fens = Defaults;

	else if (fenFile == "current")
		fens.push_back(current.fen());

	else
	{
		string fen;
		ifstream file(fenFile);

		if (!file.is_open())
		{
			cerr << "Unable to open file " << fenFile << endl;
			return;
		}

		while (getline(file, fen))
			if (!fen.empty())
				fens.push_back(fen);

		file.close();
	}

	uint64_t nodes = 0;
	TimePoint elapsed = now();
	Position pos;

	for (size_t i = 0; i < fens.size(); i++)
	{
		StateListPtr states(new std::deque<StateInfo>(1));
		pos.set(fens[i], &states->back(), Threads.main());

		cerr << "\nPosition: " << i + 1 << '/' << fens.size() << endl;

		if (limitType == "perft")
			nodes += Search::perft(pos, limits.depth * ONE_PLY);
		else
		{
			limits.startTime = now();
			Threads.start_thinking(pos, states, limits);
			Threads.main()->wait_for_search_finished();
			nodes += Threads.nodes_searched();
		}
	}

	elapsed = now() - elapsed + 1;  // Avoid a 'divide by zero'

	dbg_print(); // Just before to exit

	cerr << "\n==========================="
		<< "\nTotal time (ms) : " << elapsed
		<< "\nNodes searched  : " << nodes
		<< "\nNodes/second    : " << 1000 * nodes / elapsed << endl;
}


// byCmlx
//===============================
//	Total time (ms) : 350659
//	Nodes searched  : 2578418081
//	Nodes/second    : 7353064

//GGchess 12.0318.01 MAX 6U
//	id author Li Guolai 
//===========================
//	Total time (ms) : 72456
//	Nodes searched  : 2578418081
//	Nodes/second    : 35585984
//    info initstart ...
//	info initok ...
//	info 当前使用线程数：1
//	id name ggChess-UCI-20090712-02-MAX-1CPUS-UCI-WL-GGCHESS
//	id author liguolai
//	uciok
//	info initend
//	bench
//
//Position: 1/16
//
//		  Perft 5 leaf nodes: 133312995
//
//Position: 2/16
//
//		  Perft 5 leaf nodes: 173152112
//
//Position: 3/16
//
//		  Perft 5 leaf nodes: 181976740
//
//Position: 4/16
//
//		  Perft 5 leaf nodes: 140289291
//
//Position: 5/16
//
//		  Perft 5 leaf nodes: 84555318
//
//Position: 6/16
//
//		  Perft 5 leaf nodes: 90597952
//
//Position: 7/16
//
//		  Perft 5 leaf nodes: 227792614
//
//Position: 8/16
//
//		  Perft 5 leaf nodes: 38843992
//
//Position: 9/16
//
//		  Perft 5 leaf nodes: 369978040
//
//Position: 10/16
//
//		  Perft 5 leaf nodes: 174096644
//
//Position: 11/16
//
//		  Perft 5 leaf nodes: 351729218
//
//Position: 12/16
//
//		  Perft 5 leaf nodes: 143314746
//
//Position: 13/16
//
//		  Perft 5 leaf nodes: 25195985
//
//Position: 14/16
//
//		  Perft 5 leaf nodes: 205895317
//
//Position: 15/16
//
//		  Perft 5 leaf nodes: 70978723
//
//Position: 16/16
//
//		  Perft 5 leaf nodes: 166708394
//
//===========================
//	Total time (ms) : 73250
//	Nodes searched  : 2578418081
//	Nodes/second    : 35200246

