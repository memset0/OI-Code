#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, maxm = 500010;
int n, m, t[maxn];
vector < int > g[maxn];
int main() {
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int maxn = 0, maxi;
	for (int i = 1; i <= n; i++) 
		if (g[i].size() > maxn) {
			maxn = g[i].size();
			maxi = i;
		}
	int l = g[maxi].size();
	for (int i = 0; i < l; i++)
		t[i] = g[maxi][i];
	sort(t, t + l);
	for (int i = 0; i < l; i++)
		printf("%d ", t[i]);
	return 0;
}
