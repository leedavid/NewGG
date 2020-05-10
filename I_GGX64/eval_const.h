#ifndef MY_EVAL_CONST_H_STOCKFISH
#define MY_EVAL_CONST_H_STOCKFISH


const Score r_CheMove[]  = {  // 左右移动
	Score(((-38) << 16) + (-38)),     //-38,
	Score(((-18) << 16) + (-18)),     //-18,
	Score(((-12) << 16) + (-18)),     //-18,
	Score(((- 8) << 16) + (-18)),     //-18,
	Score(((- 4) << 16) + (-18)),     //-18, 
	Score(0), 
	Score(0), 
	Score(0), 
	Score(0),
	Score(0),
	Score(0),
	Score(0),
}; 


const Score f_CheMove[]  = {  // 上下移动
	Score(((-42) << 16) + (-72)),     //-64,
	Score(((-28) << 16) + (-54)),     //-44,
	Score(((-26) << 16) + (-44)),     //-44,
	Score(((-24) << 16) + (-44)),     //-44, 
	Score(((-20) << 16) + (-24)),     //-24,
	Score(0), 
	Score(0),
	Score(0),
	Score(0),
	Score(0),
	Score(0), 
	Score(0),
};


//const  int ChefreeCheckPointY[] = {
//	// 00 01 02 03 04 05 06 07 08
//	0, 2, 4, 8,16,20,20,20,20,20,20,20,20,20,20,20,20,20
//};
//const  int ChefreeCheckPointX[] = {
//	// 00 01 02 03 04 05 06 07 08
//	0, 2, 3, 6, 8, 10,12,12,12,12,12,12,12,12,12,12,12,12
//};




const Score Point_MaMob[] = {
	//   0        1            2           3           4            5
	SMG(-48,-64), SMG(-8,-12), SMG(0,0),   SMG(8,8), SMG(8,8), SMG(8,8),
	//  6          7           8           9           10        11              
	SMG(8,8),     SMG(8,8),    SMG(12,12), SMG(12,12),SMG(12,12),SMG(12,12)
};

//extern int PAWN_NUM_OVER_RIVER_point[8];      //       point(t,t);



const Score PAWN_num_OVER_RIVER_point[6] = {
	//   0        1           2           3           4            5
	SMG(0,0), SMG(8,8), SMG(12,12), SMG(16,24), SMG(0,0), SMG(0,0)
};





#define CHE_OPEN_SUB_LINE                     4
// ===================================================================


#define Ma_KongPao_Check                      6       // 马到空炮将军

#define PaoCanAttackPoint                     4
#define PaoGuardtheKingOut                    3       //

#define PaoInPlaceMustSub                     6

#define TwoPaoAt_SameFile_Sub                 5

#define CheCanPaoNullCHeckPoint               6       // 车能垒将.

#define Pawn_Is_Bad                           4

#define MaCanAttackPoint                      3

#define CheOpenAtt                            6       // 车已开放后的攻击能力
#define CheCanCheck                           2
#define RookSafeCheckBonus                    4       //对方的车能自由将


#define Other_Che_Can_Not_back                4       //对方的车不能回家守卫
#define MaSafeCheckBonus                      6       //对方的马能自由将
#define Ma_Not_Good_Move_to_Attack            4       //马没有好的进攻步了
#define Che_At_mid_contor_King                8
		



#define Only_1Che1PaoxPawn_Your_pawnAlr_Pao_Not_Home  spoint(8, 32)
#define Only_1Che1PaoxPawn_Your_pawnCan_Pao_Not_Home  spoint(16,32)

#define Only_1Che1PaoxPawn_Your_pawnAlr_Pao_at_Home   spoint(16,32)
#define Only_1Che1PaoxPawn_Your_pawnCan_Pao_at_Home   spoint(16,32)

	const Score Only_1Che1PaoxPawn_Your_Ma_add[] = {
		Score(((118)  << 16)   + (148)),              // 00
		Score(((96)   << 16)   + (128)),              // 01
		Score(((64)   << 16)   + (96)),               // 02
		Score(((32)   << 16)   + (64)),               // 03
		Score(((0)    << 16)   + (0))                 // 04
	};



#endif