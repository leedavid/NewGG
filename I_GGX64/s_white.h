#include "s_annul_define.h"


#define myIsLegalEvasionMove WhiteIsLegalEvasionMove

#define my_che_num      POSITION.piece_count(RCHE)
#define my_ma_num       POSITION.piece_count(RMA)
#define my_pao_num      POSITION.piece_count(RPAO)
#define my_pawn_num     POSITION.piece_count(RPAWN)
#define my_xiang_num    POSITION.piece_count(RXIANG)
#define my_shi_num      POSITION.piece_count(RSHI)

#define your_che_num    POSITION.piece_count(BCHE)
#define your_ma_num     POSITION.piece_count(BMA)
#define your_pao_num    POSITION.piece_count(BPAO)
#define your_pawn_num   POSITION.piece_count(BPAWN)
#define your_xiang_num  POSITION.piece_count(BXIANG)
#define your_shi_num    POSITION.piece_count(BSHI)

#define EV_YOUR_XBIT ei.xray_bit[BLACK]
#define EV_MY_XBIT   ei.xray_bit[WHITE]

#define EV_MY_CAN    ei.rcan
#define EV_YOUR_CAN  ei.bcan
#define EV_MY_SAFE   ei.rsafe
#define EV_YOUR_SAFE ei.bsafe

#define MY_ATTACK      ei.attackedBy[EMPTY]
#define YOUR_ATTACK    ei.attackedBy[_X_X]

#define MY_SAFE_BIT      ei.SafeBit[WHITE]
#define YOUR_SAFE_BIT    ei.SafeBit[BLACK]

#define my_che    RCHE
#define my_ma     RMA
#define my_pao    RPAO
#define my_pawn   RPAWN
#define my_xiang  RXIANG
#define my_shi    RSHI
#define my_king   RKING

#define your_che    BCHE
#define your_ma     BMA
#define your_pao    BPAO
#define your_pawn   BPAWN
#define your_xiang  BXIANG
#define your_shi    BSHI
#define your_king   BKING

#define my_m_Rsf  m_Rsf
#define my_m_Lsf  m_Lsf

#define my_pawn_add_9(to)  (to+9)    // FROM
#define my_pawn_sub_9(to)  (to-9)
#define my_guo_he_pawn(bb)  m_and(bb,_mm_load_si128((__m128i*)RpawnOverBB))


#define my_king_pos   RKpos() // POSITION.nero_re_quadretto
#define your_king_pos BKpos() // POSITION.bianco_re_quadretto

#define my_attack_by_pawn(sq)      Attack_By_Rpawn_Rking[sq]
#define your_attack_by_pawn(sq)    Attack_By_Bpawn_Bking[sq]
#define my_pawn_k_attacks(sq)      OneRpawnOrRking_AttackBB[sq]
#define your_pawn_k_attacks(sq)    OneBpawnOrBking_AttackBB[sq]

#define MyLastRankPawnBB           Rank0BB
#define MyUpBB                     UpBB
#define MyLowBB                    LowBB


#define bb_your_pawn 	bb_black_pawn     
#define bb_your_shi   	bb_black_shi
#define bb_your_xiang   bb_black_xiang
#define bb_your_ma    	bb_black_ma
#define bb_your_pao   	bb_black_pao
#define bb_your_che   	bb_black_che
#define bb_your_king   	bb_black_king

#define MyOccupied          bitboard_occ_white 
#define OppOccupied         bitboard_occ_black

#define bb_my_pawn 	bb_white_pawn 
#define bb_my_shi   	bb_white_shi
#define bb_my_xiang  	bb_white_xiang
#define bb_my_ma    	bb_white_ma
#define bb_my_pao   	bb_white_pao
#define bb_my_che   	bb_white_che
#define bb_my_king   	bb_white_king

#define MyCapture           WhiteCaptures
#define MyHaveCapture       WhiteHaveCaptures

#define mio_cattura_not_include_pawn_king cattura_not_include_pawn_king_white

#define MyOrdinary          WhiteOrdinary
#define MyHaveOrdinary      WhiteHaveOrdinary
#define MyEvasion 			WhiteEvasions
#define MyHaveEvasion       WhiteHaveEvasions
#define MyQuietChecks 		QuietChecksWhite

#define MY_EV_ADD(val) (ei.evscore += ((sint16)(val)))
#define MY_EV_SUB(val) (ei.evscore -= ((sint16)(val)))

#define  MY_COLOR           WHITE
#define  YOUR_COLOR         BLACK


#include "endgame/end_white.h"     
#include "endgame/white_mat1.h"
#include "endgame/white_mat2.h"
#include "endgame/white_mat3.h"
#include "endgame/white_mat4.h"
#include "endgame/white_mat5.h"
#include "endgame/white_mat6.h"
#include "endgame/white_mat7.h"
#include "endgame/white_mat8.h"
#include "endgame/white_mat9.h"

