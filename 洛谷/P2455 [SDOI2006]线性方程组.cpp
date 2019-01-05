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

const int maxn = 55;
const double eps = 1e-6;

int n, x, c = 1;
double f[maxn][maxn];

bool zero(double x) { return fabs(x) < eps; }

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n);
	rep(i, 1, n) rep(j, 1, n + 1)
		f[i][j] = (read(x), x);
	for (int i = 1, max; i <= n; i++) {
		// printf(">>> %d : %d\n", i, c);
		// rep(i, 1, n) { rep(j, 1, n + 1) printf("%.2lf ", f[i][j]); putc('\n'); } putc('\n');
		max = c;
		for (int j = c + 1; j <= n; j++)
			if (fabs(f[j][i]) > fabs(f[max][i]))
				max = j;
		// printf("%d %.2lf\n", max, f[max][i]);
		if (zero(f[max][i])) continue;
		// printf("swap %d %d\n", max, c);
		rep(j, i, n + 1) std::swap(f[c][j], f[max][j]);
		// rep(i, 1, n) { rep(j, 1, n + 1) printf("%.2lf ", f[i][j]); putc('\n'); } putc('\n');
		for (int j = n + 1; j >= i; j--)
			f[c][j] /= f[c][i];
		for (int j = c + 1; j <= n; j++)
			for (int k = n + 1; k >= i; k--)
				f[j][k] -= f[j][i] * f[c][k];
		++c;
	}
	// rep(i, 1, n) { rep(j, 1, n + 1) printf("%.2lf ", f[i][j]); putc('\n'); } putc('\n');
	if (c == n + 1) {
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j < i; j++)
				f[j][n + 1] -= f[i][n + 1] * f[j][i];
		}
		for (int i = 1; i <= n; i++)
			printf("x%d=%.2lf\n", i, f[i][n + 1]);
	} else {
		for (int i = c; i <= n; i++)
			if (!zero(f[i][n + 1])) {
				puts("-1");
				return;
			}
		puts("0");
	}
}

} int main() { return ringo::main(), 0; }