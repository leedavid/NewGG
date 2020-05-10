#if !defined(DEPTH_H_INCLUDED)
#define DEPTH_H_INCLUDED
////
//// Types
////

#include "s_types.h"

enum Depth {

	ONE_PLY = 2,

	DEPTH_ZERO         =  0 * ONE_PLY,
	DEPTH_QS_CHECKS    = -1 * ONE_PLY,
	DEPTH_QS_NO_CHECKS = -2 * ONE_PLY,

	DEPTH_NONE = -127 * ONE_PLY
};

ENABLE_OPERATORS_ON(Depth);


#endif