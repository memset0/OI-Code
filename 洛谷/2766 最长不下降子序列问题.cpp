#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 510, maxen = 1010, maxem = 60010, inf = 1e9;
int n, ans, a[maxn], f[maxn];
int s, e, u, en, flag, flow, max_flow, gap[maxen], dep[maxen], cur[maxen], pre[maxen];
int tot, hed[maxen], nxt[maxem], to[maxem], val[maxem];

inline void add_simple_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
	tot++;
}

inline void add_edge(int u, int v, int w) {
	// printf("ADD EDGE %d -> %d (%d)\n", u, v, w);
	add_simple_edge(u, v, w);
	add_simple_edge(v, u, 0);
}

void SAP(void) {
	// printf("TOT = %d\n", tot);
	memset(gap, 0, sizeof(gap));
	memset(dep, 0, sizeof(dep));
	memset(pre, 0, sizeof(pre));
	if ((ans == 1 || ans == 2 && n == 2) && max_flow) {
		printf("%d\n", max_flow);
		return;
	}
	max_flow = 0;
	s = n * 2 + 1, e = n * 2 + 2, en = n * 2 + 2;
	for (int i = 1; i <= en; i++)
		cur[i] = hed[i];
	u = s, pre[u] = -1, gap[0] = en;
	while (dep[s] < en) {
		flag = 0;
		for (int &i = cur[u]; ~i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				pre[to[i]] = i;
				u = to[i];
				flag = 1;
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = en;
			for (int i = hed[u]; ~i; i = nxt[i])
				if (val[i] && dep[to[i]] + 1 < dep[u]) {
					dep[u] = dep[to[i]] + 1;
					cur[u] = i;
				}
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}
		if (u == e) {
			flow = inf;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			u = s, max_flow += flow;
		}
	}
	printf("%d\n", max_flow);
}

int main() {

	// freopen("INPUT", "r", stdin);
	memset(hed, -1, sizeof(hed));

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[i] >= a[j] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
		ans = max(f[i], ans);
	}
	printf("%d\n", ans);

	for (int i = 1; i <= n; i++) {
		add_edge(i, n + i, 1);
		if (f[i] == 1) add_edge(n * 2 + 1, i, 1);
		if (f[i] == ans) add_edge(n + i, n * 2 + 2, 1);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[i] >= a[j] && f[i] == f[j] + 1)
				add_edge(n + j, i, 1);
	SAP();

	tot = 0;
	memset(hed, -1, sizeof(hed));
	for (int i = 1; i <= n; i++) {
		add_edge(i, n + i, ((i == 1 || i == n) ? inf : 1));
		if (f[i] == 1) add_edge(n * 2 + 1, i, ((i == 1 || i == n) ? inf : 1));
		if (f[i] == ans) add_edge(n + i, n * 2 + 2, ((i == 1 || i == n) ? inf : 1));
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[i] >= a[j] && f[i] == f[j] + 1)
				add_edge(n + j, i, 1);
	SAP();

	return 0;
}