#ifndef BUILD_qsearch
#define BUILD_qsearch
#include "chess.h"
#include "s_end_my_pawn_info.cpp"
#include "white.h"
#else
#include "black.h"
#endif


Bitboard My_get_connect_Pawn(typePOS &POSITION){
	//Bitboard blb = _mm_setzero_si128();

	Bitboard byp = bb_my_pawn;
	Bitboard blp_l;
	Bitboard blp_r;
	// 去了左面,

	blp_l = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),byp);	    // 去了最左面的兵		
	m_Rsf(blp_l,1);                    // 所有兵向左一步	


	blp_r = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),byp);	    // 去了最右面的兵
	m_Lsf(blp_r,1);                   // 所有兵向右一步

	return(m_and(m_or(blp_l,blp_r),byp));
}

// 我方的兵已经过河的数目
int My_pawn_already_over_river(typePOS &POSITION){

	Bitboard myp = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
	return count_1s(myp);
}


