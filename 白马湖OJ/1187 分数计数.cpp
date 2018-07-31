#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, ans, f[maxn], c[maxn], x[maxn];
int main() {
	cin >> n >> x[1];
	c[x[1]] = f[x[1]] = 1;
	for (int i = 2; i <= n; i++) {
		x[i] = ((x[i - 1]* 3703 + 1047) % n) + 1;
		c[x[i]]++;
		for (int j = 1; j <= n; j++)
			if (j != x[i]) c[j] = 0;
		if (c[x[i]] == 1) f[x[i]] += 1;
		else if (c[x[i]] == 2) f[x[i]] += 2;
		else f[x[i]] += 3;
		ans = max(ans, f[x[i]]);
	}
	cout << ans << endl;
	return 0;
}
