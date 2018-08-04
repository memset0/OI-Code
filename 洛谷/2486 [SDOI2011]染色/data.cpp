#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int n = 1000, m = 1000;
int r(int n) { return rand() % n + 1; }
int main() {
	srand(GetTickCount());
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		printf("%d ", r(n >> 1));
	putchar('\n');
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, r(i - 1));
	for (int i = 1; i <= m; i++)
		if (rand() % 2) {
			int x = r(n), y = r(n);
			while (x == y) y = r(n);
			printf("C %d %d %d\n", x, y, r(n >> 1));
		} else {
			int x = r(n), y = r(n);
			while (x == y) y = r(n);
			printf("Q %d %d\n", x, y);
		}
	return 0;
}