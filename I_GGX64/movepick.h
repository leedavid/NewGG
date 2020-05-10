#if !defined MOVEPICK_H_INCLUDED
#define MOVEPICK_H_INCLUDED


////
//// Includes
////














#include <algorithm> // For std::max
#include <array>

#include "movegen.h"
#include "position.h"
#include "types.h"


/// StatBoards is a generic 2-dimensional array used to store various statistics
template<int Size1, int Size2, typename T = int>
struct StatBoards : public std::array<std::array<T, Size2>, Size1> {

	void fill(const T& v) {
		T* p = &(*this)[0][0];
		std::fill(p, p + sizeof(*this) / sizeof(*p), v);
	}
};

/// ButterflyBoards are 2 tables (one for each color) indexed by the move's from
/// and to squares, see chessprogramming.wikispaces.com/Butterfly+Boards
typedef StatBoards<2, 90 * 256> ButterflyBoards;

/// PieceToBoards are addressed by a move's [piece][to] information
typedef StatBoards<16, 90> PieceToBoards;

/// ButterflyHistory records how often quiet moves have been successful or
/// unsuccessful during the current search, and is used for reduction and move
/// ordering decisions. It uses ButterflyBoards as backing store.
struct ButterflyHistory : public ButterflyBoards {

	void update(Color c, Move m, int v) {

		const int D = 324;
		int& entry = (*this)[c][from_to(m)];

		assert(abs(v) <= D); // Consistency check for below formula

		entry += v * 32 - entry * abs(v) / D;

		assert(abs(entry) <= 32 * D);
	}
};

/// PieceToHistory is like ButterflyHistory, but is based on PieceToBoards
struct PieceToHistory : public PieceToBoards {

	void update(Piece pc, Square to, int v) {

		const int D = 936;
		int& entry = (*this)[pc][to];

		assert(abs(v) <= D); // Consistency check for below formula

		entry += v * 32 - entry * abs(v) / D;

		assert(abs(entry) <= 32 * D);
	}
};

/// CounterMoveStat stores counter moves indexed by [piece][to] of the previous
/// move, see chessprogramming.wikispaces.com/Countermove+Heuristic
typedef StatBoards<16, 90, Move> CounterMoveStat;

/// CounterMoveHistoryStat is like CounterMoveStat but instead of a move it
/// stores a full history (based on PieceTo boards instead of ButterflyBoards).
typedef StatBoards<16, 90, PieceToHistory> CounterMoveHistoryStat;


/// MovePicker class is used to pick one pseudo legal move at a time from the
/// current position. The most important method is next_move(), which returns a
/// new pseudo legal move each time it is called, until there are no moves left,
/// when MOVE_NONE is returned. In order to improve the efficiency of the alpha
/// beta algorithm, MovePicker attempts to return the moves which are most likely
/// to get a cut-off first.
namespace Search { struct Stack; }

class MovePicker {
public:
	MovePicker(MovePicker&) = delete;
	MovePicker& operator=(const MovePicker&) = delete;

	MovePicker(Position&, Move, Value);
	MovePicker(Position&, Move, Depth, Square);
	MovePicker(Position&, Move, Depth, Search::Stack*);

	Move next_move(bool skipQuiets = false);

private:
	template<GenType> void score();
	ExtMove* begin() { return cur; }
	ExtMove* end() { return endMoves; }

	Position& pos;
	const Search::Stack* ss;
	Move killers[2];
	Move countermove;
	Depth depth;
	Move ttMove;
	Square recaptureSquare;
	Value threshold;
	int stage;
	ExtMove *cur, *endMoves, *endBadCaptures;
	ExtMove moves[MAX_MOVES];
};

#endif // !defined(MOVEPICK_H_INCLUDED)
