#include "chess.h"
 
#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"
#include "eval_const_h.h"

int Point_StringScoreByChe[16];  // 车牵制马炮的得分

int Point_R_XianProtectPoint[16]; // 象保护自己棋子的得分
int Point_B_XianProtectPoint[16];

int Point_R_ShiProtectPoint[16];  // 仕保护自己棋子的得分
int Point_B_ShiProtectPoint[16];

int point_R_CheProtectPoint[16];  // 霸王车的分数
int point_B_CheProtectPoint[16];  

int Point_R_ma_Att_Score[16]; // 马保护自己棋子的得分
int Point_B_ma_Att_Score[16];

int Point_R_pawn_Att_Score[16]; // 兵保护自己棋子的得分
int Point_B_pawn_Att_Score[16];

int PAWN_NUM_OVER_RIVER_point[8];      //       point(t,t);

//fen 2b1k2r1/3Ra4/2c6/p3p1n1p/2pn5/8P/P2rP4/2N2R2N/4A4/2B1KAB2 w - - 0 
//这个牵制马在74分左右．
// ---------------------------------------------------------------------- 车牵制马炮
const static sint16 opening_stringbyche[16]  = { 
	0,
//  将	 仕	  相   马   车   炮	 兵   
	0,   0,   0,  16,  0,   0,   0,     // 红棋, 抽將
	0,
	0,   0,   0, -16,  0,  -0,   0,     // 黑棋
};
const static sint16 endgame_stringbyche[16]  = { 
	0,
//  将	 仕	  相   马   车   炮	  兵   
	0,   0,   0, 168,  0,  196,   0,     // 红棋, 抽將
	0,
	0,   0,   0,-168,  0, -196,   0,     // 黑棋
};
// ---------------------------------------------------------------------- 马保护自己的棋子
const static sint16 opening_Rche_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马   车    炮	   兵   
	16,  0,   0,   0,  16,   8,    0,     // 红棋, //因为马保马是双方的，所以得减半哇
	0,
	0,   0,   0,  16,   0,    0,   0,     // 黑棋
};


const static sint16 endgame_Rche_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马   车    炮	   兵   
	0,   8,   8,  12,  32,   16,   4,     // 红棋, 抽將
	0,
	0,   8,   8,  32,   0,   32,   16,     // 黑棋
};


const static sint16 opening_Rma_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马   车    炮	   兵   
	0,   8,   8,  12,  16,   16,   8,     // 红棋, //因为马保马是双方的，所以得减半哇
	0,
	0,  16,  16,  16,  32,   16,   8,     // 黑棋
};


const static sint16 endgame_Rma_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马   车    炮	   兵   
	0,   8,   8,  12,  16,   16,  16,     // 红棋, 抽將
	0,
	0,  16,  16,  16,  32,   16,   8,     // 黑棋
};

// ---------------------------------------------------------------------- 仕保护自己的棋子
const static sint16 opening_Rshi_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马   车    炮	   兵   
	0,   8,   0,  12,  16,   16,   0,     // 红棋,      // 因为仕保仕是双方的，所以得减半哇
	0,
	0,   0,   0,  32,  64,   32,   8,     // 黑棋
};

const static sint16 endgame_Rshi_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马    车    炮	   兵   
	0,   8,   0,  12,  16,   16,   0,     // 红棋, 抽將
	0,
	0,   0,   0,  32,  64,   32,   8,     // 黑棋
};

// ---------------------------------------------------------------------- 相
const static sint16 opening_Rxiang_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马   车    炮	   兵   
	0,   0,   8,  12,  16,   16,   16,     // 红棋, //因为相保相是双方的，所以得减半哇
	0,
	0,   0,   0,  32,  64,   32,   8,      // 黑棋
};

const static sint16 endgame_Rxiang_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马    车    炮	   兵   
	0,   0,   8,  12,  16,   16,   16,     // 红棋, 
	0,
	0,   0,   0,  32,  64,   32,   8,      // 黑棋
};

// ---------------------------------------------------------------------- 兵保护自己的棋子的得分
const static sint16 opening_Rpawn_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马    车    炮	   兵   
	0,   0,   0,  24,  16,   16,   16,      // 红棋, //因为相保相是双方的，所以得减半哇
	0,
	0,  24,  24,  32,  64,   32,   16,      // 黑棋
};


const static sint16 endgame_Rpawn_Att_Score[16]  = { 
	0,
//  将	 仕	  相   马    车    炮	   兵   
	0,   0,   0,  16,  16,   16,   16,     // 红棋, 
	0,
	0,  36,  24,  32,  64,   32,   16,      // 黑棋
};

// --------------------------------------------------------------------------------------
static void initPointbyOpenEnd(int PointArr[], const sint16 openArr[], const sint16 endArr[], bool isMirror){
	int i;
	for(i = 0; i < 16; i++){
		if(isMirror){
			PointArr[i] = point(openArr[revertChess[i]],endArr[revertChess[i]]);
		}
		else{
		    PointArr[i] = point(openArr[i],endArr[i]);
		}
	}
}

void eval_const_int(void){

	initPointbyOpenEnd(Point_StringScoreByChe,
		opening_stringbyche,endgame_stringbyche,FALSE);    // 车牵制

	//extern int point_R_CheProtectPoint[16];  // 霸王车的分数
	//extern int point_B_CheProtectPoint[16]; 

	initPointbyOpenEnd(point_R_CheProtectPoint,
		opening_Rche_Att_Score,endgame_Rche_Att_Score,FALSE);  // 红车保护自己的棋子
	initPointbyOpenEnd(point_B_CheProtectPoint,
		opening_Rche_Att_Score,endgame_Rche_Att_Score,TRUE);  // 黑车保护自己的棋子

	//initPointbyOpenEnd(point_B_CheProtectPoint,
	//	opening_Bche_Att_Score,endgame_Bche_Att_Score);  // 黑车保护自己的棋子

	initPointbyOpenEnd(Point_R_ma_Att_Score,
		opening_Rma_Att_Score,endgame_Rma_Att_Score,FALSE);  // 红马保护自己的棋子
	initPointbyOpenEnd(Point_B_ma_Att_Score,
		opening_Rma_Att_Score,endgame_Rma_Att_Score,TRUE);  // 黑马保护自己的棋子

	//initPointbyOpenEnd(Point_B_ma_Att_Score,
	//	opening_Bma_Att_Score,endgame_Bma_Att_Score);  // 黑马保护自己的棋子

	initPointbyOpenEnd(Point_R_XianProtectPoint,
		opening_Rxiang_Att_Score,endgame_Rxiang_Att_Score,FALSE);  // 红象保护自己的棋子
	initPointbyOpenEnd(Point_B_XianProtectPoint,
		opening_Rxiang_Att_Score,endgame_Rxiang_Att_Score,TRUE);  // 黑象保护自己的棋子

	//initPointbyOpenEnd(Point_B_XianProtectPoint,
	//	opening_Bxiang_Att_Score,endgame_Bxiang_Att_Score);  // 黑象保护自己的棋子

	initPointbyOpenEnd(Point_R_ShiProtectPoint,
		opening_Rshi_Att_Score,endgame_Rshi_Att_Score,FALSE);  // 红仕保护自己的棋子

	initPointbyOpenEnd(Point_B_ShiProtectPoint,
		opening_Rshi_Att_Score,endgame_Rshi_Att_Score,TRUE);  // 黑仕保护自己的棋子

	//initPointbyOpenEnd(Point_B_ShiProtectPoint,
	//	opening_Bshi_Att_Score,endgame_Bshi_Att_Score);  // 黑仕保护自己的棋子

	initPointbyOpenEnd(Point_R_pawn_Att_Score,
		opening_Rpawn_Att_Score,endgame_Rpawn_Att_Score,FALSE);  // 红卒保护自己的棋子
	initPointbyOpenEnd(Point_B_pawn_Att_Score,
		opening_Rpawn_Att_Score,endgame_Rpawn_Att_Score,TRUE);  // 黑卒保护自己的棋子

	//initPointbyOpenEnd(Point_B_pawn_Att_Score,
	//	opening_Bpawn_Att_Score,endgame_Bpawn_Att_Score);  // 黑卒保护自己的棋子

	//const static sint16 PAWN_NUM_OVER_RIVER[6] =   {0, 16, 96, 108, 116, 124};
	//extern int PAWN_NUM_OVER_RIVER_point[16];      //       point(t,t);
	for(int i = 0; i < 6; i++){
		PAWN_NUM_OVER_RIVER_point[i] = point(PAWN_NUM_OVER_RIVER[i],PAWN_NUM_OVER_RIVER[i]);
	}
}

#endif

