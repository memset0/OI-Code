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

int b, p, k;

int main() {
	b = read(), p = read(), k = read();
	int ans = 1 % k, mul = b % k, tim = p;
	while (tim) {
		if (tim & 1) ans = ans * mul % k;
		mul = mul * mul % k;
		tim >>= 1;
	}
	printf("%d^%d mod %d=%d\n", b, p, k, ans);
	return 0;
}

