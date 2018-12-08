// =================================
//   author: memset0
//   date: 2018.12.08 08:53:28
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

const int N = 1e5 + 10;
int n, m, u, v, op, min, max;
int a[N], b[N], c[N], d[N], e[N];
std::vector < int > p[N];

void erase(std::vector < int > &p, int u) {
	for (size_t i = 0; i < p.size(); i++)
		if (p[i] == u) {
			p.erase((std::vector < int > ::iterator)&p[i]);
			return;
		}
}

void cut(int u, int v) {
	int dt_e = b[v] / (d[v] - 1) - e[v];
	c[v] += (1 - d[v]) * dt_e;
	// printf("cut %d %d : %d\n", u, v, dt_e);
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

void output() {
	puts("=============================");
	printf("a : "); for (int i = 1; i <= n; i++) printf("%5d", a[i]); puts("");
	printf("b : "); for (int i = 1; i <= n; i++) printf("%5d", b[i]); puts("");
	printf("c : "); for (int i = 1; i <= n; i++) printf("%5d", c[i]); puts("");
	printf("d : "); for (int i = 1; i <= n; i++) printf("%5d", d[i]); puts("");
	printf("e : "); for (int i = 1; i <= n; i++) printf("%5d", e[i]); puts("");
	printf("f : "); for (int i = 1; i <= n; i++) printf("%5d", e[a[i]]); puts("");
	printf("==> "); for (int i = 1; i <= n; i++) printf("%5d", c[i] + e[a[i]]); puts("");
	puts("=============================");
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) p[a[i]].push_back(i);
	for (int i = 1; i <= n; i++) d[i] = p[i].size() + 2;
	for (int i = 1; i <= n; i++) e[i] = b[i] / d[i];
	for (int i = 1; i <= n; i++) {
		c[i] = b[i] - d[i] * e[i] + e[i];
		for (size_t j = 0; j < p[i].size(); j++) c[i] += e[p[i][j]];
	}
	for (int i = 1; i <= m; i++) {
		read(op);
		if (op == 1) {
			read(u), read(v);
			// output();
			// erase(p[a[u]], u), p[v].push_back(u);
			cut(u, a[u]);
			a[u] = v;
			link(u, a[u]);
			// output();
			// for (int i = 1; i <= n; i++) e[i] = b[i] / d[i];
			// for (int i = 1; i <= n; i++) {
			// 	c[i] = b[i] - d[i] * e[i] + e[i];
			// 	for (size_t j = 0; j < p[i].size(); j++) c[i] += e[p[i][j]];
			// }
			// output();
		} else if (op == 2) {
			read(u);
			print(c[u] + e[a[u]], '\n');
		} else {
			int min = 1e9, max = -1e9;
			for (int i = 1; i <= n; i++) {
				min = std::min(min, c[i] + e[a[i]]);
				max = std::max(max, c[i] + e[a[i]]);
			}
			print(min, ' '), print(max, '\n');
		}
	}
}

} signed main() { return ringo::main(), 0; }