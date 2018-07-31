#include <bits/stdc++.h>
using namespace std;
long long n, f[50] = {0, 1, 1};
long long g(long long x) {
	if (f[x]) return f[x];
	return f[x] = (g(x - 1) + g(x - 2)) % (1 << 31);
}
int main() {
	cin >> n;
	n = g(n);
	printf("%d=", n);
	bool mark = false;
	for (int i = 2; i <= n; i++)
		while (!(n % i)) {
			n /= i;
			if (mark) putchar('*');
			else mark = true;
			printf("%d", i);
		}
	return 0;
}
