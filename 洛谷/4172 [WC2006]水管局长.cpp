// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 1010, maxm = 100010, maxq = 100010, maxp = maxn + maxm;

struct edge {
	int u, v, w;
	bool operator < (const edge &b) const {
		return w < b.w;
	}
} g[maxm];

struct query {
	int opt, u, v;
} q[maxm];

int n, m, k, u, v, w, t, opt;
int father[maxn], id[maxn][maxn], broken[maxm];
int fa[maxp], ch[maxp][2], val[maxp], max[maxp], pto[maxp], lazy[maxp];

bool is_root(int u) {
	return ch[fa[u]][0] != u && ch[fa[u]][1] != u;
}

bool get_son(int u) {
	return ch[fa[u]][1] == u;
}

void update(int u) {
	max[u] = val[u], pto[u] = u;
	if (max[ch[u][0]] > max[u]) max[u] = max[ch[u][0]], pto[u] = pto[ch[u][0]];
	if (max[ch[u][1]] > max[u]) max[u] = max[ch[u][1]], pto[u] = pto[ch[u][1]];
}

void rotate(int x) {
	int f = fa[x], fson = get_son(x);
	int ff = fa[f], ffson = get_son(f);
	int y = ch[x][fson ^ 1];
	if (!is_root(f)) ch[ff][ffson] = x;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	ch[f][fson] = y, ch[x][fson ^ 1] = f;
	update(f), update(x);
}

void clean_up(int u) {
	if (!is_root(u)) clean_up(fa[u]);
	if (lazy[u]) {
		std::swap(ch[u][0], ch[u][1]);
		lazy[ch[u][0]] ^= 1;
		lazy[ch[u][1]] ^= 1;
		lazy[u] = 0;
	}
}

void splay(int u) {
	clean_up(u);
	while (!is_root(u)) {
		if (get_son(u) ^ get_son(fa[u])) rotate(u);
		else rotate(fa[u]);
		rotate(u);
	}
}

void access(int x) {
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, update(x);
}

void mroot(int u) {
	access(u), splay(u);
	lazy[u] ^= 1;
}

void split(int u, int v) {
	mroot(u), access(v), splay(v);
}

void link(int u, int v) {
	mroot(u), fa[u] = v;
}

void cut(int u, int v) {
	split(u, v);
	fa[u] = ch[v][0] = 0;
}

int find_father(int x) {
	if (father[x] == x) return x;
	return father[x] = find_father(father[x]);
}

void add_edge(int i) {
	u = g[i].u, v = g[i].v, w = g[i].w;
	if (find_father(u) == find_father(v)) {
		split(u, v);
		int t = pto[v];
		if (w < val[t]) {
			cut(u, t), cut(t, v);
			link(u, i + n), link(i + n, v);
		}
	} else {
		father[find_father(u)] = find_father(v);
		link(u, i + n), link(i + n, v);
	}
}

int query_edge(int u, int v) {
	split(u, v);
	return max[v];
}

int main() {
	freopen("INPUT", "r", stdin);
	
	n = read(), m = read(), t = read();
	for (int i = 1; i <= n; i++) {
		u = read(), v = read(), w = read();
		g[i].u = u, g[i].v = v, g[i].w = w;
		id[u][v] = id[v][u] = i;
	}
	
	for (int i = 1; i <= t; i++) {
		opt = read(), u = read(), v = read();
		q[i].opt = opt, q[i].u = u, q[i].v = v;
		broken[id[u][v]] = 1;
	}
	
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= m; i++)
		val[i + n] = g[i].w;
	for (int i = 1; i <= m; i++)
		if (!broken[i])
			add_edge(i);
	
	for (int i = t; i >= 1; i++) {
		opt = q[i].opt, u = q[i].u, v = q[i].v;
		printf(">>> %d : %d %d\n", opt, u, v);
		if (opt == 1) add_edge(id[u][v]);
		else printf("%d\n", query_edge(u, v));
	}
	
	return 0;
}

