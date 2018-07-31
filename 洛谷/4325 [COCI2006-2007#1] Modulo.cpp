#include <bits/stdc++.h>
using namespace std;
int t, ans;
set < int > Set;
int main() {
	for (int i = 1; i <= 10; i++) {
		cin >> t;
		if (!Set.count(t % 42)) {
			Set.insert(t % 42);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 