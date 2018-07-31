#include <bits/stdc++.h> 
using namespace std;
int x, y, z, n, m, f[151][151];
int main() {
	scanf("%d%d%d%d%d", &x, &y, &z, &n, &m);
	m++;
	for (int i = 0; i <= m; i++)
		f[i][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j - 1; k++) {
//				printf("%d %d %d => %d\n", i, j, k, f[i - 1][k] * f[i - 1][j - 1 - k]);
				f[i][j] = (f[i][j] + f[i - 1][k] * f[i - 1][j - 1 - k]) % 2016;
			}
		}
	}
//	for (int i = 0; i <= m; i++) {
//		for (int j = 0; j <= n; j++) {
//			printf("%d ", f[i][j]);
//		}
//		puts("");
//	}
	printf("%d\n", (f[m][n] - f[m - 1][n] + 2016) % 2016);
	return 0;
}
