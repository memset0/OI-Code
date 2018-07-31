#include <bits/stdc++.h>
#define il inline
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;
namespace solution1 {
	const int maxn = 52;
	int m, l, r, t1, t2, t3, t4;
	bool lst, found, dis[maxn][maxn], G[maxn][maxn][4];
	struct Node {
		int x, y;
	} u, v, q[maxn * maxn];
	il void boom(int x1, int y1, int x2, int y2) {
//		printf(">>> %d %d %d %d\n", x1, y1, x2, y2);
		memset(dis, 0, sizeof(dis));
		for (int i = 0; i < 4; ++i) {
			if (x1 + mov[i][0] == x2 && y1 + mov[i][1] == y2) G[x1][y1][i] = 1;
			if (x2 + mov[i][0] == x1 && y2 + mov[i][1] == y1) G[x2][y2][i] = 1;
		}
		l = r = 1, q[1] = {x1, y1}, found = 0;
		while (l <= r && !found) {
			u = q[l++];
			for (int i = 0; i < 4; i++)
				if (!G[u.x][u.y][i]) {
					v = {u.x + mov[i][0], u.y + mov[i][1]};
					if (v.x < 1 || v.x > n || v.y < 1 || v.y > n)
						continue;
					if (!dis[v.x][v.y]) {
						dis[v.x][v.y] = 1;
						if (x2 == v.x && y2 == v.y) {
							found = 1;
							break;
						}
						q[++r] = v;
					}
				}
		}
		lst = found; 
		if (found) printf("HAHA\n");
		else printf("DAJIA\n");
	}
	il void main(void) {
		memset(G, 0, sizeof(G));
		m = read();
		t1 = read(), t2 = read(), t3 = read(), t4 = read();
		boom(t1, t2, t3, t4);
		for (int i = 2; i <= m; i++)
			if (lst) {
				t1 = read(), t2 = read(), t3 = read(), t4 = read(); 
				boom(t1, t2, t3, t4);
				t1 = read(), t2 = read(), t3 = read(), t4 = read(); 
			} else {
				t1 = read(), t2 = read(), t3 = read(), t4 = read(); 
				t1 = read(), t2 = read(), t3 = read(), t4 = read(); 
				boom(t1, t2, t3, t4);
			}
		return;
	}
}
int main() {
	n = read();
	solution1::main();
	return 0;
}
