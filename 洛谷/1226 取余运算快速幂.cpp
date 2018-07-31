#include <bits/stdc++.h>
#define sqr(x) (x*x)
using namespace std;
long long n, m, k, t;
int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	long long nn = n, mm = m;
	long long ans = 1;
	while(m > 0) {
		if(m % 2) ans = ans * n % k;
		n = n * n % k;
		m = m >> 1;
	}
	printf("%lld^%lld mod %lld=%lld\n", nn, mm, k, ans);
	return 0;
}
