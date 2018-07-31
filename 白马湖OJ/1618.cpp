#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
long long f[maxn][maxn];
int n, a[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, -1, sizeof(f));
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i <= n; i++)
		{
			int j = i + len - 1;
			if (j > n) break;
			if (len == 2)
			{
				f[i][j] = 0;
				continue;
			}
			for (int k = i+1; k <= j-1; k++)
			{
				if (f[i][j] == -1)
					f[i][j] = f[i][k] + f[k][j] + a[i] * a[j] * a[k];
				else if (f[i][j] > f[i][k] + f[k][j] + a[i] * a[j] * a[k])
					f[i][j] = f[i][k] + f[k][j] + a[i] * a[j] * a[k];
			}
		}
	}
	printf("%d", f[1][n]);
	return 0;
}
