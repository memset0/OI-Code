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

int n, u, v, cnt;

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	u = 1;
	for (int i = 1; i <= n; i++) {
		v = i;
		while (v % 2 == 0) {
			v /= 2;
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		v = i;
		while (v % 5 == 0) {
			v /= 5;
			cnt--;
		}
	}
	for (int i = 1; i <= n; i++) {
		v = i;
		while (v % 2 == 0)
			v /= 2;
		while (v % 5 == 0)
			v /= 5;
		u = u * v % 10;
	}
	while (cnt--) u = u * 2 % 10;
	printf("%d\n", u);

	return 0;
}