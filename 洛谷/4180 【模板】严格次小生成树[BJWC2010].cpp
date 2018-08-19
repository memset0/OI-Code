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

const int maxn = 100010, maxm = 300010;
const int inf = 0;

int n, m, u, v, t;
int used[maxm], dep[maxn], f[maxn][20];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

ll sum, ans, ans1, ans2;
ll w1[maxn][20], w2[maxn][20];

void add_edge(int u, int v, int w) {
	// printf("add edge %d -> %d : %d\n", u, v, w);
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;
}

struct edge {
	int u, v, w;
	bool operator < (const edge &b) const {
		return w < b.w;
	}
} g[maxm];

int fa[maxn];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int a, int b) {
	fa[find(a)] = find(b);
}

ll lim_max_3(ll lim, ll a, ll b, ll c) {
	// printf("lim_max_3(%d, %d, %d, %d) = ", lim, a, b, c);
	if (a == lim) a = -inf;
	if (b == lim) b = -inf;
	if (c == lim) c = -inf;
	// printf("%d\n",max(a, max(b, c)));
	return max(a, max(b, c));
}

ll lim_max_4(ll lim, ll a, ll b, ll c, ll d) {
	if (a == lim) a = -inf;
	if (b == lim) b = -inf;
	if (c == lim) c = -inf;
	if (d == lim) d = -inf;
	return max(max(a, b), max(c, d));
}

int lca(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void dfs(int u) {
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			f[to[i]][0] = u;
			w1[to[i]][0] = val[i];
			w2[to[i]][0] = -inf;
			dep[to[i]] = dep[u] + 1;
			dfs(to[i]);
		}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		g[i].u = read();
		g[i].v = read();
		g[i].w = read();
	}

	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(g + 1, g + m + 1);

	for (int i = 1; i <= m; i++)
		if (find(g[i].u) != find(g[i].v)) {
			merge(g[i].u, g[i].v);
			add_edge(g[i].u, g[i].v, g[i].w);
			add_edge(g[i].v, g[i].u, g[i].w);
			used[i] = 1;
		}

	dep[1] = 1;
	dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			w1[j][i] = max(w1[j][i - 1], w1[f[j][i - 1]][i - 1]);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			w2[j][i] = lim_max_4(w1[j][i], w1[j][i - 1], w1[f[j][i - 1]][i - 1], w2[j][i - 1], w2[f[j][i - 1]][i - 1]);
	for (int i = 1; i <= m; i++) {
		if (used[i]) sum += g[i].w;
		ans += g[i].w;
	}

	for (int i = 1; i <= m; i++)
		if (!used[i]) {
			u = g[i].u, v = g[i].v;
			t = lca(u, v), ans1 = ans2 = -inf;
			for (int i = 19; i >= 0; i--)
				if (dep[f[u][i]] >= dep[t]) {
					ans1 = max(ans1, w1[u][i]);
					u = f[u][i];
				}
			for (int i = 19; i >= 0; i--)
				if (dep[f[v][i]] >= dep[t]) {
					ans1 = max(ans1, w1[v][i]);
					v = f[v][i];
				}
			u = g[i].u, v = g[i].v;
			for (int i = 19; i >= 0; i--)
				if (dep[f[u][i]] >= dep[t]) {
					ans2 = lim_max_3(ans1, ans2, w1[u][i], w2[u][i]);
					u = f[u][i];
				}
			for (int i = 19; i >= 0; i--)
				if (dep[f[v][i]] >= dep[t]) {
					ans2 = lim_max_3(ans1, ans2, w1[v][i], w2[v][i]);
					v = f[v][i];
				}
			u = g[i].u, v = g[i].v;
			// printf(">>> %d %d %d %d %d %d\n", u, v, t, ans1, ans2, g[i].w);
			if (ans1 == g[i].w) ans = min(ans, sum - ans2 + g[i].w);
			else ans = min(ans, sum - ans1 + g[i].w);
		}

	printf("%lld\n", ans);

	return 0;
}