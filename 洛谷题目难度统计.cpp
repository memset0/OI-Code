/*

	作者: memset0
	网站: https:// memset0.cn 
	
	这个版本代码主要是想资瓷更多功能，以及保证一点稳定性。
	可能还会加上一些注释但由于水平问题可能会有疏漏请题 issue 指正。
	原作者由于某些原因无法找到，如果有侵权请联系我，我会立刻署名 / 删除。 
	
	TODO:
	1. 解决洛谷因为过短时间的请求访问而屏蔽的问题
	2. 资瓷多个用户统计和比较 
	3. 资瓷多线程 

*/
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#ifdef URLDownloadToFile // 避免 URLDownloadToFile 变量重复 
#undef URLDownloadToFile
#endif

typedef int (__stdcall *UDF) (LPVOID,LPCSTR,LPCSTR,DWORD,LPVOID);

UDF URLDownloadToFile = (UDF) GetProcAddress(LoadLibrary("urlmon.dll"), "URLDownloadToFileA");

char* strfind(char *text, char *temp) {
    int i = -1, j, l = strlen(temp);
    while (text[++i]) {
        for (j = 0; j < l; j++)
			if (text[i + j] == 0 || text[i + j] != temp[j])
				break;
        if (j == l)
			return text+i+l;
    }
    return 0;
}
void UTF8ToANSI(char *str) { // 将获取到的 UTF8 格式的网页源码转换为 ANSI 格式 
    int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);
    WCHAR *wsz = new WCHAR[len+1];
    len = MultiByteToWideChar(CP_UTF8, 0,str,-1,wsz,len);
    wsz[len] = 0;
    len = WideCharToMultiByte(CP_ACP, 0, wsz, -1, 0, 0, 0, 0);
    len = WideCharToMultiByte(CP_ACP, 0, wsz, -1, str, len, 0, 0);
    str[len] = 0;
    delete []wsz;
}
HANDLE hOutput;
char name[32];
int count[9];

int GetProblemDifficulty(char *file) { // 获得当前题目的难度 
    file = strfind(file, "lg-bg-");
    if (file[0] == 'r') return 0;
	if (file[0] == 'o') return 1;
    if (file[0] == 'y') return 2;
    if (file[0] == 'g' && file[2] == 'e') return 3;
    if (file[0] == 'b' && file[4] == 'l') return 4; 
    if (file[0] == 'p') return 5;
    if (file[0] == 'b' && file[4] == 'd') return 6;
    if (file[0] == 'g' && file[2] == 'a') return 7;
    return 8;
}

char DifficultyName[9][32] = {
	"入门难度",
	"普及-",
	"普及/提高-",
	"普及+/提高",
	"提高+/省选-",
	"省选/NOI-",
	"NOI/NOI+/CTSC",
	"尚无评定",
	"未知类型"
};
char DifficultySpace[9][32] = { "     ", "        ", "   ", "   ", "  ", "    ", "", "     ", "     " };

void Output(char *prob, int diff) { // 输出 
    COORD pos = {0,2};
	SetConsoleCursorPosition(hOutput, pos); 
    printf("%s 的统计: %s > %s        \n", name, prob, DifficultyName[diff]);
	for (int i = 0; i < 9; i++) {
		printf("  %s:%s%6d\n", DifficultyName[i], DifficultySpace[i], count[i]);
	}
}

void problem(char *str) {
    int i = 0,len;
    DWORD unused;
    char prob[32],url[128],*file,*ptr;
    HANDLE hFile;
    while(*str != '<')prob[i++] = *str++;
    prob[i] = 0;
    sprintf(url, "https://www.luogu.org/problemnew/show/%s", prob);
    URLDownloadToFile(0,url,"download.tmp",0,0);
    hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    len = GetFileSize(hFile,0);
    file = ptr = new char[len+3];
    ReadFile(hFile,file,len,&unused,0);
    file[len] = file[len+1] = 0;
    CloseHandle(hFile);
    file = strfind(file, "\xE9\x9A\xBE\xE5\xBA\xA6");
    if (file) {	
		int diff = GetProblemDifficulty(file);
		count[diff]++; 
		Output(prob, diff);
	} else {
		count[8]++;
		Output(prob, 8);
	}
    delete []ptr;
}

int main() {
    int uid, len, i = 0;
    DWORD unused;
    char url[128], user[16], *file, *ptr;
    HANDLE hFile;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("请输入洛谷UID: ");
    scanf("%d", &uid);
    sprintf(url, "https://www.luogu.org/space/show?uid=%d",uid);
    URLDownloadToFile(0,url,"download.tmp",0,0);
    hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    len = GetFileSize(hFile,0);
    file = new char[len+3];
    ReadFile(hFile,file,len,&unused,0);
    file[len] = file[len+1] = 0;
    CloseHandle(hFile);
    UTF8ToANSI(file);
    sprintf(user,"U%d ",uid);
    ptr = strfind(file,user);
    if (ptr != nullptr) {
        while (ptr[0] != '<' || ptr[1] != '/' || ptr[2] != 'h')
			name[i++] = *ptr++;
        printf("\n%s 的统计: ",name);
        ptr = strfind(file,"通过题目</h2>\n[<");
        if (ptr) {
            while (*ptr != '<') {
                ptr = strfind(ptr,"\">");
                problem(ptr);
                ptr = strfind(ptr,"]\n");
            }
            int ans = 0;
            for (int i = 0; i < 9; i++)
            	ans += count[i];
            printf("总共通过的题目数: %d\n",ans);
        } else {
			printf("未找到通过的题目\n");
		}
    } else {
		printf("用户不存在\n");
	}
    DeleteFile("download.tmp");
    delete []file;
    printf("\n点击任何键退出...");
    getchar();
    return 0;
}
