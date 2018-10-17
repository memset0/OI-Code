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

const int maxn = 55, maxm = 1010;
int n, s, m;
int a[maxn], f[maxn][maxm];

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(s), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	f[0][s] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (j >= a[i])
				f[i][j] |= f[i - 1][j - a[i]];
			if (j + a[i] <= m)
				f[i][j] |= f[i - 1][j + a[i]];
		}
	for (int i = m; i >= 0; i--)
		if (f[n][i]) {
			print(i, '\n');
			return 0;
		}
	puts("-1");
	return 0;
}