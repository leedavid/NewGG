#pragma once

//#define USE_OPENBOOK

#ifdef USE_OPENBOOK

#pragma comment(lib, "libdb62.lib")
#include "db.h"    
#include "AtlBase.h"
#include "AtlConv.h"

//#include "windows.h"
//#include <stdlib.h>
//#include <tchar.h>
//#include <cmath>
//#include <vector>
//#include <deque>
//#include <map>
//#include <string>
//#include <sstream>
//#include <iomanip>
//#include <algorithm>
//#include <tuple>
//
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "comctl32.lib")
//#pragma comment(lib, "Ws2_32.lib")
//#pragma comment(lib, "Wininet.lib")

struct book_face_info_t {
	sint8 result;         // 2,1,0,-1,-2;
	uint8 dummy1;         // 棋步，最大２５５       
	uint8 dummy2;         // 比重，０～１００％
	uint8 isuse;          // 是不是允许使用本棋步
};

struct book_face_t {
	uint8  f33[33];
	book_face_info_t info[1];
};

//棋库得分
typedef enum {
	BOOK_VERY_BAD   = -2,
	BOOK_LIT_BAD    = -1,
	BOOK_BALANCE    = 0,
	BOOK_LIT_GOOD   = 1,
	BOOK_VERY_GOOD  = 2,
	BOOK_NOT_RESULT = 8
}Book_Sc;

#define D8none          0x7e  //33+90
#define D8int           0x7e7e7e7e


typedef struct stock_dbs_t {

	DB_ENV *Env;

	DB *book;			//这是当前使用的的book;
	//DB *back_db;           //这个是系统缺省的book;

	char *book_db_name;
	//char *good_db_name;

	BOOL Book_Init_Ok;

} STOCK_DBS;

extern STOCK_DBS    MST[1];

extern int BD_initEnv(STOCK_DBS* mst);     //初始化环境
extern void BerKeley_DB_EXIT(STOCK_DBS *mst);

//extern int  GetPosBookScoreByAllNextPos(DB *db);
extern int  bk_GetBookInfo(book_face_t* bft, DB *db);

extern void GetMirrorOnlyB33(Color sideToMove, Piece b90[90], uint8 b33[33], Move m);
extern int GetValByBookFaceInfo(book_face_info_t *pFinfo, Color side);

extern void LogOut(TCHAR* data);
extern void LogOuts(char* data);

#endif

