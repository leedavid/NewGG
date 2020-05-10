#include "chess.h"
 
#include "preGen.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>


#ifdef USE_STOCK_FISH_FILE
#else

sint32 CAPTURE_VALU[16][16];
void InitCaptureValues (void)   // int_capture_value
{
	//memset(CAPTURE_VALU,0,16*16*sizeof(sint32));
	CAPTURE_VALU[0][0] 		= 0;
	// 吃黑车	
	CAPTURE_VALU[RPAWN][BCHE] 		= (0xd0 << 24) + (0x02 << 20);
	CAPTURE_VALU[RSHI][BCHE] 		= (0xcf << 24) + (0x02 << 20);
	CAPTURE_VALU[RXIANG][BCHE] 		= (0xcf << 24) + (0x02 << 20);
	CAPTURE_VALU[RPAO][BCHE] 		= (0xce << 24) + (0x02 << 20);
	CAPTURE_VALU[RMA][BCHE] 		= (0xce << 24) + (0x02 << 20);
	CAPTURE_VALU[RCHE][BCHE] 		= (0xcd << 24) + (0x01 << 20);
	
	// 吃黑马
	CAPTURE_VALU[RPAWN][BMA] 		= (0xc8 << 24) + (0x02 << 20);
	CAPTURE_VALU[RSHI][BMA] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[RXIANG][BMA] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[RPAO][BMA] 		= (0xc6 << 24) + (0x02 << 20);
	CAPTURE_VALU[RMA][BMA] 		    = (0xc6 << 24) + (0x01 << 20);
	CAPTURE_VALU[RCHE][BMA] 		= (0xc5 << 24) + (0x00 << 20);

	// 吃黑炮
	CAPTURE_VALU[RPAWN][BPAO] 		= (0xc8 << 24) + (0x02 << 20);
	CAPTURE_VALU[RSHI][BPAO] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[RXIANG][BPAO] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[RPAO][BPAO] 		= (0xc6 << 24) + (0x02 << 20);
	CAPTURE_VALU[RMA][BPAO] 	    = (0xc6 << 24) + (0x01 << 20);
	CAPTURE_VALU[RCHE][BPAO] 		= (0xc5 << 24) + (0x00 << 20);
	
	// 吃黑仕
	CAPTURE_VALU[RPAWN][BSHI] 		= (0xc0 << 24) + (0x02 << 20);
	CAPTURE_VALU[RSHI][BSHI] 		= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[RXIANG][BSHI] 		= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[RPAO][BSHI] 		= (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[RMA][BSHI] 	    = (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[RCHE][BSHI] 		= (0xbd << 24) + (0x00 << 20);

	// 吃黑相
	CAPTURE_VALU[RPAWN][BXIANG] 	= (0xc0 << 24) + (0x02 << 20);
	CAPTURE_VALU[RSHI][BXIANG] 		= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[RXIANG][BXIANG] 	= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[RPAO][BXIANG] 		= (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[RMA][BXIANG] 	    = (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[RCHE][BXIANG] 		= (0xbd << 24) + (0x00 << 20);

	// 吃黑兵
	CAPTURE_VALU[RPAWN][BPAWN] 	    = (0xb0 << 24) + (0x01 << 20);
	CAPTURE_VALU[RSHI][BPAWN] 		= (0xaf << 24) + (0x00 << 20);
	CAPTURE_VALU[RXIANG][BPAWN] 	= (0xaf << 24) + (0x00 << 20);
	CAPTURE_VALU[RPAO][BPAWN] 		= (0xae << 24) + (0x00 << 20);
	CAPTURE_VALU[RMA][BPAWN] 	    = (0xae << 24) + (0x00 << 20);
	CAPTURE_VALU[RCHE][BPAWN] 		= (0xac << 24) + (0x00 << 20);

	// 将吃其它
	CAPTURE_VALU[RKING][BCHE] 	    = (0xcb << 24) + (0x00 << 20);
	CAPTURE_VALU[RKING][BMA] 		= (0xc3 << 24) + (0x00 << 20);
	CAPTURE_VALU[RKING][BPAO] 	    = (0xc3 << 24) + (0x00 << 20);
	CAPTURE_VALU[RKING][BSHI] 		= (0xbb << 24) + (0x00 << 20);
	CAPTURE_VALU[RKING][BXIANG] 	= (0xbb << 24) + (0x00 << 20);
	CAPTURE_VALU[RKING][BPAWN] 		= (0xb3 << 24) + (0x00 << 20);

	// 不吃子
	/*CAPTURE_VALU[RKING][0] 	    = (0x07 << 24) + (0x00 << 15);
	CAPTURE_VALU[RPAWN][0] 		= (0x06 << 24) + (0x01 << 15);
	CAPTURE_VALU[RSHI][0] 	    = (0x05 << 24) + (0x01 << 15);
	CAPTURE_VALU[RXIANG][0]     = (0x05 << 24) + (0x01 << 15);
	CAPTURE_VALU[RPAO][0] 	    = (0x04 << 24) + (0x01 << 15);
	CAPTURE_VALU[RMA][0] 		= (0x04 << 24) + (0x01 << 15);	
	CAPTURE_VALU[RCHE][0]       = (0x03 << 24) + (0x01 << 15);*/
	CAPTURE_VALU[RKING][0] 	    = (0x07 << 24) + (0x00 << 16);
	CAPTURE_VALU[RPAWN][0] 		= (0x06 << 24) + (0x01 << 16);
	CAPTURE_VALU[RSHI][0] 	    = (0x05 << 24) + (0x01 << 16);
	CAPTURE_VALU[RXIANG][0]     = (0x05 << 24) + (0x01 << 16);
	CAPTURE_VALU[RPAO][0] 	    = (0x04 << 24) + (0x01 << 16);
	CAPTURE_VALU[RMA][0] 		= (0x04 << 24) + (0x01 << 16);	
	CAPTURE_VALU[RCHE][0]       = (0x03 << 24) + (0x01 << 16);

	// 吃红车	
	CAPTURE_VALU[BPAWN][RCHE] 		= (0xd0 << 24) + (0x02 << 20);
	CAPTURE_VALU[BSHI][RCHE] 		= (0xcf << 24) + (0x02 << 20);
	CAPTURE_VALU[BXIANG][RCHE] 		= (0xcf << 24) + (0x02 << 20);
	CAPTURE_VALU[BPAO][RCHE] 		= (0xce << 24) + (0x02 << 20);
	CAPTURE_VALU[BMA][RCHE] 		= (0xce << 24) + (0x02 << 20);
	CAPTURE_VALU[BCHE][RCHE] 		= (0xcd << 24) + (0x01 << 20);
				 
	// 吃红马	   
	CAPTURE_VALU[BPAWN][RMA] 		= (0xc8 << 24) + (0x02 << 20);
	CAPTURE_VALU[BSHI][RMA] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[BXIANG][RMA] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[BPAO][RMA] 		= (0xc6 << 24) + (0x02 << 20);
	CAPTURE_VALU[BMA][RMA] 		    = (0xc6 << 24) + (0x01 << 20);
	CAPTURE_VALU[BCHE][RMA] 		= (0xc5 << 24) + (0x00 << 20);
				
	// 吃红炮	   
	CAPTURE_VALU[BPAWN][RPAO] 		= (0xc8 << 24) + (0x02 << 20);
	CAPTURE_VALU[BSHI][RPAO] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[BXIANG][RPAO] 		= (0xc7 << 24) + (0x02 << 20);
	CAPTURE_VALU[BPAO][RPAO] 		= (0xc6 << 24) + (0x02 << 20);
	CAPTURE_VALU[BMA][RPAO] 	    = (0xc6 << 24) + (0x01 << 20);
	CAPTURE_VALU[BCHE][RPAO] 		= (0xc5 << 24) + (0x00 << 20);
				 
	// 吃红仕	   
	CAPTURE_VALU[BPAWN][RSHI] 		= (0xc0 << 24) + (0x02 << 20);
	CAPTURE_VALU[BSHI][RSHI] 		= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[BXIANG][RSHI] 		= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[BPAO][RSHI] 		= (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[BMA][RSHI] 	    = (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[BCHE][RSHI] 		= (0xbd << 24) + (0x00 << 20);
				 
	// 吃红相	   
	CAPTURE_VALU[BPAWN][RXIANG] 	= (0xc0 << 24) + (0x02 << 20);
	CAPTURE_VALU[BSHI][RXIANG] 		= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[BXIANG][RXIANG] 	= (0xbf << 24) + (0x01 << 20);
	CAPTURE_VALU[BPAO][RXIANG] 		= (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[BMA][RXIANG] 	    = (0xbe << 24) + (0x00 << 20);
	CAPTURE_VALU[BCHE][RXIANG] 		= (0xbd << 24) + (0x00 << 20);
				 
	// 吃红兵	   
	CAPTURE_VALU[BPAWN][RPAWN]  	= (0xb0 << 24) + (0x01 << 20);
	CAPTURE_VALU[BSHI][RPAWN] 		= (0xaf << 24) + (0x00 << 20);
	CAPTURE_VALU[BXIANG][RPAWN] 	= (0xaf << 24) + (0x00 << 20);
	CAPTURE_VALU[BPAO][RPAWN] 		= (0xae << 24) + (0x00 << 20);
	CAPTURE_VALU[BMA][RPAWN] 	    = (0xae << 24) + (0x00 << 20);
	CAPTURE_VALU[BCHE][RPAWN] 		= (0xac << 24) + (0x00 << 20);
				 
	// 将吃其它	   
	CAPTURE_VALU[BKING][RCHE] 	    = (0xcb << 24) + (0x00 << 20);
	CAPTURE_VALU[BKING][RMA] 		= (0xc3 << 24) + (0x00 << 20);
	CAPTURE_VALU[BKING][RPAO] 	    = (0xc3 << 24) + (0x00 << 20);
	CAPTURE_VALU[BKING][RSHI] 		= (0xbb << 24) + (0x00 << 20);
	CAPTURE_VALU[BKING][RXIANG] 	= (0xbb << 24) + (0x00 << 20);
	CAPTURE_VALU[BKING][RPAWN] 		= (0xb3 << 24) + (0x00 << 20);
				 
	// 不吃子	   
	//CAPTURE_VALU[BKING][0] 	    = (0x07 << 24) + (0x00 << 15);
	//CAPTURE_VALU[BPAWN][0] 		= (0x06 << 24) + (0x01 << 15);
	//CAPTURE_VALU[BSHI][0] 	    = (0x05 << 24) + (0x01 << 15);
	//CAPTURE_VALU[BXIANG][0]     = (0x05 << 24) + (0x01 << 15);
	//CAPTURE_VALU[BPAO][0] 	    = (0x04 << 24) + (0x01 << 15);
	//CAPTURE_VALU[BMA][0] 		= (0x04 << 24) + (0x01 << 15);	
	//CAPTURE_VALU[BCHE][0]       = (0x03 << 24) + (0x01 << 15);

	CAPTURE_VALU[BKING][0] 	    = (0x07 << 24) + (0x00 << 16);
	CAPTURE_VALU[BPAWN][0] 		= (0x06 << 24) + (0x01 << 16);
	CAPTURE_VALU[BSHI][0] 	    = (0x05 << 24) + (0x01 << 16);
	CAPTURE_VALU[BXIANG][0]     = (0x05 << 24) + (0x01 << 16);
	CAPTURE_VALU[BPAO][0] 	    = (0x04 << 24) + (0x01 << 16);
	CAPTURE_VALU[BMA][0] 		= (0x04 << 24) + (0x01 << 16);	
	CAPTURE_VALU[BCHE][0]       = (0x03 << 24) + (0x01 << 16);

}



void init_fromtoBBbackBB(void){
	int from;
	int to;
	int i;

	for(from = 0; from < 90; from++){
		for(to = 0; to < 90; to++){
			fromtoBBback[from][to] = _mm_setzero_si128 ();  // _mm_set1_epi32(0xFFFFFFFF);
			if(StoX(from) == StoX(to)){
				if(FALSE){
				}
				else if(StoY(from) < StoY(to)){
					for( i = 0; i < StoY(from); i++){
						set_bit(fromtoBBback[from][to],XYtoS(StoX(from),i));
					}
				}
				else if(StoY(from) > StoY(to)){
					for( i = 9; i > StoY(from); i--){
						set_bit(fromtoBBback[from][to],XYtoS(StoX(from),i));
					}
				}
			}
			if(StoY(from) == StoY(to)){
				if(FALSE){
				}
				else if(StoX(from) < StoX(to)){
					for( i = 0; i < StoX(from); i++){
						set_bit(fromtoBBback[from][to],XYtoS(i,StoY(from)));
					}
				}
				else if(StoX(from) > StoX(to)){
					for( i = 8; i > StoX(from); i--){
						set_bit(fromtoBBback[from][to],XYtoS(i,StoY(from)));
					}
				}
			}			
		}
	}
}

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
				if(ABS(fy-ty) == 1){
					_MaLegTable[from][to] = from+1;
				}
			}
			//to在左
			if((fx - tx) == 2){
				if(ABS(fy-ty) == 1){
					_MaLegTable[from][to] = from-1;
				}
			}
            //to在上
			if((fy - ty) == 2){
				if(ABS(fx-tx) == 1){
					_MaLegTable[from][to] = from-9;
				}
			}
			//to在下
			if((fy - ty) == -2){
				if(ABS(fx-tx) == 1){
					_MaLegTable[from][to] = from+9;
				}
			}            
		}
	}
}

// 初始化牵制分.,根据残局的状态.
void initStringTable(void){
	//int MatStringScore = 220;

	//for(int i = 0; i < 256; i++){
	//	int spao = 64  + (OpenPhase - i) / 16;
	//	int sma  = 80  + (OpenPhase - i) / 16;
	//	//int spm  = 108 + (OpenPhase - i) / 16;

	//	if(spao >= MatStringScore) spao = MatStringScore ;
	//	if(sma  >= MatStringScore) sma  = MatStringScore ;
	//	//if(spm  >= MatStringScore) spm  = MatStringScore ;

	//	MaStringByChe[i]  = sma;
	//	PaoStringByChe[i] = spao;
	//	//MaStringByPao[i]  = spm;
	//}
}

void InitKingAttackZone(void){
	int i;
	int x,y;
	//int k;
	for(i = 0; i < 90; i++){
       KingAttackZone[i] = _mm_setzero_si128 ();
	   KingKingAttBB[i]  = _mm_setzero_si128 ();
	   x = StoX(i);
	   y = StoY(i);

	   // 首先把自己加上
	   set_bit(KingKingAttBB[i],i);  // 对将检测用的

	   if(x >= 0x3 && x <= 0x5){

		   if(y <= 2){ // bk			   
			   if(y <= 1){
				   set_bit(KingKingAttBB[i],i+9);
			   }
			   if(x >= 4){
				   set_bit(KingKingAttBB[i],i-1);
			   }
			   if(x <= 4){
				   set_bit(KingKingAttBB[i],i+1);
			   }
		   }
		   if(y >= 7){ // rk
			   if(y >= 8){
				   set_bit(KingKingAttBB[i],i-9);
			   }
			   if(x >= 4){
				   set_bit(KingKingAttBB[i],i-1);
			   }
			   if(x <= 4){
				   set_bit(KingKingAttBB[i],i+1);
			   }
		   }

		   //bk
		   if(y <= 2){ // 将的四周全算可攻击的位.

			    set_bit(KingAttackZone[i],i);

			   // 将的左,右一格.
			   set_bit(KingAttackZone[i],i-1);     //左
			   set_bit(KingAttackZone[i],i+1);     //右

			   // 将的上面一格.
               set_bit(KingAttackZone[i],i+9);     //下

			   if(y != 0){
				   set_bit(KingAttackZone[i],i-9); //上
				   set_bit(KingAttackZone[i],i-9+1); //上
				   set_bit(KingAttackZone[i],i-9-1); //上
			   }

			   // 将的周围9格, 下面二排3格,左,右
			  
			   set_bit(KingAttackZone[i],i+9);     //下
			   set_bit(KingAttackZone[i],i+9-1);     //
			   set_bit(KingAttackZone[i],i+9+1);     //
			   
			   // 将的周围9格, 下面三排3格,左,右
			   set_bit(KingAttackZone[i],i+18);
			   set_bit(KingAttackZone[i],i+18-1);     //
			   set_bit(KingAttackZone[i],i+18+1);     //

		   }

		   //rk
		   if(y >= 7){

			   set_bit(KingAttackZone[i],i);
			   set_bit(KingAttackZone[i],i-1);      //左
			   set_bit(KingAttackZone[i],i+1);      //右

			   set_bit(KingAttackZone[i],i-9);      //上
			   set_bit(KingAttackZone[i],i-9+1);      //上
			   set_bit(KingAttackZone[i],i-9-1);      //上

			   set_bit(KingAttackZone[i],i-18);      //上
			   set_bit(KingAttackZone[i],i-18+1);      //上
			   set_bit(KingAttackZone[i],i-18-1);      //上

			   if(y != 9){
				   set_bit(KingAttackZone[i],i+9);   //下
				   set_bit(KingAttackZone[i],i+9+1);   //下
				   set_bit(KingAttackZone[i],i+9-1);   //下
			   }
		   }
	   }
	}
}



void second_init(void){
};

void init_SafetyTable(void){
	//int  SafetyTable[100]; 
	//MIN_ZEOR_SAFE_POINT    前面全是0
	int maxSlope   = 12;     // get_option_value_int("King Safety Max Slope");
	int peak       = 1680;
	double a       = 0.06;   // get_option_value_int("King Safety Coefficient") / 100.0;
	double b       =  0.0;   // get_option_value_int("King Safety X Intercept");
	bool quad      = TRUE;
	bool linear    = FALSE;
	int i,j;	

	for(i = 0; i <= MIN_ZEOR_SAFE_POINT; i++){
		SafetyTable[i] = 0;
	}

	sint16* pSafe = &SafetyTable[MIN_ZEOR_SAFE_POINT];

	for(i = 0; i < TOTAL_SAFE_POINT-MIN_ZEOR_SAFE_POINT; i++){

		*(pSafe+i) = 0;

		if(i < b){
			*(pSafe+i) = 0;
		}
		else if(quad){
			*(pSafe+i) = (sint16)(a*(i-b)*(i-b));
		}
		else if(linear){
			*(pSafe+i) = (sint16)(100*a*(i-b));
		}
	}
	for(i = 0; i < TOTAL_SAFE_POINT; i++){
		if (*(pSafe+i+1) - *(pSafe+i) > maxSlope){
			for (j = i + 1; j < TOTAL_SAFE_POINT; j++){
				*(pSafe+j) = *(pSafe+j-1) + (maxSlope);
			}
		}

		if (*(pSafe+i)  > (peak)){ // 最大值{
			*(pSafe+i) = (peak);
	    }
	}
}

sint16 PawnCanAddByChe[4][4];
void init_PawnCanAddByChe(void){
	for(int r = 0; r < 4; r++){
		for(int b = 0; b < 4; b++){
			PawnCanAddByChe[r][b] = 0;
			if(r == 2 && b == 2){
				PawnCanAddByChe[r][b] = 8;
			}
			if(r == 2 && b == 1){
				PawnCanAddByChe[r][b] = 32;
			}
			if(r == 2 && b == 0){
				PawnCanAddByChe[r][b] = 64;
			}
			//
			if(r == 1 && b == 2){
				PawnCanAddByChe[r][b] =  8;
			}
			if(r == 1 && b == 1){
				PawnCanAddByChe[r][b] = 16;
			}
			if(r == 1 && b == 0){
				PawnCanAddByChe[r][b] = 48;
			}
			//
			if(r == 0 && b == 0){
				PawnCanAddByChe[r][b] = 32;
			}
			if(r == 0 && b == 1){
				PawnCanAddByChe[r][b] = 16;
			}
			if(r == 0 && b == 2){
				PawnCanAddByChe[r][b] = 8;
			}
		}
	}
}

// OLD
//void init_SafetyTable(void){
//	//int  SafetyTable[100]; 
//	int maxSlope  = 30;  // get_option_value_int("King Safety Max Slope");
//	int peak      = 1280;
//	double a       = 0.4;   // get_option_value_int("King Safety Coefficient") / 100.0;
//	double b       = 0.0;   // get_option_value_int("King Safety X Intercept");
//	bool quad   = TRUE;
//	bool linear = FALSE;
//	int i,j;
//	for(i = 0; i < 100; i++){
//		SafetyTable[i] = 0;
//		if(i < b){
//			SafetyTable[i] = 0;
//		}
//		else if(quad){
//			SafetyTable[i] = (int)(a*(i-b)*(i-b));
//		}
//		else if(linear){
//			SafetyTable[i] = (int)(100*a*(i-b));
//		}
//	}
//	for(i = 0; i < 100; i++){
//		if (SafetyTable[i+1] - SafetyTable[i] > maxSlope)
//			for (j = i + 1; j < 100; j++)
//				SafetyTable[j] = SafetyTable[j-1] + (maxSlope);
//
//		if (SafetyTable[i]  > (peak)) // 最大值
//			SafetyTable[i] = (peak);
//	}
//}

void PreGenInit(void){

	//_MaLegTable[90][90]
	initMalegTable();
    initStringTable();    // 初始化牵制分
	InitPreMatinfo();     // 物质信息	
	init_PawnCanAddByChe();
	//init_preKingSafe();
	init_SafetyTable();
	//init_MaterialTotalOver();

#ifdef USE_VP_PROTECT
	VMProtectBegin(MARKER_NAME);
	int res;
	res = VMProtectGetSerialNumberState();
	if(res != 0){  //  没有注册成功
	}
	else{
		InitKingAttackZone();
	}
	VMProtectEnd();
#else
	InitKingAttackZone();
#endif
	//InitPaoThree();
}

// PaoCanAttKing
void int_PaoCanAttKing(void){   // 初始化炮能攻击将位置
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

        // 红炮攻黑将
		if(StoY(k) < 0x3){
			for(int p = 0; p < 90; p++){
				if(StoY(p) < 0x3){
					if(StoX(p) < 0x3 || StoX(p) > 0x5 || ABS(StoX(p) - StoX(k)) >= 2){
						set_bit(PaoCanAttKing[k],p);
					}
				}
				if(StoY(p) > 0x2){
					if(ABS(StoX(p) - 0x4) <= 1 && ABS(StoX(p) - StoX(k)) <= 1){
						set_bit(PaoCanAttKing[k],p);
					}
				}
			}
		}
		// 黑炮攻红将
		if(StoY(k) > 0x6){
			for(int p = 0; p < 90; p++){
				if(StoY(p) > 0x6){
					if(StoX(p) < 0x3 || StoX(p) > 0x5 || ABS(StoX(p) - StoX(k)) >= 2){
						set_bit(PaoCanAttKing[k],p);
					}
				}
				if(StoY(p) < 0x7){
					if(ABS(StoX(p) - 0x4) <= 1 && ABS(StoX(p) - StoX(k)) <= 1){
						set_bit(PaoCanAttKing[k],p);
					}
				}
			}
		}				
	}
}

void init_PawnGoodMove(void){        // 初始化兵的好步
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

//extern int ThreatBonus[16][16];        // open_end;
//组合太多了.怎么初始化??
//void init_ThreatBonus(void){
//	for(int r = 0; r < 16; r++){
//		for(int b = 0; b < 16; b++){
//			ThreatBonus[r][b] = 0;
//			switch(r){
//			case EMPTY:
//				break;
//			case RCHE:
//				{
//					const sint16 红车_X[16] = {	
//					}
//				}
//				break;
//			case RMA:
//				break;
//			case RPAO:
//				break;
//			case RPAWN:
//				break;
//			case RXIANG:
//				break;
//			case RSHI:
//				break;
//			case RKING:
//				break;
//			//*****************************************
//			case BCHE:
//				break;
//			case BMA:
//				break;
//			case BPAO:
//				break;
//			case BPAWN:
//				break;
//			case BXIANG:
//				break;
//			case BSHI:
//				break;
//			case BKING:
//				break;
//			}
//		}
//	}
//}

void frist_init(void){

	//init_mersenne();
	//init_zobrist();           // 初始化hash key 
	init_bitboards();           // 初始化位棋盘	
	init_fromtoBBbackBB();        // xxxxxx from -> to
	PreGenInit();
	eval_const_int();
	second_init();             //  

	init_PawnGoodMove();        // 初始化兵的好步
	int_PaoCanAttKing();	
	//init_MaKongKing();          // [90][90]; // 马控制将的能力

	//init_ThreatBonus();         //
	
#ifdef USE_STOCK_FISH_FILE
	std::cout << "uciok" << std::endl;
	std::cout << "info initend" << std::endl;
#else
	SEND ("uciok\n");
	SEND ("info initend\n");
#endif
	

#ifdef USE_CYCLONE_UCI
	read_uci_set_file();
#endif
}

#endif