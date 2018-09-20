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

const int maxn = 100010, maxe = 200010;

int n, m, u, v, l, r, opt;
int q[1000010], cnt[maxn];
bool inq[maxn], vis[maxn];
ll ans, dis[maxn];
int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe];

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
	printf("add edge %d %d %d\n", u, v, w);
}

void spfa(int s) {
	l = r = 0, q[0] = s, inq[s] = 1, cnt[s] = 1, dis[s] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0, vis[u] = 1;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[v] > dis[u] + val[i]) {
				dis[v] = dis[u] + val[i];
				if (!inq[v]) {
					if (++cnt[v] >= n) { puts("-1"); exit(0); }
					q[++r] =v, inq[v] = 1;
				}
			}
	}
}

int main() {
	memset(dis, 63, sizeof(dis));
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		opt = read(), u = read(), v = read();
		if (u == v && (opt == 2 || opt == 4)) { puts("-1"); return 0; }
		switch (opt) {
			case 1: add_edge(u, v, 0), add_edge(v, u, 0); break;
			case 2: add_edge(v, u, 1); break;
			case 3: add_edge(v, , 0); break;
			case 4: add_edge(u, v, 1); break;
			case 5: add_edge(v, u, 0); break;
		}
	}
	for (int i = 1; i <= n; i++)
		add_edge(i	);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			spfa(i);
	for (int i = 1; i <= n; i++)
		printf("%lld ", dis[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		ans += dis[i];
	printf("%lld\n", ans);
	return 0;
}
