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

const int maxn = 70010;
int n, u, v, max, root, full_size;
int s[maxn], fa[maxn], dp[maxn], dep[maxn], vis[maxn], dis[maxn], siz[maxn], ans[maxn], bkt[maxn], sum[maxn], maxp[maxn];
std::vector < int > G[maxn];
struct status { int dis, dp, val, nod; }; std::vector < status > vet[maxn];

void dfs1(int u, int father) {
	if (G[u].size() == 1) dp[u] = 0;
	for (auto v : G[u]) if (v != father)
		dfs1(v, u), dp[u] = std::min(dp[u], dp[v] + 1);
}

void dfs2(int u, int father) {
	if (father) dp[u] = std::min(dp[u], dp[father] + 1);
	for (auto v : G[u]) if (v != father) dfs2(v, u);
}

void get_root(int u, int father) {
	// printf("get root %d %d\n", u, father);
	maxp[u] = 0, siz[u] = 1;
	for (auto v : G[u]) if (!vis[v] && v != father) {
		get_root(v, u);
		siz[u] += siz[v];
		maxp[u] = std::max(maxp[u], siz[v]);
	}
 	maxp[u] = std::max(maxp[u], full_size - siz[u]);
 	if (maxp[u] < maxp[root]) root = u;
}

void add(int k, int x) { for (k = std::max(k + 1, 1); k <= n + 1; k += k & -k) s[k] += x; }
int ask(int k) { int r = 0; for (++k; k; k -= k & -k) r += s[k]; return r; }

void get_dis(int u, int father, int from) {
	vet[from].push_back((status){dis[u], dp[u], 2 - (int)G[u].size(), u});
	for (auto v : G[u]) if (!vis[v] && v != father)
		dis[v] = dis[u] + 1, get_dis(v, u, from);
}

void solve(int u) {
	// printf("===== solve %d =====\n", u);
	vis[u] = 1;
	for (auto v : G[u]) if (!vis[v]) dis[v] = 1, get_dis(v, u, v);
	vet[u].push_back((status){0, dp[u], 2 - (int)G[u].size(), u}), G[u].push_back(u);
	for (auto v : G[u]) if (!vis[v] || u == v)
		for (auto it : vet[v]) add(it.dp - it.dis, it.val);
	for (auto v : G[u]) if (!vis[v] || u == v) {
		for (auto it : vet[v]) add(it.dp - it.dis, -it.val);
		for (auto it : vet[v]) ans[it.nod] += ask(it.dis);
		for (auto it : vet[v]) add(it.dp - it.dis, it.val);
	}
	for (auto v : G[u]) if (!vis[v] || u == v)
		for (auto it : vet[v]) add(it.dp - it.dis, -it.val);
	G[u].pop_back(), vet[u].pop_back();
	for (auto v : G[u]) if (!vis[v]) vet[v].clear();
	for (auto v : G[u]) if (!vis[v]) {
		root = 0, maxp[root] = full_size = siz[v];
		get_root(v, u), solve(root);
	}
}

void main() {
	read(n), memset(dp, 63, sizeof(dp));
	for (int i = 1; i < n; i++) read(u), read(v), G[u].push_back(v), G[v].push_back(u);
	dfs1(1, 0), dfs2(1, 0);
	root = 0, maxp[root] = full_size = n;
	get_root(1, 0), solve(root);
	for (int i = 1; i <= n; i++) if (G[i].size() == 1) ans[i] = 1;
	for (int i = 1; i <= n; i++) print(ans[i]), putc('\n');
	for (int i = 1; i <= n; i++) if (!vis[i]) printf("[%d]\n", i);
}

} int main() { return ringo::main(), 0; }