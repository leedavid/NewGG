
#if !defined(PIECE_H_INCLUDED)
#define PIECE_H_INCLUDED


////
//// Includes
////

#include "s_color.h"
#include "s_square.h"



const Color _piece_color[16] = {
	COLOR_NONE,
	WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
	COLOR_NONE, 	
	BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
};

inline PieceTypes type_of_piece(Piece p)  {
	return PieceTypes(int(p) & 7);
}

inline Color color_of_piece(Piece p) {
	return _piece_color[p];
}


inline bool piece_type_is_ok(PieceTypes pc) {
	return pc >= KING && pc <= PAWN;
}

inline bool piece_is_ok(Piece pc) {
	return pc >= RKING && pc <= BPAWN;
}

////
//// Prototypes
////

extern char piece_to_char(Piece pc);
extern Piece piece_from_char(char c);

#endif