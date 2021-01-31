#include "chess.h"


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
#include "rkiss.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"
#include "misc.h"
#include "pawns.h"
#include "thread.h"

using std::string;
using std::cout;
using std::endl;


Score psq[16][90];    // 棋子的位置分

namespace Zobrist {

  Key psq[16][90];
  //Key enpassant[FILE_NB];
  //Key castle[CASTLE_RIGHT_NB];
  Key side;
  Key exclusion;
  Key XiangEyeHash[90];      // 棋子在象眼上的HASH

}

Key Position::exclusion_key() const { return st->key ^ Zobrist::exclusion;}



const sint16 Open_2_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,       // 0 //3
	0,   0,   0,   0,    0,       // 1 //4
	0,   0,   0,   0,    0,       // 2 //5
	0,   0,   0,   0,    0,       // 3 //6
	0,   0,   0,   0,    0,       // 4//7
	0,   0,   0,   0,    0,       // 5 //8
	0,   0,   0,   0,    0,       // 6 //9
	0,   0,   0,   0,    0,       // 7 //a
	0,   0,   0,   0,    0,       // 8 //b
	0,   0,   0,   0,    0,       // 9 //c
};

const sint16 End_2_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,       // 0 //3
	0,   0,   0,   0,    0,       // 1 //4
	0,   0,   0,   0,    0,       // 2 //5
	0,   0,   0,   0,    0,       // 3 //6
	0,   0,   0,   0,    0,       // 4//7
	0,   0,   0,   0,    0,       // 5 //8
	0,   0,   0,   0,    0,       // 6 //9
	0,   0,   0,   0,    0,       // 7 //a
	0,   0,   0,   0,    0,       // 8 //b
	0,   0,   0,   0,    0,       // 9 //c
};

// //1Shi_B_Pawn256[256];  //只有一个士后,对方兵的加分
const sint16 Open_1_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        // 0//3
	15,  15,  48,  64,   96,       // 1 //4
	15,  15,  32,  48,   64,       // 2 //5
	15,  15,  30,  30,   30,       // 3 //6
	15,  15,  15,  15,   15,       // 4 //7
	0,   0,   0,   0,    0,        // 5//8
	0,   0,   0,   0,    0,        // 6//9
	0,   0,   0,   0,    0,        // 7//a
	0,   0,   0,   0,    0,        // 8//b
	0,   0,   0,   0,    0,        // 9//c
};

// //1Shi_B_Pawn256[256];  //只有一个士后,对方兵的加分
const sint16 End_1_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,       // 0 //3
	15,  15,  48,  64,   96,      // 1  //4
	15,  15,  32,  48,   64,      // 2  //5
	15,  15,  30,  30,   30,      // 3  //6
	15,  15,  15,  15,   15,      // 4  //7
	0,   0,   0,   0,    0,       // 5 //8
	0,   0,   0,   0,    0,       // 6 //9
	0,   0,   0,   0,    0,       // 7 //a
	0,   0,   0,   0,    0,       // 8 //b
	0,   0,   0,   0,    0,       // 9 //c
};

const sint16 Open_0_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,       // 0 //3
	46,  62,  80,  96,  118,      // 1  //4
	38,  46,  62,  80,   96,      // 2  //5
	30,  30,  48,  48,   60,      // 3  //6
	30,  30,  30,  30,   30,      // 4  //7
	16,   0,  16,   0,   16,      // 5  //8
	0,   0,   0,   0,    0,       // 6 //9
	0,   0,   0,   0,    0,       // 7 //a
	0,   0,   0,   0,    0,       // 8 //b
	0,   0,   0,   0,    0,       // 9 //c
};

const sint16 End_0_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,       // 0//3
	46,  62,  80,  96,  118,      // 1  //4
	38,  46,  62,  80,   96,      // 2  //5
	30,  30,  48,  48,   60,      // 3  //6
	30,  30,  30,  30,   30,      // 4  //7
	16,   0,  16,   0,   16,      // 5  //8
	0,   0,   0,   0,    0,       // 6 //9
	0,   0,   0,   0,    0,       // 7 //a
	0,   0,   0,   0,    0,       // 8 //b
	0,   0,   0,   0,    0,       // 9 //c
};

const sint16 OpeningKing45[50] = {  //开局的将的位置分
	0,    0,   0,   0,    0,  // 0
	0,    0,   0,   0,    0,  // 1
	0,    0,   0,   0,    0,  // 2
	0,    0,   0,   0,    0,  // 3
	0,    0,   0,   0,    0,  // 4
	0,    0,   0,   0,    0,  // 5
	0,    0,   0,   0,    0,  // 6
	0,    0,   0, -115, -125, // 7
	0,    0,   0, -65,   -45, // 8
	0,    0,   0, -15,    0,  // 9
};

const sint16 EndgameKing45[50] = {
	0,    0,   0,   0,    0,   // 0
	0,    0,   0,   0,    0,   // 1
	0,    0,   0,   0,    0,   // 2
	0,    0,   0,   0,    0,   // 3
	0,    0,   0,   0,    0,   // 4
	0,    0,   0,   0,    0,   // 5
	0,    0,   0,   0,    0,   // 6
	0,    0,   0,  -25,  -15,  // 7
	0,    0,   0,  -15,  -5,   // 8
	0,    0,   0,  -5,    0,   // 9
};

const sint16 OpeningPawn45[50] = {	//奇兵的开局的兵
	-60,  -50, -40,  -30,  -55,  // 0
	80,  130, 145,  180,  270,	 // 1
	67,  100, 135,  150,  190,	 // 2
	65,   80,  95,  105,  145,	 // 3
	35,   60,  75,   80,   85,	 // 4
	10,   0,   24,   0,    15,	 // 5
	0,    0,   5,    0,    10,	 // 6
	0,    0,   0,    0,     0,	 // 7
	0,    0,   0,    0,     0,	 // 8
	0,    0,   0,    0,     0,	 // 9
};

//const sint16 OpeningPawn45[50] = {	//奇兵的开局的兵
//	-60,  -50, -40,  -30,  -55,  // 0
//	80,  140, 155,  180,  270,	 // 1
//	67,  110, 135,  160,  190,	 // 2
//	65,   80, 115,  125,  145,	 // 3
//	45,   60,  75,   80,   85,	 // 4
//	5,    0,   24,   0,    15,	 // 5
//	0,    0,   5,    0,    10,	 // 6
//	0,    0,   0,    0,     0,	 // 7
//	0,    0,   0,    0,     0,	 // 8
//	0,    0,   0,    0,     0,	 // 9
//};

//没有过河的兵要降分，残局时．
// fen 3k1ab2/3n5/4ba3/3PC3p/p1p6/6B2/3C4c/4B4/3NA4/3AK2c1 w
const sint16 EndgamePawn45[50] = {	//奇兵的残局的兵
   -60,  -50, -40,  -30,  -55,  // 0
	66,   95, 115,  125,  145,	// 1
	47,   75, 105,  115,  125,	// 2
	37,   55,  80,   85,   95,	// 3
	25,   45,  65,   70,   75,	// 4
	10,   0,   24,   0,    15,	// 5
   -5,    0,   5,    0,    10,	// 6
	0,    0,   0,    0,     0,	// 7
	0,    0,   0,    0,     0,	// 8
	0,    0,   0,    0,     0,	// 9    
};								

//const sint16 EndgamePawn45[50] = {	//奇兵的残局的兵
//	-60,  -50, -40,  -30,  -55,  // 0
//	66,   95, 115,  125,  145,	 // 1
//	47,   85, 105,  115,  125,	 // 2
//	37,   50,  70,   85,   85,	 // 3
//	15,   30,  45,   50,   55,	 // 4
//	-10,    0,  -2,    0,     0, // 5
//	-20,    0,  -15,   0,   -10, // 6
//	0,    0,   0,    0,     0,	 // 7
//	0,    0,   0,    0,     0,	 // 8
//	0,    0,   0,    0,     0,	 // 9
//};


const sint16 OpeningShiXiang45[50] = {
	0,   0,   0,   0,    0,    // 0
	0,   0,   0,   0,    0,	   // 1
	0,   0,   0,   0,    0,	   // 2
	0,   0,   0,   0,    0,	   // 3
	0,   0,   0,   0,    0,	   // 4
	0,   0,  -8,   0,    0,	   // 5
	0,   0,   0,   0,    0,	   // 6
  -12,   0,   0,  -2,    8,	   // 7
	0,   0,   0,   0,    4,	   // 8
	0,   0,   4,   0,    0,	   // 9
};

const sint16 EndgameShiXiang45[50] = {
	0,   0,   0,   0,    0,   // 0
	0,   0,   0,   0,    0,	  // 1
	0,   0,   0,   0,    0,	  // 2
	0,   0,   0,   0,    0,	  // 3
	0,   0,   0,   0,    0,	  // 4
	0,   0,   4,   0,    0,	  // 5
	0,   0,   0,   0,    0,	  // 6
   -8,   0,   0,   2,    6,	  // 7
	0,   0,   0,   0,    4,	  // 8
	0,   0,   4,   0,    0,	  // 9
};

const sint16 OpeningPao45[50] = {			//const sint16 OpeningPao45[50] = {	//奇兵的开局的炮
	82,  70,  60,  55,  40,		// 0//	85,  70,  60,  55,  40,
	65,  72,  50,  50,  40,		// 1//	65,  75,  50,  50,  40,
	65,  75,  40,  50,  50,		// 2//	65,  75,  30,  50,  50,
	65,  80,  80,  75,  80,		// 3//	65,  80,  80,  75,  80,
	65,  80,  75,  72,  80,		// 4//	65,  80,  75,  72,  80,
	56,  72,  68,  75,  85,		// 5//	56,  72,  68,  75,  85,
	65,  85,  80,  75,  95,		// 6//	65,  85,  80,  75,  95,
	80,  88,  92, 102, 100,		// 7//	80,  88,  95, 105, 100,
	80,  90, 105,  95,  90,		// 8//	80,  90, 110,  95,  90,
	30,  80, 102,  95,  65,		// 9//	30,  80, 105,  95,  65,
};		                                //};

const sint16 EndgamePao45[50] = {
	55,  60,  50,  35,  25,   // 0 
	52,  55,  55,  40,  40,	  // 1 
	50,  55,  55,  55,  65,	  // 2 
	55,  55,  55,  55,  65,	  // 3 
	65,  65,  65,  65,  65,	  // 4 
	65,  65,  65,  65,  75,	  // 5 
	75,  92,  94,  96,  95,	  // 6 
	80,  88,  92, 102, 100,	  // 7 
	80,  84,  86,  92,  80,	  // 8
	60,  80,  85,  95,  65,	  // 9
};


const sint16 OpeningMa45[50] = {	  //奇兵的马
	52,  45,  65,  50,   45,  // 0
	82,  85, 108,  80,   45,  // 1
	95,  96,  95, 110,  110,  // 2
	39, 118,  93, 128,  115,  // 3
	53,  82, 102, 105,  124,  // 4
	63,  74,  98,  83,  107,  // 5
	39,  49,  59,  56,   83,  // 6
	38,  44,  68,  62,   65,  // 7
	-10, 12,  16,  24,  -45,  // 8// fen 4kab2/3na4/2c1b1nc1/p1p5p/1r4P2/2P1C4/P3P3P/1C2B4/3N4N/1R1AKAB2 b - - 0 7
	-30,-17,  18, -12,  -65,  // 9
};



const sint16 EndgameChe45[50] = {	//奇兵的车  //const sint16 EndgameChe45[50] = {	//奇兵的车
	44,  69,  54,  96,  104,	// 0			  //	44,  69,  54, 104,   89,
	64,  79,  74,  99,  112,	// 1			  //	64,  79,  74,  99,  112,
	54,  74,  54,  96,  109,	// 2			  //	54,  74,  54, 104,  109,
	84,  94,  99, 117,  119,	// 3			  //	84,  94,  99, 117,  119,
	74,  84,  89, 107,  109,	// 4			  //	74,  84,  89, 107,  109,
	79,  89,  94, 112,  114,	// 5			  //	79,  89,  94, 112,  114,
	64,  74,  79,  97,   99,	// 6			  //	64,  74,  79,  97,   99,
	59,  74,  59,  92,   64,	// 7			  //	39,  74,  59,  92,   64,
	49,  68,  59,  62,   33,	// 8			  //	39,  64,  59,  62,   13,
	39,  54,  64,  87,  -30,	// 9			  //	9,  64,  54,  87,  -30,
};	                                 						  //};

const sint16 OpeningChe45[50] = {          //const sint16 OpeningChe45[50] = {
	44,  69,  54, 104,   98,		// 0	   //	44,  69,  54, 104,   68,
	64,  79,  74,  99,  112,		// 1	   //	64,  79,  74,  99,  112,
	54,  74,  44, 104,  109,		// 2	   //	54,  74,  54, 104,  109,
	84,  94,  99, 117,  119,		// 3	   //	84,  94,  99, 117,  119,
	74,  84,  89, 107,  109,		// 4	   //	74,  84,  89, 107,  109,
	79,  89,  94, 112,  114,		// 5	   //	79,  89,  94, 112,  114,
	64,  74,  79,  97,   99,		// 6	   //	64,  74,  79,  97,   99,
	39,  74,  59,  92,   64,		// 7	   //	39,  74,  59,  92,   64,
	39,  64,  59,  62,   13,		// 8	   //	39,  64,  59,  62,   13,
	 9,  64,  54,  87,  -30,		// 9	   //	9,  64,  54,  87,  -30,
};										   //};

										   //残局马在家要好一些
const sint16 EndgameMa45[50] = {
	48,  42,  45,  40,   25,  // 0
	62,  55,  88,  70,   49,  // 1
	75,  80,  75,  85,   90,  // 2
	39,  94,  93,  98,   95,  // 3
	43,  82,  92,  95,   84,  // 4
	33,  54,  88,  83,   87,  // 5
	39,  49,  59,  56,   83,  // 6
	16,  44,  58,  86,   55,  // 7
	-10, 16,  24,   8,  -65,  // 8
	-30,-25,  32,   5,  -55,  // 9
};

static const  uint8 a90from50[90] = {
	/////  0    1    2	  3    4    5    6    7    8
	/*00*/ 0,   1,   2,   3,   4,   3,   2,   1,   0,
	/*01*/ 5,   6,   7,   8,   9,   8,   7,   6,   5,
	/*02*/10,  11,  12,  13,  14,  13,  12,  11,  10,
	/*03*/15,  16,  17,  18,  19,  18,  17,  16,  15,
	/*04*/20,  21,  22,  23,  24,  23,  22,  21,  20,
	/*05*/25,  26,  27,  28,  29,  28,  27,  26,  25,
	/*06*/30,  31,  32,  33,  34,  33,  32,  31,  30,
	/*07*/35,  36,  37,  38,  39,  38,  37,  36,  35,
	/*08*/40,  41,  42,  43,  44,  43,  42,  41,  40,
	/*09*/45,  46,  47,  48,  49,  48,  47,  46,  45,
};


#define  MAX_PrePawnAttKingMul_Safe 255
static void init_PrePawnAttKingMul_Safe(){

	static const uint8 const_PawnAtt_X[3][10] =  {
		// 0   1   2   3   4   5  6    7   8   9
		{ 16, 32, 28, 24, 20, 16, 12,  8,  4,  0,  },  //0个仕
		{  8, 16, 12,  8,  0,  0,  0,  0,  0, 0,  },   //1个仕
		{  4,  8,  4,  0,  0,  0,  0,  0,  0, 0,  },   //2个仕
	};
	static const uint8 const_PawnAtt_Y[3][10] =  {
		// 0   1   2   3   4   5  6    7   8   9
		{ 16, 32, 28, 24, 16,  12, 0,  0,  0, 0,  },   //0个仕
		{  8, 16, 12,  8,  0,  0,  0,  0,  0, 0,  },   //1个仕
		{  4,  8,  4,  0,  0,  0,  0,  0,  0, 0,  },   //2个仕
	};
	static const char PawnKing[90] = {
		0,   0,   0,  16,  12,  16,   0,   0,   0,   
		0,   0,   0,  10,   8,  10,   0,   0,   0,   
		0,   0,   0,   8,   8,   8,   0,   0,   0,   
		0,   0,   0,   0,   0,   0,   0,   0,   0,   
		0,   0,   0,   0,   0,   0,   0,   0,   0,   
		0,   0,   0,   0,   0,   0,   0,   0,   0,   
		0,   0,   0,   0,   0,   0,   0,   0,   0,   
		0,   0,   0,   8,   8,   8,   0,   0,   0,   
		0,   0,   0,  10,   8,  10,   0,   0,   0,   
		0,   0,   0,  16,  12,  16,   0,   0,   0,   	
	};

	// 主要是看兵与将的相对位置, 这儿转化成攻击点好一些。
	for(int shi = 0; shi < 3; shi++){
		for(int p = 0; p < 90; p++){
			for(int k = 0; k < 90; k++){
                // fen 5k3/4P4/9/5c1r1/2b2R3/9/9/3A1A3/3p5/5K3 w - - 151 151
				//if(shi == 0 && k == 0x05 && p ==0x0d){
				//	shi = shi;
				//}

				


				int score = 0;
				int offx = abs(StoX(k) - StoX(p));
				int offy = abs(StoY(k) - StoY(p));

				// fen 3ak4/3na4/4br3/9/7Np/P3P2R1/3p4P/1C7/4A4/2BAK3c b - - 0 35
				if(shi == 2 && offy >= 3){
					//if(k == 0x55 || k == 0x04){
						continue;
					//}
				}

				if(offx <= 3 && offy <= 3){ // 最少要在3步内才有威胁哇

					if(shi >= 1 && offy >= 4){
						continue;						
					}
					if(shi >= 1 && offy >= 3 && offx >= 3){
						continue;						
					}
					if(shi == 2 && offx >= 4){
						continue;
					}

					// 兵在将上面
					if(  (StoY(k) <= 2 && StoY(p) >= StoY(k))
						||(StoY(k) >= 7 && StoY(p) <= StoY(k))){
							score += const_PawnAtt_X[shi][offx];
							score += const_PawnAtt_Y[shi][offy];
					}
					else{
						if(StoY(p) == 0x8 || StoY(p) == 0x1){
							score += (const_PawnAtt_X[shi][offx] /2);
							score += (const_PawnAtt_Y[shi][offy] /2);
						}
						else{
							score += (const_PawnAtt_X[shi][offx] /4);
							score += (const_PawnAtt_Y[shi][offy] /4);
						}
					}
				}
				if(StoY(p) == 0x1 || StoY(p) == 0x8){
					if(StoY(k) == 0x0 || StoY(k) == 0x9){
						if(abs(StoX(p) - StoX(k)) <= 1){
							score = score * 4 / 3;      //
						}
						if(StoX(p) == 0x4){
							score = score * 4 / 3;  //
						}
					}
				}

				//如果兵在边上,也要算小一些
				if(StoX(p) == 0x0 || StoX(p) == 0x8){
					score /= 2;  //因为兵在中间是二边算的
				}
				if(score != 0){
					score = score * PawnKing[k] / 16;
				}
				if(shi != 0){
					if(StoY(p) == 0x6 || StoY(p) == 0x3){
						score /= 2;
					}
				}
				//如果将在二线，也要降分哇
				// fen 3k1ab2/4a4/4b4/p3C4/c1p1P3p/3N1R2P/P2r1p3/1R3C2B/4AK2c/3A3r1 b - - 11 11
				if((StoY(k) == 0x1 && StoY(p) >= 0x3) || (StoY(k) == 0x8 && StoY(p) <= 0x6)){
					if(shi == 2){
						score  /= 2;
					}
				}
				// fen 4k1br1/2R1a4/3ab4/2N3R1C/4p4/1N2c1B2/6n1P/4B1p2/3KA4/r4A3 w - - 0 0
				//如果将，兵在另一边，且有２个仕
				if(shi >= 1){
					if(    (StoX(k) == 0x3 && StoX(p) > 0x4) 
						|| (StoX(k) == 0x5 && StoX(p) < 0x4)){
							if(offx >= 3){
								score /= 4;
							}
							if(offx == 2){
								score /= 2;
							}
					}
				}
				// fen 9/4k4/3a5/1P7/9/3N1R3/4r4/4Bn3/9/2BK1p3 w - - 0 0
				if(StoY(p) == 0x0 || StoY(p) == 0x9){
					score = 0;
					//if(k == 0x03 || k == 0x05 || k == 0x54 || k == 0x56){
					//	if(p == 0x03 || p == 0x05 || p == 0x54 || p == 0x56){
					//		score = 1;
					//	}
					//}
					if(abs(StoX(p) - 0x4) <= 1){
						score = 1;
					}
				}
				if(score > MAX_PrePawnAttKingMul_Safe){
					score = MAX_PrePawnAttKingMul_Safe;
				}

				// 如果兵能将军,至少加一分
				if(StoY(p) == StoY(k)){
					if(abs(StoX(p) - StoX(k)) == 2){
						score += 1;
					}
				}
				if(StoX(p) == StoX(k)){
					if(abs(StoY(p) - StoY(k)) == 2){
						if(StoY(k) <= 0x2 && StoY(p) >= StoY(k)){
							score += 1;
						}	
						if(StoY(k) >= 0x7 && StoY(p) <= StoY(k)){
							score += 1;
						}
					}
				}
				PrePawnAttKingMul_Safe[shi][p][k] = make_score(score,score*3/2);
			}
		}
	}
}




static void from50to90_OE(


	Score white90[90], 
	Score black90[90],
	const sint16 ope45[50],
	const sint16 end45[50],
	int mul_open,
	int mul_end, BOOL isNeg)
{
		int i;
		white90[0] = Score(0);
		black90[0] = Score(0);

		for(i = 0; i < 90; i++){

			int rad = 0;  //int rad = (r == 0)? 0 : (genrand_int32() % (r*2) - r);

			int mg = ope45[a90from50[i]] * mul_open / 100 + rad;
			int eg = end45[a90from50[i]] * mul_end  / 100 + rad;

			white90[i] = make_score(mg,eg);
			
			if(isNeg){
				black90[89-i] = Score(0) - white90[i];
			}
			else{
				black90[89-i] = white90[i];
			}
		}
}

bool Position::isXiangEye(Square k){

	if (   k == 0x0a || k == 0x0c || k == 0x0e || k == 0x10
		|| k == 0x1c || k == 0x1e || k == 0x20 || k == 0x22
		|| k == 0x37 || k == 0x39 || k == 0x3b || k == 0x3d
		|| k == 0x49 || k == 0x4b || k == 0x4d || k == 0x4f){
		return true;
	}
	else
		return false;
}


void Position::init(){
	
	RKISS rk;

	// init_zobrist 
	for (int j = 0; j < 16; j++)
		for (int k = 0; k < 90; k++)
			Zobrist::psq[j][k] = rk.rand<Key>();


	Zobrist::side       = rk.rand<Key>();
	Zobrist::exclusion  = rk.rand<Key>();


	//Key XiangEyeHash[90];      // 棋子在象眼上的HASH
	for (Square k = SQ_START; k < SQ_END90; k++){
		Zobrist::XiangEyeHash[k] = 0;
		if (isXiangEye(k)){
			Zobrist::XiangEyeHash[k] = rk.rand<Key>();
		}
	}

	////
	init_PrePawnAttKingMul_Safe();  // 兵能攻击将的能力 

	
	// 对方缺仕时兵的位置分 //point_B_01Shi_R_Pawn90[pnum++][yshi][pawn];
	from50to90_OE(point_B_01Shi_R_Pawn90[2], point_R_01Shi_B_Pawn90[2],  
		Open_2_Shi_Pawn45, End_2_Shi_Pawn45,  50,50,FALSE);

	from50to90_OE(point_B_01Shi_R_Pawn90[1], point_R_01Shi_B_Pawn90[1],  
		Open_1_Shi_Pawn45, End_1_Shi_Pawn45,  50,50,FALSE);

	from50to90_OE(point_B_01Shi_R_Pawn90[0], point_R_01Shi_B_Pawn90[0],  
		Open_0_Shi_Pawn45, End_0_Shi_Pawn45,  80,80,FALSE);

	from50to90_OE(psq[RKING],  psq[BKING],  
		OpeningKing45,    EndgameKing45,     100,100, TRUE); 

	from50to90_OE(psq[RSHI],   psq[BSHI],   
		OpeningShiXiang45,EndgameShiXiang45, 100,100, TRUE); 

	from50to90_OE(psq[RXIANG], psq[BXIANG], 
		OpeningShiXiang45,EndgameShiXiang45, 100,100, TRUE);

	from50to90_OE(psq[RMA],    psq[BMA],    
		OpeningMa45,      EndgameMa45,       100, 100, TRUE);

	from50to90_OE(psq[RPAO],   psq[BPAO],   
		OpeningPao45,     EndgamePao45,      100, 100, TRUE);

	from50to90_OE(psq[RCHE],   psq[BCHE],  
		OpeningChe45,     EndgameChe45,      100,100, TRUE);

	//from50to90_OE(psq[RPAWN],  psq[BPAWN],  
	//	OpeningPawn45,    EndgamePawn45,     85, 72, TRUE);

	from50to90_OE(psq[RPAWN],  psq[BPAWN],  
		OpeningPawn45,    EndgamePawn45,    100, 100, TRUE);

}

/// Position::compute_key() computes the hash key of the position. The hash
/// key is usually updated incrementally as moves are made and unmade, the
/// compute_key() function is only used when a new position is set up, and
/// to verify the correctness of the hash key when running in debug mode.

Key Position::compute_key() const {

	Key result = Key(0ULL);

	for(Square s = SQ_START; s < SQ_END90; s++){
		if (!square_is_empty(s)){
			result ^= Zobrist::psq[piece_on(s)][s];
		}
	}

	if (side_to_move() == BLACK)
		result ^= Zobrist::side;

	return result;
}


Key Position::compute_pawn_key() const {

	Key result = Key(0ULL);

	for(Square s = SQ_START; s < SQ_END90; s++){
		Piece p = piece_on(s);
		if (isPawnShiXiangKing(p)){               // 兵仕相
			result ^= Zobrist::psq[p][s];
		}
		if (isXiangEye(s) && !square_is_empty(s)){ // 相眼，也放到key中
			result ^= Zobrist::XiangEyeHash[s];
		}
	}

	return result;
}


/// Position::compute_value() compute the incremental scores for the middle
/// game and the endgame. These functions are used to initialize the incremental
/// scores when a new position is set up, and to verify that the scores are correctly
/// updated by do_move and undo_move when the program is running in debug mode.
Score Position::compute_psq_value() const {

	Score result = SCORE_ZERO;

	for(Square s = SQ_START; s < SQ_END90; s++){
		if (!square_is_empty(s)){ // if (square_is_occupied(s)){
			result += psq[piece_on(s)][s];
		}
	}
	return result;
}


void Position::do_move(Move m, StateInfo& newSt, bool moveIsCheck, CheckInfo& ci) {

	//ASSERT(pos_is_ok());
	ASSERT(&newSt != st);
	ASSERT(is_ok(m));

	++nodes;
	Key k = st->key ^ Zobrist::side;

	// Copy some fields of old state to our new StateInfo object except the ones
	// which are going to be recalculated from scratch anyway, then switch our state
	// pointer to point to the new, ready to be updated, state.
	std::memcpy(&newSt, st, offsetof(StateInfo, key));
	newSt.previous = st;
	st = &newSt;	

	// Increment the 50 moves rule draw counter. Resetting it to zero in the
	// case of non-reversible moves is taken care of later.
	++gamePly;
	++st->rule50;
	++st->pliesFromNull;

	Color us = side_to_move();
	Color them = ~us;
	Square from = from_sq(m);
	Square to = to_sq(m);

	Piece piece = piece_on(from);
	Piece capture = piece_on(to);

	ASSERT(capture != RKING && capture != BKING);
	ASSERT(color_of(piece_on(from)) == us);
	ASSERT(color_of(piece_on(to)) == them || square_is_empty(to));

	// bitboard
	//byChessBB[COLOR_BY_SIDE[c]];
	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]], from);           // di == from
	set_bit(byChessBB[COLOR_BY_SIDE_ADD[us]], to);           // ai == to

	clear_bit(byChessBB[piece], from);  // di == from
	set_bit(byChessBB[piece], to);      // ai == to

	clear_bit(byWhiteBlack, from);      // di == from

	

	if (capture){
		//do_capture_move(key, capture, them, to, ep);

		clear_bit(byChessBB[capture], to);
		clear_bit(byChessBB[COLOR_BY_SIDE_ADD[them]], to);

		// piece count
		pieceCount[capture] --;

		// piecelist
		pieceList[capture][index[to]] = pieceList[capture][pieceCount[capture]];

		// index
		index[pieceList[capture][index[to]]] = index[to];

		// pMat
		st->pMat -= MatAddress[capture];

		// Update incremental scores
		st->psq -= psq[capture][to];  // 位置分

		// Update hash key
		k ^= Zobrist::psq[capture][to];

		// Update Pawn key
		if (isPawnShiXiangKing(capture)){
			st->pawnKey ^= Zobrist::psq[capture][to];
		}

		st->pawnKey ^= Zobrist::XiangEyeHash[to];

		// Reset rule 50 counter
		st->rule50 = 0;
	}
	else{
		set_bit(byWhiteBlack, to);
	}

	// Update hash key
	k ^= Zobrist::psq[piece][from] ^ Zobrist::psq[piece][to];

	// Clear 兵HASH的 XiangEyeHash
	st->pawnKey ^= Zobrist::XiangEyeHash[from] ^ Zobrist::XiangEyeHash[to]; 

	//// Prefetch TT access as soon as we know key is updated
	//prefetch((char*)TT.first_entry(k));

	b90[to] = piece;
	b90[from] = NO_PIECE;

	// pieceList
	pieceList[piece][index[from]] = to;

	// index
	index[to] = index[from];


	// If the moving piece is a pawn do some special extra work
	if (isPawnShiXiangKing(piece)){
		// Update pawn hash key
		st->pawnKey ^= Zobrist::psq[piece][from] ^ Zobrist::psq[piece][to];
	}


	// Update pawn hash key and prefetch access to pawnsTable
#ifndef OUTPUT_END_PV_POSITION
	prefetch(thisThread->pawnsTable[st->pawnKey]);
#endif
	//prefetch((char*)thisThread->materialTable.entries[st->materialKey]);

	// Update incremental scores
	st->psq += psq[piece][to] - psq[piece][from]; //pst_delta(piece, from, to);  // 位置分

	// Set capture piece
	st->capture = capture;

	// Update the key with the final value
	st->key = k;

	// 为重复检查做准备 连将，连捉
	st->m = m;
	st->mischeck = moveIsCheck;
	
	//st->mateThread = false;
	// Update checkers bitboard, piece must be already moved
	st->checkersBB = _mm_setzero_si128(); // EMPTYBB

	if (moveIsCheck){

		//board_display("checking!");
		// CheckInfo ci(*this);

		//////////////////////////////////////////////////////////////////////////		
		// Direct checks   直接将
		if (bit_is_set(ci.checkSq[piece], to)){
			set_bit(st->checkersBB, to);  // st->checkersBB = SetMaskBB[to];
		}
		//////////////////////////////////////////////////////////////////////////	
		// Discovery checks 抽将
		//if (m_have_bit(ci.dcCandidates) && bit_is_set(ci.dcCandidates, from)){
		if (bit_is_set(ci.dcCandidates, from)){
			// 
			if (bit_is_set(ChePseudoMask_FR[ci.ksq], from)){ // 走的棋子原来在对方的将十字上.
				// 1. 是车抽将.
				st->checkersBB = m_or(st->checkersBB,
					m_and(Rook_attacks_bb(ci.ksq),
					pieces(RCHE + COLOR_BY_SIDE_ADD[us])));
				// 2. 是炮抽将
				st->checkersBB = m_or(st->checkersBB,
					m_and(Pao_Eat_bb(ci.ksq),
					pieces(RPAO + COLOR_BY_SIDE_ADD[us])));
			}
			else{
				// 加入马抽将的情况  COLOR_BY_SIDE_ADD
				st->checkersBB = m_or(st->checkersBB,
					m_and(king_to_ma_attacks_bb(ci.ksq),
					pieces(RMA + COLOR_BY_SIDE_ADD[us])));
			}
		}
		//////////////////////////////////////////////////////////////////////////	
		// 还要加入炮的叠将哇. 加入炮的将军情况
		if (bit_is_set(ci.PaoNull, to)){
			// 加入所有的炮的将军的情况.			
			st->checkersBB = m_or(st->checkersBB,
				m_and(Pao_Eat_bb(ci.ksq),
				pieces(RPAO + COLOR_BY_SIDE_ADD[us])));
		}
		//////////////////////////////////////////////////////////////////////////	
		// 还要加入炮吃子将的情况
		if (type_of(piece) == PAO && capture != NO_PIECE
			&& bit_is_set(ChePseudoMask_FR[ci.ksq], from)){ // 走的棋子原来在对方的将十字上.			
			st->checkersBB = m_or(st->checkersBB,           // 2. 是炮抽将
				m_and(Pao_Eat_bb(ci.ksq),
				pieces(RPAO + COLOR_BY_SIDE_ADD[us])));
		}

#ifdef USE_SLOW_BOARD  
		if (!m_have_bit(st->checkersBB)) {
			board_display("check_error1");
		}
#endif  
	}

	// Finish
	sideToMove = ~sideToMove;

	ASSERT(pos_is_ok());
}


/// Position::undo_move() unmakes a move. When it returns, the position should
/// be restored to exactly the same state as before the move was made.

void Position::undo_move(Move m) {

	//ASSERT(pos_is_ok());
	ASSERT(is_ok(m));

	//gamePly--; 这个不用了. 
	sideToMove = ~sideToMove;

	Color us = side_to_move();
	Color them = ~us;
	Square from = from_sq(m);
	Square to = to_sq(m);

	Piece piece = piece_on(to);

	ASSERT(square_is_empty(from));
	ASSERT(color_of(piece_on(to)) == us);


	b90[from] = piece;
	b90[to] = NO_PIECE;

	// bitboard clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],from);           // di == from
	set_bit(byChessBB[COLOR_BY_SIDE_ADD[us]], from);
	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]], to);

	set_bit(byChessBB[piece], from);
	clear_bit(byChessBB[piece], to);

	set_bit(byWhiteBlack, from);        // occ 

	// Update piece list
	//piece list
	pieceList[piece][index[to]] = from;
	index[from] = index[to];

	Piece capture = st->capture;

	if (capture)  // 如果有吃子了. 
	{
		//Square capsq = to;

		ASSERT(capture != RKING && capture != BKING);
		ASSERT(square_is_empty(to));

		// bitboard
		set_bit(byChessBB[COLOR_BY_SIDE_ADD[them]], to);
		set_bit(byChessBB[capture], to);

		b90[to] = capture;  // 这个加上,安全些		

		// Update piece list, add a new captured piece in capsq square
		pieceList[capture][pieceCount[capture]] = to;
		index[to] = pieceCount[capture];

		// Update piece count
		pieceCount[capture]++;

	}
	else{
		clear_bit(byWhiteBlack, to);
	}

	// Finally point our state pointer back to the previous state
	st = st->previous;
	--gamePly;

	ASSERT(pos_is_ok());
}



/// Position::do(undo)_null_move() is used to do(undo) a "null move": It flips
/// the side to move without executing any move on the board.

void Position::do_null_move(StateInfo& newSt) {

	ASSERT(!in_check());
	ASSERT(&newSt != st);

	std::memcpy(&newSt, st, sizeof(StateInfo)); // Fully copy here
	newSt.previous = st;
	st = &newSt;

	st->key ^= Zobrist::side;
	prefetch(TT.first_entry(st->key));
	 
	st->mischeck = false;              // 连将检测

	++st->rule50;
	st->pliesFromNull = 0;

	sideToMove = ~sideToMove;

	assert(pos_is_ok());
}

void Position::undo_null_move() {

	ASSERT(!in_check());

	st = st->previous;
	sideToMove = ~sideToMove;
}


// Position::key_after() computes the new hash key after the given moven. Needed
// for speculative prefetch. It doesn't recognize special moves like castling,
// en-passant and promotions.
Key Position::key_after(Move m) const {

	//Color us = sideToMove;
	Square from = from_sq(m);
	Square to = to_sq(m);
	Piece pc = piece_on(from);
	Piece captured = piece_on(to);
	Key k = st->key ^ Zobrist::side;

	if (captured)
		k ^= Zobrist::psq[captured][to];

	return k ^ Zobrist::psq[pc][to] ^ Zobrist::psq[pc][from];
}


//Zobrist::psq[capture][to];


