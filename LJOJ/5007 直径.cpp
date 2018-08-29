// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline char getc() {
    static const int IN_LEN = 10000000;
    static char buf[IN_LEN], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, IN_LEN, stdin), p1 == p2) ? EOF: *p1++;
}

template <typename T>
inline void read(T &x) {
    x = 0; register char ch; register bool fl = 0;
    while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}

inline void putc(char ch) {
    static const int OUT_LEN = 10000000;
    static char buf[OUT_LEN], *p1 = buf;
    if (ch == -1) fwrite(buf, 1, p1 - buf, stdout);
    if (p1 == buf + OUT_LEN) fwrite(buf, 1, OUT_LEN, stdout), p1 = buf;
    *p1++ = ch;
}
template <typename T>
inline void write(T x){
    if (x < 0) x = -x;
    if (x > 9) write(x / 10);
    putc(x % 10 + 48);
}

const int maxn = 4000010;
const ll Mod = 2333333333333333;

int n, m, u, v, w;
int root1, root2;

int l, r, q[maxn];
ll dis[maxn];
int fa[maxn], fid[maxn], used[maxn];
ll mx1[maxn], mx2[maxn], sta1[maxn], sta2[maxn], dep[maxn];

ll ans;

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1], id[maxn << 1];

struct edge {
	int u, v, w;
} g[maxn];

void add_edge(int u, int v, int w, int i) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	id[tot] = i;
	hed[u] = tot++;
}

int bfs(int s) {
	memset(dis, -1, sizeof(dis));
	l = r = 1, q[1] = s, dis[s] = 0;
	while (l <= r) {
		u = q[l++];
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[v] == -1) {
				dis[v] = dis[u] + val[i];
				q[++r] = v;
			}
	}
	int e = 1;
	for (int i = 2; i <= n; i++)
		if (dis[i] > dis[e])
			e = i;
	return e;
}

void dfs(int u, ll *sta) {
	mx1[u] = mx2[u] = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u;
			fid[v] = id[i];
			dep[v] = dep[u] + val[i];
			dfs(v, sta);
			sta[u] = max(sta[u], sta[v]);
			if (mx1[v] + val[i] > mx1[u]) mx2[u] = mx1[u], mx1[u] = mx1[v] + val[i];
			else if (mx1[v] + val[i] > mx2[u]) mx2[u] = mx1[v] + val[i];
		}
	sta[u] = max(sta[u], mx1[u] + mx2[u]);
}

void new_ans(ll pi, ll qi, ll i) {
	ans = (ans + max(pi, qi) * 23333) % Mod;
	ans = (ans + min(pi, qi) * 2333) % Mod;
	ans = (ans + i * i * 233) % Mod;
	ans = (ans + i * 23 + 2) % Mod;
	// printf(">>> (%lld : %d -> %d) %lld %lld %lld\n", i, g[i].u, g[i].v, pi, qi, ans);
}
int main() {
	// freopen("tree.in", "r", stdin);
	// freopen("tree.out", "w", stdout);
	// freopen("data.txt", "r", stdin);

	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, w, i);
		add_edge(v, u, w, i);
		g[i].u = u;
		g[i].v = v;
		g[i].w = w;
	}

	root2 = bfs(1);
	root1 = bfs(root2);

	fa[root2] = 0, dfs(root2, sta2);
	fa[root1] = 0, dfs(root1, sta1);

	// printf("root1 = %d root2 = %d\n", root1, root2);

	for (int u = root2; u != root1; u = fa[u]) {
		used[fid[u]] = 1;
		new_ans(sta1[u], sta2[fa[u]], fid[u]);
	}

	for (int i = 1; i < n; i++)
		if (!used[i]) {
			u = g[i].u, v = g[i].v;
			if (fa[u] == v) swap(u, v);
			new_ans(sta1[root1], sta1[v], i);
		}
    
	write(ans), putc('\n');
	putc(EOF);

	return 0;
}