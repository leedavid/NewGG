#include <cstring>
#include "movegen.h"

extern void read_uci_set_file();
//extern int get_cyclone_sub_depth(int depth);
extern bool is_registered();
extern void print_eval_info(Position& pos, const EvalInfo& ei, const Value val);

extern char piece_to_char(Piece pc);
extern Piece piece_from_char(char c);

extern void init_direction_table();
extern void init_relative_rank();

extern Move move_from_string(const Position& pos, const std::string& str);

// move_gen 
extern ExtMove* WhiteCaptures (typePOS &POSITION, ExtMove* mlist);
extern ExtMove* BlackCaptures (typePOS &POSITION, ExtMove* mlist);

extern ExtMove* WhiteOrdinary (typePOS &POSITION, ExtMove* mlist);
extern ExtMove* BlackOrdinary (typePOS &POSITION, ExtMove* mlist);

extern bool WhiteHaveCaptures (typePOS &POSITION);
extern bool BlackHaveCaptures (typePOS &POSITION);

extern bool WhiteHaveOrdinary (typePOS &POSITION);
extern bool BlackHaveOrdinary (typePOS &POSITION);

extern bool WhiteHaveEvasions (typePOS &POSITION);
extern bool BlackHaveEvasions (typePOS &POSITION);

extern ExtMove* QuietChecksWhite (typePOS &POSITION, ExtMove* mlist);
extern ExtMove* QuietChecksBlack (typePOS &POSITION, ExtMove* mlist);

extern ExtMove* WhiteEvasions (typePOS &POSITION, ExtMove* mlist);
extern ExtMove* BlackEvasions (typePOS &POSITION, ExtMove* mlist);

extern bool WHITE_move_is_legal(typePOS &POSITION, const Move m, Bitboard pinned);
extern bool BLACK_move_is_legal(typePOS &POSITION, const Move m, Bitboard pinned);

extern  void index_to_Bitboard	(Bitboard *result, int index, int bits, Bitboard mask); 
extern  void che_att_by_block_f		(Bitboard *result, int sq,Bitboard block);
extern  void che_att_by_block_r		(Bitboard *result, int sq,Bitboard block);

extern  void pao_eat_by_block_r		(Bitboard *result, int sq,Bitboard block);
extern  void pao_eat_by_block_f		(Bitboard *result, int sq,Bitboard block);

extern  void pao_super_by_block_r	(Bitboard *result, int sq,Bitboard block);
extern  void pao_super_by_block_f	(Bitboard *result, int sq,Bitboard block);

extern  void xiang_att_by_block		(Bitboard *result, int sq,Bitboard block);

extern  void ma_to_king_att_by_block	(Bitboard *result, int sq,Bitboard block);
extern  void king_to_ma_att_by_block	(Bitboard *result, int sq,Bitboard block);

extern  void init_bb_const(void);

extern void InitPreMatinfo(void);
extern void init_bitboards();

extern void frist_init(void);
//extern void second_init();
//extern void eval_const_int(void);

//extern void init_PawnCanAddByChe(void);
//extern void board_display(typePOS *, const std::string& reason);
extern void print_bb(Bitboard bb);

extern int White_pawn_already_over_river(typePOS &POSITION);
extern int Black_pawn_already_over_river(typePOS &POSITION);

extern Bitboard White_get_connect_Pawn(typePOS &POSITION);
extern Bitboard Black_get_connect_Pawn(typePOS &POSITION);

extern bool isWhite_have_ZhongPao_Or_DiPao(typePOS &POSITION);
extern bool isBlack_have_ZhongPao_Or_DiPao(typePOS &POSITION);

extern int White_pawn_can_over_river(typePOS&);
extern int Black_pawn_can_over_river(typePOS&);

extern bool Is_R_PawnControl_B_Ma(typePOS&);
extern bool Is_B_PawnControl_R_Ma(typePOS&);

extern void BothOnlyPawnEval(typePOS &POSITION, EvalInfo &ei);

extern bool getBetweenSq(typePOS &POSITION, Square sq1, Square sq2, Square& mid);

extern bool isStringByChe(typePOS &POSITION,Square sq1,Square mid, Square sq2);
extern bool isStringByPao(typePOS &POSITION,Square pao,Square sq3, Square sq4);

extern void (*funMat[26244])	(typePOS &board, EvalInfo &ei);  //用来评估的函数指针 
// ----------------------------------------------------------------------------------------
extern  void InitMatFunction1();
extern  void InitMatFunction2();
extern  void InitMatFunction3();
extern  void InitMatFunction4();
extern  void InitMatFunction5();
extern  void InitMatFunction6();
extern  void InitMatFunction7();
extern  void InitMatFunction8();
extern  void InitMatFunction9();
extern  void InitMatFunction();


#include "endgame\\end_fun1.h"
#include "endgame\\end_fun2.h"
#include "endgame\\end_fun3.h"
#include "endgame\\end_fun4.h"
#include "endgame\\end_fun5.h"
#include "endgame\\end_fun6.h"
#include "endgame\\end_fun7.h"
#include "endgame\\end_fun8.h"
#include "endgame\\end_fun9.h"

#define IsOnSameSide(sq1,sq2)  (King_4_Side(sq1) == King_4_Side(sq2))