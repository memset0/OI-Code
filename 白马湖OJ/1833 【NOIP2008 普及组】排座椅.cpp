//WAДњТы 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int m, n, k, l, d, x1, y, x2, yy, mark[2][maxn], rr[2][maxn], a[maxn][maxn];
bool my_sort0(int a, int b) {
	return mark[0][a] > mark[0][b];
}
bool my_sort1(int a, int b) {
	return mark[1][a] > mark[1][b];
}
int main() {
	cin >> m >> n >> k >> l >> d;
	for (int i = 1; i <= d; i++) {
		scanf("%d%d%d%d", &x1, &y, &x2, &yy);
		if (x1 == x2) mark[1][min(y, yy)]++;
		if (y == yy) mark[0][min(x1, x2)]++;
	}
	for (int i = 1; i <= m; i++) rr[0][i] = i;
	for (int i = 1; i <= n; i++) rr[1][i] = i;
	sort(rr[0] + 1, rr[0] + 1 + m, my_sort0);
	sort(rr[1] + 1, rr[1] + 1 + n, my_sort1);
	for (int i = 1; i <= k; i++) {
		printf("%d", rr[0][i]);
		if (i != k) printf(" ");
	}
	puts("");
	for (int i = 1; i <= l; i++) {
		printf("%d", rr[1][i]);
		if (i != l) printf(" ");
	}
	return 0;
}
