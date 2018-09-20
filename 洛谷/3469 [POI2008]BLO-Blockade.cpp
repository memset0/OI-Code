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

const int maxn = 100010, maxm = 1000010;

int n, m, u, v, pos;
int low[maxn], dfn[maxn];
ll ans[maxn], siz[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm];
inline void add_edge(int u, int v) { nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++; }

void tarjan(int u) {
	low[u] = dfn[u] = ++pos;
	siz[u] = 1;
	int cnt = 0; ll sum = 0; bool flag = false;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if (!dfn[v]) {
			tarjan(v);
			siz[u] += siz[v];
			low[u] = std::min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				cnt++, flag = true;
				ans[u] += siz[v] * (n - siz[v] - 1);
				sum += siz[v];
			}
		} else low[u] = std::min(low[u], dfn[v]);
	}
	if ((u != 1 && flag) || (u == 1 && cnt >= 2)) {
		ans[u] += ((n - 1) << 1) + sum * (n - sum - 1);
	} else ans[u] = (n - 1) << 1;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	tarjan(1);
	for (int i = 1; i <= n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
