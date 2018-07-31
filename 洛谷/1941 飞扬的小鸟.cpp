#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 10000;
const int maxm = 1000;
int n, m, k, t, L, R, ans = -1, res = 0, maxx = -1, x[maxn], y[maxn], l[maxn], r[maxn];
int ret; char ch;
int vis[maxn][maxm];
struct Bird{
	int i, h, cnt;
} u, v, q[maxn * 1000];
int read() {
	ch = getchar(), ret = 0;
	while (!isNum(ch)) ch = getchar();
	while (isNum(ch)) ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
void add(int x, int y, int z) {
	q[++R] = {x, y, z};
}
int main() {
//	freopen("testdata.in", "r+", stdin);
	n = read(), m = read();
	k = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	for (int i = 1; i <= n; i++)
		l[i] = 0, r[i] = m + 1;
	for (int i = 1; i <= k; i++) {
		t = read();
		l[t] = read(), r[t] = read();
	}
	L = 1, R = 0;
	for (int i = 1; i <= m; i++) add(0, i, 0);
	int i, h;
	while (L <= R) {
		u = q[L++];
		i = u.i + 1;
		h = u.h; 
//		cout << i << " " << h << endl;
		if (i > maxx) maxx = i;
		if (i > n) {
			res = 1;
			if (ans == -1 || ans > u.cnt)
				ans = u.cnt;
			continue;
		}
		if (l[i] < h - y[i] && h - y[i] < r[i]) {//不点击 
			add(i, h - y[i], u.cnt);
		}
		for (int j = 1; j <= m; j++) {//点击次数 
			if (l[i] >= h + j * x[i]) continue;
			else if (r[i] <= h + j * x[i]) {
				if (r[i] == m + 1) {
					add(i, m, u.cnt + j);
				}
				break;
			}
			else {
				if (!vis[i][h + j * x[i]])	
					add(i, h + j * x[i], u.cnt + j);
			}
		}
	}
	if (!res) {
		ans = 0;
		for (int i = 1; i < maxx; i++)
			if (r[i] != m + 1) ans++;
	}
	printf("%d\n%d", res, ans);
	return 0;
}
