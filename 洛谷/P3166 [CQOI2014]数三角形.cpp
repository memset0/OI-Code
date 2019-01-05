// luogu-judger-enable-o2
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int maxn = 1010;
int n, m;
ll ans;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

void main() {
	read(n), read(m), ++n, ++m;
	ans = (ll)n * m * (n * m - 1) * (n * m - 2) / 6;
	if (n >= 3) ans -= (ll)m * n * (n - 1) * (n - 2) / 6;
	if (m >= 3) ans -= (ll)n * m * (m - 1) * (m - 2) / 6;
	// printf("%lld\n", ans);
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <= m; j++) {
			ans -= (ll)(n - i) * (m - j) * (gcd(i, j) - 1) * 2;
			// printf("%d %d : %lld\n", i, j, (ll)(n - i) * (m - j) * (gcd(i, j) - 1) * 2);
		}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }