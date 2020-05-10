#include "chess.h"
#include "preGen.h"

const int Only2Che_To_2shi2xiang_1che_ByPao     =  96;
const int Only2Che_To_2shi2xiang_1che_ByMa      =  80;
const int Only2Che_To_2shi2xiang_1che_NoPaoMa   =  64;

// fen 3nkab2/4a1P2/4b4/7R1/8c/1p7/9/4B4/4A4/4KAB2 w - - 4 4


//有车方只有一个车时的加分
const int 有车方只有一个车时的加分a = 16;
const int 有车方只有一个车时的加分b = 32;
const int 有车方只有一个车时的加分c = 64;

//有车方只有车马或车炮
// fen 2bak4/4a4/4bc3/2nR5/n1N6/8p/9/4B4/4A4/2BAK4 w - - 0 0
const int Che_Only_1Pao_Or_1Ma_AddByOther_More_3MaPao = 16;

// fen 3ak4/4a4/P3b4/2R5p/2n3p2/4n4/R7P/6r2/4A4/4KAB2 w - - 7 7
//车方有二个车,对方仕不全, 则要加分
                                 //  0,  1   2   3  4
const int Che2ToChe1ByNot4SX[5] = { 64, 48, 24, 12, 0}; 

const int MaterialWeight        = 256; // 100%   


void InitOnePreMat(premat_t* pMat, int rpawn, int bpawn, int rche, int rma, int rpao, int bche, int bma, int bpao){

	int R_chemapao = rche + rma + rpao;
	int B_chemapao = bche + bma + bpao;

	int R_2che1ma1pao = rche * 2 + rma + rpao;
	int B_2che1ma1pao = bche * 2 + bma + bpao;

	int rpawn_val;
	int rche_val;
	int rma_val;
	int rpao_val;


	int bpawn_val;
	int bche_val;
	int bma_val;
	int bpao_val;


	int number[2][16];
	int turn,opp;

	static const  int  CheMaPao         = PAWN + 1;
	static const  int  CheMaPaoPawn     = PAWN + 2;
	static const  int  MaPao            = PAWN + 4;

	//红方是正,黑方是负
	//static const  int TurnMul[2] = {	 1,	-1	};

	pMat->material          = 0;
	pMat->searchInfo8       = 0;
	pMat->phase             = 0;


	//如果一方没有攻击子了, 另一方要加分
	if( (rche == 0 && rpao == 0  && (rpawn + rma) <= 1)
	  ||(rche == 0 && (rpao <= 1 ) && (rpawn + rma) == 0)) {
          pMat->material -= (bche * 80 + bpao * 64 + bma * 64 + bpawn * 32);
	}
	if( (bche == 0 && bpao == 0  && (bpawn + bma) <= 1)
	  ||(bche == 0 && (bpao <= 1 ) && (bpawn + bma) == 0)){
          pMat->material += (rche * 80 + rpao * 64 + rma * 64 + rpawn * 32);
	}

	rpawn_val  = PAWN_VAL * 100 / 100;
	rche_val   = CHE_VAL;
	rma_val    = MA_VAL;
	rpao_val   = PAO_VAL;


	
	bpawn_val  = PAWN_VAL * 100 / 100;
	bche_val   = CHE_VAL;
	bma_val    = MA_VAL;
	bpao_val   = PAO_VAL;
	


	number[WHITE][CHE]                = rche;
	number[WHITE][MA]                 = rma; 
	number[WHITE][PAO]                = rpao;
	number[WHITE][PAWN]               = rpawn;

	number[WHITE][CheMaPao]           = rche + rma + rpao;
	number[WHITE][CheMaPaoPawn]       = rche + rma + rpao + rpawn;
	number[WHITE][MaPao]              = rma  + rpao;

	number[BLACK][CHE]                = bche;
	number[BLACK][MA]                 = bma; 
	number[BLACK][PAO]                = bpao;
	number[BLACK][PAWN]               = bpawn;

	number[BLACK][CheMaPao]           = bche + bma + bpao;
	number[BLACK][CheMaPaoPawn]       = bche + bma + bpao + bpawn;
	number[BLACK][MaPao]              = bma  + bpao;

	// 只有1车1炮X兵的评估. 
	// fen 4ka3/4a4/4P3c/P1R6/9/8r/9/4B4/4A4/2B1KA3 w - - 0 1
	if(rche == 1 && rma == 0 && rpao == 1){
		if(bche >= 1 && (bma >= 1 || bpao >= 1 || bche == 2)){
		    pMat->searchInfo8 |= CK_Only_1Che1PaoxPawn;
		}
	}

	if(bche == 1 && bma == 0 && bpao == 1){
		if(rche >= 1 && (rma >= 1 || rpao >= 1 || rche == 2)){
			pMat->searchInfo8 |= CK_Only_1Che1PaoxPawn;
		}
	}

	if ((bche * 5 + (bma + bpao) * 3 + bpawn * 2) > 7){
		pMat->searchInfo8 |= CK_CAN_USE_FRUIT_PUN;
	}
	if ((rche * 5 + (rma + rpao) * 3 + rpawn * 2) > 7){
		pMat->searchInfo8 |= CK_CAN_USE_FRUIT_PUN;
	}

	if ((bche * 6 + (bma + bpao) * 3 ) > 5){
		pMat->searchInfo8 |= HAVE_NONE_PAWN_MATERAIL;
	}
	if ((rche * 6 + (rma + rpao) * 3 ) > 5){
		pMat->searchInfo8 |= HAVE_NONE_PAWN_MATERAIL;
	}

	// CK_5000_Material

	if ((bche * 10 + (bma + bpao) * 5 + rche * 10 + (rma+rpao) * 5 + rpawn * 2 + bpawn * 2) > 40) {
		pMat->searchInfo8 |= CK_5000_Material;
	}

	if (rche == 1 && bche == 1){
		if ((rpao + rma) == 4 && (bpao + bma) == 4){
			pMat->searchInfo8 |= CK_BR_1CHE_4MAPAO;
		}
	}

  for(turn = 0; turn < 2; turn ++){
	  opp              = turn ^ 0x1;  	  
	  //下面根据车的数量来调整相应的棋子的分数
      //*****************************************************************************	 
	  //我方2个车
	  if(number[turn][CHE] == 2){
		  //我方2个车, 对方2个车
		  if(number[opp][CHE] == 2){
			  const int Turn_Pawn_2Che2Che[10]   = {92, 88, 84, 72, 56, 52, 48, 44, 42 }; //{100, 96, 88, 80, 72, 64, 56, 48, 40,  0};
			  const int Opp_Pawn_2Che2Che[10]    = {92, 88, 84, 72, 56, 52, 48, 44, 42 };	

			  if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 108; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 108;

			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 108; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 108;
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

			  // 多子加分

			  //2, 车马马炮,比车炮炮马少32分, 以免开始用炮换马
			  if((rma+rpao) == 3 && (bma+bpao) == 3){
				  if(rma == 2){
					  pMat->material -= 8;
				  }
				  if(bma == 2){
					  pMat->material += 8;
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

			  // fen 2bak4/4a3R/4b4/p1R1p4/6P2/2P6/P7P/r8/2r6/3CK1B2 w - - 0 0
              //2车对2车(马,炮), 马,炮方没有仕了



			  // 如果对方只有一个仕
			  // fen 2bak4/4a4/4b4/p3p2rp/2p6/5N3/P3P3P/2RRB1N2/5K3/4r4 w - - 7 7
			  // fen 2bak4/4a4/4b4/p3p2rp/2p6/5N3/P3P3P/2RRB1N2/5K3/4r4 w - - 7 7==
			  // pMat->material += rpawn_val  * (2 - bshi) * rpawn / 32;
			  // pMat->material -= bpawn_val  * (2 - rshi) * bpawn / 32;

			  break;
		  }
		  //我方2个车, 对方1个车
		  else if(number[opp][CHE] == 1){
			  const int Turn_Pawn_2Che2Che[10]   = {104,100, 96, 92, 88, 84, 80, 76, 72, 68};
			  const int Opp_Pawn_2Che2Che[10]    = {100, 96, 92, 88, 84, 80, 76, 72, 68, 64};

			  const int OtherNoPaoMaLessTwo[3] = {64,32,20};

			   if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

				  // fen 4kab2/4a4/4b4/7Rp/p1pn5/9/Pr2PR2P/4B4/2n1A4/2BA1K3 w - - 4 4
				  //这个要红好一些
				  if((bpao + bma) <= 2){
                       pMat->material += OtherNoPaoMaLessTwo[bpao + bma] * rpawn;
				  }
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;


				  if((rpao + rma) <= 2){
                       pMat->material -= OtherNoPaoMaLessTwo[rpao + rma] * bpawn;
				  }
			  }
			  // fen 2rak1b2/4a4/2n6/p3p2rp/1c3Nb2/2R2NB2/P3P3P/C3C4/9/2BAKA3 b - - 0 1

			  if(turn == WHITE){
				  // fen 2bakn3/4a4/4b1c2/r8/3P5/7R1/P3P1R1c/9/4A4/2B1KA3 w - - 0 0
				  if(bpawn == 0){
					  pMat->material += (rpawn+1)/2 * 32;
				  }
			  }
			  else{
				  if(rpawn == 0){
					  pMat->material -= (bpawn+1)/2 * 32;
				  }
			  }
	
			  //如果对方只有一个仕
			  if(turn == WHITE){				
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
			  // fen 2Rakab2/9/4c4/p6r1/3P2p2/5R3/8P/9/9/3AK4 b - - 0 0
			  if(rche == 2 && (bma + bpao) == 1){
				   rpawn_val =  rpawn_val * 138 / 100; 
			  }

			  if(bche == 2 && (rma + rpao) == 1){
				   bpawn_val =  bpawn_val * 138 / 100; 
			  }

			  // fen 2R2ab2/3ka4/8n/p3r4/3r4C/6N1P/P8/4B3N/4A4/3AK1B2 b - - 0 0
			  // 如果双方是子力相同,
			  if(FALSE){
			  }
			  else if(turn == WHITE){
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
						  pMat->material += rpawn * 12;
						  pMat->material += (rma+rpao) * 16;
					  }
				  }
			  }
			  // fen 4kab2/4a4/4b1R2/p3p3p/9/5RP2/P3r3P/2n1B4/4A4/1cBAK4 w - - 2 2
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
						  pMat->material -= bpawn * 12;
						  pMat->material -= (bma+bpao) * 16;
					  }
				  }
			  }
			  // fen C1bak4/4a4/4b1n2/4n1R2/p7p/2P6/P3rpc1P/4B1R2/4A4/2BAK4 w - - 0 0
			  //这个应是一车方稍好一些
			  //
			  if(turn == WHITE){    //如果红方是二个车
				  if((rpao + rma) == 1){
					  if((bpao + bma) >= 3){
						  pMat->material -=  (bpao + bma) * 24;
					  }
				  }
				  if((rpao + rma) == 0){
					  if((bpao + bma) >= 2){
						  pMat->material -=  (bpao + bma) * 32;
					  }
				  }

				  // fen 2bakn3/4a4/4b1c2/r8/3P5/7R1/P3P1R1c/9/4A4/2B1KA3 w - - 0 0
				  // ----------------------------------------------------
				  // fen 3ak1b2/4a4/4b1n2/3Rp4/8r/5R3/9/4B4/4A4/4KAB2 w - - 0 0
				  // ----------------------------------------------------
			  }
			  else{
				  if((bpao + bma) == 1){
					  if((rpao + rma) >= 3){
						  pMat->material +=  (rpao + rma) * 24;
					  }
				  }
				  if((bpao + bma) == 0){
					  if((rpao + rma) >= 2){
						  pMat->material +=  (rpao + rma) * 32;
					  }
				  }

				  // ----------------------------------------------------
				  // fen 3ak1b2/4a4/4b1n2/3Rp4/8r/5R3/9/4B4/4A4/4KAB2 w - - 0 0
				  // ----------------------------------------------------
			  }


			  break;
		  }
		  //我方2个车, 对方0个车
		  else if(number[opp][CHE] == 0){
       								   //             0   1   2   3   4   5   6   7   8   9 
			  const int Turn_Pawn_2Che2Che[10]   = {116,112,108,100, 96, 92, 88, 84, 80, 76};
			  const int Opp_Pawn_2Che2Che[10]    = { 92, 88, 84, 80, 76, 72, 68, 64, 60,  0};

			  if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;
			  }
	
       	      //如果对方只有一个仕

			  break;
		  }
	  }
	  //*****************************************************************************
	  //我方1个车
	  else if(number[turn][CHE] == 1){	
		  //我方1个车, 对方1个车
		  if(number[opp][CHE] == 1){ 
								      //             0   1   2   3   4   5   6   7   8   9 
			  const int Turn_Pawn_2Che2Che[10]   = {96, 88, 80, 72, 68, 64, 58, 54, 52, 48};
			  const int Opp_Pawn_2Che2Che[10]    = {96, 88, 80, 72, 68, 64, 58, 54, 52, 48};

			  if(turn == WHITE){
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;
			  }
			  else{
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;
			  }

			  // fen 4kab2/4a4/4b1c2/2n1Nn3/9/P7C/3cP1P1P/1R1CB1N2/4K4/2r2A3 b - - 0 1
              // 如果一方的仕相少于等于2个，双方的马炮大于3个。
			  //if ((number[turn][XIANG] + number[turn][SHI]) <= 2
				 // && (number[opp][XIANG] + number[opp][SHI]) == 4){
				 // if ((number[opp][MA] + number[opp][PAO]) == 4){
					//  if (turn == WHITE){
					//	  pMat->material -= 32 * (4 - (number[turn][XIANG] + number[turn][SHI]));
					//  }
					//  else{
					//	  pMat->material += 32 * (4 - (number[turn][XIANG] + number[turn][SHI]));
					//  }
				 // }
				 // else if ((number[opp][MA] + number[opp][PAO]) == 3){
					//  if ((number[turn][MA] + number[turn][PAO]) <= 3){
					//	  if (turn == WHITE){
					//		  pMat->material -= 24 * (4 - (number[turn][XIANG] + number[turn][SHI]));
					//	  }
					//	  else{
					//		  pMat->material += 24 * (4 - (number[turn][XIANG] + number[turn][SHI]));
					//	  }
					//  }
				 // }
			  //}

			  // fen 2bk1a3/4a4/6c2/9/p1b3N2/9/P3P3P/6r2/4A4/1R1AK4 w - - 0 0
			  //要体现出缺相怕炮攻的形


			  // fen 3k1ab2/4a4/4b4/C3R4/1r7/P8/8P/3A5/3KA1n2/9 b - - 0 1


			  // fen 3a1k3/4a4/4P4/1r7/p3P4/9/P7p/4BA3/1c7/1RBAK4 w - - 0 0
              //车方只有车兵了


			  // fen 4ka3/9/2nab3n/p3p3p/9/P5R1P/2r6/4B1C2/6C2/2BA1K3 b - - 0 1


			  // fen 2ba1k3/4a4/b4c3/5R2C/5N3/2B6/p7P/6r2/9/3K5 b - - 0 69
			  //如果一方只有车炮了,要降分


			  //因为炮的位置分要低一些,所以2炮+马方要加一些分			  
			  // fen 2bak4/4a4/2N1b3n/2c3p2/3r1P2c/p3R4/3N5/1C2B4/4A4/4KAB2 r
			  if(rpao == 2 && rma != 0){
				  pMat->material += 16;
			  }
			  if(bpao == 2 && bma != 0){
				  pMat->material -= 16;
			  }

			  // fen 4ka3/4a4/4b4/N7r/P3P2c1/2B4n1/R6N1/4B4/9/3AK4 w - - 0 0
			  //车２马要比车马炮减一些分
			  if(rpao >= 1 && rma >= 1 && bpao == 0){
				  pMat->material += 24;
			  }
			  if(bpao >= 1 && bma >= 1 && rpao == 0){
				  pMat->material -= 24;
			  }

			  // fen 2b1k4/4a4/3ab4/p3p3p/5n3/P5R2/4P3P/9/3NK1N1r/5A3 w - - 0 1


			  //如果一方只有一个车,另一方有其它的子力,还要加分
			  if((bpao + bma + bpawn) == 0){
				  pMat->material += (rpao + rma) * 96;
				  pMat->material +=  rpawn * 64;
			  }
			  if((rpao + rma + rpawn) == 0){
				  pMat->material -= (bpao + bma) * 96;
				  pMat->material -=  bpawn * 64;
			  }
			  // fen 4ka3/4a4/4P3c/P1R6/9/8r/9/4B4/4A4/2B1KA3 w - - 0 1
			  if((bpao + bma) == 0 && bpawn <= 2){
				  pMat->material += (rpao + rma) * 32;
			  }
			  if((rpao + rma) == 0 && rpawn <= 2){
				  pMat->material -= (bpao + bma) * 32;
			  }

			  // fen 3rkab2/1R2a4/4b1n2/C3p3p/9/7p1/P3p3P/C8/4A4/1Nc1KAB2 b - - 0 1
			  // 我方多一个大子了
			  if ((rma + rpao) >= 3 && (bpao + bma) <= 2){
				  pMat->material += 64;
			  }
			  if ((bma + bpao) >= 3 && (rpao + rma) <= 2){
				  pMat->material -= 64;
			  }


			  // fen 2baka3/9/4b4/pRC1p4/8p/4n1B2/r5p2/1N7/4A4/3AK1B2 w - - 4 4
			  //如果大家是3个大子,则多二兵一方还要加一些分
			  if(R_chemapao == B_chemapao && R_chemapao <= 3){
				  if((rpawn - bpawn) >= 2){
					  pMat->material += 24;
				  }
				  if((bpawn - rpawn) >= 2){
					  pMat->material -= 24;
				  }
			  }

			  //如果对方只有车马,就要加分
			  // fen 3rkab2/1R2a4/4b1n2/C3p3p/9/7p1/P3p3P/C8/4A4/1Nc1KAB2 b - - 0 1
			  if (R_chemapao > B_chemapao){
				  pMat->material += 32;
				  if (B_chemapao <= 1){
					  pMat->material += 32;
				  }
			  }
			  if (B_chemapao > R_chemapao){
				  pMat->material -= 32;
				  if (R_chemapao <= 1){
					  pMat->material -= 32;
				  }
			  }



			  //2, 我方还多大子
			  ////红方的大子比黑方的大子多

				  // fen 4ka3/C3a4/4b4/8p/p5b2/3N5/P3c1n2/4B4/2r1A1R2/4KC3 b - - 0 1


              // fen 2b1ka3/4a4/2n1bc3/5N3/R1p1P4/9/P4r3/4BN3/4A4/2B1KA3 w - - 0 1
			  // fen 2b1ka3/n3a4/4bc3/R4N3/p1p1P4/9/r8/4BN3/4A4/2B1KA3 b
			  //如果对方是车炮马２兵，我方是车2马1兵，对方要加分		
			 if(rma >= 1 && rpao >= 1 && bpao == 0 && bma == 2){
				  if(rpawn >= 2 && bpawn <= 1){
					  pMat->material += (rpawn - bpawn) * 8;
				  }
			  }
			  if(bma >= 1 && bpao >= 1 && rpao == 0 && rma == 2){
				  if(bpawn >= 2 && rpawn <= 1){
					  pMat->material -= (bpawn - rpawn) * 8;
				  }
			  }
			 if ((rma + rpao) >= 2 && bpao == 0 && bma <= 1){
				 //fen 4kab2/4a4/n3b4/p1p1R4/3C5/4Pr3/P1P4p1/5p3/N8/2BAKA3 b - - 0 1
				 pMat->material +=  rpawn * 16;
			  }
			  if ((bma + bpao) >= 2 && rpao == 0 && rma <= 1){				  
				 pMat->material -=  bpawn * 16;				  
			  }

			  break;
			  //==================================================================================
		  }
		  //我方1个车, 对方0个车
		  else if(number[opp][CHE] == 0){										   //无车
								       //             0   1   2   3   4   5   6   7   8   9 
			  const int Turn_Pawn_2Che2Che[10]   = {120, 116,112,108,104,100, 92, 88, 84, 0};
			  const int Opp_Pawn_2Che2Che[10]    = { 96,  92, 88, 84, 80, 76, 72, 68, 64, 0};

			 
			  const int CheAdd = 48;

			  if(turn == WHITE){
			      pMat->material += CheAdd;
				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;				  
			  }
			  else if(turn == BLACK){
				  pMat->material -= CheAdd;
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;
			  }	

			  //如果双方的子是相同的.
			 if(turn == WHITE){ // fen 2b1ka3/4a4/4b4/8R/2n1p4/1p4B2/1c1nP1P1P/3AB1N2/9/1cNA1K3 w - - 0 1 车方加的太多了
				  if((rma + rpao) >= (bpao + bma - 2)){  //双方是子力平衡的,一车抵二个
                     pMat->material += (rpawn+1)/2 * 16;
					 pMat->material += ((rma+rpao)+1)/2 * 32;
					 // fen 2b1kab1C/4a4/9/8P/4r4/p5P2/7c1/3CB1N2/4A4/4KAB2 w - - 14 14
				  }
			  }
			  else if(turn == BLACK){
				  if((bma + bpao) >= (rpao + rma - 2)){  //双方是子力平衡的,一车抵二个
                     pMat->material -= (bpawn+1)/2 * 16;
					 pMat->material -= ((bma+bpao)+1)/2 * 32;
					  // fen 2b1kab1C/4a4/9/8P/4r4/p5P2/7c1/3CB1N2/4A4/4KAB2 w - - 14 14
				  }
			  }
			  // fen 4k1b2/9/2n1bR3/p5c2/4p4/9/9/4B4/4A4/2BA1K3 w - - 0 0
              //车方只有一个车了                

			  // fen 4k1b2/5C3/4baN2/p1n3c1p/3N5/9/P7r/4B4/4C4/3AKAB2 w - - 3 3
			  //如果有车方的其它的子大于二个,则也要加分
			  if(turn == WHITE){
				  if((rma+rpao) >= 2){
					  pMat->material += 32 * (rpawn+1)/2;
				  }
			  }
			  else if(turn == BLACK){
				   if((bma+bpao) >= 2){
					  pMat->material -= 32 * (bpawn+1)/2;
				  }
			  }

			   //如果对方只有一个仕	  

			  // 看一下对方的马炮数量

			  // fen 4kab2/9/4ba1n1/4p3p/p1p6/c4R3/4P3P/4B4/4A4/2BAK4 w - - 2 2
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
				  // fen 3akab2/2C6/4b4/R8/2pP4p/9/P4n2P/4B4/3K2nc1/3A1AB2 w - - 4 4
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

			  // fen 6b1C/4ak3/5aN2/9/9/9/P5P2/4B4/3c5/2rCKA3 w - - 1 1

	
			  break;
		  }
	  }
	  //*****************************************************************************
	  //我方0个车
	  else if(number[turn][CHE] == 0){
		  //我方0个车, 对方0个车
		  if(number[opp][CHE] == 0){
	    	                            //           0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
			  const int Turn_Pawn_2Che2Che[10]   = {116,112,108, 100, 92, 88, 86, 82, 78, 74 };
			  const int Opp_Pawn_2Che2Che[10]    = {116,112,108, 100, 92, 88, 86, 82, 78, 74 };
			  
			  if(turn == WHITE){	

				  rpawn_val   = rpawn_val  * Turn_Pawn_2Che2Che[B_2che1ma1pao]  / 100; 
				  bpawn_val   = bpawn_val  *  Opp_Pawn_2Che2Che[R_2che1ma1pao]  / 100;

			  }
			  else{
				  //pMat->material -= CheAdd;
				  bpawn_val   = bpawn_val  * Turn_Pawn_2Che2Che[R_2che1ma1pao]  / 100; 
				  rpawn_val   = rpawn_val  *  Opp_Pawn_2Che2Che[B_2che1ma1pao]  / 100;
			  }
			  // fen C1bak4/9/bP1a3c1/1P7/9/2B6/9/9/4A4/3A1K3 w - - 0 1
			  //if(rpao == 1 && rma == 0 && rpawn == 2 && bma == 0 && bpao == 1 && bpawn == 0){
				 // int test = 0;
			  //}

			  if(rma == 0){ // 残局马比炮要好一些。
				  pMat->material -= (bma + bpao) * 16;
			  }
			  if(bma == 0){ // 残局马比炮要好一些。
				  pMat->material += (rma + rpao) * 16;
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

			  //如果一方的兵比另一方多二个
			  if((bma + bpao) == (rma + rpao)){
				  if((rpawn - bpawn) >= 2){
					  pMat->material += 16;
				  }
				  if((bpawn - rpawn) >= 2){
					  pMat->material -= 16;
				  }
			  }
			  // fen 4k1b2/9/9/9/9/9/2n2C3/3K1A3/2p1A1p2/5C3 b - - 0 143
			  if(rma == 0 && rpawn == 0){
				  pMat->material -= 32 * bma;
				  pMat->material -= 32 * bpawn;
				  pMat->material -= 32 * bpao;
			  }
			  if(bma == 0 && bpawn == 0){
				  pMat->material += 32 * rma;
				  pMat->material += 32 * rpawn;
				  pMat->material += 32 * rpao;
			  }


			  if((rma+rpao) == 2 && (bma+bpao) == 2){       //兵种齐全的要加分
				  if(rma==2){
					  pMat->material -= 16;
				  }
				  if(bma==2){                  //马马没马炮,炮炮好
					  pMat->material += 16;
				  }

				  //如果双方仕相全，且双方的兵少于２个

			  }

			  // fen 3k1ab2/4a4/4b4/8C/2p1c4/P8/6p2/4B4/5K3/6C2 b - - 1 1
			  //2炮对1炮
			  if(bpao <= 1 && bma == 0){  //黑方只有一个炮了
				  pMat->material += (rpao+rma) * 32;
			  }
			  if(rpao <= 1 && rma == 0){  //黑方只有一个炮了
				  pMat->material -= (bpao+bma) * 32;
			  }

			  // fen 3ak4/9/1N1ab4/p8/2bn4p/2B3B2/5C3/9/4A4/5K3 b - - 0 0
			  if(bpao == 0 && bma <= 1){
				  pMat->material += (rpao+rma) * 32;
			  }
			  if(rpao == 0 && rma <= 1){
				  pMat->material -= (bpao+bma) * 32;
			  }

			  //炮方没有仕了，马方有兵


			  // fen 2bak4/1C1Ca4/1PP1b4/8p/4n4/9/8P/3AB4/4A1n2/2B2K1c1 b - - 0 
			  if(rpao <= 2 && rma == 0){
				  if((bpao + bma) >= 3){
					  pMat->material -= ((bpao + bma) - rpao) * 64;
				  }
			  }
			  if(bpao <= 2 && bma == 0){
				  if((rpao + rma) >= 3){
					  pMat->material += ((rpao + rma) - bpao) * 64;
				  }
			  }

			  //2, 我方还多大子
			  // fen 3k2b2/4a1N2/4ba3/5P3/9/6B2/4pp3/B8/3CA4/1c2KA3 b - - 0 1
			  pMat->material += 80 * (rma + rpao);
			  pMat->material -= 80 * (bma + bpao);		

			  break;
		  }
	  }// else if(number[turn][CHE] == 0){
  }

  pMat->material  += (rpawn  * rpawn_val 
	  +  rpao   * rpao_val
	  +  rma    * rma_val
	  +  rche   * rche_val);    

  pMat->material -=  (bpawn  * bpawn_val
	  +  bpao   * bpao_val
	  +  bma    * bma_val
	  +  bche   * bche_val); 

  int not_pawn_material  = (
	  rpao * rpao_val + rma * rma_val + rche * rche_val
	  + bpao * bpao_val + bma * bma_val + bche * bche_val 
	  + bpawn * bpawn_val + rpawn * rpawn_val);  


   Value MidgameLimit = Value(7200 - 1200);
   Value EndgameLimit = Value(1200);

  //const Value MidgameLimit = Value(15581/2);
  //const Value EndgameLimit = Value(3998/2);
  // fen 2bak4/9/3ab4/p3p4/9/2p1P1pp1/P8/3AKNN1c/6C2/3A5 w - - 0 ph = 24
  if((rche + bche) == 0){
     MidgameLimit -= Value(400);
	 //EndgameLimit -= Value(200);
  }
  // fen 2b1ka3/4a4/2N1b4/5Nr2/2p5p/P8/2P1P4/3KBR3/4A1n1c/2B2A3 b - - 0 1
  if(rche == 1){
	  not_pawn_material += 480;
  }
  if(bche == 1){
	  not_pawn_material += 480;
  }

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
}

void InitPreMatinfo(void){

	__int64 off;
	int rpao,rma,rche,rpawn;
	int bpao,bma,bche,bpawn;

	//void (*fp)(typePOS &POSITION, EvalInfo &ei);

    premat_t *Porg   =   &PreMatInfo[0][0][0][0][0][0][0][0];

    MatAddress[RKING]  =  0;
    MatAddress[RPAWN]  = (int)(&PreMatInfo[1][0][0][0][0][0][0][0] - Porg);
    MatAddress[RPAO]   = (int)(&PreMatInfo[0][0][0][0][1][0][0][0] - Porg);
    MatAddress[RCHE]   = (int)(&PreMatInfo[0][0][1][0][0][0][0][0] - Porg);
    MatAddress[RMA]    = (int)(&PreMatInfo[0][0][0][1][0][0][0][0] - Porg);
    MatAddress[RSHI]   = 0;
    MatAddress[RXIANG] = 0;

    MatAddress[BKING]  =  0;
    MatAddress[BPAWN]  = (int)(&PreMatInfo[0][1][0][0][0][0][0][0] - Porg);
    MatAddress[BPAO]   = (int)(&PreMatInfo[0][0][0][0][0][0][0][1] - Porg);
    MatAddress[BCHE]   = (int)(&PreMatInfo[0][0][0][0][0][1][0][0] - Porg);
    MatAddress[BMA]    = (int)(&PreMatInfo[0][0][0][0][0][0][1][0] - Porg);
    MatAddress[BSHI]   = 0;
    MatAddress[BXIANG] = 0;


	MARR = (MARR_t *)malloc(sizeof(MARR_t));
    for(rpawn = 0; rpawn < 6; rpawn ++){
        for(bpawn = 0; bpawn < 6; bpawn ++){
            for(rche = 0; rche < 3; rche ++){
                for(rma = 0; rma < 3; rma++){
                    for(rpao = 0; rpao < 3; rpao ++){ 
                                for(bche = 0; bche < 3; bche ++){
                                    for(bma = 0; bma < 3; bma ++){
                                        for(bpao = 0; bpao < 3; bpao ++){  

													premat_t *pMat =  &PreMatInfo[rpawn][bpawn][rche][rma][rpao][bche][bma][bpao];

													InitOnePreMat( pMat,rpawn, bpawn, rche, rma, rpao, bche, bma, bpao);

													off = pMat - Porg;	
													MARR->a[rpawn][bpawn][rche][rma][rpao][bche][bma][bpao] = (int)off;

													if(rche == 0 && rpao == 0 && rma == 0 && rpawn == 0 && bche == 0 && bpao == 0 && bma == 0 && bpawn == 0){
														funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][bche][bma][bpao]] = m_MT_MUST_DRAW;
													}
													else{
														funMat[MARR->a[rpawn][bpawn][rche][rma][rpao][bche][bma][bpao]] = m_MT_NONE_16;														
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
	
    free(MARR);  //释放内存. 
}




