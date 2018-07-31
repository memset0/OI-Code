#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, t, a[maxn];
struct Edge {
	int u, v, val;
} g[maxn * maxn];

bool cmp(Edge a, Edge b) {
	return a.val > b.val;
}

int fa[maxn];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
//	freopen("superbull.in", "r", stdin);
//	freopen("superbull.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j < i; j++) {
			g[++t] = {j, i, a[i] ^ a[j]};
		}
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	
	sort(g + 1, g + t + 1, cmp);
//	for (int i = 1; i <= t; i++)
//		printf("%d %d %d\n", g[i].u, g[i].v, g[i].val);
	
	long long ans = 0;
	for (int i = 1; i <= t; i++)
		if (find(g[i].u) != find(g[i].v)) {
			fa[find(g[i].u)] = find(g[i].v);
			ans += g[i].val;
		}
	printf("%lld\n", ans);
	
	return 0;
}
	
