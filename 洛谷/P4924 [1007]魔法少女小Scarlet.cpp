// luogu-judger-enable-o2
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

const int maxn = 510;

int n, m, x, y, r, d, p;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

int main() {

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = (i - 1) * n + j;
	for (int k = 1; k <= m; k++) {
		read(x), read(y), read(r), read(d);
		p = r << 1 | 1;
		if (d == 0) {
			for (int i = 1; i <= p; i++)
				for (int j = 1; j <= p; j++)
					c[j][p - i + 1] = a[x - r + i - 1][y - r + j - 1];
		} else {
			for (int i = 1; i <= p; i++)
				for (int j = 1; j <= p; j++)
					c[p - j + 1][i] = a[x - r + i - 1][y - r + j - 1];
		}
		for (int i = 1; i <= p; i++)
			for (int j = 1; j <= p; j++)
				a[x - r + i - 1][y - r + j - 1] = c[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			print(a[i][j]);
		putc('\n');
	}

	return 0;
}
