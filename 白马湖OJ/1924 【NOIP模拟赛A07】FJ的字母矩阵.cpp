#include <bits/stdc++.h>
using namespace std;

const int maxn = 60;
int n, m, a[maxn][maxn];
int x, y, i, j, ans = -1, cnt;

char chr;
char read() {
	chr = getchar();
	while (!('A' <= chr && chr <= 'Z')) chr = getchar();
	return chr;
}
bool check(int i, int j) {
//	printf("%d %d\n", i, j);
	if (i < 1 || j < 1 || i > n || j > m) return false;
	if (a[i][j] == y) return true;
	return false;
}
int main() {
//	freopen("moocrypt.in", "r", stdin);
//	freopen("moocrypt.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			a[i][j] = read();
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++)
//			putchar(a[i][j]);
//		puts("");
//	}
	for (x = 'A'; x <= 'Z'; x++)
		for (y = 'A'; y <= 'Z'; y++) {
			if (x == y || x == 'M' || y == 'O') continue;
			cnt = 0;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= m; j++)
					if (a[i][j] == x) {
//						printf(">> i = %d j = %d a[%d][%d] = %c\n", i, j, i, j, a[i][j]);
						if (check(i + 1, j) && check(i + 2, j)) cnt++;
						if (check(i - 1, j) && check(i - 2, j)) cnt++;
						if (check(i, j + 1) && check(i, j + 2)) cnt++;
						if (check(i, j - 1) && check(i, j - 2)) cnt++;
						if (check(i + 1, j + 1) && check(i + 2, j + 2)) cnt++;
						if (check(i - 1, j - 1) && check(i - 2, j - 2)) cnt++;
						if (check(i + 1, j - 1) && check(i + 2, j - 2)) cnt++; 
						if (check(i - 1, j + 1) && check(i - 2, j + 2)) cnt++;
					}
//			if (cnt) printf("%c %c => %d\n", x, y, cnt);
			ans = max(ans, cnt);
		}
		
	printf("%d\n", ans);
//	printf("%d %d\n", n, m);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%c", a[i][j]);
//	}
	return 0;
} 
