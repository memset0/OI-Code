#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
	srand(GetTickCount());
	int n = 3, m = 4, a[n][n];
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		int x = rand() % m, y = rand() % m;
		while (a[x][y]) x = rand() % m, y = rand() % m;
		a[x][y] = 1;
		printf("%d %d\n", x, y);
	}
	return 0;
}
