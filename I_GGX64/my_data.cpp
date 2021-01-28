
#include "chess.h"




MARR_t *MARR;
premat_t PreMatInfo[6][6][3][3][3][3][3][3];
int      MatAddress[16];

//#define maleg(from,to) _MaLegTable[from][to]
uint8  _MaLegTable[90][90];                 //
Score  SafetyTable[TOTAL_SAFE_POINT];                  //安全分
uint8  KposSafe[90];

TCHAR installDir[512];			   //软件运行目录
#ifdef  USE_LOG_FILE
TCHAR  log_path[512];
FILE*   llog_file;
#endif

#ifdef USE_RPPAWN_GOOD_MOVE
Bitboard RPawnGoodMove[90];     // 只有向中间走的步是好步.
Bitboard BPawnGoodMove[90];
#endif


Bitboard PaoCanAttKing[90];     // 判断一下炮能来能

Score PrePawnAttKingMul_Safe[3][90][90]; // 兵能攻击将的能力 
Score point_R_01Shi_B_Pawn90[3][90];           // 对方缺仕时兵的位置分
Score point_B_01Shi_R_Pawn90[3][90];

bool MustOuPutEvalInf;

void (*funMat[26244])	(typePOS &board, EvalInfo &ei);  //用来评估的函数指针

