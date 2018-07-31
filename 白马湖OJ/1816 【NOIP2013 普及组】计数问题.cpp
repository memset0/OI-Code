#include <bits/stdc++.h>
using namespace std;
int n, x, k;
long long cnt = 0;
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		for (int t = i; t > 0; t /= 10) {
			k = t % 10;
			if (k == x) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
