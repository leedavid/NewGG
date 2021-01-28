#include "chess.h"

////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>

#include "s_bitcount.h"
#include "s_mersenne.h"
#include "s_movegen.h"
#include "s_movepick.h"
#include "s_position.h"
#include "s_psqtab.h"
#include "s_san.h"
#include "s_tt.h"
#include "s_ucioption.h"

using std::string;


const sint16 Open_2_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        //3
	0,   0,   0,   0,    0,        //4
	0,   0,   0,   0,    0,        //5
	0,   0,   0,   0,    0,        //6
	0,   0,   0,   0,    0,       //7
	0,   0,   0,   0,    0,        //8
	0,   0,   0,   0,    0,        //9
	0,   0,   0,   0,    0,        //a
	0,   0,   0,   0,    0,        //b
	0,   0,   0,   0,    0,        //c
};

const sint16 End_2_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        //3
	0,   0,   0,   0,    0,        //4
	0,   0,   0,   0,    0,        //5
	0,   0,   0,   0,    0,        //6
	0,   0,   0,   0,    0,       //7
	0,   0,   0,   0,    0,        //8
	0,   0,   0,   0,    0,        //9
	0,   0,   0,   0,    0,        //a
	0,   0,   0,   0,    0,        //b
	0,   0,   0,   0,    0,        //c
};

// //1Shi_B_Pawn256[256];  //只有一个士后,对方兵的加分
const sint16 Open_1_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        //3
	15,  15,  48,  64,   96,        //4
	15,  15,  32,  48,   64,        //5
	15,  15,  30,  30,   30,        //6
	15,  15,  15,  15,   15,        //7
	0,   0,   0,   0,    0,        //8
	0,   0,   0,   0,    0,        //9
	0,   0,   0,   0,    0,        //a
	0,   0,   0,   0,    0,        //b
	0,   0,   0,   0,    0,        //c
};

// //1Shi_B_Pawn256[256];  //只有一个士后,对方兵的加分
const sint16 End_1_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        //3
	15,  15,  48,  64,   96,        //4
	15,  15,  32,  48,   64,        //5
	15,  15,  30,  30,   30,        //6
	15,  15,  15,  15,   15,        //7
	0,   0,   0,   0,    0,        //8
	0,   0,   0,   0,    0,        //9
	0,   0,   0,   0,    0,        //a
	0,   0,   0,   0,    0,        //b
	0,   0,   0,   0,    0,        //c
};

const sint16 Open_0_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        //3
	46,  62,  80,  96,  118,        //4
	38,  46,  62,  80,   96,        //5
	30,  30,  48,  48,   60,        //6
	30,  30,  30,  30,   30,        //7
	16,   0,  16,   0,   16,        //8
	0,   0,   0,   0,    0,        //9
	0,   0,   0,   0,    0,        //a
	0,   0,   0,   0,    0,        //b
	0,   0,   0,   0,    0,        //c
};

const sint16 End_0_Shi_Pawn45[50] = {
	0,   0,   0,   0,    0,        //3
	46,  62,  80,  96,  118,        //4
	38,  46,  62,  80,   96,        //5
	30,  30,  48,  48,   60,        //6
	30,  30,  30,  30,   30,        //7
	16,   0,  16,   0,   16,        //8
	0,   0,   0,   0,    0,        //9
	0,   0,   0,   0,    0,        //a
	0,   0,   0,   0,    0,        //b
	0,   0,   0,   0,    0,        //c
};

const sint16 OpeningKing45[50] = {  //开局的将的位置分
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0, -115, -125,
	0,    0,   0, -65,   -45,
	0,    0,   0, -25,    0,
};

const sint16 EndgameKing45[50] = {
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,   0,    0,
	0,    0,   0,  -10,   5,
	0,    0,   0,  -5,   -5,
	0,    0,   0,   0,    0,
};

const sint16 OpeningPawn45[50] = {	//奇兵的开局的兵
	-60,  -50, -40,  -30,  -55,
	80,  140, 155,  180,  270,
	67,  110, 135,  160,  190,
	65,   80, 115,  125,  145,
	45,   60,  75,   80,   85,
	5,    0,   24,   0,    15,
	0,    0,   5,    0,    10,
	0,    0,   0,    0,     0,
	0,    0,   0,    0,     0,
	0,    0,   0,    0,     0,
};

//const sint16 EndgamePawn45[50] = {	//奇兵的残局的兵
//   -60,  -50, -40,  -30,  -55,
//    76,   95, 115,  125,  145,
//    67,   85, 105,  115,  125,
//    67,   70,  80,   85,   95,
//    55,   60,  65,   70,   75,
//    15,   0,   36,   0,    25,
//    5,    0,   10,   0,    15,
//    0,    0,   0,    0,     0,
//    0,    0,   0,    0,     0,
//    0,    0,   0,    0,     0,
//};
//没有过河的兵要降分，残局时．
//fen 3k1ab2/3n5/4ba3/3PC3p/p1p6/6B2/3C4c/4B4/3NA4/3AK2c1 w
const sint16 EndgamePawn45[50] = {	//奇兵的残局的兵
	-60,  -50, -40,  -30,  -55,
	76,   95, 115,  125,  145,
	67,   85, 105,  115,  125,
	67,   70,  80,   85,   95,
	55,   60,  65,   70,   75,
	15,   0,   36,   0,    35,
	5,    0,   10,   0,    25,
	0,    0,   0,    0,     0,
	0,    0,   0,    0,     0,
};

const sint16 OpeningShiXiang45[50] = {
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,  -8,   0,    0,
	0,   0,   0,   0,    0,
  -16,   0,   0,   0,   12,
	0,   0,   0,   0,   16,
	0,   0,   0,   0,    0,
};

const sint16 EndgameShiXiang45[50] = {
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   0,   0,    0,
	0,   0,   8,   0,    0,
	0,   0,   0,   0,    0,
   -8,   0,   0,   8,    8,
	0,   0,   0,   0,    4,
	0,   0,   8,   0,    0,
};

const sint16 OpeningPao45[50] = {	//奇兵的开局的炮
	85,  70,  60,  55,  40,
	65,  75,  50,  50,  40,
	65,  75,  30,  50,  50,
	65,  80,  80,  75,  80,
	65,  80,  75,  72,  80,
	56,  72,  68,  75,  85,
	65,  85,  80,  75,  95,
	80,  88,  95, 105, 100,
	80,  90, 110,  95,  90,
	30,  80, 105,  95,  65,
};

const sint16 EndgamePao45[50] = {
	65,  65,  65,  65,  65,
	65,  65,  65,  65,  65,
	65,  65,  65,  65,  65,
	65,  65,  65,  65,  65,
	65,  65,  65,  65,  65,
	65,  65,  65,  65,  65,
	65,  65,  65,  65,  75,
	75,  95,  95, 110,  95,
	85,  95,  95,  95,  85,
	70,  75,  95, 105,  75,
};

//const sint16 CheMen45[50] = {
//	96, 108, 118, 128,  0,
//    80, 80,   80, 168,  0,
//    80, 80,   80, 128,  0,
//    98,108,  118, 138,  0,
//    80, 80,   80, 128,  0,
//    80, 80,   80, 118,  0,
//    80, 80,   80, 108,  0,
//    80, 80,   80, 108,  0,
//    80, 80,   80, 108,  0,
//    80, 80,   80, 108,  0,
//};

//残局马在家要好一些
const sint16 EndgameMa45[50] = {
	48,  45,  55,  60,   25,
	62,  55,  88,  70,   59,
	75,  80,  75,  85,   90,
	39,  84,  93,  88,   95,
	43,  82,  92,  95,   84,
	33,  54,  88,  83,   87,
	39,  49,  59,  56,   83,
	16,  44,  58,  66,   45,
	-10, 16,  24,  16,  -65,
	-30, -17, 32,  25,  -55,
};

const sint16 OpeningMa45[50] = {	  //奇兵的马
	48,  35,  55,  60,   35,
	72,  75,  88,  70,   59,
	95,  96,  85,  96,  110,
	39, 104,  93, 108,  105,
	63,  82,  92, 105,  114,
	53,  74, 100,  83,  107,
	39,  49,  59,  56,   83,
	38,  44,  68,  60,   65,
	-10,   5, 16,   8,  -65,
	-30, -17,  18, -5,  -55,
};

const sint16 EndgameChe45[50] = {	//奇兵的车
	44,  69,  54, 104,   89,
	64,  79,  74,  99,  112,
	54,  74,  54, 104,  109,
	84,  94,  99, 117,  119,
	74,  84,  89, 107,  109,
	79,  89,  94, 112,  114,
	64,  74,  79,  97,   99,
	39,  74,  59,  92,   64,
	39,  64,  59,  62,   13,
	9,  64,  54,  87,  -30,
};

const sint16 OpeningChe45[50] = {
	44,  69,  54, 104,   68,
	64,  79,  74,  99,  112,
	54,  74,  54, 104,  109,
	84,  94,  99, 117,  119,
	74,  84,  89, 107,  109,
	79,  89,  94, 112,  114,
	64,  74,  79,  97,   99,
	39,  74,  59,  92,   64,
	39,  64,  59,  62,   13,
	9,  64,  54,  87,  -30,
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
                //fen 5k3/4P4/9/5c1r1/2b2R3/9/9/3A1A3/3p5/5K3 w - - 151 151
				//if(shi == 0 && k == 0x05 && p ==0x0d){
				//	shi = shi;
				//}

				int score = 0;
				int offx = ABS(StoX(k) - StoX(p));
				int offy = ABS(StoY(k) - StoY(p));
				if(offx <= 4 && offy <= 4){ // 最少要在3步内才有威胁哇

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
						if(ABS(StoX(p) - StoX(k)) <= 1){
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
				//fen 3k1ab2/4a4/4b4/p3C4/c1p1P3p/3N1R2P/P2r1p3/1R3C2B/4AK2c/3A3r1 b - - 11 11
				if((StoY(k) == 0x1 && StoY(p) >= 0x3) || (StoY(k) == 0x8 && StoY(p) <= 0x6)){
					if(shi == 2){
						score  /= 2;
					}
				}
				//fen 4k1br1/2R1a4/3ab4/2N3R1C/4p4/1N2c1B2/6n1P/4B1p2/3KA4/r4A3 w - - 0 0
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
				//fen 9/4k4/3a5/1P7/9/3N1R3/4r4/4Bn3/9/2BK1p3 w - - 0 0
				if(StoY(p) == 0x0 || StoY(p) == 0x9){
					score = 0;
					if(k == 0x03 || k == 0x05 || k == 0x54 || k == 0x56){
						if(p == 0x03 || p == 0x05 || p == 0x54 || p == 0x56){
							score = 1;
						}
					}
				}
				if(score > MAX_PrePawnAttKingMul_Safe){
					score = MAX_PrePawnAttKingMul_Safe;
				}

				// 如果兵能将军,至少加一分
				if(StoY(p) == StoY(k)){
					if(ABS(StoX(p) - StoX(k)) == 2){
						score += 1;
					}
				}
				if(StoX(p) == StoX(k)){
					if(ABS(StoY(p) - StoY(k)) == 2){
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


const static uint8 a90from50[90] = {
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

static void from50to90_OE(
	Score white90[90], 
	Score black90[90],
	const sint16 ope45[50],
	const sint16 end45[50],
	int mul_open,
	int mul_end,
	BOOL isNeg){
		int i;
		white90[0] = Score(0);
		black90[0] = Score(0);

		int r = get_option_value_int("Randomness"); // 加一些随机分在里面. 

		for(i = 0; i < 90; i++){

			int rad = (r == 0)? 0 : (genrand_int32() % (r*2) - r);

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



/// Position::init_piece_square_tables() initializes the piece square tables.
/// This is a two-step operation:  First, the white halves of the tables are
/// copied from the MgPST[][] and EgPST[][] arrays, with a small random number
/// added to each entry if the "Randomness" UCI parameter is non-zero.
/// Second, the black halves of the tables are initialized by mirroring
/// and changing the sign of the corresponding white scores.
/// 位置分
void Position::init_piece_square_tables() {

	//int r = get_option_value_int("Randomness"), i; // 加一些随机分在里面. 


	//for (Square s = SQ_A1; s <= SQ_H8; s++){
	//	for (Piece p = WP; p <= WK; p++)
	//	{
	//		i = (r == 0)? 0 : (genrand_int32() % (r*2) - r);
	//		PieceSquareTable[p][s] = make_score(MgPST[p][s] + i, EgPST[p][s] + i);
	//	}

	//	for (Square s = SQ_A1; s <= SQ_H8; s++){
	//		for (Piece p = BP; p <= BK; p++){
	//			PieceSquareTable[p][s] = -PieceSquareTable[p-8][flip_square(s)];
	//		}
	//	}
	//}

	//
	init_PrePawnAttKingMul_Safe();  // 兵能攻击将的能力 

	from50to90_OE(point_B_01Shi_R_Pawn90_My_CheOpen, point_R_01Shi_B_Pawn90_My_CheOpen, 		
		Open_0_Shi_Pawn45, End_0_Shi_Pawn45,  80,60,FALSE);

	// 对方缺仕时兵的位置分 //point_B_01Shi_R_Pawn90[pnum++][yshi][pawn];
	from50to90_OE(point_B_01Shi_R_Pawn90[2], point_R_01Shi_B_Pawn90[2],  
		Open_2_Shi_Pawn45, End_2_Shi_Pawn45,  60,60,FALSE);

	from50to90_OE(point_B_01Shi_R_Pawn90[1], point_R_01Shi_B_Pawn90[1],  
		Open_1_Shi_Pawn45, End_1_Shi_Pawn45,  60,60,FALSE);

	from50to90_OE(point_B_01Shi_R_Pawn90[0], point_R_01Shi_B_Pawn90[0],  
		Open_0_Shi_Pawn45, End_0_Shi_Pawn45,  80,80,FALSE);

	from50to90_OE(PieceSquareTable[RKING],  PieceSquareTable[BKING],  
		OpeningKing45,    EndgameKing45,     100,100, TRUE); 

	from50to90_OE(PieceSquareTable[RSHI],   PieceSquareTable[BSHI],   
		OpeningShiXiang45,EndgameShiXiang45, 100,100, TRUE); 

	from50to90_OE(PieceSquareTable[RXIANG], PieceSquareTable[BXIANG], 
		OpeningShiXiang45,EndgameShiXiang45, 100,140, TRUE);

	from50to90_OE(PieceSquareTable[RMA],    PieceSquareTable[BMA],    
		OpeningMa45,      EndgameMa45,       100, 100, TRUE);

	from50to90_OE(PieceSquareTable[RPAO],   PieceSquareTable[BPAO],   
		OpeningPao45,     EndgamePao45,      100, 80, TRUE);

	from50to90_OE(PieceSquareTable[RCHE],   PieceSquareTable[BCHE],  
		OpeningChe45,     EndgameChe45,      100,100, TRUE);

	from50to90_OE(PieceSquareTable[RPAWN],  PieceSquareTable[BPAWN],  
		OpeningPawn45,    EndgamePawn45,     80, 68, TRUE);

	//for(int i = 0; i < 90; i++){
	//	/*if(i == 0x26 || i == 0x2d || i == 0x2c){*/
	//		Score res = PieceSquareTable[RPAWN][i];
	//		std::cout << "\nmg = " << mg_value(res) << "eg = " << eg_value(res) << std::endl;
	//	//}
	//}

}

