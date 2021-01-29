

////if(rche >= 1 && bche == 0){
////	pMat->searchInfo16 |= CK_R_12Che_B_NoChe;
////}
////if(bche >= 1 && rche == 0){
////	pMat->searchInfo16 |= CK_B_12Che_R_NoChe;
////}
////if(bche == 0 && rche == 0){
////	pMat->searchInfo16 |= CK_R_NoChe_B_NoChe;
////}

if(pMat->searchInfo16 & CK_Eval_Pawn_Can){

	ei.rcan = White_pawn_can_over_river(POSITION);
	ei.bcan = Black_pawn_can_over_river(POSITION);

	ei.evscore += ei.rcan * PawnCanAddByChe[RChe_num()][BChe_num()];
	ei.evscore -= ei.bcan * PawnCanAddByChe[BChe_num()][RChe_num()];

	//if(FALSE){
	//}
	//else if(pMat->searchInfo16 & CK_R_12Che_B_NoChe){	// 红方有车,黑方没有车
	//	ei.evscore += RChe_num() * rcan * 32;
	//	ei.evscore -= bcan * 16;
	//}
	//else if(pMat->searchInfo16 & CK_B_12Che_R_NoChe){	// 黑方有车,红方没有车
	//	ei.evscore -= BChe_num() * bcan * 32;
	//	ei.evscore += rcan * 16;
	//}
	//else if(pMat->searchInfo16 & CK_R_NoChe_B_NoChe){	// 双方没有车
	//	ei.evscore += rcan * 32;
	//	ei.evscore -= bcan * 32;
	//}	

}