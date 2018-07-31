#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 10000010;
int n, m, x, y, f[maxm], a[maxn], l = 0;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= m; i++)
		if (!f[i]) {
			a[++l] = i;
			for (int j = i << 1; j <= m; j += i)
				f[j] = 1;
		}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		if (x < 1 || y < 1 || x > m || y > m) {
			printf("Crossing the line\n");
			continue;
		}
		printf("%d\n", (upper_bound(a + 1, a + l + 1, y) - a) - (lower_bound(a + 1, a + l + 1, x) - a));
	}
	return 0;
}

