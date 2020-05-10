#ifndef XGC_殘局加分_1车_H
#define XGC_殘局加分_1车_H

//************************************************************        有1车对1车 ************************************************************ 
static const  sint16 ADD_Che2PawnCan_PawnControlMa                = 96;

static const  sint16 ADD_3PaoMaTo1Che1PaoMa1PawnByPaoMaCan        = 32;

static const  sint16 ADD_1che2paoXpawn_B_1che1pao2ma_MaHome       = 32;
static const  sint16 ADD_1che1pao1maXpawn_B_1che1pao2ma_MaHome    = 32;
static const  sint16 ADD_1che2maXpawn_B_1che1pao2ma_MaHome        = 16;

static const  sint16  ADD_1che2pao1pawn_1che1pao1ma_ByShi[3]      = { 48, 24, 16};             //1车2炮X兵对1车1炮1马
static const  sint16  ADD_1che2pao1pawn_1che2pao_ByShi[3]         = { 48, 24, 16};             //1车2炮X兵对1车2炮
static const  sint16  ADD_1che2pao1pawn_1che2ma_ByShi[3]          = { 48, 24, 16};             //1车2炮X兵对1车2马

static const  sint16  ADD_1che1pao1ma1pawn_1che1pao1ma_ByShi[3]   = { 48, 24, 16};             //1车1炮1马X兵对1车1炮1马
static const  sint16  ADD_1che1pao1ma1pawn_1che2pao_ByShi[3]      = { 48, 24, 16};             //1车1炮1马X兵对1车2炮
static const  sint16  ADD_1che1pao1ma1pawn_1che2ma_ByShi[3]       = { 48, 24, 16};             //1车1炮1马X兵对1车2马

static const  sint16  ADD_1che2ma1pawn_1che1pao1ma_ByShi[3]       = { 48, 24, 16};             //1车2马X兵对1车1炮1马
static const  sint16  ADD_1che2ma1pawn_1che2pao_ByShi[3]          = { 48, 24, 16};             //1车2马X兵对1车2炮
static const  sint16  ADD_1che2ma1pawn_1che2ma_ByShi[3]           = { 48, 24, 16};             //1车2马X兵对1车2马

static const  sint16  ADD_CheMaPawn_CheMa_ByPawnByShi[3]       = { 96, 24, 16};				//车马兵对车马多兵加分
static const  sint16  ADD_CheMaPawn_ChePao_ByPawnByShi[3]      = { 48, 24, 16}; 			//车马兵对车马多兵加分

static const  sint16  ADD_ChePaoPawn_ChePao_ByPawnByShi[3]     = { 48, 24, 16};             //车炮兵对车炮多兵加分
static const  sint16  ADD_ChePaoPawn_CheMa_ByPawnByShi[3]      = { 48, 24, 16};             //车炮兵对车马多兵加分

static const  sint16  ADD_CheXPawn_To_Che_ByShi[3]             = {96, 48, 32};             //车兵对车

static const  sint16  ADD_CheMaPawn_CheMaPao_ByPawnByShi[3]       = { 96, 36, 16};		//车马兵对车马多兵加分

static const  sint16  ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[3]       = { 64, 36, 16};		//车马兵对车马多兵加分
static const  sint16  ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[3]      = { 48, 24, 16};		//车马兵对车马多兵加分
static const  sint16  ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[3]     = { 48, 24, 16};        //车炮兵对车炮多兵加分
static const  sint16  ADD_ChePaoPawn_CheMa1pawn_ByPawnByShi[3]      = { 48, 24, 16};        //车炮兵对车马多兵加分

static const  sint16 ADD_ChePaoPawn_ChePao_ByShiXiang				 =  64;                 //车炮兵对车炮
static const  sint16 ADD_Only_Pawn_NoCheMaPaoByShi[3]				 =  {64,32,16};

static const  sint16 ADD_NO_CHE_OP_KING_NOT_BOTTOM             = 96;                      //无车方车不在底线

static const  sint16 ADD_1CheMore2Pawn_To_1Pao2ma1Pawn         = 32;
static const  sint16 ADD_1CheMore2Pawn_To_2Pao1ma1Pawn         = 32;


static const  sint16  ADD_ChePaoXPawn_CheMa1Pawn[3]            = { 48, 24, 16};            //车炮X兵对车马1兵_兵的加分
static const  sint16  ADD_ChePaoXPawn_ChePao1Pawn[3]           = { 48, 24, 16};            //车炮X兵对车炮1兵_兵的加分

static const  sint16  ADD_CheMaXPawn_CheMa1Pawn[3]             = { 48, 24, 16};            //车炮X兵对车马1兵_兵的加分
static const  sint16  ADD_CheMaXPawn_ChePao1Pawn[3]            = { 48, 24, 16};            //车炮X兵对车炮1兵_兵的加分

static const  sint16  ADD_ChePaoXPawn_CheMa2Pawn[3]            = { 48, 24, 16};            //车炮X兵对车马1兵_兵的加分
static const  sint16  ADD_ChePaoXPawn_ChePao2Pawn[3]           = { 48, 24, 16};            //车炮X兵对车炮1兵_兵的加分

static const  sint16  ADD_CheMaXPawn_CheMa2Pawn[3]             = { 48, 24, 16};            //车炮X兵对车马1兵_兵的加分
static const  sint16  ADD_CheMaXPawn_ChePao2Pawn[3]            = { 48, 24, 16};            //车炮X兵对车炮1兵_兵的加分

static const  sint16  ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[3]    = { 48, 24, 16};            //车炮X兵对车2兵_兵的加分
static const  sint16  ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[3]    = { 48, 24, 16};            //车2兵_兵对车炮X兵的加分
static const  sint16  ADD_ChePaoString_OtPawn                  =  32;                     //车炮方车炮被牵

static const  sint16  ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[3]     = { 48, 24, 16};            //车炮X兵对车2兵_兵的加分
static const  sint16  ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[3]     = { 48, 24, 16};           //车2兵_兵对车炮X兵的加分


static const  sint16 ADD_ChePawn_To_ChePawnByShi[3]            = { 48, 24, 16};            //车兵对车兵,多兵方的分

static const  sint16 ADD_CheXPawn_To1Pao                       =  80;                     //车兵对炮,
static const  sint16 ADD_CheXPawn_To1Pao_ByPawnShi[3]          = {64,32,16};

static const  sint16 ADD_CheXPawn_To1Ma                        =  64;                     //车兵对马,
static const  sint16 ADD_CheXPawn_To1Ma_ByPawnShi[3]           = {64,32,16};

static const  sint16 ADD_CheXPawn_To1Pawn                      =  64;                     //车兵对兵,
static const  sint16 ADD_CheXPawn_To1Pawn_ByPawnShi[3]         = {64,32,16};

static const  sint16 ADD_ChePawn_To_CheMa_By_PawnByShi[3]      = {64,32,16};              //车兵对车马,兵的加分
static const  sint16 ADD_ChePawn_To_CheMa_Pawn_SX_LessOne      = 108;                     //车兵以车马, 兵方没有1个以下仕相了

static const  sint16 ADD_CheXPawn_To_1Che1Ma1Pawn_ByPawn[3]    = {64,32,16};              //车兵对车马1兵,兵的加分
static const  sint16 ADD_1Che1Ma1Pawn_To_CheXPawn_ByPawn[3]    = {64,32,16};              //车兵对车马1兵,兵的加分

static const  sint16 ADD_CheXPawn_To_1Che1Pao1Pawn_ByPawn[3]    = {64,32,16};              //车兵对车马1兵,兵的加分
static const  sint16 ADD_1Che1Pao1Pawn_To_CheXPawn_ByPawn[3]    = {64,32,16};              //车兵对车马1兵,兵的加分




//************************************************************        有1车对0车 ************************************************************ 
static const  sint16 ADD_ChePawnCan_noChePawnNotcan              =  32;             //有车方的兵能过河，无车方的兵不能过河。

static const  sint16 ADD_2Pao1MaXPawn_1Che1Pao_To_ByPawn[3]      =  { 64, 32, 16 };  //2炮1马X兵对车炮
static const  sint16 ADD_1Pao2MaXPawn_1Che1Pao_To_ByPawn[3]      =  { 64, 32, 16 };  //1炮2马X兵对车炮

static const  sint16 ADD_2Pao1MaXPawn_1Che1Ma_To_ByPawn[3]       =  { 64, 32, 16 };  //2炮1马X兵对车马
static const  sint16 ADD_1Pao2MaXPawn_1Che1Ma_To_ByPawn[3]       =  { 64, 32, 16 };  //1炮2马X兵对车马

static const  sint16 ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[3]      =  { 64, 32, 16 };  //车炮X兵,对2炮1马
static const  sint16 ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[3]      =  { 64, 32, 16 };  //车炮X兵,对1炮2马

static const  sint16 ADD_ChePaoXPawn_To_2Pao1Pawn_ByPawn[3]    =  { 64, 32, 16 };  //车炮X兵,对2炮1兵
static const  sint16 ADD_2Pao1Pawn_To_ChePaoXPawn_ByPawn[3]    =  { 64, 32, 16 };  //车炮X兵,对2炮1兵

static const  sint16 ADD_ChePaoXPawn_To_1Pao1Ma1Pawn_ByPawn[3] =  { 64, 32, 16 };  //车炮X兵,对1炮1马1兵
static const  sint16 ADD_1Pao1Ma1Pawn_To_ChePaoXPawn_ByPawn[3] =  { 64, 32, 16 };  //车炮X兵,对1炮1马1兵

static const  sint16 ADD_ChePaoXPawn_To_2Ma1Pawn_ByPawn[3]	    =  { 64, 32, 16 };  //车炮X兵,对2马1兵
static const  sint16 ADD_2Ma1Pawn_To_ChePaoXPawn_ByPawn[3]     =  { 64, 32, 16 };  //车炮X兵,对2马1兵

static const  sint16 ADD_ChePaoXPawn_To_1Pao2Pawn_ByPawn[3]	=  { 64, 32, 16 };  //车炮X兵,对1马2兵
static const  sint16 ADD_1Pao2Pawn_To_ChePaoXPawn_ByPawn[3]    =  { 64, 32, 16 };  //车炮X兵,对1马2兵

static const  sint16 ADD_ChePaoXPawn_To_1Ma2Pawn_ByPawn[3]	    =  { 64, 32, 16 };  //车炮X兵,对1马2兵
static const  sint16 ADD_1Ma2Pawn_To_ChePaoXPawn_ByPawn[3]     =  { 64, 32, 16 };  //车炮X兵,对1马2兵

static const  sint16 ADD_ChePaoXPawn_To_3Pawn_ByPawn[3]	    =  { 64, 32, 16 };  //车炮X兵,对3兵
static const  sint16 ADD_3Pawn_To_ChePaoXPawn_ByPawn[3]        =  { 64, 32, 16 };  //车炮X兵,对3兵

static const  sint16 ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[3]       =  { 64, 24, 16 };  //车马X兵,对2炮1马
static const  sint16 ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[3]       =  { 64, 32, 16 };  //车马X兵,对1炮2马

static const  sint16 ADD_CheMaXPawn_To_2Pao1Pawn_ByPawn[3]     =  { 64, 32, 16 };  //车马X兵,对2炮1兵
static const  sint16 ADD_2Pao1Pawn_To_CheMaXPawn_ByPawn[3]     =  { 64, 32, 16 };  //车马X兵,对2炮1兵

static const  sint16 ADD_CheMaXPawn_To_1Pao1Ma1Pawn_ByPawn[3]  =  { 64, 32, 16 };  //车马X兵,对1炮1马1兵
static const  sint16 ADD_1Pao1Ma1Pawn_To_CheMaXPawn_ByPawn[3]  =  { 64, 32, 16 };  //车马X兵,对1炮1马1兵

static const  sint16 ADD_CheMaXPawn_To_2Ma1Pawn_ByPawn[3]	    =  { 64, 32, 16 };  //车马X兵,对2马1兵
static const  sint16 ADD_2Ma1Pawn_To_CheMaXPawn_ByPawn[3]      =  { 64, 32, 16 };  //车马X兵,对2马1兵

static const  sint16 ADD_CheMaXPawn_To_1Pao2Pawn_ByPawn[3]	    =  { 64, 32, 16 };  //车马X兵,对1炮2兵
static const  sint16 ADD_1Pao2Pawn_To_CheMaXPawn_ByPawn[3]     =  { 64, 32, 16 };  //车马X兵,对1炮2兵

static const  sint16 ADD_CheMaXPawn_To_1Ma2Pawn_ByPawn[3]	    =  { 64, 32, 16 };  //车马X兵,对1马2兵
static const  sint16 ADD_1Ma2Pawn_To_CheMaXPawn_ByPawn[3]      =  { 64, 32, 16 };  //车马X兵,对1马2兵

static const  sint16 ADD_CheMaXPawn_To_3Pawn_ByPawn[3]	        =  { 64, 32, 16 };  //车马X兵,对3兵
static const  sint16 ADD_3Pawn_To_CheMaXPawn_ByPawn[3]         =  { 64, 32, 16 };  //车马X兵,对3兵

static const  sint16 ADD_CheXPawn_To_2Pao1Ma_ByPawn[3]         =  { 64, 32, 16 };  //车X兵,对2炮1马
static const  sint16 ADD_CheXPawn_To_1Pao2Ma_ByPawn[3]         =  { 64, 32, 16 };  //车X兵,对1炮2马

static const  sint16 ADD_CheXPawn_To_2Pao1Pawn_ByPawn[3]       =  { 64, 32, 16 };  //车X兵,对2炮1兵
static const  sint16 ADD_2Pao1Pawn_To_CheXPawn_ByPawn[3]       =  { 64, 32, 16 };  //车X兵,对2炮1兵

static const  sint16 ADD_Che2Pawn_To_2PaoXPawn_ByPawn[3]       =  { 64, 32, 16 };  //车2兵,对2炮X兵
static const  sint16 ADD_2PaoXPawn_To_Che2Pawn_ByPawn[3]       =  { 80, 48, 24};  //车2兵,对2炮X兵

static const  sint16 ADD_CheXPawn_To_1Pao1Ma1Pawn_ByPawn[3]    =  { 64, 32, 16 };  //车X兵,对1炮1马1兵
static const  sint16 ADD_1Pao1Ma1Pawn_To_CheXPawn_ByPawn[3]    =  { 64, 32, 16 };  //车X兵,对1炮1马1兵

static const  sint16 ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[3]    =  { 64, 32, 16 };  //车2兵,对1炮1马X兵
static const  sint16 ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[3]    =  { 64, 24, 16 };  //车2兵,对1炮1马X兵
static const  sint16 ADD_Che2Pawn_Can0                         =   96;            //车2兵一个兵也不能过河
static const  sint16 ADD_Che2Pawn_Never                        =   96;

static const  sint16 ADD_CheXPawn_To_2Ma1Pawn_ByPawn[3]        =  { 64, 32, 16 };  //车X兵,对2马1兵
static const  sint16 ADD_2Ma1Pawn_To_CheXPawn_ByPawn[3]        =  { 64, 32, 16 };  //车X兵,对2马1兵

static const  sint16 ADD_Che2Pawn_To_2MaXPawn_ByPawn[3]        =  { 64, 32, 24 };  //车2兵,对2马x兵
static const  sint16 ADD_2MaXPawn_To_Che2Pawn_ByPawn[3]        =  { 64, 32, 16 };  //车2兵,对2马x兵

static const  sint16 ADD_CheXPawn_To_1Pao2Pawn_ByPawn[3]       =  { 64, 32, 16 };  //车X兵,对1炮2兵
static const  sint16 ADD_1Pao2Pawn_To_CheXPawn_ByPawn[3]       =  { 64, 32, 16 };  //车X兵,对1炮2兵

static const  sint16 ADD_CheXPawn_To_1Ma2Pawn_ByPawn[3]        =  { 64, 32, 16 };  //车X兵,对1马2兵
static const  sint16 ADD_1Ma2Pawn_To_CheXPawn_ByPawn[3]        =  { 64, 32, 16 };  //车X兵,对1马2兵


static const  sint16 ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[3]  =  { 80, 48, 16};  //炮兵对车兵,炮方安全后,有兵的加分 
static const  sint16 ADD_MaXPawn_To_CheByShi_WmaSafe[3]        =  { 80, 48, 16};  //马兵对车,马兵方安全后,有兵的加分    

static const  sint16 ADD_ChePawn_To_2Pao_By_PawnByShi[3]       =  {128, 80, 32};
static const  sint16 ADD_ChePawn_To_MaPao_By_PawnByShi[3]      =  {128, 80, 32};   //车兵对马炮,车兵方兵要加分,因为马炮太难杀对方了
static const  sint16 ADD_ChePawn_To_2Ma_By_PawnByShi[3]        =  {128, 80, 32};
static const  sint16 ADD_ChePawn_To_MaPao_By_Che               =  64;              //车兵对马炮,车兵方车要加分,因为马炮太难杀对方了

static const  sint16 ADD_CheXPawn_To_MaPawn                    =  96;             //车兵对马兵,车方的加分
static const  sint16 ADD_CheXPawn_To_MaPawn_PawnByShi[3]       =  {168,128, 64};

static const  sint16 ADD_CheXPawn_To_PaoPawn                   =  96;             //车兵对炮兵,车方的加分
static const  sint16 ADD_CheXPawn_To_PaoPawn_PawnByShi[3]      =  {168,128, 64};

static const  sint16 ADD_CheXPawn_To_5Pawn                     =  168;
static const  sint16 ADD_CheXPawn_To_4Pawn                     =  168;
static const  sint16 ADD_CheXPawn_To_3Pawn                     =  168;             //车兵对3兵,车方的加分


static const  sint16 ADD_CheXPawn_To_2Pawn                     =  128;             //车兵对2兵,车方的加分
static const  sint16 ADD_CheXPawn_To_2PawnByShi[3]             =  {196,128, 96};   //车兵对2兵, 车方兵的加分

static const  sint16 ADD_CheXPawn_To_1Pawn                     =  96;             //车兵对1兵,车方的加分
static const  sint16 ADD_CheXPawn_To_PawnByShi[3]              =  {196,128, 96};   //车兵对兵, 车方兵的加分

static const  sint16 ADD_1Pao1MaXPawn_To_1Che_PawnByShi[3]     =  { 48, 24, 16};    //1炮1马x兵对车
static const  sint16 ADD_1Pao1MaXPawn_To_1Che_PawnNotRiver     =  32;

static const  sint16 ADD_2PaoXPawn_To_1Che_PawnByShi[3]        =  { 48, 24, 16};   //2炮x兵对车
static const  sint16 ADD_2MaXPawn_To_1Che_PawnByShi[3]         =  { 48, 24, 16};    //2炮x兵对车


#endif