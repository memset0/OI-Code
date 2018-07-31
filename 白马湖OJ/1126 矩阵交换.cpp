#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110;
int n, m, k, t, x, y, a[maxn][maxn];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)	
			scanf("%d", &a[i][j]);
	scanf("%d", &k);
	while (k--)	{
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			for (int i = 1; i <= m; i++)
				swap(a[x][i], a[y][i]);
		}
		else {
			for (int i = 1; i <= n; i++)
				swap(a[i][x], a[i][y]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}

