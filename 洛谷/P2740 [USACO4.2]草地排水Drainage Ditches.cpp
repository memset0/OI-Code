#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 210, INF = 1e9;
int n, m, s, e, u, v, w;
int flow, ans, flag, pre[maxn], dep[maxn], gap[maxn], cur[maxn];
int tot = -1, hed[maxn], to[maxn << 1], nxt[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	++tot;
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
}

void print_array(string name, int *arr, int length) {
	cout << name << " ";
	for (int i = 0; i <= length; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

int main() {

	memset(hed, -1, sizeof(hed));

	m = read(), n = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}

	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];
	s = 1, e = n;
	u = s, pre[u] = -1, gap[0] = n;

	while (dep[s] < n) {

		// printf("u = %d\n", u);
		// print_array("dep", dep, n);
		// print_array("gap", gap, n);

		if (u == e) {
			flow = INF;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			// printf("ADD FLOW(%d)\n", flow);
			ans += flow, u = s;
		}

		flag = false;
		for (int i = cur[u]; ~i; i = nxt[i])
			if (val[i] && dep[u] == (dep[to[i]] + 1)) {
				pre[to[i]] = i;
				cur[u] = i;
				u = to[i];
				flag = true;
			}

		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = n;
			for (int i = hed[u]; ~i; i = nxt[i]) {
				// printf("%d => %d : %d\n", to[i ^ 1], to[i], val[i]);
				if (val[i] && dep[u] > (dep[to[i]] + 1)) {
					// printf("UPDATE\n");
					dep[u] = dep[to[i]] + 1;
					cur[u] = i;
				}
			}
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}	

	}

	printf("%d\n", ans);

	return 0;
}