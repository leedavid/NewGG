#ifndef E_InitMatFunction6
#define E_InitMatFunction6
#include "..\\chess.h"
 
#include "..\\white.h"
#else
#include "..\\black.h"
#endif

void InitMatFunction6(void){
	//********************************************* 6 ¶Ô 0*****************************************************************
	//********************************************* 6 ¶Ô 1*****************************************************************

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_R_1CHE_5PAWN_B_1CHE;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1CHE_5PAWN_R_1CHE;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_R_1che5pawn_B_1pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_R_1che5pawn_B_1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [0]  [0] ]  = m_MT_R_1che5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [1]  [2]  [1]  [0]  [0] ]  = m_MT_R_2pao_1ma3pawn_B_1che;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0]  [0]  [1]  [2] ]  = m_MT_B_2pao_1ma3pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [2]  [1]  [1]  [0]  [0] ]  = m_MT_R_1pao_2ma3pawn_B_1che;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0]  [0]  [2]  [1] ]  = m_MT_B_1pao_2ma3pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [1]  [0]  [0] ]  = m_MT_R_2pao_4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao_4pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [0]  [1] ]  = m_MT_R_2pao_4pawn_B_1pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao_4pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [1]  [0] ]  = m_MT_R_2pao_4pawn_B_1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao_4pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [0]  [0]  [0] ]  = m_MT_R_2pao_4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao_4pawn_R_1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [1]  [0]  [0] ]  = m_MT_R_1pao_1ma4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [1]  [1] ]  = m_MT_B_1pao_1ma4pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [0]  [1] ]  = m_MT_R_1pao_1ma4pawn_B_1pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao_1ma4pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [1]  [0] ]  = m_MT_R_1pao1ma_4pawn_B_1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [0]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma_4pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [0]  [0]  [0] ]  = m_MT_R_1pao1ma_4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma_4pawn_R_1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [1]  [0]  [0] ]  = m_MT_R_2ma_4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma_4pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [0]  [1] ]  = m_MT_R_2ma_4pawn_B_1pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma_4pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [1]  [0] ]  = m_MT_R_2ma_4pawn_B_1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma_4pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [0]  [0]  [0] ]  = m_MT_R_2ma_4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma_4pawn_R_1pawn;


	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_1che;	
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_R_1pao5pawn_B_1pao; 
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_R_1pao5pawn_B_1ma;  
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [0]  [1]  [0]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_R_1ma5pawn_B_1che;  
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_R_1ma5pawn_B_1pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_R_1ma5pawn_B_1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [1]  [0]  [0]  [0]  [0] ]  = m_MT_R_1ma5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1pawn;

	//************************************6 ¶Ô 2********************************************************
    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [2]  [0]  [1]  [2]  [0]  [0] ]  = m_MT_R_2che1pao3pawn_B_2che; //2³µ1ÅÚ1±ø¶Ô2³µ
	funMat[MARR->a[0]  [3]  [2]  [0]  [0]  [2]  [0]  [1] ]  = m_MT_B_2che1pao3pawn_R_2che;

	 //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÏà 
	funMat[MARR->a[3]  [0]  [2]  [1]  [0]  [2]  [0]  [0] ]  = m_MT_R_2che1ma3pawn_B_2che; //2³µ1ÅÚ1±ø¶Ô2³µ
	funMat[MARR->a[0]  [3]  [2]  [0]  [0]  [2]  [1]  [0] ]  = m_MT_B_2che1ma3pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [2]  [0]  [0]  [2]  [0]  [0] ]  = m_MT_R_2che4pawn_B_2che;
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [2]  [0]  [0] ]  = m_MT_R_1che1pao1ma3pawn_B_2che;
	funMat[MARR->a[0]  [3]  [2]  [0]  [0]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [2]  [0]  [0] ]  = m_MT_R_1che1pao4pawn_B_2che;  
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_R_1che1pao4pawn_B_1che1pao; 
	funMat[MARR->a[0]  [4]  [1]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [1]  [1]  [0] ]  = m_MT_R_1che1pao4pawn_B_1che1ma;	
	funMat[MARR->a[0]  [4]  [1]  [1]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [2]  [0]  [0] ]  = m_MT_R_1che1ma4pawn_B_2che;
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [1]  [0]  [1] ]  = m_MT_R_1che1ma4pawn_B_1che1pao;
	funMat[MARR->a[0]  [4]  [1]  [0]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che1ma4pawn_B_1che1ma;	
	funMat[MARR->a[0]  [4]  [1]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [2]  [0]  [0] ]  = m_MT_R_1che5pawn_B_2che;
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_R_1che5pawn_B_1che1pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1che1pao; 

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che5pawn_B_1che1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_R_1che5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [0]  [2] ]  = m_MT_R_1che5pawn_B_2pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [2]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [1]  [1] ]  = m_MT_R_1che5pawn_B_1pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [2]  [0] ]  = m_MT_R_1che5pawn_B_2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_R_1che5pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_R_1che5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [1]  [0]  [0]  [0]  [0]  [0] ]  = m_MT_R_1che5pawn_B_2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [1]  [2]  [1]  [0]  [1] ]  = m_MT_R_2pao1ma3pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [3]  [1]  [0]  [1]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [1]  [2]  [1]  [1]  [0] ]  = m_MT_R_2pao1ma3pawn_B_1che1ma; 
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [2]  [1]  [1]  [0]  [1] ]  = m_MT_R_1pao2ma3pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [3]  [1]  [0]  [1]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [2]  [1]  [1]  [1]  [0] ]  = m_MT_R_1pao2ma3pawn_B_1che1ma; 
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [1]  [2]  [1]  [0]  [0] ]  = m_MT_R_2pao_1ma3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0]  [0]  [1]  [2] ]  = m_MT_B_2pao_1ma3pawn_R_1che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [2]  [1]  [1]  [0]  [0] ]  = m_MT_R_1pao_2ma3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0]  [0]  [2]  [1] ]  = m_MT_B_1pao_2ma3pawn_R_1che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [1]  [0]  [0] ]  = m_MT_R_2pao4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [0]  [2] ]  = m_MT_R_2pao4pawn_B_2pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [2]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [1]  [1] ]  = m_MT_R_2pao4pawn_B_1ma1pao;
	funMat[MARR->a[0]  [4]  [0]  [1]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1ma1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [2]  [0] ]  = m_MT_R_2pao4pawn_B_2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [1]  [0]  [0] ]  = m_MT_R_2ma4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [0]  [2] ]  = m_MT_R_2ma4pawn_B_2pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [2]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [1]  [1] ]  = m_MT_R_2ma4pawn_B_1ma1pao;
	funMat[MARR->a[0]  [4]  [0]  [1]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1ma1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [2]  [0] ]  = m_MT_R_2ma4pawn_B_2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [1]  [0]  [0] ]  = m_MT_R_1ma1pao4pawn_B_1che1pawn; 
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [0]  [1]  [1] ]  = m_MT_B_1ma1pao4pawn_R_1che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [0]  [2] ]  = m_MT_R_1ma1pao4pawn_B_2pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [2]  [0]  [1]  [1] ]  = m_MT_B_1ma1pao4pawn_R_2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_R_1ma1pao4pawn_B_1ma1pao;
	funMat[MARR->a[0]  [4]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_B_1ma1pao4pawn_R_1ma1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [2]  [0] ]  = m_MT_R_1ma1pao4pawn_B_2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [0]  [0]  [1]  [1] ]  = m_MT_B_1ma1pao4pawn_R_2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [0]  [0]  [1] ]  = m_MT_R_2pao4pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [0]  [1]  [0] ]  = m_MT_R_2pao4pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [0]  [0]  [1] ]  = m_MT_R_1ma1pao4pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [1]  [0]  [1]  [1] ]  = m_MT_B_1ma1pao4pawn_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [0]  [1]  [0] ]  = m_MT_R_1ma1pao4pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [0]  [0]  [1]  [1] ]  = m_MT_B_1ma1pao4pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [0]  [0]  [1] ]  = m_MT_R_2ma4pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [0]  [1]  [0] ]  = m_MT_R_2ma4pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [0]  [1]  [0]  [0]  [2] ]  = m_MT_R_1pao5pawn_B_2pao;  
	funMat[MARR->a[0]  [5]  [0]  [0]  [2]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_2pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [0]  [1]  [0]  [1]  [1] ]  = m_MT_R_1pao5pawn_B_1pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [1]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1pao1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [0]  [1]  [0]  [2]  [0] ]  = m_MT_R_1pao5pawn_B_2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_R_1pao5pawn_B_1pao1pawn;	
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1pao1pawn; 
	 
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_R_1pao5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [0]  [0]  [1]  [0]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_2pawn;	
	funMat[MARR->a[2]  [5]  [0]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [1]  [0]  [0]  [0]  [2] ]  = m_MT_R_1ma5pawn_B_2pao; 
	funMat[MARR->a[0]  [5]  [0]  [0]  [2]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_2pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [1]  [0]  [0]  [1]  [1] ]  = m_MT_R_1ma5pawn_B_1pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [1]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1pao1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [0]  [1]  [0]  [0]  [2]  [0] ]  = m_MT_R_1ma5pawn_B_2ma; 
	funMat[MARR->a[0]  [5]  [0]  [2]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_R_1ma5pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [0]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_R_1ma5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [0]  [1]  [0]  [0]  [0]  [0] ]  = m_MT_R_1ma5pawn_B_2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_2pawn; 

	//************************************6 ¶Ô 3********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [2]  [0]  [1]  [2]  [0]  [1] ]  = m_MT_R_2che1pao3pawn_B_2che1pao;
	funMat[MARR->a[0]  [3]  [2]  [0]  [1]  [2]  [0]  [1] ]  = m_MT_B_2che1pao3pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [2]  [1]  [0]  [2]  [0]  [1] ]  = m_MT_R_2che1ma3pawn_B_2che1pao;
	funMat[MARR->a[0]  [3]  [2]  [0]  [1]  [2]  [1]  [0] ]  = m_MT_B_2che1ma3pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [2]  [0]  [1]  [2]  [1]  [0] ]  = m_MT_R_2che1pao3pawn_B_2che1ma;
	funMat[MARR->a[0]  [3]  [2]  [1]  [0]  [2]  [0]  [1] ]  = m_MT_B_2che1pao3pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [2]  [1]  [0]  [2]  [1]  [0] ]  = m_MT_R_2che1ma3pawn_B_2che1ma;
	funMat[MARR->a[0]  [3]  [2]  [1]  [0]  [2]  [1]  [0] ]  = m_MT_B_2che1ma3pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [2]  [0]  [0]  [2]  [0]  [1] ]  = m_MT_R_2che4pawn_B_2che1pao;
	funMat[MARR->a[0]  [4]  [2]  [0]  [1]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [2]  [0]  [0]  [2]  [1]  [0] ]  = m_MT_R_2che4pawn_B_2che1ma;
	funMat[MARR->a[0]  [4]  [2]  [1]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [2]  [0]  [0] ]  = m_MT_R_2che4pawn_B_2che1pawn;
	funMat[MARR->a[1]  [4]  [2]  [0]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [2]  [0]  [0]  [1]  [0]  [2] ]  = m_MT_R_2che4pawn_B_1che2pao;
	funMat[MARR->a[0]  [4]  [1]  [0]  [2]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [2]  [0]  [0]  [1]  [1]  [1] ]  = m_MT_R_2che4pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [1]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [2]  [0]  [0]  [1]  [2]  [0] ]  = m_MT_R_2che4pawn_B_1che2ma;
	funMat[MARR->a[0]  [4]  [1]  [2]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_R_2che4pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [1]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che1pao1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [1]  [1]  [0] ]  = m_MT_R_2che4pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [2]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_R_2che4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [1]  [0]  [2]  [2]  [0]  [0] ]  = m_MT_R_1che2pao3pawn_B_2che1pawn;
	funMat[MARR->a[1]  [3]  [2]  [0]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_2che1pawn;


	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [0]  [2]  [1]  [0]  [2] ]  = m_MT_R_1che2pao3pawn_B_1che2pao;   //---------
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che2pao; 

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_R_1che2pao3pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [0]  [2]  [1]  [2]  [0] ]  = m_MT_R_1che2pao3pawn_B_1che2ma;
	funMat[MARR->a[0]  [3]  [1]  [2]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao1ma3pawn_B_2che1pawn;
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao1ma3pawn_B_1che2pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [1]  [1]  [1] ]  = m_MT_R_1che1pao1ma3pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [1]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [1]  [2]  [0] ]  = m_MT_R_1che1pao1ma3pawn_B_1che2ma;
	funMat[MARR->a[0]  [3]  [1]  [2]  [0]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [1]  [2]  [0]  [2]  [0]  [0] ]  = m_MT_R_1che2ma3pawn_B_2che1pawn;
	funMat[MARR->a[1]  [3]  [2]  [0]  [0]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [2]  [0]  [1]  [0]  [2] ]  = m_MT_R_1che2ma3pawn_B_1che2pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [2]  [0]  [1]  [1]  [1] ]  = m_MT_R_1che2ma3pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [1]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [2]  [0]  [1]  [2]  [0] ]  = m_MT_R_1che2ma3pawn_B_1che2ma;
	funMat[MARR->a[0]  [3]  [1]  [2]  [0]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che2ma; //---------

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [0]  [2]  [1]  [1]  [0] ]  = m_MT_R_1che2pao3pawn_B_1che1ma;   
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [1]  [1]  [0] ]  = m_MT_R_1che1pao1ma3pawn_B_1che1ma;   
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [2]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che2ma3pawn_B_1che1ma;   
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [2]  [0]  [1] ]  = m_MT_R_1che1pao4pawn_B_2che1pao;
	funMat[MARR->a[0]  [4]  [2]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [2]  [1]  [0] ]  = m_MT_R_1che1pao4pawn_B_2che1ma;
	funMat[MARR->a[0]  [4]  [2]  [1]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [2]  [0]  [0] ]  = m_MT_R_1che1pao4pawn_B_2che1pawn;
	funMat[MARR->a[1]  [4]  [2]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [1]  [1]  [1] ]  = m_MT_R_1che1pao4pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1pao1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_R_1che1pao4pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [1]  [1]  [0] ]  = m_MT_R_1che1pao4pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao4pawn_B_1che2pao;
	funMat[MARR->a[0]  [4]  [1]  [0]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_R_1che1pao4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [0]  [1]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [0]  [0]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [0]  [2]  [1] ]  = m_MT_R_1che1pao4pawn_B_1pao2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [0]  [1]  [1] ]  = m_MT_R_1che1pao4pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_R_1che1pao4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_R_1che1pao4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [3]  [1]  [0]  [1]  [0]  [0]  [0] ]  = m_MT_R_1che1pao4pawn_B_3pawn;
	funMat[MARR->a[3]  [4]  [0]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [1]  [0]  [2] ]  = m_MT_R_1che1ma4pawn_B_1che2pao;
	funMat[MARR->a[0]  [4]  [1]  [0]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [1]  [1]  [1] ]  = m_MT_R_1che1ma4pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1pao1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [1]  [0]  [1] ]  = m_MT_R_1che1ma4pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che1ma4pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_R_1che1ma4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [0]  [1]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [0]  [0]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [0]  [2]  [1] ]  = m_MT_R_1che1ma4pawn_B_1pao2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [0]  [1]  [1] ]  = m_MT_R_1che1ma4pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_R_1che1ma4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_R_1che1ma4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [3]  [1]  [1]  [0]  [0]  [0]  [0] ]  = m_MT_R_1che1ma4pawn_B_3pawn;
	funMat[MARR->a[3]  [4]  [0]  [0]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [1]  [0]  [1] ]  = m_MT_R_1che5pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1che1pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che5pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [1]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_R_1che5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [1]  [2] ]  = m_MT_R_1che5pawn_B_2pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [0]  [1]  [0]  [0]  [0]  [2]  [1] ]  = m_MT_R_1che5pawn_B_1pao2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [0]  [2] ]  = m_MT_R_1che5pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [2]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [1]  [1] ]  = m_MT_R_1che5pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [2]  [0] ]  = m_MT_R_1che5pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [1]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_R_1che5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [1]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_R_1che5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1ma2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [3]  [1]  [0]  [0]  [0]  [0]  [0] ]  = m_MT_R_1che5pawn_B_3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [0]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [1]  [2]  [1]  [0]  [1] ]  = m_MT_R_2pao1ma3pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [1]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1che1pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [1]  [2]  [1]  [1]  [0] ]  = m_MT_R_2pao1ma3pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [0]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [1]  [2]  [0]  [1]  [2] ]  = m_MT_R_2pao1ma3pawn_B_2pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [1]  [2]  [0]  [2]  [1] ]  = m_MT_R_2pao1ma3pawn_B_1pao2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [2]  [1]  [1]  [0]  [1] ]  = m_MT_R_1pao2ma3pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [1]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1che1pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [2]  [1]  [1]  [1]  [0] ]  = m_MT_R_1pao2ma3pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [0]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [2]  [1]  [0]  [1]  [2] ]  = m_MT_R_1pao2ma3pawn_B_2pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [0]  [2]  [1]  [0]  [2]  [1] ]  = m_MT_R_1pao2ma3pawn_B_1pao2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [0]  [2]  [1]  [0]  [0] ]  = m_MT_R_2pao4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1che2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [1]  [2] ]  = m_MT_R_2pao4pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [0]  [2]  [0]  [2]  [1] ]  = m_MT_R_2pao4pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1pao2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [0]  [0]  [2] ]  = m_MT_R_2pao4pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [2]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_2pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [0]  [1]  [1] ]  = m_MT_R_2pao4pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1pao1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [0]  [2]  [0]  [2]  [0] ]  = m_MT_R_2pao4pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_2ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [0]  [2]  [0]  [0]  [1] ]  = m_MT_R_2pao4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [0]  [2]  [0]  [1]  [0] ]  = m_MT_R_2pao4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [1]  [1]  [1]  [0]  [0] ]  = m_MT_R_1pao1ma4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [1]  [2] ]  = m_MT_R_1pao1ma4pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [1]  [1]  [0]  [2]  [1] ]  = m_MT_R_1pao1ma4pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1pao2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [0]  [0]  [2] ]  = m_MT_R_1pao1ma4pawn_B_2pao1pawn; 
	funMat[MARR->a[1]  [4]  [0]  [0]  [2]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_R_1pao1ma4pawn_B_1pao1ma1pawn; 
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1pao1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [1]  [1]  [0]  [2]  [0] ]  = m_MT_R_1pao1ma4pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [0]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_2ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [1]  [1]  [0]  [0]  [1] ]  = m_MT_R_1pao1ma4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [1]  [1]  [0]  [1]  [0] ]  = m_MT_R_1pao1ma4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [2]  [0]  [1]  [0]  [0] ]  = m_MT_R_2ma4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [1]  [2] ]  = m_MT_R_2ma4pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [0]  [2]  [0]  [0]  [2]  [1] ]  = m_MT_R_2ma4pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1pao2ma;

	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [0]  [0]  [2] ]  = m_MT_R_2ma4pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [2]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_2pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [0]  [1]  [1] ]  = m_MT_R_2ma4pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1pao1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [0]  [2]  [0]  [0]  [2]  [0] ]  = m_MT_R_2ma4pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_2ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [2]  [0]  [0]  [0]  [1] ]  = m_MT_R_2ma4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [2]  [0]  [0]  [1]  [0] ]  = m_MT_R_2ma4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1ma2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [0]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_R_1pao5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [0]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_R_1pao5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_1ma2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [3]  [0]  [0]  [1]  [0]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_3pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [0]  [1]  [0]  [0]  [0]  [1] ]  = m_MT_R_1ma5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [2]  [0]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_R_1ma5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_1ma2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [3]  [0]  [1]  [0]  [0]  [0]  [0] ]  = m_MT_R_1ma5pawn_B_3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_3pawn;

	//************************************6 ¶Ô 4********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [2]  [0]  [1]  [2]  [0]  [2] ]  = m_MT_R_2che1pao3pawn_B_2che2pao; //
	funMat[MARR->a[0]  [3]  [2]  [0]  [2]  [2]  [0]  [1] ]  = m_MT_B_2che1pao3pawn_R_2che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [2]  [1]  [0] ]  = m_MT_R_2che4pawn_B_2che1ma1pawn;
	funMat[MARR->a[1]  [4]  [2]  [1]  [0]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_2che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [1]  [1]  [1] ]  = m_MT_R_2che4pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [1]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [1]  [1]  [1]  [2]  [2]  [0]  [1] ]  = m_MT_R_1che2pao1ma2pawn_B_2che1pao1pawn;
	funMat[MARR->a[1]  [2]  [2]  [0]  [1]  [1]  [1]  [2] ]  = m_MT_B_1che2pao1ma2pawn_R_2che1pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [0]  [2]  [1]  [1]  [2] ]  = m_MT_R_1che2pao3pawn_B_1che2pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [2]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che2pao1ma;	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [0]  [2]  [1]  [2]  [1] ]  = m_MT_R_1che2pao3pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [3]  [1]  [2]  [1]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che1pao2ma;	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [0]  [2]  [1]  [0]  [1] ]  = m_MT_R_1che2pao3pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [1]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che1pao2pawn;	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [0]  [1]  [1]  [1]  [1]  [2]  [1] ]  = m_MT_R_1che1pao1ma3pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [3]  [1]  [2]  [1]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao1ma3pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che2pao1pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [1]  [1]  [1]  [0]  [1] ]  = m_MT_R_1che1pao1ma3pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [1]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [1]  [2]  [0]  [1]  [1]  [1] ]  = m_MT_R_1che2ma3pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [1]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [2]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che2ma3pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [1]  [0]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [1]  [1]  [1] ]  = m_MT_R_1che1pao4pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_R_1che1pao4pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [1]  [0]  [0]  [2]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao2ma; //
	funMat[MARR->a[0]  [4]  [0]  [2]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao2ma;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [0]  [1]  [0]  [1]  [0]  [2]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [0]  [1]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao1ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [0]  [1]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [1]  [1]  [1] ]  = m_MT_R_1che1ma4pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_R_1che1ma4pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [4]  [1]  [1]  [0]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1che1ma2pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [0]  [2]  [1] ]  = m_MT_R_1che1ma4pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao4pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che2pao1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [0]  [2]  [1] ]  = m_MT_R_1che1pao4pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [1]  [2] ]  = m_MT_R_1che5pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [2]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_2pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [1]  [1]  [0]  [0]  [0]  [2]  [1] ]  = m_MT_R_1che5pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [1]  [1]  [0]  [0] ]  = m_MT_B_1che5pawn_R_1pao2ma1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÏà 
	funMat[MARR->a[2]  [1]  [0]  [2]  [2]  [1]  [0]  [2] ]  = m_MT_R_2pao2ma2pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [2]  [0]  [2]  [2] ]  = m_MT_B_2pao2ma2pawn_R_1che2pao1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÏà 
	funMat[MARR->a[2]  [1]  [0]  [2]  [2]  [1]  [1]  [1] ]  = m_MT_R_2pao2ma2pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [1]  [0]  [2]  [2] ]  = m_MT_B_2pao2ma2pawn_R_1che1pao1ma1pawn;

	 //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÏà 
	funMat[MARR->a[3]  [1]  [0]  [1]  [2]  [0]  [1]  [2] ]  = m_MT_R_2pao1ma3pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [2]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_2pao1ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [1]  [2]  [0]  [2]  [1] ]  = m_MT_R_2pao1ma3pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [1]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [2]  [1]  [0]  [2]  [1] ]  = m_MT_R_1pao2ma3pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [1]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [0]  [2]  [1]  [0]  [1]  [2] ]  = m_MT_R_1pao2ma3pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [2]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_2pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [0]  [2]  [0]  [1]  [1] ]  = m_MT_R_2pao4pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [1]  [0]  [0]  [2] ]  = m_MT_B_2pao4pawn_R_1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_R_1pao1ma4pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [4]  [0]  [0]  [1]  [0]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_4pawn;
	funMat[MARR->a[4]  [5]  [0]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_4pawn;
		
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [4]  [0]  [1]  [0]  [0]  [0]  [0] ]  = m_MT_R_1ma5pawn_B_4pawn;
	funMat[MARR->a[4]  [5]  [0]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_4pawn;
	
	//************************************6 ¶Ô 5********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [3]  [2]  [1]  [1]  [2]  [0]  [0] ]  = m_MT_R_2che1pao1ma2pawn_B_2che3pawn; //
	funMat[MARR->a[3]  [2]  [2]  [0]  [0]  [2]  [1]  [1] ]  = m_MT_B_2che1pao1ma2pawn_R_2che3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [2]  [0]  [1]  [2]  [1]  [0] ]  = m_MT_R_2che1pao3pawn_B_2che1ma2pawn; //
	funMat[MARR->a[2]  [3]  [2]  [1]  [0]  [2]  [0]  [1] ]  = m_MT_B_2che1pao3pawn_R_2che1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [2]  [1]  [0]  [2]  [1]  [0] ]  = m_MT_R_2che1ma3pawn_B_2che1ma2pawn; //
	funMat[MARR->a[2]  [3]  [2]  [1]  [0]  [2]  [1]  [0] ]  = m_MT_B_2che1ma3pawn_R_2che1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [1]  [1]  [2] ]  = m_MT_R_2che4pawn_B_1che2pao1ma1pawn; //
	funMat[MARR->a[1]  [4]  [1]  [1]  [2]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che2pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [2]  [0]  [0]  [1]  [2]  [1] ]  = m_MT_R_2che4pawn_B_1che1pao2ma1pawn; //
	funMat[MARR->a[1]  [4]  [1]  [2]  [1]  [2]  [0]  [0] ]  = m_MT_B_2che4pawn_R_1che1pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [2]  [1]  [1]  [2]  [1]  [2]  [0] ]  = m_MT_R_1che2pao1ma2pawn_B_1che2ma2pawn;
	funMat[MARR->a[2]  [2]  [1]  [2]  [0]  [1]  [1]  [2] ]  = m_MT_B_1che2pao1ma2pawn_R_1che2ma2pawn; //	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [1]  [0]  [2]  [2]  [0]  [0] ]  = m_MT_R_1che2pao3pawn_B_2che3pawn;
	funMat[MARR->a[3]  [3]  [2]  [0]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_2che3pawn; //	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_R_1che2pao3pawn_B_1che1pao1ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che1pao1ma2pawn; //	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [0]  [2]  [1]  [2]  [0] ]  = m_MT_R_1che2pao3pawn_B_1che2ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [2]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che2ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [1]  [2]  [0]  [1]  [1]  [2] ]  = m_MT_R_1che2ma3pawn_B_1che2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [2]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_1che2pao1ma1pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [1]  [1]  [1]  [2]  [0]  [0] ]  = m_MT_R_1che1pao1ma3pawn_B_2che3pawn;
	funMat[MARR->a[3]  [3]  [2]  [0]  [0]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_2che3pawn; //	

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [1]  [1]  [1]  [1]  [1]  [1]  [2] ]  = m_MT_R_1che1pao1ma3pawn_B_1che2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [2]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che2pao1ma1pawn; //

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [1]  [1]  [1]  [1]  [1] ]  = m_MT_R_1che1pao1ma3pawn_B_1che1pao1ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [1]  [1]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che1pao1ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao1ma3pawn_B_1che2pao2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che2pao2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [1]  [0]  [2]  [2]  [0]  [0] ]  = m_MT_R_1che2pao3pawn_B_2che3pawn;
	funMat[MARR->a[3]  [3]  [2]  [0]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_2che3pawn; //	

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [0]  [1]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao1ma2pawn; //
	funMat[MARR->a[2]  [4]  [0]  [1]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [1]  [1]  [1] ]  = m_MT_R_1che1pao4pawn_B_1che1pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [1]  [1]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [1]  [0]  [2] ]  = m_MT_R_1che1pao4pawn_B_1che2pao2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1che2pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [0]  [1]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [0]  [2]  [1] ]  = m_MT_R_1che1ma4pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [2]  [1]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_1pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [0]  [1]  [0]  [2]  [1] ]  = m_MT_R_1che1pao4pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [2]  [1]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_1pao2ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [1]  [0]  [0]  [2]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao2ma1pawn; //
	funMat[MARR->a[1]  [4]  [0]  [2]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [1]  [1]  [0]  [1]  [0]  [2]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [2]  [1]  [0]  [1] ]  = m_MT_B_1che1pao4pawn_R_2pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [3]  [0]  [2]  [2]  [1]  [0]  [1] ]  = m_MT_R_2pao2ma2pawn_B_1che1pao3pawn; //saf
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [0]  [2]  [2] ]  = m_MT_B_2pao2ma2pawn_R_1che1pao3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [3]  [0]  [2]  [2]  [1]  [1]  [0] ]  = m_MT_R_2pao2ma2pawn_B_1che1ma3pawn; //saf
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [0]  [2]  [2] ]  = m_MT_B_2pao2ma2pawn_R_1che1ma3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [1]  [0]  [2]  [2]  [0]  [2]  [2] ]  = m_MT_R_2pao2ma2pawn_B_2pao2ma1pawn; //saf
	funMat[MARR->a[1]  [2]  [0]  [2]  [2]  [0]  [2]  [2] ]  = m_MT_B_2pao2ma2pawn_R_2pao2ma1pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [0]  [1]  [2]  [1]  [1]  [0] ]  = m_MT_R_2pao1ma3pawn_B_1che1ma3pawn; //saf
	funMat[MARR->a[3]  [3]  [1]  [1]  [0]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1che1ma3pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [0]  [2]  [1]  [1]  [1]  [0] ]  = m_MT_R_1pao2ma3pawn_B_1che1ma3pawn; //saf
	funMat[MARR->a[3]  [3]  [1]  [1]  [0]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1che1ma3pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [0]  [1]  [2]  [0]  [1]  [2] ]  = m_MT_R_2pao1ma3pawn_B_2pao1ma2pawn; //saf
	funMat[MARR->a[2]  [3]  [0]  [1]  [2]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_2pao1ma2pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [0]  [1]  [2]  [0]  [2]  [1] ]  = m_MT_R_2pao1ma3pawn_B_1pao2ma2pawn; //saf
	funMat[MARR->a[2]  [3]  [0]  [2]  [1]  [0]  [1]  [2] ]  = m_MT_B_2pao1ma3pawn_R_1pao2ma2pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [0]  [2]  [1]  [0]  [1]  [2] ]  = m_MT_R_1pao2ma3pawn_B_2pao1ma2pawn; //saf
	funMat[MARR->a[2]  [3]  [0]  [1]  [2]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_2pao1ma2pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [1]  [1]  [0]  [2]  [1] ]  = m_MT_R_1pao1ma4pawn_B_1pao2ma2pawn; //saf
	funMat[MARR->a[2]  [4]  [0]  [2]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1pao2ma2pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [1]  [1]  [0]  [1]  [2] ]  = m_MT_R_1pao1ma4pawn_B_2pao1ma2pawn; //saf
	funMat[MARR->a[2]  [4]  [0]  [1]  [2]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_2pao1ma2pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[4]  [3]  [0]  [1]  [1]  [0]  [0]  [2] ]  = m_MT_R_1pao1ma4pawn_B_2pao3pawn; //saf
	funMat[MARR->a[3]  [4]  [0]  [0]  [2]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_2pao3pawn;

	//            ºì±ø  ºÚ×ä ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚ 
	funMat[MARR->a[4]  [3]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_R_1pao1ma4pawn_B_1pao1ma3pawn; //saf
	funMat[MARR->a[3]  [4]  [0]  [1]  [1]  [0]  [1]  [1] ]  = m_MT_B_1pao1ma4pawn_R_1pao1ma3pawn;

	//            ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [0]  [2]  [1]  [0]  [2]  [1] ]  = m_MT_R_1pao2ma3pawn_B_1pao2ma2pawn; //saf
	funMat[MARR->a[2]  [3]  [0]  [2]  [1]  [0]  [2]  [1] ]  = m_MT_B_1pao2ma3pawn_R_1pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [2]  [0]  [0]  [2]  [1] ]  = m_MT_R_2ma4pawn_B_1pao2ma2pawn; //saf
	funMat[MARR->a[2]  [4]  [0]  [2]  [1]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_1pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [0]  [2]  [0]  [0]  [1]  [2] ]  = m_MT_R_2ma4pawn_B_2pao1ma2pawn; //saf
	funMat[MARR->a[2]  [4]  [0]  [1]  [2]  [0]  [2]  [0] ]  = m_MT_B_2ma4pawn_R_2pao1ma2pawn;


	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [5]  [0]  [0]  [1]  [0]  [0]  [0] ]  = m_MT_R_1pao5pawn_B_5pawn;
	funMat[MARR->a[5]  [5]  [0]  [0]  [0]  [0]  [0]  [1] ]  = m_MT_B_1pao5pawn_R_5pawn;
	
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[5]  [5]  [0]  [1]  [0]  [0]  [0]  [0] ]  = m_MT_R_1ma5pawn_B_5pawn;
	funMat[MARR->a[5]  [5]  [0]  [0]  [0]  [0]  [1]  [0] ]  = m_MT_B_1ma5pawn_R_5pawn;	

	//************************************6 ¶Ô 6********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [2]  [0]  [0]  [1]  [1]  [2]] = m_MT_R_2che4pawn_B_1che2pao1ma2pawn; //
	funMat[MARR->a[2]  [4]  [1]  [1]  [2]  [2]  [0]  [0]] = m_MT_B_2che4pawn_R_1che2pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [2]  [0]  [0]  [1]  [2]  [1]] = m_MT_R_2che4pawn_B_1che1pao2ma2pawn; //
	funMat[MARR->a[2]  [4]  [1]  [2]  [1]  [2]  [0]  [0]] = m_MT_B_2che4pawn_R_1che1pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [2]  [1]  [1]  [2]  [1]  [2]  [1] ]  = m_MT_R_1che2pao1ma2pawn_B_1che1pao2ma2pawn; //
	funMat[MARR->a[2]  [2]  [1]  [2]  [1]  [1]  [1]  [2] ]  = m_MT_B_1che2pao1ma2pawn_R_1che1pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [1]  [0]  [2]  [1]  [1]  [1] ]  = m_MT_R_1che2pao3pawn_B_1che1pao1ma3pawn; //
	funMat[MARR->a[3]  [3]  [1]  [1]  [1]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che1pao1ma3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [1]  [0]  [2]  [1]  [2]  [0] ]  = m_MT_R_1che2pao3pawn_B_1che2ma3pawn; //
	funMat[MARR->a[3]  [3]  [1]  [2]  [0]  [1]  [0]  [2] ]  = m_MT_B_1che2pao3pawn_R_1che2ma3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [3]  [1]  [1]  [1]  [1]  [2]  [0] ]  = m_MT_R_1che1pao1ma3pawn_B_1che2ma3pawn; //
	funMat[MARR->a[3]  [3]  [1]  [2]  [0]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che2ma3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ
	funMat[MARR->a[3]  [4]  [1]  [1]  [1]  [1]  [1]  [0] ]  = m_MT_R_1che1pao1ma3pawn_B_1che1ma4pawn; //
	funMat[MARR->a[4]  [3]  [1]  [1]  [0]  [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma3pawn_R_1che1ma4pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[3]  [2]  [1]  [2]  [0]  [0]  [2]  [2] ]  = m_MT_R_1che2ma3pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [3]  [0]  [2]  [2]  [1]  [2]  [0] ]  = m_MT_B_1che2ma3pawn_R_2pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [0]  [2]  [2] ]  = m_MT_R_1che1ma4pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [4]  [0]  [2]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1ma4pawn_R_2pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[4]  [2]  [1]  [1]  [0]  [0]  [2]  [2] ]  = m_MT_R_1che1pao4pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [4]  [0]  [2]  [2]  [1]  [1]  [0] ]  = m_MT_B_1che1pao4pawn_R_2pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ 
	funMat[MARR->a[2]  [3]  [0]  [2]  [2]  [0]  [1]  [2] ]  = m_MT_R_2pao2ma2pawn_B_2pao1ma3pawn; //
	funMat[MARR->a[3]  [2]  [0]  [1]  [2]  [0]  [2]  [2] ]  = m_MT_B_2pao2ma2pawn_R_2pao1ma3pawn;

}