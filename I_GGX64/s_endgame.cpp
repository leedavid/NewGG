#include "chess.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include "pawns.h"
#include "VMP.h"
#include "thread.h"

void print_eval_info(Position& pos, const EvalInfo& ei, const Value val){

//	read_evaluation_uci_options();
#ifdef NDEBUG
	std::cout << "\ncmd: fen " << pos.fen() << std::endl;

	StateInfo tmp[2];
	Position mPOS;
	mPOS.set(pos.fen(), tmp, pos.this_thread());
	mPOS.board_red2black(pos);
	std::cout << "\ncmd: r2b fen " << mPOS.fen() << std::endl;
#else
	pos.board_display("cmd eval info");
#endif	

	//
	std::cout << "cmd: mat: " << pos.pMatinfo()->material << " ph: " << (int)pos.pMatinfo()->phase
		<< " mg: " << mg_value(pos.psq_score())
		<< " eg: " << eg_value(pos.psq_score())
#ifdef CAN_OUT_EVAL_INFO
		<< " rs: " << (int)ei.kingDanger[WHITE]
		<< " bs: " << (int)ei.kingDanger[BLACK]
#endif
		<< " mul: " << (int)ei.mul  // << " pos.vvalue()
		<< "  eval: " << val << (pos.side_to_move() == WHITE ? " <w>" : " <b>") 
		<< "\ncmd: rcan: " << (int)ei.rcan << " bcan: " << (int)ei.bcan 
		<< " rsafe: " << (int)ei.rsafe << " bsafe: " << (int)ei.bsafe 

		<< " \ncmd: pawn: mv: " << mg_value(ei.pi->pawns_value()) << " ev: " << eg_value(ei.pi->pawns_value())
		<< " pcan w: " << (int)ei.pi->getPawnCan(WHITE)  << " b: " << (int)ei.pi->getPawnCan(BLACK) 
		<< " patt w: " << (int)ei.pi->getAttpoint(WHITE) << " b: " << (int)ei.pi->getAttpoint(BLACK)
		<< " pinfo " << ei.pi->getExtraPawnInfo()





	<< " \ncmd: AttW Che: " 
	<< count_1s(ei.attackKingBoard[WHITE],pos.pieces(RCHE))
	<< " Ma: " 
	<< count_1s(ei.attackKingBoard[WHITE],pos.pieces(RMA))
	<< " Pao: " 
	<< count_1s(ei.attackKingBoard[WHITE],pos.pieces(RPAO))
	<< " Pawn: " 
	<< count_1s(ei.attackKingBoard[WHITE],pos.pieces(RPAWN))
	<< " King: " << (int)bit_is_set(ei.attackKingBoard[WHITE],pos.king_square(WHITE))
	<< " attpw: "
	<< (int)ei.attPoint[WHITE]
	<< " \ncmd: AttB Che: " 
	<< count_1s(ei.attackKingBoard[BLACK],pos.pieces(BCHE))
	<< " Ma: " 
	<< count_1s(ei.attackKingBoard[BLACK],pos.pieces(BMA))
	<< " Pao: " 
	<< count_1s(ei.attackKingBoard[BLACK],pos.pieces(BPAO))
	<< " Pawn: " 
	<< count_1s(ei.attackKingBoard[BLACK],pos.pieces(BPAWN))
	<< " King: " << (int)bit_is_set(ei.attackKingBoard[BLACK],pos.king_square(BLACK))
	<< " attpb: " << (int)ei.attPoint[BLACK]
	<< "\ncmdend:" << std::endl;
}
