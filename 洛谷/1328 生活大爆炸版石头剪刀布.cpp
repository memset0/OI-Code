#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n, x, y, a[maxn], b[maxn];
int check[5][5] = {
	{0, 2, 1, 1, 2},
	{1, 0, 2, 1, 2},
	{2, 1, 0, 2, 1},
	{2, 2, 1, 0, 1},
	{1, 1, 2, 2, 0}
};
int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= x; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= y; i++)
		scanf("%d", &b[i]);
	int ansA = 0, ansB = 0, nowA, nowB;
	for (int i = 1; i <= n; i++) {
		nowA = a[(i - 1) % x + 1];
		nowB = b[(i - 1) % y + 1];
		if (check[nowA][nowB] == 1) {
			ansA ++;
		} else if (check[nowA][nowB] == 2) {
			ansB ++;
		} 
	}
	printf("%d %d\n", ansA, ansB);
	return 0;
}
