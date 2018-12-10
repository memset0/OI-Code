// =================================
//   author: memset0
//   date: 2018.12.10 08:06:28
//   website: https://memset0.cn/
// =================================
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

const int N = 3e2 + 10, M = 4e4 + 10;
int n, m, u, v, w;
int ans[N];

struct edge {
	int u, v, w;
	inline bool operator < (const edge &other) const {
		if (u != other.u) return u < other.u;
		if (v != other.v) return v < other.v;
		return w < other.w;
	}
} e[M];

inline int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	if (a < b) return a;
	return b;
}

namespace S1 {
int dis[N], dis2[N], f[N][N];
void main() {
	for (int u = 1; u <= n; u++) {
		memset(f, -1, sizeof(f));
		memset(dis, -1, sizeof(dis));
		memset(dis2, -1, sizeof(dis2));
		for (int i = 1; i <= n; i++) f[i][i] = 0;
		for (int i = 1; i <= m; i++)
			if (e[i].u != u && e[i].v != u) {
				int u = e[i].u, v = e[i].v, w = e[i].w;
				f[u][v] = f[v][u] = min(f[u][v], w);
			} else if (e[i].u == u && e[i].v == u)
				ans[u] = min(ans[u], e[i].w);
			else {
				int v = e[i].u == u ? e[i].v : e[i].u, w = e[i].w;
				if (dis[v] == -1) dis[v] = w;
				else if (dis[v] < w) dis2[v] = min(dis2[v], w);
				else dis2[v] = dis[v], dis[v] = w;
			}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++) if (~f[i][k])
				for (int j = 1; j <= n; j++) if (~f[k][j])
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		for (int i = 1; i <= n; i++)
			if (~dis[i] && ~dis2[i])
				ans[u] = min(ans[u], dis[i] + dis2[i]);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (i != u && j != u && ~dis[i] && ~dis[j] && ~f[i][j]) {
					ans[u] = min(ans[u], dis[i] + dis[j] + f[i][j]);
				}
	}
}
}

namespace S2 {
int tot, dis[N], hed[N], nxt[M << 1], to[M << 1], val[M << 1], id[M << 1];
bool cant[M << 1], vis[N];
struct status {
	int point, dis;
	status () {}
	status (int _point, int _dis) { point = _point, dis = _dis; }
	inline bool operator < (const status &other) const {
		return dis > other.dis;
	}
};
std::priority_queue < status > q;
inline void add_edge(int u, int v, int w, int d) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, id[tot] = d, hed[u] = tot++;
}
inline int spfa(int s, int e, int limit) {
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	cant[limit << 1] = cant[(limit << 1) - 1] = 1;
	dis[s] = 0, 		q.push(status(s, 0));
	while (q.size()) {
		int u = q.top().point; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!cant[id[i]] && (dis[v] == -1 || dis[u] + val[i] < dis[v])) {
				dis[v] = dis[u] + val[i];
				q.push(status(v, dis[v]));
			}
	}
	cant[limit << 1] = cant[(limit << 1) - 1] = 0;
	return dis[e];
}
void main() {
	tot = 2;
	for (int i = 1; i <= m; i++) {
		add_edge(e[i].u, e[i].v, e[i].w, (i << 1) - 1);
		add_edge(e[i].v, e[i].u, e[i].w, i << 1);
	}
	for (int i = 1, now; i <= m; i++) {
		now = spfa(e[i].u, e[i].v, i);
		ans[e[i].u] = min(ans[e[i].u], now + e[i].w);
		ans[e[i].v] = min(ans[e[i].v], now + e[i].w);
	}
}
}

void main() {
	memset(ans, -1, sizeof(ans));
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		e[i] = (edge){u, v, w};
	}
	if (n <= 100) S1::main();
	else S2::main();
	for (int i = 1; i <= n; i++) print(ans[i], ' ');
	puts("");
	// std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
}

} signed main() { return ringo::main(), 0; }