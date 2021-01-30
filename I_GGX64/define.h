
#ifndef stockfish_MY_definee_H
#define stockfish_MY_definee_H


#define MOVE_BIT  8
#define MOVE_MASK 0x7f
#define MOVE07FFF 0x7fff

#define FROM(m)				   Square((((m)>>MOVE_BIT) & MOVE_MASK))  
#define TO(m)				   Square(((m) & MOVE_MASK))              
#define MOVE_FromTo(from,to)   Move((to)|((from) << MOVE_BIT))   
#define StoY(s) (_stoy[s])       
#define StoX(s) (_stox[s])       
#define XYtoS(x,y)  (Square((y)*9+(x)))



// 兼容设定 *******************************************

#define RETRUN_MUL(x)  { ei.mul = x; return; }

#define S90_from_piecelist(POSITION,piece,index)  (POSITION.piece_list(piece,index))
#define RKpos()   POSITION.piece_list(RKING,0) 
#define BKpos()   POSITION.piece_list(BKING,0) 
#define bb_white_king 	POSITION.pieces(RKING) 
#define bb_black_king	 	POSITION.pieces(BKING) 
#define bitboard_occ_white  	POSITION.pieces(NO_PIECE)  
#define bitboard_occ_black  	POSITION.pieces(_X_X)  
#define bb_white_shi 		POSITION.pieces(RSHI) 
#define bb_black_shi 		POSITION.pieces(BSHI) 
#define bb_white_xiang 	POSITION.pieces(RXIANG) 
#define bb_black_xiang 	POSITION.pieces(BXIANG) 
#define bb_white_che 		POSITION.pieces(RCHE) 
#define bb_black_che 		POSITION.pieces(BCHE) 
#define bb_white_pao		POSITION.pieces(RPAO) 
#define bb_black_pao 		POSITION.pieces(BPAO)    
#define bb_white_ma 		POSITION.pieces(RMA)     
#define bb_black_ma 		POSITION.pieces(BMA)     
#define bb_white_pawn 	POSITION.pieces(RPAWN)
#define bb_black_pawn 	POSITION.pieces(BPAWN)
#define BitboardOCC             POSITION.occupied_squares()


#define RChe_num()    POSITION.piece_count(RCHE)  
#define RMa_num()     POSITION.piece_count(RMA)   
#define RPao_num()    POSITION.piece_count(RPAO)  
#define RPawn_num()   POSITION.piece_count(RPAWN) 
#define RXiang_num()  POSITION.piece_count(RXIANG)
#define RShi_num()    POSITION.piece_count(RSHI)  

#define BChe_num()    POSITION.piece_count(BCHE)  
#define BMa_num()     POSITION.piece_count(BMA)    
#define BPao_num()    POSITION.piece_count(BPAO)   
#define BPawn_num()   POSITION.piece_count(BPAWN)  
#define BXiang_num()  POSITION.piece_count(BXIANG)  
#define BShi_num()    POSITION.piece_count(BSHI)      


#endif