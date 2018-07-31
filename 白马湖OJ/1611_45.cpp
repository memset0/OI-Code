#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
int f[maxn][maxn], a[maxn][maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j+)
		{
			a[i][j] = max(a[i-1][j], a[)
		}
	}
	return 0;
}
