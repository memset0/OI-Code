// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int maxn = 12;
int n, m, p, k, s, g[maxn][maxn][4], key[maxn][maxn], dis[maxn][maxn][1 << 15];
int l, r, ux, uy, vx, vy, tx, ty, kind;

struct status {
	int x, y, key, step;
} u, v, q[10000010];

void add_door(int ux, int uy, int vx, int vy, int kind) {
	for (int i = 0; i < 4; i++) {
		tx = ux + mov[i][0];
		ty = uy + mov[i][1];
		if (tx == vx && ty == vy) {
			g[ux][uy][i] = kind ? kind : -1;
			return;
		}
	}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read(), p = read();
	k = read();
	for (int i = 1; i <= k; i++) {
		ux = read(), uy = read();
		vx = read(), vy = read();
		kind = read();
		add_door(ux, uy, vx, vy, kind);
		add_door(vx, vy, ux, uy, kind);
	}
	s = read();
	for (int i = 1; i <= s; i++) {
		ux = read(), uy = read(), kind = read();
		key[ux][uy] |= 1 << (kind - 1);
	}

	// printf("=== g ===\n");
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		printf("(%d,%d,%d,%d) ", g[i][j][0], g[i][j][1], g[i][j][2], g[i][j][3]);
	// 	puts("");
	// }
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		printf("%d ", key[i][j]);
	// 	puts("");
	// }

	l = r = 1, q[1].x = q[1].y = q[1].step = 1, q[1].key = 0, dis[1][1][0] = 1;

	while (l <= r) {
		u = q[l++];

		for (int i = 0; i < 4; i++) {
			v.x = u.x + mov[i][0];
			v.y = u.y + mov[i][1];
			v.key = u.key | key[v.x][v.y];
			v.step = u.step + 1;
			if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
			if (v.step > dis[v.x][v.y][v.key] && dis[v.x][v.y][v.key]) continue;
			if ((!g[u.x][u.y][i]) || (g[u.x][u.y][i] && (u.key & (1 << (g[u.x][u.y][i] - 1))))) {
				dis[v.x][v.y][v.key] = v.step;
				// printf("(%d, %d, %d, %d) => (%d, %d, %d, %d)", u.x, u.y, u.key, u.step, v.x, v.y, v.key, v.step);
				// if (g[u.x][u.y][i] && (u.key & (1 << (g[u.x][u.y][i] - 1)))) printf(" key = %d %d", g[u.x][u.y][i], v.key);
				// putchar('\n');
				q[++r] = v;
				if (v.x == n && v.y == m) {
					printf("%d\n", v.step - 1);
					return 0;
				}
			}
		}

	}

	printf("-1\n");

	return 0;
}