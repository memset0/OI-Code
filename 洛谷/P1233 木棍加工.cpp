#include <bits/stdc++.h> 
using namespace std;
const int maxn = 5010;
struct Node {
	int w, l;
} a[maxn];
bool cmp(Node x, Node y) {
	if (x.w == y.w) return x.l < y.l;
	return x.w < y.w;
}
int f[maxn];
int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].w >> a[i].l;
	sort(a + 1, a + n + 1, cmp);
	int maxx, maxi;
	for (int i = 1; i <= n; i++) {
		maxx = maxi = 0;
		for (int j = 1; j <= m; j++) 
			if (f[j] > maxx && a[i].l >= f[j]) {
				maxx = f[j];
				maxi = j;
			}
		if (maxi) f[maxi] = a[i].l;
		else f[++m] = a[i].l;
	}
	cout << m << endl;
	return 0;
}