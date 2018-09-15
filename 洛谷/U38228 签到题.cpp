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

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll m, k, t;

int main() {
	
	k = readll(), m = readll();
	t = 1;
	for (int n = 1; true; n++) {
//		printf("%lld %lld %lld\n", m, k, t);
		if (t == k) {
			printf("%d\n", n);
			return 0;
		}
		t = t * 10 + 1;
		while (t > m) t -= m;
	}

	return 0;
}

