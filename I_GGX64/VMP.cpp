
#include "chess.h"

#include <windows.h>
#include <time.h>
#include "VMP.h"
#include "aes.h"
#include "Base64.h"

//#define PRINT_HELPER(state, flag) if (state & flag) printf("%s ", #flag)
//void print_state(int state)
//{
//	if (state == 0)
//	{
//		printf("your are register now! thank you\n");
//		return;
//	}
//
//	printf("state = ");
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_CORRUPTED);
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_INVALID);
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_BLACKLISTED);
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_DATE_EXPIRED);
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_RUNNING_TIME_OVER);
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_BAD_HWID);
//	PRINT_HELPER(state, SERIAL_STATE_FLAG_MAX_BUILD_EXPIRED);
//	printf("\n");
//}

#ifdef USE_VP_PROTECT
//char *read_serial(const char *fname)
char *read_serial(){

	VMProtectBegin(MARKER_NAME1);

	TCHAR KeyFile[1024];
	swprintf_s(KeyFile,sizeof(KeyFile)/sizeof(TCHAR), L"%s\\NewGGreg.key",installDir);

	FILE *f;
	if (0 != _wfopen_s(&f, KeyFile, L"rb")){
		return NULL;
	}
	fseek(f, 0, SEEK_END);
	int s = ftell(f);
	fseek(f, 0, SEEK_SET);
	char *buf = new char[s + 1];
	fread(buf, s, 1, f);
	buf[s] = 0;
	fclose(f);

	VMProtectEnd();
	return buf;
}



void xor_key2(char* hex, int len){
	VMProtectBegin(MARKER_NAME2);

	char key2[] = "efeffeqwertyushnirelitshinrgzxciouthefsfesfaffefefesaff";

	int lenk = sizeof(key2)-5;
	int pk = 0;
	for (int i = 0; i < len; i++){
		char c = hex[i];
		char hc = c ^ key2[pk];
		hex[i] = hc;
		pk++;
		if (pk > lenk){
			pk = 0;
		}
	}

	VMProtectEnd();
}

#define WMI_QUERY_NUM 2

bool is_registered(){
	VMProtectBegin(MARKER_NAME3);

	FILE *f;
	char strhex[32 * WMI_QUERY_TYPENUM* WMI_QUERY_NUM * 2];
	char hard[32 * WMI_QUERY_TYPENUM* WMI_QUERY_NUM * 2];
	char* p2 = NULL;
	int res = 0;
	char cName[64];
	char cDate[64];
	char cMonth[64];
	T_DEVICE_PROPERTY idp[WMI_QUERY_TYPENUM][WMI_QUERY_NUM];

	//  得到当前的注册文件中的信息。
	char* pser = read_serial();
	if (pser != NULL){
		// 解码一下。
		char dstr[2048];
		char DeKey[2048];
		unsigned char key[] = "efaeaffearfefeetet345fe3rfeffaaf";
		AES aes(key);
		aes.InvCipher(pser, dstr);
		unsigned int dsize = 0;
		unsigned char* db64 = base64Decode(dstr, dsize);
		xor_key2((char*)db64, dsize - 1);
		sprintf_s(DeKey, dsize * 2, "%s", db64);



		memset(cName, 0, 64);
		memset(cDate, 0, 64);
		memset(cMonth, 0, 64);
		// 得到用户名;
		char* p1 = strstr(DeKey, "name:");
		p2 = strstr(DeKey, " date:");
		if (p1 == NULL || p2 == NULL){
			return false;
		}
		p1 += 5;
		memcpy(cName, p1, p2 - p1);
		// 得到注册日期;
		p1 = strstr(DeKey, " date:");
		p2 = strstr(DeKey, " Month:");
		if (p1 == NULL || p2 == NULL){
			return false;
		}
		p1 += 6;
		memcpy(cDate, p1, p2 - p1);
		// 得到可升级月数;
		p1 = strstr(DeKey, " Month:");
		p2 = strstr(DeKey, " (End)");
		if (p1 == NULL || p2 == NULL){
			return false;
		}
		p1 += 7;
		memcpy(cMonth, p1, p2 - p1);

		p2 += 6; // p2 指向了机器码
	}

	// 读取当前的机器码
	// 读到系统的硬件rx信息。
	for (int i = 0; i < WMI_QUERY_TYPENUM; i++){
		WMI_DeviceQuery(i, idp[i], WMI_QUERY_NUM);
	}

	// 将硬件信息写到文件中去
	TCHAR HdidFileName[1024];

	swprintf_s(HdidFileName, sizeof(HdidFileName) / sizeof(TCHAR), L"%s\\HWID.txt", installDir);

	if (0 != _wfopen_s(&f, HdidFileName, L"w")){
		return false;
	}

	//memcpy(idpAES, idp, sizeof(idp));

	unsigned char key1[] = "efalkjaefoijageffeofjahfaeohihfeffef";

	AES aes1(key1);
	char str[32 * WMI_QUERY_TYPENUM* WMI_QUERY_NUM * 2];

#pragma warning(disable : 4477)                  // 
	//char result[64 * WMI_QUERY_TYPENUM* WMI_QUERY_NUM];
	str[0] = 0;
	char buf[128];
	for (int i = 0; i < WMI_QUERY_TYPENUM; i++){
		for (int j = 0; j < WMI_QUERY_NUM; j++){
			//if (i == 4) continue;
			sprintf_s(buf, sizeof(buf), "%32S", idp[i][j]);
			strcat_s((str), buf);
		}
	}
	sprintf_s(buf, sizeof(buf), "%32S", L"NewGG_Version_20170422");
	strcat_s((str), buf);
	memcpy(hard, str, sizeof(str));
	int len = (int)strnlen_s(str, 2048);
	xor_key2(str, len);
	char* base64 = base64Encode(str, len);
	aes1.Cipher(base64, strhex);

//0：网卡原生MAC地址
//1：硬盘序列号
//2：主板序列号
//3：CPU ID
//4：BIOS序列号
//5：主板型号
//6：网卡当前MAC地址
		// 下面比较 buf 和 P2
	if (pser != NULL){
		res = 1;
		for (int i = 0; i < 32 * 5; i++){
			if (p2[i] != hard[i]){
				res = 0;
				break;
			}
		}
	}

	// 如果没有注册成功，就读出当前的信息，并加密写入到文件中去。
	if (res == 0){
		
		fprintf_s(f, strhex);
		fflush(f);
		MessageBox(NULL, L"Please send \"HWID.txt\" file to the agent \nwhich under ggchess engine catalog.",
			L"Sorry not registe now!\nwww.ggchess.com", MB_OK);
	}
	else{ // 注册成功了
		printf("info register ok! thank you!\n");
		printf("regName: %s, regDate: %s, Update Month %s\n", cName, cDate, cMonth);
		frist_init();
	}
	
	VMProtectEnd();
	return false;
}

//bool is_registered_old(){
//	VMProtectBegin(MARKER_NAME);
//	int res;
//	res = VMProtectGetSerialNumberState();
//	if(res != 0){
//		char *serial = read_serial();
//		int res = -1;
//		if(serial != NULL)
//	    {
//			res = VMProtectSetSerialNumber(serial);
//
//			VMProtectSerialNumberData sd = {0};
//			VMProtectGetSerialNumberData(&sd, sizeof(sd));
//
//			printf("info user: %ls VIP user Only\n", sd.wUserName);
//
//		    delete [] serial;
//		}
//		if(res != 0){
//
//			// 也有可能不能升级了，
//			if(res == SERIAL_STATE_FLAG_MAX_BUILD_EXPIRED){
//				VMProtectSerialNumberData sd = {0};
//				VMProtectGetSerialNumberData(&sd, sizeof(sd));
//				printf("sorry you key is expiration!  max. date: y = %d, m = %d, d = %d\n", sd.dtMaxBuild.wYear, sd.dtMaxBuild.bMonth, sd.dtMaxBuild.bDay);
//				printf("please contact the agent to renew again!\n");				
//				return false;
//			}
//
//		    printf("info please registe! visit http://www.ggchess.com or contact ggchess agent \n");
//			int nSize = VMProtectGetCurrentHWID(NULL, 0); // get number of required bytes
//			char *pBuf = new char[nSize]; // allocate buffer
//			VMProtectGetCurrentHWID(pBuf, nSize); // obtain hardeare identifier
//
//			TCHAR HdidFileName[1024];
//			FILE *f;
//			swprintf_s(HdidFileName,sizeof(HdidFileName)/sizeof(TCHAR), L"%s\\HWID.txt",installDir);
//
//			if (0 != _wfopen_s(&f, HdidFileName, L"w")){
//				return false;
//			}
//			//得到注册的时间
//#define SIZE 256
//			time_t ltime;
//			char buf[SIZE];
//			time(&ltime);
//			errno_t err;
//			err = ctime_s( buf, 128, &ltime );
//			fprintf_s(f,buf);
//			fprintf_s(f,"your hd ID is:\n--------------------------\n%08x%s",ltime,pBuf);			
//			fflush(f);
//			delete [] pBuf; // release buffer
//
//			///////////////////////////////////////////////////////////////////////////
//			// 再加上自己读的一些信息。
//			T_DEVICE_PROPERTY idp[WMI_QUERY_TYPENUM][8];
//			for (int i = 0; i < WMI_QUERY_TYPENUM; i++){
//				WMI_DeviceQuery(i, idp[i], 8);
//			}
//
//			MessageBox(NULL,L"Please send \"HWID.txt\" file to the agent \nwhich under ggchess engine catalog.",
//				L"Sorry not registe now!\nwww.ggchess.com",MB_OK);			
//			return false;
//		}
//		else{
//			// 得到用户的注册名称
//			printf("info register ok! thank you!\n");
//			// 得到最终可升级版本的时间
//			VMProtectSerialNumberData sd = {0};
//			VMProtectGetSerialNumberData(&sd, sizeof(sd));
//			printf("info you can update until y = %d, m = %d, d = %d\n", sd.dtMaxBuild.wYear, sd.dtMaxBuild.bMonth, sd.dtMaxBuild.bDay);
//
//			return true;
//		}
//	}
//	VMProtectEnd();
//	return false;	
//}
#endif