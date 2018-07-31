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

const int maxn = 3000010;
ll n, p, a[maxn];

int main() {
	n = read(), p = read();
	a[0] = a[1] = 1;
	for (int i = 2; i <= n; i++)
		a[i] = (p - p / i) * a[p % i] % p;
	for (int i = 1; i <= n; i++)
		printf("%d\n", a[i]);
	return 0;
}

