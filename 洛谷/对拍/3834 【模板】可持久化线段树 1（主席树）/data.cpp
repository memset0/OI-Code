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

int n, m;

int main() {
	srand(GetTickCount());
	n = m = 10;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		printf("%d ", rand() % 8);
	puts("");
	for (int i = 1; i <= n; i++) {
		int l = rand() % n + 1, r = rand() % n + 1;
		if (l > r) swap(l, r);
		printf("%d %d %d\n", l, r, (rand() % (r - l + 1)) / 2 + 1);
	}
	return 0;
}
