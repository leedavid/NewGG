#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else

#ifdef USE_MA_KONG_KING

static const char _MaKing[90] = {
	0,   0,   0,   3,   0,   3,   0,   0,   0,   
	0,   0,   0,   4,   2,   4,   0,   0,   0,  
	0,   0,   0,   6,   8,   6,   0,   0,   0,    
	0,   0,   0,   0,   0,   0,   0,   0,   0,   
	0,   0,   0,   0,   0,   0,   0,   0,   0,   
	0,   0,   0,   0,   0,   0,   0,   0,   0,   
	0,   0,   0,   0,   0,   0,   0,   0,   0,   
	0,   0,   0,   6,   8,   6,   0,   0,   0,   
	0,   0,   0,   4,   2,   4,   0,   0,   0,   
	0,   0,   0,   3,   0,   3,   0,   0,   0,   	
};

void init_MaKongKing(){
	                            //0 1,2,3,4,0
	const uint8 att_by_kcan[] = { 6,4,2,1,0,0 };
	const uint8 ma_can_check  = 2;              //马能将军时加的点
	const uint8 sameside      = 2;
	const uint8 wocaoma       = 6;
	for(int ma = 0; ma < 90; ma++){
		for(int k = 0; k < 90; k++){
			MaKongKing[ma][k] = 0;
			uint8 att = 0;
			Bitboard occ = _mm_setzero_si128();
			if(ABS(StoX(ma) - StoX(k)) <= 4 && ABS(StoY(ma) - StoY(k)) <= 4){				
				if(StoX(k) < 0x3 || StoX(k) > 0x5){
					continue;
				}
				if(StoY(k) > 0x2 && StoY(k) < 0x7){
					continue;
				}

				//if(ma == 0x46 && k == 0x4B){
				//	ma = ma;
				//}
				//if(ma == 0x19 && k == 0x0C){
				//	ma = ma;
				//}

				// 必须是马可攻击才能算有哇
				att += _MaKing[k];
				// isSameSide?
				if(IsOnSameSide(ma,k) && StoX(k) != 0x4){
					att += sameside;
				}
				// isCanCheck
				Bitboard ktm = king_to_ma_attacks_bb(k,occ);
				Bitboard mtk = ma_to_king_attacks_bb(ma,occ);
				if(m128_is_have_bit(m_and(ktm,mtk))){
					att += ma_can_check;
				}

				Bitboard kcan = _mm_setzero_si128();
				// king 的走步
				if(StoY(k) <= 0x2){
					kcan = OneBpawnOrBking_AttackBB[k];
				}
				if(StoY(k) >= 0x7){
					kcan = OneRpawnOrRking_AttackBB[k];
				}
				kcan = _mm_andnot_si128(mtk,kcan);
				int can = count_1s(kcan);
				att += att_by_kcan[can];

				// 特殊的，卧马要加
				if(k == 0x54 || k == 0x56){
					if(ma == 0x4A || ma == 0x4E){
						att += wocaoma;
					}
				}
				// 特殊的，卧马要加
				if(k == 0x03 || k == 0x05){
					if(ma == 0x0B || ma == 0x0F){
						att += wocaoma;
					}
				}
			} 
			MaKongKing[ma][k] = att;
		}
	}
}

//#define my_pawn_k_attacks(sq)      OneRpawnOrRking_AttackBB[sq]
//#define your_pawn_k_attacks(sq)    OneBpawnOrBking_AttackBB[sq]

#endif

#endif