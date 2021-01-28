
extern sint32 statico_valu[16][90]; /* SMP read */       //static_value　

extern sint32 point_R_01Shi_B_Pawn90[3][90];           // 对方缺仕时兵的位置分
extern sint32 point_B_01Shi_R_Pawn90[3][90];

extern sint32 point_R_01Shi_B_Pawn90_My_CheOpen[90];   // 对方无仕，我方车开放时兵的位置分
extern sint32 point_B_01Shi_R_Pawn90_My_CheOpen[90];

extern sint32 PrePawnAttKingMul_Safe[3][90][90]; // 兵能攻击将的能力 
//extern Bitboard PrePawnAttKingGoodMove[90][90];  // 后可接近将的能力,看对方能不能控制我方的兵前进

extern sint32 MaterialTotalOver[16][16];    

#ifdef MULTIPLE_HISTORY                       //MULTI_HISTORY
extern uint16 HISTORY[MAX_CPUS][0x10][90]; /* SMP cashline ? */ 
#define HISTORY_VALUE(P, M) HISTORY[P->cpu][P->b90[FROM (M)]][TO (M)]
#else
uint16 HISTORY[0x10][90];
#define HISTORY_VALUE(P, M) HISTORY[P->qu[DI (M)]][AI (M)]
#endif

extern char STRING1[64], STRING2[64], STRING3[64], STRING4[64];

#define RKpos()   (POSITION->pieceList[RKING][0])//board->_kingPos[RKING]
#define BKpos()   (POSITION->pieceList[BKING][0])//board->_kingPos[BKING]

#define S90_from_piecelist(POSITION,piece,index)  ((POSITION)->pieceList[piece][index])


#define MAX(x, y) (( (x) >= (y)) ? (x) : (y))
#define MIN(x, y) (( (x) <= (y)) ? (x) : (y))
#define ABS(x) (( (x) >= 0) ? (x) : -(x))

/// 这个有问题
#define MoveHistory(x) (TRUE)   // #define move_history(x) (((x) & 060000) == 0)
#define RE0XE000 0x8000 // 不是升变，将军步

#define VALUE_ALWAYS_CHECK_OR_CAP         30000  // 常将常捉的得分
#define VALUE_MATE     30000                     // VALUE_MATE 将死的分数
#define VALUE_INFINITY 32750                     // VALUE_INFINITE
#define MOVE_NONE      0                         // MOVE_NONE

#ifdef USER_SPLIT
boolean SPLIT_AT_CUT;
int CUT_SPLIT_DEPTH, ALL_SPLIT_DEPTH, PV_SPLIT_DEPTH;
#else
#define SPLIT_AT_CUT TRUE
#define CUT_SPLIT_DEPTH 16
#define ALL_SPLIT_DEPTH 14
#define PV_SPLIT_DEPTH  14
#endif

extern boolean DO_SEARCH_MOVES;
extern uint32 SEARCH_MOVES[128];
extern volatile boolean DO_PONDER;
extern volatile boolean PONDER_HIT;
extern volatile boolean DO_INFINITE;
extern volatile boolean SUPPRESS_INPUT;
extern volatile boolean STOP; /* de sorvegliare.c */
extern boolean SEND_CURR_MOVE;
//extern boolean ROBBO_LOAD;

typedef struct 
{ 
	uint32 move; 
	sint32 Value; 
} typeMPV;
extern typeMPV MPV[128];
extern int MULTI_PV;

#ifndef MINIMAL
extern int MULTI_CENTI_PAWN_PV;
extern int RANDOM_COUNT;
extern int RANDOM_BITS;
extern boolean ALWAYS_ANALYZE;
extern int MULTI_CENTI_PAWN_PV;
extern boolean DEBUG_TIME_MANAGEMENT;
#endif

extern boolean USE_ALTERNATIVE_TIME;
extern uint64 BUFFER_TIME;
extern uint64 OUTPUT_DELAY;
extern boolean DO_OUTPUT;
extern boolean UCI_PONDER;
extern boolean VERIFY_NULL;
extern boolean SEND_HASH;
extern boolean ALLOW_INSTANT_MOVE;
//extern boolean SEARCH_ROBBO_BASES;

extern char *INPUT_BUFFER, *input_ptr;

#if 0
#define TRACE_COMPILE
#endif
#ifdef TRACE_COMPILE
boolean TRACE_QSEARCH, TRACE_HASH, TRACE_EVAL, TRACE_LOW_DEPTH, TRACE_CUT,
	TRACE_ALL, TRACE_EXCLUDE, TRACE_PV, TRACE_PVQSEARCH, TRACE_MAKE_UNMAKE;
#define TRACE(x, y) if (x) {y;}
#define HASH_READ(t) \
	printf ("READ [%x] %llx %x %x %s U:%d|%d L:%d|%d\n", \
	k + i, POSITION->DYN->HASH, t->flags, t->age, Notate(t->move, STRING1), \
	t->DepthUpper, t->ValueUpper, t->DepthLower, t->ValueLower);
#define HASH_READZ(t, zob) \
	printf ("READ [%x] %llx %x %x %s U:%d|%d L:%d|%d\n", \
	k + i, zob, t->flags, t->age, Notate(t->move, STRING1), \
	t->DepthUpper, t->ValueUpper, t->DepthLower, t->ValueLower);
#define HASH_WRITE(s, t) \
	printf ("HASH %s [%x] %llx %x %x %s U:%d|%d L:%d|%d\n", \
	s, k + i, Z, t->flags, t->age, Notate(t->move, STRING1), \
	t->DepthUpper, t->ValueUpper, t->DepthLower, t->ValueLower);
#define HASH_OVERWRITE(s, t) \
	printf ("HASHo %s [%x] %llx %x %x %s U:%d|%d L:%d|%d\n", \
	s, k + w, Z, t->flags, t->age, Notate(t->move, STRING1), \
	t->DepthUpper, t->ValueUpper, t->DepthLower, t->ValueLower);
#define HASH_ZERO(t) printf ("HASHz [%x]\n", k + j);
#else
#define TRACE(x, y) /* */
#endif


#define bitboard_white_king 	POSITION->byChessBB[RKING]    // 
#define bitboard_black_king	 	POSITION->byChessBB[BKING]    // 
#define bitboard_occ_white  	POSITION->byChessBB[0]
#define bitboard_occ_black  	POSITION->byChessBB[8]
#define bitboard_white_shi 		POSITION->byChessBB[RSHI]    // 
#define bitboard_black_shi 		POSITION->byChessBB[BSHI]    // 
#define bitboard_white_xiang 	POSITION->byChessBB[RXIANG]    // 
#define bitboard_black_xiang 	POSITION->byChessBB[BXIANG]    // 
#define bitboard_white_che 		POSITION->byChessBB[RCHE]    // 
#define bitboard_black_che 		POSITION->byChessBB[BCHE]    // 
#define bitboard_white_pao		POSITION->byChessBB[RPAO]    // 
#define bitboard_black_pao 		POSITION->byChessBB[BPAO]    // 
#define bitboard_white_ma 		POSITION->byChessBB[RMA]    // 
#define bitboard_black_ma 		POSITION->byChessBB[BMA]    //
#define bitboard_white_pawn 	POSITION->byChessBB[RPAWN]    // 
#define bitboard_black_pawn 	POSITION->byChessBB[BPAWN]    //
#define BitboardOCC             POSITION->byWhiteBlack

#define RChe_num()    POSITION->pieceCount[RCHE]
#define RMa_num()     POSITION->pieceCount[RMA]
#define RPao_num()    POSITION->pieceCount[RPAO]
#define RPawn_num()   POSITION->pieceCount[RPAWN]
#define RXiang_num()  POSITION->pieceCount[RXIANG]
#define RShi_num()    POSITION->pieceCount[RSHI]

#define BChe_num()    POSITION->pieceCount[BCHE]
#define BMa_num()     POSITION->pieceCount[BMA]
#define BPao_num()    POSITION->pieceCount[BPAO]
#define BPawn_num()   POSITION->pieceCount[BPAWN]
#define BXiang_num()  POSITION->pieceCount[BXIANG]
#define BShi_num()    POSITION->pieceCount[BSHI]

static const uint64 XMM_ALIGN Rank0BB[2] = { 0x00000000000001ff, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank1BB[2] = { 0x000000000003fe00, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank2BB[2] = { 0x0000000007fc0000, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank3BB[2] = { 0x0000000ff8000000, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank4BB[2] = { 0x00001ff000000000, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank5BB[2] = { 0x003fe00000000000, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank6BB[2] = { 0x7fc0000000000000, 0x0000000000000000 };
static const uint64 XMM_ALIGN Rank7BB[2] = { 0x8000000000000000, 0x00000000000000ff };
static const uint64 XMM_ALIGN Rank8BB[2] = { 0x0000000000000000, 0x000000000001ff00 };
static const uint64 XMM_ALIGN Rank9BB[2] = { 0x0000000000000000, 0x0000000003fe0000 };
static const uint64 XMM_ALIGN File0BB[2] = { 0x8040201008040201, 0x0000000000020100 };
static const uint64 XMM_ALIGN File1BB[2] = { 0x0080402010080402, 0x0000000000040201 };
static const uint64 XMM_ALIGN File2BB[2] = { 0x0100804020100804, 0x0000000000080402 };
static const uint64 XMM_ALIGN File3BB[2] = { 0x0201008040201008, 0x0000000000100804 };
static const uint64 XMM_ALIGN File4BB[2] = { 0x0402010080402010, 0x0000000000201008 };
static const uint64 XMM_ALIGN File5BB[2] = { 0x0804020100804020, 0x0000000000402010 };
static const uint64 XMM_ALIGN File6BB[2] = { 0x1008040201008040, 0x0000000000804020 };
static const uint64 XMM_ALIGN File7BB[2] = { 0x2010080402010080, 0x0000000001008040 };
static const uint64 XMM_ALIGN File8BB[2] = { 0x4020100804020100, 0x0000000002010080 };

static const uint64 XMM_ALIGN RpawnOverBB[2] = { 0x00001fffffffffff,0x0000000000000000 };  //过河的红兵
static const uint64 XMM_ALIGN BpawnOverBB[2] = { 0xffffe00000000000,0x0000000003ffffff };  //过河的黑兵

static const uint64 XMM_ALIGN TiMenBit_Pawn[2] = { 0x0000000000a0d844,0x0000000000886c14};

extern Bitboard OneRpawnOrRking_AttackBB[90];      // 红兵,红将,攻击其它的棋格.
extern Bitboard OneBpawnOrBking_AttackBB[90];      // 黑兵,黑将

extern Bitboard ShiAttackBB[90];                   // 双方的仕攻击到 90 的位棋盘

extern Bitboard Attack_By_Rpawn_Rking[90];         // 所有可攻击到棋格的红兵, 红将 //兵是单向的
extern Bitboard Attack_By_Bpawn_Bking[90];         // 所有可攻击到棋格的黑卒, 黑将

extern Bitboard Ma_Pseudo_Good_Att[90];            // 马可能走到好步的位置.
extern Bitboard Ma_Pseudo_Att[90];                 // 马可能走到的所有位置

#define NUM_MA_TO_KING_ATT (23040)
extern Bitboard Ma_to_King_Mask[90];             //从马的位置,来吃将, 是算一下别脚
extern Bitboard Ma_to_King_Attacks[NUM_MA_TO_KING_ATT];
extern int      Ma_to_King_AttackIndex[90];

#define NUM_KING_TO_MA_ATT (23040)
extern Bitboard King_to_Ma_Mask[90];             //从将的位置,被马吃, 是算一下反别脚
extern Bitboard King_to_Ma_Attacks[NUM_MA_TO_KING_ATT];
extern int      King_to_Ma_AttackIndex[90];

extern Bitboard fromtoBBback[90][90]; 
extern Bitboard XiangMask[90];               // 相,主要是用来算一下象眼,
extern int      XiangAttackIndex[90];
#define NUM_XIANG_ATT    (300)
extern Bitboard XiangAttacks[NUM_XIANG_ATT];

extern Bitboard SetMaskBB[90];                 
extern Bitboard ClearMaskBB[90];
extern Bitboard Che_Mask_FR[90];            // 车用来计算棋步的少最后一位,不包括自己
extern Bitboard Che_Mask_F[90];             // 车FILE MASK, 不包括自己
extern Bitboard Che_Mask_R[90];             // 车RANK MASK, 不包括自己
extern Bitboard ChePseudoMask_FR[90];       //车可攻击的位,包括最后一位
extern Bitboard KingAttackZone[90];         // 棋子可攻击将的能力.
extern Bitboard KingKingAttBB[90];          // 将与将的相互攻击性。

#define NUM_CHE_ATT_R    (11520)

extern Bitboard CheAttacks_R[NUM_CHE_ATT_R];
extern int      CheAttackIndex_R[90];

#define NUM_CHE_ATT_F    (23040)
extern Bitboard CheAttacks_F[NUM_CHE_ATT_F];
extern int      CheAttackIndex_F[90];

#define NUM_PAO_EAT_ATT_R (11520)

extern Bitboard Pao_Eat_Attacks_R[NUM_PAO_EAT_ATT_R];
extern int      Pao_Eat_AttackIndex_R[90];
#define NUM_PAO_EAT_ATT_F (23040)

extern Bitboard Pao_Eat_Attacks_F[NUM_PAO_EAT_ATT_F];
extern int      Pao_Eat_AttackIndex_F[90];

#define NUM_PAO_SUPER_ATT_R (11520)

extern Bitboard PaoSUPER_R[NUM_PAO_SUPER_ATT_R];
extern int      PaoSUPERIndex_R[90];

#define NUM_PAO_SUPER_ATT_F (23040)

extern Bitboard PaoSUPER_F[NUM_PAO_SUPER_ATT_F];
extern int      PaoSUPERIndex_F[90];
extern Bitboard FileBB_A[9];
extern Bitboard RankBB_A[10];
extern Bitboard NeighboringFilesBB[9];
extern Bitboard ThisAndNeighboringFilesBB[9]; 
extern Bitboard LowBB[10];      //棋子下面的位棋盘
extern Bitboard UpBB[10];       //棋子上面的位棋盘
extern Bitboard LeftBB[9];      //棋子左边的位棋盘
extern Bitboard RightBB[9];     //棋子右边的位棋盘
extern Bitboard BetweenBB[90][90];          // 二个在同一线上的棋子之间的位棋盘．不包括自己的信息.

extern int HashSizeNow;

//extern Bitboard TiMenBit_Pawn;              // 能铁门栓的兵
//extern Bitboard TimenBit_Che;               // 能铁门的车