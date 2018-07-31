#include <bits/stdc++.h>
using namespace std;
int n, m, ans, minn;
bool gcd(int x, int y) {
	minn = min(x, y);
	if (x == 1 || y == 1) return false;
	for (int i = 3; i <= minn; i++)
		if (x % i == 0 && y % i == 0) return false;
	return true;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (gcd(i, j)) ans++;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			cout << gcd(i, j);
//		puts("");
//	}
	cout << ans + 3 << endl;
	return 0;
}
