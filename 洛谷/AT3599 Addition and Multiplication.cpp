#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 1;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		ans += min(ans, k);
	cout << ans << endl;
	return 0;
}
