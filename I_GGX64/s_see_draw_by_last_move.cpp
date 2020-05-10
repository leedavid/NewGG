#include "chess.h"


////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>


#include "mersenne.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

using std::string;

bool Position::see_draw_by_last_move(Square mfrom, Square mto, Square ofrom, Square oto, 
	Color which, TrupCap_t* TRUECap, bool incheck){

	ExtMove mlist[MAX_MOVES];
	ExtMove *cur, *last;
	Move  undo_m;
	Piece undo_capture;
	Move m;
	Square becap;
	Square cap;
	int i;
	int this_num;
	Piece n_to_id;
	Square n_last_cap_to;
	int last_num;
	Piece to_id;

	TRUECap->cap_num[0][which] = 0; // 本次捉的次数.
	TRUECap->isTrueCap = false;

	last = cattura_not_include_pawn_king(mlist,~sideToMove); // 

	undo_m       = MOVE_FromTo(mfrom,mto);
	undo_capture = EMPTY;

#ifdef DEBUG_REPEAT
	if(b90[mto] == EMPTY || (color_of(b90[mto]) == sideToMove)){
		board_display("undo_piece = 0");
		undo_m = undo_m;
	}
	ASSERT(b90[mto] != EMPTY);
#endif

	move_undo_test(undo_m,undo_capture);
	
	for (cur = mlist; cur != last; cur++){			
		m = cur->move;	
		becap = TO(m);
		cap   = FROM(m);		
		
		// fen 3k1ab2/4a4/4b3n/p4Cp2/5PP2/P3c1p2/3n1R3/3NB4/2N1A4/2BAK3r r
		// fen 3k1ab2/4a4/4b3n/p4Cp2/5PP2/P3c1p2/3n4r/3NB4/2N1A4/2BAKR3 r moves f0f3 i3i0 f3f0 i0i3 f0f3
		//if(incheck){
		//	if(FROM(m) != mto){
		//		cur->move = MOVE_NONE;
		//	}
		//}
		// 2, 上次这个棋子是不是已在捉了.
		if(TO(undo_m) == FROM(m)){  			

			//board_display(POSITION,"cap not exit");
			if(pseudo_legal(MOVE_FromTo(FROM(undo_m),becap)) == false){ //上一次不存在这个捉
				//board_display(POSITION,"cap not exit");
				// 这次是走的棋子在捉,但上次不是这个棋子在捉.那就不是捉.
			}
			else if(test_Is_True_Cap(FROM(undo_m),becap,~sideToMove)){
				cur->move = MOVE_NONE;
			}
		}
		else{
			// 1, 上次这个棋子不能走到那儿去捉, 1, 是走不到，2，是不能走，走了就是送将了
			if(pseudo_legal(m) == false){ //上一次不存在这个捉
				//board_display(POSITION,"cap not exit");
			}
			else if(legal(m) == false){
				//legal
				// fen CR1akab1r/9/2n1b1n2/2p5p/6p2/2P6/r3P1P1P/4CcN2/9/2BAK1BR1 w - - 0 1 moves b9c9 c7e6 c9b9 e6c7 
			}
			// 2,  这个棋子是可能捉对方, 但他本身不能吃对方. 
			else if(test_Is_True_Cap(cap,becap,~sideToMove)){
				//this_move->move[i] = 0;  //做一个标志.
				cur->move = MOVE_NONE;
			}
		}	
		
	}
//#ifdef DEBUG_REPEAT
	ASSERT(b90[from_sq(undo_m)] != EMPTY);
//#endif
	move_do_test(undo_m, &undo_capture); 

	//余下的是新产生的捉, 如果上次是原来存在的捉,就不要再判断了
	for (cur = mlist; cur != last; cur++){	
		m = cur->move;

		if(m == MOVE_NONE){
			continue;    // 做一个标志.
		}
		// fen 2N2Rb2/3k5/2ra5/p5n2/4C4/P4n3/4c4/4N2CB/3KA4/5A3 b - - 0 1 moves c7c5 c9b7 c5c7 b7c9 c7c5
		if(incheck){
			if(FROM(m) != mto){
				continue;
			}
		}

		// 如果这个TO还有其它的棋子在攻击，则也不算捉。

		// fen 4ca3/3k5/3a5/R8/2r6/4C4/P3P3P/4B4/4A4/4KAB2 w moves  动将吃炮
		// 1, 常捉不过河兵不算捉
		if(b90[TO(m)] == RPAWN && StoY(TO(m)) >= 0x5){
			continue;
		}
		if(b90[TO(m)] == BPAWN && StoY(TO(m)) <= 0x4){
			continue;
		}
		// fen 4k4/4a4/b3b4/9/9/9/9/3A4B/1Cn2p3/3K5 b - - 0 1 moves c1b3 d0d1 b3c1 d1d0 
		if(type_of(b90[mto]) == KING){
			if(type_of(b90[FROM(m)]) != PAO){
				continue;
			}
		}
		if(!legal(m)){
			continue;
		}  // 这个可以放在前面的判断中，也就是这个for放到前面

		if(test_Is_True_Cap(FROM(m),TO(m),which)){ // from,to,side)){ //TRUECap)){ // test_Is_True_Cap(board,cap,becap,from,to,which,TRUECap); 
			
			//保存本次的捉
			to_id = b90[TO(m)];
			int num   = TRUECap->cap_num[0][which];                // 共有多少有吃子步.
			TRUECap->LastCapChess[num][0][which]      = to_id;     // 被捉的棋子.            1. 这个棋子是跑的. 2. 这个棋子是不动的. 
			TRUECap->last_to[num][0][which]           = TO(m);     // 捉子方的吃子步的to
			TRUECap->last_ot_from[num][0][which]      = ofrom;     // 被捉子方走的from 
			TRUECap->last_ot_to[num][0][which]        = oto;
			if(num < MAX_REAL_CAP_NUM - 1){   //最多同时判断三个常捉
				TRUECap->cap_num[0][which]++;
			}
		}
	}

	//**************************************************************************************************
	//所有的捉有列表了, 与上次的所有的捉比对一下, 如果有对同一个ID的,就是捉.
	//这个有二个常捉在, 要二次判断那个捉, 所以这个最复杂.
	// fen 3a1kb2/2r6/4ba3/p6Np/9/P3p1RcP/9/4B4/4A4/2BK1A3 b - - 53 53 
	// fen r2akab2/1c7/2n1b1c2/p1R1p3p/5nr2/9/P3P2NP/1CN1C4/5R3/2BAKAB2 b - - 16 16 
	this_num = TRUECap->cap_num[0][which];
	while(this_num > 0 && TRUECap->isTrueCap == false){  //本次有捉
		this_num --;
		n_to_id        = TRUECap->LastCapChess   [this_num][0][which];

		TRUECap->capture_chess[which] = type_of(n_to_id);  // 保存捉的棋子

		n_last_cap_to  = TRUECap->last_to        [this_num][0][which];
		last_num   = TRUECap->cap_num[1][which];
		if(last_num == 0){                                               // 如果上次没有捉,这个肯定是捉
			TRUECap->isTrueCap = true;			
		}
		else{
			while(last_num > 0){
				last_num --;
				if(TRUECap->LastCapChess[last_num][1][which] == n_to_id){         // 这个二个捉的是同一类棋子. 但可能是不同的棋子. 
					
					// fen 3ak1b2/4a4/4b4/8R/6r2/p3P3p/9/4B4/4A4/4KAB2 b - - 0 1
					// 捉不同的棋子怎样判断
					// fen 3ak1b2/4a4/4b4/8R/6r2/p3P2p1/9/4B4/4A4/4KAB2 w - - 0 1 moves i6h6 h4i4 h6a6 a4b4 a6i6 i4h4 i6b6 b4a4 b6h6 h4i4 h6a6 a4b4 a6i6 i4h4 i6b6 b4a4 b6h6

					// fen 3a5/9/4k4/3N1n3/9/3C2B2/3c5/4B4/2C1A4/4K4 w - - 13 13 3ak1b2/4a4/4b4/8R/6r2/p3P2p1/9/4B4/4A4/4KAB2 w - - 0 1 i6h6
					if(TRUECap->last_to[last_num][1][which] == n_last_cap_to){    // 0x09 目标棋格没有动过。
						TRUECap->isTrueCap = true;                                // 这个一般是让开炮的捉						
					}
					//if(TRUECap->last_to[last_num][1][which] == n_last_op_from){   // 这个是跟着捉
					//	TRUECap->isTrueCap = true;						  
					//}
					// fen 3ak1b2/4a4/4b4/8R/6r2/p3P2p1/9/4B4/4A4/4KAB2 w - - 0 1 moves i6h6 h4i4 h6i6 i4h4 i6h6
					//if(TRUECap->last_ot_from[last_num][1][which] == n_last_cap_to){
					if(TRUECap->last_ot_from[last_num][1][which] == n_last_cap_to){
						if(TRUECap->last_to[last_num][1][which] == TRUECap->last_ot_to[last_num][1][which]){
							TRUECap->isTrueCap = true; 						
						}
					}
				}
			}
		}
	}	

	for(i = 0;  i < TRUECap->cap_num[0][which]; i++){		
		TRUECap->LastCapChess[i][1][which]	  = TRUECap->LastCapChess[i][0][which];
		TRUECap->last_ot_from[i][1][which]    = TRUECap->last_ot_from[i][0][which];
		TRUECap->last_ot_to[i][1][which]      = TRUECap->last_ot_to[i][0][which];
		TRUECap->last_to     [i][1][which]    = TRUECap->last_to     [i][0][which];
	}
	TRUECap->cap_num[1][which] = TRUECap->cap_num[0][which];  // 上次共有多少次捉的走步. 
	return TRUECap->isTrueCap;
}

