#include "chess.h"
#include <cassert>
#include <cstring>
#include "preGen.h"

#include "evaluate.h"
#include "material.h"
#include "thread.h"
#include "uci.h"
#include "eval_const.h"

#pragma once

template<Color Us> Score eval_king_up_one_string(Position& pos, EvalInfo& ei);
template<Color Us> int PawnOverRiver(Position& pos, EvalInfo& ei);
template<Color Us> Score eval_zhou_and_moveless(Position& pos, EvalInfo& ei,
	Square mid, PieceType XPiece, Square xPos);
