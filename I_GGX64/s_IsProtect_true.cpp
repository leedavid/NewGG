#include "chess.h"
#pragma warning(disable : 4530)    

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

bool Position::isPretecte_TrueCap(Color side, Square to){



	Bitboard att = sq_attack_by_color(to,side);

	Square from;
	while (pop_1st_bit_sq(att, from)) {
		if(legal(MOVE_FromTo(from,to))){   // if(Is_Can_Move_To_Eat(board,from,sqDst)) return TRUE;
			return true;
		}
	}

	return false;
}
