#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 10010, maxm = 100010;

int n, m, u, v, l, r, ans, top, tim, pos;
int a[maxn], s[maxn], q[maxn], ind[maxn], dis[maxn];
int dfn[maxn], low[maxn], stk[maxn], ins[maxn], col[maxn];
int tot = 2, hed[maxn], to[maxm], val[maxm], nxt[maxm];
struct edge{ int u, v; } e[maxm];

il void add_edge(int u, int v) { nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++; }

void tarjan(int u) {
	// printf("tarjan %d\n", u);
	dfn[u] = low[u] = ++tim;
	stk[++top] = u, ins[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
	if (dfn[u] == low[u]) { ++pos; int v;
		while (1) { v = stk[top--]; col[v] = pos, ins[v] = 0; if (u == v) break; }
	}
}

void main() {
	read(n), read(m); rep(i, 1, n) read(a[i]);
	rep(i, 1, m) read(u), read(v), add_edge(u, v), e[i] = (edge){u, v};
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
	rep(i, 1, n) s[col[i]] += a[i];
	tot = 2, memset(hed, 0, sizeof(hed));
	rep(i, 1, m) { u = col[e[i].u], v = col[e[i].v]; if (u != v) add_edge(u, v), ++ind[v]; }
	l = 1; rep(i, 1, n) if (!ind[i]) q[++r] = i, dis[i] = s[i];
	// rep(i, 1, n) print(col[i]), putc(' '); putc('\n');
	while (l <= r) { u = q[l++];
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!--ind[v]) dis[v] = std::max(dis[v], dis[u] + s[v]), q[++r] = v;
	}
	rep(i, 1, n) ans = std::max(ans, dis[i]);
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }