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

const int maxn = 50010;

int n, m;

void dfs(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0]) {
			f[v][0] = u, g[v][0] = val[i];
			dfs(v);
		}
}

bool check(int x) {
	p = q = 0;
	for (int i = 1; i <= m; i++) {
		memset()
		u = a[i], lst = x;
		for (int i = 19; i >= 0; i--)
			if (lst >= g[u][i]) {
				lst -= g[u][i];
				u = f[u][i];
			}
		if (!u)
			tp[++p] = lst;
	}
	for (int i = hed[1], v = to[i]; i; i = nxt[i], v = to[i])
		if ()
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	read(m);
	for (int i = 1; i <= m; i++) {
		read(a[i]);
		v[a[i]]++;
	}
	dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = g[f[j][i - 1]][i - 1] + g[j][i - 1];
		}
	l = 0, r = 1e9;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	print(ans);
	return 0;
}