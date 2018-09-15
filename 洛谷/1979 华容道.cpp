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

const int maxn = 32;

void bfs(int sx, int sy)  {
	l = r = 1;
	q[1] = status(sx, sy, 0);
	g[sx][sy][sx][sy] = 0;
	while (l <= r) {
		u = q[l++];
		for (int t = 0; t < 4; t++) {
			v.x = u.v + nxt[t][0];
			v.y = u.y + nxt[t][1];
			v.stp = u.stp + 1;
			if (!a[v.x][v.y] && !g[sx][sy][v.x][v.y]) {
				g[sx][sy][v.x][v.y] = v.stp;
				q[++r] = v;
			}
		}
	}
}

int main() {
	memset(g, -1, sizeof(g));
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!a[i][j])
				bfs(i, j);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!a[i][j]) {
				for (int t = 0; t < 4; t++) {
					x = i + nxt[t][0];
					y = j + nxt[t][1];
					if (!a[x][y])
						id[i][j][x][y] = ++pos;
				}
			}
	while (p--) {
		
	}
	return 0;
}
