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
	register char ch;
	while (ch = getc(), ch != 'Y' && ch != 'N');
	x = (ch == 'Y' ? 1 : 0);
}
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 1010, maxm = 4010;

int n, m, u, v, w1, w2, top, pos, cnt;
int dfn[maxn << 1], low[maxn << 1], ins[maxn << 1], stk[maxn << 1], col[maxn << 1], ans[maxn], vis[maxn << 1];

struct edge {
	int tot = 2, hed[maxn << 1], nxt[maxm << 1], to[maxm << 1];
	inline void add_edge(int u, int v) {
		nxt[tot] = hed[u], to[tot] = v;
		hed[u] = tot++;
	}
} e1, e2;


void tarjan(int u) {
//	printf("%d\n", u);
	dfn[u] = low[u] = ++pos;
	ins[u] = 1, stk[++top] = u;
	for (int i = e1.hed[u]; i; i = e1.nxt[i]) {
		int v = e1.to[i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (top) {
			int v = stk[top--];
			col[v] = cnt;
			ins[v] = 0; 
			if (u == v) break;
		}
	}
}

void dfs(int u) {
	vis[u] = 1;
	for (int i = e2.hed[u]; i; i = e2.nxt[i]) {
		int v = e2.to[i];
		if (!vis[v])
			dfs(v);
	}
}

bool check(int u) {
	memset(vis, 0, sizeof(vis));
	dfs(u);
//	for (int i = 1; i <= (n << 1); i++)
//		print(vis[i], ' ');
//	putc('\n');
	for (int i = 1; i <= n; i++)
		if (vis[col[i]] && vis[col[i + n]])
			return 0;
	return 1;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), readc(w1);
		read(v), readc(w2);
		e1.add_edge(w1 ? u : u + n, w2 ? v + n : v);
		e1.add_edge(w2 ? v : v + n, w1 ? u + n : u);
	}
	
	for (int i = 1; i <= (n << 1); i++)
		if (!dfn[i])
			tarjan(i);
	for (int u = 1; u <= (n << 1); u++)
		for (int j = e1.hed[u]; j; j = e1.nxt[j]) {
			v = e1.to[j];
			if (col[u] ^ col[v]) {
				e2.add_edge(col[u], col[v]);
			}
		}
	
	for (int i = 1; i <= n; i++) {
		w1 = check(col[i]), w2 = check(col[i + n]);
		if (!w1 && !w2)	{
			puts("IMPOSSIBLE");
			return 0;
		}
		if (w1 && w2) ans[i] = '?';
		if (w1 && !w2) ans[i] = 'N';
		if (!w1 && w2) ans[i] = 'Y';
	}
	for (int i = 1; i <= n; i++)
		putc(ans[i]);
	putc('\n');

	return 0;
}
