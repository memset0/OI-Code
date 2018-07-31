#include <bits/stdc++.h>
#define f(i,l,r) for (i = l; i <= r; i++)
using namespace std;
int main() {
	int i, j, k, n = 5, a[6][6];
	f(i, 1, n) f(j, 1, n) scanf("%d", &a[i][j]);
	int x, y;
	scanf("%d%d", &x, &y);
	f(i, 1, n) {
		if (i == x) k = y;
		else if (i == y) k = x;
		else k = i;
		f(j, 1, n) printf("%d ", a[k][j]);
		puts("");
	}
	return 0;
}
