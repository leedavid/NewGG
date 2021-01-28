
//point(opening,endgame) (((opening) << 16) + (endgame))
const static int LackShiAttackByChePoint[] = {
	(((0) << 0) + (0)), (((64) << 16) + (128)), (((128) << 16) + (256))
};
// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
// 我对方少仕，对方有二车的评估 
switch(BShi_num()){
case 2:
	break;
case 1:
	// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
	// 我对方少仕，对方有二车的评估 
	if(RChe_num() == 2){
		int shi = S90_from_piecelist(POSITION,BSHI,0);
		// 如果这个仕受到对方车的攻击，而我方只有将在保护，就加减分
		int n = 0;
		for(int i = 0; i < RChe_num(); i++){
			if(bit_is_set(ei.RcheAtt[i],shi)){
				int s = S90_from_piecelist(POSITION,RCHE,i);
				if(WhiteSEE(POSITION,MOVE_FromTo(s,shi))){
					n++;
				}
			}
		}
		valu += LackShiAttackByChePoint[n];
	}
	break;
case 0:
	break;
}
// fen 4ka3/rC3R3/4b1n1c/p3p3p/2b6/8P/r6R1/4B4/4A4/2BAK4 w
// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
// fen 4ka1R1/rC3R3/2n1b3c/p3p3p/2b6/8P/r8/4B4/4A4/2BAK4 b
// 我对方少仕，对方有二车的评估 
switch(RShi_num()){
case 2:
	break;
case 1:
	// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
	// 我对方少仕，对方有二车的评估 
	if(BChe_num() == 2){
		////看一下仕的攻击
		int shi = S90_from_piecelist(POSITION,RSHI,0);
		// 如果这个仕受到对方车的攻击，而我方只有将在保护，就加减分
		int n = 0;
		for(int i = 0; i < BChe_num(); i++){
			if(bit_is_set(ei.BcheAtt[i],shi)){
				int s = S90_from_piecelist(POSITION,BCHE,i);
				if(BlackSEE(POSITION,MOVE_FromTo(s,shi))){
                   n++;
				}
			}
		}
		valu -= LackShiAttackByChePoint[n];
	}
	break;
case 0:
	break;
}