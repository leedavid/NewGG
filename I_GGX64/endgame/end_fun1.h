//********************************************* 一对无********************
 extern void m_MT_NONE_16(typePOS &POSITION, EvalInfo &ei);
 extern void m_MT_MUST_DRAW(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1CHE(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1CHE(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1PAO(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1PAO(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1PAWN(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1PAWN(typePOS &POSITION, EvalInfo &ei);
//********************************************* 一对一********************

 extern void m_MT_1CHE_TO_1CHE(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1CHE_B_1PAO(typePOS &POSITION, EvalInfo &ei);		 //红一车黑一炮	

 extern void m_MT_B_1CHE_R_1PAO(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1CHE_B_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1CHE_R_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1CHE_B_1PAWN(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1CHE_R_1PAWN(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_PAO_TO_PAO(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1PAO_B_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_B_1PAO_R_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1PAO_B_1PAWN(typePOS &POSITION, EvalInfo &ei);	//红一炮黑一兵

 extern void m_MT_B_1PAO_R_1PAWN(typePOS &POSITION, EvalInfo &ei);	//黑一炮红一兵

// extern void m_MT_R_1MA_B_1MA(typePOS &POSITION, EvalInfo &ei);
//
// extern void m_MT_B_1MA_R_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_1MA_1MA(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_R_1MA_B_1PAWN(typePOS &POSITION, EvalInfo &ei);	//红一马黑一兵

 extern void m_MT_B_1MA_R_1PAWN(typePOS &POSITION, EvalInfo &ei);

 extern void m_MT_PAWN_TO_PAWN(typePOS &POSITION, EvalInfo &ei);     //大家一兵

