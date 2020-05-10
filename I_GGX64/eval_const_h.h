#ifndef MY_EVAL_CONST_H_IPP
#define MY_EVAL_CONST_H_IPP
#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else

#ifdef NDEBUG
#else
#define DEBUG_EVAL_OPP_SIDE_IS_SAME
#endif

#define Point_PaoThree(t) point((t)*2/2,(t)*3/2)

#define Che_Ding_ByPao    point(32,-64)
//
//const static int MidgameRookMobilityBonus[] = {                  // 车的移动性奖励.
//	//0    1    2    3    4   5    6   7   8   9
//	-80, -64, -48, -32, -16, -8,   0,  1,  2,  3,
//	//10, 11,  12,  13,  14, 15,  16, 17, 18,  19
//	4,   5,   6,   7,   8,  9,  10, 11, 12,  13 
//	//const int ROOK_RANK_MOB_BONUS[12]  = {-38,-18,-18,-18, -18,  0,  0,  0,  0,  0,  0,  0,}; 
//	//const int ROOK_FILE_MOB_BONUS[12]  = {-64,-44,-44,-44, -24,  0,  0,  0,  0,  0,  0,  0,};
//};

const int r_CheMove[]  = {
	(((-48) << 16) + (-28)),     //-38,
	(((-18) << 16) + (-18)),     //-18,
	(((-18) << 16) + (-18)),     //-18,
	(((-18) << 16) + (-18)),     //-18,
	(((-18) << 16) + (-18)),     //-18, 
	0, 
	0, 
	0, 
	0,
	0,
	0,
	0,}; 
const int f_CheMove[]  = {
	(((-64) << 16) + (-64)),     //-64,
	(((-44) << 16) + (-44)),     //-44,
	(((-44) << 16) + (-44)),     //-44,
	(((-44) << 16) + (-44)),     //-44, 
	(((-24) << 16) + (-24)),     //-24,
	0, 
	0,
	0,
	0,
	0,
	0, 
	0,};

//r_CheMove ljh01048

const static int TwoCheFreeCheck[] = {
	//point(0,0), point(0,0), point(64,512)
	(((0) << 16) + (0)),     // 0             // Y 方向双车错杀
	(((0) << 16) + (0)),     // 1
	(((0) << 16) + (0)),     // 2
	(((16) << 16) + (64)),   // 3
	(((32) << 16) + (378)),  // 4
	(((32) << 16) + (378)),   // 5
	(((32) << 16) + (378)),   // 6
	(((32) << 16) + (378)),   // 7
	(((32) << 16) + (378)),   // 8
	(((32) << 16) + (378)),   // 9
	(((32) << 16) + (378)),   // 10
	(((32) << 16) + (378)),   // 11
	(((32) << 16) + (378)),   // 12
};

//const static int MaControlByPawn[] = {
//	(((0) << 16) +  (0)),    // 0             // Y 方向双车错杀
//	(((36) << 16) + (36)),    // 1
//	(((48) << 16) + (48)),    // 2
//	(((48) << 16) + (48)),    // 3
//	(((48) << 16) + (48)),    // 4
//	(((48) << 16) + (48)),    // 5
//	(((48) << 16) + (48)),    // 6
//	(((48) << 16) + (48)),    // 7
//	(((48) << 16) + (48)),    // 8
//};

const static int MaControlByPawn = (((64) << 16) + (48));

//LackShiAttackByChePoint

const static int ChefreeCheckPointY[] = {
 // 00 01 02 03 04 05 06 07 08
	 0, 2, 4, 8,16,20,20,20,20,20,20,20,20
};
const static int ChefreeCheckPointX[] = {
// 00 01 02 03 04 05 06 07 08
	0, 2, 4, 5, 8, 10,12,12,12,12,12,12,12
};


#define Point_MaMob(t)  point((t*2/3),(t*2/2))
const __int16 MaMoveAddNoProtect[12]   =  {-64, -24,  8,  8,  8,  8,  8, 8, 8, 8,  8,  8 };
const __int16 PAWN_NUM_OVER_RIVER[6]   =  { 0, 16, 64,  80, 116, 124};
extern int PAWN_NUM_OVER_RIVER_point[8];      //       point(t,t);

extern int Point_StringScoreByChe[16];    // 车牵制自己的棋子的得分

extern int Point_R_XianProtectPoint[16];  // 相保护自己棋子的得分
extern int Point_B_XianProtectPoint[16];

extern int Point_R_ma_Att_Score[16];    // 马保护自己棋子的得分
extern int Point_B_ma_Att_Score[16];

extern int point_R_CheProtectPoint[16];  // 霸王车的分数
extern int point_B_CheProtectPoint[16];  

extern int Point_R_ShiProtectPoint[16]; // 仕保护自己棋子的得分
extern int Point_B_ShiProtectPoint[16];

extern int Point_R_pawn_Att_Score[16];  // 卒保护自己棋子的得分
extern int Point_B_pawn_Att_Score[16];

static const int PawnNotOnSameSide[] = {
	(((8) << 16)  + (16)),     // 0  
	(((16) << 16) + (32)),     // 0  
	(((32) << 16) + (64)),     // 0  
};


static const int my_che_open_score = (((32) << 16)  + (32));


#define CHE_OPEN_SUB_LINE                    3
// ===================================================================
// below is safe point
//#define CheAttackKingZone         			  8
#define WoXinMaAttackKingZone                24
#define WoXinPaoAttackKingZone               24

#define CheAttWeight                         5
#define PaoAttWeight                         3
#define PawnAttWeight                        5
#define MaAttWeight                          6

#define Rook_CanNotMove_Att                  5

#define PaoCan_Eat_Check                      3     //炮能吃子将.
#define PaoCan_Safe_Eat_Check                 4    
#define PaoCan_Direct_Check                   3     //炮直接将.
#define PaoCan_Safe_Direct_Check              3     //炮直接将.
#define PaoCan_TwoPao_Check                   3     //炮能垒将

#define KongPao_kingAdjacentZoneAttacksCount  2

#define Ma_KongPao_Check                      6     // 马到空炮将军
 
#define PaoCanAttackPoint                     4
#define PaoGuardtheKingOut                    3     //

#define PaoInPlaceMustSub                     6

#define TwoPaoAt_SameFile_Sub                 6

#define MaCanCHeckPoint                       8 
#define MaCanPaoNullCHeckPoint                8

#define CheCanPaoNullCHeckPoint               6   // 车能垒将.

//#define Pawn_Can_Check_Ponit                  5

#define Pawn_Is_Bad                           4

#define MaCanAttackPoint                      3

#define CheOpenAtt                            6       // 车已开放后的攻击能力
#define CheCanCheck                           2
#define RookSafeCheckBonus                    4       //对方的车能自由将


#define Other_Che_Can_Not_back                4       //对方的车不能回家守卫
#define King_CheSameLineAtt                   6       //将兵一线的得分


#define MaSafeCheckBonus                      6       //对方的马能自由将

//#define Ma_at_Mid_must_SUB_Point            8      //马在中间,要减一下,因为算二边有马了
#define Ma_Not_Good_Move_to_Attack            4      //马没有好的进攻步了
//#define Che_at_Mid_Must_SuB_Point           10
#define Che_At_mid_contor_King                8




#define KingCanNotBackToBottom 2
#define KingCanNotBackToMid    2

#define Y_HavePao_Protect      6
#define X_Have_Che_Protect     5
#define X_Have_Pao_Protect     4

const int att_黑车_红马_红帅_string = 4; 
const int att_黑炮_红马_红帅_string = 6;
const int att_黑马_红马_红帅_string = 8;

const int att_黑车_红炮_红帅_string = 3;
const int att_黑炮_红炮_红帅_string = 3;
const int att_黑马_红炮_红帅_string = 8;

const int att_黑车_红车_红帅_string = 2;
const int att_黑炮_红车_红帅_string = 8;
const int att_黑马_红车_红帅_string = 12;

const int att_黑车_红相_红帅_string = 4;
const int att_黑炮_红相_红帅_string = 1;
const int att_黑马_红相_红帅_string = 4;

const int att_黑车_红仕_红帅_string = 4;
const int att_黑炮_红仕_红帅_string = 1;
const int att_黑马_红仕_红帅_string = 4;

// ==========================================================
const int att_黑车_黑卒_红帅_zhou   = 6;
const int att_黑炮_黑卒_红帅_zhou   = 6;
const int att_黑马_黑卒_红帅_zhou   = 8;

const int att_黑车_黑车_红帅_zhou   =  0;
const int att_黑炮_黑车_红帅_zhou   = 14;
const int att_黑马_黑车_红帅_zhou   = 20;

const int att_黑车_黑马_红帅_zhou   = 16;
const int att_黑炮_黑马_红帅_zhou   = 12;
const int att_黑马_黑马_红帅_zhou   = 20;

const int att_黑车_黑炮_红帅_zhou   = 16;
const int att_黑炮_黑炮_红帅_zhou   = 16;
const int att_黑马_黑炮_红帅_zhou   = 16;

const int att_黑车_黑象_红帅_zhou   =  8;
const int att_黑炮_黑象_红帅_zhou   =  4;
const int att_黑马_黑象_红帅_zhou   =  0;

const int att_黑车_黑士_红帅_zhou   =  8;
const int att_黑炮_黑士_红帅_zhou   =  4;
const int att_黑马_黑士_红帅_zhou   =  0;

const int Zhou_Chess_Att_By_Other_sub = 4;

const int att_Ma_String[12]  = {
	//00 01 02 03 04 05 06 07 08 09 10 11
	   0, 8,10,12,14,15,16,17,18,19,20
};

// 再加些分,马牵制棋,对牵制的攻击再加些分
const int att_Ma_String_Valu[12] = {
	(((0)      << 16)   + (0)),                   // 00
	(((64)     << 16)   + (96)),                  // 01
	(((80)     << 16)   + (108)),                 // 02
	(((98)     << 16)   + (116)),                 // 03
	(((106)    << 16)   + (124)),                 // 04
	(((118)    << 16)   + (132)),                 // 05
	(((124)    << 16)   + (140)),                 // 06
	(((132)    << 16)   + (148)),                 // 07
	(((140)    << 16)   + (156)),                 // 08
	(((148)    << 16)   + (164)),                 // 09
	(((156)    << 16)   + (172)),                 // 10
	(((164)    << 16)   + (180)),                 // 11
};



const int att_Pao_String[]  = {
	//00 01 02 03 04 05 06 07 08 09 10 11 
	   0, 1, 3, 5, 7, 9,10,11,12,13,14,15
};
const int att_Che_String[]  = { // 12 够了
	//00 01 02 03 04 05 06 07 08 09 10 11
	   0, 0, 4, 6, 8,12,13,14,15,16,17,18
};

//与车的数量挂一下钩
const static __int8 KongPao_att_point[] = {
	12,        // 0 che
	16,        // 1 che
	36,        // 2 che
	0,         // 3 che 
};



const static __int8 KongPaoBetweenAttBYNum[] = {
	//0  1  2  3  4  5  6  7  8  9  10 11 12,13,14,15
	 -2, 0, 6, 8,12,17,18,19,20,21,22,23,24,25,26,27
};

#define MidPao_att_point      					 6
#define KongPao_that_Can_att_Line      			 6

//#define ChongPaoAttPoint                         6
#define Di_KongPao_that_Can_att_Line_point 		 4
#define Di_KongPao_att_point      				16
#define Di_Pao_att_point     					 8

#define Di_Pao_att_By_Other                      6
#define Kong_Di_Pao_att_By_Other                 8

#define TwoPaoAt_Same_Di_Line_Not_SameSide       8

#define Wo_Xing_Ma_att_point                    36
#define Ma_at_WoXing_point                       8

//#define Point_KKongPao_that_Can_att_Line(t)     point((t),(t)/8)

#define TiMen_King_att_point                          4
#define TiMen_King_att_Score                          point(0, 96);

#define TiMen_Che_att_point                           8
#define TiMen_Che_att_Score                           point(0, 96);

#define TiMen_Ma_att_point                            8
#define TiMen_Ma_att_Score                            point(8, 80);

#define TiMen_Pawn_att_point                          4
#define TiMen_Pawn_att_Score                          point(16,96);
// //////////////////////////////// safe score

#define KingNotOnBottom_Che_SameY_Sub                 point(64,32);

#define Only_1Che1PaoxPawn_Your_pawnAlr_Pao_Not_Home  point(32,64)
#define Only_1Che1PaoxPawn_Your_pawnCan_Pao_Not_Home  point(32,64)

#define Only_1Che1PaoxPawn_Your_pawnAlr_Pao_at_Home   point(16,32)
#define Only_1Che1PaoxPawn_Your_pawnCan_Pao_at_Home   point(16,32)

const int Only_1Che1PaoxPawn_Your_Ma_add[] = {
	(((128)  << 16)   + (160)),              // 00
	(((96)   << 16)   + (128)),              // 01
	(((64)   << 16)   + (96)),               // 02
	(((32)   << 16)   + (64)),               // 03
	(((0)    << 16)   + (0))                 // 04
};

//typedef enum
//{
//	EMPTY=0,  // 这个不用了
//	RKING=1,  RSHI=2, RXIANG=3, RMA=4, RCHE=5, RPAO=6, RPAWN=7,
//	_X_X =8,
//	BKING=9,  BSHI=10,BXIANG=11,BMA=12,BCHE=13,BPAO=14,BPAWN=15,   
//} enum_chess_piece;
#define SMG(mg,eg)     (((mg)<< 16)+(eg)) 
const int PAWN_ThreatBonus[8] = {
	0,
	// BKING=9,   BSHI=10,   BXIANG=11,  BMA=12,     BCHE=13,     BPAO=14,     BPAWN=15,  
	SMG(0,0),  SMG(32,64), SMG(32,64), SMG(56,80), SMG(86,118),  SMG(56,96),  SMG(0,32),
};

const int CHE_ThreatBonus[8] = {
	0,
  // BKING=9,   BSHI=10,   BXIANG=11,   BMA=12,     BCHE=13,     BPAO=14,     BPAWN=15,  
   SMG(0,0),  SMG(8,16), SMG(16,64),  SMG(0,128), SMG(0,0),   SMG(-16,128),  SMG(0,16),
};

const int MA_ThreatBonus[8] = {
	0,
// BKING=9,   BSHI=10,   BXIANG=11,  BMA=12,     BCHE=13,      BPAO=14,     BPAWN=15,  
   SMG(0,0),  SMG(16,64),SMG(16,64), SMG(16,64),  SMG(32,96), SMG(16,64),  SMG(0,16),
};

const int PAO_ThreatBonus[8] = {
	0,
//  BKING=9,   BSHI=10,   BXIANG=11,  BMA=12,     BCHE=13,      BPAO=14,     BPAWN=15,  
	SMG(0,0),  SMG(16,64),SMG(16,64), SMG(16,64),  SMG(32,96),  SMG(0,0),  SMG(0,16),
};

const int SHI_XIANG_ThreatBonus[8] = {
	0,
//  BKING=9,   BSHI=10,   BXIANG=11,  BMA=12,     BCHE=13,      BPAO=14,     BPAWN=15,  
	SMG(0,0),  SMG(0,0),  SMG(0,0), SMG(16,64),  SMG(32,96), SMG(16,64),  SMG(0,16),
};


#endif

#endif