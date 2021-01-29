#include "chess.h"

#ifdef USE_STOCK_FISH_FILE

#include "preGen.h"

const int Only2Che_To_2shi2xiang_1che_ByPao     = 196;
const int Only2Che_To_2shi2xiang_1che_ByMa      = 128;
const int Only2Che_To_2shi2xiang_1che_NoPaoMa   =  96;

//fen 3nkab2/4a1P2/4b4/7R1/8c/1p7/9/4B4/4A4/4KAB2 w - - 4 4
//
const int Che_Only_Less_OnePawn_ByOnly1Pao = 96;
const int Che_Only_Less_OnePawn_ByOnly1Ma  = 64;
const int Che_Only_Less_OnePawn_ByPaoMa    = 80;
const int Che_Only_Less_OnePawn_ByPawn     = 32;

//有车方只有一个车时的加分
const int 有车方只有一个车时的加分a = 16;
const int 有车方只有一个车时的加分b = 32;
const int 有车方只有一个车时的加分c = 64;

//有车方只有车马或车炮
//fen 2bak4/4a4/4bc3/2nR5/n1N6/8p/9/4B4/4A4/2BAK4 w - - 0 0
const int Che_Only_1Pao_Or_1Ma_AddByOther_More_3MaPao = 48;

//fen 3ak4/4a4/P3b4/2R5p/2n3p2/4n4/R7P/6r2/4A4/4KAB2 w - - 7 7
//车方有二个车,对方仕不全, 则要加分
//                                0,  1   2   3  4
const int Che2ToChe1ByNot4SX[5] = { 64, 48, 24, 12, 0}; 

const int MaterialWeight        = 256; // 100%   

const int che1max = 15;
const int che1min =  8;

void InitOnePreMat(premat_t* pMat, int rpawn, int bpawn, int rche, int rma, int rpao, int rshi, int rxiang,int bche, int bma, int bpao, int bshi, int bxiang){

	//if(bche == 1 && bma == 1 && bpao == 0 && bpawn == 0 && bshi == 2 && bxiang == 1){
	//	if(rche == 0 && rma == 0 && rpao == 0 && rpawn == 1 && rshi == 1 && rxiang == 1){
	//		rche = rche;
	//	}
	//}

	//这儿可放入红相红仕的数量

	int R_chemapao = rche + rma + rpao;
	int B_chemapao = bche + bma + bpao;

	int R_2che1ma1pao = rche * 2 + rma + rpao;
	int B_2che1ma1pao = bche * 2 + bma + bpao;
	//int Rphase;
	//int Bphase;

	int rpawn_val;
	int rche_val;
	int rma_val;
	int rpao_val;

	int rshi_val;
	int rxiang_val;


	int bpawn_val;
	int bche_val;
	int bma_val;
	int bpao_val;

	int bshi_val;
	int bxiang_val;

	int number[2][16];
	int turn,opp;

	const static int  CheMaPao         = PAWN + 1;
	const static int  CheMaPaoPawn     = PAWN + 2;
	const static int  SHIXiang         = PAWN + 3;
	const static int  MaPao            = PAWN + 4;

	//红方是正,黑方是负
	const static int TurnMul[2] = {	 1,	-1	};
	//uint32 kpao;
	//int att;

	

	pMat->material         = 0;
	pMat->R_KongPaoScore   = 0;
	pMat->B_KongPaoScore   = 0;
	pMat->searchInfo16     = 0;
	pMat->phase            = 0;
	//pMat->Rphase           = 0;      //红方的攻子状态， 包括对方没有仕相
	//pMat->Bphase           = 0;      //黑方的攻子状态， 包括对方没有仕相


	////fen 2b2R3/3k5/3ab4/p8/3N5/P1P6/n3P3P/4B1N2/9/cr1AK1B2 w - - 1 1
	//只有一个,不减车
	//if(rche == 1){
	//	Rphase += CheAttPhase;
	//}
	//
	

	//如果一方的车没有了,且马炮少于4个,将Phase减小一些
	//if(rche == 0 && (rma + rpao) <= 2 && rpawn == 0){
 //        Rphase = Rphase * 6/8;
	//}

	////fen 2b2k3/4a4/3c5/3R2N2/9/6p2/7r1/3A1A3/3K5/4C4 b - - 6 6
	//if(rche == 1 && rpao <= 1 && rma == 0 && rpawn <= 1){
	//	if(bche >= 1 && (bpao + bma) >= 2){
	//		Rphase = Rphase * 6/8;
	//	}
	//}

	//fen 2b2R3/3k5/3ab4/p8/3N5/P1P6/n3P3P/4B1N2/9/cr1AK1B2 w - - 1 1
    //只要对方有三个大子, 基数也要加一些
	//if(rche == 1 && (rpao + rma) >= 2){
	//	Rphase += CheAttPhase;
	//}

	


	//pMat->phase = uint8(getPhase(pMat,rpawn,bpawn,rche,rma,rpao,rshi,rxiang,bche,bma,bpao,bshi,bxiang));



	////fen 2b2R3/3k5/3ab4/p8/3N5/P1P6/n3P3P/4B1N2/9/cr1AK1B2 w - - 1 1
	//只有一个,不减车
	//if(bche == 1){
	//	Bphase += CheAttPhase;
	//}

	

	//如果一方的车没有了,且马炮少于4个,将Phase减小一些
	//if(bche == 0 && (bma + bpao) <= 2 && bpawn == 0){
 //        Bphase = Bphase * 6/8;
	//}

	////fen 2b2k3/4a4/3c5/3R2N2/9/6p2/7r1/3A1A3/3K5/4C4 b - - 6 6
	//if(bche == 1 && bpao <= 1 && bma == 0 && bpawn <= 1){
	//	if(rche >= 1 && (rpao + rma) >= 2){
	//		 Bphase = Bphase * 6/8;
	//	}
	//}

	//fen 2b2R3/3k5/3ab4/p8/3N5/P1P6/n3P3P/4B1N2/9/cr1AK1B2 w - - 1 1
    //只要对方有三个大子, 基数也要加一些
	//if(bche == 1 && (bpao + bma) >= 2){
	//	Bphase += CheAttPhase;
	//}

	

	//如果一方没有攻击子了, 另一方要加分
	if(rche == 0 && rpao == 0 && rma == 0 && rpawn <= 1){
          pMat->material -= (bche * 256 + bpao * 128 + bma * 128 + bpawn * 64);
	}
	if(bche == 0 && bpao == 0 && bma == 0 && bpawn <= 1){
          pMat->material += (rche * 256 + rpao * 128 + rma * 128 + rpawn * 64);
	}

	if(rche == 0 && rpao == 0 && rma == 1 && rpawn == 0){
          pMat->material -= (bche * 128 + bpao * 96 + bma * 64 + bpawn * 64);
	}
	if(bche == 0 && bpao == 0 && bma == 1 && bpawn == 0){
          pMat->material += (rche * 128 + rpao * 96 + rma * 64 + rpawn * 64);
	}

	//fen 3a1k3/4a4/4P4/1r7/p3P4/9/P7p/4BA3/1c7/1RBAK4 w - - 0 0
    //一方只有

	//*************************************************************************************
	//如果没有兵了
	//if(rpawn == 0){
	//	if(FALSE){
	//	}
	//	else if(rche == 2){			
	//	}
	//	else if(rche == 1){
	//		if(FALSE){
	//		}
	//		else if(rma == 2){
	//		}
	//		else if(rma == 1){
	//		}
	//		else if(rma == 0){          //以下只有车炮
	//			if(FALSE){
	//			}
	//			else if(rpao == 2){     //车2炮
	//			}
	//			else if(rpao == 1){     //车1炮
	//				Rphase /= 2;
	//			}
	//			else if(rpao == 0){     //光车
	//				Rphase /= 4;
	//			}
	//		}
	//	}
	//	else if(rche == 0){
	//		if(FALSE){
	//		}
	//		else if(rma == 2){
	//			if(FALSE){
	//			}
	//			else if(rpao == 2){
	//			}
	//			else if(rpao == 1){
	//			}
	//			else if(rpao == 0){     //只有二个马
	//				Rphase /= 2;
	//			}
	//		}
	//		else if(rma == 1){
	//			if(FALSE){
	//			}
	//			else if(rpao == 2){
	//			}
	//			else if(rpao == 1){   //只有马炮
	//				Rphase /= 2;
	//			}
	//			else if(rpao == 0){   //只有一个马
	//				Rphase /= 4;
	//			}
	//		}
	//		else if(rma == 0){   //以下只有炮
	//			if(FALSE){
	//			}
	//			else if(rpao == 2){
	//				Rphase /= 2;
	//			}
	//			else if(rpao == 1){
	//				Rphase /= 4;
	//			}
	//			else if(rpao == 0){
	//				Rphase /= 8;
	//			}
	//		}
	//	}
	//}
	////*************************************************************************************
	//if(bpawn == 0){
	//	if(FALSE){
	//	}
	//	else if(bche == 2){			
	//	}
	//	else if(bche == 1){
	//		if(FALSE){
	//		}
	//		else if(bma == 2){
	//		}
	//		else if(bma == 1){
	//		}
	//		else if(bma == 0){          //以下只有车炮
	//			if(FALSE){
	//			}
	//			else if(bpao == 2){     //车2炮
	//			}
	//			else if(bpao == 1){     //车1炮
	//				Bphase /= 2;
	//			}
	//			else if(bpao == 0){     //光车
	//				Bphase /= 4;
	//			}
	//		}
	//	}
	//	else if(bche == 0){
	//		if(FALSE){
	//		}
	//		else if(bma == 2){
	//			if(FALSE){
	//			}
	//			else if(bpao == 2){
	//			}
	//			else if(bpao == 1){
	//			}
	//			else if(bpao == 0){     //只有二个马
	//				Bphase /= 2;
	//			}
	//		}
	//		else if(bma == 1){
	//			if(FALSE){
	//			}
	//			else if(bpao == 2){
	//			}
	//			else if(bpao == 1){   //只有马炮
	//				Bphase /= 2;
	//			}
	//			else if(bpao == 0){   //只有一个马
	//				Bphase /= 4;
	//			}
	//		}
	//		else if(bma == 0){   //以下只有炮
	//			if(FALSE){
	//			}
	//			else if(bpao == 2){
	//				Bphase /= 2;
	//			}
	//			else if(bpao == 1){
	//				Bphase /= 4;
	//			}
	//			else if(bpao == 0){
	//				Bphase /= 8;
	//			}
	//		}
	//	}
	//}

	//如果只有一个兵了
	//if(rpawn == 1){
	//	if(FALSE){
	//	}
	//	else if(rche == 2){			
	//	}
	//	else if(rche == 1){
	//	}
	//	else if(rche == 0){
	//		if(FALSE){
	//		}
	//		else if(rpao == 2){
	//		}
	//		else if(rpao == 1){
	//		}
	//		else if(rpao == 0){
	//			if(FALSE){
	//			}
	//			else if(rma == 2){
	//				Rphase /= 2;
	//			}
	//			else if(rma == 1){
	//				Rphase /= 4;
	//			}
	//			else if(rma == 0){
	//				Rphase /= 8;
	//			}
	//		}
	//	}
	//}
	//if(bpawn == 1){
	//	if(FALSE){
	//	}
	//	else if(bche == 2){			
	//	}
	//	else if(bche == 1){
	//	}
	//	else if(bche == 0){
	//		if(FALSE){
	//		}
	//		else if(bpao == 2){
	//		}
	//		else if(bpao == 1){
	//		}
	//		else if(bpao == 0){
	//			if(FALSE){
	//			}
	//			else if(bma == 2){
	//				Bphase /= 2;
	//			}
	//			else if(bma == 1){
	//				Bphase /= 4;
	//			}
	//			else if(bma == 0){
	//				Bphase /= 8;
	//			}
	//		}
	//	}
	//}

	//fen 5c3/9/3k5/9/5C3/5n3/4C4/5K3/4p4/2B6 w - - 132 132
	//if(rche == 0){
	//	if((bma + bpao) <= 2 ){
	//		if(bshi == 0 || bma == 2){
	//			if(bpawn == 1){
	//				Bphase /= 2;
	//			}
	//			if(bpawn == 0){
	//				Bphase /= 4;
	//			}
	//		}
	//	}
	//}
	//if(bche == 0){
	//	if((rma + rpao) <= 2 ){
	//		if(rshi == 0 || rma == 2){
	//			if(rpawn == 1){
	//				Rphase /= 2;
	//			}
	//			if(rpawn == 0){
	//				Rphase /= 4;
	//			}
	//		}
	//	}
	//}

	//*************************************************************************************

	//pMat->Rphase = Rphase;			//最大255
	//pMat->Bphase = Bphase;			//最大255


	rpawn_val  = PAWN_VAL;
	rche_val   = CHE_VAL;
	rma_val    = MA_VAL;
	rpao_val   = PAO_VAL;

	rshi_val    = SHI_VAL;
	rxiang_val  = XIANG_VAL;
	
	bpawn_val  = PAWN_VAL;
	bche_val   = CHE_VAL;
	bma_val    = MA_VAL;
	bpao_val   = PAO_VAL;
	
	bshi_val    = SHI_VAL;
	bxiang_val  = XIANG_VAL;


	number[WHITE][CHE]                = rche;
	number[WHITE][MA]                 = rma; 
	number[WHITE][PAO]                = rpao;
	number[WHITE][SHI]                = rshi;
	number[WHITE][XIANG]              = rxiang;
	number[WHITE][PAWN]               = rpawn;

	number[WHITE][CheMaPao]           = rche + rma + rpao;
	number[WHITE][CheMaPaoPawn]       = rche + rma + rpao + rpawn;
	number[WHITE][SHIXiang]           = rshi + rxiang;
	number[WHITE][MaPao]              = rma  + rpao;

	number[BLACK][CHE]                = bche;
	number[BLACK][MA]                 = bma; 
	number[BLACK][PAO]                = bpao;
	number[BLACK][SHI]                = bshi;
	number[BLACK][XIANG]              = bxiang;
	number[BLACK][PAWN]               = bpawn;

	number[BLACK][CheMaPao]           = bche + bma + bpao;
	number[BLACK][CheMaPaoPawn]       = bche + bma + bpao + bpawn;
	number[BLACK][SHIXiang]           = bshi + bxiang;
	number[BLACK][MaPao]              = bma  + bpao;


	if((rche + rma + rpao) <= 2 && rpawn <= 2 ){
		pMat->searchInfo16 |= CK_CAN_NOT_EASY_EVAL;  //CK_R_Must_Do_Ver;
	}
	if((bche + bma + bpao) <= 2 && bpawn <= 2 ){
		pMat->searchInfo16 |= CK_CAN_NOT_EASY_EVAL; //CK_B_Must_Do_Ver;
	}

	if(rche == 1 && rma == 0 && rpao == 1){
		if(bche >= 1){
		    pMat->searchInfo16 |= CK_R_Only_1Che1PaoxPawn;
		}
		//if(bche == 1 && ((bma + bpao) >= 1)){
		//	pMat->searchInfo16 |= CK_R_Only_1Che1PaoxPawn;
		//}
	}

	//#define CK_R_CAN_DO_NULL        (1 << 9)   // 是不是能做NULL
	//#define CK_B_CAN_DO_NULL        (1 << 10)  // 是不是能做NULL
	if((rche + rma + rpao) >= 1 || rpawn >= 2 ){
		pMat->searchInfo16 |= CK_R_CAN_DO_NULL;
	}
	if((bche + bma + bpao) >= 1 || bpawn >= 2 ){
		pMat->searchInfo16 |= CK_B_CAN_DO_NULL;
	}

	if(rche >= 1 || (rma + rpao) >= 2 || rpawn >= 3 || ((rma + rpao) >= 1 && rpawn >= 2)){
		pMat->searchInfo16 |= R_HAVE_enoughMaterial;
	}

	if(bche >= 1 || (bma + bpao) >= 2 || bpawn >= 3 || ((bma + bpao) >= 1 && bpawn >= 2)){
		pMat->searchInfo16 |= B_HAVE_enoughMaterial;
	}

	

	//if(rche == 1 && rma == 0 && rpao == 2){
	//	if(bche >= 1){
	//		pMat->searchInfo16 |= CK_R_Only_1Che2PaoxPawn;
	//	}
	//	//if(bche == 1 && ((bma + bpao) >= 1)){
	//	//	pMat->searchInfo16 |= CK_R_Only_1Che1PaoxPawn;
	//	//}
	//}
//#define CK_R_12Che_B_NoChe       (1 << 2)
//#define CK_B_12Che_R_NoChe       (1 << 3)
//#define CK_R_NoChe_B_NoChe       (1 << 4)
//

	//if((rche + bche) != 4){
	//	pMat->searchInfo16 |= CK_Eval_Pawn_Can; //评估一下双方兵可能过河的能力
	//}

    //缺相怕炮攻．
	//fen 4k4/4a4/4ba2N/N4P3/P1b3n2/c8/5p3/2nA5/4A2C1/4K4 b - - 0 0
	if(rpao >= 1){
		if((rche == 0 && (rma + rpao) <= 2) || (rche == 1 && (rma + rpao) == 1)){
		}
		else{
			if(bxiang == 1){
				pMat->material += 16;
			}
			if(bxiang == 0){
				pMat->material += 80;
			}
		}
	}
	if(bpao >= 1){
		if((bche == 0 && (bma + bpao) <= 2) || (bche == 1 && (bma + bpao) == 1)){
		}
		else{
			if(rxiang == 1){
				pMat->material -= 16;
			}
			if(rxiang == 0){
				pMat->material -= 80;
			}
		}
	}

	//if(rche == 2 && bche == 1){
	//	pMat->searchInfo16 |= CK_R_2Che_B_1Che;
	//}
	//if(bche == 2 && rche == 1){
	//	pMat->searchInfo16 |= CK_B_2Che_R_1Che;
	//}

	if(bche == 1 && bma == 0 && bpao == 1){
		if(rche >= 1){
			pMat->searchInfo16 |= CK_B_Only_1Che1PaoxPawn;
		}
		//if(rche == 1 && ((rma + rpao) >= 1)){
		//	pMat->searchInfo16 |= CK_B_Only_1Che1PaoxPawn;
		//}
	}
	//if(bche == 1 && bma == 0 && bpao == 2){
	//	if(rche >= 1){
	//		pMat->searchInfo16 |= CK_B_Only_1Che2PaoxPawn;
	//	}
	//	//if(rche == 1 && ((rma + rpao) >= 1)){
	//	//	pMat->searchInfo16 |= CK_B_Only_1Che1PaoxPawn;
	//	//}
	//}
	//fen 7r1/4k4/5a2b/p7p/6p2/3N5/P6cP/B3B4/4A4/4KR3 b - - 0 0
	//
	//#define CK_R_Only_1Che2PaoxPawn (1 << 2)   // 一方只有1车1炮X兵的评介
    //#define CK_B_Only_1Che2PaoxPawn (1 << 3)   // 一方只有1车1炮X兵的评介 

	//if((rche + rma + rpao + bche + bma + bpao) >= 4){
		//pMat->searchInfo16 |= IS_EARLY_GAME; // 总是要延伸搜索
	//}
	
	////如果一方是光头了,另一方有车马以上的子, 车马方要加分哇
	if(rshi <= 1 && rxiang <= 1){
		if(bche >= 1 && bma >= 1){
			pMat->material -= 80;
			if(rshi == 0 && rxiang == 0){
				pMat->material -= 64;
			}
		}		
	}
	if(bshi <= 1 && bxiang <= 1){
		if(rche >= 1 && rma >= 1){
			pMat->material += 80;
			if(bshi == 0 && bxiang == 0){
				pMat->material += 64;
			}
		}
	}


	//一方有二车,对方没有仕
	if(number[WHITE][CHE] == 2 && number[BLACK][SHI] == 0){
		pMat->material += 64 * (3 - number[BLACK][CHE]);
		//fen 2b1k1r2/R6R1/4b4/p1pr1n2p/6n2/2P3B1P/P8/1N2B4/4A4/4KA3 b - - 63 63
		//pMat->material += 32 + (OpenPhase - pMat->Bphase) * 2;
	}
	if(number[BLACK][CHE] == 2 && number[WHITE][SHI] == 0){
		pMat->material -= 64 * (3 - number[WHITE][CHE]);
		//pMat->material -= 32 + (OpenPhase - pMat->Rphase) * 2;
	}

	if(number[WHITE][CHE] == 2 && number[BLACK][SHI] == 1){
		pMat->material += 16 * (3 - number[BLACK][CHE]);
		//fen 2b1k1r2/R6R1/4b4/p1pr1n2p/6n2/2P3B1P/P8/1N2B4/4A4/4KA3 b - - 63 63
		//spao = 80 + s * (OpenPhase - i) / 32;
		//pMat->material += 16 + (OpenPhase - pMat->Bphase) ;
	}
	if(number[BLACK][CHE] == 2 && number[WHITE][SHI] == 1){
		pMat->material -= 16 * (3 - number[WHITE][CHE]);
		//pMat->material -= 16 + (OpenPhase - pMat->Rphase) ;
	}

	if(number[WHITE][CHE] != 0 && number[WHITE][PAO] != 0 && number[BLACK][XIANG] != 2){
		pMat->material += 24 * (2 - number[BLACK][XIANG]);
	}

	if(number[BLACK][CHE] != 0 && number[BLACK][PAO] != 0 && number[WHITE][XIANG] != 2){
		pMat->material -= 24 * (2 - number[WHITE][XIANG]);
	}


  for(turn = 0; turn < 2; turn ++){
	  opp              = turn ^ 0x1;  	  

	  //下面根据车的数量来调整相应的棋子的分数

      //*****************************************************************************	 
	  //我方2个车
	  if(number[turn][CHE] == 2){
		  //我方2个车, 对方2个车
		  if(number[opp][CHE] == 2){
			  const int Turn_Pawn_2Che2Che[10]   = {100, 96, 92, 88, 84, 72, 56, 52, 48, 0 }; //{100, 96, 88, 80, 72, 64, 56, 48, 40,  0};
			  const int Opp_Pawn_2Che2Che[10]    = {100, 96, 92, 88, 84, 72, 56, 52, 48, 0 };

			  const int Turn_Shi_2Che2Che[10]    = {100,100,100,100,100,100,100,100,100,100 };
			  const int Opp_Shi_2Che2Che[10]     = {100,100,100,100,100,100,100,100,100,100 };

			  const int Turn_Xiang_2Che2Che[10]  = {100,100,100,100,100,100,100,100,100,100 };
			  const int Opp_Xiang_2Che2Che[10]   = {100,100,100,100,100,100,100,100,100,100 };

			  if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 108; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 108;

				  rshi_val    = rshi_val   *  Turn_Shi_2Che2Che[B_2che1ma1pao]  / 100; 
				  bshi_val    = bshi_val   *   Opp_Shi_2Che2Che[R_2che1ma1pao]  / 100; 

				  rxiang_val  = rxiang_val * Turn_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
				  bxiang_val  = bxiang_val *  Opp_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 108; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 108;

				  bshi_val    = bshi_val   *  Turn_Shi_2Che2Che[R_2che1ma1pao]  / 100; 
				  rshi_val    = rshi_val   *   Opp_Shi_2Che2Che[B_2che1ma1pao]  / 100; 

				  bxiang_val  = bxiang_val * Turn_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
				  rxiang_val  = rxiang_val *  Opp_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
			  }

			  if((rma+rpao) == 2 && (bma+bpao) == 2){       //兵种齐全的要加分
				  if(rma==2){
					  pMat->material -= 16;
				  }
				  if(bma==2){                  //车马马没车马炮,车炮炮好
					  pMat->material += 16;
				  }

				  if(rpao == 2){
					  pMat->material -= 16;
				  }
				  if(bpao == 2){ 
					  pMat->material += 16;
				  }
			  }

			  if((rma+rpao) > (bma + bpao)){
				  if((bxiang+bshi) == 4){			//黑方是仕相全
					  pMat->material += ((rma + rpao) - (bma + bpao)) *   64;
				  }
				  else{
					  pMat->material += ((rma + rpao) - (bma + bpao)) *   96;
				  }
			  }
			  else if((rma+rpao) < (bma+bpao)){
				  if((rxiang+rshi) == 4){			//红方是仕相全
					  pMat->material += ((rma + rpao) - (bma + bpao)) *   64;
				  }
				  else{
					  pMat->material += ((rma + rpao) - (bma + bpao)) *   96;
				  }
			  }	

			  //2, 车马马炮,比车炮炮马少32分, 以免开始用炮换马
			  if((rma+rpao) == 3 && (bma+bpao) == 3){
				  if(rma == 2){
					  pMat->material -= 24;
				  }
				  if(bma == 2){
					  pMat->material += 24;
				  }
			  }

			  //如果一方只有二个车,一方多二个马炮, 则另一方要加分
			  if((rma+rpao) == 0){
				  if((bpao+bma) >= 2){
					  pMat->material -= 256;
				  }
			  }
			  if((bma+bpao) == 0){
				  if((rpao+rma) >= 2){
					   pMat->material += 256;
				  }
			  }

			  //fen 2bak4/4a3R/4b4/p1R1p4/6P2/2P6/P7P/r8/2r6/3CK1B2 w - - 0 0
              //2车对2车(马,炮), 马,炮方没有仕了
			  if((rma + rpao) <= 1 && rshi == 0){
				  pMat->material -= 96;
			  }

			  if((bma + bpao) <= 1 && bshi == 0){
				  pMat->material += 96;
			  }



			  //如果对方只有一个仕
			  if(bshi == 0){
				  pMat->material += rpawn_val  * (2 - bshi) * rpawn / 32;

				  //fen 2bak4/4a4/4b4/p3p2rp/2p6/5N3/P3P3P/2RRB1N2/5K3/4r4 w - - 7 7
				  if(bxiang <= 1 && bpao == 0 && rpawn != 0){
					  pMat->material += rpawn * 64;
				  }  
			  }
			  if(bshi <= 1){
				  pMat->material += rpawn_val  * (2 - bshi) * rpawn / 32;
			  }
			  if(rshi == 0){
				  pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 32;

				  //fen 2bak4/4a4/4b4/p3p2rp/2p6/5N3/P3P3P/2RRB1N2/5K3/4r4 w - - 7 7
				  if(rxiang <= 1 && rpao == 0 && bpawn != 0){
					   pMat->material -= bpawn * 64;
				  }
			  }
			  if(rshi <= 1){
				  pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 32;
			  }
			  //pMat->material += rpawn_val  * (2 - bshi) * rpawn / 32;
			  //pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 32;

			  break;
		  }
		  //我方2个车, 对方1个车
		  else if(number[opp][CHE] == 1){
			  const int Turn_Pawn_2Che2Che[10]   = {120,116,112,108,104,100, 96, 92, 88, 84};
			  const int Opp_Pawn_2Che2Che[10]    = {100, 96, 92, 88, 84, 80, 76, 72, 68, 64};

			  const int Turn_Shi_2Che2Che[10]    = {100,100,100,100,100,100,100,100,100,100 };
			  const int Opp_Shi_2Che2Che[10]     = {100,100,100,100,100,100,100,100,100,100 };

			  const int Turn_Xiang_2Che2Che[10]  = {100,100,100,100,100,100,100,100,100,100 };
			  const int Opp_Xiang_2Che2Che[10]   = {100,100,100,100,100,100,100,100,100,100 };

			  const int OtherNoPaoMaLessTwo[3] = {96,64,48};

			   if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

				  rshi_val    = rshi_val   *  Turn_Shi_2Che2Che[B_2che1ma1pao]  / 100; 
				  bshi_val    = bshi_val   *   Opp_Shi_2Che2Che[R_2che1ma1pao]  / 100; 

				  rxiang_val  = rxiang_val * Turn_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
				  bxiang_val  = bxiang_val *  Opp_Xiang_2Che2Che[R_2che1ma1pao] / 100; 

				  //fen 4kab2/4a4/4b4/7Rp/p1pn5/9/Pr2PR2P/4B4/2n1A4/2BA1K3 w - - 4 4
				  //这个要红好一些
				  if((bpao + bma) <= 2){
                       pMat->material += OtherNoPaoMaLessTwo[bpao + bma] * rpawn;
				  }
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;

				  bshi_val    = bshi_val   *  Turn_Shi_2Che2Che[R_2che1ma1pao]  / 100; 
				  rshi_val    = rshi_val   *   Opp_Shi_2Che2Che[B_2che1ma1pao]  / 100; 

				  bxiang_val  = bxiang_val * Turn_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
				  rxiang_val  = rxiang_val *  Opp_Xiang_2Che2Che[B_2che1ma1pao] / 100; 

				  if((rpao + rma) <= 2){
                       pMat->material -= OtherNoPaoMaLessTwo[rpao + rma] * bpawn;
				  }
			  }

			  if(turn == WHITE){
				  //fen 2bakn3/4a4/4b1c2/r8/3P5/7R1/P3P1R1c/9/4A4/2B1KA3 w - - 0 0
				  if(bpawn == 0){
					  pMat->material += rpawn * 32;
				  }
			  }
			  else{
				  if(rpawn == 0){
					  pMat->material -= bpawn * 32;
				  }
			  }
	
			  //如果对方只有一个仕
			  if(turn == WHITE){
				 //pMat->material += rpawn_val * (2 - bshi) * rpawn  / 32;

				 //一车换二炮,得加一些分
				 //if(rpao == 0){
					// pMat->material -= 32;
				 //}
				
				 if(rpao != 0 || rma != 0){
					 pMat->material += 64;
				 }
			  }
			  else{
				 if(bpao != 0 || bma != 0){

					 pMat->material -= 64;
				 }
			  }

			  //二车对车炮, 二炮方有兵
			  //fen 2Rakab2/9/4c4/p6r1/3P2p2/5R3/8P/9/9/3AK4 b - - 0 0
			  if(rche == 2 && (bma + bpao) == 1){
				   rpawn_val =  rpawn_val * 138 / 100; 
			  }

			  if(bche == 2 && (rma + rpao) == 1){
				   bpawn_val =  bpawn_val * 138 / 100; 
			  }



			  if(FALSE){
			  }
			  else if(turn == WHITE){
				  if((bshi + bxiang) != 4){
					  pMat->material += rpawn * Che2ToChe1ByNot4SX[bma+bpao];
				  }
			  }
			  else if(turn == BLACK){
				  if((rshi + rxiang) != 4){
					  pMat->material -= bpawn * Che2ToChe1ByNot4SX[rma+rpao];
				  }
			  }

			  //fen 2R2ab2/3ka4/8n/p3r4/3r4C/6N1P/P8/4B3N/4A4/3AK1B2 b - - 0 0
			  //如果双方是子力相同,
			  if(FALSE){
			  }
			  else if(turn == WHITE){
				  //if((bpao+bma) <= 3 && (rma+rpao) >= 1){
				  if((bpao + bma) - 2 <= (rma+rpao)){
					  if((bpao + bma) == 4){
						  pMat->material += rpawn * 4;
						  pMat->material += (rma+rpao) * 8;
					  }
					  if((bpao + bma) == 3){
						  pMat->material += rpawn * 8;
						  pMat->material += (rma+rpao) * 16;
					  }
					  if((bpao + bma) <= 2){
						  pMat->material += rpawn * 48;
						  pMat->material += (rma+rpao) * 16;
					  }
					  //pMat->material += rpawn * 32;
					  //pMat->material += (rma+rpao) * 32;
					  //pMat->material +=  64;
				  }
			  }
			  //fen 4kab2/4a4/4b1R2/p3p3p/9/5RP2/P3r3P/2n1B4/4A4/1cBAK4 w - - 2 2
			  else if(turn == BLACK){
				  if((rpao + rma) - 2 <= (bma+bpao)){
					  if((rpao + rma) == 4){
						  pMat->material -= bpawn * 4;
						  pMat->material -= (bma+bpao) * 8;
					  }
					  if((rpao + rma) == 3){
						  pMat->material -= bpawn * 8;
						  pMat->material -= (bma+bpao) * 16;
					  }
					  if((rpao + rma) <= 2){
						  pMat->material -= bpawn * 48;
						  pMat->material -= (bma+bpao) * 16;
					  }
					  //pMat->material -=  64;
				  }
			  }




			  //fen C1bak4/4a4/4b1n2/4n1R2/p7p/2P6/P3rpc1P/4B1R2/4A4/2BAK4 w - - 0 0
			  //这个应是一车方稍好一些
			  //
			  if(turn == WHITE){    //如果红方是二个车
				  if((rpao + rma) == 1){
					  if((bpao + bma) >= 3){
						  pMat->material -=  (bpao + bma) * 32;
					  }
				  }
				  if((rpao + rma) == 0){
					  if((bpao + bma) >= 2){
						  pMat->material -=  (bpao + bma) * 48;
					  }
				  }

				  //fen 2bakn3/4a4/4b1c2/r8/3P5/7R1/P3P1R1c/9/4A4/2B1KA3 w - - 0 0


				  //----------------------------------------------------
				  //fen 3ak1b2/4a4/4b1n2/3Rp4/8r/5R3/9/4B4/4A4/4KAB2 w - - 0 0
				  if(rma == 0 && rpao == 0 && rpawn == 0){
					  if(bshi == 2 && bxiang == 2 && bche != 0){
						  if(FALSE){
						  }
						  else if(bpao != 0){
							  pMat->material -=  Only2Che_To_2shi2xiang_1che_ByPao;
						  }
						  else if(bma  != 0){
							   pMat->material -= Only2Che_To_2shi2xiang_1che_ByMa;
						  }
						  else{
							  pMat->material  -= Only2Che_To_2shi2xiang_1che_NoPaoMa;
						  }
					  }
				  }
				  //----------------------------------------------------
			  }
			  else{
				  if((bpao + bma) == 1){
					  if((rpao + rma) >= 3){
						  pMat->material +=  (rpao + rma) * 32;
					  }
				  }
				  if((bpao + bma) == 0){
					  if((rpao + rma) >= 2){
						  pMat->material +=  (rpao + rma) * 48;
					  }
				  }

				  //----------------------------------------------------
				  //fen 3ak1b2/4a4/4b1n2/3Rp4/8r/5R3/9/4B4/4A4/4KAB2 w - - 0 0
				  if(bma == 0 && bpao == 0 && bpawn == 0){
					  if(rshi == 2 && rxiang == 2 && rche != 0){
						  if(FALSE){
						  }
						  else if(rpao != 0){
							  pMat->material  +=  Only2Che_To_2shi2xiang_1che_ByPao;
						  }
						  else if(rma  != 0){
							   pMat->material += Only2Che_To_2shi2xiang_1che_ByMa;
						  }
						  else{
							  pMat->material  += Only2Che_To_2shi2xiang_1che_NoPaoMa;
						  }
					  }
				  }
				  //----------------------------------------------------
			  }


			  break;
		  }
		  //我方2个车, 对方0个车
		  else if(number[opp][CHE] == 0){
       								   //             0   1   2   3   4   5   6   7   8   9 
			  const int Turn_Pawn_2Che2Che[10]   = {116,112,108,100, 96, 92, 88, 84, 80, 76};
			  const int Opp_Pawn_2Che2Che[10]    = { 96, 92, 88, 84, 80, 76, 72, 68, 64,  0};

			  const int Turn_Shi_2Che2Che[10]    = { 80, 84, 88, 92, 96, 96, 96, 96, 96, 96};
			  const int Opp_Shi_2Che2Che[10]     = {100,100,100,100,100,100,100,100,100,100};

			  const int Turn_Xiang_2Che2Che[10]  = { 80, 84, 88, 92, 96, 96, 96, 96, 96, 96};
			  const int Opp_Xiang_2Che2Che[10]   = {100,100,100,100,100,100,100,100,100,100};

			   if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

				  rshi_val    = rshi_val   *  Turn_Shi_2Che2Che[B_2che1ma1pao]  / 100; 
				  bshi_val    = bshi_val   *   Opp_Shi_2Che2Che[R_2che1ma1pao]  / 100; 

				  rxiang_val  = rxiang_val * Turn_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
				  bxiang_val  = bxiang_val *  Opp_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;

				  bshi_val    = bshi_val   *  Turn_Shi_2Che2Che[R_2che1ma1pao]  / 100; 
				  rshi_val    = rshi_val   *   Opp_Shi_2Che2Che[B_2che1ma1pao]  / 100; 

				  bxiang_val  = bxiang_val * Turn_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
				  rxiang_val  = rxiang_val *  Opp_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
			  }
	
       	      //如果对方只有一个仕
			  if(turn == WHITE){
				 pMat->material += rpawn_val * (2 - bshi) / 16;
			  }
			  else{
				 pMat->material -= bpawn_val * (2 - rshi) / 16 ;
			  }
			  break;
		  }
	  }
	  //*****************************************************************************
	  //我方1个车
	  else if(number[turn][CHE] == 1){
		  //我方1个车, 对方1个车
		  if(number[opp][CHE] == 1){ 
								       //             0   1   2   3   4   5   6   7   8   9 
			  const int Turn_Pawn_2Che2Che[10]   = {108, 104, 100, 96, 88, 80, 72, 68, 64, 58};
			  const int Opp_Pawn_2Che2Che[10]    = {108, 104, 100, 96, 88, 80, 72, 68, 64, 58};

			  //const int Turn_Shi_2Che2Che[10]    = { 64,  68,  72,  76, 80, 84, 96, 96, 96,  0};
			  //const int Opp_Shi_2Che2Che[10]     = { 64,  68,  72,  76, 80, 84, 96, 96, 96,  0};

			  //const int Turn_Xiang_2Che2Che[10]  = { 68,  72,  76,  80, 84, 88, 92, 96, 96,  0};
			  //const int Opp_Xiang_2Che2Che[10]   = { 68,  72,  76,  80, 84, 88, 92, 96, 96,  0};

			  const int Turn_Shi_2Che2Che[10]    = { 72,  76, 80, 84, 96, 96, 96,96,96,96};
			  const int Opp_Shi_2Che2Che[10]     = { 72,  76, 80, 84, 96, 96, 96,96,96,96};

			  const int Turn_Xiang_2Che2Che[10]  = { 76,  80, 84, 88, 92, 96, 96, 96,96,96};
			  const int Opp_Xiang_2Che2Che[10]   = { 76,  80, 84, 88, 92, 96, 96, 96,96,96};

			  if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

				  rshi_val    = rshi_val   *  Turn_Shi_2Che2Che[B_2che1ma1pao]  / 100; 
				  bshi_val    = bshi_val   *   Opp_Shi_2Che2Che[R_2che1ma1pao]  / 100; 

				  rxiang_val  = rxiang_val * Turn_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
				  bxiang_val  = bxiang_val *  Opp_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;

				  bshi_val    = bshi_val   *  Turn_Shi_2Che2Che[R_2che1ma1pao]  / 100; 
				  rshi_val    = rshi_val   *   Opp_Shi_2Che2Che[B_2che1ma1pao]  / 100; 

				  bxiang_val  = bxiang_val * Turn_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
				  rxiang_val  = rxiang_val *  Opp_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
			  }

			  //fen 2bk1a3/4a4/6c2/9/p1b3N2/9/P3P3P/6r2/4A4/1R1AK4 w - - 0 0
			  //要体现出缺相怕炮攻的形
			  if(rpao >= 1 && rshi == 2 && rxiang == 2){
				  if(bpao == 0 && bma <= 1 && bxiang == 0 && bshi == 2){
					  pMat->material += 64;
				  }
			  }
			  if(bpao >= 1 && bshi == 2 && bxiang == 2){
				  if(rpao == 0 && rma <= 1 && rxiang == 0 && rshi == 2){
					  pMat->material -= 64;
				  }
			  }

			  //如果一方的兵比另一方多二个
			  if((bma + bpao) == (rma + rpao)){
				  if((rpawn - bpawn) >= 2){
					  pMat->material += 32;
				  }
				  if((bpawn - rpawn) >= 2){
					  pMat->material -= 32;
				  }
			  }

			  //fen 3a1k3/4a4/4P4/1r7/p3P4/9/P7p/4BA3/1c7/1RBAK4 w - - 0 0
              //车方只有车兵了
			  if((rpao + rma) == 0){
				  if(bshi == 2){
					  pMat->material -= (bma+bpao) * 64;
					  pMat->material -=  bpawn * 32;
				  }
			  }
			  if((bpao + bma) == 0){
				  if(rshi == 2){
					  pMat->material += (rma+rpao) * 64;
					  pMat->material +=  rpawn * 32;
				  }
			  }

			  //因为炮的位置分要低一些,所以2炮+马方要加一些分			  
			  //fen 2bak4/4a4/2N1b3n/2c3p2/3r1P2c/p3R4/3N5/1C2B4/4A4/4KAB2 r
			  if(rpao == 2 && rma != 0){
				  pMat->material += 64;
			  }
			  if(bpao == 2 && bma != 0){
				  pMat->material -= 64;
			  }

			  //fen 4ka3/4a4/4b4/N7r/P3P2c1/2B4n1/R6N1/4B4/9/3AK4 w - - 0 0
			  //车２马要比车马炮减一些分
			  if(rpao >= 1 && rma >= 1 && bpao == 0){
				  pMat->material += 48;
			  }
			  if(bpao >= 1 && bma >= 1 && rpao == 0){
				  pMat->material -= 48;
			  }

			  //如果一方只有一个车,另一方有其它的子力,还要加分
			  if((bpao + bma + bpawn) == 0){
				  pMat->material += (rpao + rma) * 96;
				  pMat->material +=  rpawn * 64;
			  }
			  if((rpao + rma + rpawn) == 0){
				  pMat->material -= (bpao + bma) * 96;
				  pMat->material -=  bpawn * 64;
			  }


			  //fen 2baka3/9/4b4/pRC1p4/8p/4n1B2/r5p2/1N7/4A4/3AK1B2 w - - 4 4
			  //如果大家是3个大子,则多二兵一方还要加一些分
			  if(R_chemapao == B_chemapao && R_chemapao <= 3){
				 if((rpawn - bpawn) >= 2){
					  pMat->material += 32;
				  }
				  if((bpawn - rpawn) >= 2){
					  pMat->material -= 32;
				  }
			  }

			  //如果对方只有车马,就要加分
			  if(rma == 1 && rpao == 0 && rpawn == 0){
				  if((bma + bpao) >= 1 && bpawn > 0 && (bshi == 2 && bxiang == 2)){
					  pMat->material -= bpawn * 32;
				  }
			  }
			  if(bma == 1 && bpao == 0 && bpawn == 0){
				  if((rma + rpao) >= 1 && rpawn > 0 && (rshi == 2 && rxiang == 2)){
					  pMat->material += rpawn * 32;
				  }
			  }

			  //==================================================================================
			  //其它情况
			  //1，兵种齐全要加分
			  if((rma+rpao) == 2 && (bma+bpao) == 2){       //兵种齐全的要加分
				  if(rma==2){
					  pMat->material -= 32;
				  }
				  if(bma==2){                  //车马马没车马炮,车炮炮好
					  pMat->material += 32;
				  }

				  if(rpao == 2){
					  pMat->material -= 32;
				  }
				  if(bpao == 2){ 
					  pMat->material += 32;
				  }
			  }
			  //2, 我方还多大子
			  ////红方的大子比黑方的大子多
			  if((rma+rpao) > (bma + bpao)){
				  if((bxiang+bshi) == 4){			//黑方是仕相全
					  pMat->material += ((rma + rpao) - (bma + bpao)) *   96;
				  }
				  else{
					  pMat->material += ((rma + rpao) - (bma + bpao)) *  128;
				  }
			  }
			  else if((rma+rpao) < (bma+bpao)){
				  if((rxiang+rshi) == 4){			//红方是仕相全
					  pMat->material += ((rma + rpao) - (bma + bpao)) *   96;
				  }
				  else{
					  pMat->material += ((rma + rpao) - (bma + bpao)) *  128;
				  }
			  }	
              //fen 2b1ka3/4a4/2n1bc3/5N3/R1p1P4/9/P4r3/4BN3/4A4/2B1KA3 w - - 0 1
			  //fen 2b1ka3/n3a4/4bc3/R4N3/p1p1P4/9/r8/4BN3/4A4/2B1KA3 b
			  //如果对方是车炮马２兵，我方是车2马1兵，对方要加分		
			  if(FALSE){
			  }
			  else if(rma >= 1 && rpao >= 1 && bpao == 0 && bma <= 2){
				  if(rpawn >= 2 && bpawn <= 1){
					  pMat->material += (rpawn-bpawn) * 32;

				  }
			  }
			  else if(bma >= 1 && bpao >= 1 && rpao == 0 && rma <= 2){
				  if(bpawn >= 2 && rpawn <= 1){
					  pMat->material -= (bpawn-rpawn) * 32;
				  }
			  }
		


			  //goto  OutEval;
			  //如果对方只有一个仕
			  //pMat->material += rpawn_val  * (2 - bshi) * rpawn / 64;
			  //pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 64;

			  //

			  //if(turn == WHITE){
				 //pMat->material += rpawn_val /4 * (2 - bshi) * rpawn;
			  //}
			  //else{
				 //pMat->material -= bpawn_val /4 * (2 - rshi) * bpawn;
			  //}
			  break;
			  //==================================================================================
		  }
		  //我方1个车, 对方0个车
		  else if(number[opp][CHE] == 0){										   //无车
			                             //           0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
			  //const int Turn_Pawn_2Che2Che[16]   = {164,156,148,140,132,124,116,108,100, 96, 80, 76, 72, 70, 70, 70};
			  //const int Opp_Pawn_2Che2Che[16]    = {148,140,132,124,116,108,100, 96, 80, 76, 72, 68, 68, 68, 68, 68};

			  //const int Turn_Shi_2Che2Che[16]    = { 56, 60, 64, 68, 72, 78, 82, 86, 90, 90, 90, 90, 90, 90, 90, 90};
			  //const int Opp_Shi_2Che2Che[16]     = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

			  //const int Turn_Xiang_2Che2Che[16]  = { 60, 64, 68, 72, 78, 82, 86, 90, 90, 90, 90, 90, 90, 90, 90, 90};
			  //const int Opp_Xiang_2Che2Che[16]   = { 68, 72, 78, 82, 86, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
								       //             0   1   2   3   4   5   6   7   8   9 
			  const int Turn_Pawn_2Che2Che[10]   = {124, 120,116,112,108,104,100, 92, 88, 0};
			  const int Opp_Pawn_2Che2Che[10]    = {100,  96, 92, 88, 84, 80, 76, 72, 68, 0};

			  const int Turn_Shi_2Che2Che[10]    = { 76, 80, 84, 96, 96, 96, 96, 96,96,   0};
			  const int Opp_Shi_2Che2Che[10]     = { 84, 86, 88, 90, 92, 94, 96, 98,100,  0};

			  const int Turn_Xiang_2Che2Che[10]  = { 76, 80, 84, 96, 96, 96, 96, 96, 96,  0};
			  const int Opp_Xiang_2Che2Che[10]   = { 84, 86, 88, 90, 92, 94, 96, 98,100,  0};
			 
			  const int CheAdd = 48;


			  if(FALSE){
			  }
			  else if(turn == WHITE){

			      pMat->material += CheAdd;

				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

				  rshi_val    = rshi_val   *  Turn_Shi_2Che2Che[B_2che1ma1pao]  / 100; 
				  bshi_val    = bshi_val   *   Opp_Shi_2Che2Che[R_2che1ma1pao]  / 100; 

				  rxiang_val  = rxiang_val * Turn_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
				  bxiang_val  = bxiang_val *  Opp_Xiang_2Che2Che[R_2che1ma1pao] / 100; 

				  
			  }
			  else if(turn == BLACK){

				  pMat->material -= CheAdd;

				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;

				  bshi_val    = bshi_val   *  Turn_Shi_2Che2Che[R_2che1ma1pao]  / 100; 
				  rshi_val    = rshi_val   *   Opp_Shi_2Che2Che[B_2che1ma1pao]  / 100; 

				  bxiang_val  = bxiang_val * Turn_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
				  rxiang_val  = rxiang_val *  Opp_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
			  }	

			  //如果双方的子是相同的.
			  if(FALSE){
			  }
			  else if(turn == WHITE){
				  if((rma + rpao) >= (bpao + bma - 2)){  //双方是子力平衡的,一车抵二个
                     pMat->material += rpawn * 64;
					 pMat->material += (rma+rpao) * 16;

					 //fen 2b1kab1C/4a4/9/8P/4r4/p5P2/7c1/3CB1N2/4A4/4KAB2 w - - 14 14
					 if(rshi == 2 && rxiang == 2){
						 pMat->material += (rma+rpao) * 64;
						 pMat->material += rpawn * 32;
					 }
				  }
			  }
			  else if(turn == BLACK){
				  if((bma + bpao) >= (rpao + rma - 2)){  //双方是子力平衡的,一车抵二个
                     pMat->material -= bpawn * 64;
					 pMat->material -= (bma+bpao) * 16;
					  //fen 2b1kab1C/4a4/9/8P/4r4/p5P2/7c1/3CB1N2/4A4/4KAB2 w - - 14 14
					 if(bshi == 2 && bxiang == 2){
						 pMat->material -= (bma+bpao) * 64;
						 pMat->material -= bpawn * 32;
					 }
				  }
			  }


			  //fen 4k1b2/9/2n1bR3/p5c2/4p4/9/9/4B4/4A4/2BA1K3 w - - 0 0
              //车方只有一个车了
			  if(FALSE){
			  }
			  else if(turn == WHITE){
				  if((rpao + rma + rpawn) == 0){
					  if((bpao + bma) >= 2){
						  if(bshi == 2 || bxiang == 2){
                              pMat->material -= (bpao + bma) * 32;
							  pMat->material -= bpawn * 32;
						  }
					  }
				  }

				  //
			  }
			  else if(turn == BLACK){
				  if((bpao + bma + bpawn) == 0){
					  if((rpao + rma) >= 2){
						  if(rshi == 2 || rxiang == 2){
                              pMat->material += (rpao + rma) * 32;
							  pMat->material += rpawn * 32;
						  }
					  }
				  }
			  }
                

			  //fen 4k1b2/5C3/4baN2/p1n3c1p/3N5/9/P7r/4B4/4C4/3AKAB2 w - - 3 3
			  //如果有车方的其它的子大于二个,则也要加分
			  if(FALSE){
			  }
			  else if(turn == WHITE){
				  if((rma+rpao) >= 2){
					  pMat->material += 32 * rpawn;
				  }
			  }
			  else if(turn == BLACK){
				   if((bma+bpao) >= 2){
					  pMat->material -= 32 * bpawn;
				  }
			  }

			   //如果对方只有一个仕
			  if(FALSE){
			  }
			  else if(turn == WHITE){
				 pMat->material += rpawn_val  * (2 - bshi) * rpawn / 16;
			  }
			  else if(turn == BLACK){
				 pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 16;
			  }



			  // 看一下对方的马炮数量
			  if(turn == WHITE){
				  //pMat->material += 64 * (rma + rpao);

				  if((rma + rpao ) == 0){   //有车方只有一个车
					  if((bshi + bxiang) == 4){
						  pMat->material += 有车方只有一个车时的加分a;
					  }
					  else if(bshi == 2 || bxiang == 2){
						  pMat->material += 有车方只有一个车时的加分b;
					  }
					  else{
						  pMat->material += 有车方只有一个车时的加分c;
					  }
				  }
				  else{
					  if((bshi + bxiang) == 4){
						  pMat->material += 有车方只有一个车时的加分a;
					  }
					  else{
						  //if(bshi == 2 || bxiang == 2) && bpao != 
						  pMat->material += 有车方只有一个车时的加分c;
					  }

					  //如果对方只有二个大子(马炮),则车方要另分
					  if((bma+bpao) <= 2){
						  pMat->material += 64;
					  }
				  }				  
			  }
			  else{
				  //pMat->material -= 64 * (bma + bpao);
				  if((bma + bpao ) == 0){   //有车方只有一个车
					  if((rshi + rxiang) == 4){
						  pMat->material -= 有车方只有一个车时的加分a;
					  }
					  else if(rshi == 2 || rxiang == 2){
						  pMat->material -= 有车方只有一个车时的加分b;
					  }
					  else{
						  pMat->material -= 有车方只有一个车时的加分c;
					  }
				  }
				  else{
					  if((rshi + rxiang) == 4){
						  pMat->material -= 有车方只有一个车时的加分a;
					  }
					  else{
						  pMat->material -= 有车方只有一个车时的加分c;
					  }

					  //如果对方只有二个大子(马炮),则车方要另分
					  if((rma+rpao) <= 2){
						  pMat->material -= 64;
					  }
				  }				  
			  }
			  //fen 4kab2/9/4ba1n1/4p3p/p1p6/c4R3/4P3P/4B4/4A4/2BAK4 w - - 2 2
              //这个应是黑好一些


			  if(turn == WHITE){    //红方有车,黑方没有车
				  if((rma + rpao) == 1){
					  if((bma + bpao) == 4){
						  pMat->material -= (bma + bpao) * 32;
					  }
				  }
				  if((rma + rpao) == 0){
					  if((bma + bpao) >= 3){
						  pMat->material -= (bma + bpao) * 48;
					  }
				  }

				  //车1个以上的子,对马炮3个以下的子, 车方的兵要要加分
				  //fen 3akab2/2C6/4b4/R8/2pP4p/9/P4n2P/4B4/3K2nc1/3A1AB2 w - - 4 4
				  if((rma+rpao) >= 1){
					  if((bma + bpao) <= 3){
						  pMat->material += rpawn * 32;
					  }
				  }
			  }
			  else{

				  //车1个以上的子,对马炮3个以下的子, 车方的兵要要加分
				  if((bma+bpao) >= 1){
					  if((rma + rpao) <= 3){
						  pMat->material -= bpawn * 32;
					  }
				  }


				  if((bma + bpao) == 1){
					  if((rma + rpao) == 4){
						  pMat->material += (rma + rpao) * 32;
					  }
				  }
				  if((bma + bpao) == 0){
					  if((rma + rpao) >= 3){
						  pMat->material += (rma + rpao) * 48;
					  }
				  }
			  }

			  //fen 6b1C/4ak3/5aN2/9/9/9/P5P2/4B4/3c5/2rCKA3 w - - 1 1
			  if(turn == WHITE){
				  if((rpao+rma) >= 1 && (bpao+bma) <= 3){
					  if((bshi + bxiang) <= 3){
						  pMat->material += (4 - (bshi+bxiang)) * 48;
					  }
				  }
			  }
			  else{
				  if((bpao+bma) >= 1 && (rpao+rma) <= 3){
					  if((rshi + rxiang) <= 3){
						  pMat->material -= (4 - (rshi+rxiang)) * 48;
					  }
				  }
			  }


			  if(turn == WHITE){
				  if((rma + rpao) <= 1){
					  if((bma+bpao) >= 3){
						  if(bshi == 2 && bxiang == 2){
							  pMat->material -= (bma+bpao) * Che_Only_1Pao_Or_1Ma_AddByOther_More_3MaPao;
							  pMat->material -=  bpawn * 32;
						  }
					  }
				  }
			  }
			  else{
				  if((bma + bpao) <= 1){
					  if((rma+rpao) >= 3){
						  if(rshi == 2 && rxiang == 2){
							  pMat->material += (rma+rpao) * Che_Only_1Pao_Or_1Ma_AddByOther_More_3MaPao;
							  pMat->material +=  rpawn * 32;
						  }
					  }
				  }
			  }


			  if(turn == WHITE){
                  //有车方只有车兵以下
				  if(rma == 0 && rpao == 0){
					  if(rpawn <= 1){
						  if(bshi == 2 && bxiang == 2){
							  //车兵能胜马仕相全，但不能胜炮仕相全
							  if(bma == 1 && bpao == 0){
								  pMat->material -= Che_Only_Less_OnePawn_ByOnly1Ma;
							  }
							  if(bpao == 1 && bma == 0){
								  pMat->material -= Che_Only_Less_OnePawn_ByOnly1Pao;
							  }
							  if((bma + bpao) >= 2){
								  pMat->material -= Che_Only_Less_OnePawn_ByPaoMa * (bma+bpao);
							  }
							  //再加上对方兵的分
							  pMat->material -= bpawn * Che_Only_Less_OnePawn_ByPawn;
						  }
					  }
				  }
			  }
			  else{
				   //有车方只有车兵以下
				  if(bma == 0 && bpao == 0){
					  if(bpawn <= 1){
						  if(rshi == 2 && rxiang == 2){
							  //车兵能胜马仕相全，但不能胜炮仕相全
							  if(rma == 1 && rpao == 0){
								  pMat->material += Che_Only_Less_OnePawn_ByOnly1Ma;
							  }
							  if(rpao == 1 && rma == 0){
								  pMat->material += Che_Only_Less_OnePawn_ByOnly1Pao;
							  }
							  if((rma + rpao) >= 2){
								  pMat->material += Che_Only_Less_OnePawn_ByPaoMa * (rma+rpao);
							  }
							  //再加上对方兵的分
							  pMat->material += rpawn * Che_Only_Less_OnePawn_ByPawn;
						  }
					  }
				  }
			  }
			  break;
		  }
	  }
	  //*****************************************************************************
	  //我方0个车
	  else if(number[turn][CHE] == 0){
		  //我方0个车, 对方0个车
		  if(number[opp][CHE] == 0){
	    	                            //           0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
			  const int Turn_Pawn_2Che2Che[10]   = {128,124,120,116,112,108, 100, 92, 88, 0};
			  const int Opp_Pawn_2Che2Che[10]    = {128,124,120,116,112,108, 100, 92, 88, 0};

			  const int Turn_Shi_2Che2Che[10]    = { 72, 76, 80, 84, 96, 96, 96, 96, 96, 96};
			  const int Opp_Shi_2Che2Che[10]     = { 72, 76, 80, 84, 96, 96, 96, 96, 96, 96};

			  const int Turn_Xiang_2Che2Che[10]  = { 72, 76, 80, 84, 96, 96, 96, 96, 96, 96};
			  const int Opp_Xiang_2Che2Che[10]   = { 72, 76, 80, 84, 96, 96, 96, 96, 96, 96};

			  if(turn == WHITE){

				  //pMat->material += CheAdd;

				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

				  rshi_val    = rshi_val   *  Turn_Shi_2Che2Che[B_2che1ma1pao]  / 100; 
				  bshi_val    = bshi_val   *   Opp_Shi_2Che2Che[R_2che1ma1pao]  / 100; 

				  //fen 4k4/4a4/4ba2N/N4P3/P1b3n2/c8/5p3/2nA5/4A2C1/4K4 b - - 0 0
				  //缺相怕炮攻．
				  rxiang_val  = rxiang_val *  (Turn_Xiang_2Che2Che[B_2che1ma1pao]) / 100; 
				  bxiang_val  = bxiang_val *  (Opp_Xiang_2Che2Che[R_2che1ma1pao] ) / 100; 
			  }
			  else{

				  //pMat->material -= CheAdd;

				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;

				  bshi_val    = bshi_val   *  Turn_Shi_2Che2Che[R_2che1ma1pao]  / 100; 
				  rshi_val    = rshi_val   *   Opp_Shi_2Che2Che[B_2che1ma1pao]  / 100; 

				  bxiang_val  = bxiang_val * Turn_Xiang_2Che2Che[R_2che1ma1pao] / 100; 
				  rxiang_val  = rxiang_val *  Opp_Xiang_2Che2Che[B_2che1ma1pao] / 100; 
			  }

			  //如果双方都只有少二个大子了,则双方的兵的价值要加大
			  if((rma+rpao) == 2){
				  bpawn_val = bpawn_val * 118 / 100;
			  }
			  if((bma+bpao) == 2){
				  rpawn_val = rpawn_val * 118 / 100;
			  }

			  if((rma+rpao) == 1){
				  bpawn_val = bpawn_val * 128 / 100;
			  }
			  if((bma+bpao) == 1){
				  rpawn_val = rpawn_val * 128 / 100;
			  }

			  //因为炮的位置分要低一些,所以2炮+马方要加一些分
			  //fen 2bak4/4a4/2N1b3n/2c3p2/5P2c/p8/3N5/1C2B4/4A4/4KAB2 w - - 17 17
			  if(rpao == 2 && rma != 0){
				  pMat->material += 64;
			  }
			  if(bpao == 2 && bma != 0){
				  pMat->material -= 64;
			  }

			  //如果一方的兵比另一方多二个
			  if((bma + bpao) == (rma + rpao)){
				  if((rpawn - bpawn) >= 2){
					  pMat->material += 48;
				  }
				  if((bpawn - rpawn) >= 2){
					  pMat->material -= 48;
				  }
			  }

			  //如果大家是3个大子,则多二兵一方还要加一些分
			  if(R_chemapao == B_chemapao && R_chemapao <= 2){
				 if((rpawn - bpawn) >= 2){
					  pMat->material += 64;
				  }
				  if((bpawn - rpawn) >= 2){
					  pMat->material -= 64;
				  }
			  }

			  if((rma+rpao) == 2 && (bma+bpao) == 2){       //兵种齐全的要加分
				  if(rma==2){
					  pMat->material -= 32;
				  }
				  if(bma==2){                  //马马没马炮,炮炮好
					  pMat->material += 32;
				  }

				  //如果双方仕相全，且双方的兵少于２个
				  if(rshi == 2 && rxiang == 2 && bshi == 2 && bxiang == 2 && rpawn <= 2 && bpawn <= 2){
				  }
				  else{
					  if(rpao == 2){
						  if(rshi == 0){
							  pMat->material -= 96;
						  }
						  else{
							  pMat->material -= 64;
						  }
					  }
					  if(bpao == 2){ 
						  if(bshi == 0){
							  pMat->material +=  96;
						  }
						  else{
							  pMat->material +=  64;
						  }
					  }
				  }
			  }

			  //fen 3k1ab2/4a4/4b4/8C/2p1c4/P8/6p2/4B4/5K3/6C2 b - - 1 1
			  //2炮对1炮
			  if(bpao <= 1 && bma == 0){  //黑方只有一个炮了
				  pMat->material += (rpao+rma) * 64;
			  }
			  if(rpao <= 1 && rma == 0){  //黑方只有一个炮了
				  pMat->material -= (bpao+bma) * 64;
			  }

			  //fen 3ak4/9/1N1ab4/p8/2bn4p/2B3B2/5C3/9/4A4/5K3 b - - 0 0
			  if(bpao == 0 && bma <= 1){
				  pMat->material += (rpao+rma) * 64;
			  }
			  if(rpao == 0 && rma <= 1){
				  pMat->material -= (bpao+bma) * 64;
			  }

			  //炮方没有仕了，马方有兵
			  if(bma == 0 && bpao <= 1 && bshi == 0 && rma >= 0 && rpawn != 0){
				   pMat->material += 80;
			  }
			  if(rma == 0 && rpao <= 1 && rshi == 0 && bma >= 0 && bpawn != 0){
				   pMat->material -= 80;
			  }

			  //2, 我方还多大子

			  pMat->material += 128 * (rma + rpao);
			  pMat->material -= 128 * (bma + bpao);

			  pMat->material += rpawn_val  * (2 - bshi) * rpawn / 32;
			  pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 32;

			  break;
		  }
	  }// else if(number[turn][CHE] == 0){
  }

  //以下评价双方空炮的能力基础分
  //*****************************************************************************************************
  //pMat->BR_KongPaoScore  = 0;
  //EV->king_safety[BLACK] -= Zhong_KongPaoSafe[board->pMat->BR_KongPaoScore & 0x0f];   //红方炮要 & 0x0f
//#define Pao_Max_Base  = 15;
//#define Pao_Min_Base  =  0;

//#define TOTAL_PAO_ATT  22  // 2 * 4 + 2 * 2 + 2 * 2 + 1 * 5 = 21

  //for(turn = 0; turn < 2; turn ++){
	 // 

	 // opp = turn ^ 0x1;

	 //  kpao = 0;

	 //att  = number[turn][CHE] * 4 + number[turn][PAO] * 2 + number[turn][MA] * 2 + number[turn][PAWN] * 1;

	 // //if(FALSE){
	 // //}

	 // ////走子方有二个车
	 // //else if(number[turn][CHE] == 2){		
  // //                           
		// // //const int Pao2Che[22] 
		// // ////  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,
		// // //= {10,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,15 };

		// // const int che2max = 15;
		// // const int che2min = 12;		  
  //
		// // // y = ax + b;  a = (y - b) /x 

		// // kpao = (che2max - che2min) * att / TOTAL_PAO_ATT + che2min;
  // //       
		// // 
	 // //}

	 // ////走子方有1个车
	 // //else if(number[turn][CHE] == 1){
		// // 


		// // kpao = (che1max - che1min) * att / TOTAL_PAO_ATT + che1min;

		// // if(number[turn][MA] == 0){
		//	//  kpao = kpao * 2 / 3;
		//	//  if(number[turn][PAWN] == 0){
		//	//	  kpao = kpao * 2 / 3;				 
		//	//  }
		//	//  if(number[opp][SHI] == 0){   //有炮要留他仕
		//	//	  kpao = kpao * 2 / 3;
		//	//  }
		// // }
	 // //}

	 // ////炮方没有车了
	 // //else{ 

		// // const int che0max =   8;
		// // const int che0min =   0;

		// // kpao = (che0max - che0min) * att / TOTAL_PAO_ATT + che0min;

		// // if(number[turn][MA] == 0){
		//	//  kpao = kpao * 2 / 3;
		//	//  if(number[turn][PAWN] == 0){
		//	//	  kpao = kpao * 2 / 3;				 
		//	//  }
		//	//  if(number[opp][SHI] == 0){   //有炮要留他仕
		//	//	  kpao = kpao * 2 / 3;
		//	//  }
		// // }
	 // //}

	 // //EV->king_safety[BLACK] -= Zhong_KongPaoSafe[board->pMat->BR_KongPaoScore & 0x0f];   //红方炮要 & 0x0f

	 // if(turn == WHITE){
		//  //pMat->BR_KongPaoScore &= 0x0f;
		//  pMat->R_KongPaoScore = (uint8)kpao;
	 // }
	 // else{
		//  //pMat->BR_KongPaoScore &= 0xf0;
		//  pMat->B_KongPaoScore = (uint8)kpao;
	 // }
  //}

  //*****************************************************************************************************

  



//OutEval:

  pMat->material  += (rpawn  * rpawn_val 
	  +  rpao   * rpao_val
	  +  rma    * rma_val
	  +  rxiang * rxiang_val
	  +  rshi   * rshi_val 
	  +  rche   * rche_val);    

  pMat->material -=  (bpawn  * bpawn_val
	  +  bpao   * bpao_val
	  +  bma    * bma_val
	  +  bxiang * bxiang_val
	  +  bshi   * bshi_val  
	  +  bche   * bche_val); 

  int not_pawn_material  = (
	    rpao * rpao_val + rma * rma_val + rche * rche_val
	  + bpao * bpao_val + bma * bma_val + bche * bche_val);


  const Value MidgameLimit = Value(15581/2);
  const Value EndgameLimit = Value(3998/2);

  if (not_pawn_material >= MidgameLimit){
	  pMat->phase = PHASE_MIDGAME;
  }
  else if (not_pawn_material <= EndgameLimit){
	  pMat->phase = PHASE_ENDGAME;
  }
  else{
	  pMat->phase = (((not_pawn_material - EndgameLimit) * 128) / (MidgameLimit - EndgameLimit));
  }

  //  最后, 保存一下
  pMat->material = (pMat->material * MaterialWeight) / 256; 

  //pMat->Rphase = RegPhase[WHITE];
  //pMat->Bphase = RegPhase[BLACK];



#ifdef  USE_ASSERT
  ////  在这儿确认一下,
  //if(number[WHITE][CheMaPaoPawn] == 0){
  //    ASSERT(pMat->material <= 0);
  //    //if(pMat->material >= 0){
  //    //   int test = 0;
  //    //}
  //}
  //if(number[BLACK][CheMaPaoPawn] == 0){
  //    ASSERT(pMat->material >= 0);
  //    //if(pMat->material <= 0){
  //    //  int test = 0;
  //    //}
  //}
#endif



}

void InitPreMatinfo(void){

		__int64 off;
	int rpao,rma,rche,rxiang,rshi,rpawn;
	int bpao,bma,bche,bxiang,bshi,bpawn;

	void (*fp)(const typePOS *POSITION, EvalInfo *ei);

    premat_t *Porg   =   &PreMatInfo[0][0][0][0][0][0][0][0][0][0][0][0];

    MatAddress[RKING]  =  0;
    MatAddress[RPAWN]  = (int)(&PreMatInfo[1][0][0][0][0][0][0][0][0][0][0][0] - Porg);
    MatAddress[RPAO]   = (int)(&PreMatInfo[0][0][0][0][1][0][0][0][0][0][0][0] - Porg);
    MatAddress[RCHE]   = (int)(&PreMatInfo[0][0][1][0][0][0][0][0][0][0][0][0] - Porg);
    MatAddress[RMA]    = (int)(&PreMatInfo[0][0][0][1][0][0][0][0][0][0][0][0] - Porg);
    MatAddress[RSHI]   = (int)(&PreMatInfo[0][0][0][0][0][1][0][0][0][0][0][0] - Porg);
    MatAddress[RXIANG] = (int)(&PreMatInfo[0][0][0][0][0][0][1][0][0][0][0][0] - Porg);

    MatAddress[BKING]  =  0;
    MatAddress[BPAWN]  = (int)(&PreMatInfo[0][1][0][0][0][0][0][0][0][0][0][0] - Porg);
    MatAddress[BPAO]   = (int)(&PreMatInfo[0][0][0][0][0][0][0][0][0][1][0][0] - Porg);
    MatAddress[BCHE]   = (int)(&PreMatInfo[0][0][0][0][0][0][0][1][0][0][0][0] - Porg);
    MatAddress[BMA]    = (int)(&PreMatInfo[0][0][0][0][0][0][0][0][1][0][0][0] - Porg);
    MatAddress[BSHI]   = (int)(&PreMatInfo[0][0][0][0][0][0][0][0][0][0][1][0] - Porg);
    MatAddress[BXIANG] = (int)(&PreMatInfo[0][0][0][0][0][0][0][0][0][0][0][1] - Porg);

             //                        //兵 卒 车 马 炮 士 相 车 马 炮 士 相 
             //  preMT_t PreMatInfo[6][6][3][3][3][3][3][3][3][3][3][3];
             //                            6 *6 *3 *3 *3 *3 *3 *3 *3 *3 *3 *3

	MARR = (MARR_t *)malloc(sizeof(MARR_t));

	//MARR = new 

    for(rpawn = 0; rpawn < 6; rpawn ++){
        for(bpawn = 0; bpawn < 6; bpawn ++){
            for(rche = 0; rche < 3; rche ++){
                for(rma = 0; rma < 3; rma++){
                    for(rpao = 0; rpao < 3; rpao ++){
                        for(rshi = 0; rshi < 3; rshi ++){
                            for(rxiang = 0; rxiang < 3; rxiang ++){
                                for(bche = 0; bche < 3; bche ++){
                                    for(bma = 0; bma < 3; bma ++){
                                        for(bpao = 0; bpao < 3; bpao ++){
                                            for(bshi = 0; bshi < 3; bshi ++){
                                                for(bxiang = 0; bxiang < 3; bxiang++){

													premat_t *pMat =  &PreMatInfo[rpawn][bpawn][rche][rma][rpao][rshi][rxiang][bche][bma][bpao][bshi][bxiang];

													InitOnePreMat( pMat,rpawn, bpawn, rche, rma, rpao, rshi, rxiang, bche, bma, bpao, bshi, bxiang);

													off = pMat - Porg;	
													MARR->a[rpawn][bpawn][rche][rma][rpao][rshi][rxiang][bche][bma][bpao][bshi][bxiang] = (int)off;

													if(rche == 0 && rpao == 0 && rma == 0 && rpawn == 0 && bche == 0 && bpao == 0 && bma == 0 && bpawn == 0){
														funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][rshi][rxiang][bche][bma][bpao][bshi][bxiang]] = m_MT_MUST_DRAW;
													}
													else{
														funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][rshi][rxiang][bche][bma][bpao][bshi][bxiang]] = m_MT_NONE_16;
														//funMat[MARR->marr[0][0][0][0][0][2][2][0][0][0][2][2]]
													}

													//红兵 黑卒 红车 红马 红炮 红士 红相 黑车 黑马 黑炮 黑士 黑相 													
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


	//888888888888888888888888888888888888888888888888888888888888888888
	InitMatFunction();
	//888888888888888888888888888888888888888888888888888888888888888888

		//在这儿还得搞将第一个搞成4个
	for(rpawn = 0; rpawn < 6; rpawn ++){
		for(bpawn = 0; bpawn < 6; bpawn ++){
			for(rche = 0; rche < 3; rche ++){
				for(rma = 0; rma < 3; rma++){
					for( rpao = 0; rpao < 3; rpao ++){
						for(rshi = 0; rshi < 3; rshi ++){
							for(rxiang = 0; rxiang < 3; rxiang ++){
								for(bche = 0; bche < 3; bche ++){
									for(bma = 0; bma < 3; bma ++){
										for(bpao = 0; bpao < 3; bpao ++){
											for(bshi = 0; bshi < 3; bshi ++){
												for(bxiang = 0; bxiang < 3; bxiang++){
													//if(bshi == 0 && bxiang == 0 && rshi == 0 && rxiang == 0){
													//	//void(*fp)();
													//	//int (*fp)(board_t* board);
													//	//fp = funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][rshi][rxiang][bche][bma][bpao][bshi][bxiang]];
													//	//for(int rs = 0; rs < 3; rs ++){
													//	//	for(int rx = 0; rx < 3; rx ++){
													//	//		for(int bs = 0; bs < 3; bs ++){
													//	//			for(int bx = 0; bx < 3; bx ++){

													//	//			}
													//	//		}
													//	//	}
													//	//}
													//}
													//else{  //这个就不要处理了
														
														fp = funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][0][0][bche][bma][bpao][0][0]];
														funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][rshi][rxiang][bche][bma][bpao][bshi][bxiang]] = fp;

													//}
													//
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

    free(MARR);  //释放内存. 

}

#endif



