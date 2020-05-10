#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"



void m_MT_BR_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){


  // fen C1cak1b2/4aRN2/4bn3/6r2/9/9/9/3AB4/9/2BAK4 b - - 0 1

  Square rk = RKpos();
  Square bk = BKpos();

  Square bpao = S90_from_piecelist(POSITION,BPAO,0);
  Square rpao = S90_from_piecelist(POSITION,RPAO,0);
  Square rche = S90_from_piecelist(POSITION,RCHE,0);
  Square bche = S90_from_piecelist(POSITION,BCHE,0);
  Square bma  = S90_from_piecelist(POSITION,BMA,0);
  Square rma  = S90_from_piecelist(POSITION,RMA,0);

  if((RShi_num() + RXiang_num()) >= 3 && StoY(rk) >= 0x8){
	  if((BShi_num() + BXiang_num()) == 0x4){
		  if(PB90(0x0d) == BSHI && bk == 0x04 && bit_is_set(ei.attacked_by(BCHE),rma)){
			  if(bma == 0x17 && rche == 0x0e && rma == 0x0f){
				  if(StoX(rpao) < 0x4 && StoX(bpao) < 0x4){
					  RETRUN_MUL(8);
				  }
			  }
			  if(bma == 0x15 && rche == 0x0c && rma == 0x0b){
				  if(StoX(rpao) > 0x4 && StoX(bpao) > 0x4){
					  RETRUN_MUL(8);
				  }
			  }
		  }
	  }
  }

  if((BShi_num() + BXiang_num()) >= 3 && StoY(bk) <= 0x01){
	  if((RShi_num() + RXiang_num()) == 0x4){
		  if(PB90(0x4c) == RSHI && rk == 0x55 && bit_is_set(ei.attacked_by(RCHE),bma)){
			  if(rma == 0x44 && bche == 0x4d && bma == 0x4e){
				  if(StoX(rpao) < 0x4 && StoX(bpao) < 0x4){
					  RETRUN_MUL(8);
				  }
			  }
			  if(rma == 0x42 && bche == 0x4b && bma == 0x4a){
				  if(StoX(rpao) > 0x4 && StoX(bpao) > 0x4){
					  RETRUN_MUL(8);
				  }
			  }
		  }
	  }
  }


}