#ifndef S_CHESS_H_INCLUDED
#define S_CHESS_H_INCLUDED

//#define USE_LOG_FILE
#define USE_32KEY_HASH
#define STORE_ALWAYS_CHECK                          // 保存常将的分数

#define MAX_CPUS                36                  // vary for increase 
#define USE_I7_MACHINE                              // _mm_popcnt_u64

//////////////////////////////////////////////////////////////////////////
#define MARKER_NAME1            "GGx64_ST_VMP3091"
#define MARKER_NAME2            "GGx64_ST_VMP3092"
#define MARKER_NAME3            "GGx64_ST_VMP3093"
#define MARKER_NAME4            "GGx64_ST_VMP3094"
#define MOVES_MAX              168

#define DELEY_BEST_MOVE_TIME   880
//////////////////////////////////////////////////////////////////////////

//#define 性能向导

#ifndef 性能向导

#ifndef NDEBUG

#define DEBUG_EVAL_OPP_SIDE_IS_SAME
#define OUTPUT_END_PV_POSITION
// #define USE_LOG_FILE
#define USE_ASSERT_COMMON
#define USE_ASSERT
#define USE_SLOW_BOARD  
#define DEBUG_REPEAT
//#define DEBUG_IN_CHECK

#endif

#endif // 性能向导





//////////////////////////////////////////////////////////////////////////

#pragma warning(disable : 4244)                    // conversion from '__int64' to 'int', possible loss of data
#pragma warning(disable : 4706)    
#define NOT_USE_FIND_MUL
//////////////////////////////////////////////////////////////////////////

#include "platform.h"
#include "types.h"
#include "Config.h"
#include "my_data.h"   // ok
#include "my_const.h"
#include "stock_fish_data.h"
#include "bitboard.h"
#include "position.h"
#include "evaluate.h"
#include "funzione.h"  
// #include "VMProtectSDK.h"
// #include "WMI_DeviceQuery.h"

#endif


