#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int n, m, f[maxn];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		f[find(x)] = find(y);
	}
	for (int i = 1; i <= n; i++)
		cnt[find(i)]++;
	int maxn = 0, maxi;
	for (int i = 1;)
	return 0;
}
