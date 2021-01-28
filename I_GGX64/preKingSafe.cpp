/*

#include "chess.h"
 
#include "preGen.h"
#include "mfa.h"
#include "valore.h"

//uint8   PreKingSafe[KS_SIZE];

void init_preKingSafe(void){
	int safe;

    for(safe = 0; safe < KS_SIZE; safe ++){
        PreKingSafe[safe] = (uint8)TempSafe(safe);
    }
}

const uint8 V16_0[] = {
	//0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
	  0, 2, 6, 8,12,16,20,24,28,32,36,40,44,48,52
};
const uint8 V16_1[] = {
	//0  1  2  3  4 5  6  7  8  9  10 11 12 13 14 15
	  0, 2, 4, 6, 8,12,16,20,24,28,32,36,40,44,48,52
};
const uint8 V16_2[] = {
	//0  1  2  3  4 5  6 7  8  9  10 11 12 13 14 15
	  0, 0, 2, 4, 6, 8,12,16,20,24,28,32,36,40,44,48
};
const uint8 V16_3[] = {
	//1  2  3  4  5  6 7  8  9  10 11 12 13 14 15
	  0, 0, 0, 2, 4, 6, 8,12,16,20,24,28,32,36,40,44,
};
const uint8 V16_4[] = {
	//1  2  3  4 5  6  7 8  9  10 11 12 13 14 15
	  0, 0, 0, 0,2, 4, 6, 8,12,16,20,24,28,32,36,40
};


//const int 大于这个子不算 = 4;
void init_MaterialTotalOver(void){
	//MaterialTotalOver[16][16]; 
	//ei.Rattack_B_Count = MaterialTotalOver[iwo][ibo];
	//ei.Battack_R_Count = MaterialTotalOver[ibo][iwo];
	for(int r = 0; r < 16; r++){
		for(int b = 0; b < 16; b++){			
			int att = 0;
			switch(r){
			case 0:
				att = V16_0[b];
				break;
			case 1:
				att = V16_1[b];
				break;
			case 2:
				att = V16_2[b];
				break;
			case 3:
				att = V16_3[b];
				break;
			case 4:
				att = V16_4[b];
				break;
			default:
				att = 0;
				break;
			}
			MaterialTotalOver[b][r] = att;
		}
	}
}
*/