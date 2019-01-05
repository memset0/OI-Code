// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

#define int long long

const int maxn = 100010;

int n, m, x, y, u, v, w, tu, tv, tw, opt, ans, pos;
int a[maxn], s[maxn], cst[maxn], tmp[maxn];
int fa[maxn], id[maxn], top[maxn], son[maxn], wid[maxn], dep[maxn], siz[maxn];
bool vis[maxn];

int tot = 2, hed[maxn], to[maxn << 1], val[maxn << 1], nxt[maxn << 1];
struct edge {
	int u, v, w;
} e[maxn];

void dfs1(int u) {
	vis[u] = siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!vis[v]) {
			fa[v] = u, dep[v] = dep[u] + 1, cst[v] = val[i];
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		} else if (v != fa[u]) {
			tu = u, tv = v, tw = val[i];
			// printf("%d %d %d %d\n", u, v, tu, tv);
		}
}

void dfs2(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u] && !(u == tu && v == tv) && !(u == tv && v == tu))
			dfs2(v, v);
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]])
			std::swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v])
		std::swap(u, v);
	return u;
}

void modify(int k, int w) {
	// printf("modify %d : %d -> %d\n", k, tmp[k], w);
	for (int i = k; i <= n; i += i & -i)
		s[i] += w - tmp[k];
	tmp[k] = w;
}

int query(int l, int r) {
	int ret = 0;
	for (int i = r; i; i -= i & -i)
		ret += s[i];
	for (int i = l - 1; i; i -= i & -i)
		ret -= s[i];
	return ret;
}

int query_path_to_root(int u, int v) {
	int ret = 0;
	while (top[u] != top[v]) {
		ret += query(id[top[u]], id[u]);
		u = fa[top[u]];
	}
	if (u != v)
		ret += query(id[son[v]], id[u]);
	return ret;
}

int query_path(int u, int v) {
	int ret = 0, t = lca(u, v);
	ret += query_path_to_root(u, t);
	ret += query_path_to_root(v, t);
	// printf("path %d %d : %d\n", u, v, ret);
	return ret;
}

signed main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(u), read(v), read(w);
		e[i] = edge{u, v, w};
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	dfs1(1), dfs2(1, 1);
	// printf("%d %d %d\n", tu, tv, tw);
	for (int i = 1; i <= n; i++)
		for (int j = id[i]; j <= n; j += j & -j)
			s[j] += cst[i];
	for (int i = 1; i <= n; i++)
		tmp[id[i]] = cst[i];
	// for (int i = 1; i <= n; i++)
	// 	print(query(id[i], id[i]));
	// putc('\n');
	// printf("%d %d %d\n", tu, tv, tw);
	for (int i = 1; i <= m; i++) {
		read(opt), read(x), read(y);
		if (opt == 1) {
			u = e[x].u, v = e[x].v;
			if ((u == tu && v == tv) || (u == tv && v == tu)) {
				tw = y;
			} else {
				u = dep[u] > dep[v] ? u : v;
				modify(id[u], y);
			}
			// for (int i = 1; i <= n; i++)
			// 	print(query(id[i], id[i]));
			// putc('\n');
		} else {
			ans = query_path(x, y);
			ans = std::min(ans, query_path(x, tu) + query_path(tv, y) + tw);
			ans = std::min(ans, query_path(y, tu) + query_path(tv, x) + tw);
			print(ans, '\n');
		}
	}

	return 0;
}