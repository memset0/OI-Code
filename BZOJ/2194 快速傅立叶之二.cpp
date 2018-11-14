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

#define mul(a, b) a = 1ll * (a) * (b) % P

const int maxn = 4e5 + 10, P = 998244353, G = 3;
int n, m, k, tmp, a[maxn], b[maxn], rev[maxn];

int inv(int x) { return !x || x == 1 ? 1 : (ll)(P - P / x) * inv(P % x) % P; }
int pow(int x, int b) { int s = 1; while (b) { if (b & 1) mul(s, x); mul(x, x); b >>= 1; } return s; }

void ntt(int *a, int G) {
	for (int i = 0; i < m; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1, wn, w, i, j; len < m; len <<= 1) {
		wn = pow(G, (P - 1) / (len << 1));
		for (i = 0, w = 1; i < m; i += (len << 1), w = 1) {
			for (j = 0; j < len; j++, mul(w, wn)) {
				int x = a[i + j], y = (ll)w * a[i + j + len] % P;
				a[i + j] = (x + y) % P, a[i + j + len] = ((ll)x - y + P) % P;
			}
		}
	}
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), --n;
	rep(i, 0, n) read(a[n - i]), read(b[i]);
	m = 1; while (m <= (n << 1)) m <<= 1, ++k;
	rep(i, 0, m) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	ntt(a, G), ntt(b, G);
	rep(i, 0, m) mul(a[i], b[i]);
	ntt(a, inv(G)), tmp = inv(m);
	rep(i, 0, n) print((ll)tmp * a[n - i] % P), putc('\n');
}

} int main() { return ringo::main(), 0; }