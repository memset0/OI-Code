#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, f[maxn];
long long ans = 0;
int main()
{
	cin >> n;
	int i = 1, k = 0;
	while (k <= n) {
		for (int j = 1; j <= i; j++) f[++k] = i;
		i++;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += f[i];
	}
	cout << ans;
	return 0;
}
