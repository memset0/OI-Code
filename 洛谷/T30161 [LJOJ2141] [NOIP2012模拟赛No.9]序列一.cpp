#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, maxm = 2010;
long long n, m, a[maxn][maxm], s[maxm];
int main() {
//	freopen("Sequence1.in", "r", stdin);
//	freopen("Sequence1.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)  {
		for (int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);
		sort(a[i] + 1, a[i] + m + 1);
		for (int j = 1; j <= m; j++)
			s[j] += a[i][j];
	}
	for (int j = 1; j <= m; j++) {
		printf("%lld", s[j]);
		if (j != m) putchar(' ');
	}
	return 0;
}