
//当棋盘上有1.红方不可走动的棋子 2.黑方的抽将 时
//set_bit(POSITION->DYN->black_xray,msq);
//xray_black_list[msq] = s;

//当棋盘上有1.黑方不可走动的棋子 2.红方的抽将 时

#define BCanNotMove_attNum GetWhiteAtt_SQcount_CheMaPaoPawn(POSITION,&ei,msq)

CannotMove = POSITION->DYN->white_xray;
while(m128_is_have_bit(CannotMove)){	
	int msq     = pop_1st_bit(&CannotMove);
	int s       = xray_white_list[msq];

	//只有黑方才要用哇
	//int attNum  = GetWhiteAtt_SQcount_CheMaPaoPawn(POSITION,&ei,msq);

	// 1, 不能动, 
	switch(PB90(msq)){
	// 黑方不能走动的棋
	//=======================================
	case BPAWN:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case RCHE:  // 黑车 红兵 红帅
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum]/2;
			break;
		case RPAO:  // 黑炮 X 红兵 红帅
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum]/2;
			break;
		case RMA:   // 黑马 红兵 红帅  // 这个不可能
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case BMA:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case RCHE:  // 黑车_红马_红帅
			ei.attPoint[WHITECOLOR] += att_黑车_红马_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum];
			break;
		case RPAO: // 黑炮_红马_红帅
			ei.attPoint[WHITECOLOR] += att_黑炮_红马_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum];
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_红马_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum];
			valu += att_Ma_String_Valu[BCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case BPAO:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){ 
		case RCHE:    // 黑车_红炮_红帅
			ei.attPoint[WHITECOLOR] += att_黑车_红炮_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum];
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_红炮_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum];
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_红炮_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum];
			valu += att_Ma_String_Valu[BCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case BCHE:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_红车_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum];
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_红车_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum];
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_红车_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum];
			valu += att_Ma_String_Valu[BCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case BSHI:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_红仕_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum]/2;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_红仕_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum]/2;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_红仕_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case BXIANG:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_红相_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum]/2;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_红相_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum]/2;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_红相_红帅_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum]/2;
			break;
		}
		break;

	//***************************************
	case RPAWN:
		// 再看一下是给那个在后面抽将了.
		if(StoY(msq) <= 0x4){
			switch(PB90(s)){
			case RCHE:
				ei.attPoint[WHITECOLOR] += att_黑车_黑卒_红帅_zhou;
				break;
			case RPAO:
				ei.attPoint[WHITECOLOR] += att_黑炮_黑卒_红帅_zhou;
				break;
			case RMA:
				ei.attPoint[WHITECOLOR] += att_黑马_黑卒_红帅_zhou;
				break;
			}
		}
		break;
	//***************************************
	case RMA:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_黑马_红帅_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_黑马_红帅_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_黑马_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case RPAO:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_黑炮_红帅_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_黑炮_红帅_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_黑炮_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case RCHE:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_黑车_红帅_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_黑车_红帅_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_黑车_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case RSHI:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_黑士_红帅_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_黑士_红帅_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_黑士_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case RXIANG:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_黑车_黑象_红帅_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_黑炮_黑象_红帅_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_黑马_黑象_红帅_zhou;
			break;
		}
		break;
	default:
		break;
	}	
} 