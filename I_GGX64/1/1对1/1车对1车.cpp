
#include "../../chess.h"
#include "../../preGen.h"
//
//能不能和，怎样胜
#pragma warning(disable : 4100)                    // unreferenced formal parameter  
//红方一个兵, 黑方一个兵, 总是和棋
void m_MT_1CHE_TO_1CHE(typePOS &POSITION, EvalInfo &ei){  //因为兵的位置分相差太大
	RETRUN_MUL(1);
}