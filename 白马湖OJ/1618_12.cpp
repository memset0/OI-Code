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
	memset(f, 63, sizeof(f));
	for (int i = 1; i < n; i++)
		f[i][i+1] = 0;
	for (int len = 2; len <= n; len++)
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			for (int k = i+1; k <= j-1; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
		}
	printf("%d", f[1][n]);
	return 0;
}
