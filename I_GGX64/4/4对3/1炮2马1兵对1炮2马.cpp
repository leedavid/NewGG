#ifndef END_my_m_MT_R_1pao2ma1pawn_B_1pao2ma
#define END_my_m_MT_R_1pao2ma1pawn_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马1兵对1炮2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2ma1pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn[your_shi_num]);

	Square mk = my_king_pos;
	
   if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	   MY_EV_ADD(32);
   }

   Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
   Square ypao  = S90_from_piecelist(POSITION,your_pao,0);


   // fen 3k1a3/4ac3/4b3b/5N3/P8/2B2n3/4N1C2/9/4A1n2/5K3 w - - 0 1
   if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
	   MY_EV_ADD(EV_MY_CAN * 64);
   }

   // fen 2ba1k3/4a4/4b1c2/1P6c/9/2C3nC1/9/5A2N/4A4/4K4 b - - 0 1
   if(my_shi_num == 2 || my_xiang_num == 2){
	   if(StoY(mk) MY_LARGE_EQL MY_RANK8){
		   MY_EV_ADD(EV_MY_CAN * 32);
		   if(StoY(mpawn) == MY_RANK3){
			   MY_EV_ADD(32);
		   }
	   }
   }

   // fen 3k4C/4a2nN/3a5/7N1/2b3b1p/6B2/8n/9/4A4/4KAB1c b - - 0 1
   if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
	   if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
		   ////if(bit_is_set(YOUR_ATTACK,mpawn)){
			  // //if(!bit_is_set(ei.attacked_by(my_xiang],mpawn)){
				 //  MY_EV_SUB(64);
			  // //}
		   ////}
		   // fen 2bak4/4a4/4b4/9/1P2N1nC1/3Nn1B2/9/9/4A4/4KABc1 b - - 0 1
		   RETRUN_MUL(8);
	   }
   }

   // fen 2b2k3/4ac3/5a3/3P3N1/1N4b2/6Bn1/4C4/2nA5/3KA4/2B6 b - - 0 1
   if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
	   if(StoY(ypao) MY_SMALL_EQL MY_RANK1 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		   RETRUN_MUL(10);
	   }
   }


}

