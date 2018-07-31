#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
#define locate(i,j) (i * (n + 1) + j)
const int maxn = 510;
int n, m, f[maxn * maxn];
bool ans;
struct Point {
	int x, y;
	void r() {
		x = read(), y = read();
	}
} u, v, x, y, tmp;
int find(int x) {
	if (x == f[x]) return x;
	else return f[x] = find(f[x]);
}
void link(int x1, int y1, int x2, int y2) {
	f[find(locate(x1, y1))] = find(locate(x2, y2));
}
int main() {
	// freopen("data.txt", "r", stdin);
	// freopen("testdata.in", "r", stdin);
	// freopen("testdata.out", "w", stdout);
	n = read(), m = read();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[locate(i, j)] = locate(i, j);
	for (int i = 1; i <= n; i++) {
		link(i - 1, 0, i, 0);
		link(i - 1, n, i, n);
		link(0, i - 1, 0, i);
		link(n, i - 1, n, i);
	}
	for (int i = 1; i <= m; i++) {
		// printf("==== %d ====\n", i);
		u.r(), v.r();
		if (i != 1) {
			if (ans) read(), read(), read(), read();
			else u.r(), v.r();
		}
		if (u.x == v.x) {
			if (u.y > v.y) swap(u.y, v.y);
			x.x = u.x - 1, x.y = u.y;
			y.x = u.x, y.y = u.y;
		} else if (u.y == v.y) {
			if (u.x > v.x) swap(u.x, v.x);
			x.x = u.x, x.y = u.y;
			y.x = u.x, y.y = u.y - 1;
		}
		// printf("%d %d %d %d\n", u.x, u.y, v.x, v.y);
		// printf("%d %d %d %d %d %d\n", x.x, x.y, y.x, y.y, locate(x.x, x.y), locate(y.x, y.y));
		ans = find(locate(x.x, x.y)) != find(locate(y.x, y.y));
		link(x.x, x.y, y.x, y.y);
		if (ans) printf("HAHA\n");
		else printf("DAJIA\n");
	}
	return 0;
}