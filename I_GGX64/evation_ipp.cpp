#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"
#include "valore.h"
#include "eval_const_h.h"



#ifndef MINIMAL
typedef struct { uint64 RandKey; uint8 pad[56]; } RAND; /* cache */
static RAND Rand[MAX_CPUS]; /* init ? */
static uint32 Random32 (int cpu)
{
	Rand[cpu].RandKey =
		Rand[cpu].RandKey * 0x7913cc52088a6cfULL + 0x99f2e6bb0313ca0dULL;
	return ((Rand[cpu].RandKey >> 18) & 0xffffffff);
}

void InitRandom32 (uint64 x)
{
	int cpu;
	for (cpu = 0; cpu < MAX_CPUS; cpu++)
	{
		x = x * 0xb18ec564ff729005ULL + 0x86ee25701b5e244fULL;
		Rand[cpu].RandKey = x;
	}
}
#endif

#define HashSize ( 0x8000 ) /* larger makes NPS drop with memory access */
#define HASH_MASK ( (HashSize) - 1 )
uint64 EvalHash[HashSize]; /* non atomico con 32-bits ? */


void EvalHashClear ()
{
	int c;
	for (c = 0; c < HashSize; c++)
		EvalHash[c] = 0;
}

static void AdjustPositionalGainB (const typePOS *POSITION, int mossa)
{
  int v, p, m;
  if (POSITION->DYN->catturaa)
    return;                                 // TO(m)	
  //if (POSITION->DYN->cattura && PB90(AI (mossa)] != RPAWN)
  //  return;
  p = PB90(TO (mossa));
  m = mossa & MOVE07FFF;
  v = POSITION->DYN->valu_posizionale - ((POSITION->DYN - 1)->valu_posizionale);
  if (MAX_POS_GAIN (p ,m) <= v)
    MAX_POS_GAIN (p, m) = v;
  else
    MAX_POS_GAIN (p, m)--;
}

static void AdjustPositionalGainW (const typePOS *POSITION, int mossa)
{
  int v, p, m;
  if (POSITION->DYN->catturaa)
    return;
  //if (POSITION->DYN->cattura && PB90(AI (mossa)] != BPAWN)
  //  return;
  p = PB90(TO (mossa));
  m = mossa & MOVE07FFF;
  v = ((POSITION->DYN - 1)->valu_posizionale) - POSITION->DYN->valu_posizionale;
  if (MAX_POS_GAIN (p ,m) <= v)
    MAX_POS_GAIN (p, m) = v;
  else
    MAX_POS_GAIN (p, m)--;
}

const static premat_t *Porg  = &PreMatInfo[0][0][0][0][0][0][0][0][0][0][0][0];
//const static uint16 _emul[4] = { 16, 16, 1, 16 };
//#define DEBUG_EVAL_OPP_SIDE_IS_SAME
#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
void                                   //   minimum     maximum     move
	valutazione_debug (const typePOS *POSITION, int minimo, int massimo, int mossa)
#else
void                                   //   minimum     maximum     move
	Eval (typePOS *POSITION, int minimo, int massimo, int mossa)
#endif
{
	Bitboard occ;
	Bitboard bit_rk;  // = SetMaskBB[rk];
	Bitboard bit_bk;  // = SetMaskBB[bk];
	Bitboard BString; // 中炮, 车X将的检查

	int valu = 0;	
	int posizionale;  // 位置分
	int endgame;
	int opening;
	int rk;
	int bk;
	EvalInfo ei;	
	premat_t* pMat = POSITION->pMat;
	int Material_value = pMat->material;
	int totalAttact = (pMat->Rphase + pMat->Bphase) / 2;
#ifdef USE_HASH_EAXCT_VALUE 
	POSITION->DYN->exact = FALSE;
#endif


#ifdef USE_EVAL_HASH //#define USE_EVAL_HASH
	// 取估值 HASH.
	if (((POSITION->DYN->HASH ^ EvalHash[POSITION->DYN->HASH & HASH_MASK]) &
		0xffffffffffff0000) == 0)
	{
		valu =
			(int) ((sint16)(EvalHash[POSITION->DYN->HASH & HASH_MASK] & 0xffff)); //低4位做值
		POSITION->DYN->lazy = 0;  // hash flag??
		Mobility (POSITION); // attack and attack_king
		POSITION->DYN->valu_posizionale =
			((POS_SIDE) ? valu : -valu) - Material_value;  // 
		POSITION->DYN->valu = valu;
		if (mossa && !(POSITION->DYN - 1)->lazy){
			POS_SIDE ?
			AdjustPositionalGainW (POSITION, mossa) : 
		    AdjustPositionalGainB (POSITION, mossa);
		}
#ifdef USE_HASH_EAXCT_VALUE 
		if (valu > 15000 || valu < -15000){
			POSITION->DYN->exact = TRUE;
		}
#endif
		return;
	}
#endif	
    
	memset(&ei,0,sizeof(EvalInfo));                          // 清空评估的信息
	ei.mul = 16;



#include "eval_将帅_first.h" 　　　　　　 // 2 
#include "eval_炮的第一次评估.h"          // 先评估一下双方的炮      // 因为炮有牵制功能,可去了对方仕相的防守
#include "eval_仕相.h"                  // 评估一下双方的仕相。
#include "eval_兵的第一次评估.h"          // 评价一下双方的兵
#include "eval_兵的过河能力.h"            // 评价双方的兵可过河的数量, 因为在残局中要用到,所以得先评估一下.

#ifdef TEST_ENDGAME_SHI_XIANG_IS_OK
	int oldsx = POSITION->pieceCount[BSHI] + POSITION->pieceCount[BXIANG]
	          + POSITION->pieceCount[RSHI] + POSITION->pieceCount[RXIANG];
	(*funMat[(POSITION->pMat - Porg)])(POSITION, &ei);       // 得到残局的分信息
	int newsx = POSITION->pieceCount[BSHI] + POSITION->pieceCount[BXIANG]
	+ POSITION->pieceCount[RSHI] + POSITION->pieceCount[RXIANG];
	if(oldsx != newsx){
		board_display(POSITION,"ERROR sx not same??\n");
	}
#else
	(*funMat[(POSITION->pMat - Porg)])(POSITION, &ei);       // 得到残局的分信息
#endif

	if((ei.bsafe + ei.rsafe) == 2) {
		ei.mul = 1;
	}

#include "eval_lazy_first.h"  　　　　　// 1 这个一定要放在这儿


#include "eval_马的第一次评估.h"         // 再评估一下双方的马
#include "eval_车的第一次评估.h"	       // 然后可评估一下双方的车.车的评估要放在后面。

Bitboard white_safe = m_not(m128_bb_or_bb(bitboard_occ_white,
	POSITION->DYN->attack_black));  // 红方可安全走到的棋格,还得加上pao_NULL哇
Bitboard black_safe = m_not(m128_bb_or_bb(bitboard_occ_black,
	POSITION->DYN->attack_white));  // 黑方可安全走到的棋格

//下面已得到所有的attacter.
#include "eval_炮的第二次评估.h"          // 
#include "eval_将的活动情况.h"            // 将的活动情况
#include "eval_车的第二次评估.h"	        // 然后可评估一下双方的车.车的评估要放在后面。
#include "eval_牵制信息.h"               // 牵制分
#include "eval_空中炮空底炮.h"            // 空炮
#include "eval_中炮底炮.h"               // 中炮底炮
#include "eval_马的第二次评估.h"          // 马的第二次评估
#include "eval_兵的第二次评估.h"          // 看一下兵能不能接近对方的老将
#include "eval_少仕.h"                   // 我方少仕的情况
#include "eval_少相.h"                   // 我方少仕的情况
#include "eval_1车1炮X兵.h"              // if(pMat->searchInfo16 & CK_R_Only_1Che1PaoxPawn){
#include "get_check_history.h"          // 得到双方的将军信息
#include "eval_子力平衡.h"                // 双方区域的对方的子力差.
#include "eval_红不能走与黑抽将的子.h"      // 评价一下不能走与抽将的棋子.
#include "eval_黑不能走与红抽将的子.h"      // 评价一下不能走与抽将的棋子
#include "eval_weak_piece.h"            // 评价双方的弱子
#include "eval_窝心马.h"                 // 窝心马
#include "eval_rking_safe.h"            // 评价红帅的安全性
#include "eval_bking_safe.h"            // 评价黑将的安全性

	//valu += TwoCheFreeCheck[ei.rcy + ei.rcx];     //双车错杀的分
	//valu -= TwoCheFreeCheck[ei.bcy + ei.bcx];     //
	//***********************************************************
	// 转换分数
	//***********************************************************
	endgame = (sint16)(valu & 0xffff);
	opening = (endgame < 0) + (sint16)((valu >> 16) & 0xffff);
	valu  = ((opening * totalAttact) + endgame * (256 - totalAttact)) / 256;

	ei.rattb_score = SafetyTable[MIN_ZEOR_SAFE_POINT 
		             + ei.attPoint[WHITECOLOR] 
	                 + ChefreeCheckPointY[ei.rcy] 
					 + ChefreeCheckPointX[ei.rcx] ];
	ei.battr_score = SafetyTable[MIN_ZEOR_SAFE_POINT 
		             + ei.attPoint[BLACKCOLOR]
	                 + ChefreeCheckPointY[ei.bcy] 
	                 + ChefreeCheckPointX[ei.bcx] ];

//*********************************************************************

#ifdef DEBUG_SAFE_SCORE
	POSITION->rattb_score   = ei.rattb_score;
	//POSITION->rattb_point   = ei.Rattack_B_Count;
	POSITION->battr_score   = ei.battr_score;
	//POSITION->battr_point   = ei.Battack_R_Count;
#endif

	valu += ei.rattb_score - ei.battr_score;
	// end           // 残局分数
	valu = (valu + ei.evscore + Material_value) * ei.mul / 16;

#include "eval_random.h"
	
	POSITION->DYN->valu = POS_SIDE ? valu : -valu;
	POSITION->DYN->valu_posizionale = valu - Material_value;  //POSITION->DYN->valu_posizionale = 0;	
	POSITION->DYN->lazy = 0;
#ifdef USE_EVAL_HASH 
	 // 将估值保存一下.
	 EvalHash[POSITION->DYN->HASH & HASH_MASK] =     // 将估值保存一下.
		(POSITION->DYN->HASH & 0xffffffffffff0000) | (POSITION->DYN->valu & 0xffff);
#endif
	if (mossa && !(POSITION->DYN - 1)->lazy){
		POS_SIDE ?         // 窍门 black 
		AdjustPositionalGainW (POSITION, mossa) : AdjustPositionalGainB (POSITION, mossa);
	}
}

#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
void 
Eval(const typePOS *POSITION, int minimo, int massimo, int mossa){

	// valutazione_debug (const typePOS *POSITION, int minimo, int massimo, int mossa)
	int val_old;
	int val_r2b;
	int val_mir;
	char fen[256];
	typePOS mPOSITION[1];	
	typeDYNAMIC mydin[3];
	int from,to;	
	int move_new;

	memcpy(mPOSITION,POSITION,sizeof(typePOS));  //);
	mPOSITION->DYN_ROOT = mydin+1;
	//memcpy(mPOSITION->DYN_ROOT,POSITION->DYN-1,2*sizeof(typeDYNAMIC));
	//mPOSITION->DYN = mPOSITION->DYN_ROOT + 1;
	

	valutazione_debug(POSITION,minimo,massimo,mossa);

	val_old = POSITION->DYN->valu;

	board_mirror(mPOSITION,POSITION);

	memcpy(mPOSITION->DYN_ROOT,POSITION->DYN-1,2*sizeof(typeDYNAMIC));
	mPOSITION->DYN = mPOSITION->DYN_ROOT + 1;


	from = FROM(mossa);
	to   = TO(mossa);
	move_new = mossa;
	if(mossa != 0){
	    move_new = MOVE_FromTo(Mirror(from),Mirror(to));
	}

	valutazione_debug(mPOSITION,minimo,massimo,move_new);

	val_mir = mPOSITION->DYN->valu; 

	/*if(val_old != val_mir || POSITION->etest != mPOSITION->etest){*/
	if(val_old != val_mir ){
		board_display(POSITION,"pos old");
		board_display(mPOSITION,"mpos mir");
		board_to_fen(POSITION,fen);
		printf("\nOrgFen: %s",fen);
		board_to_fen(mPOSITION,fen);
		printf("\nBcRFen: %s",fen);
		valutazione_debug(POSITION,minimo,massimo,mossa);
		valutazione_debug(mPOSITION,minimo,massimo,move_new);
		val_mir = 0;
	}

	board_red2black(mPOSITION,POSITION); // 红黑交换一下
	val_r2b = mPOSITION->DYN->statico;
	memcpy(mPOSITION->DYN_ROOT,POSITION->DYN-1,2*sizeof(typeDYNAMIC));
	mPOSITION->DYN = mPOSITION->DYN_ROOT + 1;
	mPOSITION->DYN->statico = val_r2b;

	// POSITION->DYN->cattura  POSITION->DYN->statico
	mPOSITION->DYN->catturaa = revertChess[POSITION->DYN->catturaa];
	(mPOSITION->DYN - 1)->valu_posizionale = -(mPOSITION->DYN - 1)->valu_posizionale;
	// 位置分也要反一反哇
	if(mossa != 0){
		move_new = MOVE_FromTo((89-from),(89-to));
	}
	// 评估红黑交换局面
	valutazione_debug(mPOSITION,minimo,massimo,move_new);

	val_r2b = mPOSITION->DYN->valu; 
#ifdef DEBUG_etest
	if(val_old != val_r2b || POSITION->etest != -mPOSITION->etest){
#else
	if(val_old != val_r2b){
#endif	
		board_display(POSITION,"pos old");
		board_display(mPOSITION,"mpos r2b");
		board_to_fen(POSITION,fen);
		printf("\nOrgFen: %s",fen);
		board_to_fen(mPOSITION,fen);
		printf("\nBcRFen: %s",fen);		

		valutazione_debug(POSITION,minimo,massimo,mossa);
		valutazione_debug(mPOSITION,minimo,massimo,move_new);
		val_r2b = 0;
	}	
}

#endif


#endif