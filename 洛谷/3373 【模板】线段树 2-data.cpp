#include <bits/stdc++.h>
int n = 5, m = 10, p = 38;
int main() {
	srand(time(0));
	printf("%d %d %d\n", n, m, p);
	for (int i = 1; i <= n; i++) printf("%d ", rand() % p);
	puts("");
	int t, x, y, z, tmp;
	for (int i = 1; i <= m; i++) {
		 t = (rand() - 1) % 3 + 1;
		 x = (rand() - 1) % n + 1;
		 y = (rand() - 1) % n + 1;
		 z = (rand() - 1) % p + 1;
		 if (x > y) tmp = x, x = y, y = tmp;
		 printf("%d %d %d", t, x, y);
		 if (t == 3) puts("");
		 else printf(" %d\n", z);
	}
	return 0;
}
