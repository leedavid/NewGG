#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"
 


char* board_to_fen(const typePOS *POSITION, char *fen){

    int rank;
	int file;
	int sq90;
	int piece;
	int c;
	int pc = 0;	
	for(rank = 0; rank <= 9; rank ++){
		for(file = 0; file <= 8;){
			sq90 = XYtoS(file, rank);
			piece = PB90(sq90);
		  
			ASSERT(piece <= 16);

			//if(piece >= 16){
			//	int test = 0;
			//}


			if(piece == EMPTY){
				int len = 0;
				for(; file <= 8 && PB90(XYtoS(file,rank)) == EMPTY; file++){
					len ++;
				}

				ASSERT(len>=1&&len<=9);

				c = '0' + len;
			}
			else{
				c = piece_to_char(piece);
				file++;
			}
			fen[pc++] = (sint8)c;
		}
		fen[pc++] = '/';
	}

	fen[pc-1] = ' '; // HACK: remove the last '/'

	fen[pc++] = (POS_SIDE) ? 'w' : 'b';

	/*sprintf_s(fen+pc, 250, " - - %d %d", board->gamePly, board->His[board->gamePly].nonCap); */
	//sprintf_s(fen+pc, 250, " - - %d %d", 0, 0); 

	fen[pc++] = ' ';
	fen[pc++] = '-';
	fen[pc++] = ' ';
	fen[pc++] = '-';
	fen[pc++] = ' ';
	fen[pc++] = '0';
	fen[pc++] = ' ';
	fen[pc++] = '0';

	fen[pc++] = 0;
	//pc = 0;

	return fen;
}

void board_from_fen(const typePOS *POSITION, char *fen, bool iseval){
	ReadFEN(POSITION,fen);
	InitBitboards  (POSITION,iseval);  // 初始化一下位棋盘
}

#endif