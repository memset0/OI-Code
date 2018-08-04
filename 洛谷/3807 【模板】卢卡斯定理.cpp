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

const int maxn = 100010;
int t, n, m, p;
ll a[maxn], b[maxn];

ll C(int n, int m) {
	if (n < m) return 0;
	else if (n < p) return a[n] * b[m] % p * b[n - m] % p;
	else return C(n / p, m / p) * C(n % p, m % p) % p;
}

int main() {
	t = read();
	while (t--) {
		n = read(), m = read(), p = read();
		a[0] = a[1] = b[0] = b[1] = 1;
		for (int i = 2; i <= m + n; i++)
			a[i] = a[i - 1] * i % p;
		for (int i = 2; i <= m + n; i++)
			b[i] = (p - p / i) * b[p % i] % p;
		for (int i = 2; i <= m + n; i++)
			b[i] = b[i - 1] * b[i] % p;
//		for (int i = 1; i <= m + n; i++)
//			printf("%d ", a[i]);
//		puts("");
//		for (int i = 1; i <= m + n; i++)
//			printf("%d ", b[i]);
//		puts("");
		printf("%lld\n", C(m + n, m));
	}
	return 0;
}

