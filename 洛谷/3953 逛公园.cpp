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

const int maxn = 100010, maxm = 200010;

int n, m, p, u, k, v, w, l, r, t;
int ans, tim, flag;
int dis[maxn], disn[maxn], q[maxn * 100], id[maxn], f[maxn][51], ind[maxn], ord[maxn];
bool inq[maxn];

struct graph {
	int tot, hed[maxn], nxt[maxm], to[maxm], val[maxm];
	inline void add_edge(int u, int v, int w) {
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
		hed[u] = tot++;
	}
} h, g, z;


bool cmp(int a, int b) {
	if (dis[a] != dis[b]) return dis[a] < dis[b];
	return ord[a] < ord[b];
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	
	t = read();
	while (t--) {
		z.tot = h.tot = g.tot = 2, ans = tim = flag = 0;
		memset(h.hed, 0, sizeof(h.hed));
		memset(g.hed, 0, sizeof(g.hed));
		memset(z.hed, 0, sizeof(g.hed));
		memset(dis, -1, sizeof(dis));
		memset(ind, 0, sizeof(dis));
		memset(disn, -1, sizeof(disn));
		memset(f, 0, sizeof(f));
		
		n = read(), m = read(), k = read(), p = read();
		for (int i = 1; i <= m; i++) {
			u = read(), v = read(), w = read();
			g.add_edge(u, v, w);
			h.add_edge(v, u, w);
			if (!w) {
				z.add_edge(u, v, 0);
				ind[v]++;
			}	
		}
		
		
		l = r = 1, q[1] = 1, dis[1] = 0, inq[1] = 1;
		while (l <= r) {
			u = q[l++], inq[u] = 0;
			for (int i = g.hed[u]; i; i = g.nxt[i]) {
				v = g.to[i];
				if (!~dis[v] || dis[v] > dis[u] + g.val[i]) {
					dis[v] = dis[u] + g.val[i];
					if (!inq[v]) {
						inq[v] = 1;
						q[++r] = v;
					}
				}
			}
		}
		l = r = 1, q[1] = n, disn[n] = 0, inq[n] = 1;
		while (l <= r) {
			u = q[l++], inq[u] = 0;
			for (int i = g.hed[u]; i; i = g.nxt[i]) {
				v = g.to[i];
				if (!~disn[v] || disn[v] > disn[u] + g.val[i]) {
					disn[v] = disn[u] + g.val[i];
					if (!inq[v]) {
						inq[v] = 1;
						q[++r] = v;
					}
				}
			}
		}
		
		l = 1, r = 0;
		for (int i = 1; i <= n; i++)
			if (!ind[i])
				q[++r] = i;
//		for (int i = 1; i <= n; i++)
//			printf("%d ", ind[i]);
//		puts("");
		while (l <= r) {
			u = q[l++], ord[u] = ++tim;
//			printf("%d : %d\n", u, ind[u]);
			for (int i = z.hed[u]; i; i = z.nxt[i]) {
				v = z.to[i];
//				printf("%d -> %d : %d %d\n", u, v, i, z.nxt[i]);
				if (ind[v]) {
					ind[v]--;
					if (!ind[v])
						q[++r] = v;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (ind[i] && dis[i] + disn[i] <= dis[n] + k) {
				printf("-1\n");
				flag = 1;
				break;
			}
//		for (int i = 1; i <= n; i++)
//			printf("%d ", ind[i]);
//		puts("");
		if (flag) continue;
		
//		for (int i = 1; i <= n; i++)
//			printf("%d ", dis[i]);
//		puts("");
		for (int i = 1; i <= n; i++)
			id[i] = i;
		sort(id + 1, id + n + 1, cmp);
		
		f[1][0] = 1;
		for (int q = 0; q <= k; q++)
			for (int i = 1; i <= n; i++) {
				u = id[i];
				if (!~dis[u]) continue;
				for (int j = h.hed[u]; j; j = h.nxt[j]) {
					v = h.to[j];
					if (!~dis[v]) continue;
					w = dis[v] + h.val[j] - dis[u];
//					printf("%d -> %d : %d\n", v, u, t);
					(f[u][q] += q >= w ? f[v][q - w] : 0) %= p;
				}
			}
		
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j <= k; j++)
//				printf("%d ", f[i][j]);
//			puts("");
//		}
		for (int i = 0; i <= k; i++)
			(ans += f[n][i]) %= p;
		printf("%d\n", ans);
		
	}
	
	return 0;
}
