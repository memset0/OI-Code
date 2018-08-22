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

const int maxn = 20000010;
int n, k, p, t, ans, A, B, C, D;
int a[maxn], b[maxn];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), k = read(), p = read();
	A = read(), B = read(), C = read(), D = read();

	a[1] = A;
	for (int i = 2; i <= n; i++)
		a[i] = (a[i - 1] * (ll)B + C) % D;
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

	for (int i = n; i >= 1; i--)
		b[i] = ((i == n || i % k == 0) ? 1 : b[i + 1]) * (ll)a[i] % p;
	t = A;
	for (int i = 1; i <= n; i++) {
		a[i] = ((i % k == 1) ? 1 : a[i - 1]) * (ll)t % p;
		t = (t * (ll)B + C) % D;
	}

	// for (int i = 1; i <= n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << b[i] << " ";
	// cout << endl;

	for (int i = 1; i <= n - k + 1; i++) {
		if (i % k == 1) ans = ans ^ b[i];
		else ans = ans ^ int(b[i] * (ll)a[i + k - 1] % p);
		// cout << ((i % k) == 1 ? b[i] : b[i] * (ll)a[i + k - 1] % p) << endl;
	}
	printf("%d\n", ans);

	return 0;
}