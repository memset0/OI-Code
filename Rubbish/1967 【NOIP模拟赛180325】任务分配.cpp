#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n, a[maxn], b[maxn];
int f[maxn][maxn * maxn];
int main() {
	memset(f, 63, sizeof(f));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= 40000; j++)
			f[i][j] = f[i - 1][j - a[i]];
		for (int j = 0; j <= 40000; j++)
			f[i][j] = min(f[i][j], f[i - 1][j] + b[i]);
	}
	int ans = 1000000;
	for (int i = 0; i <= 40000; i++)
		ans = min(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}
