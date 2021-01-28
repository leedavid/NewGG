#ifndef END_my_m_MT_R_2pao1pawn_B_1ma2pawn
#define END_my_m_MT_R_2pao1pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int _OnlyOnePawnCanOverRiver = 96; 
//const int  ADD_2PaoXPawn_1Ma2Pawn_ByPawn[3]         = {96, 64, 32};            //2炮兵对1马2兵, 多兵的加分
//const int  ADD_1Ma2Pawn_2PaoXPawn_ByPawn[3]         = {96, 64, 32};            //1马2兵对2炮兵, 多兵的加分

 void my_m_MT_R_2pao1pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	 // ADD_MY
	 Square yk = your_king_pos;
	 Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	 int pmok = (int)count_1s(bmp);
	 MY_EV_ADD(pmok * ADD_2PaoXPawn_1Ma2Pawn_ByPawn[your_shi_num]);
	 // SUB
	 Square mk = my_king_pos;
	 Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	 int pyok = (int)count_1s(ymp);
	 MY_EV_SUB(pyok * ADD_1Ma2Pawn_2PaoXPawn_ByPawn[my_shi_num]);

	 Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	 // fen 5k3/2P1a4/3aCn3/9/9/6B2/3pp4/5A3/4AC3/2BK5 b - - 0 1
	 Bitboard lp = Your_get_connect_Pawn(POSITION);
	 if(bit_is_set(lp,Square(MY_SQ31)) || bit_is_set(lp,Square(MY_SQ3A))){
		 MY_EV_SUB(128);
	 }

	 if(!IsOnSameSide(mpawn,yk) && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		 if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			 if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ15) == your_shi){
				 RETRUN_MUL(4);
			 }
			 if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ17) == your_shi){
				 RETRUN_MUL(4);
			 }
		 }
	 }
	
	// fen 4kab2/4a4/4b4/1CC3P2/5n3/4pp3/9/4B4/4A4/2BAK4 w
	 if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		 // fen 2bak4/4aC3/4b4/4p3p/9/2P1n4/9/4B1C2/4K4/2BA1A3 b - - 0 1
		 if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){

			 Bitboard mlp = My_get_connect_Pawn(POSITION);
			 mlp = m_and(mlp,MyLowBB[MY_RANK2]);

			 if(m_have_bit(mlp)){
				 RETRUN_MUL(4);
			 }
			 // fen 2bak4/4aC3/4b4/4p3p/9/2P1n4/9/4B1C2/4K4/2BA1A3 b - - 0 1
			 if(EV_MY_CAN == 0){
				 RETRUN_MUL(4);
			 }

			 RETRUN_MUL(8);
		 }
	 }

 }
