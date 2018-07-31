#include <bits/stdc++.h>
using namespace std;
const int maxn = 2510, maxm = 6210;
int n, m, s, t, l, r, u, q[maxn * 10], dis[maxn];
bool inq[maxn];
struct Edge {
	int e, v;
};
vector < Edge > g[maxn];
int main() {
	memset(dis, 63, sizeof(dis));
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int ta, tb, tc;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ta, &tb, &tc);
		g[ta].push_back({tb, tc});
		g[tb].push_back({ta, tc});
	}
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = 0; i < g[u].size(); i++)
			if (dis[g[u][i].e] > dis[u] + g[u][i].v) {
				dis[g[u][i].e] = dis[u] + g[u][i].v;
				if (!inq[g[u][i].e]) {
					inq[g[u][i].e] = 1;
					q[++r] = g[u][i].e;
				}
			}
	}
	printf("%d\n", dis[t]);
	return 0;
}
