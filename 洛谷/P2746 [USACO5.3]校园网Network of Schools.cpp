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

const int maxn = 110;

int n, u, v, tim, top, cnt, cnt1, cnt2;
int dfn[maxn], low[maxn], ind[maxn], outd[maxn], stk[maxn], ins[maxn], bln[maxn];
int tot = 2, hed[maxn], to[maxn * maxn], nxt[maxn * maxn];

struct edge {
	int u, v;
};
std::vector < edge > e;

inline void add_edge(int u, int v) {
	// printf("add edge %d %d\n", u, v);
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	stk[++top] = u, ins[u] = true;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	if (dfn[u] == low[u]) {
		++cnt;
		while (true) {
			int v = stk[top--];
			ins[v] = false;	
			bln[v] = cnt;
			if (u == v)
				break;
		}
	}
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n);
	for (int u = 1, v; u <= n; u++)
		while (read(v), v) {
			add_edge(u, v);
			e.push_back(edge{u, v});
		}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);

	tot = 2, memset(hed, 0, sizeof(hed));
	for (auto it = e.begin(); it != e.end(); it++) {
		u = bln[it->u], v = bln[it->v];
		if (u != v) {
			outd[u]++;
			ind[v]++;
		}
	}

	// for (int i = 1; i <= n; i++)
	// 	print(bln[i]);
	// putc('\n');
	for (int i = 1; i <= cnt; i++) {
		if (!ind[i])
			++cnt1;
		if (!outd[i])
			++cnt2;
	}

	print(cnt1, '\n');
	print(cnt == 1 ? 0 : std::max(cnt1, cnt2), '\n');

	return 0;
}