// ================================
//   author: memset0
//   date: 2018.12.10 12:05:37
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

const int N = 3e2 + 10, M = 4e4 + 10;
int n, m;
int ans[N], pe[N], pn[N];
ll dis[N], dis2[N];
int tot = 2, hed[N], to[M << 1], nxt[M << 1], val[M << 1];
bool ln[N], le[M << 1], vis[N];

struct edge {
	int u, v, w;
} e[M];

struct status {
	int u;
	ll w;
	status () {}
	status (int _u, int _w) { u = _u, w = _w; }
	inline bool operator < (const status &other) const {
		return w > other.w;
	}
};
std::priority_queue < status > q;

inline void mind(int &x, int y) {
	if (x == -1 || y < x) x = y;
}

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

inline void spfa(int s) {
	// printf("=== spfa %d ===\n", s);
	memset(vis, 0, sizeof(vis)), memset(dis, -1, sizeof(dis));
	int u; dis[s] = 0, q.push(status(s, 0));
	while (q.size()) {
		u = q.top().u, q.pop(); if (vis[u]) continue; vis[u] = 1;
		// printf("> %d\n", u);
		for (register int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[v] == -1 || dis[u] + val[i] < dis[v]) {
				dis[v] = dis[u] + val[i], pe[v] = i, pn[v] = u;
				q.push(status(v, dis[v]));
			}
	}
	// printf("=== end spfa ===\n");
}

#define dis dis2
inline int spfa(int s, int e) {
	// printf("--- spfa %d %d ---\n", s, e);
	memset(vis, 0, sizeof(vis)), memset(dis, -1, sizeof(dis));
	int u; dis[s] = 0, q.push(status(s, 0));
	while (q.size()) {
		u = q.top().u, q.pop(); if (vis[u]) continue; vis[u] = 1;
		// printf("> %d\n", u);
		for (register int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if ((!le[i] && !ln[v]) && (dis[v] == -1 || dis[u] + val[i] < dis[v])) {
				dis[v] = dis[u] + val[i];
				// printf("%d(%d) -> %d(%d)\n", u, dis[u], v, dis[v]);
				q.push(status(v, dis[v]));
			}
	}
	// printf("%d -> %d : %d\n", s, e, dis[e]);
	return dis[e];
}
#undef dis

inline void split_out(int s, int e, bool tag) {
	// printf("> split %d %d %d <\n", s, e, tag);
	for (int u = pn[e]; u != s; u = pn[u]) ln[u] = tag;
	for (int u = e; u != s; u = pn[u]) le[pe[u]] = le[pe[u] ^ 1] = tag;
	// printf("> end split <\n");
}

void main() {
	memset(ans, -1, sizeof(ans));
	read(n), read(m);
	for (register int i = 1; i <= m; i++) {
		read(e[i].u), read(e[i].v), read(e[i].w);
		if (e[i].u == e[i].v) { mind(ans[e[i].u], e[i].w); continue; }
		add_edge(e[i].u, e[i].v, e[i].w);
		add_edge(e[i].v, e[i].u, e[i].w);
	}
	for (register int u = 1; u <= n; u++) {
		spfa(u);
		// for (register int v = 1; v <= n; v++) print(dis[v], " \n"[v == n]);
		for (register int v = 1, w; v <= n; v++)
			if (~dis[v] && v != u) {
				split_out(u, v, 1);
				w = spfa(u, v);
				// printf("ln: "); for (int i = 1; i <= n; i++) if (ln[i]) print(i, ' '); puts("");
				// printf("le: "); for (int i = 2; i < tot; i++) if (le[i]) printf("(%d %d %d) ", to[i], to[i ^ 1], val[i]); puts("");
				// printf("%d %d : %d %d\n", u, v, w, dis[v]);
				if (~w) mind(ans[u], w + dis[v]);
				split_out(u, v, 0);
			}
	}
	for (int i = 1; i <= n; i++) print(ans[i], ' ');
	puts("");
}

} signed main() { return ringo::main(), 0; }