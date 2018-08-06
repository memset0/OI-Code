// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.05 22:43:30
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

ll a, b, c, x, y, z, t;

int main() {
	a = read(), b = read(), c = read();
	x = read(), y = read(), z = read();
	t = read();
	printf("%lld\n", t * ((x - a) * 3600 + (y - b) * 60 + (z - c)));
	return 0;
}