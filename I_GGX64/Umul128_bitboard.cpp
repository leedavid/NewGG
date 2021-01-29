#include "chess.h"
#pragma warning(disable : 4530)                   // unreferenced formal parameter  
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>

//#define FIND_UM128_MUL
#ifdef FIND_UM128_MUL


Bitboard M_CheAttacks_R[NUM_CHE_ATT_R];
int      M_CheAttackIndex_R[90];
uint64   M_CHE_Mult_R[90];


Bitboard M_CheAttacks_F[NUM_CHE_ATT_F];
int      M_CheAttackIndex_F[90];
uint64   M_CHE_Mult_F[90];


Bitboard M_Pao_Eat_Attacks_R[NUM_PAO_EAT_ATT_R];
int      M_Pao_Eat_AttackIndex_R[90];
uint64   M_Pao_Eat_Mult_R[90];


Bitboard M_Pao_Eat_Attacks_F[NUM_PAO_EAT_ATT_F];
int      M_Pao_Eat_AttackIndex_F[90];
uint64   M_Pao_Eat_Mult_F[90];

#define NUM_PAO_SUPER_ATT_R (11520)
Bitboard M_Pao_SUPER_R[NUM_PAO_SUPER_ATT_R];
int      M_Pao_SUPER_Index_R[90];
uint64   M_Pao_SUPER_Mult_R[90];


Bitboard M_PaoSUPER_F[NUM_PAO_SUPER_ATT_F];
int      M_Pao_SUPER_Index_F[90];
uint64   M_Pao_SUPER_Mult_F[90];


Bitboard M_Ma_to_King_Mask[90];             //从马的位置,来吃将, 是算一下别脚
Bitboard M_Ma_to_King_Attacks[NUM_MA_TO_KING_ATT];
int      M_Ma_to_King_AttackIndex[90];
uint64   M_Ma_to_King_Mult[90];


Bitboard M_King_to_Ma_Mask[90];             //从将的位置,被马吃, 是算一下反别脚
Bitboard M_King_to_Ma_Attacks[NUM_MA_TO_KING_ATT];
int      M_King_to_Ma_AttackIndex[90];
uint64   M_King_to_Ma_Mult[90];


Bitboard M_XiangMask[90];               // 相,主要是用来算一下象眼,
Bitboard M_XiangAttacks[NUM_XIANG_ATT];
int      M_XiangAttackIndex[90];
uint64   M_Xiang_Mult[90];

#endif