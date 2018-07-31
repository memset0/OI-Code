#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int a[1010][1010];
int f[1010][1010];
int max(int a, int b)
{
	if (a > b) return a;
	return b;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
		f[n][i] = a[n][i];
	for (int i = (n - 1); i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = a[i][j] + max(f[i + 1][j], f[i + 1][j + 1]);
			//printf("f[%d][%d]=%d\n", i, j, f[i][j]);
		}
	}
	printf("%d", f[1][1]);
	return 0;
}

