
#include "chess.h"

////
//// Includes
////


//#include "s_direction.h"
#include "endgame.h"
#include "evaluate.h"
#include "material.h"
#include "mersenne.h"
#include "misc.h"
#include "movepick.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "uci.h"
#include "tt.h"
#include "VMP.h"

/// Application class is in charge of initializing global resources
/// at startup and cleanly releases them when program terminates.




void initTOTAL() {

	

#ifdef USE_VP_PROTECT
	is_registered();
#else
	frist_init();  // Bitboards::init();
#endif

	UCI::init(Options);	

	Position::init();
	Eval::init();

	Search::init();
	Threads.init();


#ifdef USE_USE_VP_PROTECT_BY_GG
#else
	read_uci_set_file();
#endif


	TT.resize(Options["Hash"]);	


	//Bitboard test = _mm_setzero_si128();
	//test = _mm_insert_epi64(test, -1, 0);
	//test = _mm_insert_epi64(test, -1, 1);

	//Bitboard test1 = test;
	//Bitboard test2 = test;

	//for (int i = 0; i < 256; i++) {



	//	int t1 = pop_1st_bit(test1);
	//	int t2 = pop_1st_bitFast(test2);

	//	if (t1 != t2) {
	//		int t3 = 4;
	//	}
	//	else{
	//		int t4 = 4;
	//	}
	//}

}







//FORCE_INLINE Square pop_11st_bit(Bitboard &b) {	//_BitScanForward
//	unsigned long index;
//	if (_mm_extract_epi64(b, 0)) {
//		_BitScanForward64(&index, _mm_extract_epi64(b, 0));
//	}
//	else {
//		_BitScanForward64(&index, _mm_extract_epi64(b, 1));
//		index += 64;
//	}
//	clear_bit(b, index);
//	return (Square)index;
//}


