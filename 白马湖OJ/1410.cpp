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
char z[10001];
int n;
int a[1001], b[1001];
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
	int k, j;
    while (scanf("%d", &n) != EOF)
    {
    	int j = 1;
    	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    	for (int i = 1; i <= n; i++)
    	{
    		push(a[i]);
    		if (a[i] == b[j] && j <= n)
			{	
				pop();
				j++;
				while (z[r] == b[j] && r > 0) 
				{
					pop();
					j++;
				}
			}
		}
		for (int i = r; i > 0; i--) 
		{
			if (z[i] == b[j]) j++;
			pop();
		}
		if /*YES*/(j == (n + 1)) printf("YES!\n");
		else /*NO*/ printf("NO!\n");
	}
    return 0;
}
