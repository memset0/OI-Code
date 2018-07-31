#include<bits/stdc++.h>
using namespace std;
#define isN(x) ('0' <= x && x <= '9')
#define read(x) do { \
	Ch = getchar(), Mk = 1, x = 0; \
	while (!isN(Ch) && Ch != '-') Ch = getchar(); \
	if (Ch == '-') Ch = getchar(), Mk = -1; \
	while (isN(Ch)) x = x * 10 + Ch - '0', Ch = getchar(); \
	x *= Mk; \
} while(0)
int Mk; char Ch;
int a[25] = {0, 1, 1, 2}, b[25];
int p, q, n, m, x;
int main() {
    read(p); read(n); read(m); read(x);
    for (int i = 4; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2] - 1;
        b[i] = b[i - 1] + b[i - 2] + 1;
    }
    q = (m - p * a[n - 1]) / b[n - 1];
    printf("%d", p * a[x] + q * b[x]);
	return 0;
}
