#include <bits/stdc++.h>
using namespace std;
int n, m;
inline int _r(int limit) {
	return rand() * rand() % limit + 1;
}
int main() {
	srand(time(NULL));
	n = 500000, m = 200000;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
		printf("%d ", _r(n));
	putchar('\n');
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) {
		int l = _r(n), r = _r(n);
		if (l > r) swap(l, r);
		printf("%d %d\n", l, r);
	}
	return 0;
}
