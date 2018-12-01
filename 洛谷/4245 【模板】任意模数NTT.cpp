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

const int N = 4e5 + 10, G = 3, P[3] = {469762049, 998244353, 1004535809};
int n1, n2, k, n, p, p1, p2, M2;
int a[N], b[N], f[3][N], g[N], rev[N], ans[N];

int inv(int x, int p) {
	if (x >= p) return inv(x % p, p);
	return !x || x == 1 ? 1 : (ll)(p - p / x) * inv(p % x, p) % p;
}

int pow(int a, int b, int p) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

void ntt(int *a, int g, int p) {
	for (int i = 0; i < n; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < n; len <<= 1) {
		int wn = pow(g, (p - 1) / (len << 1), p);
		for (int i = 0; i < n; i += (len << 1)) {
			int w = 1;
			for (int j = 0; j < len; j++, w = (ll)w * wn % p) {
				int x = a[i + j], y = (ll)w * a[i + j + len] % p;
				a[i + j] = (x + y) % p, a[i + j + len] = (x - y + p) % p;
			}
		}
	}
}

int merge(int a1, int a2, int A2) {
	// printf("--- merge %d %d %d -----\n", a1, a2, A2);
	// printf("ans ≡ %d(mod %d)\n", a1, p1);
	// printf("ans ≡ %d(mod %d)\n", a2, p2);
	ll M1 = (ll)p1 * p2;
	ll A1 = ((ll)inv(p2, p1) * a1 % p1 * p2 + (ll)inv(p1, p2) * a2 % p2 * p1) % M1;
	// printf("ans ≡ %lld(mod %lld)\n", A1, M1);
	// printf("ans ≡ %d(mod %d)\n", A2, M2);
	ll K = ((A2 - A1) % M2 + M2) % M2 * inv(M1 % M2, M2) % M2;
	int ans = (A1 + M1 % p * K) % p;
	// printf("> %lld %d\n", K, ans);
	return ans;
}

void main() {
	read(n1), read(n2), read(p);
	p1 = P[0], p2 = P[1], M2 = P[2];
	for (int i = 0; i <= n1; i++) read(a[i]);
	for (int i = 0; i <= n2; i++) read(b[i]);
	n = 1; while (n <= (n1 + n2)) n <<= 1, ++k;
	for (int i = 0; i < n; i++ ) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	for (int k = 0; k < 3; k++) {
		// puts("===============");
		for (int i = 0; i < n; i++) f[k][i] = a[i] % P[k];
		for (int i = 0; i < n; i++) g[i] = b[i] % P[k];
		// for (int i = 0; i < n; i++) print(f[k][i], " \n"[i == n - 1]);
		// for (int i = 0; i < n; i++) print(g[i], " \n"[i == n - 1]);
		ntt(f[k], G, P[k]), ntt(g, G, P[k]);
		for (int i = 0; i < n; i++) f[k][i] = (ll)f[k][i] * g[i] % P[k];
		ntt(f[k], inv(G, P[k]), P[k]);
		for (int i = 0; i < n; i++) f[k][i] = (ll)f[k][i] * inv(n, P[k]) % P[k];
		// for (int i = 0; i < n; i++) print(f[k][i], " \n"[i == n - 1]);
	}
	for (int i = 0; i <= n1 + n2; i++) ans[i] = merge(f[0][i], f[1][i], f[2][i]);
	for (int i = 0; i <= n1 + n2; i++) print(ans[i], " \n"[i == n1 + n2]);	
}

} signed main() { return ringo::main(), 0; }
