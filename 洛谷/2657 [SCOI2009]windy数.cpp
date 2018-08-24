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

const int n = 11;

int A, B;
int l, a[20];

ll ans;
ll utime, vtime;
ll f[10][20];

void init() {
	for (int i = 0; i <= 9; i++)
		f[i][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				if (abs(j - k) >= 2) {
					f[j][i] += f[k][i - 1];
				}
}

ll calc(int x) {
	// printf("=== %d ===\n", x);
	l = ans = 0;
	while (x) {
		a[++l] = x % 10;
		x /= 10;
	}
	a[l + 1] = 233;
	for (int i = l; i >= 1; i--) {
		// printf(">>> %d %d\n", i, a[i]);
		if (i == l) {
			for (int j = i - 1; j >= 1; j--)
				for (int k = 1; k <= 9; k++) {
					// printf("ans += f[%d][%d](%lld)\n", k, j, f[k][j]);
					ans += f[k][j];
				}
			utime = 1;
		}
		vtime = 0;
		for (int j = (i == l ? 1 : 0); j < a[i] || (i == 1 && j <= a[i]); j++)
			if (abs(j - a[i + 1]) >= 2) {
				// printf("ans += f[%d][%d](%lld) * %lld\n", j, i, f[j][i], utime);
				ans += f[j][i] * utime;
			}
		if (abs(a[i + 1] - a[i]) >= 2) vtime = 1;
		utime &= vtime;
	}
	// for (int i = 1; i <= l; i++)
	// 	printf("%d ", a[i]);
	// puts("");
	// printf("%lld\n", ans);
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	init();

	// for (int i = 1; i < 10000; i++)
	// 	printf("%lld\n", calc(i));

	A = read(), B = read();
	printf("%lld\n", calc(B) - calc(A - 1));

	return 0;
}