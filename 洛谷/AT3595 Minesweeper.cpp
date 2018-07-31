#include <bits/stdc++.h> 
using namespace std;
const int maxn = 60;
int n, m, a[maxn][maxn];
int f(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m) return 0;
	if (a[x][y] == '#') return 1;
	return 0;
}
int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			a[i][j] = getchar();
		getchar();
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '.') {
				a[i][j] = 
					f(i + 1, j) +
					f(i - 1, j) +
					f(i, j + 1) +
					f(i, j - 1) +
					f(i + 1, j + 1) +
					f(i + 1, j - 1) +
					f(i - 1, j + 1) +
					f(i - 1, j - 1); 
			}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '#') putchar('#');
			else printf("%d", a[i][j]);
		puts("");
	}
	return 0;
}
