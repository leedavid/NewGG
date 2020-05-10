


#ifndef NOTATION_H_INCLUDED
#define NOTATION_H_INCLUDED

#include <string>

#include "types.h"

class Position;

//extern std::string score_to_uci(Value v, Value alpha = -VALUE_INFINITE, Value beta = VALUE_INFINITE);
//extern Move move_from_uci(Position& pos, std::string& str);
//extern const std::string move_to_uci(Move m);
//const std::string move_to_san(Position& pos, Move m);
extern std::string pretty_pv(Position& pos, int depth, Value score, sint64 msecs, Move pv[]);

#endif // #ifndef NOTATION_H_INCLUDED
