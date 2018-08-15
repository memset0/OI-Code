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

int main() {
	
	int b, p, k, mul, ans;
	b = read(), p = read(), k = read();
	mul = b % k, ans = 1 % k;
	printf("%d^%d mod %d=", b, p, k);
	while (p) {
		if (p & 1) ans = ans * mul % k;
		mul = mul * mul % k;
		p >>= 1;
	}
	printf("%d\n", ans);

	return 0;
}

