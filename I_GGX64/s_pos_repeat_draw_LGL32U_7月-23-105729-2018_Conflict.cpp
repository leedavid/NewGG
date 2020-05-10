
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
#include "search.h"
using std::string;
//using Search::Signals;

#define IsChess(x)  ((x) > 0 && (x) < 16)

// fen 3k5/1R7/3ara3/9/6n2/6B2/9/4C4/4AK3/c5B2 w - - 0 1 moves b8a8 a0b0 a8a9 d9d8 a9b9 b0a0 b9b8 d8d9
// Explicit template instantiations

// 一将一捉，repeat 测试
// 


REPEAT_INFO Position::is_repeat() {

	// Draw by repetition?	
	int i = 4, e = std::min(st->rule50, st->pliesFromNull);
	if (i <= e)
	{
		StateInfo* stp = st->previous->previous;

		do {
			stp = stp->previous->previous;
			if (stp->key == st->key){
				Position Tpos;
				memcpy(&Tpos, this, sizeof(Position));    // 复制当前的局面，以免有问题, 要用REP_COPY
				
				return Tpos.get_repeat_info(i, st->m);    // 最后一个走步				
			}
			i += 2;
		} while (i <= e);
	}

	return REPEAT_NO;
}

// by have same key
REPEAT_INFO Position::get_repeat_info(int i, Move last_move){

	TrupCap_t TRUECap[1];
	Square ofrom, oto;
	Square mfrom, mto;
	Move   me_m, other_m;
	bool alwaysCheckByHis;
	bool alwaysCapture;

	memset(TRUECap, 0, sizeof(TrupCap_t));

	int nOwnChecks = 1;
	int nOppChecks = 1;
	int nOwnCapture = 1;
	int nOppCapture = 1;
	int n;

	for (n = 0; n < i; n++){ // 从当前棋步开始反推，是不是有重复步？？

		alwaysCheckByHis = st->mischeck; // alwaysCheckByHis = (st - n)->mischeck; /// LLL

		if (alwaysCheckByHis == false){  // 如果不是将军
			if (1 & n){
				nOppChecks = 0;
			}
			else{
				nOwnChecks = 0;
			}
		}
		else{
			ASSERT(in_check());   // 正在被将军
		}

		alwaysCapture = false;
		if (alwaysCheckByHis == false && (nOppCapture + nOwnCapture) != 0){

			me_m = st->m;            // me_m = Move((st-n)->m);    
			other_m = st->previous->m;  // other_m    = Move((st-n-1)->m);  /// LLL

			if (n == i - 1){
				other_m = last_move;
				ASSERT(IsChess(b90[TO(other_m)]));
			}

			oto = TO(other_m);	      // 
			ofrom = FROM(other_m);

			mfrom = FROM(me_m);
			mto = TO(me_m);

			alwaysCapture = see_draw_by_last_move(mfrom, mto, ofrom, oto, side_to_move(), TRUECap, st->previous->mischeck);
		}

		if (alwaysCapture == false){
			if (1 & n){
				nOppCapture = 0;
			}
			else{
				nOwnCapture = 0;
			}
		}
		// look if we can jump out recycle
		if ((nOwnChecks + nOppChecks + nOwnCapture + nOppCapture) == 0){
			break;
		}

#ifdef REPEAT_BUG
		if (b90[TO(st->m)] == EMPTY || st->capture != EMPTY){
			return REPEAT_NO;
		}
#endif
		ASSERT(IsChess(b90[TO(st->m)]));

		move_undo_test(st->m, st->capture);       //repeat_unmake();
		st = st->previous;
	} //for(n = 0; n < i; n++){

	if (nOwnChecks && nOppChecks){		//双方长将	
		return REPEAT_TRUE;
	}
	else if (nOwnChecks){
		return REPEAT_BAN_OTHER_CHECK;
	}
	else if (nOppChecks){
		return REPEAT_BAN_ME_CHECK;
	}
	else if (nOwnCapture && nOppCapture){		//双方长捉
		return REPEAT_TRUE;
	}
	else if (nOwnCapture){
		return REPEAT_BAN_OTHER_CAP;
	}
	else if (nOppCapture){
		return REPEAT_BAN_ME_CAP;
	}
	else{
		return REPEAT_TRUE;            //完全相同??
	}
}

// by have same key
REPEAT_INFO Position::get_repeat_info_notCatChe(int i, Move last_move){

	TrupCap_t TRUECap[1];	
	Square ofrom,oto;
	Square mfrom,mto;
	Move   me_m,other_m;
	bool alwaysCheckByHis;
	bool alwaysCapture;	

	//StateInfo* prest = st;

	memset(TRUECap,0,sizeof(TrupCap_t));					

	int nOwnChecks  = 1;
	int nOppChecks  = 1;
	int nOwnCapture = 1;
	int nOppCapture = 1;
	int n;

	for(n = 0; n < i; n++){ // 从当前棋步开始反推，是不是有重复步？？

		alwaysCheckByHis = st->mischeck; // alwaysCheckByHis = (st - n)->mischeck; /// LLL

		if(alwaysCheckByHis == false){  // 如果不是将军
			if( 1 & n){
				nOppChecks = 0;
			}
			else{
				nOwnChecks = 0;
			}
		}
		else{
			ASSERT(in_check());   // 正在被将军
		}

		alwaysCapture = false;
		if(alwaysCheckByHis == false && (nOppCapture + nOwnCapture) != 0){  
		//if((nOppCapture + nOwnCapture) != 0){  
			//if((nOppCapture + nOwnCapture) != 0){  
			// 是将就不用判断是不是捉了。 

			me_m      = st->m;            // me_m = Move((st-n)->m);    
			other_m   = st->previous->m;  // other_m    = Move((st-n-1)->m);  /// LLL

			if(n == i - 1){
				other_m = last_move;
				//board_display("reeefasf!");
				ASSERT(IsChess(b90[TO(other_m)]));
			}

			oto   = TO(other_m);	      // 
			ofrom = FROM(other_m);
		
			mfrom = FROM(me_m);
			mto   = TO(me_m);
			//alwaysCapture = false;
			//board_display("is true cap");
			//如果走的棋子是KING，则不是捉
			// fen 4k4/4a4/b3b4/9/9/9/9/3A4B/1Cn2p3/3K5 b - - 0 1
			//但这个动将算捉，因为是让炮来捉
			//if(type_of(b90[mto]) == KING){
			//	alwaysCapture = false;
			//}									
			//else{
				// fen 2bak4/2Nra2R1/c1n1bc3/p1p1p4/6p2/2P6/P3P1P2/2C1B1C2/9/3AKAB2 r moves h8h9 e8f9 h9h8 f9e8
				// 如果上把是对方将军，则如果我方走的不是车，也不会是捉。。。	
			//if(st->previous->mischeck){          // if(n < i-1 && (st - n - 1)->mischeck){
			//	ASSERT((st->previous->m & 0xcccc)  != 0xcccc);
			//	alwaysCapture = see_draw_by_last_move(mfrom, mto,ofrom,oto,side_to_move(), TRUECap,true);	
			//}
			//else{
			//	alwaysCapture = see_draw_by_last_move(mfrom, mto,ofrom,oto,side_to_move(), TRUECap,false);	
			//}
			////}

			alwaysCapture = see_draw_by_last_move(mfrom, mto, ofrom, oto, side_to_move(), TRUECap, st->previous->mischeck);
		}

		if(alwaysCapture == false){
			if( 1 & n){
				nOppCapture = 0;
			}
			else{
				nOwnCapture = 0;
			}
		}
		// look if we can jump out recycle
		if((nOwnChecks + nOppChecks + nOwnCapture + nOppCapture) == 0){
			break;
		}

#ifdef REPEAT_BUG
		if(b90[TO(st->m)] == EMPTY || st->capture != EMPTY){
			return REPEAT_NO;
		}
#endif
		ASSERT(IsChess(b90[TO(st->m)]));

		move_undo_test(st->m,st->capture);       //repeat_unmake();
		st = st->previous;
	} //for(n = 0; n < i; n++){

#ifdef REPEAT_DEBUG
	if(nOwnChecks && nOppChecks){		//双方长将	
		return REPEAT_TRUE;
	}
	else if(nOwnChecks){
		return REPEAT_BAN_OTHER_CHECK;
	}
	else if(nOppChecks){
		return REPEAT_BAN_ME_CHECK;
	}
	else if(nOwnCapture && nOppCapture){		//双方长捉

		if(TRUECap->capture_chess[WHITE] != CHE && TRUECap->capture_chess[BLACK] != CHE){
			return REPEAT_TRUE;
		}
		if(side_to_move() == WHITE){
			if(TRUECap->capture_chess[BLACK] == CHE && TRUECap->capture_chess[WHITE] != CHE){					    
				return REPEAT_BAN_ME_CAP;
			}
			else if(TRUECap->capture_chess[WHITE] == CHE && TRUECap->capture_chess[BLACK] != CHE){
				return REPEAT_BAN_OTHER_CAP;
			}
		}
		else{
			if(TRUECap->capture_chess[BLACK] == CHE && TRUECap->capture_chess[WHITE] != CHE){
				return REPEAT_BAN_OTHER_CAP;
			}
			else if(TRUECap->capture_chess[WHITE] == CHE && TRUECap->capture_chess[BLACK] != CHE){
				return REPEAT_BAN_ME_CAP;
			}
		}
		return REPEAT_TRUE;
	}
	else if(nOwnCapture){	
		return REPEAT_BAN_OTHER_CAP;
	}
	else if(nOppCapture){
		return REPEAT_BAN_ME_CAP;
	}
	else{
		return REPEAT_TRUE;            //完全相同??
	}

#else


	if (nOwnChecks && nOppChecks){		//双方长将	
		return REPEAT_TRUE;
	}
	else if (nOwnChecks){
		return REPEAT_BAN_OTHER_CHECK;
	}
	else if (nOppChecks){
		return REPEAT_BAN_ME_CHECK;
	}
	else if (nOwnCapture && nOppCapture){		//双方长捉

		if (TRUECap->capture_chess[WHITE] != CHE && TRUECap->capture_chess[BLACK] != CHE){
			return REPEAT_TRUE;
		}
		if (side_to_move() == WHITE){
			if (TRUECap->capture_chess[BLACK] == CHE && TRUECap->capture_chess[WHITE] != CHE){
				return REPEAT_BAN_ME_CAP;
			}
			else if (TRUECap->capture_chess[WHITE] == CHE && TRUECap->capture_chess[BLACK] != CHE){
				return REPEAT_BAN_OTHER_CAP;
			}
		}
		else{
			if (TRUECap->capture_chess[BLACK] == CHE && TRUECap->capture_chess[WHITE] != CHE){
				return REPEAT_BAN_OTHER_CAP;
			}
			else if (TRUECap->capture_chess[WHITE] == CHE && TRUECap->capture_chess[BLACK] != CHE){
				return REPEAT_BAN_ME_CAP;
			}
		}
		return REPEAT_TRUE;
	}
	else if (nOwnCapture){
		return REPEAT_BAN_OTHER_CAP;
	}
	else if (nOppCapture){
		return REPEAT_BAN_ME_CAP;
	}
	else{
		return REPEAT_TRUE;            //完全相同??
	}

#endif

}


