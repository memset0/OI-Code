#include <bits/stdc++.h>
using namespace std;
const int maxn = 30, maxm = 10010;
int n, m, a[maxn];
long long f[maxm];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= m; j++)
			f[j] += f[j - a[i]];
	printf("%lld", f[m]);
	return 0;
}
