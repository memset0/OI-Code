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

const int maxn = 2e5 + 10, maxm = 1e6 + 10, inf = 0x3f3f3f3f;
int n, m, u, v, w, ans, root, full_size;
int vis[maxn], siz[maxn], dis[maxn], stp[maxn], bkt[maxm], maxp[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];
struct status { int dis, stp; }; std::vector < status > vet;
std::vector < int > rub;

void get_root(int u, int father) {
	siz[u] = 1, maxp[u] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			get_root(v, u);
			siz[u] += siz[v];
			maxp[u] = std::max(maxp[u], siz[v]);
		}
	maxp[u] = std::max(maxp[u], full_size - siz[u]);
	if (maxp[u] < maxp[root]) root = u;
}

void get_dis(int u, int father) {
	if (dis[u] > m) return;
	vet.push_back((status){dis[u], stp[u]});
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father) {
			dis[v] = dis[u] + val[i], stp[v] = stp[u] + 1;
			get_dis(v, u);
		}
}

void solve(int u) {
	// printf("===== solve %d =====\n", u);
	vis[u] = 1, rub.clear(), rub.push_back(0);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			vet.clear(), vet.push_back((status){0, 0});
			dis[v] = val[i], stp[v] = 1, get_dis(v, u);
			for (auto it : vet) ans = std::min(ans, it.stp + bkt[m - it.dis]);
			for (auto it : vet) bkt[it.dis] = std::min(bkt[it.dis], it.stp), rub.push_back(it.dis);
		}
	for (auto it : rub) bkt[it] = inf;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			root = 0, maxp[root] = full_size = siz[v];
			get_root(v, u), solve(root);
		}
}

void main() {
	read(n), read(m), ans = inf;
	memset(bkt, 63, sizeof(bkt));
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w), ++u, ++v;
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	root = 0, maxp[root] = full_size = n;
	get_root(1, 0), solve(root);
	printf("%d\n", ans == inf ? -1 : ans);
}

} int main() { return ringo::main(), 0; }