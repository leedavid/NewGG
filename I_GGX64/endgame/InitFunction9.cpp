#ifndef E_InitMatFunction9
#define E_InitMatFunction9
#include "..\\chess.h"
 
#include "..\\white.h"
#else
#include "..\\black.h"
#endif


void InitMatFunction9(void){
	//********************************************* 9 对 0**********/
	//********************************************* 9 对 1**********/
	//********************************************* 9 对 2**********/
	//********************************************* 9 对 3**********/
	//********************************************* 9 对 4**********/

	//********************************************* 9 对 5**********/

	//           红兵  黑卒 红车 红马 红炮 黑车 黑马 黑炮  
	funMat[MARR->a[5]  [2]  [0]  [2]  [2]  [1]  [0]  [2]  ]  = m_MT_R_2pao2ma5pawn_B_1che2pao2pawn;
	funMat[MARR->a[2]  [5]  [1]  [0]  [2]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma5pawn_R_1che2pao2pawn;
	//************************************9 对 6**********
	//           红兵  黑卒 红车 红马 红炮 黑车 黑马 黑炮  
	funMat[MARR->a[5]  [2]  [1]  [2]  [1]  [1]  [2]  [1]  ]  = m_MT_R_1che1pao2ma5pawn_B_1che1pao2ma2pawn;
	funMat[MARR->a[2]  [5]  [1]  [2]  [1]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma5pawn_R_1che1pao2ma2pawn;

	//           红兵  黑卒 红车 红马 红炮 黑车 黑马 黑炮  
	funMat[MARR->a[5]  [2]  [1]  [1]  [2]  [1]  [2]  [1]  ]  = m_MT_R_1che2pao1ma5pawn_B_1che1pao2ma2pawn;
	funMat[MARR->a[2]  [5]  [1]  [2]  [1]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma5pawn_R_1che1pao2ma2pawn;
	//********************************************* 9 对 7**********/
	//********************************************* 9 对 8**********/
	//********************************************* 9 对 9**********/
}