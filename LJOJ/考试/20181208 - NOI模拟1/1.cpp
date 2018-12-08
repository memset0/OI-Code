// =================================
//   author: memset0
//   date: 2018.12.08 08:53:28
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;
#define int long long

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

const int N = 1e5 + 10;
int n, m, u, v, op, min, max;
int a[N], b[N], c[N], d[N], e[N];

void cut(int u, int v) {
	int dt_e = b[v] / (d[v] - 1) - e[v];
	c[v] += (1 - d[v]) * dt_e;
	--d[v];
	e[v] += dt_e, c[a[v]] += dt_e;
	c[v] -= e[u], c[v] += e[v];
}

void link(int u, int v) {
	int dt_e = b[v] / (d[v] + 1) - e[v];
	c[v] += (1 - d[v]) * dt_e;
	++d[v];
	e[v] += dt_e, c[a[v]] += dt_e;
	c[v] -= e[v], c[v] += e[u];
}

// void output() {
// 	puts("=============================");
// 	printf("a : "); for (int i = 1; i <= n; i++) printf("%5d", a[i]); puts("");
// 	printf("b : "); for (int i = 1; i <= n; i++) printf("%5d", b[i]); puts("");
// 	printf("c : "); for (int i = 1; i <= n; i++) printf("%5d", c[i]); puts("");
// 	printf("d : "); for (int i = 1; i <= n; i++) printf("%5d", d[i]); puts("");
// 	printf("e : "); for (int i = 1; i <= n; i++) printf("%5d", e[i]); puts("");
// 	printf("f : "); for (int i = 1; i <= n; i++) printf("%5d", e[a[i]]); puts("");
// 	printf("==> "); for (int i = 1; i <= n; i++) printf("%5d", c[i] + e[a[i]]); puts("");
// 	puts("=============================");
// }

void main() {
	read(n), read(m);
	if (n > 30000) return;
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++) read(a[i]);

	for (int i = 1; i <= n; i++) ++d[a[i]];
	for (int i = 1; i <= n; i++) d[i] += 2;
	for (int i = 1; i <= n; i++) e[i] = b[i] / d[i];
	for (int i = 1; i <= n; i++) c[i] = b[i] - d[i] * e[i] + e[i];
	for (int i = 1; i <= n; i++) c[a[i]] += e[i];

	for (int i = 1; i <= m; i++) {
		read(op);
		if (op == 1) {
			read(u), read(v);
			cut(u, a[u]);
			a[u] = v;
			link(u, a[u]);
		} else if (op == 2) {
			read(u);
			print(c[u] + e[a[u]], '\n');
		} else {
			min = 1e18, max = -1e18;
			for (int i = 1; i <= n; i++) {
				min = std::min(min, c[i] + e[a[i]]);
				max = std::max(max, c[i] + e[a[i]]);
			}
			print(min, ' '), print(max, '\n');
		}
	}
}

} signed main() { return ringo::main(), 0; }