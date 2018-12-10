// =================================
//   author: memset0
//   date: 2018.12.10 14:00:33
//   website: https://memset0.cn/
// =================================
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

#define pb push_back

const int N = 8e5 + 10, p = 998244353;
int T, n;
int a[N], f[N], g[N], rev[N];

typedef std::vector < int > vector;
vector ans;

inline int fpow(int a, int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll) s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

int inv(int x) {
	if (!x || x == 1) return 1;
	return (ll)(p - p / x) * inv(p % x) % p;
}

inline void ntt(int *a, int g, int lim) {
	for (int i = 0; i < lim; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < lim; len <<= 1)
		for (int i = 0, wn = fpow(g, (p - 1) / (len << 1)); i < lim; i += (len << 1))
			for (int j = 0, w = 1; j < len; j++, w = (ll)w * wn % p) {
				int x = a[i + j], y = (ll)w * a[i + j + len] % p;
				a[i + j] = (x + y) % p, a[i + j + len] = (x - y + p) % p;
			}
}

inline void operator *= (vector &a, const vector &b) {
	int n = a.size(), m = b.size(), lim = 1, k = 0;
	while (lim <= (n + m)) lim <<= 1, ++k;
	for (int i = 0; i < n; i++) f[i] = a[i];
	for (int i = 0; i < m; i++) g[i] = b[i];
	for (int i = n; i < lim; i++) f[i] = 0;
	for (int i = m; i < lim; i++) g[i] = 0;
	for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	ntt(f, 3, lim), ntt(g, 3, lim);
	for (int i = 0; i < lim; i++) f[i] = (ll)f[i] * g[i] % p;
	ntt(f, inv(3), lim), lim = inv(lim);
	for (int i = 0; i < n; i++) a[i] = (ll)f[i] * lim % p;
	for (int i = n; i < n + m - 1; i++) a.pb((ll)f[i] * lim % p);
}

vector solve(int l, int r) {
	if (l == r) {
		vector s;
		if (a[l] == 1) s.pb(0), s.pb(0), s.pb(1);
		else if (a[l] > 1) s.pb(a[l] - 2), s.pb(2);
		return s;
	}
	int mid = (l + r) >> 1;
	vector left = solve(l, mid);
	vector right = solve(mid + 1, r);
	left *= right;
	return left;
}

void main() {
	for (read(T); T--; ) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		vector ans = solve(1, n);
		for (size_t i = 0; i < ans.size(); i++) print(ans[i], ' ');
		for (int i = (int)ans.size(); i <= (n << 1); i++) putchar('0'), putchar(' ');
		putchar('\n');
	}
}

} signed main() { return ringo::main(), 0; }
