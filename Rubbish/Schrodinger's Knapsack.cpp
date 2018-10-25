#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int read(void);
int t, i, j, k1, k2, n, m, c;
long long a[maxn], b[maxn], sa[maxn], sb[maxn], f[maxn][maxn];
long long max(long long a, long long b) {
	if (a > b) return a;
	else return b;
}
int main() {
	t = read();
	while (t--) {
		k1 = read(), k2 = read(), c = read();
		n = read(), m = read();
		for (i = 1; i <= n; i++) a[i] = read();
		for (j = 1; j <= m; j++) b[j] = read();
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		sa[0] = sb[0] = f[0][0] = 0;
		for (i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
		for (j = 1; j <= m; j++) sb[j] = sb[j - 1] + b[j];
		for (i = 1; i <= n; i++) f[i][0] = f[i - 1][0] + k1 * max(0, c - sa[i]);
		for (j = 1; j <= m; j++) f[0][j] = f[0][j - 1] + k2 * max(0, c - sb[j]);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				f[i][j] = max( f[i - 1][j] + k1 * max(0, (c - sa[i] - sb[j])), f[i][j - 1] + k2 * max(0, c - sa[i] - sb[j]));
//		puts("");
//		for (i = 0; i <= n; i++) {
//			for (j = 0; j <= m; j++)
//				printf("%5d", f[i][j]);
//			puts("");
//		}
//		puts("");
		printf("%lld\n", f[n][m]);
	}
	return 0;
}

int ret; char chr; bool mrk;
int read(void) {
	ret = 0, chr = getchar(), mrk = false;
	while (!isdigit(chr) && chr != '-') chr = getchar();
	if (chr == '-') mrk = true, chr = getchar();
	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	if (mrk) ret = -ret;
	return ret;
}
