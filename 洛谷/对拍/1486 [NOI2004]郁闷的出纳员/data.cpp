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

int n, m, opt;

int main() {
	srand(GetTickCount());
	n = 10, m = 0;
	printf("%d %d\n", n, m);
	while (n--) {
		opt = rand() % 4;
		switch (opt) {
			case 0:
				printf("F %d\n", rand() % 10 + 1);
				break;
			case 1:
				printf("I %d\n", rand() % 10);
				break;
			case 2:
				printf("A %d\n", rand() % 10);
				break;
			case 3:
				printf("S %d\n", rand() % 10);
				break;
		}
	}
	return 0;
}
