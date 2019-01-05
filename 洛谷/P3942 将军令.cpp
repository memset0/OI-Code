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

const int maxn = 100010, inf = 1e9;

int n, m, u, v, t, ans, pts;
int dep[maxn], fa[maxn];
bool vis[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct cmp {
	bool operator () (int a, int b) {
		return dep[a] < dep[b];
	}
};
std::priority_queue < int, std::vector < int >, cmp > q;

void dfs(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
}

void clear(int u, int k, int from) {
	if (k < 0)
		return;
	if (!vis[u]) {
		vis[u] = 1;
		pts--;
	}
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != from)
			clear(v, k - 1, u);
}

int main() {
//	freopen("general.in", "r", stdin);
//	freopen("general.out", "w", stdout);
	
	read(n), read(m), read(t);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	
	dep[1] = 1;
	dfs(1);
	for (int i = 1; i <= n; i++)
		q.push(i);
	
	pts = n;
	while (pts) {
		++ans;
		while (vis[q.top()])
			q.pop();
		u = q.top();
		for (int i = 1; i <= m; i++)
			u = fa[u];
		if (!u) u = 1;
//		for (int i = 1; i <= n; i++)
//			printf("%d ", vis[i]);
//		puts("");
//		printf("%d %d\n", u, vis[u]);
		clear(u, m, 0);
	}
	
	print(ans, '\n');

	return 0;
}