
#ifndef END_my_m_MT_R_1PAO_B_1MA
#define END_my_m_MT_R_1PAO_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "1炮对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//红方一个炮, 黑方一个马 //一马和炮双士 
void my_m_MT_R_1PAO_B_1MA(typePOS &POSITION, EvalInfo &ei){

	if(my_shi_num == 0){
		RETRUN_MUL(1);
	}

	//如果马方有什或相，和
	if(your_shi_num > 0 || your_xiang_num > 0){
		RETRUN_MUL(2);
	}

	//<<象棋残局例典>>，第16局  一马例和炮仕相全
	//看炮方能不能胜
	//if((Info16 & (CK_R_1x + CK_R_2x)) == 0){		//炮方没有相
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	if(StoY(yma) MY_LARGE MY_RANK4){
		if(King_4_Side(yma) == King_4_Side(mpao)){
			RETRUN_MUL(2);
		}
	}
	//if(bma > 0x80){
	//	if(King_4_Side(bma) == King_4_Side(rpao)){
	//		return 2;
	//	}
	//}
	RETRUN_MUL(4);
 
}
