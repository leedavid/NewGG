#ifndef CHESS_TOTAL_H_INCLUDED
#define CHESS_TOTAL_H_INCLUDED

//////////////////////////////////////////////////////////////////////////
//#pragma warning(disable : 4530)                   // unreferenced formal parameter  
#pragma warning(disable : 4100)                   // unreferenced formal parameter  
#pragma warning(disable : 4244)                   // conversion from '__int64' to 'int', possible loss of data
#define MAX_CPUS                 12               /* vary for increase */
#define VERSION         "11.0619.02"
#define USE_I7_MACHINE                            // _mm_popcnt_u64
//#define USE_ST_180_MARGIN                         // 这个上层快一些. 
//#define USE_LOG_FILE

#define 挂机模式

//////////////////////////////////////////////////////////////////////////
#ifdef NDEBUG      
#define  USE_CYCLONE_UCI
//#define  USE_VP_PROTECT                            // 使用VMP 加密
#endif

//#define NOT_STORE_TT_DEPTH_TO_TT (bestValue > (VALUE_BAN_CHECK - 202)  && bestValue <= VALUE_BAN_CHECK)
//#define NOT_STORE_TT_DEPTH_TO_TT ((ABS(ABS(bestValue) - VALUE_BAN_CHECK) <= 202) || bestValue == 0)
#define NOT_STORE_TT_DEPTH_TO_TT ((ABS(ABS(bestValue) - VALUE_BAN_CHECK) <= 202))
//#define NOT_STORE_TT_DEPTH_TO_TT ((bestValue > (VALUE_BAN_CHECK - 202)  && bestValue < VALUE_BAN_CHECK) || bestValue == 0)

//////////////////////////////////////////////////////////////////////////
#define SEARCH_REPEAT_PLY_120  128                      // was 120

#ifdef  USE_CYCLONE_UCI
#ifdef USE_VP_PROTECT                                 // 使用VMP加密
#if MAX_CPUS > 12
#define CYCLONE_SUB_DEPTH  0
#else
#define CYCLONE_SUB_DEPTH  2
#endif
#else
#define CYCLONE_SUB_DEPTH  0
#endif
#define CYCLONE_MUL_NPS    2
#endif


#if MAX_CPUS > 8
///
#define MAX_ACTIVE_SPLIT_POINTS 8
#define NODE_BETWEEN_POLLS      30000
#else
///
#define MAX_ACTIVE_SPLIT_POINTS 8                // was 8
#define NODE_BETWEEN_POLLS      30000
#endif


#define MARKER_NAME     "GGx64_ST_VMP260"
//#define BENCHMARK
#define BOOK_MOVE_DELAY 2800
#define MOVES_MAX       128

#ifdef USE_CYCLONE_UCI
#define NOT_OUT_UPBOND_OR_LOW_BAND
#else
#define CAN_OUT_EVAL_INFO
#endif



//////////////////////////////////////////////////////////////////////////
#ifndef NDEBUG
//#define FIND_BAN_MOVE
#define DEBUG_EVAL_OPP_SIDE_IS_SAME
#define OUT_PUT_END_PV_POSITION
//#define USE_LOG_FILE
#define USE_ASSERT_COMMON
#define USE_ASSERT
#define USE_SLOW_BOARD  
#define DEBUG_REPEAT
//#undef  USE_CYCLONE_UCI
#endif
//////////////////////////////////////////////////////////////////////////

#ifdef  USE_CYCLONE_UCI
#ifdef USE_I7_MACHINE
#define EPONYM          "GGchess-I7" 
#else
#define EPONYM          "GGchess-not-I7"
#endif
#else
#ifdef USE_I7_MACHINE
#define EPONYM          "NewGG-I7"
#else
#define EPONYM          "NewGG-nI7"
#endif
#endif

#include "s_chess.h"

// Evaluation grain size, must be a power of 2
#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
const int GrainSize = 1;  // 去掉一些细微的差异?? 
#else
const int GrainSize = 4;  // 去掉一些细微的差异?? 
#endif

#endif