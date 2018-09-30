// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

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

const int maxn = 200010;

#define lowbit(x) ((x)&(-(x)))

int n, m, u, v, x, pos, opt;
int a[maxn];
ll s[maxn];

int dep[maxn], fa[maxn], siz[maxn], son[maxn], id[maxn], wid[maxn], top[maxn];

struct graph {
	int to, val;
	graph *nxt;
} edge[maxn];

inline void add_edge(int u, int v) {
	edge[u].nxt = new graph;
	edge[u].nxt->to = v;
	edge[v].nxt = new graph;
	edge[v].nxt->to = u;
}

void dfs(int u) {
	printf("dfs %d\n", u);
	for (int i = hed[u])
		if (e->to != fa[u]) {
			fa[e->to] = u;
			dep[e->to] = dep[u] + 1;
			dfs(e->to);
			siz[u] += siz[e->to];
			if (siz[e->to] > siz[son[u]])
				son[u] = e->to;
		}
}

void dfs(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs(son[u], toppoint);
	for (graph *e = &edge[u]; e; e = e->nxt)
		if (e->to != fa[u] && e->to != son[u])
			dfs(e->to, e->to);
}


ll add(int k, int x) {
	for (int i = k; i <= n + 1; i += lowbit(i))
		s[i] += x;
}

ll ask(int k) {
	ll ret = 0;
	printf(">> %d\n", k);
	for (int i = k; i >= 1; i -= lowbit(i))
		ret += s[i];
	return ret;
}

int main() {

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		read(u), read(v);
		add_edge(u, v);
	}
	dfs(1), dfs(1, 1);
	for (int i = 1; i <= n; i++)
		add(id[i], a[i]);
	
	read(m);
	for (int i = 1; i <= m; i++) {
		readc(opt);
		switch (opt) {
			case 'Q':
				read(u);
				print(ask(id[u] + siz[u]) - ask(id[u]));
				break;
			case 'C':
				read(u), read(x);
				add(u + 1, x);
				break;
		}
	}

	return 0;
}
