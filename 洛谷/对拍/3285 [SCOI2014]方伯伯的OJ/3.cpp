#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int maxn = 100010;

int a[maxn];

int main() {
	srand(GetTickCount());
	int n = 5, m = 5;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 1; i <= m; i++) {
		int opt = rand() % 4 + 1;
		printf("%d ", opt);
		int x = rand() % n;
		if (opt == 2 || opt == 3) printf("%d\n", a[x]);
		else if (opt == 4) printf("%d\n", a[x]);
		else {
			int t = a[x];
			a[x] = n + rand();
			printf("%d %d\n", t, a[x]);
		}
		
	}
	return 0;
}
