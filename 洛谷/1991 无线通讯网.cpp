#include <bits/stdc++.h> 
#define sqr(x) ((x)*(x))
using namespace std;
const int maxn = 510;
int n, m, p, q, f[maxn];
double ans;
struct Node {
	int x, y;
} a[maxn];
struct Edge {
	int a, b;
	double val;
} g[maxn * maxn];
inline int find(int &x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
inline bool cmp(Edge x, Edge y) {
	return x.val < y.val;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		for (int j = 1; j < i; j++)
			g[++p] = {j, i, sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y))};
	}
	sort(g + 1, g + p + 1, cmp);
	for (int i = 1; i <= p; i++) 
		if (find(g[i].a) != find(g[i].b)) {
			f[find(g[i].a)] = find(g[i].b);
			ans = g[i].val, ++q;
			if (q >= n - m) break;
		}
	printf("%.2lf\n", ans);
	return 0;
}
