




//#define  USE_VP_PROTECT                          // 使用VMP 加密


#ifdef NDEBUG    
#define  VIP_USE_INFO                               // 
#endif

#ifdef USE_VP_PROTECT  

#else
#define CAN_OUT_EVAL_INFO
#endif



#ifdef USE_VP_PROTECT                                 // 使用VMP加密
#define CYCLONE_SUB_DEPTH  0
#define CYCLONE_MUL_NPS    2
#else
#define CYCLONE_SUB_DEPTH  0
#define CYCLONE_MUL_NPS    1 



#endif