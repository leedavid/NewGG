#ifndef BUILD_mossa_garantire
#define BUILD_mossa_garantire
#include "chess.h"
 
#include "ok_move.cpp"
#include "white.h"
#else
#include "black.h"
#endif

// 

#ifdef USE_STOCK_FISH_FILE
#else

boolean  MyOK (const typePOS *POSITION, uint32 mossa)
{
  int from,to;
  uint8 piece,capture;

  from = FROM(mossa);
  to   = TO(mossa);

  piece = PB90(from);

  if(piece == 0) return FALSE;

  if(PIECE_IS_OPP(piece)){
	  //board_display(POSITION,"piece is opp\n");
	  return FALSE;
  }

  capture = PB90(to);

  if(capture && PIECE_IS_MINE(capture) ) {
	  //board_display(POSITION,"PIECE_IS_MINE\n");
	  return FALSE;
  }

  if(capture == your_king ){
	  ASSERT(0); // 在走步生成,要产生吃将步才行. 也就是对将时,我方的将可吃对方的将.
	  return FALSE;
  }

  switch(piece){
  case my_ma: //得到马的所有走步	
	  //print_bb(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack));
	  return (bit_is_set(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  case my_xiang:
	  //print_bb(xiang_attacks_bb(to,POSITION->byWhiteBlack));
	  return (bit_is_set(xiang_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  case my_shi:
	  //print_bb(shi_attacks(to));
	  return (bit_is_set(shi_attacks(to),from) !=0);
  case my_che: //不吃子与吃子
	  return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  case my_pao://不吃子
	  if(capture == EMPTY){
		  return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
	  }
	  else{
		  return (bit_is_set(pao_eat_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
	  }
  case my_pawn:
  case my_king:	{
	  //print_bb(my_pawn_k_attacks(from));
	  return (bit_is_set(my_pawn_k_attacks(from),to) !=0);
				}
  default:
	  return FALSE;
  }


  //return FALSO;
}

#endif
