#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, a[maxn][maxn], f[maxn][maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j]) {
				if (i == 0 || j == 0) f[i][j] = 1;
				else f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
			} else {
				f[i][j] = 0;
			}
	int maxx = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			maxx = max(maxx, f[i][j]);
	cout << maxx << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%3d", f[i][j]);
//		puts("");
//	}
	return 0;
}
