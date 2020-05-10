// move_null

#ifdef USE_STOCK_FISH_FILE
#else

static INLINE void MakeNull (typePOS* POSITION)         // null_do(
{
  POSITION->nodes++;
  POSITION->DYN->SAVED_FLAGS = POSITION->DYN->flags;
  memcpy (POSITION->DYN + 1, POSITION->DYN, sizeof(DYN_size64)); // 64
  POSITION->DYN++;
  POSITION->DYN->HASH ^= ZOBRIST_side;             // zobrist_mossa_bianca;     // 走子方HASH
  POS_SIDE ^= 1;
  POSITION->height++;
  //POSITION->DYN->mossa50 ++;      // 这个不能加.
  POSITION->DYN->mossa50 = 0;
  POSITION->DYN->valu = -((POSITION->DYN - 1)->valu + TempoValue);    // 先手分
  POSITION->DYN->valu_posizionale = (POSITION->DYN - 1)->valu_posizionale;
  POSITION->DYN->lazy = (POSITION->DYN - 1)->lazy;
  POSITION->DYN->flags &= ~3;
  POSITION->DYN->move = 0;
  
#ifdef USE_STACK_MOVE
  POSITION->StackHeight++;
#ifdef USE_STACK_CHECK
  POSITION->STACKst[POSITION->StackHeight].checkk    = 0;
#endif
  POSITION->STACKst[POSITION->StackHeight].move      = 0;
  POSITION->STACKst[POSITION->StackHeight].capturer  = 0;
  POSITION->STACKst[POSITION->StackHeight].HASH      = POSITION->DYN->HASH;
#else
  POSITION->STACK[++(POSITION->StackHeight)] = POSITION->DYN->HASH;
#endif

 }

static INLINE void UndoNull (typePOS* POSITION) // null_cancel
{
  POSITION->DYN--;
  POSITION->StackHeight--;
  POSITION->height--;
  POS_SIDE ^= 1;
  POSITION->DYN->flags = POSITION->DYN->SAVED_FLAGS;
}

#include <cmath>
/*smooth scaling added from RobboLito version 0.009*/
static INLINE int null_new_depth(int depth, int delta)
{
	double ddelta, r;
	ddelta = MIN((double)delta, 225.0);
	ddelta = MAX(ddelta, 1.0); 
	r = MAX(0.18 * (double)depth + 3.1, 8) + sqrt(ddelta) / 10.0;
	r = MIN(r, (double)depth);  
	return (depth - (int)r);
}

#define NULL_REDUCTION   8
#define VERIFY_REDUCTION 2


#endif


