#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long cnt = 0;
int main() {
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		for (int t = i; t > 0; t /= 10) {
			k = t % 10;
			if (k == 2) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
