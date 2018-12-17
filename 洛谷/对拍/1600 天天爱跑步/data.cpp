#include <bits/stdc++.h>
using namespace std;
int r(int l) { return rand() % l + 1; }
int n = 10, m = 5;
int main() {
	srand(time(0));
	printf("%d %d\n", n, m);
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, r(i - 1));
	for (int i = 1; i <= n; i++)
		printf("%d ", r(n + 1) - 1);
	putchar('\n');
	for (int i = 1; i <= m; i++) {
		int u = r(n), v = r(n);
		printf("%d %d\n", u, v);
	}
	return 0;
}
