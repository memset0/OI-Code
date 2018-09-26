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

const ll p = 19940417;

int n, m;

ll solve(ll n) {
	printf("=== solve %lld ===\n", n);
	ll m, ans = 0;
	for (ll i = 2, x = n; x > 0; i++) {
		m = (x + i - 1) / i;
		ans += (n % x) % p * m % p;
		ans += m * (m - 1) / 2 % p * (i - 1) % p;
//		printf("> %lld %lld %lld %lld\n", i, n, m, ans);
//		printf("< %lld %lld\n", (n % x) % p * m % p, m * (m - 1) / 2 % p * (i - 1) % p);
		x -= m;
	}
//	printf(">>> %lld\n", ans);
	return ans;
}

int main() {
	freopen("INPUT", "r", stdin);
	read(n), read(m);
	print(solve(n) * solve(m) % p);
	return 0;
}

