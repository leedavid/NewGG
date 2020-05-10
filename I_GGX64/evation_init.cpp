#include "eval_total.h"


// Evaluation weights, initialized from UCI options
Score WeightMobility, WeightPawnStructure;
Score WeightPassedPawns, WeightSpace;
Score WeightKingSafety[2];


// weight_option() computes the value of an evaluation weight, by combining
// two UCI-configurable weights (midgame and endgame) with an internal weight.

//Score weight_option(const std::string& mgOpt, const std::string& egOpt, Score internalWeight) {
//
//	Score uciWeight = make_score(get_option_value_int(mgOpt), get_option_value_int(egOpt));
//
//	// Convert to integer to prevent overflow
//	int mg = mg_value(uciWeight);
//	int eg = eg_value(uciWeight);
//
//	mg = (mg * 0x100) / 100;
//	eg = (eg * 0x100) / 100;
//	mg = (mg * mg_value(internalWeight)) / 0x100;
//	eg = (eg * eg_value(internalWeight)) / 0x100;
//	return make_score(mg, eg);
//}





/// 攻击分数

//uint8 KingPosSafe[90];
//static void init_KingPosSafe(void){
//	for(int k = 0; k < 90; k++){
//		uint8 result = 128;
//
//		if(k == 0x04 || k == 0x55){
//			result = 128;
//		}
//
//		if(k == 0x0d || k == 0x4c){
//			result = 138;
//		}
//
//		if(k == 0x16 || k == 0x43){
//			result = 180;
//		}
//
//		if(k == 0x03 || k == 0x05 || k == 0x54 || k == 0x56){
//			result = 138;
//		}
//
//		if(k == 0x0c || k == 0x0e || k == 0x4b || k == 0x4d){
//			result = 148;
//		}
//
//		if(k == 0x15 || k == 0x17 || k == 0x42 || k == 0x44){
//			result = 198;
//		}
//
//		KingPosSafe[k] = result;
//	}
//}

//KposSafe[90];

namespace Eval {

	void init_safety(){

		//int  SafetyTable[100]; 
		//MIN_ZEOR_SAFE_POINT    前面全是0
		int maxSlope   = 12;     // get_option_value_int("King Safety Max Slope");
		int peak       = 1680;
		double a       = 0.06;   // get_option_value_int("King Safety Coefficient") / 100.0;
		double b       =  0.0;   // get_option_value_int("King Safety X Intercept");
		bool quad      = TRUE;
		bool linear    = FALSE;
		int i,j;	

		Value tmp[TOTAL_SAFE_POINT];

		for(i = 0; i <= MIN_ZEOR_SAFE_POINT; i++){
			tmp[i] = Value(0);
		}

		Value* pSafe = &tmp[MIN_ZEOR_SAFE_POINT];

		for(i = 0; i < TOTAL_SAFE_POINT-MIN_ZEOR_SAFE_POINT-2; i++){

			*(pSafe+i) = Value(0);

			if(i < b){
				*(pSafe+i) = Value(0);
			}
			else if(quad){
				*(pSafe+i) = Value((int)(a*(i-b)*(i-b)));
			}
			else if(linear){
				*(pSafe+i) = Value((int)(100*a*(i-b)));
			}
		}
		for(i = 0; i < TOTAL_SAFE_POINT - MIN_ZEOR_SAFE_POINT-2; i++){
			if (*(pSafe+i+1) - *(pSafe+i) > maxSlope){
				for (j = i + 1; j < TOTAL_SAFE_POINT - MIN_ZEOR_SAFE_POINT-2; j++){
					*(pSafe+j) = *(pSafe+j-1) + (maxSlope);
				}
			}

			if (*(pSafe+i)  > (peak)){ // 最大值{
				*(pSafe+i) = Value(peak);
			}
		}

		for(i = 0; i < TOTAL_SAFE_POINT; i++){
			int val = tmp[i];
			SafetyTable[i] = make_score(val,val);  // 这个不需要哇
		}
	}

	/// read_weights() reads evaluation weights from the corresponding UCI parameters

	void init() {

		//Color them = flip(us);

		//	WeightMobility         = weight_option("Mobility (Middle Game)", "Mobility (Endgame)", WeightMobilityInternal);
		//	WeightPawnStructure    = weight_option("Pawn Structure (Middle Game)", "Pawn Structure (Endgame)", WeightPawnStructureInternal);
		//	WeightPassedPawns      = weight_option("Passed Pawns (Middle Game)", "Passed Pawns (Endgame)", WeightPassedPawnsInternal);
		//	WeightSpace            = weight_option("Space", "Space", WeightSpaceInternal);
		//	WeightKingSafety[us]   = weight_option("Cowardice", "Cowardice", WeightKingSafetyInternal);
		//	WeightKingSafety[them] = weight_option("Aggressiveness", "Aggressiveness", WeightKingOppSafetyInternal);

		// If running in analysis mode, make sure we use symmetrical king safety. We do this
		// by replacing both WeightKingSafety[us] and WeightKingSafety[them] by their average.
		//if (get_option_value_bool("UCI_AnalyseMode"))
		//{
		//	WeightKingSafety[us] = (WeightKingSafety[us] + WeightKingSafety[them]) / 2;
		//	WeightKingSafety[them] = WeightKingSafety[us];
		//}

		static bool ainit = false;

		if(ainit == false){
			init_safety();
			ainit = true;
		}
		//init_safety();
	}

} // namespace Eval 

