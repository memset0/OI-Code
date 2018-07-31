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
int z[101];
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
    char ch = ' ';
    char cge[200];
    cge['['] = ']';
    cge['('] = ')';
    cge['{'] = '}';
    int ans = -1;
    int i = 0;
    while (ch != '@')
    {
    	i++;
    	scanf("%c", &ch);
    	if (ans != -1) continue;
    	if (ch == '(' || ch == '[' || ch == '{')
    	{
    		push(cge[ch]);
		}
		if (ch == ')' || ch == ']' || ch == '}')
		{
			if (r == 0 || z[r] != ch) {ans = i; continue;}
			else pop();
		}
	}
	if (ans == -1) printf("OK!");
	else printf("%d", ans);
    return 0;
}
