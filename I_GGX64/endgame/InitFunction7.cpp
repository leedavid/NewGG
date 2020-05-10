#ifndef E_InitMatFunction7
#define E_InitMatFunction7
#include "..\\chess.h"
 
#include "..\\white.h"
#else
#include "..\\black.h"
#endif

void InitMatFunction7(void){

	//********************************************* 7 ¶Ô 0*****************************************************************
	//********************************************* 7 ¶Ô 1*****************************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma4pawn_R_1che;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma4pawn_R_1che;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_5pawn_B_1che;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao_5pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_R_2pao_5pawn_B_1pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao_5pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_R_2pao_5pawn_B_1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao_5pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [0]  [0]  [0]  ]  = m_MT_R_2pao_5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao_5pawn_R_1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_1ma5pawn_B_1che;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao_1ma5pawn_R_1che;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1pao1ma_5pawn_B_1pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_5pawn_R_1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1pao1ma_5pawn_B_1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_5pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao1ma_5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_5pawn_R_1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2ma_5pawn_B_1che;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma_5pawn_R_1che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_R_2ma_5pawn_B_1pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma_5pawn_R_1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_R_2ma_5pawn_B_1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma_5pawn_R_1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [0]  [0]  [0]  ]  = m_MT_R_2ma_5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma_5pawn_R_1pawn;


	//************************************7 ¶Ô 2*********************************************************
    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [2]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_2che1pao4pawn_B_2che; //2³µ1ÅÚ1±ø¶Ô2³µ
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao4pawn_R_2che;

	 //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[4]  [0]  [2]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che1ma4pawn_B_2che; //2³µ1ÅÚ1±ø¶Ô2³µ
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma4pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che5pawn_B_2che;
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_2che;	
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao1ma4pawn_B_2che;
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_2che;	
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao5pawn_B_2che;  
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2che;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1che1pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao5pawn_B_1che1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che1ma5pawn_B_2che;
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2che;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1che1pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che1ma5pawn_B_1che1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao1ma4pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [4]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma4pawn_B_1che1ma; 
	funMat[MARR->a[0]  [4]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1pao2ma4pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [4]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma4pawn_B_1che1ma; 
	funMat[MARR->a[0]  [4]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_1che1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma4pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma4pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_R_2pao5pawn_B_2pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_2pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao5pawn_B_1ma1pao;
	funMat[MARR->a[0]  [5]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1ma1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_R_2pao5pawn_B_2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_R_2ma5pawn_B_2pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_2pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_R_2ma5pawn_B_1ma1pao;
	funMat[MARR->a[0]  [5]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1ma1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_R_2ma5pawn_B_2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1ma1pao5pawn_B_1che1pawn; 
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao5pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1ma1pao5pawn_B_2pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao5pawn_R_2pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1ma1pao5pawn_B_1ma1pao;
	funMat[MARR->a[0]  [5]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao5pawn_R_1ma1pao;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1ma1pao5pawn_B_2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao5pawn_R_2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_R_2pao5pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_R_2pao5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1ma1pao5pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao5pawn_R_1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1ma1pao5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao5pawn_R_1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2ma5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_R_2ma5pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_R_2ma5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1ma1pawn;	

	//************************************7 ¶Ô 3*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_R_2che1pao4pawn_B_2che1pao;
	funMat[MARR->a[0]  [4]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao4pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_R_2che1ma4pawn_B_2che1pao;
	funMat[MARR->a[0]  [4]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma4pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_R_2che1pao4pawn_B_2che1ma;
	funMat[MARR->a[0]  [4]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao4pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [2]  [1]  [0]  [2]  [1]  [0]  ]  = m_MT_R_2che1ma4pawn_B_2che1ma;
	funMat[MARR->a[0]  [4]  [2]  [1]  [0]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma4pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [0]  [2]  [0]  [1]  ]  = m_MT_R_2che5pawn_B_2che1pao;
	funMat[MARR->a[0]  [5]  [2]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [0]  [2]  [1]  [0]  ]  = m_MT_R_2che5pawn_B_2che1ma;
	funMat[MARR->a[0]  [5]  [2]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che5pawn_B_2che1pawn;
	funMat[MARR->a[1]  [5]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_2che1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_R_2che5pawn_B_1che2pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_R_2che5pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [0]  [1]  [2]  [0]  ]  = m_MT_R_2che5pawn_B_1che2ma;
	funMat[MARR->a[0]  [5]  [1]  [2]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_R_2che5pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che1pao1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [2]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_R_2che5pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [2]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2che5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_R_1che2pao4pawn_B_2che1pawn;
	funMat[MARR->a[1]  [4]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_R_1che2pao4pawn_B_1che2pao;   //---------
	funMat[MARR->a[0]  [4]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che2pao; 

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao4pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_R_1che2pao4pawn_B_1che2ma;
	funMat[MARR->a[0]  [4]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che2ma;
    
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao1ma4pawn_B_2che1pawn;
	funMat[MARR->a[1]  [4]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao1ma4pawn_B_1che2pao;
	funMat[MARR->a[0]  [4]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao1ma4pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_R_1che1pao1ma4pawn_B_1che2ma;
	funMat[MARR->a[0]  [4]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [1]  [2]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che2ma4pawn_B_2che1pawn;
	funMat[MARR->a[1]  [4]  [2]  [0]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_R_1che2ma4pawn_B_1che2pao;
	funMat[MARR->a[0]  [4]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che2ma4pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [2]  [0]  [1]  [2]  [0]  ]  = m_MT_R_1che2ma4pawn_B_1che2ma;
	funMat[MARR->a[0]  [4]  [1]  [2]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che2ma; //---------

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_R_1che1pao5pawn_B_2che1pao;
	funMat[MARR->a[0]  [5]  [2]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_R_1che1pao5pawn_B_2che1ma;
	funMat[MARR->a[0]  [5]  [2]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao5pawn_B_2che1pawn;
	funMat[MARR->a[1]  [5]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao5pawn_B_1che2pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao5pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1che1pao5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che2pawn;    ////////////

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1pao2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1che1pao5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [3]  [1]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1che1pao5pawn_B_3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1pao1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che1ma5pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1che1ma5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1pao2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1che1ma5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [3]  [1]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1che1ma5pawn_B_3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma4pawn_B_2pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma4pawn_B_1pao2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao2ma4pawn_B_2pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma4pawn_B_1pao2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao5pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [0]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao5pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1pao2ma;

	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_R_2pao5pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_2pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao5pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1pao1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_R_2pao5pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_2ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_R_2pao5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_R_2pao5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao5pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao1ma5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao1ma5pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao1ma5pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_1pao2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1pao1ma5pawn_B_2pao1pawn;  
	funMat[MARR->a[1]  [5]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao1ma5pawn_B_1pao1ma1pawn;  
	funMat[MARR->a[1]  [5]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_1pao1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1pao1ma5pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_2ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1pao1ma5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1pao1ma5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma5pawn_R_1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2ma5pawn_B_1che2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [1]  [2]  ]  = m_MT_R_2ma5pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [0]  [0]  [2]  [1]  ]  = m_MT_R_2ma5pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1pao2ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_R_2ma5pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_2pao1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_R_2ma5pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1pao1ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_R_2ma5pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_2ma1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_R_2ma5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_R_2ma5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma5pawn_R_1ma2pawn;	
	
	//************************************7 ¶Ô 4*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_R_2che5pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [1]  [1]  [1]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao1ma3pawn_B_1che1pao1ma1pawn; //
	funMat[MARR->a[1]  [3]  [1]  [1]  [1]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma3pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [1]  [1]  [2]  [1]  [2]  [1]  [0]  ]  = m_MT_R_1che1pao2ma3pawn_B_2che1ma1pawn; //
	funMat[MARR->a[1]  [3]  [2]  [1]  [0]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_2che1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [1]  [2]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao2ma3pawn_B_2che2pawn; //
	funMat[MARR->a[2]  [3]  [2]  [0]  [0]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_2che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [1]  [1]  [2]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma1pawn; //
	funMat[MARR->a[1]  [3]  [1]  [1]  [1]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [0]  [2]  [1]  [2]  [1]  ]  = m_MT_R_1che2pao4pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [4]  [1]  [2]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_R_1che2ma4pawn_B_1che2pao2pawn; //
	funMat[MARR->a[2]  [4]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che2pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [0]  [1]  [1]  [1]  [1]  [2]  [1]  ]  = m_MT_R_1che1pao1ma4pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [4]  [1]  [2]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_1che1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao1ma4pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che2ma4pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao2ma; //
	funMat[MARR->a[0]  [5]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao2ma;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao1ma1pawn;

     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2pao1ma1pawn;

     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [1]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1pao1ma1pawn;

     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [1]  [0]  [2]  [2]  [1]  [0]  [2]  ]  = m_MT_R_2pao2ma3pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [2]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma3pawn_R_1che2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [1]  [0]  [2]  [2]  [1]  [1]  [1]  ]  = m_MT_R_2pao2ma3pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [1]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma3pawn_R_1che1pao1ma1pawn;

	 //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[4]  [1]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma4pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_2pao1ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma4pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_1pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma4pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_1pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma4pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_2pao1ma1pawn;
	//************************************7 ¶Ô 5*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [2]  [0]  [1]  [2]  [0]  [2]  ]  = m_MT_R_2che1pao4pawn_B_2che2pao1pawn; //
	funMat[MARR->a[1]  [4]  [2]  [0]  [2]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao4pawn_R_2che2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_R_2che1pao4pawn_B_2che1ma2pawn; //
	funMat[MARR->a[2]  [4]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao4pawn_R_2che1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [2]  [0]  [0]  [1]  [1]  [2]  ]  = m_MT_R_2che5pawn_B_1che2pao1ma1pawn; //
	funMat[MARR->a[1]  [5]  [1]  [1]  [2]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che2pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [2]  [0]  [0]  [1]  [2]  [1]  ]  = m_MT_R_2che5pawn_B_1che1pao2ma1pawn; //
	funMat[MARR->a[1]  [5]  [1]  [2]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che5pawn_R_1che1pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [1]  [1]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao1ma3pawn_B_1che1pao1ma2pawn; //
	funMat[MARR->a[2]  [3]  [1]  [1]  [1]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma3pawn_R_1che1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_R_1che2pao4pawn_B_1che2pao2pawn; //
	funMat[MARR->a[2]  [4]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che2pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [1]  [2]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma2pawn; //
	funMat[MARR->a[2]  [3]  [1]  [1]  [1]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_1che1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [1]  [1]  [2]  [2]  [1]  [0]  ]  = m_MT_R_1che2pao1ma3pawn_B_2che1ma2pawn; //
	funMat[MARR->a[2]  [3]  [2]  [1]  [0]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma3pawn_R_2che1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [1]  [2]  [1]  [2]  [1]  [0]  ]  = m_MT_R_1che1pao2ma3pawn_B_2che1ma2pawn; //
	funMat[MARR->a[2]  [3]  [2]  [1]  [0]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_2che1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [1]  [2]  [1]  [2]  [0]  [1]  ]  = m_MT_R_1che1pao2ma3pawn_B_2che1pao2pawn; //
	funMat[MARR->a[2]  [3]  [2]  [0]  [1]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_2che1pao2pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao1ma4pawn_B_1che1pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma4pawn_R_1che1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che2ma4pawn_B_1che1pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che1pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao2ma1pawn; //
	funMat[MARR->a[1]  [5]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2pao2ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao1ma2pawn; //
	funMat[MARR->a[2]  [5]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao1ma2pawn;

     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [2]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_2pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [3]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che1ma5pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [5]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1che1ma3pawn;

     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che1ma5pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_1pao2ma2pawn;

     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [2]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1che1pao5pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao5pawn_R_1pao2ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [2]  [0]  [2]  [2]  [1]  [2]  [0]  ]  = m_MT_R_2pao2ma3pawn_B_1che2ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [2]  [0]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma3pawn_R_1che2ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [3]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao2ma3pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [3]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma3pawn_R_1che1ma3pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [3]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao2ma3pawn_B_1che1pao3pawn;
	funMat[MARR->a[3]  [3]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma3pawn_R_1che1pao3pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [3]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma4pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [4]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_1che1ma3pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [3]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma4pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [4]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_1che1ma3pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma4pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_1pao2ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao2ma4pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_2pao1ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma4pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_1pao2ma2pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma4pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_2pao1ma2pawn; //
	//************************************7 ¶Ô 6*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [3]  [1]  [1]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao1ma3pawn_B_1che1pao1ma3pawn; //
	funMat[MARR->a[3]  [3]  [1]  [1]  [1]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma3pawn_R_1che1pao1ma3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [4]  [1]  [2]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao2ma3pawn_B_2che4pawn; //
	funMat[MARR->a[4]  [3]  [2]  [0]  [0]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_2che4pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [3]  [1]  [2]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma3pawn; //
	funMat[MARR->a[3]  [3]  [1]  [1]  [1]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma3pawn_R_1che1pao1ma3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [0]  [2]  [1]  [2]  [1]  ]  = m_MT_R_1che2pao4pawn_B_1che1pao2ma2pawn; //
	funMat[MARR->a[2]  [4]  [1]  [2]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che1pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [0]  [2]  [1]  [1]  [2]  ]  = m_MT_R_1che2pao4pawn_B_1che2pao1ma2pawn; //
	funMat[MARR->a[2]  [4]  [1]  [1]  [2]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao4pawn_R_1che2pao1ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [3]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_R_1che2ma4pawn_B_1che2pao3pawn; //
	funMat[MARR->a[3]  [4]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma4pawn_R_1che2pao3pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_R_1che1ma5pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [5]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma5pawn_R_2pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_R_1che1pao5pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [5]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1pao5pawn_R_2pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [2]  [1]  [0]  [2]  [2]  ]  = m_MT_R_1pao2ma4pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [4]  [0]  [2]  [2]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma4pawn_R_2pao2ma2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [1]  [2]  [0]  [2]  [2]  ]  = m_MT_R_2pao1ma4pawn_B_2pao2ma2pawn; //
	funMat[MARR->a[2]  [4]  [0]  [2]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma4pawn_R_2pao2ma2pawn;
	//************************************7 ¶Ô 7*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[3]  [3]  [1]  [1]  [2]  [1]  [1]  [2]  ]  = BR_1che2pao1ma3pawn; //
	

}