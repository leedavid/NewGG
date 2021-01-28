#include "chess.h"
 
#ifdef USE_STOCK_FISH_FILE
#else

bool board_is_ok(const typePOS *POSITION){	
#ifdef USE_SLOW_BOARD 
	typePOS tmp[1];
	//tipo_POSITION->DYN premydin[1];
	typeDYNAMIC mydin[3];
	char fen[256];
	int i;
	board_to_fen(POSITION,fen);
	memcpy(tmp,POSITION,sizeof(typePOS));  //);
	//i = sizeof(TP_size); // 800
	//i = sizeof(typePOS); // 17808
	tmp->DYN_ROOT = mydin+1;
	memcpy(tmp->DYN_ROOT,POSITION->DYN-1,2*sizeof(typeDYNAMIC));
	tmp->DYN = tmp->DYN_ROOT + 1;

	board_from_fen(tmp,fen,FALSE);	
	// piececount
	for(i = 0; i < 16; i++){
		if(tmp->pieceCount[i] != POSITION->pieceCount[i]){
			printf("board_is_ok(), pieceCount[%d] error!\n",i);
			goto board_is_ok_ERR;
		}
	}
	// byChessBB
	for(i = 0; i < 16; i++){
		if(!m128_is_same(tmp->byChessBB[i],POSITION->byChessBB[i])){
			printf("board_is_ok(), byChessBB[%d] error!\n",i);
			goto board_is_ok_ERR;
		}
	}
	// byBlackWhite
	if(!m128_is_same(tmp->byWhiteBlack,POSITION->byWhiteBlack)){
		printf("board_is_ok(), byWhiteBlackerror!\n");
		goto board_is_ok_ERR;
	}
	// val
	//if(tmp->DIN->valu != POSITION->DIN->valu){
	//	printf("board_is_ok(), DIN->valu!\n");
	//	goto board_is_ok_ERR;
	//}
	// val_positional
	//if(tmp->DIN->valu_posizionale != POSITION->DIN->valu_posizionale){
	//	printf("board_is_ok(), DIN->valu_posizionale!\n");
	//	goto board_is_ok_ERR;
	//}
	// pMat
	if(tmp->pMat != POSITION->pMat){
		printf("board_is_ok(), pMat!\n");
		goto board_is_ok_ERR;
	}
	// key
	if(tmp->DYN->HASH != POSITION->DYN->HASH){
		printf("board_is_ok(), Zobrist!\n");
		goto board_is_ok_ERR;
	}
	return TRUE;
board_is_ok_ERR: 
	//board_display(POSITION,"board_ok error!\n");
	return FALSE;
#else	
	return TRUE;
#endif
}

void board_display(const typePOS *POSITION, char * szReason){

	char buf[512];
	char pv[6*256];
	FILE* out = stdout;
	int r,f;
	int chess;
    typeDYNAMIC *p;
	char* q;

	const static char *c_BoardStrSim[19] = {
		"cmd: 9┌--┬--┬--┬--┬--┬--┬--┬--┐ \n",
		"cmd:  │  │  │  │＼│／│  │  │  │ \n",
		"cmd: 8├--┼--┼--┼--※--┼--┼--┼--┤ \n",
		"cmd:  │  │  │  │／│＼│  │  │  │ \n",
		"cmd: 7├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
		"cmd:  │  │  │  │  │  │  │  │  │ \n",
		"cmd: 6├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
		"cmd:  │  │  │  │  │  │  │  │  │ \n",
		"cmd: 5├--┴--┴--┴--┴--┴--┴--┴--┤ \n",
		"cmd:  │                              │ \n",
		"cmd: 4├--┬--┬--┬--┬--┬--┬--┬--┤ \n",
		"cmd:  │  │  │  │  │  │  │  │  │ \n",
		"cmd: 3├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
		"cmd:  │  │  │  │  │  │  │  │  │ \n",
		"cmd: 2├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
		"cmd:  │  │  │  │＼│／│  │  │  │ \n",
		"cmd: 1├--┼--┼--┼--※--┼--┼--┼--┤ \n",
		"cmd:  │  │  │  │／│＼│  │  │  │ \n",
		"cmd: 0└--┴--┴--┴--┴--┴--┴--┴--┘ \n"
		"cmd:  a   b   c   d   e   f   g   h   i\n"
	};

	const static char chessStr[17][4] = {
		"错",
		"帥","仕","相","馬","車","炮","兵",
		"错",
		"將","士","象","马","车","包","卒",
		"错"
	};

   fprintf(out,"cmd: ");
   fprintf(out, szReason);   //

   //to_fen(buf);
   board_to_fen(POSITION,buf);

   fprintf(out, "\ncmd: fen %s\n",buf);

   for(r = 0; r < 19; r++){
        sprintf_s(buf,256, c_BoardStrSim[r]);
        if(r%2 == 0){
            for(f = 0; f < 9; f++){
                chess = PB90(XYtoS(f, r/2));
                if(chess != EMPTY){
                    buf[f*4+1+5] = chessStr[chess][0];
                    buf[f*4+2+5] = chessStr[chess][1];
                }
            }
        }
        fprintf(out,buf);
   }

   //
   if(POS_SIDE){
	   fprintf(out,"cmd: 当前是红方走棋\n");
   }
   else{
	   fprintf(out,"cmd: 当前是黑方走棋\n");
   }
   q = pv;
   *q = 0;
   r = 0;
   // print pv
   for(p = POSITION->DYN_ROOT + 1; p->HASH != 0; p++){
	   //if(p->move == 0xcdcd) break;
	   if(p>POSITION->DYN) break;
	   Notate(p->move, STRING1);
	   strcpy_s (q,64, STRING1);
	   q += strlen (STRING1);
	   strcpy_s (q,64, " ");
	   q++;
	   if(r++ > 128) break;
   }
   *q = 0;
   fprintf(out,"pv= %s\n",pv);

   // 分数


   //Record* re = &board->His[board->gamePly];

   //fprintf(out, "cmd: hk: %.16I64X\n",re->key);



   //fprintf(out, "cmd: cV: %d op: %d ep: %d\n", re->ischeck, board->Opening, board->Endgame);

   //board_to_fen(board,buf);

   //fprintf(out,"cmd: fen %s\n",buf);

   //pov val 

   //fprintf(out, "  posVal: %d\n",  re->posOpening);

   //Mat
   //fprintf(out, "m:    %d\n"
   //             "c:    %d\n"
			//	"s:    %d\n"
   //             "d:    %d\n"
			//	"r:    %d\n"
			//	"b:    %d\n",
   //    board->pMat->material, 
   //    board->pMat->sixiangInfo8,
	  // board->pMat->searchInfo8,
	  // board->pMat->mat_dummy,
	  // board->pMat->Rphase,
	  // board->pMat->Bphase
   //    );

   //输出当前的评估值
   //fprintf(out,"eval %d\n", evaluate(board,NULL,0));

   //打印当前所有的历史走步,nocap,是不是将军,posVal, move2str
   //for(int i = 1; i <= board->gply; i++){
	  // fprintf(out,"cmd: No.%2d,Move:%s, n: %d, c: %d, o: %d, e: %d  \n",
		 //  i,move2str(board->His[i].move,buf),board->His[i].nonCap,board->His[i].ischeck,board->Opening,board->Endgame);
   //}
   fflush(out);
}
const static uint8 r2b_chess[16] = {
	0,  //这个不用了
	BKING,BSHI,BXIANG,BMA,BCHE,BPAO,BPAWN,
	8,		
	RKING,RSHI,RXIANG,RMA,RCHE,RPAO,RPAWN,
};
// 棋局黑红交换
void board_red2black			(typePOS * tNow, typePOS * tOld){
	int i;
	char fen[256];
	for(i = 0; i < 90; i++){
		tNow->b90[89-i] = r2b_chess[tOld->b90[i]];
	}

	tNow->sideToMove = tOld->sideToMove ^ 0x1;

	board_to_fen(tNow,fen);
	board_from_fen(tNow,fen,FALSE);
}
// 棋局左右交换
void board_mirror 				(typePOS * tNow, const typePOS * tOld){
    int i;
	char fen[256];
	for(i = 0; i < 90; i++){
		tNow->b90[Mirror(i)] = tOld->b90[i];
	}
	tNow->sideToMove = tOld->sideToMove;
	board_to_fen(tNow,fen);
	board_from_fen(tNow,fen,FALSE);
}

#endif
