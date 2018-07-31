#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 210, maxm = 80010, INF = 1e9;
int n, m, x, y, u, s, e, flag, minn, flow, ans, dep[maxn], used[maxn], gap[maxn], pre[maxn], cur[maxn], way[maxn][3];
int tot = -1, hed[maxn], nxt[maxm], to[maxm], val[maxm];
void add_edge(int u, int v, int w) {
	++tot;
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
}
int main() {
	// freopen("INPUT", "r", stdin);
	memset(hed, -1, sizeof(hed));
	// m = read(), n = read(), m -= n;
	n = read(), m = read() - n;
	for (int i = 1; i <= n; i++)
		add_edge(1, i + 1, 1), add_edge(i + 1, 1, 0);
	for (int i = 1; i <= m; i++)
		add_edge(n + i + 1, n + m + 2, 1), add_edge(n + m + 2, n + i + 1, 0);
	while (((x = read()) != -1) && ((y = read()) != -1))
		add_edge(x + 1, y + 1, 1), add_edge(y + 1, x + 1, 0);
	// while (scanf("%d%d", &x, &y) != EOF)
	// 	add_edge(x + 1, y + 1, 300), add_edge(y + 1, x + 1, 0);

	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];
	n = n + m + 2, s = 1, e = n;
	u = 1, pre[u] = -1, gap[0] = n;
	while (dep[s] < n) {
		// printf("u = %d\n", u);
		if (u == e) {
			// printf("FIND A ANSWER\n");
			flow = INF;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				if (val[i] < flow) flow = val[i];
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]]) {
				// cout << to[i] << " ";
				if (to[i] != s && to[i] != e && !used[to[i]])
					way[ans][++way[ans][0]] = to[i], used[to[i]] = 1;
			}
			// cout << way[ans][0] << endl;
			ans += flow, u = s;
		} else {
			flag = false;
			// printf("TRY TO FIND A WAY\n");
			for (int i = cur[u]; ~i; i = nxt[i])
				if (val[i] && dep[u] == dep[to[i]] + 1) {
					// printf("FIND A WAY OUT\n");
					cur[u] = i;
					pre[to[i]] = i;
					u = to[i];
					flag = true;
					break;
				}
			if (!flag) {
				// printf("REFRESH THE DEPTH\n");
				minn = n;
				for (int i = hed[u]; ~i; i = nxt[i])
					if (val[i] && dep[to[i]] < minn) {
						cur[u] = i;
						minn = dep[to[i]];
					}
				if (!--gap[dep[u]]) break;
				++gap[dep[u] = ++minn];
				if (u != s) u = to[pre[u] ^ 1];
			}
		}
	}
	if (!ans) {
		printf("No Solution!\n");
		return 0;
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++)
		printf("%d %d\n", way[i][2] - 1, way[i][1] - 1);
	// printf("s = %d, e = %d\n", s, e);
	return 0;
}