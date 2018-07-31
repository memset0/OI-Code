#include <bits/stdc++.h>
using namespace std;
int main() {
	int ans = 0;
	double u, v = 2;
	cin >> u;
	while (u > 0) {
		u -= v;
		v *= 0.98;
		ans += 1;
	}
	cout << ans << endl; 
}
