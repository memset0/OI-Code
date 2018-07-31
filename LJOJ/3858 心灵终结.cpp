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
ll t, n, m;
ll calc(ll n, ll m) {
	if (n == 1) return m;
	else if (n == 2) {
		if (m % 4 == 0) return m;
		else if (m % 4 == 1) return ((m >> 2) << 2) + 2;
		else if (m % 4 == 2 || m % 4 == 3) return ((m >> 2) + 1) << 2;
	} else return ((n * m + 1) >> 1);
}
int main() {
	freopen("psycho.in", "r", stdin);
	freopen("psycho.out", "w", stdout);
	t = read();
	while (t--) {
		n = read(), m = read();
		if (n > m) swap(n, m);
		printf("%lld\n", calc(n, m));
	}
	for (int i = 1; i <= n; i++) {

	}
	return 0;
}
