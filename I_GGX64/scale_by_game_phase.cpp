#include "eval_total.h"
#include "uci.h"
#include "VMP.h"

// scale_by_game_phase() interpolates between a middle game and an endgame
// score, based on game phase.  It also scales the return value by a
// ScaleFactor array.

//Value scale_by_game_phase(const Position& pos, EvalInfo& ei, const Score& v) {
Value scale_by_game_phase(Position& pos, EvalInfo& ei, const Score& v) {

	// 1, 先求残局的和棋因子
	ei.mul = 16;

	//static const  premat_t *Porg  = &PreMatInfo[0][0][0][0][0][0][0][0][0][0][0][0];

	(*funMat[(pos.pMatinfo() - &PreMatInfo[0][0][0][0][0][0][0][0])])(pos, ei);       // 得到残局的分信息

	if((ei.bsafe + ei.rsafe) == 2) {
		ei.mul = 1;
	}

	// 加上残局的信息分.
	Score bonus = v + make_score(ei.evscore,ei.evscore);

	int ev = eg_value(bonus);
	int mv = mg_value(bonus);

	int ph = pos.pMatinfo()->phase;

	//if(!(ev > -VALUE_INFINITE && ev < VALUE_INFINITE)){
	//	pos.board_display("EVV??");
	//	ev = ev;
	//} // fen 1rbakab1r/9/2n3nc1/p1p1p1p1p/1C7/2P6/N3P1P1P/6NC1/9/1RBAKAB1R b - - 0 1

	ASSERT(mv > -VALUE_INFINITE && mv < VALUE_INFINITE);
	ASSERT(ev > -VALUE_INFINITE && ev < VALUE_INFINITE);
	ASSERT(ph >= PHASE_ENDGAME && ph <= PHASE_MIDGAME);

	int result = ((mv * ph + ev * (128 - ph)) * ei.mul) / (128 * 16); 
	//result = result * ei.mul / 16;               // 和棋因子.

#ifdef CAN_OUT_EVAL_INFO
	if(MustOuPutEvalInf){
       MustOuPutEvalInf = false;
	   print_eval_info(pos,ei,pos.side_to_move() == WHITE ? (Value)result : (Value)(-result));	
	}
#endif
	return Value(result); // Sign independent


}