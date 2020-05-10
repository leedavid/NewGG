
#include "chess.h"

static uint64 rand0 = 1;
uint16
random16bits ()
{
  rand0 = rand0 * 8765432181103515245ULL + 1234567891ULL;
  return ((rand0 >> 32) % 65536);
}

static uint64
RAND64 ()
{
  return (((uint64) random16bits ()) << 48) |
    (((uint64) random16bits ()) << 32) |
    (((uint64) random16bits ()) << 16) |
    (((uint64) random16bits ()) << 0);
}

#ifdef USE_STOCK_FISH_FILE
#else

void
	zob_iniz ()
{
	int i,j;
	ZOBRIST_side = RAND64();
	for(i = 0; i < 16; i++){  
		for(j = 0; j < 90; j++){
			ZOBRIST[i][j] = RAND64();
		}
	}
}

void
InitArrays ()
{
  zob_iniz ();
}

#endif
