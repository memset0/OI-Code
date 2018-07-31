#include <bits/stdc++.h>
#define path(d) (max(abs(p-x[d]),abs(q-y[d])))
using namespace std;
const int maxn = 30;
int d, n, a[maxn], x[maxn], y[maxn];
int cnt, sum = 0, ans = -1;
int main() {
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &x[i], &y[i], &a[i]);
	for (int p = 0; p <= 128; p++)
		for (int q = 0; q <= 128; q++) {
			cnt = 0;
			for (int i = 1; i <= n; i++)
				if (path(i) <= d) cnt += a[i];
			if (cnt > ans) ans = cnt, sum = 1;
			else if (cnt == ans) sum++;
		}
	printf("%d %d\n", sum, ans);
	return 0;
}
