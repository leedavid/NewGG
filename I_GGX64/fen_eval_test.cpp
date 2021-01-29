#include "chess.h"

////
//// Includes
////
#include <fstream>
#include <sstream>
#include <vector>

#include "benchmark.h"
#include "search.h"
#include "thread.h"
#include "uci.h"

#ifdef USE_TEST_FEN

using namespace std;

// 最大值, 最小值
const string Fen_Test_Eavl[] = {
	"N2a1kb2/4a2PR/4b4/6r2/9/6r2/9/B8/4A2C1/2B1KA3 w - - 0 91 max 160 min 20",
	"2bak4/4a4/2N1b3n/2c3p2/3r1P2c/p3R4/3N5/1C2B4/4A4/4KAB2 w - - 0 1  max -9 min -60",
	"2bk1a3/7R1/2nNb1N2/p2r5/2p3p2/8c/4P4/B2C5/4A4/3AK1c2 w - - 0 0 max 100 min 50",
	"2b1kab1C/4a4/4c4/p3p4/9/3r2B1P/P8/1N3R3/2nN5/2B2K3 w - - 0 1 max -100, min -1",
};

#endif
