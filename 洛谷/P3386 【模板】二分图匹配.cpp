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

const int maxn = 2010, maxe = 2004010;
int n, m, u, v, s, e, en, flag, flow, ans;
int cur[maxn], pre[maxn], dep[maxn], gap[maxn];
int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe];

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = 1, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, hed[v] = tot++;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read(), e = read();
	for (int i = 1; i <= e; i++) {
		u = read(), v = read();
		if (v <= m)
			add_edge(u, n + v);
	}
	s = n + m + 1, e = n + m + 2;
	for (int i = 1; i <= n; i++)
		add_edge(s, i);
	for (int i = 1; i <= m; i++)
		add_edge(n + i, e);

	for (int i = 1; i <= n; i++) 
		cur[i] = hed[i];
	u = s, pre[u] = -1, gap[0] = e;
	while (dep[s] < e) {
//		printf(">>> %d\n", u);
		flag = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				flag = 1, u = to[i], pre[u] = i;
				break;
			}
		if (!flag) {
//			printf("refresh\n");
			if (!--gap[dep[u]]) break;
			dep[u] = e;
			for (int i = hed[u]; i; i = nxt[i])
				if (val[i] && dep[to[i]] + 1 < dep[u]) {
					dep[u] = dep[to[i]] + 1;
					cur[u] = i;
				}
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}
		if (u == e) {
//			printf("find ans\n");
			flow = n;
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			ans += flow, u = s; 
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
