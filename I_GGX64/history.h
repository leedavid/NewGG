#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED


////
#include <algorithm>
#include <cstring>
#include "move.h"









//
//////
////// Types
//////
//
///// The History class stores statistics about how often different moves
///// have been successful or unsuccessful during the current search. These
///// statistics are used for reduction and move ordering decisions. History
///// entries are stored according only to moving piece and destination square,
///// in particular two moves with different origin but same destination and
///// same piece will be considered identical.
//
//
//
//class History {
//
//public:
//	void clear();
//	Value vvalue(Piece p, Square to) const;
//	void add(Piece p, Square to, Value bonus);
//	Value gain(Piece p, Square to) const;
//	void update_gain(Piece p, Square to, Value g);
//
//	static const Value MaxValue = Value(2000);   // was 2000
//
//private:
//	Value history[16][90];  // [piece][to_square]
//	Value maxGains[16][90]; // [piece][to_square]
//};
//
//inline void History::clear() {
//	memset(history,  0, 16 * 90 * sizeof(Value));
//	memset(maxGains, 0, 16 * 90 * sizeof(Value));
//}
//
//inline Value History::vvalue(Piece p, Square to) const {
//	return history[p][to];
//}
//
//inline void History::add(Piece p, Square to, Value bonus) {
//	if (abs(history[p][to] + bonus) < MaxValue) history[p][to] += bonus;
//}
//
//inline Value History::gain(Piece p, Square to) const {
//	return maxGains[p][to];
//}
//
//inline void History::update_gain(Piece p, Square to, Value g) {
//	maxGains[p][to] = std::max(g, maxGains[p][to] - 1);
//}

#endif