#ifndef END_my_m_MT_R_2PAWN_B_1MA
#define END_my_m_MT_R_2PAWN_B_1MA
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2兵对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int PawnShiAdd[3] = {96,48,0};

void my_m_MT_R_2PAWN_B_1MA(typePOS &POSITION, EvalInfo &ei){

   Square yk   = your_king_pos;
   int mcan = EV_MY_CAN;
   Square yma = S90_from_piecelist(POSITION,your_ma,0);

   MY_EV_ADD(ADD_XPawnToMa_ByPawnShi[your_shi_num]);

   if(mcan <= 1){
	   RETRUN_MUL(2);
   }

   if(your_shi_num >= 1){
	   RETRUN_MUL(2);
   }

   // fen 4k1b2/6P2/b6P1/4n4/9/6B2/9/4B4/4A4/5K3 w - - 120 120
   if(mcan == 2 && PB90(MY_SQ0D) == my_pawn && StoY(yk) == MY_RANK0){

   }
   else{
	   RETRUN_MUL(2);
   }

   // fen 5k3/4P4/8b/4P4/2b6/4n4/9/B3BA3/4A4/5K3 b - - 0 1
   if(your_xiang_num >= 1){
	   if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
		   if(!bit_is_set(EV_MY_XBIT,yma)){
			   RETRUN_MUL(2);
		   }
	   }
   }

   // fen 3k5/9/9/9/9/9/7N1/4B1p2/4p4/5K3 w - - 0 1
   if(your_xiang_num >= 1 && PB90(MY_SQ0D) == my_pawn){
	   Bitboard bmp = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
	   if(MY_SQ03 == yk && PB90(MY_SQ1C) == your_ma){
		   if(have_bit(bmp,LeftBB[0x4])){
			   RETRUN_MUL(4);
		   }
	   }
	   if(MY_SQ05 == yk && PB90(MY_SQ22) == your_ma){
		   if(have_bit(bmp,RightBB[0x4])){
			   RETRUN_MUL(4);
		   }
	   }
   }



}

