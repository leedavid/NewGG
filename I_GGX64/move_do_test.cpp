#include "chess.h" 
#include "preGen.h"

#ifdef USE_STOCK_FISH_FILE
#else

void move_do_test_white(const typePOS *POSITION, int m, int* cattura){
	int di  = FROM(m);
	int ai    = TO(m);
	int pezzo = PB90(di);
	*cattura  = PB90(ai);

	POS_SIDE = PIECE_SIDE(pezzo);

	//
	ASSERT(pezzo != EMPTY);
	//
	PB90(di) = 0;                    // from
	// bitboard from
	clear_bit(bitboard_occ_white,di);           // di == from
	set_bit  (bitboard_occ_white,ai);           // ai == to

	clear_bit(POSITION->byChessBB[pezzo],di);  // di == from
	set_bit  (POSITION->byChessBB[pezzo],ai);  // ai == to

	clear_bit(POSITION->byWhiteBlack,di);      // di == from


	if(*cattura != EMPTY){
		clear_bit(POSITION->byChessBB[*cattura],ai);      // 被吃的棋子的位棋盘清除
		clear_bit(bitboard_occ_black,ai);                 // 对方颜色的位棋盘

		// piece count
		POSITION->pieceCount[*cattura] --;

		// piecelist
		POSITION->pieceList[*cattura][POSITION->index[ai]] 
		= POSITION->pieceList[*cattura][POSITION->pieceCount[*cattura]];

		// index
		POSITION->index[POSITION->pieceList[*cattura][POSITION->index[ai]]] 
		= POSITION->index[ai];
	}
	else{
		set_bit(POSITION->byWhiteBlack,ai);        // ai == to
	}

	PB90(ai) = pezzo;  // to
	
	//pieceList
	POSITION->pieceList[pezzo][POSITION->index[di]] = ai;

	//index
	POSITION->index[ai] = POSITION->index[di];

	POS_SIDE ^= 0x1;
}

void move_do_test_black(const typePOS *POSITION, int m, int* cattura){
	int di  = FROM(m);
	int ai    = TO(m);
	int pezzo = PB90(di);
	*cattura  = PB90(ai);

	POS_SIDE = PIECE_SIDE(pezzo);

	//
	ASSERT(pezzo != EMPTY);
	if(pezzo == EMPTY){
		pezzo = pezzo;
	}
	//
	PB90(di) = 0;                    // from
	// bitboard from
	clear_bit(bitboard_occ_black,di);           // di == from
	set_bit  (bitboard_occ_black,ai);           // ai == to

	clear_bit(POSITION->byChessBB[pezzo],di);  // di == from
	set_bit  (POSITION->byChessBB[pezzo],ai);  // ai == to

	clear_bit(POSITION->byWhiteBlack,di);      // di == from


	if(*cattura != EMPTY){
		clear_bit(POSITION->byChessBB[*cattura],ai);      // 被吃的棋子的位棋盘清除
		clear_bit(bitboard_occ_white,ai);                  // 对方颜色的位棋盘

		// piece count
		POSITION->pieceCount[*cattura] --;

		// piecelist
		POSITION->pieceList[*cattura][POSITION->index[ai]] 
		= POSITION->pieceList[*cattura][POSITION->pieceCount[*cattura]];

		// index
		POSITION->index[POSITION->pieceList[*cattura][POSITION->index[ai]]] 
		= POSITION->index[ai];
	}
	else{
		set_bit(POSITION->byWhiteBlack,ai);        // ai == to
	}

	PB90(ai) = pezzo;  // to
	
	//pieceList
	POSITION->pieceList[pezzo][POSITION->index[di]] = ai;

	//index
	POSITION->index[ai] = POSITION->index[di];

	POS_SIDE ^= 0x1;
}



void move_do_test(const typePOS *POSITION, int m, int* cattura){
	
	uint8 pezzo = PB90(FROM(m));
	//if(m == 0){
	//	board_display(POSITION,"move_do = 0\n");
	//}
	if(PIECE_SIDE(pezzo) == WHITE_TO_MOVE){
		move_do_test_white(POSITION,m,cattura);
	}
	else{
		move_do_test_black(POSITION,m,cattura);
	}
}

#endif