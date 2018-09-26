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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 40, maxm = 2510;

#define at(i,j) (((i) - 1) * (m) + (j))

int n, m, p, 

int main() {
	
	read(p), read(m), read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i + 1][j] ^ 1) {
				if (i ^ n && a[i + 1][j] ^ 1) add_edge(at(i, j) + n * m, at(i + 1, j), inf, 0);
				if (j ^ n && a[i][j + 1] ^ 1) add_edge(at(i, j) + n * m, at(i, j + 1), inf, 0);
				if (a[i][j] == 2) add_edge(at(i, j), at(i, j) + n * m, 1, 1);
			}
	s = ((n * m) << 1) + 1, e = s + 1;
	add_edge(s, 1, p, 0);
	add_edge((n * m) << 1, e, inf, 0);
	
	while 

	return 0;
}

