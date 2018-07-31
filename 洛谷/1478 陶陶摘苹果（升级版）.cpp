#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010, maxm = 1010;
int n, m, x, y, h, ans = 0, a[maxn], b[maxn], f[maxm];
int main() {
	
	scanf("%d%d%d%d", &n, &m, &x, &y);
	h = x + y;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		if (h >= a[i]) {
			for (int j = m; j >= b[i]; j--)
				f[j] = max(f[j], f[j - b[i]] + 1);
		}
	}
	for (int i = 1; i <= m; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	
	return 0;
}
