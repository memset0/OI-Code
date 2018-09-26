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

ll n, m;

void update(ll &x) {
	x = (x % p + p) % p;
}

ll sum(ll n) {
	ll a = n, b = n - 1;
	if (a % 2 == 0) a /= 2;
	else b /= 2;
	a %= p, b %= p;
	return a * b % p;
}

ll sum(ll l, ll r) {
	ll a = l + r, b = r - l + 1;
	if (a % 2 == 0) a /= 2;
	else b /= 2;
	a %= p, b %= p;
	return a * b % p;
}

ll sum2(ll n) {
	ll a = n, b = n + 1, c = (n << 1) + 1;
	if (a % 2 == 0) a /= 2;
	else if (b % 2 == 0) b /= 2;
	else c /= 2;
	if (a % 3 == 0) a /= 3;
	else if (b % 3 == 0) b /= 3;
	else c /= 3;
	a %= p, b %= p, c %= p;
	return a * b % p * c % p;
}

ll solve(ll n) {
//	printf("=== solve %lld ===\n", n);
	ll m, ans = 0, sqn = sqrt(n), x, i, t;
	for (i = 2, x = n; x > sqn; i++) {
		t = m = (n - (n / i)) - (n - x);
		m %= p;
		ans += (n % x) % p * (m % p) % p, update(ans);
		ans += sum(m) % p * ((i - 1) % p) % p, update(ans);
//		printf("> %lld %lld %lld %lld\n", i, x, m, ans);
//		printf("< %lld %lld\n", (n % x) % p * m % p, m * (m - 1) / 2 % p * (i - 1) % p);
		x -= t;
	}
	for (i = 1; i <= x; i++)
		ans += (n % i) % p, update(ans);
//	printf(">>> %lld\n", ans);
	return ans;
}

ll solve2(ll n, ll m) {
	if (n > m) std::swap(n, m);
	ll ans = n * n % p * m % p;
//	printf("%lld\n", ans);
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = std::min(n / (n / l), m / (m / l));
		ans -= n % p * (m / l % p) % p * sum(l, r) % p, update(ans);
		ans -= m % p * (n / l % p) % p * sum(l, r) % p, update(ans);
		ans += (n / l % p) * (m / l % p) % p * ((sum2(r) - sum2(l - 1) + p) % p) % p, update(ans);
//		printf("%lld %lld\n", ans);
	}
	return ans;
}

int main() {
//	freopen("3.txt", "r", stdin);
	read(n), read(m);
	print((solve(n) * solve(m) % p - solve2(n, m) + p) % p);
	return 0;
}
