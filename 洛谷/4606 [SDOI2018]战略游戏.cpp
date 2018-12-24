// =================================
//   author: memset0
//   date: 2018.12.23 20:16:50
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define walk(i, u, v, G) for (int i = G.hed[u], v = G.to[i]; i; i = G.nxt[i], v = G.to[i])
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
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

const int N = 2e5 + 10, M = 4e5 + 10;
int T, n, m, i, u, v, p, top, cnt, tim, nod;
int a[N], in[N], fa[N], pre[N], ins[N], out[N], dep[N], stk[N], dfn[N], low[N], f[N][20];
std::vector <int> rub;

struct graph {
	int tot, hed[N], nxt[M], to[M];
	graph () { tot = 2; } void init() { tot = 2, memset(hed, 0, sizeof(hed)); }
	inline void add_edge(int u, int v) {
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
} G1, G2, G3;

inline int cmp(int a, int b) { return in[a] < in[b]; }

inline int lca(int u, int v) {
	if (dep[u] > dep[v]) std::swap(u, v);
	for (int i = 19; i >= 0; i--) if (dep[f[v][i]] >= dep[u]) v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

void tarjan(int u, int father) {
	dfn[u] = low[u] = ++tim, stk[++top] = u, ins[u] = 1;
	walk(i, u, v, G1)
		if (!dfn[v]) {
			tarjan(v, u), mind(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				G2.add_edge(u, ++nod);
				int x; do { x = stk[top--];
					G2.add_edge(x, nod), ins[x] = false;
				} while (x != v);
			}
		} else if (ins[v] && v != father) mind(low[u], dfn[v]);
}

void build(int u, int sum) {
	in[u] = ++tim, pre[u] = (sum += u <= n);
	walk(i, u, v, G2) if (v != f[u][0]) {
		f[v][0] = u, dep[v] = dep[u] + 1;
		build(v, sum);
	}
	out[u] = ++tim;
}

int dp(int u, int father) {
	int sum = u <= n;
	walk(i, u, v, G3) if (v != father) sum += dp(v, u) + pre[f[v][0]] - pre[u];
	return sum;
}

void main() {
	for (read(T); T--; ) {
		top = tim = f[1][0] = 0, G1.init(), G2.init();
		memset(ins, 0, sizeof(ins));
		memset(dfn, 0, sizeof(dfn));
		read(n), read(m);
		for (int i = 1; i <= m; i++) read(u), read(v), G1.add_edge(u, v);
		dep[1] = 1, nod = n, tarjan(1, 0), tim = 0, build(1, 0), top = 0;
		for (int i = 1; i < 20; i++)
			for (int j = 1; j <= nod; j++)
				f[j][i] = f[f[j][i - 1]][i - 1];
		read(m);
		// for (int i = 1; i <= nod; i++) print(in[i], " \n"[i == nod]);
		// for (int i = 1; i <= nod; i++) print(out[i], " \n"[i == nod]);
		for (int i = 1; i <= m; i++) {
			rub.clear(), G3.tot = 2, top = 0, rub.push_back(1);
			read(p);
			for (int i = 1; i <= p; i++) read(a[i]);
			std::sort(a + 1, a + p + 1, cmp);
			for (int i = 1, u, v; i <= p; i++) {
				u = a[i];
				while (top > 1 && in[u] < in[stk[top - 1]] && out[stk[top - 1]] < out[u])
					G3.add_edge(stk[top - 1], stk[top]), top--;
				if (in[u] < in[stk[top]] && out[stk[top]] < out[u])
					G3.add_edge(u, stk[top--]);
				v = lca(u, stk[top]);
				while (top > 1 && in[v] < in[stk[top - 1]] && out[stk[top - 1]] < out[v])
					G3.add_edge(stk[top - 1], stk[top]), top--;
				if (in[v] < in[stk[top]] && out[stk[top]] < out[v])
					G3.add_edge(v, stk[top--]);
				if (stk[top] != v) stk[++top] = v, rub.push_back(v);
				if (stk[top] != u) stk[++top] = u, rub.push_back(u);		
				// printf("[%d %d] ", u, v);
				// for (int i = 1; i <= top; i++) print(stk[i], " \n"[i == top]);
			}
			for (int i = 1; i < top; i++) G3.add_edge(stk[i], stk[i + 1]);
			print(dp(stk[1], 0) - p, '\n');
			for (int i : rub) G3.hed[i] = 0;
		}
	}
}

} signed main() { return ringo::main(), 0; }
