#ifndef MY_EVAL_CONST_H_STOCKFISH
#define MY_EVAL_CONST_H_STOCKFISH





//const  int ChefreeCheckPointY[] = {
//	// 00 01 02 03 04 05 06 07 08
//	0, 2, 4, 8,16,20,20,20,20,20,20,20,20,20,20,20,20,20
//};
//const  int ChefreeCheckPointX[] = {
//	// 00 01 02 03 04 05 06 07 08
//	0, 2, 3, 6, 8, 10,12,12,12,12,12,12,12,12,12,12,12,12
//};









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





#endif