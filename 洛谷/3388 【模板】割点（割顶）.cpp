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

const int maxn = 100010;
int n, m, u, v, pos, ans, dfn[maxn], low[maxn], cut[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void tarjan(int u, int root) {
	// printf("tarjan %d %d\n", u, root);
	dfn[u] = low[u] = ++pos;
	int child = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if (!dfn[v]) {
			tarjan(v, root);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u] && u != root)
				cut[u] = 1;
			child++;
		}
		low[u] = min(low[u], dfn[v]);
	}
	if (u == root && child >= 2)
		cut[u] = 1;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i, i);

	for (int i = 1; i <= n; i++)
		ans += cut[i];

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		if (cut[i])
			printf("%d ", i);
	puts("");

	return 0;
}