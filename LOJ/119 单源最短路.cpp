#include <bits/stdc++.h>
using namespace std;
const int maxn = 2510;
int n, m, s, t, u, l, r, t1, t2, t3, a[maxn], dis[maxn], q[maxn * 1000], inq[maxn];
struct Edge {
	int e, v;
};
vector < Edge > G[maxn];
int main() {
	memset(dis, 63, sizeof(dis));
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &t1, &t2, &t3);
		G[t1].push_back({t2, t3});
		G[t2].push_back({t1, t3});
	}
	l = r = inq[s] = 1, dis[s] = 0, q[1] = s;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = 0; i < G[u].size(); i++)
			if (dis[G[u][i].e] > dis[u] + G[u][i].v) {
				dis[G[u][i].e] = dis[u] + G[u][i].v;
				if (!inq[G[u][i].e]) 
					inq[G[u][i].e] = 1, q[++r] = G[u][i].e; 
			} 
	}
	printf("%d\n", dis[t]);
	return 0;
} 
