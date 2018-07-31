#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, m, fa[maxn];
int find(int x) {
	if (fa[x] == x) return fa[x];
	else return fa[x] = find(fa[x]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int x, y, z;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			fa[find(y)] = find(z);
		} else if (x == 2) {
			if (find(y) == find(z)) {
				puts("Y");
			} else {
				puts("N");
			}
		}
	}
	return 0;
}
