
// #define bitboard_two(x, y) (((uint64) 1) << (x))|(((uint64) 1) << (y))
//#define bitbordo_due(x, y) (((uint64) 1) << (x))|(((uint64) 1) << (y))
//#define F1H1 bitbordo_due(F1, H1)
//#define F1H1_sinistra90 bitbordo_due(sinistro90[F1], sinistro90[H1])
//#define F1H1_sinistra45 bitbordo_due(sinistro45[F1], sinistro45[H1])
//#define F1H1_retto45 bitbordo_due(retto45[F1], retto45[H1])
//#define A1D1 bitbordo_due(A1, D1)
//#define A1D1_sinistra90 bitbordo_due(sinistro90[A1], sinistro90[D1])
//#define A1D1_sinistra45 bitbordo_due(sinistro45[A1], sinistro45[D1])
//#define A1D1_retto45 bitbordo_due(retto45[A1], retto45[D1])
//#define F8H8 bitbordo_due(F8, H8)
//#define F8H8_sinistra90 bitbordo_due(sinistro90[F8], sinistro90[H8])
//#define F8H8_sinistra45 bitbordo_due(sinistro45[F8], sinistro45[H8])
//#define F8H8_retto45 bitbordo_due(retto45[F8], retto45[H8])
//#define A8D8 bitbordo_due(A8, D8)
//#define A8D8_sinistra90 bitbordo_due(sinistro90[A8], sinistro90[D8])
//#define A8D8_sinistra45 bitbordo_due(sinistro45[A8], sinistro45[D8])
//#define A8D8_retto45 bitbordo_due(retto45[A8], retto45[D8])

// #define occupied_free(M, x)                    
//#define occupato_libero(M, x)\
//  { POSITION->occupato_nero_bianco &= M;\
//    POSITION->occupato_sinistro90 &= sinistro90_reset[x];\
//    POSITION->occupato_sinistro45 &= sinistro45_reset[x];\
//    POSITION->occupato_retto45 &= retto45_reset[x]; }
// #define occupied_fixed(M, x)     
//#define occupato_fisso(M, x)\
//  { POSITION->occupato_nero_bianco |= M;\
//    POSITION->occupato_sinistro90 |= sinistro90_fisso[x];\
//    POSITION->occupato_sinistro45 |= sinistro45_fisso[x];\
//    POSITION->occupato_retto45 |= retto45_fisso[x]; }
