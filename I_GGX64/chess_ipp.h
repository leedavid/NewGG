
#include <stdio.h>
#include <stdlib.h>

#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else



#define SMOOTH_SCALING FALSE



//#define USE_棋子的保护分   // 使用棋子的相互保护分

#define NOT_USE_FIND_MUL             // 找到魔术数字,这个是程序用的,
//#define USE_HASH_EAXCT_VALUE       //使用EVAL_HASH的确切值, 用了残局库才要这个东东
#define RP_PER_CPU  8                /* per cpu */
#define MAX_SP     16                /* total splitpoints */


//#pragma warning(disable : 4702) //#pragma warning(disable : 4100)

#define XMM_ALIGN __declspec(align(16))
#define TRUE   1
#define FALSE  0
#define WINDOWS
#define YUSUF_MULTICORE
#define MULTIPLE_POS_GAIN  // TRUE
#define MULTIPLE_HISTORY   // TRUE
#define USE_STACK_MOVE     // 棋局中保护历史棋步

#include <windows.h>
#include <intrin.h>
#define Bitboard __m128i



#define NODE_CHECK_SIZE 4095  // 0xfff

#define sint8 __int8
#define sint16 __int16
#define sint32 __int32
#define sint64 __int64
#define uint8 unsigned __int8
#define uint16 unsigned __int16
#define uint32 unsigned __int32
#define uint64 unsigned __int64
#define INLINE __inline
#define atoll _atoi64
#define TYPE_64_BIT "%I64d"
#if 1
#define MEMALIGN(a, b, c) a = (typeHash*)_aligned_malloc (c, b)
#define ALIGNED_FREE(x) _aligned_free (x)
#else
#define MEMALIGN(a, b, c) a = malloc (c)
#define ALIGNED_FREE(x) free (x)
#endif
#define WINDOWS_X64
#define __builtin_prefetch // #define __builtin_prefetch(x, y, z) _mm_prefetch((char*)x, z); 
#include "win64bits.h"

#define MUTEX_TYPE CRITICAL_SECTION
#define COND_TYPE HANDLE
#define LOCK(x) EnterCriticalSection(x)
#define UNLOCK(x) LeaveCriticalSection(x)
#define WAIT_CON_LOCK(x, y) WaitForSingleObject (x, INFINITE)
#define SIGNAL_CON_LOCK(x, y) SetEvent (x)
#define LOCK_INIT(x) InitializeCriticalSection(x)
#define COND_INIT(x, y) (x) = CreateEvent (0, FALSE, FALSE, 0)
#define PTHREAD_CREATE(N, b, thr, d)  CreateThread (NULL, 0, thr, (LPVOID) (d), 0, N);
extern DWORD PTHREAD[MAX_CPUS];
#define IVAN_THREAD(A) DWORD WINAPI ivan_thread (LPVOID A)

extern MUTEX_TYPE SMP_IVAN[1];
extern MUTEX_TYPE PTHREAD_COND_MUTEX[MAX_CPUS];
extern MUTEX_TYPE WAKEUP_LOCK[MAX_CPUS];
extern COND_TYPE PTHREAD_COND_WAIT[MAX_CPUS];
extern COND_TYPE WAKEUP[MAX_CPUS];

//#define SERCH_SEND_INFO_TIME
#ifdef  USE_ASSERT_COMMON
#define ASSERT_COMMON(a)	{ if (!(a)){fprintf(stdout,"\nfile \"%s\", line %d, ASSERTion \"" #a "\" failed\n",__FILE__,__LINE__); fflush(stdout);} }
#else
#define ASSERT_COMMON(a)        ((void)0) 
#endif

#ifdef  USE_ASSERT
//#define ASSERT(a)     
#define ASSERT(a)	            { if (!(a)){fprintf(stdout,"\nfile \"%s\", line %d, ASSERTion \"" #a "\" failed\n",__FILE__,__LINE__); fflush(stdout);} }
#else
#define ASSERT(a) 
#endif

/****************************************************************/
#define boolean uint8   // bool 

#define CHECK_HALT()   {if(POSITION->stop) RETURN (FALSE); }


#define FLAG_LOWER  1
#define FLAG_UPPER  2
#define FLAG_CUT    4
#define FLAG_ALL    8
#define FLAG_EXACT 16

#define IsCUT(tr)     ((tr->flags) & FLAG_CUT)
#define IsALL(tr)     ((tr->flags) & FLAG_ALL)
#define IsExact(tr)   ((tr)->flags & FLAG_EXACT)

#define MOVE_BIT  8
#define MOVE_MASK 0x7f
#define GAIN_MASK 0x7fff
#define GAIN_SIZE (GAIN_MASK+1)
#define MOVE07FFF 0x7fff


#define FROM(m)				   (((m)>>MOVE_BIT) & MOVE_MASK)  //  DI(m)
#define TO(m)				   ((m) & MOVE_MASK)              //  AI(m)
#define MOVE_FromTo(from,to)   ((to)|((from) << MOVE_BIT))   //还有二位,一位做历史步,一位做将军步
#define StoY(s) (_stoxy[s])       // ((s)/9)           // 
#define StoX(s) (_stoxx[s])       // _stoxx[s] StoX(s) ((s)%9)      // _stoxx[s]
#define XYtoS(x,y) ((y)*9+(x))

#define IS_EXACT(x) (x) /* exact from RobboTriple */

#define NEW_HASH
#ifdef NEW_HASH
#define VAS(v) VALUE_ADJUST_STORE((v), (HEIGHT(POSITION)))
#define HashLowerALL(POS, mv, dp, v) \
	HashLowerALLNew (POS->DYN->HASH, mv, dp, VAS (v))
#define HashUpperCUT(POS, dp, v) \
	HashUpperCUTNew (POS->DYN->HASH, dp, VAS (v))
#define HashLower(Z, mv, dp, v) HashLowerNew (Z, mv, dp, VAS (v))
#define HashUpper(Z, dp, v) HashUpperNew (Z, dp, VAS (v))
#define HashExact(POS, mv, dp, v, FL) \
	HashExactNew (POS->DYN->HASH, mv, dp, VAS (v), FL)
#endif

#if 0
#define MATEING_SCORE /* Fact: slows by 1-2%: for the why? */
#endif
#ifdef MATEING_SCORE
#if 1 /* asm code */ /* still the snail? */
static INLINE sint32 VALUE_ADJUST_STORE(sint32 v, uint32 ht)
{
	asm volatile ("xor %%r8d,%%r8d\n"
		"cmpl $29000,%0\n"
		"cmovg %1,%%r8d\n"
		"xor %%r9d,%%r9d\n"
		"cmpl $-29000,%0\n"
		"cmovl %1,%%r9d\n"
		"add %%r8d,%0\n"
		"sub %%r9d,%0\n" :
	"=r" (v) :
	"r" (ht), "0" (v) :
	"%r8", "%r9");
	return v;
}
#define HashUpperBound(tr) \
	VALUE_ADJUST_STORE (tr->ValueUpper, -HEIGHT(POSITION))
#define HashLowerBound(tr) \
	VALUE_ADJUST_STORE (tr->ValueLower, -HEIGHT(POSITION))
#else /* no asm code, slower */
#define VALUE_ADJUST_STORE(val, ht) \
	((val) + (((val) > 29000) ? (ht) : 0) - (((val) < -29000) ? (ht) : 0))
#define HashUpperBound(tr) \
	(tr->ValueUpper - ((tr->ValueUpper > 29000) ? (HEIGHT(POSITION)) : 0)	\
	+ ((tr->ValueUpper < -29000) ? (HEIGHT(POSITION)) : 0))
#define HashLowerBound(tr) \
	(tr->ValueLower - ((tr->ValueLower > 29000) ? (HEIGHT(POSITION)) : 0)	\
	+ ((tr->ValueLower < -29000) ? (HEIGHT(POSITION)) : 0))
#endif
#else
#define VALUE_ADJUST_STORE(Value, height) Value
#define HashUpperBound(tr) (tr->ValueUpper)
#define HashLowerBound(tr) (tr->ValueLower)
#endif

extern boolean TITANIC_MODE;
extern uint64  volatile CPUS_SIZE;
extern uint64  NODE_CHECK;

#if 0
#define LOCKLESS_HASHING /* functional Yet: poored */
#endif
#ifdef LOCKLESS_HASHING  /* Fact: 2-3% slowed, for the why? */
#define TRANS_DECLARE() typeHash trans[1]
#define YUSUF_DECLARE() typeHash *Trans
#define TRANS_PV_DECLARE() typePVHash trans_pv[1]
#define YUSUF_PV_DECLARE() typePVHash *Trans_pv
#if 0 /* on/off */
#define READ_WRITE_BARRIER() asm volatile ("" ::: "memory")
#define HYATT_HASH(T, t) \
{ READ_WRITE_BARRIER(); \
	((uint64*) (t))[0] = ((uint64*) (T))[0] ^ ((uint64*) (T))[1]; \
	((uint64*) (t))[1] = ((uint64*) (T))[1]; READ_WRITE_BARRIER(); }
#define HYATT_HASH_WRITE(t, T) \
{ READ_WRITE_BARRIER(); \
	((uint64*) (T))[0] = ((uint64*) (t))[0] ^ ((uint64*) (t))[1]; \
	((uint64*) (T))[1] = ((uint64*) (t))[1]; READ_WRITE_BARRIER(); }
#else /* dummy */ /* Fact: 2-3% snailed in the already with the this */
#define HYATT_HASH(T, t) { memcpy (t, T, 16); }
#define HYATT_HASH_WRITE(T, t) { memcpy (t, T, 16); }
#endif
#define UPDATE_AGE() /* ? */ /* Need for the think */
#else /* Personal Opinion: in the forget for the LOCKLESS_HASHING */
#define Trans trans
#define Trans_pv trans_pv
#define TRANS_DECLARE() typeHash *trans
#define YUSUF_DECLARE() /* */
#define TRANS_PV_DECLARE() typePVHash *trans_pv
#define YUSUF_PV_DECLARE() /* */
#define HYATT_HASH(x, y) /* */
#define HYATT_HASH_WRITE(x, y) /* */
#define UPDATE_AGE() trans->age = AGE;
#endif

#define EVAL(m) Eval (POSITION, -0x7fff0000, 0x7fff0000, m)
#define EvalLazy(B, A, p, m) Eval (POSITION, (B) - (p), (A) + (p), m)

#define WHITE_IN_CHECK   (m128_is_have_bit(m_and(POSITION->DYN->attack_black,bitboard_white_king)) 
#define BLACK_IN_CHECK   (m128_is_have_bit(m_and(POSITION->DYN->attack_white,bitboard_black_king)) 
#define POS1 (POS0 + 1)
#define MOVE_IS_CHECK_WHITE m128_is_have_bit(POS1->white_king_check)
#define MOVE_IS_CHECK_BLACK m128_is_have_bit(POS1->black_king_check)

#ifdef MULTIPLE_POS_GAIN           //GUADAGNO 增益
extern sint16 MAX_POSITIONAL_GAIN[MAX_CPUS][0x10][GAIN_SIZE];
#define MAX_POS_GAIN(pez, mos) MAX_POSITIONAL_GAIN[POSITION->cpu][pez][mos]
#else
extern sint16 MAX_POSITIONAL_GAIN[0x10][GAIN_SIZE];
#define MAX_POS_GAIN(pez, mos) MAX_POSITIONAL_GAIN[pez][mos]
#endif

extern boolean BOARD_IS_OK;      // board_is_legal
extern boolean NEW_GAME;         // NEW_GAME

#define CheckRepetition \
	if(POSITION->stop){ RETURN(0);} \
	i = is_repeat(POSITION); \
	switch(i){ \
	case REPEAT_TRUE: \
	RETURN(0);   \
	case REPEAT_BAN_ME: \
	return    HEIGHT (POSITION) - VALUE_ALWAYS_CHECK_OR_CAP ;   \
	case REPEAT_BAN_OTHER: \
	return -(HEIGHT (POSITION) - VALUE_ALWAYS_CHECK_OR_CAP);   \
	default: \
	break;\
}; 


#define MAX_REAL_CAP_NUM 16
typedef struct  {	
   int    LastCapChess[MAX_REAL_CAP_NUM][2][2];                   //最后一次吃的棋子
   int    last_to[MAX_REAL_CAP_NUM][2][2];                        //最后一次对方to
   int    last_ot_from[MAX_REAL_CAP_NUM][2][2];                   //最多可能有16个真捉	
   int    cap_num[2][2];
   bool   isTrueCap;
}TrupCap_t;


typedef struct
{
  uint32 hash;              // key
  uint8  flags;             // flags 石
  uint8  age;                // years 年代
  uint8  DepthUpper;         // hole_high
  uint8  DepthLower;         // hole_low
  sint16 ValueLower;         // value_low
  sint16 ValueUpper;         // value_high
  uint16 move;              // move
  uint8  rev;
  uint8 _2;
} typeHash;   // type_hash 

extern typeHash *HashTable;   // hash_指针
extern uint64 HashMask;      // hash_mask list_hide elenco 目录 mask
extern uint32 AGE;           // ANNI 年代,

typedef struct
{
	uint64 hash;
	sint32 Value;
	uint16 move;
	uint8 depth, age;
} typePVHash;
extern typePVHash PVHashTable[0x10000];    // multicore ? 
#define PVHashMask 0xfffc



//#define typeMoveList uint32
typedef struct
{
  uint32 move;
} typeMoveList;


typedef struct
{
	uint32 move;
	uint64 nodes;
} typeRootMoveList;

extern typeRootMoveList ROOT_MOVE_LIST[128]; // ROOT_LIST_MOVE

typedef struct
{
	/* 0x00-0x0f */ 
	uint64 HASH;
	uint32 statico;             // statik    位置分
	uint16 mossa50;             // move50 
	uint8 _10;                  //_en_passant;          // 所谓en passant (巧行将吃妙招)是国际象棋中一个“吃过路兵”的技
	uint8 cattura;              // capture 吃的棋子

} DYN_size32;             // type_dynamic 发展变化的

typedef struct
{
	uint64 HASH;
	uint32 statico;            // statik    位置分
	uint16 mossa50;             // move50 
	uint8 _10;                  //_en_passant;          // 所谓en passant (巧行将吃妙招)是国际象棋中一个“吃过路兵”的技
	uint8 cattura;              // capture 吃的棋子
	// 
	Bitboard attack_white;       // attacco_bianco;   // attack_white
	Bitboard attack_black;       // attacco_nero;     // attack_black
	Bitboard white_xray;
	Bitboard black_xray;
	Bitboard white_pao_null;      // 棋子可走到炮X将军的棋也要搜索哇
	Bitboard black_pao_null;      // 棋子可走到炮X将军的棋也要搜索哇
} DYN_size64;      // type_dynamic 发展变化的

typedef struct
{
	uint64 HASH;
    uint32 statico;             // statik    位置分
	uint16 mossa50;             // move50 
	uint8 _check;               //_en_passant;          // 所谓en passant (巧行将吃妙招)是国际象棋中一个“吃过路兵”的技
	uint8 catturaa;             // capture 吃的棋子
	// 
	Bitboard attack_white;       // attacco_bianco;   // attack_white
	Bitboard attack_black;       // attacco_nero;     // attack_black
	Bitboard white_xray;
	Bitboard black_xray;

	Bitboard white_pao_null;      // 棋子可走到炮X将军的棋也要搜索哇
	Bitboard black_pao_null;      // 棋子可走到炮X将军的棋也要搜索哇

	Bitboard white_king_check;    // bianco_re_scacco; // white_king_check
	Bitboard black_king_check;    // nero_re_scacco;   // black_king_check
	// 
	sint32 valu;                  // value    
	sint32 valu_posizionale;      // value_positional
	
	uint16 _6;
	uint16 killer1;         // uccisore_uno;     // killer_one
	uint16 killer2;         // uccisore_due;     // killer_two
	uint16 move;              // move
	
	//uint8 _0;
	//uint8 _3;
#ifdef USE_HASH_EAXCT_VALUE 
	uint8 exact;
#else
	uint8 _exact_not_use;
#endif

	uint8 lazy;			 // pigro 懒惰 lazy?	
	uint8 SAVED_FLAGS;   // flags_saves
	uint8 flags;         // flags
	//uint64 _8;
} typeDYNAMIC;             // type_dynamic 发展变化的

typedef struct
{
  Bitboard TARGET; // uint64 targa;
  int phase;
  int mask;
  int bc;               // bad_capture_num
  uint32 trans_move;
  uint32 move;
  uint32 exclude;  
  typeMoveList LISTA[128];
  uint32 BAD_CAP_MOVE[64];
} typeNEXT;  // type_next

#define HEIGHT(x) ((x)->height)

typedef struct
{
  int alpha;
  int beta;
  int depth;
  int node_type;
  int valu;
  uint32 move;
  uint32 good_move;
  uint32 childs;
  typeNEXT* MOVE_PICK;
  boolean tot;
  boolean aktiv;
  MUTEX_TYPE splock[1];
}
SPLITPUNKT;
extern SPLITPUNKT ROOT_SP[MAX_SP];
extern volatile int SMP_FREE;
#define NODE_TYPE_PV  1
#define NODE_TYPE_ALL 2
#define NODE_TYPE_CUT 3
#include <setjmp.h>
typedef struct  {    
	uint8   R_KongPaoScore;
	uint8   B_KongPaoScore;     //
    uint8   Rphase;             // 红方的攻棋的状态	//最大256 车 4 炮 3 马 2 兵 1 对方的士 -2 ，相 -2 ，
	uint8   Bphase;             // 黑方的攻棋的状态  //
	uint16  searchInfo16;       // 是棋局的检查状态
	sint16  material;		    // 2 子力分
} premat_t;

#define xray_white_list POSITION->_xray_white_lista
#define xray_black_list POSITION->_xray_black_lista

#ifdef USE_STACK_MOVE
typedef struct stRecord { 
	uint64 HASH;
	uint16 move;
	uint8  capturer;
	uint8  checkk;
} _STACKst;
#endif

typedef struct 
{
	Bitboard byChessBB[16];          // byChessBB[0] = white byChessBB[8] = black 
	Bitboard byWhiteBlack;           // 
	uint8 b90[90];
	uint8 index[90];
	uint8 _xray_white_lista[90];     // rook x king, record rook into xray.
	uint8 _xray_black_lista[90];     // 
	//Piece counts
	uint8 pieceCount[16];            // now [piece], was [color][type]
	//Piece lists
	uint8 pieceList[16][8];          // now [piece][index], was [color][pieceType][index]
		
	uint8 wtm;                       // bianco_en_mossa
	uint8 height;                    // 	
	premat_t*      pMat;             // 子力
	
} TP_size;

struct TP
{
	Bitboard byChessBB[16];          // byChessBB[0] = white byChessBB[8] = black 
	Bitboard byWhiteBlack;           // 
	uint8 b90[90];
	uint8 index[90];
	uint8 _xray_white_lista[90];     // rook x king, record rook into xray.
	uint8 _xray_black_lista[90];     // 	
	//Piece counts
	uint8 pieceCount[16];            // now [piece], was [color][type]
	//Piece lists
	uint8 pieceList[16][8];          // now [piece][index], was [color][pieceType][index]
	
	uint8 wtm;                       // bianco_en_mossa
	uint8 height;                    // 	
	premat_t*      pMat;             // 子力

	typeDYNAMIC *DYN;
	typeDYNAMIC *DYN_ROOT;

#ifdef USE_STACK_MOVE
	_STACKst STACKst[1024];           // 这儿还要加入MOVE，以便检测常捉什么的。
	sint64 StackHeight;             // stack_height = 0;
#else
    uint64 STACK[1024];             // 这儿还要加入MOVE，以便检测常捉什么的。
	sint64 StackHeight;             // stack_height = 0;
#endif

	uint64 cpu;
	uint64 nodes;
	uint64 tbhits;

#ifdef DEBUG_SAFE_SCORE
	int rattb_score;
	int rattb_point;
	//int rattb_safe_L;
	//int rattb_safe_R;
	int battr_score;
	int battr_point;
	//int battr_safe_L;
	//int battr_safe_R;
#endif

#ifdef DEBUG_etest
	int etest;
#endif
	boolean stop;
	boolean used;
	MUTEX_TYPE padlock[1];
	int child_count;
	struct TP* parent;
	struct TP* children[MAX_CPUS];
	SPLITPUNKT *SplitPoint;
};

typedef struct {
	//Bitboard canNotMoveBB;                             // 不能移动的棋子, 能不能合在一起??
	//Bitboard attackedBy[16];						     // 代表所有棋子各自可攻击的棋格	
	//Bitboard StringBB;                                 // 受牵制的棋子,只可能是马或炮.这个不用了,因为已有其它的评价代替一下.
	Bitboard ZhongDiPaoBB;                               // 中炮或底炮的位棋盘, xray_list 有已有了
	Bitboard KongPaoBB;                                  // 空炮的位棋盘.	

	Bitboard attackKingMaCan[2];                         // 马能将军的格式, 对方的马能跳到将军的格子
	Bitboard attackKingCheCan[2];                        // 车能攻击到 将 的格子
	Bitboard attackKingPaoCan[2];                        // 对方炮能攻击到 将 的格子.
	//Bitboard attackKignPawnCan[2];                     // 对方兵能将军的棋子
	Bitboard attackKingBoard;                            // 双方可攻击的棋子位置棋盘 
	//Bitboard attackZone[2];                              // 代表所有攻王的棋格.
	//sint16 kingAttackersCount[2];                      // 对方在攻击的棋子的数目
	//sint16 kingAttackersWeight[2];                     // AttackWeight
	sint16 kingAdjacentZoneAttacksCount[2];              // 可将军的棋格总数
	sint16 attPoint[2];                                  // 合计的攻击数
	


	Bitboard RmaAtt[2];                                  // 保存中间的数据
	Bitboard BmaAtt[2];
	Bitboard RcheAtt[2];
	Bitboard BcheAtt[2];
	Bitboard RPaoAtt[2];
	Bitboard BPaoAtt[2];
	//Bitboard RPaoCheAtt[2];                              // 炮可走到的棋格.
	//Bitboard BPaoCheAtt[2];
	Bitboard RpawnAtt;
	Bitboard BpawnAtt;

	Bitboard RShiXiangAtt;      // 红仕红相
	Bitboard BShiXiangAtt;      // 黑仕黑象

	uint8 rsafe;
	uint8 bsafe;
	uint8 rcan;
	uint8 bcan;
	uint8 bcx;
	uint8 bcy;
	uint8 rcx;
	uint8 rcy;
	uint16 mul;
	sint16 evscore;

	uint32 ev_stat;                            // 评估的一些信息.
	int rattb_score;                           // 红方攻击黑方的得分
	int battr_score;                           // 黑方攻击红方的得分	

	uint16 RKing_Info;
	uint16 BKing_Info;

} EvalInfo;

typedef struct TP typePOS;

extern typePOS ROOT_POSITION[MAX_CPUS][RP_PER_CPU];
extern typePOS ROOT_POSIZIONE0[1];
extern typePOS NULL_PARENT[1];

#define PB90(x) POSITION->b90[x]
#define POS_SIDE POSITION->wtm

#define MAXIMUM_PLY 1024   // hole_maximum

typedef enum
{
	   EMPTY=0,  // 这个不用了
       RKING=1,  RSHI=2, RXIANG=3, RMA=4, RCHE=5, RPAO=6, RPAWN=7,
	   _X_X =8,
       BKING=9,  BSHI=10,BXIANG=11,BMA=12,BCHE=13,BPAO=14,BPAWN=15,   
} enum_chess_piece;



typedef enum {
  NO_PIECE_TYPE = 0,
  KING=1, SHI=2, XIANG=3, MA=4, CHE=5, PAO=6, PAWN=7
} PieceType_enum ;

enum Color {
  WHITECOLOR, 
  BLACKCOLOR, 
  COLORNONE
};

enum Side_to_Move {
	BLACK_TO_MOVE,
	WHITE_TO_MOVE,
	NONE_TO_MOVE,
};

extern uint32 ROOT_BEST_MOVE;
extern int ROOT_SCORE;
extern int ROOT_PREVIOUS;
extern int ROOT_DEPTH;
extern int PREVIOUS_DEPTH;
extern int PREVIOUS_FAST;

#include <time.h>
extern jmp_buf J;
extern boolean JUMP_IS_SET;
extern boolean EASY_MOVE;
extern boolean BAD_MOVE;
extern boolean BATTLE_MOVE;
extern uint64 START_CLOCK;
extern uint64 INIT_CLOCK;
extern boolean ANALYSING;


const static char posizione_originale[80] =
  "rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w - - 0 1";

const static uint8 _piece_side[16] = {
	NONE_TO_MOVE,
	WHITE_TO_MOVE,WHITE_TO_MOVE,WHITE_TO_MOVE,WHITE_TO_MOVE,WHITE_TO_MOVE,WHITE_TO_MOVE,WHITE_TO_MOVE,
	NONE_TO_MOVE, 	
	BLACK_TO_MOVE,BLACK_TO_MOVE,BLACK_TO_MOVE,BLACK_TO_MOVE,BLACK_TO_MOVE,BLACK_TO_MOVE,BLACK_TO_MOVE,
};

#define PIECE_TYPE(p)    ((p)&7)           // 这个可以
#define PIECE_SIDE(p)    _piece_side[p]

typedef struct {
	int a[6][6][3][3][3][3][3][3][3][3][3][3];
}MARR_t ;

typedef enum
{ TRANS, 
CAPTURE_GEN, 
CAPTURE_MOVES,
KILLER1, 
KILLER2, 
ORDINARY_MOVES, 
BAD_CAPS,
TRANS2, 
CAPTURE_PGEN2,
CAPTURE_MOVES2, 
QUIET_CHECKS, 
EVADE_PHASE, 
TRANS3,
CAPTURE_GEN3, 
CAPTURE_MOVES3, 
QUIET_CHECKS3, 
POSITIONAL_GAIN_PHASE, 
FASE_0
} EnumPhases;

#include "chess_date.h"
#include "Config.h"    // ok
#include "my_data.h"   // ok
#include "common.h"    // ok
#include "my_const_h.h"// ok
#include "bitboard.h"
#include "funzione.h"  // function 函数
#include "VMProtectSDK.h"
// end_game_common_define
#define RETRUN_MUL(x)  { ei->mul = x; return; }

#endif

