#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"


bool isPretecte_TrueCap(const typePOS *POSITION, int side, int sqDst){

	int from;
	Bitboard att = sq_attacked_by_color(POSITION,sqDst,side);

	while(m128_is_have_bit(att)){  //当有保护存在
		from = pop_1st_bit(&att);
		//if(Is_Can_Move_To_Eat(board,from,sqDst)) return TRUE;
		if(pseudo_is_legal(MOVE_FromTo(from,sqDst),POSITION) == TRUE){
			return TRUE;
		}
	}

	return FALSE;

	////走子方是不是有棋子在保护sqDst;

	////
	//if(side == WHITE){
	//	Bitboard bb;

	//	attack

	//	//1, 是不是受红车保护
	//	rook_attacks(bb,board,sqDst);
	//	BB_and_BB(bb,board->byChessBB[RCHE]);

	//	while(m128_is_have_bit(bb)){  //当有车存在
 //            int from = pop_1st_bit(&att);
	//		 if(Is_Can_Move_To_Eat(board,from,sqDst)) return TRUE;
	//	}

	//	//2, 是不是受红马保护
	//	king_to_ma_attacks(bb,board,sqDst);
	//	BB_and_BB(bb,board->byChessBB[RMA]);

	//	while(m128_is_have_bit(bb)){  //当有马存在
 //            int from = pop_1st_bit(&att);
	//		 if(Is_Can_Move_To_Eat(board,from,sqDst)) return TRUE;
	//	}

	//	//3, 是不是受红炮的保护
	//	pao_eat_attacks(bb,board,sqDst);
	//	BB_and_BB(bb,board->byChessBB[RPAO]);

	//	while(m128_is_have_bit(bb)){  //当有炮存在
 //            int from = pop_1st_bit(&att);
	//		 if(Is_Can_Move_To_Eat(board,from,sqDst)) return TRUE;
	//	}

	//	//4, 是不是受
	//}
	//else{
	//}
}

//上次这个子是不是提供了保护.
//bool isCanProtect_Last_Move(const typePOS *POSITION, int side, int from, int to){
//
//	int piece = PB90(from);
//
//	if(PIECE_SIDE(piece) != side) return FALSE;
//
//	//Bitboard att;
//
//	switch(piece){
//		case RMA:
//		case BMA:
//			return (bit_is_set(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
//			break;
//		case RXIANG:
//		case BXIANG:
//			return (bit_is_set(xiang_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
//			break;
//		case BSHI:
//		case RSHI:
//			return (bit_is_set(shi_attacks(to),from) !=0);
//			break;
//		case RCHE:
//		case BCHE: 
//			return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
//			break;
//		case RPAO:
//		case BPAO:			
//			return (bit_is_set(pao_eat_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
//			break;
//		case RPAWN:
//		case RKING:
//			return (bit_is_set(attacks_by_rpawn_rk(to),from) !=0);
//			break;
//		case BPAWN:
//		case BKING:
//			return (bit_is_set(attacks_by_bpawn_bk(to),from) !=0);
//			break;		
//		default:
//			return FALSE;
//	}
//	return FALSE;
//}

//	switch(piece){
//		case RMA:
//		case BMA:{
//			//得到马的所有走步			
//			king_to_ma_attacks(att,board,to); 
//			return (bit_is_set(att,from) !=0);
//				 }
//			break;
//		case RXIANG:
//		case BXIANG:{
//			xiang_attacks(att,board,to); 
//			return (bit_is_set(att,from) !=0);
//					}
//			break;
//		case BSHI:
//		case RSHI:			{
//			shi_attacks(att,to); 
//			return (bit_is_set(att,from) !=0);
//				  }
//			break;
//		case RCHE:
//		case BCHE:{ //不吃子与吃子
//			rook_attacks(att,board,to); 
//			return (bit_is_set(att,from) !=0);
//				  }
//			break;
//		case RPAO:
//		case BPAO:{//不吃子
//			if(cap == EMPTY16){
//				rook_attacks(att,board,to); 
//				return (bit_is_set(att,from) !=0);
//			}
//			else{
//				pao_eat_attacks(att,board,to);
//				return (bit_is_set(att,from) !=0);
//			}
//				  }
//			break;
//		case RPAWN:{
//			attacks_by_rpawn_rk(att,to);
//			return (bit_is_set(att,from) !=0);
//				   }
//			break;
//		case BPAWN:{
//			attacks_by_bpawn_bk(att,to);
//			return (bit_is_set(att,from) !=0);
//				   }
//			break;
//		case RKING:{
//			attacks_by_rpawn_rk(att,to);
//			return (bit_is_set(att,from) !=0);
//				   }
//			break;
//		case BKING:{
//			attacks_by_bpawn_bk(att,to);
//			return (bit_is_set(att,from) !=0);
//				   }
//			break;
//		default:
//			return FALSE;
//	}
//
//
//	return FALSE;
//}

#endif