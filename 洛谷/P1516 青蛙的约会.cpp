#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

ll x, y, m, n, l, a, b, c, d, ans;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) return (void)(x = 1, y = 0);
	exgcd(b, a % b, x, y);
	ll tmp = y;
	y = x - (a / b) * y;
	x = tmp;
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(x), read(y), read(m), read(n), read(l);
	a = m - n, b = -l, c = y - x, d = gcd(a, b);
	// printf("%lld %lld %lld %lld\n", a, b, c, d);
	if (c % d) puts("Impossible");
	else {
		exgcd(a, b, x, y);
		ans = x * (c / d);
		l = abs(l / d);
		ans = (ans % l + l) % l;
		// printf("%lld %lld %lld %lld\n", x, y, ans, l);
		print(ans), putc('\n');
	}
}

} int main() { return ringo::main(), 0; }