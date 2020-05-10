#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"

//所有的走步是不是可以走
bool move_is_pseudo(int move, typePOS *POSITION) {

	int from  = FROM(move);
	int to    = TO(move);
	int piece = PB90(from);
	int cap   = PB90(to);

	if(PIECE_SIDE(piece) != POS_SIDE){  // 这个因为相反,所以要这样.
		return FALSE;
	}

	if(PIECE_SIDE(piece) == PIECE_SIDE(cap)){
		return FALSE;
	}

	//Bitboard att;

	switch(piece){
		case RMA:
		case BMA:{
			//得到马的所有走步			
			return (bit_is_set(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
				 }
			break;
		case RXIANG:
		case BXIANG:{
			return (bit_is_set(xiang_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
					}
			break;
		case BSHI:
		case RSHI:			{
			return (bit_is_set(shi_attacks(to),from) !=0);
				  }
			break;
		case RCHE:
		case BCHE:{ //不吃子与吃子
			return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
				  }
			break;
		case RPAO:
		case BPAO:{//不吃子
			if(cap == EMPTY){
				return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
			}
			else{
				return (bit_is_set(pao_eat_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
			}
				  }
			break;
		case RPAWN:{
			return (bit_is_set(attacks_by_rpawn_rk(to),from) !=0);
				   }
			break;
		case BPAWN:{
			return (bit_is_set(attacks_by_bpawn_bk(to),from) !=0);
				   }
			break;
		case RKING:{
			return (bit_is_set(attacks_by_rpawn_rk(to),from) !=0);
				   }
			break;
		case BKING:{
			return (bit_is_set(attacks_by_bpawn_bk(to),from) !=0);
				   }
			break;
		default:
			return FALSE;
	}


	//return FALSE;
}

  //switch(piece){
  //case my_ma: //得到马的所有走步		  		
	 // return (bit_is_set(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  //case my_xiang:
	 // return (bit_is_set(xiang_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  //case my_shi:
	 // return (bit_is_set(shi_attacks(to),from) !=0);
  //case my_che: //不吃子与吃子
	 // return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  //case my_pao://不吃子
	 // if(capture == EMPTY){
		//  return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
	 // }
	 // else{
		//  return (bit_is_set(pao_eat_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
	 // }
  //case my_pawn:
  //case my_king:	
	 // return (bit_is_set(my_pawn_k_attacks(to),from) !=0);
  //default:
	 // return FALSE;
  //}

#endif