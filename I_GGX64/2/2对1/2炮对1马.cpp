#ifndef END_my_m_MT_R_2pao_B_1ma
#define END_my_m_MT_R_2pao_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// 2炮对1马


// fen 4ck3/4a4/3a5/1N7/6b2/6B2/4c4/9/4A4/2BAK4 w - - 126 126 

void my_m_MT_R_2pao_B_1ma(typePOS &POSITION, EvalInfo &ei){

   Square yk  = your_king_pos;
   Square mk = my_king_pos;
   Square yma = S90_from_piecelist(POSITION,your_ma,0);
   
   // fen 2b6/4a4/3a1k3/6N2/9/6B2/9/B2A1A3/3K5/cc7 b - - 135 135
   if((your_shi_num + your_xiang_num) == 4){
	   if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		   RETRUN_MUL(2);
	   }
   }

   // fen 3c5/9/5k3/4c1N2/9/2B3B2/9/5A3/9/3K5 b - - 123 123
   if((my_shi_num + my_xiang_num) == 0){
	   if(your_xiang_num == 2){
		  RETRUN_MUL(2);
	   }
   }

   // fen 4k1b2/9/8b/9/2n6/9/4C4/3C5/4A4/5K3 b - - 0 1
   if(your_xiang_num == 2){
	   if(my_shi_num <= 1 && my_xiang_num <= 1){
		   if(!bit_is_set(EV_MY_XBIT,yma)){
			   RETRUN_MUL(2);
		   }
	   }
   }

   //  fen 3k5/9/9/9/8n/2B6/9/3CB4/4CK3/9 w - - 0 1
   if (my_shi_num == 0) {
	   if (StoX(mk) != 0x4) {
		   if (!bit_is_set(EV_MY_XBIT, yma)) {
			   RETRUN_MUL(2);
		   }
	   }
   }


   // fen 3k5/4a4/5a3/9/6b2/9/3CC4/4B4/1n2A4/3A1KB2 w - - 0 1
   if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	   if(!bit_is_set(EV_MY_XBIT,yma)){ // fen 4k4/4a4/5a3/9/4n1b2/9/3CC4/4B4/4A4/3A1KB2 b
	      RETRUN_MUL(2);
	   }
   }

   // fen 3c5/9/5k3/4c1N2/9/2B3B2/9/5A3/9/3K5 b - - 123 123
   if(my_shi_num == 0 && my_xiang_num <= 1){
	   if(your_xiang_num == 2){
		  if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			  RETRUN_MUL(2);
		  }
	   }
	   // fen 2bk5/9/9/9/1N7/1cB6/9/3ABK3/c3A4/9 r
       if(your_xiang_num == 2 && your_shi_num >= 1){
		   RETRUN_MUL(2);
	   }

	   // fen 9/9/3k5/2N3c2/1cb6/9/9/4B4/9/5K3 w - - 225 225 
	   if(your_xiang_num >= 1 && StoY(yk)  MY_SMALL_EQL MY_RANK1){
		    RETRUN_MUL(4);
	   }
   }



   // fen 6b2/3ka4/3n5/4C4/2b6/2B6/9/3AB4/3C5/3A1K3 w - - 3 3
   if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk)  MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
   }

   // fen 4c4/3c5/3abk3/9/2b6/5N3/9/4BA3/4A4/4K4 w - - 0 1
   if((your_shi_num + your_xiang_num) >= 3){
	   if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		   RETRUN_MUL(4);
	   }
   }

  if(my_shi_num == 0){
	  RETRUN_MUL(4);
  }

  //fen 1c7/3ka4/5a3/9/4c4/2B3B1N/9/9/9/4K4 w - - 0 1
  if (your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	  if (!bit_is_set(EV_MY_XBIT, yma)){
		  RETRUN_MUL(4);
	  }
  }


}


