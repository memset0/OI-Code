#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
const int maxm = 100010;
int n, l, r, a[maxn][maxn];
struct Str {
	int x, y;
} q[maxm], u, v;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	l = 1, r = 0;
	for (int i = 1; i <= n; i++) {
		q[++r].x = 1, q[r].y = i;
		q[++r].x = n, q[r].y = i;
		q[++r].x = i, q[r].y = 1;
		q[++r].x = i, q[r].y = n;
	}
	while (l <= r) {
		u = q[l++];
		if (u.x < 1 || u.y < 1 || u.x > n || u.y > n) continue;
		if (!a[u.x][u.y]) {
			a[u.x][u.y] = -1;
			q[++r].x = u.x + 1, q[r].y = u.y;
			q[++r].x = u.x - 1, q[r].y = u.y;
			q[++r].x = u.x, q[r].y = u.y + 1;
			q[++r].x = u.x, q[r].y = u.y - 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (a[i][j] == 0) printf("2 ");
			else if (a[i][j] == -1) printf("0 ");
			else printf("1 ");
		puts("");
	}
	return 0;
}
