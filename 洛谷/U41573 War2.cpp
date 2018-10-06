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

const int maxn = 20;

int	n, m, k, u, v, cnt;
ll w, ans;
ll a[maxn], b[maxn][maxn], f[maxn][1 << 18];

int main() {
	
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= k; i++) {
		read(u), read(v), read(w);
		b[u][v] += w;
	}
	for (int i = 1; i <= n; i++)
		f[i][1 << (i - 1)] = a[i];
	for (int x = 0; x < (1 << n); x++) {
		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (x & (1 << (i - 1)))
				++cnt;
		if (cnt == m) {
			for (int i = 1; i <= n; i++)
				ans = std::max(ans, f[i][x]);
		} else if (cnt < m) {
			for (int i = 1; i <= n; i++)
				if (x & (1 << (i - 1)))
					for (int j = 1; j <= n; j++)
						if (!(x & (1 << (j - 1)))) {
							ll &to = f[j][x | (1 << (j - 1))];
							to = std::max(to, f[i][x] + a[j] + b[i][j]);
						}
		}
	}
//	for (int x = 0; x < (1 << n); x++) {
//		printf(">> %d (%d) : ", x, __builtin_popcount(x));
//		for (int i = 1; i <= n; i++)
//			printf("%d", x & (1 << (i - 1)) ? 1 : 0);
//		printf(" : ");
//		for (int i = 1; i <= n; i++)
//			printf("%lld ", f[i][x]);
//		puts("");
//	}
	print(ans, '\n');

	return 0;
}
