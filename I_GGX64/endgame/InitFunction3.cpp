#ifndef E_InitMatFunction3
#define E_InitMatFunction3
#include "../chess.h"
 
#include "../white.h"
#else
#include "../black.h"
#endif

void InitMatFunction3(void){
	//********************************************* 三对0**********************************************************************

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [0]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_R_3pawn;
	funMat[MARR->a[0]  [3]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_R_1pao2pawn;
	funMat[MARR->a[0]  [2]  [0]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn;

	//*************************************三对1*************************************************************
	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1che_1pao_1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che_1pao_1pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1che_1ma_1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che_1ma_1pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1CHE_2PAWN_B_1CHE;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1CHE_2PAWN_R_1CHE;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_R_1che_2pawn_B_1pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1che_2pawn_R_1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_R_1che_2pawn_B_1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che_2pawn_R_1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1che_2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che_2pawn_R_1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [1]  [2]   [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma_B_1che;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]   [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [2]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma_B_1che;
	funMat[MARR->a[0]  [0]  [1]  [0]  [0]   [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [1]  [0]  [0]  ]  = m_MT_R_2pao_1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao_1pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [0]  [1]  ]  = m_MT_R_2pao_1pawn_B_1pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [1]   [0]  [0]  [2]  ]  = m_MT_B_2pao_1pawn_R_1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [1]  [0]  ]  = m_MT_R_2pao_1pawn_B_1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao_1pawn_R_1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [0]  [0]  [0]  ]  = m_MT_R_2pao_1pawn_B_1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao_1pawn_R_1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1pao1ma_1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_1pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [0]  [1]  ]  = m_MT_R_1pao1ma_1pawn_B_1pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [1]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_1pawn_R_1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1pao1ma_1pawn_B_1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_1pawn_R_1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [0]  [0]  [0]  ]  = m_MT_R_1pao1ma_1pawn_B_1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_1pawn_R_1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [1]  [0]  [0]  ]  = m_MT_R_2ma_1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma_1pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [0]  [1]  ]  = m_MT_R_2ma_1pawn_B_1pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [1]   [0]  [2]  [0]  ]  = m_MT_B_2ma_1pawn_R_1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [1]  [0]  ]  = m_MT_R_2ma_1pawn_B_1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma_1pawn_R_1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [0]  [0]  ]  = m_MT_R_2ma_1pawn_B_1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma_1pawn_R_1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1pao2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [0]  [0]  [1]  ]  = m_MT_R_1PAO2PAWN_B_1PAO;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1]   [0]  [0]  [1]  ]  = m_MT_B_1PAO2PAWN_R_1PAO;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1PAO2PAWN_B_1MA;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1PAO2PAWN_R_1MA;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_R_1pao2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1ma2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [1]  [0]   [0]  [0]  [1]  ]  = m_MT_R_1ma2pawn_B_1pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [1]  [0]   [0]  [1]  [0]  ]  = m_MT_R_1ma2pawn_B_1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1ma2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [0]  [0]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_R_3PAWN_B_1CHE;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3PAWN_R_1CHE;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [0]  [0]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_R_3pawn_B_1pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [0]  [0]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_R_3pawn_B_1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [1]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_R_3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_1pawn;	

	//*************************************三对2*****************************************************
	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [2]  [0]  [1]   [2]  [0]  [0]  ]  = m_MT_R_2che1pao_B_2che;
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]   [2]  [0]  [1]  ]  = m_MT_B_2che1pao_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [2]  [1]  [0]   [2]  [0]  [0]  ]  = m_MT_R_2che1ma_B_2che;
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]   [2]  [1]  [0]  ]  = m_MT_B_2che1ma_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [2]  [0]  [0]  ]  = m_MT_R_2che1pawn_B_2che;
	funMat[MARR->a[0]  [1]  [2]  [0]  [0]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_R_2che1pawn_B_1che1pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [1]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_R_2che1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [0]  [2]   [2]  [0]  [0]  ]  = m_MT_R_1che2pao_B_2che;
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]   [1]  [0]  [2]  ]  = m_MT_B_1che2pao_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [0]  [2]   [1]  [0]  [1]  ]  = m_MT_R_1che2pao_B_1che1pao;
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]   [1]  [0]  [2]  ]  = m_MT_B_1che2pao_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [0]  [2]   [1]  [1]  [0]  ]  = m_MT_R_1che2pao_B_1che1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]   [1]  [0]  [2]  ]  = m_MT_B_1che2pao_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [1]  [1]   [2]  [0]  [0]  ]  = m_MT_R_1che1pao1ma_B_2che;
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]   [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [1]  [1]   [1]  [0]  [1]  ]  = m_MT_R_1che1pao1ma_B_1che1pao;
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]   [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [1]  [1]   [1]  [1]  [0]  ]  = m_MT_R_1che1pao1ma_B_1che1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]   [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [1]  [1]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1che1pao1ma_B_1che1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]   [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [2]  [0]   [2]  [0]  [0]  ]  = m_MT_R_1che2ma_B_2che;
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]   [1]  [2]  [0]  ]  = m_MT_B_1che2ma_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [2]  [0]   [1]  [0]  [1]  ]  = m_MT_R_1che2ma_B_1che1pao;
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]   [1]  [2]  [0]  ]  = m_MT_B_1che2ma_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [2]  [0]   [1]  [1]  [0]  ]  = m_MT_R_1che2ma_B_1che1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]   [1]  [2]  [0]  ]  = m_MT_B_1che2ma_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [2]  [0]  [0]  ]  = m_MT_R_1che1pao1pawn_B_2che;
	funMat[MARR->a[0]  [1]  [2]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [1]  [0]  [1]  ]  = m_MT_R_1che1pao1pawn_B_1che1pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [1]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [1]  [1]  [0]  ]  = m_MT_R_1che1pao1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1che1pao1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [2]  [0]  [0]  ]  = m_MT_R_1che1ma1pawn_B_2che;
	funMat[MARR->a[0]  [1]  [2]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [1]  [0]  [1]  ]  = m_MT_R_1che1ma1pawn_B_1che1pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [1]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [1]  [1]  [0]  ]  = m_MT_R_1che1ma1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1che1ma1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [2]  [0]  [0]  ]  = m_MT_R_1che2pawn_B_2che;
	funMat[MARR->a[0]  [2]  [2]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_R_1CHE2PAWN_B_1CHE1PAO;
	funMat[MARR->a[0]  [2]  [1]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1CHE2PAWN_R_1CHE1PAO;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_R_1che2pawn_B_1che1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1che2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [0]  [2]  ]  = m_MT_R_1che2pawn_B_2pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [2]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [1]  [1]  ]  = m_MT_R_1che2pawn_B_1pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [2]  [0]  ]  = m_MT_R_1che2pawn_B_2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_R_1che2pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_R_1che2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [1]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1che2pawn_B_2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [1]  [2]   [2]  [0]  [0]  ]  = m_MT_R_2pao1ma_B_2che;
	funMat[MARR->a[0]  [0]  [2]  [0]  [0]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_2che;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [1]  [2]   [1]  [0]  [1]  ]  = m_MT_R_2pao1ma_B_1che1pao;
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [1]  [2]   [1]  [1]  [0]  ]  = m_MT_R_2pao1ma_B_1che1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [2]  [1]   [1]  [0]  [1]  ]  = m_MT_R_1pao2ma_B_1che1pao;
	funMat[MARR->a[0]  [0]  [1]  [0]  [1]   [0]  [2]  [1]  ]  = m_MT_B_1pao2ma_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [2]  [1]   [1]  [1]  [0]  ]  = m_MT_R_1pao2ma_B_1che1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [0]   [0]  [2]  [1]  ]  = m_MT_B_1pao2ma_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [1]  [2]   [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma_B_1che1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]   [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [2]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma_B_1che1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [0]   [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [1]  [0]  [1]  ]  = m_MT_R_2pao1pawn_B_1che1pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [1]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [1]  [1]  [0]  ]  = m_MT_R_2pao1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [1]  [0]  [0]  ]  = m_MT_R_2pao1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [0]  [2]  ]  = m_MT_R_2pao1pawn_B_2pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [1]  [1]  ]  = m_MT_R_2pao1pawn_B_1pao1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [2]  [0]  ]  = m_MT_R_2pao1pawn_B_2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [0]  [0]  [1]  ]  = m_MT_R_2pao1pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [0]  [1]  [0]  ]  = m_MT_R_2pao1pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [1]  [0]  [1]  ]  = m_MT_R_1ma1pao1pawn_B_1che1pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [1]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_1che1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [1]  [1]  [0]  ]  = m_MT_R_1ma1pao1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1ma1pao1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [0]  [2]  ]  = m_MT_R_1ma1pao1pawn_B_2pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [1]  [1]  ]  = m_MT_R_1ma1pao1pawn_B_1ma1pao;
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_1ma1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [2]  [0]  ]  = m_MT_R_1ma1pao1pawn_B_2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [0]  [0]  [1]  ]  = m_MT_R_1ma1pao1pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1ma1pao1pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1ma1pao1pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [1]  [1]  [0]  ]  = m_MT_R_2ma1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1che1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [1]  [0]  [0]  ]  = m_MT_R_2ma1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [0]  [2]  ]  = m_MT_R_2ma1pawn_B_2pao;
	funMat[MARR->a[0]  [1]  [0]  [0]  [2]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [1]  [1]  ]  = m_MT_R_2ma1pawn_B_1ma1pao;
	funMat[MARR->a[0]  [1]  [0]  [1]  [1]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1ma1pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [2]  [0]  ]  = m_MT_R_2ma1pawn_B_2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [0]  [1]  ]  = m_MT_R_2ma1pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [1]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [1]  [0]  ]  = m_MT_R_2ma1pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1pao2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [0]  [0]  [2]  ]  = m_MT_R_1pao2pawn_B_2pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [2]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [0]  [1]  [1]  ]  = m_MT_R_1pao2pawn_B_1pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [1]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [0]  [1]   [0]  [2]  [0]  ]  = m_MT_R_1pao2pawn_B_2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [0]  [0]  [1]  ]  = m_MT_R_1pao2pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [1]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1pao2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [0]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_R_1pao2pawn_B_2pawn; 
	funMat[MARR->a[2]  [2]  [0]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1ma2pawn_B_1che1pawn; 
	funMat[MARR->a[1]  [2]  [1]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [1]  [0]   [0]  [0]  [2]  ]  = m_MT_R_1ma2pawn_B_2pao; 
	funMat[MARR->a[0]  [2]  [0]  [0]  [2]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [1]  [0]   [0]  [1]  [1]  ]  = m_MT_R_1ma2pawn_B_1pao1ma;	
	funMat[MARR->a[0]  [2]  [0]  [1]  [1]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [0]  [1]  [0]   [0]  [2]  [0]  ]  = m_MT_R_1ma2pawn_B_2ma;  
	funMat[MARR->a[0]  [2]  [0]  [2]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [0]  [0]  [1]  ]  = m_MT_R_1ma2pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [1]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [0]  [1]  [0]  ]  = m_MT_R_1ma2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [0]  [1]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1ma2pawn_B_2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [1]  [0]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_R_3pawn_B_1che1pawn; 
	funMat[MARR->a[1]  [3]  [1]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_1che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [1]  [0]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_R_3pawn_B_1pao1pawn; 
	funMat[MARR->a[1]  [3]  [0]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [1]  [0]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_R_3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [2]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_R_3pawn_B_2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_B_3pawn_R_2pawn;

	//*************************************3 对 3******************************************************************
	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]   [2]   [0]   [1]    [2]   [0]   [0]  ]  = m_MT_R_2che1pao_B_2che1pawn;
	funMat[MARR->a[1]  [0]   [2]   [0]   [0]    [2]   [0]   [1]  ]  = m_MT_B_2che1pao_R_2che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [2]  [1]  [0]   [2]  [0]  [0]  ]  = m_MT_R_2che1ma_B_2che1pawn;
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [2]  [1]  [0]  ]  = m_MT_B_2che1ma_R_2che1pawn;
	
	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [2]  [0]  [0]   [2]  [0]  [0]  ]  = m_MT_R_B_2che1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [1]  [0]  [2]  ]  = m_MT_R_2che1pawn_B_1che2pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [2]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che2pao;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [1]  [1]  [1]  ]  = m_MT_R_2che1pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [1]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che1pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [2]  [0]  [0]   [1]  [2]  [0]  ]  = m_MT_R_2che1pawn_B_1che2ma;
	funMat[MARR->a[0]  [1]  [1]  [2]  [0]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che2ma;	

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [2]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_R_2che1pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [2]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_R_2che1pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che1ma1pawn;  

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [2]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_R_2che1pawn_B_1che2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [2]  [0]  [0]  ]  = m_MT_B_2che1pawn_R_1che2pawn;	

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [0]  [2]   [1]  [1]  [1]  ]  = m_MT_R_1che2pao_B_1che1pao1ma;
	funMat[MARR->a[0]  [0]  [1]  [1]  [1]   [1]  [0]  [2]  ]  = m_MT_B_1che2pao_R_1che1pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [1]  [0]  [2]   [1]  [0]  [1]  ]  = m_MT_R_1che2pao_B_1che1pao1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [1]  [0]  [2]  ]  = m_MT_B_1che2pao_R_1che1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [1]  [1]  [1]   [1]  [1]  [1]  ]  = m_MT_BR_1che1pao1ma;	

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [1]  [1]  [1]   [1]  [0]  [1]  ]  = m_MT_R_1che1pao1ma_B_1che1pao1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma_R_1che1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [1]  [1]  [1]   [1]  [1]  [0]  ]  = m_MT_R_1che1pao1ma_B_1che1ma1pawn;
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma_R_1che1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [1]  [2]  [0]   [1]  [0]  [1]  ]  = m_MT_R_1che2ma_B_1che1pao1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [1]  [2]  [0]  ]  = m_MT_B_1che2ma_R_1che1pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [1]  [0]  [1]  ]  = m_MT_BR_1che1pao1pawn;	

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [1]  [1]  [0]  ]  = m_MT_R_1che1pao1pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1che1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [1]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_R_1che1pao1pawn_B_1che2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1che2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [0]  [1]  [2]  ]  = m_MT_R_1che1pao1pawn_B_2pao1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [2]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_2pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [0]  [1]   [0]  [2]  [1]  ]  = m_MT_R_1che1pao1pawn_B_1pao2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [1]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1pao2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [0]  [0]  [2]  ]  = m_MT_R_1che1pao1pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_2pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [0]  [1]  [1]  ]  = m_MT_R_1che1pao1pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]   [0]  [2]  [0]  ]  = m_MT_R_1che1pao1pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [1]  [0]  [1]   [0]  [0]  [1]  ]  = m_MT_R_1che1pao1pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1pao2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [1]  [0]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1che1pao1pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_1ma2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [3]  [1]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_R_1che1pao1pawn_B_3pawn;
	funMat[MARR->a[3]  [1]  [0]  [0]  [0]   [1]  [0]  [1]  ]  = m_MT_B_1che1pao1pawn_R_3pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [1]  [1]  [0]  ]  = m_MT_BR_1che1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_R_1che1ma1pawn_B_1che2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1che2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [0]  [1]  [2]  ]  = m_MT_R_1che1ma1pawn_B_2pao1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [2]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_2pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [0]  [1]  [1]  [0]   [0]  [2]  [1]  ]  = m_MT_R_1che1ma1pawn_B_1pao2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [1]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1pao2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [0]  [0]  [2]  ]  = m_MT_R_1che1ma1pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_2pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [0]  [1]  [1]  ]  = m_MT_R_1che1ma1pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [1]  [1]  [0]   [0]  [2]  [0]  ]  = m_MT_R_1che1ma1pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]   [0]  [0]  [1]  ]  = m_MT_R_1che1ma1pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1pao2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]   [0]  [1]  [0]  ]  = m_MT_R_1che1ma1pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_1ma2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [3]  [1]  [1]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1che1ma1pawn_B_3pawn;
	funMat[MARR->a[3]  [1]  [0]  [0]  [0]   [1]  [1]  [0]  ]  = m_MT_B_1che1ma1pawn_R_3pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [1]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_1che2pawn_1che2pawn; 

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [1]  [2]  ]  = m_MT_R_1che2pawn_B_2pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [2]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2pao1ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [0]  [1]  [0]  [0]   [0]  [2]  [1]  ]  = m_MT_R_1che2pawn_B_1pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1pao2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [0]  [0]  [2]  ]  = m_MT_R_1che2pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [2]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [0]  [1]  [1]  ]  = m_MT_R_1che2pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [1]  [1]  [0]  [0]   [0]  [2]  [0]  ]  = m_MT_R_1che2pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [1]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_R_1che2pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [1]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1pao2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [1]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_R_1che2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_1ma2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1che2pawn_B_3pawn;
	funMat[MARR->a[3]  [2]  [0]  [0]  [0]   [1]  [0]  [0]  ]  = m_MT_B_1che2pawn_R_3pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [1]  [2]   [0]  [1]  [2]  ]  = m_MT_BR_2pao1ma_B_2pao1ma; //

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [1]  [2]   [0]  [2]  [1]  ]  = m_MT_R_2pao1ma_B_1pao2ma; //
	funMat[MARR->a[0]  [0]  [0]  [2]  [1]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_1pao2ma;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [0]  [0]  [2]  [1]   [0]  [2]  [1]  ]  = m_MT_BR_1pao2ma_B_1pao2ma; //

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [1]  [2]   [0]  [0]  [2]  ]  = m_MT_R_2pao1ma_B_2pao1pawn; //
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_2pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [2]  [1]   [0]  [0]  [2]  ]  = m_MT_R_1pao2ma_B_2pao1pawn;
	funMat[MARR->a[1]  [0]  [0]  [0]  [2]   [0]  [2]  [1]  ]  = m_MT_B_1pao2ma_R_2pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [1]  [2]   [0]  [1]  [1]  ]  = m_MT_R_2pao1ma_B_1pao1ma1pawn; //
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [2]  [1]   [0]  [1]  [1]  ]  = m_MT_R_1pao2ma_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [0]  [0]  [1]  [1]   [0]  [2]  [1]  ]  = m_MT_B_1pao2ma_R_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [1]  [2]   [0]  [2]  [0]  ]  = m_MT_R_2pao1ma_B_2ma1pawn; //
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [1]  [2]  ]  = m_MT_B_2pao1ma_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [0]  [0]  [2]  ]  = m_MT_2pao1pawn_2pao1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[0]  [1]  [0]  [2]  [1]   [0]  [2]  [0]  ]  = m_MT_R_1pao2ma_B_2ma1pawn;
	funMat[MARR->a[1]  [0]  [0]  [2]  [0]   [0]  [2]  [1]  ]  = m_MT_B_1pao2ma_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [0]  [1]  [1]  ]  = m_MT_R_2pao1pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [0]  [2]   [0]  [2]  [0]  ]  = m_MT_R_2pao1pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [0]  [0]  [2]   [0]  [0]  [1]  ]  = m_MT_R_2pao1pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1pao2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [0]  [0]  [2]   [0]  [1]  [0]  ]  = m_MT_R_2pao1pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [0]  [0]  [2]  ]  = m_MT_B_2pao1pawn_R_1ma2pawn;	

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [0]  [1]  [1]  ]  = m_MT_1pao1ma1pawn_1pao1ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [1]  [1]   [0]  [2]  [0]  ]  = m_MT_R_1pao1ma1pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma1pawn_R_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [0]  [1]  [1]   [0]  [0]  [1]  ]  = m_MT_R_1pao1ma1pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma1pawn_R_1pao2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [0]  [1]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1pao1ma1pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [0]  [1]  [1]  ]  = m_MT_B_1pao1ma1pawn_R_1ma2pawn; 

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [2]  [0]  ]  = m_MT_BR_2ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [2]  [0]   [0]  [2]  [0]  ]  = m_MT_BR_2ma1pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [0]  [2]  [0]   [0]  [0]  [1]  ]  = m_MT_R_2ma1pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [1]  [0]  [0]  [1]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1pao2pawn; 

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[1]  [2]  [0]  [2]  [0]   [0]  [1]  [0]  ]  = m_MT_R_2ma1pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [0]   [0]  [2]  [0]  ]  = m_MT_B_2ma1pawn_R_1ma2pawn; 

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [0]  [0]  [1]   [0]  [0]  [1]  ]  = m_MT_BR_1pao2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [0]  [0]  [1]   [0]  [1]  [0]  ]  = m_MT_R_1pao2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_1ma2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [3]  [0]  [0]  [1]   [0]  [0]  [0]  ]  = m_MT_R_1pao2pawn_B_3pawn;
	funMat[MARR->a[3]  [2]  [0]  [0]  [0]   [0]  [0]  [1]  ]  = m_MT_B_1pao2pawn_R_3pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [2]  [0]  [1]  [0]   [0]  [1]  [0]  ]  = m_MT_1ma2pawn_1ma2pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[2]  [3]  [0]  [1]  [0]   [0]  [0]  [0]  ]  = m_MT_R_1ma2pawn_B_3pawn;
	funMat[MARR->a[3]  [2]  [0]  [0]  [0]   [0]  [1]  [0]  ]  = m_MT_B_1ma2pawn_R_3pawn;

	//           红兵  黑卒  红车  红马  红炮   黑车  黑马  黑炮  
	funMat[MARR->a[3]  [3]  [0]  [0]  [0]   [0]  [0]  [0]  ]  = m_MT_3pawn_TO_3pawn;

}