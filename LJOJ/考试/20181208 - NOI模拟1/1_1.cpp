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
int a[N], b[N], c[N], e[N];
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
inline void erase(T &a, T &b, int x) {
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

void erase(std::vector < int > &p, int u) {
	for (size_t i = 0; i < p.size(); i++)
		if (p[i] == u) {
			p.erase((std::vector < int > ::iterator)&p[i]);
			return;
		}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) p[a[i]].push_back(i);
	for (int i = 1; i <= n; i++) e[i] = b[i] / (p[i].size() + 2);
	for (int i = 1; i <= n; i++) {
		c[i] = b[i] - (p[i].size() + 2) * e[i] + e[i] + e[a[i]];
		for (size_t j = 0; j < p[i].size(); j++) c[i] += e[p[i][j]];
		// push(h1, h1p, c[i]), push(h2, h2p, c[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(op);
		if (op == 1) {
			read(u), read(v);
			erase(p[a[u]], u);
			a[u] = v, p[v].push_back(u);
			// for (int i = 1; i <= n; i++)
			// 	erase(h1, h1p, c[i]), erase(h2, h2p, c[i]);
			for (int i = 1; i <= n; i++) e[i] = b[i] / (p[i].size() + 2);
			for (int i = 1; i <= n; i++) {
				c[i] = b[i] - (p[i].size() + 2) * e[i] + e[i] + e[a[i]];
				for (size_t j = 0; j < p[i].size(); j++) c[i] += e[p[i][j]];
				// push(h1, h1p, c[i]), push(h2, h2p, c[i]);
			}
		} else if (op == 2) {
			read(u);
			print(c[u], '\n');
		} else {
			min = 1e9, max = -1e9;
			for (int i = 1; i <= n; i++) {
				min = std::min(min, c[i]);
				max = std::max(max, c[i]);
			}
			print(min, ' '), print(max, '\n');
			// print(top(h1, h1p), ' ');
			// print(top(h2, h2p), '\n');
		}
	}
}

} signed main() { return ringo::main(), 0; }