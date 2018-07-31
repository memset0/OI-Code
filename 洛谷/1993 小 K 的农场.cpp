#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, m;
struct Node {
	int e, v;
};
vector < Node > g[maxn];
void link(int x, int y, int z) {
	g[x].push_back({y, z});
//	printf("%d -> %d : %d\n", x, y, z);
}
int q[maxn * 1000], dis[maxn], inq[maxn], cnt[maxn];

int spfa() {
	memset(dis, 63, sizeof(dis));
	int l, r, u;
	l = r = 1;
//	dis[1] = 0;
//	q[r] = 1, inq[1] = 1;
	dis[0] = 0;
	q[r] = 0, inq[0] = 1;
	while (l <= r) {
		if (r >= 1000000)  return -1;
		u = q[l++], inq[u] = 0;
		for (int i = 0; i < g[u].size(); i++)
			if (dis[g[u][i].e] > dis[u] + g[u][i].v) {
				dis[g[u][i].e] = dis[u] + g[u][i].v;
				if (!inq[g[u][i].e]) {
					inq[g[u][i].e] = 1;
					cnt[g[u][i].e] ++;
					q[++r] = g[u][i].e;
					if (cnt[g[u][i].e] == n) return -1;
				}
			}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dis[i]);
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	int x, y, z;
	for (int i = 1; i <= n; i++) {
		link(0, i, 0);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		if (x == 1) {
			// a - b <= c
			scanf("%d%d%d", &x, &y, &z);
			link(x, y, z);
		} else if (x == 2) {
			// a - b >= c => b - a <= -c
			scanf("%d%d%d", &x, &y, &z);
			link(y, x, -z);
		} else {
			// a == b => a - b <= 0 && b - a <= 0
			scanf("%d%d", &x, &y);
			link(x, y, 0);
			link(y, x, 0);
		}
	}
	int ans = spfa();
	if (ans == -1) printf("No\n");
	else printf("Yes\n");
}
