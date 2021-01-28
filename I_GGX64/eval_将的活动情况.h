
// 将的的活动性能。-----------------------------------------------
Bitboard KcanBB;
KcanBB = one_rpawn_rk_attacks(rk); 
KcanBB = _mm_andnot_si128(m128_bb_or_bb(bitboard_occ_white,
	POSITION->DYN->attack_black),KcanBB);
while(m128_is_have_bit(KcanBB)){
	int can = pop_1st_bit(&KcanBB);
	if(StoY(can) == StoY(rk)){  // 能左右移动
		ei.RKing_Info |= KING_CAN_RIGHT_LEFT;
	}
	else {
		ei.RKing_Info |= KING_CAN_UP_DOWN; 
	}
}

if(StoX(rk) != 0x4){
	ei.RKing_Info |= KING_IS_OUT_SIDE;  
}
if(StoY(rk) != 0x9){
	ei.RKing_Info |= KING_IS_NOT_BOTTOM; 
}
if(StoX(bk) != 0x4){
	ei.BKing_Info |= KING_IS_OUT_SIDE; 
}
if(StoY(bk) != 0x0){
	ei.BKing_Info |= KING_IS_NOT_BOTTOM; 
}

//const uint16 KING_CAN_UP_DOWN     = 1 << 0;   // 老将的工作状态
//const uint16 KING_CAN_RIGHT_LEFT  = 1 << 1;
//const uint16 KING_IS_OUT_SIDE     = 1 << 2;
//const uint16 KING_IS_NOT_BOTTOM   = 1 << 3;



////如果将在上面,不能回去,就要扣分
//if(StoY(rk) != 0x9){
//	if((ei.B_att_Rside[RK_LEFT] & KS_M_CAN_UPDOWN) == 0){
//		 ei.Battack_R_Count += KingCanNotBackToBottom;
//	}
//	//fen 3ak4/4a4/9/2N6/P5b2/2B6/7rp/4BA3/R3AKR2/c6r1 w - - 0 0</
//	//再看一下,自己线上车的个数,越多越要扣分
//	Bitboard bbc = m_and(bitboard_white_che,RankBB_A[StoY(rk)]);
//	if(m128_is_have_bit(bbc)){
//		valu -= KingNotOnBottom_Che_SameY_Sub;
//	}
//
//	//再看一下是不是有炮在防守
//	Bitboard bbp = m_and(bitboard_white_pao,RankBB_A[StoY(rk)]);
//	if(m128_is_have_bit(bbp)){
//		ei.Battack_R_Count -= Y_HavePao_Protect; 
//	}
//}
//if(StoX(rk) != 0x4){
//
//	//fen 3ak4/4a4/9/2N6/P5b2/2B6/7rp/4BA3/R3AKR2/c6r1 w - - 0 0
//	if((ei.B_att_Rside[RK_LEFT] & KS_M_CAN_LEFTRIGHT) == 0){
//		ei.Battack_R_Count += KingCanNotBackToMid;
//	}
//
//	//再看一下是不是将线上的自己的车,炮在防守
//	Bitboard bbc = m_and(bitboard_white_che,FileBB_A[StoX(rk)]);
//	if(m128_is_have_bit(bbc)){
//		ei.Battack_R_Count -= X_Have_Che_Protect;
//	}
//	Bitboard bbp = m_and(bitboard_white_pao,FileBB_A[StoX(rk)]);
//	if(m128_is_have_bit(bbp)){
//		ei.Battack_R_Count -= X_Have_Pao_Protect;
//	}
//}


//*************************************************************************************
KcanBB = one_bpawn_bk_attacks(bk); 
KcanBB = _mm_andnot_si128(m128_bb_or_bb(bitboard_occ_black,
	POSITION->DYN->attack_white),KcanBB);
while(m128_is_have_bit(KcanBB)){
	int can = pop_1st_bit(&KcanBB);
	if(StoY(can) == StoY(bk)){  // 能左右移动
		ei.BKing_Info |= KING_CAN_RIGHT_LEFT;
	}
	else {
		ei.BKing_Info |= KING_CAN_UP_DOWN; 
	}
}


//if(StoY(bk) != 0x0){
//	if((ei.R_att_Bside[BK_LEFT] & KS_M_CAN_UPDOWN) == 0){
//		ei.Rattack_B_Count += KingCanNotBackToBottom;
//	}
//
//	//fen 3ak4/4a4/9/2N6/P5b2/2B6/7rp/4BA3/R3AKR2/c6r1 w - - 0 0</
//	//再看一下,自己线上车的个数,越多越要扣分
//	Bitboard bbc = m_and(bitboard_black_che,RankBB_A[StoY(bk)]);
//	if(m128_is_have_bit(bbc)){
//		valu += KingNotOnBottom_Che_SameY_Sub;
//	}
//
//	//再看一下是不是有炮在防守
//	Bitboard bbp = m_and(bitboard_black_pao,RankBB_A[StoY(bk)]);
//	if(m128_is_have_bit(bbp)){
//		ei.Rattack_B_Count -= Y_HavePao_Protect; 
//	}
//
//}
//if(StoX(bk) != 0x4){
//	if((ei.R_att_Bside[BK_LEFT] & KS_M_CAN_LEFTRIGHT) == 0){
//		ei.Rattack_B_Count += KingCanNotBackToMid;
//	}
//
//	//这个要看一下FILE上车,炮的个数,
//	//再看一下是不是将线上的自己的车,炮在防守
//	Bitboard bbc = m_and(bitboard_black_che,FileBB_A[StoX(bk)]);
//	if(m128_is_have_bit(bbc)){
//		ei.Rattack_B_Count -= X_Have_Che_Protect;
//	}
//	Bitboard bbp = m_and(bitboard_black_pao,FileBB_A[StoX(bk)]);
//	if(m128_is_have_bit(bbp)){
//		ei.Rattack_B_Count -= X_Have_Pao_Protect;
//	}
//}

////再看一下是不是有双车抽杀的棋
//if(RXiang_num() <= 1 && BChe_num() == 2 && StoY(yk) != 0x9){
//
//     switch(ei.B_att_Rside[RK_LEFT] & const_CHE_OPEN_INFO){
//	 case KS_S_CHE_MY_SIDE_2_OPEN:
//		 break;
//	 case 
//	 } 
//}

//const uint32   KS_S_CHE_MY_SIDE_1_OPEN   =(1<<4);     // 我这边有一个车开放了
//const uint32   KS_S_CHE_MY_SIDE_2_OPEN   =(KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_1_OPEN);     //我这边有2个车开放了
//
//const uint32   KS_S_CHE_OT_SIDE_1_OPEN   =(1<<6);     // 我另一边有一个车开放了
//const uint32   KS_S_CHE_OT_SIDE_2_OPEN   =(KS_S_CHE_OT_SIDE_1_OPEN + KS_S_CHE_OT_SIDE_1_OPEN);     //我另一边有一个车开放了
//
