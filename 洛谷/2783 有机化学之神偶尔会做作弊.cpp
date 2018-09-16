// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 10010, maxm = 50010;

int n, m, q, u, v;
int tim, pos, top;
int dfn[maxn], low[maxn], id[maxn], stk[maxn], f[maxn][20], dep[maxn];
bool ins[maxn];

int tot = 2, hed[maxn], nxt[maxm << 1], to[maxm << 1];

struct edge {
	int u, v;
	edge () {}
	edge (int a, int b) {
		u = a, v = b;
	}
} e[maxm];

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	stk[++top] = u, ins[u] = 1;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		if (!dfn[v]) {
//			printf("%d -> %d\n", u, v);	
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
//	for (int i = 1; i <= top; i++)
//		printf("%d ", stk[i]);
//	puts("");
	if (dfn[u] == low[u]) {
		++pos;
		while (top) {
			int v = stk[top--];
			id[v] = pos;
			if (u == v) break;
		}
	}
}

void dfs(int u) {
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != f[u][0] && !dep[v]) {
			f[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u] && f[v][i])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i] && f[u][i] && f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void print(int x) {
	if (x > 1) print(x >> 1);
	putchar((x & 1) + '0');
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		e[i] = edge(u, v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i, -1);

//	for (int i = 1; i <= n; i++)
//		siz[id[i]]++;
	tot = 2, memset(hed, 0, sizeof(hed));
	for (int i = 1; i <= m; i++) {
		u = id[e[i].u], v = id[e[i].v];
		if (u ^ v) {
			nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
			nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", low[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dfn[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", id[i]);
//	puts("");
	
	dep[1] = 1, dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= pos; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	
	q = read();
	for (int i = 1; i <= q; i++) {
		u = id[read()], v = id[read()];
		print(dep[u] + dep[v] - (dep[lca(u, v)] << 1) + 1);
		putchar('\n');
	}
	
	return 0;
}

/*
8 8
1 2 2 3 3 4
2 5 5 6 6 7 7 8 8 3
1
1 4
*/
