#include <bits/stdc++.h>
using namespace std;
const int maxn = 2510;
int n, m, a[maxn][maxn];
short ans;
short lft[maxn][maxn], upt[maxn][maxn], f[maxn][maxn];
short rit[maxn][maxn], dwn[maxn][maxn], g[maxn][maxn];

int ret, mrk; char chr;
inline int read() {
	chr = getchar(), mrk = 1, ret = 0;
	while (!('0' <= chr && chr <= '9') && chr != '-') chr = getchar();
	if (chr == '-') chr = getchar(), mrk = -1;
	while ('0' <= chr && chr <= '9') ret = ret * 10 + chr - '0', chr = getchar();
	return ret * mrk;
}
inline int Min(int a, int b, int c) {
	return min(a, min(b, c));
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j - 1]) lft[i][j] = 1;
			else lft[i][j] = lft[i][j - 1] + 1;
			if (a[i - 1][j]) upt[i][j] = 1;
			else upt[i][j] = upt[i - 1][j] + 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			if (a[i][j + 1]) rit[i][j] = 1;
			else rit[i][j] = rit[i][j + 1] + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) f[i][j] = Min(f[i - 1][j - 1] + 1, upt[i][j], lft[i][j]);
			ans = max(ans, f[i][j]);
		}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--) {
			if (a[i][j]) g[i][j] = Min(g[i - 1][j + 1] + 1, upt[i][j], rit[i][j]);
			ans = max(ans, g[i][j]);
		}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d ", g[i][j]);
//		puts("");
//	}
	printf("%d\n", ans);
	return 0;
}
