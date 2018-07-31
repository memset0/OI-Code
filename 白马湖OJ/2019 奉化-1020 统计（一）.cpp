#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 3; i <= n; i += 3) {
		for (int t = i; t > 0; t /= 10) {
			if (t % 10 == 5) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
