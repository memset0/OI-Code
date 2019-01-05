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

const int maxn = 2010, maxm = 6010;

int T, n, m, l, r, u, v, w, ans;
int q[maxn], dis[maxm], cnt[maxn], inq[maxn], vis[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

bool spfa(int s) {
	memset(dis, 63, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	memset(inq, 0, sizeof(inq));
	l = r = 0, q[0] = s, cnt[s] = inq[s] = 1, dis[s] = 0, vis[s] = 1;
	while (l <= r) {
//		printf("%d %d %d %d %d \n", u, l, r, cnt[u], n);
		u = q[(l++) % n], inq[u] = 0, vis[v] = 1;
		for (int i = hed[u]; i; i = nxt[i]) {
			v = to[i];
			if (dis[u] + val[i] < dis[v]) {
				dis[v] = dis[u] + val[i];
//				printf("%d -> %d\n", u, v);
				if (!inq[v]) {
					inq[v] = 1;
					if (++cnt[v] >= n) {
						return true;
					}
					q[(++r) % n] = v;
				} 
			} 
		} 
	}
	return false;
}

int main() {
//	freopen("INPUT", "r", stdin);
	T = read();
	while (T--) {
		tot = 2;
		memset(hed, 0, sizeof(hed));
		memset(vis, 0, sizeof(vis));
		n = read(), m = read();
		for (int i = 1; i <= m; i++) {
			u = read(), v = read(), w = read();
			if (w >= 0) {
				add_edge(u, v, w);
				add_edge(v, u, w);
			} else {
				add_edge(u, v, w);
			}
		}
//		ans = false;
//		for (int i = 1; i <= n; i++)
//			if (!vis[i])
//				ans |= spfa(i);
		ans = spfa(1);
		printf("%s\n", ans ? "YE5" : "N0");
	}
	return 0;
}
