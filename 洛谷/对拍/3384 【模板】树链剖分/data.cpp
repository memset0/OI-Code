#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define r(l) (rand() % (l) + 1)

int main() {
	srand(GetTickCount());
	int n = 5, m = 5, r = 1, p = 11;
	printf("%d %d %d %d\n", n, m, r, p);
	for (int i = 1; i <= n; i++)
		printf("%d ", r(p));
	putchar('\n');
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, r(i - 1));
	for (int i = 1; i <= m; i++) {
		int opt = r(4), x = r(n), y = r(n), z = r(p * 2);
		if (x > y) swap(x, y);
		if (opt == 1) printf("%d %d %d %d\n", opt, x, y, z);
		else if (opt == 2) printf("%d %d %d\n", opt, x, y);
		else if (opt == 3) printf("%d %d %d\n", opt, x, z);
		else printf("%d %d\n", opt, x);
	}
	return 0;
}

