#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 160, maxm = 280, maxen = 430, maxem = 84000, inf = 1e9;
int n, m, a[maxn], b[maxm];
int u, en, s, e, sum, flow, flag, max_flow, dep[maxen], gap[maxen], cur[maxen], pre[maxen];
int tot, hed[maxen], nxt[maxem], to[maxem], val[maxem];

inline void add_simple_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
	tot++;
}
inline void add_edge(int u, int v, int w) {
	add_simple_edge(u, v, w);
	add_simple_edge(v, u, 0);
}

int main() {

	// freopen("INPUT", "r", stdin);
	memset(hed, -1, sizeof(hed));

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		b[i] = read();

	for (int i = 1; i <= n; i++)
		sum += a[i];
	for (int i = 1; i <= n; i++)
		add_edge(n + m + 1, i, a[i]);
	for (int i = 1; i <= m; i++)
		add_edge(n + i, n + m + 2, b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			add_edge(i, n + j, 1);

	s = n + m + 1, e = n + m + 2, en = n + m + 2;
	u = s, pre[u] = -1, gap[0] = en;
	for (int i = 1; i <= n + m + 2; i++)
		cur[i] = hed[i];

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
					break;
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
			max_flow += flow;
			u = s;
		}
	}

	if (max_flow < sum) {
		printf("0\n");
	} else {
		printf("1\n");
		for (int i = 1; i <= n; i++) {
			for (int j = hed[i]; ~j; j = nxt[j])
				if (to[j] != n + m + 1 && !val[j])
					printf("%d ", to[j] - n);
			putchar('\n');
		}
	}

	return 0;
}