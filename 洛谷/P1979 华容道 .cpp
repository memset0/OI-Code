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


namespace wyl {
	
	const int maxn = 32;
	const int mov[4][2] = {
		{1, 0}, {-1, 0},
		{0, 1}, {0, -1},
	};
	
	int n, m, p, u, v, l, r;
	int x, y, x1, x2, y1, y2;
	int s, e, sx, sy, ex, ey, tx, ty;
	int pos;
	int a[35][35], id[35][35][35][35], dis[1000000];
	int q[10000000];
	bool inq[1000000], vis[35][35];
	
	struct status {
		int x, y, stp;
		status () {}
		status (int a, int b, int c) {
			x = a, y = b, stp = c;
		}
	} q0[10000000];
	
	int tot = 2, tmptot, hed[1000000], tmphed[1000000], to[8000000], nxt[8000000], val[8000000];
	void add_edge(int u, int v, int w) {
		if (!~w) return;
//		printf("add edge %d %d %d\n", u, v, w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
		hed[u] = tot++;
	}
			
	int bfs(int sx, int sy, int ex, int ey, int kx, int ky)  {
		if (sx == ex && sy == ey) return 0;
		status u, v;
		memset(vis, 0, sizeof(vis));
		l = r = 1;
		q0[1] = status(sx, sy, 0);
		vis[sx][sy] = vis[kx][ky] = 1;
		while (l <= r) {
			u = q0[l++];
			for (int t = 0; t < 4; t++) {
				v.x = u.x + mov[t][0];
				v.y = u.y + mov[t][1];
				v.stp = u.stp + 1;
				if ((!a[v.x][v.y]) && !vis[v.x][v.y]) {
					if (v.x == ex && v.y == ey) {
//						printf("%d %d => %d %d | %d %d : %d\n", sx, sy, ex, ey, kx, ky, v.stp);
						return v.stp;
					}
					vis[v.x][v.y] = 1;
					q0[++r] = v;
				}
			}
		}
		return -1;
	}
	
	int spfa(int s, int e) {
		memset(dis, -1, sizeof(dis));
		l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
		while (l <= r) {
			u = q[l++], inq[u] = 0;
			for (int i = hed[u]; i; i = nxt[i]) {
				int v = to[i];
				if (~val[i] && (!~dis[v] || dis[v] > dis[u] + val[i])) {
//					printf("spfa %d => %d : %d %d %d\n", u, v, dis[u], val[i], dis[v]);
					dis[v] = dis[u] + val[i];
					if (!inq[v]) {
						q[++r] = v;
						inq[v] = 1;
					}
				}
			}
		}
		return dis[e];
	}
	
	int main() {
		n = read(), m = read(), p = read();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] = read() ^ 1;
		for (int i = 0; i <= n + 1; i++)
			a[i][0] = a[i][m + 1] = 1;
		for (int i = 0; i <= m + 1; i++)
			a[0][i] = a[n + 1][i] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (!a[i][j]) {
					for (int t = 0; t < 4; t++) {
						x = i + mov[t][0];
						y = j + mov[t][1];
						if (!a[x][y]) {
							id[i][j][x][y] = ++pos;
//							printf("id[%d][%d][%d][%d] = %d\n", i, j, x, y, id[i][j][x][y]);
						}
					}
				}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (!a[i][j]) {
					for (int t = 0; t < 4; t++) {
						x = i + mov[t][0];
						y = j + mov[t][1];
						if (!a[x][y])
							add_edge(id[i][j][x][y], id[x][y][i][j], 1);
					}
					for (int t1 = 0; t1 < 4; t1++) {
						x1 = i + mov[t1][0];
						y1 = j + mov[t1][1];
						if (!a[x1][y1])
							for (int t2 = 0; t2 < 4; t2++) 
								if (t1 ^ t2) {
									x2 = i + mov[t2][0];
									y2 = j + mov[t2][1];
									if (!a[x2][y2])
										add_edge(id[i][j][x1][y1], id[i][j][x2][y2], bfs(x1, y1, x2, y2, i, j));
								}
					}
				}
		tmptot = tot;
		memcpy(tmphed, hed, sizeof(hed));
		while (p--) {
			tot = tmptot;
			memcpy(hed, tmphed, sizeof(hed));
			tx = read(), ty = read(), sx = read(), sy = read(), ex = read(), ey = read();
			s = ++pos, e = ++pos;
//			printf("%d -> %d\n", s, e);
			if (sx == ex && sy == ey) {
				puts("0");
				continue;
			}
			for (int t = 0; t < 4; t++) {
				x = sx + mov[t][0];
				y = sy + mov[t][1];
				if (id[sx][sy][x][y]) {
//					printf("add S %d %d %d %d : %d\n", x, y, tx, ty, bfs(tx, ty, x, y, sx, sy));
					add_edge(s, id[sx][sy][x][y], bfs(tx, ty, x, y, sx, sy));
				}
			}
			for (int t = 0; t < 4; t++) {
				x = ex + mov[t][0];
				y = ey + mov[t][1];
				if (id[ex][ey][x][y]) {
//					printf("add E %d %d %d %d : %d\n", x, y, tx, ty, 0);
					add_edge(id[ex][ey][x][y], e, 0);
				}
			}
			printf("%d\n", spfa(s, e));
			pos -= 2;
		}
		return 0;
	}

} 

int main() {
//	freopen("INPUT", "r", stdin);
	return wyl::main();
}