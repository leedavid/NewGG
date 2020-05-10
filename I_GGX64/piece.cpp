#include "chess.h"

////
//// Includes
////

#include <string>

using namespace std;

////
//// Functions
////

/// Translating piece types to/from English piece letters

char piece_to_char(Piece pt) {

	static const  char PieceString[15+3] = "0KABNRCP kabnrcp ";
	return PieceString[pt];
}

Piece piece_from_char(char c) {

	switch(c){
	case 'K':
		return RKING;
	case 'A':
		return RSHI;
	case 'B':
	case 'E':
		return RXIANG;
	case 'N':
	case 'H':
		return RMA;
	case 'R':
		return RCHE;
	case 'C':
		return RPAO;
	case 'P':
		return RPAWN;

	case 'k':
		return BKING;
	case 'a':
		return BSHI;
	case 'b':
	case 'e':
		return BXIANG;
	case 'n':
	case 'h':
		return BMA;
	case 'r':
		return BCHE;
	case 'c':
		return BPAO;
	case 'p':
		return BPAWN;
	default:
		return EMPTY;
	}
}

