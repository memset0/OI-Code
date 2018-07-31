#include <bits/stdc++.h>
using namespace std;
const int maxn = 160;
struct farm {
	int x, y;
} a[maxn];
int n, tmp;
double g[maxn][maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &tmp);
			g[i][j] = tmp * sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y- a[j].y));
		}
	
	return 0;
}
