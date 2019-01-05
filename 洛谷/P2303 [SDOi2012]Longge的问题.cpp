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

ll n, ans;

ll phi(ll x) {
//	printf("phi %lld\n", x);
	ll ans = x;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ans = ans / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	if (x ^ 1) ans = ans / x * (x - 1);
//	printf("= %lld\n", ans);
	return ans;
}

int main() {
	
	read(n);
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0) {
			if (i * i == n) ans += phi(i) * i;
			else ans += phi(i) * (n / i) + phi(n / i) * i;
		}
	print(ans, endl);

	return 0;
}