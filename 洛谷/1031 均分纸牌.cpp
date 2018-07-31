#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, a[maxn], b[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
	sum /= n;
	int ans = 0;
	bool flag;
	for (int i = 1; i < n; i++) {
		if (a[i] < sum) {
			a[i + 1] -= sum - a[i];
			a[i] = sum;
			ans ++;
		} else if (a[i] > sum) {
			a[i + 1] += a[i] - sum;
			a[i] = sum;
			ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
