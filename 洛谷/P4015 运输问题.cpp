// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 510, maxe = 80410;
const int inf = 1e9;

int n, m, s, e, u, v, l, r, flow, ans;
int a[maxn], b[maxn], c[maxn][maxn];
int pre[maxn], dis[maxn], inq[maxn], q[maxn];

int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe], cst[maxe];
inline void add_simple_edge(int u, int v, int w, int c)
	{ nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] = c; hed[u] = tot++; }
inline void add_edge(int u, int v, int w, int c)
	{ add_simple_edge(u, v, w, c), add_simple_edge(v, u, 0, -c); } 

bool spfa1() {
	memset(pre, 0, sizeof(pre));
	memset(dis, 63, sizeof(dis));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			if (val[i] && dis[u] + cst[i] < dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[++r] = v;
			}
		}
	}
	return pre[e];
}

bool spfa2() {
	memset(pre, 0, sizeof(pre));
	memset(dis, -63, sizeof(dis));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			if (val[i] && dis[u] + cst[i] > dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[++r] = v;
			}
		}
	}
	return pre[e];
}

int main() {
	n = read(), m = read(), s = n + m + 1, e = s + 1;
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) b[i] = read();
	rep(i, 1, n) rep(j, 1, m) c[i][j] = read();
	rep(i, 1, n) add_edge(s, i, a[i], 0);
	rep(i, 1, m) add_edge(i + n, e, b[i], 0);
	rep(i, 1, n) rep(j, 1, m) add_edge(i, j + n, inf, c[i][j]);
	while (spfa1()) {
		flow = inf;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow, ans += flow * cst[i];
	}
	printf("%d\n", ans);
	for (int i = 2; i < tot; i += 2)
		val[i] += val[i ^ 1], val[i ^ 1] = 0;
	ans = 0;
	while (spfa2()) {
		flow = inf;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow, ans += flow * cst[i]; 
	}
	printf("%d\n", ans);
	return 0;
}
