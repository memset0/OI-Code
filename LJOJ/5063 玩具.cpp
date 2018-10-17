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
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 210;
int n, p;
ll ans, inv[maxn];
ll f[maxn][maxn], g[maxn][maxn], dp[maxn][maxn];

ll solveF(int, int);
ll solveG(int, int);

ll solveF(int i, int j) {
	if (~f[i][j]) return f[i][j];
	// printf(">>> solveF %d %d\n", i, j);
	ll now = 0;
	now += solveG(i - 1, j - 1);
	// printf("<<< solveF %d %d %lld\n", i, j, now);
	return f[i][j] = now;
}

ll solveG(int i, int j) {
	if (j < 0) return 0;
	if (i == 0) return 1;
	if (~g[i][j]) return g[i][j];
	// printf(">>> solveG %d %d\n", i, j);
	ll now = 0;
	for (int k = 1; k <= i; k++)
		now = (now + solveF(k, j) * solveG(i - k, j) % p * dp[i][k]) % p;
	// printf("<<< solveG %d %d %lld\n", i, j, now);
	return g[i][j] = now;
}

int main() {
	// freopen("1.in", "r", stdin);
	memset(f, -1, sizeof(f));
	memset(g, -1, sizeof(g));
	read(n), read(p);
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i - 1][j - 1] * (j - 1) % p * inv[i] +
				dp[i - 1][j] * (i - j) % p * inv[i]) % p;
	f[1][1] = g[1][1] = 1;
	for (int i = 1; i <= n; i++)
		solveF(n, i);
	for (int i = 1; i <= n; i++)
		ans = (ans + (f[n][i] - f[n][i - 1] + p) % p * (i - 1)) % p;
	print(ans, '\n');
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		print(f[i][j]);
	// 	putc('\n');
	// }
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		print(g[i][j]);
	// 	putc('\n');
	// }
	return 0;
}