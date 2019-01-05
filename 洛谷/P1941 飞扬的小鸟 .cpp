#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, rd::c = getchar(), rd::m = 1; \
	while (!isnum(rd::c) && rd::c != '-') rd::c = getchar(); \
	if (rd::c == '-') rd::c = getchar(), rd::m = -1; \
	while (isnum(rd::c)) x = x * 10 + rd::c - '0', rd::c = getchar(); \
	x *= rd::m; \
} while (false)

#define update(i, j, x, y, t) if (1 <= y && y <= m) f[i][j] = min(f[i][j], f[x][y] + t)

namespace rd {
	char c;
	int m;
}
using namespace std;

const int maxn = 10010;
const int maxm = 1010;
int n, m, k, ans, tans, a[maxn][maxm], f[maxn][maxm];
bool able = true, mark;
struct Speed {
	int up, down;
} v[maxn];
struct Hitter {
	int i, top, bottom;
} h[maxn];
bool cmp(Hitter x, Hitter y) {
	return x.i < y.i;
}

int main() {
//	freopen("bird0.in", "r+", stdin);
//	freopen("bird00.txt", "w+", stdout);
	
	read(n); read(m); read(k);
	for (int i = 1; i <= n; i++) {
		read(v[i].up);
		read(v[i].down);
	}
	for (int i = 1; i <= k; i++) {
		read(h[i].i);
		read(h[i].bottom);
		read(h[i].top);
//		cout << h[i].top << " " << h[i].bottom << endl;
		for (int j = 1; j <= h[i].bottom; j++)
			a[h[i].i][j] = 1;
		for (int j = h[i].top; j <= m; j++)
			a[h[i].i][j] = 1;
	}
//	for (int i = m; i > 0; i--) {
//		for (int j = 1; j <= n; j++)
//			printf("%d	", a[j][i]);
//		puts("");
//	}
	
	memset(f, 63, sizeof(f));
	for (int i = 1; i <= m; i++)
		f[0][i] = 0;
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			/*if (!a[i][j])*/ {
				update(i, j, i - 1, j - v[i].up, 1);
				update(i, j, i, j - v[i].up, 1);
				if (j == m) {
					for (int k = 0; k <= v[i].up; k++) {
						update(i, j, i - 1, j - k, 1);
						update(i, j, i, j - k, 1);
					}
				}
			}
		for (int j = 1; j <= m; j++) 
			if (!a[i][j]) {
				update(i, j, i - 1, j + v[i].down, 0);
			}
		for (int j = 1; j <= m; j++)
			if (a[i][j])
				f[i][j] = 1061109567;
		mark = false;
		for (int j = 1; j <= m; j++)
			if (f[i][j] != 1061109567)
				mark = true;
		if (!mark) {
			able = false;
			tans = i - 1;
			break;
		}
	}
	
//	for (int i = m; i > 0; i--) {
//		for (int j = 1; j <= n; j++)
////			if (f[j][i] == 1061109567) printf("    *");
////			else printf("%5d", f[j][i]);
//			if (f[j][i] == 1061109567) printf("*	");
//			else printf("%d	", f[j][i]);
//		puts("");
//	}
	
	if (able) {
		ans = 1061109567;
		for (int i = 1; i <= m; i++)
			ans = min(ans, f[n][i]);
		printf("1\n%d\n", ans);
	} else {
		sort(h + 1, h + k + 1, cmp);
		ans = 0;
		for (int i = 1; i <= k; i++)
			if (h[i].i <= tans)
				ans++;
			else
				break;
		printf("0\n%d\n", ans);
	}
	
	return 0;
}