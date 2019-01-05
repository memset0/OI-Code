// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.16 13:59:47
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

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

const int N = 250010, inf = 1e18;
int n, m, u, v, w, t, x, c, tim, pos, til;
typedef int R[N]; R f, g, in, fa, id, wid, out, top, siz, dep, son, stk, que, tag;
int tot = 2, hed[N], to[N << 1], nxt[N << 1], val[N << 1];
std::vector <int> G[N];

inline bool cmp(int a, int b) { return in[a] < in[b]; }
inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
}

void dfs1(int u, int min) {
	in[u] = ++tim, g[u] = min, siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dfs1(v, std::min(min, val[i])), siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
	out[u] = ++tim;
}

void dfs2(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], top[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u]) dfs2(v, v);
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

void dp(int u) {
	f[u] = tag[u] ? inf : 0;
	for (std::vector <int> ::iterator it = G[u].begin(); it != G[u].end(); it++)
		dp(*it), f[u] += std::min(f[*it], g[*it]);
	G[u].clear();
}

void main() {
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, w);
	}
	dfs1(1, inf), dfs2(1, 1), read(m);
	for (int i = 1, top; i <= m; i++) {
		x = 0, stk[1] = top = 1, read(til);
		for (int i = 1; i <= til; i++) read(que[i]), tag[que[i]] = 1;
		std::sort(que + 1, que + til + 1, cmp);
		for (int i = 1; i <= til; i++) {
			u = que[i];
			while (top > 1 && in[u] < in[stk[top - 1]] && out[stk[top - 1]] < out[u])
				G[stk[top - 1]].push_back(stk[top]), --top;
			if (in[u] < in[stk[top]] && out[stk[top]] < out[u]) G[u].push_back(stk[top--]);
			t = lca(stk[top], u);
			while (top > 1 && in[t] < in[stk[top - 1]] && out[stk[top - 1]] < out[t])
				G[stk[top - 1]].push_back(stk[top]), --top;
			if (in[t] < in[stk[top]] && out[stk[top]] < out[t]) G[t].push_back(stk[top--]);
			if (t != stk[top]) stk[++top] = t;
			if (u != stk[top]) stk[++top] = u;
		}
		for (int i = 1; i < top; i++) G[stk[i]].push_back(stk[i + 1]);
		dp(1), print(f[1], '\n');
		for (int i = 1; i <= til; i++) tag[que[i]] = 0;
	}
}

} signed main() { return ringo::main(), 0; }