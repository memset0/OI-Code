#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
const int maxn = 310;
int n, m;
int f[maxn][maxn], a[maxn][maxn];
int main()
{
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			int maxx = -1;
			for (int k = 0; k <= i; k++)
				maxx = max(maxx, f[i-k][j-1] + a[j][k]);
			f[i][j] = maxx;
		}
	printf("%d", f[m][n]);
	return 0;
}
