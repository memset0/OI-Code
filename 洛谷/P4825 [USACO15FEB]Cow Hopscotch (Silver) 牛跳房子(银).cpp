// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

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

const int maxn = 760, mod = 1000000007;

int n, m, k;
int a[maxn][maxn], f[maxn][maxn];

int main() {
	
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	f[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int p = i + 1; p <= n; p++)
				for (int q = j + 1; q <= m; q++)
					if (a[i][j] ^ a[p][q]) {
						f[p][q] += f[i][j];
						if (f[p][q] > mod) {
							f[p][q] -= mod;
						}
					}
	print(f[n][m], endl);

	return 0;
}