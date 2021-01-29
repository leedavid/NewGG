#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"

//#define ripetizione_verificare \
// CHECK_HALT(); \
// if (POSITION->DYN->mossa50 >= 128) RETURN(0); \
// for (i = 4; i <= POSITION->DYN->mossa50 && i <= mucchio_altezzo; i += 2) \
//   if (MUCCHIO[mucchio_altezzo - i] == POSITION->DYN->Zobrist) RETURN(0);
//

int is_repeat(const typePOS *POSITION){
	int i;
	int n;
	int from,to;
	int mfrom,mto;
	int other_m,me_m;
	
	bool alwaysCheckByHis;
	bool alwaysCapture;

#ifdef DEBUG_REPEAT	
	int old_wtm   = POS_SIDE;
	int old_hight = POSITION->StackHeight;
#endif

#ifdef USE_STACK_MOVE
	_STACKst* re;
#else
	typeDYNAMIC * re;
#endif	
	TrupCap_t TRUECap[1];	

#ifdef GG_TEST_MODE   // 佳佳测试模式这个不能用.
	//if(POSITION->DYN->mossa50 >= 168){
	//	//if(board_is_incheck(POSITION,POS_SIDE)){
	//	//	return REPEAT_NO;
	//	//}
	//	//else{
	//	//   return REPEAT_TRUE;
	//	//}
	//	return REPEAT_NO;
	//}
#else
	if(POSITION->DYN->mossa50 >= REPEAT_DRAW_STEP) return REPEAT_TRUE;
#endif

#ifdef USE_STACK_MOVE
	re = &POSITION->STACKst[POSITION->StackHeight];
	for(i = 4; i <= POSITION->DYN->mossa50 && i <= POSITION->StackHeight; i += 2){	
		if ((re-i)->HASH == POSITION->DYN->HASH){
#else
	re = POSITION->DYN;
	for(i = 4; i <= POSITION->DYN->mossa50 && i <= POSITION->StackHeight; i += 2){
		if (POSITION->STACK[POSITION->StackHeight - i] == POSITION->DYN->HASH){
			
#endif
			//if(POSITION->DYN->mossa == 0){
			//	//board_display(POSITION,"mossa == 0, cannot undo!");
			//	return REPEAT_TRUE;
			//} //fen 
			// fen 1C2ka3/4a4/b3bc3/p5p2/8p/4Cn3/P3P1P1P/3R4N/4A4/2r1KA3 w - - 0 0 moves e1d0 c0c3 d0e1 c3c0 e1d0 c0c3 d0e1 c3c0

			// fen 1nbaka3/5r3/3Pb4/p1p1p3p/3c5/P1PN5/R5p2/2N1C1n2/4A4/2B1KAB2 b - - 0 moves d5e5 e0d0 e5d5 d0e0 d5e5
#ifdef DEBUG_REPEAT			
            //board_display(POSITION,"repeat");
			//if((re->move & 0xffff) == 0xd5e5){
			//	board_display(POSITION,"repeat");
			//	re = re; // fen 4kaRC1/4a4/9/7r1/9/9/9/4B4/4A4/4KAB2 w
			//}
#endif

			memset(TRUECap,0,sizeof(TrupCap_t));

			int nOwnChecks  = 1;
			int nOppChecks  = 1;
			int nOwnCapture = 1;
			int nOppCapture = 1;

			for(n = 0; n < i; n++){
				// 首先看一下是不是有 move = 0
				/*if((re-n)->move == 0 || PB90(TO((re-n)->move)] == 0){*/
#ifdef DEBUG_REPEAT
				if((re-n)->move == 0 ){
					board_display(POSITION,"repeat move == 0\n");
					while(--n >= 0){
						repeat_make(POSITION);
					}
					if(old_wtm != POS_SIDE || old_hight != POSITION->StackHeight){
						board_display(POSITION,"wtm is not same!!!");
						old_wtm = old_wtm;
					};
					return REPEAT_NO;
				}
#endif
				//bool alwaysCheck;
				//alwaysCheckByHis = POSITION->STACKst[POSITION->StackHeight].checkk;
				alwaysCheckByHis = board_is_incheck(POSITION,POS_SIDE);

				if(alwaysCheckByHis == FALSE){
					if( 1 & n){
						nOppChecks = 0;
					}
					else{
						nOwnChecks = 0;
					}
				}
				alwaysCapture  = FALSE;	
				//board_display(POSITION,"repeat?");
				if(alwaysCheckByHis == FALSE && (nOppCapture + nOwnCapture) != 0){  // 是将就不用判断是不是捉了。 				

					other_m = (re-n)->move;
					me_m    = (re-n-1)->move;

					if(n == i - 1){
						to   = FROM((re-n+1)->move);
						from = TO((re-n+1)->move);
					}
					else{
						to   = TO(me_m);	
						from = FROM(me_m);
					}
					mfrom = FROM(other_m);
					mto   = TO(other_m);

#ifdef DEBUG_REPEAT
					if(PB90(mto) == 0){
						board_display(POSITION,"undo_piece = 0\n");
						mto = mto;
					}
#endif
					
					alwaysCapture = see_draw_by_last_move(POSITION,mfrom, mto,from,to,POS_SIDE, TRUECap);									
				}

				if(alwaysCapture == FALSE){
					if( 1 & n){
						nOppCapture = 0;
					}
					else{
						nOwnCapture = 0;
					}
				}
				//move_undo_test(POSITION,(re-n)->move,(re-n)->capture);  //undo_move
				repeat_unmake(POSITION);

				// look if we can jump out recycle
				if((nOwnChecks + nOppChecks + nOwnCapture + nOppCapture) == 0){
					n++;
					break;
				}
			}
			//还原原来的棋盘.
			while(--n >= 0){
				repeat_make(POSITION);
			}

			
#ifdef DEBUG_REPEAT
			ASSERT(board_is_ok(POSITION));
			if(old_wtm != POS_SIDE || old_hight != POSITION->StackHeight){
				board_display(POSITION,"wtm is not same!!!");
				old_wtm = old_wtm;
			}
#endif

			if(nOwnChecks && nOppChecks){		// 双方长将
				return REPEAT_TRUE;
			}
			else if(nOwnChecks){
				return REPEAT_BAN_OTHER;
			}
			else if(nOppChecks){
				return REPEAT_BAN_ME;
			}
			if(nOwnCapture && nOppCapture){		// 双方长捉
				return REPEAT_TRUE;
			}
			else if(nOwnCapture){	
			    return REPEAT_BAN_OTHER;
			}
			else if(nOppCapture){
				return REPEAT_BAN_ME;
			}
			else{
				return REPEAT_TRUE;            // 完全相同??
			}
		}
	}
	return REPEAT_NO;
}

#endif