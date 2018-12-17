#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
using namespace std;

int r(ll l) {
	return rand() * rand() % l + 1;
}

int main() {

	srand(GetTickCount());
	int t = 100, n = 200;
	while (t--) {
		printf("%d\n1\n", n);
		for (int i = 2; i <= n; i++)
			printf("%d %d\n", i, r(i - 1));
	}
	puts("0");

	return 0;
}