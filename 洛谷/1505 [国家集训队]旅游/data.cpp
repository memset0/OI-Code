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

int r(int n) { return rand() % n + 1; }

int main() {
	srand(GetTickCount());
	int n = 5, m = 3;
	printf("%d\n", n);
	for (int i = 1; i < n; i++)
		printf("%d %d %d\n", i, r(i) - 1, r(100));
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) {
		int opt = rand() % 5, u = r(n) - 1, v = r(n) - 1;
		if (opt == 0) printf("C %d %d\n", u, r(100));
		else if (opt == 1) printf("N %d %d\n", u, v);
		else if (opt == 2) printf("SUM %d %d\n", u, v);
		else if (opt == 3) printf("MAX %d %d\n", u, v);
		else printf("MIN %d %d\n", u, v);
	}
	return 0;
}
