#include <bits/stdc++.h>
using namespace std;
int main() {
	long long x, n, ans = 1;
	cin >> x >> n;
	for (int i = 1; i <= n; i++)
		ans *= x+1;
	cout << ans << endl;
	return 0;
}