#include <bits/stdc++.h>
using namespace std;
bool get_enter = 0;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (c == '\r' || c == '\n') get_enter = 1;
	if (m) return -x; else return x;
}
const int maxn = 110, maxm = 5010, inf = 1e9;
int n, m, x, full, sum, pro[maxn], cst[maxn], tmp[maxm];
int en, flow, ans, flag, s, e, u, dis[maxn], pre[maxn], cur[maxn], gap[maxn], dep[maxn];
int tot = -1, hed[maxn], used[maxm], nxt[maxm], to[maxm], val[maxm], ori[maxm];
void add_simple_edge(int u, int v, int w) {
	++tot;
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	ori[tot] = w;
	hed[u] = tot;
}
void add_edge(int u, int v, int w) {
	// printf("%d => %d : %d\n", u, v, w);
	add_simple_edge(u, v, w);
	add_simple_edge(v, u, 0);
}
int SAP(void) {
	memset(dep, 0, sizeof(dep));
	memset(gap, 0, sizeof(gap));
	memset(pre, 0, sizeof(pre));
	memset(used, 0, sizeof(used));
	int ans = 0;
	u = s, gap[0] = en, pre[u] = -1;
	for (int i = 1; i <= en; i++)
		cur[i] = hed[i];
	while (dep[u] < en) {
		// cout << u << endl;
		if (u == e) {
			flow = inf;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i] - used[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				used[i] += flow, used[i ^ 1] -= flow;
			// printf("flow = %d\n", flow);
			// for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
			// 	dis[to[i]] = 1;
			ans += flow, u = s;
		}
		flag = false;
		for (int i = cur[u]; ~i; i = nxt[i])
			if ((val[i] - used[i]) && dep[u] == dep[to[i]] + 1) {
				cur[u] = i;
				flag = true;
				pre[to[i]] = i;
				u = to[i];
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = en;
			for (int i = hed[u]; ~i; i = nxt[i])
				if ((val[i] - used[i]) && dep[to[i]] < dep[u]) {
					cur[u] = i;
					dep[u] = dep[to[i]];
				}
			++gap[++dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}
	}
	// printf("ans = %d\n", ans);
	return ans;
}
int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("2762.out", "w", stdout);
	memset(hed, -1, sizeof(hed));
	m = read(), n = read();
	for (int i = 1; i <= m; i++) {
		add_edge(n + m + 1, i, pro[i] = read());
		ans += pro[i];
		get_enter = 0;
		while (!get_enter)
			x = read(), add_edge(i, m + x, inf);
	}
	s = n + m + 1, e = en = n + m + 2;
	for (int i = 1; i <= n; i++)
		add_edge(m + i, n + m + 2, cst[i] = read());
	full = SAP();
	ans -= full;
	for (int i = m + 1; i <= m + n; i++) {
		for (int j = hed[i]; ~j; j = nxt[j])
			sum += val[j], swap(tmp[j], val[j]);
		int ret = SAP();
		// printf("ret=%d sum=%d full=%d\n", ret, sum, full);
		if (sum == (full - ret)) {
			dis[i] = 1;
		}
		for (int j = hed[i]; ~j; j = nxt[j])
			swap(tmp[j], val[j]), sum -= val[j];
	}
	for (int i = 1; i <= m; i++) {
		flag = 1;
		for (int j = hed[i]; ~j; j = nxt[j])
			if (to[j] != s && to[j] != e && !dis[to[j]])
				flag = 0;
		dis[i] = flag;
	}
	for (int i = 1; i <= m; i++)
		if (dis[i]) printf("%d ", i);
	putchar('\n');
	for (int i = 1; i <= n; i++)
		if (dis[i + m]) printf("%d ", i);
	putchar('\n');
	printf("%d\n", ans);
	return 0;
}