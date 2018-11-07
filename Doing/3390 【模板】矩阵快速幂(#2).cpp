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

const int maxn = 110, mod = 1e9 + 7;
int n; ll k;
struct matrix { int a[maxn][maxn]; } x, s;

il matrix operator * (const matrix &a, const matrix &b) {
	matrix c; memset(c.a, 0, sizeof(c.a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				c.a[i][j] = (c.a[i][j] + 1ll * a.a[i][k] * b.a[k][j]) % mod;
	return c;
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(k);
	// printf("%d %lld\n", n, k);
	rep(i, 1, n) rep(j, 1, n) read(x.a[i][j]);
	s = x; --k;
	while (k) {
		// printf(">> %lld\n", k);
		if (k & 1) s = s * x;
		x = x * x; k >>= 1;
	}
	rep(i, 1, n) { rep(j, 1, n) print(s.a[i][j]), putc(' '); putc('\n'); }
}

} int main() { return ringo::main(), 0; }