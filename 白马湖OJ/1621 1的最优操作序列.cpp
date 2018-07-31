#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, f[maxn];
int main() {
	cin >> n;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			f[i] = max(f[i], f[j] * f[i - j] + 1);
	}
	cout << f[n];
	return 0;
}
