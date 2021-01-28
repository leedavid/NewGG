#include "chess.h" 
#include "preGen.h"

#ifdef USE_STOCK_FISH_FILE
#else

void repeat_make_white(const typePOS *POSITION){
#ifdef USE_STACK_MOVE
	uint32    m  = POSITION->STACKst[++POSITION->StackHeight].move;
#else
	uint32    m  = (++POSITION->DYN)->move;
#endif	   
		int di       = FROM(m);
		int ai       = TO(m);
		int pezzo    = PB90(di);
		int cattura  = PB90(ai);

		POS_SIDE = PIECE_SIDE(pezzo);

		//
		ASSERT(pezzo != EMPTY);
#ifdef DEBUG_REPEAT
		if(pezzo == EMPTY){
             pezzo = pezzo;
		}
#endif
		//
		PB90(di) = 0;                    // from
		// bitboard from
		clear_bit(bitboard_occ_white,di);           // di == from
		set_bit  (bitboard_occ_white,ai);           // ai == to

		clear_bit(POSITION->byChessBB[pezzo],di);  // di == from
		set_bit  (POSITION->byChessBB[pezzo],ai);  // ai == to

		clear_bit(POSITION->byWhiteBlack,di);      // di == from


		if(cattura != EMPTY){
			clear_bit(POSITION->byChessBB[cattura],ai);      // 被吃的棋子的位棋盘清除
			clear_bit(bitboard_occ_black,ai);                 // 对方颜色的位棋盘

			// piece count
			POSITION->pieceCount[cattura] --;

			// piecelist
			POSITION->pieceList[cattura][POSITION->index[ai]] 
			= POSITION->pieceList[cattura][POSITION->pieceCount[cattura]];

			// index
			POSITION->index[POSITION->pieceList[cattura][POSITION->index[ai]]] 
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

		//POSITION->StackHeight ++;
}
void repeat_make_black(const typePOS *POSITION){

#ifdef USE_STACK_MOVE
	uint32    m  = POSITION->STACKst[++POSITION->StackHeight].move;
#else
	uint32    m  = (++POSITION->DYN)->move;
#endif	

	int di       = FROM(m);
	int ai       = TO(m);
	int pezzo    = PB90(di);
	int cattura  = PB90(ai);

	POS_SIDE = PIECE_SIDE(pezzo);

	//
	ASSERT(pezzo != EMPTY);
#ifdef DEBUG_REPEAT
	if(pezzo == EMPTY){
		board_display(POSITION,"repeat_make_black\n");
		pezzo = pezzo;
	}
#endif
	//
	PB90(di) = 0;                    // from
	// bitboard from
	clear_bit(bitboard_occ_black,di);           // di == from
	set_bit  (bitboard_occ_black,ai);           // ai == to

	clear_bit(POSITION->byChessBB[pezzo],di);  // di == from
	set_bit  (POSITION->byChessBB[pezzo],ai);  // ai == to

	clear_bit(POSITION->byWhiteBlack,di);      // di == from


	if(cattura != EMPTY){
		clear_bit(POSITION->byChessBB[cattura],ai);      // 被吃的棋子的位棋盘清除
		clear_bit(bitboard_occ_white,ai);                  // 对方颜色的位棋盘

		// piece count
		POSITION->pieceCount[cattura] --;

		// piecelist
		POSITION->pieceList[cattura][POSITION->index[ai]] 
		= POSITION->pieceList[cattura][POSITION->pieceCount[cattura]];

		// index
		POSITION->index[POSITION->pieceList[cattura][POSITION->index[ai]]] 
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
void repeat_unmake_white(const typePOS *POSITION){

	int di;
	int ai;
	int pezzo;
	int cattura;
#ifdef USE_STACK_MOVE
	uint32 m = POSITION->STACKst[POSITION->StackHeight].move;
#else
	uint32 m = POSITION->DYN->move;
#endif
	di   = FROM (m);
	ai   = TO (m);
	pezzo = PB90(ai);
#ifdef USE_STACK_MOVE
	cattura = POSITION->STACKst[POSITION->StackHeight].capturer;
#else
	cattura = POSITION->DYN->cattura;
#endif

	PB90(di) = pezzo;
	PB90(ai) = cattura;

	// bitboard
	set_bit  (bitboard_occ_white,di);           // di == from
	clear_bit(bitboard_occ_white,ai);           // ai == to

	set_bit  (POSITION->byChessBB[pezzo],di);
	clear_bit(POSITION->byChessBB[pezzo],ai);

	set_bit(POSITION->byWhiteBlack,di);        // di == from

	//piece list
	POSITION->pieceList[pezzo][POSITION->index[ai]] = di;
	POSITION->index[di] = POSITION->index[ai];

	//cattura = POSITION->DYN->cattura;
	if (cattura)  // 吃的子
	{
		// bitboard
		set_bit(bitboard_occ_black,ai);
		set_bit(POSITION->byChessBB[cattura],ai);

		//update piece list
		POSITION->pieceList[cattura][POSITION->pieceCount[cattura]] = ai;
		POSITION->index[ai] = POSITION->pieceCount[cattura];

		POSITION->pieceCount[cattura] ++;

		//POSITION->pMat += MatAddress[cattura];
	}
	else{
		clear_bit(POSITION->byWhiteBlack,ai);        // ai == to
	}

	POS_SIDE ^= 0x1;

#ifdef USE_STACK_MOVE
	POSITION->StackHeight --;
#else
	POSITION->DYN --;
#endif	
}
void repeat_unmake_black(const typePOS *POSITION){
	int di;
	int ai;
	int pezzo;
	int cattura;

#ifdef USE_STACK_MOVE
	uint32 m = POSITION->STACKst[POSITION->StackHeight].move;
#else
	uint32 m = POSITION->DYN->move;
#endif
	di   = FROM (m);
	ai   = TO (m);
	pezzo = PB90(ai);
#ifdef USE_STACK_MOVE
	cattura = POSITION->STACKst[POSITION->StackHeight].capturer;
#else
	cattura = POSITION->DYN->cattura;
#endif

	PB90(di) = pezzo;
	PB90(ai) = cattura;

	// bitboard
	set_bit  (bitboard_occ_black,di);           // di == from
	clear_bit(bitboard_occ_black,ai);           // ai == to

	set_bit  (POSITION->byChessBB[pezzo],di);
	clear_bit(POSITION->byChessBB[pezzo],ai);

	set_bit(POSITION->byWhiteBlack,di);        // di == from

	//piece list
	POSITION->pieceList[pezzo][POSITION->index[ai]] = di;
	POSITION->index[di] = POSITION->index[ai];

	//cattura = POSITION->DYN->cattura;
	if (cattura)  // 吃的子
	{
		// bitboard
		set_bit(bitboard_occ_white,ai);
		set_bit(POSITION->byChessBB[cattura],ai);

		//update piece list
		POSITION->pieceList[cattura][POSITION->pieceCount[cattura]] = ai;
		POSITION->index[ai] = POSITION->pieceCount[cattura];

		POSITION->pieceCount[cattura] ++;

		//POSITION->pMat += MatAddress[cattura];
	}
	else{
		clear_bit(POSITION->byWhiteBlack,ai);        // ai == to
	}

	POS_SIDE ^= 0x1;

#ifdef USE_STACK_MOVE
	POSITION->StackHeight --;
#else
	POSITION->DYN --;
#endif	
}
//===============================================================
void repeat_make(const typePOS *POSITION){
	if(POS_SIDE == WHITE_TO_MOVE){
		repeat_make_white(POSITION);
	}
	else{
		repeat_make_black(POSITION);
	}
}
void repeat_unmake(const typePOS *POSITION){
	if(POS_SIDE == WHITE_TO_MOVE){
		repeat_unmake_black(POSITION);
	}
	else{
		repeat_unmake_white(POSITION);
	}
}


#endif