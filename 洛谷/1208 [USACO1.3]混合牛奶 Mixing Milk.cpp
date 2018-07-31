#include <bits/stdc++.h> 
using namespace std;
const int maxm = 1010;
int n, m, x, y, b[maxm];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		b[x] += y;
	}
	long long ans = 0;
	for (int i = 1; i <= 1000; i++) {
		if (b[i] > m) {
			ans += m * i;
			break;
		} else {
			ans += b[i] * i;
			m -= b[i];
		}
	}
	cout << ans << endl; 
	return 0;
}
