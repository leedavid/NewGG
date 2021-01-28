#include "chess.h"

 //Bitboard EmptyBoardBB;           //   =   { 0x0000000000000000,0x0000000000000000};
 //Bitboard FullBoardBB;
 //bb0,               bb1
 //Bitboard  Rank0BB;               //   =   { 0x00000000000001ff, 0x0000000000000000};
 //Bitboard  Rank1BB;               //   =   { 0x000000000003fe00, 0x0000000000000000};
 //Bitboard  Rank2BB;               //   =   { 0x0000000007fc0000, 0x0000000000000000};
 //Bitboard  Rank3BB;               //   =   { 0x0000000ff8000000, 0x0000000000000000};
 //Bitboard  Rank4BB;               //   =   { 0x00001ff000000000, 0x0000000000000000};

 //Bitboard  Rank5BB;               //   =   { 0x003fe00000000000, 0x0000000000000000};
 //Bitboard  Rank6BB;               //   =   { 0x7fc0000000000000, 0x0000000000000000};
 //Bitboard  Rank7BB;               //   =   { 0x8000000000000000, 0x00000000000000ff};
 //Bitboard  Rank8BB;               //   =   { 0x0000000000000000, 0x000000000001ff00};
 //Bitboard  Rank9BB;               //   =   { 0x0000000000000000, 0x0000000003fe0000};

 //Bitboard  File0BB;               //   =   { 0x8040201008040201, 0x0000000000020100};
 //Bitboard  File1BB;               //   =   { 0x0080402010080402, 0x0000000000040201};
 //Bitboard  File2BB;               //   =   { 0x0100804020100804, 0x0000000000080402};
 //Bitboard  File3BB;               //   =   { 0x0201008040201008, 0x0000000000100804};
 //Bitboard  File4BB;               //   =   { 0x0402010080402010, 0x0000000000201008};
 //Bitboard  File5BB;               //   =   { 0x0804020100804020, 0x0000000000402010};
 //Bitboard  File6BB;               //   =   { 0x1008040201008040, 0x0000000000804020};
 //Bitboard  File7BB;               //   =   { 0x2010080402010080, 0x0000000001008040};
 //Bitboard  File8BB;               //   =   { 0x4020100804020100, 0x0000000002010080};

 //Bitboard  RpawnOverBB;               //   =   {0x00001fffffffffff,0x0000000000000000};  //过河的红兵
 //Bitboard  BpawnOverBB;               //   =   {0xffffe00000000000,0x0000000003ffffff};  //过河的黑兵

 Bitboard OneRpawnOrRking_AttackBB[90];      // 红兵,红将,攻击其它的棋格.
 Bitboard OneBpawnOrBking_AttackBB[90];      // 黑兵,黑将

void initNeighboringFilesBB(){
	//NeighboringFilesBB[0] = _mm_load_si128 ((__m128i*) File1BB);
	//NeighboringFilesBB[1] = m_or(_mm_load_si128 ((__m128i*)File0BB),_mm_load_si128 ((__m128i*)File2BB));
	//NeighboringFilesBB[2] = m_or(_mm_load_si128 ((__m128i*)File1BB),_mm_load_si128 ((__m128i*)File3BB));
	//NeighboringFilesBB[3] = m_or(_mm_load_si128 ((__m128i*)File2BB),_mm_load_si128 ((__m128i*)File4BB));
	//NeighboringFilesBB[4] = m_or(_mm_load_si128 ((__m128i*)File3BB),_mm_load_si128 ((__m128i*)File5BB));
	//NeighboringFilesBB[5] = m_or(_mm_load_si128 ((__m128i*)File4BB),_mm_load_si128 ((__m128i*)File6BB));
	//NeighboringFilesBB[6] = m_or(_mm_load_si128 ((__m128i*)File5BB),_mm_load_si128 ((__m128i*)File7BB));
	//NeighboringFilesBB[7] = m_or(_mm_load_si128 ((__m128i*)File6BB),_mm_load_si128 ((__m128i*)File8BB));
	//NeighboringFilesBB[8] = _mm_load_si128 ((__m128i*) File7BB);
};
//uint32 aa;
void initFileRankconst(void){

	//static const uint64 XMM_ALIGN init_sbitmask[] = {
	//	0x0000000000000000, 0x0000000000000000,
	//	0xffffffffffffffff, 0xffffffffffffffff,
	//	0x00000000000001ff, 0x0000000000000000,
	//	0x000000000003fe00, 0x0000000000000000,
	//	0x0000000007fc0000, 0x0000000000000000,
	//	0x0000000ff8000000, 0x0000000000000000,
	//	0x00001ff000000000, 0x0000000000000000,
	//	0x003fe00000000000, 0x0000000000000000,
	//	0x7fc0000000000000, 0x0000000000000000,
	//	0x8000000000000000, 0x00000000000000ff,
	//	0x0000000000000000, 0x000000000001ff00,
	//	0x0000000000000000, 0x0000000003fe0000,
	//	0x8040201008040201, 0x0000000000020100,
	//	0x0080402010080402, 0x0000000000040201,
	//	0x0100804020100804, 0x0000000000080402,
	//	0x0201008040201008, 0x0000000000100804,
	//	0x0402010080402010, 0x0000000000201008,
	//	0x0804020100804020, 0x0000000000402010,
	//	0x1008040201008040, 0x0000000000804020,
	//	0x2010080402010080, 0x0000000001008040,
	//	0x4020100804020100, 0x0000000002010080,
	//	0x00001fffffffffff, 0x0000000000000000,
	//	0xffffe00000000000, 0x0000000003ffffff,
	//};
	//EmptyBoardBB = _mm_set_epi64x(0,0);
	//FullBoardBB  = _mm_load_si128((__m128i*)init_sbitmask[2]);
	//Rank0BB      = _mm_load_si128((__m128i*)init_sbitmask[4]);	
	//Rank1BB      = _mm_load_si128((__m128i*)init_sbitmask[6]);	
	//Rank2BB      = _mm_load_si128((__m128i*)init_sbitmask[8]);	
	//Rank3BB      = _mm_load_si128((__m128i*)init_sbitmask[10]);	
	//Rank4BB      = _mm_load_si128((__m128i*)init_sbitmask[12]);		
	//Rank5BB      = _mm_load_si128((__m128i*)init_sbitmask[14]);		
	//Rank6BB      = _mm_load_si128((__m128i*)init_sbitmask[16]);	
	//Rank7BB      = _mm_load_si128((__m128i*)init_sbitmask[18]);	
	//Rank8BB      = _mm_load_si128((__m128i*)init_sbitmask[20]);		
	//Rank9BB      = _mm_load_si128((__m128i*)init_sbitmask[22]);		
	//File0BB      = _mm_load_si128((__m128i*)init_sbitmask[24]);		
	//File1BB      = _mm_load_si128((__m128i*)init_sbitmask[26]);		
	//File2BB      = _mm_load_si128((__m128i*)init_sbitmask[28]);		
	//File3BB      = _mm_load_si128((__m128i*)init_sbitmask[30]);		
	//File4BB      = _mm_load_si128((__m128i*)init_sbitmask[32]);	
	//File5BB      = _mm_load_si128((__m128i*)init_sbitmask[34]);	
	//File6BB      = _mm_load_si128((__m128i*)init_sbitmask[36]);	
	//File7BB      = _mm_load_si128((__m128i*)init_sbitmask[38]);	
	//File8BB      = _mm_load_si128((__m128i*)init_sbitmask[40]);	
	//RpawnOverBB  = _mm_load_si128((__m128i*)init_sbitmask[42]);
	//BpawnOverBB	 = _mm_load_si128((__m128i*)init_sbitmask[44]);

 //   m128_from_2u64(EmptyBoardBB,0x0000000000000000, 0x0000000000000000);
 //   m128_from_2u64(FullBoardBB, 0xffffffffffffffff, 0xffffffffffffffff);
	//m128_from_2u64(Rank0BB,		0x00000000000001ff, 0x0000000000000000);
	//m128_from_2u64(Rank1BB,		0x000000000003fe00, 0x0000000000000000);
	//m128_from_2u64(Rank2BB,		0x0000000007fc0000, 0x0000000000000000);
	//m128_from_2u64(Rank3BB,		0x0000000ff8000000, 0x0000000000000000);
	//m128_from_2u64(Rank4BB,		0x00001ff000000000, 0x0000000000000000);
	//m128_from_2u64(Rank5BB,		0x003fe00000000000, 0x0000000000000000);
	//m128_from_2u64(Rank6BB,		0x7fc0000000000000, 0x0000000000000000);
	//m128_from_2u64(Rank7BB,		0x8000000000000000, 0x00000000000000ff);
	//m128_from_2u64(Rank8BB,		0x0000000000000000, 0x000000000001ff00);
	//m128_from_2u64(Rank9BB,		0x0000000000000000, 0x0000000003fe0000);				 
	//m128_from_2u64(File0BB,		0x8040201008040201, 0x0000000000020100);
	//m128_from_2u64(File1BB,		0x0080402010080402, 0x0000000000040201);
	//m128_from_2u64(File2BB,		0x0100804020100804, 0x0000000000080402);
	//m128_from_2u64(File3BB,		0x0201008040201008, 0x0000000000100804);
	//m128_from_2u64(File4BB,		0x0402010080402010, 0x0000000000201008);
	//m128_from_2u64(File5BB,		0x0804020100804020, 0x0000000000402010);
	//m128_from_2u64(File6BB,		0x1008040201008040, 0x0000000000804020);
	//m128_from_2u64(File7BB,		0x2010080402010080, 0x0000000001008040);
	//m128_from_2u64(File8BB,		0x4020100804020100, 0x0000000002010080);
	//m128_from_2u64(RpawnOverBB, 0x00001fffffffffff, 0x0000000000000000);  //过河的红兵
	//m128_from_2u64(BpawnOverBB, 0xffffe00000000000, 0x0000000003ffffff);  //过河的黑兵
}

void initFileBB_A_RankBB_A(void){
	//
	FileBB_A[0] =  _mm_load_si128 ((__m128i*)File0BB);
	FileBB_A[1] =  _mm_load_si128 ((__m128i*)File1BB);
	FileBB_A[2] =  _mm_load_si128 ((__m128i*)File2BB);
	FileBB_A[3] =  _mm_load_si128 ((__m128i*)File3BB);
	FileBB_A[4] =  _mm_load_si128 ((__m128i*)File4BB);
	FileBB_A[5] =  _mm_load_si128 ((__m128i*)File5BB);
	FileBB_A[6] =  _mm_load_si128 ((__m128i*)File6BB);
	FileBB_A[7] =  _mm_load_si128 ((__m128i*)File7BB);
	FileBB_A[8] =  _mm_load_si128 ((__m128i*)File8BB);

	//
	RankBB_A[0] =  _mm_load_si128 ((__m128i*)Rank0BB);
	RankBB_A[1] =  _mm_load_si128 ((__m128i*)Rank1BB);
	RankBB_A[2] =  _mm_load_si128 ((__m128i*)Rank2BB);
	RankBB_A[3] =  _mm_load_si128 ((__m128i*)Rank3BB);
	RankBB_A[4] =  _mm_load_si128 ((__m128i*)Rank4BB);
	RankBB_A[5] =  _mm_load_si128 ((__m128i*)Rank5BB);
	RankBB_A[6] =  _mm_load_si128 ((__m128i*)Rank6BB);
	RankBB_A[7] =  _mm_load_si128 ((__m128i*)Rank7BB);
	RankBB_A[8] =  _mm_load_si128 ((__m128i*)Rank8BB);
	RankBB_A[9] =  _mm_load_si128 ((__m128i*)Rank9BB);
}

//Bitboard ThisAndNeighboringFilesBB[9];
void initThisAndNeighboringFilesBB(void){

	//ThisAndNeighboringFilesBB[0] = m_or(FileBB_A[0],FileBB_A[1]);
	//ThisAndNeighboringFilesBB[1] = m_or(m_or(FileBB_A[0],FileBB_A[1]),FileBB_A[2]);
	//ThisAndNeighboringFilesBB[2] = m_or(m_or(FileBB_A[1],FileBB_A[2]),FileBB_A[3]);
	//ThisAndNeighboringFilesBB[3] = m_or(m_or(FileBB_A[2],FileBB_A[3]),FileBB_A[4]);
	//ThisAndNeighboringFilesBB[4] = m_or(m_or(FileBB_A[3],FileBB_A[4]),FileBB_A[5]);
	//ThisAndNeighboringFilesBB[5] = m_or(m_or(FileBB_A[4],FileBB_A[5]),FileBB_A[6]);
	//ThisAndNeighboringFilesBB[6] = m_or(m_or(FileBB_A[5],FileBB_A[6]),FileBB_A[7]);
	//ThisAndNeighboringFilesBB[7] = m_or(m_or(FileBB_A[6],FileBB_A[7]),FileBB_A[8]);
	//ThisAndNeighboringFilesBB[8] = m_or(FileBB_A[7],FileBB_A[8]);
}


void init_bb_const(void){
	initFileRankconst();
	initFileBB_A_RankBB_A();    //
	initNeighboringFilesBB();
	initThisAndNeighboringFilesBB();
}

