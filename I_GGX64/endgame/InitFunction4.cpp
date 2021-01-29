#ifndef E_InitMatFunction4
#define E_InitMatFunction4
#include "../chess.h"
 
#include "../white.h"
#else
#include "../black.h"
#endif

void InitMatFunction4(void){
	//********************************************* 4 对 0*******************************************************************
	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [0]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_4pawn;
	funMat[MARR->a[0]  [4]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn; 

	//************************************ 对 1**********************************************************
	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_R_1CHE_3PAWN_B_1CHE;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1CHE_3PAWN_R_1CHE;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [0]  [1] ]  = m_MT_R_1che3pawn_B_1pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [1]  [0] ]  = m_MT_R_1che3pawn_B_1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_1che3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [1]  [2] [1]  [0]  [0] ]  = m_MT_R_2pao_1ma1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0] [0]  [1]  [2] ]  = m_MT_B_2pao_1ma1pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [0]  [1] ]  = m_MT_R_2pao_2pawn_B_1pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao_2pawn_R_1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [1]  [0] ]  = m_MT_R_2pao_2pawn_B_1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao_2pawn_R_1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [0]  [0]  [0] ]  = m_MT_R_2pao_2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao_2pawn_R_1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [2]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao_2ma1pawn_B_1che;
	funMat[MARR->a[0]  [1]  [1]  [0]  [0] [0]  [2]  [1] ]  = m_MT_B_1pao_2ma1pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [1]  [0]  [0] ]  = m_MT_R_2pao_2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao_2pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao_1ma2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao_1ma2pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [0]  [1] ]  = m_MT_R_1pao_1ma2pawn_B_1pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1] [0]  [1]  [1] ]  = m_MT_B_1pao_1ma2pawn_R_1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [1]  [0] ]  = m_MT_R_1pao1ma_2pawn_B_1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao1ma_2pawn_R_1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [0]  [0] ]  = m_MT_R_1pao1ma_2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao1ma_2pawn_R_1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [1]  [0]  [0] ]  = m_MT_R_2ma_2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma_2pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [0]  [1] ]  = m_MT_R_2ma_2pawn_B_1pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [1] [0]  [2]  [0] ]  = m_MT_B_2ma_2pawn_R_1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [1]  [0] ]  = m_MT_R_2ma_2pawn_B_1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma_2pawn_R_1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [0]  [0] ]  = m_MT_R_2ma_2pawn_B_1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma_2pawn_R_1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [0]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao3pawn_B_1che;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [0]  [1] [0]  [0]  [1] ]  = m_MT_R_1PAO3PAWN_B_1PAO;
	funMat[MARR->a[0]  [3]  [0]  [0]  [1] [0]  [0]  [1] ]  = m_MT_B_1PAO3PAWN_R_1PAO;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [0]  [1] [0]  [1]  [0] ]  = m_MT_R_1PAO3PAWN_B_1MA;	
	funMat[MARR->a[0]  [3]  [0]  [1]  [0] [0]  [0]  [1] ]  = m_MT_B_1PAO3PAWN_R_1MA;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_R_1pao3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [1]  [0] [1]  [0]  [0] ]  = m_MT_R_1ma3pawn_B_1che;  
	funMat[MARR->a[0]  [3]  [1]  [0]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [1]  [0] [0]  [0]  [1] ]  = m_MT_R_1ma3pawn_B_1pao; 
	funMat[MARR->a[0]  [3]  [0]  [0]  [1] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_R_1ma3pawn_B_1ma;  
	funMat[MARR->a[0]  [3]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_R_1ma3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [0]  [0]  [0]  [0] [1]  [0]  [0] ]  = m_MT_R_4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [0]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_R_4pawn_B_1pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [0]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_R_4pawn_B_1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [1]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1pawn;

	//************************************ 对 2********************************************************
    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [2]  [0]  [1] [2]  [0]  [0] ]  = m_MT_R_2che1pao1pawn_B_2che; //2车1炮1兵对2车
	funMat[MARR->a[0]  [1]  [2]  [0]  [0] [2]  [0]  [1] ]  = m_MT_B_2che1pao1pawn_R_2che;

	 //           红兵  黑卒  红车  红马  红炮 黑车  黑马  黑相 
	funMat[MARR->a[1]  [0]  [2]  [1]  [0] [2]  [0]  [0] ]  = m_MT_R_2che1ma1pawn_B_2che; //2车1炮1兵对2车
	funMat[MARR->a[0]  [1]  [2]  [0]  [0] [2]  [1]  [0] ]  = m_MT_B_2che1ma1pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [2]  [0]  [0] ]  = m_MT_R_2che2pawn_B_2che;
	funMat[MARR->a[0]  [2]  [2]  [0]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [0]  [2] [2]  [0]  [0] ]  = m_MT_R_1che2pao1pawn_B_2che;  
	funMat[MARR->a[0]  [1]  [2]  [0]  [0] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [2]  [0] [2]  [0]  [0] ]  = m_MT_R_1che2ma1pawn_B_2che;  
	funMat[MARR->a[0]  [1]  [2]  [0]  [0] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [2]  [0]  [0] ]  = m_MT_R_1che1pao1ma1pawn_B_2che;
	funMat[MARR->a[0]  [1]  [2]  [0]  [0] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [0]  [2] [1]  [1]  [0] ]  = m_MT_R_1che2pao1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [1]  [1]  [0] ]  = m_MT_R_1che1pao1ma1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [2]  [0] [1]  [1]  [0] ]  = m_MT_R_1che2ma1pawn_B_1che1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [0] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [2]  [0]  [0] ]  = m_MT_R_1che1pao2pawn_B_2che;  
	funMat[MARR->a[0]  [2]  [2]  [0]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [1]  [0]  [1] ]  = m_MT_R_1che1pao2pawn_B_1che1pao;
	funMat[MARR->a[0]  [2]  [1]  [0]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [1]  [1]  [0] ]  = m_MT_R_1che1pao2pawn_B_1che1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [2]  [0]  [0] ]  = m_MT_R_1che1ma2pawn_B_2che;
	funMat[MARR->a[0]  [2]  [2]  [0]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [1]  [0]  [1] ]  = m_MT_R_1che1ma2pawn_B_1che1pao; 
	funMat[MARR->a[0]  [2]  [1]  [0]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [1]  [1]  [0] ]  = m_MT_R_1che1ma2pawn_B_1che1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [2]  [0]  [0] ]  = m_MT_R_1che3pawn_B_2che;	
	funMat[MARR->a[0]  [3]  [2]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [1]  [0]  [1] ]  = m_MT_R_1che3pawn_B_1che1pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1che1pao; 

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [1]  [1]  [0] ]  = m_MT_R_1che3pawn_B_1che1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_R_1che3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [0]  [2] ]  = m_MT_R_1che3pawn_B_2pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [2] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [1]  [1] ]  = m_MT_R_1che3pawn_B_1pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [2]  [0] ]  = m_MT_R_1che3pawn_B_2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [0]  [1] ]  = m_MT_R_1che3pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [1]  [0] ]  = m_MT_R_1che3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [1]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_1che3pawn_B_2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [1]  [2] [2]  [0]  [0] ]  = m_MT_R_2pao1ma1pawn_B_2che;  //
	funMat[MARR->a[0]  [1]  [2]  [0]  [0] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_2che;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [1]  [2] [1]  [0]  [1] ]  = m_MT_R_2pao1ma1pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [1]  [1]  [0]  [1] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [1]  [2] [1]  [1]  [0] ]  = m_MT_R_2pao1ma1pawn_B_1che1ma; 
	funMat[MARR->a[0]  [1]  [1]  [1]  [0] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [2]  [1] [1]  [0]  [1] ]  = m_MT_R_1pao2ma1pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [1]  [1]  [0]  [1] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [2]  [1] [1]  [1]  [0] ]  = m_MT_R_1pao2ma1pawn_B_1che1ma; 
	funMat[MARR->a[0]  [1]  [1]  [1]  [0] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [1]  [2] [1]  [0]  [0] ]  = m_MT_R_2pao_1ma1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0] [0]  [1]  [2] ]  = m_MT_B_2pao_1ma1pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [2]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao_2ma1pawn_B_1che1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [0] [0]  [2]  [1] ]  = m_MT_B_1pao_2ma1pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [1]  [0]  [0] ]  = m_MT_R_2pao2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [0]  [2] ]  = m_MT_R_2pao2pawn_B_2pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [2] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [1]  [1] ]  = m_MT_R_2pao2pawn_B_1ma1pao;
	funMat[MARR->a[0]  [2]  [0]  [1]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1ma1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [2]  [0] ]  = m_MT_R_2pao2pawn_B_2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [1]  [0]  [0] ]  = m_MT_R_2ma2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [0]  [2] ]  = m_MT_R_2ma2pawn_B_2pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [2] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [1]  [1] ]  = m_MT_R_2ma2pawn_B_1ma1pao;
	funMat[MARR->a[0]  [2]  [0]  [1]  [1] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1ma1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [2]  [0] ]  = m_MT_R_2ma2pawn_B_2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [1]  [0] ]  = m_MT_R_2ma2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [1]  [0]  [0] ]  = m_MT_R_1ma1pao2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0] [0]  [1]  [1] ]  = m_MT_B_1ma1pao2pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [0]  [2] ]  = m_MT_R_1ma1pao2pawn_B_2pao;
	funMat[MARR->a[0]  [2]  [0]  [0]  [2] [0]  [1]  [1] ]  = m_MT_B_1ma1pao2pawn_R_2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [1]  [1] ]  = m_MT_R_1ma1pao2pawn_B_1ma1pao;
	funMat[MARR->a[0]  [2]  [0]  [1]  [1] [0]  [1]  [1] ]  = m_MT_B_1ma1pao2pawn_R_1ma1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [2]  [0] ]  = m_MT_R_1ma1pao2pawn_B_2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [0] [0]  [1]  [1] ]  = m_MT_B_1ma1pao2pawn_R_2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [0]  [0]  [1] ]  = m_MT_R_2pao2pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [0]  [1]  [0] ]  = m_MT_R_2pao2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [0]  [1] ]  = m_MT_R_1ma1pao2pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [1] [0]  [1]  [1] ]  = m_MT_B_1ma1pao2pawn_R_1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [1]  [0] ]  = m_MT_R_1ma1pao2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0] [0]  [1]  [1] ]  = m_MT_B_1ma1pao2pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [0]  [1] ]  = m_MT_R_2ma2pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [1] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [1]  [0] ]  = m_MT_R_2ma2pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [0]  [1] [0]  [0]  [2] ]  = m_MT_R_1pao3pawn_B_2pao;  
	funMat[MARR->a[0]  [3]  [0]  [0]  [2] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [0]  [1] [0]  [1]  [1] ]  = m_MT_R_1pao3pawn_B_1pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [1] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [0]  [1] [0]  [2]  [0] ]  = m_MT_R_1pao3pawn_B_2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [0]  [0]  [1] ]  = m_MT_R_1pao3pawn_B_1pao1pawn;	
	funMat[MARR->a[1]  [3]  [0]  [0]  [1] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1pao1pawn;  

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [0]  [1]  [0] ]  = m_MT_R_1pao3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_R_1pao3pawn_B_2pawn;	
	funMat[MARR->a[2]  [3]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [1]  [0] [0]  [0]  [2] ]  = m_MT_R_1ma3pawn_B_2pao;  
	funMat[MARR->a[0]  [3]  [0]  [0]  [2] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [1]  [0] [0]  [1]  [1] ]  = m_MT_R_1ma3pawn_B_1pao1ma;	
	funMat[MARR->a[0]  [3]  [0]  [1]  [1] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [0]  [1]  [0] [0]  [2]  [0] ]  = m_MT_R_1ma3pawn_B_2ma; 
	funMat[MARR->a[0]  [3]  [0]  [2]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [1]  [0] [1]  [0]  [0] ]  = m_MT_R_1ma3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [1]  [0] [0]  [0]  [1] ]  = m_MT_R_1ma3pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [1] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_R_1ma3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_R_1ma3pawn_B_2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [1]  [0]  [0]  [0] [1]  [0]  [0] ]  = m_MT_R_4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [1]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_R_4pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [1]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_R_4pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [2]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_4pawn_B_2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_2pawn;
	
	//************************************ 对 3********************************************************
	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [2]  [0]  [1] [2]  [0]  [1] ]  = m_MT_R_2che1pao1pawn_B_2che1pao;
	funMat[MARR->a[0]  [1]  [2]  [0]  [1] [2]  [0]  [1] ]  = m_MT_B_2che1pao1pawn_R_2che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [2]  [1]  [0] [2]  [0]  [1] ]  = m_MT_R_2che1ma1pawn_B_2che1pao;
	funMat[MARR->a[0]  [1]  [2]  [0]  [1] [2]  [1]  [0] ]  = m_MT_B_2che1ma1pawn_R_2che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [2]  [0]  [1] [2]  [1]  [0] ]  = m_MT_R_2che1pao1pawn_B_2che1ma;
	funMat[MARR->a[0]  [1]  [2]  [1]  [0] [2]  [0]  [1] ]  = m_MT_B_2che1pao1pawn_R_2che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [2]  [1]  [0] [2]  [1]  [0] ]  = m_MT_R_2che1ma1pawn_B_2che1ma;
	funMat[MARR->a[0]  [1]  [2]  [1]  [0] [2]  [1]  [0] ]  = m_MT_B_2che1ma1pawn_R_2che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [2]  [0]  [1] ]  = m_MT_R_2che2pawn_B_2che1pao;
	funMat[MARR->a[0]  [2]  [2]  [0]  [1] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_2che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [2]  [1]  [0] ]  = m_MT_R_2che2pawn_B_2che1ma;
	funMat[MARR->a[0]  [2]  [2]  [1]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_2che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [2]  [0]  [0] [2]  [0]  [0] ]  = m_MT_R_2che2pawn_B_2che1pawn;
	funMat[MARR->a[1]  [2]  [2]  [0]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_2che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [1]  [0]  [2] ]  = m_MT_R_2che2pawn_B_1che2pao;
	funMat[MARR->a[0]  [2]  [1]  [0]  [2] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [1]  [1]  [1] ]  = m_MT_R_2che2pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [1] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [1]  [2]  [0] ]  = m_MT_R_2che2pawn_B_1che2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [2]  [0]  [0] [1]  [0]  [1] ]  = m_MT_R_2che2pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [1] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che1pao1pawn;

    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [2]  [0]  [0] [1]  [1]  [0] ]  = m_MT_R_2che2pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [2]  [0]  [0] [1]  [0]  [0] ]  = m_MT_R_2che2pawn_B_1che2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [0]  [2] [2]  [0]  [0] ]  = m_MT_R_1che2pao1pawn_B_2che1pawn;
	funMat[MARR->a[1]  [1]  [2]  [0]  [0] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_2che1pawn;
	
	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [0]  [2] [1]  [0]  [2] ]  = m_MT_R_1che2pao1pawn_B_1che2pao;   //---------
	funMat[MARR->a[0]  [1]  [1]  [0]  [2] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che2pao; 

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [0]  [2] [1]  [1]  [1] ]  = m_MT_R_1che2pao1pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [1] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [0]  [2] [1]  [2]  [0] ]  = m_MT_R_1che2pao1pawn_B_1che2ma;
	funMat[MARR->a[0]  [1]  [1]  [2]  [0] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che2ma;	

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [2]  [1]  [0] ]  = m_MT_R_1che1pao1ma1pawn_B_2che1ma;
	funMat[MARR->a[0]  [1]  [2]  [1]  [0] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_2che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [2]  [0]  [1] ]  = m_MT_R_1che1pao1ma1pawn_B_2che1pao;
	funMat[MARR->a[0]  [1]  [2]  [0]  [1] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_2che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [1]  [1] [2]  [0]  [0] ]  = m_MT_R_1che1pao1ma1pawn_B_2che1pawn;
	funMat[MARR->a[1]  [1]  [2]  [0]  [0] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_2che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [1]  [0]  [2] ]  = m_MT_R_1che1pao1ma1pawn_B_1che2pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [2] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [1]  [1]  [1] ]  = m_MT_R_1che1pao1ma1pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [1] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [1]  [1] [1]  [2]  [0] ]  = m_MT_R_1che1pao1ma1pawn_B_1che2ma;
	funMat[MARR->a[0]  [1]  [1]  [2]  [0] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [1]  [1] [1]  [0]  [1] ]  = m_MT_R_1che1pao1ma1pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [1] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [1]  [1] [1]  [1]  [0] ]  = m_MT_R_1che1pao1ma1pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [0] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [2]  [0] [2]  [0]  [0] ]  = m_MT_R_1che2ma1pawn_B_2che1pawn;
	funMat[MARR->a[1]  [1]  [2]  [0]  [0] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_2che1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [2]  [0] [1]  [0]  [2] ]  = m_MT_R_1che2ma1pawn_B_1che2pao;
	funMat[MARR->a[0]  [1]  [1]  [0]  [2] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [2]  [0] [1]  [1]  [1] ]  = m_MT_R_1che2ma1pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [1]  [1]  [1]  [1] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [1]  [2]  [0] [1]  [2]  [0] ]  = m_MT_R_1che2ma1pawn_B_1che2ma;
	funMat[MARR->a[0]  [1]  [1]  [2]  [0] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che2ma; //---------

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [2]  [0] [1]  [1]  [0] ]  = m_MT_R_1che2ma1pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [0] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che1ma1pawn; //---------

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [2]  [0]  [1] ]  = m_MT_R_1che1pao2pawn_B_2che1pao;
	funMat[MARR->a[0]  [2]  [2]  [0]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2che1pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [2]  [1]  [0] ]  = m_MT_R_1che1pao2pawn_B_2che1ma;
	funMat[MARR->a[0]  [2]  [2]  [1]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2che1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [2]  [0]  [0] ]  = m_MT_R_1che1pao2pawn_B_2che1pawn;
	funMat[MARR->a[1]  [2]  [2]  [0]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2che1pawn;	

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [1]  [0]  [1] ]  = m_MT_R_1che1pao2pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [1]  [0]  [2] ]  = m_MT_R_1che1pao2pawn_B_1che2pao;
	funMat[MARR->a[0]  [2]  [1]  [0]  [2] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che2pao;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [1]  [1]  [1] ]  = m_MT_R_1che1pao2pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che1pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [1]  [1]  [0] ]  = m_MT_R_1che1pao2pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [0]  [1] [1]  [0]  [0] ]  = m_MT_R_1che1pao2pawn_B_1che2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [0]  [1]  [2] ]  = m_MT_R_1che1pao2pawn_B_2pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [2] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [0]  [0]  [2] ]  = m_MT_R_1che1pao2pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [2] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [0]  [2]  [1] ]  = m_MT_R_1che1pao2pawn_B_1pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [0]  [1]  [1] ]  = m_MT_R_1che1pao2pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [0]  [2]  [0] ]  = m_MT_R_1che1pao2pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [0]  [1] [0]  [1]  [0] ]  = m_MT_R_1che1pao2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [0]  [1] [0]  [0]  [1] ]  = m_MT_R_1che1pao2pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [3]  [1]  [0]  [1] [0]  [0]  [0] ]  = m_MT_R_1che1pao2pawn_B_3pawn;
	funMat[MARR->a[3]  [2]  [0]  [0]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [2]  [0]  [0] ]  = m_MT_R_1che1ma2pawn_B_2che1pawn;
	funMat[MARR->a[1]  [2]  [2]  [0]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2che1pawn;


	//            红兵  黑卒 红车  红马  红炮 黑车  黑马  黑炮相 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [1]  [1]  [1] ]  = m_MT_R_1che1ma2pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che1pao1ma;

	//            红兵  黑卒 红车  红马  红炮 黑车  黑马  黑炮相 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [1]  [0]  [2] ]  = m_MT_R_1che1ma2pawn_B_1che2pao;
	funMat[MARR->a[0]  [2]  [1]  [0]  [2] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che2pao;

	//            红兵  黑卒 红车  红马  红炮 黑车  黑马  黑炮相 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [1]  [2]  [0] ]  = m_MT_R_1che1ma2pawn_B_1che2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che2ma;


	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [1]  [0]  [1] ]  = m_MT_R_1che1ma2pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [1]  [1]  [0] ]  = m_MT_R_1che1ma2pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [1]  [0] [1]  [0]  [0] ]  = m_MT_R_1che1ma2pawn_B_1che2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [0]  [1]  [2] ]  = m_MT_R_1che1ma2pawn_B_2pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [2] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [0]  [0]  [2] ]  = m_MT_R_1che1ma2pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [2] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [0]  [2]  [1] ]  = m_MT_R_1che1ma2pawn_B_1pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [0]  [1]  [1] ]  = m_MT_R_1che1ma2pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [0]  [2]  [0] ]  = m_MT_R_1che1ma2pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [1]  [0] [0]  [1]  [0] ]  = m_MT_R_1che1ma2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [1]  [0] [0]  [0]  [1] ]  = m_MT_R_1che1ma2pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [3]  [1]  [1]  [0] [0]  [0]  [0] ]  = m_MT_R_1che1ma2pawn_B_3pawn;
	funMat[MARR->a[3]  [2]  [0]  [0]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_3pawn;

    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [1]  [0]  [1] ]  = m_MT_R_1che3pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [1]  [1]  [0] ]  = m_MT_R_1che3pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_R_1che3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [1]  [2] ]  = m_MT_R_1che3pawn_B_2pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [2] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [0]  [1]  [0]  [0] [0]  [2]  [1] ]  = m_MT_R_1che3pawn_B_1pao2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [0]  [2] ]  = m_MT_R_1che3pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [2] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [1]  [1] ]  = m_MT_R_1che3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [2]  [0] ]  = m_MT_R_1che3pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [1]  [0]  [0] [0]  [0]  [1] ]  = m_MT_R_1che3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [1]  [0]  [0] [0]  [1]  [0] ]  = m_MT_R_1che3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[0]  [1]  [0]  [2]  [2] [1]  [0]  [1] ]  = m_MT_R_2pao2ma_B_1che1pao1pawn;
	funMat[MARR->a[1]  [0]  [1]  [0]  [1] [0]  [2]  [2] ]  = m_MT_B_2pao2ma_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [1]  [2] [1]  [0]  [1] ]  = m_MT_R_2pao1ma1pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [1] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [1]  [2] [1]  [1]  [0] ]  = m_MT_R_2pao1ma1pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [0] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [0]  [1]  [2] [1]  [0]  [0] ]  = m_MT_R_2pao1ma1pawn_B_1che2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [0] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [2]  [1] [1]  [0]  [1] ]  = m_MT_R_1pao2ma1pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [1] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1che1pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [2]  [1] [1]  [1]  [0] ]  = m_MT_R_1pao2ma1pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [0] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [0]  [2]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao2ma1pawn_B_1che2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [0] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [1]  [2] [0]  [1]  [2] ]  = m_MT_R_2pao1ma1pawn_B_2pao1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [2] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [1]  [2] [0]  [2]  [1] ]  = m_MT_R_2pao1ma1pawn_B_1pao2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [1] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [2]  [1] [0]  [1]  [2] ]  = m_MT_R_1pao2ma1pawn_B_2pao1ma;
	funMat[MARR->a[0]  [1]  [0]  [1]  [2] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [0]  [0]  [2]  [1] [0]  [2]  [1] ]  = m_MT_R_1pao2ma1pawn_B_1pao2ma;
	funMat[MARR->a[0]  [1]  [0]  [2]  [1] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [3]  [1]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_1che3pawn_B_3pawn;
	funMat[MARR->a[3]  [3]  [0]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [0]  [2] [1]  [0]  [0] ]  = m_MT_R_2pao2pawn_B_1che2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [1]  [2] ]  = m_MT_R_2pao2pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [2]  [0]  [1]  [2] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [0]  [2] [0]  [2]  [1] ]  = m_MT_R_2pao2pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [2]  [0]  [2]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [0]  [0]  [2] ]  = m_MT_R_2pao2pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [2] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [0]  [1]  [1] ]  = m_MT_R_2pao2pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [0]  [2] [0]  [2]  [0] ]  = m_MT_R_2pao2pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [0]  [2] [0]  [0]  [1] ]  = m_MT_R_2pao2pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [0]  [2] [0]  [1]  [0] ]  = m_MT_R_2pao2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [1]  [1] [1]  [0]  [0] ]  = m_MT_R_1pao1ma2pawn_B_1che2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [1]  [2] ]  = m_MT_R_1pao1ma2pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [2]  [0]  [1]  [2] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [1]  [1] [0]  [2]  [1] ]  = m_MT_R_1pao1ma2pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [2]  [0]  [2]  [1] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [0]  [2] ]  = m_MT_R_1pao1ma2pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [2] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [1]  [1] ]  = m_MT_R_1pao1ma2pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [1] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [2]  [0] ]  = m_MT_R_1pao1ma2pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [1]  [1] [0]  [0]  [1] ]  = m_MT_R_1pao1ma2pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [1] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [1]  [1] [0]  [1]  [0] ]  = m_MT_R_1pao1ma2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [2]  [0] [1]  [0]  [0] ]  = m_MT_R_2ma2pawn_B_1che2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [1]  [2] ]  = m_MT_R_2ma2pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [2]  [0]  [1]  [2] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_2pao1ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [0]  [2]  [0] [0]  [2]  [1] ]  = m_MT_R_2ma2pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [2]  [0]  [2]  [1] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [0]  [2] ]  = m_MT_R_2ma2pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [2]  [0]  [0]  [2] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [1]  [1] ]  = m_MT_R_2ma2pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [1] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [0]  [2]  [0] [0]  [2]  [0] ]  = m_MT_R_2ma2pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [2]  [0] [0]  [0]  [1] ]  = m_MT_R_2ma2pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [2]  [0]  [0]  [1] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [2]  [0] [0]  [1]  [0] ]  = m_MT_R_2ma2pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [0] [0]  [2]  [0] ]  = m_MT_B_2ma2pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [0]  [0]  [2] ]  = m_MT_R_1pao3pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [2] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_2pao1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [0]  [1]  [1] ]  = m_MT_R_1pao3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [0]  [1] [0]  [2]  [0] ]  = m_MT_R_1pao3pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [0]  [0]  [1] [0]  [0]  [1] ]  = m_MT_R_1pao3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [0]  [0]  [1] [0]  [1]  [0] ]  = m_MT_R_1pao3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [3]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_R_1pao3pawn_B_3pawn;
	funMat[MARR->a[3]  [3]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [0]  [1]  [0] [0]  [1]  [1] ]  = m_MT_R_1ma3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [0]  [1]  [0] [0]  [0]  [1] ]  = m_MT_R_1ma3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [2]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_R_1ma3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [3]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_R_1ma3pawn_B_3pawn;
	funMat[MARR->a[3]  [3]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [2]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_R_4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [2]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_R_4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [3]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_4pawn_B_3pawn;
	funMat[MARR->a[3]  [4]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_B_4pawn_R_3pawn;

	//************************************ 对 4********************************************************
	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [2]  [1]  [0] [2]  [1]  [0] ]  = m_MT_BR_2che1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[0]  [2]  [2]  [2]  [0] [2]  [0]  [0] ]  = m_MT_R_2che2ma_B_2che2pawn;
	funMat[MARR->a[2]  [0]  [2]  [0]  [0] [2]  [2]  [0] ]  = m_MT_B_2che2ma_R_2che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [2]  [1]  [0] [2]  [0]  [0] ]  = m_MT_R_2che1ma1pawn_B_2che2pawn;
	funMat[MARR->a[2]  [1]  [2]  [0]  [0] [2]  [1]  [0] ]  = m_MT_B_2che1ma1pawn_R_2che2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [2]  [0]  [0] [1]  [1]  [1] ]  = m_MT_R_2che2pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [1] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [2]  [0]  [0] [1]  [1]  [0] ]  = m_MT_R_2che2pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [2]  [1]  [1]  [0] [2]  [0]  [0] ]  = m_MT_B_2che2pawn_R_1che1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [1]  [1] [1]  [1]  [1] ]  = m_MT_BR_1che1pao1ma1pawn;	

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [1]  [0]  [2] [1]  [1]  [1] ]  = m_MT_R_1che2pao1pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [1]  [1]  [1]  [1] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che1pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [1]  [0]  [2] [1]  [0]  [1] ]  = m_MT_R_1che2pao1pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [1]  [0]  [2] [1]  [1]  [0] ]  = m_MT_R_1che2pao1pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [1]  [0]  [2] ]  = m_MT_B_1che2pao1pawn_R_1che1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [1]  [1]  [1] [1]  [0]  [1] ]  = m_MT_R_1che1pao1ma1pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [1]  [1]  [1] ]  = m_MT_B_1che1pao1ma1pawn_R_1che1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [1]  [2]  [0] [1]  [0]  [1] ]  = m_MT_R_1che2ma1pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che1pao2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [1]  [2]  [0] [1]  [1]  [0] ]  = m_MT_R_1che2ma1pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [1]  [2]  [0] ]  = m_MT_B_1che2ma1pawn_R_1che1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [0]  [2]  [2] ]  = m_MT_R_1che1pao2pawn_B_2pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [2] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [0]  [1]  [2] ]  = m_MT_R_1che1ma2pawn_B_2pao1ma1pawn; //
	funMat[MARR->a[1]  [2]  [0]  [1]  [2] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [0]  [1] [1]  [1]  [0] ]  = m_MT_R_1che1pao2pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [2]  [1]  [1]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che1ma2pawn;

    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [0]  [1]  [2] ]  = m_MT_R_1che1pao2pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [2] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2pao1ma1pawn;    

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [3]  [1]  [0]  [1] [1]  [0]  [0] ]  = m_MT_R_1che1pao2pawn_B_1che3pawn;
	funMat[MARR->a[3]  [2]  [1]  [0]  [0] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1che3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [0]  [1] [0]  [2]  [2] ]  = m_MT_R_1che1pao2pawn_B_2pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [2] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_2pao2ma;
    
	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1] [0]  [2]  [1] ]  = m_MT_R_1che1pao2pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [1] [1]  [0]  [1] ]  = m_MT_B_1che1pao2pawn_R_1pao2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [1]  [1]  [0] [1]  [1]  [0] ]  = m_MT_BR_1che1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [3]  [1]  [1]  [0] [1]  [0]  [0] ]  = m_MT_R_1che1ma2pawn_B_1che3pawn;
	funMat[MARR->a[3]  [2]  [1]  [0]  [0] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1che3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [0]  [1]  [1]  [0] [0]  [2]  [2] ]  = m_MT_R_1che1ma2pawn_B_2pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [2] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2pao2ma;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [0]  [1]  [2] ]  = m_MT_R_1che1ma2pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [2] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_2pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0] [0]  [2]  [1] ]  = m_MT_R_1che1ma2pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [1] [1]  [1]  [0] ]  = m_MT_B_1che1ma2pawn_R_1pao2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [3]  [1]  [0]  [0] [1]  [0]  [0] ]  = m_MT_BR_1che3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [4]  [1]  [0]  [0] [0]  [0]  [0] ]  = m_MT_R_1che3pawn_B_4pawn;
	funMat[MARR->a[4]  [3]  [0]  [0]  [0] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_4pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [1]  [2] ]  = m_MT_R_1che3pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [2] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_2pao1ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [1]  [1]  [0]  [0] [0]  [2]  [1] ]  = m_MT_R_1che3pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [1] [1]  [0]  [0] ]  = m_MT_B_1che3pawn_R_1pao2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [1]  [2] [0]  [1]  [2] ]  = m_MT_BR_2pao1ma1pawn;

    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [1]  [2] [0]  [2]  [1] ]  = m_MT_R_2pao1ma1pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [1]  [0]  [2]  [1] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1pao2ma1pawn;


	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [0]  [1]  [2] [0]  [1]  [1] ]  = m_MT_R_2pao1ma1pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [1]  [2] ]  = m_MT_B_2pao1ma1pawn_R_1pao1ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [2]  [0]  [2]  [1] [0]  [1]  [1] ]  = m_MT_R_1pao2ma1pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [1] [0]  [2]  [1] ]  = m_MT_B_1pao2ma1pawn_R_1pao1ma2pawn;

    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[1]  [1]  [0]  [2]  [1] [0]  [2]  [1] ]  = m_MT_BR_1pao2ma1pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [0]  [2] [0]  [0]  [2] ]  = m_MT_BR_2pao2pawn;  

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [0]  [2] [0]  [1]  [1] ]  = m_MT_R_2pao2pawn_B_1pao1ma2pawn;  //2炮2兵对1炮1马2兵
	funMat[MARR->a[2]  [2]  [0]  [1]  [1] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_1pao1ma2pawn;

    //           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [0]  [2] [0]  [2]  [0] ]  = m_MT_R_2pao2pawn_B_2ma2pawn;       //2炮2兵对2马2兵
	funMat[MARR->a[2]  [2]  [0]  [2]  [0] [0]  [0]  [2] ]  = m_MT_B_2pao2pawn_R_2ma2pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [3]  [0]  [0]  [2]  [0]  [0]  [1]] = m_MT_R_2pao2pawn_B_1pao3pawn;       //2炮2兵对1炮3兵
	funMat[MARR->a[3]  [2]  [0]  [0]  [1]  [0]  [0]  [2]] = m_MT_B_2pao2pawn_R_1pao3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [1]  [1] [0]  [1]  [1] ]  = m_MT_BR_1pao1ma2pawn;  

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[2]  [2]  [0]  [1]  [1] [0]  [2]  [0] ]  = m_MT_R_1pao1ma2pawn_B_2ma2pawn;  //1炮1马2兵对2马2兵
	funMat[MARR->a[2]  [2]  [0]  [2]  [0] [0]  [1]  [1] ]  = m_MT_B_1pao1ma2pawn_R_2ma2pawn;

	funMat[MARR->a[2]  [2]  [0]  [2]  [0] [0]  [2]  [0] ]  = m_MT_BR_2ma2pawn;  

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [4]  [0]  [0]  [1] [0]  [0]  [0] ]  = m_MT_R_1pao3pawn_B_4pawn;
	funMat[MARR->a[4]  [3]  [0]  [0]  [0] [0]  [0]  [1] ]  = m_MT_B_1pao3pawn_R_4pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [3]  [0]  [1]  [0] [0]  [1]  [0] ]  = m_MT_BR_1ma3pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[3]  [4]  [0]  [1]  [0] [0]  [0]  [0] ]  = m_MT_R_1ma3pawn_B_4pawn;
	funMat[MARR->a[4]  [3]  [0]  [0]  [0] [0]  [1]  [0] ]  = m_MT_B_1ma3pawn_R_4pawn;

	//           红兵 黑卒 红车 红马 红炮 黑车 黑马 黑炮 
	funMat[MARR->a[4]  [4]  [0]  [0]  [0] [0]  [0]  [0] ]  = m_MT_4pawn_TO_4pawn;

}