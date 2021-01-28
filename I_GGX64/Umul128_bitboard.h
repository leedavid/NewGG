#ifndef Umul128_bitboard_h
#define Umul128_bitboard_h

//#define FIND_UM128_MUL
#ifdef FIND_UM128_MUL

//#define M_get_Che_File(resFR)    ((resFR) & 0xff)               // 8位
//#define M_get_CHe_Rank(resFR)    (((resFR)>>8) & 0x7f)          // 7位
#define M_get_Che_f(res1)           ((res1) & 0xff)                 // 只要车的情况
#define M_get_Che_r(res1)           ((res1) & 0x7f)                 // 只要车的情况
#define M_get_Ma(res1)            ((res1) & 0xff)                 // 8位
#define M_get_Xiang(res1)         ((res1) & 0x0f)                 // 4位

//_mm_unpackhi_epi64
//#define M128_get_Mix64(bb)  (_mm_cvtsi128_si64(m_or(bb,_mm_slli_si128(_mm_srli_si128(bb,8),2)))) 
//#define M128_get_Mix64(bb)  (_mm_cvtsi128_si64(m_or(bb,_mm_slli_si128(_mm_unpackhi_epi64(bb,bb),2))))
                                   // 先8位移，再1位移

#define NUM_CHE_ATT_R    (11520)
extern Bitboard M_CheAttacks_R[NUM_CHE_ATT_R];
extern int      M_CheAttackIndex_R[90];
extern uint64   M_CHE_Mult_R[90];

#define NUM_CHE_ATT_F    (23040)
extern Bitboard M_CheAttacks_F[NUM_CHE_ATT_F];
extern int      M_CheAttackIndex_F[90];
extern uint64   M_CHE_Mult_F[90];

#define NUM_PAO_EAT_ATT_R (11520)
extern Bitboard M_Pao_Eat_Attacks_R[NUM_PAO_EAT_ATT_R];
extern int      M_Pao_Eat_AttackIndex_R[90];
extern uint64   M_Pao_Eat_Mult_R[90];

#define NUM_PAO_EAT_ATT_F (23040)
extern Bitboard M_Pao_Eat_Attacks_F[NUM_PAO_EAT_ATT_F];
extern int      M_Pao_Eat_AttackIndex_F[90];
extern uint64   M_Pao_Eat_Mult_F[90];

#define NUM_PAO_SUPER_ATT_R (11520)
extern Bitboard M_Pao_SUPER_R[NUM_PAO_SUPER_ATT_R];
extern int      M_Pao_SUPER_Index_R[90];
extern uint64   M_Pao_SUPER_Mult_R[90];

#define NUM_PAO_SUPER_ATT_F (23040)
extern Bitboard M_Pao_SUPER_F[NUM_PAO_SUPER_ATT_F];
extern int      M_Pao_SUPER_Index_F[90];
extern uint64   M_Pao_SUPER_Mult_F[90];

#define NUM_MA_TO_KING_ATT (23040)
extern Bitboard M_Ma_to_King_Mask[90];             //从马的位置,来吃将, 是算一下别脚
extern Bitboard M_Ma_to_King_Attacks[NUM_MA_TO_KING_ATT];
extern int      M_Ma_to_King_AttackIndex[90];
extern uint64   M_Ma_to_King_Mult[90];

#define NUM_KING_TO_MA_ATT (23040)
extern Bitboard M_King_to_Ma_Mask[90];             //从将的位置,被马吃, 是算一下反别脚
extern Bitboard M_King_to_Ma_Attacks[NUM_MA_TO_KING_ATT];
extern int      M_King_to_Ma_AttackIndex[90];
extern uint64   M_King_to_Ma_Mult[90];

#define NUM_XIANG_ATT    (300)
extern Bitboard M_XiangMask[90];               // 相,主要是用来算一下象眼,
extern Bitboard M_XiangAttacks[NUM_XIANG_ATT];
extern int      M_XiangAttackIndex[90];
extern uint64   M_Xiang_Mult[90];

// 高8位与低8位或一下
#define M128_get_Or64(bb)        (_mm_cvtsi128_si64(m_or(bb,_mm_srli_si128(bb,8))))
#define M128_Mul128(bb,mul,res)   _umul128(M128_get_Or64(bb),mul,res);


__inline Bitboard M_rook_attacks_bb(int sq, Bitboard blockers){
	
	uint64 resr;
	Bitboard br = m_and(blockers,Che_Mask_R[sq]);
	M128_Mul128(br,M_CHE_Mult_R[sq],&resr);
	br = M_CheAttacks_R[M_get_Che_r(resr) + M_CheAttackIndex_R[sq]];

	uint64 resf;
	Bitboard bf = m_and(blockers,Che_Mask_F[sq]);
	M128_Mul128(bf,M_CHE_Mult_F[sq],&resf);
	bf = M_CheAttacks_F[M_get_Che_f(resf) + M_CheAttackIndex_F[sq]];
	
	return(m_or(br,bf));
}

__inline Bitboard M_pao_eat_attacks_bb(int sq, Bitboard blockers){

	uint64 resr;
	Bitboard br = m_and(blockers,Che_Mask_R[sq]);
	M128_Mul128(br,M_Pao_Eat_Mult_R[sq],&resr);
	br = M_Pao_Eat_Attacks_R[M_get_Che_r(resr) + M_Pao_Eat_AttackIndex_R[sq]];

	uint64 resf;
	Bitboard bf = m_and(blockers,Che_Mask_F[sq]);
	M128_Mul128(bf,M_Pao_Eat_Mult_F[sq],&resf);
	bf = M_Pao_Eat_Attacks_F[M_get_Che_f(resf) + M_Pao_Eat_AttackIndex_F[sq]];

	return(m_or(br,bf));
}

__inline Bitboard M_pao_super_attacks_bb(int sq, Bitboard blockers){

	uint64 resr;
	Bitboard br = m_and(blockers,Che_Mask_R[sq]);
	M128_Mul128(br,M_Pao_SUPER_Mult_R[sq],&resr);
	br = M_Pao_SUPER_R[M_get_Che_r(resr) + M_Pao_SUPER_Index_R[sq]];

	uint64 resf;
	Bitboard bf = m_and(blockers,Che_Mask_F[sq]);
	M128_Mul128(bf,M_Pao_SUPER_Mult_F[sq],&resf);
	bf = M_Pao_SUPER_F[M_get_Che_f(resf) + M_Pao_SUPER_Index_F[sq]];

	return(m_or(br,bf));
}

__inline Bitboard M_ma_to_king_attacks_bb(int sq, Bitboard blockers){
	uint64 res;
	Bitboard bb = m_and(blockers,Ma_to_King_Mask[sq]);
	M128_Mul128(bb,M_Ma_to_King_Mult[sq],&res);
	return M_Ma_to_King_Attacks[M_get_Ma(res) + M_Ma_to_King_AttackIndex[sq]];
}

__inline Bitboard M_king_to_ma_attacks_bb(int sq, Bitboard blockers){
	uint64 res;
	Bitboard bb = m_and(blockers,King_to_Ma_Mask[sq]);
	M128_Mul128(bb,M_King_to_Ma_Mult[sq],&res);
	return M_King_to_Ma_Attacks[M_get_Ma(res) + M_King_to_Ma_AttackIndex[sq]];
}

__inline Bitboard M128_xiang_attacks_bb(int sq, Bitboard blockers){
	uint64 res;
	Bitboard bb = m_and(blockers,XiangMask[sq]);
	M128_Mul128(bb,M_Xiang_Mult[sq],&res);
	return M_XiangAttacks[M_get_Xiang(res) + M_XiangAttackIndex[sq]];
}



//
//__inline Bitboard M128_xiang_attacks_bb(int sq, Bitboard blockers){
//	uint64 res;
//	Bitboard bb = m_and(blockers,XiangMask[sq]);
//	M128_Mul128(bb,M_XIANG_Mult[sq],&res);
//	return M_XiangAttacks[sq][M_get_Xiang(res)];
//}


extern void M_find_mul(bool isZero);

#endif

#endif

////Bitboard rook_attacks_bb(int sq, Bitboard blockers){
////	Bitboard ratt = CheAttacks_R[transform_bbm(m_and(blockers,Che_Mask_R[sq]),CHE_Mult_R[sq],64-7) + CheAttackIndex_R[sq]];
////	Bitboard fatt = CheAttacks_F[transform_bbm(m_and(blockers,Che_Mask_F[sq]),CHE_Mult_F[sq],64-8) + CheAttackIndex_F[sq]];
////	return _mm_or_si128(ratt,fatt);
////}



//inline void M_getFR_index(Bitboard bb, Bitboard mask,uint64 mul, uint64 &res){
//	uint64 re;
//	_umul128( _umul128
//}


//__m128i _mm_srli_si128(__m128i a, int imm) // 右移
//        _mm_slli_si128                     // 左移，
//d = _umul128(a, b, &c);
//取出一个64位数据
//#define _mm_extract_epi64(x, imm) 
//_mm_cvtsi128_si64(_mm_srli_si128((x), 8 * (imm)))
