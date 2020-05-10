#include <cassert>
#include <iomanip>
#include <sstream>
#include <stack>

#include "notation.h"
#include "movegen.h"
#include "position.h"

using namespace std;

// score _to_uci() converts a value to a string suitable for use with the UCI
// protocol specifications:
//
// cp <x>     The score from the engine's point of view in centipawns.
// mate <y>   Mate in y moves, not plies. If the engine is getting mated
//            use negative values for y.

/// score_to_uci() converts a value to a string suitable for use with the UCI
/// protocol specifications:
///
/// cp <x>     The score from the engine's point of view in centipawns.
/// mate <y>   Mate in y moves, not plies. If the engine is getting mated
///            use negative values for y.

//string score_to_uci(Value v, Value alpha, Value beta) {
//
//	stringstream s;
//
//	//if (abs(v) < VALUE_MATE_IN_MAX_PLY)
//	//	s << "score " << v ;
//	//else
//	//	s << "mate " << (v > 0 ? VALUE_MATE - v + 1 : -VALUE_MATE - v) / 2;
//
//	s << " score " << v;
//
//	s << (v >= beta ? " lowerbound" : v <= alpha ? " upperbound" : "");
//
//	return s.str();
//}


/// move_to_string() converts a move to a string in coordinate notation
/// (g1f3, a7a8q, etc.).  The only special case is castling moves, where we
/// print in the e1g1 notation in normal chess mode, and in e1h1 notation in
/// Chess960 mode.

//const string move_to_uci(Move m) { // const std::string move_to_string(Move move) {
//
//	std::string str;
//	Square from = from_sq(m);
//	Square to   = to_sq(m);
//
//	if (m == MOVE_NONE)
//		str = "0000";
//	else if (m == MOVE_NULL)
//		str = "0000";
//	else{
//		str = square_to_string(from) + square_to_string(to);
//	}
//	return str;
//}

/// moove_from_uci() takes a position and a string representing a move in
/// simple coordinate notation and returns an equivalent Move if any.
/// Moves are guaranteed to be legal.

//Move move_from_uci(Position& pos, string& str) {
//
//  for (MoveList<LEGAL> it(pos); *it; ++it)
//      if (str == move_to_uci(*it))
//          return *it;
//
//	return MOVE_NONE;
//}

/// pretty_pv() formats human-readable search information, typically to be
/// appended to the search log file. It uses the two helpers below to pretty
/// format time and score respectively.

//string time_to_string(sint64 millisecs) {
//
//		const int MSecMinute = 1000 * 60;
//		const int MSecHour   = 1000 * 60 * 60;
//
//		sint64 hours = millisecs / MSecHour;
//		sint64 minutes =  (millisecs % MSecHour) / MSecMinute;
//		sint64 seconds = ((millisecs % MSecHour) % MSecMinute) / 1000;
//
//		std::stringstream s;
//
//		if (hours)
//			s << hours << ':';
//
//		s << setfill('0') << setw(2) << minutes << ':' << setw(2) << seconds;
//
//		return s.str();
//}

//static string score_to_string(Value v) {
//
//  stringstream s;
//
//  s << setprecision(2) << fixed << showpos << double(v) / PAWN_VAL;
//
//  return s.str();
//}








