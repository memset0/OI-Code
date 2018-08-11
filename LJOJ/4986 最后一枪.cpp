// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll n, m, p, q, t, a, b;

//bool check() {
//	if (!b) return false;
//	if (!a) return true;
//	m = n - b; b += a;
//	for (int q = 0; b * q < n; q++) {
//		p = (m - b * q + a - 1) / a;
//		if (p * a + b * q < n) {
////			printf("%d <= %d * %d + %d * %d < %d\n", m, a, p, b, q, n);
//			return true;
//		}
//	}
//	return false;
//}

bool check()  {
	if (!b) return false;
	if (!a) return true;
	long long rst = (n - 1) % a + 1;
	long long cnt = (n - rst) / a;
	long long tim = rst / b + (rst % b ? 1 : 0);
	if (tim <= cnt + 1) return true;
	return false;
}

int main() {
	
	t = read();
	while (t--) {
		n = read(), a = read(), b = read();
		if (check()) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
