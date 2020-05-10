#ifndef MY_CONST_H
#define MY_CONST_H


#define King_4_Side(p90)       _KingSide[p90]
#define King_LR_Side(p90)    _ON_KING_LR[p90]
#define point(opening,endgame) (((opening) << 16) + (endgame))
#define Mirror(s) XYtoS(8-StoX(s),StoY(s))

static const uint8 revertChess[] = {
	EMPTY, 
	BKING, BSHI, BXIANG, BMA, BCHE, BPAO, BPAWN,
	_X_X,
	RKING, RSHI, RXIANG, RMA, RCHE, RPAO, RPAWN,
};

const static uint8 _stoxx[90] = {
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	

	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,	
	0,    1,    2,    3,    4,    5,    6,    7,    8,
};

const static uint8 _stoxy[90] = {
	0,    0,    0,    0,    0,    0,    0,    0,    0,	
	1,    1,    1,    1,    1,    1,    1,    1,    1,	
	2,    2,    2,    2,    2,    2,    2,    2,    2,	
	3,    3,    3,    3,    3,    3,    3,    3,    3,	
	4,    4,    4,    4,    4,    4,    4,    4,    4,	

	5,    5,    5,    5,    5,    5,    5,    5,    5,	
	6,    6,    6,    6,    6,    6,    6,    6,    6,	
	7,    7,    7,    7,    7,    7,    7,    7,    7,	
	8,    8,    8,    8,    8,    8,    8,    8,    8,	
	9,    9,    9,    9,    9,    9,    9,    9,    9,
};


const static uint8 _KingSide[90] = {
	0,    0,    0,    0,    4,    1,    1,    1,    1,	
	0,    0,    0,    0,    4,    1,    1,    1,    1,	
	0,    0,    0,    0,    4,    1,    1,    1,    1,	
	0,    0,    0,    0,    4,    1,    1,    1,    1,	
	0,    0,    0,    0,    4,    1,    1,    1,    1,	

	2,    2,    2,    2,    4,    3,    3,    3,    3,	
	2,    2,    2,    2,    4,    3,    3,    3,    3,	
	2,    2,    2,    2,    4,    3,    3,    3,    3,	
	2,    2,    2,    2,    4,    3,    3,    3,    3,	
	2,    2,    2,    2,    4,    3,    3,    3,    3,	
};

//const static uint8 _ON_KING_LR[90] = {
//	1,   1,   1,   1,   0,   1,   1,   1,   1,  
//	1,   1,   1,   1,   0,   1,   1,   1,   1,  
//	1,   1,   1,   1,   0,   1,   1,   1,   1,  
//	0,   0,   0,   0,   0,   0,   0,   0,   0,     //炮归边了
//	0,   0,   0,   0,   0,   0,   0,   0,   0,  
//	0,   0,   0,   0,   0,   0,   0,   0,   0,  
//	0,   0,   0,   0,   0,   0,   0,   0,   0,  
//	1,   1,   1,   1,   0,   1,   1,   1,   1,  
//	1,   1,   1,   1,   0,   1,   1,   1,   1,  
//	1,   1,   1,   1,   0,   1,   1,   1,   1,  
//};


/*

#define KsP  KS_S_PAO_1_SIDE
#define KmP  KS_M_PAO_HAVE_ONE 
#define KS_R_PAO_INOF(p90) _R_PaoInfo[p90]
#define KS_B_PAO_INOF(p90) _B_PaoInfo[p90]

//红炮在中间的情况
const static uint32 _R_PaoInfo[90] = { 
  KsP,  KsP,  KsP,    KsP,  0,    KsP,  KsP,  KsP,  KsP,	
  KsP,  KsP,  KsP,    KsP,  0,    KsP,  KsP,  KsP,  KsP,
  KsP,  KsP,  KsP,    KsP,  0,    KsP,  KsP,  KsP,  KsP,
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	

	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,    0,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,    0,  KmP,  0,    0,    0,	
};
//黑炮在中间的情况
const static uint32 _B_PaoInfo[90] = { 
	0,    0,    0,    KmP,    0,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,    0,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	

	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
	0,    0,    0,    KmP,  KmP,  KmP,  0,    0,    0,	
  KsP,  KsP,  KsP,    KsP,  0,    KsP,  KsP,  KsP,  KsP,	
  KsP,  KsP,  KsP,    KsP,  0,    KsP,  KsP,  KsP,  KsP,
  KsP,  KsP,  KsP,    KsP,  0,    KsP,  KsP,  KsP,  KsP,	
};

#define BK_LEFT  0  //共二位 xx  0x 黑方 1x红方
#define BK_RIGHT 1
#define RK_LEFT  2
#define RK_RIGHT 3


*/

//#define R_B_CHE_OPEN(x)      ((x)&0x5)
//#define B_R_CHE_OPEN(x)      ((x)|0x2)

//#define EV_STAT_Rwoxin_By_B                (1 << 0)
//#define EV_STAT_Bwoxin_By_R                (1 << 1)

//#define EV_STAT_R_left_TieMen_By_B         (1 << 2)
//#define EV_STAT_R_right_TieMen_By_B        (1 << 3)
//#define EV_STAT_B_left_TieMen_By_R         (1 << 4)
//#define EV_STAT_B_right_TieMen_By_R        (1 << 5)


#include "endgame\\残局加分_0车.h"
#include "endgame\\残局加分_1车.h"
#include "endgame\\残局加分_2车.h"

#endif