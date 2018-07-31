#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxm = 100010;
const int Move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, l, r, x, y, cnt, a[maxn][maxn], b[maxn][maxn], mem[maxm], pos[maxn][maxn];
struct Point {
	int x, y;
} q[maxn * maxn * 10 + 100], p[maxm];
char c, str[100];
int main() {
	cin >> n >> m;
	gets(str);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &c);
			a[i][j] = c - '0';
		}
		gets(str);
	}
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	for (int i = 1; i <= m; i++) {
		if (b[p[i].x][p[i].y]) {
			cout << mem[b[p[i].x][p[i].y]] << endl;
			continue;
		}
		else {
			l = r = 1, cnt = 0, q[r] = p[i];
			while (l <= r) {
				x = q[l].x, y = q[l++].y;
				if (x < 1 || y < 1 || x > n || y > n || pos[x][y] == i) continue;
				pos[x][y] = i, cnt++, b[x][y] = i;
				for (int j = 0; j < 4; j++) {
					if (a[x + Move[j][0]][y + Move[j][1]] != a[x][y]) {
						q[++r].x = x + Move[j][0], q[r].y = y + Move[j][1];
					}
				}
			}
//			for (int ii = 1; ii <= n; ii++) {
//				for (int jj = 1; jj <= n; jj++)
//					cout << pos[ii][jj];
//				puts("");
//			}
			cout << cnt << endl;
			mem[i] = cnt;
		}
	}
}
