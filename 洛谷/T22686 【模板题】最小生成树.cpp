#include <bits/stdc++.h>
using namespace std;
const int maxn = 2510, maxm = 6210;
int n, m, fa[maxn];
struct Node {
	long long u, v, val;
} g[maxm];
bool cmp(Node x, Node y) {
	return x.val < y.val;
}
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	long long tx, ty, tz;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &tx, &ty, &tz);
		g[i] = {tx, ty, tz};
	}
	sort(g + 1, g + m + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= m; i++)
		if (find(g[i].u) != find(g[i].v)) {
			fa[find(g[i].u)] = find(g[i].v);
			ans += g[i].val;
		}
	printf("%lld\n", ans);
	return 0;
}
