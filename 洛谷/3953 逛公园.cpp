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

const int maxn = 100010, maxm = 200010;

int n, m, k, p, u, v, w, l, r, t;
int ans;
int f[maxn][51], dis[maxn], q[maxn * 100];
bool vis[maxn][51], inq[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

int dfs(int u, int p) {
	printf("%d %d %d %d\n", u, p, f[u][p], vis[u][p]);
	if (vis[u][p]) return -1;
	if (f[u][p]) return f[u][p];
	vis[u][p] = 1;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		int q = dis[u] + p + val[i] - dis[v];
		if (q <= k) {
			printf("%d %d => %d %d\n", u, p, v, q);
			int ret = dfs(v, q);
			f[u][p] += ret;
		}
	}
	return f[u][p];
	vis[u][p] = 0;
}

void spfa() {
	l = r = 1, q[1] = 1, dis[1] = 0, inq[1] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u]; i; i = nxt[i]) {
			v = to[i];
			if (!~dis[v] || dis[v] > dis[u] + val[i]) {
				dis[v] = dis[u] + val[i];
				if (!inq[v]) {
					inq[v] = 1;
					q[++r] = v;
				}
			}
		}
	}
}

int main() {
	freopen("INPUT", "r", stdin);
	
	t = read();
	while (t--) {
		tot = 2, ans = 0;
		memset(f, 0, sizeof(f));
		memset(hed, 0, sizeof(hed));
		memset(dis, -1, sizeof(dis));
		
		n = read(), m = read(), k = read(), p = read();
		for (int i = 1; i <= m; i++) {
			u = read(), v = read(), w = read();
			add_edge(u, v, w);
		}
		
		spfa();
		f[n][0] = 1;
		dfs(1, 0);
		for (int i = 0; i <= k; i++)
			ans += f[1][i];
		printf("%d\n", ans);
		
	}
	return 0;
}
