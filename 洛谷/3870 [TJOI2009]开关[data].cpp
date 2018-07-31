#include <bits/stdc++.h>
using namespace std;
int n = 100, l, r, x;
int main() {
	srand(time(0));
	printf("%d %d\n", n, n);
	for (int i = 1; i <= n; i++) {
		x = rand() % 2, l = (rand() - 1) % n + 1, r = (rand() - 1) % n + 1;
		if (l > r) swap(l, r);
		printf("%d %d %d\n", x, l, r);
	}
}
