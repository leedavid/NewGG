
#include <iostream>
#include <string>

#include "chess.h"
#include "evaluate.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "uci.h"
#include "VMP.h"
#include "open_book.h"



#pragma warning(disable : 4530)    

using namespace std;

extern void initTOTAL();
////
//// Functions
////

#ifdef  USE_LOG_FILE

BOOL Open_Log_File(void){

	errno_t err;
	int   log_id;
	TCHAR log_filename[1024];

	for(log_id = 1; log_id < 900; log_id++){
		swprintf_s(log_filename,sizeof(log_filename)/sizeof(TCHAR), L"%slog%03d.txt", log_path, log_id);
		if((err = _wfopen_s(&llog_file, log_filename,L"r")) != 0){
			break;
		}
		fclose(llog_file);
	}
	err = _wfopen_s(&llog_file, log_filename, L"w");

	return err==0;
}

#endif


int main(int argc, char *argv[]) {

	// Disable output buffering: printf() does not work correctly otherwise
	//setvbuf(stdout, NULL, _IONBF, 0);

#include <stdio.h>
#include <stdlib.h>
	TCHAR * filepart;

#ifdef USE_USE_VP_PROTECT_BY_GG
	if(SearchPath(NULL,(L"NewGG.exe"),NULL,MAX_PATH, installDir, &filepart)){
		*filepart = 0;
	}
	else{
		GetCurrentDirectory(MAX_PATH, (installDir));			//得到软件运行目录
	}
#else
	if(SearchPath(NULL,(L"NewGG.exe"),NULL,MAX_PATH, installDir, &filepart)){
		*filepart = 0;
	}
	else{
		GetCurrentDirectory(MAX_PATH, (installDir));			//得到软件运行目录
	}
#endif


#ifdef  USE_LOG_FILE
	swprintf_s(log_path, MAX_PATH, L"%s\\log\\", installDir);
	CreateDirectory(log_path,NULL);
	Open_Log_File();
#endif

	// 将当前线程的优先级降一下
	//HANDLE hProcess = GetCurrentProcess();
	//SetPriorityClass(hProcess, IDLE_PRIORITY_CLASS);  //BELOW_NORMAL_PRIORITY_CLASS  IDLE_PRIORITY_CLASS

	// Initialization through global resources manager
	initTOTAL();  

	MessageBox(NULL,  _T("中国象棋的 AlphaZero\nhttp:\\www.lcchess.com\nQQ群：779375937 \n\n期待您的加入！\n\n20180507"), _T("欢迎使用佳佳象棋"), MB_OK);

#ifdef USE_OPENBOOK
	BD_initEnv(MST);
#endif

	UCI::loop(argc, argv);

	Threads.set(0);
	return 0;
}








