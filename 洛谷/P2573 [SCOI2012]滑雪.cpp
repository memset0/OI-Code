// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define int long long
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

const int N = 1e5 + 10, M = 2e6 + 10;
int n, m, u, v, w, cnt, sum;
int h[N], vis[N];
int tot = 2, hed[N], nxt[M], to[M], val[M];

struct status {
	int node, high, edge;
	inline bool operator < (const status &other) const {
		if (high == other.high) return edge > other.edge;
		return high < other.high;
	}
} now;
std::priority_queue < status > hep;

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(h[i]);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		if (h[u] >= h[v]) add_edge(u, v, w);
		if (h[v] >= h[u]) add_edge(v, u, w);
	}
	hep.push((status){1, h[1], 0});
	while (hep.size()) {
		now = hep.top(), u = now.node, hep.pop();
		// printf("%d %d %d\n", now.node, now.high, now.edge);
		if (vis[u]) continue;
		vis[u] = 1;
		++cnt, sum += now.edge;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!vis[v]) {
				// printf("%d -> %d\n", u, v);
				hep.push((status){v, h[v], val[i]});
			}
	}
	print(cnt, ' '), print(sum, '\n');
}

} signed main() { return ringo::main(), 0; }