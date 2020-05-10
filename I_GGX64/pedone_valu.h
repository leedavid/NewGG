//
//#define puntos(x,y) (((x)<<16)+(y))
//
//#define distanza_re_pedone_bianco(pe, re)\
//  MASSIMO ( ( ( re > pe) ? 3 : 6) * ASSOLUTO (TRAVERSA (pe) - TRAVERSA (re) ),\
//            6 * ASSOLUTO (COLONNA (pe) - COLONNA (re) ) )
//#define distanza_re_pedone_nero(pe,re)\
//  MASSIMO ( ( ( re < pe) ? 3 : 6) * ASSOLUTO (TRAVERSA (pe) - TRAVERSA (re) ),\
//            6 * ASSOLUTO ( COLONNA(pe) - COLONNA (re) ) )
//
//static uint8 opposto_moltiplicatore[9] = { 6, 5, 4, 3, 2, 1, 0, 0, 0 };
//static uint8 conto_moltiplicatore[9] = { 6, 5, 4, 3, 2, 1, 0, 0, 0 };
//
//const static uint8 pedone_bloccato_valu[64] =
//{ 0, 0, 0, 0, 0, 0, 0, 0,
//  1, 1, 2, 2, 2, 2, 1, 1,
//  1, 2, 3, 3, 3, 3, 2, 1,
//  1, 2, 3, 5, 5, 3, 2, 1,
//  1, 2, 3, 5, 5, 3, 2, 1,
//  1, 2, 3, 3, 3, 3, 2, 1,
//  1, 1, 2, 2, 2, 2, 1, 1,
//  0, 0, 0, 0, 0, 0, 0, 0
//};
//
//const static sint32 mio_re_pedone_distanza[8] = { 0, 0, 0, 1, 2, 3, 5, 0 };
//const static sint32 mitu_re_pedone_distanza[8] = { 0, 0, 0, 2, 4, 6, 10, 0 };
//
//const static sint32 pedone_libero_valu[8] =
//  { puntos (0, 0), puntos (0, 0), puntos (0, 0), puntos (10, 10),
//    puntos (20, 25), puntos (40, 50), puntos (60, 75), puntos (0, 0)
//};
//
//const static sint32 pedone_libero_valu_ampio[8] =
//  { puntos (0, 0), puntos (0, 0), puntos (0, 0), puntos (0, 0),
//    puntos (2, 5), puntos (5, 10), puntos (10, 20), puntos (0, 0)
//};
//
//const static sint32 pedone_libero_valu_protetto[8] =
//  { puntos (0, 0), puntos (0, 0), puntos (0, 0), puntos (0, 0),
//    puntos (5, 10), puntos (10, 15), puntos (15, 25), puntos (0, 0)
//};
//
//const static sint32 pedone_libero_valu_connesso[8] =
//  { puntos (0, 0), puntos (0, 0), puntos (0, 0), puntos (0, 0),
//    puntos (5, 10), puntos (10, 15), puntos (20, 30), puntos (0, 0)
//};
//
//const static sint32 pedone_candidato_valu[8] =
//  { puntos (0, 0), puntos (0, 0), puntos (0, 0), puntos (5, 5),
//    puntos (10, 12), puntos (20, 25), puntos (0, 0), puntos (0, 0)
//};
//
//#define isola puntos(0, 3)
//#define foro puntos(1, 2)
//#define doppio_chiuso puntos(2, 4)
//#define doppio_aperto puntos(4, 8)
//#define doppio_chiuso_isolato puntos(2, 4)
//#define doppio_aperto_isolato puntos(6, 10)
//#define isolato_chiuso puntos(5, 8)
//#define isolato_aperto puntos(15, 20)
//#define ritardato_chiuso puntos(5, 5)
//#define ritardato_aperto puntos(10, 15)
//
//#define re_attacco_pedone puntos(0, 5)
//#define re_oo puntos(5, 0)
//#define re_ooo puntos(5, 0)
