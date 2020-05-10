
#ifndef E_InitMatFunction8
#define E_InitMatFunction8
#include "..\\chess.h"
 
#include "..\\white.h"
#else
#include "..\\black.h"
#endif

void InitMatFunction8(void){

	//********************************************* 8 ¶Ô 0*****************************************************************
	//********************************************* 8 ¶Ô 1*****************************************************************

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma5pawn_B_1che;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma5pawn_R_1che;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma5pawn_B_1che;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma5pawn_R_1che;
	
	//************************************8 ¶Ô 2*********************************************************
     //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [0]  [2]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_2che1pao5pawn_B_2che; //2³µ1ÅÚ1±ø¶Ô2³µ
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao5pawn_R_2che;

	 //           ºì±ø  ºÚ×ä  ºì³µ  ºìÂí  ºìÅÚ  ºÚ³µ  ºÚÂí  ºÚÅÚÏà 
	funMat[MARR->a[5]  [0]  [2]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che1ma5pawn_B_2che; //2³µ1ÅÚ1±ø¶Ô2³µ
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma5pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao1ma5pawn_B_2che;
	funMat[MARR->a[0]  [5]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_2che;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao1ma5pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [5]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma5pawn_B_1che1ma; 
	funMat[MARR->a[0]  [5]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_1che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1pao2ma5pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [5]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_1che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma5pawn_B_1che1ma; 
	funMat[MARR->a[0]  [5]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_1che1ma;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma5pawn_R_1che1pawn;
	
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma5pawn_R_1che1pawn;
	
	//************************************8 ¶Ô 3*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_R_2che1pao5pawn_B_2che1pao;
	funMat[MARR->a[0]  [5]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao5pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_R_2che1ma5pawn_B_2che1pao;
	funMat[MARR->a[0]  [5]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma5pawn_R_2che1pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_R_2che1pao5pawn_B_2che1ma;
	funMat[MARR->a[0]  [5]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao5pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [2]  [1]  [0]  [2]  [1]  [0]  ]  = m_MT_R_2che1ma5pawn_B_2che1ma;
	funMat[MARR->a[0]  [5]  [2]  [1]  [0]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma5pawn_R_2che1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_R_1che2pao5pawn_B_2che1pawn;
	funMat[MARR->a[1]  [5]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao5pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_R_1che2pao5pawn_B_1che2pao;   //---------
	funMat[MARR->a[0]  [5]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao5pawn_R_1che2pao; 

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao5pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao5pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_R_1che2pao5pawn_B_1che2ma;
	funMat[MARR->a[0]  [5]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao5pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao1ma5pawn_B_2che1pawn;
	funMat[MARR->a[1]  [5]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao1ma5pawn_B_1che2pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao1ma5pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_R_1che1pao1ma5pawn_B_1che2ma;
	funMat[MARR->a[0]  [5]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_1che2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [2]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che2ma5pawn_B_2che1pawn;
	funMat[MARR->a[1]  [5]  [2]  [0]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma5pawn_R_2che1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_R_1che2ma5pawn_B_1che2pao;
	funMat[MARR->a[0]  [5]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma5pawn_R_1che2pao;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che2ma5pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [5]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma5pawn_R_1che1pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [2]  [0]  [1]  [2]  [0]  ]  = m_MT_R_1che2ma5pawn_B_1che2ma;
	funMat[MARR->a[0]  [5]  [1]  [2]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma5pawn_R_1che2ma; //---------

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma5pawn_B_2pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma5pawn_B_1pao2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao2ma5pawn_B_2pao1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_2pao1ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma5pawn_B_1pao2ma;
	funMat[MARR->a[0]  [5]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_1pao2ma;
	//************************************8 ¶Ô 4*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [1]  [2]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao2ma4pawn_B_2che2pawn;
	funMat[MARR->a[2]  [4]  [2]  [0]  [0]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma4pawn_R_2che2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [0]  [2]  [1]  [2]  [1]  ]  = m_MT_R_1che2pao5pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [5]  [1]  [2]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao5pawn_R_1che1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [0]  [1]  [1]  [1]  [1]  [2]  [1]  ]  = m_MT_R_1che1pao1ma5pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [5]  [1]  [2]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_1che1pao2ma;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [2]  [2]  [1]  [1]  [1]  ]  = m_MT_R_2pao2ma4pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [1]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma4pawn_R_1che1pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [1]  [0]  [2]  [2]  [1]  [0]  [2]  ]  = m_MT_R_2pao2ma4pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [2]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma4pawn_R_1che2pao1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma5pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_2pao1ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma5pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_1pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma5pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_1pao2ma1pawn;

    //           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma5pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_2pao1ma1pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [1]  [1]  [1]  [1]  [2]  [0]  [1]  ]  = m_MT_R_1che1pao1ma5pawn_B_2che1pao1pawn;
	funMat[MARR->a[1]  [5]  [2]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_2che1pao1pawn;
	//************************************8 ¶Ô 5*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[4]  [2]  [0]  [2]  [2]  [1]  [0]  [2]  ]  = m_MT_R_2pao2ma4pawn_B_1che2pao2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [2]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma4pawn_R_1che2pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [2]  [1]  [1]  [1]  [2]  [0]  [1]  ]  = m_MT_R_1che1pao1ma5pawn_B_2che1pao2pawn;
	funMat[MARR->a[2]  [5]  [2]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_2che1pao2pawn;

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [3]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma5pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [5]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma5pawn_R_1che1ma3pawn; //

	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [3]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma5pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [5]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma5pawn_R_1che1ma3pawn; //
	//************************************8 ¶Ô 6*********************************************************
	//           ºì±ø  ºÚ×ä ºì³µ ºìÂí ºìÅÚ ºÚ³µ ºÚÂí ºÚÅÚ  
	funMat[MARR->a[5]  [3]  [1]  [1]  [1]  [2]  [0]  [1]  ]  = m_MT_R_1che1pao1ma5pawn_B_2che1pao3pawn;
	funMat[MARR->a[3]  [5]  [2]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma5pawn_R_2che1pao3pawn;
	//************************************8 ¶Ô 7*********************************************************
	//************************************8 ¶Ô 8*********************************************************

}