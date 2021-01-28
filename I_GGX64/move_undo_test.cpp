#include "chess.h"
 
#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"


void move_undo_test_white(const typePOS *POSITION, int m, int cattura){
	int di;
	int ai;
	int pezzo;
	//int cattura;
	//int z;
	//Bitboard cel;
	di   = FROM (m);
	ai   = TO (m);
	pezzo = PB90(ai);
	//POS_SIDE ^= 1;
	//POSITION->height--;

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

	//POSITION->DYN--;
	//mucchio_altezzo--;

	//ASSERT(board_is_ok(POSITION));
}
void move_undo_test_black(const typePOS *POSITION, int m, int cattura){
	int di;
	int ai;
	int pezzo;
	//int cattura;
	//int z;
	//Bitboard cel;
	di   = FROM (m);
	ai   = TO (m);
	pezzo = PB90(ai);
	//POS_SIDE ^= 1;
	//POSITION->height--;

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

	//POSITION->DYN--;
	//mucchio_altezzo--;

	//ASSERT(board_is_ok(POSITION));
}



void move_undo_test(const typePOS *POSITION, int m, int cattura){

	uint8 pezzo = PB90(TO(m));
	//if(m == 0){
	//	board_display(POSITION,"move_undo = 0\n");
	//}
	if(PIECE_SIDE(pezzo) == WHITE_TO_MOVE){
		move_undo_test_white(POSITION,m,cattura);
	}
	else{
		move_undo_test_black(POSITION,m,cattura);
	}
}

#endif