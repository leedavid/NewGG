#include "chess.h"
#include "open_book.h"
#include "uci.h"

#ifdef USE_OPENBOOK

void LogOut(TCHAR* data) {

};
void LogOuts(char* data) {

};

STOCK_DBS    MST[1];

BOOL isWhiteGo_By_FaceInfo(uint8* f33) {

	switch (f33[0]) {
	case 'f':
	case 'g':
	case 'h':

	case 'o':
	case 'p':
	case 'q':

	case 'x':
	case 'y':
	case 'z':
		return 1;  //return true;
	case '#':
	case '$':
	case '%':

	case ',':
	case '-':
	case '.':

	case '5':
	case '6':
	case '7':
		return 0;
	default:
		LogOut(TEXT("\n备份棋库局面出错,王的位置有错"));
		return 2;
	}

	return 2;
}

BOOL is_book_face_ok(book_face_t *bft) {
	if (abs(bft->info->result) > 2) {
		return FALSE;
	}
	if (abs(bft->info->isuse) > 1) {
		return FALSE;
	}
	return TRUE;
}

//得到当前棋库的棋步信息
int  bk_GetBookInfo(book_face_t* bft, DB *db) {
	int ret;

	DBT key, data;
	memset(&key, 0, sizeof(DBT));
	memset(&data, 0, sizeof(DBT));

	//memset(bft->info,0,sizeof(book_face_info_t));

	bft->info->result = BOOK_NOT_RESULT;
	bft->info->isuse = 0;

	key.data = bft->f33;
	key.size = 33;
	data.ulen = sizeof(book_face_info_t);

	ret = db->get(db, NULL, &key, &data, 0);

	if (ret == 0) {
		book_face_info_t *binfo = (book_face_info_t*)data.data;

		bft->info->isuse = binfo->isuse;
		bft->info->result = binfo->result;
	}

	return ret;
}

//根据棋库的得分，得到结果字符串
TCHAR* BookScoreToChar(int score) {

	switch (score) {
	case BOOK_VERY_GOOD:
		return _T("红大优");
		break;
	case BOOK_LIT_GOOD:
		return _T("红略优");
		break;
	case BOOK_BALANCE:
		return _T("  均势");
		break;
	case BOOK_LIT_BAD:
		return _T("黑略优");
		break;
	case BOOK_VERY_BAD:
		return _T("黑大优");
		break;
	default:
		return _T(" ");
		break;
	}
}

// db_err_handle

void BD_my_error_handler(const DB_ENV* env, const char *error_prefix, const char *msg) {
	if (msg != NULL) {
		//printf("info DB_ERR: %s %s\n",error_prefix,msg); 

		LogOut(TEXT("DB_ERR: "));
		LogOuts((char*)error_prefix);
		LogOuts((char*)msg);
	}
}


const char ASCP90[128] = {
	//   0   1   2   3   4   5   6   7   8   9
	91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
	91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
	91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
	91, 91,  0,  1, 91,  3,  4,  5,  6, 91,
	//          32   !   "   #   $   %   &   '
	8,  9, 10, 11, 12, 13, 14, 15, 16, 17,
	//  (    )   *   +   ,   -   .   /   0   1  
	18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
	//   2   3   4   5   6   7   8   9   :   ;
	28, 29, 30, 31,  2, 32, 33, 34, 35, 36,
	//   <   =   >   ?   @   A   B   C   D   E
	37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
	//   F   G   H   I   J   K   L   M   N   O
	47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
	//   P   Q   R   S   T   U   V   W   X   Y
	57, 58, 91, 59,  7, 60, 91, 61, 62, 63,
	//    Z  [   \   ]   ^   _   '   a   b   c
	64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
	//	 d   e   f   g   h   i   j   k   l   m
	74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
	//   n   o   p   q   r   s   t   u   v   w
	84, 85, 86, 87, 88, 89, 90, 91,
	//   x   y   z   {   |    }  ~  DEl
};

char P90ASC[92];


void p90ToAsc(void) {
	for (int i = 0; i < sizeof(ASCP90); i++) {
		P90ASC[ASCP90[i]] = i;
	}
}

int BD_initEnv(STOCK_DBS* mst) {      //初始化环境

	p90ToAsc();

	mst->Book_Init_Ok = FALSE;

	LogOut(TEXT("正在初始化棋库数据库。。。!\n"));

	memset(mst, 0, sizeof(STOCK_DBS));

	uint32 env_flag = DB_CREATE
		| DB_INIT_MPOOL;      //初始化in-memory cache
							  //|DB_THREAD ;        //数据库句柄可以给多个线程使用

	mst->book_db_name = "book.db";
	// mst->good_db_name = "good.db";

	int ret;

	ret = db_env_create(&mst->Env, 0);

	if (ret != 0) {
		LogOut(TEXT("DB_ERR: Create env: "));
		LogOuts(db_strerror(ret));
		return ret;
	}

	if (Options["UseOpenNet"]) {
		ret = mst->Env->open(mst->Env,
			CW2A(_T("W:\\")),
			env_flag,
			0);
	}
	else {
		ret = mst->Env->open(mst->Env,
			CW2A(installDir),
			env_flag,
			0);
	}

	

	if (ret != 0) {
		LogOut(TEXT("DB_ERR: Environment open: "));
		LogOuts(db_strerror(ret));
		return ret;
	}

	//建立book数据库连接

	ret = db_create(&mst->book, mst->Env, 0);

	if (ret != 0) {
		LogOut(TEXT("DB_ERR: Create Book: "));
		LogOuts(db_strerror(ret));
		return ret;
	}

	mst->book->set_errcall(mst->book, BD_my_error_handler);
	mst->book->set_errpfx(mst->book, "book->");

	//打开book 数据库
	ret = mst->book->open(mst->book,
		NULL,
		mst->book_db_name,
		NULL,
		DB_HASH,
		DB_CREATE,
		0);

	if (ret != 0) {
		mst->book->err(mst->book, ret, "book file open failed: %s", mst->book_db_name);
		return ret;
	}

	LogOut(TEXT("初始化棋库数据库成功!\n"));

	mst->Book_Init_Ok = TRUE;

	//mst->back_db = NULL;

	return ret;

}


void BerKeley_DB_EXIT(STOCK_DBS *mst) {
	if (mst->book != NULL) {
		mst->book->close(mst->book, 0);
	}
}


void strCopybyNum(char* dst, size_t num, char* src) {
	size_t i;
	for (i = 0; i < num; i++) {
		dst[i] = src[i];
	}
	dst[i] = 0; //加上结尾
}

int GetValByBookFaceInfo(book_face_info_t *pFinfo, Color side) {

	int val = 0;

	int pj = pFinfo->result;


	if (side == BLACK) {
		val = (+pj * 50 * 100 / 50);
	}
	else {
		val = (-pj * 50 * 100 / 50);
	}

	return val;
}

void GetMirrorOnlyB33(Color sideToMove, Piece orgb90[90], uint8 b33[33], Move m) {

	int from = FROM(m);
	Piece fromPiece = orgb90[from];
	int to = TO(m);
	Piece capPiece = orgb90[to];

	orgb90[from] = EMPTY;
	orgb90[to] = fromPiece;
	
	// 先把现在的棋子换成原来的棋子
	Piece b90[90];

	for (int i = 0; i < 90; i++) {
		switch (orgb90[i]) {
		case RKING:
			b90[i] = RKING;
			break;
		case RSHI:
			b90[i] = RSHI;
			break; 
		case RXIANG:
			b90[i] = RXIANG;
			break;
		case RMA:
			b90[i] = RMA;
			break;
		case RCHE:
			b90[i] = RCHE;
			break;
		case RPAO:
			b90[i] = RPAO;
			break;
		case RPAWN:
			b90[i] = RPAWN;
			break;
		case BKING:
			b90[i] = _X_X;
			break;
		case BSHI:
			b90[i] = BKING;
			break;
		case BXIANG:
			b90[i] = BSHI;
			break;
		case BMA:
			b90[i] = BXIANG;
			break;
		case BCHE:
			b90[i] = BMA;
			break;
		case BPAO:
			b90[i] = BCHE;
			break;
		case BPAWN:
			b90[i] = BPAO;
			break;
		default:
			b90[i] = EMPTY;
		}
	}
	

	
	uint8 sq;
	Piece   chess;

	for (int i = 0; i < 32; i++) {
		b33[i] = D8none;
	}

	//sideToMove = Color(sideToMove ^ 0x1);

	bool useMirror = false;

	Piece *pc = b90; //  +0x33;
	for (int y = 0; y < 10; y++) {

		if (*(pc + 8) > *(pc + 0)) {
			goto MIRROR;
		}
		else if (*(pc + 8) < *(pc + 0)) {
			goto UNMIROR;
		}

		if (*(pc + 7) > *(pc + 1)) {
			goto MIRROR;
		}
		else if (*(pc + 7) < *(pc + 1)) {
			goto UNMIROR;
		}


		if (*(pc + 6) > *(pc + 2)) {
			goto MIRROR;
		}
		else if (*(pc + 6) < *(pc + 2)) {
			goto UNMIROR;
		}


		if (*(pc + 5) > *(pc + 3)) {
			goto MIRROR;
		}
		else if (*(pc + 5) < *(pc + 3)) {
			goto UNMIROR;
		}
		pc += 9;
	}

MIRROR:
	useMirror = true;
UNMIROR:

	for (sq = 0x0; sq<90; sq++) {
		//if (b90[sq] != EMPTY) {

			if (useMirror) {
				chess = b90[Mirror(sq)];
			}
			else {
				chess = b90[sq];
			}

			switch (chess) {
			case RKING:                          //红帅,如果是红方走,就b33[16] == RKING
				if (sideToMove == WHITE) {
					b33[16] = P90ASC[sq];
				}
				else {
					b33[0] = P90ASC[sq];
				}
				break;
			case _X_X:
				if (sideToMove == WHITE) {
					b33[0] = P90ASC[sq];
				}
				else {
					b33[16] = P90ASC[sq];
				}
				break;
			case RSHI:
				if (b33[1] == D8none) {
					b33[1] = P90ASC[sq];
				}
				else {
					b33[2] = P90ASC[sq];
				}
				break;
			case RXIANG:
				if (b33[3] == D8none) {
					b33[3] = P90ASC[sq];
				}
				else {
					b33[4] = P90ASC[sq];
				}
				break;
			case RMA:
				if (b33[5] == D8none) {
					b33[5] = P90ASC[sq];
				}
				else {
					b33[6] = P90ASC[sq];
				}
				break;
			case RCHE:
				if (b33[7] == D8none) {
					b33[7] = P90ASC[sq];
				}
				else {
					b33[8] = P90ASC[sq];
				}
				break;
			case RPAO:
				if (b33[9] == D8none) {
					b33[9] = P90ASC[sq];
				}
				else {
					b33[10] = P90ASC[sq];
				}
				break;
			case RPAWN:
				if (b33[11] == D8none) {
					b33[11] = P90ASC[sq];
				}
				else if (b33[12] == D8none) {
					b33[12] = P90ASC[sq];
				}
				else if (b33[13] == D8none) {
					b33[13] = P90ASC[sq];
				}
				else if (b33[14] == D8none) {
					b33[14] = P90ASC[sq];
				}
				else {
					b33[15] = P90ASC[sq];
				}
				break;
				//*********************************
			case BSHI-1:
				if (b33[17] == D8none) {
					b33[17] = P90ASC[sq];
				}
				else {
					b33[18] = P90ASC[sq];
				}
				break;
			case BXIANG-1:
				if (b33[19] == D8none) {
					b33[19] = P90ASC[sq];
				}
				else {
					b33[20] = P90ASC[sq];
				}
				break;
			case BMA-1:
				if (b33[21] == D8none) {
					b33[21] = P90ASC[sq];
				}
				else {
					b33[22] = P90ASC[sq];
				}
				break;
			case BCHE-1:
				if (b33[23] == D8none) {
					b33[23] = P90ASC[sq];
				}
				else {
					b33[24] = P90ASC[sq];
				}
				break;
			case BPAO-1:
				if (b33[25] == D8none) {
					b33[25] = P90ASC[sq];
				}
				else {
					b33[26] = P90ASC[sq];
				}
				break;
			case BPAWN-1:
				if (b33[27] == D8none) {
					b33[27] = P90ASC[sq];
				}
				else if (b33[28] == D8none) {
					b33[28] = P90ASC[sq];
				}
				else if (b33[29] == D8none) {
					b33[29] = P90ASC[sq];
				}
				else if (b33[30] == D8none) {
					b33[30] = P90ASC[sq];
				}
				else {
					b33[31] = P90ASC[sq];
				}
				break;
			default:
				break;
			}
		//}
	}


	b33[32] = 0;        //加上结尾


	// 恢复原来的棋子
	orgb90[from] = fromPiece;
	orgb90[to] = capPiece;

}


#endif