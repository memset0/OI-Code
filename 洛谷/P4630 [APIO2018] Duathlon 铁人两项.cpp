// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.12 23:54:19
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

template < class T > inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template < class T > inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template < class T > inline void maxd(T &a, T b) { if (b > a) a = b; }
template < class T > inline void mind(T &a, T b) { if (b < a) a = b; }
template < class T > inline void print(T x, char c) { print(x), putchar(c); }

const int N = 2e5 + 10, M = 8e5 + 10;
int n, m, top, tot, ans, tim, base;
int dfn[N], low[N], ins[N], stk[N], son[N], siz[N], val[N];

struct edge {
	int tot, flag, hed[N], nxt[M], to[M];
	edge () { tot = 2; }
	void link(int u, int v) {
		// if (flag) printf("link %d %d\n", u, v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
} G1, G2;

void tarjan(int u, int father) {
	// printf("tarjan %d %d\n", u, father);
	++base, dfn[u] = low[u] = ++tim, ins[u] = 1, stk[++top] = u;
	for (int i = G1.hed[u]; i; i = G1.nxt[i]) {
		int v = G1.to[i];
		if (v != father) {
			if (!dfn[v]) {
				tarjan(v, u), low[u] = std::min(low[u], low[v]);
				if (low[v] >= dfn[u]) {
					G2.link(u, ++tot), ++val[tot]; int x;
					do {
						x = stk[top--], ins[x] = 0;
						G2.link(x, tot), ++val[tot];
					} while (x != v);
				}
			} else if (ins[v]) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
	}
}

void dfs(int u, int father) {
	// printf("dfs %d %d\n", u, father);
	if (u <= n) val[u] = -1, siz[u] = 1;
	int sum = 0;
	for (int i = G2.hed[u], v = G2.to[i]; i; i = G2.nxt[i], v = G2.to[i])
		if (v != father) {
			dfs(v, u);
			siz[u] += siz[v];
			sum += (ll)siz[v] * (base - siz[v]);
			// printf("%d %d => %d\n", u, val[u], (ll)val[u] * siz[v] * (base - siz[v]));
		}
	sum += (ll)(siz[u]) * (base - siz[u]);
	if (u <= n) sum += base - 1;
	ans += (ll)val[u] * sum;
	// printf("%d %d => %d\n", u, val[u], sum);
}

void main() {
	read(n), read(m);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		G1.link(u, v);
	}
	tot = n;
	G2.flag = true;
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) {
			base = 0;
			tarjan(i, 0);
			dfs(i, 0);
		}
	// for (int i = 1; i <= tot; i++) print(val[i], " \n"[i == tot]);
	// for (int i = 1; i <= tot; i++) print(siz[i], " \n"[i == tot]);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }