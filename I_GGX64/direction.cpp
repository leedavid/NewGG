#include "chess.h"


////
//// Includes
////

//#include "s_direction.h"
//#include "s_square.h"

////
//// Local definitions
////

namespace {


}

////
//// Variables
////

uint8 DirectionTable[90][90];

uint8 Relative_rank90[2][90];

////
//// Functions
////

void init_relative_rank(){
	 // uint8 Relative_rank90[2][90];
	for (int c = 0; c < 2; c++){
		for (int s = 0; s < 90; s++){
			if (c == 0){
				Relative_rank90[c][s] = StoY(s);
			}
			else{
				Relative_rank90[c][s] = 9-StoY(s);
			}

		}
	}
}

//enum Direction {
//	DIR_左右 = 0, DIR_上下 = 1, DIR_马 = 2, DIR_相 = 3, DIR_仕 = 4
//};

void init_direction_table() {

	//for (Square s1 = SQ_A1; s1 <= SQ_H8; s1++)
	//	for (Square s2 = SQ_A1; s2 <= SQ_H8; s2++)
	//	{
	//		DirectionTable[s1][s2] = uint8_t(DIR_NONE);
	//		SignedDirectionTable[s1][s2] = uint8_t(SIGNED_DIR_NONE);
	//		if (s1 == s2)
	//			continue;

	//		for (SignedDirection d = SIGNED_DIR_E; d != SIGNED_DIR_NONE; d++)
	//		{
	//			if (reachable(s1, s2, d))
	//			{
	//				SignedDirectionTable[s1][s2] = uint8_t(d);
	//				DirectionTable[s1][s2] = uint8_t(d / 2);
	//				break;
	//			}
	//		}
	//	}

	for(int s1 = 0; s1 < 90; s1++){
		for(int s2 = 0; s2 < 90; s2++){
			DirectionTable[s1][s2] = DIR_NONE;

			if(s1 == s2)
				continue;

			if(StoX(s1) == StoX(s2)){
				DirectionTable[s1][s2] = DIR_上下;
			}

			if(StoY(s1) == StoY(s2)){
				DirectionTable[s1][s2] = DIR_左右;
			}

			

		}
	}
}




