#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, a[maxn][maxn], f[maxn][maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			f[i][j] = a[i][j] + max(f[i - 1][j], f[i - 1][j - 1]);
	}
	int ans = -1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}
