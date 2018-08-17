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

const int maxn = 1010;
int n, ans, points, fa[maxn], dep[maxn], vis[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs(int u) {
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = u;
			dep[to[i]] = dep[u] + 1;
			dfs(to[i]);
		}
}

int find() {
	int maxdep = -1;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && dep[i] > maxdep)
			maxdep = dep[i];
	for (int i = 1; i <= n; i++)
		if (!vis[i] && dep[i] == maxdep)
			return i;
	return 0;
}

void setup(int u) {
	if (!vis[u]) {
		vis[u] = 1;
		points--;
	}
	for (int i = hed[u]; i; i = nxt[i]) {
		if (!vis[to[i]]) {
			vis[to[i]] = 1;
			points--;
		}
		for (int j = hed[to[i]]; j; j = nxt[j])
			if (!vis[to[j]]) {
				vis[to[j]] = 1;
				points--;
			}
	}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 2; i <= n; i++)
		add_edge(i, read());

	fa[1] = 1, dep[1] = 1;
	dfs(1);
	points = n;

	while(points) {
		setup(fa[fa[find()]]);
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}