#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1010;
int n, k, len = 1, a[maxn];
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++) {
		a[1]++;
		for (int j = 1; j <= len; j++)
			if (a[j] == 2) {
				a[j] = 0;
				a[j + 1]++;
			}
		if (a[len + 1]) len++;
	}
	// for (int i = 1; i <= len; i++)
	// 	printf("%d ", a[i]);
	// puts("");
	ll ans = 0, times = 1;
	for (int i = 1; i <= len; i++) {
		ans += times * a[i];
		times *= k;
	}
	printf("%lld\n", ans);
	return 0;
}