#ifndef E_InitMatFunction2
#define E_InitMatFunction2
#include "..\\chess.h"
 
#include "..\\white.h"
#else
#include "..\\black.h"
#endif

void InitMatFunction2(void){
	//********************************************* ¶þ¶ÔÎÞ*******************************************************

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [0]  [0]  [0]  ]  = m_MT_R_2pao_B_NO;
	funMat[MARR->a[0]  [0]  [0]  [0]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_NO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [0]  [0]  [0]  ]  = m_MT_R_1PAO1ma_B_NO;
	funMat[MARR->a[0]  [0]  [0]  [0]  [0]    [0]  [1]  [1]  ]  = m_MT_B_1PAO1ma_R_NO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [0]  [0]  [0]  ]  = m_MT_R_1PAO1PAWN_B_NO;
	funMat[MARR->a[0]  [1]  [0]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_B_1PAO1PAWN_R_NO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [0]  [0]  [0]  ]  = m_MT_R_1MA1PAWN_B_NO;
	funMat[MARR->a[0]  [1]  [0]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_B_1MA1PAWN_R_NO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[2]  [0]  [0]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_R_2PAWN;
	funMat[MARR->a[0]  [2]  [0]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_B_2PAWN;

	//************************************* ¶þ¶ÔÒ»**************************************************
	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_R_2CHE_B_1CHE;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]    [2]  [0]  [0]  ]  = m_MT_B_2CHE_R_1CHE;
	
	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]    [1]  [0]  [0]  ]  = m_MT_R_1CHE1PAO_B_1CHE;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]    [1]  [0]  [1]  ]  = m_MT_B_1CHE1PAO_R_1CHE;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]    [1]  [0]  [0]  ]  = m_MT_R_1CHE1MA_B_1CHE;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]    [1]  [1]  [0]  ]  = m_MT_B_1CHE1MA_R_1CHE;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_R_1CHE1PAWN_B_1CHE;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_B_1CHE1PAWN_R_1CHE;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_R_1che1pawn_B_1pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [1]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_1pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_R_1che1pawn_B_1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [0]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_R_1che1pawn_B_1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [1]  [0]  [0]  ]  = m_MT_R_2pao_B_1che;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1che;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [0]  [0]  [1]  ]  = m_MT_R_2pao_B_1pao;
	funMat[MARR->a[0]  [0]  [0]  [0]  [1]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [0]  [1]  [0]  ]  = m_MT_R_2pao_B_1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]    [0]  [0]  [0]  ]  = m_MT_R_2pao_B_1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1pawn;
	

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [1]  [0]  [0]  ]  = m_MT_R_1pao1ma_B_1che;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_1che;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [0]  [0]  [1]  ]  = m_MT_R_1pao1ma_B_1pao;
	funMat[MARR->a[0]  [0]  [0]  [0]  [1]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_1pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [0]  [1]  [0]  ]  = m_MT_R_1pao1ma_B_1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [0]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]    [0]  [0]  [0]  ]  = m_MT_R_1pao1ma_B_1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [0]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [2]  [0]    [1]  [0]  [0]  ]  = m_MT_R_2ma_B_1che;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]    [0]  [2]  [0]  ]  = m_MT_B_2ma_R_1che;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [2]  [0]    [0]  [0]  [1]  ]  = m_MT_R_2ma_B_1pao;
	funMat[MARR->a[0]  [0]  [0]  [0]  [1]    [0]  [2]  [0]  ]  = m_MT_B_2ma_R_1pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [2]  [0]    [0]  [1]  [0]  ]  = m_MT_R_2ma_B_1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [0]    [0]  [2]  [0]  ]  = m_MT_B_2ma_R_1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [1]  [0]  [0]  ]  = m_MT_R_1PAO1PAWN_B_1CHE;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_B_1PAO1PAWN_R_1CHE;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [0]  [0]  [1]  ]  = m_MT_R_1PAO1PAWN_B_1PAO;
	funMat[MARR->a[0]  [1]  [0]  [0]  [1]    [0]  [0]  [1]  ]  = m_MT_B_1PAO1PAWN_R_1PAO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [0]  [1]  [0]  ]  = m_MT_R_1PAO1PAWN_B_1MA;
	funMat[MARR->a[0]  [1]  [0]  [1]  [0]    [0]  [0]  [1]  ]  = m_MT_B_1PAO1PAWN_R_1MA;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]    [0]  [0]  [0]  ]  = m_MT_R_1PAO1PAWN_B_1PAWN;
	funMat[MARR->a[1]  [1]  [0]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_B_1PAO1PAWN_R_1PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [1]  [0]  [0]  ]  = m_MT_R_1MA1PAWN_B_1CHE;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_B_1MA1PAWN_R_1CHE;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [0]  [0]  [1]  ]  = m_MT_R_1MA1PAWN_B_1PAO;
	funMat[MARR->a[0]  [1]  [0]  [0]  [1]    [0]  [1]  [0]  ]  = m_MT_B_1MA1PAWN_R_1PAO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [0]  [1]  [0]  ]  = m_MT_R_1MA1PAWN_B_1MA;
	funMat[MARR->a[0]  [1]  [0]  [1]  [0]    [0]  [1]  [0]  ]  = m_MT_B_1MA1PAWN_R_1MA;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]    [0]  [0]  [0]  ]  = m_MT_R_1MA1PAWN_B_1PAWN;
	funMat[MARR->a[1]  [1]  [0]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_B_1MA1PAWN_R_1PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[2]  [0]  [0]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_R_2PAWN_B_1CHE;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_B_2PAWN_R_1CHE;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[2]  [0]  [0]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_R_2pawn_B_1pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1]    [0]  [0]  [0]  ]  = m_MT_B_2pawn_R_1pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[2]  [0]  [0]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_R_2PAWN_B_1MA;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0]    [0]  [0]  [0]  ]  = m_MT_B_2PAWN_R_1MA;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[2]  [1]  [0]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_R_2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_B_2pawn_R_1pawn;

	//************************************* ¶þ¶Ô¶þ****************************************************

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]    [2]  [0]  [0]  ]  = m_MT_2che_2che;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]    [1]  [0]  [1]  ]  = m_MT_R_2CHE_B_1CHE1PAO;
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]    [2]  [0]  [0]  ]  = m_MT_B_2CHE_R_1CHE1PAO;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]    [1]  [1]  [0]  ]  = m_MT_R_2CHE_B_1CHE1MA;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]    [2]  [0]  [0]  ]  = m_MT_B_2CHE_R_1CHE1MA;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [2]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_R_2CHE_B_1CHE1PAWN;
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [2]  [0]  [0]  ]  = m_MT_B_2CHE_R_1CHE1PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]    [0]  [1]  [1]  ]  = m_MT_R_2che_B_1pao1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [2]  [0]  [0]  ]  = m_MT_B_2che_R_1pao1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]    [0]  [0]  [2]  ]  = m_MT_R_2che_B_2pao;
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [2]  [0]  [0]  ]  = m_MT_B_2che_R_2pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]    [1]  [0]  [1]  ]  = m_MT_1che1pao_1che1pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]    [1]  [1]  [0]  ]  = m_MT_R_1che1pao_B_1che1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]    [1]  [0]  [1]  ]  = m_MT_B_1che1pao_R_1che1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [1]  [0]  [1]    [1]  [0]  [0]  ]  = m_MT_R_1CHE1PAO_B_1CHE1PAWN;
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [1]  [0]  [1]  ]  = m_MT_B_1CHE1PAO_R_1CHE1PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]    [0]  [0]  [2]  ]  = m_MT_R_1che1pao_B_2pao;
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [1]  [0]  [1]  ]  = m_MT_B_1che1pao_R_2pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]    [0]  [1]  [1]  ]  = m_MT_R_1che1pao_B_1pao1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [1]  [0]  [1]  ]  = m_MT_B_1che1pao_R_1pao1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]    [1]  [1]  [0]  ]  = m_MT_1che1ma_1che1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]    [1]  [0]  [0]  ]  = m_MT_R_1che1ma_B_1che1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [1]  [1]  [0]  ]  = m_MT_B_1che1ma_R_1che1pawn;

	//            ºì±ø  ºÚ×ä  ºì³µ ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]    [0]  [0]  [2]  ]  = m_MT_R_1che1ma_B_2pao;
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [1]  [1]  [0]  ]  = m_MT_B_1che1ma_R_2pao;

	//            ºì±ø  ºÚ×ä  ºì³µ ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]    [0]  [1]  [1]  ]  = m_MT_R_1che1ma_B_1pao1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [1]  [1]  [0]  ]  = m_MT_B_1che1ma_R_1pao1ma;

	//            ºì±ø  ºÚ×ä  ºì³µ ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]    [0]  [0]  [1]  ]  = m_MT_R_1che1ma_B_1pao1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [1]  [1]  [0]  ]  = m_MT_B_1che1ma_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_1CHE1PAWN_TO_1CHE1PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [0]  [0]  [2]  ]  = m_MT_R_1che1pawn_B_2pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_2pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [0]  [1]  [1]  ]  = m_MT_R_1che1pawn_B_1pao1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_1pao1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]    [0]  [2]  [0]  ]  = m_MT_R_1che1pawn_B_2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [0]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_2ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_R_1che1pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_R_1che1pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_1ma1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [2]  [1]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_R_1che1pawn_B_2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [0]    [1]  [0]  [0]  ]  = m_MT_B_1che1pawn_R_2pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [0]  [0]  [2]  ]  = m_MT_R_2pao_B_2pao;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [0]  [1]  [1]  ]  = m_MT_R_2pao_B_1pao1ma;
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1pao1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [0]  [2]    [0]  [2]  [0]  ]  = m_MT_R_2pao_B_2ma;
	funMat[MARR->a[0]  [0]  [0]  [2]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_2ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]    [0]  [0]  [1]  ]  = m_MT_R_2pao_B_1pao1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]    [0]  [1]  [0]  ]  = m_MT_R_2pao_B_1ma1pawn;
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_1ma1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [2]  [0]  [0]  [2]    [0]  [0]  [0]  ]  = m_MT_R_2pao_B_2pawn;
	funMat[MARR->a[2]  [0]  [0]  [0]  [0]    [0]  [0]  [2]  ]  = m_MT_B_2pao_R_2pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [0]  [1]  [1]  ]  = m_MT_BR_1pao1ma_B_1pao1ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [1]  [1]    [0]  [2]  [0]  ]  = m_MT_R_1pao1ma_B_2ma;
	funMat[MARR->a[0]  [0]  [0]  [2]  [0]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_2ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]    [0]  [0]  [1]  ]  = m_MT_R_1pao1ma_B_1pao1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]    [0]  [1]  [0]  ]  = m_MT_R_1pao1ma_B_1ma1pawn;
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_R_1ma1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [0]  [0]  [2]  [0]    [0]  [2]  [0]  ]  = m_MT_R_2ma_B_2ma;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [2]  [0]    [0]  [0]  [1]  ]  = m_MT_R_2ma_B_1pao1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [1]    [0]  [2]  [0]  ]  = m_MT_B_2ma_R_1pao1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[0]  [1]  [0]  [2]  [0]    [0]  [1]  [0]  ]  = m_MT_R_2ma_B_1ma1pawn;
	funMat[MARR->a[1]  [0]  [0]  [1]  [0]    [0]  [2]  [0]  ]  = m_MT_B_2ma_R_1ma1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]    [0]  [0]  [1]  ]  = m_MT_PaoPawn_To_PaoPawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]    [0]  [1]  [0]  ]  = m_MT_R_1pao1pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]    [0]  [0]  [1]  ]  = m_MT_B_1pao1pawn_R_1ma1pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [2]  [0]  [0]  [1]    [0]  [0]  [0]  ]  = m_MT_R_1pao1pawn_B_2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [0]    [0]  [0]  [1]  ]  = m_MT_B_1pao1pawn_R_2pawn;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]    [0]  [1]  [0]  ]  = m_MT_1MA1PAWN_1MA1PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[1]  [2]  [0]  [1]  [0]    [0]  [0]  [0]  ]  = m_MT_R_1MA1PAWN_B_2PAWN;
	funMat[MARR->a[2]  [1]  [0]  [0]  [0]    [0]  [1]  [0]  ]  = m_MT_B_1MA1PAWN_R_2PAWN;

	//           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ    ºÚ³µ  ºÚÂí  ºÚÅÚ  
	funMat[MARR->a[2]  [2]  [0]  [0]  [0]    [0]  [0]  [0]  ]  = m_MT_2pawn_TO_2pawn;

}