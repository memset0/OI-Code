#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
int a[maxn][maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= m; i++)
		a[0][i] = -1;
	int maxj;
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		maxj = 0;
		for (int j = 1; j <= n; j++)
			if (a[j][i] > a[maxj][i]) maxj = j;
		ans += a[maxj][i];
	}
	printf("%d", ans);
	return 0;
}
