#include <bits/stdc++.h> 
using namespace std;

const int maxn = 1510, mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, l, r, sx, sy, a[maxn][maxn], f[maxn][maxn];
char ch;
struct Point {
	int x, y;
} u, v, q[maxn * maxn];
int main() {
	while (scanf("%d%d\n", &n, &m) != EOF) {
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ch = getchar();
				if (ch == 'S') sx = i, sy = j, a[i][j] = 0;
				else if (ch == '.') a[i][j] = 0;
				else if (ch == '#') a[i][j] = 1;
			}
			getchar();
		}
		l = r = 1, q[1].x = sx, q[1].y = sy;
		while (l <= r) {
			u = q[l++];
			for (int i = 0; i < 4; i++) {
				v.x = u.x + mov[i][0];
				v.y = u.y + mov[i][1];
				if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
				if (a[v.x][v.y] || f[v.x][v.y]) continue;
				f[v.x][v.y] = 1;
				q[++r] = v;
			}
		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++)
//				cout << f[i][j];
//			cout << endl;
//		}
		bool mrk = false;
		for (int i = 1; i <= n && !mrk; i++)
			if (f[i][1] && f[i][1] == f[i][m])
				mrk = true;
		for (int i = 1; i <= m && !mrk; i++)
			if (f[1][i] && f[1][i] == f[n][i])
				mrk = true;
		if (mrk == true) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
