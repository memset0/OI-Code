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

const int maxn = 10010;
ll n, t, s1, s2, a[maxn];

int main() {
//	freopen("election.in", "r", stdin);
//	freopen("election.out", "w", stdout);
	t = read();
	while (t--) {
		n = read(), s1 = s2 = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			if ((a[i] - 1) * 10000000 + 5000000 > 0)
				s1 += (a[i] - 1) * 10000000 + 5000000;
			s2 += a[i] * 10000000 + 4999999;
		}
//		printf("%lld %lld\n", s1, s2);
		if (s1 <= 1000000000 && 1000000000 <= s2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
