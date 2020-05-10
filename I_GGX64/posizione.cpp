#include "chess.h"
 
#ifdef USE_STOCK_FISH_FILE
#else

static void board_clear(typePOS *POSITION){
	//int pieceCount[16];                     // now [piece], was [color][type]
	//Piece lists
	//int pieceList[16][8];                   // now [piece][index], was [color][pieceType][index]
	//int index[90];
	int sq;
	int a,b;
	for(sq = 0; sq < 90; sq++){
		PB90(sq) = 0;
		POSITION->index[sq] = 0;
	}
	for(a = 0; a < 16; a++){
		POSITION->pieceCount[a] = 0;
		for(b = 0; b < 8; b++){
			POSITION->pieceList[a][b] = 0;
		}
	}
}

static bool fen_posizionale (const typePOS *POSITION, char *I)
{
	int rank;
	int file;
	int sq90;
	//int len;
	int i;
	int pf = 0;
	int c = I[pf];

	board_clear(POSITION);

	for(rank = 0; rank <= 9; rank++){
		for(file = 0; file <=8;){
			sq90= XYtoS(file,rank);
			//PB90(sq90) = EMPTY;  //注意,这儿的空棋子是16,不是0! PB90(sq90)
			if(c >= '1' && c <= '9'){
				int len = c - '0';
				for(i = 0; i < len; i++){
					if(file > 8){
						printf("Error>行空格不正确,board_from_fen(): bad FEN (board=%d)\n",pf); 
						return FALSE;
					}					
					file++;
				}
			}
			else{  // piece, 这是一个棋子
				int piece = piece_from_char(c);
				if(piece == EMPTY){
					printf("Error>棋子不对, board_from_fen(): bad FEN (board=%d)\n",pf);
					return FALSE;
				}
				PB90(sq90)     = piece;
				POSITION->index[sq90]   = POSITION->pieceCount[piece];
				POSITION->pieceList[piece][POSITION->index[sq90]] = sq90;
				POSITION->pieceCount[piece] ++;
				//put piece end ////////////////////////////////////////
				file++;
			}
			c = I[++pf];
		}
		if(rank < 9){
			if( c != '/'){
				printf("Error>棋子没行结束,board_from_fen(): bad FEN (board=%d)\n",pf); 
				return FALSE;
			}
			c = I[++pf];
		}
	}
	return TRUE;
}

char * ReadFEN (const typePOS *POSITION, char *I)
{
   
	char i[1024];
    sscanf_s (I, "%s", i, 512);
    fen_posizionale (POSITION, i);  // 得到B90的棋子信息
    //memset (POSITION->DYN_inizio, 0, 256 * sizeof (tipo_POSITION->DYN));
    POSITION->DYN = POSITION->DYN_ROOT;
    I += strlen (i) + 1;
    sscanf_s (I, "%s", i,512);
	if (i[0] == 'w' || i[0] == 'W' || i[0] == 'r' || i[0] == 'R' )
		POS_SIDE = TRUE;
	else if (i[0] == 'b' || i[0] == 'B')
		POS_SIDE = FALSE;
	else{
		ERROR_END ("FEN wb %s\n", i);
	}

	POSITION->DYN->mossa50 = 0;	
	return I;
}

static uint32 FullMove (const typePOS *POSITION, uint32 x)
{
  //int pezzo, ai = AI (x), di = DI (x);
  //if (!x)
  //  return x;
 // pezzo = POSITION->qu[di];
 // if (pezzo == conto_re_bianco || pezzo == conto_re_nero)
 //   {
 //     if (ai - di == 2 || di - ai == 2)
	//x |= pietra_arrocco;        // flag_castling 王车易位
 //   }
 // if (AI (x) != 0 && AI (x) == POSITION->DYN->en_passant
 //     && (pezzo == conto_pedone_bianco || pezzo == conto_pedone_nero))
 //   x |= pietra_en_passant;     // 吃过河兵
 return x;

  //int piece, ai = AI(x), di = DI(x);

  //if( !x )
	 // return x;

  //piece = QU[di];

  //if( piece == count_king_white || piece == count_king_black )
  //{
	 // if( ai - di == 2 || di - ai == 2 )
		//  x |= flag_castling;
  //}

  //if( AI(x) != 0 && AI(x) == DYNAMIC->en_passant && (piece == count_pawn_white || piece == count_pawn_black) )
	 // x |= flag_en_passant;
  //return x;
}

#define IN_CHECK  ( POS_SIDE ? \
	m128_is_have_bit(m_and(POSITION->DYN->attack_black,bitboard_white_king)): \
	m128_is_have_bit(m_and(POSITION->DYN->attack_white,bitboard_black_king)))

static void ReadMoves (const typePOS *POSITION, char *I)
{
	typeMoveList LISTA[128], *lista;
	char T[256];
	int i;
	uint32 totale;
	int from;
	int to;
	while (I[0])
	{
		Mobility (POSITION);  // mobility();
		if (IN_CHECK) // check
		{
			// lista = evasione_mossa (POSITION, LISTA, 0xffffffffffffffff);
			lista = EvasionMoves  (POSITION, LISTA,_mm_set1_epi32(0xFFFFFFFF));
			lista++;
		}
		else
		{
			// capture 
			// lista = cattura_mossa (POSITION, LISTA, POSITION->occupato_nero_bianco);
			lista = CaptureMoves  (POSITION, LISTA,POSITION->byWhiteBlack);
			lista = OrdinaryMoves (POSITION, lista);
		}
		//totale =
		//	FullMove (POSITION, (I[2] - 'a') + ((I[3] - '1') << 4) +
		//	((I[0] - 'a') << 8) + ((I[1] - '1') << 12));
		from = (I[0] - 'a') + (('9' - I[1]) * 9);
		to   = (I[2] - 'a') + (('9' - I[3]) * 9);
		totale = MOVE_FromTo(from,to);

		sscanf_s (I, "%s", T,256);
		//if (strlen (T) == 5)
		//{
		//	if (I[4] == 'b')
		//		totale |= pietra_promozione_alfiere;
		//	if (I[4] == 'n')
		//		totale |= pietra_promozione_cavallo;
		//	if (I[4] == 'r')
		//		totale |= pietra_promozione_torre;
		//	if (I[4] == 'q')
		//		totale |= pietra_promozione_donna;
		//}
		for (i = 0; i < lista - LISTA; i++)
		{
			if (totale == (LISTA[i].move & 0x7fff))      // 走步不存在?
			{
				Make (POSITION, totale);
				break;
			}
		}
		if (i == lista - LISTA)
		{
			ERROR_END ("moves? %s\n", T);
		}
		I += strlen (T) + 1;
		while (I[0] == ' ')
			I++;
	}
}

void InitPosition (const typePOS *POSITION, char *I)
{
	char i[1024];
	NODE_CHECK = 0;
	//SEARCH_ROBBO_BASES = TRUE;

	sscanf_s (I, "%s", i,1000);
	if (!strcmp (i, "startpos"))  // 开始的局面
	{
		ReadFEN (POSITION, (char*)posizione_originale);
		InitBitboards (POSITION,TRUE);
		I += strlen ("startpos") + 1;
	}
	if (!strcmp (i, "fen"))
	{
		I += strlen ("fen") + 1;
		I = ReadFEN (POSITION, I); // 
		InitBitboards (POSITION,TRUE);
	}
	if (I[0])
	{
		I = strstr(I,"moves");
		if(I != NULL){
			I += 6;
			ReadMoves (POSITION, I);   // legal_moves(I); // 如果有走步,就判断合法走步
		}
	}
	POSITION->height = 0;
	if (NEW_GAME)          // GAME_NEW
		ResetPositionalGain ();      // 增益初始化 gain_reset();
}

#endif

