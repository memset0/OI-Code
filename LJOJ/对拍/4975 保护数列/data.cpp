#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int r(int n) { return rand() % n + 1; }
int main() {
	srand(GetTickCount());
	int n = 10000;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
		printf("%d ", r(n));
	puts("");
	return 0;
}