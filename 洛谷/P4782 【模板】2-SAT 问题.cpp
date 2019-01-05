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

const int maxn = 4000010;

int n, m, u, v, w1, w2, tim, pos, top, tot = 2;
typedef int arr[maxn];
arr dfn, low, ins, stk, col, hed, nxt, to;

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v;
	hed[u] = tot++;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	ins[u] = 1, stk[++top] = u;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++pos;
		while (top) {
			int v = stk[top--];
			ins[v] = 0;
			col[v] = pos;
			if (u == v) break;
		}
	}
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), w1 = read();
		v = read(), w2 = read();
		add_edge(w1 ? u + n : u, w2 ? v : v + n);
		add_edge(w2 ? v + n : v, w1 ? u : u + n);
	}
	for (int i = 1; i <= (n << 1); i++)
		if (!dfn[i])
			tarjan(i);
//	for (int i = 1; i <= (n << 1); i++)
//		printf("%d ", col[i]);
//	puts("");
	for (int i = 1; i <= n; i++)
		if (col[i] == col[i + n]) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
	printf("POSSIBLE\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", col[i] < col[i + n]);
	puts("");

	return 0;
}