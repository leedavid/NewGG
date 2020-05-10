#ifndef XGC_殘局加分_2车_H
#define XGC_殘局加分_2车_H

//************************************************************        有2车对有2车
static const  sint16 ADD_MT_2che1pao1pawn_2che1pao_ByShi[3]	    = { 80, 36, 16};  
static const  sint16 ADD_MT_2che1ma1pawn_2che1pao_ByShi[3]	    = { 80, 36, 16};  
static const  sint16 ADD_MT_2che1pao1pawn_2che1ma_ByShi[3]		= { 80, 36, 16};  
static const  sint16 ADD_MT_2che1ma1pawn_2che1ma_ByShi[3]		= { 80, 36, 16};  

static const  sint16 ADD_1che1ma1paoXpawn_2che1pawnByCan       =  32;
static const  sint16 ADD_1che2paoXpawn_2che1pawnByCan          =  32;
static const  sint16 ADD_1che2maXpawn_2che1pawnByCan           =  32;

static const  sint16 ADD_2车x兵对1车2马                          =  80;

static const  sint16 ADD_2che_2che_const_Shi_add[3]             = {128,48,0};

static const  sint16 ADD_2车x兵对2车_byPawn[3]                   =  { 80, 36, 16}; 

//************************************************************        有2车对有1车 
static const  sint16 ADD_2che1pao1maXPawn_2chexPawn[3]             = { 64, 36, 16};

static const  sint16 ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[3]    = { 80, 36, 16};            //2车x兵对1车1炮1马1兵, 兵方的加分
static const  sint16 ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[3]    = { 80, 36, 16};            //1车1炮1马1兵对2车x兵, 兵方的加分

static const  sint16 ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  48;                     //2车方有兵可过河，

static const  sint16  ADD_2che1paoXpawn_2che_ByShi[3]          = {80, 48, 32};   //1 
static const  sint16  ADD_2che1maXpawn_2che_ByShi[3]           = {80, 48, 32};   //1 


static const  sint16  ADD_1Che1Pao1MaXPawn_2CheOnly[3]         = { 80, 36, 16};   //1 
static const  sint16  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe       = 32;
static const  sint16  ADD_1Che1Pao1MaXPawn_PawnNotOverRiver    = 32;

static const  sint16 ADD_2CheXPawn_2Che1Pawn_ByShi[3]          = { 80, 36, 16};            //2车x兵对2车1兵, 兵的加分
static const  sint16 ADD_2CheXPawn_1Che2Pao_ByPawnShi[3]       = { 80, 36, 16};            //2车x兵对1车2炮, 兵方的加分

static const  sint16 ADD_2CheXPawn_1Che1Pao1Ma_ByPawnShi[3]    = { 80, 36, 16};            //2车x兵对1车1炮1马, 兵方的加分

static const  sint16 ADD_2CheXPawn_1Che2Ma_ByPawnShi[3]        = { 80, 36, 16};            //2车x兵对1车2马, 兵方的加分

static const  sint16 ADD_2CheXPawn_1Che1Pao1Pawn_ByShi[3]      = { 80, 36, 16};            //2车x兵对1车1炮1兵, 兵方的加分
static const  sint16 ADD_1Che1PaoXPawn__2Che1Pawn_ByShi[3]     = { 80, 36, 16}; 

static const  sint16 ADD_2CheXPawn_1Che1Ma1Pawn_ByShi[3]       = { 80, 36, 16};            //2车x兵对1车1马1兵, 兵方的加分
static const  sint16 ADD_1Che1MaXPawn__2Che1Pawn_ByShi[3]      = { 80, 36, 16}; 

static const  sint16 ADD_2CheXPawn_1Che2Pawn_ByShi[3]          = { 80, 36, 16};            //2车x兵对1车2兵, 兵方的加分
static const  sint16 ADD_1CheXPawn__2Che1Pawn_ByShi[3]         = { 80, 36, 16}; 

static const  sint16  ADD_1Che1PaoXPawn_2Che1Pao_ByPawnShi[3]   = {80, 32, 16}; 	        //车炮x兵对2车1炮的加分
static const  sint16  ADD_1Che1PaoXPawn_2Che1Ma_ByPawnShi[3]    = {80, 32, 16}; 	        //车炮x兵对2车1马的加分

static const  sint16  ADD_1che1paoXpawn_To_2che1pawn_ByShi[3]   = {80, 32, 16}; 	        //车炮x兵对2车1兵的加分
static const  sint16  ADD_2che1pawn_To_1pao1paoXpawn_ByShi[3]   = {80, 32, 16}; 	        //车炮x兵对2车1兵的加分

static const  sint16  ADD_1che1paoXpawn_To_2che1pawn_ByPsafe    = 168; 	                //车炮x兵对2车1兵的加分
//static const  sint16  ADD_2che1pawn_To_1pao1paoXpawn_ByShiPsafe[3]   = { 80, 36, 16}; 	        //车炮x兵对2车1兵的加分

#endif