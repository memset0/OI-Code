#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
long long k, a[maxn];
bool check(long long x) {
	long long cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += a[i] / x;
	return (cnt >= k);
}
int main() {
//	freopen("cable.in", "r", stdin);
//	freopen("cable.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	long long t1, t2, sum;
	for (int i = 1; i <= n; i++) {
		scanf("%lld.%lld", &t1, &t2);
		a[i] = t1 * 100 + t2;
		sum += a[i];
	}
	long long L = 1, R = sum / k + 1, Mid;
	while (L + 3 < R) {
		Mid = (L + R) >> 1;
		if (check(Mid)) L = Mid;
		else R = Mid;
	}
	for (Mid = R; Mid >= L; Mid--)
		if (check(Mid)) {
			printf("%lld.%02lld\n", Mid / 100, Mid % 100);
			return 0;
		}
	printf("0.00\n");
	return 0;
}