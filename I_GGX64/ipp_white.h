#include "annul_define.h"

#define MyPVNodeSMP  	    WhitePVNodeSMP
#define OppPVNodeSMP 	    BlackPVNodeSMP
#define MyAllSMP 		    WhiteAllSMP
#define OppAllSMP 		    BlackAllSMP
#define MyCutSMP		    WhiteCutSMP
#define OppCutSMP 		    BlackCutSMP

#define MyMultiPV 			WhiteMultiPV

#define MyPVQsearch 		PVQsearchWhite
#define MyPVQsearchCheck 	PVQsearchWhiteCheck
#define MyPVQsearchEvasion 	PVQsearchWhiteEvasion

#define MyQsearch 			QsearchWhite
#define MyQsearchCheck 		QsearchWhiteCheck
#define MyQsearchEvasion 	QsearchWhiteEvasion

#define MyLowDepth 			LowDepthWhite
#define MyLowDepthCheck 	LowDepthWhiteCheck
#define MyLowDepthEvasion   LowDepthWhiteEvasion

#define MyExclude 			ExcludeWhite
#define MyExcludeCheck 		ExcludeWhiteCheck
#define MyExcludeEvasion    ExcludeWhiteEvasion

#define MyCut 				CutNodeWhite
#define MyCutCheck 			CutNodeWhiteCheck
#define MyCutEvasion 		CutNodeWhiteEvasion

#define MyAll 				AllNodeWhite
#define MyAllCheck 			AllNodeWhiteCheck
#define MyAllEvasion 		AllNodeWhiteEvasion

#define MyPV 				PVNodeWhite
#define MyRootNode 			RootWhite
#define MyAnalysis 			WhiteAnalysis
#define MyTop 				TopWhite
#define MyTopAnalysis       WhiteTopAnalysis

#define MyAttacked   POSITION->DYN->attack_white // mio_attaco POSITION->DYN->attack_white
#define OppAttacked  POSITION->DYN->attack_black // tuo_attaco POSITION->DYN->attack_black

#define my_king_check    POSITION->DYN->white_king_check

#define myIsLegalEvasionMove WhiteIsLegalEvasionMove

#define my_che_num    POSITION->pieceCount[RCHE]
#define my_ma_num     POSITION->pieceCount[RMA]
#define my_pao_num    POSITION->pieceCount[RPAO]
#define my_pawn_num   POSITION->pieceCount[RPAWN]
#define my_xiang_num  POSITION->pieceCount[RXIANG]
#define my_shi_num    POSITION->pieceCount[RSHI]

#define your_che_num    POSITION->pieceCount[BCHE]
#define your_ma_num     POSITION->pieceCount[BMA]
#define your_pao_num    POSITION->pieceCount[BPAO]
#define your_pawn_num   POSITION->pieceCount[BPAWN]
#define your_xiang_num  POSITION->pieceCount[BXIANG]
#define your_shi_num    POSITION->pieceCount[BSHI]

#define EV_MY_CAN    ei->rcan
#define EV_YOUR_CAN  ei->bcan
#define EV_MY_SAFE   ei->rsafe
#define EV_YOUR_SAFE ei->bsafe

#define my_m_Rsf m_Rsf

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

#define my_m_Rsf m_Rsf
#define my_m_Lsf  m_Lsf

#define my_pawn_add_9(to)  (to+9)    // FROM
#define my_pawn_sub_9(to)  (to-9)
#define my_guo_he_pawn(bb)  m_and(bb,_mm_load_si128((__m128i*)RpawnOverBB))


#define my_king_pos   RKpos() // POSITION->nero_re_quadretto
#define your_king_pos BKpos() // POSITION->bianco_re_quadretto

#define my_attack_by_pawn(sq)      Attack_By_Rpawn_Rking[sq]
#define your_attack_by_pawn(sq)    Attack_By_Bpawn_Bking[sq]
#define my_pawn_k_attacks(sq)      OneRpawnOrRking_AttackBB[sq]
#define your_pawn_k_attacks(sq)    OneBpawnOrBking_AttackBB[sq]

#define MyLastRankPawnBB           Rank0BB
#define MyUpBB                     UpBB
#define MyLowBB                    LowBB

#define OppPVQsearch 				PVQsearchBlack
#define OppPVQsearchCheck 			PVQsearchBlackCheck
#define OppPVQsearchEvasion 		PVQsearchBlackEvasion

#define OppQsearch 					QsearchBlack
#define OppQsearchCheck 			QsearchBlackCheck
#define OppQsearchEvasion 			QsearchBlackEvasion

#define OppLowDepth 				LowDepthBlack
#define OppLowDepthCheck 			LowDepthBlackCheck
#define OppLowDepthEvasion          LowDepthBlackEvasion

#define OppExclude 					ExcludeBlack
#define OppExcludeCheck 			ExcludeBlackCheck
#define OppExcludeEvasion 			ExcludeBlackEvasion

#define OppCut 						CutNodeBlack
#define OppCutCheck 				CutNodeBlackCheck
#define OppCutEvasion 				CutNodeBlackEvasion

#define OppAll 						AllNodeBlack
#define OppAllCheck 				AllNodeBlackCheck
#define OppAllEvasion 				AllNodeBlackEvasion

#define OppPV 						PVNodeBlack
#define OppRootNode 				RootBlack
#define OppAnalysis 				BlackAnalysis
#define OppTop 						TopBlack
#define OppTopAnalysis 				BlackTopAnalysis

#define bitboard_your_pawn 		bitboard_black_pawn     //#define bitbordo_tuo_pedone bitboard_black_pawn     // bitbordo_nero_pedone
#define bitboard_your_shi   	bitboard_black_shi
#define bitboard_your_xiang   	bitboard_black_xiang
#define bitboard_your_ma    	bitboard_black_ma
#define bitboard_your_pao   	bitboard_black_pao
#define bitboard_your_che   	bitboard_black_che
#define bitboard_your_king   	bitboard_black_king

#define MyOccupied          bitboard_occ_white 
#define OppOccupied         bitboard_occ_black

#define bitboard_my_pawn 	bitboard_white_pawn //bitbordo_mio_pedone bitbordo_bianco_pedone
#define bitboard_my_shi   	bitboard_white_shi
#define bitboard_my_xiang  	bitboard_white_xiang
#define bitboard_my_ma    	bitboard_white_ma
#define bitboard_my_pao   	bitboard_white_pao
#define bitboard_my_che   	bitboard_white_che
#define bitboard_my_king   	bitboard_white_king

#define OppKingCheck        POSITION->DYN->black_king_check
#define MyCapture           WhiteCaptures

#define mio_cattura_not_include_pawn_king cattura_not_include_pawn_king_white

#define MyOrdinary          WhiteOrdinary
#define MyPositionalGain 	PositionalMovesWhite
#define MyEvasion 			WhiteEvasions
#define MyQuietChecks 		QuietChecksWhite
#define MySEE				WhiteSEE
#define MAKE 				MakeWhite
#define UNDO 				UndoWhite
#define ILLEGAL_MOVE 		MOVE_IS_CHECK_WHITE  //  mossa_illegale  move_white_in_check
#define MOVE_IS_CHECK 		MOVE_IS_CHECK_BLACK  // mossa_scacco

#define MyOK 				WhiteOK
#define MyNext 				NextWhite
#define MyNull 				((POSITION->DYN->flags)&2)

#define MyXRAY   			(POSITION->DYN->white_xray)   // (POSITION->DYN->bianco_xray)
#define OppXRAY             (POSITION->DYN->black_xray)   // (POSITION->DYN->nero_xray)

#define MyXPaoNull          (POSITION->DYN->white_pao_null)
#define OppXPaoNull         (POSITION->DYN->black_pao_null)

#define MyXrayTable         xray_white_list
#define OppXrayTable        xray_black_list

#define MyKingCheck         POSITION->DYN->white_king_check   // bianco_re_scacco
#define IN_CHECK 		    WHITE_IN_CHECK

#define PIECE_IS_MINE       PIECE_WHITE
#define PIECE_IS_OPP        PIECE_BLACK

#define MY_EV_ADD(val) (ei->evscore+=(val))
#define MY_EV_SUB(val) (ei->evscore-=(val))

//#include "endgame/end_white_common_fun.h"

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

