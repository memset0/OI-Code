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

const int maxn = 4210;

int n, p, ans;
int f[2][maxn];

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(p);
	f[0][2] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 2; j <= i; j++)
			f[i & 1][j] = (f[i & 1][j - 1] + f[(i - 1) & 1][i - j + 1]) % p;
		// for (int j = 2; j <= i; j++)
		// 	print(f[i & 1][j]);
		// putc('\n');
	}
	for (int i = 2; i <= n; i++)
		ans = (ans + f[n & 1][i]) % p;
	print((ans << 1) % p, '\n');

	return 0;
}