#include "..\\chess.h" 



#include "preGen.h"

// 王牵制对方的仕的加分
void KingControlKingAdd(const typePOS *POSITION, EvalInfo *ei){
	Square rk = RKpos();
	Square bk = BKpos();

	if(StoX(rk) == StoX(bk)){
		Bitboard cheeat = rook_attacks_bb(rk,BitboardOCC);
		if(bit_is_set(cheeat,bk)){
			cheeat = m_and(BetweenBB[rk][bk],BitboardOCC);
			int sq = pop_1st_bit(&cheeat);
			switch(PB90(sq)){
			case RSHI:
				ei->evscore -= 96;
				break;
			case RXIANG:
				ei->evscore -= 64;
				break;
			case BSHI:
				ei->evscore += 96;
				break;
			case BXIANG:
				ei->evscore += 64;
				break;
			}
		}
	}
}

void BothOnlyPawnEval(const typePOS *POSITION, EvalInfo *ei){
	
	Bitboard p;
	
	// 王牵制对方的仕的加分
	KingControlKingAdd(POSITION,ei);

	int rcan = ei->rcan;
	int bcan = ei->bcan;

	ei->evscore += 80 * (rcan - bcan);

	// fen 2b3P2/3k5/6P2/9/9/9/9/B8/9/2B1K4 w
	// 兵相对对方的仕的加分。
	p = m_and(bitboard_white_pawn,UpBB[StoY(BKpos())]);
	if(count_1s(p) == count_1s(bitboard_white_pawn)){
		if(BXiang_num() >= 1 || bcan >= 1){
			ei->bsafe = true;
		}
	}
	

	//
	p = m_and(bitboard_black_pawn,LowBB[StoY(RKpos())]);
	if(count_1s(p) == count_1s(bitboard_black_pawn)){
		if(RXiang_num() >= 1 || rcan >= 1){
			ei->rsafe = true;
		}
	}

	if(bcan == 0) ei->rsafe = TRUE;

	if(rcan == 0) ei->bsafe = TRUE;
	
	if(rcan <= 1){
		if((BShi_num() + BXiang_num()) >= 3){
			ei->bsafe = TRUE;
		}
	}

	if(bcan <= 1){
		if((RShi_num() + RXiang_num()) >= 3){
			ei->rsafe = TRUE;
		}
	}

	Square rk = RKpos();
	Square bk = BKpos();

	// fen 9/2P1PP3/3k5/p1p1p3p/9/9/P7P/9/9/2BAKAB2 w - - 0 1
	// 我方的兵全在对方的将下面，与不能过河
	Bitboard mrup = m_and(bitboard_white_pawn,UpBB[StoY(bk)]);
	int rup = count_1s(mrup);

	Bitboard mbup = m_and(bitboard_black_pawn,LowBB[StoY(rk)]);
	int bup = count_1s(mbup);

	if(rup >= rcan){
		ei->evscore -= bcan * 64;
		if(bcan >= 2){
			ei->evscore -= bcan * 96;
		}
	}
	if(bup >= bcan){
		ei->evscore += rcan * 64;
		if(rcan >= 2){
			ei->evscore += rcan * 96;
		}
	}

	// fen 9/3kaP3/b4a3/9/6b2/9/9/4BK2B/1p1p5/5A3 w - - 0 111
	// 一方的兵全在将在的下面. 另一方有兵或有相. 


	//ei->rcan = (uint8)(rcan);
	//ei->bcan = (uint8)(bcan);

	// 对方将上有仕要加分
	//if(StoX(yk) == 0x3){
	//	if(PB90(MY_SQ15) == your_shi){
	//		MY_EV_ADD(96);
	//	}
	//	else{
	//		MY_EV_SUB(64);
	//	}
	//}
	//if(StoX(yk) == 0x5){
	//	if(PB90(MY_SQ17) == your_shi){
	//		MY_EV_ADD(96);
	//	}
	//	else{
	//		MY_EV_SUB(64);
	//	}
	//}
	//if(StoX(mk) == StoX(yk)){
	//	MY_EV_ADD(64);
	//}
}

bool getBetweenSq(const typePOS *POSITION, int sq1, int sq2, int& mid){

	if(StoX(sq1) == StoX(sq2) || StoY(sq1) == StoY(sq2)){
		Bitboard bet = m_and(BetweenBB[sq1][sq2],BitboardOCC);
		if(count_1s(bet) == 1){
			mid = pop_1st_bit(&bet);
			return TRUE;
		}
	}
   return FALSE;
} 

// 是不是给车牵制了
bool isStringByChe(const typePOS *POSITION,int sq1,int mid, int sq2){
	Bitboard peat = pao_eat_attacks_bb(sq1,BitboardOCC);
	if(bit_is_set(peat,sq2)){
		peat = m_and(BetweenBB[sq1][sq2],BitboardOCC);
		if(pop_1st_bit(&peat) == (Square)mid){
			return TRUE;
		}
	}
	return FALSE;
}

// 是不是给炮牵制了
bool isStringByPao(const typePOS *POSITION,int pao,int sq3, int sq4){
	
	Bitboard paoatt = pao_super_attacks_bb(pao,BitboardOCC);
	if(bit_is_set(paoatt,sq4)){
		paoatt = m_and(BetweenBB[pao][sq4],
			m_and(pao_eat_attacks_bb(pao,BitboardOCC),BitboardOCC));
		if(pop_1st_bit(&paoatt) == (Square)sq3){
			return TRUE;
		}
	}
	return FALSE;
}


