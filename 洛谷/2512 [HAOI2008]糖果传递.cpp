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

const int maxn = 1e6 + 10;
int n;
ll a[maxn], s[maxn], ans, sum;

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++)
		sum += a[i];
	sum /= n;
	for (int i = 1; i <= n; i++)
		a[i] -= sum;

	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	sort(s + 1, s + n + 1);

	for (int i = 1; i <= n; i++)
		ans += abs(s[(n + 1) >> 1] - s[i]);

	printf("%lld\n", ans);

	return 0;
}