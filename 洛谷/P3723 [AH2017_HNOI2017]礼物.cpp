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

const int N = 6e5 + 10, p = 998244353;
int n, m, k, lim, sum1a, sum1b, sum2a, sum2b;;
ll A, B, C, X, Y, ans = -1;
int a[N], b[N], f[N], g[N], rev[N];

int fpow(int a, int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

int inv(int x) {
	if (!x || x == 1) return 1;
	return (ll)(p - p / x) * inv(p % x) % p;
}

void upd(ll x) {
	Y = A * x * x + B * x + C;
	// printf("%lld => %lld\n", x, Y);
	if (Y < ans || ans == -1) ans = Y;
}

void ntt(int *a, int g) {
	for (int i = 0; i < lim; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < lim; len <<= 1) {
		int wn = fpow(g, (p - 1) / (len << 1));
		for (int i = 0; i < lim; i += (len << 1)) {
			int w = 1;
			for (int j = 0; j < len; j++, w = (ll)w * wn % p) {
				int x = a[i + j], y = (ll)w * a[i + j + len] % p;
				a[i + j] = (x + y) % p, a[i + j + len] = (x - y + p) % p;
			}
		}
	}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++) {
		sum1a += a[i], sum2a += a[i] * a[i];
		sum1b += b[i], sum2b += b[i] * b[i];
	}
	for (int i = 1; i <= (n << 1); i++) f[i - 1] = i > n ? a[i - n] : a[i];
	for (int i = 0; i < n; i++) g[i] = b[n - i];
	lim = 1; while (lim <= n * 3) lim <<= 1, ++k;
	for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	ntt(f, 3), ntt(g, 3);
	for (int i = 0; i < lim; i++) f[i] = (ll)f[i] * g[i] % p;
	ntt(f, inv(3));
	for (int i = 0, t = inv(lim); i < lim; i++) f[i] = (ll)f[i] * t % p;
	// for (int i = 0; i < lim; i++) print(f[i], " \n"[i == lim - 1]);
	// printf("%d %d %d %d\n", sum1a, sum1b, sum2a, sum2b);
	for (int i = 1; i <= n; i++) {
		A = n;
		B = (sum1a - sum1b) << 1;
		C = sum2a + sum2b - 2 * f[n + i - 2];
		X = -B / (A << 1);
		// printf(">>> %lld %lld %lld %lld : %d\n", A, B, C, X, f[n + i - 2]);
		upd(X), upd(X + 1), upd(X - 1);
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }