#include "chess.h"

#include <cassert>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>

#include "move.h"
//#include "s_piece.h"
#include "position.h"
#include "search.h"
#include "movegen.h"

using std::string;

namespace {
	//const string time_string(int milliseconds);
	//const string score_string(Value v);
}



/// move_from_string() takes a position and a string as input, and attempts to
/// convert the string to a move, using simple coordinate notation (g1f3,
/// a7a8q, etc.). In order to correctly parse en passant captures and castling
/// moves, we need the position. This function is not robust, and expects that
/// the input move is legal and correctly formatted.
#pragma warning(disable : 4100) 
Move move_from_string(const Position& pos, const std::string& str) {

	Square from, to;

	if (str.length() < 4)
		return MOVE_NONE;

	// Read the from and to squares
	from = square_from_string(str.substr(0, 2));
	to   = square_from_string(str.substr(2, 4));

	return make_move(from, to);
}




