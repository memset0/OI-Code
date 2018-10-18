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

const int maxn = 100010, maxm = 510;
const int mod = 998244353;

int n, m, u, v, k, o, t, s, ans, ret, X, Y;
int fa[maxn], dep[maxn], siz[maxn], top[maxn], son[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

int f[maxn][maxm], g[maxn][maxm];
int fac[maxm], mat[maxm][maxm];

#define mul(a,b) (a=1ll*(a)*(b)%mod)

inline void sum(int &a, ll b) { a += b; if (a >= mod) a -= mod; }
inline void dec(int &a, ll b) { a -= b; if (a < 0) a += mod; if (a >= mod) a -= mod; }

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	if (siz[u] == 1) return;
	dfs2(son[u], top[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u] && v ^ son[u])
			dfs2(v, v);
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] > dep[top[v]])
			std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

int jump(int u, int v) {
	while (top[u] ^ top[v]) {
		if (fa[top[u]] == v)
			return top[u];
		u = fa[top[u]];
	}
	return son[v];
}

int solve(int u, int exc) {
	if (o) {
		s = exc == fa[u] ? n - siz[u] : siz[exc];
		for (int i = 1; i <= k; i++)
			dec(f[u][i], 1ll * f[u][i - 1] * s % mod);
	 	ret = f[u][k];
		for (int i = k; i >= 1; i--)
			sum(f[u][i], 1ll * f[u][i - 1] * s % mod);
		return ret;
	} else {
		s = exc == fa[u] ? n - siz[u] : siz[exc];
		for (int i = 1; i <= k; i++)
			dec(g[u][i], 1ll * g[u][i - 1] * s % mod);
		ret = 0;
		for (int i = 0; i <= k; i++)
			sum(ret, 1ll * mat[k][i] * g[u][i] % mod);
		for (int i = k; i >= 1; i--)
			sum(g[u][i], 1ll * g[u][i - 1] * s % mod);
	}
	return ret;
}

int main() {
	// freopen("1.in", "r", stdin); 
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs1(1), dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		f[i][0] = f[i][1] = g[i][0] = 1;
	for (int u = 1; u <= n; u++) {
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			int s = v == fa[u] ? n - siz[u] : siz[v];
			for (int j = 500; j; j--) {
				sum(f[u][j], 1ll * f[u][j - 1] * s % mod);
				sum(g[u][j], 1ll * g[u][j - 1] * s % mod);
			}
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= 500; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 1; i <= 500; i++) {
		mat[i][0] = 1;
		for (int j = 1; j <= i; j++)
			mat[i][j] = 1ll * mat[i][j - 1] * (i - j + 1) % mod;
	}
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(k), read(o);
		t = lca(u, v);
		if (o) {
			if (u == t) {
				X = solve(u, jump(v, u));
				Y = solve(v, fa[v]);
			} else if (v == t) {
				X = solve(u, fa[u]);
				Y = solve(v, jump(u, v));
			} else {
				X = solve(u, fa[u]);
				Y = solve(v, fa[v]);
			}
			ans = 1ll * fac[k] * fac[k] % mod * X % mod * Y % mod;
		} else {
			if (u == t) {
				X = solve(u, jump(v, u));
				Y = solve(v, fa[v]);
			} else if (v == t) {
				X = solve(u, fa[u]);
				Y = solve(v, jump(u, v));
			} else {
				X = solve(u, fa[u]);
				Y = solve(v, fa[v]);
			}
			ans = 1ll * X * Y % mod;
		}
		print(ans, '\n');
	}
	return 0;
}