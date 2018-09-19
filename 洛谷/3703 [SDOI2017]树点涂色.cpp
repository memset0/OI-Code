// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;

int n, m;

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = siz[v];
		}
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
		

	return 0;
}
