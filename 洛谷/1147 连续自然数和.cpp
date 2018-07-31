#include <bits/stdc++.h>
using namespace std;
int m, sum, i, j;
int main() {
	cin >> m;
	for (i = 1; i <= m / 2; i++) {
		sum = 0;
		for (j = i; j < m; j++) {
			sum += j;
			if (sum >= m) break;
		}
		if (sum == m) cout << i << ' ' << j << endl;
	}
	return 0;
}
