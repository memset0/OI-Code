#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int a[39], f[30][10010];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = f[i-1][j];
			if (j > a[i]) f[i][j] += f[i][j-a[i]];
		}
	}
	printf("%d", f[n][m]);
	return 0;
} 
