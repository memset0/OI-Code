// luogu-judger-enable-o2
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

const int maxn = 510;
const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, l, r;
int cnt, ans, mr;
int a[maxn][maxn];
bool arr[maxn], dis[maxn][maxn];

struct edge {
	int l, r;
} f[maxn];

struct node {
	int x, y;
	node () {}
	node (int a, int b) { x = a, y = b; }
} u, v, q[maxn * maxn];

bool cmp(edge a, edge b) {
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}

void bfs(int s) {
	memset(dis, 0, sizeof(dis));
	l = r = 1, q[1] = node(1, s), dis[1][s] = 1;
	while (l <= r) {
		u = q[l++];
//		cout << u.x << " " << u.y << endl;
		for (int i = 0; i < 4; i++) {
			v.x = u.x + mov[i][0];
			v.y = u.y + mov[i][1];
			if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
			if (!dis[v.x][v.y] && a[u.x][u.y] > a[v.x][v.y]) {
				dis[v.x][v.y] = 1;
				q[++r] = v;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		if (dis[n][i]) {
			arr[i] = 1;
			if (!f[s].l) f[s].l = i;
			f[s].r = i;
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= m; i++)
		bfs(i);
	for (int i = 1; i <= m; i++)
		if (!arr[i]) {
			cnt = 0;
			for (int i = 1; i <= m; i++)
				cnt += arr[i] ^ 1;
			printf("0\n%d\n", cnt);
			return 0;
		}
	sort(f + 1, f + m + 1, cmp);
//	for (int i = 1; i <= m; i++)
//		printf("%d %d\n", f[i].l, f[i].r);
	for (int i = 1; i <= m; ) {
		mr = 0;
		for (int j = 1; j <= m; j++)
			if (f[j].l <= i && f[j].r > f[mr].r)
				mr = j;
		i = f[mr].r + 1, ans++;
	}
	printf("1\n%d\n", ans);
	return 0;
}
