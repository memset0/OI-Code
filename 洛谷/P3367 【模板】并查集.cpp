//Union-Find Sets
#include <bits/stdc++.h> 
using namespace std;
const int maxn = 10010;
int n, m, fa[maxn];
int getFather(int n) {
	if (fa[n] == n) return n;
	return fa[n] = getFather(fa[n]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int k, a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &k, &a, &b);
		if (k == 1) {
			fa[getFather(b)] = getFather(a);
		}
		else {
			if (getFather(a) == getFather(b)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}