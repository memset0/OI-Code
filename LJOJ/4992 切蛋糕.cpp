// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll n, m, a, b, ans;

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	a = b = 1;
	while (b <= n || b <= m) {
		if (n % (a + b) == 0 || m % (a + b) == 0) {
//			printf(">>> %d %d %d %d\n", a, b, ans, n * m - n * m / (a + b));
			ans = max(ans, n * m - n * m / (a + b));
		}
		a += b, swap(a, b);
	}
	printf("%lld\n", ans);

	return 0;
}
