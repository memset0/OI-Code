#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
long long n, m, l, r, a[maxn];
int main() {
	scanf("%lld%lld", &n, &m);
	l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		// cout << l5 << " " << r << endl;
		if ((n - i) * (n - i - 1) / 2 >= m) a[l++] = i;
		else a[r--] = i, m -= r - l + 1;
	}
	for (int i = 1; i <= n; i++)
		printf("%lld ", a[i]);
	putchar('\n');
	return 0;
}