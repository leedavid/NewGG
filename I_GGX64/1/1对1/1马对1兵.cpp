#ifndef END_my_m_MT_R_1MA_B_1PAWN
#define END_my_m_MT_R_1MA_B_1PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "1马对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//能不能和，怎样胜


// <<象棋殘局例典>>
// 第1页 第2局 底兵例和一马

//红方一个马, 黑方一个兵
void my_m_MT_R_1MA_B_1PAWN(typePOS &POSITION, EvalInfo &ei){

   Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

   if(abs(StoX(ypawn) - 0x4) >= 3){
	   MY_EV_SUB(196);
   }

   if(StoY(ypawn) MY_LARGE MY_RANK4){
	   if(abs(StoX(ypawn) - 0x4) > 1){
		   MY_EV_SUB(64);
	   }

	   // 如果对方的兵可能被困死，也不是和
	   if(StoY(ypawn) == MY_RANK9){
		   if(your_shi_num <= 1 && your_xiang_num == 0
			   && my_xiang_num >= 1){
			   if(abs(StoX(ypawn) - 0x4) <= 1){
				   RETRUN_MUL(8);
			   }
		   }
	   }
	   RETRUN_MUL(1);
   }
   if((your_shi_num + your_xiang_num) >= 2){
	   RETRUN_MUL(1);
   }

   if(your_xiang_num >= 1){
	   RETRUN_MUL(1);
   }



   // 这个可能胜哇
   if(your_shi_num <= 1){
	   if(StoY(ypawn) == MY_RANK9){
		   if((StoX(ypawn) -0x4) <= 1){
			   if(my_xiang_num != 0){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

   RETRUN_MUL(2);
}

