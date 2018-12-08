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

std::priority_queue < int, std::vector < int >, std::greater < int > > h1, h1p;
std::priority_queue < int > h2, h2p;

template < class T >
inline void push(T &a, T &b, int x) {
	a.push(x);
	while (b.size())
		if (a.top() == b.top()) a.pop(), b.pop();
		else break;
}

template < class T >
inline void pop(T &a, T &b, int x) {
	b.push(x);
	while (b.size())
		if (a.top() == b.top()) a.pop(), b.pop();
		else break;
}

template < class T >
inline int top(T &a, T &b) {
	while (b.size())
		if (a.top() == b.top()) a.pop(), b.pop();
		else break;
	return a.top();
}

inline void insert(int x) {
	push(h1, h1p, x), push(h2, h2p, x);
}

inline void erase(int x) {
	pop(h1, h1p, x), pop(h2, h2p, x);
}

void cut(int u, int v) {
	int dt_e = b[v] / (d[v] - 1) - e[v];
	--d[v], e[v] += dt_e;
	c[v] += (1 - d[v]) * dt_e - e[u];
}

void link(int u, int v) {
	int dt_e = b[v] / (d[v] + 1) - e[v];
	++d[v], e[v] += dt_e;
	c[v] += (1 - d[v]) * dt_e + e[u];
}

void output() {
	auto name = {"a", "b", "c", "d", "e"};
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
			c[u] -= e[a[u]], cut(u, a[u]);
			link(u, v), c[u] += e[v];
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