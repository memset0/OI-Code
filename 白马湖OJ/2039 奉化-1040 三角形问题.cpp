#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, ans;
int main() {
	cin >> n;
	for (a = 1; a * 3 <= n; a++) 
		for (b = a; a + b * 2 <= n; b++) {
			c = n - a - b;
			if (c >= b && a + b > c) {
				ans++;
			}
		}
	cout << ans << endl;
	return 0;
}
