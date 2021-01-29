#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"
#include "mfa.h"
#include "valore.h"


void MakeWhite (const typePOS *POSITION, uint32 mossa)
{
	int di;
	int ai;
	int pezzo;
	int cattura;

	ASSERT(board_is_ok(POSITION));

	POSITION->nodes++;
	if (POSITION->cpu == 0)  // 核心的次序
	{
		NODE_CHECK++;
		if ((NODE_CHECK & 4095) == 0){
			CheckDone (POSITION, 0);   // resolve_term
		}
	}
	memcpy (POSITION->DYN + 1, POSITION->DYN, sizeof(DYN_size32)); // 32
	di = FROM (mossa);   // from
	ai = TO (mossa);   // to
	pezzo = PB90(di);

	ASSERT(PIECE_SIDE(PB90(di)) != PIECE_SIDE(PB90(ai)));

	POSITION->DYN++;
	POSITION->DYN->mossa50++;
	POSITION->DYN->move = mossa; // 保存本次的 Move

	PB90(di) = 0;                    // from

	POSITION->DYN->statico += statico_valu[pezzo][ai] - statico_valu[pezzo][di]; // 位置分
	//cel = ZOBRIST[pezzo][di] ^ ZOBRIST[pezzo][ai];                        // hash_key
	cattura = PB90(ai);                // capture
	POSITION->DYN->catturaa = cattura;                 // capture

	POS_SIDE ^= 1;                // side_to_move
	POSITION->height++;
	POSITION->DYN->HASH ^= ZOBRIST_side;    // side_to_move_hash
	
	// bitboard
	clear_bit(bitboard_occ_white,di);           // di == from
	set_bit  (bitboard_occ_white,ai);           // ai == to

	clear_bit(POSITION->byChessBB[pezzo],di);  // di == from
	set_bit  (POSITION->byChessBB[pezzo],ai);  // ai == to

	clear_bit(POSITION->byWhiteBlack,di);      // di == from

	if (cattura)  // capture                            
	{
#ifdef  USE_ASSERT_COMMON
		if(cattura == BKING || cattura == RKING ){
			board_display(POSITION,"caputer a king !!");
		}
#endif
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

		// pMat
		POSITION->pMat -= MatAddress[cattura];

		POSITION->DYN->statico -= statico_valu[cattura][ai];     // position value
		POSITION->DYN->HASH ^= ZOBRIST[cattura][ai];
		POSITION->DYN->mossa50 = 0; // repeat 
	}
	else
	{
		set_bit(POSITION->byWhiteBlack,ai);        // ai == to
	}
	PB90(ai) = pezzo;  // to
	
	//pieceList
	POSITION->pieceList[pezzo][POSITION->index[di]] = ai;

	//index
	POSITION->index[ai] = POSITION->index[di];

	// key
	POSITION->DYN->HASH ^= ZOBRIST[pezzo][ai] ^ ZOBRIST[pezzo][di];
#ifdef USE_STACK_MOVE
	POSITION->StackHeight++;
	POSITION->STACKst[POSITION->StackHeight].move     = mossa;
	POSITION->STACKst[POSITION->StackHeight].capturer = cattura;
	POSITION->STACKst[POSITION->StackHeight].HASH     = POSITION->DYN->HASH;
#else
	POSITION->STACK[++(POSITION->StackHeight)] = POSITION->DYN->HASH;
#endif


	ASSERT(board_is_ok(POSITION));
}

//const static uint8 promozione_nero[8] =
//{ 0, 0, 0, 0,
//conto_cavallo_nero, conto_chiaro_nero, conto_torre_nero, conto_donna_nera };

void // do_black
	MakeBlack (const typePOS *POSITION, uint32 mossa)
{
	int di;
	int ai;
	int pezzo;
	int cattura;
	POSITION->nodes++;

	memcpy (POSITION->DYN + 1, POSITION->DYN, sizeof(DYN_size32)); // 32
	di = FROM (mossa);   // from
	ai = TO (mossa);   // to
	pezzo = PB90(di);

	ASSERT(PIECE_SIDE(PB90(di)) != PIECE_SIDE(PB90(ai)));

	POSITION->DYN++;
	POSITION->DYN->mossa50++;
	POSITION->DYN->move = mossa; // 保存本次的 Move

	PB90(di) = 0;                    // from
	//cel = quadretto_libero[di];              // clear_mask
	//bitbordo_occupato_bianco &= cel;         // white_occ 
	//POSITION->bitbordo[pezzo] &= cel;       // bitboard_chess
	//occupato_libero (cel, di);                 // bitboard

	POSITION->DYN->statico += statico_valu[pezzo][ai] - statico_valu[pezzo][di]; // 位置分
	//cel = ZOBRIST[pezzo][di] ^ ZOBRIST[pezzo][ai]; // hash_key
	cattura = PB90(ai);                // capture
	POSITION->DYN->catturaa = cattura;                 // capture
	//POSITION->DYN->Zobrist ^= cel;
	//if (pezzo == conto_pedone_bianco)           // if move piece is pawn
	//	POSITION->DYN->ZobristPedone ^= cel;
	POS_SIDE ^= 1;                // side_to_move
	POSITION->height++;
	POSITION->DYN->HASH ^= ZOBRIST_side;    // side_to_move_hash

	// bitboard
	clear_bit(bitboard_occ_black,di);           // di == from
	set_bit  (bitboard_occ_black,ai);           // ai == to

	clear_bit(POSITION->byChessBB[pezzo],di);  // di == from
	set_bit  (POSITION->byChessBB[pezzo],ai);  // ai == to

	clear_bit(POSITION->byWhiteBlack,di);      // di == from

	if (cattura)  // capture                            
	{
#ifdef  USE_ASSERT_COMMON
		if(cattura == BKING || cattura == RKING ){
			board_display(POSITION,"caputer a king !!");
		}
#endif
		// bitboard
		clear_bit(POSITION->byChessBB[cattura],ai);      // 被吃的棋子的位棋盘清除
		clear_bit(bitboard_occ_white,ai);                 // 对方颜色的位棋盘

		// piece count
		POSITION->pieceCount[cattura] --;

		// piecelist
		POSITION->pieceList[cattura][POSITION->index[ai]] 
		  = POSITION->pieceList[cattura][POSITION->pieceCount[cattura]];

		// index
	    POSITION->index[POSITION->pieceList[cattura][POSITION->index[ai]]] 
		  = POSITION->index[ai];

		// pMat
		POSITION->pMat -= MatAddress[cattura];

		
		//POSITION->DYN->materiale -= valu_materiale[cattura];   // material
		POSITION->DYN->statico -= statico_valu[cattura][ai];     // position value

		POSITION->DYN->HASH ^= ZOBRIST[cattura][ai];

		POSITION->DYN->mossa50 = 0; // repeat 
	}
	else{
		set_bit(POSITION->byWhiteBlack,ai);        // ai == to
	}
	PB90(ai) = pezzo;  // to

	//pieceList
	POSITION->pieceList[pezzo][POSITION->index[di]] = ai;

	//index
	POSITION->index[ai] = POSITION->index[di];

	// key
	POSITION->DYN->HASH ^= ZOBRIST[pezzo][ai] ^ ZOBRIST[pezzo][di];

#ifdef USE_STACK_MOVE
	POSITION->StackHeight++;
	POSITION->STACKst[POSITION->StackHeight].move     = mossa;
	POSITION->STACKst[POSITION->StackHeight].capturer = cattura;
	POSITION->STACKst[POSITION->StackHeight].HASH     = POSITION->DYN->HASH;
#else
	POSITION->STACK[++(POSITION->StackHeight)] = POSITION->DYN->HASH;
#endif

    ASSERT(board_is_ok(POSITION));
}

void Make (const typePOS *POSITION, uint32 mossa)
{

#ifdef DEBUG_TMP	
	if(PB90(FROM(mossa)) == 0){
		board_display(POSITION,"make_mossa == 0\n");
		mossa = mossa;
	}
#endif

	if (POS_SIDE)
	{
		if (NODE_CHECK & NODE_CHECK_SIZE){
			NODE_CHECK--;
		}
		POSITION->nodes--;
		MakeWhite (POSITION, mossa);  // do_white
	}
	else
	{
		POSITION->nodes--;
		MakeBlack (POSITION, mossa);   // do_black
	}
}

#endif