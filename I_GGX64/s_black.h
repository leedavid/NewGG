
//#define MyAttacked   POSITION.DYN->attack_black // mio_attaco POSITION.DYN->attack_white
//#define OppAttacked  POSITION.DYN->attack_white

#define myIsLegalEvasionMove BlackIsLegalEvasionMove

#define my_che_num    POSITION.piece_count(BCHE)
#define my_ma_num     POSITION.piece_count(BMA)
#define my_pao_num    POSITION.piece_count(BPAO)
#define my_pawn_num   POSITION.piece_count(BPAWN)
#define my_xiang_num  POSITION.piece_count(BXIANG)
#define my_shi_num    POSITION.piece_count(BSHI)

#define your_che_num    POSITION.piece_count(RCHE)
#define your_ma_num     POSITION.piece_count(RMA)
#define your_pao_num    POSITION.piece_count(RPAO)
#define your_pawn_num   POSITION.piece_count(RPAWN)
#define your_xiang_num  POSITION.piece_count(RXIANG)
#define your_shi_num    POSITION.piece_count(RSHI)

#define EV_YOUR_XBIT ei.xray_bit[WHITE]
#define EV_MY_XBIT   ei.xray_bit[BLACK]

#define EV_MY_CAN    ei.bcan
#define EV_YOUR_CAN  ei.rcan
#define EV_MY_SAFE   ei.bsafe
#define EV_YOUR_SAFE ei.rsafe
//static const  Piece COLOR_BY_SIDE_ADD[2] = { EMPTY, _X_X }; 
#define MY_ATTACK      ei.attackedBy[_X_X]
#define YOUR_ATTACK    ei.attackedBy[EMPTY]

#define MY_SAFE_BIT      ei.SafeBit[BLACK]
#define YOUR_SAFE_BIT    ei.SafeBit[WHITE]

#define my_m_Rsf m_Lsf
#define my_m_Lsf  m_Rsf

#define my_che    BCHE
#define my_ma     BMA
#define my_pao    BPAO
#define my_pawn   BPAWN
#define my_xiang  BXIANG
#define my_shi    BSHI
#define my_king   BKING

#define your_che    RCHE
#define your_ma     RMA
#define your_pao    RPAO
#define your_pawn   RPAWN
#define your_xiang  RXIANG
#define your_shi    RSHI
#define your_king   RKING

#define my_m_Rsf 		m_Lsf
#define my_pawn_add_9(to)  		(to-9)
#define my_pawn_sub_9(to)       (to+9)
#define my_guo_he_pawn(bb)  	m_and(bb,_mm_load_si128((__m128i*)BpawnOverBB))

#define my_king_pos   			BKpos() // POSITION.nero_re_quadretto
#define your_king_pos 			RKpos() // POSITION.bianco_re_quadretto

#define my_attack_by_pawn(sq)      Attack_By_Bpawn_Bking[sq]
#define my_pawn_k_attacks(sq)      OneBpawnOrBking_AttackBB[sq]

#define your_attack_by_pawn(sq)    Attack_By_Rpawn_Rking[sq]
#define your_pawn_k_attacks(sq)    OneRpawnOrRking_AttackBB[sq]

//#define my_king_check    POSITION.DYN->black_king_check

#define bb_your_pawn 		bb_white_pawn      // bitbordo_bianco_pedone
#define bb_your_shi   	bb_white_shi
#define bb_your_xiang   	bb_white_xiang
#define bb_your_ma    	bb_white_ma
#define bb_your_pao   	bb_white_pao
#define bb_your_che   	bb_white_che
#define bb_your_king   	bb_white_king

#define MyOccupied        		bitboard_occ_black // mio_occupato bitbordo_occupato_nero
#define OppOccupied       		bitboard_occ_white

#define bb_my_pawn 	bb_black_pawn //bitbordo_mio_pedone bitbordo_bianco_pedone
#define bb_my_shi   	bb_black_shi
#define bb_my_xiang  	bb_black_xiang
#define bb_my_ma    	bb_black_ma
#define bb_my_pao   	bb_black_pao
#define bb_my_che   	bb_black_che
#define bb_my_king   	bb_black_king

#define MyCapture           BlackCaptures
#define MyHaveCapture       BlackHaveCaptures

#define mio_cattura_not_include_pawn_king cattura_not_include_pawn_king_black

#define MyOrdinary          BlackOrdinary
#define MyHaveOrdinary      BlackHaveOrdinary
//#define MyPositionalGain 	PositionalMovesWhite
#define MyEvasion 			BlackEvasions
#define MyHaveEvasion       BlackHaveEvasions
#define MyQuietChecks 		QuietChecksBlack

#define MyLastRankPawnBB    Rank9BB
#define MyUpBB              LowBB
#define MyLowBB             UpBB

#define  MY_COLOR           BLACK
#define  YOUR_COLOR         WHITE

#include "endgame\\end_black.h"

//#include "endgame\\end_black_common_fun.h"

#include "endgame\\black_mat1.h"
#include "endgame\\black_mat2.h"
#include "endgame\\black_mat3.h"
#include "endgame\\black_mat4.h"
#include "endgame\\black_mat5.h"
#include "endgame\\black_mat6.h"
#include "endgame\\black_mat7.h"
#include "endgame\\black_mat8.h"
#include "endgame\\black_mat9.h"

