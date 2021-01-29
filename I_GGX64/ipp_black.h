#define MyPVNodeSMP  	    BlackPVNodeSMP
#define OppPVNodeSMP 	    WhitePVNodeSMP
#define MyAllSMP 		    BlackAllSMP
#define OppAllSMP 		    WhiteAllSMP
#define MyCutSMP		    BlackCutSMP
#define OppCutSMP 		    WhiteCutSMP

#define MyMultiPV 			BlackMultiPV

#define MyPVQsearch 		PVQsearchBlack
#define MyPVQsearchCheck 	PVQsearchBlackCheck
#define MyPVQsearchEvasion 	PVQsearchBlackEvasion

#define MyQsearch 		    QsearchBlack
#define MyQsearchCheck 		QsearchBlackCheck
#define MyQsearchEvasion    QsearchBlackEvasion

#define MyLowDepth 			LowDepthBlack
#define MyLowDepthCheck 	LowDepthBlackCheck
#define MyLowDepthEvasion   LowDepthBlackEvasion

#define MyExclude 			ExcludeBlack
#define MyExcludeCheck 		ExcludeBlackCheck
#define MyExcludeEvasion    ExcludeBlackEvasion

#define MyCut 				CutNodeBlack
#define MyCutCheck 			CutNodeBlackCheck
#define MyCutEvasion 	    CutNodeBlackEvasion

#define MyAll 				AllNodeBlack
#define MyAllCheck 			AllNodeBlackCheck
#define MyAllEvasion	    AllNodeBlackEvasion

#define MyPV 				PVNodeBlack
#define MyRootNode 			RootBlack

#define MyAnalysis 			BlackAnalysis
#define MyTop 				TopBlack
#define MyTopAnalysis       BlackTopAnalysis

#define MyAttacked   POSITION->DYN->attack_black // mio_attaco POSITION->DYN->attack_white
#define OppAttacked  POSITION->DYN->attack_white

#define myIsLegalEvasionMove BlackIsLegalEvasionMove

#define my_che_num    POSITION->pieceCount[BCHE]
#define my_ma_num     POSITION->pieceCount[BMA]
#define my_pao_num    POSITION->pieceCount[BPAO]
#define my_pawn_num   POSITION->pieceCount[BPAWN]
#define my_xiang_num  POSITION->pieceCount[BXIANG]
#define my_shi_num    POSITION->pieceCount[BSHI]

#define your_che_num    POSITION->pieceCount[RCHE]
#define your_ma_num     POSITION->pieceCount[RMA]
#define your_pao_num    POSITION->pieceCount[RPAO]
#define your_pawn_num   POSITION->pieceCount[RPAWN]
#define your_xiang_num  POSITION->pieceCount[RXIANG]
#define your_shi_num    POSITION->pieceCount[RSHI]

#define EV_MY_CAN    ei->bcan
#define EV_YOUR_CAN  ei->rcan
#define EV_MY_SAFE   ei->bsafe
#define EV_YOUR_SAFE ei->rsafe

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

#define my_king_pos   			BKpos() // POSITION->nero_re_quadretto
#define your_king_pos 			RKpos() // POSITION->bianco_re_quadretto

#define my_attack_by_pawn(sq)      Attack_By_Bpawn_Bking[sq]
#define my_pawn_k_attacks(sq)      OneBpawnOrBking_AttackBB[sq]

#define your_attack_by_pawn(sq)    Attack_By_Rpawn_Rking[sq]
#define your_pawn_k_attacks(sq)    OneRpawnOrRking_AttackBB[sq]

#define my_king_check    POSITION->DYN->black_king_check

#define OppPVQsearch 				PVQsearchWhite
#define OppPVQsearchCheck 			PVQsearchWhiteCheck
#define OppPVQsearchEvasion			PVQsearchWhiteEvasion

#define OppQsearch 					QsearchWhite
#define OppQsearchCheck 			QsearchWhiteCheck
#define OppQsearchEvasion		    QsearchWhiteEvasion

#define OppLowDepth 				LowDepthWhite
#define OppLowDepthCheck 			LowDepthWhiteCheck
#define OppLowDepthEvasion          LowDepthWhiteEvasion

#define OppExclude 					ExcludeWhite
#define OppExcludeCheck 			ExcludeWhiteCheck
#define OppExcludeEvasion 		    ExcludeWhiteEvasion

#define OppCut 						CutNodeWhite
#define OppCutCheck 				CutNodeWhiteCheck
#define OppCutEvasion 	    		CutNodeWhiteEvasion

#define OppAll 						AllNodeWhite
#define OppAllCheck 				AllNodeWhiteCheck
#define OppAllEvasion 		    	AllNodeWhiteEvasion

#define OppPV 						PVNodeWhite
#define OppRootNode 				RootWhite
#define OppAnalysis 				WhiteAnalysis
#define OppTop 						TopWhite
#define OppTopAnalysis 				WhiteTopAnalysis

#define bitboard_your_pawn 		bitboard_white_pawn      // bitbordo_bianco_pedone
#define bitboard_your_shi   	bitboard_white_shi
#define bitboard_your_xiang   	bitboard_white_xiang
#define bitboard_your_ma    	bitboard_white_ma
#define bitboard_your_pao   	bitboard_white_pao
#define bitboard_your_che   	bitboard_white_che
#define bitboard_your_king   	bitboard_white_king

#define MyOccupied        		bitboard_occ_black // mio_occupato bitbordo_occupato_nero
#define OppOccupied       		bitboard_occ_white

#define bitboard_my_pawn 	bitboard_black_pawn //bitbordo_mio_pedone bitbordo_bianco_pedone
#define bitboard_my_shi   	bitboard_black_shi
#define bitboard_my_xiang  	bitboard_black_xiang
#define bitboard_my_ma    	bitboard_black_ma
#define bitboard_my_pao   	bitboard_black_pao
#define bitboard_my_che   	bitboard_black_che
#define bitboard_my_king   	bitboard_black_king

#define MyLastRankPawnBB    Rank9BB
#define MyUpBB              LowBB
#define MyLowBB             UpBB

#define OppKingCheck        POSITION->DYN->white_king_check // tuo_re_scacco POSITION->DYN->bianco_re_scacco
#define MyCapture           BlackCaptures

#define mio_cattura_not_include_pawn_king cattura_not_include_pawn_king_black

#define MyOrdinary          BlackOrdinary
#define MyPositionalGain 	PositionalMovesBlack
#define MyEvasion 			BlackEvasions
#define MyQuietChecks 		QuietChecksBlack
#define MySEE				BlackSEE
#define MAKE 				MakeBlack
#define UNDO 				UndoBlack
#define ILLEGAL_MOVE 		MOVE_IS_CHECK_BLACK  //  mossa_illegale  move_white_in_check
#define MOVE_IS_CHECK 		MOVE_IS_CHECK_WHITE  // mossa_scacco

#define MyOK 				BlackOK
#define MyNext 				NextBlack
#define MyNull 				((POSITION->DYN->flags)&1)  // old is 1

#define MyXRAY   			(POSITION->DYN->black_xray)   // (POSITION->DYN->bianco_xray)
#define OppXRAY             (POSITION->DYN->white_xray)   // (POSITION->DYN->nero_xray)

#define MyXPaoNull          (POSITION->DYN->black_pao_null)
#define OppXPaoNull         (POSITION->DYN->white_pao_null)

#define MyXrayTable         xray_black_list
#define OppXrayTable        xray_white_list

#define MyKingCheck         POSITION->DYN->black_king_check   // bianco_re_scacco
#define IN_CHECK 		    BLACK_IN_CHECK

#define PIECE_IS_MINE       PIECE_BLACK
#define PIECE_IS_OPP        PIECE_WHITE

#include "endgame/end_black.h"

//#include "endgame/end_black_common_fun.h"

#include "endgame/black_mat1.h"
#include "endgame/black_mat2.h"
#include "endgame/black_mat3.h"
#include "endgame/black_mat4.h"
#include "endgame/black_mat5.h"
#include "endgame/black_mat6.h"
#include "endgame/black_mat7.h"
#include "endgame/black_mat8.h"
#include "endgame/black_mat9.h"

