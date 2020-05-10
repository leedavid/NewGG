#include "chess.h"

#include "chess.h"
#ifdef USE_STOCK_FISH_FILE
#else

#define xpoint(x,y) ( ( ( x ) << 16 ) + ( y ) )    // 将残局分与开局分全在一起
//statico_valu[16][90]

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
    0,    0,   0, -25,  -15,
    0,    0,   0, -15,  -10,
    0,    0,   0,  -5,    0,
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
    66,   95, 115,  125,  145,
    47,   85, 105,  115,  125,
    37,   50,  70,   85,   85,
    15,   30,  45,   50,   55,
  -10,    0,  -2,    0,    15,
  -20,    0,  -15,   0,    10,
    0,    0,   0,    0,     0,
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
     0,   0,  16,   0,    0,
     0,   0,   0,   0,    0,
   -32,   0,   0,   8,    8,
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
    80,  88, 100, 105, 100,
    80,  90, 110,  95,  90,
    30,  80, 105, 100,  75,
};

const sint16 EndgamePao45[50] = {
    65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,
    65,  65,  65,  65,  75,
    75,  95,  95, 110, 105,
    85,  95,  95, 115, 105,
    70,  75,  95, 110, 105,
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
    48,  65,  75,  80,   65,
    92,  95, 108,  90,   59,
    95, 100, 115, 120,  130,
    39, 104, 103, 108,  115,
    63,  82, 112, 115,  104,
    53,  74, 108,  83,  107,
    39,  49,  59,  56,   83,
    16,  44,  68,  86,   65,
   -10, -10, -10,   0,  -55,
   -30, -17,  18,  -5,  -55,
};

const sint16 OpeningMa45[50] = {	  //奇兵的马
    48,  65,  75,  80,   65,
    92,  95, 108,  90,   59,
    95, 100, 115, 120,  130,
    39, 124, 103, 138,  115,
    63,  82, 112, 115,  124,
    53,  74, 100,  83,  107,
    39,  49,  59,  56,   83,
    38,  44,  68,  60,   65,
   -10,   5,   0,   0,  -45,
   -30, -17,  18,  -5,  -55,
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

static void from50to90_OE(
	int white90[90], 
	int black90[90],
	const sint16 ope45[50],
	const sint16 end45[50],
	int mul_open,
	int mul_end,
	bool isNeg){
		int i;
		white90[0] = 0;
		black90[0] = 0;

		for(i = 0; i < 90; i++){
			white90[i] = xpoint(ope45[a90from50[i]] * mul_open/100,end45[a90from50[i]] * mul_end/100);
			if(isNeg){
				black90[89-i] = 0 - white90[i];
			}
			else{
				black90[89-i] = white90[i];
			}
		}
}




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

//extern sint32 R_01Shi_B_Pawn90[3][90];           // 对方缺仕时兵的位置分
//extern sint32 B_01Shi_R_Pawn90[3][90];
//
//extern sint32 R_01Shi_B_Pawn90_My_CheOpen[90];   // 对方无仕，我方车开放时兵的位置分
//extern sint32 B_01Shi_R_Pawn90_My_CheOpen[90];

//extern sint32 PrePawnAttKingMul_Safe[3][90][90]; // 兵能攻击将的能力 

#define  MAX_PrePawnAttKingMul_Safe 255
static void init_PrePawnAttKingMul_Safe(){

	static const uint8 const_PawnAtt_X[3][10] =  {
		// 0   1   2   3   4   5  6    7   8   9
		{ 16, 32, 28, 24, 20, 16, 12,  8,  4,  0,  },  //0个仕
		{  8, 16, 12,  8,  0,  0,  0,  0,  0, 0,  },  //1个仕
		{  4,  8,  4,  0,  0,  0,  0,  0,  0, 0,  },  //2个仕
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

				//if(shi == 2 && k == 0x4d && p ==0x3b){
				//	shi = shi;
				//}

				uint8 score = 0;
				int offx = ABS(StoX(k) - StoX(p));
				int offy = ABS(StoY(k) - StoY(p));
				if(offx <= 3 && offy <= 2){ // 最少要在3步内才有威胁哇
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
							score = score * 2;      //
						}
						if(StoX(p) == 0x4){
							score = score * 2;  //
						}
					}
				}
				if(StoX(p) == 0x4){  //如果兵在中线还要加一些
					score /= 2;  //因为兵在中间是二边算的								
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

				PrePawnAttKingMul_Safe[shi][p][k] = make_score(score,score);
			}
		}
	}
}


void
InitStatic ()
{
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

	//// 兵的个数要减一些。
	//static const sint16 NumOfPawnAdd[8] = {
	//	//1  2  3  4  5 6 
	//	128,32,16,16,8,4,0,
	//};
	//int valu,final;
	//int endgame,opening;
	//for(int p = 1; p <= 5; p++){
	//	for(int s = 0; s <= 2; s++){
	//		for(int sq = 0; sq < 90; sq++){

	//			if(s == 1 && p == 2 && 

	//			valu = point_B_01Shi_R_Pawn90[0][s][sq];
	//			endgame = (sint16)(valu & 0xffff);
	//			/*int opening = (endgame < 0) + (sint16)((valu >> 16) & 0xffff);*/
	//			opening = (sint16)((valu >> 16) & 0xffff);
	//			final = xpoint(opening * NumOfPawnAdd[p]/128,endgame * NumOfPawnAdd[p]/128);
	//			point_B_01Shi_R_Pawn90[p][s][sq] = final;

	//			valu = point_R_01Shi_B_Pawn90[0][s][sq];
	//			endgame = (sint16)(valu & 0xffff);
	//			/*int opening = (endgame < 0) + (sint16)((valu >> 16) & 0xffff);*/
	//			opening = (sint16)((valu >> 16) & 0xffff);
	//			final = xpoint(opening * NumOfPawnAdd[p]/128,endgame * NumOfPawnAdd[p]/128);
	//			point_R_01Shi_B_Pawn90[p][s][sq] = final;


	//		}
	//	}
	//}


	from50to90_OE(statico_valu[RKING],  statico_valu[BKING],  
		OpeningKing45,    EndgameKing45,     100,100, TRUE); 

	from50to90_OE(statico_valu[RSHI],   statico_valu[BSHI],   
		OpeningShiXiang45,EndgameShiXiang45, 100,100, TRUE); 

	from50to90_OE(statico_valu[RXIANG], statico_valu[BXIANG], 
		OpeningShiXiang45,EndgameShiXiang45, 100,140, TRUE);

	from50to90_OE(statico_valu[RMA],    statico_valu[BMA],    
		OpeningMa45,      EndgameMa45,       100, 80, TRUE);

	from50to90_OE(statico_valu[RPAO],   statico_valu[BPAO],   
		OpeningPao45,     EndgamePao45,      100, 80, TRUE);

	from50to90_OE(statico_valu[RCHE],   statico_valu[BCHE],  
		OpeningChe45,     EndgameChe45,      100,100, TRUE);

	from50to90_OE(statico_valu[RPAWN],  statico_valu[BPAWN],  
		OpeningPawn45,    EndgamePawn45,     80, 72, TRUE);



}

#endif
