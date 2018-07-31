#include <bits/stdc++.h>
#define r(lim) (rand() % lim + 1)
using namespace std;
int main() {
	srand(time(0)); 
	int n = 6, lim = 10;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
		printf("%d ", r(lim));
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d %d %d %d\n", rand() % 2, r(n), r(n), r(lim));
	return 0;
} 
