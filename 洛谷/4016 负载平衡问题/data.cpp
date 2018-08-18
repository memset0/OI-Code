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

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	srand(GetTickCount());

	int n = 100, m = 200;
	printf("%d\n", n);
	int s = n * m;
	for (int i = 1; i < n; i++) {
		int t = rand() % (s >> 1);
		s -= t;
		printf("%d ", t);
	}
	printf("%d\n", s);
	puts("");

	return 0;
}