
#include "chess.h"

////
//// Includes
////


//#include "s_direction.h"
#include "endgame.h"
#include "evaluate.h"
#include "material.h"
#include "mersenne.h"
#include "misc.h"
#include "movepick.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "uci.h"
#include "tt.h"
//#include "VMP.h"

/// Application class is in charge of initializing global resources
/// at startup and cleanly releases them when program terminates.




//void initTOTAL() {
//
//
//	frist_init();  // Bitboards::init();
//
//
//	UCI::init(Options);	
//
//	Position::init();
//	Eval::init();
//
//	Search::init();
//	Threads.init();
//
//	read_uci_set_file();
//
//	TT.resize(Options["Hash"]);		
//}







