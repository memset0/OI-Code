// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 310;
const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
int a[maxn][maxn], ans[maxn][maxn], vis[maxn][maxn];

struct node {
	int x, y;
	node () {}
	node (int a, int b) { x = a, y = b; }
} u, v;
bool operator < (const node &x, const node &y) {
	return a[x.x][x.y] > a[y.x][y.y];
}

std::priority_queue < node > q;

void fill(int x, int y, int h) {
//	printf("fill %d %d %d\n", x, y, h);
	if (a[x][y] > h) {
		q.push(node(x, y));
		return;
	} else {
		vis[x][y] = 1;
		ans[x][y] += h - a[x][y];
		for (int t = 0; t < 4; t++) {
			int vx = x + mov[t][0];
			int vy = y + mov[t][1];
			if (vx < 1 || vy < 1 || vx > n || vy > n) continue;
			if (vis[vx][vy]) continue;
			fill(vx, vy, h);
		}
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i =  1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] < 0) {
				ans[i][j] = -a[i][j];
				a[i][j] = 0;
			}
			
	for (int i = 1; i <= n; i++) {
		q.push(node(i, 1));
		q.push(node(i, m));
	}
	for (int i = 1; i <= m; i++) {
		q.push(node(1, i));
		q.push(node(n, i));
	}
	
	while (q.size()) {
		u = q.top(), q.pop();
		if (vis[u.x][u.y]) continue;
		vis[u.x][u.y] = 1;
		for (int t = 0; t < 4; t++) {
			v.x = u.x + mov[t][0];
			v.y = u.y + mov[t][1];
			if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
			if (vis[v.x][v.y]) continue;
			fill(v.x, v.y, a[u.x][u.y]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%d ", ans[i][j]);
		puts("");
	}

	return 0;
}
