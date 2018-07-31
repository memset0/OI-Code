#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
long long M, ans, a[maxn];
int main() {
	scanf("%d%d%lld", &n, &m, &M);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int x, y, k;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		if (x == 1) {
			scanf("%d%d%d", &x, &y, &k);
			for (int i = x; i <= y; i++)
				a[i] = (a[i] * k) % M;
		} else if (x == 2) {
			scanf("%d%d%d", &x, &y, &k);
			for (int i = x; i <= y; i++)
				a[i] = (a[i] + k) % M;
		} else if (x == 3) {
			scanf("%d%d", &x, &y);
			ans = 0;
			for (int i = x; i <= y; i++)
				ans = (ans + a[i]) % M;
			printf("%d\n", ans);
		}
	}
	return 0;
}
