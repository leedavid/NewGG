#ifdef GG_TEST_MODE   // 佳佳测试模式这个不能用.
#else
// advance draw score
if(POSITION->DYN->mossa50 > (REPEAT_DRAW_STEP/2)){
	valu *= (64+64 - POSITION->DYN->mossa50);
	valu /= 64;
}
#endif

#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
//if (RANDOM_COUNT) /* omit Random32 */
//{
//	uint32 r;
//	int n, adj = 0;
//	int mask = (1 << RANDOM_BITS) - 1;
//	r = Random32 (POSITION->cpu);
//	for (n = 0; n < RANDOM_COUNT; n++)
//	{
//		adj = r & mask;
//		r >>= RANDOM_BITS;
//		valu += (r & 1) ? adj : -adj;
//		r >>= 1;
//	}
//}
#endif