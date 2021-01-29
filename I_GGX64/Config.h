#ifndef stockfish_MY_CONFIG_H_123
#define stockfish_MY_CONFIG_H_123


#define HAVE_NONE_PAWN_MATERAIL      (1 << 0)   // 红方有足够的子力
#define CK_CAN_USE_FRUIT_PUN         (1 << 1)   // 接近有和棋时不能用模糊裁剪
#define CK_BR_1CHE_4MAPAO            (1 << 2)   // 双方1车还有4个马炮的评价
#define CK_Only_1Che1PaoxPawn        (1 << 3)   // 一方只有1车1炮X兵的评介
#define CK_5000_Material             (1 << 4)


#define SMG(mg,eg)     Score(((mg)<< 16)+(eg)) 
static const  Piece COLOR_BY_SIDE_ADD[2] = { EMPTY, _X_X };

typedef struct {
	sint16 a[6][6][3][3][3][3][3][3];  // BY LGL 20131124
}MARR_t;   // PreMatInfo[6][6][3][3][3][3][3][3]; 比较小。


#ifdef REPEAT_DEBUG

enum REPEAT_INFO {
	REPEAT_NO = 0,					    // 没有重复
	REPEAT_TRUE = 1,				    // 是真和棋
	REPEAT_BAN_ME_CHECK = 2,		    // 走子方走了禁着
	REPEAT_BAN_OTHER_CHECK = 3,         // 走子方走了禁着
	REPEAT_BAN_ME_CAP = 4,				// 走子方走了禁着
	REPEAT_BAN_OTHER_CAP = 5,		    // 走子方走了禁着
};

#define CheckRepetition(sply) \
	switch (pos.is_repeat()){\
	case REPEAT_TRUE: \
	return(Value(0));   \
	case REPEAT_BAN_ME_CHECK: \
	return  value_baned_check_in(sply);   \
	case REPEAT_BAN_OTHER_CHECK: \
	return -value_baned_check_in(sply);   \
	case REPEAT_BAN_ME_CAP: \
	return  value_baned_cap_in(sply);   \
	case REPEAT_BAN_OTHER_CAP: \
	return -value_baned_cap_in(sply);   \
	default: \
	break; \
	};
#else
enum REPEAT_INFO {
	REPEAT_NO = 0,                      // 没有重复
	REPEAT_TRUE = 1,                    // 是真和棋
	REPEAT_BAN_ME_CHECK = 2,		    // 走子方走了禁着
	REPEAT_BAN_OTHER_CHECK = 3,         // 走子方走了禁着
	REPEAT_BAN_ME_CAP = 4,				// 走子方走了禁着
	REPEAT_BAN_OTHER_CAP = 5,		    // 走子方走了禁着
};

#endif

#define CheckRepetition(sply) \
	switch (pos.is_repeat()){\
	case REPEAT_TRUE: \
	return(Value(0));   \
	case REPEAT_BAN_ME_CHECK: \
	return  value_baned_check_in(sply);   \
	case REPEAT_BAN_OTHER_CHECK: \
	return -value_baned_check_in(sply);   \
	case REPEAT_BAN_ME_CAP: \
	return  value_baned_cap_in(sply);   \
	case REPEAT_BAN_OTHER_CAP: \
	return -value_baned_cap_in(sply);   \
	default: \
	break; \
	};


#ifndef NDEBUG
#if defined(_WIN32) || defined(_WIN64)
#define ASSERT(_Expression) (void)( (!!(_Expression)) || ((_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
#else /* defined(_WIN32) || defined(_WIN64) */
#define ASSERT(_Expression) (void)( (!!(_Expression)) || ((#_Expression, __FILE__, __LINE__), 0) )
#endif /* defined(_WIN32) || defined(_WIN64) */
#else /* !NDEBUG */
#define ASSERT(_Expression)
#endif /* !NDEBUG */

#define typePOS Position

struct premat_t {
	sint16  material;		      // 1  子力分	
	uint8   searchInfo8;          // 2. 是棋局的检查状态	
	uint8   phase;                // 4. 残局状态	
};


#endif


