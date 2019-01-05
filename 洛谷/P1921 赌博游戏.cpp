// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 55, maxm = 1010;

int n, m, q;
double a[maxn][maxn], b[maxn][maxn];
double f[maxm][maxn], g[maxm][maxn];
int p[maxm];
double ans, now;

int main() {
//	freopen("INPUT", "r", stdin);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &g[1][i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= q; j++)
			scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%lf", &b[i][j]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &p[i]);
		++p[i];
	}
	
	ans = 1;
	for (int i = 1; i <= m; i++) {
		now = 0;
		for (int j = 1; j <= n; j++)
			now += g[i][j] * a[j][p[i]];
//		for (int j = 1; j <= n; j++)
//			printf("%.4lf ", g[i][j]);
//		puts("");
//		for (int j = 1; j <= n; j++)
//			printf("%.4lf ", g[i][j] * a[j][p[i]]);
		ans *= now;
//		printf("[%.8lf %.8lf]\n", now, ans);
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				g[i + 1][k] += g[i][j] * b[j][k] * a[j][p[i]] / now;
	}
	printf("%.4lf\n", ans);

	return 0;
}