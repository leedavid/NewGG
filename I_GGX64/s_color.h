#if !defined(COLOR_H_INCLUDED)
#define COLOR_H_INCLUDED

#include "s_types.h"

enum Color {
	WHITE,
	BLACK,
	COLOR_NONE
};

ENABLE_OPERATORS_ON(Color);

////
//// Inline functions
////

inline Color opposite_color(Color c) {
	return Color(int(c) ^ 1);
}

inline bool color_is_ok(Color c) {
	return c == WHITE || c == BLACK;
}

#endif