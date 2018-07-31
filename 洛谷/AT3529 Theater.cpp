#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, maxm = 100010;
int n, ans, m = 100000, l, r, f[maxm];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; j++)
			f[j] = 1;
	}
	for (int i = 1; i <= m; i++)
		if (f[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
