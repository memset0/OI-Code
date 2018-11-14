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

const int maxn = 4e6 + 10, P = 998244353, G = 3;
int n, k, n1, n2, tmp, rev[maxn];
ll a[maxn], b[maxn];

int inv(int x) {
	if (x == 0 || x == 1) return 1;
	return 1ll * (P - P / x) * inv(P % x) % P;
}

int pow(ll x, int b) {
	ll s = 1;
	while (b) {
		if (b & 1) (s *= x) %= P;
		(x *= x) %= P, b >>= 1;
	}
	return s;
}

void fft(ll *a, int G) {
	for (int i = 0; i < n; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < n; len <<= 1) {
		ll wn = pow(G, (P - 1) / (len << 1));
		for (int i = 0; i < n; i += (len << 1)) {
			ll w = 1;
			for (int j = 0; j < len; j++, w = w * wn % P) {
				ll x = a[i + j], y = w * a[i + j + len] % P;
				a[i + j] = (x + y) % P, a[i + j + len] = (x - y + P) % P;
			}
		}
	}
}

void main() {
	read(n1), read(n2);
	for (int i = 0; i <= n1; i++) read(a[i]), a[i] %= P;
	for (int i = 0; i <= n2; i++) read(b[i]), b[i] %= P;
	n = 1; while (n <= (n1 + n2)) n <<= 1, ++k;
	for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	fft(a, G), fft(b, G);
	for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % P;
	fft(a, inv(G)), tmp = inv(n);
	for (int i = 0; i <= n1 + n2; i++) print(a[i] * tmp % P), putc(i == n1 + n2 ? '\n' : ' ');
}

} int main() { return ringo::main(), 0; }