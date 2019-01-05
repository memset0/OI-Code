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

const int maxn = 1510;
int n, m, l, r, sx, sy, dis[maxn][maxn];
bool find_ans, a[maxn][maxn], vis[maxn][maxn];
char c;

struct node {
	int x, y;
	node operator + (const node &b) const {
		return (node){x + b.x, y + b.y};
	}
	bool operator == (const node &b) const {
		return (x == b.x && y == b.y);
	}
	void relocate(void) {
		if (x < 1) x += n;
		if (y < 1) y += m;
		if (x > n) x -= n;
		if (y > m) y -= m;
	}
} nxt[4], fir[maxn][maxn];

struct status {
	node now, real;
	int step;
} u, v, q[maxn * maxn];

int main() {
//	freopen("INPUT", "r", stdin);

	nxt[0] = (node){0, 1};
	nxt[1] = (node){1, 0};
	nxt[2] = (node){0, -1};
	nxt[3] = (node){-1, 0};

	while (scanf("%d %d\n", &n, &m) != EOF) {
		memset(vis, 0, sizeof(vis));
		memset(dis, 0, sizeof(dis));
		memset(fir, 0, sizeof(fir));
		find_ans = false;
		sx = sy = 0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				c = getchar();
				if (c == '#') a[i][j] = 1;
				else if (c == '.') a[i][j] = 0;
				else if (c == 'S') {
					a[i][j] = 0;
					sx = i, sy = j;
				} else printf("!");
			}
			scanf("\n");
		}
		
		l = r = 1, q[1] = (status){(node){sx, sy}, (node){sx, sy}, 1};
		vis[sx][sy] = dis[sx][sy] = 1, fir[sx][sy] = (node){sx, sy};
		while (l <= r && !find_ans) {
			u = q[l++];
//			printf(">>> %d %d %d %d %d\n", u.now.x, u.now.y, u.real.x, u.real.y, u.step);
			for (int i = 0; i < 4; i++) {
				v.now = u.now + nxt[i];
				v.real = u.real + nxt[i];
				v.step = u.step + 1;
				v.now.relocate();
				if (vis[v.now.x][v.now.y] && dis[v.now.x][v.now.y] <= u.step && (!(v.real == fir[v.now.x][v.now.y]))) {
					find_ans = 1;
					node a = v.now, b = v.real, c = fir[v.now.x][v.now.y];
//					printf("%d %d %d %d %d %d\n", a.x, a.y, b.x, b.y, c.x, c.y);
				}
				if (a[v.now.x][v.now.y] || vis[v.now.x][v.now.y]) continue;
				vis[v.now.x][v.now.y] = 1;
				dis[v.now.x][v.now.y] = v.step;
				fir[v.now.x][v.now.y] = v.real;
				q[++r] = v;
			}
		}

		if (find_ans) printf("Yes\n");
		else printf("No\n");

	}
	
	return 0;
}