#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxm = 100010;
int n, m, ans, f[maxn], mrk;
struct Edge {
	int s, e, t;
} a[maxm];
bool cmp(Edge x, Edge y) {
	return x.t <= y.t;
}
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].t);
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++)
		if (find(a[i].s) != find(a[i].e)) {
			f[find(a[i].s)] = find(a[i].e);
			ans = a[i].t;
		}
	mrk = find(1);
	for (int i = 2; i <= n; i++)
		if (mrk != find(i)) {
			ans = -1;
			break;
		}
	printf("%d\n", ans);
	return 0;
}
