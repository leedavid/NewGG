

	// 
	// 0  1  2  3  4  5  6  7 
	//	                    black_piece
	//	                 white_piece
	//	              final_queen
	//	            final_rook
	//	         king_pawn
	//	     white_minor
	//	  black_minor
	// mate_bishop&knight
	POSITION->DYN->flags = 0x3; // 
	if(pMat->searchInfo16 & CK_CAN_NOT_EASY_EVAL){	
		//|| (POSITION->DYN->ppietras & 128)){
	}
	else{
		int la_valu;
		if(POS_SIDE){
			posizionale = (POSITION->DYN - 1)->valu_posizionale;
			if(mossa == 0){
				la_valu = 0;
			}
			else{
				int capture = POSITION->DYN->catturaa;
				int to = TO(mossa);  // to
				la_valu = statico_valu[PB90(to)][to] - statico_valu[PB90(to)][FROM(mossa)];
				if(capture){
					la_valu -= statico_valu[capture][to];  // 位置分包括开局分与残局分.
				}
				endgame = (sint16)(la_valu & 0xffff);
				opening = (endgame < 0) + (sint16)((la_valu >> 16) & 0xffff);
				la_valu  = ((opening * totalAttact) + endgame * (256 - totalAttact)) / 256;
			}
			posizionale += la_valu + ei.evscore;
			int v = (posizionale + Material_value )*ei.mul/16;
	#ifdef DEBUG_etest
			POSITION->etest = v;
	#endif
			if (v < -massimo - 16 * (int) (POSITION->DYN - 1)->lazy
				|| v > -minimo + 16 * (int) (POSITION->DYN - 1)->lazy)
			{
				POSITION->DYN->lazy = (POSITION->DYN - 1)->lazy + 1;
				POSITION->DYN->valu = v;
				POSITION->DYN->valu_posizionale = posizionale;
				Mobility (POSITION);
				return;
			}
		}
		else{
			posizionale = (POSITION->DYN - 1)->valu_posizionale;
			if(mossa == 0){
				la_valu = 0;
			}
			else{
				int capture = POSITION->DYN->catturaa;
				int to = TO(mossa);  // to
				la_valu = statico_valu[PB90(to)][to] - statico_valu[PB90(to)][FROM(mossa)];
				if(capture){
					la_valu -= statico_valu[capture][to];  // 位置分包括开局分与残局分.
				}			
				endgame = (sint16)(la_valu & 0xffff);
				opening = (endgame < 0) + (sint16)((la_valu >> 16) & 0xffff);
				la_valu  = ((opening * totalAttact) + endgame * (256 - totalAttact)) / 256;
			}
			posizionale += la_valu + ei.evscore;
			int v = (posizionale + Material_value )*ei.mul/16;
	#ifdef DEBUG_etest
			POSITION->etest = v;
	#endif
			if (v < minimo - 16 * (int) (POSITION->DYN - 1)->lazy
				|| v > massimo + 16 * (int) (POSITION->DYN - 1)->lazy)
			{
				POSITION->DYN->lazy = (POSITION->DYN - 1)->lazy + 1;
				POSITION->DYN->valu = -v;
				POSITION->DYN->valu_posizionale = posizionale;
				Mobility (POSITION);  // 王的攻击性
				return;
			}
		}
	}