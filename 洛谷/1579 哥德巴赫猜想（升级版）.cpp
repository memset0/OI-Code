#include <bits/stdc++.h>
using namespace std;
const int maxm = 20010;
int n, a, b, c, f[maxm];
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++)
		if (!f[i]) {
			for (int j = i + i; j <= n; j += i)
				f[j] = 1;
		}
	for (a = 2; a <= n; a++)
		for (b = a; a + b <= n / 2; b++) {
			c = n - a - b;
//				printf("%d %d %d\n", a, b, c);
			if (!f[a] && !f[b] && !f[c]) {
				printf("%d %d %d\n", a, b, c);
				return 0;
			}
		}
	return 0;
}
