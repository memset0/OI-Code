// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 110, maxm = 20010;

int n, m, u, v, s, e, l, r, ans;
int pre[maxn], dis[maxn], q[maxn * maxn], inq[maxn], a[maxn][maxn];

int tot = 2, hed[maxn], nxt[maxm], val[maxm], to[maxm], cst[maxm];

inline void add_simple_edge(int u, int v, int w, int c) { nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] = c, hed[u] = tot++; }
inline void add_edge(int u, int v, int c) { add_simple_edge(u, v, 1, c), add_simple_edge(v, u, 0, -c); }

bool spfa1() {
	memset(pre, 0, sizeof(pre));
	memset(dis, 63, sizeof(dis));
	l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[u] + cst[i] < dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[++r] = v;
			}
	}
	return pre[e]; 
}

bool spfa2() {
	memset(pre, 0, sizeof(pre));
	memset(dis, -63, sizeof(dis));
	l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[u] + cst[i] > dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[++r] = v;
			}
	}
	return pre[e]; 
}

int main() {
	n = read(), s = (n << 1) + 1, e = s + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			add_edge(i, j + n, a[i][j]);
	for (int i = 1; i <= n; i++)
		add_edge(s, i, 0);
	for (int i = 1; i <= n; i++)
		add_edge(i + n, e, 0);
	while (spfa1()) {
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			ans += cst[i], val[i] -= 1, val[i ^ 1] += 1;
	}
	printf("%d\n", ans);
	ans = 0, tot = 2, memset(hed, 0, sizeof(hed));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			add_edge(i, j + n, a[i][j]);
	for (int i = 1; i <= n; i++)
		add_edge(s, i, 0);
	for (int i = 1; i <= n; i++)
		add_edge(i + n, e, 0);
	while (spfa2()) {
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			ans += cst[i], val[i] -= 1, val[i ^ 1] += 1;
	}
	printf("%d\n", ans);
	return 0;
}
