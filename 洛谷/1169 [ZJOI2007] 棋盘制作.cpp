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

const int maxn = 2010;
int n, m, ans1, ans2;
int a[maxn][maxn], p1[maxn][maxn], p2[maxn][maxn], f1[maxn][maxn], f2[maxn][maxn];

void print(int a[maxn][maxn]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%3d", a[i][j]);
		putc('\n');
	}
}

int main() {
	freopen("INPUT", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
		p1[i][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			p1
	return 0;
}	

