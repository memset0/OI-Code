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
ll readll() {
	ll x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 110, maxm = 10010;
const ll INF = 2e19;
int n, m, s, e, u, v, minn, flag, cur[maxn], dep[maxn], gap[maxn], pre[maxn];
int tot = -1, hed[maxn], to[maxm], nxt[maxm];
ll flow, ans, w, val[maxm];
void add_edge(int u, int v, int w) {
	tot++;
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
}
int main() {
	// freopen("INPUT", "r", stdin);
	memset(hed, -1, sizeof(hed));
	n = read(), m = read(), s = read(), e = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = readll();
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}
	for (int i = 1; i <= n; i++)
		cur[i] = hed[i];
	u = s, gap[0] = n, pre[u] = -1;
	while (dep[s] < n) {
		if (u == e) {
			flow = INF;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			ans += flow, u = s;
			continue;
		}
		flag = false;
		for (int i = cur[u]; ~i; i = nxt[i]) {
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				cur[u] = i;
				pre[to[i]] = i;
				u = to[i];
				flag = true;
				break;
			}
		}
		if (flag) continue;
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
	printf("%lld\n", ans);
	return 0;
}