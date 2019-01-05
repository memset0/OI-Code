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

const int maxn = 5010, maxm = 100010;

int n, m, u, v, w, tim, top;
int dfn[maxn], low[maxn], ins[maxn], stk[maxn], ans[maxn], now[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm];

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
	if (low[u] == dfn[u]) {
		now[0] = 0;
		while (top) {
			int v = stk[top--];
			ins[v] = 0;
			now[++now[0]] = v;
			if (v == u) break;
		}
		sort(now + 1, now + now[0] + 1);
		if (now[0] > ans[0] || (now[0] == ans[0] && now[1] < ans[1])) {
			for (int i = 0; i <= now[0]; i++)
				ans[i] = now[i];
		}
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v);
		if (w == 2)
			add_edge(v, u);
	}
	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	
	printf("%d\n", ans[0]);
	for (int i = 1; i <= ans[0]; i++)
		printf("%d ", ans[i]);
	putchar('\n');
	
	return 0;
}