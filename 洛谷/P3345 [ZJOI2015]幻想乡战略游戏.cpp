// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.21 18:25:50
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 1e5 + 10, L = 20;
int n, m, root, full_size, _con;
int siz[N], vis[N], sum[N], cnt[N], maxp[N], sumv[N];
int con[N][3], fa[N][L], sum2[N][L], dis[N][L], sumv2[N][L];
int tot = 2, hed[N], nxt[N << 1], val[N << 1], to[N << 1];
std::pair <int, int> side[N][L];

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

void get_siz(int u, int father) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father)	 {
			get_siz(v, u);
			siz[u] += siz[v];
		}
}

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

void get_dis(int u, int father, int root, int distance) {
	// printf("get dis (root = %d) => %d\n", root, u);
	int id = ++cnt[u]; fa[u][id] = root, dis[u][id] = distance;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father)
			get_dis(v, u, root, distance + val[i]);
}

void get_side(int u, int father, int first, int second) {
	side[u][cnt[u]] = std::make_pair(first, second);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v] && v != father)
			get_side(v, u, first, second);
}

void build_tree(int u) {
	// printf("build tree %d\n", u);
	vis[u] = 1, fa[u][++cnt[u]] = u;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			get_dis(v, u, u, val[i]);
			get_side(v, u, v, cnt[v]);
		}
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			get_siz(v, u), root = 0, maxp[0] = full_size = siz[v], get_root(v, u);
			con[++_con][0] = u, con[_con][1] = root, con[_con][2] = v;
			build_tree(root);
		}
}

void modify(int u, int dta) {
	for (int i = 1, root = fa[u][i]; i <= cnt[u]; i++, root = fa[u][i]) {
		if (u == root) { sumv[root] += dta; continue; }
		// printf("modify %d %d : %d %d %d \n", u, root, fa[u][i], dis[u][i], dis[u][i] * dta);
		sumv[root] += dta, sumv2[side[u][i].first][side[u][i].second] += dta;
		sum[root] += dis[u][i] * dta, sum2[side[u][i].first][side[u][i].second] += dis[u][i] * dta;
	}
}

int calc(int u, int flag = 0) {
	int ans = 0;
	for (int i = 1, root = fa[u][i]; i <= cnt[u]; i++, root = fa[u][i]) {
		if (u == root) { ans += sum[root]; continue; }
		// if (!flag) printf("calc %d %d %d : %d %d %d %d\n", u, root, dis[u][i], sum[root], sum2[side[u][i].first][side[u][i].second], sumv[root], sumv2[side[u][i].first][side[u][i].second]);
		ans += sum[root] - sum2[side[u][i].first][side[u][i].second]
			 + dis[u][i] * (sumv[root] - sumv2[side[u][i].first][side[u][i].second]);
	}
	return ans;
}

int query(int u, int father, int now) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father) {
			int mov = calc(val[i]);
			if (mov < now)
				return query(v, u, calc(v));
		}
	return now;
}

void main() {
	read(n), read(m);
	for (int i = 1, u, v, w; i < n; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, w), add_edge(v, u, w);
	}
	root = 0, maxp[0] = full_size = n, get_root(1, 0);
	build_tree(root);
	tot = 2, memset(hed, 0, sizeof(hed));
	for (int i = 1; i <= _con; i++) {
		add_edge(con[i][0], con[i][1], con[i][2]);
		add_edge(con[i][1], con[i][0], con[i][2]);
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 1) {
			root = i;
			break;
		}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= cnt[i]; j++)
	// 		printf("%d [%d %d] ", fa[i][j], side[i][j].first, side[i][j].second);
	// 	putchar('\n');
	// }
	for (int i = 1, u, w; i <= m; i++) {
		read(u), read(w);
		modify(u, w);
		// for (int i = 1; i <= n; i++) print(calc(i, 1), " \n"[i == n]);
		print(query(root, 0, calc(root)), '\n');
	}
}

} signed main() { return ringo::main(), 0; }