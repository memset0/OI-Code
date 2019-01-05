#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 410, maxm = 40010, inf = 1e9 + 10;
int n, m;
int u, v, t, j, s, e, en, flag, flow, max_flow;
int dep[maxn], gap[maxn], cur[maxn], pre[maxn];
int tot, hed[maxn], nxt[maxm << 1], to[maxm << 1], val[maxm << 1];

inline void add_simple_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;
}

inline void add_edge(int u, int v, int w) {
	// printf("ADD EDGE %d %d %d\n", u, v, w);
	add_simple_edge(u, v, w);
	add_simple_edge(v, u, 0);
}

int main() {
	memset(hed, -1, sizeof(hed));
	n = read(), m = read();
	s = n + m + 1, e = s + 1, en = e;
	for (int i = 1; i <= n; i++)
		add_edge(s, i, 1);
	for (int i = 1; i <= m; i++)
		add_edge(n + i, e, 1);
	for (int i = 1; i <= n; i++) {
		t = read();
		while (t--) {
			j = read();
			add_edge(i, j + n, 1);
		}
	}
	for (int i = 1; i <= en; i++)
		cur[i] = hed[i];
	u = s, pre[u] = -1, gap[0] = en;
	while (dep[s] < en) {
		// printf(">>> %d\n", u);
		flag = 0;
		for (int i = cur[u]; ~i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				cur[u] = i;
				pre[to[i]] = i;
				u = to[i];
				flag = 1;
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
			// printf("FIND ANS\n");
			flow = inf;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			max_flow += flow, u = s;
		}
	}
	printf("%d\n", max_flow);
	return 0;
}