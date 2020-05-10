#include "chess.h"


////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>


#include "mersenne.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

using std::string;


/// Position::is_mate() returns true or false depending on whether the
/// side to move is checkmated.

//bool Position::is_mate() {
//	//ExtMove moves[MAX_MOVES];
//	return !MoveList<LEGAL>(*this).size();
//}

