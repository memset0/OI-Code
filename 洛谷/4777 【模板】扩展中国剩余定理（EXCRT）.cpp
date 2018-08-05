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

const int maxn = 1e5 + 10;
int n;
ll a[maxn], b[maxn];
ll A, B, Gcd;

ll inv(ll x, ll p) {
	if (x == 0 || x == 1) return 1;
	return (p - p / x) * inv(p % x, p) % p;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = readll(), b[i] = readll();
	A = a[1], B = b[1];
	for (int i = 2; i <= n; i++) {
		Gcd = __gcd(A, a[i]);
		A = a[i] / Gcd;
		B = (B + A * inv(A / Gcd, A) * (b[i] - B) / Gcd) % A;
	}
	printf("%lld %lld\n", A, B);
	printf("%lld\n", (A + B) % A);
	return 0;
}