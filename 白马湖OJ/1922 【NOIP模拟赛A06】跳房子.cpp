#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
long long n, m, k, a[maxn][maxn], f[maxn][maxn];
long long i, j, ii, jj;
int main()  {
//	freopen("hopscotch.in", "r", stdin);
//	freopen("hopscotch.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) 
			scanf("%d", &a[i][j]);
	
	f[1][1] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			for (ii = 1; ii < i; ii++)
				for (jj = 1; jj < j; jj++) {
//					if (ii == i && jj == j) continue;
					if (a[ii][jj] == a[i][j]) continue;
					f[i][j] = (f[i][j] + f[ii][jj]) % 1000000007;
				}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d ", f[i][j]);
//		puts("");
//	}
	printf("%d\n", f[n][m]);
	
	return 0;
}

