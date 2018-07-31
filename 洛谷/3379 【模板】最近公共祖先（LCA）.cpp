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

#define add_edge(u,v) ++tot,nxt[tot]=hed[u],to[tot]=v,hed[u]=tot;
const int maxn = 500010;
int n, m, s, u, v, dep[maxn], vis[maxn], f[maxn][20];
int tot, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct Edge {
	int to, flow;
	vector < Edge > ::iterator back;
};

void DFS(int u, int d) {
	dep[u] = d, vis[u] = 1;
	for (int i = hed[u]; i; i = nxt[i])
		if (!vis[to[i]]) {
			f[to[i]][0] = u;
			DFS(to[i], d + 1);
		}
}

int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
//	printf(">>> %d(%d) %d(%d)\n", u, dep[u], v, dep[v]);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u] && f[v][i])
			v = f[v][i];
	if (u == v) return u;
//	printf(">>> %d(%d) %d(%d)\n", u, dep[u], v, dep[v]);
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i] && f[u][i] && f[v][i])
			u = f[u][i], v = f[v][i];
//	printf(">>> %d(%d) %d(%d)\n", u, dep[u], v, dep[v]);
	return f[u][0];
}

int main() {
	freopen("INPUT", "r", stdin);
	n = read(), m = read(), s = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	DFS(s, 1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) 
			f[j][i] = f[f[j][i - 1]][i - 1];
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		printf("%d\n", LCA(u, v));
	}
	return 0;
}

