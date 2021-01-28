#ifndef XGC_殘局加分_0车_H
#define XGC_殘局加分_0车_H



//************************************************************           有0车对0车

static const  sint16 ADD_2pao1ma_2paoXpawn_ByShi[3]            = { 64, 32, 16};
static const  sint16 ADD_2pao1ma_1pao1maXpawn_ByShi[3]         = { 64, 32, 16};
static const  sint16 ADD_2pao1ma_2maXpawn_ByShi[3]             = { 64, 32, 16};
			  	  
static const  sint16 ADD_1pao2ma_2paoXpawn_ByShi[3]            = { 64, 32, 16};
static const  sint16 ADD_1pao2ma_1pao1maXpawn_ByShi[3]         = { 64, 32, 16};
static const  sint16 ADD_1pao2ma_2maXpawn_ByShi[3]             = { 64, 32 ,16};
			  	  
static const  sint16 ADD_2MaXPawn_2Pao_ByPawnShi[3]            = { 64, 32, 16};    //2马X兵对2炮,  多兵的加分
static const  sint16 ADD_1Pao1MaXPawn_1Pao1Ma_ByPawnShi[3]     = { 64, 32, 16}; 
static const  sint16 ADD_1Pao1MaXPawn_2Ma_ByPawnShi[3]         = { 64, 32, 16};    //
static const  sint16 ADD_1Pao1MaXPawn_2Pao_ByPawnShi[3]        = { 64, 32, 16};  //
static const  sint16 ADD_2MaXPawn_2Ma_ByPawnShi[3]             = { 64, 32, 16}; 

//static const  int ADD_2Pao1Ma_To_2Pao1Ma_By_PawnCan         = 64;
//static const  int ADD_2Pao1Ma_To_1Pao2Ma_By_PawnCan         = 64;
//static const  int ADD_1Pao2Ma_To_1Pao2Ma_By_PawnCan         = 64;

//双方没有其它大子，仅有兵时的加分
static const  sint16 ADD_XPawn_XPanw_ByShi[3] = { 80, 48, 32 };
//static const  int ADD_CanEat_OtherPawn                      =  80;

static const  sint16 ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[3] = { 64, 32, 16 };   //
static const  sint16 ADD_2Pao1Ma1pawn_To_2Pao1MaXPawn_ByPawn[3] = { 64, 32, 16 };   //

static const  sint16 ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3] = { 64, 32, 16 };   //
static const  sint16 ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3] = { 64, 32, 16 };

static const  sint16 ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[3] = { 64, 32, 16 };

static const  sint16 ADD_2Pao2Pawn_To_2PaoxPawn_ByPawn[3] = { 48, 32, 16 };
static const  sint16 ADD_2Pao2Pawn_To_1Pao1MaxPawn_ByPawn[3] = { 48, 32, 16 };
static const  sint16 ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[3] = { 48, 32, 16 };
static const  sint16 ADD_2Ma2Pawn_To_2MaXPawn_ByPawn[3] = { 64, 32, 16 };
static const  sint16 ADD_1Pao1Ma2Pawn_To_1Pao1MaxPawn[3] = { 64, 32, 16 };
static const  sint16 ADD_1Pao1Ma2Pawn_To_2MaxPawn[3] = { 64, 32, 16 };

static const  sint16 ADD_1Pao2MaXpawn_To_2Pao1Ma1Pawn_ByPawn[3] = { 64, 32, 16 };  //

static const  sint16 ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3] = { 64, 32, 16 };  //
static const  sint16 ADD_1Pao2Ma1pawn_To_1Pao2MaXPawn_ByPawn[3] = { 64, 32, 16 };   //

static const  sint16 ADD_2Pao1MaXpawn_To_2Pao1Ma_ByPawn[3] = { 64, 32, 16 };   //
static const  sint16 ADD_2Pao1Ma_To_2Pao1MaXpawn_ByPawn[3] = { 64, 32, 16 };  //ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn

static const  sint16 ADD_2Pao1MaXpawn_To_1Pao2Ma_ByPawn[3] = { 64, 32, 16 };   //
static const  sint16 ADD_1Pao2Ma_To_2Pao1MaXpawn_ByPawn[3] = { 64, 32, 16 };   // ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn

static const  sint16 ADD_1Pao2MaXpawn_To_2Pao1Ma_ByPawn[3] = { 64, 32, 16 };   //
static const  sint16 ADD_2Pao1Ma_To_1Pao2MaXpawn_ByPawn[3] = { 64, 32, 16 };   //ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn

static const  sint16 ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn[3] = { 64, 32, 16 };   //
static const  sint16 ADD_1Pao2Ma_To_1Pao2MaXpawn_ByPawn[3] = { 64, 32, 16 };   //ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn


//其它棋子对3兵
static const  sint16  ADD_1PaoXPawn_3Pawn = 80;              //1炮x兵对3兵的加分 
static const  sint16  ADD_3pawn_PaoXPawn_ShiAdd[3] = { 48, 32, 16 };     //3兵对炮x兵,兵方的加分
static const  sint16  ADD_1PaoXPawn_3pawn_ShiAdd[3] = { 64, 32, 16 };     //炮X兵对3兵,炮方的加分

//static const  int  ADD_3Pawn_To_1pao_ByShi[3]               = { 64, 32, 16};     //3兵对炮,兵方的加分

static const  sint16 ADD_1paoXPawn_2Ma1Pawn_ShiAdd[3] = { 48, 24, 16 };

//static const  int  ADD_1PaoXPawn_2Pao_ByShi[3]              = { 64, 32, 16};     //1炮x兵对2炮
static const  sint16  ADD_1PaoXPawn_1PaoXPawn_ByShi[3] = { 64, 32, 16 };    //1炮x兵对1炮x兵
static const  sint16  ADD_1MaXPawn_1MaXPawn_ByShi[3] = { 64, 32, 16 };     //1马x兵对1马x兵
static const  sint16  ADD_1PaoXPawn_1MaXPawn_ByShi[3] = { 64, 32, 16 };    //1炮x兵对1马x兵

static const  sint16  ADD_1MaXPawn_3Pawn = 128;              //1马x兵对3兵的加分 
static const  sint16  ADD_3pawn_MaXPawn_ShiAdd[3] = { 32, 24, 16 };     //3兵对马x兵,兵方的加分
static const  sint16  ADD_1MaXPawn_3pawn_ShiAdd[3] = { 64, 48, 32 };     //马X兵对3兵,马方的加分

static const  sint16  ADD_1MaXPawn_1Pawn = 80;              //1马x兵对1兵的加分 
static const  sint16  ADD_1MaXPawn_1Pawn_ByPawnShi[3]          = { 64, 32, 16};

static const  sint16  ADD_XPawnToMa_ByPawnShi[3]               = { 48, 32 ,16};    //兵对1马, 兵的加分
static const  sint16  ADD_XPawnToPao_ByPawnShi[3]              = { 64, 32, 16};    //兵对1炮, 兵的加分

static const  sint16  ADD_1PaoXPawn_1Pawn                      = 64;               //1炮x兵对1兵的加分 
static const  sint16  ADD_1PaoXPawn_1Pawn_ByPawnShi[3]         = { 64, 32, 16};

static const  sint16  ADD_1PaoXPawn_2Pawn                      =  64;              //1炮x兵对2兵的加分
static const  sint16  ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[3]      = {64,  64, 32};
static const  sint16  ADD_1PaoXPawn_To_2Pawn_ByPawnSide[3]     = {64,  48, 16};

static const  sint16  ADD_1MaXPawn_2Pawn                       =  80;              //1马x兵对2兵的加分 
static const  sint16  ADD_1MaXPawn_To_2Pawn_ByMaPawn[3]        = {80,  64, 32};
static const  sint16  ADD_1MaXPawn_To_2Pawn_ByPawnSide[3]      = {64,  48, 16};

// fen 4kab2/4a4/b3c4/C2P5/9/8P/P6c1/4B4/4A4/2BA1K3 b - - 0 0
static const  sint16  ADD_1PaoXPawn_2Pao_ByPawnShi[3]          = {64, 48, 16};             //炮x兵对2炮,    多兵的加分
static const  sint16  ADD_1PaoXPawn_1Pao1Ma_ByPawnShi[3]       = {64, 48, 16};             //炮x兵对1炮1马, 多兵的加分
static const  sint16  ADD_1PaoXPawn_2Ma_ByPawnShi[3]           = {64, 48, 16};             //炮x兵对2马,    多兵的加分

static const  sint16  ADD_1PaoM2Pawn_1Ma1Pawn_ByM2Pawn         = 64;
static const  sint16  ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[3]      = { 64, 24, 16};           //炮x兵对1马1兵, 多兵的加分
static const  sint16  ADD_1PaoXPawn_1Ma1Pawn_ByMaPawn[3]       = { 64, 24, 16};           //炮x兵对1马1兵, 多兵的加分

static const  sint16  ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[3]      = {64, 48, 16};           //炮x兵对1炮1兵, 多兵的加分
//static const  sint16  ADD_1PaoXPawn_1Pao1Pawn_ByMaPawn[3]       = { 64, 32, 16};          //炮x兵对1马1兵, 多兵的加分

static const  sint16 ADD_2PaoXPawn_2Pao_ByPawnShi[3]            = { 64, 32, 16};           //2炮x兵对2炮, 兵方的加分

static const  sint16 ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[3]      = { 64, 32, 16};           //2炮x兵对2炮, 兵方的加分
static const  sint16 ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[3]      = { 64, 32, 16};           //2炮x兵对2炮, 兵方的加分


static const  sint16  ADD_2PaoXPawn_1Pao1Ma_ByPawn[3]          = { 64, 32, 16};            //2炮兵对1炮1马,  多兵的加分
static const  sint16 ADD_2PaoXPawn_2Ma_ByPawnShi[3]            = { 64, 32, 16};           //2炮x兵对2马, 兵方的加分
//static const  sint16  ADD_2PaoXPawn_2Ma_ByPawn[3]              = { 64, 32, 16};          //2炮兵对2马,  多兵的加分
static const  sint16  ADD_2MaXPawn_1Pao1Ma_ByPawn[3]           = { 64, 32, 16};             //2马兵对1炮1马,  多兵的加分

static const  sint16  ADD_2PaoXPawn_1Ma2Pawn_ByPawn[3]         = { 64, 32, 16};           //2炮兵对1马2兵, 多兵的加分
static const  sint16  ADD_1Ma2Pawn_2PaoXPawn_ByPawn[3]         = { 64, 32, 16};            //1马2兵对2炮兵, 多兵的加分

static const  sint16  ADD_2PaoXPawn_1Pao2Pawn_ByPawn[3]        = { 64, 32, 16};            //2炮兵对1马2兵, 多兵的加分
static const  sint16  ADD_1Pao2Pawn_2PaoXPawn_ByPawn[3]        = { 64, 32, 16};            //1马2兵对2炮兵, 多兵的加分

static const  sint16  ADD_2MaXPawn_1Pao1Pawn_ByPawn[3]         = { 64, 32, 16};            //2马x兵对1炮2兵, 多兵的加分

static const  sint16  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = { 64, 32, 16};            //2马x兵对1炮2兵, 多兵的加分
static const  sint16  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = { 64, 32, 16};            //2炮1兵对2马x兵, 多兵的加分
//static const  sint16  ADD_Wo_2Ma                               = -128;

static const  sint16  ADD_2MaXPawn_1Pao1Ma1Pawn_ByPawn[3]      = { 64, 32, 16};            //2马x兵对1炮1马1兵, 多兵的加分
static const  sint16  ADD_1Pao1Ma1Pawn_2MaXPawn_ByPawn[3]      = { 64, 32, 16};            //1炮1马1兵对2马x兵, 多兵的加分

static const  sint16  ADD_2MaXPawn_2Ma1Pawn_ByPawn[3]          = { 64, 32, 16};            //2马x兵对1炮1马1兵, 多兵的加分
static const  sint16  ADD_2Ma1Pawn_2MaXPawn_ByPawn[3]          = { 64, 32, 16};            //1炮1马1兵对2马x兵, 多兵的加分

static const  sint16  ADD_2MaXPawn_1Pao2Pawn_ByPawn[3]         = { 64, 32, 16};            //2马x兵对1炮2兵, 多兵的加分
static const  sint16  ADD_1Pao2Pawn_2MaXPawn_ByPawn[3]         = { 64, 32, 16};            //1炮2兵对2马x兵, 多兵的加分


static const  sint16  ADD_2MaXPawn_1Ma1Pawn_ByPawn[3]         = { 64, 32, 16};            //2马x兵对1马2兵, 多兵的加分
static const  sint16  ADD_1Ma1Pawn_2MaXPawn_ByPawn[3]         = { 64, 32, 16};            //2马x兵对1马2兵, 多兵的加分

static const  sint16  ADD_2MaXPawn_1Ma2Pawn_ByPawn[3]         = { 64, 32, 16};            //2马x兵对1马2兵, 多兵的加分
static const  sint16  ADD_1Ma2Pawn_2MaXPawn_ByPawn[3]         = { 64, 32, 16};            //1炮2兵对2马x兵, 多兵的加分

static const  sint16  ADD_1PaoXPawn_1Pao_ByPawn[3]             = { 64, 32, 16}; 
static const  sint16  ADD_1PaoXPawn_1Ma_ByPawn[3]              = { 64, 32, 16};            //1炮兵对1马, 多兵的加分

static const  sint16  ADD_1Pao1MaXPawn_1Pawn[3]                = { 64, 32, 16};
static const  sint16  ADD_2MaXPawn_1Pawn[3]                    = { 64, 32, 16};
static const  sint16  ADD_2PaoXPawn_1Pawn[3]                   = { 64, 32, 16};

static const  sint16  ADD_1Pao1MaXPawn_1Ma[3]                = { 64, 32, 16};
static const  sint16  ADD_2MaXPawn_1Ma[3]                    = { 64, 32, 16};
static const  sint16  ADD_2PaoXPawn_1Ma[3]                   = { 64, 32, 16};

static const  sint16  ADD_1Pao1MaXPawn_1Pao[3]                = { 64, 32, 16};
static const  sint16  ADD_2MaXPawn_1Pao[3]                    = { 64, 32, 16};
static const  sint16  ADD_2PaoXPawn_1Pao[3]                   = { 64, 32, 16};

static const  sint16  ADD_MAPAO_Xpawn_To_PAO                   = 80;                      //马炮对炮的优势分
static const  sint16  ADD_MAPAO_Xpawn_To_PAO1Pawn[3]           = { 64, 32, 16};            //马炮对炮的优势分
static const  sint16  ADD_PAO1Pawn_To_MAPAO_Xpawn[3]           = {64, 32, 16};            //马炮对炮的优势分

static const  sint16  ADD_MAPAO_Xpawn_To_PAO2PawnNoSafe        = 80;                      //马炮对炮的优势分,炮方不安全的加分
//static const  sint16  ADD_MAPAO_Xpawn_To_PAO2Pawn
//static const  sint16  ADD_MAPAO_Xpawn_To_PAO3Pawn              = 80;                      //马炮对炮的优势分
//static const  sint16  ADD_MAPAO_Xpawn_To_PAO4Pawn              = 80;                      //马炮对炮的优势分
//static const  sint16  ADD_MAPAO_Xpawn_To_PAO5Pawn              = 80;                      //马炮对炮的优势分

static const  sint16  ADD_1Ma1Pao_To_1PaoXPawn_ByPawn[3]       =  { 64,  32 ,16};

static const  sint16 ADD_1pao1maXpawn_To_2pao1pawn_ByPs[3]     =  { 64,  32 ,16};         //马炮X兵对2马兵
static const  sint16 ADD_1pao1maXpawn_To_2pao1pawn             =    32;

static const  sint16 ADD_1pao1maXpawn_To_2ma1pawn_ByPs[3]      =  { 64,  32 ,16};         //马炮X兵对2马兵
static const  sint16 ADD_1pao1maXpawn_To_2ma1pawn              =    32;

static const  sint16 ADD_1pao1maXpawn_To_1pao2pawn_ByPs[3]     =  { 64,  32 ,16};         //马炮X兵对1炮2兵
static const  sint16 ADD_1pao1maXpawn_To_1pao2pawn             =    32;

static const  sint16 ADD_1pao1maXpawn_To_1ma2pawn_ByPs[3]      =  { 64,  32 ,16};         //马炮X兵对1炮2兵
static const  sint16 ADD_1pao1maXpawn_To_1ma2pawn              =    32;


static const  sint16 ADD_1Pao1MaXPawn_TO_PaoByPawnShi[3]       =  { 64,  32 ,16};


static const  sint16 ADD_x_Pawn_To_PaoPawnByShi[3]	    		=   { 64, 32, 16};        //兵对炮兵的加分

static const  sint16 ADD_PaoXPawn_To_PaoPawnByShi[3]           =   { 64,  32 ,16};        //炮兵对炮兵_兵的加分

static const  sint16 ADD_PaoXPawn_To_1Pao1Ma_ByShi[3]          =   { 64, 48, 16};
static const  sint16 ADD_PaoXPawn_To_2MaByShi[3]               =   { 64, 48, 16};

static const  sint16 ADD_MaPawn_To_2Pao_ByShi[3]               =   { 64,  32 ,16};
static const  sint16 ADD_MaPawn_To_1Pao1Ma_ByShi[3]            =   { 64,  32 ,16};        //
static const  sint16 ADD_MaPawn_To_2Ma_ByShi[3]                =   { 64,  32 ,16};        //
static const  sint16 ADD_MaPawn_To_MaPawnByShi[3]              =   { 64,  32 ,16};        //马兵对马兵_兵的加分
static const  sint16 ADD_MaPawn_To_PaoPawnByShi[3]             =   { 64,  32, 16};        //马兵对炮兵_兵的加分

   

//车兵对车炮,兵方的加分
static const  sint16 ADD_ChePawn_To_ChePao_Pawn_Shi_Add[3]		=  {64,  32, 16};
static const  sint16 ADD_ChePawn_To_ChePao_By_StringPao		=  128;                //车兵对车炮,车炮被牵制

static const  sint16 ADD_1马兵对1马_by_Pawn_By_Shi[3]			=  { 64, 32, 16};
static const  sint16 ADD_1马兵对1炮_by_Pawn_By_Shi[3]			=  { 64, 32, 16};

static const    sint16 ADD_MaxPawn对1Che_addByPawnSafeByShi[3]	=   {48, 24, 16};        //     
static const    sint16 ADD_PaoxPawn对1Che_addByPawnSafeByShi[3] =   {48, 24, 16};        //  
																			 //马马或马炮对车
static const    sint16 马马兵对1车_addByPawnSafeByShi[3]		=   {64, 48, 24};        // 
static const    sint16 炮炮兵对1车_addByPawnSafeByShi[3]		=   {64, 48, 24};        // 
static const    sint16 炮马兵对1车_addByPawnSafeByShi[3]		=   {64, 48, 24};        //

																			
static const  sint16 Add_车x兵_2车_by_Pawn_Safe_Shi[3]		   =  { 80, 64, 32}; 		 //车兵对二车, 车兵方的安全后的加分	 																  //车炮X兵对二车
static const  sint16 ADD_车炮兵对二车_by_Pawn__Safe_Shi[3]	   =  { 80, 48, 32};		 //车炮兵对二车,炮方安全时兵的加分	
static const  sint16 ADD_CheMaPawn_2Che_MaSafe_ByPawn[3]      =  { 80, 48, 32};

//马炮X兵对马 //马过河的分数
static const  sint16 MaPaoXPawn_Vs_Ma_PaoMao_Over_River		=  64;


																	  	     //马炮三子对一车  马炮三子方肯定是好
static const  sint16 Add_2炮1马对1车                    =  32;
static const  sint16 Add_2炮1马对1车_byPawn_Shi[3]      = { 64, 32, 16};
static const  sint16 Add_1炮2马对1车                    =  32;
static const  sint16 Add_1炮2马对1车_byPawn_Shi[3]      = { 64, 32, 16};

//马炮三子对1车1兵                        //如果马炮方有仕或车方的兵没有过河,那么肯定是马炮方好
static const  sint16 Add_2炮1马对1车1兵                 = 80;                   //如果红兵没有过河或者马炮方有仕
static const  sint16 Add_2炮1马对1车1兵_byPawn_Shi[3]   = { 64, 32, 16};
static const  sint16 Add_1炮2马对1车1兵                 = 64;
static const  sint16 Add_1炮2马对1车1兵_byPawn_Shi[3]   = { 64, 32, 16};
																					//马炮兵对车兵_马炮兵加分
static const  sint16 Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[3]			= { 64, 32, 16};
static const  sint16 Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByConPawn          = 64;              //红方有连兵后的加分
static const  sint16 Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[3]			= {80, 80, 64};
																					//2炮兵对车兵_马炮兵加分
static const  sint16 Add_MAT_B_2pao1pawn_R_1che1pawn_ByShi[3]				= {72, 48, 32};
static const  sint16 Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[3]				= {80, 80, 64};
																					//2马兵对车兵_马炮兵加分
static const  sint16 Add_MAT_B_2ma1pawn_R_1che1pawn_ByShi[3]				= {80, 48, 32};
static const  sint16 Add_2ma1pawn_1che1pawn_MaPawnCan                      = 32;
static const  sint16 Add_MAT_B_1che1pawn_R_2ma1pawn_ByShi[3]				= {80, 80, 64};

static const  sint16 MaPaoXPawn_Ma                                         =  80;
static const  sint16 MaPaoXPawn_MaPawn                                     =  80;

static const  sint16 MaPawn_PaoPawnPaoNoShiXiang                           =  128;



//************************************************************

#endif