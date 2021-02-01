#include "chess.h"
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>

 Bitboard ShiAttackBB[90];                   // 双方的仕攻击到 90 的位棋盘


 Bitboard Attack_By_Rpawn_Rking[90];         // 所有可攻击到棋格的红兵, 红将 //兵是单向的
 Bitboard Attack_By_Bpawn_Bking[90];         // 所有可攻击到棋格的黑卒, 黑将


 Bitboard Ma_to_King_Mask[90];             //从马的位置,来吃将, 是算一下别脚
 Bitboard Ma_to_King_Attacks[NUM_MA_TO_KING_ATT];
 int      Ma_to_King_AttackIndex[90];

 Bitboard King_to_Ma_Mask[90];             //从将的位置,被马吃, 是算一下反别脚
 Bitboard King_to_Ma_Attacks[NUM_MA_TO_KING_ATT];
 int      King_to_Ma_AttackIndex[90];


 Bitboard XiangMask[90];               // 相,主要是用来算一下象眼,
 int      XiangAttackIndex[90];
 Bitboard XiangAttacks[NUM_XIANG_ATT];

 Bitboard SetMaskBB[90];                 
 Bitboard ClearMaskBB[90];


 Bitboard Che_Mask_FR[90];            // 车用来计算棋步的少最后一位,不包括自己
 Bitboard Che_Mask_F[90];             // 车FILE MASK, 不包括自己
 Bitboard Che_Mask_R[90];             // 车RANK MASK, 不包括自己

 Bitboard ChePseudoMask_FR[90];       //车可攻击的位,包括最后一位
 Bitboard Ma_Pseudo_Att[90];          // 马可能走到的所有位置

 Bitboard MaKingAttackZone[90];         // 棋子可攻击将的能力.
 Bitboard MaPosAttackKing[90];


 Bitboard Ma_good_mask[2];              // 白马不太好走的步子

 Bitboard CheAttacks_R[NUM_CHE_ATT_R];
 int      CheAttackIndex_R[90];

 Bitboard CheAttacks_F[NUM_CHE_ATT_F];
 int      CheAttackIndex_F[90];

 Bitboard Pao_Eat_Attacks_R[NUM_PAO_EAT_ATT_R];
 int      Pao_Eat_AttackIndex_R[90];

 Bitboard Pao_Eat_Attacks_F[NUM_PAO_EAT_ATT_F];
 int      Pao_Eat_AttackIndex_F[90];

 Bitboard PaoSUPER_R[NUM_PAO_SUPER_ATT_R];
 int      PaoSUPERIndex_R[90];

 Bitboard PaoSUPER_F[NUM_PAO_SUPER_ATT_F];
 int      PaoSUPERIndex_F[90];

 Bitboard FileBB_A[9];
 Bitboard RankBB_A[10];

 Bitboard LowBB[10];      //棋子下面的位棋盘
 Bitboard UpBB[10];       //棋子上面的位棋盘

 Bitboard LeftBB[9];      //棋子左边的位棋盘
 Bitboard RightBB[9];     //棋子右边的位棋盘

 Bitboard BetweenBB[90][90];          // 二个在同一线上的棋子之间的位棋盘．不包括自己的信息.

 // void print_bb(Bitboard bb){
 // 	printf("%s\n", "=========");
 // 	for (int row = 0; row < 10; row++)  {
 // 		for (int col = 0; col < 9; col++) {
 // 			int bit = row * 9 + col;
 // 			uint64_t occupied;
 // 			if (bit > 63) {
 // 				occupied = (bb[1] >> (bit - 64)) & 1;
 // 			} else {
 // 				occupied = (bb[0] >> bit) & 1;
 // 			}

 // 			if (occupied) {
 // 				printf("%s", "*");
 // 			} else {
 // 				printf("%s", "o");
 // 			}
 // 		}
 // 		printf("%s\n", "");
 // 		if (row == 4) {
 // 			printf("%s\n", "---------");
 // 		} 
 // 	}
 // 	printf("%s\n", "=========");
 // }

// const char BB_BDISPLAY_CHESS[3] = {"●"};

//将位棋盘打印出来
//将位棋盘打印出来
//void print_bb(Bitboard bb){
//
//	static const  char *c_BoardStrSim[] = {
//		"cmd:    0  1   2   3   4   5   6   7   8  \n",
//		"cmd: 0 ┌--┬--┬--┬--┬--┬--┬--┬--┐ \n",
//		"cmd:   │  │  │  │＼│／│  │  │  │ \n",
//		"cmd: 1 ├--┼--┼--┼--※--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │／│＼│  │  │  │ \n",
//		"cmd: 2 ├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 3 ├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 4 ├--┴--┴--┴--┴--┴--┴--┴--┤ \n",
//		"cmd:   │                              │ \n",
//		"cmd: 5 ├--┬--┬--┬--┬--┬--┬--┬--┤ \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 6 ├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 7 ├--┼--┼--┼--┼--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │＼│／│  │  │  │ \n",
//		"cmd: 8 ├--┼--┼--┼--※--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │／│＼│  │  │  │ \n",
//		"cmd: 9 └--┴--┴--┴--┴--┴--┴--┴--┘ \n"
//	};
//
//	char buf[256];
//	int r;
//	int f;
//
//	std::cout << "input Bitboard is: bb[1] = " << std::hex << bb.m128i_u64[1] 
//	          << ", bb[0] = " << std::hex << bb.m128i_u64[0] << std::endl;
//
//	std::cout << c_BoardStrSim[0] << std::endl;
//
//	for(r = 1; r < 20; r++){
//		sprintf_s(buf,256,c_BoardStrSim[r]);
//		if((r-1)%2 == 0){
//			for(f = 0; f < 9; f++){
//				if(bit_is_set(bb,XYtoS(f,(r-1)/2))){
//					buf[f*4+1+6] = BB_BDISPLAY_CHESS[0];
//					buf[f*4+2+6] = BB_BDISPLAY_CHESS[1];
//				}
//			}
//		}
//		std::cout << buf;
//	}
//	std::cout << std::dec << std::endl;
//}


// 根据棋盘,得到位棋盘
//void qibanToBB(Bitboard* bb){
//
//	int r;
//	int f;
//	static const  char *c_BoardStrSim[] = {
//		"cmd:    0  1   2   3   4   5   6   7   8  \n",
//		"cmd: 0 ●--●--●--●--●--●--●--●--● \n",
//		"cmd:   │  │  │  │＼│／│  │  │  │ \n",
//		"cmd: 1 ├--┼--┼--┼--※--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │／│＼│  │  │  │ \n",
//		"cmd: 2 ├--●--┼--┼--┼--┼--┼--●--┤ \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 3 ●--┼--●--┼--●--┼--●--┼--● \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 4 ├--┴--┴--┴--┴--┴--┴--┴--┤ \n",
//		"cmd:   │                              │ \n",
//		"cmd: 5 ├--┬--┬--┬--┬--┬--┬--┬--┤ \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 6 ●--┼--●--┼--●--┼--●--┼--● \n",
//		"cmd:   │  │  │  │  │  │  │  │  │ \n",
//		"cmd: 7 ├--●--┼--┼--┼--┼--┼--●--┤ \n",
//		"cmd:   │  │  │  │＼│／│  │  │  │ \n",
//		"cmd: 8 ├--┼--┼--┼--※--┼--┼--┼--┤ \n",
//		"cmd:   │  │  │  │／│＼│  │  │  │ \n",
//		"cmd: 9 ●--●--●--●--●--●--●--●--● \n"
//	};
//
//	*bb = _mm_setzero_si128();
//
//	for(r = 1; r < 20; r++){
//		if((r-1)%2 == 0){
//			for(f = 0; f < 9; f++){
//				if(c_BoardStrSim[r][f*4+1+6] == BB_BDISPLAY_CHESS[0] 
//				   && c_BoardStrSim[r][f*4+2+6] == BB_BDISPLAY_CHESS[1]){
//					set_bit(*bb,XYtoS(f,(r-1)/2));
//				}
//			}
//		}
//	}
//}

void initLeftRightBB(void){

	int i,j;

	for(i = 0; i < 9; i++){
	
		LeftBB[i]    =  _mm_setzero_si128(); 
		RightBB[i]   =  _mm_setzero_si128(); 

		for(j = 0; j < i; j++){				
			LeftBB[i] = m_or(LeftBB[i], FileBB_A[j]);	
		}

		for(j = i+1; j < 9; j++){
			RightBB[i] = m_or(RightBB[i],FileBB_A[j]);	
		}
	}
}

void initLowUpBB(void){
	int i;
	int j;
	for(i = 0; i < 10; i++){

		UpBB[i] = LowBB[i] = _mm_setzero_si128();

		for(j = 0; j < i; j++){
			UpBB[i] = m_or(UpBB[i],RankBB_A[j]);
		}

		for(j = 0; j <(9-i); j++){
			LowBB[i] = m_or(LowBB[i],RankBB_A[9-j]);
		}
	}
}

// 得到车的攻击位棋盘
void find_che_mask(Bitboard* result,Bitboard* result_f, Bitboard* result_r, int sq){

	int r,f;
	int rk = StoY(sq);
	int fl = StoX(sq);	

	*result = *result_f = *result_r = _mm_setzero_si128(); 

	//向上
	for(r = rk+1; r <= 8; r++){
       set_bit(*result,XYtoS(fl,r));
	   set_bit(*result_f,XYtoS(fl,r));
	}
	//向下
	for(r = rk-1; r >= 1; r--){
		set_bit(*result,XYtoS(fl,r));
		set_bit(*result_f,XYtoS(fl,r));
	}
	//向右
	for(f = fl+1; f <= 7; f++){
		set_bit(*result,XYtoS(f,rk));
		set_bit(*result_r,XYtoS(f,rk));
	}
	//向左
	for(f = fl-1; f >= 1; f--){
		set_bit(*result,XYtoS(f,rk));
		set_bit(*result_r,XYtoS(f,rk));
	}
}

void isMaJumpGood(int x, int y, Bitboard* result ){
    //跳到边线的马都不是好马

	if(x == 0 || x == 8) return ;
	//if(y == 0 || y == 9) return ;

	if(XYtoS(x,y) == 13 || XYtoS(x,y) == 76) return ;

	set_bit(*result,XYtoS(x,y));
}

void Init_Ma_Pseudo_Good_Mask(Bitboard* all, int sq){

	int rk = StoY(sq);
	int fl = StoX(sq);	

	*all = _mm_setzero_si128(); 

	//马的8个方向,1,上左
	if(rk >= 2 && fl >= 1){
		set_bit(*all,XYtoS(fl-1,rk-2));
		
	}
	//马的8个方向,1,上右
	if(rk >= 2 && fl <= 7){
		set_bit(*all,XYtoS(fl+1,rk-2));
		
	}

	//马的8个方向,1,右上
	if(rk >= 1 && fl <= 6){
		set_bit(*all,XYtoS(fl+2,rk-1));		
	}

	//马的8个方向,1,右下
	if(rk <= 8 && fl <= 6){
		set_bit(*all,XYtoS(fl+2,rk+1));
		
	}

	//马的8个方向,1,下右
	if(rk <= 7 && fl <= 7){
		set_bit(*all,XYtoS(fl+1,rk+2));
		
	}

	//马的8个方向,1,下左
	if(rk <= 7 && fl >= 1){
		set_bit(*all,XYtoS(fl-1,rk+2));
		
	}

	//马的8个方向,1,左下
	if(rk <= 8 && fl >= 2){
		set_bit(*all,XYtoS(fl-2,rk+1));
		
	}

	//马的8个方向,1,左上
	if(rk >= 1 && fl >= 2){
		set_bit(*all,XYtoS(fl-2,rk-1));
		
	}	
}

void find_ma_to_king_mask(Bitboard* result,int sq){
    
	int rk = StoY(sq);
	int fl = StoX(sq);
	*result = _mm_setzero_si128(); 

	if(rk >= 2){ //马可不可以向上
       set_bit(*result,XYtoS(fl,rk-1));
	}

	if(rk <= 7){ //马可不可以向下
       set_bit(*result,XYtoS(fl,rk+1));
	}

	if(fl >= 2){
		set_bit(*result,XYtoS(fl-1,rk));
	}

	if(fl <= 6){
		set_bit(*result,XYtoS(fl+1,rk));
	}
	//还可以再优化一下,把边角的MASK再去了.
}

// 这个是从King的角度,看有马能不能吃到
void find_king_to_ma_mask(Bitboard* result,int sq){

	int rk = StoY(sq);
	int fl = StoX(sq);	

	*result = _mm_setzero_si128(); 	

    if(rk <= 8 && fl <= 7) set_bit(*result,XYtoS(fl+1,rk+1));
	if(rk <= 8 && fl >= 1) set_bit(*result,XYtoS(fl-1,rk+1));
	if(rk >= 1 && fl <= 7) set_bit(*result,XYtoS(fl+1,rk-1));
	if(rk >= 1 && fl >= 1) set_bit(*result,XYtoS(fl-1,rk-1));
}

void find_xiang_mask(Bitboard* result,int sq){

	*result = _mm_setzero_si128(); 

	if(sq == 2){
		set_bit(*result,10);
		set_bit(*result,12);
	}
	if(sq == 6){
		set_bit(*result,14);
		set_bit(*result,16);
	}
	if(sq == 18){
		set_bit(*result,10);
		set_bit(*result,28);
	}
	if(sq == 22){
		set_bit(*result,12);
		set_bit(*result,14);
		set_bit(*result,30);
		set_bit(*result,32);
	}
	if(sq == 26){
		set_bit(*result,16);
		set_bit(*result,34);
	}
	if(sq == 38){
		set_bit(*result,28);
		set_bit(*result,30);
	}
	if(sq == 42){
		set_bit(*result,32);
		set_bit(*result,34);
	}

	//
	if(sq == 47){
		set_bit(*result,55);
		set_bit(*result,57);
	}

	if(sq == 51){
		set_bit(*result,59);
		set_bit(*result,61);
	}

	if(sq == 63){
		set_bit(*result,55);
		set_bit(*result,73);
	}

	if(sq == 67){
		set_bit(*result,57);
		set_bit(*result,59);
		set_bit(*result,75);
		set_bit(*result,77);
	}

	if(sq == 71){
		set_bit(*result,61);
		set_bit(*result,79);
	}

	if(sq == 83){
		set_bit(*result,73);
		set_bit(*result,75);
	}

	if(sq == 87){
		set_bit(*result,77);
		set_bit(*result,79);
	}
}
void find_che_pseudo_mask(Bitboard* result, int sq){
	
	int r,f;
	int rk = StoY(sq);
	int fl = StoX(sq);

	*result = _mm_setzero_si128(); 

	//放上自己
	set_bit(*result,sq);

	//向上
	for(r = rk+1; r <= 9; r++){
       set_bit(*result,XYtoS(fl,r));
	}
	//向下
	for(r = rk-1; r >= 0; r--){
		set_bit(*result,XYtoS(fl,r));
	}
	//向右
	for(f = fl+1; f <= 8; f++){
		set_bit(*result,XYtoS(f,rk));
	}
	//向左
	for(f = fl-1; f >= 0; f--){
		set_bit(*result,XYtoS(f,rk));
	}	
}

// 找到仕的可攻击位棋盘, 仕是双向的,不用分开判断
void find_stepshi_attack(Bitboard* result, int sq){

	*result = _mm_setzero_si128(); 

	if(sq == 3){
		set_bit(*result,13);
	}
	if(sq == 5){
		set_bit(*result,13);     //
	}
	if(sq == 13){
		set_bit(*result,3);
		set_bit(*result,5);
		set_bit(*result,21);
		set_bit(*result,23);
	}
	if(sq == 21){
		set_bit(*result,13);
	}
	if(sq == 23){
		set_bit(*result,13);
	}

	if(sq == 66){
		set_bit(*result,76);
	}
	if(sq == 68){
		set_bit(*result,76);
	}
	if(sq == 76){
		set_bit(*result,66);
		set_bit(*result,68);
		set_bit(*result,84);
		set_bit(*result,86);
	}
	if(sq == 84){
		set_bit(*result,76);
	}
	if(sq == 86){
		set_bit(*result,76);
	}
}

// Bitboard StepKingToPawnBB[90];  从将的位置看有没有兵在将军
void find_stepking_to_pawn(Bitboard* result,int sq){

	int rk = StoY(sq);
	int fl = StoX(sq);

	if(fl >= 3 && fl <= 5){
		if(rk <= 2){
			set_bit(*result,sq-1);
			set_bit(*result,sq+1);
			set_bit(*result,sq+9);
		}
		if(rk >= 7){
			set_bit(*result,sq-1);
			set_bit(*result,sq+1);
			set_bit(*result,sq-9);
		}
	}
}

// find_sq_attack_by_pawn(BB_Attack_By_Rpawn[sq],BB_Attack_By_Bpawn[sq],sq);
void find_sq_attack_by_pawn(Bitboard* byrpawn,Bitboard* bybpawn,int sq){	

	int x = StoX(sq);
	int y = StoY(sq);

	*byrpawn = *bybpawn = _mm_setzero_si128(); 

	if(y <= 5){
		set_bit(*byrpawn,XYtoS(x,y+1));
	}
	if(y >= 4){
		set_bit(*bybpawn,XYtoS(x,y-1));
	}

	if(y <= 4){
		if(x >= 1){
			set_bit(*byrpawn,sq-1);
		}
		if(x <= 7){
			set_bit(*byrpawn,sq+1);
		}
	}

	if(y >= 5){
		if(x >= 1){
			set_bit(*bybpawn,sq-1);
		}
		if(x <= 7){
			set_bit(*bybpawn,sq+1);
		}
	}

	if(x >= 3 && x <= 5){
		//红将
		if(y >= 7){
			if(y >= 8){
				set_bit(*byrpawn,XYtoS(x,y-1));
			}
			if(y <= 8){
				set_bit(*byrpawn,XYtoS(x,y+1));
			}
			if(x >= 4){
				set_bit(*byrpawn,XYtoS(x-1,y));
			}
			if(x <= 4){
				set_bit(*byrpawn,XYtoS(x+1,y));
			}
		}

		//黑将
		if(y <= 2){
			if(y >= 1){
				set_bit(*bybpawn,XYtoS(x,y-1));
			}
			if(y <= 1){
				set_bit(*bybpawn,XYtoS(x,y+1));
			}
			if(x >= 4){
				set_bit(*bybpawn,XYtoS(x-1,y));
			}
			if(x <= 4){
				set_bit(*bybpawn,XYtoS(x+1,y));
			}
		}
	}
}


// 红将红兵攻击其它的子的情况
void find_step_rking_rpawn_attack(Bitboard* result,int sq){

	int x = StoX(sq);
	int y = StoY(sq);

	*result = _mm_setzero_si128();

	//红兵
	if(y == 6 || y == 5){  // 红兵还没有过河
		set_bit(*result,XYtoS(x,y-1));  //只能向前
	}

	if(y <= 4){            // 红兵过河了
		if(y != 0){
			set_bit(*result,XYtoS(x,y-1));  //向前
		}
		if(x != 0){
			set_bit(*result,XYtoS(x-1,y));   //向左
		}
		if(x != 8){
			set_bit(*result,XYtoS(x+1,y));   //向右
		}
	}

	//红将
	if(y >= 7){
		if(y >= 8){
			set_bit(*result,XYtoS(x,y-1));  //向前
		}
		if(y <= 8){
			set_bit(*result,XYtoS(x,y+1));  //向下
		}
		if(x >= 4){
			set_bit(*result,XYtoS(x-1,y));  //向左
		}
		if(x <= 4){
			set_bit(*result,XYtoS(x+1,y));  //向右
		}
	}

}
// 黑将黑兵
void find_step_bking_bpawn_attack(Bitboard* result,int sq){

	int x = StoX(sq);
	int y = StoY(sq);

	*result = _mm_setzero_si128();

	//黑兵
	if(y == 4 || y == 3){  // 黑兵还没有过河
		set_bit(*result,XYtoS(x,y+1));  //只能向前
	}

	if(y >= 5){            // 红兵过河了
		if(y != 9){
			set_bit(*result,XYtoS(x,y+1));  //向前
		}
		if(x != 0){
			set_bit(*result,XYtoS(x-1,y));   //向左
		}
		if(x != 8){
			set_bit(*result,XYtoS(x+1,y));   //向右
		}
	}

	//黑将
	if(y <= 2){
		if(y >= 1){
			set_bit(*result,XYtoS(x,y-1));  //向前
		}
		if(y <= 1){
			set_bit(*result,XYtoS(x,y+1));  //向下
		}
		if(x >= 4){
			set_bit(*result,XYtoS(x-1,y));  //向左
		}
		if(x <= 4){
			set_bit(*result,XYtoS(x+1,y));  //向右
		}
	}
}



void init_rool_attack_r(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

	int sq,j,k, index = 0;
	int n;
	Bitboard att;
	int tra;

	Bitboard b;

	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){
		attackIndex[sq] = index;  //攻击位棋盘的开始编号
		m = m_and(RankBB_A[StoY(sq)],mask[sq]);
		n = (int)count_1s(m);  //得到mask的位数6         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);		   
		   che_att_by_block_r(&att,sq,b);
		   tra = (int)transform_bba(b, mult[sq], 64 - shift);
		   attacks[index + tra] = att;
		}

		index += j;
	}

	ASSERT(index <= NUM_CHE_ATT_R);
}

void init_paoeat_attack_r(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

	int sq,j,k, index = 0;

	Bitboard b;
	int n;
	int tra;
	Bitboard att;

	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){
		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		m = m_and(RankBB_A[StoY(sq)],mask[sq]);

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);  // 1 << 7  = 

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);

		   
		   pao_eat_by_block_r(&att,sq,b);


		   tra = (int)transform_bba(b, mult[sq], 64 - shift);


		   attacks[index + tra] = att;

		}

		index += j;
	}

	ASSERT(index <= NUM_PAO_EAT_ATT_R);
}

void init_paoeat_attack_f(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

	int sq,j,k, index = 0;

	Bitboard b;

	Bitboard m;  //车要中另外算MASK

	int n,tra;
	Bitboard att;

	for(sq = 0; sq < 90; sq++){
		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		m = m_and(FileBB_A[StoX(sq)], mask[sq]);

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);

		   
		   pao_eat_by_block_f(&att,sq,b);

		   tra = (int)transform_bba(b, mult[sq], 64 - shift);

		   attacks[index + tra] = att;
		}

		index += j;
	}

	ASSERT(index <= NUM_PAO_EAT_ATT_F);
}

void init_rool_attack_f(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {
	int sq,j,k, index = 0;
	Bitboard b;
	Bitboard m;  //车要中另外算MASK
	int n,tra;
	Bitboard att;
	//Bitboard occ;
	for(sq = 0; sq < 90; sq++){
		attackIndex[sq] = index;  //攻击位棋盘的开始编号
		m = m_and(FileBB_A[StoX(sq)],mask[sq]);
		n = (int)count_1s(m);  //得到mask的位数6
		j = (1 << shift);
		//这个没有检测冲突, 要检测一下.
		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);		   
		   che_att_by_block_f(&att,sq,b);
		   tra = (int)transform_bba(b, mult[sq], 64 - shift);
		   attacks[index + tra] = att;	
		}
		index += j;
	}
	ASSERT(index <= NUM_CHE_ATT_F);
}

void init_paosuper_attack_f(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

	int sq,j,k, index = 0;
	Bitboard b;
	 Bitboard att;
	 int n,tra;
	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){
		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		//BB_from_BB(m,FileBB_A[StoX(sq)]);
		//m_and(m,mask[sq]);

		m = m_and(FileBB_A[StoX(sq)],mask[sq]);

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);		  
		   pao_super_by_block_f(&att,sq,b); //print_bb(att);
		   tra = (int)transform_bba(b, mult[sq], 64 - shift);
		   //m128_BB_from_BB(attacks[index + tra],att);
		   attacks[index + tra] = att;
		}
		index += j;
	}

	ASSERT(index <= NUM_PAO_SUPER_ATT_F);
}

void init_paosuper_attack_r(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

	int sq,j,k, index = 0;

	Bitboard b;
	int n, tra;
	Bitboard att;
	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){
		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		m = m_and(RankBB_A[StoY(sq)], mask[sq]);

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);

		   
		   pao_super_by_block_r(&att,sq,b);  //print_bb(b); print_bb(att);

		   tra = (int)transform_bba(b, mult[sq], 64 - shift);

		   //m128_BB_from_BB(attacks[index + tra],att);

		   attacks[index + tra] = att;
		}

		index += j;
	}

	ASSERT(index <= NUM_PAO_SUPER_ATT_R);
}


void init_xiang_attack(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

								
	int sq,j,k, index = 0;

	Bitboard b;
	Bitboard att;
	int n,tra;

	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){

		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		if((sq == 2 || sq == 6 || sq == 18 || sq == 22 || sq == 26
			|| sq == 38 || sq == 42
			|| sq == 47 || sq == 51 || sq == 63 || sq == 67 || sq == 71
			|| sq == 83 || sq == 87) == FALSE) {

				//m128_from_2u64(attacks[index + 0],0,0);
				attacks[index + 0] = _mm_setzero_si128();
				index++;
				continue;
		}

		//m128_BB_from_BB(m,mask[sq]);

		m = mask[sq];

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);

		   
		   xiang_att_by_block(&att,sq,b);

		   tra = (int)transform_bba(b, mult[sq], 64 - shift);

		   //m128_BB_from_BB(attacks[index + tra],att);

		   attacks[index + tra] = att;
		}

		index += j;
	}

	ASSERT(index <= NUM_XIANG_ATT);
}


void init_ma_to_king_attack(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

								
	int sq,j,k, index = 0;

	Bitboard b;
	 Bitboard att;
	 int n,tra;
	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){

		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		//m128_BB_from_BB(m,mask[sq]);

		m = mask[sq];

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);

		  
		   ma_to_king_att_by_block(&att,sq,b);

		   tra = (int)transform_bba(b, mult[sq], 64 - shift);

		   //m128_BB_from_BB(attacks[index + tra],att);

		   attacks[index + tra] = att;
		}

		index += j;
	}

	ASSERT(index <= NUM_MA_TO_KING_ATT);
}

void init_king_to_ma_attack(Bitboard attacks[],
                            int attackIndex[], Bitboard mask[],
                            const int shift, const uint64 mult[]) {

								
	int sq,j,k, index = 0;

	Bitboard b;
	int n,tra;
	Bitboard att;
	Bitboard m;  //车要中另外算MASK

	for(sq = 0; sq < 90; sq++){

		attackIndex[sq] = index;  //攻击位棋盘的开始编号

		//m128_BB_from_BB(m,mask[sq]);

		m = mask[sq];

		n = (int)count_1s(m);  //得到mask的位数6
         
		j = (1 << shift);

		for(k = 0; k < j; k++){
           index_to_Bitboard(&b,k,n,m);

		   
		   king_to_ma_att_by_block(&att,sq,b);

		   tra = (int)transform_bba(b, mult[sq], 64 - shift);

		   //m128_BB_from_BB(attacks[index + tra],att);

		   attacks[index + tra] = att;
		}

		index += j;
	}

	ASSERT(index <= NUM_KING_TO_MA_ATT);
}


void init_attack_bitboard(void){


	init_rool_attack_r(CheAttacks_R,CheAttackIndex_R,Che_Mask_FR,7,CHE_Mult_R);  //初始化车的攻击位棋盘
	init_rool_attack_f(CheAttacks_F,CheAttackIndex_F,Che_Mask_FR,8,CHE_Mult_F);  //初始化车的攻击位棋盘

	init_paoeat_attack_r(Pao_Eat_Attacks_R,Pao_Eat_AttackIndex_R,Che_Mask_FR,7,PAO_EAT_Mult_R);  //初始化炮吃子的攻击位棋盘
	init_paoeat_attack_f(Pao_Eat_Attacks_F,Pao_Eat_AttackIndex_F,Che_Mask_FR,8,PAO_EAT_Mult_F);  //初始化炮吃子的攻击位棋盘

	init_paosuper_attack_r(PaoSUPER_R,PaoSUPERIndex_R,Che_Mask_FR,7,PAO_SUPER_Mult_R);  //初始化超级炮的攻击位棋盘
	init_paosuper_attack_f(PaoSUPER_F,PaoSUPERIndex_F,Che_Mask_FR,8,PAO_SUPER_Mult_F);  //初始化超级炮的攻击位棋盘

	//////////////////////////////////////////////////////////////////////////

	init_xiang_attack(XiangAttacks,XiangAttackIndex,XiangMask,4,XIANG_Mult);  //初始化象的攻击位棋盘
	//////////////////////////////////////////////////////////////////////////

	init_ma_to_king_attack(Ma_to_King_Attacks,Ma_to_King_AttackIndex,Ma_to_King_Mask,4,Ma_to_King_Mult);  //初始化马到将的攻击位棋盘
	//////////////////////////////////////////////////////////////////////////
	
    init_king_to_ma_attack(King_to_Ma_Attacks,King_to_Ma_AttackIndex,King_to_Ma_Mask,4,King_to_Ma_Mult);  //初始化马到将的攻击位棋盘

}

//////////////////////////////////////////////////////////////////////////
/// 同一直线
 void init_BetweenBB(void){ //BetweenBB[90][90];          // 二个在同一线上的棋子之间的位棋盘．

	 int i,j,x,y;
	 int ix,iy,jx,jy;

	 //BetweenBB[90][90] 
	 for(i = 0; i < 90; i++){
		 for(j = 0; j < 90; j++){
			 BetweenBB[i][j] = _mm_setzero_si128 ();

			 ix = StoX(i);
			 iy = StoY(i);
			 jx = StoX(j);
			 jy = StoY(j);

			 if(ix == jx){
				 if(iy < jy){
					 for(y = iy + 1; y < jy; y++){
                         set_bit(BetweenBB[i][j],XYtoS(ix,y));
					 }
				 }
				 else{
					 for(y = iy - 1; y > jy; y--){
						 set_bit(BetweenBB[i][j],XYtoS(ix,y));
					 }
				 }
			 }
			 if(iy == jy){
				 if(ix < jx){
					 for(x = ix + 1; x < jx; x++){
						 set_bit(BetweenBB[i][j],XYtoS(x,iy)); //print_bb(BetweenBB[i][j]);
					 }
				 }
				 else{
					 for(x = ix - 1; x > jx; x--){
						 set_bit(BetweenBB[i][j],XYtoS(x,iy));
					 }
				 }
			 }
		 }
	 }
 }

//static 
void init_mask(){
	//Bitboard att;
	Bitboard btmp = _mm_setr_epi32(1,0,0,0);
	int s;
	int sq;
	init_bb_const();  //初始化数据.

	for(s = 0; s < 90; s++){  
		SetMaskBB[s] = btmp;

		ClearMaskBB[s] = m_not(btmp);
		m_Lsf(btmp,0x1);
	}


 	initLeftRightBB();
    initLowUpBB();
	init_BetweenBB(); //BetweenBB[90][90];          // 二个在同一线上的棋子之间的位棋盘．

	//
	for(sq = 0; sq < 90; sq++){
     	find_che_pseudo_mask(&ChePseudoMask_FR[sq],sq);
		find_che_mask(&Che_Mask_FR[sq],&Che_Mask_F[sq],&Che_Mask_R[sq],sq);	
		find_ma_to_king_mask(&Ma_to_King_Mask[sq],sq);
		find_king_to_ma_mask(&King_to_Ma_Mask[sq],sq);
		find_xiang_mask(&XiangMask[sq],sq);
		find_stepshi_attack(&ShiAttackBB[sq],sq);
		find_step_rking_rpawn_attack(&OneRpawnOrRking_AttackBB[sq],sq); //红将红兵
		find_step_bking_bpawn_attack(&OneBpawnOrBking_AttackBB[sq],sq); //黑将黑兵
		find_sq_attack_by_pawn(&Attack_By_Rpawn_Rking[sq],&Attack_By_Bpawn_Bking[sq],sq);		
		Init_Ma_Pseudo_Good_Mask(&Ma_Pseudo_Att[sq], sq);
	}	


	Ma_good_mask[WHITE] = _mm_setzero_si128();
	Ma_good_mask[BLACK] = _mm_setzero_si128();

	for(sq = 0; sq < 90; sq++){
		if(sq <= 0x2c){
			set_bit(Ma_good_mask[WHITE],sq);

			if(StoY(sq) == 0x0 || StoY(sq) == 0x1 || sq == 0x0d || sq == 0x09 || sq == 0x12 || sq == 0x11 || sq == 0x1a){
			}
			else{
				set_bit(Ma_good_mask[BLACK],sq);
			}
		}
		// fen rC2kab2/4a4/2c1b1nc1/p1p1n1p1p/3RC4/2P6/P5r1P/N3B4/9/1RBAKA1N1 w - - 0 1
		if(sq >= 0x2d){
			set_bit(Ma_good_mask[BLACK],sq);

			if(StoY(sq) == 0x9 || StoY(sq) == 0x8 || sq == 0x4c || sq == 0x3f || sq == 0x48 || sq == 0x50 || sq == 0x47){
			}
			else{
               set_bit(Ma_good_mask[WHITE],sq);
			}
		}
	}

	//print_bb(Black_Ma_good_mask);
	//print_bb(White_Ma_good_mask);
#ifndef NOT_USE_FIND_MUL		
    //找到磨术数字, 这个已找到.写入常数6669-8+-+----------------------
	find_mul(TRUE);
	//find_mul(FALSE);
#endif

	//初始化攻击位棋盘, 所有的有blocker的.
	init_attack_bitboard();
}

void init_bitboards(){
	init_mask();
};

Bitboard Position::ma_to_king_attacks_bb(Square sq, Bitboard& blockers){
	Bitboard bb = m_and(blockers,Ma_to_King_Mask[sq]);
	return Ma_to_King_Attacks[transform_bbm(bb,Ma_to_King_Mult[sq],64-4) + Ma_to_King_AttackIndex[sq]];
}

Bitboard Position::king_to_ma_attacks_bb(Square sq, Bitboard& blockers){
	Bitboard bb = m_and(blockers,King_to_Ma_Mask[sq]);
	return King_to_Ma_Attacks[transform_bbm(bb,King_to_Ma_Mult[sq],64-4) + King_to_Ma_AttackIndex[sq]];
}

Bitboard Position::xiang_attacks_bb(Square sq, Bitboard& blockers){
	Bitboard bb = m_and(blockers,XiangMask[sq]);
	return XiangAttacks[transform_bbm(bb,XIANG_Mult[sq],64-4) + XiangAttackIndex[sq]];
}

Bitboard Position::Rook_attacks_bb(Square sq, Bitboard& blockers){
	Bitboard rbb = m_and(blockers,Che_Mask_R[sq]);
	Bitboard fbb = m_and(blockers,Che_Mask_F[sq]);
	Bitboard ratt = CheAttacks_R[transform_bbm(rbb,CHE_Mult_R[sq],64-7) + CheAttackIndex_R[sq]];
	Bitboard fatt = CheAttacks_F[transform_bbm(fbb,CHE_Mult_F[sq],64-8) + CheAttackIndex_F[sq]];
	return _mm_or_si128(ratt,fatt);
}

Bitboard Position::Rook_attacks_bb_only_F(Square sq, Bitboard& blockers){
	Bitboard fbb = m_and(blockers, Che_Mask_F[sq]);
	return CheAttacks_F[transform_bbm(fbb, CHE_Mult_F[sq], 64-8) + CheAttackIndex_F[sq]];
}

Bitboard Position::Pao_Eat_bb(Square sq, Bitboard& blockers){
	Bitboard rbb = m_and(blockers,Che_Mask_R[sq]);
	Bitboard fbb = m_and(blockers,Che_Mask_F[sq]);
	Bitboard ratt = Pao_Eat_Attacks_R[transform_bbm(rbb,PAO_EAT_Mult_R[sq],64-7) + Pao_Eat_AttackIndex_R[sq]];   //print_bb(ratt);
	Bitboard fatt = Pao_Eat_Attacks_F[transform_bbm(fbb,PAO_EAT_Mult_F[sq],64-8) + Pao_Eat_AttackIndex_F[sq]];   //print_bb(fatt);
	return _mm_or_si128(ratt,fatt);
}

Bitboard Position::Pao_Super_bb(Square sq, Bitboard& blockers){
	Bitboard rbb = m_and(blockers,Che_Mask_R[sq]);
	Bitboard fbb = m_and(blockers,Che_Mask_F[sq]);
	Bitboard ratt = PaoSUPER_R[transform_bbm(rbb,PAO_SUPER_Mult_R[sq],64-7) + PaoSUPERIndex_R[sq]];
	Bitboard fatt = PaoSUPER_F[transform_bbm(fbb,PAO_SUPER_Mult_F[sq],64-8) + PaoSUPERIndex_F[sq]];
	return _mm_or_si128(ratt,fatt);
}








