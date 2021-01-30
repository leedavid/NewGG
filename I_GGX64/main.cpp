
#include <iostream>
#include <string>

#include "chess.h"
#include "evaluate.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "uci.h"
#include "syzygy/tbprobe.h"



#pragma warning(disable : 4530)    

using namespace std;


int main(int argc, char *argv[]) {

	std::cout << engine_info() << std::endl;

	CommandLine::init(argc, argv);

	frist_init();  // Bitboards::init();


	UCI::init(Options);

	Position::init();
	Eval::init();

	Search::init();
	Threads.set(size_t(Options["Threads"]));
	Search::clear(); // After threads are up
	Eval::NNUE::init();

	UCI::loop(argc, argv);

	Threads.set(0);
	return 0;
}








