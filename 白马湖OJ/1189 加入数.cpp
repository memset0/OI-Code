#include <bits/stdc++.h>
using namespace std;
long long n, m, a[30], t;
int main() {
	cin >> t >> m;
	while (t) a[++n] = t % 10, t /= 10;
	for (int i = n; i > 0; i--)
		if (m > a[i]) {
			a[i] = m;
			break;
		}
	for (int i = n; i > 0; i--)
		printf("%lld", a[i]);
	puts("");
	return 0;
}
