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

const int maxn = 1010, maxe = 20010;

int n, m1, m2, l, r, u, a, b, c, ans;
int inq[maxn], q[maxn * maxn], cnt[maxn], dis[maxn], vis[maxn];
int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void spfa(int s) {
	l = r = 1, q[1] = s, inq[s] = cnt[s] = 1, dis[s] = 0;
	while (l <= r) {
//		printf("%d\n", u);
		u = q[l++], inq[u] = 0, vis[u] = 1;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[v] > dis[u] + val[i]) {
//				printf("%d -> %d : %d\n", u, v, val[i]);
				dis[v] = dis[u] + val[i];
				if (!inq[v]) {
					if (++cnt[v] >= n) { puts("-1"); exit(0); }
					q[++r] = v;
				}
			}
	}
}

int main() {
	memset(dis, 63, sizeof(dis));

	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= n; i++)
		add_edge(0, i, 0);
	for (int i = 1; i <= m1; i++) {
		a = read(), b = read(), c = read();
		if (a > b) std::swap(a, b);
		add_edge(a, b, c);
	}
	for (int i = 1; i <= m2; i++) {
		a = read(), b = read(), c = read();
		if (a > b) std::swap(a, b);
		add_edge(b, a, -c);
	}
	spfa(0);
	memset(dis, 63, sizeof(dis));
	spfa(1);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dis[i]);
//	puts("");
	ans = dis[n];
	if (ans ^ dis[0]) printf("%d\n", ans);
	else puts("-2");
	return 0;
}
/*
d[u] + w(u, v) >= d[v]
d[u] - d[v] >= -w(u, v)
d[v] - d[u] <= w(u, v)

d[b] - d[a] <= v;
*/