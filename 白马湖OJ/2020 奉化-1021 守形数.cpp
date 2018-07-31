#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (t = 1; t < i; t *= 10);
		if (i == ((i * i) % t)) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
