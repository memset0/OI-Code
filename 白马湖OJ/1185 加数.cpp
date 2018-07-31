#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main() {
	cin >> n;
	while (n) {
		m = n;
		while (m) ans++, m /= 10;
		n /= 2;
	}
	cout << ans << endl; 
	return 0;
}
