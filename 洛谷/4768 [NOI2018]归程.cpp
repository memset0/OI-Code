// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int N = 200010, N2 = 400010, N3 = 800010;
int T, n, m, u, v, w, c, p, l, k, s;
int fu, fv, pos, lastans;
int fa[N2], f[N2][20], g[N2][20], dis[N2], lim[N2];
bool vis[N];
int tot, hed[N2], nxt[N3], to[N3], val[N3];

struct edge {
	int u, v, w, c;
	edge () {}
	edge (int _u, int _v, int _w, int _c) { u = _u, v = _v, w = _w, c = _c; }
} e[N2];
bool operator < (const edge &a, const edge &b) {
	return a.c > b.c;
}

struct status {
	int u, w;
	status () {}
	status (int _u, int _w) { u = _u, w = _w; }
};
bool operator < (const status &a, const status &b) {
	return a.w > b.w;
}
priority_queue < status > q;

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void add_edge(int u, int v, int w = 0) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void dfs(int u) {
//	printf("dfs %d\n", u);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0]) {
			f[v][0] = u;
			g[v][0] = lim[u];
			dfs(v);
			dis[u] = ~dis[u] && dis[u] < dis[v] ? dis[u] : dis[v];
		}
}

void solve() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read(), c = read();
		add_edge(u, v, w), add_edge(v, u, w);
		e[i] = edge(u, v, w, c);
	}
	q.push(status(1, 0)), dis[1] = 0;
	while (q.size()) {
		u = q.top().u, q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!~dis[v] || dis[u] + val[i] < dis[v]) {
				dis[v] = dis[u] + val[i];
				q.push(status(v, dis[v]));
			}
	}
	sort(e + 1, e + m + 1);
	tot = 2, memset(hed, 0, sizeof(hed));
	for (int i = 1; i <= n << 1; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v, w = e[i].w, c = e[i].c;
//		printf("%d %d %d %d\n", u, v, w, c);
		if ((fu = find(u)) == (fv = find(v))) continue;
		lim[n + (++pos)] = c, fa[fu] = fa[fv] = n + pos;
		add_edge(fu, n + pos), add_edge(n + pos, fu);
		add_edge(fv, n + pos), add_edge(n + pos, fv);
//		printf("%d(%d) -> %d -> %d(%d)\n", u, fu, n + pos, v, fv);
	}
	dfs(n + pos);
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n << 1; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = g[f[j][i - 1]][i - 1];
		}
//	for (int i = 1; i <= n << 1; i++)
//		printf("%d ", dis[i]);
//	puts("");
	p = read(), k = read(), s = read();
	for (int i = 1; i <= p; i++) {
		u = (read() + k * lastans - 1) % n + 1;
		l = (read() + k * lastans) % (s + 1);
//		printf(">>> %d %d\n", u, l);
		for (int i = 19; i >= 0; i--)
			if (f[u][i] && l < g[u][i]) {
//				printf("%d %d -> %d %d : %d\n", u, l, f[u][i], g[u][i], i);
				u = f[u][i];
			}
//		printf("%d %d %d\n", u, f[u][0], g[u][0]);
		printf("%d\n", lastans = (~dis[u] ? dis[u] : -1));
	}
}

void init() {
	tot = 2, pos = lastans = 0;
	while (q.size()) q.pop();
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(hed, 0, sizeof(hed));
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
}

int main() {
//	freopen("INPUT", "r", stdin);
	T = read();
	while (T--) {
		init();
		solve();
	}
	return 0;
}
