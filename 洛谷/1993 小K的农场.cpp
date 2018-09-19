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

const int maxn = 10010, maxe = 30010;

int n, m, u, a, b, c, l, r, opt;
int dis[maxn], q[maxn], inq[maxn], cnt[maxn];
int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
//	printf("%d -> %d : %d\n", u, v, w);
}

bool spfa() {
	memset(dis, 63, sizeof(dis));
//	printf("%d\n", dis[0]);
	l = r = q[0] = dis[0] = 0, inq[0] = cnt[0] = 1;
	while (l <= r) {
		u = q[(l++) % (n + 1)], inq[u] = 0;
//		printf("%d %d (%d %d)\n", u, dis[u], l, r);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[u] + val[i] < dis[v]) {
				dis[v] = dis[u] + val[i];
				if (!inq[v]) {
					if (++cnt[v] > 2) return true;
					q[(++r) % (n + 1)] = v, inq[v] = 1;
				}
			}
	}
	return false;
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		add_edge(0, i, 0);
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			a = read(), b = read(), c = read();
			add_edge(b, a, -c);
		} else if (opt == 2) {
			a = read(), b = read(), c = read();
			add_edge(a, b, c);
		} else {
			a = read(), b = read();
			add_edge(a, b, 0);
			add_edge(b, a, 0);
		}
	}
	printf("%s", spfa() ? "No" : "Yes");
	return 0;
}

/*
d[u] + w(u, v) >= d[v]
d[u] - d[v] >= -w(u, v)
d[v] - d[u] <= w(u, v)

v[a] - v[b] >= c
v[a] - v[b] <= c
*/
