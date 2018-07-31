#include <iostream> 
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
#define y1 sb002
#define y2 sb003
#define mark sb004
#define cst sb005
using namespace std;
double ans[1001];
char opl[1001];
int n[1001];
int r = 0;
int pop()
{
    r = r - 1;
}
int push(int n)
{
    z[++r] = n;
}
int main()
{
	char str[1000];
	int n = 0;
	char c;
	int w = 0;
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if ('0' <= c && c <= '9') n = n * 10 + c - '0';
	}
	printf("%.2lf", ans[0]);
    return 0;
}
