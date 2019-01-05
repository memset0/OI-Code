#include <bits/stdc++.h>
using namespace std;
namespace r { char c; int m; }
#define gcd(a,b) __gcd(a,b)
#define isNum(x) ('0' <= x && x <= '9')
#define read(x) do{ \
	x = 0, r::c = getchar(), r::m = 1; \
	while (!isNum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::c = getchar(), r::m == 1; \
	while (isNum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
#define readc(x) do{ \
	r::c = getchar(); \
	while (r::c != '.' && r::c != '#') r::c = getchar(); \
	if (r::c == '#') x = 1; \
	else x = 0; \
} while(0)
const int maxn = 1010;
int n, m, lx, ly, rx, ry, ii, jj, ans;
bool fit, a[maxn][maxn];
int main() {
//	freopen("battle.in", "r", stdin);
//	freopen("battle.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			readc(a[i][j]);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			cout << a[i][j] << " ";
//		puts("");
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				fit = true;
				rx = lx = i, ry = ly = j;
				while (a[rx][ly]) rx++;
				while (a[lx][ry]) ry++;
//				cout << lx << " " << ly << " " << rx << " " << ry << endl;
				for (ii = lx; ii < rx && fit; ++ii)
					if (a[ii][ry]) fit = false;
				for (ii = ly; ii < ry && fit; ++ii)
					if (a[rx][ii]) fit = false;
				for (ii = lx; ii < rx && fit; ++ii)
					if (a[ii][ly - 1]) fit = false;
				for (ii = ly; ii < ry && fit; ++ii)
					if (a[lx - 1][ii]) fit = false;
				for (ii = lx; ii < rx && fit; ++ii)
					for (jj = ly; jj < ry && fit; ++jj) {
						if (!a[ii][jj]) fit = false;
						a[ii][jj] = 0;
					}
				if (!fit) {
					printf("Bad placement.\n");
					return 0;
				} else ++ans;
			}
		}
	}
	printf("There are %d ships.\n", ans);
	return 0;
}