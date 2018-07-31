#include <bits/stdc++.h>
using namespace std;
const int maxn = 310, maxm = 50010;
struct Edge {
	int x, y, val;
} a[maxm];
int n, m, ans, f[maxn];
bool cmp(Edge x, Edge y) {
	return x.val < y.val;
}
int find(int &x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].val;
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++)
		if (find(a[i].x) != find(a[i].y)) {
			f[find(a[i].x)] = find(a[i].y);
			ans = a[i].val;
		}
	cout << n - 1 << " " << ans << endl;
	return 0;
}
