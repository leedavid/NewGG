#include "chess.h"

////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>


#include "mersenne.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

using std::string;

static bool RequestPending = false;


/// Position c'tors. Here we always create a slower but safer copy of
/// the original position or the FEN string, we want the new born Position
/// object do not depend on any external data. Instead if we know what we
/// are doing and we need speed we can create a position with default
/// c'tor Position() and then use just fast_copy().

//Position::Position(int th) : threadID(th) {}

//void Position::copy(const Position& pos, Thread* th) {
//
//	memcpy(this, &pos, sizeof(Position));
//	startState = *st;
//	st = &startState;
//	thisThread = th;
//	nodes = 0;
//
//	ASSERT(pos.pos_is_ok());
//}

// position fen rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 moves g1f3 b8c6

//void Position::rep_copy_only(const Position& pos, int th) {
//
//	memcpy(this, &pos, sizeof(Position));
//
//	ASSERT(pos.is_ok());
//}




//Position::Position(int dummy, const Position& pos){
//	memcpy(this, &pos, sizeof(Position));
//}

//void Position::copy_pos(const Position& scr){
//	memcpy(this, &scr, sizeof(Position));
//}



//Position::Position(const string& fen, int th) {
//
//	from_fen(fen);
//	threadID = th;
//}

/////////////////////////////////////////////////////////////
/// 打印输出棋盘
/////////////////////////////////////////////////////////////
void Position::board_display(const std::string& reason) const{

	//static bool isouting = false;

	//if(isouting) return;

	//isouting = true;

	//char buf[256];
	//int r,f;
	//int chess;

	//static const  char *c_BoardStrSim[19] = {
	//	"cmd: 9┌--┬--┬--┬--┬--┬--┬--┬--┐ \n",
	//	"cmd:  │  │  │  │＼│／│  │  │  │ \n",
	//	"cmd: 8├--┼--┼--┼--※--┼--┼--┼--┤ \n",
	//	"cmd:  │  │  │  │／│＼│  │  │  │ \n",
	//	"cmd: 7├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
	//	"cmd:  │  │  │  │  │  │  │  │  │ \n",
	//	"cmd: 6├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
	//	"cmd:  │  │  │  │  │  │  │  │  │ \n",
	//	"cmd: 5├--┴--┴--┴--┴--┴--┴--┴--┤ \n",
	//	"cmd:  │                              │ \n",
	//	"cmd: 4├--┬--┬--┬--┬--┬--┬--┬--┤ \n",
	//	"cmd:  │  │  │  │  │  │  │  │  │ \n",
	//	"cmd: 3├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
	//	"cmd:  │  │  │  │  │  │  │  │  │ \n",
	//	"cmd: 2├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
	//	"cmd:  │  │  │  │＼│／│  │  │  │ \n",
	//	"cmd: 1├--┼--┼--┼--※--┼--┼--┼--┤ \n",
	//	"cmd:  │  │  │  │／│＼│  │  │  │ \n",
	//	"cmd: 0└--┴--┴--┴--┴--┴--┴--┴--┘ \n"
	//	"cmd:  a   b   c   d   e   f   g   h   i\n"
	//};

	//static const  char chessStr[17][4] = {
	//	"错",
	//	"帥","仕","相","馬","車","炮","兵",
	//	"错",
	//	"將","士","象","马","车","包","卒",
	//	"错"
	//};

	////fprintf(out,"cmd: ");
	////fprintf(out, szReason);   //

	//std::cout << "cmd: fen " << fen() << std::endl;

	//std::cout << "cmd: " << reason << std::endl;             

	//for(r = 0; r < 19; r++){
	//	sprintf_s(buf,256, c_BoardStrSim[r]);
	//	if(r%2 == 0){
	//		for(f = 0; f < 9; f++){
	//			chess = piece_on(XYtoS(f, r/2));
	//			if(chess != EMPTY){
	//				buf[f*4+1+5] = chessStr[chess][0];
	//				buf[f*4+2+5] = chessStr[chess][1];
	//			}
	//		}
	//	}
	//	std::cout << buf;
	//}
	//std::cout << "cmd: fen " << fen() << std::endl;

	//isouting = false;
}

// Position::set() initializes the position object with the given FEN string.
/// This function is not very robust - make sure that input FENs are correct,
/// this is assumed to be the responsibility of the GUI.

Position& Position::set(const string& fenStr, StateInfo* si, Thread* th) {
	/*
	A FEN string defines a particular position using only the ASCII character set.

	A FEN string contains six fields separated by a space. The fields are:

	1) Piece placement (from white's perspective). Each rank is described, starting
	with rank 8 and ending with rank 1. Within each rank, the contents of each
	square are described from file A through file H. Following the Standard
	Algebraic Notation (SAN), each piece is identified by a single letter taken
	from the standard English names. White pieces are designated using upper-case
	letters ("PNBRQK") whilst Black uses lowercase ("pnbrqk"). Blank squares are
	noted using digits 1 through 8 (the number of blank squares), and "/"
	separates ranks.

	2) Active color. "w" means white moves next, "b" means black.

	3) Castling availability. If neither side can castle, this is "-". Otherwise,
	this has one or more letters: "K" (White can castle kingside), "Q" (White
	can castle queenside), "k" (Black can castle kingside), and/or "q" (Black
	can castle queenside).

	4) En passant target square (in algebraic notation). If there's no en passant
	target square, this is "-". If a pawn has just made a 2-square move, this
	is the position "behind" the pawn. This is recorded regardless of whether
	there is a pawn in position to make an en passant capture.

	5) Halfmove clock. This is the number of halfmoves since the last pawn advance
	or capture. This is used to determine if a draw can be claimed under the
	fifty-move rule.

	6) Fullmove number. The number of the full move. It starts at 1, and is
	incremented after Black's move.
	*/

	unsigned char token;
	Square sq = SQ_START;
//	size_t idx;
	Piece p;
	std::istringstream ss(fenStr);

	std::memset(this, 0, sizeof(Position));      // 清空棋盘
	std::memset(si, 0, sizeof(StateInfo));       // 清空状态
	// std::fill_n(&pieceList[0][0][0], sizeof(pieceList) / sizeof(Square), SQ_NONE);
	st = si;

	ss >> std::noskipws;

	// 1. Piece placement  放置棋子
	while ((ss >> token) && !isspace(token))
	{
		if (isdigit(token))
			sq += Square(token - '0');

		else if (token == '/') {
			sq += Square(0);
		}
		else if ((p = piece_from_char(token)) != EMPTY) {
			put_piece(p, sq);
			++sq;
		}

	}


	// 2. Active color
	ss >> token;
	if (token == 'w' || token == 'W' || token == 'r' || token == 'R') {
		sideToMove = WHITE;
	}
	else {
		sideToMove = BLACK;
	}
	ss >> token;

	// 3. Castling availability. Compatible with 3 standards: Normal FEN standard,
	// Shredder-FEN that uses the letters of the columns on which the rooks began
	// the game instead of KQkq and also X-FEN standard that, in case of Chess960,
	// if an inner rook is associated with the castling right, the castling tag is
	// replaced by the file letter of the involved rook, as for the Shredder-FEN.
	//---------------------------------------------------------------------------
	
	// 4. En passant square. Ignore if no pawn capture is possible
	//---------------------------------------------------------------------------
	
	// 5-6. Halfmove clock and fullmove number
	ss >> std::skipws >> st->rule50 >> gamePly;

	st->rule50 = 0;

	// Convert from fullmove starting from 1 to ply starting from 0,
	// handle also common incorrect FEN with fullmove = 0.
	gamePly = std::max(2 * (gamePly - 1), 0) + (sideToMove == BLACK);

	// chess960 = isChess960;
	thisThread = th;
	set_state(st);	

	assert(pos_is_ok());

	//board_display("");

	return *this;

}

/// Position::set_state() computes the hash keys of the position, and other
/// data that once computed is updated incrementally as moves are made.
/// The function is only used when a new position is set up, and to verify
/// the correctness of the StateInfo data when running in debug mode.

void Position::set_state(StateInfo* si) {

	si->key = compute_key();
	si->pawnKey = compute_pawn_key();
	si->psq = compute_psq_value();
	si->pMat = compute_premat();
	
	Color Us = side_to_move();
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Square mk = king_square(Us);

	si->checkersBB = m_or(m_and(pieces(BPAWN - delt),
		Us == WHITE ? Attack_By_Bpawn_Bking[mk] : Attack_By_Rpawn_Rking[mk]), m_or(
			m_and(Rook_attacks_bb(mk), pieces(BCHE - delt)), m_or(
				m_and(Pao_Eat_bb(mk), pieces(BPAO - delt)),
				m_and(king_to_ma_attacks_bb(mk), pieces(BMA - delt)))));

	// 将军的信息？fen 2b1k1b2/4a1P2/3a5/R8/8C/9/9/9/1r2K1p2/2B6 w - - 0 1 moves e1e2 b1b2 e2e1
	si->m = MOVE_NONE;
	si->mischeck = m_have_bit(si->checkersBB);
}

/// Position::to_fen() converts the position object to a FEN string. This is
/// probably only useful for debugging.

const string Position::fen() const {

	string fen;

	int rank;
	int file;
	Square sq90;
	Piece pt;
	int c;
	//int pc = 0;	

	for(rank = 0; rank <= 9; rank ++){
		for(file = 0; file <= 8;){
			sq90  = XYtoS(file,rank);
			//pt= PB90(sq90);
			pt = b90[sq90];

			ASSERT(pt <= BPAWN); 

			if(pt == EMPTY){
				char len = 0;
				for(; file <= 8 && b90[XYtoS(file,rank)] == EMPTY; file++){
					len ++;
				}

				ASSERT(len>=1&&len<=9);

				c = '0' + len;
			}
			else{
				c = piece_to_char(pt);
				file++;
			}

			fen += (char)c;
		}
		fen += (rank < 9 ? '/' : ' ');
	}

	fen += (sideToMove == WHITE ? "w " : "b ");
	fen += "- - 0 1";

	return fen;
}

/// Position::print() prints an ASCII representation of the position to
/// the standard output. If a move is given then also the san is print.

void Position::print(Move m) const {

	// Check for reentrancy, as example when called from inside
	// MovePicker that is used also here in move_to_san()
	if (RequestPending)
		return;

	RequestPending = true;

	std::cout << std::endl;

	//////////////////////////////////////////////////////////////////////////
	if(m != MOVE_NONE){
		string col = (color_of(piece_on(from_sq(m))) == BLACK ? ".." : "");
		std::cout << "Move is: " << col << UCI::move(m) << std::endl;
	}

	board_display("print m: >> ");

	 std::cout << "Fen is: " << fen() << std::endl
		       << "Key is: " << st->key  << std::endl;


	//////////////////////////////////////////////////////////////////////////

	RequestPending = false;
}

