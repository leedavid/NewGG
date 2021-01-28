
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

static const uint64 XMM_ALIGN RpawnOverBB[2] =     { 0x00001fffffffffff,0x0000000000000000 };  //过河的红兵
static const uint64 XMM_ALIGN BpawnOverBB[2] =     { 0xffffe00000000000,0x0000000003ffffff };  //过河的黑兵

static const uint64 XMM_ALIGN WHOLE_BITBOARD90[2] = {0xffffffffffffffff,0x03ffffff};       //所有90格棋子

#define ALL_B90 _mm_load_si128((__m128i*)(WHOLE_BITBOARD90))

static const uint64 XMM_ALIGN TiMenBit_Pawn[2] = { 0x0000000000a0d844,0x0000000000886c14};

extern Bitboard OneRpawnOrRking_AttackBB[90];      // 红兵,红将,攻击其它的棋格.
extern Bitboard OneBpawnOrBking_AttackBB[90];      // 黑兵,黑将

extern Bitboard ShiAttackBB[90];                   // 双方的仕攻击到 90 的位棋盘

//extern Bitboard MaHouPaoByKing[90];                // 马后炮的位置

extern Bitboard Attack_By_Rpawn_Rking[90];         // 所有可攻击到棋格的红兵, 红将 //兵是单向的
extern Bitboard Attack_By_Bpawn_Bking[90];         // 所有可攻击到棋格的黑卒, 黑将

//extern Bitboard Ma_Pseudo_Good_Att[90];           // 马可能走到好步的位置.

extern Bitboard Ma_Pseudo_Att[90];                 // 马可能走到的所有位置

#define NUM_MA_TO_KING_ATT (1440)
extern Bitboard Ma_to_King_Mask[90];             // 从马的位置,来吃将, 是算一下别脚
extern Bitboard Ma_to_King_Attacks[NUM_MA_TO_KING_ATT];
extern int      Ma_to_King_AttackIndex[90];

#define NUM_KING_TO_MA_ATT (1440)
extern Bitboard King_to_Ma_Mask[90];             // 从将的位置,被马吃, 是算一下反别脚
extern Bitboard King_to_Ma_Attacks[NUM_MA_TO_KING_ATT];
extern int      King_to_Ma_AttackIndex[90];

//extern Bitboard fromtoBBback[90][90]; 
extern Bitboard XiangMask[90];                   // 相,主要是用来算一下象眼,
extern int      XiangAttackIndex[90];
#define NUM_XIANG_ATT    (300)
extern Bitboard XiangAttacks[NUM_XIANG_ATT];

extern Bitboard SetMaskBB[90];                 
extern Bitboard ClearMaskBB[90];
extern Bitboard Che_Mask_FR[90];                // 车用来计算棋步的少最后一位,不包括自己
extern Bitboard Che_Mask_F[90];                 // 车FILE MASK, 不包括自己
extern Bitboard Che_Mask_R[90];                 // 车RANK MASK, 不包括自己
extern Bitboard ChePseudoMask_FR[90];           // 车可攻击的位,包括最后一位
extern Bitboard MaKingAttackZone[90];           // 棋子可攻击将的能力.
extern Bitboard MaPosAttackKing[90];            // 马攻击将的棋格
extern Bitboard PawnKingAttackZone[90];         // 棋子可攻击将的能力.
extern Bitboard Ma_good_mask[2];                // 双方马不太好走的步子


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
extern Bitboard LowBB[10];          // 棋子下面的位棋盘
extern Bitboard UpBB[10];           // 棋子上面的位棋盘
extern Bitboard LeftBB[9];          // 棋子左边的位棋盘
extern Bitboard RightBB[9];         // 棋子右边的位棋盘
extern Bitboard BetweenBB[90][90];  // 二个在同一线上的棋子之间的位棋盘．不包括自己的信息.