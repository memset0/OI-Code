#include <bits/stdc++.h>
using namespace std;
long long n;
int a[10000000];
int main() {
	cin >> n;
	int i = 0;
	while (n > 0) {
		a[++i] = n % 2;
		n /= 2;
	}
	for (int j = i; j; j--)
		printf("%d", a[j]);
	return 0;
}
