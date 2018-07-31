#include <bits/stdc++.h>
using namespace std;
long long n, m, k, t, cnt;
int main() {
	scanf("%lld%lld", &n, &k);
	m = n;
	while (1) {
		cnt = 0, t = m;
		while (t > 0) {
			cnt += t % 2;
			t /= 2;
		}
		if (cnt <= k) break;
		m += m & -m;
		// ×¢Òâ²»ÊÇ m += n & n; 
	}
	printf("%lld", m - n);
	return 0;
}

