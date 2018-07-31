#include <bits/stdc++.h>
using namespace std;
const int maxn = 450;
const int maxl = maxn * maxn * 50;
const int mov[8][2] {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};
int n, m, l, r, f[maxn][maxn];
struct Str{
	int x, y, i;
} q[maxl + 10], u, v;
int main() {
	memset(f, 0, sizeof(f));
	cin >> n >> m >> q[1].x >> q[1].y;
	for (int i = 11; i <= n + 10; i++)
		for (int j = 11; j <= m + 10; j++)
			f[i][j] = -1;
	q[1].x += 10, q[1].y += 10, f[q[1].x][q[1].y] = 0;
	q[1].i = 0, l = r = 1;
	while (l <= r) {
		for (int i = 0; i < 8; i++) {
			v.x = q[l % maxl].x + mov[i][0];
			v.y = q[l % maxl].y + mov[i][1];
			if (f[v.x][v.y] == -1) {
				r++;
				v.i = q[l % maxl].i + 1;
				f[v.x][v.y] = v.i;
				q[(r % maxl)] = v;
			}
		}
		l++;
	}
	for (int i = 11; i <= n + 10; i++) {
		for (int j = 11; j <= m + 10; j++)
			cout << setiosflags(ios :: left) << setw(5) << f[i][j];
		puts("");
	}
	return 0;
}
