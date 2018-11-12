#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 5010;
int n, m, u, v, tu, tv, tim;
int fa[maxn], now[maxn], ans[maxn], deg[maxn];
int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];
std::vector < int > G[maxn];
bool vis[maxn];

struct edge {
	int u, v;
} e[maxn];

il void add_edge(int u, int v) {
	printf("add edge %d %d\n", u, v);
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
}

void dfs(int u) {
	// printf("dfs %d %d\n", u, fa[u]);
	now[++tim] = u, vis[u] = 1;
	for (std::vector < int > ::iterator it = G[u].begin(); it != G[u].end(); it++) {
		v = *it;
		if (!vis[v]) {
			if (u == tu && v == tv) continue;
			if (u == tv && v == tu) continue;
			fa[v] = u;
			dfs(v);
		}
	}
}

il void calc(int exp) {
	// printf("=== calc %d ===\n", exp);
	tim = 0, tu = e[exp].u, tv = e[exp].v;
	memset(vis, 0, sizeof(vis));
	dfs(1);
	if (tim < n) return;
	for (int i = 1; i <= n; i++)
		if (now[i] < ans[i] || !ans[i]) {
			for (int i = 1; i <= n; i++)
				ans[i] = now[i];
			break;
		} else if (ans[i] < now[i])
			break;
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		G[u].push_back(v);
		G[v].push_back(u);
		++deg[u], ++deg[v];
		e[i] = (edge){u, v};
	}
	for (int i = 1; i <= n; i++)
		std::sort(G[i].begin(), G[i].end());
	if (m == n - 1) {
		calc(n);
	} else {
		for (int k = 1; k <= m; k++)
			calc(k);
	}
	for (int i = 1; i <= n; i++)
		print(ans[i]), putc(i == n ? '\n' : ' ');
}

} int main() { return ringo::main(), 0; }