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

const int maxn = 2000010;
const int mod = 20100403;

int n, m;
int fac[maxn], inv[maxn];

int C(int m, int n) {
	return 1ll * fac[m] * inv[m - n] % mod * inv[n] % mod;
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m);
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= n + m; i++)
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 1; i <= n + m; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 1; i <= n + m; i++)
		inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	print((C(n + m, n) - C(n + m, m - 1) + mod) % mod, '\n');

	return 0;
}