
//当棋盘上有1.红方不可走动的棋子 2.黑方的抽将 时
//set_bit(POSITION->DYN->black_xray,msq);
//xray_black_list[msq] = s;

//当棋盘上有1.红方不可走动的棋子 2.黑方的抽将 时
// ei.attPoint[BLACKCOLOR]

#define RCanNotMove_attNum GetBlackAtt_SQcount_CheMaPaoPawn(POSITION,&ei,msq)

Bitboard CannotMove = POSITION->DYN->black_xray;
while(m128_is_have_bit(CannotMove)){	
	int msq     = pop_1st_bit(&CannotMove);
	int s       = xray_black_list[msq];
	switch(PB90(msq)){
	// 红方不能走动的棋
	//=======================================
	case RPAWN:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case BCHE:  // 黑车 红兵 红帅
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum]/2;
			break;
		case BPAO:  // 黑炮 X 红兵 红帅
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum]/2;
			break;
		case BMA:   // 黑马 红兵 红帅  // 这个不可能
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case RMA:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case BCHE:  // 黑车_红马_红帅
			ei.attPoint[BLACKCOLOR] += att_黑车_红马_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum];
			break;
		case BPAO: // 黑炮_红马_红帅
			ei.attPoint[BLACKCOLOR] += att_黑炮_红马_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum];
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_红马_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum];
			valu -= att_Ma_String_Valu[RCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case RPAO:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){ 
		case BCHE:    // 黑车_红炮_红帅
			ei.attPoint[BLACKCOLOR] += att_黑车_红炮_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum];
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_红炮_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum];
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_红炮_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum];
			valu -= att_Ma_String_Valu[RCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case RCHE:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_红车_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum];
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_红车_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum];
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_红车_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum];
			valu -= att_Ma_String_Valu[RCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case RSHI:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_红仕_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum]/2;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_红仕_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum]/2;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_红仕_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case RXIANG:
		// 再看一下是给那个牵制了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_红相_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum]/2;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_红相_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum]/2;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_红相_红帅_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum]/2;
			break;
		}
		break;
	// ********************************************
	case BPAWN:
		// 再看一下是给那个在后面抽将了.
		if(StoY(msq) >= 0x5){
			switch(PB90(s)){
			case BCHE:
				ei.attPoint[BLACKCOLOR] += att_黑车_黑卒_红帅_zhou;
				break;
			case BPAO:
				ei.attPoint[BLACKCOLOR] += att_黑炮_黑卒_红帅_zhou;
				break;
			case BMA:
				ei.attPoint[BLACKCOLOR] += att_黑马_黑卒_红帅_zhou;
				break;
			}
		}
		break;
	//***************************************
	case BMA:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_黑马_红帅_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_黑马_红帅_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_黑马_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case BPAO:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_黑炮_红帅_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_黑炮_红帅_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_黑炮_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case BCHE:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_黑车_红帅_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_黑车_红帅_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_黑车_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case BSHI:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_黑士_红帅_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_黑士_红帅_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_黑士_红帅_zhou;
			break;
		}
		break;
	//***************************************
	case BXIANG:
		// 再看一下是给那个在后面抽将了.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_黑车_黑象_红帅_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_黑炮_黑象_红帅_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_黑马_黑象_红帅_zhou;
			break;
		}
		break;
	default:
		break;
	}
}

