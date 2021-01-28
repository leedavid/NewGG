

#if !defined(POSITION_H_INCLUDEDs)
#define POSITION_H_INCLUDEDs


// Disable some silly and noisy warning from MSVC compiler
#if defined(_MSC_VER)

// Forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable: 4800)

// Conditional expression is constant
#pragma warning(disable: 4127)
#pragma warning(disable: 4324)  // struct pad ....

#endif

#include <cassert>
#include <cstddef>  // For offsetof()
#include <deque>
#include <memory>   // For std::unique_ptr
#include <string>
#include <vector>

#include "chess.h"
#include "bitboard.h"
#include "movegen.h"


class Position;
class Thread;

/// CheckInfo struct is initialized at constructor time and keeps info used to
/// detect if a move gives check.

struct CheckInfo {

	explicit CheckInfo(Position&);  // explicit 用来禁止隐式转换，它仅适用于构造函数。
	
	Bitboard dcCandidates;			// 抽将的棋子, 这个位棋格盘可抽将.
	Bitboard PaoNull;				// 空炮的棋格. 棋子可以走到这儿来叠将.
	Bitboard checkSq[16];			// 将军的模子, 这个必须要16个位置
									// Bitboard pinned;
    Square ksq;  // 将的位置
};

/// The StateInfo struct stores information we need to restore a Position
/// object to its previous state when we retract a move. Whenever a move
/// is made on the board (by calling Position::do_move), an StateInfo object
/// must be passed as a parameter.

struct StateInfo {
	Key pawnKey;
	premat_t*  pMat;                // 子力
	int rule50, pliesFromNull;      // 不吃子检测 
	Score psq;                      // 棋子的位置分	
	Move  m;                        // 对方走的棋步
	bool  mischeck;                 // 走步是不是将军

	// Not copied when making a move
    Key key;
    Bitboard checkersBB;
	Piece capture;	                // 被吃的棋子
	StateInfo* previous;
};

// In a std::deque references to elements are unaffected upon resizing
typedef std::unique_ptr<std::deque<StateInfo>> StateListPtr;

/// 常捉判断结构
/// 共有多少个新增吃子步. 最多16个吃子步? 
typedef struct  {
#define MAX_REAL_CAP_NUM 16                                
	Piece       LastCapChess[MAX_REAL_CAP_NUM][2][2];      // 最后一次吃的棋子
	Square      last_to[MAX_REAL_CAP_NUM][2][2];           // 最后一次对方to
	Square      last_ot_from[MAX_REAL_CAP_NUM][2][2];      // 最多可能有16个真捉	
	Square      last_ot_to[MAX_REAL_CAP_NUM][2][2];        // 最后对方走的to
	int         cap_num[2][2];
	BOOL        isTrueCap;
	PieceType   capture_chess[2];                          // 双方捉的棋子  
}TrupCap_t;

/// The Position class stores the information regarding the board representation
/// like pieces, side to move, hash keys, castling info, etc. The most important
/// methods are do_move() and undo_move(), used by the search to update node info
/// when traversing the search tree.

class Position {	

public:
	static void init();
	
	Position() = default;
	Position(const Position&) = delete;
	Position& operator=(const Position&) = delete;

	// FEN string input/output
	Position& set(const std::string& fenStr, StateInfo* si, Thread* th);
	const std::string fen() const;

	void print(Move m = MOVE_NONE) const;
	void board_display(const std::string& reason) const;

	// Copying
	void board_red2black(const Position& pos);
	void board_mirror(const Position& pos);

	static bool isXiangEye(Square s);

	// The piece on a given square
	Piece piece_on(Square s) const;
	Piece moved_piece(Move m) const;
	bool square_is_empty(Square s) const;

   inline Bitboard pieces(Piece pc)  const        { return   byChessBB[pc]; };
   inline Bitboard pieces_of_color(Color c) const { return   byChessBB[COLOR_BY_SIDE_ADD[c]]; };
   inline Bitboard occupied_squares() const       { return   byWhiteBlack; };

	// Side to move
	Color side_to_move() const;

	// material info
	premat_t* pMatinfo() const;

	void do_move(Move m, StateInfo& st, bool moveIsCheck, CheckInfo& ci);
	void do_move_sim(Move m, StateInfo& st, bool moveIsCheck, CheckInfo& ci);
	void undo_move(Move m);
	void do_null_move(StateInfo& st);
	void undo_null_move();
	

	void move_undo_test(Move m, Piece capture); 
	void move_do_test(Move m, Piece* capture);

	 Bitboard Rook_attacks_bb(Square sq);
	 Bitboard Pao_Eat_bb(Square sq);
	 Bitboard Pao_Super_bb(Square sq);

	 Bitboard Rook_attacks_bb(Square sq, Bitboard& blockers);
	 Bitboard Rook_attacks_bb_only_F(Square sq, Bitboard& blockers);
	 Bitboard Pao_Eat_bb(Square sq, Bitboard& blockers);
	 Bitboard Pao_Super_bb(Square sq, Bitboard& blockers);

	 Bitboard ma_to_king_attacks_bb(Square sq);
	 Bitboard king_to_ma_attacks_bb(Square sq);
	 Bitboard xiang_attacks_bb(Square sq);

	 Bitboard ma_to_king_attacks_bb(Square sq, Bitboard& blockers);
	 Bitboard king_to_ma_attacks_bb(Square sq, Bitboard& blockers);
	 Bitboard xiang_attacks_bb(Square sq, Bitboard& blockers);

	// Static exchange evaluation
	 Value see(Move m);
	 Value see_sign(Move m);
	 // Static Exchange Evaluation
	 bool see_ge(Move m, Value value = VALUE_ZERO);

	// Accessing hash keys
	Key key() const;
	Key key_after(Move m) const;
	Key exclusion_key() const;
	//Key material_key() const;
	Key pawn_key() const;	

	// Incremental evaluation
	Score psq_score() const;

	REPEAT_INFO  is_repeat() ;
	REPEAT_INFO  get_repeat_info(int n, Move last_move);
	REPEAT_INFO  get_repeat_info_notCatChe(int n, Move last_move);
	//void repeat_unmake();
	//void repeat_make();
	bool see_draw_by_last_move(Square mfrom, Square mto,
		Square ofrom,Square oto, Color side, TrupCap_t* TRUECap, bool isincheck);

	// 不包括动兵,动将的吃子步. 
	ExtMove* cattura_not_include_pawn_king(ExtMove* mlist, Color c);

	// Number of pieces of each color and type
	int piece_count(Piece pc) const;

	// Current king position for each color
	Square king_square(Color c) const;

	 // Plies from start position to the beginning of search
	int game_ply() const; // int startpos_ply_counter() const;
	bool is_draw(int ply) const;
	// Bitboards for pinned pieces and discovered check candidates
	Bitboard discovered_check_candidates(Color c);    // 找出所有可抽将的棋子.
	Bitboard findPaoNullBiboard(Color c, Square ksq); // 找出所有可叠炮将的格子.
	//Bitboard pinned_pieces(Color c) const;

	// Checking pieces and under check information
	Bitboard checkers() const;
	bool in_check() const;

	// Piece lists
	Square piece_list(Piece pc, int index) const;

	// Current thread ID searching on the position
	Thread* this_thread() const;

	uint64 nodes_searched() const;
	void set_nodes_searched(uint64 n);

	// Position consistency check, for debugging
	bool pos_is_ok(int* failedStep = NULL);

	// Information about attacks to or from a given square
	Bitboard sq_attack_by_color(Square to, Color side);
	Bitboard attackers_to(Square s);

	Bitboard attacks_from(Piece p, Square s);
	Bitboard attacks_from_occ(Piece p, Square s, Bitboard occ);

	bool test_Is_True_Cap(Square from, Square to, Color c);
	bool isPretecte_TrueCap(Color c, Square to);


	// Properties of moves
	bool pseudo_legal(const Move m); // bool move_is_pseudo(Move move) const;
	bool legal(Move m); 
#ifndef NDEBUG
	bool pl_move_is_legala(Move m); 
#endif
	//bool gives_check(Move m);
	bool gives_check(Move m, CheckInfo& ci);
	bool capture(Move m) const;
	bool capture_or_promotion(Move m) const;

	// Piece captured with previous moves
	Piece captured_piece() const;
	Piece* posB90() { return this->b90; };

	template<PieceType Pt>
	PieceType min_attacker(const Bitboard* bb, Square to, Bitboard stmAttackers,
		Bitboard& occupied, Bitboard& attackers, Piece delta);

public:

	Bitboard byChessBB[16];          // byChessBB[0] = white; byChessBB[8] = black 
	Bitboard byWhiteBlack;           // 

private:  
	// Initialization helper functions (used while setting up a position)
	void set_state(StateInfo* si);
	void put_piece(Piece p, Square s);

	// Computing hash keys from scratch (for initialization and debugging)
	Key compute_key() const;
	Key compute_pawn_key() const;
	premat_t* compute_premat() const;

	// Computing incremental evaluation scores and material counts
	Score compute_psq_value() const;

	// Data members
	Piece b90[90];
	int index[90];
	int pieceCount[16];               // 
	Square pieceList[16][8];          // 
	//uint64 nodes;
	int gamePly;
	Color sideToMove;                 // 	
	Thread* thisThread;	
	StateInfo* st;
};

extern std::ostream& operator<<(std::ostream& os, const Position& pos);

//////////////////////////////////////////////////////////////////////////
inline Bitboard Position::Rook_attacks_bb(Square sq){
	return Rook_attacks_bb(sq,byWhiteBlack);
}
inline Bitboard Position::Pao_Eat_bb(Square sq){
	return Pao_Eat_bb(sq,byWhiteBlack);
}
inline Bitboard Position::Pao_Super_bb(Square sq){
	return Pao_Super_bb(sq,byWhiteBlack);
}

inline Bitboard Position::ma_to_king_attacks_bb(Square sq){
	return ma_to_king_attacks_bb(sq,byWhiteBlack);
}
inline Bitboard Position::king_to_ma_attacks_bb(Square sq){
	return king_to_ma_attacks_bb(sq,byWhiteBlack);
}

inline Bitboard Position::xiang_attacks_bb(Square sq){
	return xiang_attacks_bb(sq,byWhiteBlack);
}



//inline uint64 Position::nodes_searched() const {
//	return nodes;
//}

//inline void Position::set_nodes_searched(uint64 n) {
//	nodes = n;
//}


inline Thread* Position::this_thread() const {
	return thisThread;
}


//inline Piece Position::captured_piece_type() const {
//	return st->capturedType;
//}

inline Color Position::side_to_move() const {
	return sideToMove;
}



inline Piece Position::piece_on(Square s) const {
	return b90[s];
}

inline Piece Position::moved_piece(Move m) const {
	return b90[FROM(m)];
}

inline int Position::game_ply() const {
	return gamePly;
}




inline Square Position::piece_list(Piece pc, int idex) const {
	return pieceList[pc][idex];
}

inline int Position::piece_count(Piece pc) const {
	return pieceCount[pc];
}

inline Bitboard Position::checkers() const {
	return st->checkersBB;
}

inline bool Position::in_check() const {
	return m_have_bit(st->checkersBB);
}



inline bool Position::capture(Move m) const {

	// Move must not be MOVE_NONE !
	return (!square_is_empty(Square(m & 0x7F))); //return (!square_is_empty(to_sq(m)));	
}


inline bool Position::square_is_empty(Square s) const {
	return b90[s] == EMPTY;
}

inline premat_t* Position::pMatinfo() const {
	return st->pMat;
}

inline Key Position::key() const {
	return st->key;
}

inline Key Position::pawn_key() const {
	return st->pawnKey;
}


inline Square Position::king_square(Color c) const {
	return pieceList[RKING + COLOR_BY_SIDE_ADD[c]][0];
}


inline bool Position::capture_or_promotion(Move m) const {

	// Move must not be MOVE_NONE !
	//return (m & (0x1F << 12)) ? !move_is_castle(m) : !square_is_empty(to_sq(m));
	return (!square_is_empty(Square(m & 0xFF)));
}

//inline PieceType Position::captured_piece_type() const {
//	return type_of(st->capture);
//}


inline Piece Position::captured_piece() const {
	return st->capture;
}

inline Score Position::psq_score() const {
	return st->psq;
}


#endif

