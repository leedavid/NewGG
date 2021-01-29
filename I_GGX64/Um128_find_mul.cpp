#include "chess.h"
#pragma warning(disable : 4530)    

#ifdef FIND_UM128_MUL



#ifdef USE_FIND_UM128_MUL


#define MAX_ARR NUM_CHE_ATT_F
Bitboard b[MAX_ARR];
Bitboard used[MAX_ARR];
Bitboard a[MAX_ARR];

Bitboard br[MAX_ARR];
Bitboard usedr[MAX_ARR];
Bitboard ar[MAX_ARR];

Bitboard bf[MAX_ARR];
Bitboard usedf[MAX_ARR];
Bitboard af[MAX_ARR];

#define NO_CAN_ATT_MUL -1



//#define M128_get_Mix64(bb)  (_mm_cvtsi128_si64(m_or(bb,_mm_slli_si128(_mm_srli_si128(bb,8),2)))) 
//#define M128_Mul128(bb,mul,res)   _umul128(M128_get_Mix64(bb),mul,res);

uint64 M_get_transfrom_u64(Bitboard bb, uint64 magic64){
	uint64 res;
	M128_Mul128(bb,magic64,&res);
	return res;  //  res 是 64X64 的高64位，前 15位 7位是rank, 8位是file
}

// 原来的                                                   
///////////////////////////////////////////////////////////////////////////////////////
// bits   = mask 总共有多少位
// index  = rank(7位） file(8位）
void M_index_to_Bitboard(Bitboard* result, int index, int bits, Bitboard mask){
	int i,j;
	*result = _mm_setzero_si128();      //print_bb(mask);
	for(i = 0; i < bits; i++){
		j = pop_1st_bit(mask);        //
		if(index & (1 << i)){          //
			set_bit(*result,j);
		}
	}
}

void M_che_att_by_block_r(Bitboard* result, int sq,Bitboard block){

	//m128_from_2u64(result,0,0);



	int rk = StoY(sq);
	int fl = StoX(sq);
	int f;

	*result = _mm_setzero_si128();

	//向右
	for(f = fl+1; f <= 8; f++){
		set_bit(*result,XYtoS(f,rk));
		if(bit_is_set(block,XYtoS(f,rk))) break;
	}
	//向左
	for(f = fl-1; f >= 0; f--){
		set_bit(*result,XYtoS(f,rk));
		if(bit_is_set(block,XYtoS(f,rk))) break;
	}
}

void M_che_att_by_block_f(Bitboard* result, int sq,Bitboard block){

	int rk = StoY(sq);
	int fl = StoX(sq);
	int r;
	*result = _mm_setzero_si128();
	//向上
	for(r = rk+1; r <= 9; r++){
		set_bit(*result,XYtoS(fl,r));
		if(bit_is_set(block,XYtoS(fl,r))) break;
	}
	//向下
	for(r = rk-1; r >= 0; r--){
		set_bit(*result,XYtoS(fl,r));
		if(bit_is_set(block,XYtoS(fl,r))) break;
	}
}


void m_find_che_magic_r(uint64* BB_magic, int sq, int m){ 	
	//sq = 64;
	Bitboard mask = m_and(RankBB_A[StoY(sq)],Che_Mask_FR[sq]);
	int n = (int)count_1s(mask);
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 100000000000000;
	printf_s("\n Now find >>>>>>>>>Che sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);    // b[i] = index_to_uint64(i, n, mask);
		che_att_by_block_r(&a[i],sq,b[i]);    // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xfffff) == 0){
			printf_s("\n >>now CHE SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//得到
		*BB_magic = random_uint64_fewbits();
		//*BB_magic = 0x8000000000000000;
		t64 = M_get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(M_get_Che_r(t64)) < n){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			//j = transform_mul(b[i],*BB_magic,m);
			j = M_get_Che_r(M_get_transfrom_u64(b[i],*BB_magic));
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];  // BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //还是清一下0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}


//#define M128_get_Or64(bb)        (_mm_cvtsi128_si64(m_or(bb,_mm_srli_si128(bb,8))))
uint64 Mm_get_transfrom_u64(Bitboard bb, uint64 magic64){
	return M128_get_Or64(bb) * magic64;
}

void m_find_che_magic_fr(uint64* BB_magic, int sq, int m){ 	
	//sq = 64;
	Bitboard mask  = Che_Mask_FR[sq];
	Bitboard maskr = m_and(RankBB_A[StoY(sq)],mask);
	Bitboard maskf = m_and(FileBB_A[StoX(sq)],mask);
	
	int n  = (int)count_1s(mask);
	int nr = (int)count_1s(maskr);
	int nf = (int)count_1s(maskf);

	int fail;
	int i; // j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 100000000000000;
	printf_s("\n Now find >>>>>>>>>Che sq= %d", sq);
	//for(i = 0; i < (1 << n); i++) {
	//	index_to_Bitboard(&b[i],i,n,mask);    // b[i] = index_to_uint64(i, n, mask);
	//	che_att_by_block_r(&a[i],sq,b[i]);    // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	//}

	for(i = 0; i < (1 << nr); i++) {
		index_to_Bitboard(&br[i],i,nr,maskr);    // b[i] = index_to_uint64(i, n, mask);
		che_att_by_block_r(&ar[i],sq,br[i]);    // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}

	for(i = 0; i < (1 << nf); i++) {
		index_to_Bitboard(&bf[i],i,nf,maskf);    // b[i] = index_to_uint64(i, n, mask);
		che_att_by_block_f(&af[i],sq,bf[i]);    // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}

	for(k = 0; k < testchenum; k++) {
		if((k & 0xfffff) == 0){
			printf_s("\n >>now CHE SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//得到
		*BB_magic = random_uint64_fewbits();
		//*BB_magic = 0x8000000000000000;
		//print_bb(mask);
		t64 = Mm_get_transfrom_u64(mask,*BB_magic) >> (64-15);
		if(_mm_popcnt_u64(t64) < (nf+nr)){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(usedr[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
			m128_from_2u64(usedf[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {

			uint64 iif = i & 0xff;
			uint64 iir = i >> 8;
			b[i] = m_or(bf[iif],br[iir]); 
			
			
			//print_bb(b[i]);
			//print_bb(af[iif]);
			//print_bb(ar[iir]);

			//j = transform_mul(b[i],*BB_magic,m);
			uint64 res = Mm_get_transfrom_u64(b[i],*BB_magic) >> (64  - 15);
			uint64 resf = res & 0xff;
			uint64 resr = (res >> 8);

			

			if(usedr[resr].m128i_u64[0]==NO_CAN_ATT_MUL  && usedf[resf].m128i_u64[1] ==NO_CAN_ATT_MUL){
				usedf[resf] = af[iif];  // BB_from_BB(used[j],a[i]);
				usedr[resr] = ar[iir];
			}
			//else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
			else if(usedf[resf].m128i_u64[0] != af[iif].m128i_u64[0] || usedr[resr].m128i_u64[0] != ar[iir].m128i_u64[0]
			     || usedf[resf].m128i_u64[1] != af[iif].m128i_u64[1] || usedr[resr].m128i_u64[1] != ar[iir].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //还是清一下0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void M_find_mul(bool isZero){

	int find = 0;
	uint64* PMul;
	int sq;
	PMul = (uint64*)M_CHE_Mult_R;
	//goto findma;
	//找到车的魔术数字
	for(sq = 0; sq < 90; sq++){
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			m_find_che_magic_fr(&PMul[sq], sq, 15);    // Rank 最多 7 + file 8
			if(PMul[sq] != 0){
				//还要再算一下哇
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n che rank mage_num: sq: %4d\n",sq);
		//print_bb(_Mult[sq],log_file);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	fprintf_s(llog_file,"\n che rank array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		//fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	/*
	//----------------------------------------------------------------------------
	PMul = (uint64*)CHE_Mult_F;
	find = 0;
	//找到车的魔术数字
	for(sq = 0; sq < 90; sq++){
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_che_magic_f(&PMul[sq], sq, 8);    // Rank 最多 7
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n che file mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n che file array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	//----------------------------------------------------------------------------
	PMul = PAO_EAT_Mult_R;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_eat_magic_r(&PMul[sq], sq, 7);  //R最多7
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao eat rank mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n pao eat rank array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	//-----------------------------------------------------------------
	PMul = PAO_EAT_Mult_F;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_eat_magic_f(&PMul[sq], sq, 8);  //File 最多 8
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao eat file mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n pao eat file array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	//----------------------------------------------------------------------------
	PMul = PAO_SUPER_Mult_R;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_super_magic_r(&PMul[sq], sq, 7);

			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao super rank mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	fprintf_s(log_file,"\n pao super rank array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	//----------------------------------------------------------------------------
	PMul = PAO_SUPER_Mult_F;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_super_magic_f(&PMul[sq], sq, 8);
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao super file mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n pao super file array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	//MA_Mult
	//findma:
	//----------------------------------------------------------------------------
	PMul = Ma_to_King_Mult;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_ma_magic(&PMul[sq], sq, 4);
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n ma_ma eat mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n ma_ma eat array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif

	//----------------------------------------------------------------------------
	PMul = King_to_Ma_Mult;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_king_to_ma_magic(&PMul[sq], sq, 4);
			if(PMul[sq] != 0){
				find++;
			}
		}		
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n king_to_ma eat mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n king_to_ma eat array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	//----------------------------------------------------------------------------
	PMul = XIANG_Mult;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if((sq == 2 || sq == 6 || sq == 18 || sq == 22 || sq == 26
			|| sq == 38 || sq == 42
			|| sq == 47 || sq == 51 || sq == 63 || sq == 67 || sq == 71
			|| sq == 83 || sq == 87) == FALSE) continue;
		if(PMul[sq] == 0){
			find_xiang_magic(&PMul[sq], sq, 4);
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n xiang eat mage_num: sq: %4d\n",sq);
		fflush(log_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//再打印数组
	fprintf_s(log_file,"\n xiang eat array ******************************** 又发现了 %d 个\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(log_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(log_file,"\n");
	}
	fflush(log_file);
#endif
	*/
}

#endif

#endif

