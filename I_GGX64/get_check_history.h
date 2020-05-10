
#ifdef USE_STACK_CHECK
if(POS_SIDE == 0){
	if(m128_is_have_bit(POSITION->DYN->black_king_check)){
		//board_display(POSITION,"white in check\n");
		POSITION->STACKst[POSITION->StackHeight].checkk = TRUE;
	}
	else{
		POSITION->STACKst[POSITION->StackHeight].checkk = FALSE;
	}
}
else{
	if(m128_is_have_bit(POSITION->DYN->white_king_check)){
		//board_display(POSITION,"white in check\n");
		POSITION->STACKst[POSITION->StackHeight].checkk = TRUE;
	}
	else{
		POSITION->STACKst[POSITION->StackHeight].checkk = FALSE;
	}
}
#endif