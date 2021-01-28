

//fen 3k2b2/4a4/4ba3/6r1p/3PC4/3R4P/9/5A3/3KA4/8c b - - 127 127
if(pMat->searchInfo16 & (CK_R_Only_1Che1PaoxPawn + CK_B_Only_1Che1PaoxPawn)){

	// 红方只有1车1炮x兵 时的攻势分
	if(pMat->searchInfo16 & CK_R_Only_1Che1PaoxPawn){			
		int malr = White_pawn_already_over_river(POSITION);
		if(malr == 0){
			int mpao = S90_from_piecelist(POSITION,RPAO,0);
			int mcan = ei.rcan;
			int yalr = Black_pawn_already_over_river(POSITION);
			int ycan = ei.bcan;

			if(StoY(mpao) <= 0x4){
				if(malr == 0){				
					for(int i = 0; i < yalr; i++){
						valu -= Only_1Che1PaoxPawn_Your_pawnAlr_Pao_Not_Home;
					}
				}
				if(mcan == 0){				
					for(int i = 0; i < ycan; i++){
						valu -= Only_1Che1PaoxPawn_Your_pawnCan_Pao_Not_Home;
					}
				}
			}
			else{
				if(malr == 0){
					for(int i = 0; i < yalr; i++){
						valu -= Only_1Che1PaoxPawn_Your_pawnAlr_Pao_at_Home;
					}
				}

				if(mcan == 0){
					for(int i = 0; i < ycan; i++){
						valu -= Only_1Che1PaoxPawn_Your_pawnCan_Pao_at_Home;
					}
				}
			}
			//再看一下我方的炮是不是被牵制了。

			//fen 7r1/4k4/5a2b/p7p/6p2/3N5/P6cP/B3B4/4A4/4KR3 b - - 0 0
			if(BMa_num() != 0){
				if(RShi_num() <= 1 || RXiang_num() <= 1){
					Bitboard yma = m_and(bitboard_black_ma,LowBB[0x3]);
					if(m128_is_have_bit(yma)){
						valu -= Only_1Che1PaoxPawn_Your_Ma_add[RShi_num() + RXiang_num()];
					}
				}
			}
		}
		}
	// 黑方只有1车1炮x兵 时的攻势分
	if(pMat->searchInfo16 & CK_B_Only_1Che1PaoxPawn){			
		int malr = Black_pawn_already_over_river(POSITION);
		if(malr == 0){
			int mpao = S90_from_piecelist(POSITION,BPAO,0);
			int mcan = ei.bcan;
			int yalr = White_pawn_already_over_river(POSITION);
			int ycan = ei.rcan;
			if(StoY(mpao) >= 0x5){
				if(malr == 0){				
					for(int i = 0; i < yalr; i++){
						valu += Only_1Che1PaoxPawn_Your_pawnAlr_Pao_Not_Home;
					}
				}
				if(mcan == 0){				
					for(int i = 0; i < ycan; i++){
						valu += Only_1Che1PaoxPawn_Your_pawnCan_Pao_Not_Home;
					}
				}
			}
			else{
				if(malr == 0){
					for(int i = 0; i < yalr; i++){
						valu += Only_1Che1PaoxPawn_Your_pawnAlr_Pao_at_Home;
					}
				}

				if(mcan == 0){
					for(int i = 0; i < ycan; i++){
						valu += Only_1Che1PaoxPawn_Your_pawnCan_Pao_at_Home;
					}
				}
			}
			//fen 7r1/4k4/5a2b/p7p/6p2/3N5/P6cP/B3B4/4A4/4KR3 b - - 0 0
			if(RMa_num() != 0){
				if(BShi_num() <= 1 || BXiang_num() <= 1){
					Bitboard yma = m_and(bitboard_white_ma,UpBB[0x6]);
					if(m128_is_have_bit(yma)){
						valu += Only_1Che1PaoxPawn_Your_Ma_add[BShi_num() + BXiang_num()];
					}
				}
			}
		}
	}
}