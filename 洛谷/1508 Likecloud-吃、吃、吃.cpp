#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int maxl = 10000000;
int n, m, a[maxn][maxn], f[maxn][maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			f[i][j] = -maxl;
	f[n + 1][m / 2 + 1] = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i + 1][j - 1], max(f[i + 1][j], f[i + 1][j + 1])) + a[i][j];
		}
	}
	int maxx = -maxl;
	for (int i = 1; i <= m; i++)
		maxx = max(maxx, f[1][i]);
	cout << maxx << endl;
	return 0;
}
