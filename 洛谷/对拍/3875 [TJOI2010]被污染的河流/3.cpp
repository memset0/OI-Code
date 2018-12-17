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

int brand() {
	return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int main() {
	srand(GetTickCount());
	freopen("3.txt", "w", stdout);
	
	int n = 500;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		int a = brand() % 100000 + 1;
		int b = brand() % 100000 + 1;
		int c = brand() % 100000 + 1;
		if (rand() & 1) printf("%d %d %d %d\n", a, b, a, c);
		else printf("%d %d %d %d\n", a, b, c, b);
	}

	return 0;
}

