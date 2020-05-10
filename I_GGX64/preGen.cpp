
#include "chess.h"
#include "preGen.h"
#include "eval_const.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include "VMP.h"


Bitboard CheYaMa[90];
Bitboard BitMaGooDMove[2];                      // 马有好步子可走


												//  将的相应位置压缩格式
												//  1 0 1
												//  2 4 2
												//  3 5 3

const int _KposSafeMul[6] = {
	//    0    1    2    3    4    5    6   7
	//    4    3   12   21   13   22   
	128, 138, 158, 198, 148, 180
};

void init_Ma_bitboard(){

	//  1 0 1
	//  2 4 2
	//  3 5 3
	for (int ma = 0; ma < 90; ma++){
		int mx = StoX(ma);
		int my = StoY(ma);
		int che = 0;
		CheYaMa[ma] = _mm_setzero_si128();
		if (mx == 0){
			che = XYtoS(1, my);
			set_bit(CheYaMa[ma], che);
		}
		if (mx == 8){
			che = XYtoS(7, my);
			set_bit(CheYaMa[ma], che);
		}
		if (my == 0){
			che = XYtoS(mx, 1);
			set_bit(CheYaMa[ma], che);
		}
		if (my == 9){
			che = XYtoS(mx, 8);
			set_bit(CheYaMa[ma], che);
		}
	}

	BitMaGooDMove[WHITE] = _mm_setzero_si128();
	BitMaGooDMove[BLACK] = _mm_setzero_si128();

	for (int ma = 0; ma < 90; ma++){
		int mx = StoX(ma);
		int my = StoY(ma);
		if (mx > 0 && mx < 8){

			//////////////////////////////////////////////////
			// 红马的好步子
			if (my < 8 && my >= 0){
				set_bit(BitMaGooDMove[WHITE], ma);
			}

			//if (ma == 0x3a){
			//	set_bit(BitMaGooDMove[WHITE], ma);
			//}

			//////////////////////////////////////////////////
			//  黑马的好步子
			if (my > 1 && my <= 9){
				set_bit(BitMaGooDMove[BLACK], ma);
			}

			//if (ma == 0x1f){
			//	set_bit(BitMaGooDMove[BLACK], ma);
			//}
		}
	}
}

void init_KposSafe(){

	for(int i = 0; i < 90; i++){
		KposSafe[i] = 0;
		if(i == 4 || i == 85){
			KposSafe[i] = 0;             // 128
		}
		if(i == 3 || i == 5 || i == 84 || i == 86){
			KposSafe[i] = 1;             // 138
		}
		if(i == 12 || i == 14 || i == 75 || i == 77){
			KposSafe[i] = 2;             // 158
		}
		if(i == 21 || i == 23 || i == 66 || i == 68){
			KposSafe[i] = 3;             // 198
		}
		if(i == 13 || i == 76){
			KposSafe[i] = 4;             // 148
		}
		if(i == 22 || i == 67){
			KposSafe[i] = 5;             // 180
		}
	}

};
               // che ma pao pawn kingpos
uint8 TOTAL_ATT_POINT[3][3][3][6][6];
static void init_TOTAL_ATT_POIN(void){
	for(int che = 0; che < 3; che++){
		for(int ma = 0; ma < 3; ma++){
			for(int pao = 0; pao < 3; pao++){
				for(int pawn = 0; pawn < 6; pawn++){	
					for(int kpos = 0; kpos < 6; kpos++){
						//for(int shi = 0; shi < 3; shi ++){
						int safe = 0;
						// fen 1Rbk1ab2/9/n2P2n1c/p1p3p1p/3N5/9/P1P3c1P/4C2rN/9/2BAKAB1R b - - 0 1
						safe += che * 2 + ma * 3 + pao * 3 + pawn * 4;
						// fen 9/5k3/4ba3/8R/r8/1nC5P/9/2p1B4/4A4/1cNAK1B2 w - - 0 1

						if(kpos == 3 || kpos == 5){
							if((ma + che) >= 2){
								safe += ma * 2 + che * 1;
							}
						}
						// fen 2Rak1b2/9/2n2C3/p3p3p/9/1N7/PcrNP3P/1C7/c2KA4/5A3 w - - 0 1
						if(che <= 1 && ma == 0 && pawn == 0){
							safe -= 4;
						}

						if (che == 0 && pao == 1 && ma == 1 && pawn == 1 && kpos == 0) {
							che = 0;						
						}

						//  将的相应位置压缩格式
						//  1 0 1
						//  2 4 2
						//  3 5 3
						if(che == 2){
							if(kpos != 0){
								safe += 2;
							}
							if(kpos == 2 || kpos == 4){
								safe += 3;
							}
							if(kpos == 3 || kpos == 5){
								safe += 6;
							}
						}
						else if(che == 1){
							if(ma >= 1){
								if(kpos != 0){
									safe += che * 2 + ma * 2;
								}
								//// fen 2bak3C/9/7R1/2n5N/1c4r2/P3pp3/2p5P/4B4/4A4/2BAK4 b - - 0 1
								//if((che + ma + pao + pawn) >= 4){
								//	safe += (ma * 2 + pao * 2 + pawn * 2);
								//}
								// fen 3a1ab2/4k4/3r2n2/p1R3p1p/1N7/4C1P2/P6cP/4B4/3pA4/3AK4 w - - 0 1
								if((ma + pao + pawn) >= 2){
									if(kpos != 0){
										safe += ma * 1 + pao * 1 ;
									}
								}
								// fen 3aka3/3R5/4br3/p7p/6p2/5p3/Pn3n2P/4B4/4A2R1/2BAK4 w - - 0 1
								if(ma == 2){
									safe += 3;
								}
							}
							if(pao >= 1){ // fen 1CRa1ab2/4k4/4nc3/4N3p/6p2/9/P3P4/4B3r/4K4/9 b - - 0 1
								safe += pao * 1;
								if(kpos == 4){
									safe += che * 2 + ma * 2 + pao * 2;
								}
								if(kpos == 5){
									safe += che * 3 + ma * 3 + pao * 2;
								}
							}
							if(((che + ma + pao)*2 + pawn) >= 7){
								safe += ma * 1 + pao * 1 + pawn;
							} 
						}
						else {
							// fen 4k4/3Pa4/3a5/3cNn3/4C4/9/4p4/4B4/4AK3/3A5 w - - 0 1
							if (ma <= 1 && pao <= 1 && pawn <= 1) {
								safe -= 3;
								if (kpos == 0) {
									safe -= 3;
								}
							}
						}

						
						//  黑将的相应位置压缩格式
						//  1 0 1
						//  2 4 2
						//  3 5 3
						int mul = _KposSafeMul[kpos];
						safe = mul * safe / 128;
						if(safe >= 128) safe = 128;						
						if(safe < 0)    safe = 0;
						TOTAL_ATT_POINT[che][ma][pao][pawn][kpos] = safe;
						//}
					}					
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
///              che ma pao deltking
uint8 SIDE_ATT_POINT[3][3][3][3];
static void init_SIDE_ATT_POINT(void){
	for(int che = 0; che < 3; che++){
		for(int ma = 0; ma < 3; ma++){
			for(int pao = 0; pao < 3; pao++){
				for(int deltking = 0; deltking < 3; deltking++){
					int result = 0;

					if(che >= 0){                     // 有车的情况
						result += pao * 4;
						result += ma *  4;
						result += che * 3;
						if((pao + ma) >= 2){
							result += (pao + ma) * 3;
							if(pao >= 1){ // fen C1cak1b2/4a4/4b4/1NR3P2/9/P3p4/3n1r2p/4B4/4A4/3AK1B2 w - - 0 1
								result += 2;
							}
							//result += pao * 1;
						}
						if(ma == 0){
							result = result * 80 / 100;
						}	
					}
					else{
						result += pao * 2 + ma * 2;
						if(ma == 0){
							result = result * 80 / 100;
						}
					}

					// 再看一下将是不是在一边
					if(deltking == 0){
						result = result * 138 / 100;
					}
					else if(deltking == 1){   // 将在中间
						result = result * 100 / 100;
					}
					else{                     // 将在另一边
						result = result * 85 / 100;
					}
					ASSERT(result < 128);

					SIDE_ATT_POINT[che][ma][pao][deltking] = uint8(result);
				}
			}
		}
	}
};

static void initMalegTable(void){
	//_MaLegTable[90][90]
	int from;
	int to;
	int fx;
	int fy;
	int tx;
	int ty;
	for(from = 0; from < 90; from++){
		for(to = 0; to < 90; to++){
			_MaLegTable[from][to] = 0;
			fx = StoX(from);
			fy = StoY(from);
			tx = StoX(to);
			ty = StoY(to);

			//to在右
			if((fx - tx) == -2){
				if(abs(fy-ty) == 1){
					_MaLegTable[from][to] = uint8(from+1);
				}
			}
			//to在左
			if((fx - tx) == 2){
				if(abs(fy-ty) == 1){
					_MaLegTable[from][to] = uint8(from-1);
				}
			}
			//to在上
			if((fy - ty) == 2){
				if(abs(fx-tx) == 1){
					_MaLegTable[from][to] = uint8(from-9);
				}
			}
			//to在下
			if((fy - ty) == -2){
				if(abs(fx-tx) == 1){
					_MaLegTable[from][to] = uint8(from+9);
				}
			}            
		}
	}
}

Bitboard PawnKingAttackZone[90];  
// 计算兵三子归边的进攻性能.
static void InitPawnKingAttackZone(void){
	for(int k = 0; k < 90; k++){

		Bitboard result = _mm_setzero_si128();

		int x1 = StoX(k);
		int y1 = StoY(k);

		if(x1 <= 2 || x1 >= 6){
			continue;
		}
		//
		if(y1 >= 3 && y1 <= 6){
			continue;
		}
		// 如果将在原位.
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x04){
			for(int x = 2; x <= 6; x++){
				for(int y = 0; y <= 2; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			clear_bit(result,0x13);
			clear_bit(result,0x14);
			clear_bit(result,0x18);
			clear_bit(result,0x19);
		}
		if(k == 0x55){
			for(int x = 2; x <= 6; x++){
				for(int y = 7; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			clear_bit(result,0x40);
			clear_bit(result,0x41);
			clear_bit(result,0x45);
			clear_bit(result,0x46);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x0d){
			for(int x = 2; x <= 6; x++){
				for(int y = 1; y <= 2; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			//clear_bit(result,0x0a);
			//clear_bit(result,0x10);
			//clear_bit(result,0x1c);
			//clear_bit(result,0x1d);
			//clear_bit(result,0x21);
			//clear_bit(result,0x22);
			//set_bit(result,0x1e);
			//set_bit(result,0x20);
		}
		if(k == 0x4c){
			for(int x = 2; x <= 6; x++){
				for(int y = 7; y <= 8; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			//clear_bit(result,0x37);
			//clear_bit(result,0x38);
			//clear_bit(result,0x3c);
			//clear_bit(result,0x3d);
			//set_bit(result,0x39);
			//set_bit(result,0x3b);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x16){
			for(int x = 2; x <= 6; x++){
				for(int y = 1; y <= 3; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			clear_bit(result,0x1c);
			clear_bit(result,0x22);
		}
		if(k == 0x43){
			for(int x = 2; x <= 6; x++){
				for(int y = 6; y <= 8; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			clear_bit(result,0x37);
			clear_bit(result,0x3d);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x03){
			for(int x = 1; x <= 6; x++){
				for(int y = 0; y <= 2; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			// fen 1Cra1k3/4ac3/2P1b4/1R3N3/2n5p/P8/8P/9/2p1A4/4KAB2 b - - 0 1
			//clear_bit(result,0x17);
			//clear_bit(result,0x18);
		}
		if(k == 0x54){
			for(int x = 1; x <= 6; x++){
				for(int y = 7; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			//clear_bit(result,0x44);
			//clear_bit(result,0x45);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x05){
			for(int x = 2; x <= 7; x++){
				for(int y = 0; y <= 2; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			//clear_bit(result,0x14);
			//clear_bit(result,0x15);
		}
		if(k == 0x56){
			for(int x = 2; x <= 7; x++){
				for(int y = 7; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			//clear_bit(result,0x41);
			//clear_bit(result,0x42);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x0c){
			for(int x = 1; x <= 6; x++){
				for(int y = 1; y <= 2; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			set_bit(result,0x1d);
			set_bit(result,0x1e);
		}
		if(k == 0x4b){
			for(int x = 1; x <= 6; x++){
				for(int y = 7; y <= 8; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			set_bit(result,0x38);
			set_bit(result,0x39);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x0e){
			for(int x = 2; x <= 7; x++){
				for(int y = 1; y <= 2; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			set_bit(result,0x20);
			set_bit(result,0x21);
		}
		if(k == 0x4d){
			for(int x = 2; x <= 7; x++){
				for(int y = 7; y <= 8; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			set_bit(result,0x3b);
			set_bit(result,0x3c);
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x15){
			for(int x = 1; x <= 6; x++){
				for(int y = 1; y <= 3; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(k == 0x42){
			for(int x = 1; x <= 6; x++){
				for(int y = 6; y <= 8; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(k == 0x17){
			for(int x = 2; x <= 7; x++){
				for(int y = 1; y <= 3; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(k == 0x44){
			for(int x = 2; x <= 7; x++){
				for(int y = 6; y <= 8; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		PawnKingAttackZone[k] = result;
		//print_bb(result);
		//int i = 0;

		//if(k == 0x0d || k == 0x4c){
		//	print_bb(result);
		//}
	}

}

// MaPosAttackKing;
static void InitMaKingAttackZone(void){
	for(int i = 0; i < 90; i++){

		Bitboard result = _mm_setzero_si128();
		Bitboard mpk    = _mm_setzero_si128();
		Bitboard ppk    = _mm_setzero_si128();

		int x1 = StoX(i);
		int y1 = StoY(i);

		if(x1 <= 2 || x1 >= 6){
			continue;
		}
		//
		if(y1 >= 3 && y1 <= 6){
			continue;
		}

		for(int m = 0; m < 90; m++){
			if(abs(StoY(m) - y1) <= 3 && abs(StoX(m) - x1) <= 3){
				set_bit(mpk,m);
			}
		}
		// 如果将在原位.
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x04){
			for(int x = 0; x <= 8; x++){
				for(int y = 0; y <= 3; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			// fen 2r1kab2/4a4/3cb1nR1/C3p1C2/6p2/2Nn5/3r4P/4B4/4A4/1R2KAB2 w - - 0 25
			// 对方的马下一步能到臣位
			//set_bit(result,0x1c);
			//set_bit(result,0x1e);
			//set_bit(result,0x20);
			//set_bit(result,0x22);
			//set_bit(result,0x28);
			//set_bit(result,0x1f);

			// fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
			//clear_bit(result,0x14);
			//clear_bit(result,0x18);
		}
		if(i == 0x55){
			for(int x = 0; x <= 8; x++){
				for(int y = 6; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
			//set_bit(result,0x37);
			//set_bit(result,0x39);
			//set_bit(result,0x3b);
			//set_bit(result,0x3d);
			//set_bit(result,0x3a);
			//set_bit(result,0x31);

			// fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
			//clear_bit(result,0x41);
			//clear_bit(result,0x45);
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x0d){
			for(int x = 1; x <= 7; x++){
				for(int y = 0; y <= 4; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x4c){
			for(int x = 1; x <= 7; x++){
				for(int y = 5; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x16){
			for(int x = 0; x <= 8; x++){
				for(int y = 0; y <= 5; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x43){
			for(int x = 0; x <= 8; x++){
				for(int y = 4; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x03){
			for(int x = 0; x <= 6; x++){
				for(int y = 0; y <= 3; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x54){
			for(int x = 0; x <= 6; x++){
				for(int y = 6; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x05){
			for(int x = 2; x <= 8; x++){
				for(int y = 0; y <= 3; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x56){
			for(int x = 2; x <= 8; x++){
				for(int y = 6; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x0c){
			for(int x = 0; x <= 6; x++){
				for(int y = 0; y <= 4; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x4b){
			for(int x = 0; x <= 6; x++){
				for(int y = 5; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x0e){
			for(int x = 2; x <= 8; x++){
				for(int y = 0; y <= 4; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x4d){
			for(int x = 2; x <= 8; x++){
				for(int y = 5; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x15){
			for(int x = 0; x <= 7; x++){
				for(int y = 0; y <= 5; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x42){
			for(int x = 0; x <= 7; x++){
				for(int y = 4; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		if(i == 0x17){
			for(int x = 1; x <= 8; x++){
				for(int y = 0; y <= 5; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		if(i == 0x44){
			for(int x = 1; x <= 8; x++){
				for(int y = 4; y <= 9; y++){
					set_bit(result,XYtoS(x,y));
				}
			}
		}
		// 
		set_bit(ppk,XYtoS(x1-2,y1));
		set_bit(ppk,XYtoS(x1+2,y1));
		if(y1 < 0x3){
			set_bit(ppk,XYtoS(x1,y1+2));
		}
		if(y1 > 0x6){
			set_bit(ppk,XYtoS(x1,y1-2));
		}

		//////////////////////////////////////////////////////////////////////////
		MaKingAttackZone[i] = result;
		//KpaoKingPawn[i]     = ppk;
		MaPosAttackKing[i]  = mpk;

		//if(m_have_bit(result)){
		//	//std::cout << i << std::endl;
		//	clear_bit(result,i);
		//	print_bb(result);
		//	i = i;
		//}
	}
}



void PreGenInit(void){


	initMalegTable();
	InitPreMatinfo();                // 物质信息	

	init_KposSafe();                 // 这个要放在下面的前面
	init_Ma_bitboard();
	init_TOTAL_ATT_POIN();
	init_SIDE_ATT_POINT();

	InitMaKingAttackZone();
	InitPawnKingAttackZone();
}

#ifdef USE_RPPAWN_GOOD_MOVE
static void init_PawnGoodMove(void){        // 初始化兵的好步
	//	extern Bitboard RPawnGoodMove[90];     // 只有向中间走的步是好步.
	//	extern Bitboard BPawnGoodMove[90];
	for(int i = 0; i < 90; i++){
		RPawnGoodMove[i] = _mm_setzero_si128();
		BPawnGoodMove[i] = _mm_setzero_si128();


		if(StoY(i) <= 4){  // 看一下红兵能不能向前
			if(StoY(i) > 0){
				set_bit(RPawnGoodMove[i],i-9);
			}
			if(StoX(i) < 0x4){
				set_bit(RPawnGoodMove[i],i+1);
			}
			if(StoX(i) > 0x4){
				set_bit(RPawnGoodMove[i],i-1);
			}
			if(StoX(i) == 0x4){
				set_bit(RPawnGoodMove[i],i-1);
				set_bit(RPawnGoodMove[i],i+1);
			}
		}
		if(StoY(i) >= 5){ // 看一下黑兵能不能向前
			if(StoY(i) < 9){
				set_bit(BPawnGoodMove[i],i+9);
			}
			if(StoX(i) < 0x4){
				set_bit(BPawnGoodMove[i],i+1);
			}
			if(StoX(i) > 0x4){
				set_bit(BPawnGoodMove[i],i-1);
			}
			if(StoX(i) == 0x4){
				set_bit(BPawnGoodMove[i],i-1);
				set_bit(BPawnGoodMove[i],i+1);
			}
		}
	}
}
#endif

// PaoCanAttKing
static void int_PaoCanAttKing(void){   // 初始化炮能攻击将位置
	for(int k = 0; k < 90; k++){
		//上三线, 下三线
		if(StoX(k) < 0x3){
			continue;
		}
		if(StoX(k) > 0x5){
			continue;
		}
		if(StoY(k) > 0x2 && StoY(k) < 0x7){
			continue;
		}
		// fen 2bakNR2/5r3/8N/p8/4p4/2n6/Pr1n5/1c1CB4/1R2A4/2BK1A3 w - - 0 1
		// 红炮攻黑将
		if(StoY(k) < 0x3){
			for(int p = 0; p < 90; p++){
				if(StoY(p) < 0x3 && abs(StoY(p) - StoY(k)) <= 1){
					if(StoX(p) < 0x3 || StoX(p) > 0x5 || abs(StoX(p) - StoX(k)) >= 2){
						set_bit(PaoCanAttKing[k],p);
					}
				}
				if(StoY(p) > 0x2 && abs(StoY(p) - StoY(k)) >= 1){
					if(abs(StoX(p) - 0x4) <= 1 && abs(StoX(p) - StoX(k)) <= 1){
						set_bit(PaoCanAttKing[k],p);
					}
				}
			}
		}
		// 黑炮攻红将
		if(StoY(k) > 0x6){
			for(int p = 0; p < 90; p++){
				if(StoY(p) > 0x6 && abs(StoY(p) - StoY(k)) <= 1){
					if(StoX(p) < 0x3 || StoX(p) > 0x5 || abs(StoX(p) - StoX(k)) >= 2){
						set_bit(PaoCanAttKing[k],p);
					}
				}
				if(StoY(p) < 0x7 && abs(StoY(p) - StoY(k)) >= 1){
					if(abs(StoX(p) - 0x4) <= 1 && abs(StoX(p) - StoX(k)) <= 1){
						set_bit(PaoCanAttKing[k],p);
					}
				}
			}
		}				
	}
}

// Bitboard PawnMayBeCanNotRiver[2];

void frist_init(void){

	init_direction_table();  // 
	init_relative_rank();

	init_bitboards();           // 初始化位棋盘	
	PreGenInit();

	int_PaoCanAttKing();

	std::cout << "uciok" << std::endl;           
	std::cout << "info initend" << std::endl;    
}



