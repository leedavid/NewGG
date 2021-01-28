#ifndef END_my_m_MT_R_2pao1pawn_B_1che1pao
#define END_my_m_MT_R_2pao1pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

#pragma warning(disable : 4100)       
//2炮1兵对车炮
void my_m_MT_R_2pao1pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

    
	MY_EV_SUB(96);
	// fen 4k4/4a4/3ab4/9/6b2/2P4r1/9/4B3C/4A4/c1CAK1B2 b - - 95 95


	//m_MT_B_1che1pao_R_2pao(board,ei);
}

//void m_MT_B_2pao1pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//
//	m_MT_R_1che1pao_B_2pao(board,ei);
//}
