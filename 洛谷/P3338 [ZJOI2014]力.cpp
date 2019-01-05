// luogu-judger-enable-o2
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

const int maxn = 4e5 + 10;
const double pi = acos(-1);
int n, m, k, rev[maxn];
double g[maxn], ans[maxn];

struct complex {
	double x, y;
	il complex(double a = 0, double b = 0) { x = a, y = b; }
	il complex operator + (const complex &b) { return complex(x + b.x, y + b.y); }
	il complex operator - (const complex &b) { return complex(x - b.x, y - b.y); }
	il complex operator * (const complex &b) { return complex(x * b.x - y * b.y, x * b.y + y * b.x); }
} a[maxn], b[maxn], c[maxn];

void fft(complex *a, int flag) {
	for (int i = 0; i < m; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < m; len <<= 1) {
		complex wn(cos(pi / len), flag * sin(pi / len));
		for (int i = 0; i < m; i += (len << 1)) {
			complex w(1, 0);
			for (int j = 0; j < len; j++, w = w * wn) {
				complex x = a[i + j], y = w * a[i + j + len];
				a[i + j] = x + y, a[i + j + len] = x - y;
			}
		}
	}
}

void solve(complex *a, complex *b, complex *c) {
	// puts("==== solve =====");
	// for (int i = 0; i < m; i++) printf("%.2lf ", a[i].x); puts("");
	// for (int i = 0; i < m; i++) printf("%.2lf ", b[i].x); puts("");
	fft(a, 1), fft(b, 1);
	for (int i = 0; i < m; i++) c[i] = a[i] * b[i];
	// for (int i = 0; i < m; i++) printf("%.2lf ", c[i].x); puts("");
	fft(c, -1);
	for (int i = 0; i < m; i++) c[i].x = c[i].x / m;
	// for (int i = 0; i < m; i++) printf("%.2lf ", a[i].x); puts("");
	// for (int i = 0; i < m; i++) printf("%.2lf ", b[i].x); puts("");
	// for (int i = 0; i < m; i++) printf("%.2lf ", c[i].x); puts("");
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) scanf("%lf", &g[i]);
	m = 1; while (m <= (n << 1)) m <<= 1, ++k;
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	for (int i = 0; i < n; i++) a[i] = g[i + 1];
	for (int i = 0; i < n; i++) b[i] = (double)1 / (i + 1) / (i + 1);
	solve(a, b, c);
	for (int i = 2; i <= n; i++) ans[i] += c[i - 2].x;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) a[i] = g[n - i];
	for (int i = 0; i < n; i++) b[i] = (double)1 / (i + 1) / (i + 1);
	solve(a, b, c);
	for (int i = 1; i < n; i++) ans[i] -= c[n - i - 1].x;
	for (int i = 1; i <= n; i++) printf("%.3lf\n", ans[i]);
}

} int main() { return ringo::main(), 0; }