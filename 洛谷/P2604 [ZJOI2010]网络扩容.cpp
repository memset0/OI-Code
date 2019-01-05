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

const int maxn = 1010, maxm = 20010, inf = 1e9;

int n, m, k;
int l, r, u, s, e, flow, flag, cost, max_flow, min_cost;
int dis[maxn], pre[maxn], dep[maxn], gap[maxn], inq[maxn], q[maxn], cur[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm], cst[maxm];

struct edge {
	int u, v, c, w;
} g[5010];

void add_edge(int u, int v, int w, int c) {
	// printf("add edge[%d]: %d %d %d %d\n", tot, u, v, w, c);
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	cst[tot] = c;
	hed[u] = tot++;
}

int isap() {
	int ans = 0;

	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];
	u = s, gap[0] = n;
	while (dep[u] < n) {

		// printf(">>> %d %d\n", u, flag);
		flag = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				u = to[i];
				pre[to[i]] = i;
				flag = 1;
				break;
			}

		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = n;
			for (int i = hed[u]; i; i = nxt[i])
				if (val[i] && dep[u] > dep[to[i]] + 1) {
					dep[u] = dep[to[i]] + 1;
					cur[u] = i;
				}
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}

		if (u == e) {
			flow = inf;
			for (int i = pre[u]; i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			u = s, ans += flow;
		}
	}
	return ans;
}

int spfa() {
	memset(dis, -1, sizeof(dis));
	memset(pre, 0, sizeof(pre));

	u = s;

	l = r = 1, q[1] = u, inq[u] = 1, dis[u] = 0;
	while (l <= r) {
		u = q[(l++) % n], inq[u] = 0;
		// cout << u << endl;
		// for (int i = hed[u]; i; i = nxt[i])
		// 	printf("[%d] %d %d %d\n", i, val[i], to[i], dis[to[i]]);
		for (int i = hed[u]; i; i = nxt[i])
			if (val[i] && (dis[to[i]] == -1 || dis[u] + cst[i] < dis[to[i]])) {
				dis[to[i]] = dis[u] + cst[i];
				pre[to[i]] = i;
				if (!inq[to[i]]) {
					inq[to[i]] = 1;
					q[(++r) % n] = to[i];
				}
			}
	}

	return pre[e];

}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		g[i].u = read();
		g[i].v = read();
		g[i].c = read();
		g[i].w = read();
	}

	for (int i = 1; i <= m; i++) {
		add_edge(g[i].u, g[i].v, g[i].c, 0);
		add_edge(g[i].v, g[i].u, 0, 0);
	}	

	s = 1, e = n;
	max_flow = isap();

	memset(hed, 0, sizeof(hed));
	tot = 2;

	for (int i = 1; i <= m; i++) {
		add_edge(g[i].u, g[i].v, g[i].c, 0);
		add_edge(g[i].v, g[i].u, 0, 0);
		add_edge(g[i].u, g[i].v, inf, g[i].w);
		add_edge(g[i].v, g[i].u, 0, -g[i].w);
	}
	add_edge(n, n + 1, max_flow + k, 0);
	add_edge(n + 1, n, 0, 0);
	n = n + 1;
	s = 1, e = n;

	while (spfa()) {
		// printf("find answer\n");
		flow = inf, cost = 0;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = min(val[i], flow);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			cost += flow * cst[i];
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow;
		// printf(">>> %d %d\n", flow, cost);
		min_cost += cost;
	}

	printf("%d %d\n", max_flow, min_cost);

	return 0;
}