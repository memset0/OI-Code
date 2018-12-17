// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int rr(int n) {
	return rand() % n + 1;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	srand(GetTickCount());

	int n = 5, m = 5;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		int l = rr(n), r = rr(n);
		if (l > r) swap(l, r);
		int opt = rr(3) - 1;
		printf("%d %d %d ", opt, l, r);
		if (opt == 1) {
			int l = rr(n), r = rr(n);
			if (l > r) swap(l, r);
			printf("%d %d", l, r);
		}
		putchar('\n');
	}

	return 0;
}