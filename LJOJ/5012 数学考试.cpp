// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll n, k, t;
ll f[35];

ll getans(ll n, ll k) {
	// printf(">> %lld %lld\n", n, k);
	if (k > n) return 0;
	if (n == 1 && k == 1) return 1;
	for (int i = 0; i < 34; i++)
		if (n > f[i] && n <= f[i + 1]) {
			if (n > (f[i] << 1)) {
				k = (k - 1) % f[i] + 1;
				n = (n - 1) % f[i] + 1;
				return getans(n, k);
			} else {
				if (k > f[i]) {
					// puts("===ONE===");
					return (3 - getans(n, k - f[i])) % 3;
				}
				if (n > (f[i] + f[i - 1] * 2)) {
					// puts("===TWO===");
					k = (k - 1) % f[i - 1] + 1;
					n -= f[i], n = (n - 1) % f[i - 1] + 1, n += f[i];
					return getans(n, k);
				}
				if (n > (f[i] + f[i - 1])) {
					// puts("===THREE===");
					if (k > f[i - 1] * 2) return 0;
					if (k > f[i - 1]) return (3 - getans(n, k - f[i - 1])) % 3;
					return getans(n - 4 * f[i - 1], k);
				}
				// puts("===FOUR===");
				if (k > f[i - 1]) return 0;
				return getans(n - 2 * f[i - 1], k);
			}
		}
	return -1;
}

ll solve(ll n, ll k) {
	return getans(n * 2 + 1, n * 2 + 1 - k);
}

int main() {
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < 35; i++)
		f[i] = f[i - 1] * 3;

	// puts("1");
	// for (int i = 1; i <= 1000; i++) {
	// 	for (int j = 1; j <= 2 * i + 1; j++)
	// 		printf("%lld", getans(2 * i + 1, j));
	// 	puts("");
	// }

	t = read();
	while (t--) {
		n = readll(), k = readll();
		printf("%lld\n", solve(n, k));
	}

	return 0;
}