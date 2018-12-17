#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() { return (rand() << 16) + (rand() << 1) + (rand() & 1); }
int lrand(int l) { return brand() % l + 1; }
int main() {
//	freopen("data.txt", "r", stdin);
	srand(GetTickCount());
	int n = 3, m = 3;
	printf("%d\n", n);
	for (int i = 2; i <= n; i++) {
		int u = lrand(i - 1), v = i;
		if (rand() & 1) swap(u, v);
		printf("%d %d\n", u, v);
	}
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) {
		if (rand() & 1) printf("G\n");
		else printf("C %d\n", lrand(n));
	}
	return 0;
}
