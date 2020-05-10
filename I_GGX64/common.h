#define   REPEAT_NO        0       //没有重复
#define   REPEAT_TRUE      1       //是真和棋
#define   REPEAT_BAN_ME    3       //走子方走了禁着
#define   REPEAT_BAN_OTHER 4       //走子方走了禁着

// common.h

#define TempoValue		5                  // value_tempo was 5
#define TempoValue2		5
#define PrunePawn    	160                // pawn_plum   // 理想之物 plum
#define PruneMinor  	500                // minor_plum
#define PruneRook   	800                // rook_plum   // torre rook
#define PruneCheck  	10                 // check_plum
#define LazyValue		150                // value_lazy
#define LazyValue2		300

#define EARLY_GAME  ((POSITION->pMat->searchInfo16 & IS_EARLY_GAME) != 0)

#define MAX_POSITIONAL(x)\
 ((int) MAX_POSITIONAL_GAIN[POSITION->cpu][PB90(FROM(x))][x & MOVE07FFF])


#define IsInterpose(x) (x & (1 << 15))  // #define IsInterpose(x) (x & (1 << 15))
#define EasySEE(x) (x & 0x300000)       // see_easy

#define PassedPawnPush(to, x) (FALSE)

#define PIECE_WHITE(pezzo)   (pezzo <= 7)
#define PIECE_BLACK(pezzo)   (pezzo >= 9)

#define QSEARCH_CONDITION        (new_depth <= 1)
#define LOW_DEPTH_CONDITION      (new_depth <= 7)
#define LOW_DEPTH_CONDITION_PV   (new_depth <= 7)


