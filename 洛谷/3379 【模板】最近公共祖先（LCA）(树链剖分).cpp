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

int n, m, s;
int 

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void dfs1(int u) {
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = i;
			dfs1(to[i]);
		}
}

void dfs2(int u, int toppoint) {
	id[u] = ++pos, 
}

int main() {
	
	n = read(), m = read(), s = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	
	dfs1(s);
	dfs2(s, s);
	
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		printf("%d\n", lca(u, v));
	}
	
	return 0;
}
