// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

int read1d() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	return c - '0';
}

const int maxn = 80;

int n, m, l, r, mid, lst, cnt, min, now, ans;
int i[5], a[maxn][maxn], s[maxn][maxn];

bool check(int x) {
	i[0] = 0, i[4] = n;
	for (i[1] = 1; i[1] <= n - 1; i[1]++)
		for (i[2] = i[1] + 1; i[2] <= n - 1; i[2]++)
			for (i[3] = i[2] + 1; i[3] <= n - 1; i[3]++) {
				lst = cnt = 0;
				for (int j = 1; j <= m; j++) {
					min = -1;
					for (int p = 0; p < 4; p++) {
						now = s[i[p + 1]][j]
							- s[i[p + 1]][lst]
							- s[i[p]][j]
							+ s[i[p]][lst];
						min = ~min && min < now ? min : now;
					}
					if (min >= x) {
						lst = j, cnt++;
						if (cnt >= 4)
							return true;
					}
				}
			}
	return false;
}

int main() {
//	freopen("cake.in", "r", stdin);
//	freopen("cake.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read1d();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] - s[i - 1][j - 1] + s[i][j - 1] + a[i][j];

	l = 0, r = s[n][m];
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}
