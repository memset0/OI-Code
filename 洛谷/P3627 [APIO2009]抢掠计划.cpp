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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 500010;

int n, m, u, v, s, p, l, r, ans, pos, cnt, top;
int a[maxn], b[maxn], q[maxn];
int dis[maxn], low[maxn], dfn[maxn], stk[maxn], col[maxn], sum[maxn];
bool ins[maxn], inq[maxn];

int tot = 2, hed[maxn], nxt[maxn], to[maxn];
inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v;
	hed[u] = tot++;
//	printf("add edge %d %d\n", u, v);
}
struct edge {
	int u, v;
} e[maxn];

void tarjan(int u) {
	dfn[u] = low[u] = ++pos;
	ins[u] = 1, stk[++top] = u;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		++cnt;
		while (top) {
			int v = stk[top--];
			col[v] = cnt;
			ins[v] = 0;
			if (u == v) return;
		}
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		add_edge(u, v);
		e[i].u = u, e[i].v = v;
	}
	for (int i = 1; i <= n; i++)
		read(a[i]);
	read(s), read(p);
	for (int i = 1; i <= p; i++)
		read(b[i]);

	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
		sum[col[i]] += a[i];
		
//	for (int i = 1; i <= n; i++)
//		print(low[i], ' ');
//	putc('\n');
//	for (int i = 1; i <= n; i++)
//		print(dfn[i], ' ');
//	putc('\n');
//	for (int i = 1; i <= n; i++)
//		print(col[i], ' ');
//	putc('\n');
//	for (int i = 1; i <= cnt; i++)
//		print(sum[i], ' ');
//	putc('\n');
			
	tot = 2, memset(hed, 0, sizeof(hed));
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v;
		if (col[u] != col[v])
			add_edge(col[u], col[v]);
	}
	
	s = col[s]; 
	l = r = 0, q[0] = s, inq[s] = 1, dis[s] = sum[s];
	while (l <= r) {
		u = q[(l++) % n], inq[u] = 0;
		for (int i = hed[u]; i; i = nxt[i]) {
			int v = to[i];
			if (dis[v] < dis[u] + sum[v]) {
				dis[v] = dis[u] + sum[v];
				if (!inq[v]) {
					inq[v] = 1;
					q[(++r) % n] = v;
				}
			}
		}
	}

//	for (int i = 1; i <= cnt; i++)	
//		print(dis[i], ' ');
//	putc('\n');
	for (int i = 1; i <= p; i++)
		ans = std::max(ans, dis[col[b[i]]]);
	print(ans);
	
	return 0;
}