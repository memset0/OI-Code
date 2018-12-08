#include <bits/stdc++.h>
using namespace std;
int r(int t) {
	return (rand() % t) + 1;
}
int main() {
	srand(time(0));
	int l = 10;
	int n = r(l), m = r(l);
	while (n > m + 1) n = r(l), m = r(l);
	printf("1 2 3 %d %d\n", n, m);
	return 0;
}
