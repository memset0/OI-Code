// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define int long long
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

const int maxn = 100010;

int n, m, u, v, tmp, cnt, tot, sum, root, full_size, rev_flag;
int maxp[maxn], siz[maxn], col[maxn], mrk[maxn], ans[maxn], vis[maxn], bkt[maxn];
std::vector < int > rub, G[maxn];
struct status { int col, siz; }; std::vector < status > vet;

void get_root(int u, int father) {
	siz[u] = 1, maxp[u] = 0;
	for (auto v : G[u]) if (!vis[v] && v != father)
		get_root(v, u), siz[u] += siz[v], maxp[u] = std::max(maxp[u], siz[v]);
	maxp[u] = std::max(maxp[u], full_size - siz[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void get_dis(int u, int father, int along, int except) {
	++cnt;
	if (!mrk[col[u]]) {
		vet.push_back((status){col[u], siz[u]});
		along++, except += bkt[col[u]];
		// printf("vet.push_back(%d %d)\n", col[u], siz[u]);
	}
	++mrk[col[u]];
	if (rev_flag) {
		ans[root] += along + (mrk[col[root]] ? 0 : 1);
		ans[u] -= along + (mrk[col[root]] ? 0 : 1);
		// printf("ans[%d] += %d; ans[%d] -= %d\n", root, along + (mrk[col[root]] ? 0 : 1), u, along + (mrk[col[root]] ? 0 : 1));
	}
	// printf("get dis %d %d %d %d\n", u, father, along, except);
	// printf("ans[%d] += %d : %d %d %d %d\n", u, tot * along + sum - except, tot, along, sum, except);
	ans[u] += tot * along + sum - except;
	for (auto v : G[u]) if (!vis[v] && v != father)
		get_dis(v, u, along, except);
	--mrk[col[u]];
}

void solve_out(int u) {
	// printf(">>> solve out\n");
	tot = sum = bkt[col[u]] = 1;
	rub.clear(), rub.push_back(col[u]);
	for (auto v : G[u]) if (!vis[v]) {
		// printf("----- %d -----\n", v);
		cnt = 0, vet.clear();
		get_dis(v, u, 0, 0);
		bkt[col[u]] += cnt, sum += cnt, tot += cnt;
		for (auto it : vet) if (it.col != col[u])
			sum += it.siz, bkt[it.col] += it.siz;
		for (auto it : vet) rub.push_back(it.col);
	}
	for (auto it : rub) bkt[it] = 0;
}

void get_size(int u, int father) {
	siz[u] = 1;
	for (auto v : G[u]) if (!vis[v] && v != father)
		get_size(v, u), siz[u] += siz[v];
}

void solve(int u) {
	// printf("===== solve %d =====\n", u);
	vis[u] = 1;
	get_size(u, 0);
	rev_flag = 0, solve_out(u);
	std::reverse(G[u].begin(), G[u].end());
	rev_flag = 1, solve_out(u);
	// for (int i = 1; i <= n; i++) print(ans[i]), putc(i == n ? '\n' : ' ');
	for (auto v : G[u]) if (!vis[v])
		root = 0, maxp[0] = full_size = siz[v], get_root(v, u), solve(root);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(col[i]), ans[i] = 1;
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	root = 0, maxp[0] = full_size = n, get_root(1, 0), solve(root);
	for (int i = 1; i <= n; i++) print(ans[i]), putc('\n');
}

} signed main() { return ringo::main(), 0; }
