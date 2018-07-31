#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 310, maxm = 25010, inf = 1e9;
int n, m, u, v, s, e, en, flag, last, flow, ans, G[maxn][maxn], vis[maxn], dis[maxn], cur[maxn], pre[maxn], gap[maxn], dep[maxn];
int tot, hed[maxn], nxt[maxm], val[maxm], to[maxm];

void add_simple_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
	tot++;
}

void add_edge(int u, int v, int w) {
	add_simple_edge(u, v, w);
	add_simple_edge(v, u, 0);
}

void max_flow(void) {

	en = e;
	for (int i = 1; i <= en; i++)
		cur[i] = hed[i];
	u = s, pre[u] = -1, gap[0] = en;
	while (dep[s] < en) {
		flag = 0;
		for (int i = cur[u]; ~i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				flag = 1, cur[u] = i;
				pre[to[i]] = i, u = to[i];
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = en;
			for (int i = hed[u]; ~i; i = nxt[i])
				if (val[i] && dep[u] > dep[to[i]] + 1) {
					dep[u] = dep[to[i]] + 1;
					cur[u] = i;
				}
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}
		if (u == e) {
			flow = inf;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = flow < val[i] ? flow : val[i];
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			last = u;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				if (to[i] != e && to[i ^ 1] != s) {
					// printf("%d => %d | ", to[i ^ 1], to[i]);
					int first = to[i ^ 1], second = to[i];
					if (first > n) {
						first -= n;
						G[first][second] = 1;
						dis[second] = 1;
					} else {
						second -= n;
						G[second][first] = 0;
					}
					// printf("%d => %d (%d -> %d)\n", first, second, G[first][second] ^ 1, G[first][second]);
				}
			// cout << endl;
			ans += flow, u = s;
		}
	}
}

void get_way(int s) {
	printf("%d ", s);
	for (int u = s, flag = 1; flag;) {
		flag = 0;
		for (int i = 1; i <= n; i++)
			if (G[u][i] && !vis[i]) {
				flag = vis[i] = 1, u = i;
				printf("%d ", i);
			}
	}
	putchar('\n');
}

int main() {

	memset(hed, -1, sizeof(hed));

	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		add_edge(u + n, v, 1);
	}
	s = n << 1 | 1, e = s + 1;
	for (int i = 1; i <= n; i++)
		add_edge(s, i + n, 1), add_edge(i, e, 1);

	max_flow();

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << G[i][j];
	// 	cout << endl;
	// }

	for (int i = 1; i <= n; i++)
		if (!dis[i]) {
			vis[u = i] = flag = 1, printf("%d ", u);
			while (flag--) {
				for (int i = 1; i <= n; i++)
					if (G[u][i]) {
						flag = 1;
						u = i;
						printf("%d ", u);
						break;
					}
			}
			putchar('\n');
		}

	printf("%d\n", n - ans);

	return 0;
}