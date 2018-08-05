#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3 * 1e6 + 10;
ll n, p, a[maxn];
int main() {
	scanf("%lld%lld", &n, &p);
	a[0] = a[1] = 1;
	for (int i = 2; i <= n; i++)
		a[i] = (p - p / i) * a[p % i] % p;
	for (int i = 1; i <= n; i++)
		printf("%lld\n", a[i]);
	return 0;
}