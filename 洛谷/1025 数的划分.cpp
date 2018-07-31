#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int maxm = 10;
int n, m, f[maxn][maxn][maxm], s[maxn][maxn][maxm];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		f[i][i][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i][j][1] = s[i][j - 1][1] + f[i][j][1];
	for (int k = 2; k <= m; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
//				for (int t = 1; t <= j; t++) {
////					printf(">>> /%d %d %d %d\n", k, i, j, t);
//					f[i][j][k] += f[i - j][t][k - 1];
//				}
				f[i][j][k] = s[i - j][j][k - 1];
//				s[i][j][k] = s[i][j - 1][k] + f[i][j][k];
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				s[i][j][k] = s[i][j - 1][k] + f[i][j][k];
	}
//	for (int k = 1; k <= m; k++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= i; j++)
//				printf("%d ", s[i][j][k]);
//			printf("\n");
//		}
//		printf("\n\n");
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans += f[n][i][m];	
////		printf("%d ", f[n][i][m]);
//	}
//	printf("%d\n", ans);
	printf("%d\n", s[n][n][m]);
	return 0;
}
	
